#include "sample_data.h"
// #include <stdio.h>

#define K 3

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;
unsigned int num_incorrect = 0;

// Function to calculate Euclidean distance between two points
unsigned long euclidean_distance(short moisture1, short temp1, short moisture2, short temp2) {
  unsigned long sum = 0;
  short moisture_diff = moisture1 - moisture2;
  short temp_diff = temp1 - temp2;
  sum = moisture_diff * moisture_diff + temp_diff * temp_diff;
  return sum;
}

// Find the majority class among k neighbors
char majority_vote(short *labels) {
  char count[2] = {0, 0}; // Assuming binary classification (0 or 1)
  for (int i = 0; i < K; i++) {
    count[labels[i]]++;
  }
  return (count[0] > count[1]) ? 0 : 1;
}

// Custom implementation of KNN without standard library functions
int predict_classification(short test_moisture, short test_temp) {
  unsigned long max_distance = 0xFFFFFFFF;  // Track largest distance among K smallest
  int max_idx = 0;                         // Index of largest distance among K smallest
  short min_labels[K];                     // Labels for K nearest neighbors
  unsigned long min_distances[K];          // K smallest distances
  unsigned long curr_distance;
  int i, j;

  // Initialize with first K points
  for (i = 0; i < K; i++) {
    curr_distance = euclidean_distance(Training_Moisture_Vector[i], Training_Temp_Vector[i],
                                     test_moisture, test_temp);
    min_distances[i] = curr_distance;
    min_labels[i] = Training_Pump_Vector[i];
    

    if (curr_distance > max_distance) {
      max_distance = curr_distance;
      max_idx = i;
    }
  }

  // For remaining points, replace max if we find smaller distance
  for (i = K; i < Num_Training_Samples; i++) {
    curr_distance = euclidean_distance(Training_Moisture_Vector[i], Training_Temp_Vector[i],
                                     test_moisture, test_temp);
    if (curr_distance < max_distance) {
      min_distances[max_idx] = curr_distance;

      min_labels[max_idx] = Training_Pump_Vector[i];
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


char Read_Sensor_Values_Run_KNNs() {

  char golden_reference, predicted_pump;
  short test_moisture, test_temp;
  unsigned short data_sample;
  char parity_with_python = 1;

  for (data_sample = 0; data_sample < Num_Data_Samples; data_sample++) {
    test_moisture = Testing_Moisture_Vector[data_sample];
    test_temp = Testing_Temp_Vector[data_sample];

    golden_reference = (char) Testing_Golden_Reference_Vector[data_sample];

    predicted_pump = predict_classification(test_moisture, test_temp);

    if (golden_reference != predicted_pump) {
      parity_with_python = 0;
      num_incorrect++;
    }
  }

  return parity_with_python;
}

int main() {
    correct_result = Read_Sensor_Values_Run_KNNs();
    // printf("Num incorrect: %d / %d\n", num_incorrect, Num_Data_Samples);
    return 0;
}
