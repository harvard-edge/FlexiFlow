#include "sample_multi_data.h"
#include <stdio.h>

// kernel_predict prototype remains unchanged
char kernel_predict(
    unsigned char test_MQ135, unsigned char test_MQ136, unsigned char test_MQ137, unsigned char test_MQ138,
    unsigned char test_MQ2, unsigned char test_MQ3, unsigned char test_MQ4, unsigned char test_MQ5,
    unsigned char test_MQ6, unsigned char test_MQ8, unsigned char test_MQ9
);

// Global volatile variable to verify result is not optimized out
volatile int num_correct = 0;

// Expects: arrays of sensor values and labels, and the number of samples
int Evaluate_All_Samples() {
    int correct = 0;
    for (int i = 0; i < NUM_SAMPLES; ++i) {
        char predicted = kernel_predict(
            Testing_MQ135_Vector[i],
            Testing_MQ136_Vector[i],
            Testing_MQ137_Vector[i],
            Testing_MQ138_Vector[i],
            Testing_MQ2_Vector[i],
            Testing_MQ3_Vector[i],
            Testing_MQ4_Vector[i],
            Testing_MQ5_Vector[i],
            Testing_MQ6_Vector[i],
            Testing_MQ8_Vector[i],
            Testing_MQ9_Vector[i]
        );
        if (predicted == Label_Vector[i]) {
            correct++;
        }
    }
    return correct;
}

int main() {
    // These arrays and num_samples must be defined in sample_data.h or elsewhere
    // Example expected declarations in sample_data.h:
    // extern const unsigned char Testing_MQ135_Vector[];
    // extern const unsigned char Testing_MQ136_Vector[];
    // ...
    // extern const char Label_Vector[];
    // extern const int NUM_SAMPLES;

    num_correct = Evaluate_All_Samples();
    printf("Number correct: %d out of %d\n", num_correct, NUM_SAMPLES);
    return 0;
}