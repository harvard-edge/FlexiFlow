#include "sample_data.h"
// #include <stdio.h>

volatile char correct_result = -1;

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

int __divsi3(int dividend, int divisor) {
    if (divisor == 0 || dividend == 0)
        return 0;

    int isNegative = (dividend < 0) ^ (divisor < 0);

    unsigned int absDividend = dividend < 0 ? -dividend : dividend;
    unsigned int absDivisor = divisor < 0 ? -divisor : divisor;

    unsigned int result = 0;

    while (absDividend >= absDivisor) {
        unsigned int tempDivisor = absDivisor, multiple = 1;

        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            multiple <<= 1;
        }

        absDividend -= tempDivisor;
        result += multiple;
    }

    return isNegative ? -((int)result) : (int)result;
}

int __modsi3(int dividend, int divisor) {
    if (divisor == 0 || dividend == 0)
        return 0;

    unsigned int absDividend = dividend < 0 ? -dividend : dividend;
    unsigned int absDivisor = divisor < 0 ? -divisor : divisor;

    while (absDividend >= absDivisor) {
        unsigned int tempDivisor = absDivisor;

        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
        }

        absDividend -= tempDivisor;
    }

    return dividend < 0 ? -((int)absDividend) : (int)absDividend;
}

// Helper function to calculate sine using a lookup table
int sine_lookup(int angle) {
    angle = angle % 360;
    return sine_wave_lookup[angle];
}

// Simple DFT function (not an optimized FFT) with integer math
void discrete_fourier_transform(const int* signal, int* real, int* imag) {
    for (int n = 0; n < (Samples_Per_Symbol >> 1); n++) {
        real[n] = 0;
        imag[n] = 0;
        for (int k = 0; k < Samples_Per_Symbol; k++) {
            int angle = (360 * n * k / Samples_Per_Symbol) % 360;
            real[n] += signal[k] * sine_lookup(360 - angle);
            imag[n] += signal[k] * sine_lookup(angle);
        }
    }
}

// Demodulate FSK signal to binary sequence
unsigned char demodulate_fsk_signal(const int* fsk_signal) {
    unsigned char decoded_bits = 0;
    int real[Samples_Per_Symbol >> 1], imag[Samples_Per_Symbol >> 1];
    for (int i = 0; i < Message_Bits; ++i) {
        discrete_fourier_transform(fsk_signal + i*Samples_Per_Symbol, real, imag);
        int index_1 = FREQUENCY_1 * Samples_Per_Symbol / SAMPLE_RATE;
        int index_2 = FREQUENCY_2 * Samples_Per_Symbol / SAMPLE_RATE;
        int power_1 = real[index_1] * real[index_1] + imag[index_1] * imag[index_1];
        int power_2 = real[index_2] * real[index_2] + imag[index_2] * imag[index_2];
        decoded_bits |= (power_1 > power_2) << i; // Set i'th bit
    }
    return decoded_bits;
}

char Read_Input_Signal_Respond() {
    char parity_with_python = 1; // Represents if a response was sent
    unsigned char decoded_sequence, VERIFICATION;
    char Golden_Reference;
    const int *RFID_Input_Signal;
    
    for (int i = 0; i < Num_Data_Samples; ++i) {
        RFID_Input_Signal = &RFID_Input_Signal_Vector[i][0];
        decoded_sequence = demodulate_fsk_signal(RFID_Input_Signal);
        VERIFICATION = Verification_Vector[i];
        Golden_Reference = Golden_Reference_Prediction_Vector[i];
        if ((VERIFICATION == decoded_sequence) != Golden_Reference)
            parity_with_python = 0;
    }
    return parity_with_python;
}

int main() {
    correct_result = Read_Input_Signal_Respond();
    // printf("%d\n", correct_result);

    return 0;
}
