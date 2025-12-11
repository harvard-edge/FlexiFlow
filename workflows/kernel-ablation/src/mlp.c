#define INPUT_DIM  11
#define HIDDEN_DIM 8
#define OUTPUT_DIM 4

#define INPUT_LAYER_ZERO_POINT -128
const signed char layer_one_weights[INPUT_DIM*HIDDEN_DIM] = {
	4,7,-93,4,9,-16,66,-52,24,40,48,
    -19,-6,-79,13,22,45,96,-47,-21,13,75,
    0,0,0,0,0,0,0,0,0,0,0,
    11,77,-44,25,36,-127,84,-42,9,51,20,
    5,9,-81,1,8,-7,52,-36,21,38,36,
    25,-2,70,-2,-8,26,-62,45,25,-1,-31,
    21,40,-16,9,11,-78,28,-16,5,28,7,
    4,-13,69,2,-4,50,-47,48,14,-17,-16
};
#define LAYER_ONE_WEIGHTS_ZERO_POINT 0
const int layer_one_bias[HIDDEN_DIM] = {
    9668,  2910,     0, 14814,  7039, 10296,  5936,  8006
};
#define LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT -128
const signed char layer_two_weights[HIDDEN_DIM*OUTPUT_DIM] = {
    64,95,0,9,52,-49,-6,-39,
    35,-19,0,56,33,-2,40,-33,
    -45,-57,0,52,-42,14,28,0,
    -58,-18,0,-127,-45,58,-59,52
};
#define LAYER_TWO_WEIGHTS_ZERO_POINT 0
const int layer_two_bias[OUTPUT_DIM] = {
    -2269,    89,  2063,   115
};
#define OUTPUT_LAYER_ZERO_POINT 11

#define M0_1 1808705664
#define N_1 7
#define M0_2 1710688256
#define N_2 8

// Declare arrays for intermediate activations
int input_activations[INPUT_DIM];
int weights_shifted[INPUT_DIM*HIDDEN_DIM]; // TODO: Refactor
int weights_two_shifted[HIDDEN_DIM*OUTPUT_DIM];  // TODO: Refactor
int layer_one_activations[HIDDEN_DIM];
int output_activations[OUTPUT_DIM];

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
char kernel_predict(
    unsigned char test_MQ135, unsigned char test_MQ136, unsigned char test_MQ137, unsigned char test_MQ138,
    unsigned char test_MQ2, unsigned char test_MQ3, unsigned char test_MQ4, unsigned char test_MQ5,
    unsigned char test_MQ6, unsigned char test_MQ8, unsigned char test_MQ9
) {
  char predicted_class;

  // (Inputs - Zero Point of Inputs)
  input_activations[0] = test_MQ135 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[1] = test_MQ136 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[2] = test_MQ137 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[3] = test_MQ138 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[4] = test_MQ2 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[5] = test_MQ3 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[6] = test_MQ4 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[7] = test_MQ5 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[8] = test_MQ6 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[9] = test_MQ8 - INPUT_LAYER_ZERO_POINT - 128;
  input_activations[10] = test_MQ9 - INPUT_LAYER_ZERO_POINT - 128;

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