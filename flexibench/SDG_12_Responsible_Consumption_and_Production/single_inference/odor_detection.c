#include "sample_data.h"

// Global volatile variable to verify result is not optimized out
volatile char result = -1;  

// Female DT uses only Sensors J & L
char  Female_DT(char Sensor_2_B_Input, char Sensor_4_B_Input, char Sensor_2_A_Input, char Sensor_4_A_Input) {
  char predicted_class;

  if (Sensor_2_B_Input <= 41 >> SHIFT_AMT) {
    if (Sensor_4_A_Input <= 45 >> SHIFT_AMT) {
      if (Sensor_4_B_Input <= 43 >> SHIFT_AMT) {
        if (Sensor_2_B_Input <= 39 >> SHIFT_AMT) {
          if (Sensor_4_A_Input <= 39 >> SHIFT_AMT) predicted_class =  4;
          else {
            if (Sensor_2_B_Input <= 35 >> SHIFT_AMT) predicted_class =  8;
            else {
              if (Sensor_2_A_Input <= 37 >> SHIFT_AMT) predicted_class =  8;
              else {
                if (Sensor_2_B_Input <= 37 >> SHIFT_AMT) {
                  if (Sensor_4_A_Input <= 41 >> SHIFT_AMT) {
                    if (Sensor_2_A_Input <= 39 >> SHIFT_AMT) {
                      predicted_class =  4;
                    } 
                    else predicted_class =  4;
                  } 
                  else predicted_class =  4;
                }
                else { 
                  if (Sensor_4_B_Input <= 41 >> SHIFT_AMT) predicted_class =  8;
                  else predicted_class =  4;
                }
              }
            }
          }
        } 
        else predicted_class =  8;
     } 
     else predicted_class =  4;
    } 
    else {
      if (Sensor_2_B_Input <= 39 >> SHIFT_AMT) predicted_class =  16;
      else {
        if (Sensor_2_A_Input <= 43 >> SHIFT_AMT) predicted_class =  8;
        else {
          predicted_class =  4;
        }
      }
    }
  } 
  else {
    if (Sensor_4_A_Input <= 47 >> SHIFT_AMT) {
      predicted_class =  1;
    } 
    else {
      predicted_class =  4;
    }
  }

  return predicted_class;
}


// Male DT uses only Sensors I & K but Sensor_1_B_Input value is never used
char Male_DT(char Sensor_3_B_Input, char Sensor_1_A_Input, char Sensor_3_A_Input) {
  char predicted_class;

  if (Sensor_3_B_Input <= 27 >> SHIFT_AMT) {
    if (Sensor_3_B_Input <= 25 >> SHIFT_AMT) {
      if (Sensor_3_A_Input <= 25 >> SHIFT_AMT) predicted_class =  4;
      else predicted_class =  8;
    }
    else {
      predicted_class =  8;
    }
  } 
  else {
    if (Sensor_3_A_Input <= 37 >> SHIFT_AMT) {
      if (Sensor_3_A_Input <= 31 >> SHIFT_AMT) {
        if (Sensor_3_A_Input <= 27 >> SHIFT_AMT) predicted_class =  8;
        else {
          if (Sensor_3_A_Input <= 29 >> SHIFT_AMT) predicted_class =  2;
          else predicted_class =  4;
        }
      } 
      else {
        if (Sensor_3_B_Input <= 33 >> SHIFT_AMT) {
          if (Sensor_3_B_Input <= 31 >> SHIFT_AMT) {
            predicted_class =  16;
          } 
          else {
            if (Sensor_3_A_Input <= 33 >> SHIFT_AMT) predicted_class =  1;
            else predicted_class =  8;
          }
        } 
        else {
          predicted_class =  2;
        }
      }
    } 
    else {
      if (Sensor_1_A_Input <= 1) {
        predicted_class =  4;
      } 
      else predicted_class =  8;
    }
  }
  return predicted_class;
}


// Read the sensor values from the data samples and run the DTs to make predictions
// Compare the predicted class made by this model to the predicted class made by the Python model for equivalence check
char Read_Sensor_Values_Run_DTs() {
  char Sensor_2_B_Input, Sensor_3_B_Input, Sensor_4_B_Input, Sensor_1_A_Input, Sensor_2_A_Input, Sensor_3_A_Input, Sensor_4_A_Input, python_predicted_class, onehot_encoded_python_predicted_class, gender, c_predicted_class;
  //char Sensor_2_B_Input, Sensor_4_B_Input, Sensor_2_A_Input, Sensor_4_A_Input, data_sample, python_predicted_class, c_predicted_class, onehot_encoded_python_predicted_class;
  char GPIO;
  // Read sensor values from the static data array
  // Because trained Decision Trees use half-point boundary conditions (e.g. 9.5)
  // so I have multiplied these conditions by 2 to make them integer numbers
  // Therefore when the sensor values are received from SRI to MLE
  // Sensor values will be multiplied by 2
  Sensor_1_A_Input = Sensor_1_A_Sample_Input << 1;
  Sensor_2_A_Input = Sensor_2_A_Sample_Input << 1;
  Sensor_3_A_Input = Sensor_3_A_Sample_Input << 1;
  Sensor_4_A_Input = Sensor_4_A_Sample_Input << 1;

  // Sensor_1_B_Input value is never used
  Sensor_2_B_Input = Sensor_2_B_Sample_Input << 1;
  Sensor_3_B_Input = Sensor_3_B_Sample_Input << 1;
  Sensor_4_B_Input = Sensor_4_B_Sample_Input << 1;


  // Predicted classes spitted out by the HW are in one-hot encoded format
  // Because of this, we need to convert the predicted classes coming from the datasets into one-hot format
  onehot_encoded_python_predicted_class = 1 << Golden_Reference_Class_Prediction;

  // Female
  if (Gender == 0) {
      c_predicted_class = Female_DT(Sensor_2_B_Input, Sensor_4_B_Input, Sensor_2_A_Input, Sensor_4_A_Input);
  }
  else c_predicted_class = Male_DT(Sensor_3_B_Input, Sensor_1_A_Input, Sensor_3_A_Input);

  GPIO = c_predicted_class;
  //printf ("GPIO=%d for Data Sample:%d\n", GPIO, data_sample);

  return GPIO;
}

int main() {
  result = Read_Sensor_Values_Run_DTs();
  return 0;
}
