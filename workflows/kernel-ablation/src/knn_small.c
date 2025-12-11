#include "knn_training_small.h"
// #include <stdio.h>

#define K 3
#define Num_Features 11
#define Num_Outputs 4

// L1 distance for 11-dimensional MQ sensor inputs
unsigned long l1_distance(const unsigned char *a, const unsigned char *b) {
    unsigned long sum = 0;
    for (int i = 0; i < Num_Features; i++) {
        short diff = (short) a[i] - (short) b[i];
        if (diff < 0)
            diff = -diff;
        sum += diff;
    }
    return sum;
}

// Find the majority class among k neighbors
char majority_vote(short *labels) {
  char count[Num_Outputs] = {0};
  for (int i = 0; i < K; i++) {
    count[labels[i]]++;
  }
  // Determine the label with the highest count (majority)
  int max_label = 0;
  for (int i = 1; i < Num_Outputs; i++) {
    if (count[i] > count[max_label]) {
      max_label = i;
    }
  }
  return max_label;
}

// Custom implementation of KNN without standard library functions

char kernel_predict(
    unsigned char test_MQ135, unsigned char test_MQ136, unsigned char test_MQ137, unsigned char test_MQ138,
    unsigned char test_MQ2, unsigned char test_MQ3, unsigned char test_MQ4, unsigned char test_MQ5,
    unsigned char test_MQ6, unsigned char test_MQ8, unsigned char test_MQ9
) {
    unsigned long max_distance = 0xFFFFFFFF;  // Track largest distance among K smallest
    int max_idx = 0;                         // Index of largest distance among K smallest
    short min_labels[K];                     // Labels for K nearest neighbors
    unsigned long min_distances[K];          // K smallest distances
    unsigned long curr_distance;
    int i, j;

    // Prepare test vector
    unsigned char test_vec[Num_Features];
    test_vec[0] = test_MQ135;
    test_vec[1] = test_MQ136;
    test_vec[2] = test_MQ137;
    test_vec[3] = test_MQ138;
    test_vec[4] = test_MQ2;
    test_vec[5] = test_MQ3;
    test_vec[6] = test_MQ4;
    test_vec[7] = test_MQ5;
    test_vec[8] = test_MQ6;
    test_vec[9] = test_MQ8;
    test_vec[10] = test_MQ9;

    // Initialize with first K points
    for (i = 0; i < K; i++) {
        curr_distance = l1_distance(&Training_Data[i][0], test_vec);
        min_distances[i] = curr_distance;
        min_labels[i] = Training_Labels[i];

        if (curr_distance > max_distance) {
            max_distance = curr_distance;
            max_idx = i;
        }
    }

    // For remaining points, replace max if we find smaller distance
    for (i = K; i < Num_Training_Samples; i++) {
        curr_distance = l1_distance(&Training_Data[i][0], test_vec);
        if (curr_distance < max_distance) {
            min_distances[max_idx] = curr_distance;
            min_labels[max_idx] = Training_Labels[i];
            // Find new maximum distance among K smallest distances
            max_distance = min_distances[0];
            max_idx = 0;
            for (int k = 1; k < K; k++) {
                if (min_distances[k] > max_distance) {
                    max_distance = min_distances[k];
                    max_idx = k;
                }
            }
        }
    }
    // Majority vote to decide the class
    return majority_vote(min_labels);
}
