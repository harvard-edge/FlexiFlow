#include "sample_data.h"

#define INPUT_DIM  33
#define HIDDEN_DIM_1 20
#define HIDDEN_DIM_2 10
#define OUTPUT_DIM 5

#define INPUT_LAYER_ZERO_POINT -128
const signed char layer_one_weights[INPUT_DIM*HIDDEN_DIM_1] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    18,-3,10,21,17,7,6,6,0,-1,10,18,-1,7,21,20,8,4,-1,0,-3,9,8,-8,-30,36,28,21,18,8,6,11,11,
    -21,1,20,-11,37,6,13,6,11,3,-6,-23,-21,14,-37,0,17,23,26,20,22,22,-20,-6,-3,-22,20,26,16,7,7,21,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    -21,27,17,-32,7,-2,2,-12,-18,-2,-4,-1,5,6,3,4,0,-8,0,-15,-5,0,-30,11,15,-36,-14,-21,-17,-21,-34,-17,-28,
    -26,37,7,-35,8,-2,5,-15,-21,-7,-9,-20,10,6,-1,6,7,-3,4,-13,-3,0,-26,17,10,-32,-10,-17,-18,-18,-34,-15,-25,
    12,-4,6,12,-14,9,6,5,-2,5,5,21,12,5,43,11,-1,-14,-19,-23,-20,-15,2,-10,-15,33,16,8,14,1,-10,-5,10,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    -11,-13,-9,27,-42,21,25,38,27,29,18,-18,45,17,67,11,-3,-27,-45,-43,-40,-53,-20,-9,-17,51,10,3,27,-9,-15,-19,10,
    77,13,-42,39,-39,5,-6,4,-10,-12,1,127,8,-3,79,17,-14,-19,-23,-9,-14,-28,57,21,-58,67,-4,-25,-10,-20,-18,-22,16,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    71,-16,-103,65,3,-30,-39,-20,-28,-40,-5,29,30,-68,35,23,6,0,-26,0,-9,-19,3,-10,-80,71,9,-14,-13,-26,14,-14,-18,
    24,-8,-86,39,-29,-6,-8,17,26,11,15,-78,60,-11,-9,-16,-2,0,-15,16,-3,-29,-29,45,6,11,-40,-19,-9,-5,13,-27,-16,
    -10,4,-2,-8,-6,-2,1,0,1,0,-5,-13,5,1,-11,-8,0,0,0,1,0,-4,-7,10,11,-15,-9,-6,-5,-3,-3,-5,-6,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
#define LAYER_ONE_WEIGHTS_ZERO_POINT 0
const int layer_one_bias[HIDDEN_DIM_1] = {
    -794,  -427,  -911, -4249,   535,  -187, 48632, 44484, -1354,  -712,  -638, -2720,
    -2567,  -874, 12308, 19645, 13867,  -912, -1573,  -814
};
#define LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT -128
const signed char layer_two_weights[HIDDEN_DIM_1*HIDDEN_DIM_2] = {
    0,0,0,3,13,0,27,18,-11,0,0,-61,-23,0,47,-8,-2,0,0,0,
    0,0,0,40,50,0,23,18,6,0,0,-53,-86,0,-69,-95,-8,0,0,0,
    0,0,0,39,-23,0,-59,-64,41,0,0,30,127,0,-31,-63,-13,0,0,0,
    0,0,0,38,6,0,-35,-28,23,0,0,52,63,0,100,60,-2,0,0,0,
    0,0,0,-10,-4,0,4,4,-4,0,0,-6,-2,0,-7,1,2,0,0,0,
    0,0,0,9,50,0,43,54,10,0,0,47,-73,0,-101,-20,10,0,0,0,
    0,0,0,-31,-4,0,39,37,-19,0,0,-36,-21,0,-51,1,13,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,-34,-10,0,35,31,-17,0,0,-31,-14,0,-37,1,10,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
#define LAYER_TWO_WEIGHTS_ZERO_POINT 0
const int layer_two_bias[HIDDEN_DIM_2] = {
    4109,   857, -2242,  4634,  3145,  3164, 10734,  -237, 10977,  -375
};
#define LAYER_TWO_OUTPUT_ACTIVATIONS_ZERO_POINT -128
const signed char layer_three_weights[HIDDEN_DIM_2*OUTPUT_DIM] = {
    43,127,-25,-52,1,38,9,0,11,0,
    17,-16,0,-93,13,28,58,0,51,0,
    6,-60,-125,80,-8,-12,-68,0,-56,0,
    -56,0,74,-6,-3,59,8,0,0,0,
    -10,-64,69,59,-1,-123,-7,0,-5,0,
};
#define LAYER_THREE_WEIGHTS_ZERO_POINT 0
const int layer_three_bias[OUTPUT_DIM] = {
    1055, -3636,  2262, -1153,   821
};
#define OUTPUT_LAYER_ZERO_POINT -1

#define M0_1 1404307200
#define N_1 7
#define M0_2 1200851840
#define N_2 6
#define M0_3 1176678400
#define N_3 7

// Declare arrays for intermediate activations
int input_activations[INPUT_DIM];
int weights_shifted[INPUT_DIM*HIDDEN_DIM_1]; // TODO: Refactor
int weights_two_shifted[HIDDEN_DIM_1*HIDDEN_DIM_2];  // TODO: Refactor
int weights_three_shifted[HIDDEN_DIM_2*OUTPUT_DIM];  // TODO: Refactor
int layer_one_activations[HIDDEN_DIM_1];
int layer_two_activations[HIDDEN_DIM_2];
int output_activations[OUTPUT_DIM];

// Global volatile variable to verify result is not optimized out
volatile signed char result = -1;  

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
        unsigned char feature0, unsigned char feature1, unsigned char feature2, unsigned char feature3, unsigned char feature4,
        unsigned char feature5, unsigned char feature6, unsigned char feature7, unsigned char feature8, unsigned char feature9,
        unsigned char feature10, unsigned char feature11, unsigned char feature12, unsigned char feature13, unsigned char feature14,
        unsigned char feature15, unsigned char feature16, unsigned char feature17, unsigned char feature18, unsigned char feature19,
        unsigned char feature20, unsigned char feature21, unsigned char feature22, unsigned char feature23, unsigned char feature24,
        unsigned char feature25, unsigned char feature26, unsigned char feature27, unsigned char feature28, unsigned char feature29,
        unsigned char feature30, unsigned char feature31, unsigned char feature32
        ) {
    char predicted_class;

    // (Inputs - Zero Point of Inputs)
    input_activations[0] = feature0 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[1] = feature1 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[2] = feature2 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[3] = feature3 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[4] = feature4 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[5] = feature5 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[6] = feature6 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[7] = feature7 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[8] = feature8 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[9] = feature9 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[10] = feature10 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[11] = feature11 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[12] = feature12 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[13] = feature13 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[14] = feature14 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[15] = feature15 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[16] = feature16 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[17] = feature17 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[18] = feature18 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[19] = feature19 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[20] = feature20 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[21] = feature21 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[22] = feature22 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[23] = feature23 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[24] = feature24 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[25] = feature25 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[26] = feature26 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[27] = feature27 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[28] = feature28 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[29] = feature29 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[30] = feature30 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[31] = feature31 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[32] = feature32 - INPUT_LAYER_ZERO_POINT - 128;

    // (Weights - Zero Point of Weights)
    // TODO: Optimize this by preprocessing weight offset offline
    for (int i = 0; i < INPUT_DIM * HIDDEN_DIM_1; i++) {
        weights_shifted[i] = (int)layer_one_weights[i] - LAYER_ONE_WEIGHTS_ZERO_POINT;
    }

    // (Inputs * Layer 1 Weights) + Bias followed by ReLU
    for (int i = 0; i < HIDDEN_DIM_1; i++) {
        for (int j = 0; j < INPUT_DIM; j++){
            // TODO: Optimize to not read layer_one_activations[i] each time
            layer_one_activations[i] += (int)input_activations[j] * (int)weights_shifted[i*INPUT_DIM + j]; 
        }
        layer_one_activations[i] += layer_one_bias[i];
        if (layer_one_activations[i] < 0) layer_one_activations[i] = 0;
    }

    // Requantization pipeline
    for (int i = 0; i < HIDDEN_DIM_1; i++) {
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
    for (int i = 0; i < HIDDEN_DIM_1; i++) {
        layer_one_activations[i] = layer_one_activations[i] - LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT;
    }


    // (Layer 2 Weights - Zero Point of Layer 2 Weights)
    // TODO: Optimize this by preprocessing weight offset offline and hardcode for loop lengths?
    for (int i = 0; i < HIDDEN_DIM_1 * HIDDEN_DIM_2; i++) {
        weights_two_shifted[i] = (int)layer_two_weights[i] - LAYER_TWO_WEIGHTS_ZERO_POINT;
    }

    // (Layer 1 Activations * Layer 2 Weights) + Bias + ReLU
    for (int i = 0; i < HIDDEN_DIM_2; i++) {
        for (int j = 0; j < HIDDEN_DIM_1; j++){
            // TODO: Optimize to not read output_activations[i] each time
            layer_two_activations[i] += (int)layer_one_activations[j] * (int)weights_two_shifted[i*HIDDEN_DIM_1 + j]; 
        }
        layer_two_activations[i] += layer_two_bias[i];
        if (layer_two_activations[i] < 0) layer_two_activations[i] = 0;
    }

    // Requantization pipeline
    for (int i = 0; i < HIDDEN_DIM_2; i++) {
        // Multiply by layer_one_multiplier
        long long temp = (long long)layer_two_activations[i] * M0_2;

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
        temp += (int)LAYER_TWO_OUTPUT_ACTIVATIONS_ZERO_POINT;

        // Clip to the 8-bit signed range
        if (temp > 127) temp = 127;
        if (temp < -128) temp = -128;

        // Store the result back
        layer_two_activations[i] = (int)temp;
    }

    // (Layer 2 Activations - Zero Point of Layer 2 Activations)
    // TODO: Optimize this by folding offset into previous statement
    for (int i = 0; i < HIDDEN_DIM_2; i++) {
        layer_two_activations[i] = layer_two_activations[i] - LAYER_TWO_OUTPUT_ACTIVATIONS_ZERO_POINT;
    }

    // (Layer 3 Weights - Zero Point of Layer 3 Weights)
    // TODO: Optimize this by preprocessing weight offset offline and hardcode for loop lengths?
    for (int i = 0; i < HIDDEN_DIM_2 * OUTPUT_DIM; i++) {
        weights_three_shifted[i] = (int)layer_three_weights[i] - LAYER_THREE_WEIGHTS_ZERO_POINT;
    }

    // (Layer 2 Activations * Layer 3 Weights) + Bias
    for (int i = 0; i < OUTPUT_DIM; i++) {
        for (int j = 0; j < HIDDEN_DIM_2; j++){
            // TODO: Optimize to not read output_activations[i] each time
            output_activations[i] += (int)layer_two_activations[j] * (int)weights_three_shifted[i*HIDDEN_DIM_2 + j]; 
        }
        output_activations[i] += layer_three_bias[i];
    }

    // Requantization pipeline
    for (int i = 0; i < OUTPUT_DIM; i++) {
        // Multiply by layer_one_multiplier
        long long temp = (long long)output_activations[i] * M0_3;

        // Divide by 2^31 and round
        if (temp >= 0) {
            temp = (temp + (1LL << 30)) >> 31; // Add 2^30 for rounding, then shift
        } else {
            temp = (temp - (1LL << 30)) >> 31; // Subtract 2^30 for rounding, then shift
        }

        // Divide by 2^layer_one_shift and round
        if (temp >= 0) {
            temp = (temp + (1LL << (N_2 - 1))) >> N_3;
        } else {
            temp = (temp - (1LL << (N_2 - 1))) >> N_3;
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

char Read_Values_Run_Neural_Network() {

    signed char feature0 = Feature_0;
    signed char feature1 = Feature_1;
    signed char feature2 = Feature_2;
    signed char feature3 = Feature_3;
    signed char feature4 = Feature_4;
    signed char feature5 = Feature_5;
    signed char feature6 = Feature_6;
    signed char feature7 = Feature_7;
    signed char feature8 = Feature_8;
    signed char feature9 = Feature_9;
    signed char feature10 = Feature_10;
    signed char feature11 = Feature_11;
    signed char feature12 = Feature_12;
    signed char feature13 = Feature_13;
    signed char feature14 = Feature_14;
    signed char feature15 = Feature_15;
    signed char feature16 = Feature_16;
    signed char feature17 = Feature_17;
    signed char feature18 = Feature_18;
    signed char feature19 = Feature_19;
    signed char feature20 = Feature_20;
    signed char feature21 = Feature_21;
    signed char feature22 = Feature_22;
    signed char feature23 = Feature_23;
    signed char feature24 = Feature_24;
    signed char feature25 = Feature_25;
    signed char feature26 = Feature_26;
    signed char feature27 = Feature_27;
    signed char feature28 = Feature_28;
    signed char feature29 = Feature_29;
    signed char feature30 = Feature_30;
    signed char feature31 = Feature_31;
    signed char feature32 = Feature_32;

    signed char c_model_prediction = nn_inference(
        feature0, feature1, feature2, feature3, feature4, feature5, feature6, feature7, feature8, feature9, 
        feature10, feature11, feature12, feature13, feature14, feature15, feature16, feature17, feature18, feature19, 
        feature20, feature21, feature22, feature23, feature24, feature25, feature26, feature27, feature28, feature29, 
        feature30, feature31, feature32
    );

    signed char GPIO = c_model_prediction;
    return GPIO;
}

int main() {
    result = Read_Values_Run_Neural_Network();
    return 0;
}
