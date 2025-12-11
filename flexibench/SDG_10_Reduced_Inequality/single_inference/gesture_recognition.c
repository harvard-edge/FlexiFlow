#include "sample_data.h"
// #include <stdio.h>

volatile char result = -1;

// Function to compute the sign agreement difference
int sign_agreement_difference(const volatile int* u, const volatile int* v) {
    volatile int same_sign_count = 0;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        if (u[i] == v[i]) {
            same_sign_count++;  // Count same signs
        }
    }
    return 2 * same_sign_count - VECTOR_SIZE;  // Direct computation of the dot product based on sign agreement
}

// Function to calculate cosine similarity using additions, subtractions, and negations
int cosine_similarity(const volatile int* u, const volatile int* v) {
    volatile int dot = sign_agreement_difference(u, v);
    return dot;  // Cosine similarity * 10000 (avoid division)
}

// Find the array with the lowest cosine similarity to the 'ngram' array
int Run_Gesture_Recognition() {
    int maxSim = 0;  // Initialize minimum similarity to the highest possible int value
    int label = -1;  // Initialize label to -1
    char GPIO = 0;
    int sim;

    for (int i = 0; i < AM_COUNT; i++) {
        sim = cosine_similarity(AM[i], Ngram_Array);
        if (sim > maxSim) {
            maxSim = sim;
            label = i;
        }
    }

    GPIO = (char)label;
    return GPIO;
}

int main() {
    result = Run_Gesture_Recognition();
    //printf("res: %d\n", correct_result);
    return 0;
}
