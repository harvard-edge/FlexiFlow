#include "sample_data.h"
// #include <stdio.h>

#define K 3

// Global volatile variable to verify result is not optimized out
volatile char result = -1;

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

char Read_Sensor_Values_Run_KNN() {

  char predicted_pump;
  short test_moisture, test_temp;
  char GPIO;

  test_moisture = Testing_Moisture;
  test_temp = Testing_Temp;
  
  predicted_pump = predict_classification(test_moisture, test_temp);

  if (predicted_pump)
    GPIO = 1;
  else
    GPIO = 0;

  return GPIO;
}

int main() {
  result = Read_Sensor_Values_Run_KNN();
  // printf("Result: %d\n", result);
  return 0;
}
