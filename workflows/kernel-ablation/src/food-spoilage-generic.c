#include "sample_data.h"
// #include <stdio.h>

char kernel_predict(
    unsigned char test_MQ135, unsigned char test_MQ136, unsigned char test_MQ137, unsigned char test_MQ138,
    unsigned char test_MQ2, unsigned char test_MQ3, unsigned char test_MQ4, unsigned char test_MQ5,
    unsigned char test_MQ6, unsigned char test_MQ8, unsigned char test_MQ9
);

// Global volatile variable to verify result is not optimized out
volatile char result = -1;

char Read_Sensor_Values_Run() {

    char predicted_spoilage;
    unsigned char test_MQ135, test_MQ136, test_MQ137, test_MQ138, test_MQ2, test_MQ3, test_MQ4, test_MQ5, test_MQ6, test_MQ8, test_MQ9;
    char GPIO;

    test_MQ135 = Testing_MQ135;
    test_MQ136 = Testing_MQ136;
    test_MQ137 = Testing_MQ137;
    test_MQ138 = Testing_MQ138;
    test_MQ2   = Testing_MQ2;
    test_MQ3   = Testing_MQ3;
    test_MQ4   = Testing_MQ4;
    test_MQ5   = Testing_MQ5;
    test_MQ6   = Testing_MQ6;
    test_MQ8   = Testing_MQ8;
    test_MQ9   = Testing_MQ9;

    predicted_spoilage = kernel_predict(test_MQ135, test_MQ136, test_MQ137, test_MQ138, test_MQ2, test_MQ3, test_MQ4, test_MQ5, test_MQ6, test_MQ8, test_MQ9);
    GPIO = predicted_spoilage;

    return GPIO;
}

int main() {
    result = Read_Sensor_Values_Run();
    // printf("Result: %d\n", result);
    return 0;
}
