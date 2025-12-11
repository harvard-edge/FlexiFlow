// C implementation of the decision tree (max_depth=2)
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
    if (MQ4 <= 27) {
        if (MQ136 <= 32) {
            return 3;
        } else {
            return 2;
        }
    } else {
        if (MQ138 <= 145) {
            return 1;
        } else {
            return 0;
        }
    }
}
