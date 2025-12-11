// C implementation of the decision tree (max_depth=5)
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
            if (MQ137 <= 112) {
                return 1;
            } else {
                if (MQ138 <= 26) {
                    if (MQ3 <= 56) {
                        return 2;
                    } else {
                        return 3;
                    }
                } else {
                    if (MQ5 <= 118) {
                        return 3;
                    } else {
                        return 3;
                    }
                }
            }
        } else {
            if (MQ3 <= 49) {
                return 2;
            } else {
                return 3;
            }
        }
    } else {
        if (MQ138 <= 145) {
            if (MQ137 <= 149) {
                if (MQ9 <= 188) {
                    if (MQ135 <= 47) {
                        return 2;
                    } else {
                        return 1;
                    }
                } else {
                    if (MQ4 <= 53) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (MQ3 <= 105) {
                    if (MQ4 <= 37) {
                        return 2;
                    } else {
                        return 1;
                    }
                } else {
                    if (MQ135 <= 126) {
                        return 3;
                    } else {
                        return 2;
                    }
                }
            }
        } else {
            if (MQ4 <= 46) {
                if (MQ5 <= 52) {
                    if (MQ138 <= 158) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            } else {
                if (MQ3 <= 50) {
                    if (MQ138 <= 149) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    if (MQ138 <= 147) {
                        return 0;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}
