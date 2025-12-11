#include "sample_data.h"

/**
 * O2 > 6
 * 6.5 < pH < 8.5
 * TDS < 600
 */

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;
unsigned int num_incorrect = 0;

char potable_check(long o2, long pH, long tds) {
  return o2 > O2_MIN && (pH < PH_MAX && pH > PH_MIN) && tds < TDS_MAX;
}

char Read_Sensor_Values_Run_Check() {
  long pH, o2, tds;
  char potable, golden_reference;

  unsigned short data_sample;
  char parity_with_python = 1;

  for (data_sample = 0; data_sample < Num_Data_Samples; data_sample++) {
    pH = pH_Sensor_Sample_Input_Vector[data_sample];
    o2 = O2_Sensor_Sample_Input_Vector[data_sample];
    tds = TDS_Sensor_Sample_Input_Vector[data_sample];
    potable = potable_check(o2, pH, tds);
    golden_reference = Golden_Reference_Potability_Vector[data_sample];

    if (potable != golden_reference) {
      // Failure case - this really shouldn't happen for basic thresholding
      parity_with_python = 0;
      num_incorrect++;
    }
  }

  return parity_with_python;
}

int main() {
  correct_result = Read_Sensor_Values_Run_Check();
  // printf("Accuracy: %d / %d\n", Num_Data_Samples - num_incorrect, Num_Data_Samples);
  return 0;
}
