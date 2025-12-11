#include "sample_data.h"
// #include <stdio.h>

// TODO: Move to another header file and add link to notebook for how these params were obtained
#define INPUT_DIM  21
#define HIDDEN_DIM 3
#define OUTPUT_DIM 3

#define INPUT_LAYER_ZERO_POINT -128
const signed char layer_one_weights[INPUT_DIM*HIDDEN_DIM] = {
	-33, 127, -26, 72,  31, -42, -112, -49,  79, -84,  34,  18,  8, -7, -18,   1, -16,  12, 29, -70,  32,
         27,  21, -35,  4, -46, -70, -116, -17, -27, -82,  86,   5, -6,  8,  31,  12,  48,  -1, 64, -76,  28,
        -12,  13,   2, -4,   0, -26,  -39, -20,  -3, -25, -32, -32, 15,  5,  38, -20,  10, -32, -6, -38, -10
};
#define LAYER_ONE_WEIGHTS_ZERO_POINT 0
const int layer_one_bias[HIDDEN_DIM] = {
	9064, 1891, 0
};
#define LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT -128
const signed char layer_two_weights[HIDDEN_DIM*OUTPUT_DIM] = {
	127, 40, 30, -81, 91, 4, 15, -119, -63
};
#define LAYER_TWO_WEIGHTS_ZERO_POINT 0
const int layer_two_bias[OUTPUT_DIM] = {
	-906, -3877, 3253
};
#define OUTPUT_LAYER_ZERO_POINT -30

#define M0_1 1373103872
#define N_1 7
#define M0_2 1142335232
#define N_2 7

// Declare arrays for intermediate activations
int input_activations[INPUT_DIM];
int weights_shifted[INPUT_DIM*HIDDEN_DIM]; // TODO: Refactor
int weights_two_shifted[HIDDEN_DIM*OUTPUT_DIM];  // TODO: Refactor
int layer_one_activations[HIDDEN_DIM];
int output_activations[OUTPUT_DIM];

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;  
volatile int num_incorrect = 0;

// Software implementation of integer multiplication adapted from: https://github.com/gcc-mirror/gcc/blob/master/libgcc/config/epiphany/mulsi3.c
int __mulsi3(int a, int b) {
    int result = 0;
    int negative = 0;

    // Handle sign and convert to positive
    if (a < 0) {
        a = -a;
        negative = !negative;
    }
    if (b < 0) {
        b = -b;
        negative = !negative;
    }

    // Perform shift-and-add multiplication
    while (b != 0) {
        if (b & 1) {
            result += a; // Add multiplicand if LSB of multiplier is 1
        }
        b >>= 1; // Shift multiplier to the right by 1 bit
        a <<= 1; // Shift multiplicand to the left by 1 bit
    }

    // Apply sign
    return negative ? -result : result;
}

long long __muldi3(long long a, long long b) {
    long long result = 0;
    int negative = 0;

    // Handle sign and convert to positive
    if (a < 0) {
        a = -a;
        negative = !negative;
    }
    if (b < 0) {
        b = -b;
        negative = !negative;
    }

    // Perform shift-and-add multiplication
    while (b != 0) {
        if (b & 1) {
            result += a; // Add multiplicand if LSB of multiplier is 1
        }
        b >>= 1; // Shift multiplier to the right by 1 bit
        a <<= 1; // Shift multiplicand to the left by 1 bit
    }

    // Apply sign
    return negative ? -result : result;
}

// Implementation of integer only neural network inference for 8-bit quantized model trained on UCI cardiotocography dataset with Tensorflow 
char nn_inference(
		signed char lb, 
		signed char ac, 
		signed char fm, 
		signed char uc, 
		signed char dl, 
		signed char ds, 
		signed char dp, 
		signed char astv, 
		signed char mstv, 
		signed char altv, 
		signed char mltv, 
		signed char width, 
		signed char min, 
		signed char max, 
		signed char nmax, 
		signed char nzeros, 
		signed char mode, 
		signed char mean, 
		signed char median, 
		signed char variance, 
		signed char tendency
		) 
{
  char predicted_class = -1;

  // (Inputs - Zero Point of Inputs)
  input_activations[0]  = (int)lb       - INPUT_LAYER_ZERO_POINT;
  input_activations[1]  = (int)ac       - INPUT_LAYER_ZERO_POINT;
  input_activations[2]  = (int)fm       - INPUT_LAYER_ZERO_POINT;
  input_activations[3]  = (int)uc       - INPUT_LAYER_ZERO_POINT;
  input_activations[4]  = (int)dl       - INPUT_LAYER_ZERO_POINT;
  input_activations[5]  = (int)ds       - INPUT_LAYER_ZERO_POINT;
  input_activations[6]  = (int)dp       - INPUT_LAYER_ZERO_POINT;
  input_activations[7]  = (int)astv     - INPUT_LAYER_ZERO_POINT;
  input_activations[8]  = (int)mstv     - INPUT_LAYER_ZERO_POINT;
  input_activations[9]  = (int)altv     - INPUT_LAYER_ZERO_POINT;
  input_activations[10] = (int)mltv     - INPUT_LAYER_ZERO_POINT;
  input_activations[11] = (int)width    - INPUT_LAYER_ZERO_POINT;
  input_activations[12] = (int)min      - INPUT_LAYER_ZERO_POINT;
  input_activations[13] = (int)max      - INPUT_LAYER_ZERO_POINT;
  input_activations[14] = (int)nmax     - INPUT_LAYER_ZERO_POINT;
  input_activations[15] = (int)nzeros   - INPUT_LAYER_ZERO_POINT;
  input_activations[16] = (int)mode     - INPUT_LAYER_ZERO_POINT;
  input_activations[17] = (int)mean     - INPUT_LAYER_ZERO_POINT;
  input_activations[18] = (int)median   - INPUT_LAYER_ZERO_POINT;
  input_activations[19] = (int)variance - INPUT_LAYER_ZERO_POINT;
  input_activations[20] = (int)tendency - INPUT_LAYER_ZERO_POINT;

  // (Weights - Zero Point of Weights)
  // TODO: Optimize this by preprocessing weight offset offline
  for (int i = 0; i < INPUT_DIM * HIDDEN_DIM; i++) {
	  weights_shifted[i] = (int)layer_one_weights[i] - LAYER_ONE_WEIGHTS_ZERO_POINT;
  }

  // (Inputs * Layer 1 Weights) + Bias followed by ReLU
  for (int i = 0; i < HIDDEN_DIM; i++) {
	  for (int j = 0; j < INPUT_DIM; j++){
		  // TODO: Optimize to not read layer_one_activations[i] each time
		  layer_one_activations[i] += (int)input_activations[j] * (int)weights_shifted[i*INPUT_DIM + j]; 
	  }
	  layer_one_activations[i] += layer_one_bias[i];
	  if (layer_one_activations[i] < 0) layer_one_activations[i] = 0;
  }

  // Requantization pipeline
  for (int i = 0; i < HIDDEN_DIM; i++) {
      // Multiply by layer_one_multiplier
      long long temp = (long long)layer_one_activations[i] * M0_1;

      // Divide by 2^31 and round
      if (temp >= 0) {
          temp = (temp + (1LL << 30)) >> 31; // Add 2^30 for rounding, then shift
      } else {
          temp = (temp - (1LL << 30)) >> 31; // Subtract 2^30 for rounding, then shift
      }

      // Divide by 2^layer_one_shift and round
      if (temp >= 0) {
          temp = (temp + (1LL << (N_1 - 1))) >> N_1;
      } else {
          temp = (temp - (1LL << (N_1 - 1))) >> N_1;
      }

      // Add the zero point
      temp += (int)LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT;

      // Clip to the 8-bit signed range
      if (temp > 127) temp = 127;
      if (temp < -128) temp = -128;

      // Store the result back
      layer_one_activations[i] = (int)temp;
  }

  // (Layer 1 Activations - Zero Point of Layer 1 Activations)
  // TODO: Optimize this by folding offset into previous statement
  for (int i = 0; i < HIDDEN_DIM; i++) {
	  layer_one_activations[i] = layer_one_activations[i] - LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT;
  }


  // (Layer 2 Weights - Zero Point of Layer 2 Weights)
  // TODO: Optimize this by preprocessing weight offset offline and hardcode for loop lengths?
  for (int i = 0; i < HIDDEN_DIM * OUTPUT_DIM; i++) {
	  weights_two_shifted[i] = (int)layer_two_weights[i] - LAYER_TWO_WEIGHTS_ZERO_POINT;
  }

  // (Layer 1 Activations * Layer 2 Weights) + Bias
  for (int i = 0; i < OUTPUT_DIM; i++) {
	  for (int j = 0; j < HIDDEN_DIM; j++){
		  // TODO: Optimize to not read output_activations[i] each time
		  output_activations[i] += (int)layer_one_activations[j] * (int)weights_two_shifted[i*HIDDEN_DIM + j]; 
	  }
	  output_activations[i] += layer_two_bias[i];
  }

  // Requantization pipeline
  for (int i = 0; i < OUTPUT_DIM; i++) {
      // Multiply by layer_one_multiplier
      long long temp = (long long)output_activations[i] * M0_2;

      // Divide by 2^31 and round
      if (temp >= 0) {
          temp = (temp + (1LL << 30)) >> 31; // Add 2^30 for rounding, then shift
      } else {
          temp = (temp - (1LL << 30)) >> 31; // Subtract 2^30 for rounding, then shift
      }

      // Divide by 2^layer_one_shift and round
      if (temp >= 0) {
          temp = (temp + (1LL << (N_1 - 1))) >> N_2;
      } else {
          temp = (temp - (1LL << (N_1 - 1))) >> N_2;
      }

      // Add the zero point
      temp += (int)OUTPUT_LAYER_ZERO_POINT;

      // Clip to the 8-bit signed range
      if (temp > 127) temp = 127;
      if (temp < -128) temp = -128;

      // Store the result back
      output_activations[i] = (int)temp;
  }

  // Return argmax for predicted class
  int max_activation = -128;
  for (int i = 0; i < OUTPUT_DIM; i++) {
	  if (output_activations[i] >= max_activation) {
		  max_activation = output_activations[i];
		  predicted_class = i;
	  }
  }
  return predicted_class;
}



// Read the values for the data sample and run the neural network to make a prediction
// Compare the predicted class made by this model to the predicted class made by the TFLite model for equivalence check
char Read_Values_Run_Neural_Network() {
    signed char lb, ac, fm, uc, dl, ds, dp, astv, mstv, altv, mltv, width, min, max, nmax, nzeros, mode, mean, median, variance, tendency, nsp_golden_label;
    signed char tflite_model_prediction, c_model_prediction;
    char parity_with_python = 1;

    for (int i = 0; i < Num_Data_Samples; ++i) {
        lb = LB_Vector[i];
        ac = AC_Vector[i];
        fm = FM_Vector[i];
        uc = UC_Vector[i];
        dl = DL_Vector[i];
        ds = DS_Vector[i];
        dp = DP_Vector[i];
        astv = ASTV_Vector[i];
        mstv = MSTV_Vector[i];
        altv = ALTV_Vector[i];
        mltv = MLTV_Vector[i];
        width = Width_Vector[i];
        min = Min_Vector[i];
        max = Max_Vector[i];
        nmax = Nmax_Vector[i];
        nzeros = Nzeros_Vector[i];
        mode = Mode_Vector[i];
        mean = Mean_Vector[i];
        median = Median_Vector[i];
        variance = Variance_Vector[i];
        tendency = Tendency_Vector[i];
        nsp_golden_label = NSP_Golden_Label_Vector[i];
        tflite_model_prediction = TFLite_Model_Prediction_Vector[i];

        c_model_prediction = nn_inference(lb, ac, fm, uc, dl, ds, dp, astv, mstv, altv, mltv, width, min, max, nmax, nzeros, mode, mean, median, variance, tendency);
        if (tflite_model_prediction != c_model_prediction) {
          parity_with_python = 0;
          num_incorrect++;
        }
    }
  return parity_with_python;
}

int main() {
  correct_result = Read_Values_Run_Neural_Network();
  // printf("Number incorrect: %d / %d\n", num_incorrect, Num_Data_Samples);
  return 0;
}
