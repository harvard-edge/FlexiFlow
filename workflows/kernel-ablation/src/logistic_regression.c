// Quantized logistic regression (linear discriminant) model
#define N_CLASSES 4
#define N_FEATURES 11

const short coef_q[N_CLASSES][N_FEATURES] = {
    {-1, -7, -61, -30, 8, 10, 108, 10, -10, 1, 20},
    {8, 44, -21, -19, -2, -26, 38, -1, 18, 8, 7},
    {5, 29, 43, 32, -28, -27, -18, -6, -6, -3, -15},
    {-12, -66, 40, 16, 21, 43, -128, -3, -3, -5, -12}
};

const long intercept_q[N_CLASSES] = {0, 2, -1, -2};

// Predict class for quantized input x_q (uint8_t[N_FEATURES])
char kernel_predict(
    unsigned char MQ135,
    unsigned char MQ136,
    unsigned char MQ137,
    unsigned char MQ138,
    unsigned char MQ2,
    unsigned char MQ3,
    unsigned char MQ4,
    unsigned char MQ5,
    unsigned char MQ6,
    unsigned char MQ8,
    unsigned char MQ9
) {
    unsigned char x_q[N_FEATURES] = {
        MQ135, MQ136, MQ137, MQ138, MQ2, MQ3, MQ4, MQ5, MQ6, MQ8, MQ9
    };
    long logits[N_CLASSES] = {0};
    for (int c = 0; c < N_CLASSES; ++c) {
        long sum = intercept_q[c];
        for (int f = 0; f < N_FEATURES; ++f) {
            sum += coef_q[c][f] * (short)x_q[f];
        }
        logits[c] = sum;
    }
    // Argmax over logits
    int max_idx = 0;
    long max_val = logits[0];
    for (int c = 1; c < N_CLASSES; ++c) {
        if (logits[c] > max_val) {
            max_val = logits[c];
            max_idx = c;
        }
    }
    return max_idx;
}
