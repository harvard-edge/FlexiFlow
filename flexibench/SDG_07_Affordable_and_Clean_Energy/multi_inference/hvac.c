#include "sample_data.h"
// #include <stdio.h>

volatile char correct_result = -1;
int num_incorrect = 0;

char predict_random_forest(unsigned short temperature, unsigned short humidity,
                           unsigned short light, unsigned short co2, unsigned short humidity_ratio);

char Read_Sensor_Values_Run_RF() {
    char occupancy, golden_reference, python_prediction, parity_with_python = 1;
    unsigned short temperature, humidity, light, co2, humidity_ratio;

    for (int i = 0; i < Num_Data_Samples; ++i) {
        temperature = Temperature_Sensor_Sample_Input_Vector[i];
        humidity = Humidity_Sensor_Sample_Input_Vector[i];
        light = Light_Sensor_Sample_Input_Vector[i];
        co2 = CO2_Sensor_Sample_Input_Vector[i];
        humidity_ratio = HumidityRatio_Sensor_Sample_Input_Vector[i];
        golden_reference = Golden_Reference_Occupancy_Vector[i];
        python_prediction = Python_Predicted_Occupancy_Vector[i];
        occupancy = predict_random_forest(temperature, humidity, light, co2, humidity_ratio);

        if (occupancy != python_prediction) {
            parity_with_python = 0;
            num_incorrect++;
        }
    }

    return parity_with_python;
}

int main() {
    correct_result = Read_Sensor_Values_Run_RF();
    // printf("parity: %d, %d\n", correct_result, num_incorrect);

    return 0;
}

int predict_tree_0(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity_ratio <= 245) {
            if (light <= 48) {
                if (co2 <= 68) {
                    return -1;
                } else {
                    if (light <= 31) {
                        if (humidity <= 189) {
                            if (co2 <= 129) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 27) {
                    return -1;
                } else {
                    if (humidity <= 134) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (temperature <= 227) {
            if (co2 <= 7) {
                if (light <= 67) {
                    return 1;
                } else {
                    if (temperature <= 70) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (temperature <= 203) {
                    if (humidity <= 30) {
                        if (humidity <= 30) {
                            if (co2 <= 38) {
                                return 1;
                            } else {
                                if (temperature <= 168) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (temperature <= 200) {
                            if (co2 <= 10) {
                                if (humidity <= 66) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 43) {
                                    if (humidity <= 43) {
                                        if (humidity <= 42) {
                                            return 1;
                                        } else {
                                            if (light <= 79) {
                                                if (light <= 78) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (light <= 79) {
                                            return 1;
                                        } else {
                                            if (co2 <= 63) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (light <= 73) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 122) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 115) {
                        if (co2 <= 82) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (humidity_ratio <= 129) {
                if (humidity <= 111) {
                    return -1;
                } else {
                    if (temperature <= 232) {
                        if (humidity <= 112) {
                            if (co2 <= 102) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_1(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 33) {
        if (co2 <= 13) {
            if (co2 <= 11) {
                if (light <= 63) {
                    if (co2 <= 10) {
                        if (temperature <= 105) {
                            return -1;
                        } else {
                            if (temperature <= 107) {
                                if (co2 <= 7) {
                                    return -1;
                                } else {
                                    if (light <= 29) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (co2 <= 10) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (co2 <= 7) {
                        if (humidity_ratio <= 3) {
                            if (light <= 69) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (co2 <= 9) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (light <= 67) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (light <= 32) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (temperature <= 113) {
            if (humidity_ratio <= 151) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (humidity <= 217) {
                if (light <= 31) {
                    return -1;
                } else {
                    if (temperature <= 234) {
                        if (co2 <= 76) {
                            if (co2 <= 76) {
                                if (humidity <= 100) {
                                    if (humidity_ratio <= 41) {
                                        if (temperature <= 159) {
                                            return 1;
                                        } else {
                                            if (humidity <= 43) {
                                                if (temperature <= 163) {
                                                    return -1;
                                                } else {
                                                    if (light <= 79) {
                                                        if (co2 <= 62) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (light <= 74) {
                                        return 1;
                                    } else {
                                        if (co2 <= 63) {
                                            if (humidity_ratio <= 111) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            } else {
                                if (humidity <= 81) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (temperature <= 227) {
                                if (co2 <= 100) {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        if (co2 <= 99) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity_ratio <= 124) {
                                    return -1;
                                } else {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        if (light <= 91) {
                                            if (humidity_ratio <= 127) {
                                                return -1;
                                            } else {
                                                if (co2 <= 110) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 204) {
                    if (humidity_ratio <= 216) {
                        if (light <= 39) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 37) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 27) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_2(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 28) {
        if (humidity <= 81) {
            if (light <= 63) {
                if (light <= 59) {
                    return -1;
                } else {
                    if (humidity_ratio <= 35) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (light <= 70) {
                    if (humidity <= 24) {
                        if (humidity_ratio <= 3) {
                            return 1;
                        } else {
                            if (temperature <= 71) {
                                return -1;
                            } else {
                                if (temperature <= 73) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (temperature <= 32) {
                return -1;
            } else {
                if (co2 <= 9) {
                    return -1;
                } else {
                    if (light <= 24) {
                        return -1;
                    } else {
                        if (temperature <= 34) {
                            if (humidity_ratio <= 77) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (humidity <= 189) {
            if (light <= 31) {
                if (humidity_ratio <= 173) {
                    return -1;
                } else {
                    if (co2 <= 131) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 227) {
                    if (temperature <= 200) {
                        if (light <= 76) {
                            return 1;
                        } else {
                            if (light <= 76) {
                                if (humidity <= 113) {
                                    return 1;
                                } else {
                                    if (co2 <= 108) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (co2 <= 64) {
                                    if (humidity <= 43) {
                                        if (light <= 79) {
                                            if (light <= 78) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            if (co2 <= 38) {
                                                if (co2 <= 37) {
                                                    return 1;
                                                } else {
                                                    if (temperature <= 153) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (humidity <= 43) {
                                            if (light <= 79) {
                                                return 1;
                                            } else {
                                                if (co2 <= 62) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        if (co2 <= 100) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (co2 <= 79) {
                            if (humidity_ratio <= 119) {
                                if (light <= 81) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        if (co2 <= 64) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 89) {
                        if (temperature <= 230) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 110) {
                            return -1;
                        } else {
                            if (light <= 91) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        } else {
            if (temperature <= 148) {
                return -1;
            } else {
                if (temperature <= 181) {
                    if (humidity <= 229) {
                        if (light <= 37) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 37) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 27) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_3(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (temperature <= 110) {
            if (co2 <= 11) {
                if (light <= 60) {
                    return -1;
                } else {
                    if (co2 <= 7) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 3) {
                            return -1;
                        } else {
                            if (temperature <= 91) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            } else {
                if (light <= 32) {
                    return -1;
                } else {
                    if (temperature <= 36) {
                        if (humidity_ratio <= 77) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (light <= 52) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (co2 <= 27) {
            if (humidity <= 73) {
                if (humidity <= 72) {
                    if (co2 <= 26) {
                        return -1;
                    } else {
                        if (co2 <= 26) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (humidity_ratio <= 56) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (light <= 28) {
                if (co2 <= 132) {
                    return -1;
                } else {
                    if (humidity <= 205) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (temperature <= 227) {
                    if (humidity_ratio <= 115) {
                        if (temperature <= 204) {
                            if (humidity_ratio <= 115) {
                                if (temperature <= 201) {
                                    if (humidity_ratio <= 113) {
                                        if (humidity <= 30) {
                                            if (humidity <= 29) {
                                                return 1;
                                            } else {
                                                if (co2 <= 38) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (light <= 78) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 40) {
                                                    if (humidity_ratio <= 40) {
                                                        return 1;
                                                    } else {
                                                        if (light <= 79) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        if (temperature <= 192) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (humidity_ratio <= 108) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            if (co2 <= 76) {
                                if (humidity_ratio <= 111) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity <= 116) {
                        if (co2 <= 92) {
                            return 1;
                        } else {
                            if (light <= 86) {
                                if (humidity <= 113) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_4(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 62) {
        if (temperature <= 106) {
            if (light <= 48) {
                return -1;
            } else {
                if (humidity_ratio <= 91) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (humidity <= 63) {
                return -1;
            } else {
                if (humidity_ratio <= 48) {
                    if (co2 <= 7) {
                        return -1;
                    } else {
                        if (co2 <= 7) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (co2 <= 67) {
                        return -1;
                    } else {
                        if (humidity <= 94) {
                            return 1;
                        } else {
                            if (humidity <= 189) {
                                if (co2 <= 129) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (co2 <= 7) {
            return -1;
        } else {
            if (humidity_ratio <= 3) {
                return -1;
            } else {
                if (light <= 87) {
                    if (temperature <= 204) {
                        if (temperature <= 34) {
                            if (humidity <= 120) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (co2 <= 10) {
                                if (light <= 70) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (light <= 75) {
                                    return 1;
                                } else {
                                    if (light <= 76) {
                                        if (co2 <= 58) {
                                            if (light <= 75) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (light <= 76) {
                                                return 1;
                                            } else {
                                                if (co2 <= 97) {
                                                    return 1;
                                                } else {
                                                    if (co2 <= 103) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (humidity <= 43) {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                if (temperature <= 171) {
                                                    if (humidity <= 43) {
                                                        if (co2 <= 62) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (temperature <= 190) {
                                                return 1;
                                            } else {
                                                if (humidity <= 112) {
                                                    return 1;
                                                } else {
                                                    if (temperature <= 192) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (humidity_ratio <= 114) {
                            if (light <= 73) {
                                return 1;
                            } else {
                                if (co2 <= 87) {
                                    if (co2 <= 63) {
                                        if (humidity_ratio <= 111) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 87) {
                        if (humidity <= 29) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity <= 106) {
                            if (humidity_ratio <= 27) {
                                if (co2 <= 37) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 230) {
                                if (humidity <= 109) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 110) {
                                    return -1;
                                } else {
                                    if (light <= 89) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_5(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 139) {
        if (co2 <= 18) {
            if (humidity <= 29) {
                if (co2 <= 7) {
                    if (light <= 55) {
                        return -1;
                    } else {
                        if (co2 <= 4) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (humidity_ratio <= 6) {
                        return 1;
                    } else {
                        if (temperature <= 77) {
                            if (temperature <= 73) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (co2 <= 13) {
                                return -1;
                            } else {
                                if (light <= 34) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 13) {
                    if (temperature <= 105) {
                        if (temperature <= 32) {
                            return -1;
                        } else {
                            if (temperature <= 33) {
                                if (humidity_ratio <= 76) {
                                    if (humidity <= 117) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (humidity <= 55) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 47) {
                                if (co2 <= 7) {
                                    if (co2 <= 7) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (humidity <= 54) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (light <= 46) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (co2 <= 31) {
            return -1;
        } else {
            if (temperature <= 227) {
                if (temperature <= 163) {
                    if (humidity <= 214) {
                        if (humidity_ratio <= 38) {
                            if (humidity <= 33) {
                                if (temperature <= 159) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            if (humidity_ratio <= 72) {
                                if (humidity <= 54) {
                                    if (humidity <= 46) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (co2 <= 40) {
                                        if (co2 <= 36) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 176) {
                                    if (humidity_ratio <= 168) {
                                        return 1;
                                    } else {
                                        if (light <= 41) {
                                            if (co2 <= 131) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (light <= 26) {
                        return -1;
                    } else {
                        if (temperature <= 200) {
                            if (humidity_ratio <= 42) {
                                if (humidity <= 43) {
                                    if (light <= 79) {
                                        if (light <= 78) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    if (light <= 76) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 115) {
                                            if (humidity_ratio <= 115) {
                                                if (co2 <= 100) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (temperature <= 209) {
                                if (co2 <= 76) {
                                    if (light <= 73) {
                                        return 1;
                                    } else {
                                        if (humidity <= 106) {
                                            if (humidity_ratio <= 111) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (humidity <= 111) {
                    return -1;
                } else {
                    if (co2 <= 110) {
                        if (humidity <= 112) {
                            if (humidity_ratio <= 124) {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_6(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 65) {
        if (humidity_ratio <= 247) {
            if (temperature <= 142) {
                if (light <= 56) {
                    return -1;
                } else {
                    if (light <= 62) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 85) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (co2 <= 38) {
                    return -1;
                } else {
                    if (co2 <= 40) {
                        return 1;
                    } else {
                        if (humidity <= 189) {
                            if (humidity <= 188) {
                                if (light <= 27) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (co2 <= 7) {
            if (light <= 68) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (light <= 111) {
                if (humidity <= 116) {
                    if (co2 <= 106) {
                        if (humidity_ratio <= 109) {
                            if (temperature <= 107) {
                                if (temperature <= 105) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 33) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 41) {
                                    if (co2 <= 62) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 41) {
                                            if (humidity_ratio <= 40) {
                                                if (humidity <= 41) {
                                                    return 1;
                                                } else {
                                                    if (light <= 79) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (temperature <= 200) {
                                if (humidity <= 113) {
                                    return 1;
                                } else {
                                    if (co2 <= 100) {
                                        if (humidity_ratio <= 116) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity <= 107) {
                                    if (humidity <= 106) {
                                        if (temperature <= 205) {
                                            return -1;
                                        } else {
                                            if (humidity <= 105) {
                                                return 1;
                                            } else {
                                                if (co2 <= 61) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        if (light <= 73) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    if (temperature <= 228) {
                                        if (temperature <= 206) {
                                            if (co2 <= 76) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (humidity_ratio <= 124) {
                                                return 1;
                                            } else {
                                                if (light <= 86) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (humidity_ratio <= 126) {
                            return 1;
                        } else {
                            if (temperature <= 228) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 110) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_7(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (light <= 54) {
            if (light <= 48) {
                return -1;
            } else {
                if (co2 <= 6) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (co2 <= 7) {
                if (light <= 67) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (light <= 65) {
                    if (light <= 65) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 85) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity <= 23) {
                        if (temperature <= 71) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (co2 <= 26) {
            if (light <= 63) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (light <= 28) {
                if (humidity_ratio <= 174) {
                    return -1;
                } else {
                    if (humidity_ratio <= 175) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity <= 104) {
                    if (light <= 89) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 27) {
                            if (co2 <= 37) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity <= 109) {
                        if (co2 <= 76) {
                            if (temperature <= 201) {
                                return 1;
                            } else {
                                if (co2 <= 63) {
                                    if (co2 <= 62) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 122) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (light <= 86) {
                            if (humidity_ratio <= 115) {
                                if (humidity <= 113) {
                                    if (light <= 77) {
                                        return 1;
                                    } else {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 227) {
                                return 1;
                            } else {
                                if (humidity <= 114) {
                                    if (temperature <= 234) {
                                        if (temperature <= 232) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (light <= 91) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_8(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (humidity <= 246) {
            if (co2 <= 10) {
                if (humidity <= 65) {
                    if (humidity_ratio <= 45) {
                        return -1;
                    } else {
                        if (light <= 29) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return -1;
                }
            } else {
                if (light <= 31) {
                    if (co2 <= 132) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 184) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (temperature <= 227) {
            if (humidity_ratio <= 14) {
                if (co2 <= 7) {
                    if (temperature <= 70) {
                        if (temperature <= 69) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity_ratio <= 3) {
                            if (co2 <= 4) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (temperature <= 200) {
                    if (light <= 66) {
                        if (humidity <= 125) {
                            if (humidity_ratio <= 68) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 162) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 27) {
                                if (humidity <= 29) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (light <= 76) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 113) {
                                        if (co2 <= 64) {
                                            if (light <= 79) {
                                                if (co2 <= 63) {
                                                    if (humidity <= 42) {
                                                        if (humidity_ratio <= 39) {
                                                            return 1;
                                                        } else {
                                                            if (humidity_ratio <= 41) {
                                                                if (light <= 78) {
                                                                    return 1;
                                                                } else {
                                                                    if (light <= 78) {
                                                                        return -1;
                                                                    } else {
                                                                        return 1;
                                                                    }
                                                                }
                                                            } else {
                                                                return 1;
                                                            }
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (light <= 76) {
                                            if (co2 <= 103) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (temperature <= 192) {
                                                if (co2 <= 123) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 79) {
                        if (co2 <= 63) {
                            if (humidity_ratio <= 111) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (humidity_ratio <= 122) {
                return 1;
            } else {
                if (co2 <= 111) {
                    if (temperature <= 228) {
                        if (light <= 86) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (temperature <= 232) {
                            return -1;
                        } else {
                            if (co2 <= 97) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_9(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 111) {
        if (temperature <= 104) {
            if (light <= 47) {
                return -1;
            } else {
                if (humidity <= 23) {
                    if (temperature <= 73) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 12) {
                        if (humidity_ratio <= 77) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (co2 <= 9) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (co2 <= 7) {
                        if (humidity_ratio <= 48) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 161) {
                    if (co2 <= 20) {
                        if (humidity <= 31) {
                            return -1;
                        } else {
                            if (light <= 35) {
                                return -1;
                            } else {
                                if (humidity <= 48) {
                                    return 1;
                                } else {
                                    if (temperature <= 107) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            }
        }
    } else {
        if (co2 <= 22) {
            if (humidity_ratio <= 58) {
                if (humidity <= 55) {
                    return -1;
                } else {
                    if (humidity <= 69) {
                        return 1;
                    } else {
                        if (light <= 33) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (humidity <= 217) {
                if (humidity <= 108) {
                    if (humidity_ratio <= 111) {
                        if (humidity_ratio <= 37) {
                            if (humidity <= 35) {
                                if (light <= 35) {
                                    return -1;
                                } else {
                                    if (humidity_ratio <= 27) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 28) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (co2 <= 54) {
                                    if (humidity_ratio <= 24) {
                                        if (humidity_ratio <= 23) {
                                            if (humidity_ratio <= 23) {
                                                return 1;
                                            } else {
                                                if (co2 <= 30) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (light <= 43) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (humidity_ratio <= 35) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (co2 <= 58) {
                                if (humidity_ratio <= 40) {
                                    if (temperature <= 156) {
                                        if (co2 <= 40) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity_ratio <= 63) {
                                        if (light <= 36) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (light <= 34) {
                                            return -1;
                                        } else {
                                            if (humidity <= 95) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 110) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (light <= 35) {
                                    return -1;
                                } else {
                                    if (co2 <= 64) {
                                        if (temperature <= 202) {
                                            if (co2 <= 64) {
                                                if (humidity <= 43) {
                                                    if (humidity_ratio <= 41) {
                                                        return 1;
                                                    } else {
                                                        if (light <= 84) {
                                                            if (co2 <= 63) {
                                                                return 1;
                                                            } else {
                                                                return -1;
                                                            }
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            if (humidity_ratio <= 111) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (temperature <= 237) {
                            if (co2 <= 95) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 122) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (co2 <= 130) {
                        if (humidity <= 181) {
                            if (temperature <= 234) {
                                if (temperature <= 227) {
                                    if (co2 <= 100) {
                                        if (humidity_ratio <= 117) {
                                            if (co2 <= 100) {
                                                if (temperature <= 203) {
                                                    if (humidity <= 112) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (co2 <= 108) {
                                        if (co2 <= 102) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            if (co2 <= 114) {
                                if (humidity <= 184) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity_ratio <= 173) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (light <= 27) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_10(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (humidity_ratio <= 115) {
            if (humidity <= 150) {
                if (humidity <= 148) {
                    if (co2 <= 13) {
                        if (light <= 53) {
                            return -1;
                        } else {
                            if (humidity <= 25) {
                                if (co2 <= 7) {
                                    if (humidity_ratio <= 3) {
                                        if (humidity_ratio <= 3) {
                                            if (co2 <= 5) {
                                                if (light <= 69) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity_ratio <= 77) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (humidity <= 79) {
                            if (co2 <= 13) {
                                return 1;
                            } else {
                                if (co2 <= 19) {
                                    if (humidity <= 28) {
                                        return 1;
                                    } else {
                                        if (light <= 34) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (humidity <= 32) {
                                        if (humidity_ratio <= 18) {
                                            return 1;
                                        } else {
                                            if (co2 <= 22) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (temperature <= 63) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                return -1;
            }
        } else {
            if (light <= 35) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (humidity <= 40) {
            if (co2 <= 27) {
                if (humidity <= 34) {
                    return -1;
                } else {
                    if (light <= 37) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity_ratio <= 27) {
                    if (humidity <= 36) {
                        if (humidity <= 30) {
                            if (humidity <= 29) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 37) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (temperature <= 167) {
                        if (humidity <= 30) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (co2 <= 54) {
                            if (co2 <= 53) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (co2 <= 58) {
                if (light <= 33) {
                    return -1;
                } else {
                    if (humidity_ratio <= 93) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (temperature <= 228) {
                    if (light <= 48) {
                        if (humidity_ratio <= 175) {
                            if (humidity <= 188) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity_ratio <= 115) {
                            if (humidity <= 104) {
                                if (humidity <= 43) {
                                    if (humidity <= 43) {
                                        if (humidity <= 42) {
                                            return 1;
                                        } else {
                                            if (temperature <= 170) {
                                                if (co2 <= 62) {
                                                    return 1;
                                                } else {
                                                    if (co2 <= 62) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (light <= 80) {
                                            return 1;
                                        } else {
                                            if (co2 <= 63) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 107) {
                                    if (temperature <= 198) {
                                        return 1;
                                    } else {
                                        if (co2 <= 87) {
                                            if (humidity <= 106) {
                                                if (humidity <= 105) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (temperature <= 203) {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            if (co2 <= 99) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (light <= 79) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 110) {
                        if (humidity <= 105) {
                            if (humidity <= 104) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 113) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 129) {
                            return 1;
                        } else {
                            if (light <= 89) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_11(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (temperature <= 188) {
            if (light <= 48) {
                return -1;
            } else {
                if (light <= 48) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (co2 <= 90) {
                if (humidity <= 49) {
                    return -1;
                } else {
                    if (humidity <= 95) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (light <= 28) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (humidity <= 24) {
            if (light <= 67) {
                return 1;
            } else {
                if (co2 <= 7) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (temperature <= 230) {
                if (temperature <= 200) {
                    if (temperature <= 34) {
                        if (light <= 67) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 25) {
                            if (temperature <= 91) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (humidity <= 30) {
                                if (temperature <= 164) {
                                    if (humidity_ratio <= 26) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 10) {
                                    return -1;
                                } else {
                                    if (light <= 76) {
                                        return 1;
                                    } else {
                                        if (light <= 76) {
                                            if (humidity <= 150) {
                                                if (humidity_ratio <= 111) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (humidity_ratio <= 40) {
                                                if (humidity <= 41) {
                                                    return 1;
                                                } else {
                                                    if (humidity_ratio <= 40) {
                                                        return 1;
                                                    } else {
                                                        if (co2 <= 62) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 114) {
                        if (co2 <= 76) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 227) {
                            return 1;
                        } else {
                            if (co2 <= 107) {
                                if (light <= 104) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (temperature <= 240) {
                    if (temperature <= 232) {
                        if (light <= 89) {
                            if (humidity <= 115) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            }
        }
    }
}
int predict_tree_12(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 62) {
        if (light <= 35) {
            return -1;
        } else {
            if (co2 <= 24) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (humidity <= 25) {
            if (light <= 69) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
        } else {
            if (humidity <= 116) {
                if (temperature <= 200) {
                    if (humidity <= 112) {
                        if (humidity <= 42) {
                            if (co2 <= 62) {
                                if (temperature <= 163) {
                                    if (humidity_ratio <= 27) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (light <= 79) {
                                    if (temperature <= 171) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (co2 <= 11) {
                                if (humidity <= 66) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 192) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 115) {
                                if (humidity_ratio <= 115) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (light <= 73) {
                        return 1;
                    } else {
                        if (humidity <= 110) {
                            if (temperature <= 223) {
                                if (co2 <= 63) {
                                    if (humidity <= 105) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                if (humidity <= 106) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (temperature <= 227) {
                                return 1;
                            } else {
                                if (co2 <= 108) {
                                    if (co2 <= 101) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (humidity_ratio <= 129) {
                                        return 1;
                                    } else {
                                        if (co2 <= 110) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_13(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (co2 <= 231) {
            if (humidity_ratio <= 85) {
                if (light <= 59) {
                    return -1;
                } else {
                    if (light <= 59) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity <= 105) {
                    return 1;
                } else {
                    if (temperature <= 153) {
                        return -1;
                    } else {
                        if (temperature <= 157) {
                            if (humidity_ratio <= 175) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity <= 25) {
            if (light <= 70) {
                if (humidity_ratio <= 5) {
                    if (humidity <= 22) {
                        return 1;
                    } else {
                        if (humidity <= 22) {
                            if (light <= 69) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
        } else {
            if (light <= 94) {
                if (co2 <= 12) {
                    if (humidity <= 120) {
                        if (humidity_ratio <= 48) {
                            if (temperature <= 91) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (temperature <= 227) {
                        if (temperature <= 204) {
                            if (light <= 74) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 109) {
                                    if (humidity_ratio <= 41) {
                                        if (humidity_ratio <= 41) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity <= 106) {
                                        return -1;
                                    } else {
                                        if (humidity_ratio <= 115) {
                                            if (humidity_ratio <= 115) {
                                                if (light <= 77) {
                                                    return 1;
                                                } else {
                                                    if (humidity <= 112) {
                                                        return 1;
                                                    } else {
                                                        if (humidity_ratio <= 114) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (humidity_ratio <= 114) {
                                if (humidity_ratio <= 108) {
                                    return 1;
                                } else {
                                    if (co2 <= 76) {
                                        if (co2 <= 63) {
                                            if (co2 <= 61) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 230) {
                            return -1;
                        } else {
                            if (humidity <= 109) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 128) {
                                    return -1;
                                } else {
                                    if (co2 <= 110) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 97) {
                    if (temperature <= 199) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 109) {
                        return 1;
                    } else {
                        if (light <= 102) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_14(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (co2 <= 13) {
            if (co2 <= 10) {
                if (light <= 63) {
                    if (temperature <= 105) {
                        return -1;
                    } else {
                        if (light <= 59) {
                            return -1;
                        } else {
                            if (light <= 59) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 91) {
                        if (light <= 69) {
                            return 1;
                        } else {
                            if (co2 <= 7) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (light <= 67) {
                    if (co2 <= 10) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (co2 <= 54) {
                if (humidity <= 79) {
                    if (humidity <= 36) {
                        if (light <= 29) {
                            return -1;
                        } else {
                            if (light <= 89) {
                                if (light <= 87) {
                                    return 1;
                                } else {
                                    if (light <= 87) {
                                        if (humidity <= 30) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (light <= 89) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (light <= 40) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 104) {
                    if (humidity <= 45) {
                        if (humidity_ratio <= 36) {
                            return -1;
                        } else {
                            if (temperature <= 164) {
                                return -1;
                            } else {
                                if (light <= 81) {
                                    if (co2 <= 64) {
                                        if (humidity <= 43) {
                                            if (light <= 78) {
                                                if (humidity <= 42) {
                                                    if (co2 <= 61) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (light <= 81) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (humidity <= 69) {
                            if (co2 <= 58) {
                                if (humidity_ratio <= 46) {
                                    return 1;
                                } else {
                                    if (light <= 36) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 82) {
                                return -1;
                            } else {
                                if (light <= 35) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 86) {
                        if (co2 <= 63) {
                            if (light <= 74) {
                                return 1;
                            } else {
                                if (humidity <= 105) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity_ratio <= 113) {
                            return 1;
                        } else {
                            if (co2 <= 100) {
                                if (light <= 76) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (light <= 41) {
            if (light <= 5) {
                return -1;
            } else {
                if (light <= 5) {
                    if (co2 <= 110) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (temperature <= 227) {
                return 1;
            } else {
                if (light <= 102) {
                    if (co2 <= 92) {
                        return 1;
                    } else {
                        if (co2 <= 110) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_15(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (light <= 62) {
            if (light <= 59) {
                if (humidity <= 117) {
                    return -1;
                } else {
                    if (humidity <= 118) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 35) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (humidity <= 25) {
                if (humidity <= 24) {
                    if (humidity <= 22) {
                        if (light <= 69) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (humidity_ratio <= 9) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 13) {
                    if (light <= 67) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (light <= 31) {
            return -1;
        } else {
            if (humidity <= 116) {
                if (temperature <= 200) {
                    if (co2 <= 99) {
                        if (light <= 79) {
                            return 1;
                        } else {
                            if (temperature <= 170) {
                                if (humidity <= 43) {
                                    if (humidity <= 30) {
                                        if (temperature <= 164) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (co2 <= 65) {
                                        if (humidity_ratio <= 42) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (co2 <= 99) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 115) {
                                if (humidity_ratio <= 115) {
                                    if (temperature <= 191) {
                                        if (temperature <= 190) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (co2 <= 77) {
                        if (humidity_ratio <= 111) {
                            if (co2 <= 61) {
                                return -1;
                            } else {
                                if (co2 <= 63) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity_ratio <= 123) {
                            if (co2 <= 93) {
                                if (humidity <= 105) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (co2 <= 98) {
                                return -1;
                            } else {
                                if (light <= 91) {
                                    if (humidity_ratio <= 124) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_16(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (temperature <= 102) {
            if (humidity_ratio <= 81) {
                if (co2 <= 10) {
                    if (humidity_ratio <= 6) {
                        if (temperature <= 69) {
                            return -1;
                        } else {
                            if (light <= 68) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 4) {
                                    if (temperature <= 73) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (co2 <= 10) {
                            return -1;
                        } else {
                            if (light <= 24) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 11) {
                        return 1;
                    } else {
                        if (light <= 67) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (co2 <= 10) {
                    return -1;
                } else {
                    if (humidity <= 159) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (co2 <= 17) {
                if (humidity <= 55) {
                    return -1;
                } else {
                    if (light <= 51) {
                        return -1;
                    } else {
                        if (temperature <= 107) {
                            if (humidity_ratio <= 48) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (humidity <= 33) {
                    if (humidity_ratio <= 18) {
                        if (co2 <= 19) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (temperature <= 118) {
                            if (co2 <= 19) {
                                if (light <= 35) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (light <= 33) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (light <= 38) {
            if (light <= 5) {
                return -1;
            } else {
                if (humidity_ratio <= 146) {
                    return -1;
                } else {
                    if (co2 <= 131) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (temperature <= 227) {
                if (humidity <= 113) {
                    if (light <= 75) {
                        if (light <= 74) {
                            return 1;
                        } else {
                            if (temperature <= 201) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 108) {
                            if (temperature <= 170) {
                                if (humidity <= 30) {
                                    if (temperature <= 163) {
                                        if (humidity_ratio <= 26) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity <= 43) {
                                        if (humidity_ratio <= 41) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (co2 <= 76) {
                                if (light <= 75) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                if (temperature <= 191) {
                                    if (temperature <= 190) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (light <= 76) {
                                        if (humidity <= 113) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity_ratio <= 123) {
                    return 1;
                } else {
                    if (humidity <= 116) {
                        if (humidity_ratio <= 125) {
                            if (co2 <= 96) {
                                return -1;
                            } else {
                                if (temperature <= 229) {
                                    if (light <= 86) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_17(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (temperature <= 36) {
            if (light <= 69) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (light <= 62) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (co2 <= 7) {
                        if (light <= 58) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 7) {
                    if (humidity_ratio <= 3) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (light <= 70) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
    } else {
        if (temperature <= 113) {
            if (humidity_ratio <= 150) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (co2 <= 58) {
                if (humidity_ratio <= 27) {
                    if (humidity <= 35) {
                        if (light <= 46) {
                            return -1;
                        } else {
                            if (light <= 89) {
                                return 1;
                            } else {
                                if (humidity <= 28) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (humidity <= 80) {
                        if (light <= 38) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity_ratio <= 93) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (light <= 37) {
                    if (light <= 5) {
                        return -1;
                    } else {
                        if (temperature <= 182) {
                            if (co2 <= 131) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (light <= 87) {
                        if (temperature <= 204) {
                            if (temperature <= 190) {
                                if (humidity <= 43) {
                                    if (light <= 79) {
                                        if (humidity_ratio <= 41) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 41) {
                                                if (co2 <= 61) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 100) {
                                    if (co2 <= 100) {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            if (humidity <= 113) {
                                                if (co2 <= 99) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity <= 107) {
                                if (humidity <= 104) {
                                    return 1;
                                } else {
                                    if (co2 <= 83) {
                                        if (co2 <= 63) {
                                            if (co2 <= 62) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 230) {
                            if (light <= 87) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 117) {
                                    if (light <= 93) {
                                        if (temperature <= 203) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (co2 <= 112) {
                                if (humidity_ratio <= 125) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_18(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (light <= 61) {
            if (light <= 59) {
                if (co2 <= 39) {
                    return -1;
                } else {
                    if (light <= 35) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 156) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (co2 <= 7) {
                return -1;
            } else {
                if (humidity_ratio <= 111) {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        if (temperature <= 201) {
                            if (temperature <= 36) {
                                if (temperature <= 34) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (humidity_ratio <= 48) {
                                    if (humidity_ratio <= 48) {
                                        if (light <= 78) {
                                            return 1;
                                        } else {
                                            if (temperature <= 170) {
                                                if (co2 <= 65) {
                                                    if (co2 <= 62) {
                                                        if (light <= 86) {
                                                            return 1;
                                                        } else {
                                                            if (co2 <= 37) {
                                                                return 1;
                                                            } else {
                                                                if (humidity <= 30) {
                                                                    return -1;
                                                                } else {
                                                                    return 1;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (light <= 83) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (light <= 74) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 110) {
                                    return -1;
                                } else {
                                    if (humidity <= 105) {
                                        if (light <= 81) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (humidity <= 107) {
                        if (co2 <= 89) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 80) {
                            if (light <= 76) {
                                return 1;
                            } else {
                                if (humidity <= 113) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            }
        }
    } else {
        if (light <= 41) {
            if (humidity <= 189) {
                if (temperature <= 154) {
                    return -1;
                } else {
                    if (temperature <= 187) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                return -1;
            }
        } else {
            if (light <= 93) {
                if (temperature <= 229) {
                    return 1;
                } else {
                    if (humidity_ratio <= 128) {
                        return 1;
                    } else {
                        if (light <= 89) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (co2 <= 97) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_19(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (light <= 62) {
            if (humidity_ratio <= 47) {
                return -1;
            } else {
                if (co2 <= 10) {
                    if (light <= 54) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity <= 117) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (humidity_ratio <= 109) {
                if (co2 <= 7) {
                    if (co2 <= 7) {
                        if (co2 <= 4) {
                            if (humidity_ratio <= 3) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (co2 <= 7) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (humidity_ratio <= 28) {
                        if (humidity_ratio <= 27) {
                            if (light <= 89) {
                                return 1;
                            } else {
                                if (temperature <= 163) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (temperature <= 34) {
                            if (light <= 67) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 43) {
                                if (temperature <= 170) {
                                    if (humidity <= 43) {
                                        if (light <= 78) {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (temperature <= 169) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 85) {
                    if (co2 <= 54) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 114) {
                            if (light <= 75) {
                                return -1;
                            } else {
                                if (co2 <= 64) {
                                    if (co2 <= 61) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity <= 113) {
                        return 1;
                    } else {
                        if (co2 <= 100) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (temperature <= 111) {
            if (humidity_ratio <= 147) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (humidity <= 109) {
                if (temperature <= 240) {
                    return -1;
                } else {
                    if (light <= 92) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (light <= 41) {
                    return -1;
                } else {
                    if (humidity <= 116) {
                        if (temperature <= 229) {
                            return 1;
                        } else {
                            if (co2 <= 112) {
                                if (humidity <= 112) {
                                    if (temperature <= 237) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_20(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity <= 247) {
            if (light <= 56) {
                if (light <= 35) {
                    return -1;
                } else {
                    if (light <= 35) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 72) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity <= 24) {
            if (light <= 67) {
                return 1;
            } else {
                if (co2 <= 7) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (humidity <= 116) {
                if (light <= 94) {
                    if (humidity <= 104) {
                        if (humidity <= 43) {
                            if (co2 <= 62) {
                                return 1;
                            } else {
                                if (humidity <= 43) {
                                    if (temperature <= 169) {
                                        if (light <= 79) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (light <= 80) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            if (light <= 70) {
                                if (co2 <= 10) {
                                    if (humidity <= 66) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (co2 <= 74) {
                            if (humidity <= 107) {
                                if (light <= 80) {
                                    if (humidity <= 106) {
                                        if (humidity <= 105) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (co2 <= 67) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 124) {
                                return 1;
                            } else {
                                if (light <= 91) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 97) {
                        if (co2 <= 62) {
                            if (light <= 167) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (temperature <= 230) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 126) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_21(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 138) {
        if (light <= 55) {
            return -1;
        } else {
            if (co2 <= 7) {
                if (light <= 67) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (temperature <= 36) {
                    if (humidity <= 120) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 10) {
                        if (humidity <= 46) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 48) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (co2 <= 31) {
            return -1;
        } else {
            if (co2 <= 58) {
                if (light <= 46) {
                    return -1;
                } else {
                    if (humidity_ratio <= 93) {
                        if (light <= 89) {
                            return 1;
                        } else {
                            if (temperature <= 165) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (light <= 27) {
                    if (light <= 5) {
                        return -1;
                    } else {
                        if (co2 <= 131) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (temperature <= 204) {
                        if (co2 <= 99) {
                            return 1;
                        } else {
                            if (co2 <= 99) {
                                if (temperature <= 192) {
                                    return -1;
                                } else {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 207) {
                            if (co2 <= 82) {
                                if (co2 <= 63) {
                                    if (temperature <= 205) {
                                        return -1;
                                    } else {
                                        if (humidity_ratio <= 110) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 230) {
                                if (temperature <= 227) {
                                    return 1;
                                } else {
                                    if (temperature <= 229) {
                                        if (co2 <= 102) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 130) {
                                        if (temperature <= 234) {
                                            if (humidity <= 112) {
                                                return 1;
                                            } else {
                                                if (co2 <= 110) {
                                                    return -1;
                                                } else {
                                                    if (light <= 89) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                }
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_22(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity <= 246) {
            if (humidity_ratio <= 175) {
                if (light <= 59) {
                    if (temperature <= 188) {
                        if (humidity <= 117) {
                            return -1;
                        } else {
                            if (light <= 47) {
                                return -1;
                            } else {
                                if (humidity <= 133) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (co2 <= 38) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 99) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (humidity <= 38) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 189) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (co2 <= 7) {
            if (humidity <= 22) {
                if (light <= 69) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                return -1;
            }
        } else {
            if (temperature <= 234) {
                if (temperature <= 204) {
                    if (co2 <= 13) {
                        if (humidity_ratio <= 77) {
                            if (light <= 68) {
                                if (temperature <= 74) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (temperature <= 162) {
                            return 1;
                        } else {
                            if (light <= 76) {
                                return 1;
                            } else {
                                if (humidity <= 112) {
                                    if (temperature <= 163) {
                                        if (humidity_ratio <= 36) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (humidity_ratio <= 42) {
                                            if (humidity <= 43) {
                                                if (humidity <= 42) {
                                                    return 1;
                                                } else {
                                                    if (co2 <= 62) {
                                                        return 1;
                                                    } else {
                                                        if (light <= 79) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (light <= 76) {
                                        return -1;
                                    } else {
                                        if (co2 <= 100) {
                                            if (temperature <= 197) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (temperature <= 206) {
                        if (light <= 74) {
                            return 1;
                        } else {
                            if (co2 <= 87) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 227) {
                            if (humidity_ratio <= 113) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 91) {
                                if (temperature <= 228) {
                                    if (light <= 86) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                if (humidity <= 115) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 128) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (humidity_ratio <= 122) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
    }
}
int predict_tree_23(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 65) {
        if (humidity <= 247) {
            if (co2 <= 18) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (co2 <= 7) {
                        if (temperature <= 103) {
                            return -1;
                        } else {
                            if (light <= 58) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 18) {
                    return 1;
                } else {
                    if (temperature <= 68) {
                        return 1;
                    } else {
                        if (light <= 31) {
                            if (co2 <= 131) {
                                return -1;
                            } else {
                                if (light <= 3) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity <= 24) {
            return -1;
        } else {
            if (humidity_ratio <= 128) {
                if (humidity_ratio <= 109) {
                    if (temperature <= 36) {
                        if (humidity <= 121) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (light <= 87) {
                            if (temperature <= 107) {
                                if (light <= 70) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (co2 <= 62) {
                                    if (light <= 78) {
                                        return 1;
                                    } else {
                                        if (light <= 79) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (temperature <= 164) {
                                if (humidity <= 30) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (humidity <= 107) {
                        if (light <= 74) {
                            if (co2 <= 83) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 197) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (temperature <= 227) {
                            if (light <= 76) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 115) {
                                    if (light <= 76) {
                                        return -1;
                                    } else {
                                        if (light <= 83) {
                                            if (humidity <= 112) {
                                                return 1;
                                            } else {
                                                if (co2 <= 100) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (co2 <= 101) {
                                if (temperature <= 234) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (light <= 90) {
                                    return -1;
                                } else {
                                    if (light <= 96) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_24(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 62) {
        if (humidity <= 247) {
            if (co2 <= 40) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (light <= 59) {
                        if (humidity <= 117) {
                            return -1;
                        } else {
                            if (light <= 24) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 236) {
                    if (humidity_ratio <= 28) {
                        if (humidity <= 34) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 189) {
                            if (co2 <= 131) {
                                if (humidity <= 82) {
                                    return -1;
                                } else {
                                    if (humidity_ratio <= 85) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (light <= 86) {
            if (co2 <= 7) {
                return -1;
            } else {
                if (co2 <= 13) {
                    if (light <= 67) {
                        return -1;
                    } else {
                        if (co2 <= 10) {
                            if (light <= 70) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 76) {
                        if (co2 <= 76) {
                            if (temperature <= 200) {
                                if (humidity <= 43) {
                                    if (co2 <= 62) {
                                        return 1;
                                    } else {
                                        if (temperature <= 171) {
                                            if (co2 <= 62) {
                                                return -1;
                                            } else {
                                                if (humidity <= 43) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 63) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (temperature <= 202) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 115) {
                            if (humidity_ratio <= 115) {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    if (humidity <= 113) {
                                        if (light <= 77) {
                                            if (co2 <= 99) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (humidity <= 80) {
                if (humidity_ratio <= 18) {
                    return -1;
                } else {
                    if (humidity <= 29) {
                        if (temperature <= 163) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 227) {
                    if (co2 <= 85) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (co2 <= 110) {
                        if (light <= 113) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity_ratio <= 129) {
                            if (temperature <= 230) {
                                return 1;
                            } else {
                                if (co2 <= 110) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_25(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (temperature <= 138) {
            if (light <= 48) {
                return -1;
            } else {
                if (co2 <= 13) {
                    if (humidity <= 25) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 77) {
                            if (humidity <= 66) {
                                if (light <= 69) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (co2 <= 33) {
                return -1;
            } else {
                if (temperature <= 204) {
                    if (light <= 28) {
                        return -1;
                    } else {
                        if (temperature <= 200) {
                            if (humidity <= 112) {
                                if (co2 <= 64) {
                                    if (co2 <= 63) {
                                        if (co2 <= 62) {
                                            if (co2 <= 38) {
                                                if (light <= 90) {
                                                    if (humidity <= 30) {
                                                        if (humidity <= 29) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (co2 <= 62) {
                                                if (temperature <= 171) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (light <= 76) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (light <= 73) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 109) {
                        return 1;
                    } else {
                        if (co2 <= 91) {
                            if (light <= 75) {
                                return -1;
                            } else {
                                if (light <= 75) {
                                    return 1;
                                } else {
                                    if (humidity <= 107) {
                                        return -1;
                                    } else {
                                        if (light <= 82) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (co2 <= 98) {
            if (light <= 31) {
                return -1;
            } else {
                if (temperature <= 241) {
                    if (light <= 96) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (light <= 5) {
                return -1;
            } else {
                if (humidity <= 116) {
                    if (humidity_ratio <= 126) {
                        if (light <= 82) {
                            return 1;
                        } else {
                            if (light <= 88) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (light <= 100) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (temperature <= 157) {
                        if (co2 <= 131) {
                            if (co2 <= 130) {
                                if (light <= 44) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_26(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (light <= 63) {
            return -1;
        } else {
            if (humidity <= 25) {
                if (light <= 69) {
                    if (humidity_ratio <= 4) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            } else {
                if (light <= 70) {
                    if (temperature <= 36) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (temperature <= 69) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
    } else {
        if (humidity <= 189) {
            if (light <= 46) {
                if (humidity <= 188) {
                    return -1;
                } else {
                    if (humidity_ratio <= 175) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (temperature <= 240) {
                    if (co2 <= 76) {
                        if (humidity_ratio <= 107) {
                            if (humidity <= 30) {
                                if (temperature <= 163) {
                                    if (light <= 86) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (light <= 79) {
                                    return 1;
                                } else {
                                    if (co2 <= 63) {
                                        return 1;
                                    } else {
                                        if (temperature <= 169) {
                                            if (co2 <= 65) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (temperature <= 200) {
                                return 1;
                            } else {
                                if (co2 <= 62) {
                                    if (co2 <= 61) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (humidity <= 112) {
                            return 1;
                        } else {
                            if (humidity <= 113) {
                                if (co2 <= 99) {
                                    return -1;
                                } else {
                                    if (light <= 86) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (temperature <= 230) {
                                    return 1;
                                } else {
                                    if (humidity <= 116) {
                                        if (light <= 91) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (humidity_ratio <= 173) {
                return -1;
            } else {
                if (humidity_ratio <= 235) {
                    if (temperature <= 146) {
                        return -1;
                    } else {
                        if (light <= 39) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 219) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_27(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 32) {
        if (light <= 62) {
            if (humidity_ratio <= 47) {
                return -1;
            } else {
                if (humidity <= 65) {
                    if (co2 <= 7) {
                        if (co2 <= 7) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (temperature <= 32) {
                        return -1;
                    } else {
                        if (temperature <= 33) {
                            if (humidity_ratio <= 74) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            }
        } else {
            if (humidity_ratio <= 4) {
                if (temperature <= 73) {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity <= 22) {
                        if (temperature <= 74) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity <= 25) {
                    if (temperature <= 91) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 13) {
                        if (light <= 66) {
                            return -1;
                        } else {
                            if (humidity <= 66) {
                                if (light <= 69) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (light <= 28) {
            return -1;
        } else {
            if (temperature <= 228) {
                if (humidity <= 113) {
                    if (temperature <= 203) {
                        if (temperature <= 190) {
                            if (light <= 87) {
                                if (humidity <= 43) {
                                    if (humidity_ratio <= 41) {
                                        return 1;
                                    } else {
                                        if (temperature <= 170) {
                                            if (light <= 79) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (temperature <= 163) {
                                    if (co2 <= 53) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 115) {
                                if (humidity <= 112) {
                                    if (temperature <= 201) {
                                        return 1;
                                    } else {
                                        if (humidity <= 103) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    if (temperature <= 192) {
                                        return -1;
                                    } else {
                                        if (co2 <= 100) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (co2 <= 102) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (light <= 74) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 118) {
                                if (co2 <= 63) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity_ratio <= 122) {
                    return 1;
                } else {
                    if (co2 <= 110) {
                        if (light <= 117) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 111) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_28(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (light <= 61) {
            if (co2 <= 66) {
                if (light <= 59) {
                    if (temperature <= 142) {
                        return -1;
                    } else {
                        if (temperature <= 144) {
                            if (co2 <= 38) {
                                return -1;
                            } else {
                                if (co2 <= 40) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (light <= 59) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 85) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (humidity <= 104) {
                if (co2 <= 11) {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        if (light <= 70) {
                            if (temperature <= 69) {
                                return -1;
                            } else {
                                if (light <= 68) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 4) {
                                        if (light <= 69) {
                                            return -1;
                                        } else {
                                            if (co2 <= 6) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (humidity <= 43) {
                        if (humidity <= 43) {
                            if (humidity <= 30) {
                                if (temperature <= 163) {
                                    if (light <= 86) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 171) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 76) {
                    if (temperature <= 200) {
                        if (humidity_ratio <= 81) {
                            if (co2 <= 11) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 80) {
                            return -1;
                        } else {
                            if (light <= 81) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (humidity <= 112) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 114) {
                            return -1;
                        } else {
                            if (humidity <= 113) {
                                if (co2 <= 99) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 113) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (light <= 42) {
            if (humidity <= 189) {
                if (humidity_ratio <= 173) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
        } else {
            if (humidity <= 109) {
                if (co2 <= 92) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (light <= 86) {
                    return 1;
                } else {
                    if (humidity <= 115) {
                        if (humidity <= 112) {
                            if (light <= 101) {
                                return 1;
                            } else {
                                if (humidity <= 111) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (temperature <= 227) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (humidity <= 116) {
                            if (light <= 90) {
                                if (light <= 89) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_29(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (light <= 62) {
            if (co2 <= 10) {
                return -1;
            } else {
                if (co2 <= 10) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (co2 <= 13) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (humidity <= 120) {
                        if (humidity_ratio <= 3) {
                            return -1;
                        } else {
                            if (temperature <= 94) {
                                return 1;
                            } else {
                                if (co2 <= 10) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (light <= 38) {
            return -1;
        } else {
            if (humidity <= 114) {
                if (temperature <= 204) {
                    if (humidity <= 112) {
                        if (humidity <= 30) {
                            if (temperature <= 165) {
                                if (humidity_ratio <= 26) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 79) {
                                return 1;
                            } else {
                                if (light <= 79) {
                                    if (temperature <= 169) {
                                        if (humidity_ratio <= 41) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (light <= 81) {
                                        if (light <= 81) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 41) {
                                                return 1;
                                            } else {
                                                if (humidity <= 46) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (co2 <= 100) {
                            if (co2 <= 82) {
                                return 1;
                            } else {
                                if (light <= 75) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 74) {
                        if (light <= 73) {
                            return 1;
                        } else {
                            if (humidity <= 108) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 117) {
                            if (humidity_ratio <= 111) {
                                if (humidity <= 105) {
                                    if (light <= 78) {
                                        return -1;
                                    } else {
                                        if (co2 <= 63) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            if (humidity_ratio <= 123) {
                                if (light <= 92) {
                                    return 1;
                                } else {
                                    if (humidity <= 109) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (light <= 109) {
                                    if (humidity_ratio <= 124) {
                                        if (temperature <= 235) {
                                            if (co2 <= 102) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_30(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (co2 <= 233) {
            if (light <= 35) {
                if (co2 <= 131) {
                    return -1;
                } else {
                    if (light <= 3) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 45) {
                    return -1;
                } else {
                    if (humidity_ratio <= 95) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 115) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (temperature <= 200) {
            if (temperature <= 36) {
                if (humidity_ratio <= 77) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (humidity_ratio <= 4) {
                    if (humidity <= 22) {
                        return 1;
                    } else {
                        if (temperature <= 73) {
                            if (humidity <= 23) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (light <= 116) {
                        if (humidity <= 43) {
                            if (co2 <= 63) {
                                if (humidity <= 29) {
                                    if (humidity <= 29) {
                                        return 1;
                                    } else {
                                        if (light <= 87) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (temperature <= 171) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (co2 <= 79) {
                if (humidity <= 114) {
                    if (humidity_ratio <= 111) {
                        if (humidity_ratio <= 111) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (temperature <= 230) {
                    if (humidity <= 112) {
                        if (humidity <= 112) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity <= 106) {
                        return 1;
                    } else {
                        if (co2 <= 111) {
                            if (light <= 113) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_31(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (co2 <= 132) {
            if (light <= 59) {
                if (co2 <= 40) {
                    return -1;
                } else {
                    if (light <= 35) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 165) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (light <= 3) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (humidity <= 25) {
            if (co2 <= 7) {
                return -1;
            } else {
                if (temperature <= 71) {
                    if (light <= 68) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (temperature <= 228) {
                if (light <= 66) {
                    if (humidity_ratio <= 82) {
                        if (temperature <= 77) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (temperature <= 204) {
                        if (light <= 76) {
                            if (co2 <= 10) {
                                if (light <= 70) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 190) {
                                if (co2 <= 64) {
                                    if (light <= 79) {
                                        if (humidity <= 45) {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                if (co2 <= 63) {
                                                    if (humidity <= 41) {
                                                        return 1;
                                                    } else {
                                                        if (humidity_ratio <= 41) {
                                                            if (light <= 79) {
                                                                return -1;
                                                            } else {
                                                                return 1;
                                                            }
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    if (light <= 76) {
                                        if (humidity_ratio <= 115) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (temperature <= 192) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (co2 <= 76) {
                            if (light <= 75) {
                                if (humidity_ratio <= 110) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (co2 <= 110) {
                    if (co2 <= 92) {
                        return 1;
                    } else {
                        if (temperature <= 230) {
                            if (light <= 104) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (humidity_ratio <= 128) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 129) {
                            if (light <= 89) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_32(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 65) {
        if (humidity_ratio <= 247) {
            if (light <= 59) {
                if (light <= 48) {
                    return -1;
                } else {
                    if (co2 <= 9) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 125) {
                    if (light <= 59) {
                        if (humidity_ratio <= 34) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity <= 25) {
            if (co2 <= 7) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (humidity_ratio <= 129) {
                if (temperature <= 200) {
                    if (humidity_ratio <= 113) {
                        if (temperature <= 36) {
                            if (co2 <= 11) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (humidity_ratio <= 42) {
                                if (humidity_ratio <= 41) {
                                    if (light <= 87) {
                                        if (co2 <= 62) {
                                            return 1;
                                        } else {
                                            if (co2 <= 62) {
                                                if (light <= 80) {
                                                    if (light <= 78) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (temperature <= 164) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (light <= 76) {
                            return 1;
                        } else {
                            if (light <= 76) {
                                if (humidity <= 113) {
                                    if (co2 <= 103) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                if (co2 <= 100) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 76) {
                        if (temperature <= 203) {
                            if (humidity_ratio <= 116) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 106) {
                                if (co2 <= 61) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (light <= 84) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 124) {
                                if (humidity <= 109) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (temperature <= 230) {
                                    if (co2 <= 105) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity <= 115) {
                                        return -1;
                                    } else {
                                        if (co2 <= 110) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_33(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (co2 <= 68) {
            if (light <= 48) {
                return -1;
            } else {
                if (co2 <= 9) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (light <= 31) {
                if (light <= 5) {
                    return -1;
                } else {
                    if (humidity_ratio <= 169) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 175) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (light <= 95) {
            if (humidity_ratio <= 5) {
                if (humidity <= 22) {
                    if (temperature <= 74) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            } else {
                if (light <= 75) {
                    if (co2 <= 13) {
                        if (temperature <= 55) {
                            if (humidity_ratio <= 77) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity <= 116) {
                        if (humidity <= 104) {
                            if (humidity <= 43) {
                                if (humidity <= 43) {
                                    if (co2 <= 38) {
                                        if (temperature <= 164) {
                                            if (humidity_ratio <= 27) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (humidity <= 42) {
                                            return 1;
                                        } else {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                if (light <= 79) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (light <= 79) {
                                        return 1;
                                    } else {
                                        if (co2 <= 63) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 108) {
                                if (temperature <= 198) {
                                    return 1;
                                } else {
                                    if (temperature <= 226) {
                                        if (co2 <= 63) {
                                            if (humidity <= 105) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (co2 <= 106) {
                                    if (temperature <= 227) {
                                        if (co2 <= 84) {
                                            return -1;
                                        } else {
                                            if (co2 <= 100) {
                                                if (co2 <= 100) {
                                                    if (co2 <= 99) {
                                                        return 1;
                                                    } else {
                                                        if (humidity <= 112) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    }
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (light <= 89) {
                                        if (co2 <= 108) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (co2 <= 112) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (humidity <= 111) {
                return -1;
            } else {
                if (temperature <= 230) {
                    return 1;
                } else {
                    if (light <= 102) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_34(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 13) {
        if (light <= 68) {
            if (light <= 59) {
                return -1;
            } else {
                if (humidity_ratio <= 35) {
                    return -1;
                } else {
                    if (humidity <= 93) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (co2 <= 7) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (light <= 31) {
            if (humidity_ratio <= 175) {
                return -1;
            } else {
                if (humidity_ratio <= 175) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (temperature <= 240) {
                if (humidity <= 104) {
                    if (humidity <= 30) {
                        if (humidity <= 30) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (temperature <= 169) {
                            return 1;
                        } else {
                            if (temperature <= 170) {
                                if (light <= 80) {
                                    return 1;
                                } else {
                                    if (light <= 82) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 204) {
                        if (humidity <= 113) {
                            if (co2 <= 99) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 114) {
                                    return 1;
                                } else {
                                    if (co2 <= 101) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 206) {
                            if (light <= 73) {
                                return 1;
                            } else {
                                if (co2 <= 76) {
                                    if (light <= 75) {
                                        if (light <= 75) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 125) {
                                return 1;
                            } else {
                                if (humidity <= 116) {
                                    if (light <= 104) {
                                        if (co2 <= 110) {
                                            if (light <= 91) {
                                                return -1;
                                            } else {
                                                if (humidity_ratio <= 127) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            if (co2 <= 110) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                return -1;
            }
        }
    }
}
int predict_tree_35(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (light <= 62) {
            if (light <= 35) {
                return -1;
            } else {
                if (humidity_ratio <= 26) {
                    return -1;
                } else {
                    if (humidity_ratio <= 94) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (temperature <= 203) {
                if (light <= 98) {
                    if (humidity_ratio <= 4) {
                        return -1;
                    } else {
                        if (temperature <= 36) {
                            if (co2 <= 11) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (co2 <= 11) {
                                if (humidity <= 45) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (humidity <= 30) {
                                    if (temperature <= 163) {
                                        if (temperature <= 159) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (co2 <= 99) {
                                        if (temperature <= 200) {
                                            if (co2 <= 64) {
                                                if (humidity <= 43) {
                                                    if (co2 <= 63) {
                                                        if (humidity <= 42) {
                                                            return 1;
                                                        } else {
                                                            if (light <= 78) {
                                                                if (co2 <= 62) {
                                                                    return 1;
                                                                } else {
                                                                    return -1;
                                                                }
                                                            } else {
                                                                return 1;
                                                            }
                                                        }
                                                    } else {
                                                        if (temperature <= 171) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (humidity <= 104) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        if (co2 <= 99) {
                                            if (humidity_ratio <= 112) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    return -1;
                }
            } else {
                if (humidity <= 104) {
                    return 1;
                } else {
                    if (co2 <= 87) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (temperature <= 107) {
            if (temperature <= 89) {
                if (humidity_ratio <= 139) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (humidity_ratio <= 148) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (co2 <= 97) {
                if (humidity <= 112) {
                    if (humidity <= 106) {
                        if (light <= 31) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity_ratio <= 185) {
                    if (light <= 44) {
                        if (humidity_ratio <= 173) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 175) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (temperature <= 227) {
                            return 1;
                        } else {
                            if (light <= 91) {
                                if (light <= 86) {
                                    if (temperature <= 229) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 153) {
                        return -1;
                    } else {
                        if (co2 <= 213) {
                            if (co2 <= 168) {
                                if (humidity <= 222) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (light <= 36) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (light <= 27) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_36(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 28) {
        if (light <= 62) {
            if (humidity <= 117) {
                return -1;
            } else {
                if (light <= 47) {
                    return -1;
                } else {
                    if (humidity_ratio <= 92) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (co2 <= 7) {
                return -1;
            } else {
                if (temperature <= 36) {
                    if (humidity <= 120) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (light <= 70) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
    } else {
        if (temperature <= 111) {
            if (humidity <= 180) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (light <= 28) {
                return -1;
            } else {
                if (temperature <= 240) {
                    if (humidity_ratio <= 108) {
                        if (humidity <= 30) {
                            if (temperature <= 163) {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 78) {
                                return 1;
                            } else {
                                if (light <= 79) {
                                    if (humidity_ratio <= 41) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (light <= 81) {
                                        if (light <= 81) {
                                            return 1;
                                        } else {
                                            if (temperature <= 169) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 49) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (co2 <= 76) {
                            if (humidity <= 110) {
                                if (temperature <= 200) {
                                    return 1;
                                } else {
                                    if (humidity <= 106) {
                                        if (humidity_ratio <= 110) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 129) {
                                if (temperature <= 230) {
                                    if (light <= 76) {
                                        return 1;
                                    } else {
                                        if (light <= 76) {
                                            if (humidity <= 113) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            if (humidity <= 112) {
                                                if (humidity_ratio <= 124) {
                                                    return 1;
                                                } else {
                                                    if (co2 <= 102) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (temperature <= 232) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return -1;
                }
            }
        }
    }
}
int predict_tree_37(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (light <= 62) {
            if (light <= 48) {
                return -1;
            } else {
                if (co2 <= 9) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (humidity <= 24) {
                if (light <= 67) {
                    return 1;
                } else {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        if (humidity <= 23) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (temperature <= 36) {
                    return -1;
                } else {
                    if (humidity <= 25) {
                        if (humidity_ratio <= 9) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (co2 <= 10) {
                            if (temperature <= 91) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (temperature <= 107) {
            if (temperature <= 89) {
                return 1;
            } else {
                if (humidity_ratio <= 148) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (light <= 31) {
                return -1;
            } else {
                if (light <= 89) {
                    if (co2 <= 76) {
                        if (temperature <= 201) {
                            if (humidity <= 42) {
                                if (humidity_ratio <= 40) {
                                    return 1;
                                } else {
                                    if (humidity <= 42) {
                                        return 1;
                                    } else {
                                        if (co2 <= 62) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (co2 <= 63) {
                                if (temperature <= 205) {
                                    return -1;
                                } else {
                                    if (light <= 75) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (light <= 76) {
                            return 1;
                        } else {
                            if (humidity <= 113) {
                                if (humidity <= 113) {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        if (co2 <= 100) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 230) {
                        if (temperature <= 165) {
                            if (humidity <= 39) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 203) {
                                return 1;
                            } else {
                                if (humidity <= 110) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return -1;
                    }
                }
            }
        }
    }
}
int predict_tree_38(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (light <= 54) {
            return -1;
        } else {
            if (co2 <= 7) {
                return -1;
            } else {
                if (co2 <= 13) {
                    if (humidity <= 120) {
                        if (light <= 68) {
                            if (co2 <= 7) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (light <= 61) {
            if (humidity_ratio <= 83) {
                return -1;
            } else {
                if (humidity <= 84) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (light <= 93) {
                if (co2 <= 74) {
                    if (temperature <= 200) {
                        if (humidity_ratio <= 41) {
                            if (humidity_ratio <= 41) {
                                if (humidity_ratio <= 41) {
                                    if (light <= 87) {
                                        if (temperature <= 168) {
                                            return 1;
                                        } else {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                if (light <= 82) {
                                                    if (temperature <= 171) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        if (temperature <= 163) {
                                            if (co2 <= 38) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (co2 <= 63) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 41) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 113) {
                            if (co2 <= 63) {
                                if (humidity <= 105) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (temperature <= 226) {
                        if (humidity_ratio <= 115) {
                            if (humidity <= 112) {
                                if (light <= 83) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 110) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (temperature <= 192) {
                                    return -1;
                                } else {
                                    if (co2 <= 102) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 102) {
                            return 1;
                        } else {
                            if (co2 <= 107) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (temperature <= 234) {
                    if (temperature <= 230) {
                        if (humidity_ratio <= 118) {
                            if (humidity_ratio <= 79) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 102) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return -1;
                }
            }
        }
    }
}
int predict_tree_39(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 110) {
        if (light <= 56) {
            if (light <= 48) {
                return -1;
            } else {
                if (temperature <= 41) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (co2 <= 7) {
                if (light <= 67) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (co2 <= 13) {
                    if (humidity <= 120) {
                        if (humidity_ratio <= 3) {
                            return -1;
                        } else {
                            if (light <= 70) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (light <= 61) {
            if (co2 <= 39) {
                return -1;
            } else {
                if (co2 <= 40) {
                    return 1;
                } else {
                    if (humidity <= 82) {
                        return -1;
                    } else {
                        if (co2 <= 69) {
                            return 1;
                        } else {
                            if (light <= 5) {
                                return -1;
                            } else {
                                if (humidity <= 148) {
                                    return -1;
                                } else {
                                    if (humidity_ratio <= 175) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (temperature <= 227) {
                if (co2 <= 76) {
                    if (temperature <= 203) {
                        if (humidity_ratio <= 100) {
                            return 1;
                        } else {
                            if (light <= 74) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 111) {
                            if (humidity <= 105) {
                                if (light <= 78) {
                                    return -1;
                                } else {
                                    if (co2 <= 63) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (co2 <= 99) {
                        if (light <= 76) {
                            return 1;
                        } else {
                            if (co2 <= 99) {
                                return 1;
                            } else {
                                if (humidity <= 111) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 127) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 115) {
                    if (humidity_ratio <= 122) {
                        return 1;
                    } else {
                        if (co2 <= 98) {
                            return -1;
                        } else {
                            if (light <= 105) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_40(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity_ratio <= 28) {
            return -1;
        } else {
            if (humidity <= 34) {
                if (temperature <= 146) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (temperature <= 238) {
                    if (humidity <= 65) {
                        if (humidity_ratio <= 47) {
                            return -1;
                        } else {
                            if (light <= 29) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (co2 <= 10) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 75) {
                                if (light <= 24) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (humidity_ratio <= 5) {
            return -1;
        } else {
            if (temperature <= 205) {
                if (humidity <= 25) {
                    if (temperature <= 91) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 64) {
                        if (co2 <= 63) {
                            if (humidity_ratio <= 27) {
                                if (temperature <= 159) {
                                    return 1;
                                } else {
                                    if (humidity <= 29) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (humidity <= 42) {
                                    if (co2 <= 62) {
                                        return 1;
                                    } else {
                                        if (co2 <= 62) {
                                            if (humidity_ratio <= 40) {
                                                return 1;
                                            } else {
                                                if (light <= 80) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 81) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (light <= 76) {
                            return 1;
                        } else {
                            if (humidity <= 113) {
                                return 1;
                            } else {
                                if (humidity <= 113) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 76) {
                    if (co2 <= 63) {
                        if (light <= 76) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 110) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (temperature <= 230) {
                        if (co2 <= 102) {
                            if (co2 <= 101) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 89) {
                            if (light <= 86) {
                                return 1;
                            } else {
                                if (temperature <= 237) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_41(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 29) {
        if (co2 <= 13) {
            if (co2 <= 10) {
                if (temperature <= 69) {
                    if (temperature <= 32) {
                        return -1;
                    } else {
                        if (light <= 47) {
                            return -1;
                        } else {
                            if (temperature <= 45) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (co2 <= 7) {
                        if (light <= 68) {
                            return -1;
                        } else {
                            if (co2 <= 7) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 78) {
                            return 1;
                        } else {
                            if (light <= 64) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (humidity <= 49) {
                    if (humidity_ratio <= 11) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (light <= 67) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (humidity <= 61) {
                if (light <= 34) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (humidity_ratio <= 121) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
    } else {
        if (humidity <= 189) {
            if (co2 <= 58) {
                if (humidity <= 36) {
                    if (light <= 29) {
                        return -1;
                    } else {
                        if (co2 <= 38) {
                            return 1;
                        } else {
                            if (co2 <= 38) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 76) {
                        if (temperature <= 168) {
                            if (light <= 41) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 60) {
                                if (light <= 31) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (light <= 32) {
                            return -1;
                        } else {
                            if (temperature <= 200) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            } else {
                if (temperature <= 230) {
                    if (humidity_ratio <= 70) {
                        if (humidity <= 43) {
                            if (light <= 79) {
                                if (light <= 78) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 41) {
                                        if (humidity_ratio <= 41) {
                                            if (co2 <= 62) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 38) {
                            return -1;
                        } else {
                            if (co2 <= 76) {
                                if (humidity <= 100) {
                                    return 1;
                                } else {
                                    if (temperature <= 203) {
                                        return 1;
                                    } else {
                                        if (humidity <= 106) {
                                            if (humidity_ratio <= 111) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            } else {
                                if (temperature <= 227) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 124) {
                                        if (co2 <= 102) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 109) {
                        if (humidity <= 106) {
                            if (temperature <= 238) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (temperature <= 148) {
                return -1;
            } else {
                if (light <= 29) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_42(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (light <= 35) {
            return -1;
        } else {
            if (co2 <= 9) {
                if (light <= 59) {
                    return -1;
                } else {
                    if (temperature <= 156) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (co2 <= 7) {
            return -1;
        } else {
            if (co2 <= 13) {
                if (temperature <= 54) {
                    if (temperature <= 32) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity_ratio <= 108) {
                    if (humidity <= 43) {
                        if (co2 <= 63) {
                            if (co2 <= 62) {
                                if (humidity <= 30) {
                                    if (temperature <= 163) {
                                        if (humidity_ratio <= 19) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 42) {
                                    if (co2 <= 62) {
                                        if (light <= 80) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (light <= 82) {
                                if (humidity <= 42) {
                                    return 1;
                                } else {
                                    if (co2 <= 65) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (co2 <= 76) {
                        if (temperature <= 201) {
                            return 1;
                        } else {
                            if (humidity <= 114) {
                                if (humidity <= 106) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 230) {
                            if (humidity_ratio <= 115) {
                                if (co2 <= 99) {
                                    return 1;
                                } else {
                                    if (co2 <= 99) {
                                        if (humidity <= 109) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (humidity_ratio <= 115) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 102) {
                                if (co2 <= 92) {
                                    return 1;
                                } else {
                                    if (light <= 89) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_43(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (humidity_ratio <= 247) {
            if (co2 <= 68) {
                if (light <= 48) {
                    return -1;
                } else {
                    if (light <= 48) {
                        return 1;
                    } else {
                        if (humidity <= 27) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 67) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            } else {
                if (light <= 24) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (temperature <= 230) {
            if (co2 <= 7) {
                if (co2 <= 4) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (temperature <= 36) {
                    if (humidity_ratio <= 77) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        if (humidity <= 113) {
                            if (humidity_ratio <= 109) {
                                if (humidity <= 30) {
                                    if (humidity <= 30) {
                                        if (humidity <= 29) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 26) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 29) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (light <= 81) {
                                        return 1;
                                    } else {
                                        if (light <= 81) {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (humidity <= 107) {
                                    if (co2 <= 87) {
                                        if (light <= 74) {
                                            return 1;
                                        } else {
                                            if (humidity <= 106) {
                                                if (humidity_ratio <= 111) {
                                                    return -1;
                                                } else {
                                                    if (humidity_ratio <= 111) {
                                                        if (co2 <= 63) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity_ratio <= 124) {
                                        if (humidity_ratio <= 114) {
                                            if (humidity <= 112) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 114) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (humidity <= 113) {
                                                if (humidity_ratio <= 115) {
                                                    if (light <= 76) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    if (humidity_ratio <= 124) {
                                                        return 1;
                                                    } else {
                                                        if (humidity_ratio <= 124) {
                                                            if (light <= 86) {
                                                                return 1;
                                                            } else {
                                                                return -1;
                                                            }
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (co2 <= 110) {
                if (co2 <= 92) {
                    return 1;
                } else {
                    if (light <= 113) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity_ratio <= 129) {
                    if (co2 <= 110) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_44(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (co2 <= 230) {
            if (temperature <= 142) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (humidity <= 63) {
                        return -1;
                    } else {
                        if (co2 <= 7) {
                            if (humidity_ratio <= 48) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (temperature <= 32) {
                                return -1;
                            } else {
                                if (temperature <= 33) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (humidity_ratio <= 83) {
                    if (temperature <= 144) {
                        if (humidity_ratio <= 31) {
                            if (co2 <= 22) {
                                return -1;
                            } else {
                                if (humidity <= 34) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 74) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 175) {
                            if (humidity_ratio <= 174) {
                                if (humidity <= 105) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity_ratio <= 12) {
            if (co2 <= 7) {
                if (light <= 67) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                return 1;
            }
        } else {
            if (temperature <= 227) {
                if (temperature <= 204) {
                    if (co2 <= 13) {
                        if (humidity_ratio <= 77) {
                            if (humidity <= 66) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity <= 30) {
                            if (temperature <= 163) {
                                if (temperature <= 159) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 43) {
                                if (humidity <= 43) {
                                    return 1;
                                } else {
                                    if (co2 <= 62) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (light <= 76) {
                                    return 1;
                                } else {
                                    if (temperature <= 193) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 114) {
                                            return 1;
                                        } else {
                                            if (humidity <= 113) {
                                                if (humidity_ratio <= 115) {
                                                    if (co2 <= 102) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 76) {
                        if (co2 <= 63) {
                            if (co2 <= 61) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity_ratio <= 122) {
                    return 1;
                } else {
                    if (humidity_ratio <= 129) {
                        if (light <= 86) {
                            return 1;
                        } else {
                            if (co2 <= 110) {
                                return -1;
                            } else {
                                if (light <= 89) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_45(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 114) {
        if (light <= 63) {
            if (co2 <= 66) {
                if (light <= 48) {
                    return -1;
                } else {
                    if (temperature <= 45) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (light <= 26) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (co2 <= 7) {
                if (co2 <= 5) {
                    if (light <= 69) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            } else {
                if (humidity <= 104) {
                    if (temperature <= 71) {
                        if (humidity <= 23) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 30) {
                            if (co2 <= 37) {
                                return 1;
                            } else {
                                if (temperature <= 168) {
                                    if (humidity <= 30) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (co2 <= 64) {
                                if (temperature <= 168) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 41) {
                                        return 1;
                                    } else {
                                        if (light <= 79) {
                                            return 1;
                                        } else {
                                            if (temperature <= 171) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 201) {
                        if (temperature <= 36) {
                            if (humidity_ratio <= 78) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 74) {
                            return 1;
                        } else {
                            if (humidity <= 107) {
                                return -1;
                            } else {
                                if (light <= 82) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (temperature <= 123) {
            if (light <= 35) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (light <= 30) {
                return -1;
            } else {
                if (humidity <= 109) {
                    if (humidity <= 106) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (temperature <= 230) {
                        if (light <= 87) {
                            return 1;
                        } else {
                            if (temperature <= 227) {
                                return 1;
                            } else {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 126) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (light <= 109) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_46(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity_ratio <= 247) {
            if (temperature <= 238) {
                if (light <= 59) {
                    if (temperature <= 142) {
                        return -1;
                    } else {
                        if (light <= 48) {
                            return -1;
                        } else {
                            if (temperature <= 150) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 156) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (temperature <= 240) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (temperature <= 230) {
            if (co2 <= 13) {
                if (co2 <= 7) {
                    if (humidity_ratio <= 3) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 3) {
                            if (temperature <= 71) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (light <= 70) {
                        if (humidity_ratio <= 79) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (temperature <= 204) {
                    if (light <= 75) {
                        return 1;
                    } else {
                        if (temperature <= 201) {
                            if (humidity <= 30) {
                                if (humidity <= 29) {
                                    return 1;
                                } else {
                                    if (co2 <= 40) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 113) {
                                    return 1;
                                } else {
                                    if (co2 <= 99) {
                                        if (humidity <= 123) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (humidity <= 110) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (humidity <= 108) {
                        if (light <= 74) {
                            return 1;
                        } else {
                            if (co2 <= 63) {
                                if (light <= 75) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (humidity <= 116) {
                if (co2 <= 92) {
                    return 1;
                } else {
                    if (co2 <= 111) {
                        if (light <= 108) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_47(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (temperature <= 113) {
            if (humidity <= 150) {
                if (humidity_ratio <= 112) {
                    if (co2 <= 12) {
                        if (light <= 53) {
                            return -1;
                        } else {
                            if (temperature <= 109) {
                                if (humidity_ratio <= 77) {
                                    if (light <= 70) {
                                        if (humidity_ratio <= 4) {
                                            if (humidity <= 22) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (humidity <= 92) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (light <= 32) {
                            return -1;
                        } else {
                            if (co2 <= 13) {
                                if (light <= 67) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
        } else {
            if (humidity_ratio <= 37) {
                if (humidity <= 25) {
                    return -1;
                } else {
                    if (light <= 46) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 27) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 28) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 58) {
                    if (humidity <= 80) {
                        if (light <= 33) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 200) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (temperature <= 204) {
                        if (humidity_ratio <= 70) {
                            if (humidity_ratio <= 41) {
                                if (humidity_ratio <= 41) {
                                    if (humidity_ratio <= 40) {
                                        if (humidity <= 42) {
                                            return 1;
                                        } else {
                                            if (temperature <= 157) {
                                                return 1;
                                            } else {
                                                if (light <= 78) {
                                                    if (light <= 78) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 77) {
                                return -1;
                            } else {
                                if (light <= 18) {
                                    return -1;
                                } else {
                                    if (co2 <= 99) {
                                        return 1;
                                    } else {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (humidity <= 106) {
                            if (humidity_ratio <= 109) {
                                return 1;
                            } else {
                                if (co2 <= 61) {
                                    return -1;
                                } else {
                                    if (light <= 81) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            if (co2 <= 91) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (co2 <= 88) {
            if (humidity <= 167) {
                if (humidity <= 110) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
        } else {
            if (light <= 5) {
                return -1;
            } else {
                if (temperature <= 230) {
                    if (humidity_ratio <= 115) {
                        if (co2 <= 100) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 112) {
                            if (humidity <= 112) {
                                return 1;
                            } else {
                                if (co2 <= 102) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 109) {
                        if (humidity <= 113) {
                            if (co2 <= 97) {
                                if (humidity_ratio <= 122) {
                                    if (co2 <= 90) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_48(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (humidity_ratio <= 115) {
            if (temperature <= 32) {
                if (co2 <= 11) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (humidity_ratio <= 81) {
                    if (humidity <= 117) {
                        if (humidity_ratio <= 5) {
                            if (temperature <= 69) {
                                return -1;
                            } else {
                                if (temperature <= 73) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 3) {
                                        if (humidity_ratio <= 3) {
                                            return -1;
                                        } else {
                                            if (co2 <= 4) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            if (light <= 50) {
                                return -1;
                            } else {
                                if (light <= 70) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (co2 <= 11) {
                            if (humidity_ratio <= 79) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (light <= 56) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (co2 <= 50) {
                return -1;
            } else {
                if (humidity_ratio <= 151) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
    } else {
        if (co2 <= 27) {
            if (light <= 63) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (temperature <= 163) {
                if (light <= 48) {
                    return -1;
                } else {
                    if (humidity <= 30) {
                        if (co2 <= 38) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (light <= 27) {
                    return -1;
                } else {
                    if (temperature <= 234) {
                        if (humidity <= 116) {
                            if (humidity <= 104) {
                                if (humidity_ratio <= 41) {
                                    if (co2 <= 62) {
                                        return 1;
                                    } else {
                                        if (light <= 79) {
                                            if (temperature <= 171) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (temperature <= 169) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (temperature <= 204) {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        if (temperature <= 192) {
                                            return -1;
                                        } else {
                                            if (humidity_ratio <= 115) {
                                                if (co2 <= 99) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (light <= 75) {
                                        if (co2 <= 83) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (humidity <= 110) {
                                            if (light <= 78) {
                                                return -1;
                                            } else {
                                                if (humidity <= 106) {
                                                    if (co2 <= 63) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    if (co2 <= 76) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (light <= 90) {
                                                if (humidity_ratio <= 124) {
                                                    if (light <= 86) {
                                                        return 1;
                                                    } else {
                                                        if (humidity_ratio <= 124) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    }
                                                } else {
                                                    if (light <= 88) {
                                                        return -1;
                                                    } else {
                                                        if (humidity <= 115) {
                                                            return -1;
                                                        } else {
                                                            if (co2 <= 110) {
                                                                return 1;
                                                            } else {
                                                                return -1;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity_ratio <= 121) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_49(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 138) {
        if (light <= 54) {
            return -1;
        } else {
            if (humidity_ratio <= 15) {
                if (light <= 69) {
                    return 1;
                } else {
                    if (co2 <= 7) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (light <= 61) {
            if (humidity_ratio <= 247) {
                if (humidity <= 34) {
                    return -1;
                } else {
                    if (humidity <= 35) {
                        return 1;
                    } else {
                        if (temperature <= 238) {
                            if (light <= 27) {
                                if (humidity_ratio <= 173) {
                                    return -1;
                                } else {
                                    if (co2 <= 143) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (temperature <= 200) {
                if (humidity_ratio <= 41) {
                    if (humidity <= 42) {
                        if (temperature <= 163) {
                            if (temperature <= 159) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity_ratio <= 41) {
                            if (humidity <= 42) {
                                if (temperature <= 170) {
                                    if (light <= 78) {
                                        return 1;
                                    } else {
                                        if (light <= 78) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 79) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 190) {
                        return 1;
                    } else {
                        if (temperature <= 191) {
                            if (humidity_ratio <= 112) {
                                return 1;
                            } else {
                                if (light <= 75) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 114) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 115) {
                                    if (co2 <= 101) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 76) {
                    if (temperature <= 203) {
                        if (humidity <= 112) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 97) {
                        if (temperature <= 223) {
                            return 1;
                        } else {
                            if (light <= 91) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (temperature <= 230) {
                            if (co2 <= 103) {
                                if (co2 <= 103) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 126) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (co2 <= 111) {
                                if (light <= 89) {
                                    if (light <= 87) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_50(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (humidity <= 125) {
            if (humidity <= 69) {
                if (humidity_ratio <= 52) {
                    if (light <= 50) {
                        return -1;
                    } else {
                        if (co2 <= 7) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 48) {
                                return 1;
                            } else {
                                if (humidity <= 66) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (co2 <= 13) {
                    if (light <= 67) {
                        if (temperature <= 32) {
                            return -1;
                        } else {
                            if (light <= 41) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 76) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (light <= 58) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (humidity_ratio <= 37) {
            if (light <= 61) {
                if (humidity_ratio <= 28) {
                    return -1;
                } else {
                    if (light <= 31) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity_ratio <= 27) {
                    return 1;
                } else {
                    if (humidity <= 30) {
                        if (temperature <= 164) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (light <= 42) {
                return -1;
            } else {
                if (light <= 86) {
                    if (temperature <= 204) {
                        if (humidity <= 43) {
                            if (co2 <= 63) {
                                return 1;
                            } else {
                                if (co2 <= 64) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 115) {
                                if (humidity_ratio <= 115) {
                                    if (humidity <= 112) {
                                        if (co2 <= 58) {
                                            if (light <= 74) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (temperature <= 192) {
                                            return -1;
                                        } else {
                                            if (co2 <= 99) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 112) {
                            if (light <= 73) {
                                return 1;
                            } else {
                                if (humidity <= 106) {
                                    if (humidity_ratio <= 110) {
                                        return -1;
                                    } else {
                                        if (light <= 75) {
                                            if (light <= 74) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity <= 106) {
                        return 1;
                    } else {
                        if (co2 <= 97) {
                            return -1;
                        } else {
                            if (temperature <= 228) {
                                return 1;
                            } else {
                                if (humidity <= 114) {
                                    return -1;
                                } else {
                                    if (humidity <= 116) {
                                        if (co2 <= 110) {
                                            return -1;
                                        } else {
                                            if (co2 <= 110) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 128) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_51(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 28) {
        if (temperature <= 106) {
            if (temperature <= 32) {
                if (light <= 63) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 119) {
                    if (co2 <= 13) {
                        if (humidity <= 29) {
                            if (co2 <= 7) {
                                return -1;
                            } else {
                                if (humidity <= 25) {
                                    if (light <= 68) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity <= 28) {
                                        return -1;
                                    } else {
                                        if (light <= 34) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity_ratio <= 11) {
                            return 1;
                        } else {
                            if (temperature <= 91) {
                                if (light <= 34) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (light <= 56) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 82) {
                            if (humidity_ratio <= 77) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (co2 <= 13) {
                if (humidity <= 55) {
                    return -1;
                } else {
                    if (humidity_ratio <= 47) {
                        if (co2 <= 7) {
                            return -1;
                        } else {
                            if (light <= 29) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity <= 68) {
                            if (temperature <= 107) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (temperature <= 129) {
                    if (light <= 33) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            }
        }
    } else {
        if (light <= 31) {
            if (co2 <= 131) {
                return -1;
            } else {
                if (co2 <= 132) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (temperature <= 230) {
                if (co2 <= 76) {
                    if (humidity_ratio <= 107) {
                        if (humidity_ratio <= 42) {
                            if (co2 <= 62) {
                                if (light <= 87) {
                                    return 1;
                                } else {
                                    if (light <= 87) {
                                        if (humidity_ratio <= 29) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (co2 <= 62) {
                                    if (light <= 78) {
                                        return 1;
                                    } else {
                                        if (temperature <= 171) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (co2 <= 64) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 41) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 201) {
                            return 1;
                        } else {
                            if (humidity <= 113) {
                                if (humidity_ratio <= 111) {
                                    if (light <= 78) {
                                        return -1;
                                    } else {
                                        if (co2 <= 63) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (co2 <= 100) {
                        if (co2 <= 99) {
                            return 1;
                        } else {
                            if (humidity <= 112) {
                                return 1;
                            } else {
                                if (light <= 75) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (light <= 89) {
                    return 1;
                } else {
                    if (humidity <= 115) {
                        if (humidity_ratio <= 124) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            }
        }
    }
}
int predict_tree_52(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 33) {
        if (light <= 62) {
            return -1;
        } else {
            if (humidity <= 26) {
                if (co2 <= 7) {
                    if (humidity <= 22) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 34) {
                    if (co2 <= 11) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 10) {
                        if (co2 <= 9) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (humidity <= 190) {
            if (light <= 31) {
                return -1;
            } else {
                if (temperature <= 241) {
                    if (co2 <= 68) {
                        if (humidity_ratio <= 107) {
                            if (humidity <= 30) {
                                if (humidity <= 29) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 27) {
                                        if (light <= 86) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (light <= 78) {
                                    return 1;
                                } else {
                                    if (co2 <= 62) {
                                        return 1;
                                    } else {
                                        if (humidity <= 43) {
                                            if (temperature <= 171) {
                                                if (co2 <= 62) {
                                                    return -1;
                                                } else {
                                                    if (co2 <= 63) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (humidity <= 109) {
                                if (temperature <= 200) {
                                    return 1;
                                } else {
                                    if (co2 <= 63) {
                                        if (light <= 78) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 112) {
                            return 1;
                        } else {
                            if (light <= 84) {
                                if (humidity_ratio <= 115) {
                                    if (co2 <= 100) {
                                        if (humidity <= 113) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 109) {
                                    return -1;
                                } else {
                                    if (humidity <= 115) {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            if (temperature <= 226) {
                                                return 1;
                                            } else {
                                                if (light <= 86) {
                                                    return 1;
                                                } else {
                                                    if (temperature <= 232) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (temperature <= 230) {
                                            return 1;
                                        } else {
                                            if (humidity <= 117) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 92) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (co2 <= 127) {
                if (co2 <= 120) {
                    return -1;
                } else {
                    if (light <= 38) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (light <= 27) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_53(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (humidity_ratio <= 92) {
            if (co2 <= 13) {
                if (humidity_ratio <= 11) {
                    if (co2 <= 8) {
                        if (light <= 68) {
                            return -1;
                        } else {
                            if (humidity <= 24) {
                                if (temperature <= 73) {
                                    if (temperature <= 70) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity <= 27) {
                            return 1;
                        } else {
                            if (co2 <= 10) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (light <= 67) {
                        if (co2 <= 10) {
                            if (light <= 59) {
                                return -1;
                            } else {
                                if (light <= 59) {
                                    if (co2 <= 7) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (humidity <= 116) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 77) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (light <= 70) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (light <= 32) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            return -1;
        }
    } else {
        if (humidity <= 189) {
            if (light <= 31) {
                if (light <= 5) {
                    return -1;
                } else {
                    if (humidity_ratio <= 169) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 230) {
                    if (humidity <= 104) {
                        if (humidity <= 42) {
                            if (humidity <= 42) {
                                if (temperature <= 163) {
                                    if (humidity_ratio <= 27) {
                                        if (light <= 87) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (humidity_ratio <= 28) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 62) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 40) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 76) {
                            if (light <= 74) {
                                return 1;
                            } else {
                                if (light <= 80) {
                                    if (co2 <= 61) {
                                        return -1;
                                    } else {
                                        if (humidity_ratio <= 111) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    if (light <= 80) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            if (humidity <= 113) {
                                if (humidity <= 113) {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 122) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (light <= 86) {
                        return 1;
                    } else {
                        if (co2 <= 110) {
                            if (co2 <= 97) {
                                return -1;
                            } else {
                                if (humidity <= 113) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (light <= 89) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            }
        } else {
            if (light <= 27) {
                return -1;
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_54(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity_ratio <= 247) {
            if (temperature <= 238) {
                if (co2 <= 40) {
                    if (light <= 59) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 34) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 40) {
                        return 1;
                    } else {
                        if (light <= 31) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (co2 <= 49) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (temperature <= 230) {
            if (co2 <= 7) {
                if (humidity_ratio <= 3) {
                    if (co2 <= 4) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (temperature <= 70) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 76) {
                    if (humidity_ratio <= 107) {
                        if (light <= 79) {
                            if (humidity <= 121) {
                                if (light <= 70) {
                                    if (light <= 70) {
                                        return 1;
                                    } else {
                                        if (humidity <= 49) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 124) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (co2 <= 38) {
                                if (humidity <= 29) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 26) {
                                        return 1;
                                    } else {
                                        if (co2 <= 37) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            } else {
                                if (co2 <= 63) {
                                    return 1;
                                } else {
                                    if (co2 <= 64) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (light <= 74) {
                            if (humidity_ratio <= 112) {
                                if (humidity_ratio <= 112) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 106) {
                                if (co2 <= 62) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (humidity <= 113) {
                        if (co2 <= 99) {
                            return 1;
                        } else {
                            if (humidity <= 113) {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    if (humidity <= 112) {
                                        return -1;
                                    } else {
                                        if (humidity_ratio <= 114) {
                                            return -1;
                                        } else {
                                            if (light <= 75) {
                                                return 1;
                                            } else {
                                                if (co2 <= 100) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (light <= 105) {
                return -1;
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_55(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (light <= 65) {
            if (temperature <= 106) {
                return -1;
            } else {
                if (humidity_ratio <= 43) {
                    return -1;
                } else {
                    if (humidity_ratio <= 47) {
                        if (light <= 29) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (co2 <= 7) {
                if (humidity <= 22) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (humidity <= 120) {
                    return 1;
                } else {
                    if (temperature <= 36) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (temperature <= 113) {
            if (light <= 32) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (light <= 42) {
                if (co2 <= 132) {
                    return -1;
                } else {
                    if (humidity <= 205) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (temperature <= 234) {
                    if (humidity_ratio <= 108) {
                        if (co2 <= 38) {
                            if (humidity <= 31) {
                                if (humidity <= 29) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 27) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 79) {
                            if (humidity_ratio <= 116) {
                                if (humidity_ratio <= 111) {
                                    if (co2 <= 61) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 228) {
                                if (humidity_ratio <= 115) {
                                    if (humidity <= 113) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (light <= 88) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 122) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
    }
}
int predict_tree_56(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (light <= 58) {
            return -1;
        } else {
            if (humidity <= 24) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 36) {
                    if (light <= 67) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (humidity_ratio <= 32) {
            if (light <= 65) {
                return -1;
            } else {
                if (temperature <= 159) {
                    return 1;
                } else {
                    if (humidity <= 29) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 27) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (light <= 31) {
                if (humidity <= 188) {
                    return -1;
                } else {
                    if (humidity_ratio <= 175) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 100) {
                    if (temperature <= 204) {
                        if (co2 <= 99) {
                            if (humidity <= 43) {
                                if (co2 <= 63) {
                                    return 1;
                                } else {
                                    if (co2 <= 64) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 108) {
                                    return 1;
                                } else {
                                    if (humidity <= 105) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (humidity <= 113) {
                                if (temperature <= 191) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (light <= 73) {
                            return 1;
                        } else {
                            if (humidity <= 111) {
                                if (light <= 78) {
                                    return -1;
                                } else {
                                    if (temperature <= 230) {
                                        if (humidity_ratio <= 113) {
                                            if (light <= 81) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            if (co2 <= 87) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (co2 <= 92) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 230) {
                        return 1;
                    } else {
                        if (co2 <= 111) {
                            if (light <= 89) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_57(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (light <= 35) {
            if (humidity_ratio <= 175) {
                return -1;
            } else {
                if (humidity <= 200) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (co2 <= 9) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (humidity <= 25) {
            if (humidity <= 22) {
                if (temperature <= 74) {
                    if (temperature <= 73) {
                        if (light <= 69) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
        } else {
            if (co2 <= 13) {
                if (light <= 67) {
                    return -1;
                } else {
                    if (co2 <= 10) {
                        if (co2 <= 9) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (light <= 86) {
                    if (temperature <= 200) {
                        if (humidity <= 43) {
                            if (humidity_ratio <= 41) {
                                if (co2 <= 62) {
                                    return 1;
                                } else {
                                    if (light <= 79) {
                                        if (humidity_ratio <= 40) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (temperature <= 171) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (light <= 76) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 113) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 113) {
                                        return -1;
                                    } else {
                                        if (humidity_ratio <= 115) {
                                            if (co2 <= 100) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (humidity_ratio <= 114) {
                            if (humidity_ratio <= 108) {
                                return 1;
                            } else {
                                if (co2 <= 87) {
                                    if (light <= 80) {
                                        return -1;
                                    } else {
                                        if (co2 <= 63) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (temperature <= 230) {
                        if (humidity_ratio <= 85) {
                            if (humidity_ratio <= 27) {
                                if (humidity <= 29) {
                                    return 1;
                                } else {
                                    if (co2 <= 38) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 110) {
                                return -1;
                            } else {
                                if (temperature <= 227) {
                                    return 1;
                                } else {
                                    if (humidity <= 114) {
                                        if (light <= 86) {
                                            return 1;
                                        } else {
                                            if (humidity <= 112) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (humidity <= 114) {
                            if (light <= 109) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 232) {
                                if (co2 <= 110) {
                                    return -1;
                                } else {
                                    if (co2 <= 110) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_58(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (temperature <= 238) {
            if (light <= 59) {
                if (co2 <= 40) {
                    return -1;
                } else {
                    if (humidity_ratio <= 28) {
                        if (light <= 29) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (temperature <= 159) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (humidity <= 57) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (humidity <= 25) {
            if (humidity <= 24) {
                if (light <= 69) {
                    if (co2 <= 7) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 7) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                return -1;
            }
        } else {
            if (light <= 89) {
                if (temperature <= 200) {
                    if (light <= 76) {
                        return 1;
                    } else {
                        if (co2 <= 100) {
                            if (co2 <= 99) {
                                if (humidity_ratio <= 41) {
                                    if (humidity <= 43) {
                                        return 1;
                                    } else {
                                        if (light <= 79) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity_ratio <= 113) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 76) {
                        if (humidity_ratio <= 111) {
                            return -1;
                        } else {
                            if (co2 <= 63) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 118) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (temperature <= 226) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 123) {
                                return 1;
                            } else {
                                if (humidity <= 114) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (temperature <= 230) {
                    if (co2 <= 71) {
                        if (humidity <= 29) {
                            if (humidity <= 28) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 86) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 113) {
                        if (humidity <= 117) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_59(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (light <= 54) {
            return -1;
        } else {
            if (co2 <= 7) {
                if (humidity <= 22) {
                    if (temperature <= 74) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            } else {
                if (humidity_ratio <= 3) {
                    return -1;
                } else {
                    if (temperature <= 34) {
                        if (humidity_ratio <= 77) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity <= 66) {
                            if (humidity <= 65) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (humidity <= 40) {
            if (co2 <= 26) {
                return -1;
            } else {
                if (light <= 46) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (temperature <= 119) {
                if (light <= 33) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (co2 <= 58) {
                    if (temperature <= 133) {
                        if (humidity <= 41) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 35) {
                            return -1;
                        } else {
                            if (co2 <= 57) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (light <= 36) {
                        return -1;
                    } else {
                        if (light <= 86) {
                            if (temperature <= 204) {
                                if (humidity <= 43) {
                                    if (humidity_ratio <= 41) {
                                        return 1;
                                    } else {
                                        if (temperature <= 171) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (humidity_ratio <= 115) {
                                        if (humidity_ratio <= 115) {
                                            if (humidity_ratio <= 114) {
                                                if (co2 <= 58) {
                                                    if (temperature <= 201) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                if (light <= 77) {
                                                    if (light <= 76) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 112) {
                                    if (co2 <= 82) {
                                        if (humidity <= 106) {
                                            if (light <= 75) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (co2 <= 76) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (temperature <= 238) {
                                if (temperature <= 203) {
                                    return 1;
                                } else {
                                    if (humidity <= 110) {
                                        return -1;
                                    } else {
                                        if (co2 <= 111) {
                                            if (temperature <= 228) {
                                                return 1;
                                            } else {
                                                if (light <= 105) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (humidity_ratio <= 130) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (light <= 91) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_60(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (co2 <= 13) {
            if (humidity_ratio <= 5) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (light <= 35) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 119) {
                    if (humidity <= 117) {
                        if (temperature <= 105) {
                            return -1;
                        } else {
                            if (humidity <= 55) {
                                return -1;
                            } else {
                                if (light <= 45) {
                                    return -1;
                                } else {
                                    if (light <= 65) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (co2 <= 9) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (light <= 32) {
                return -1;
            } else {
                if (co2 <= 13) {
                    if (humidity_ratio <= 67) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (co2 <= 57) {
            if (temperature <= 104) {
                if (humidity_ratio <= 134) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (humidity_ratio <= 24) {
                    if (light <= 35) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (light <= 35) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 27) {
                            if (light <= 87) {
                                return 1;
                            } else {
                                if (light <= 87) {
                                    return -1;
                                } else {
                                    if (temperature <= 165) {
                                        if (humidity <= 30) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (temperature <= 123) {
                if (light <= 35) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 221) {
                    if (humidity <= 103) {
                        if (humidity <= 47) {
                            if (humidity <= 47) {
                                if (light <= 38) {
                                    return -1;
                                } else {
                                    if (light <= 79) {
                                        if (humidity <= 43) {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 42) {
                                                    if (light <= 79) {
                                                        return -1;
                                                    } else {
                                                        if (humidity <= 42) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (co2 <= 57) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (co2 <= 66) {
                                if (co2 <= 65) {
                                    if (humidity <= 49) {
                                        if (humidity <= 48) {
                                            return 1;
                                        } else {
                                            if (light <= 37) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (humidity_ratio <= 78) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 79) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (light <= 35) {
                            if (humidity_ratio <= 173) {
                                return -1;
                            } else {
                                if (humidity <= 189) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 115) {
                                if (temperature <= 200) {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 115) {
                                            if (light <= 76) {
                                                return 1;
                                            } else {
                                                if (co2 <= 100) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    if (co2 <= 76) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (temperature <= 228) {
                                    return 1;
                                } else {
                                    if (light <= 104) {
                                        if (humidity_ratio <= 122) {
                                            return 1;
                                        } else {
                                            if (co2 <= 111) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (co2 <= 97) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 180) {
                        return -1;
                    } else {
                        if (light <= 27) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_61(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 24) {
        if (light <= 62) {
            if (co2 <= 7) {
                return -1;
            } else {
                if (temperature <= 105) {
                    return -1;
                } else {
                    if (co2 <= 7) {
                        if (temperature <= 109) {
                            if (humidity <= 65) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (co2 <= 7) {
                return -1;
            } else {
                if (temperature <= 36) {
                    if (co2 <= 11) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (light <= 41) {
            return -1;
        } else {
            if (humidity_ratio <= 108) {
                if (humidity <= 30) {
                    if (temperature <= 163) {
                        if (humidity_ratio <= 26) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity_ratio <= 41) {
                        if (humidity_ratio <= 41) {
                            return 1;
                        } else {
                            if (co2 <= 61) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 107) {
                    if (co2 <= 94) {
                        if (co2 <= 81) {
                            if (humidity <= 107) {
                                if (humidity_ratio <= 111) {
                                    if (humidity <= 105) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 107) {
                                if (humidity_ratio <= 122) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (light <= 86) {
                        if (humidity <= 113) {
                            if (light <= 76) {
                                return 1;
                            } else {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    if (co2 <= 101) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 227) {
                            if (humidity_ratio <= 116) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 114) {
                                if (light <= 109) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (light <= 91) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_62(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (co2 <= 13) {
            if (light <= 66) {
                if (light <= 59) {
                    if (humidity_ratio <= 75) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 75) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (light <= 59) {
                        if (co2 <= 7) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 4) {
                    if (light <= 67) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (light <= 70) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (humidity_ratio <= 47) {
                if (temperature <= 120) {
                    if (light <= 34) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            } else {
                if (light <= 32) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (temperature <= 114) {
            if (light <= 32) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (light <= 31) {
                return -1;
            } else {
                if (temperature <= 240) {
                    if (co2 <= 76) {
                        if (humidity_ratio <= 101) {
                            if (humidity_ratio <= 41) {
                                if (humidity <= 43) {
                                    if (humidity <= 29) {
                                        if (temperature <= 163) {
                                            if (light <= 87) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity <= 45) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 111) {
                                if (humidity_ratio <= 111) {
                                    if (humidity <= 105) {
                                        return -1;
                                    } else {
                                        if (co2 <= 63) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 227) {
                            if (co2 <= 100) {
                                if (co2 <= 100) {
                                    if (co2 <= 99) {
                                        return 1;
                                    } else {
                                        if (co2 <= 99) {
                                            if (light <= 75) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            if (temperature <= 191) {
                                                if (humidity_ratio <= 112) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 114) {
                                if (humidity_ratio <= 125) {
                                    if (co2 <= 102) {
                                        if (humidity <= 111) {
                                            if (humidity_ratio <= 122) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return -1;
                }
            }
        }
    }
}
int predict_tree_63(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (temperature <= 142) {
            if (co2 <= 20) {
                if (co2 <= 13) {
                    if (light <= 66) {
                        if (co2 <= 10) {
                            return -1;
                        } else {
                            if (light <= 24) {
                                return -1;
                            } else {
                                if (co2 <= 11) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (humidity <= 25) {
                            if (co2 <= 7) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 33) {
                        return -1;
                    } else {
                        if (co2 <= 13) {
                            if (humidity <= 96) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (co2 <= 32) {
                    if (light <= 32) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (co2 <= 41) {
                        if (humidity_ratio <= 25) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 59) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (co2 <= 31) {
                return -1;
            } else {
                if (light <= 28) {
                    return -1;
                } else {
                    if (temperature <= 204) {
                        if (humidity <= 112) {
                            if (co2 <= 38) {
                                if (temperature <= 164) {
                                    if (temperature <= 153) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 64) {
                                    if (co2 <= 64) {
                                        if (light <= 79) {
                                            if (light <= 78) {
                                                if (temperature <= 201) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (co2 <= 99) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 115) {
                                    return 1;
                                } else {
                                    if (humidity <= 113) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (humidity <= 105) {
                            return 1;
                        } else {
                            if (co2 <= 89) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (temperature <= 114) {
            if (humidity_ratio <= 149) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (temperature <= 230) {
                if (humidity_ratio <= 190) {
                    if (light <= 49) {
                        if (humidity <= 188) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 227) {
                            return 1;
                        } else {
                            if (light <= 97) {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (co2 <= 213) {
                        if (humidity <= 220) {
                            if (light <= 38) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 176) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 229) {
                                    return 1;
                                } else {
                                    if (light <= 36) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 110) {
                    if (humidity_ratio <= 119) {
                        return 1;
                    } else {
                        if (humidity <= 106) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (co2 <= 110) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 129) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_64(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (temperature <= 138) {
            if (co2 <= 13) {
                if (temperature <= 106) {
                    if (co2 <= 7) {
                        return -1;
                    } else {
                        if (humidity <= 25) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 8) {
                                if (co2 <= 8) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (light <= 67) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (light <= 52) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 30) {
                            return -1;
                        } else {
                            if (humidity <= 66) {
                                if (humidity <= 65) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (humidity_ratio <= 33) {
                    if (humidity_ratio <= 24) {
                        if (light <= 34) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 42) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (temperature <= 136) {
                        return 1;
                    } else {
                        if (co2 <= 33) {
                            return -1;
                        } else {
                            if (co2 <= 35) {
                                return 1;
                            } else {
                                if (co2 <= 46) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (light <= 61) {
                if (co2 <= 67) {
                    if (humidity <= 34) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 28) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (humidity <= 95) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity <= 104) {
                    if (humidity_ratio <= 41) {
                        if (humidity_ratio <= 41) {
                            if (co2 <= 38) {
                                if (co2 <= 38) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 77) {
                                return 1;
                            } else {
                                if (co2 <= 60) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity <= 107) {
                        if (light <= 74) {
                            return 1;
                        } else {
                            if (temperature <= 198) {
                                return 1;
                            } else {
                                if (light <= 75) {
                                    if (co2 <= 61) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (humidity_ratio <= 113) {
                            return 1;
                        } else {
                            if (co2 <= 99) {
                                if (temperature <= 203) {
                                    if (co2 <= 80) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (light <= 44) {
            if (temperature <= 154) {
                return -1;
            } else {
                if (temperature <= 157) {
                    if (light <= 5) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (humidity <= 109) {
                if (humidity <= 106) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (humidity_ratio <= 129) {
                    if (temperature <= 227) {
                        return 1;
                    } else {
                        if (humidity <= 115) {
                            return -1;
                        } else {
                            if (co2 <= 110) {
                                return -1;
                            } else {
                                if (light <= 89) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_65(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (humidity_ratio <= 247) {
            if (light <= 48) {
                return -1;
            } else {
                if (humidity <= 27) {
                    return -1;
                } else {
                    if (co2 <= 21) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity <= 25) {
            if (humidity_ratio <= 3) {
                if (temperature <= 71) {
                    return -1;
                } else {
                    if (light <= 71) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (light <= 69) {
                    if (temperature <= 73) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (light <= 93) {
                if (co2 <= 76) {
                    if (humidity_ratio <= 107) {
                        if (co2 <= 12) {
                            if (co2 <= 11) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (humidity_ratio <= 42) {
                                if (humidity_ratio <= 41) {
                                    if (humidity <= 42) {
                                        return 1;
                                    } else {
                                        if (light <= 78) {
                                            return 1;
                                        } else {
                                            if (humidity <= 43) {
                                                if (co2 <= 62) {
                                                    return 1;
                                                } else {
                                                    if (co2 <= 63) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                if (temperature <= 159) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 201) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 118) {
                                if (humidity_ratio <= 111) {
                                    if (light <= 78) {
                                        return -1;
                                    } else {
                                        if (light <= 81) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (light <= 86) {
                        if (co2 <= 100) {
                            if (co2 <= 100) {
                                if (co2 <= 99) {
                                    return 1;
                                } else {
                                    if (light <= 76) {
                                        return 1;
                                    } else {
                                        if (light <= 76) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 106) {
                            return 1;
                        } else {
                            if (humidity <= 114) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (temperature <= 230) {
                    if (co2 <= 86) {
                        if (humidity_ratio <= 79) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (light <= 108) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_66(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (co2 <= 233) {
            if (temperature <= 105) {
                if (light <= 48) {
                    return -1;
                } else {
                    if (temperature <= 41) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity <= 34) {
                    return -1;
                } else {
                    if (temperature <= 235) {
                        if (humidity_ratio <= 47) {
                            if (humidity <= 34) {
                                return 1;
                            } else {
                                if (humidity <= 60) {
                                    return -1;
                                } else {
                                    if (co2 <= 7) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (temperature <= 154) {
                                return -1;
                            } else {
                                if (temperature <= 157) {
                                    if (light <= 5) {
                                        return -1;
                                    } else {
                                        if (humidity <= 189) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (light <= 95) {
            if (co2 <= 13) {
                if (temperature <= 71) {
                    return -1;
                } else {
                    if (light <= 70) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 108) {
                    if (light <= 78) {
                        return 1;
                    } else {
                        if (light <= 79) {
                            if (temperature <= 157) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (co2 <= 38) {
                                if (humidity <= 30) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 27) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 42) {
                                    if (humidity_ratio <= 41) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (temperature <= 200) {
                        if (co2 <= 100) {
                            if (co2 <= 100) {
                                if (co2 <= 99) {
                                    return 1;
                                } else {
                                    if (humidity <= 112) {
                                        return 1;
                                    } else {
                                        if (co2 <= 99) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 113) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 107) {
                            if (light <= 73) {
                                return 1;
                            } else {
                                if (humidity <= 106) {
                                    if (humidity_ratio <= 111) {
                                        if (temperature <= 205) {
                                            return -1;
                                        } else {
                                            if (light <= 74) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 114) {
                                if (light <= 77) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (temperature <= 226) {
                                    if (light <= 93) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (light <= 86) {
                                        return 1;
                                    } else {
                                        if (light <= 89) {
                                            if (temperature <= 229) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (temperature <= 232) {
                                                return -1;
                                            } else {
                                                if (light <= 93) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (co2 <= 98) {
                return -1;
            } else {
                if (humidity_ratio <= 127) {
                    return 1;
                } else {
                    if (temperature <= 230) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
    }
}
int predict_tree_67(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 33) {
        if (light <= 62) {
            if (temperature <= 106) {
                return -1;
            } else {
                if (light <= 59) {
                    return -1;
                } else {
                    if (temperature <= 156) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (humidity <= 24) {
                if (humidity <= 22) {
                    if (co2 <= 6) {
                        return -1;
                    } else {
                        if (temperature <= 71) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return -1;
                }
            } else {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (co2 <= 12) {
                        if (humidity <= 120) {
                            if (temperature <= 91) {
                                return 1;
                            } else {
                                if (light <= 70) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    } else {
        if (light <= 31) {
            if (co2 <= 132) {
                return -1;
            } else {
                if (humidity <= 189) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (humidity_ratio <= 108) {
                if (humidity <= 43) {
                    if (temperature <= 170) {
                        if (humidity_ratio <= 41) {
                            if (humidity_ratio <= 41) {
                                if (light <= 89) {
                                    if (humidity <= 42) {
                                        return 1;
                                    } else {
                                        if (humidity <= 42) {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (temperature <= 163) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (light <= 79) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 108) {
                    if (co2 <= 76) {
                        if (temperature <= 200) {
                            return 1;
                        } else {
                            if (light <= 80) {
                                if (light <= 80) {
                                    if (humidity_ratio <= 111) {
                                        if (humidity_ratio <= 111) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (temperature <= 241) {
                            return 1;
                        } else {
                            if (light <= 91) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 230) {
                        if (humidity <= 113) {
                            if (humidity_ratio <= 124) {
                                if (co2 <= 100) {
                                    if (temperature <= 191) {
                                        if (co2 <= 98) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (co2 <= 100) {
                                            if (humidity_ratio <= 114) {
                                                return 1;
                                            } else {
                                                if (temperature <= 197) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 116) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_68(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 62) {
        if (humidity <= 246) {
            if (humidity <= 104) {
                if (co2 <= 90) {
                    if (light <= 59) {
                        if (co2 <= 67) {
                            if (co2 <= 39) {
                                return -1;
                            } else {
                                if (humidity <= 35) {
                                    if (humidity_ratio <= 28) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (temperature <= 188) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 102) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (humidity_ratio <= 35) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
        } else {
            return 1;
        }
    } else {
        if (co2 <= 12) {
            if (co2 <= 4) {
                if (temperature <= 74) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (humidity_ratio <= 4) {
                    return -1;
                } else {
                    if (humidity <= 120) {
                        if (co2 <= 7) {
                            return -1;
                        } else {
                            if (light <= 69) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (light <= 93) {
                if (humidity <= 116) {
                    if (humidity_ratio <= 109) {
                        if (humidity <= 43) {
                            if (humidity_ratio <= 41) {
                                return 1;
                            } else {
                                if (co2 <= 63) {
                                    return 1;
                                } else {
                                    if (temperature <= 171) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 83) {
                            if (temperature <= 202) {
                                return 1;
                            } else {
                                if (light <= 75) {
                                    if (light <= 75) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (co2 <= 63) {
                                        if (light <= 78) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            if (temperature <= 229) {
                                if (humidity <= 113) {
                                    return 1;
                                } else {
                                    if (light <= 76) {
                                        return 1;
                                    } else {
                                        if (co2 <= 100) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (co2 <= 99) {
                                    return 1;
                                } else {
                                    if (light <= 91) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (co2 <= 97) {
                    if (temperature <= 199) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    if (temperature <= 230) {
                        return 1;
                    } else {
                        if (humidity <= 113) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_69(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity <= 247) {
            if (humidity_ratio <= 75) {
                return -1;
            } else {
                if (humidity_ratio <= 75) {
                    return 1;
                } else {
                    if (temperature <= 188) {
                        if (humidity_ratio <= 175) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 175) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (co2 <= 74) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (co2 <= 7) {
            if (humidity_ratio <= 3) {
                if (temperature <= 74) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
        } else {
            if (temperature <= 201) {
                if (humidity_ratio <= 115) {
                    if (temperature <= 36) {
                        if (temperature <= 32) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity <= 112) {
                            if (humidity <= 43) {
                                if (co2 <= 63) {
                                    if (light <= 87) {
                                        return 1;
                                    } else {
                                        if (co2 <= 38) {
                                            if (temperature <= 163) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (temperature <= 171) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 76) {
                                return 1;
                            } else {
                                if (light <= 77) {
                                    if (light <= 76) {
                                        if (co2 <= 103) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (co2 <= 76) {
                    if (co2 <= 63) {
                        if (humidity <= 105) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (temperature <= 230) {
                        if (light <= 86) {
                            return 1;
                        } else {
                            if (humidity <= 114) {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity <= 114) {
                            if (humidity_ratio <= 122) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (humidity_ratio <= 129) {
                                if (humidity_ratio <= 128) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 128) {
                                        return -1;
                                    } else {
                                        if (co2 <= 110) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_70(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity <= 247) {
            if (humidity_ratio <= 175) {
                if (humidity <= 117) {
                    return -1;
                } else {
                    if (humidity_ratio <= 75) {
                        if (humidity <= 118) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 175) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (co2 <= 7) {
            return -1;
        } else {
            if (temperature <= 234) {
                if (co2 <= 76) {
                    if (co2 <= 76) {
                        if (temperature <= 200) {
                            if (co2 <= 13) {
                                if (co2 <= 12) {
                                    if (light <= 66) {
                                        return -1;
                                    } else {
                                        if (co2 <= 10) {
                                            if (temperature <= 91) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                if (humidity <= 29) {
                                    if (humidity <= 29) {
                                        return 1;
                                    } else {
                                        if (temperature <= 159) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    if (humidity_ratio <= 41) {
                                        if (humidity_ratio <= 41) {
                                            if (humidity <= 42) {
                                                return 1;
                                            } else {
                                                if (co2 <= 62) {
                                                    return 1;
                                                } else {
                                                    if (humidity <= 42) {
                                                        if (light <= 79) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (light <= 79) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (light <= 73) {
                                return 1;
                            } else {
                                if (co2 <= 62) {
                                    if (humidity <= 105) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (humidity_ratio <= 128) {
                        if (temperature <= 227) {
                            if (humidity_ratio <= 114) {
                                return 1;
                            } else {
                                if (humidity <= 113) {
                                    if (humidity_ratio <= 115) {
                                        if (co2 <= 100) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 128) {
                                if (temperature <= 229) {
                                    if (co2 <= 102) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 105) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
    }
}
int predict_tree_71(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (co2 <= 233) {
            if (temperature <= 238) {
                if (light <= 59) {
                    if (co2 <= 10) {
                        return -1;
                    } else {
                        if (temperature <= 33) {
                            if (temperature <= 32) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 188) {
                                return -1;
                            } else {
                                if (humidity <= 95) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    }
                } else {
                    if (humidity <= 38) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity_ratio <= 72) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (co2 <= 13) {
            if (humidity_ratio <= 77) {
                if (humidity_ratio <= 4) {
                    if (co2 <= 7) {
                        if (light <= 67) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (light <= 69) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 7) {
                        return -1;
                    } else {
                        if (co2 <= 9) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 49) {
                                if (temperature <= 94) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                return -1;
            }
        } else {
            if (temperature <= 230) {
                if (temperature <= 204) {
                    if (temperature <= 162) {
                        return 1;
                    } else {
                        if (temperature <= 163) {
                            if (co2 <= 51) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 108) {
                                if (humidity_ratio <= 40) {
                                    if (humidity <= 41) {
                                        return 1;
                                    } else {
                                        if (humidity <= 42) {
                                            if (co2 <= 62) {
                                                return 1;
                                            } else {
                                                if (co2 <= 62) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (light <= 75) {
                                    return 1;
                                } else {
                                    if (humidity <= 105) {
                                        return -1;
                                    } else {
                                        if (humidity <= 113) {
                                            if (light <= 76) {
                                                if (humidity <= 112) {
                                                    return 1;
                                                } else {
                                                    if (co2 <= 103) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 76) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (light <= 89) {
                    if (humidity <= 110) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 128) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 112) {
                        if (humidity <= 110) {
                            return -1;
                        } else {
                            if (temperature <= 232) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_72(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (light <= 59) {
            if (light <= 35) {
                return -1;
            } else {
                if (co2 <= 9) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (humidity_ratio <= 35) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (humidity <= 25) {
            if (humidity_ratio <= 3) {
                if (humidity_ratio <= 3) {
                    if (temperature <= 74) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 24) {
                    return -1;
                } else {
                    if (humidity_ratio <= 9) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (humidity_ratio <= 109) {
                if (temperature <= 36) {
                    if (light <= 67) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (temperature <= 107) {
                        if (co2 <= 11) {
                            if (light <= 69) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 43) {
                            if (light <= 79) {
                                if (co2 <= 63) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (temperature <= 204) {
                    if (co2 <= 100) {
                        if (co2 <= 100) {
                            if (humidity_ratio <= 109) {
                                return -1;
                            } else {
                                if (co2 <= 99) {
                                    return 1;
                                } else {
                                    if (co2 <= 99) {
                                        return -1;
                                    } else {
                                        if (humidity_ratio <= 113) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 113) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (temperature <= 193) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (co2 <= 97) {
                        if (light <= 72) {
                            return 1;
                        } else {
                            if (light <= 75) {
                                if (humidity_ratio <= 110) {
                                    return -1;
                                } else {
                                    if (humidity <= 106) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (humidity <= 106) {
                                    if (humidity_ratio <= 116) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        if (temperature <= 227) {
                            return 1;
                        } else {
                            if (light <= 86) {
                                return 1;
                            } else {
                                if (light <= 91) {
                                    if (light <= 88) {
                                        return -1;
                                    } else {
                                        if (co2 <= 110) {
                                            return -1;
                                        } else {
                                            if (light <= 89) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_73(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 30) {
        if (temperature <= 107) {
            if (light <= 47) {
                return -1;
            } else {
                if (humidity_ratio <= 6) {
                    if (temperature <= 74) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (temperature <= 105) {
                        if (light <= 56) {
                            if (humidity <= 133) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (temperature <= 36) {
                                if (humidity <= 121) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity <= 28) {
                            return -1;
                        } else {
                            if (humidity <= 65) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            }
        } else {
            if (light <= 63) {
                return -1;
            } else {
                if (humidity <= 28) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (temperature <= 111) {
            if (light <= 33) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (light <= 41) {
                return -1;
            } else {
                if (light <= 97) {
                    if (co2 <= 73) {
                        if (humidity <= 99) {
                            if (light <= 87) {
                                if (light <= 81) {
                                    return 1;
                                } else {
                                    if (light <= 81) {
                                        if (humidity <= 37) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (temperature <= 164) {
                                    if (light <= 89) {
                                        if (humidity <= 30) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity <= 107) {
                                if (humidity_ratio <= 111) {
                                    if (humidity_ratio <= 110) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity <= 116) {
                            if (co2 <= 106) {
                                if (humidity_ratio <= 124) {
                                    if (light <= 83) {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            if (co2 <= 99) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (co2 <= 76) {
                                            if (humidity <= 80) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                if (light <= 81) {
                                    return 1;
                                } else {
                                    if (humidity <= 114) {
                                        return -1;
                                    } else {
                                        if (light <= 91) {
                                            if (co2 <= 110) {
                                                return -1;
                                            } else {
                                                if (co2 <= 110) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity <= 111) {
                        return -1;
                    } else {
                        if (light <= 100) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_74(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (temperature <= 113) {
            if (light <= 58) {
                if (light <= 47) {
                    return -1;
                } else {
                    if (humidity <= 133) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (light <= 70) {
                        if (temperature <= 36) {
                            if (co2 <= 11) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 71) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            if (humidity_ratio <= 35) {
                if (humidity <= 25) {
                    return -1;
                } else {
                    if (temperature <= 163) {
                        if (humidity <= 35) {
                            if (light <= 35) {
                                return -1;
                            } else {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 26) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            if (humidity <= 41) {
                                return -1;
                            } else {
                                if (co2 <= 46) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 54) {
                    if (light <= 38) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (temperature <= 200) {
                        if (light <= 22) {
                            return -1;
                        } else {
                            if (humidity <= 112) {
                                if (humidity_ratio <= 41) {
                                    if (humidity_ratio <= 41) {
                                        if (humidity_ratio <= 41) {
                                            return 1;
                                        } else {
                                            if (co2 <= 63) {
                                                return 1;
                                            } else {
                                                if (co2 <= 64) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 99) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (co2 <= 82) {
                            if (co2 <= 63) {
                                if (co2 <= 62) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 107) {
                                    return -1;
                                } else {
                                    if (humidity_ratio <= 113) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (light <= 41) {
            if (light <= 5) {
                return -1;
            } else {
                if (humidity_ratio <= 169) {
                    return -1;
                } else {
                    if (co2 <= 131) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (temperature <= 230) {
                return 1;
            } else {
                if (co2 <= 110) {
                    if (co2 <= 92) {
                        return 1;
                    } else {
                        if (co2 <= 97) {
                            return -1;
                        } else {
                            if (light <= 106) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_75(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 110) {
        if (light <= 56) {
            return -1;
        } else {
            if (co2 <= 13) {
                if (humidity <= 120) {
                    if (humidity_ratio <= 11) {
                        if (light <= 69) {
                            return 1;
                        } else {
                            if (temperature <= 73) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (co2 <= 7) {
                            return -1;
                        } else {
                            if (light <= 65) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 62) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    return -1;
                }
            } else {
                return 1;
            }
        }
    } else {
        if (co2 <= 26) {
            if (co2 <= 15) {
                if (light <= 64) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 59) {
                    if (light <= 35) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (temperature <= 228) {
                if (temperature <= 163) {
                    if (co2 <= 55) {
                        if (humidity <= 79) {
                            if (humidity_ratio <= 27) {
                                if (humidity_ratio <= 23) {
                                    return 1;
                                } else {
                                    if (humidity <= 35) {
                                        if (co2 <= 30) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (co2 <= 38) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (light <= 35) {
                                    return -1;
                                } else {
                                    if (light <= 86) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 38) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity_ratio <= 68) {
                        if (light <= 40) {
                            return -1;
                        } else {
                            if (temperature <= 170) {
                                if (temperature <= 169) {
                                    if (co2 <= 63) {
                                        return 1;
                                    } else {
                                        if (light <= 79) {
                                            return 1;
                                        } else {
                                            if (humidity <= 44) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (co2 <= 65) {
                                        if (light <= 82) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity <= 107) {
                            if (light <= 44) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 109) {
                                    if (humidity_ratio <= 108) {
                                        return 1;
                                    } else {
                                        if (co2 <= 76) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (light <= 74) {
                                        if (co2 <= 83) {
                                            if (temperature <= 203) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        if (humidity <= 106) {
                                            if (humidity <= 105) {
                                                return -1;
                                            } else {
                                                if (light <= 81) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (light <= 27) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 115) {
                                    if (humidity_ratio <= 113) {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (co2 <= 101) {
                                            if (light <= 75) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (humidity <= 105) {
                    if (co2 <= 90) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity_ratio <= 128) {
                        return -1;
                    } else {
                        if (light <= 100) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_76(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 138) {
        if (humidity_ratio <= 115) {
            if (humidity <= 82) {
                if (light <= 55) {
                    return -1;
                } else {
                    if (humidity <= 26) {
                        if (temperature <= 73) {
                            if (humidity_ratio <= 3) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 10) {
                    if (temperature <= 32) {
                        return -1;
                    } else {
                        if (temperature <= 33) {
                            if (humidity <= 133) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (co2 <= 13) {
                        if (temperature <= 34) {
                            if (light <= 34) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (humidity_ratio <= 152) {
                if (light <= 35) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (light <= 50) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (light <= 61) {
            if (co2 <= 233) {
                if (humidity_ratio <= 119) {
                    if (co2 <= 39) {
                        return -1;
                    } else {
                        if (light <= 35) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 5) {
                        return -1;
                    } else {
                        if (temperature <= 197) {
                            if (humidity <= 189) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (temperature <= 227) {
                if (temperature <= 201) {
                    if (co2 <= 38) {
                        if (humidity_ratio <= 27) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 27) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 40) {
                            if (co2 <= 62) {
                                return 1;
                            } else {
                                if (temperature <= 169) {
                                    if (humidity_ratio <= 40) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity <= 113) {
                                return 1;
                            } else {
                                if (humidity <= 113) {
                                    if (humidity_ratio <= 115) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 76) {
                        if (light <= 75) {
                            if (humidity_ratio <= 111) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 111) {
                    if (co2 <= 92) {
                        return 1;
                    } else {
                        if (temperature <= 230) {
                            if (light <= 98) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_77(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (light <= 62) {
            if (light <= 59) {
                if (co2 <= 10) {
                    return -1;
                } else {
                    if (co2 <= 10) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity <= 38) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (humidity <= 24) {
                if (co2 <= 4) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (temperature <= 34) {
                        if (humidity_ratio <= 77) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (co2 <= 10) {
                            if (co2 <= 9) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        if (humidity <= 189) {
            if (co2 <= 58) {
                if (humidity <= 36) {
                    if (temperature <= 163) {
                        if (temperature <= 159) {
                            if (humidity_ratio <= 27) {
                                if (temperature <= 124) {
                                    return 1;
                                } else {
                                    if (humidity <= 33) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (co2 <= 40) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity <= 80) {
                        if (light <= 38) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 171) {
                            if (humidity_ratio <= 107) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 110) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (light <= 44) {
                    if (humidity_ratio <= 173) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 175) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (humidity_ratio <= 109) {
                        if (humidity <= 43) {
                            if (humidity <= 43) {
                                if (co2 <= 62) {
                                    return 1;
                                } else {
                                    if (temperature <= 169) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (temperature <= 171) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 76) {
                            if (light <= 74) {
                                return 1;
                            } else {
                                if (humidity <= 106) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (temperature <= 230) {
                                if (temperature <= 228) {
                                    return 1;
                                } else {
                                    if (light <= 97) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity <= 116) {
                                    if (humidity <= 106) {
                                        return 1;
                                    } else {
                                        if (light <= 113) {
                                            if (light <= 94) {
                                                if (light <= 91) {
                                                    if (light <= 89) {
                                                        if (co2 <= 108) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (co2 <= 129) {
                if (co2 <= 119) {
                    return -1;
                } else {
                    if (humidity <= 207) {
                        if (light <= 41) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (light <= 27) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_78(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 32) {
        if (light <= 62) {
            if (light <= 59) {
                if (co2 <= 10) {
                    return -1;
                } else {
                    if (temperature <= 33) {
                        if (humidity_ratio <= 74) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 34) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (co2 <= 13) {
                if (light <= 70) {
                    if (humidity_ratio <= 65) {
                        if (humidity_ratio <= 4) {
                            if (light <= 67) {
                                return 1;
                            } else {
                                if (temperature <= 73) {
                                    if (humidity_ratio <= 3) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            } else {
                return 1;
            }
        }
    } else {
        if (light <= 31) {
            if (co2 <= 132) {
                return -1;
            } else {
                if (humidity <= 189) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (humidity <= 116) {
                if (humidity_ratio <= 123) {
                    if (light <= 75) {
                        if (light <= 74) {
                            return 1;
                        } else {
                            if (humidity <= 106) {
                                if (humidity <= 78) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 108) {
                            if (humidity_ratio <= 28) {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    if (humidity <= 28) {
                                        return 1;
                                    } else {
                                        if (temperature <= 159) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            } else {
                                if (co2 <= 64) {
                                    if (light <= 81) {
                                        if (light <= 81) {
                                            if (light <= 78) {
                                                return 1;
                                            } else {
                                                if (humidity <= 41) {
                                                    return 1;
                                                } else {
                                                    if (humidity_ratio <= 40) {
                                                        if (co2 <= 61) {
                                                            return 1;
                                                        } else {
                                                            if (co2 <= 62) {
                                                                return -1;
                                                            } else {
                                                                return 1;
                                                            }
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (humidity <= 43) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity_ratio <= 115) {
                                if (humidity <= 108) {
                                    if (temperature <= 198) {
                                        return 1;
                                    } else {
                                        if (co2 <= 76) {
                                            if (co2 <= 64) {
                                                if (co2 <= 62) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (humidity <= 112) {
                                        if (temperature <= 199) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (temperature <= 192) {
                                            return -1;
                                        } else {
                                            if (co2 <= 100) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 227) {
                        return 1;
                    } else {
                        if (humidity <= 111) {
                            return -1;
                        } else {
                            if (temperature <= 232) {
                                if (light <= 89) {
                                    if (light <= 88) {
                                        if (humidity <= 112) {
                                            if (co2 <= 102) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_79(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 28) {
        if (humidity_ratio <= 91) {
            if (co2 <= 13) {
                if (light <= 59) {
                    if (co2 <= 10) {
                        return -1;
                    } else {
                        if (humidity <= 117) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity <= 45) {
                        if (co2 <= 4) {
                            if (light <= 69) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (temperature <= 73) {
                                if (light <= 69) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 77) {
                            if (co2 <= 9) {
                                return 1;
                            } else {
                                if (temperature <= 69) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (light <= 32) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            return -1;
        }
    } else {
        if (temperature <= 109) {
            if (light <= 32) {
                return -1;
            } else {
                return 1;
            }
        } else {
            if (temperature <= 163) {
                if (light <= 35) {
                    return -1;
                } else {
                    if (temperature <= 162) {
                        return 1;
                    } else {
                        if (humidity_ratio <= 38) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (temperature <= 203) {
                    if (co2 <= 58) {
                        if (light <= 77) {
                            if (humidity <= 38) {
                                return 1;
                            } else {
                                if (light <= 41) {
                                    return -1;
                                } else {
                                    if (temperature <= 185) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 191) {
                            if (humidity_ratio <= 68) {
                                if (light <= 79) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 41) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 41) {
                                            return -1;
                                        } else {
                                            if (co2 <= 64) {
                                                if (light <= 82) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (light <= 18) {
                                    return -1;
                                } else {
                                    if (light <= 77) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 112) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 154) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (humidity <= 113) {
                                return 1;
                            } else {
                                if (light <= 33) {
                                    return -1;
                                } else {
                                    if (humidity <= 113) {
                                        if (co2 <= 102) {
                                            if (humidity_ratio <= 116) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (light <= 38) {
                        return -1;
                    } else {
                        if (co2 <= 76) {
                            return -1;
                        } else {
                            if (light <= 86) {
                                return 1;
                            } else {
                                if (temperature <= 227) {
                                    return 1;
                                } else {
                                    if (humidity <= 111) {
                                        return -1;
                                    } else {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            if (humidity <= 116) {
                                                if (co2 <= 110) {
                                                    if (co2 <= 101) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    if (humidity_ratio <= 129) {
                                                        return 1;
                                                    } else {
                                                        if (co2 <= 110) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_80(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (light <= 65) {
            if (humidity <= 117) {
                return -1;
            } else {
                if (co2 <= 9) {
                    return -1;
                } else {
                    if (humidity_ratio <= 77) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (humidity_ratio <= 14) {
                if (humidity <= 25) {
                    if (humidity_ratio <= 9) {
                        if (light <= 69) {
                            return 1;
                        } else {
                            if (light <= 70) {
                                if (humidity_ratio <= 3) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (co2 <= 13) {
                    if (humidity_ratio <= 77) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (temperature <= 111) {
            if (humidity_ratio <= 148) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (temperature <= 163) {
                if (light <= 44) {
                    return -1;
                } else {
                    if (light <= 86) {
                        return 1;
                    } else {
                        if (humidity <= 30) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (humidity_ratio <= 69) {
                    if (light <= 36) {
                        return -1;
                    } else {
                        if (temperature <= 170) {
                            if (light <= 79) {
                                return 1;
                            } else {
                                if (humidity <= 43) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 42) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 27) {
                        return -1;
                    } else {
                        if (humidity <= 108) {
                            if (humidity <= 104) {
                                if (humidity <= 104) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 107) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 109) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (temperature <= 200) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 112) {
                                        if (humidity_ratio <= 110) {
                                            return -1;
                                        } else {
                                            if (light <= 75) {
                                                if (light <= 74) {
                                                    return 1;
                                                } else {
                                                    if (co2 <= 61) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                if (humidity <= 106) {
                                                    if (humidity <= 105) {
                                                        return -1;
                                                    } else {
                                                        if (co2 <= 63) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    }
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        }
                                    } else {
                                        if (light <= 79) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 121) {
                                                if (humidity_ratio <= 117) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (temperature <= 230) {
                                if (humidity_ratio <= 115) {
                                    if (co2 <= 84) {
                                        if (light <= 84) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (light <= 77) {
                                            if (humidity_ratio <= 115) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            if (temperature <= 191) {
                                                if (temperature <= 190) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (co2 <= 103) {
                                        if (humidity_ratio <= 124) {
                                            return 1;
                                        } else {
                                            if (co2 <= 102) {
                                                return 1;
                                            } else {
                                                if (temperature <= 223) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity <= 114) {
                                    return -1;
                                } else {
                                    if (temperature <= 232) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_81(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 114) {
        if (light <= 48) {
            return -1;
        } else {
            if (humidity_ratio <= 4) {
                return -1;
            } else {
                if (co2 <= 13) {
                    if (humidity <= 120) {
                        if (temperature <= 91) {
                            return 1;
                        } else {
                            if (humidity <= 66) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (humidity_ratio <= 35) {
            if (light <= 65) {
                if (co2 <= 39) {
                    return -1;
                } else {
                    if (humidity_ratio <= 28) {
                        if (humidity_ratio <= 28) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (light <= 89) {
                    return 1;
                } else {
                    if (light <= 89) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (temperature <= 163) {
                if (co2 <= 54) {
                    if (light <= 33) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity_ratio <= 190) {
                        if (humidity <= 45) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 165) {
                                if (light <= 49) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (light <= 40) {
                                    if (light <= 5) {
                                        return -1;
                                    } else {
                                        if (humidity_ratio <= 175) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (humidity_ratio <= 191) {
                            if (humidity <= 211) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (humidity_ratio <= 67) {
                    if (co2 <= 64) {
                        if (co2 <= 64) {
                            if (light <= 35) {
                                return -1;
                            } else {
                                if (co2 <= 62) {
                                    return 1;
                                } else {
                                    if (co2 <= 62) {
                                        if (light <= 80) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (light <= 27) {
                        return -1;
                    } else {
                        if (co2 <= 73) {
                            if (humidity_ratio <= 114) {
                                if (temperature <= 200) {
                                    return 1;
                                } else {
                                    if (co2 <= 63) {
                                        if (humidity_ratio <= 110) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 86) {
                                if (co2 <= 77) {
                                    if (humidity <= 102) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (light <= 76) {
                                        return 1;
                                    } else {
                                        if (co2 <= 100) {
                                            if (co2 <= 99) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 113) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (co2 <= 97) {
                                    return -1;
                                } else {
                                    if (humidity <= 114) {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 124) {
                                                if (light <= 86) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        if (humidity <= 115) {
                                            if (temperature <= 228) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 128) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_82(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (light <= 62) {
            if (co2 <= 10) {
                if (light <= 59) {
                    return -1;
                } else {
                    if (humidity <= 38) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (humidity <= 117) {
                    return -1;
                } else {
                    if (humidity_ratio <= 113) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (light <= 70) {
                if (co2 <= 7) {
                    if (temperature <= 74) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (co2 <= 13) {
                        if (humidity <= 121) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 52) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
    } else {
        if (humidity <= 186) {
            if (light <= 34) {
                return -1;
            } else {
                if (humidity <= 104) {
                    if (co2 <= 64) {
                        if (temperature <= 169) {
                            if (light <= 89) {
                                return 1;
                            } else {
                                if (light <= 90) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity <= 43) {
                                return 1;
                            } else {
                                if (co2 <= 64) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (humidity_ratio <= 115) {
                        if (humidity_ratio <= 111) {
                            if (temperature <= 200) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 110) {
                                    return -1;
                                } else {
                                    if (co2 <= 61) {
                                        return -1;
                                    } else {
                                        if (co2 <= 63) {
                                            return 1;
                                        } else {
                                            if (co2 <= 81) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (co2 <= 76) {
                                if (humidity <= 109) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    if (co2 <= 99) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (co2 <= 97) {
                            if (light <= 88) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (light <= 87) {
                                return 1;
                            } else {
                                if (temperature <= 228) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 130) {
                                        if (humidity_ratio <= 125) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (co2 <= 124) {
                if (light <= 41) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (light <= 5) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_83(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity_ratio <= 246) {
            if (co2 <= 39) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (temperature <= 32) {
                        return -1;
                    } else {
                        if (co2 <= 7) {
                            if (light <= 58) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 117) {
                                return -1;
                            } else {
                                if (light <= 24) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 40) {
                    return 1;
                } else {
                    if (humidity_ratio <= 85) {
                        if (light <= 28) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (co2 <= 7) {
            if (light <= 67) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (humidity <= 104) {
                if (humidity_ratio <= 40) {
                    if (humidity <= 30) {
                        if (co2 <= 37) {
                            return 1;
                        } else {
                            if (temperature <= 168) {
                                if (temperature <= 159) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 40) {
                            return 1;
                        } else {
                            if (co2 <= 62) {
                                return 1;
                            } else {
                                if (light <= 79) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 108) {
                    if (light <= 73) {
                        return 1;
                    } else {
                        if (co2 <= 94) {
                            if (co2 <= 82) {
                                if (light <= 74) {
                                    if (humidity_ratio <= 111) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (humidity <= 106) {
                                        if (co2 <= 61) {
                                            return -1;
                                        } else {
                                            if (co2 <= 63) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                if (temperature <= 241) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity_ratio <= 82) {
                        if (humidity <= 120) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity <= 116) {
                            if (light <= 83) {
                                if (co2 <= 100) {
                                    if (humidity_ratio <= 113) {
                                        return 1;
                                    } else {
                                        if (light <= 75) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (temperature <= 227) {
                                    if (humidity_ratio <= 116) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (co2 <= 112) {
                                        if (humidity_ratio <= 125) {
                                            if (humidity <= 111) {
                                                return -1;
                                            } else {
                                                if (temperature <= 230) {
                                                    if (light <= 86) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_84(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 15) {
        if (temperature <= 69) {
            if (light <= 71) {
                if (co2 <= 10) {
                    return -1;
                } else {
                    if (light <= 24) {
                        return -1;
                    } else {
                        if (humidity <= 120) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                return 1;
            }
        } else {
            if (co2 <= 13) {
                if (light <= 63) {
                    if (light <= 59) {
                        return -1;
                    } else {
                        if (humidity <= 38) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (co2 <= 10) {
                        if (light <= 67) {
                            return 1;
                        } else {
                            if (co2 <= 7) {
                                return -1;
                            } else {
                                if (temperature <= 70) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (light <= 34) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (light <= 35) {
            if (light <= 5) {
                return -1;
            } else {
                if (light <= 5) {
                    if (temperature <= 187) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (humidity <= 116) {
                if (temperature <= 204) {
                    if (humidity_ratio <= 41) {
                        if (co2 <= 62) {
                            if (humidity <= 30) {
                                if (temperature <= 163) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 41) {
                                if (co2 <= 62) {
                                    if (temperature <= 171) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (co2 <= 100) {
                            if (humidity_ratio <= 108) {
                                return 1;
                            } else {
                                if (temperature <= 201) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (co2 <= 100) {
                                if (light <= 76) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (light <= 74) {
                        if (humidity_ratio <= 113) {
                            if (humidity <= 106) {
                                return 1;
                            } else {
                                if (co2 <= 85) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity_ratio <= 118) {
                            if (co2 <= 76) {
                                if (light <= 75) {
                                    if (co2 <= 61) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (temperature <= 227) {
                                return 1;
                            } else {
                                if (humidity <= 106) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 126) {
                                        return -1;
                                    } else {
                                        if (light <= 91) {
                                            if (co2 <= 110) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_85(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (humidity_ratio <= 115) {
        if (light <= 61) {
            if (humidity_ratio <= 28) {
                return -1;
            } else {
                if (co2 <= 10) {
                    if (humidity <= 65) {
                        if (temperature <= 105) {
                            return -1;
                        } else {
                            if (humidity <= 55) {
                                return -1;
                            } else {
                                if (light <= 29) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (light <= 33) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (humidity <= 24) {
                return -1;
            } else {
                if (light <= 94) {
                    if (temperature <= 204) {
                        if (co2 <= 99) {
                            if (humidity <= 30) {
                                if (humidity <= 30) {
                                    if (temperature <= 163) {
                                        if (co2 <= 26) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                if (temperature <= 36) {
                                    if (temperature <= 34) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (humidity_ratio <= 109) {
                                        if (temperature <= 107) {
                                            if (co2 <= 11) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (humidity <= 43) {
                                                if (humidity_ratio <= 41) {
                                                    return 1;
                                                } else {
                                                    if (temperature <= 171) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (humidity_ratio <= 109) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (temperature <= 191) {
                                return -1;
                            } else {
                                if (humidity <= 113) {
                                    return 1;
                                } else {
                                    if (light <= 77) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else {
                        if (light <= 74) {
                            if (light <= 73) {
                                return 1;
                            } else {
                                if (co2 <= 83) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (co2 <= 75) {
                                if (light <= 80) {
                                    return -1;
                                } else {
                                    if (co2 <= 67) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 196) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
    } else {
        if (temperature <= 126) {
            if (humidity_ratio <= 150) {
                return 1;
            } else {
                if (light <= 36) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (humidity <= 110) {
                if (light <= 31) {
                    return -1;
                } else {
                    if (humidity_ratio <= 121) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity <= 221) {
                    if (temperature <= 230) {
                        if (light <= 33) {
                            return -1;
                        } else {
                            if (temperature <= 227) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 124) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (humidity_ratio <= 128) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (light <= 27) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
}
int predict_tree_86(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (co2 <= 13) {
            if (light <= 66) {
                if (humidity_ratio <= 75) {
                    return -1;
                } else {
                    if (humidity_ratio <= 75) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 7) {
                    if (humidity <= 22) {
                        if (co2 <= 4) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 9) {
                        if (humidity <= 23) {
                            if (co2 <= 7) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 94) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            }
        } else {
            if (temperature <= 66) {
                return 1;
            } else {
                if (temperature <= 127) {
                    if (co2 <= 23) {
                        if (light <= 33) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity_ratio <= 21) {
                            return 1;
                        } else {
                            if (temperature <= 123) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 44) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    return -1;
                }
            }
        }
    } else {
        if (humidity <= 189) {
            if (light <= 28) {
                if (light <= 5) {
                    return -1;
                } else {
                    if (light <= 5) {
                        if (co2 <= 111) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 109) {
                    if (humidity_ratio <= 27) {
                        if (temperature <= 159) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 27) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (humidity <= 43) {
                            if (humidity <= 43) {
                                return 1;
                            } else {
                                if (temperature <= 183) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity <= 108) {
                        if (light <= 75) {
                            if (humidity <= 107) {
                                if (co2 <= 79) {
                                    if (light <= 74) {
                                        if (co2 <= 63) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 109) {
                                return 1;
                            } else {
                                if (humidity <= 106) {
                                    if (temperature <= 223) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity_ratio <= 113) {
                                        return -1;
                                    } else {
                                        if (light <= 79) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (light <= 87) {
                            if (co2 <= 99) {
                                if (humidity <= 114) {
                                    if (co2 <= 99) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (light <= 87) {
                                if (humidity_ratio <= 133) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (temperature <= 237) {
                                    if (temperature <= 230) {
                                        return 1;
                                    } else {
                                        if (co2 <= 110) {
                                            if (temperature <= 232) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (light <= 30) {
                return -1;
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_87(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (humidity <= 80) {
            if (co2 <= 12) {
                if (light <= 63) {
                    if (humidity_ratio <= 47) {
                        return -1;
                    } else {
                        if (humidity <= 65) {
                            if (light <= 29) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (co2 <= 7) {
                        if (humidity_ratio <= 3) {
                            if (temperature <= 74) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity_ratio <= 3) {
                            return -1;
                        } else {
                            if (co2 <= 9) {
                                return 1;
                            } else {
                                if (temperature <= 108) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            } else {
                if (light <= 33) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (humidity_ratio <= 92) {
                if (light <= 39) {
                    return -1;
                } else {
                    if (co2 <= 13) {
                        if (humidity_ratio <= 76) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                return -1;
            }
        }
    } else {
        if (light <= 31) {
            if (light <= 5) {
                return -1;
            } else {
                if (co2 <= 122) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (light <= 93) {
                if (co2 <= 76) {
                    if (humidity_ratio <= 107) {
                        if (light <= 78) {
                            return 1;
                        } else {
                            if (humidity <= 43) {
                                if (humidity <= 43) {
                                    if (co2 <= 38) {
                                        if (humidity <= 30) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (humidity <= 42) {
                                            return 1;
                                        } else {
                                            if (light <= 79) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                } else {
                                    if (humidity_ratio <= 45) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 114) {
                            if (co2 <= 60) {
                                if (temperature <= 201) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (light <= 75) {
                                    if (co2 <= 61) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (temperature <= 227) {
                        if (co2 <= 100) {
                            if (co2 <= 100) {
                                if (humidity <= 113) {
                                    return 1;
                                } else {
                                    if (co2 <= 97) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 127) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (humidity <= 113) {
                            if (light <= 86) {
                                return 1;
                            } else {
                                if (co2 <= 97) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (co2 <= 97) {
                    if (humidity <= 74) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_88(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (co2 <= 40) {
            if (light <= 59) {
                if (light <= 48) {
                    return -1;
                } else {
                    if (co2 <= 9) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 7) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            if (light <= 31) {
                return -1;
            } else {
                return 1;
            }
        }
    } else {
        if (temperature <= 227) {
            if (co2 <= 7) {
                if (humidity_ratio <= 3) {
                    if (light <= 69) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            } else {
                if (humidity <= 124) {
                    if (temperature <= 201) {
                        if (humidity <= 120) {
                            if (co2 <= 99) {
                                if (light <= 78) {
                                    return 1;
                                } else {
                                    if (temperature <= 170) {
                                        if (light <= 79) {
                                            if (humidity_ratio <= 42) {
                                                if (co2 <= 50) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            if (co2 <= 38) {
                                                if (temperature <= 164) {
                                                    if (humidity <= 31) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                if (humidity <= 43) {
                                                    return 1;
                                                } else {
                                                    if (humidity <= 43) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (co2 <= 99) {
                                    return -1;
                                } else {
                                    if (co2 <= 100) {
                                        if (humidity <= 112) {
                                            return 1;
                                        } else {
                                            if (light <= 75) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            if (light <= 69) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (co2 <= 80) {
                            if (humidity <= 114) {
                                if (co2 <= 62) {
                                    if (humidity <= 105) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            if (light <= 104) {
                if (co2 <= 110) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (temperature <= 237) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
    }
}
int predict_tree_89(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity_ratio <= 247) {
            if (light <= 35) {
                if (humidity_ratio <= 175) {
                    return -1;
                } else {
                    if (humidity <= 189) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity_ratio <= 115) {
                    if (co2 <= 9) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity <= 24) {
            if (humidity <= 22) {
                if (light <= 69) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (temperature <= 73) {
                    if (light <= 69) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (co2 <= 12) {
                if (humidity <= 120) {
                    if (temperature <= 91) {
                        return 1;
                    } else {
                        if (temperature <= 107) {
                            return -1;
                        } else {
                            if (light <= 155) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    return -1;
                }
            } else {
                if (light <= 86) {
                    if (humidity_ratio <= 115) {
                        if (humidity_ratio <= 108) {
                            if (co2 <= 13) {
                                if (humidity_ratio <= 67) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (humidity <= 43) {
                                    if (humidity <= 43) {
                                        return 1;
                                    } else {
                                        if (co2 <= 64) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity <= 107) {
                                if (co2 <= 85) {
                                    if (temperature <= 200) {
                                        return 1;
                                    } else {
                                        if (humidity_ratio <= 111) {
                                            if (co2 <= 62) {
                                                return -1;
                                            } else {
                                                if (co2 <= 63) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            } else {
                                if (humidity_ratio <= 115) {
                                    if (light <= 80) {
                                        if (humidity_ratio <= 113) {
                                            return 1;
                                        } else {
                                            if (temperature <= 192) {
                                                return -1;
                                            } else {
                                                if (co2 <= 99) {
                                                    if (light <= 74) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    if (temperature <= 230) {
                        if (humidity <= 114) {
                            if (temperature <= 203) {
                                if (temperature <= 163) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (temperature <= 216) {
                                    return -1;
                                } else {
                                    if (temperature <= 227) {
                                        return 1;
                                    } else {
                                        if (co2 <= 101) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 110) {
                            if (light <= 113) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_90(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 62) {
        if (humidity <= 247) {
            if (co2 <= 10) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (co2 <= 7) {
                        if (light <= 58) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (co2 <= 10) {
                    return 1;
                } else {
                    if (co2 <= 68) {
                        return -1;
                    } else {
                        if (light <= 31) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity <= 25) {
            if (humidity_ratio <= 9) {
                if (light <= 69) {
                    if (humidity_ratio <= 4) {
                        if (humidity_ratio <= 3) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            } else {
                return -1;
            }
        } else {
            if (temperature <= 204) {
                if (light <= 76) {
                    if (light <= 65) {
                        if (humidity <= 125) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (temperature <= 201) {
                            return 1;
                        } else {
                            if (humidity <= 103) {
                                return 1;
                            } else {
                                if (co2 <= 75) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (temperature <= 190) {
                        if (humidity <= 30) {
                            if (temperature <= 163) {
                                if (humidity <= 30) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity <= 43) {
                                if (humidity_ratio <= 41) {
                                    return 1;
                                } else {
                                    if (co2 <= 64) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (light <= 76) {
                            if (humidity <= 110) {
                                return 1;
                            } else {
                                if (co2 <= 103) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (temperature <= 191) {
                                if (co2 <= 86) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 76) {
                    if (co2 <= 63) {
                        if (humidity <= 105) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    if (co2 <= 98) {
                        if (light <= 91) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity <= 116) {
                            if (humidity_ratio <= 124) {
                                if (humidity_ratio <= 124) {
                                    return 1;
                                } else {
                                    if (light <= 104) {
                                        if (co2 <= 102) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (light <= 104) {
                                    if (humidity_ratio <= 128) {
                                        return -1;
                                    } else {
                                        if (co2 <= 110) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_91(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (co2 <= 40) {
            if (co2 <= 7) {
                return -1;
            } else {
                if (co2 <= 7) {
                    if (light <= 58) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (light <= 27) {
                if (co2 <= 131) {
                    return -1;
                } else {
                    if (light <= 3) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (humidity <= 24) {
            if (humidity_ratio <= 3) {
                if (temperature <= 71) {
                    return -1;
                } else {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                return -1;
            }
        } else {
            if (humidity <= 116) {
                if (temperature <= 227) {
                    if (humidity_ratio <= 109) {
                        if (light <= 99) {
                            if (humidity_ratio <= 41) {
                                if (humidity_ratio <= 41) {
                                    if (light <= 87) {
                                        if (co2 <= 62) {
                                            return 1;
                                        } else {
                                            if (light <= 78) {
                                                return 1;
                                            } else {
                                                if (light <= 79) {
                                                    return -1;
                                                } else {
                                                    if (humidity <= 43) {
                                                        return 1;
                                                    } else {
                                                        if (temperature <= 159) {
                                                            return 1;
                                                        } else {
                                                            return -1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (co2 <= 38) {
                                            if (temperature <= 164) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        if (co2 <= 76) {
                            if (light <= 74) {
                                if (temperature <= 203) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (co2 <= 63) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (humidity <= 112) {
                                return 1;
                            } else {
                                if (temperature <= 192) {
                                    return -1;
                                } else {
                                    if (co2 <= 99) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 122) {
                        return 1;
                    } else {
                        if (light <= 108) {
                            if (humidity_ratio <= 124) {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            if (humidity <= 110) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (temperature <= 36) {
                    if (co2 <= 12) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_92(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (co2 <= 131) {
            if (light <= 59) {
                if (temperature <= 238) {
                    if (light <= 48) {
                        return -1;
                    } else {
                        if (co2 <= 9) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                } else {
                    if (humidity_ratio <= 72) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (temperature <= 165) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (co2 <= 132) {
                return 1;
            } else {
                return -1;
            }
        }
    } else {
        if (temperature <= 230) {
            if (co2 <= 7) {
                if (light <= 67) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                if (temperature <= 204) {
                    if (light <= 66) {
                        if (humidity_ratio <= 83) {
                            if (co2 <= 14) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 74) {
                            return 1;
                        } else {
                            if (light <= 74) {
                                if (humidity <= 109) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 100) {
                                    if (light <= 79) {
                                        if (co2 <= 99) {
                                            if (humidity_ratio <= 114) {
                                                if (humidity <= 43) {
                                                    if (light <= 78) {
                                                        return 1;
                                                    } else {
                                                        if (temperature <= 170) {
                                                            if (light <= 79) {
                                                                if (co2 <= 61) {
                                                                    return 1;
                                                                } else {
                                                                    return -1;
                                                                }
                                                            } else {
                                                                return -1;
                                                            }
                                                        } else {
                                                            return 1;
                                                        }
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                if (humidity_ratio <= 125) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            if (humidity <= 112) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        }
                                    } else {
                                        if (temperature <= 163) {
                                            if (light <= 87) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 36) {
                                                    return -1;
                                                } else {
                                                    return 1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 81) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (light <= 89) {
                if (light <= 87) {
                    if (co2 <= 109) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            } else {
                if (light <= 104) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_93(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (co2 <= 12) {
            if (temperature <= 69) {
                if (temperature <= 32) {
                    return -1;
                } else {
                    if (light <= 43) {
                        return -1;
                    } else {
                        if (light <= 48) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (temperature <= 73) {
                    if (light <= 68) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (light <= 64) {
                        if (co2 <= 7) {
                            return -1;
                        } else {
                            if (humidity_ratio <= 39) {
                                return -1;
                            } else {
                                if (light <= 29) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        }
                    } else {
                        if (light <= 70) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            }
        } else {
            if (temperature <= 66) {
                if (humidity <= 124) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (temperature <= 127) {
                    if (humidity_ratio <= 108) {
                        if (humidity <= 52) {
                            if (humidity_ratio <= 11) {
                                return 1;
                            } else {
                                if (humidity <= 32) {
                                    if (light <= 34) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity_ratio <= 19) {
                                        return 1;
                                    } else {
                                        if (humidity <= 34) {
                                            if (light <= 35) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            }
        }
    } else {
        if (light <= 35) {
            if (temperature <= 154) {
                return -1;
            } else {
                if (temperature <= 157) {
                    if (co2 <= 131) {
                        return -1;
                    } else {
                        if (humidity <= 208) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    return -1;
                }
            }
        } else {
            if (temperature <= 204) {
                if (co2 <= 38) {
                    if (light <= 86) {
                        return 1;
                    } else {
                        if (light <= 87) {
                            return -1;
                        } else {
                            if (co2 <= 37) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (temperature <= 190) {
                        if (humidity <= 43) {
                            if (humidity <= 43) {
                                return 1;
                            } else {
                                if (light <= 80) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (light <= 78) {
                            return 1;
                        } else {
                            if (temperature <= 191) {
                                if (light <= 78) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (humidity <= 108) {
                    if (humidity <= 104) {
                        return 1;
                    } else {
                        if (humidity <= 107) {
                            if (light <= 74) {
                                return 1;
                            } else {
                                if (humidity_ratio <= 117) {
                                    if (humidity <= 106) {
                                        if (co2 <= 61) {
                                            return -1;
                                        } else {
                                            if (humidity <= 105) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    if (humidity_ratio <= 122) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            if (light <= 81) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (co2 <= 80) {
                        return -1;
                    } else {
                        if (light <= 86) {
                            return 1;
                        } else {
                            if (light <= 87) {
                                if (co2 <= 105) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                if (co2 <= 109) {
                                    return 1;
                                } else {
                                    if (co2 <= 109) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_94(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (co2 <= 27) {
        if (humidity_ratio <= 90) {
            if (humidity <= 127) {
                if (co2 <= 13) {
                    if (light <= 67) {
                        if (light <= 48) {
                            return -1;
                        } else {
                            if (temperature <= 34) {
                                if (humidity <= 119) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    } else {
                        if (co2 <= 7) {
                            return -1;
                        } else {
                            if (co2 <= 9) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 48) {
                        if (humidity <= 28) {
                            return 1;
                        } else {
                            if (light <= 34) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 11) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            return -1;
        }
    } else {
        if (humidity <= 189) {
            if (light <= 31) {
                if (humidity <= 188) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (humidity <= 104) {
                    return 1;
                } else {
                    if (temperature <= 201) {
                        if (co2 <= 99) {
                            if (light <= 77) {
                                return 1;
                            } else {
                                if (humidity <= 112) {
                                    return 1;
                                } else {
                                    if (temperature <= 196) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 76) {
                            if (light <= 73) {
                                return 1;
                            } else {
                                if (light <= 75) {
                                    if (humidity_ratio <= 111) {
                                        return -1;
                                    } else {
                                        if (co2 <= 65) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    }
                                } else {
                                    return -1;
                                }
                            }
                        } else {
                            if (co2 <= 97) {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            } else {
                                if (temperature <= 227) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 127) {
                                        if (co2 <= 101) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (light <= 35) {
                return -1;
            } else {
                return 1;
            }
        }
    }
}
int predict_tree_95(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (co2 <= 233) {
            if (light <= 35) {
                if (temperature <= 155) {
                    return -1;
                } else {
                    if (humidity_ratio <= 147) {
                        return -1;
                    } else {
                        if (light <= 3) {
                            return -1;
                        } else {
                            if (co2 <= 131) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            } else {
                if (co2 <= 9) {
                    return -1;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity_ratio <= 4) {
            if (light <= 67) {
                return 1;
            } else {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (co2 <= 7) {
                        return 1;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            if (temperature <= 234) {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (temperature <= 204) {
                        if (co2 <= 13) {
                            if (light <= 67) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 48) {
                                    if (humidity_ratio <= 29) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity <= 30) {
                                if (humidity_ratio <= 27) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 27) {
                                        if (temperature <= 165) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 41) {
                                    if (humidity_ratio <= 41) {
                                        if (humidity_ratio <= 40) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 40) {
                                                if (light <= 78) {
                                                    if (co2 <= 61) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                } else {
                                                    return 1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        if (temperature <= 171) {
                                            if (co2 <= 61) {
                                                return 1;
                                            } else {
                                                return -1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    }
                                } else {
                                    if (light <= 75) {
                                        return 1;
                                    } else {
                                        if (temperature <= 201) {
                                            if (temperature <= 190) {
                                                return 1;
                                            } else {
                                                if (humidity_ratio <= 113) {
                                                    return 1;
                                                } else {
                                                    if (humidity <= 113) {
                                                        if (co2 <= 99) {
                                                            return -1;
                                                        } else {
                                                            return 1;
                                                        }
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (humidity_ratio <= 114) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (humidity <= 108) {
                            if (co2 <= 76) {
                                if (humidity_ratio <= 111) {
                                    if (humidity_ratio <= 110) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (co2 <= 80) {
                                return -1;
                            } else {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    if (light <= 87) {
                                        if (co2 <= 102) {
                                            return 1;
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        if (temperature <= 230) {
                                            return 1;
                                        } else {
                                            if (co2 <= 112) {
                                                if (light <= 89) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            } else {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (light <= 91) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
    }
}
int predict_tree_96(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 61) {
        if (humidity <= 247) {
            if (humidity_ratio <= 175) {
                if (co2 <= 40) {
                    if (humidity_ratio <= 47) {
                        return -1;
                    } else {
                        if (humidity <= 65) {
                            if (light <= 29) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            if (humidity_ratio <= 75) {
                                if (light <= 27) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        }
                    }
                } else {
                    if (humidity_ratio <= 28) {
                        if (co2 <= 40) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        return -1;
                    }
                }
            } else {
                if (humidity <= 189) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (humidity_ratio <= 14) {
            if (light <= 69) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (light <= 86) {
                if (temperature <= 204) {
                    if (temperature <= 34) {
                        if (humidity <= 120) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (light <= 76) {
                            if (temperature <= 107) {
                                if (temperature <= 105) {
                                    return 1;
                                } else {
                                    if (co2 <= 14) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        } else {
                            if (co2 <= 100) {
                                if (humidity <= 111) {
                                    if (temperature <= 169) {
                                        if (light <= 79) {
                                            if (humidity_ratio <= 41) {
                                                if (light <= 78) {
                                                    return 1;
                                                } else {
                                                    if (temperature <= 156) {
                                                        return 1;
                                                    } else {
                                                        return -1;
                                                    }
                                                }
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity <= 122) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (humidity <= 107) {
                        if (humidity_ratio <= 109) {
                            return 1;
                        } else {
                            if (co2 <= 87) {
                                if (humidity <= 106) {
                                    if (humidity <= 105) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (humidity_ratio <= 114) {
                            if (humidity <= 108) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    }
                }
            } else {
                if (temperature <= 227) {
                    if (temperature <= 163) {
                        if (humidity_ratio <= 26) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (temperature <= 204) {
                            return 1;
                        } else {
                            if (humidity_ratio <= 117) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    if (co2 <= 92) {
                        return 1;
                    } else {
                        if (temperature <= 234) {
                            if (co2 <= 100) {
                                return 1;
                            } else {
                                if (humidity <= 116) {
                                    return -1;
                                } else {
                                    if (co2 <= 110) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                }
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_97(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (light <= 48) {
            if (co2 <= 68) {
                return -1;
            } else {
                if (humidity_ratio <= 85) {
                    if (humidity_ratio <= 83) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (temperature <= 154) {
                        return -1;
                    } else {
                        if (humidity <= 189) {
                            if (humidity_ratio <= 147) {
                                return -1;
                            } else {
                                return 1;
                            }
                        } else {
                            return -1;
                        }
                    }
                }
            }
        } else {
            if (co2 <= 9) {
                if (humidity_ratio <= 36) {
                    return -1;
                } else {
                    if (temperature <= 82) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        }
    } else {
        if (temperature <= 230) {
            if (co2 <= 7) {
                if (humidity_ratio <= 3) {
                    return 1;
                } else {
                    if (co2 <= 7) {
                        return -1;
                    } else {
                        if (co2 <= 7) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                }
            } else {
                if (co2 <= 74) {
                    if (humidity_ratio <= 108) {
                        if (co2 <= 12) {
                            if (temperature <= 54) {
                                return -1;
                            } else {
                                if (humidity <= 66) {
                                    if (co2 <= 9) {
                                        return 1;
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            if (humidity <= 43) {
                                if (humidity <= 43) {
                                    if (humidity <= 30) {
                                        if (humidity_ratio <= 27) {
                                            return 1;
                                        } else {
                                            if (temperature <= 164) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    if (humidity_ratio <= 42) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 202) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    if (co2 <= 100) {
                        if (co2 <= 100) {
                            if (humidity <= 112) {
                                if (humidity_ratio <= 113) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 114) {
                                        return -1;
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 120) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            }
                        } else {
                            return -1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (light <= 89) {
                return 1;
            } else {
                if (light <= 105) {
                    if (co2 <= 112) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}
int predict_tree_98(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (temperature <= 113) {
        if (co2 <= 10) {
            if (humidity <= 21) {
                if (light <= 33) {
                    return -1;
                } else {
                    if (humidity_ratio <= 3) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 7) {
                    return -1;
                } else {
                    if (light <= 50) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 3) {
                            return -1;
                        } else {
                            if (co2 <= 9) {
                                return 1;
                            } else {
                                return -1;
                            }
                        }
                    }
                }
            }
        } else {
            if (light <= 32) {
                return -1;
            } else {
                if (temperature <= 37) {
                    if (light <= 67) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    } else {
        if (humidity_ratio <= 26) {
            if (humidity <= 32) {
                if (co2 <= 29) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (co2 <= 27) {
                    if (light <= 37) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else {
                    if (light <= 35) {
                        return -1;
                    } else {
                        return 1;
                    }
                }
            }
        } else {
            if (light <= 24) {
                return -1;
            } else {
                if (temperature <= 203) {
                    if (humidity <= 29) {
                        if (humidity <= 29) {
                            return 1;
                        } else {
                            return -1;
                        }
                    } else {
                        if (humidity <= 104) {
                            return 1;
                        } else {
                            if (co2 <= 58) {
                                return -1;
                            } else {
                                if (humidity_ratio <= 115) {
                                    if (humidity_ratio <= 115) {
                                        if (humidity_ratio <= 113) {
                                            return 1;
                                        } else {
                                            if (humidity_ratio <= 113) {
                                                return -1;
                                            } else {
                                                if (humidity_ratio <= 114) {
                                                    return 1;
                                                } else {
                                                    if (co2 <= 100) {
                                                        return -1;
                                                    } else {
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return -1;
                                    }
                                } else {
                                    return 1;
                                }
                            }
                        }
                    }
                } else {
                    if (humidity <= 109) {
                        if (humidity <= 104) {
                            return 1;
                        } else {
                            if (co2 <= 99) {
                                if (humidity <= 106) {
                                    if (temperature <= 223) {
                                        if (humidity <= 105) {
                                            if (humidity_ratio <= 111) {
                                                return -1;
                                            } else {
                                                if (co2 <= 63) {
                                                    return 1;
                                                } else {
                                                    return -1;
                                                }
                                            }
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return -1;
                                }
                            } else {
                                return 1;
                            }
                        }
                    } else {
                        if (temperature <= 227) {
                            return 1;
                        } else {
                            if (light <= 105) {
                                if (light <= 86) {
                                    return 1;
                                } else {
                                    if (humidity_ratio <= 127) {
                                        return -1;
                                    } else {
                                        if (temperature <= 232) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    }
                                }
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
int predict_tree_99(unsigned short temperature, unsigned short humidity, unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    if (light <= 60) {
        if (humidity <= 247) {
            if (co2 <= 39) {
                return -1;
            } else {
                if (light <= 31) {
                    if (light <= 5) {
                        return -1;
                    } else {
                        if (humidity_ratio <= 169) {
                            return -1;
                        } else {
                            if (co2 <= 131) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        if (co2 <= 7) {
            if (light <= 67) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (temperature <= 230) {
                if (temperature <= 200) {
                    if (light <= 66) {
                        if (temperature <= 37) {
                            return -1;
                        } else {
                            return 1;
                        }
                    } else {
                        if (co2 <= 10) {
                            if (co2 <= 9) {
                                return 1;
                            } else {
                                return -1;
                            }
                        } else {
                            if (temperature <= 193) {
                                if (light <= 78) {
                                    return 1;
                                } else {
                                    if (co2 <= 62) {
                                        if (light <= 78) {
                                            return -1;
                                        } else {
                                            return 1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            } else {
                                if (humidity_ratio <= 114) {
                                    return 1;
                                } else {
                                    if (humidity <= 113) {
                                        if (humidity <= 113) {
                                            if (co2 <= 100) {
                                                return -1;
                                            } else {
                                                return 1;
                                            }
                                        } else {
                                            return -1;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (co2 <= 76) {
                        if (humidity_ratio <= 118) {
                            if (co2 <= 63) {
                                if (humidity_ratio <= 110) {
                                    return -1;
                                } else {
                                    return 1;
                                }
                            } else {
                                return -1;
                            }
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            } else {
                if (co2 <= 112) {
                    if (light <= 113) {
                        if (humidity <= 106) {
                            return 1;
                        } else {
                            if (co2 <= 108) {
                                return -1;
                            } else {
                                if (co2 <= 110) {
                                    return 1;
                                } else {
                                    return -1;
                                }
                            }
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }
}

char predict_random_forest(unsigned short temperature, unsigned short humidity,
                           unsigned short light, unsigned short co2, unsigned short humidity_ratio) {
    int votes = 0;  // Assuming binary classification (class 0 and class 1)
    votes += predict_tree_0(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_1(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_2(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_3(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_4(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_5(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_6(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_7(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_8(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_9(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_10(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_11(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_12(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_13(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_14(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_15(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_16(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_17(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_18(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_19(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_20(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_21(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_22(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_23(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_24(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_25(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_26(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_27(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_28(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_29(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_30(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_31(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_32(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_33(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_34(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_35(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_36(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_37(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_38(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_39(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_40(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_41(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_42(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_43(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_44(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_45(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_46(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_47(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_48(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_49(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_50(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_51(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_52(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_53(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_54(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_55(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_56(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_57(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_58(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_59(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_60(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_61(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_62(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_63(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_64(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_65(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_66(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_67(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_68(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_69(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_70(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_71(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_72(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_73(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_74(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_75(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_76(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_77(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_78(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_79(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_80(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_81(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_82(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_83(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_84(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_85(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_86(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_87(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_88(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_89(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_90(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_91(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_92(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_93(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_94(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_95(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_96(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_97(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_98(temperature, humidity, light, co2, humidity_ratio);
    votes += predict_tree_99(temperature, humidity, light, co2, humidity_ratio);
    return votes >= 0;  // Majority voting
}
