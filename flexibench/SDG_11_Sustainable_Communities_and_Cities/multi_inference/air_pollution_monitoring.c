#include "sample_data.h"
// #include <stdio.h>

// Global volatile variable to verify result is not optimized out
volatile char result = -1;  


int boosted_predict(
  unsigned char pm25,
  unsigned char pm10,
  unsigned char no,
  unsigned char no2,
  unsigned char nox,
  unsigned char nh3,
  unsigned char co,
  unsigned char so2,
  unsigned char o3,
  unsigned char benzene,
  unsigned char toluene,
  unsigned char xylene
);

int main() {
    int correct = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        unsigned char pm25 = PM25_Vector[i];
        unsigned char pm10 = PM10_Vector[i];
        unsigned char no = NO_Vector[i];
        unsigned char no2 = NO2_Vector[i];
        unsigned char nox = NOx_Vector[i];
        unsigned char nh3 = NH3_Vector[i];
        unsigned char co = CO_Vector[i];
        unsigned char so2 = SO2_Vector[i];
        unsigned char o3 = O3_Vector[i];
        unsigned char benzene = Benzene_Vector[i];
        unsigned char toluene = Toluene_Vector[i];
        unsigned char xylene = Xylene_Vector[i];

        int prediction = boosted_predict(
            pm25, pm10, no, no2, nox, nh3, co, so2, o3, benzene, toluene, xylene
        );

        if (prediction == Label_Vector[i]) {
            correct++;
        }
    }
    // Optionally print the result
    printf("%d / %d\n", correct, NUM_SAMPLES);
    return 0;
}



short tree0(const unsigned char* features) {
  if (features[6] < 28) {
    if (features[0] < 64) {
      if (features[1] < 104) {
        if (features[6] < 15) {
          if (features[0] < 58) {
            if (features[1] < 82) {
              if (features[0] < 41) {
                return -28763;
              } else {
                return -26961;
              }
            } else {
              if (features[3] < 54) {
                return -26321;
              } else {
                return -11391;
              }
            }
          } else {
            if (features[1] < 91) {
              if (features[8] < 47) {
                return -16442;
              } else {
                return -27677;
              }
            } else {
              if (features[8] < 41) {
                return -16945;
              } else {
                return 15343;
              }
            }
          }
        } else {
          if (features[10] < 13) {
            if (features[0] < 54) {
              if (features[7] < 50) {
                return -27138;
              } else {
                return -18046;
              }
            } else {
              return -4562;
            }
          } else {
            if (features[0] < 15) {
              if (features[6] < 25) {
                return -23478;
              } else {
                return 425;
              }
            } else {
              if (features[8] < 28) {
                return -14099;
              } else {
                return 8771;
              }
            }
          }
        }
      } else {
        if (features[10] < 1) {
          if (features[1] < 115) {
            return -25170;
          } else {
            return -6691;
          }
        } else {
          if (features[5] < 37) {
            if (features[2] < 5) {
              if (features[1] < 117) {
                return -24788;
              } else {
                return 1093;
              }
            } else {
              if (features[6] < 4) {
                return 17265;
              } else {
                return -4008;
              }
            }
          } else {
            if (features[0] < 60) {
              return -22595;
            } else {
              return 5786;
            }
          }
        }
      }
    } else {
      if (features[0] < 71) {
        if (features[9] < 2) {
          if (features[6] < 2) {
            return -23806;
          } else {
            if (features[3] < 52) {
              if (features[2] < 4) {
                return -23723;
              } else {
                return 4343;
              }
            } else {
              return -25170;
            }
          }
        } else {
          if (features[3] < 67) {
            if (features[8] < 28) {
              return -6941;
            } else {
              if (features[10] < 5) {
                return -9266;
              } else {
                return 17265;
              }
            }
          } else {
            return -12958;
          }
        }
      } else {
        if (features[6] < 1) {
          if (features[3] < 3) {
            return -24788;
          } else {
            if (features[7] < 18) {
              return 11558;
            } else {
              return -14326;
            }
          }
        } else {
          if (features[0] < 194) {
            if (features[8] < 14) {
              if (features[7] < 7) {
                return -11700;
              } else {
                return 19055;
              }
            } else {
              if (features[5] < 8) {
                return -6691;
              } else {
                return 30834;
              }
            }
          } else {
            return -9266;
          }
        }
      }
    }
  } else {
    if (features[4] < 14) {
      return -25212;
    } else {
      if (features[1] < 19) {
        return -6852;
      } else {
        return 29257;
      }
    }
  }
}

short tree1(const unsigned char* features) {
  if (features[0] < 32) {
    if (features[6] < 9) {
      if (features[1] < 72) {
        if (features[0] < 29) {
          if (features[0] < 24) {
            if (features[1] < 69) {
              return -28767;
            } else {
              if (features[8] < 38) {
                return -26627;
              } else {
                return -10341;
              }
            }
          } else {
            if (features[3] < 75) {
              if (features[1] < 56) {
                return -27089;
              } else {
                return -23112;
              }
            } else {
              return -4562;
            }
          }
        } else {
          if (features[5] < 20) {
            if (features[3] < 16) {
              if (features[8] < 26) {
                return -4388;
              } else {
                return -16236;
              }
            } else {
              if (features[6] < 5) {
                return -20784;
              } else {
                return -4562;
              }
            }
          } else {
            if (features[8] < 94) {
              return -26869;
            } else {
              return -6852;
            }
          }
        }
      } else {
        if (features[0] < 22) {
          if (features[3] < 6) {
            if (features[7] < 94) {
              if (features[1] < 81) {
                return -21219;
              } else {
                return -776;
              }
            } else {
              return -24445;
            }
          } else {
            if (features[10] < 7) {
              return -27852;
            } else {
              if (features[10] < 11) {
                return -6691;
              } else {
                return -24788;
              }
            }
          }
        } else {
          if (features[1] < 84) {
            if (features[5] < 17) {
              if (features[1] < 73) {
                return -9266;
              } else {
                return -25081;
              }
            } else {
              if (features[10] < 13) {
                return 4090;
              } else {
                return -24318;
              }
            }
          } else {
            if (features[7] < 36) {
              if (features[3] < 10) {
                return -18696;
              } else {
                return 2048;
              }
            } else {
              return 14915;
            }
          }
        }
      }
    } else {
      if (features[6] < 32) {
        if (features[2] < 8) {
          if (features[0] < 22) {
            if (features[10] < 25) {
              if (features[11] < 7) {
                return -26596;
              } else {
                return -14675;
              }
            } else {
              if (features[10] < 27) {
                return 5786;
              } else {
                return -18046;
              }
            }
          } else {
            if (features[7] < 11) {
              return -24788;
            } else {
              if (features[7] < 41) {
                return 12496;
              } else {
                return -11468;
              }
            }
          }
        } else {
          if (features[4] < 11) {
            return -27115;
          } else {
            if (features[6] < 27) {
              if (features[6] < 14) {
                return -5803;
              } else {
                return 11813;
              }
            } else {
              if (features[11] < 7) {
                return -2289;
              } else {
                return -27316;
              }
            }
          }
        }
      } else {
        if (features[1] < 19) {
          return -6691;
        } else {
          return -27121;
        }
      }
    }
  } else {
    if (features[0] < 71) {
      if (features[0] < 37) {
        if (features[1] < 69) {
          if (features[5] < 17) {
            if (features[6] < 28) {
              if (features[11] < 12) {
                return -2182;
              } else {
                return 16854;
              }
            } else {
              return -27316;
            }
          } else {
            if (features[5] < 29) {
              if (features[8] < 62) {
                return -23533;
              } else {
                return -6999;
              }
            } else {
              if (features[8] < 36) {
                return -6785;
              } else {
                return -22636;
              }
            }
          }
        } else {
          if (features[10] < 21) {
            if (features[8] < 16) {
              if (features[1] < 95) {
                return -24318;
              } else {
                return -6691;
              }
            } else {
              if (features[2] < 7) {
                return -18046;
              } else {
                return 16741;
              }
            }
          } else {
            return -19064;
          }
        }
      } else {
        if (features[6] < 25) {
          if (features[0] < 64) {
            if (features[6] < 2) {
              if (features[1] < 106) {
                return 18524;
              } else {
                return -14380;
              }
            } else {
              if (features[2] < 90) {
                return 27131;
              } else {
                return -3100;
              }
            }
          } else {
            if (features[9] < 2) {
              if (features[10] < 1) {
                return -2289;
              } else {
                return 10913;
              }
            } else {
              if (features[8] < 72) {
                return -2182;
              } else {
                return -22595;
              }
            }
          }
        } else {
          if (features[7] < 54) {
            if (features[0] < 52) {
              if (features[8] < 28) {
                return 10342;
              } else {
                return -24788;
              }
            } else {
              return -21740;
            }
          } else {
            return -27642;
          }
        }
      }
    } else {
      if (features[0] < 75) {
        if (features[8] < 34) {
          if (features[3] < 14) {
            return -24788;
          } else {
            if (features[3] < 26) {
              return 4858;
            } else {
              if (features[3] < 35) {
                return -24318;
              } else {
                return -5599;
              }
            }
          }
        } else {
          if (features[3] < 56) {
            return -27711;
          } else {
            return -14326;
          }
        }
      } else {
        if (features[6] < 1) {
          if (features[0] < 104) {
            if (features[2] < 4) {
              return 5360;
            } else {
              return -19906;
            }
          } else {
            return -24445;
          }
        } else {
          return -26769;
        }
      }
    }
  }
}

short tree2(const unsigned char* features) {
  if (features[0] < 21) {
    if (features[6] < 6) {
      if (features[1] < 53) {
        if (features[8] < 100) {
          if (features[0] < 19) {
            if (features[1] < 46) {
              if (features[4] < 90) {
                return -28414;
              } else {
                return -13744;
              }
            } else {
              if (features[5] < 22) {
                return -24761;
              } else {
                return -4845;
              }
            }
          } else {
            if (features[4] < 58) {
              if (features[8] < 65) {
                return -24301;
              } else {
                return -17595;
              }
            } else {
              if (features[1] < 39) {
                return 7992;
              } else {
                return -21219;
              }
            }
          }
        } else {
          if (features[3] < 25) {
            if (features[8] < 111) {
              return -24688;
            } else {
              if (features[3] < 8) {
                return 4698;
              } else {
                return -19361;
              }
            }
          } else {
            if (features[11] < 1) {
              return -23723;
            } else {
              if (features[11] < 8) {
                return 18158;
              } else {
                return -16792;
              }
            }
          }
        }
      } else {
        if (features[10] < 2) {
          if (features[4] < 15) {
            if (features[1] < 99) {
              if (features[8] < 11) {
                return -14797;
              } else {
                return -26458;
              }
            } else {
              return -6691;
            }
          } else {
            if (features[1] < 105) {
              if (features[1] < 64) {
                return -13618;
              } else {
                return 2577;
              }
            } else {
              return -27564;
            }
          }
        } else {
          if (features[7] < 12) {
            if (features[10] < 5) {
              return -22949;
            } else {
              return -6691;
            }
          } else {
            if (features[11] < 2) {
              if (features[1] < 59) {
                return 1093;
              } else {
                return 24449;
              }
            } else {
              return -8747;
            }
          }
        }
      }
    } else {
      if (features[6] < 18) {
        if (features[4] < 8) {
          if (features[8] < 8) {
            if (features[0] < 5) {
              return -16792;
            } else {
              if (features[6] < 13) {
                return -15207;
              } else {
                return 11466;
              }
            }
          } else {
            if (features[9] < 1) {
              if (features[4] < 3) {
                return -9618;
              } else {
                return -24445;
              }
            } else {
              if (features[1] < 28) {
                return -26719;
              } else {
                return -6691;
              }
            }
          }
        } else {
          if (features[6] < 12) {
            if (features[10] < 3) {
              if (features[4] < 11) {
                return -1522;
              } else {
                return -22304;
              }
            } else {
              if (features[0] < 10) {
                return -19786;
              } else {
                return 8631;
              }
            }
          } else {
            if (features[8] < 36) {
              if (features[4] < 17) {
                return 23747;
              } else {
                return -4562;
              }
            } else {
              if (features[7] < 56) {
                return 7613;
              } else {
                return -12267;
              }
            }
          }
        }
      } else {
        if (features[7] < 5) {
          if (features[0] < 6) {
            if (features[0] < 5) {
              return -6941;
            } else {
              return -23723;
            }
          } else {
            return 8922;
          }
        } else {
          if (features[2] < 11) {
            if (features[0] < 18) {
              if (features[3] < 49) {
                return -11700;
              } else {
                return -25556;
              }
            } else {
              return -26901;
            }
          } else {
            return -28126;
          }
        }
      }
    }
  } else {
    if (features[0] < 37) {
      if (features[0] < 24) {
        if (features[5] < 22) {
          if (features[8] < 68) {
            if (features[0] < 23) {
              if (features[1] < 62) {
                return -20262;
              } else {
                return -4783;
              }
            } else {
              if (features[6] < 17) {
                return -8543;
              } else {
                return -27115;
              }
            }
          } else {
            if (features[6] < 11) {
              if (features[5] < 11) {
                return -12746;
              } else {
                return 3005;
              }
            } else {
              return -25170;
            }
          }
        } else {
          if (features[8] < 59) {
            if (features[4] < 15) {
              if (features[6] < 2) {
                return -22444;
              } else {
                return -4562;
              }
            } else {
              if (features[7] < 9) {
                return -18046;
              } else {
                return 1449;
              }
            }
          } else {
            if (features[4] < 20) {
              return -6852;
            } else {
              return 27663;
            }
          }
        }
      } else {
        if (features[6] < 8) {
          if (features[1] < 82) {
            if (features[1] < 24) {
              return -24624;
            } else {
              if (features[5] < 12) {
                return 10786;
              } else {
                return 19034;
              }
            }
          } else {
            if (features[1] < 95) {
              if (features[3] < 14) {
                return 13572;
              } else {
                return -13198;
              }
            } else {
              if (features[7] < 15) {
                return -8747;
              } else {
                return -26218;
              }
            }
          }
        } else {
          if (features[7] < 11) {
            if (features[4] < 3) {
              return -24318;
            } else {
              if (features[6] < 15) {
                return 23443;
              } else {
                return -8747;
              }
            }
          } else {
            if (features[2] < 8) {
              if (features[0] < 25) {
                return -1740;
              } else {
                return -22736;
              }
            } else {
              return -28608;
            }
          }
        }
      }
    } else {
      if (features[0] < 42) {
        if (features[0] < 39) {
          if (features[3] < 58) {
            if (features[1] < 47) {
              if (features[5] < 11) {
                return -746;
              } else {
                return -18177;
              }
            } else {
              if (features[4] < 45) {
                return -615;
              } else {
                return -20391;
              }
            }
          } else {
            return -27115;
          }
        } else {
          if (features[10] < 4) {
            if (features[6] < 2) {
              if (features[4] < 32) {
                return -16209;
              } else {
                return 2699;
              }
            } else {
              if (features[7] < 10) {
                return -27772;
              } else {
                return -18408;
              }
            }
          } else {
            return -25395;
          }
        }
      } else {
        if (features[6] < 2) {
          if (features[4] < 15) {
            if (features[5] < 47) {
              if (features[3] < 11) {
                return -11380;
              } else {
                return -24039;
              }
            } else {
              return 13312;
            }
          } else {
            return -26514;
          }
        } else {
          return -27846;
        }
      }
    }
  }
}

short tree3(const unsigned char* features) {
  if (features[1] < 21) {
    if (features[6] < 2) {
      if (features[0] < 13) {
        if (features[8] < 55) {
          if (features[4] < 44) {
            if (features[4] < 1) {
              if (features[1] < 3) {
                return 11312;
              } else {
                return -19664;
              }
            } else {
              if (features[2] < 30) {
                return -25361;
              } else {
                return -8528;
              }
            }
          } else {
            if (features[1] < 18) {
              return 26157;
            } else {
              return -9266;
            }
          }
        } else {
          if (features[3] < 5) {
            return -26150;
          } else {
            if (features[10] < 5) {
              if (features[8] < 77) {
                return -6802;
              } else {
                return 13443;
              }
            } else {
              if (features[9] < 1) {
                return -9266;
              } else {
                return 22406;
              }
            }
          }
        }
      } else {
        if (features[4] < 12) {
          if (features[0] < 19) {
            if (features[1] < 19) {
              if (features[1] < 4) {
                return -746;
              } else {
                return -21723;
              }
            } else {
              if (features[7] < 21) {
                return -3701;
              } else {
                return -24318;
              }
            }
          } else {
            if (features[3] < 9) {
              return -16792;
            } else {
              return 13572;
            }
          }
        } else {
          if (features[8] < 26) {
            if (features[5] < 5) {
              if (features[1] < 18) {
                return -24445;
              } else {
                return -6852;
              }
            } else {
              if (features[11] < 2) {
                return 12139;
              } else {
                return -22595;
              }
            }
          } else {
            if (features[7] < 5) {
              if (features[1] < 16) {
                return -19064;
              } else {
                return 425;
              }
            } else {
              if (features[2] < 3) {
                return -8747;
              } else {
                return 20681;
              }
            }
          }
        }
      }
    } else {
      if (features[6] < 3) {
        if (features[0] < 13) {
          if (features[5] < 12) {
            if (features[8] < 55) {
              if (features[4] < 45) {
                return -15785;
              } else {
                return 19151;
              }
            } else {
              return 20294;
            }
          } else {
            if (features[8] < 6) {
              if (features[7] < 8) {
                return -5599;
              } else {
                return 27048;
              }
            } else {
              if (features[8] < 35) {
                return -11304;
              } else {
                return 18158;
              }
            }
          }
        } else {
          if (features[7] < 5) {
            return -12958;
          } else {
            return 16277;
          }
        }
      } else {
        if (features[6] < 12) {
          if (features[2] < 1) {
            if (features[5] < 3) {
              return 13312;
            } else {
              return -27255;
            }
          } else {
            if (features[7] < 14) {
              if (features[11] < 5) {
                return 10111;
              } else {
                return -20664;
              }
            } else {
              if (features[3] < 29) {
                return 32766;
              } else {
                return -15207;
              }
            }
          }
        } else {
          return -27373;
        }
      }
    }
  } else {
    if (features[0] < 24) {
      if (features[0] < 13) {
        if (features[1] < 25) {
          if (features[8] < 51) {
            if (features[6] < 2) {
              if (features[4] < 26) {
                return -13740;
              } else {
                return 12293;
              }
            } else {
              if (features[6] < 12) {
                return 11571;
              } else {
                return -16665;
              }
            }
          } else {
            if (features[6] < 14) {
              if (features[11] < 12) {
                return 17404;
              } else {
                return -18046;
              }
            } else {
              if (features[4] < 15) {
                return -12958;
              } else {
                return -26852;
              }
            }
          }
        } else {
          if (features[6] < 11) {
            if (features[4] < 2) {
              if (features[7] < 14) {
                return -7637;
              } else {
                return 25777;
              }
            } else {
              if (features[1] < 27) {
                return 12302;
              } else {
                return 24221;
              }
            }
          } else {
            return -27278;
          }
        }
      } else {
        if (features[6] < 8) {
          if (features[1] < 59) {
            if (features[1] < 24) {
              if (features[6] < 2) {
                return 2206;
              } else {
                return 21378;
              }
            } else {
              if (features[0] < 21) {
                return 30109;
              } else {
                return 18369;
              }
            }
          } else {
            if (features[1] < 74) {
              if (features[5] < 15) {
                return 11160;
              } else {
                return -17512;
              }
            } else {
              if (features[8] < 31) {
                return -20062;
              } else {
                return -5263;
              }
            }
          }
        } else {
          if (features[4] < 8) {
            if (features[3] < 2) {
              return -16792;
            } else {
              if (features[0] < 16) {
                return -67;
              } else {
                return 31493;
              }
            }
          } else {
            if (features[5] < 11) {
              return 22681;
            } else {
              if (features[10] < 1) {
                return -67;
              } else {
                return -23579;
              }
            }
          }
        }
      }
    } else {
      if (features[0] < 27) {
        if (features[6] < 5) {
          if (features[1] < 38) {
            if (features[0] < 26) {
              if (features[4] < 1) {
                return -23723;
              } else {
                return 3994;
              }
            } else {
              if (features[9] < 1) {
                return -4743;
              } else {
                return -19700;
              }
            }
          } else {
            if (features[1] < 72) {
              if (features[4] < 16) {
                return 2225;
              } else {
                return -12199;
              }
            } else {
              return -27604;
            }
          }
        } else {
          if (features[7] < 9) {
            return -6852;
          } else {
            return -27054;
          }
        }
      } else {
        if (features[0] < 199) {
          if (features[10] < 2) {
            if (features[7] < 4) {
              if (features[8] < 33) {
                return -17443;
              } else {
                return -3976;
              }
            } else {
              if (features[0] < 35) {
                return -20386;
              } else {
                return -26278;
              }
            }
          } else {
            if (features[2] < 5) {
              if (features[0] < 29) {
                return -12746;
              } else {
                return -23976;
              }
            } else {
              if (features[5] < 8) {
                return -20580;
              } else {
                return -27956;
              }
            }
          }
        } else {
          return 10997;
        }
      }
    }
  }
}

short tree4(const unsigned char* features) {
  if (features[0] < 13) {
    if (features[6] < 3) {
      if (features[1] < 25) {
        if (features[1] < 10) {
          if (features[6] < 1) {
            if (features[8] < 37) {
              if (features[4] < 18) {
                return -14348;
              } else {
                return 14876;
              }
            } else {
              if (features[3] < 33) {
                return 25377;
              } else {
                return -12874;
              }
            }
          } else {
            if (features[8] < 55) {
              if (features[4] < 45) {
                return 23703;
              } else {
                return -16792;
              }
            } else {
              if (features[7] < 8) {
                return 5786;
              } else {
                return -22595;
              }
            }
          }
        } else {
          if (features[8] < 54) {
            if (features[1] < 21) {
              if (features[4] < 44) {
                return 25637;
              } else {
                return -21120;
              }
            } else {
              if (features[4] < 26) {
                return 15754;
              } else {
                return -10457;
              }
            }
          } else {
            if (features[8] < 77) {
              if (features[1] < 21) {
                return 12603;
              } else {
                return -5960;
              }
            } else {
              if (features[7] < 8) {
                return -7039;
              } else {
                return -26665;
              }
            }
          }
        }
      } else {
        if (features[4] < 2) {
          if (features[7] < 14) {
            if (features[6] < 2) {
              if (features[8] < 39) {
                return 23678;
              } else {
                return -1631;
              }
            } else {
              return -21740;
            }
          } else {
            return -22595;
          }
        } else {
          if (features[1] < 27) {
            if (features[8] < 46) {
              if (features[0] < 8) {
                return 14620;
              } else {
                return -2636;
              }
            } else {
              if (features[4] < 14) {
                return -13529;
              } else {
                return -24788;
              }
            }
          } else {
            if (features[5] < 26) {
              if (features[1] < 32) {
                return -16679;
              } else {
                return -25019;
              }
            } else {
              if (features[0] < 10) {
                return 17130;
              } else {
                return -18916;
              }
            }
          }
        }
      }
    } else {
      if (features[7] < 10) {
        if (features[4] < 17) {
          if (features[2] < 4) {
            if (features[5] < 20) {
              if (features[11] < 2) {
                return -18683;
              } else {
                return 1825;
              }
            } else {
              if (features[8] < 44) {
                return 1463;
              } else {
                return -25170;
              }
            }
          } else {
            return -26015;
          }
        } else {
          if (features[6] < 5) {
            if (features[1] < 10) {
              return -25751;
            } else {
              if (features[1] < 25) {
                return 17184;
              } else {
                return -20614;
              }
            }
          } else {
            return -23266;
          }
        }
      } else {
        if (features[2] < 1) {
          if (features[0] < 6) {
            return -22195;
          } else {
            return 5360;
          }
        } else {
          if (features[6] < 4) {
            if (features[7] < 16) {
              if (features[5] < 7) {
                return -2387;
              } else {
                return -22707;
              }
            } else {
              if (features[11] < 1) {
                return -11304;
              } else {
                return -27233;
              }
            }
          } else {
            return -28402;
          }
        }
      }
    }
  } else {
    if (features[1] < 24) {
      if (features[6] < 2) {
        if (features[5] < 5) {
          if (features[8] < 63) {
            if (features[7] < 58) {
              if (features[11] < 2) {
                return 20272;
              } else {
                return -471;
              }
            } else {
              return -19064;
            }
          } else {
            return -25485;
          }
        } else {
          if (features[0] < 15) {
            if (features[8] < 36) {
              if (features[5] < 13) {
                return 24281;
              } else {
                return 5504;
              }
            } else {
              if (features[4] < 18) {
                return -67;
              } else {
                return -23266;
              }
            }
          } else {
            if (features[3] < 6) {
              return -24106;
            } else {
              if (features[7] < 6) {
                return 3782;
              } else {
                return -9584;
              }
            }
          }
        }
      } else {
        if (features[7] < 9) {
          if (features[1] < 5) {
            return -26948;
          } else {
            if (features[8] < 42) {
              if (features[6] < 4) {
                return 2633;
              } else {
                return -23723;
              }
            } else {
              if (features[6] < 3) {
                return -26745;
              } else {
                return 1825;
              }
            }
          }
        } else {
          if (features[5] < 10) {
            if (features[8] < 46) {
              if (features[7] < 13) {
                return -21387;
              } else {
                return -5655;
              }
            } else {
              return -27188;
            }
          } else {
            return -28275;
          }
        }
      }
    } else {
      if (features[0] < 17) {
        if (features[1] < 27) {
          if (features[6] < 2) {
            if (features[8] < 41) {
              if (features[6] < 1) {
                return 6163;
              } else {
                return -8322;
              }
            } else {
              if (features[10] < 18) {
                return -20047;
              } else {
                return -3026;
              }
            }
          } else {
            if (features[7] < 11) {
              if (features[8] < 53) {
                return -12501;
              } else {
                return -27035;
              }
            } else {
              return -26576;
            }
          }
        } else {
          if (features[1] < 30) {
            if (features[8] < 40) {
              if (features[7] < 29) {
                return -16292;
              } else {
                return -27373;
              }
            } else {
              if (features[10] < 1) {
                return -18358;
              } else {
                return -28064;
              }
            }
          } else {
            if (features[4] < 13) {
              if (features[2] < 7) {
                return -26378;
              } else {
                return -19642;
              }
            } else {
              return -28131;
            }
          }
        }
      } else {
        if (features[3] < 12) {
          if (features[0] < 19) {
            if (features[11] < 14) {
              if (features[1] < 36) {
                return -25434;
              } else {
                return -28656;
              }
            } else {
              if (features[1] < 31) {
                return 2413;
              } else {
                return -18046;
              }
            }
          } else {
            return -28295;
          }
        } else {
          return -28501;
        }
      }
    }
  }
}

short tree5(const unsigned char* features) {
  if (features[1] < 11) {
    if (features[6] < 1) {
      if (features[8] < 35) {
        if (features[4] < 17) {
          if (features[1] < 9) {
            if (features[7] < 6) {
              if (features[3] < 20) {
                return 12166;
              } else {
                return -25978;
              }
            } else {
              if (features[8] < 21) {
                return 27963;
              } else {
                return 15983;
              }
            }
          } else {
            if (features[8] < 26) {
              if (features[0] < 7) {
                return 14019;
              } else {
                return -15315;
              }
            } else {
              if (features[2] < 4) {
                return 1594;
              } else {
                return -19255;
              }
            }
          }
        } else {
          if (features[4] < 22) {
            if (features[3] < 12) {
              if (features[1] < 8) {
                return -10733;
              } else {
                return -25449;
              }
            } else {
              if (features[0] < 6) {
                return 10608;
              } else {
                return -13897;
              }
            }
          } else {
            return -25556;
          }
        }
      } else {
        if (features[8] < 40) {
          if (features[5] < 15) {
            if (features[0] < 3) {
              if (features[2] < 4) {
                return 6471;
              } else {
                return -24318;
              }
            } else {
              if (features[10] < 1) {
                return -4297;
              } else {
                return -21315;
              }
            }
          } else {
            return -26627;
          }
        } else {
          return -27610;
        }
      }
    } else {
      if (features[6] < 3) {
        if (features[11] < 2) {
          if (features[6] < 2) {
            if (features[8] < 31) {
              if (features[8] < 12) {
                return -26920;
              } else {
                return -21146;
              }
            } else {
              return -27858;
            }
          } else {
            return -28668;
          }
        } else {
          if (features[10] < 1) {
            return 10206;
          } else {
            return -22949;
          }
        }
      } else {
        if (features[0] < 18) {
          if (features[2] < 1) {
            return 12496;
          } else {
            if (features[8] < 8) {
              if (features[4] < 12) {
                return -24788;
              } else {
                return -1740;
              }
            } else {
              return -26228;
            }
          }
        } else {
          if (features[5] < 23) {
            if (features[2] < 7) {
              if (features[5] < 6) {
                return -67;
              } else {
                return -23723;
              }
            } else {
              return 21180;
            }
          } else {
            return -23723;
          }
        }
      }
    }
  } else {
    if (features[0] < 8) {
      if (features[6] < 1) {
        if (features[8] < 35) {
          if (features[1] < 13) {
            if (features[2] < 7) {
              if (features[8] < 28) {
                return 5596;
              } else {
                return -18277;
              }
            } else {
              if (features[2] < 10) {
                return -14029;
              } else {
                return -25222;
              }
            }
          } else {
            if (features[1] < 24) {
              if (features[0] < 3) {
                return -3736;
              } else {
                return -23630;
              }
            } else {
              if (features[1] < 25) {
                return -6000;
              } else {
                return -27205;
              }
            }
          }
        } else {
          return -28382;
        }
      } else {
        if (features[4] < 6) {
          if (features[8] < 22) {
            if (features[8] < 15) {
              if (features[6] < 2) {
                return -19036;
              } else {
                return -26771;
              }
            } else {
              if (features[7] < 4) {
                return 2699;
              } else {
                return -18312;
              }
            }
          } else {
            return -27155;
          }
        } else {
          return -28236;
        }
      }
    } else {
      if (features[1] < 13) {
        if (features[4] < 12) {
          if (features[6] < 1) {
            if (features[8] < 30) {
              if (features[0] < 10) {
                return -3064;
              } else {
                return -22595;
              }
            } else {
              return -23550;
            }
          } else {
            return -26901;
          }
        } else {
          return -28339;
        }
      } else {
        return -28708;
      }
    }
  }
}

short tree6(const unsigned char* features) {
  if (features[6] < 27) {
    if (features[0] < 61) {
      if (features[1] < 104) {
        if (features[6] < 15) {
          if (features[1] < 81) {
            if (features[0] < 55) {
              if (features[6] < 8) {
                return -28307;
              } else {
                return -25941;
              }
            } else {
              if (features[4] < 10) {
                return -14113;
              } else {
                return -24729;
              }
            }
          } else {
            if (features[3] < 53) {
              if (features[8] < 98) {
                return -25706;
              } else {
                return -5868;
              }
            } else {
              if (features[1] < 90) {
                return -20366;
              } else {
                return -1671;
              }
            }
          }
        } else {
          if (features[10] < 10) {
            if (features[0] < 23) {
              return -27211;
            } else {
              if (features[1] < 25) {
                return -5417;
              } else {
                return -27400;
              }
            }
          } else {
            if (features[0] < 19) {
              if (features[2] < 10) {
                return -19586;
              } else {
                return -9855;
              }
            } else {
              if (features[4] < 37) {
                return 1722;
              } else {
                return -25742;
              }
            }
          }
        }
      } else {
        if (features[1] < 116) {
          if (features[7] < 26) {
            return -26465;
          } else {
            if (features[5] < 20) {
              if (features[0] < 27) {
                return -6723;
              } else {
                return -26253;
              }
            } else {
              if (features[5] < 37) {
                return 7686;
              } else {
                return -16485;
              }
            }
          }
        } else {
          if (features[10] < 8) {
            if (features[5] < 24) {
              return 4981;
            } else {
              return -13064;
            }
          } else {
            return -24561;
          }
        }
      }
    } else {
      if (features[0] < 72) {
        if (features[5] < 31) {
          if (features[2] < 4) {
            return -23318;
          } else {
            if (features[5] < 12) {
              if (features[3] < 52) {
                return -5037;
              } else {
                return -20936;
              }
            } else {
              if (features[4] < 47) {
                return -26804;
              } else {
                return -9165;
              }
            }
          }
        } else {
          if (features[4] < 24) {
            if (features[8] < 40) {
              return -12217;
            } else {
              return -26345;
            }
          } else {
            if (features[2] < 76) {
              if (features[8] < 22) {
                return -16540;
              } else {
                return 7099;
              }
            } else {
              if (features[5] < 47) {
                return -20070;
              } else {
                return -1681;
              }
            }
          }
        }
      } else {
        if (features[5] < 3) {
          return -24587;
        } else {
          if (features[0] < 199) {
            if (features[8] < 17) {
              if (features[6] < 3) {
                return -19260;
              } else {
                return 3172;
              }
            } else {
              return 5576;
            }
          } else {
            if (features[7] < 8) {
              return -1679;
            } else {
              return -24989;
            }
          }
        }
      }
    }
  } else {
    if (features[4] < 15) {
      if (features[2] < 9) {
        return -27233;
      } else {
        if (features[9] < 2) {
          return -21387;
        } else {
          return -246;
        }
      }
    } else {
      if (features[5] < 12) {
        if (features[10] < 2) {
          if (features[0] < 25) {
            if (features[2] < 21) {
              return -27491;
            } else {
              return -1955;
            }
          } else {
            return 4399;
          }
        } else {
          return 5132;
        }
      } else {
        return -25378;
      }
    }
  }
}

short tree7(const unsigned char* features) {
  if (features[0] < 31) {
    if (features[6] < 9) {
      if (features[1] < 70) {
        if (features[0] < 28) {
          if (features[0] < 22) {
            return -28337;
          } else {
            if (features[7] < 60) {
              if (features[1] < 58) {
                return -27363;
              } else {
                return -22340;
              }
            } else {
              if (features[4] < 13) {
                return -13949;
              } else {
                return -24447;
              }
            }
          }
        } else {
          if (features[8] < 25) {
            if (features[2] < 6) {
              if (features[7] < 5) {
                return -24576;
              } else {
                return -1254;
              }
            } else {
              if (features[9] < 2) {
                return -17852;
              } else {
                return -27233;
              }
            }
          } else {
            if (features[6] < 3) {
              if (features[3] < 88) {
                return -25492;
              } else {
                return -6899;
              }
            } else {
              if (features[1] < 25) {
                return -6534;
              } else {
                return -21114;
              }
            }
          }
        }
      } else {
        if (features[2] < 14) {
          if (features[1] < 81) {
            if (features[8] < 38) {
              return -26141;
            } else {
              if (features[8] < 45) {
                return 1600;
              } else {
                return -24031;
              }
            }
          } else {
            if (features[1] < 117) {
              if (features[7] < 13) {
                return -22910;
              } else {
                return -5975;
              }
            } else {
              return -22902;
            }
          }
        } else {
          if (features[10] < 12) {
            if (features[10] < 2) {
              if (features[1] < 86) {
                return -23894;
              } else {
                return -4758;
              }
            } else {
              if (features[11] < 1) {
                return -12076;
              } else {
                return 6125;
              }
            }
          } else {
            return -25299;
          }
        }
      }
    } else {
      if (features[6] < 32) {
        if (features[2] < 8) {
          if (features[0] < 22) {
            if (features[3] < 15) {
              return -27176;
            } else {
              if (features[10] < 25) {
                return -21341;
              } else {
                return -8060;
              }
            }
          } else {
            if (features[1] < 35) {
              if (features[7] < 15) {
                return -25225;
              } else {
                return -9692;
              }
            } else {
              return 6324;
            }
          }
        } else {
          if (features[4] < 11) {
            return -26611;
          } else {
            if (features[10] < 3) {
              if (features[11] < 3) {
                return 11458;
              } else {
                return -20014;
              }
            } else {
              if (features[1] < 51) {
                return -7667;
              } else {
                return 8779;
              }
            }
          }
        }
      } else {
        if (features[1] < 19) {
          return -9008;
        } else {
          return -26304;
        }
      }
    }
  } else {
    if (features[0] < 72) {
      if (features[0] < 36) {
        if (features[7] < 25) {
          if (features[6] < 5) {
            if (features[11] < 28) {
              if (features[5] < 16) {
                return -11722;
              } else {
                return -17546;
              }
            } else {
              return 5333;
            }
          } else {
            if (features[8] < 26) {
              if (features[4] < 25) {
                return -25886;
              } else {
                return -7408;
              }
            } else {
              if (features[7] < 23) {
                return 8922;
              } else {
                return -14996;
              }
            }
          }
        } else {
          if (features[6] < 11) {
            if (features[5] < 11) {
              if (features[5] < 8) {
                return -6729;
              } else {
                return -25599;
              }
            } else {
              if (features[4] < 41) {
                return 3935;
              } else {
                return -11337;
              }
            }
          } else {
            if (features[7] < 33) {
              return -7947;
            } else {
              return -27395;
            }
          }
        }
      } else {
        if (features[6] < 25) {
          if (features[0] < 61) {
            if (features[0] < 39) {
              if (features[7] < 89) {
                return -1684;
              } else {
                return -26153;
              }
            } else {
              if (features[1] < 24) {
                return -26608;
              } else {
                return 3946;
              }
            }
          } else {
            if (features[10] < 27) {
              if (features[5] < 9) {
                return -22884;
              } else {
                return -2646;
              }
            } else {
              return -23516;
            }
          }
        } else {
          if (features[8] < 21) {
            if (features[0] < 52) {
              return 3159;
            } else {
              return -23779;
            }
          } else {
            return -24451;
          }
        }
      }
    } else {
      if (features[0] < 75) {
        if (features[8] < 34) {
          if (features[7] < 8) {
            return -25166;
          } else {
            if (features[4] < 18) {
              return -23710;
            } else {
              return 1018;
            }
          }
        } else {
          return -25206;
        }
      } else {
        if (features[7] < 5) {
          if (features[0] < 103) {
            if (features[0] < 80) {
              return -23756;
            } else {
              if (features[8] < 16) {
                return 8068;
              } else {
                return -13507;
              }
            }
          } else {
            return -26015;
          }
        } else {
          if (features[4] < 18) {
            if (features[7] < 21) {
              if (features[0] < 79) {
                return -14442;
              } else {
                return -26852;
              }
            } else {
              if (features[3] < 11) {
                return -26154;
              } else {
                return -8273;
              }
            }
          } else {
            return -28167;
          }
        }
      }
    }
  }
}

short tree8(const unsigned char* features) {
  if (features[0] < 20) {
    if (features[6] < 6) {
      if (features[1] < 47) {
        if (features[8] < 106) {
          if (features[4] < 80) {
            if (features[0] < 19) {
              if (features[0] < 13) {
                return -28214;
              } else {
                return -27408;
              }
            } else {
              if (features[4] < 18) {
                return -25945;
              } else {
                return -21390;
              }
            }
          } else {
            if (features[3] < 25) {
              return -27600;
            } else {
              if (features[7] < 20) {
                return 4393;
              } else {
                return -23620;
              }
            }
          }
        } else {
          if (features[4] < 17) {
            if (features[10] < 5) {
              if (features[0] < 19) {
                return -26970;
              } else {
                return -12797;
              }
            } else {
              return -4695;
            }
          } else {
            if (features[8] < 109) {
              return -16652;
            } else {
              return 2073;
            }
          }
        }
      } else {
        if (features[5] < 13) {
          if (features[1] < 64) {
            if (features[3] < 7) {
              if (features[7] < 38) {
                return -12309;
              } else {
                return -23623;
              }
            } else {
              if (features[0] < 11) {
                return -13905;
              } else {
                return -26730;
              }
            }
          } else {
            if (features[1] < 93) {
              if (features[7] < 20) {
                return 4840;
              } else {
                return -11766;
              }
            } else {
              if (features[1] < 110) {
                return -14149;
              } else {
                return -24753;
              }
            }
          }
        } else {
          if (features[4] < 16) {
            if (features[10] < 3) {
              return -26226;
            } else {
              if (features[10] < 8) {
                return -3259;
              } else {
                return -24742;
              }
            }
          } else {
            if (features[7] < 8) {
              return -20841;
            } else {
              if (features[2] < 9) {
                return -12069;
              } else {
                return 6978;
              }
            }
          }
        }
      }
    } else {
      if (features[6] < 17) {
        if (features[4] < 8) {
          if (features[8] < 27) {
            if (features[7] < 9) {
              if (features[6] < 11) {
                return -23742;
              } else {
                return -11564;
              }
            } else {
              if (features[3] < 11) {
                return 2912;
              } else {
                return -23682;
              }
            }
          } else {
            if (features[4] < 2) {
              if (features[7] < 6) {
                return -2048;
              } else {
                return -24557;
              }
            } else {
              return -26673;
            }
          }
        } else {
          if (features[6] < 12) {
            if (features[1] < 25) {
              if (features[9] < 2) {
                return -14867;
              } else {
                return -3260;
              }
            } else {
              if (features[7] < 64) {
                return 11423;
              } else {
                return -15114;
              }
            }
          } else {
            if (features[4] < 17) {
              if (features[9] < 6) {
                return 3988;
              } else {
                return -24845;
              }
            } else {
              if (features[4] < 19) {
                return -21913;
              } else {
                return -7104;
              }
            }
          }
        }
      } else {
        if (features[2] < 9) {
          if (features[0] < 18) {
            if (features[0] < 4) {
              return -25284;
            } else {
              if (features[8] < 72) {
                return -5572;
              } else {
                return -23994;
              }
            }
          } else {
            return -26510;
          }
        } else {
          return -26816;
        }
      }
    }
  } else {
    if (features[0] < 39) {
      if (features[0] < 23) {
        if (features[5] < 19) {
          if (features[8] < 97) {
            if (features[1] < 61) {
              if (features[6] < 3) {
                return -21187;
              } else {
                return -15761;
              }
            } else {
              if (features[3] < 17) {
                return -16206;
              } else {
                return 2033;
              }
            }
          } else {
            if (features[5] < 11) {
              if (features[11] < 1) {
                return -25022;
              } else {
                return -7429;
              }
            } else {
              return 13340;
            }
          }
        } else {
          if (features[4] < 10) {
            return -27632;
          } else {
            if (features[8] < 52) {
              if (features[1] < 53) {
                return -11411;
              } else {
                return 1040;
              }
            } else {
              if (features[4] < 17) {
                return -24148;
              } else {
                return 4605;
              }
            }
          }
        }
      } else {
        if (features[6] < 15) {
          if (features[0] < 36) {
            if (features[0] < 26) {
              if (features[3] < 32) {
                return -7636;
              } else {
                return -606;
              }
            } else {
              if (features[0] < 31) {
                return 3334;
              } else {
                return -3113;
              }
            }
          } else {
            if (features[2] < 40) {
              if (features[7] < 8) {
                return -21641;
              } else {
                return -7910;
              }
            } else {
              if (features[3] < 32) {
                return -10165;
              } else {
                return -27819;
              }
            }
          }
        } else {
          if (features[3] < 8) {
            return -509;
          } else {
            return -27484;
          }
        }
      }
    } else {
      if (features[0] < 46) {
        if (features[10] < 6) {
          if (features[6] < 2) {
            if (features[3] < 27) {
              if (features[8] < 18) {
                return -27004;
              } else {
                return -6582;
              }
            } else {
              if (features[3] < 53) {
                return -24661;
              } else {
                return -14268;
              }
            }
          } else {
            if (features[7] < 10) {
              return -26844;
            } else {
              if (features[7] < 15) {
                return -10754;
              } else {
                return -24864;
              }
            }
          }
        } else {
          return -26419;
        }
      } else {
        if (features[5] < 6) {
          if (features[3] < 8) {
            if (features[1] < 89) {
              return 3680;
            } else {
              return -24410;
            }
          } else {
            return -26296;
          }
        } else {
          if (features[6] < 1) {
            if (features[5] < 25) {
              return -24254;
            } else {
              if (features[0] < 61) {
                return -1397;
              } else {
                return -23920;
              }
            }
          } else {
            return -27467;
          }
        }
      }
    }
  }
}

short tree9(const unsigned char* features) {
  if (features[0] < 26) {
    if (features[1] < 22) {
      if (features[6] < 2) {
        if (features[8] < 51) {
          if (features[0] < 12) {
            if (features[4] < 28) {
              if (features[4] < 1) {
                return -15666;
              } else {
                return -24779;
              }
            } else {
              if (features[8] < 36) {
                return -12858;
              } else {
                return 10344;
              }
            }
          } else {
            if (features[4] < 6) {
              if (features[1] < 20) {
                return -23906;
              } else {
                return -11229;
              }
            } else {
              if (features[11] < 10) {
                return -4964;
              } else {
                return -22593;
              }
            }
          }
        } else {
          if (features[3] < 5) {
            if (features[8] < 65) {
              return -27788;
            } else {
              if (features[7] < 5) {
                return -6029;
              } else {
                return -24493;
              }
            }
          } else {
            if (features[10] < 5) {
              if (features[8] < 66) {
                return -11903;
              } else {
                return -656;
              }
            } else {
              if (features[9] < 1) {
                return -15574;
              } else {
                return 10601;
              }
            }
          }
        }
      } else {
        if (features[10] < 1) {
          if (features[7] < 4) {
            if (features[6] < 3) {
              if (features[4] < 4) {
                return -7577;
              } else {
                return -22401;
              }
            } else {
              return 8498;
            }
          } else {
            if (features[2] < 7) {
              if (features[1] < 15) {
                return -24660;
              } else {
                return -11883;
              }
            } else {
              if (features[8] < 10) {
                return -16153;
              } else {
                return -2043;
              }
            }
          }
        } else {
          if (features[6] < 14) {
            if (features[4] < 15) {
              if (features[9] < 1) {
                return 6337;
              } else {
                return -2555;
              }
            } else {
              if (features[9] < 1) {
                return -10656;
              } else {
                return -1711;
              }
            }
          } else {
            return -27257;
          }
        }
      }
    } else {
      if (features[0] < 10) {
        if (features[1] < 26) {
          if (features[6] < 2) {
            if (features[11] < 1) {
              if (features[6] < 1) {
                return -13225;
              } else {
                return 7378;
              }
            } else {
              if (features[8] < 56) {
                return -18503;
              } else {
                return -3506;
              }
            }
          } else {
            if (features[6] < 28) {
              if (features[8] < 21) {
                return -7541;
              } else {
                return 1195;
              }
            } else {
              if (features[4] < 15) {
                return 591;
              } else {
                return -25439;
              }
            }
          }
        } else {
          if (features[5] < 26) {
            if (features[6] < 11) {
              if (features[6] < 2) {
                return -1800;
              } else {
                return 6893;
              }
            } else {
              return -26463;
            }
          } else {
            if (features[4] < 11) {
              if (features[3] < 24) {
                return -28857;
              } else {
                return -11757;
              }
            } else {
              return 663;
            }
          }
        }
      } else {
        if (features[6] < 9) {
          if (features[1] < 61) {
            if (features[0] < 16) {
              if (features[1] < 25) {
                return -4886;
              } else {
                return 3909;
              }
            } else {
              if (features[0] < 23) {
                return 5411;
              } else {
                return -5147;
              }
            }
          } else {
            if (features[4] < 19) {
              if (features[1] < 85) {
                return -4190;
              } else {
                return -19054;
              }
            } else {
              if (features[2] < 31) {
                return -25611;
              } else {
                return -7405;
              }
            }
          }
        } else {
          if (features[4] < 10) {
            if (features[4] < 5) {
              return 6578;
            } else {
              if (features[7] < 19) {
                return -788;
              } else {
                return -15760;
              }
            }
          } else {
            if (features[3] < 19) {
              if (features[2] < 5) {
                return 3703;
              } else {
                return -13615;
              }
            } else {
              if (features[10] < 1) {
                return -13073;
              } else {
                return -25510;
              }
            }
          }
        }
      }
    }
  } else {
    if (features[10] < 2) {
      if (features[0] < 28) {
        if (features[1] < 37) {
          if (features[8] < 64) {
            if (features[8] < 39) {
              if (features[8] < 35) {
                return -7580;
              } else {
                return -24945;
              }
            } else {
              if (features[6] < 2) {
                return 6617;
              } else {
                return -13531;
              }
            }
          } else {
            return -22843;
          }
        } else {
          if (features[4] < 11) {
            if (features[4] < 9) {
              if (features[0] < 27) {
                return -393;
              } else {
                return -25863;
              }
            } else {
              return 4424;
            }
          } else {
            if (features[7] < 24) {
              if (features[1] < 44) {
                return -24915;
              } else {
                return -13066;
              }
            } else {
              return -27392;
            }
          }
        }
      } else {
        if (features[6] < 1) {
          if (features[4] < 6) {
            if (features[9] < 1) {
              return 14311;
            } else {
              if (features[8] < 19) {
                return -23476;
              } else {
                return -128;
              }
            }
          } else {
            if (features[8] < 18) {
              if (features[4] < 18) {
                return -4006;
              } else {
                return -24840;
              }
            } else {
              if (features[5] < 43) {
                return -22163;
              } else {
                return 1234;
              }
            }
          }
        } else {
          if (features[1] < 24) {
            if (features[3] < 24) {
              return 7639;
            } else {
              return -15454;
            }
          } else {
            if (features[8] < 10) {
              if (features[6] < 2) {
                return -4787;
              } else {
                return -23686;
              }
            } else {
              if (features[0] < 155) {
                return -24995;
              } else {
                return -4700;
              }
            }
          }
        }
      }
    } else {
      if (features[5] < 11) {
        if (features[4] < 13) {
          if (features[3] < 15) {
            if (features[10] < 7) {
              return -22913;
            } else {
              return -5434;
            }
          } else {
            return 3694;
          }
        } else {
          if (features[0] < 27) {
            if (features[8] < 31) {
              return 802;
            } else {
              return -21266;
            }
          } else {
            return -25156;
          }
        }
      } else {
        if (features[2] < 14) {
          if (features[0] < 31) {
            if (features[6] < 2) {
              if (features[10] < 15) {
                return -18887;
              } else {
                return 3780;
              }
            } else {
              if (features[2] < 3) {
                return -6976;
              } else {
                return -26532;
              }
            }
          } else {
            if (features[0] < 116) {
              return -26404;
            } else {
              return -14196;
            }
          }
        } else {
          if (features[9] < 23) {
            return -28044;
          } else {
            if (features[2] < 64) {
              return -6882;
            } else {
              return -23771;
            }
          }
        }
      }
    }
  }
}

short tree10(const unsigned char* features) {
  if (features[0] < 14) {
    if (features[6] < 3) {
      if (features[1] < 26) {
        if (features[0] < 3) {
          if (features[6] < 1) {
            if (features[3] < 5) {
              if (features[7] < 3) {
                return -12674;
              } else {
                return -24688;
              }
            } else {
              if (features[2] < 4) {
                return -18914;
              } else {
                return -1692;
              }
            }
          } else {
            if (features[8] < 7) {
              if (features[8] < 6) {
                return -6874;
              } else {
                return -26175;
              }
            } else {
              if (features[1] < 8) {
                return 5352;
              } else {
                return -3018;
              }
            }
          }
        } else {
          if (features[8] < 66) {
            if (features[4] < 44) {
              if (features[6] < 2) {
                return 1819;
              } else {
                return -4010;
              }
            } else {
              if (features[4] < 54) {
                return -14769;
              } else {
                return -26313;
              }
            }
          } else {
            if (features[1] < 22) {
              if (features[4] < 15) {
                return -4975;
              } else {
                return -23462;
              }
            } else {
              if (features[2] < 2) {
                return -14093;
              } else {
                return -25094;
              }
            }
          }
        }
      } else {
        if (features[0] < 11) {
          if (features[7] < 10) {
            if (features[5] < 10) {
              if (features[8] < 32) {
                return -11333;
              } else {
                return -24393;
              }
            } else {
              if (features[7] < 4) {
                return -21085;
              } else {
                return 2631;
              }
            }
          } else {
            if (features[1] < 30) {
              if (features[8] < 41) {
                return -7530;
              } else {
                return -23840;
              }
            } else {
              if (features[10] < 24) {
                return -22535;
              } else {
                return 4596;
              }
            }
          }
        } else {
          if (features[1] < 30) {
            if (features[8] < 50) {
              if (features[4] < 17) {
                return -8916;
              } else {
                return -18289;
              }
            } else {
              return -26275;
            }
          } else {
            if (features[4] < 1) {
              if (features[0] < 12) {
                return -4422;
              } else {
                return -25698;
              }
            } else {
              if (features[8] < 35) {
                return -23398;
              } else {
                return -27907;
              }
            }
          }
        }
      }
    } else {
      if (features[7] < 10) {
        if (features[6] < 9) {
          if (features[9] < 1) {
            if (features[2] < 3) {
              if (features[8] < 21) {
                return -21202;
              } else {
                return -4257;
              }
            } else {
              if (features[4] < 17) {
                return -25406;
              } else {
                return -12690;
              }
            }
          } else {
            if (features[0] < 6) {
              if (features[5] < 20) {
                return -25790;
              } else {
                return -845;
              }
            } else {
              if (features[2] < 6) {
                return 1757;
              } else {
                return -20186;
              }
            }
          }
        } else {
          if (features[8] < 6) {
            if (features[0] < 5) {
              return -1773;
            } else {
              return -22550;
            }
          } else {
            return -25851;
          }
        }
      } else {
        if (features[6] < 4) {
          if (features[11] < 1) {
            if (features[4] < 11) {
              return 5269;
            } else {
              return -17063;
            }
          } else {
            if (features[7] < 14) {
              if (features[5] < 7) {
                return -8564;
              } else {
                return -22131;
              }
            } else {
              if (features[9] < 3) {
                return -26026;
              } else {
                return -8181;
              }
            }
          }
        } else {
          return -28016;
        }
      }
    }
  } else {
    if (features[1] < 24) {
      if (features[6] < 3) {
        if (features[8] < 63) {
          if (features[0] < 20) {
            if (features[8] < 20) {
              if (features[1] < 5) {
                return -17961;
              } else {
                return 1969;
              }
            } else {
              if (features[7] < 27) {
                return -6223;
              } else {
                return -20952;
              }
            }
          } else {
            if (features[7] < 6) {
              if (features[0] < 24) {
                return -21128;
              } else {
                return 2943;
              }
            } else {
              return -25943;
            }
          }
        } else {
          return -25923;
        }
      } else {
        if (features[11] < 5) {
          if (features[2] < 4) {
            if (features[3] < 6) {
              return -24053;
            } else {
              return -6409;
            }
          } else {
            return -26401;
          }
        } else {
          if (features[1] < 10) {
            return -20211;
          } else {
            return 82;
          }
        }
      }
    } else {
      if (features[0] < 17) {
        if (features[1] < 28) {
          if (features[6] < 1) {
            if (features[8] < 29) {
              if (features[5] < 21) {
                return 8230;
              } else {
                return -11361;
              }
            } else {
              if (features[5] < 32) {
                return -11417;
              } else {
                return -24644;
              }
            }
          } else {
            if (features[6] < 3) {
              if (features[8] < 28) {
                return -10311;
              } else {
                return -19820;
              }
            } else {
              return -26491;
            }
          }
        } else {
          if (features[4] < 1) {
            if (features[1] < 31) {
              return 1001;
            } else {
              return -20338;
            }
          } else {
            if (features[3] < 14) {
              if (features[1] < 29) {
                return -9899;
              } else {
                return -24146;
              }
            } else {
              if (features[5] < 50) {
                return -27534;
              } else {
                return -7370;
              }
            }
          }
        }
      } else {
        if (features[3] < 12) {
          if (features[0] < 19) {
            if (features[11] < 14) {
              if (features[6] < 2) {
                return -24330;
              } else {
                return -27962;
              }
            } else {
              if (features[7] < 9) {
                return 1402;
              } else {
                return -18737;
              }
            }
          } else {
            return -27780;
          }
        } else {
          return -28000;
        }
      }
    }
  }
}

short tree11(const unsigned char* features) {
  if (features[1] < 12) {
    if (features[6] < 1) {
      if (features[8] < 36) {
        if (features[4] < 18) {
          if (features[0] < 7) {
            if (features[8] < 30) {
              if (features[3] < 20) {
                return 2906;
              } else {
                return -9276;
              }
            } else {
              if (features[1] < 9) {
                return -2871;
              } else {
                return -16759;
              }
            }
          } else {
            if (features[4] < 5) {
              if (features[8] < 14) {
                return -15898;
              } else {
                return 6352;
              }
            } else {
              if (features[9] < 2) {
                return -22175;
              } else {
                return -1973;
              }
            }
          }
        } else {
          if (features[7] < 2) {
            return 1402;
          } else {
            if (features[11] < 3) {
              if (features[5] < 2) {
                return -6477;
              } else {
                return -28090;
              }
            } else {
              if (features[3] < 16) {
                return -4510;
              } else {
                return -24889;
              }
            }
          }
        }
      } else {
        if (features[8] < 41) {
          if (features[7] < 18) {
            if (features[11] < 2) {
              if (features[4] < 1) {
                return -10810;
              } else {
                return -24640;
              }
            } else {
              return -5397;
            }
          } else {
            if (features[5] < 4) {
              if (features[0] < 4) {
                return 14646;
              } else {
                return -16208;
              }
            } else {
              if (features[11] < 1) {
                return -9533;
              } else {
                return -26178;
              }
            }
          }
        } else {
          return -27725;
        }
      }
    } else {
      if (features[6] < 3) {
        if (features[11] < 2) {
          if (features[3] < 33) {
            if (features[6] < 2) {
              if (features[5] < 10) {
                return -22505;
              } else {
                return -26693;
              }
            } else {
              return -28210;
            }
          } else {
            if (features[4] < 25) {
              return 4395;
            } else {
              return -25091;
            }
          }
        } else {
          if (features[10] < 1) {
            return 93;
          } else {
            return -23508;
          }
        }
      } else {
        if (features[0] < 18) {
          if (features[2] < 2) {
            if (features[8] < 26) {
              return 5252;
            } else {
              return -25506;
            }
          } else {
            if (features[8] < 8) {
              if (features[0] < 5) {
                return -6020;
              } else {
                return -25138;
              }
            } else {
              return -26796;
            }
          }
        } else {
          if (features[3] < 18) {
            if (features[11] < 2) {
              return -20421;
            } else {
              return 195;
            }
          } else {
            return 5647;
          }
        }
      }
    }
  } else {
    if (features[0] < 8) {
      if (features[6] < 1) {
        if (features[8] < 35) {
          if (features[8] < 34) {
            if (features[8] < 18) {
              if (features[1] < 13) {
                return -1752;
              } else {
                return -17528;
              }
            } else {
              if (features[7] < 3) {
                return -4803;
              } else {
                return -23083;
              }
            }
          } else {
            if (features[5] < 13) {
              if (features[3] < 5) {
                return -5532;
              } else {
                return -23913;
              }
            } else {
              if (features[1] < 25) {
                return 13228;
              } else {
                return -23364;
              }
            }
          }
        } else {
          return -28049;
        }
      } else {
        if (features[7] < 5) {
          if (features[3] < 6) {
            return -27784;
          } else {
            if (features[3] < 8) {
              if (features[0] < 7) {
                return -3768;
              } else {
                return -25254;
              }
            } else {
              if (features[0] < 4) {
                return -14238;
              } else {
                return -24819;
              }
            }
          }
        } else {
          if (features[4] < 1) {
            if (features[8] < 20) {
              if (features[3] < 23) {
                return -4146;
              } else {
                return -24926;
              }
            } else {
              return -27307;
            }
          } else {
            return -27883;
          }
        }
      }
    } else {
      return -28231;
    }
  }
}

short tree12(const unsigned char* features) {
  if (features[6] < 21) {
    if (features[0] < 58) {
      if (features[1] < 108) {
        if (features[6] < 12) {
          if (features[1] < 82) {
            if (features[0] < 39) {
              return -28037;
            } else {
              return -25790;
            }
          } else {
            if (features[3] < 59) {
              if (features[5] < 41) {
                return -25690;
              } else {
                return -15279;
              }
            } else {
              if (features[8] < 39) {
                return -21562;
              } else {
                return -2324;
              }
            }
          }
        } else {
          if (features[7] < 44) {
            if (features[3] < 40) {
              if (features[0] < 48) {
                return -26942;
              } else {
                return -14237;
              }
            } else {
              if (features[3] < 46) {
                return -7905;
              } else {
                return -25617;
              }
            }
          } else {
            if (features[0] < 19) {
              if (features[3] < 82) {
                return -21711;
              } else {
                return -9469;
              }
            } else {
              if (features[8] < 68) {
                return -451;
              } else {
                return -21000;
              }
            }
          }
        }
      } else {
        if (features[5] < 38) {
          if (features[8] < 67) {
            if (features[2] < 5) {
              if (features[1] < 144) {
                return -5512;
              } else {
                return -26130;
              }
            } else {
              if (features[11] < 1) {
                return -13582;
              } else {
                return 376;
              }
            }
          } else {
            return -19289;
          }
        } else {
          return -23352;
        }
      }
    } else {
      if (features[0] < 65) {
        if (features[1] < 90) {
          if (features[8] < 50) {
            if (features[4] < 38) {
              if (features[2] < 7) {
                return -20049;
              } else {
                return -7526;
              }
            } else {
              if (features[10] < 21) {
                return -23441;
              } else {
                return -9749;
              }
            }
          } else {
            return -25507;
          }
        } else {
          if (features[3] < 47) {
            if (features[5] < 12) {
              return -23207;
            } else {
              if (features[5] < 37) {
                return 1711;
              } else {
                return -22019;
              }
            }
          } else {
            if (features[3] < 67) {
              return 5105;
            } else {
              if (features[6] < 2) {
                return -302;
              } else {
                return -25958;
              }
            }
          }
        }
      } else {
        if (features[6] < 2) {
          if (features[8] < 12) {
            return -26127;
          } else {
            if (features[0] < 70) {
              if (features[10] < 8) {
                return -23931;
              } else {
                return -3137;
              }
            } else {
              if (features[1] < 121) {
                return -4780;
              } else {
                return -24678;
              }
            }
          }
        } else {
          if (features[0] < 75) {
            if (features[9] < 2) {
              if (features[3] < 57) {
                return -7459;
              } else {
                return -26940;
              }
            } else {
              if (features[10] < 40) {
                return -1762;
              } else {
                return -16422;
              }
            }
          } else {
            if (features[2] < 5) {
              if (features[4] < 8) {
                return -6172;
              } else {
                return -25923;
              }
            } else {
              return -422;
            }
          }
        }
      }
    }
  } else {
    if (features[4] < 15) {
      if (features[2] < 12) {
        return -26761;
      } else {
        if (features[9] < 1) {
          return -20665;
        } else {
          return -3149;
        }
      }
    } else {
      if (features[6] < 28) {
        if (features[7] < 55) {
          if (features[0] < 27) {
            return -26220;
          } else {
            if (features[3] < 12) {
              return -21708;
            } else {
              return 3324;
            }
          }
        } else {
          if (features[8] < 29) {
            if (features[3] < 44) {
              return -26704;
            } else {
              return -4303;
            }
          } else {
            if (features[3] < 76) {
              if (features[11] < 15) {
                return 3915;
              } else {
                return -16512;
              }
            } else {
              if (features[0] < 14) {
                return -25766;
              } else {
                return -7663;
              }
            }
          }
        }
      } else {
        if (features[5] < 12) {
          return -1837;
        } else {
          return -24827;
        }
      }
    }
  }
}

short tree13(const unsigned char* features) {
  if (features[0] < 30) {
    if (features[6] < 9) {
      if (features[1] < 70) {
        if (features[0] < 24) {
          return -27991;
        } else {
          if (features[3] < 70) {
            if (features[8] < 18) {
              if (features[6] < 6) {
                return -22530;
              } else {
                return -6632;
              }
            } else {
              return -25711;
            }
          } else {
            return -11769;
          }
        }
      } else {
        if (features[7] < 107) {
          if (features[10] < 13) {
            if (features[10] < 5) {
              if (features[1] < 84) {
                return -20308;
              } else {
                return -10341;
              }
            } else {
              if (features[2] < 10) {
                return -18803;
              } else {
                return 2817;
              }
            }
          } else {
            return -26043;
          }
        } else {
          return -26493;
        }
      }
    } else {
      if (features[6] < 32) {
        if (features[4] < 12) {
          if (features[11] < 3) {
            if (features[10] < 18) {
              return -27778;
            } else {
              if (features[2] < 3) {
                return -23785;
              } else {
                return -4738;
              }
            }
          } else {
            if (features[7] < 78) {
              if (features[0] < 21) {
                return -22961;
              } else {
                return -4245;
              }
            } else {
              return 8485;
            }
          }
        } else {
          if (features[2] < 8) {
            if (features[8] < 46) {
              if (features[0] < 25) {
                return -21684;
              } else {
                return -8459;
              }
            } else {
              if (features[3] < 20) {
                return 2174;
              } else {
                return -14246;
              }
            }
          } else {
            if (features[6] < 27) {
              if (features[0] < 10) {
                return 1229;
              } else {
                return -7460;
              }
            } else {
              if (features[11] < 7) {
                return -8385;
              } else {
                return -26893;
              }
            }
          }
        }
      } else {
        if (features[1] < 23) {
          if (features[8] < 37) {
            return -3247;
          } else {
            return -24784;
          }
        } else {
          if (features[4] < 20) {
            if (features[4] < 16) {
              return -26668;
            } else {
              if (features[7] < 53) {
                return 3570;
              } else {
                return -24843;
              }
            }
          } else {
            return -26529;
          }
        }
      }
    }
  } else {
    if (features[0] < 72) {
      if (features[0] < 36) {
        if (features[1] < 68) {
          if (features[5] < 17) {
            if (features[6] < 28) {
              if (features[3] < 7) {
                return -21492;
              } else {
                return -9780;
              }
            } else {
              return -27056;
            }
          } else {
            if (features[0] < 35) {
              if (features[7] < 21) {
                return -22988;
              } else {
                return -15815;
              }
            } else {
              if (features[1] < 60) {
                return -7204;
              } else {
                return -25539;
              }
            }
          }
        } else {
          if (features[10] < 21) {
            if (features[7] < 33) {
              if (features[2] < 19) {
                return -8731;
              } else {
                return 767;
              }
            } else {
              if (features[3] < 57) {
                return -7074;
              } else {
                return -26447;
              }
            }
          } else {
            return -25586;
          }
        }
      } else {
        if (features[6] < 21) {
          if (features[1] < 107) {
            if (features[3] < 3) {
              return -22602;
            } else {
              if (features[7] < 5) {
                return -9910;
              } else {
                return -3447;
              }
            }
          } else {
            if (features[10] < 1) {
              return -3656;
            } else {
              if (features[3] < 75) {
                return -21176;
              } else {
                return -1671;
              }
            }
          }
        } else {
          if (features[11] < 2) {
            return -7865;
          } else {
            if (features[0] < 50) {
              return -26261;
            } else {
              if (features[6] < 58) {
                return -5174;
              } else {
                return -24846;
              }
            }
          }
        }
      }
    } else {
      if (features[8] < 20) {
        if (features[6] < 4) {
          if (features[2] < 30) {
            if (features[3] < 8) {
              return -11339;
            } else {
              return -24155;
            }
          } else {
            if (features[8] < 12) {
              return -18603;
            } else {
              return -103;
            }
          }
        } else {
          return -24935;
        }
      } else {
        return -24303;
      }
    }
  }
}

short tree14(const unsigned char* features) {
  if (features[0] < 20) {
    if (features[6] < 6) {
      if (features[1] < 47) {
        if (features[8] < 106) {
          if (features[4] < 80) {
            if (features[0] < 19) {
              if (features[0] < 13) {
                return -27879;
              } else {
                return -26917;
              }
            } else {
              if (features[4] < 18) {
                return -25199;
              } else {
                return -20408;
              }
            }
          } else {
            if (features[3] < 25) {
              return -27106;
            } else {
              if (features[4] < 103) {
                return -13148;
              } else {
                return 9240;
              }
            }
          }
        } else {
          if (features[11] < 1) {
            return -25189;
          } else {
            if (features[0] < 12) {
              return -17446;
            } else {
              if (features[9] < 2) {
                return -2427;
              } else {
                return -17679;
              }
            }
          }
        }
      } else {
        if (features[4] < 28) {
          if (features[1] < 59) {
            if (features[2] < 21) {
              if (features[1] < 53) {
                return -24674;
              } else {
                return -16472;
              }
            } else {
              return -4633;
            }
          } else {
            if (features[1] < 94) {
              if (features[4] < 11) {
                return -23845;
              } else {
                return -6391;
              }
            } else {
              if (features[2] < 3) {
                return -6813;
              } else {
                return -22010;
              }
            }
          }
        } else {
          if (features[5] < 13) {
            return -23742;
          } else {
            if (features[2] < 20) {
              return 11461;
            } else {
              if (features[6] < 3) {
                return -4087;
              } else {
                return -25861;
              }
            }
          }
        }
      }
    } else {
      if (features[6] < 17) {
        if (features[4] < 8) {
          if (features[8] < 8) {
            if (features[3] < 9) {
              if (features[4] < 5) {
                return -17787;
              } else {
                return 4770;
              }
            } else {
              return -18853;
            }
          } else {
            if (features[9] < 1) {
              if (features[2] < 5) {
                return -19826;
              } else {
                return -4625;
              }
            } else {
              if (features[7] < 30) {
                return -26320;
              } else {
                return -12674;
              }
            }
          }
        } else {
          if (features[3] < 6) {
            return 2858;
          } else {
            if (features[0] < 11) {
              if (features[6] < 11) {
                return -20023;
              } else {
                return -9221;
              }
            } else {
              if (features[5] < 11) {
                return -23534;
              } else {
                return -5209;
              }
            }
          }
        }
      } else {
        if (features[2] < 11) {
          if (features[0] < 18) {
            if (features[1] < 27) {
              if (features[11] < 11) {
                return -13803;
              } else {
                return 9818;
              }
            } else {
              return -24286;
            }
          } else {
            return -26165;
          }
        } else {
          return -27055;
        }
      }
    }
  } else {
    if (features[0] < 39) {
      if (features[6] < 18) {
        if (features[0] < 24) {
          if (features[8] < 66) {
            if (features[5] < 15) {
              if (features[6] < 3) {
                return -19765;
              } else {
                return -10074;
              }
            } else {
              if (features[4] < 14) {
                return -19520;
              } else {
                return -9371;
              }
            }
          } else {
            if (features[7] < 10) {
              if (features[3] < 15) {
                return -4782;
              } else {
                return -19844;
              }
            } else {
              if (features[5] < 13) {
                return -7994;
              } else {
                return 3608;
              }
            }
          }
        } else {
          if (features[1] < 86) {
            if (features[0] < 34) {
              if (features[1] < 39) {
                return -7616;
              } else {
                return -3719;
              }
            } else {
              if (features[11] < 17) {
                return -9419;
              } else {
                return -22502;
              }
            }
          } else {
            if (features[2] < 63) {
              if (features[2] < 14) {
                return -14926;
              } else {
                return -26724;
              }
            } else {
              return -7092;
            }
          }
        }
      } else {
        return -27343;
      }
    } else {
      if (features[0] < 46) {
        if (features[10] < 8) {
          if (features[3] < 7) {
            if (features[1] < 58) {
              return -4527;
            } else {
              return -24598;
            }
          } else {
            if (features[7] < 10) {
              if (features[6] < 2) {
                return -18275;
              } else {
                return -26445;
              }
            } else {
              if (features[7] < 17) {
                return -14550;
              } else {
                return -20695;
              }
            }
          }
        } else {
          return -26860;
        }
      } else {
        if (features[6] < 1) {
          if (features[2] < 5) {
            return -27260;
          } else {
            if (features[2] < 7) {
              if (features[2] < 6) {
                return -17191;
              } else {
                return 3307;
              }
            } else {
              if (features[8] < 43) {
                return -23291;
              } else {
                return -8889;
              }
            }
          }
        } else {
          if (features[3] < 4) {
            if (features[5] < 9) {
              return -230;
            } else {
              return -24659;
            }
          } else {
            return -26996;
          }
        }
      }
    }
  }
}

short tree15(const unsigned char* features) {
  if (features[0] < 26) {
    if (features[1] < 21) {
      if (features[6] < 2) {
        if (features[8] < 50) {
          if (features[0] < 15) {
            if (features[4] < 27) {
              if (features[4] < 1) {
                return -15842;
              } else {
                return -24062;
              }
            } else {
              if (features[6] < 1) {
                return -2122;
              } else {
                return -14713;
              }
            }
          } else {
            if (features[7] < 8) {
              if (features[9] < 1) {
                return -8425;
              } else {
                return -20403;
              }
            } else {
              if (features[3] < 7) {
                return -8860;
              } else {
                return 1592;
              }
            }
          }
        } else {
          if (features[11] < 2) {
            if (features[2] < 5) {
              if (features[7] < 8) {
                return -22624;
              } else {
                return -12800;
              }
            } else {
              if (features[10] < 1) {
                return 2665;
              } else {
                return -7186;
              }
            }
          } else {
            if (features[5] < 29) {
              if (features[3] < 23) {
                return 3698;
              } else {
                return -17956;
              }
            } else {
              return -18128;
            }
          }
        }
      } else {
        if (features[10] < 1) {
          if (features[4] < 45) {
            if (features[8] < 23) {
              if (features[6] < 3) {
                return -24261;
              } else {
                return -10642;
              }
            } else {
              if (features[3] < 7) {
                return -15591;
              } else {
                return -7059;
              }
            }
          } else {
            return 2666;
          }
        } else {
          if (features[6] < 12) {
            if (features[4] < 15) {
              if (features[3] < 15) {
                return -2532;
              } else {
                return -13158;
              }
            } else {
              if (features[9] < 1) {
                return -14091;
              } else {
                return -6429;
              }
            }
          } else {
            return -26608;
          }
        }
      }
    } else {
      if (features[0] < 11) {
        if (features[1] < 25) {
          if (features[6] < 2) {
            if (features[8] < 43) {
              if (features[11] < 1) {
                return -5225;
              } else {
                return -18302;
              }
            } else {
              if (features[11] < 11) {
                return -6866;
              } else {
                return -24227;
              }
            }
          } else {
            if (features[6] < 14) {
              if (features[7] < 9) {
                return -10438;
              } else {
                return -2804;
              }
            } else {
              if (features[4] < 8) {
                return -2014;
              } else {
                return -24117;
              }
            }
          }
        } else {
          if (features[6] < 11) {
            if (features[4] < 12) {
              if (features[8] < 46) {
                return -13132;
              } else {
                return -2145;
              }
            } else {
              if (features[1] < 48) {
                return -3299;
              } else {
                return -19303;
              }
            }
          } else {
            return -26588;
          }
        }
      } else {
        if (features[6] < 6) {
          if (features[1] < 53) {
            if (features[7] < 17) {
              if (features[1] < 27) {
                return -6144;
              } else {
                return -2469;
              }
            } else {
              if (features[0] < 23) {
                return -1039;
              } else {
                return -9299;
              }
            }
          } else {
            if (features[5] < 15) {
              if (features[1] < 74) {
                return -5129;
              } else {
                return -17153;
              }
            } else {
              if (features[10] < 2) {
                return -8527;
              } else {
                return -20614;
              }
            }
          }
        } else {
          if (features[4] < 10) {
            if (features[0] < 18) {
              if (features[6] < 13) {
                return -7285;
              } else {
                return -19408;
              }
            } else {
              if (features[11] < 2) {
                return 265;
              } else {
                return -20684;
              }
            }
          } else {
            if (features[3] < 24) {
              if (features[5] < 11) {
                return -121;
              } else {
                return -16003;
              }
            } else {
              if (features[2] < 6) {
                return -16103;
              } else {
                return -25241;
              }
            }
          }
        }
      }
    }
  } else {
    if (features[10] < 2) {
      if (features[0] < 28) {
        if (features[7] < 27) {
          if (features[4] < 62) {
            if (features[2] < 10) {
              if (features[7] < 15) {
                return -12098;
              } else {
                return -1321;
              }
            } else {
              if (features[6] < 2) {
                return -13128;
              } else {
                return -23177;
              }
            }
          } else {
            return 2904;
          }
        } else {
          if (features[7] < 47) {
            return -26861;
          } else {
            return -14744;
          }
        }
      } else {
        if (features[6] < 1) {
          if (features[4] < 6) {
            return 342;
          } else {
            if (features[8] < 18) {
              if (features[2] < 8) {
                return -18637;
              } else {
                return -3213;
              }
            } else {
              if (features[5] < 47) {
                return -21419;
              } else {
                return 1439;
              }
            }
          }
        } else {
          if (features[1] < 24) {
            return -2145;
          } else {
            if (features[0] < 35) {
              if (features[5] < 39) {
                return -21915;
              } else {
                return -8217;
              }
            } else {
              if (features[7] < 4) {
                return -16202;
              } else {
                return -25384;
              }
            }
          }
        }
      }
    } else {
      if (features[2] < 14) {
        if (features[0] < 29) {
          if (features[5] < 11) {
            if (features[4] < 9) {
              return -25018;
            } else {
              if (features[9] < 3) {
                return -12426;
              } else {
                return 8691;
              }
            }
          } else {
            if (features[10] < 6) {
              if (features[10] < 3) {
                return -24705;
              } else {
                return -11185;
              }
            } else {
              if (features[11] < 38) {
                return -27642;
              } else {
                return -7502;
              }
            }
          }
        } else {
          if (features[6] < 2) {
            if (features[10] < 20) {
              if (features[3] < 5) {
                return -12816;
              } else {
                return -23765;
              }
            } else {
              return -7566;
            }
          } else {
            if (features[0] < 121) {
              return -26436;
            } else {
              return -13628;
            }
          }
        }
      } else {
        if (features[5] < 10) {
          if (features[4] < 26) {
            if (features[2] < 17) {
              return -24756;
            } else {
              return -1553;
            }
          } else {
            return -25341;
          }
        } else {
          if (features[9] < 23) {
            return -27671;
          } else {
            return -14395;
          }
        }
      }
    }
  }
}

short tree16(const unsigned char* features) {
  if (features[0] < 15) {
    if (features[6] < 3) {
      if (features[1] < 27) {
        if (features[8] < 66) {
          if (features[1] < 6) {
            if (features[6] < 1) {
              if (features[8] < 33) {
                return -22510;
              } else {
                return -5445;
              }
            } else {
              if (features[0] < 9) {
                return -3570;
              } else {
                return -22980;
              }
            }
          } else {
            if (features[4] < 44) {
              if (features[1] < 23) {
                return -3886;
              } else {
                return -6716;
              }
            } else {
              if (features[7] < 33) {
                return -23988;
              } else {
                return -5839;
              }
            }
          }
        } else {
          if (features[1] < 22) {
            if (features[5] < 24) {
              if (features[4] < 16) {
                return -7341;
              } else {
                return -23602;
              }
            } else {
              if (features[7] < 9) {
                return -14629;
              } else {
                return -28033;
              }
            }
          } else {
            if (features[5] < 10) {
              if (features[3] < 6) {
                return -2622;
              } else {
                return -21482;
              }
            } else {
              if (features[11] < 13) {
                return -25849;
              } else {
                return -14287;
              }
            }
          }
        }
      } else {
        if (features[0] < 11) {
          if (features[5] < 10) {
            if (features[1] < 33) {
              if (features[4] < 18) {
                return -21732;
              } else {
                return -4982;
              }
            } else {
              return -26098;
            }
          } else {
            if (features[6] < 2) {
              if (features[8] < 51) {
                return -3959;
              } else {
                return -19527;
              }
            } else {
              return -23457;
            }
          }
        } else {
          if (features[4] < 1) {
            if (features[3] < 24) {
              if (features[1] < 29) {
                return -10528;
              } else {
                return -26310;
              }
            } else {
              return 1416;
            }
          } else {
            if (features[8] < 39) {
              if (features[1] < 32) {
                return -15050;
              } else {
                return -25194;
              }
            } else {
              return -26128;
            }
          }
        }
      }
    } else {
      if (features[7] < 10) {
        if (features[6] < 10) {
          if (features[4] < 17) {
            if (features[2] < 4) {
              if (features[1] < 8) {
                return -26408;
              } else {
                return -10699;
              }
            } else {
              if (features[8] < 45) {
                return -25244;
              } else {
                return -14270;
              }
            }
          } else {
            if (features[1] < 12) {
              return -25770;
            } else {
              if (features[2] < 9) {
                return -375;
              } else {
                return -19930;
              }
            }
          }
        } else {
          if (features[8] < 6) {
            if (features[0] < 5) {
              return -4562;
            } else {
              return -22257;
            }
          } else {
            return -25900;
          }
        }
      } else {
        if (features[6] < 4) {
          if (features[11] < 1) {
            return -4986;
          } else {
            if (features[7] < 14) {
              if (features[4] < 17) {
                return -22981;
              } else {
                return -7717;
              }
            } else {
              if (features[9] < 3) {
                return -25016;
              } else {
                return -9420;
              }
            }
          }
        } else {
          return -27724;
        }
      }
    }
  } else {
    if (features[1] < 24) {
      if (features[2] < 8) {
        if (features[8] < 22) {
          if (features[8] < 3) {
            return -19739;
          } else {
            if (features[6] < 2) {
              if (features[10] < 2) {
                return -984;
              } else {
                return -18658;
              }
            } else {
              if (features[1] < 10) {
                return -6552;
              } else {
                return -23551;
              }
            }
          }
        } else {
          if (features[2] < 6) {
            if (features[0] < 17) {
              if (features[10] < 2) {
                return -5320;
              } else {
                return -21718;
              }
            } else {
              if (features[7] < 9) {
                return -14962;
              } else {
                return -22618;
              }
            }
          } else {
            if (features[8] < 35) {
              if (features[8] < 23) {
                return -16643;
              } else {
                return 3260;
              }
            } else {
              if (features[4] < 12) {
                return -6916;
              } else {
                return -26605;
              }
            }
          }
        }
      } else {
        if (features[5] < 12) {
          if (features[8] < 39) {
            if (features[4] < 19) {
              if (features[1] < 6) {
                return -20178;
              } else {
                return -7150;
              }
            } else {
              return -22706;
            }
          } else {
            return -25231;
          }
        } else {
          if (features[11] < 1) {
            return -6913;
          } else {
            return -26474;
          }
        }
      }
    } else {
      if (features[0] < 17) {
        if (features[1] < 28) {
          if (features[6] < 1) {
            if (features[8] < 29) {
              if (features[4] < 10) {
                return 2705;
              } else {
                return -10146;
              }
            } else {
              if (features[8] < 59) {
                return -12699;
              } else {
                return -26674;
              }
            }
          } else {
            if (features[6] < 3) {
              if (features[2] < 7) {
                return -20634;
              } else {
                return -14424;
              }
            } else {
              return -26877;
            }
          }
        } else {
          if (features[6] < 1) {
            if (features[1] < 34) {
              if (features[3] < 21) {
                return -4487;
              } else {
                return -24956;
              }
            } else {
              return -26630;
            }
          } else {
            return -27200;
          }
        }
      } else {
        if (features[3] < 12) {
          if (features[0] < 19) {
            if (features[11] < 14) {
              if (features[1] < 36) {
                return -23461;
              } else {
                return -27934;
              }
            } else {
              if (features[7] < 9) {
                return -1843;
              } else {
                return -18150;
              }
            }
          } else {
            return -27364;
          }
        } else {
          return -27614;
        }
      }
    }
  }
}

short tree17(const unsigned char* features) {
  if (features[1] < 13) {
    if (features[6] < 1) {
      if (features[8] < 37) {
        if (features[2] < 15) {
          if (features[8] < 22) {
            if (features[0] < 8) {
              if (features[2] < 8) {
                return -1631;
              } else {
                return -9494;
              }
            } else {
              if (features[11] < 15) {
                return -18190;
              } else {
                return 89;
              }
            }
          } else {
            if (features[3] < 9) {
              if (features[3] < 2) {
                return -15335;
              } else {
                return -3635;
              }
            } else {
              if (features[7] < 20) {
                return -17855;
              } else {
                return -5487;
              }
            }
          }
        } else {
          if (features[1] < 7) {
            return -14440;
          } else {
            return -27815;
          }
        }
      } else {
        if (features[8] < 41) {
          if (features[0] < 4) {
            if (features[2] < 4) {
              if (features[5] < 7) {
                return 4289;
              } else {
                return -24498;
              }
            } else {
              return -25821;
            }
          } else {
            if (features[10] < 1) {
              if (features[7] < 9) {
                return -3642;
              } else {
                return -22814;
              }
            } else {
              return -27300;
            }
          }
        } else {
          return -27459;
        }
      }
    } else {
      if (features[6] < 3) {
        if (features[6] < 2) {
          if (features[1] < 10) {
            if (features[11] < 2) {
              if (features[8] < 31) {
                return -19979;
              } else {
                return -26557;
              }
            } else {
              if (features[10] < 2) {
                return 868;
              } else {
                return -24374;
              }
            }
          } else {
            return -26050;
          }
        } else {
          return -27935;
        }
      } else {
        if (features[8] < 33) {
          if (features[7] < 13) {
            if (features[8] < 5) {
              return -24774;
            } else {
              if (features[5] < 21) {
                return -772;
              } else {
                return -20979;
              }
            }
          } else {
            if (features[2] < 1) {
              return -5304;
            } else {
              if (features[3] < 29) {
                return -27023;
              } else {
                return -9049;
              }
            }
          }
        } else {
          if (features[11] < 5) {
            return -25738;
          } else {
            return -11580;
          }
        }
      }
    }
  } else {
    if (features[0] < 8) {
      if (features[6] < 1) {
        if (features[8] < 35) {
          if (features[5] < 11) {
            if (features[9] < 7) {
              if (features[1] < 15) {
                return -19298;
              } else {
                return -25975;
              }
            } else {
              if (features[9] < 12) {
                return 758;
              } else {
                return -17668;
              }
            }
          } else {
            if (features[7] < 5) {
              if (features[8] < 16) {
                return 10577;
              } else {
                return -13589;
              }
            } else {
              if (features[2] < 7) {
                return -22454;
              } else {
                return -6868;
              }
            }
          }
        } else {
          return -27961;
        }
      } else {
        if (features[4] < 5) {
          if (features[8] < 22) {
            if (features[6] < 2) {
              if (features[1] < 21) {
                return -20765;
              } else {
                return -2796;
              }
            } else {
              if (features[5] < 29) {
                return -24587;
              } else {
                return -2488;
              }
            }
          } else {
            return -27247;
          }
        } else {
          if (features[7] < 2) {
            if (features[5] < 12) {
              if (features[3] < 18) {
                return -2033;
              } else {
                return -23261;
              }
            } else {
              return -25047;
            }
          } else {
            return -27507;
          }
        }
      }
    } else {
      return -27916;
    }
  }
}

short tree18(const unsigned char* features) {
  if (features[6] < 21) {
    if (features[0] < 58) {
      if (features[1] < 93) {
        if (features[6] < 12) {
          if (features[0] < 39) {
            if (features[1] < 80) {
              return -27803;
            } else {
              if (features[3] < 54) {
                return -26462;
              } else {
                return -8247;
              }
            }
          } else {
            if (features[2] < 81) {
              return -25085;
            } else {
              if (features[8] < 31) {
                return -25012;
              } else {
                return -7496;
              }
            }
          }
        } else {
          if (features[7] < 32) {
            if (features[10] < 10) {
              return -26384;
            } else {
              if (features[11] < 6) {
                return -21467;
              } else {
                return -7111;
              }
            }
          } else {
            if (features[0] < 26) {
              if (features[8] < 55) {
                return -15140;
              } else {
                return -26161;
              }
            } else {
              if (features[4] < 16) {
                return -16314;
              } else {
                return 4484;
              }
            }
          }
        }
      } else {
        if (features[1] < 108) {
          if (features[3] < 54) {
            if (features[7] < 74) {
              return -26411;
            } else {
              return -13494;
            }
          } else {
            if (features[1] < 95) {
              return 2300;
            } else {
              if (features[6] < 3) {
                return -9731;
              } else {
                return -24845;
              }
            }
          }
        } else {
          if (features[4] < 33) {
            return -6844;
          } else {
            return -18696;
          }
        }
      }
    } else {
      if (features[0] < 75) {
        if (features[9] < 2) {
          if (features[8] < 50) {
            if (features[3] < 52) {
              if (features[8] < 36) {
                return -13833;
              } else {
                return -5850;
              }
            } else {
              return -22860;
            }
          } else {
            if (features[4] < 29) {
              return -27045;
            } else {
              return -13151;
            }
          }
        } else {
          if (features[8] < 66) {
            if (features[8] < 55) {
              if (features[0] < 63) {
                return -14622;
              } else {
                return -7524;
              }
            } else {
              return -21667;
            }
          } else {
            if (features[10] < 12) {
              return 1518;
            } else {
              if (features[0] < 65) {
                return -21833;
              } else {
                return -3910;
              }
            }
          }
        }
      } else {
        if (features[6] < 1) {
          if (features[3] < 3) {
            return -24902;
          } else {
            if (features[0] < 107) {
              if (features[8] < 19) {
                return -26435;
              } else {
                return -11498;
              }
            } else {
              if (features[0] < 199) {
                return -1174;
              } else {
                return -18481;
              }
            }
          }
        } else {
          return -4501;
        }
      }
    }
  } else {
    if (features[4] < 16) {
      if (features[2] < 10) {
        return -27408;
      } else {
        if (features[0] < 10) {
          return -24864;
        } else {
          return -11469;
        }
      }
    } else {
      if (features[7] < 55) {
        if (features[6] < 29) {
          if (features[0] < 27) {
            if (features[3] < 107) {
              return -26539;
            } else {
              return -9999;
            }
          } else {
            if (features[2] < 6) {
              return -26441;
            } else {
              return -3540;
            }
          }
        } else {
          if (features[9] < 12) {
            if (features[10] < 12) {
              if (features[7] < 51) {
                return -9489;
              } else {
                return -26356;
              }
            } else {
              if (features[4] < 20) {
                return -12321;
              } else {
                return -4122;
              }
            }
          } else {
            return -25300;
          }
        }
      } else {
        if (features[10] < 2) {
          if (features[0] < 19) {
            return -27734;
          } else {
            return -8192;
          }
        } else {
          return -4464;
        }
      }
    }
  }
}

short tree19(const unsigned char* features) {
  if (features[0] < 30) {
    if (features[6] < 9) {
      if (features[1] < 69) {
        if (features[0] < 24) {
          return -27750;
        } else {
          if (features[3] < 70) {
            if (features[1] < 57) {
              if (features[3] < 8) {
                return -20421;
              } else {
                return -25543;
              }
            } else {
              if (features[6] < 4) {
                return -21564;
              } else {
                return 197;
              }
            }
          } else {
            return -12314;
          }
        }
      } else {
        if (features[0] < 22) {
          if (features[3] < 6) {
            if (features[7] < 94) {
              if (features[8] < 8) {
                return 2769;
              } else {
                return -13093;
              }
            } else {
              return -23776;
            }
          } else {
            if (features[4] < 25) {
              return -26503;
            } else {
              return -12225;
            }
          }
        } else {
          if (features[7] < 49) {
            if (features[7] < 38) {
              if (features[1] < 110) {
                return -12058;
              } else {
                return -26614;
              }
            } else {
              return -1041;
            }
          } else {
            return -24590;
          }
        }
      }
    } else {
      if (features[4] < 11) {
        if (features[0] < 19) {
          return -27122;
        } else {
          if (features[11] < 2) {
            return -25298;
          } else {
            return -2547;
          }
        }
      } else {
        if (features[6] < 32) {
          if (features[6] < 15) {
            if (features[8] < 60) {
              if (features[7] < 14) {
                return -26894;
              } else {
                return -18237;
              }
            } else {
              if (features[11] < 11) {
                return -2108;
              } else {
                return -24599;
              }
            }
          } else {
            if (features[11] < 3) {
              if (features[10] < 15) {
                return -2310;
              } else {
                return -11010;
              }
            } else {
              if (features[0] < 10) {
                return -2808;
              } else {
                return -14912;
              }
            }
          }
        } else {
          if (features[6] < 48) {
            if (features[7] < 53) {
              if (features[4] < 20) {
                return -2574;
              } else {
                return -19796;
              }
            } else {
              if (features[9] < 1) {
                return -11337;
              } else {
                return -25723;
              }
            }
          } else {
            return -27577;
          }
        }
      }
    }
  } else {
    if (features[0] < 73) {
      if (features[0] < 38) {
        if (features[6] < 45) {
          if (features[8] < 58) {
            if (features[5] < 17) {
              if (features[9] < 7) {
                return -11176;
              } else {
                return -23693;
              }
            } else {
              if (features[1] < 69) {
                return -20068;
              } else {
                return -9678;
              }
            }
          } else {
            if (features[2] < 19) {
              if (features[0] < 35) {
                return -14575;
              } else {
                return -5585;
              }
            } else {
              if (features[1] < 80) {
                return -1856;
              } else {
                return -15019;
              }
            }
          }
        } else {
          return -26569;
        }
      } else {
        if (features[0] < 58) {
          if (features[6] < 21) {
            if (features[6] < 1) {
              if (features[7] < 4) {
                return -28432;
              } else {
                return -9158;
              }
            } else {
              if (features[3] < 3) {
                return -23253;
              } else {
                return -5673;
              }
            }
          } else {
            if (features[7] < 12) {
              return -2729;
            } else {
              if (features[8] < 34) {
                return -15173;
              } else {
                return -26795;
              }
            }
          }
        } else {
          if (features[8] < 101) {
            if (features[5] < 9) {
              return -23603;
            } else {
              if (features[7] < 5) {
                return -17013;
              } else {
                return -9499;
              }
            }
          } else {
            return -22764;
          }
        }
      }
    } else {
      if (features[5] < 14) {
        if (features[6] < 4) {
          if (features[0] < 104) {
            if (features[4] < 13) {
              return -23319;
            } else {
              if (features[2] < 5) {
                return 1324;
              } else {
                return -13655;
              }
            }
          } else {
            return -25497;
          }
        } else {
          return -26126;
        }
      } else {
        return -26630;
      }
    }
  }
}

short tree20(const unsigned char* features) {
  if (features[0] < 19) {
    if (features[6] < 6) {
      if (features[1] < 47) {
        if (features[8] < 110) {
          if (features[4] < 90) {
            if (features[0] < 13) {
              return -27607;
            } else {
              if (features[8] < 53) {
                return -26775;
              } else {
                return -23606;
              }
            }
          } else {
            if (features[8] < 36) {
              return -26323;
            } else {
              return 3547;
            }
          }
        } else {
          if (features[4] < 17) {
            if (features[7] < 54) {
              return -26230;
            } else {
              return -9423;
            }
          } else {
            return -2751;
          }
        }
      } else {
        if (features[10] < 1) {
          return -25661;
        } else {
          if (features[5] < 13) {
            if (features[1] < 64) {
              if (features[0] < 11) {
                return -5932;
              } else {
                return -23556;
              }
            } else {
              if (features[1] < 110) {
                return -9930;
              } else {
                return -23674;
              }
            }
          } else {
            if (features[2] < 10) {
              if (features[7] < 11) {
                return -26240;
              } else {
                return -13409;
              }
            } else {
              if (features[10] < 12) {
                return -2269;
              } else {
                return -17378;
              }
            }
          }
        }
      }
    } else {
      if (features[2] < 11) {
        if (features[0] < 18) {
          if (features[2] < 5) {
            if (features[7] < 32) {
              if (features[4] < 11) {
                return -14045;
              } else {
                return -27086;
              }
            } else {
              if (features[8] < 49) {
                return -2264;
              } else {
                return -17312;
              }
            }
          } else {
            if (features[7] < 37) {
              if (features[9] < 5) {
                return -5076;
              } else {
                return -21007;
              }
            } else {
              if (features[4] < 35) {
                return -13045;
              } else {
                return -24123;
              }
            }
          }
        } else {
          if (features[1] < 25) {
            return -25111;
          } else {
            return 1914;
          }
        }
      } else {
        if (features[5] < 16) {
          return -26689;
        } else {
          return -4759;
        }
      }
    }
  } else {
    if (features[0] < 42) {
      if (features[6] < 18) {
        if (features[0] < 22) {
          if (features[6] < 5) {
            if (features[8] < 65) {
              if (features[1] < 53) {
                return -20770;
              } else {
                return -11744;
              }
            } else {
              if (features[4] < 11) {
                return -18957;
              } else {
                return -6174;
              }
            }
          } else {
            if (features[8] < 14) {
              return -25060;
            } else {
              if (features[7] < 38) {
                return -1457;
              } else {
                return -11096;
              }
            }
          }
        } else {
          if (features[0] < 36) {
            if (features[1] < 95) {
              if (features[0] < 25) {
                return -11884;
              } else {
                return -8356;
              }
            } else {
              if (features[10] < 1) {
                return -8211;
              } else {
                return -26530;
              }
            }
          } else {
            if (features[11] < 17) {
              if (features[8] < 98) {
                return -13707;
              } else {
                return -27736;
              }
            } else {
              return -25837;
            }
          }
        }
      } else {
        return -27034;
      }
    } else {
      if (features[0] < 49) {
        if (features[7] < 17) {
          if (features[7] < 14) {
            if (features[2] < 66) {
              if (features[6] < 1) {
                return -12257;
              } else {
                return -23240;
              }
            } else {
              return -7105;
            }
          } else {
            if (features[4] < 37) {
              if (features[1] < 25) {
                return -10018;
              } else {
                return 12794;
              }
            } else {
              return -24358;
            }
          }
        } else {
          if (features[5] < 51) {
            return -26422;
          } else {
            return -2043;
          }
        }
      } else {
        if (features[5] < 6) {
          if (features[1] < 89) {
            return -5348;
          } else {
            return -24851;
          }
        } else {
          if (features[3] < 24) {
            if (features[5] < 12) {
              if (features[7] < 5) {
                return -19288;
              } else {
                return -26496;
              }
            } else {
              if (features[0] < 54) {
                return 1100;
              } else {
                return -25573;
              }
            }
          } else {
            return -27690;
          }
        }
      }
    }
  }
}

short tree21(const unsigned char* features) {
  if (features[0] < 27) {
    if (features[0] < 10) {
      if (features[6] < 2) {
        if (features[1] < 18) {
          if (features[8] < 49) {
            if (features[4] < 1) {
              if (features[5] < 2) {
                return -2513;
              } else {
                return -22024;
              }
            } else {
              if (features[4] < 36) {
                return -24304;
              } else {
                return -7819;
              }
            }
          } else {
            if (features[5] < 3) {
              return -25790;
            } else {
              if (features[10] < 5) {
                return -14383;
              } else {
                return -1389;
              }
            }
          }
        } else {
          if (features[8] < 41) {
            if (features[5] < 15) {
              if (features[1] < 30) {
                return -15975;
              } else {
                return -6540;
              }
            } else {
              if (features[10] < 5) {
                return -23735;
              } else {
                return -4516;
              }
            }
          } else {
            if (features[9] < 2) {
              if (features[1] < 25) {
                return -13716;
              } else {
                return -5832;
              }
            } else {
              if (features[7] < 8) {
                return -21023;
              } else {
                return 6565;
              }
            }
          }
        }
      } else {
        if (features[6] < 11) {
          if (features[6] < 3) {
            if (features[10] < 1) {
              if (features[4] < 45) {
                return -18628;
              } else {
                return -1267;
              }
            } else {
              if (features[1] < 8) {
                return -397;
              } else {
                return -11272;
              }
            }
          } else {
            if (features[7] < 29) {
              if (features[9] < 5) {
                return -7093;
              } else {
                return -20925;
              }
            } else {
              return -1118;
            }
          }
        } else {
          if (features[2] < 4) {
            if (features[7] < 2) {
              return -25969;
            } else {
              if (features[4] < 1) {
                return -25359;
              } else {
                return -891;
              }
            }
          } else {
            if (features[7] < 20) {
              if (features[8] < 17) {
                return -26144;
              } else {
                return -10833;
              }
            } else {
              return -24903;
            }
          }
        }
      }
    } else {
      if (features[6] < 12) {
        if (features[1] < 23) {
          if (features[5] < 13) {
            if (features[6] < 2) {
              if (features[8] < 66) {
                return -16743;
              } else {
                return -6040;
              }
            } else {
              if (features[10] < 1) {
                return -21216;
              } else {
                return -7529;
              }
            }
          } else {
            if (features[4] < 6) {
              if (features[5] < 17) {
                return -26523;
              } else {
                return -16244;
              }
            } else {
              if (features[8] < 39) {
                return -9308;
              } else {
                return -859;
              }
            }
          }
        } else {
          if (features[0] < 22) {
            if (features[0] < 17) {
              if (features[1] < 28) {
                return -10013;
              } else {
                return -5072;
              }
            } else {
              if (features[1] < 53) {
                return -4464;
              } else {
                return -12220;
              }
            }
          } else {
            if (features[8] < 57) {
              if (features[1] < 72) {
                return -10018;
              } else {
                return -24597;
              }
            } else {
              if (features[4] < 30) {
                return -13753;
              } else {
                return -27817;
              }
            }
          }
        }
      } else {
        if (features[4] < 7) {
          if (features[0] < 13) {
            return -18385;
          } else {
            return -3659;
          }
        } else {
          if (features[3] < 20) {
            if (features[8] < 30) {
              if (features[2] < 6) {
                return -12345;
              } else {
                return -22408;
              }
            } else {
              if (features[0] < 19) {
                return -2730;
              } else {
                return -25797;
              }
            }
          } else {
            if (features[2] < 29) {
              if (features[10] < 1) {
                return -12809;
              } else {
                return -26213;
              }
            } else {
              if (features[0] < 20) {
                return -7412;
              } else {
                return -24321;
              }
            }
          }
        }
      }
    }
  } else {
    if (features[10] < 2) {
      if (features[6] < 2) {
        if (features[4] < 3) {
          if (features[8] < 17) {
            return 9961;
          } else {
            if (features[6] < 1) {
              if (features[8] < 19) {
                return -18204;
              } else {
                return 523;
              }
            } else {
              if (features[0] < 28) {
                return -7045;
              } else {
                return -26247;
              }
            }
          }
        } else {
          if (features[5] < 41) {
            if (features[8] < 16) {
              if (features[3] < 28) {
                return -14990;
              } else {
                return 2182;
              }
            } else {
              if (features[4] < 18) {
                return -18631;
              } else {
                return -24742;
              }
            }
          } else {
            if (features[0] < 43) {
              return 1754;
            } else {
              return -21318;
            }
          }
        }
      } else {
        if (features[0] < 46) {
          if (features[8] < 5) {
            return -1876;
          } else {
            if (features[7] < 3) {
              if (features[8] < 16) {
                return -19368;
              } else {
                return -770;
              }
            } else {
              if (features[8] < 24) {
                return -24253;
              } else {
                return -20238;
              }
            }
          }
        } else {
          if (features[3] < 62) {
            return -26174;
          } else {
            return -14097;
          }
        }
      }
    } else {
      if (features[2] < 6) {
        if (features[7] < 19) {
          if (features[4] < 10) {
            if (features[0] < 32) {
              return -8313;
            } else {
              return -22062;
            }
          } else {
            return -25743;
          }
        } else {
          if (features[3] < 12) {
            if (features[4] < 5) {
              if (features[0] < 37) {
                return -5822;
              } else {
                return -23689;
              }
            } else {
              return 16606;
            }
          } else {
            if (features[7] < 27) {
              return -10849;
            } else {
              return -26571;
            }
          }
        }
      } else {
        if (features[5] < 8) {
          if (features[1] < 26) {
            return -23692;
          } else {
            if (features[1] < 56) {
              return 81;
            } else {
              return -24704;
            }
          }
        } else {
          if (features[6] < 48) {
            return -26953;
          } else {
            if (features[7] < 38) {
              return 6485;
            } else {
              return -25434;
            }
          }
        }
      }
    }
  }
}

short tree22(const unsigned char* features) {
  if (features[0] < 16) {
    if (features[1] < 28) {
      if (features[6] < 3) {
        if (features[8] < 55) {
          if (features[1] < 9) {
            if (features[6] < 1) {
              if (features[8] < 29) {
                return -19733;
              } else {
                return -9553;
              }
            } else {
              if (features[6] < 2) {
                return -5101;
              } else {
                return -10452;
              }
            }
          } else {
            if (features[1] < 21) {
              if (features[1] < 12) {
                return -9186;
              } else {
                return -5515;
              }
            } else {
              if (features[4] < 25) {
                return -8745;
              } else {
                return -17546;
              }
            }
          }
        } else {
          if (features[2] < 1) {
            if (features[8] < 76) {
              if (features[0] < 14) {
                return -1383;
              } else {
                return -20127;
              }
            } else {
              if (features[7] < 11) {
                return -9633;
              } else {
                return -26869;
              }
            }
          } else {
            if (features[10] < 16) {
              if (features[1] < 24) {
                return -13527;
              } else {
                return -22060;
              }
            } else {
              if (features[9] < 2) {
                return 4911;
              } else {
                return -27020;
              }
            }
          }
        }
      } else {
        if (features[6] < 4) {
          if (features[7] < 13) {
            if (features[0] < 6) {
              if (features[5] < 23) {
                return -23698;
              } else {
                return -6800;
              }
            } else {
              if (features[5] < 11) {
                return -3729;
              } else {
                return -15614;
              }
            }
          } else {
            if (features[11] < 1) {
              if (features[4] < 11) {
                return -1199;
              } else {
                return -18228;
              }
            } else {
              if (features[11] < 2) {
                return -23785;
              } else {
                return -11232;
              }
            }
          }
        } else {
          if (features[7] < 10) {
            if (features[2] < 3) {
              if (features[8] < 28) {
                return -10063;
              } else {
                return -23485;
              }
            } else {
              if (features[4] < 6) {
                return -17622;
              } else {
                return -26482;
              }
            }
          } else {
            return -27370;
          }
        }
      }
    } else {
      if (features[4] < 12) {
        if (features[5] < 10) {
          return -24373;
        } else {
          if (features[8] < 42) {
            if (features[6] < 2) {
              if (features[11] < 1) {
                return -21083;
              } else {
                return -4758;
              }
            } else {
              return -23873;
            }
          } else {
            if (features[5] < 27) {
              if (features[1] < 30) {
                return -14884;
              } else {
                return -25365;
              }
            } else {
              if (features[1] < 31) {
                return 4918;
              } else {
                return -19240;
              }
            }
          }
        }
      } else {
        if (features[8] < 34) {
          if (features[1] < 30) {
            if (features[2] < 6) {
              if (features[5] < 9) {
                return 6307;
              } else {
                return -20817;
              }
            } else {
              if (features[8] < 12) {
                return -11421;
              } else {
                return -21749;
              }
            }
          } else {
            if (features[5] < 8) {
              return -26370;
            } else {
              if (features[7] < 12) {
                return -14732;
              } else {
                return -24272;
              }
            }
          }
        } else {
          if (features[7] < 6) {
            if (features[1] < 33) {
              if (features[5] < 12) {
                return 3705;
              } else {
                return -25080;
              }
            } else {
              return -26195;
            }
          } else {
            return -26958;
          }
        }
      }
    }
  } else {
    if (features[1] < 24) {
      if (features[4] < 19) {
        if (features[1] < 7) {
          if (features[5] < 10) {
            if (features[11] < 2) {
              return -9742;
            } else {
              return -24901;
            }
          } else {
            return -26104;
          }
        } else {
          if (features[11] < 10) {
            if (features[3] < 20) {
              if (features[8] < 19) {
                return -9649;
              } else {
                return -17095;
              }
            } else {
              if (features[10] < 1) {
                return 1423;
              } else {
                return -15706;
              }
            }
          } else {
            if (features[1] < 11) {
              if (features[7] < 5) {
                return -26308;
              } else {
                return -12110;
              }
            } else {
              return -141;
            }
          }
        }
      } else {
        if (features[7] < 5) {
          return -12516;
        } else {
          return -28002;
        }
      }
    } else {
      if (features[0] < 17) {
        if (features[4] < 7) {
          if (features[7] < 9) {
            if (features[4] < 3) {
              return -20997;
            } else {
              if (features[8] < 34) {
                return 10742;
              } else {
                return -15210;
              }
            }
          } else {
            if (features[2] < 2) {
              if (features[9] < 1) {
                return -2100;
              } else {
                return -23905;
              }
            } else {
              if (features[3] < 28) {
                return -27109;
              } else {
                return -10530;
              }
            }
          }
        } else {
          if (features[8] < 28) {
            if (features[8] < 27) {
              if (features[1] < 27) {
                return -16969;
              } else {
                return -26020;
              }
            } else {
              if (features[9] < 1) {
                return -23824;
              } else {
                return 6051;
              }
            }
          } else {
            return -25008;
          }
        }
      } else {
        if (features[0] < 19) {
          if (features[3] < 15) {
            if (features[11] < 15) {
              if (features[6] < 2) {
                return -22592;
              } else {
                return -27428;
              }
            } else {
              return -9066;
            }
          } else {
            return -26813;
          }
        } else {
          return -27554;
        }
      }
    }
  }
}

short tree23(const unsigned char* features) {
  if (features[1] < 13) {
    if (features[6] < 1) {
      if (features[8] < 36) {
        if (features[2] < 13) {
          if (features[0] < 8) {
            if (features[8] < 20) {
              if (features[4] < 2) {
                return -11217;
              } else {
                return -4738;
              }
            } else {
              if (features[7] < 17) {
                return -11767;
              } else {
                return -3375;
              }
            }
          } else {
            if (features[4] < 5) {
              if (features[8] < 11) {
                return -22050;
              } else {
                return -4088;
              }
            } else {
              if (features[10] < 4) {
                return -21730;
              } else {
                return -1384;
              }
            }
          }
        } else {
          if (features[1] < 7) {
            return -13280;
          } else {
            if (features[0] < 6) {
              return -27555;
            } else {
              return -14435;
            }
          }
        }
      } else {
        if (features[8] < 42) {
          if (features[10] < 1) {
            if (features[4] < 17) {
              if (features[7] < 7) {
                return -22012;
              } else {
                return -6099;
              }
            } else {
              return -25296;
            }
          } else {
            if (features[0] < 3) {
              return -10742;
            } else {
              return -26164;
            }
          }
        } else {
          return -27614;
        }
      }
    } else {
      if (features[6] < 3) {
        if (features[6] < 2) {
          if (features[1] < 10) {
            if (features[2] < 11) {
              if (features[5] < 10) {
                return -19040;
              } else {
                return -25380;
              }
            } else {
              if (features[7] < 12) {
                return -452;
              } else {
                return -25666;
              }
            }
          } else {
            return -25475;
          }
        } else {
          return -27670;
        }
      } else {
        if (features[8] < 33) {
          if (features[0] < 18) {
            if (features[4] < 3) {
              if (features[8] < 24) {
                return -196;
              } else {
                return -17328;
              }
            } else {
              if (features[7] < 11) {
                return -16189;
              } else {
                return -26915;
              }
            }
          } else {
            if (features[5] < 21) {
              return -2825;
            } else {
              return -18571;
            }
          }
        } else {
          if (features[11] < 5) {
            return -25324;
          } else {
            return -12576;
          }
        }
      }
    }
  } else {
    if (features[0] < 8) {
      if (features[6] < 1) {
        if (features[8] < 35) {
          if (features[5] < 11) {
            if (features[2] < 3) {
              if (features[0] < 5) {
                return -8125;
              } else {
                return -21587;
              }
            } else {
              if (features[9] < 7) {
                return -24608;
              } else {
                return -8281;
              }
            }
          } else {
            if (features[3] < 6) {
              if (features[7] < 7) {
                return 6500;
              } else {
                return -17190;
              }
            } else {
              if (features[2] < 7) {
                return -21219;
              } else {
                return -10134;
              }
            }
          }
        } else {
          return -27709;
        }
      } else {
        if (features[7] < 7) {
          if (features[4] < 6) {
            if (features[3] < 6) {
              return -27214;
            } else {
              if (features[6] < 6) {
                return -12489;
              } else {
                return -24382;
              }
            }
          } else {
            return -25852;
          }
        } else {
          return -27369;
        }
      }
    } else {
      return -27651;
    }
  }
}

short tree24(const unsigned char* features) {
  if (features[6] < 21) {
    if (features[0] < 56) {
      if (features[1] < 85) {
        if (features[6] < 12) {
          if (features[0] < 39) {
            if (features[1] < 83) {
              return -27607;
            } else {
              if (features[2] < 38) {
                return -25068;
              } else {
                return -5802;
              }
            }
          } else {
            if (features[3] < 77) {
              return -25041;
            } else {
              if (features[4] < 59) {
                return -5131;
              } else {
                return -23825;
              }
            }
          }
        } else {
          if (features[10] < 10) {
            if (features[3] < 45) {
              return -25412;
            } else {
              if (features[6] < 15) {
                return -2405;
              } else {
                return -23312;
              }
            }
          } else {
            if (features[0] < 15) {
              if (features[10] < 12) {
                return -6257;
              } else {
                return -24783;
              }
            } else {
              if (features[8] < 68) {
                return -5959;
              } else {
                return -26345;
              }
            }
          }
        }
      } else {
        if (features[1] < 108) {
          if (features[3] < 49) {
            if (features[6] < 3) {
              return -27389;
            } else {
              if (features[0] < 19) {
                return -9367;
              } else {
                return -23799;
              }
            }
          } else {
            if (features[7] < 61) {
              if (features[8] < 98) {
                return -18843;
              } else {
                return -3579;
              }
            } else {
              return 3486;
            }
          }
        } else {
          if (features[10] < 10) {
            return -8896;
          } else {
            return -25115;
          }
        }
      }
    } else {
      if (features[0] < 65) {
        if (features[1] < 90) {
          if (features[6] < 5) {
            if (features[3] < 45) {
              if (features[8] < 47) {
                return -14408;
              } else {
                return -25178;
              }
            } else {
              return -24958;
            }
          } else {
            return 79;
          }
        } else {
          if (features[5] < 19) {
            return -21207;
          } else {
            if (features[5] < 53) {
              if (features[3] < 63) {
                return -2135;
              } else {
                return -14466;
              }
            } else {
              return -25564;
            }
          }
        }
      } else {
        if (features[6] < 2) {
          if (features[8] < 12) {
            return -26124;
          } else {
            if (features[8] < 63) {
              if (features[0] < 66) {
                return -24615;
              } else {
                return -10608;
              }
            } else {
              return -26420;
            }
          }
        } else {
          if (features[0] < 75) {
            if (features[3] < 92) {
              return -9764;
            } else {
              return -25299;
            }
          } else {
            if (features[2] < 5) {
              if (features[4] < 8) {
                return -9442;
              } else {
                return -26442;
              }
            } else {
              return -6200;
            }
          }
        }
      }
    }
  } else {
    if (features[4] < 16) {
      if (features[2] < 10) {
        return -27081;
      } else {
        return -14952;
      }
    } else {
      if (features[6] < 33) {
        if (features[7] < 55) {
          if (features[0] < 19) {
            return -25006;
          } else {
            return -12492;
          }
        } else {
          if (features[8] < 29) {
            if (features[3] < 39) {
              return -26672;
            } else {
              return -10685;
            }
          } else {
            if (features[11] < 29) {
              if (features[3] < 77) {
                return -5287;
              } else {
                return -13799;
              }
            } else {
              return -24331;
            }
          }
        }
      } else {
        return -7181;
      }
    }
  }
}

short tree25(const unsigned char* features) {
  if (features[0] < 28) {
    if (features[6] < 7) {
      if (features[1] < 81) {
        if (features[0] < 22) {
          return -27585;
        } else {
          if (features[8] < 88) {
            if (features[7] < 60) {
              return -25818;
            } else {
              if (features[3] < 14) {
                return -22563;
              } else {
                return -9235;
              }
            }
          } else {
            if (features[2] < 8) {
              return -24083;
            } else {
              if (features[9] < 1) {
                return -23515;
              } else {
                return 5648;
              }
            }
          }
        }
      } else {
        if (features[1] < 125) {
          if (features[7] < 13) {
            return -23861;
          } else {
            if (features[0] < 17) {
              return -23891;
            } else {
              if (features[7] < 43) {
                return -8128;
              } else {
                return -16727;
              }
            }
          }
        } else {
          return -23729;
        }
      }
    } else {
      if (features[4] < 12) {
        if (features[11] < 3) {
          if (features[10] < 19) {
            return -27292;
          } else {
            if (features[7] < 22) {
              return -24583;
            } else {
              return -8548;
            }
          }
        } else {
          if (features[7] < 64) {
            if (features[0] < 19) {
              return -26483;
            } else {
              if (features[6] < 12) {
                return -23624;
              } else {
                return -4058;
              }
            }
          } else {
            return -1988;
          }
        }
      } else {
        if (features[6] < 35) {
          if (features[1] < 50) {
            if (features[6] < 18) {
              if (features[7] < 14) {
                return -24889;
              } else {
                return -16121;
              }
            } else {
              if (features[2] < 12) {
                return -8947;
              } else {
                return -16410;
              }
            }
          } else {
            return -583;
          }
        } else {
          if (features[4] < 20) {
            return -11689;
          } else {
            return -25238;
          }
        }
      }
    }
  } else {
    if (features[0] < 32) {
      if (features[1] < 72) {
        if (features[10] < 15) {
          if (features[5] < 37) {
            if (features[3] < 24) {
              if (features[8] < 42) {
                return -13956;
              } else {
                return -21550;
              }
            } else {
              if (features[10] < 3) {
                return -24066;
              } else {
                return -16198;
              }
            }
          } else {
            return -26789;
          }
        } else {
          return -26774;
        }
      } else {
        if (features[8] < 10) {
          return -18569;
        } else {
          if (features[2] < 39) {
            return -3177;
          } else {
            if (features[1] < 80) {
              if (features[7] < 27) {
                return -1477;
              } else {
                return -19337;
              }
            } else {
              return -23362;
            }
          }
        }
      }
    } else {
      if (features[0] < 75) {
        if (features[0] < 39) {
          if (features[4] < 48) {
            if (features[4] < 15) {
              if (features[2] < 2) {
                return -21836;
              } else {
                return -8689;
              }
            } else {
              if (features[8] < 26) {
                return -10942;
              } else {
                return -16075;
              }
            }
          } else {
            if (features[3] < 15) {
              return 3696;
            } else {
              if (features[1] < 67) {
                return -14978;
              } else {
                return -5774;
              }
            }
          }
        } else {
          if (features[0] < 63) {
            if (features[7] < 4) {
              if (features[6] < 1) {
                return -28435;
              } else {
                return -10512;
              }
            } else {
              if (features[6] < 17) {
                return -8206;
              } else {
                return -16621;
              }
            }
          } else {
            if (features[11] < 5) {
              if (features[2] < 67) {
                return -13412;
              } else {
                return -5171;
              }
            } else {
              if (features[11] < 10) {
                return -27471;
              } else {
                return -15065;
              }
            }
          }
        }
      } else {
        if (features[4] < 18) {
          if (features[0] < 104) {
            if (features[4] < 15) {
              return -20521;
            } else {
              if (features[7] < 21) {
                return -15126;
              } else {
                return 7301;
              }
            }
          } else {
            return -25144;
          }
        } else {
          if (features[7] < 5) {
            return -14791;
          } else {
            return -27360;
          }
        }
      }
    }
  }
}

short tree26(const unsigned char* features) {
  if (features[0] < 19) {
    if (features[6] < 6) {
      if (features[1] < 43) {
        if (features[8] < 110) {
          if (features[4] < 75) {
            if (features[0] < 13) {
              return -27386;
            } else {
              if (features[8] < 82) {
                return -26228;
              } else {
                return -18758;
              }
            }
          } else {
            if (features[5] < 25) {
              if (features[1] < 31) {
                return -26965;
              } else {
                return -14199;
              }
            } else {
              return 2729;
            }
          }
        } else {
          if (features[4] < 17) {
            if (features[10] < 5) {
              return -25826;
            } else {
              return -10495;
            }
          } else {
            return -6132;
          }
        }
      } else {
        if (features[5] < 22) {
          if (features[1] < 55) {
            if (features[8] < 101) {
              if (features[7] < 18) {
                return -18974;
              } else {
                return -26614;
              }
            } else {
              return 625;
            }
          } else {
            if (features[7] < 21) {
              if (features[7] < 7) {
                return -24946;
              } else {
                return -8806;
              }
            } else {
              if (features[7] < 64) {
                return -22942;
              } else {
                return -12586;
              }
            }
          }
        } else {
          if (features[4] < 12) {
            return -24359;
          } else {
            if (features[11] < 4) {
              if (features[10] < 8) {
                return 3758;
              } else {
                return -11401;
              }
            } else {
              return -24582;
            }
          }
        }
      }
    } else {
      if (features[2] < 11) {
        if (features[2] < 3) {
          if (features[10] < 1) {
            if (features[8] < 35) {
              if (features[8] < 10) {
                return -8377;
              } else {
                return -24064;
              }
            } else {
              return 637;
            }
          } else {
            if (features[5] < 8) {
              return -14815;
            } else {
              if (features[10] < 12) {
                return -27624;
              } else {
                return -16687;
              }
            }
          }
        } else {
          if (features[5] < 11) {
            if (features[7] < 6) {
              return -15541;
            } else {
              return -27073;
            }
          } else {
            if (features[3] < 6) {
              if (features[7] < 2) {
                return -18542;
              } else {
                return -2342;
              }
            } else {
              if (features[0] < 10) {
                return -16405;
              } else {
                return -11525;
              }
            }
          }
        }
      } else {
        if (features[5] < 16) {
          return -26254;
        } else {
          return -6269;
        }
      }
    }
  } else {
    if (features[0] < 42) {
      if (features[6] < 18) {
        if (features[0] < 23) {
          if (features[5] < 19) {
            if (features[8] < 91) {
              if (features[6] < 5) {
                return -19313;
              } else {
                return -9461;
              }
            } else {
              if (features[5] < 11) {
                return -14288;
              } else {
                return -1299;
              }
            }
          } else {
            if (features[4] < 10) {
              return -27253;
            } else {
              if (features[10] < 2) {
                return -14813;
              } else {
                return -7580;
              }
            }
          }
        } else {
          if (features[0] < 34) {
            if (features[1] < 24) {
              return -26140;
            } else {
              if (features[6] < 7) {
                return -10543;
              } else {
                return -17759;
              }
            }
          } else {
            if (features[5] < 41) {
              if (features[4] < 15) {
                return -17490;
              } else {
                return -12515;
              }
            } else {
              return -23169;
            }
          }
        }
      } else {
        return -26655;
      }
    } else {
      if (features[0] < 49) {
        if (features[7] < 17) {
          if (features[7] < 13) {
            if (features[6] < 2) {
              if (features[4] < 12) {
                return -5879;
              } else {
                return -21155;
              }
            } else {
              if (features[8] < 12) {
                return -11426;
              } else {
                return -27274;
              }
            }
          } else {
            if (features[8] < 28) {
              if (features[1] < 25) {
                return -25608;
              } else {
                return -9578;
              }
            } else {
              if (features[8] < 56) {
                return 1686;
              } else {
                return -23949;
              }
            }
          }
        } else {
          if (features[5] < 51) {
            return -25925;
          } else {
            return -4086;
          }
        }
      } else {
        if (features[5] < 9) {
          if (features[3] < 8) {
            return -8336;
          } else {
            return -25402;
          }
        } else {
          return -26323;
        }
      }
    }
  }
}

short tree27(const unsigned char* features) {
  if (features[0] < 27) {
    if (features[0] < 10) {
      if (features[6] < 2) {
        if (features[1] < 18) {
          if (features[8] < 49) {
            if (features[4] < 1) {
              if (features[5] < 2) {
                return -6378;
              } else {
                return -21276;
              }
            } else {
              if (features[3] < 26) {
                return -23764;
              } else {
                return -11952;
              }
            }
          } else {
            if (features[5] < 3) {
              return -25232;
            } else {
              if (features[10] < 9) {
                return -14667;
              } else {
                return -1631;
              }
            }
          }
        } else {
          if (features[2] < 30) {
            if (features[8] < 41) {
              if (features[5] < 15) {
                return -15554;
              } else {
                return -20565;
              }
            } else {
              if (features[9] < 2) {
                return -13041;
              } else {
                return -3233;
              }
            }
          } else {
            return 1429;
          }
        }
      } else {
        if (features[1] < 26) {
          if (features[4] < 18) {
            if (features[10] < 1) {
              if (features[6] < 3) {
                return -18422;
              } else {
                return -11335;
              }
            } else {
              if (features[7] < 4) {
                return -15058;
              } else {
                return -8499;
              }
            }
          } else {
            if (features[2] < 31) {
              if (features[8] < 27) {
                return -22441;
              } else {
                return -15108;
              }
            } else {
              if (features[5] < 10) {
                return -17969;
              } else {
                return -4569;
              }
            }
          }
        } else {
          if (features[6] < 11) {
            return -5424;
          } else {
            return -25229;
          }
        }
      }
    } else {
      if (features[8] < 34) {
        if (features[0] < 15) {
          if (features[1] < 30) {
            if (features[6] < 1) {
              if (features[1] < 25) {
                return -20562;
              } else {
                return -14361;
              }
            } else {
              if (features[6] < 13) {
                return -11978;
              } else {
                return -23677;
              }
            }
          } else {
            if (features[1] < 62) {
              if (features[5] < 47) {
                return -6601;
              } else {
                return -23126;
              }
            } else {
              return -18944;
            }
          }
        } else {
          if (features[1] < 74) {
            if (features[0] < 24) {
              if (features[1] < 17) {
                return -14292;
              } else {
                return -9007;
              }
            } else {
              if (features[7] < 20) {
                return -13058;
              } else {
                return -21750;
              }
            }
          } else {
            if (features[0] < 18) {
              if (features[6] < 4) {
                return -19814;
              } else {
                return 2274;
              }
            } else {
              if (features[1] < 135) {
                return -23898;
              } else {
                return -7019;
              }
            }
          }
        }
      } else {
        if (features[6] < 5) {
          if (features[0] < 22) {
            if (features[1] < 23) {
              if (features[4] < 15) {
                return -14758;
              } else {
                return -8610;
              }
            } else {
              if (features[8] < 35) {
                return -5786;
              } else {
                return -7994;
              }
            }
          } else {
            if (features[8] < 69) {
              if (features[10] < 2) {
                return -8642;
              } else {
                return -14983;
              }
            } else {
              if (features[5] < 11) {
                return -9021;
              } else {
                return -20755;
              }
            }
          }
        } else {
          if (features[4] < 10) {
            if (features[0] < 14) {
              if (features[4] < 9) {
                return -11003;
              } else {
                return -24981;
              }
            } else {
              if (features[0] < 20) {
                return -5211;
              } else {
                return -20385;
              }
            }
          } else {
            if (features[3] < 19) {
              if (features[0] < 20) {
                return -4814;
              } else {
                return -27109;
              }
            } else {
              if (features[9] < 3) {
                return -24278;
              } else {
                return -17002;
              }
            }
          }
        }
      }
    }
  } else {
    if (features[10] < 2) {
      if (features[4] < 18) {
        if (features[7] < 35) {
          if (features[2] < 2) {
            if (features[10] < 1) {
              if (features[4] < 11) {
                return 4326;
              } else {
                return -16542;
              }
            } else {
              if (features[8] < 27) {
                return -25449;
              } else {
                return -10956;
              }
            }
          } else {
            if (features[2] < 7) {
              if (features[0] < 29) {
                return -9971;
              } else {
                return -22385;
              }
            } else {
              if (features[8] < 37) {
                return -10202;
              } else {
                return -21803;
              }
            }
          }
        } else {
          if (features[5] < 19) {
            return -25981;
          } else {
            return -8227;
          }
        }
      } else {
        if (features[0] < 32) {
          if (features[1] < 36) {
            if (features[11] < 1) {
              return 4044;
            } else {
              if (features[0] < 28) {
                return -5545;
              } else {
                return -20841;
              }
            }
          } else {
            if (features[5] < 7) {
              return -2159;
            } else {
              return -24277;
            }
          }
        } else {
          if (features[5] < 55) {
            if (features[7] < 6) {
              if (features[2] < 23) {
                return -7845;
              } else {
                return -21741;
              }
            } else {
              if (features[3] < 61) {
                return -26395;
              } else {
                return -16568;
              }
            }
          } else {
            return -6896;
          }
        }
      }
    } else {
      if (features[2] < 14) {
        if (features[6] < 2) {
          if (features[10] < 20) {
            if (features[3] < 23) {
              if (features[3] < 20) {
                return -19104;
              } else {
                return -7602;
              }
            } else {
              if (features[3] < 45) {
                return -25670;
              } else {
                return -13798;
              }
            }
          } else {
            if (features[7] < 16) {
              return -16821;
            } else {
              return 3254;
            }
          }
        } else {
          if (features[7] < 12) {
            return -26888;
          } else {
            if (features[2] < 3) {
              return -7561;
            } else {
              if (features[0] < 117) {
                return -23964;
              } else {
                return -9894;
              }
            }
          }
        }
      } else {
        if (features[6] < 48) {
          if (features[5] < 10) {
            if (features[4] < 26) {
              if (features[2] < 17) {
                return -23288;
              } else {
                return -3311;
              }
            } else {
              return -26343;
            }
          } else {
            return -27450;
          }
        } else {
          if (features[7] < 38) {
            return 35;
          } else {
            return -24816;
          }
        }
      }
    }
  }
}

short tree28(const unsigned char* features) {
  if (features[0] < 16) {
    if (features[1] < 30) {
      if (features[6] < 4) {
        if (features[8] < 77) {
          if (features[6] < 2) {
            if (features[1] < 10) {
              if (features[6] < 1) {
                return -15154;
              } else {
                return -8675;
              }
            } else {
              if (features[1] < 21) {
                return -8471;
              } else {
                return -11144;
              }
            }
          } else {
            if (features[0] < 10) {
              if (features[3] < 32) {
                return -11612;
              } else {
                return -29859;
              }
            } else {
              if (features[7] < 5) {
                return -8099;
              } else {
                return -19405;
              }
            }
          }
        } else {
          if (features[0] < 5) {
            if (features[0] < 3) {
              return -25347;
            } else {
              return -2740;
            }
          } else {
            if (features[4] < 3) {
              if (features[7] < 10) {
                return -6224;
              } else {
                return -26161;
              }
            } else {
              return -27242;
            }
          }
        }
      } else {
        if (features[7] < 10) {
          if (features[2] < 3) {
            if (features[3] < 8) {
              if (features[5] < 20) {
                return -25792;
              } else {
                return -4451;
              }
            } else {
              if (features[8] < 28) {
                return -4602;
              } else {
                return -21981;
              }
            }
          } else {
            if (features[4] < 6) {
              if (features[8] < 6) {
                return -3162;
              } else {
                return -20944;
              }
            } else {
              return -26007;
            }
          }
        } else {
          return -27123;
        }
      }
    } else {
      if (features[0] < 12) {
        if (features[5] < 19) {
          if (features[6] < 2) {
            if (features[5] < 8) {
              if (features[0] < 8) {
                return -10066;
              } else {
                return -27454;
              }
            } else {
              if (features[10] < 7) {
                return -18069;
              } else {
                return -4120;
              }
            }
          } else {
            return -26489;
          }
        } else {
          if (features[10] < 4) {
            if (features[1] < 44) {
              if (features[7] < 7) {
                return -4742;
              } else {
                return -17210;
              }
            } else {
              return 3127;
            }
          } else {
            return -25705;
          }
        }
      } else {
        if (features[4] < 13) {
          if (features[3] < 30) {
            if (features[2] < 7) {
              return -25296;
            } else {
              if (features[1] < 33) {
                return 3909;
              } else {
                return -26755;
              }
            }
          } else {
            if (features[10] < 1) {
              return -19092;
            } else {
              return 3478;
            }
          }
        } else {
          if (features[8] < 19) {
            if (features[5] < 11) {
              return -25160;
            } else {
              if (features[1] < 33) {
                return 1026;
              } else {
                return -22037;
              }
            }
          } else {
            return -27136;
          }
        }
      }
    }
  } else {
    if (features[1] < 24) {
      if (features[4] < 19) {
        if (features[6] < 3) {
          if (features[2] < 2) {
            if (features[5] < 4) {
              if (features[1] < 15) {
                return -4234;
              } else {
                return -19521;
              }
            } else {
              return -24325;
            }
          } else {
            if (features[8] < 37) {
              if (features[1] < 3) {
                return -24830;
              } else {
                return -10276;
              }
            } else {
              if (features[4] < 11) {
                return -3450;
              } else {
                return -28394;
              }
            }
          }
        } else {
          if (features[7] < 10) {
            if (features[8] < 28) {
              return -25466;
            } else {
              return -4244;
            }
          } else {
            return -25529;
          }
        }
      } else {
        if (features[7] < 5) {
          return -13582;
        } else {
          return -27580;
        }
      }
    } else {
      if (features[0] < 17) {
        if (features[4] < 7) {
          if (features[7] < 9) {
            if (features[4] < 3) {
              return -20537;
            } else {
              if (features[8] < 34) {
                return 3702;
              } else {
                return -15197;
              }
            }
          } else {
            if (features[6] < 1) {
              if (features[8] < 47) {
                return -6708;
              } else {
                return -24924;
              }
            } else {
              return -24249;
            }
          }
        } else {
          if (features[6] < 2) {
            if (features[1] < 27) {
              if (features[11] < 1) {
                return -26907;
              } else {
                return -14603;
              }
            } else {
              if (features[3] < 17) {
                return -18994;
              } else {
                return -26585;
              }
            }
          } else {
            return -27506;
          }
        }
      } else {
        if (features[0] < 19) {
          if (features[3] < 15) {
            if (features[11] < 2) {
              if (features[6] < 2) {
                return -22146;
              } else {
                return -27095;
              }
            } else {
              if (features[10] < 2) {
                return -7766;
              } else {
                return -26173;
              }
            }
          } else {
            return -26390;
          }
        } else {
          return -27309;
        }
      }
    }
  }
}

short tree29(const unsigned char* features) {
  if (features[1] < 13) {
    if (features[6] < 1) {
      if (features[8] < 40) {
        if (features[4] < 18) {
          if (features[2] < 3) {
            if (features[1] < 3) {
              if (features[7] < 6) {
                return -31023;
              } else {
                return -13618;
              }
            } else {
              if (features[8] < 33) {
                return -7036;
              } else {
                return -12068;
              }
            }
          } else {
            if (features[8] < 23) {
              if (features[10] < 3) {
                return -11635;
              } else {
                return -4052;
              }
            } else {
              if (features[9] < 1) {
                return -20774;
              } else {
                return -11487;
              }
            }
          }
        } else {
          if (features[7] < 3) {
            return -6722;
          } else {
            if (features[5] < 2) {
              return -5733;
            } else {
              if (features[11] < 3) {
                return -28012;
              } else {
                return -15375;
              }
            }
          }
        }
      } else {
        return -25939;
      }
    } else {
      if (features[6] < 3) {
        if (features[6] < 2) {
          if (features[1] < 10) {
            if (features[5] < 10) {
              if (features[1] < 9) {
                return -19434;
              } else {
                return -7814;
              }
            } else {
              if (features[3] < 28) {
                return -25055;
              } else {
                return -9892;
              }
            }
          } else {
            if (features[0] < 3) {
              if (features[3] < 10) {
                return -6495;
              } else {
                return -23826;
              }
            } else {
              return -25335;
            }
          }
        } else {
          return -27468;
        }
      } else {
        if (features[8] < 33) {
          if (features[2] < 12) {
            if (features[5] < 4) {
              return -20695;
            } else {
              if (features[8] < 5) {
                return -24306;
              } else {
                return -8443;
              }
            }
          } else {
            return -22704;
          }
        } else {
          if (features[11] < 5) {
            return -24787;
          } else {
            return -13627;
          }
        }
      }
    }
  } else {
    if (features[0] < 8) {
      if (features[6] < 1) {
        if (features[8] < 35) {
          if (features[5] < 9) {
            if (features[9] < 7) {
              if (features[2] < 3) {
                return -17308;
              } else {
                return -24867;
              }
            } else {
              if (features[8] < 21) {
                return -841;
              } else {
                return -23365;
              }
            }
          } else {
            if (features[3] < 6) {
              if (features[7] < 7) {
                return 42;
              } else {
                return -16876;
              }
            } else {
              if (features[5] < 16) {
                return -20854;
              } else {
                return -12495;
              }
            }
          }
        } else {
          return -27495;
        }
      } else {
        if (features[7] < 7) {
          if (features[4] < 6) {
            if (features[3] < 6) {
              return -26885;
            } else {
              if (features[10] < 3) {
                return -13438;
              } else {
                return -25937;
              }
            }
          } else {
            if (features[4] < 17) {
              return -26953;
            } else {
              if (features[2] < 6) {
                return -9080;
              } else {
                return -26323;
              }
            }
          }
        } else {
          return -27076;
        }
      }
    } else {
      return -27427;
    }
  }
}

short tree30(const unsigned char* features) {
  if (features[6] < 15) {
    if (features[0] < 56) {
      if (features[1] < 82) {
        if (features[0] < 39) {
          if (features[6] < 8) {
            return -27484;
          } else {
            if (features[3] < 23) {
              return -26452;
            } else {
              if (features[6] < 12) {
                return -23511;
              } else {
                return -11769;
              }
            }
          }
        } else {
          if (features[3] < 77) {
            if (features[6] < 9) {
              return -24782;
            } else {
              if (features[10] < 6) {
                return -23261;
              } else {
                return -5410;
              }
            }
          } else {
            if (features[3] < 85) {
              return -5225;
            } else {
              return -23292;
            }
          }
        }
      } else {
        if (features[1] < 113) {
          if (features[3] < 58) {
            if (features[8] < 98) {
              return -23106;
            } else {
              return -9498;
            }
          } else {
            if (features[8] < 32) {
              return -24685;
            } else {
              if (features[2] < 35) {
                return -24321;
              } else {
                return -3891;
              }
            }
          }
        } else {
          if (features[10] < 8) {
            if (features[7] < 38) {
              if (features[2] < 5) {
                return -15867;
              } else {
                return -3653;
              }
            } else {
              if (features[4] < 15) {
                return -27316;
              } else {
                return -10161;
              }
            }
          } else {
            return -24627;
          }
        }
      }
    } else {
      if (features[0] < 75) {
        if (features[2] < 4) {
          if (features[0] < 68) {
            return -26748;
          } else {
            return -13689;
          }
        } else {
          if (features[0] < 60) {
            if (features[4] < 37) {
              if (features[3] < 49) {
                return -24266;
              } else {
                return -12207;
              }
            } else {
              if (features[5] < 36) {
                return -6705;
              } else {
                return -25785;
              }
            }
          } else {
            if (features[3] < 92) {
              if (features[5] < 44) {
                return -12946;
              } else {
                return -7419;
              }
            } else {
              return -26096;
            }
          }
        }
      } else {
        if (features[4] < 18) {
          if (features[1] < 27) {
            if (features[8] < 9) {
              return -26016;
            } else {
              if (features[7] < 20) {
                return -8617;
              } else {
                return -15153;
              }
            }
          } else {
            return -23842;
          }
        } else {
          if (features[7] < 7) {
            if (features[7] < 4) {
              return -11110;
            } else {
              return -27816;
            }
          } else {
            return -6061;
          }
        }
      }
    }
  } else {
    if (features[6] < 28) {
      if (features[10] < 10) {
        if (features[0] < 54) {
          return -23545;
        } else {
          if (features[10] < 5) {
            return -1536;
          } else {
            return -21168;
          }
        }
      } else {
        if (features[0] < 13) {
          if (features[1] < 23) {
            return -10096;
          } else {
            return -24782;
          }
        } else {
          if (features[7] < 103) {
            return -14861;
          } else {
            if (features[3] < 88) {
              return -3894;
            } else {
              return -21472;
            }
          }
        }
      }
    } else {
      if (features[5] < 12) {
        if (features[4] < 19) {
          if (features[0] < 64) {
            if (features[7] < 59) {
              return -23075;
            } else {
              return -9584;
            }
          } else {
            return -7039;
          }
        } else {
          return -8693;
        }
      } else {
        return -26491;
      }
    }
  }
}

short tree31(const unsigned char* features) {
  if (features[0] < 28) {
    if (features[6] < 7) {
      if (features[1] < 69) {
        if (features[0] < 23) {
          return -27429;
        } else {
          if (features[1] < 58) {
            if (features[7] < 59) {
              return -25590;
            } else {
              if (features[4] < 13) {
                return -7582;
              } else {
                return -25312;
              }
            }
          } else {
            if (features[4] < 41) {
              if (features[8] < 28) {
                return -13573;
              } else {
                return -26532;
              }
            } else {
              return 1568;
            }
          }
        }
      } else {
        if (features[3] < 27) {
          if (features[7] < 43) {
            if (features[9] < 1) {
              if (features[0] < 22) {
                return -26649;
              } else {
                return -11826;
              }
            } else {
              if (features[4] < 18) {
                return -12898;
              } else {
                return -2158;
              }
            }
          } else {
            if (features[2] < 5) {
              return -15258;
            } else {
              return -27169;
            }
          }
        } else {
          if (features[4] < 38) {
            return -25915;
          } else {
            return -11513;
          }
        }
      }
    } else {
      if (features[4] < 11) {
        if (features[0] < 19) {
          return -26596;
        } else {
          if (features[11] < 2) {
            return -24185;
          } else {
            return -4198;
          }
        }
      } else {
        if (features[6] < 48) {
          if (features[1] < 50) {
            if (features[6] < 14) {
              if (features[7] < 21) {
                return -24945;
              } else {
                return -16242;
              }
            } else {
              if (features[6] < 27) {
                return -11884;
              } else {
                return -17613;
              }
            }
          } else {
            return -3350;
          }
        } else {
          return -27084;
        }
      }
    }
  } else {
    if (features[0] < 32) {
      if (features[1] < 72) {
        if (features[10] < 15) {
          if (features[5] < 37) {
            if (features[2] < 26) {
              if (features[4] < 31) {
                return -17841;
              } else {
                return -7538;
              }
            } else {
              if (features[8] < 68) {
                return -23701;
              } else {
                return -7914;
              }
            }
          } else {
            return -26476;
          }
        } else {
          return -26289;
        }
      } else {
        return -9319;
      }
    } else {
      if (features[0] < 75) {
        if (features[0] < 39) {
          if (features[8] < 73) {
            if (features[8] < 9) {
              if (features[4] < 15) {
                return -15363;
              } else {
                return -2689;
              }
            } else {
              if (features[11] < 20) {
                return -14897;
              } else {
                return -8061;
              }
            }
          } else {
            if (features[8] < 82) {
              if (features[3] < 37) {
                return -13209;
              } else {
                return 2332;
              }
            } else {
              if (features[8] < 96) {
                return -16588;
              } else {
                return -7816;
              }
            }
          }
        } else {
          if (features[0] < 58) {
            if (features[6] < 2) {
              if (features[5] < 47) {
                return -11358;
              } else {
                return -27753;
              }
            } else {
              if (features[6] < 21) {
                return -8780;
              } else {
                return -17676;
              }
            }
          } else {
            if (features[5] < 9) {
              return -25056;
            } else {
              if (features[8] < 101) {
                return -12927;
              } else {
                return -21877;
              }
            }
          }
        }
      } else {
        if (features[4] < 18) {
          if (features[0] < 104) {
            if (features[7] < 21) {
              if (features[2] < 5) {
                return -7953;
              } else {
                return -24225;
              }
            } else {
              if (features[10] < 12) {
                return -230;
              } else {
                return -23164;
              }
            }
          } else {
            return -24645;
          }
        } else {
          if (features[7] < 5) {
            return -14693;
          } else {
            return -27100;
          }
        }
      }
    }
  }
}

short tree32(const unsigned char* features) {
  if (features[0] < 19) {
    if (features[6] < 4) {
      if (features[1] < 43) {
        if (features[8] < 82) {
          if (features[4] < 71) {
            if (features[0] < 13) {
              return -27260;
            } else {
              if (features[0] < 18) {
                return -24860;
              } else {
                return -26668;
              }
            }
          } else {
            if (features[8] < 41) {
              return -25147;
            } else {
              if (features[5] < 25) {
                return -19686;
              } else {
                return 5370;
              }
            }
          }
        } else {
          if (features[3] < 29) {
            if (features[8] < 111) {
              if (features[2] < 6) {
                return -27079;
              } else {
                return -17705;
              }
            } else {
              if (features[3] < 8) {
                return -7865;
              } else {
                return -21567;
              }
            }
          } else {
            if (features[4] < 25) {
              if (features[4] < 12) {
                return -5788;
              } else {
                return -20898;
              }
            } else {
              return 9655;
            }
          }
        }
      } else {
        if (features[7] < 9) {
          if (features[8] < 23) {
            if (features[9] < 1) {
              return -9186;
            } else {
              return -23231;
            }
          } else {
            return -26913;
          }
        } else {
          if (features[7] < 17) {
            if (features[3] < 37) {
              if (features[4] < 29) {
                return -12631;
              } else {
                return 288;
              }
            } else {
              return -25566;
            }
          } else {
            if (features[5] < 25) {
              if (features[1] < 53) {
                return -25163;
              } else {
                return -15174;
              }
            } else {
              if (features[4] < 8) {
                return -24224;
              } else {
                return -2042;
              }
            }
          }
        }
      }
    } else {
      if (features[2] < 11) {
        if (features[2] < 3) {
          if (features[10] < 1) {
            if (features[8] < 35) {
              if (features[8] < 7) {
                return -7000;
              } else {
                return -24940;
              }
            } else {
              return -2173;
            }
          } else {
            if (features[6] < 28) {
              if (features[9] < 10) {
                return -24878;
              } else {
                return -12523;
              }
            } else {
              if (features[10] < 14) {
                return -7152;
              } else {
                return -23776;
              }
            }
          }
        } else {
          if (features[5] < 11) {
            if (features[2] < 7) {
              return -25032;
            } else {
              return -10534;
            }
          } else {
            if (features[4] < 11) {
              if (features[8] < 65) {
                return -9661;
              } else {
                return -27037;
              }
            } else {
              if (features[0] < 10) {
                return -20822;
              } else {
                return -13594;
              }
            }
          }
        }
      } else {
        if (features[5] < 16) {
          return -25449;
        } else {
          return -9097;
        }
      }
    }
  } else {
    if (features[0] < 43) {
      if (features[6] < 18) {
        if (features[4] < 16) {
          if (features[0] < 20) {
            if (features[3] < 22) {
              if (features[7] < 5) {
                return -10133;
              } else {
                return -24897;
              }
            } else {
              if (features[8] < 77) {
                return -18102;
              } else {
                return 1260;
              }
            }
          } else {
            if (features[1] < 94) {
              if (features[5] < 59) {
                return -14770;
              } else {
                return -23836;
              }
            } else {
              return -26111;
            }
          }
        } else {
          if (features[7] < 8) {
            if (features[3] < 7) {
              if (features[0] < 30) {
                return -2274;
              } else {
                return -18109;
              }
            } else {
              if (features[0] < 24) {
                return -20177;
              } else {
                return -15417;
              }
            }
          } else {
            if (features[9] < 16) {
              if (features[1] < 69) {
                return -11859;
              } else {
                return -15841;
              }
            } else {
              if (features[0] < 23) {
                return 11486;
              } else {
                return -6245;
              }
            }
          }
        }
      } else {
        return -26267;
      }
    } else {
      if (features[6] < 2) {
        if (features[4] < 15) {
          if (features[5] < 47) {
            if (features[0] < 68) {
              if (features[3] < 11) {
                return -2312;
              } else {
                return -19278;
              }
            } else {
              return -26136;
            }
          } else {
            return 6045;
          }
        } else {
          if (features[8] < 20) {
            if (features[8] < 19) {
              return -21832;
            } else {
              return -135;
            }
          } else {
            if (features[8] < 80) {
              return -26098;
            } else {
              return -12658;
            }
          }
        }
      } else {
        if (features[0] < 49) {
          if (features[8] < 12) {
            if (features[8] < 9) {
              return -23787;
            } else {
              return -4046;
            }
          } else {
            return -23776;
          }
        } else {
          return -26577;
        }
      }
    }
  }
}

short tree33(const unsigned char* features) {
  if (features[0] < 27) {
    if (features[0] < 10) {
      if (features[6] < 2) {
        if (features[1] < 18) {
          if (features[4] < 29) {
            if (features[8] < 54) {
              if (features[4] < 1) {
                return -14561;
              } else {
                return -22850;
              }
            } else {
              if (features[8] < 66) {
                return -16308;
              } else {
                return -9570;
              }
            }
          } else {
            if (features[6] < 1) {
              if (features[2] < 25) {
                return -10310;
              } else {
                return 10242;
              }
            } else {
              if (features[4] < 42) {
                return -25158;
              } else {
                return -6304;
              }
            }
          }
        } else {
          if (features[7] < 10) {
            if (features[8] < 49) {
              if (features[5] < 16) {
                return -16778;
              } else {
                return -23090;
              }
            } else {
              if (features[7] < 9) {
                return -9827;
              } else {
                return -22602;
              }
            }
          } else {
            if (features[5] < 38) {
              if (features[0] < 8) {
                return -15815;
              } else {
                return -10587;
              }
            } else {
              return -28058;
            }
          }
        }
      } else {
        if (features[5] < 12) {
          if (features[8] < 32) {
            if (features[5] < 11) {
              if (features[10] < 1) {
                return -19224;
              } else {
                return -10189;
              }
            } else {
              if (features[2] < 5) {
                return -15247;
              } else {
                return -22264;
              }
            }
          } else {
            if (features[6] < 19) {
              if (features[1] < 14) {
                return -15111;
              } else {
                return -8372;
              }
            } else {
              if (features[4] < 15) {
                return -10883;
              } else {
                return -25313;
              }
            }
          }
        } else {
          if (features[7] < 4) {
            if (features[5] < 23) {
              return -11566;
            } else {
              if (features[1] < 4) {
                return -4684;
              } else {
                return -22820;
              }
            }
          } else {
            if (features[9] < 6) {
              if (features[3] < 13) {
                return -5947;
              } else {
                return -11201;
              }
            } else {
              return -27505;
            }
          }
        }
      }
    } else {
      if (features[8] < 34) {
        if (features[1] < 28) {
          if (features[0] < 17) {
            if (features[6] < 1) {
              if (features[4] < 9) {
                return -21612;
              } else {
                return -16941;
              }
            } else {
              if (features[6] < 13) {
                return -12903;
              } else {
                return -23898;
              }
            }
          } else {
            if (features[11] < 4) {
              if (features[7] < 6) {
                return -13105;
              } else {
                return -9497;
              }
            } else {
              if (features[4] < 17) {
                return -26863;
              } else {
                return -16234;
              }
            }
          }
        } else {
          if (features[1] < 62) {
            if (features[0] < 23) {
              if (features[6] < 5) {
                return -9111;
              } else {
                return -19748;
              }
            } else {
              if (features[3] < 32) {
                return -12036;
              } else {
                return -23217;
              }
            }
          } else {
            if (features[2] < 39) {
              if (features[4] < 9) {
                return -8299;
              } else {
                return -19407;
              }
            } else {
              return -5693;
            }
          }
        }
      } else {
        if (features[6] < 5) {
          if (features[8] < 35) {
            if (features[7] < 16) {
              if (features[1] < 24) {
                return -19235;
              } else {
                return -11197;
              }
            } else {
              if (features[5] < 22) {
                return -6773;
              } else {
                return -17437;
              }
            }
          } else {
            if (features[0] < 22) {
              if (features[8] < 144) {
                return -9965;
              } else {
                return -32768;
              }
            } else {
              if (features[5] < 11) {
                return -9576;
              } else {
                return -15090;
              }
            }
          }
        } else {
          if (features[4] < 15) {
            if (features[0] < 16) {
              if (features[4] < 9) {
                return -12349;
              } else {
                return -22400;
              }
            } else {
              if (features[0] < 20) {
                return -5569;
              } else {
                return -24612;
              }
            }
          } else {
            if (features[1] < 26) {
              if (features[4] < 43) {
                return -20667;
              } else {
                return -9853;
              }
            } else {
              if (features[10] < 16) {
                return -28509;
              } else {
                return -20092;
              }
            }
          }
        }
      }
    }
  } else {
    if (features[10] < 2) {
      if (features[6] < 2) {
        if (features[7] < 8) {
          if (features[5] < 12) {
            if (features[4] < 3) {
              if (features[3] < 6) {
                return -2388;
              } else {
                return -20465;
              }
            } else {
              if (features[2] < 11) {
                return -21206;
              } else {
                return -9320;
              }
            }
          } else {
            if (features[3] < 28) {
              if (features[8] < 24) {
                return -12241;
              } else {
                return 6208;
              }
            } else {
              return -17975;
            }
          }
        } else {
          if (features[8] < 16) {
            if (features[0] < 30) {
              return -23240;
            } else {
              if (features[9] < 1) {
                return -2309;
              } else {
                return -16196;
              }
            }
          } else {
            if (features[0] < 32) {
              if (features[7] < 20) {
                return -14041;
              } else {
                return -25190;
              }
            } else {
              if (features[0] < 115) {
                return -25340;
              } else {
                return -4830;
              }
            }
          }
        }
      } else {
        if (features[0] < 46) {
          if (features[8] < 5) {
            return -4749;
          } else {
            if (features[11] < 1) {
              if (features[6] < 3) {
                return -19066;
              } else {
                return -860;
              }
            } else {
              if (features[0] < 34) {
                return -19070;
              } else {
                return -24673;
              }
            }
          }
        } else {
          if (features[3] < 62) {
            if (features[0] < 74) {
              return -26929;
            } else {
              if (features[7] < 7) {
                return -11795;
              } else {
                return -23240;
              }
            }
          } else {
            return -13786;
          }
        }
      }
    } else {
      if (features[2] < 14) {
        if (features[6] < 2) {
          if (features[10] < 20) {
            if (features[7] < 17) {
              if (features[0] < 32) {
                return -12622;
              } else {
                return -21150;
              }
            } else {
              return -24587;
            }
          } else {
            return -6352;
          }
        } else {
          if (features[7] < 12) {
            return -26573;
          } else {
            if (features[2] < 3) {
              return -8878;
            } else {
              if (features[8] < 30) {
                return -16538;
              } else {
                return -24683;
              }
            }
          }
        }
      } else {
        if (features[6] < 48) {
          if (features[5] < 10) {
            if (features[4] < 26) {
              return -10385;
            } else {
              return -25977;
            }
          } else {
            return -27252;
          }
        } else {
          if (features[7] < 38) {
            return -2719;
          } else {
            return -24172;
          }
        }
      }
    }
  }
}

short tree34(const unsigned char* features) {
  if (features[0] < 17) {
    if (features[1] < 30) {
      if (features[6] < 4) {
        if (features[8] < 51) {
          if (features[4] < 44) {
            if (features[1] < 12) {
              if (features[6] < 1) {
                return -15694;
              } else {
                return -10495;
              }
            } else {
              if (features[1] < 21) {
                return -9449;
              } else {
                return -12385;
              }
            }
          } else {
            if (features[7] < 34) {
              if (features[4] < 49) {
                return -18314;
              } else {
                return -26897;
              }
            } else {
              return -11321;
            }
          }
        } else {
          if (features[0] < 11) {
            if (features[8] < 77) {
              if (features[2] < 1) {
                return -5586;
              } else {
                return -13722;
              }
            } else {
              if (features[4] < 1) {
                return -7014;
              } else {
                return -23351;
              }
            }
          } else {
            if (features[5] < 12) {
              if (features[1] < 23) {
                return -10876;
              } else {
                return -18838;
              }
            } else {
              if (features[6] < 1) {
                return -19003;
              } else {
                return -26578;
              }
            }
          }
        }
      } else {
        if (features[7] < 10) {
          if (features[2] < 3) {
            if (features[4] < 9) {
              if (features[8] < 28) {
                return -14552;
              } else {
                return -24341;
              }
            } else {
              return -4702;
            }
          } else {
            if (features[7] < 6) {
              if (features[8] < 6) {
                return -16596;
              } else {
                return -27678;
              }
            } else {
              if (features[4] < 8) {
                return -9399;
              } else {
                return -24377;
              }
            }
          }
        } else {
          return -26942;
        }
      }
    } else {
      if (features[0] < 12) {
        if (features[5] < 19) {
          if (features[6] < 2) {
            if (features[5] < 8) {
              if (features[0] < 8) {
                return -11581;
              } else {
                return -27188;
              }
            } else {
              if (features[3] < 21) {
                return -19990;
              } else {
                return -11465;
              }
            }
          } else {
            return -26004;
          }
        } else {
          if (features[10] < 4) {
            if (features[8] < 38) {
              if (features[4] < 1) {
                return -17550;
              } else {
                return -1425;
              }
            } else {
              if (features[5] < 27) {
                return -25736;
              } else {
                return -11881;
              }
            }
          } else {
            return -25329;
          }
        }
      } else {
        if (features[6] < 1) {
          if (features[1] < 35) {
            if (features[3] < 17) {
              if (features[0] < 14) {
                return -20368;
              } else {
                return -3125;
              }
            } else {
              if (features[4] < 8) {
                return -10916;
              } else {
                return -26501;
              }
            }
          } else {
            if (features[5] < 20) {
              return -27066;
            } else {
              if (features[4] < 8) {
                return -24850;
              } else {
                return -8934;
              }
            }
          }
        } else {
          return -25849;
        }
      }
    }
  } else {
    if (features[1] < 24) {
      if (features[8] < 37) {
        if (features[5] < 5) {
          if (features[8] < 17) {
            return -8399;
          } else {
            if (features[4] < 11) {
              if (features[1] < 10) {
                return -18597;
              } else {
                return -3677;
              }
            } else {
              if (features[3] < 5) {
                return -9784;
              } else {
                return -23327;
              }
            }
          }
        } else {
          if (features[3] < 6) {
            return -25080;
          } else {
            if (features[1] < 7) {
              return -24899;
            } else {
              if (features[8] < 9) {
                return -24094;
              } else {
                return -12112;
              }
            }
          }
        }
      } else {
        if (features[4] < 11) {
          if (features[1] < 19) {
            return -7465;
          } else {
            return -27309;
          }
        } else {
          return -27783;
        }
      }
    } else {
      if (features[0] < 19) {
        if (features[3] < 15) {
          if (features[6] < 2) {
            if (features[1] < 32) {
              if (features[9] < 2) {
                return -18853;
              } else {
                return -2194;
              }
            } else {
              if (features[5] < 11) {
                return -27473;
              } else {
                return -19698;
              }
            }
          } else {
            return -26862;
          }
        } else {
          if (features[1] < 55) {
            return -26034;
          } else {
            if (features[6] < 1) {
              return -5056;
            } else {
              return -24487;
            }
          }
        }
      } else {
        return -27089;
      }
    }
  }
}

short tree35(const unsigned char* features) {
  if (features[1] < 13) {
    if (features[6] < 1) {
      if (features[8] < 41) {
        if (features[4] < 16) {
          if (features[8] < 22) {
            if (features[10] < 3) {
              if (features[7] < 6) {
                return -14805;
              } else {
                return -9329;
              }
            } else {
              if (features[0] < 6) {
                return -4377;
              } else {
                return -13650;
              }
            }
          } else {
            if (features[2] < 4) {
              if (features[3] < 2) {
                return -22455;
              } else {
                return -10560;
              }
            } else {
              if (features[9] < 1) {
                return -22525;
              } else {
                return -10510;
              }
            }
          }
        } else {
          if (features[7] < 8) {
            if (features[4] < 19) {
              if (features[3] < 14) {
                return -20016;
              } else {
                return -4364;
              }
            } else {
              return -20069;
            }
          } else {
            if (features[11] < 2) {
              if (features[5] < 2) {
                return -12876;
              } else {
                return -23914;
              }
            } else {
              if (features[10] < 1) {
                return -3345;
              } else {
                return -23728;
              }
            }
          }
        }
      } else {
        return -26571;
      }
    } else {
      if (features[6] < 3) {
        if (features[6] < 2) {
          if (features[1] < 10) {
            if (features[0] < 6) {
              if (features[8] < 12) {
                return -23663;
              } else {
                return -14485;
              }
            } else {
              return -24836;
            }
          } else {
            return -24308;
          }
        } else {
          return -27306;
        }
      } else {
        if (features[3] < 22) {
          if (features[5] < 7) {
            if (features[7] < 4) {
              return -25704;
            } else {
              if (features[3] < 6) {
                return -7985;
              } else {
                return -17680;
              }
            }
          } else {
            if (features[7] < 3) {
              return -14509;
            } else {
              return -27050;
            }
          }
        } else {
          if (features[8] < 16) {
            return -3442;
          } else {
            return -23815;
          }
        }
      }
    }
  } else {
    if (features[0] < 8) {
      if (features[6] < 1) {
        if (features[8] < 35) {
          if (features[5] < 9) {
            if (features[0] < 3) {
              return -8143;
            } else {
              if (features[2] < 1) {
                return -7721;
              } else {
                return -23001;
              }
            }
          } else {
            if (features[8] < 7) {
              if (features[2] < 7) {
                return 7745;
              } else {
                return -15392;
              }
            } else {
              if (features[3] < 6) {
                return -7757;
              } else {
                return -17409;
              }
            }
          }
        } else {
          return -27312;
        }
      } else {
        if (features[7] < 7) {
          if (features[8] < 22) {
            if (features[4] < 5) {
              if (features[8] < 15) {
                return -18863;
              } else {
                return -5226;
              }
            } else {
              if (features[4] < 17) {
                return -26216;
              } else {
                return -14035;
              }
            }
          } else {
            if (features[7] < 3) {
              if (features[2] < 4) {
                return -23761;
              } else {
                return -5458;
              }
            } else {
              return -26711;
            }
          }
        } else {
          return -26805;
        }
      }
    } else {
      if (features[1] < 17) {
        if (features[11] < 15) {
          return -25285;
        } else {
          return -8862;
        }
      } else {
        return -27329;
      }
    }
  }
}

short tree36(const unsigned char* features) {
  if (features[0] < 52) {
    if (features[6] < 15) {
      if (features[1] < 79) {
        if (features[6] < 8) {
          if (features[0] < 41) {
            return -27364;
          } else {
            if (features[8] < 9) {
              return -10903;
            } else {
              return -24307;
            }
          }
        } else {
          if (features[3] < 23) {
            return -26217;
          } else {
            if (features[8] < 30) {
              if (features[2] < 7) {
                return 5166;
              } else {
                return -16163;
              }
            } else {
              if (features[6] < 12) {
                return -26535;
              } else {
                return -13852;
              }
            }
          }
        }
      } else {
        if (features[1] < 113) {
          if (features[3] < 42) {
            return -23922;
          } else {
            if (features[8] < 93) {
              if (features[7] < 32) {
                return -23463;
              } else {
                return -7708;
              }
            } else {
              if (features[10] < 4) {
                return 8317;
              } else {
                return -18045;
              }
            }
          }
        } else {
          if (features[10] < 8) {
            return -10217;
          } else {
            return -24182;
          }
        }
      }
    } else {
      if (features[2] < 6) {
        return -27549;
      } else {
        if (features[5] < 12) {
          if (features[6] < 33) {
            if (features[0] < 27) {
              if (features[3] < 24) {
                return -21348;
              } else {
                return -14321;
              }
            } else {
              if (features[3] < 12) {
                return -20922;
              } else {
                return -5399;
              }
            }
          } else {
            if (features[10] < 9) {
              if (features[4] < 50) {
                return -16221;
              } else {
                return -7493;
              }
            } else {
              if (features[8] < 69) {
                return -8756;
              } else {
                return -17557;
              }
            }
          }
        } else {
          return -27150;
        }
      }
    }
  } else {
    if (features[0] < 65) {
      if (features[1] < 90) {
        if (features[6] < 5) {
          if (features[0] < 61) {
            if (features[2] < 49) {
              if (features[4] < 16) {
                return -17701;
              } else {
                return -25945;
              }
            } else {
              if (features[4] < 85) {
                return -5836;
              } else {
                return -25665;
              }
            }
          } else {
            if (features[3] < 50) {
              if (features[4] < 13) {
                return -22560;
              } else {
                return -11671;
              }
            } else {
              return -26260;
            }
          }
        } else {
          if (features[8] < 50) {
            if (features[10] < 4) {
              return 1353;
            } else {
              return -13383;
            }
          } else {
            return -23309;
          }
        }
      } else {
        if (features[5] < 53) {
          if (features[5] < 19) {
            if (features[6] < 3) {
              return -26011;
            } else {
              return -9933;
            }
          } else {
            if (features[10] < 16) {
              if (features[0] < 63) {
                return -3872;
              } else {
                return -15343;
              }
            } else {
              if (features[0] < 62) {
                return -26031;
              } else {
                return -6744;
              }
            }
          }
        } else {
          return -26074;
        }
      }
    } else {
      if (features[6] < 2) {
        if (features[10] < 8) {
          if (features[0] < 71) {
            return -25074;
          } else {
            if (features[5] < 23) {
              if (features[0] < 104) {
                return -21685;
              } else {
                return -13256;
              }
            } else {
              return -7969;
            }
          }
        } else {
          return -6362;
        }
      } else {
        if (features[0] < 75) {
          if (features[3] < 15) {
            return -8533;
          } else {
            if (features[3] < 26) {
              if (features[0] < 66) {
                return -8460;
              } else {
                return -23995;
              }
            } else {
              if (features[3] < 33) {
                return -6334;
              } else {
                return -13656;
              }
            }
          }
        } else {
          return -9039;
        }
      }
    }
  }
}

short tree37(const unsigned char* features) {
  if (features[0] < 28) {
    if (features[6] < 7) {
      if (features[1] < 63) {
        if (features[0] < 22) {
          return -27327;
        } else {
          if (features[7] < 59) {
            return -25191;
          } else {
            return -15179;
          }
        }
      } else {
        if (features[1] < 81) {
          if (features[4] < 36) {
            if (features[8] < 8) {
              return -12621;
            } else {
              if (features[7] < 14) {
                return -18963;
              } else {
                return -27501;
              }
            }
          } else {
            if (features[2] < 25) {
              return 4888;
            } else {
              return -25634;
            }
          }
        } else {
          if (features[7] < 13) {
            return -23734;
          } else {
            if (features[1] < 117) {
              return -12228;
            } else {
              if (features[8] < 9) {
                return -11229;
              } else {
                return -24284;
              }
            }
          }
        }
      }
    } else {
      if (features[4] < 12) {
        if (features[11] < 2) {
          if (features[10] < 25) {
            return -26805;
          } else {
            return -16033;
          }
        } else {
          if (features[7] < 54) {
            return -22933;
          } else {
            return -7067;
          }
        }
      } else {
        if (features[6] < 48) {
          if (features[1] < 50) {
            if (features[6] < 18) {
              if (features[10] < 17) {
                return -20904;
              } else {
                return -12748;
              }
            } else {
              if (features[10] < 2) {
                return -6079;
              } else {
                return -15037;
              }
            }
          } else {
            return -5281;
          }
        } else {
          return -26851;
        }
      }
    }
  } else {
    if (features[0] < 32) {
      if (features[1] < 72) {
        if (features[3] < 34) {
          if (features[2] < 30) {
            if (features[4] < 31) {
              if (features[4] < 27) {
                return -16448;
              } else {
                return -26529;
              }
            } else {
              if (features[2] < 26) {
                return -2357;
              } else {
                return -24132;
              }
            }
          } else {
            return -24759;
          }
        } else {
          if (features[8] < 96) {
            if (features[3] < 53) {
              return -26525;
            } else {
              if (features[6] < 23) {
                return -14556;
              } else {
                return -25659;
              }
            }
          } else {
            if (features[8] < 105) {
              return 89;
            } else {
              return -24146;
            }
          }
        }
      } else {
        return -10956;
      }
    } else {
      if (features[0] < 75) {
        if (features[6] < 1) {
          if (features[7] < 4) {
            return -26945;
          } else {
            if (features[10] < 2) {
              if (features[0] < 44) {
                return -20239;
              } else {
                return -11320;
              }
            } else {
              if (features[8] < 42) {
                return -8203;
              } else {
                return -18363;
              }
            }
          }
        } else {
          if (features[6] < 58) {
            if (features[1] < 22) {
              return -27494;
            } else {
              if (features[2] < 103) {
                return -12355;
              } else {
                return -22400;
              }
            }
          } else {
            return -26045;
          }
        }
      } else {
        if (features[4] < 18) {
          if (features[0] < 94) {
            if (features[8] < 34) {
              return -20297;
            } else {
              if (features[8] < 46) {
                return -490;
              } else {
                return -19127;
              }
            }
          } else {
            if (features[6] < 1) {
              if (features[8] < 17) {
                return -8759;
              } else {
                return -22290;
              }
            } else {
              return -26367;
            }
          }
        } else {
          if (features[7] < 5) {
            return -14995;
          } else {
            return -26835;
          }
        }
      }
    }
  }
}

short tree38(const unsigned char* features) {
  if (features[0] < 19) {
    if (features[6] < 4) {
      if (features[1] < 43) {
        if (features[8] < 82) {
          if (features[4] < 71) {
            if (features[0] < 13) {
              if (features[1] < 40) {
                return -27129;
              } else {
                return -17994;
              }
            } else {
              if (features[2] < 11) {
                return -24368;
              } else {
                return -26427;
              }
            }
          } else {
            if (features[8] < 41) {
              return -24609;
            } else {
              if (features[5] < 25) {
                return -19230;
              } else {
                return 1341;
              }
            }
          }
        } else {
          if (features[3] < 29) {
            if (features[8] < 111) {
              if (features[2] < 6) {
                return -26836;
              } else {
                return -17202;
              }
            } else {
              if (features[3] < 8) {
                return -9227;
              } else {
                return -21032;
              }
            }
          } else {
            if (features[4] < 25) {
              if (features[2] < 9) {
                return -10217;
              } else {
                return -24865;
              }
            } else {
              return 5441;
            }
          }
        }
      } else {
        if (features[8] < 94) {
          if (features[10] < 1) {
            return -25262;
          } else {
            if (features[5] < 22) {
              if (features[1] < 53) {
                return -20992;
              } else {
                return -14489;
              }
            } else {
              if (features[4] < 16) {
                return -18510;
              } else {
                return -4901;
              }
            }
          }
        } else {
          return 1890;
        }
      }
    } else {
      if (features[2] < 11) {
        if (features[2] < 5) {
          if (features[10] < 4) {
            if (features[0] < 3) {
              return -4829;
            } else {
              if (features[4] < 12) {
                return -18895;
              } else {
                return -26614;
              }
            }
          } else {
            if (features[7] < 43) {
              if (features[6] < 28) {
                return -20087;
              } else {
                return -9589;
              }
            } else {
              if (features[9] < 5) {
                return -6441;
              } else {
                return -22346;
              }
            }
          }
        } else {
          if (features[3] < 10) {
            if (features[8] < 37) {
              return -8694;
            } else {
              return -23441;
            }
          } else {
            if (features[4] < 1) {
              return -6611;
            } else {
              if (features[0] < 11) {
                return -20190;
              } else {
                return -14628;
              }
            }
          }
        }
      } else {
        if (features[5] < 16) {
          return -24958;
        } else {
          return -10366;
        }
      }
    }
  } else {
    if (features[0] < 46) {
      if (features[6] < 18) {
        if (features[4] < 16) {
          if (features[8] < 97) {
            if (features[0] < 26) {
              if (features[1] < 29) {
                return -15886;
              } else {
                return -20188;
              }
            } else {
              if (features[0] < 31) {
                return -12867;
              } else {
                return -17189;
              }
            }
          } else {
            if (features[5] < 11) {
              if (features[3] < 23) {
                return -20309;
              } else {
                return -7749;
              }
            } else {
              if (features[9] < 1) {
                return 1824;
              } else {
                return -12844;
              }
            }
          }
        } else {
          if (features[0] < 38) {
            if (features[5] < 21) {
              if (features[10] < 1) {
                return -17483;
              } else {
                return -13640;
              }
            } else {
              if (features[1] < 74) {
                return -11002;
              } else {
                return -18113;
              }
            }
          } else {
            if (features[5] < 26) {
              if (features[7] < 10) {
                return -20281;
              } else {
                return -12808;
              }
            } else {
              if (features[3] < 41) {
                return -19290;
              } else {
                return -25998;
              }
            }
          }
        }
      } else {
        return -25924;
      }
    } else {
      if (features[6] < 2) {
        if (features[5] < 47) {
          if (features[7] < 14) {
            if (features[8] < 24) {
              if (features[8] < 17) {
                return -22763;
              } else {
                return -4325;
              }
            } else {
              if (features[3] < 3) {
                return -10719;
              } else {
                return -24280;
              }
            }
          } else {
            return -25660;
          }
        } else {
          return -7109;
        }
      } else {
        return -25840;
      }
    }
  }
}

short tree39(const unsigned char* features) {
  if (features[0] < 26) {
    if (features[1] < 19) {
      if (features[6] < 2) {
        if (features[2] < 30) {
          if (features[8] < 55) {
            if (features[0] < 15) {
              if (features[4] < 1) {
                return -15669;
              } else {
                return -21548;
              }
            } else {
              if (features[7] < 6) {
                return -20381;
              } else {
                return -11242;
              }
            }
          } else {
            if (features[5] < 23) {
              if (features[10] < 5) {
                return -16848;
              } else {
                return -6571;
              }
            } else {
              if (features[7] < 16) {
                return -4937;
              } else {
                return -20636;
              }
            }
          }
        } else {
          if (features[3] < 5) {
            return -22319;
          } else {
            if (features[10] < 1) {
              if (features[4] < 37) {
                return -22173;
              } else {
                return -4482;
              }
            } else {
              if (features[7] < 6) {
                return -11052;
              } else {
                return 9610;
              }
            }
          }
        }
      } else {
        if (features[5] < 12) {
          if (features[5] < 5) {
            if (features[0] < 7) {
              if (features[7] < 7) {
                return -5486;
              } else {
                return -14518;
              }
            } else {
              if (features[7] < 14) {
                return -17608;
              } else {
                return -10179;
              }
            }
          } else {
            if (features[0] < 9) {
              if (features[8] < 50) {
                return -21348;
              } else {
                return -3900;
              }
            } else {
              if (features[7] < 15) {
                return -17654;
              } else {
                return -8854;
              }
            }
          }
        } else {
          if (features[7] < 8) {
            if (features[0] < 12) {
              if (features[5] < 28) {
                return -10567;
              } else {
                return -19910;
              }
            } else {
              return -26830;
            }
          } else {
            if (features[4] < 8) {
              if (features[9] < 1) {
                return -1737;
              } else {
                return -17389;
              }
            } else {
              return -10755;
            }
          }
        }
      }
    } else {
      if (features[0] < 15) {
        if (features[1] < 26) {
          if (features[8] < 39) {
            if (features[6] < 1) {
              if (features[3] < 3) {
                return -3660;
              } else {
                return -19478;
              }
            } else {
              if (features[11] < 1) {
                return -10131;
              } else {
                return -16020;
              }
            }
          } else {
            if (features[10] < 16) {
              if (features[10] < 8) {
                return -12577;
              } else {
                return -4972;
              }
            } else {
              if (features[2] < 7) {
                return -13102;
              } else {
                return -25508;
              }
            }
          }
        } else {
          if (features[6] < 6) {
            if (features[4] < 3) {
              if (features[3] < 21) {
                return -10689;
              } else {
                return -19804;
              }
            } else {
              if (features[1] < 92) {
                return -10573;
              } else {
                return -28338;
              }
            }
          } else {
            if (features[4] < 8) {
              return -10315;
            } else {
              return -26817;
            }
          }
        }
      } else {
        if (features[0] < 20) {
          if (features[0] < 18) {
            if (features[6] < 12) {
              if (features[1] < 25) {
                return -13194;
              } else {
                return -10247;
              }
            } else {
              if (features[4] < 39) {
                return -24963;
              } else {
                return -5519;
              }
            }
          } else {
            if (features[1] < 44) {
              if (features[3] < 75) {
                return -8446;
              } else {
                return -28633;
              }
            } else {
              if (features[5] < 24) {
                return -13074;
              } else {
                return -25186;
              }
            }
          }
        } else {
          if (features[7] < 57) {
            if (features[8] < 89) {
              if (features[6] < 6) {
                return -12786;
              } else {
                return -22207;
              }
            } else {
              if (features[5] < 11) {
                return -14185;
              } else {
                return -25559;
              }
            }
          } else {
            if (features[3] < 6) {
              return -9795;
            } else {
              if (features[11] < 22) {
                return -24457;
              } else {
                return -13817;
              }
            }
          }
        }
      }
    }
  } else {
    if (features[2] < 14) {
      if (features[0] < 35) {
        if (features[6] < 4) {
          if (features[3] < 44) {
            if (features[3] < 36) {
              if (features[7] < 12) {
                return -17775;
              } else {
                return -13803;
              }
            } else {
              return -25279;
            }
          } else {
            if (features[5] < 12) {
              if (features[3] < 55) {
                return -7414;
              } else {
                return -26070;
              }
            } else {
              if (features[2] < 8) {
                return -19074;
              } else {
                return 16798;
              }
            }
          }
        } else {
          if (features[9] < 1) {
            if (features[4] < 22) {
              if (features[4] < 10) {
                return -14335;
              } else {
                return -26397;
              }
            } else {
              if (features[5] < 7) {
                return -308;
              } else {
                return -19947;
              }
            }
          } else {
            return -25539;
          }
        }
      } else {
        if (features[0] < 199) {
          if (features[7] < 4) {
            if (features[2] < 10) {
              if (features[4] < 3) {
                return -8747;
              } else {
                return -23365;
              }
            } else {
              return 8675;
            }
          } else {
            if (features[8] < 37) {
              if (features[4] < 18) {
                return -18399;
              } else {
                return -25762;
              }
            } else {
              if (features[7] < 91) {
                return -25780;
              } else {
                return -5863;
              }
            }
          }
        } else {
          return -6882;
        }
      }
    } else {
      if (features[10] < 2) {
        if (features[7] < 7) {
          if (features[0] < 74) {
            if (features[1] < 25) {
              if (features[0] < 53) {
                return -10254;
              } else {
                return -23033;
              }
            } else {
              return -25909;
            }
          } else {
            if (features[0] < 102) {
              return 2586;
            } else {
              return -23290;
            }
          }
        } else {
          if (features[2] < 129) {
            if (features[3] < 61) {
              if (features[4] < 20) {
                return -17519;
              } else {
                return -24346;
              }
            } else {
              if (features[2] < 48) {
                return -5320;
              } else {
                return -24516;
              }
            }
          } else {
            return -226;
          }
        }
      } else {
        if (features[6] < 48) {
          if (features[5] < 10) {
            if (features[10] < 6) {
              if (features[2] < 24) {
                return -9579;
              } else {
                return -24288;
              }
            } else {
              return -26060;
            }
          } else {
            return -26992;
          }
        } else {
          if (features[7] < 38) {
            return -5248;
          } else {
            return -23887;
          }
        }
      }
    }
  }
}

short tree40(const unsigned char* features) {
  if (features[0] < 17) {
    if (features[6] < 3) {
      if (features[1] < 31) {
        if (features[8] < 46) {
          if (features[4] < 49) {
            if (features[1] < 12) {
              if (features[6] < 1) {
                return -16197;
              } else {
                return -11418;
              }
            } else {
              if (features[1] < 23) {
                return -10893;
              } else {
                return -13253;
              }
            }
          } else {
            if (features[7] < 34) {
              return -27268;
            } else {
              return -11648;
            }
          }
        } else {
          if (features[4] < 17) {
            if (features[5] < 10) {
              if (features[8] < 76) {
                return -10331;
              } else {
                return -22440;
              }
            } else {
              if (features[10] < 16) {
                return -16630;
              } else {
                return -5566;
              }
            }
          } else {
            if (features[0] < 11) {
              if (features[5] < 11) {
                return -27198;
              } else {
                return -14313;
              }
            } else {
              if (features[2] < 1) {
                return -9863;
              } else {
                return -25514;
              }
            }
          }
        }
      } else {
        if (features[6] < 1) {
          if (features[5] < 19) {
            if (features[10] < 26) {
              if (features[1] < 34) {
                return -15321;
              } else {
                return -22243;
              }
            } else {
              return -3717;
            }
          } else {
            if (features[11] < 1) {
              return -24303;
            } else {
              if (features[5] < 37) {
                return -4597;
              } else {
                return -18589;
              }
            }
          }
        } else {
          if (features[7] < 11) {
            if (features[8] < 51) {
              if (features[5] < 8) {
                return -26348;
              } else {
                return -15219;
              }
            } else {
              return -26779;
            }
          } else {
            return -25921;
          }
        }
      }
    } else {
      if (features[7] < 10) {
        if (features[6] < 10) {
          if (features[1] < 10) {
            return -25116;
          } else {
            if (features[9] < 1) {
              if (features[8] < 24) {
                return -23231;
              } else {
                return -12818;
              }
            } else {
              if (features[10] < 2) {
                return -9511;
              } else {
                return -18380;
              }
            }
          }
        } else {
          if (features[8] < 6) {
            if (features[0] < 5) {
              return -8741;
            } else {
              return -21627;
            }
          } else {
            return -24838;
          }
        }
      } else {
        if (features[5] < 9) {
          if (features[9] < 2) {
            if (features[8] < 14) {
              return -27016;
            } else {
              if (features[5] < 4) {
                return -26137;
              } else {
                return -14422;
              }
            }
          } else {
            return -32;
          }
        } else {
          return -25755;
        }
      }
    }
  } else {
    if (features[1] < 24) {
      if (features[8] < 37) {
        if (features[5] < 5) {
          if (features[2] < 8) {
            if (features[6] < 2) {
              return -8928;
            } else {
              if (features[7] < 13) {
                return -17051;
              } else {
                return -3982;
              }
            }
          } else {
            return -21036;
          }
        } else {
          if (features[3] < 6) {
            return -24472;
          } else {
            if (features[1] < 7) {
              return -24310;
            } else {
              if (features[5] < 13) {
                return -11868;
              } else {
                return -18805;
              }
            }
          }
        }
      } else {
        if (features[4] < 11) {
          if (features[1] < 19) {
            return -9186;
          } else {
            return -26727;
          }
        } else {
          return -27373;
        }
      }
    } else {
      if (features[0] < 19) {
        if (features[3] < 15) {
          if (features[1] < 36) {
            if (features[6] < 2) {
              if (features[7] < 11) {
                return -20567;
              } else {
                return -12162;
              }
            } else {
              return -26430;
            }
          } else {
            return -27248;
          }
        } else {
          if (features[11] < 1) {
            return -27130;
          } else {
            if (features[10] < 1) {
              if (features[3] < 27) {
                return -21950;
              } else {
                return -7704;
              }
            } else {
              return -24891;
            }
          }
        }
      } else {
        return -26884;
      }
    }
  }
}

short tree41(const unsigned char* features) {
  if (features[1] < 14) {
    if (features[6] < 1) {
      if (features[8] < 41) {
        if (features[2] < 3) {
          if (features[1] < 3) {
            if (features[7] < 6) {
              return -29724;
            } else {
              return -14899;
            }
          } else {
            if (features[3] < 20) {
              if (features[8] < 22) {
                return -8399;
              } else {
                return -12058;
              }
            } else {
              if (features[7] < 14) {
                return -24750;
              } else {
                return -7895;
              }
            }
          }
        } else {
          if (features[3] < 1) {
            if (features[1] < 9) {
              return -4939;
            } else {
              return -23724;
            }
          } else {
            if (features[8] < 27) {
              if (features[2] < 13) {
                return -13623;
              } else {
                return -22439;
              }
            } else {
              if (features[9] < 1) {
                return -23238;
              } else {
                return -15837;
              }
            }
          }
        }
      } else {
        return -26418;
      }
    } else {
      if (features[1] < 10) {
        if (features[11] < 2) {
          if (features[8] < 31) {
            if (features[8] < 12) {
              if (features[7] < 5) {
                return -17943;
              } else {
                return -25771;
              }
            } else {
              if (features[4] < 7) {
                return -10207;
              } else {
                return -19307;
              }
            }
          } else {
            return -26082;
          }
        } else {
          if (features[10] < 2) {
            return -5521;
          } else {
            return -23568;
          }
        }
      } else {
        return -24292;
      }
    }
  } else {
    if (features[0] < 7) {
      if (features[7] < 5) {
        if (features[6] < 2) {
          if (features[2] < 7) {
            if (features[8] < 14) {
              return 2371;
            } else {
              if (features[0] < 5) {
                return -1624;
              } else {
                return -16350;
              }
            }
          } else {
            return -24017;
          }
        } else {
          if (features[5] < 29) {
            if (features[4] < 11) {
              return -25813;
            } else {
              return -7067;
            }
          } else {
            return -8126;
          }
        }
      } else {
        if (features[6] < 1) {
          if (features[5] < 13) {
            if (features[9] < 5) {
              if (features[8] < 8) {
                return -6944;
              } else {
                return -22815;
              }
            } else {
              return -5682;
            }
          } else {
            if (features[2] < 7) {
              if (features[1] < 17) {
                return -12372;
              } else {
                return -27414;
              }
            } else {
              if (features[1] < 23) {
                return -20848;
              } else {
                return 525;
              }
            }
          }
        } else {
          if (features[4] < 4) {
            if (features[3] < 9) {
              return -26212;
            } else {
              if (features[4] < 3) {
                return -19328;
              } else {
                return -838;
              }
            }
          } else {
            return -26581;
          }
        }
      }
    } else {
      if (features[0] < 9) {
        if (features[4] < 5) {
          if (features[8] < 35) {
            if (features[7] < 5) {
              if (features[2] < 3) {
                return -2694;
              } else {
                return -19503;
              }
            } else {
              if (features[8] < 34) {
                return -24176;
              } else {
                return -11796;
              }
            }
          } else {
            return -26829;
          }
        } else {
          return -26047;
        }
      } else {
        return -27154;
      }
    }
  }
}

short tree42(const unsigned char* features) {
  if (features[0] < 52) {
    if (features[6] < 15) {
      if (features[1] < 79) {
        if (features[6] < 8) {
          if (features[0] < 41) {
            return -27263;
          } else {
            if (features[10] < 15) {
              return -24040;
            } else {
              if (features[8] < 33) {
                return -2341;
              } else {
                return -24197;
              }
            }
          }
        } else {
          if (features[3] < 23) {
            return -25918;
          } else {
            if (features[8] < 30) {
              return -4939;
            } else {
              if (features[6] < 12) {
                return -26281;
              } else {
                return -14361;
              }
            }
          }
        }
      } else {
        if (features[1] < 107) {
          if (features[8] < 39) {
            return -24858;
          } else {
            if (features[11] < 1) {
              return -24944;
            } else {
              if (features[0] < 35) {
                return -18641;
              } else {
                return -8639;
              }
            }
          }
        } else {
          return -12667;
        }
      }
    } else {
      if (features[2] < 6) {
        return -27288;
      } else {
        if (features[5] < 12) {
          if (features[6] < 33) {
            if (features[8] < 6) {
              return -26647;
            } else {
              if (features[0] < 13) {
                return -19278;
              } else {
                return -12824;
              }
            }
          } else {
            return -10742;
          }
        } else {
          return -26797;
        }
      }
    }
  } else {
    if (features[0] < 65) {
      if (features[1] < 90) {
        if (features[6] < 5) {
          if (features[0] < 61) {
            if (features[2] < 49) {
              if (features[4] < 16) {
                return -17348;
              } else {
                return -25514;
              }
            } else {
              if (features[4] < 85) {
                return -8149;
              } else {
                return -25269;
              }
            }
          } else {
            if (features[8] < 47) {
              if (features[8] < 36) {
                return -18113;
              } else {
                return -4332;
              }
            } else {
              return -23979;
            }
          }
        } else {
          if (features[8] < 50) {
            if (features[10] < 4) {
              return -526;
            } else {
              return -13860;
            }
          } else {
            return -23124;
          }
        }
      } else {
        if (features[5] < 53) {
          return -10816;
        } else {
          return -25624;
        }
      }
    } else {
      if (features[10] < 9) {
        if (features[6] < 2) {
          if (features[5] < 23) {
            if (features[0] < 94) {
              if (features[7] < 29) {
                return -27193;
              } else {
                return -14104;
              }
            } else {
              if (features[7] < 18) {
                return -12400;
              } else {
                return -25566;
              }
            }
          } else {
            return -11616;
          }
        } else {
          return -12644;
        }
      } else {
        return -10017;
      }
    }
  }
}

short tree43(const unsigned char* features) {
  if (features[0] < 28) {
    if (features[6] < 7) {
      if (features[1] < 63) {
        if (features[0] < 22) {
          return -27218;
        } else {
          if (features[7] < 59) {
            return -24747;
          } else {
            return -15773;
          }
        }
      } else {
        if (features[1] < 94) {
          if (features[8] < 72) {
            if (features[3] < 4) {
              return -10414;
            } else {
              return -21478;
            }
          } else {
            if (features[2] < 12) {
              return -18316;
            } else {
              return 292;
            }
          }
        } else {
          if (features[7] < 94) {
            if (features[0] < 18) {
              return -24812;
            } else {
              if (features[8] < 31) {
                return -8651;
              } else {
                return -19156;
              }
            }
          } else {
            return -24925;
          }
        }
      }
    } else {
      if (features[4] < 12) {
        if (features[11] < 2) {
          return -25663;
        } else {
          if (features[7] < 54) {
            return -22447;
          } else {
            return -8717;
          }
        }
      } else {
        if (features[6] < 48) {
          if (features[8] < 3) {
            return -4703;
          } else {
            if (features[1] < 50) {
              if (features[10] < 44) {
                return -16803;
              } else {
                return -9693;
              }
            } else {
              return -6614;
            }
          }
        } else {
          return -26619;
        }
      }
    }
  } else {
    if (features[0] < 35) {
      if (features[1] < 64) {
        if (features[5] < 13) {
          if (features[8] < 42) {
            if (features[8] < 41) {
              if (features[1] < 41) {
                return -16370;
              } else {
                return -10511;
              }
            } else {
              return 870;
            }
          } else {
            if (features[0] < 30) {
              return -27386;
            } else {
              if (features[7] < 26) {
                return -21089;
              } else {
                return -12887;
              }
            }
          }
        } else {
          if (features[6] < 15) {
            if (features[8] < 9) {
              if (features[8] < 8) {
                return -19943;
              } else {
                return 778;
              }
            } else {
              if (features[2] < 5) {
                return -13574;
              } else {
                return -22100;
              }
            }
          } else {
            return -6105;
          }
        }
      } else {
        if (features[4] < 54) {
          if (features[4] < 41) {
            if (features[3] < 25) {
              if (features[4] < 18) {
                return -13055;
              } else {
                return -26056;
              }
            } else {
              if (features[2] < 13) {
                return -20441;
              } else {
                return -8233;
              }
            }
          } else {
            if (features[8] < 58) {
              return -29279;
            } else {
              return -9672;
            }
          }
        } else {
          return -3842;
        }
      }
    } else {
      if (features[0] < 65) {
        if (features[6] < 2) {
          if (features[7] < 61) {
            if (features[4] < 27) {
              if (features[8] < 56) {
                return -17562;
              } else {
                return -8025;
              }
            } else {
              if (features[0] < 62) {
                return -11655;
              } else {
                return -22264;
              }
            }
          } else {
            if (features[8] < 33) {
              return -15359;
            } else {
              return -30539;
            }
          }
        } else {
          if (features[7] < 127) {
            if (features[4] < 11) {
              if (features[7] < 6) {
                return -15118;
              } else {
                return -8540;
              }
            } else {
              if (features[3] < 7) {
                return -29954;
              } else {
                return -12485;
              }
            }
          } else {
            return -26665;
          }
        }
      } else {
        if (features[0] < 104) {
          if (features[6] < 2) {
            if (features[10] < 8) {
              return -10043;
            } else {
              if (features[8] < 18) {
                return -11429;
              } else {
                return -27189;
              }
            }
          } else {
            if (features[0] < 66) {
              if (features[8] < 41) {
                return -27026;
              } else {
                return -14130;
              }
            } else {
              if (features[8] < 66) {
                return -16233;
              } else {
                return -23657;
              }
            }
          }
        } else {
          return -24879;
        }
      }
    }
  }
}

short tree44(const unsigned char* features) {
  if (features[0] < 19) {
    if (features[6] < 4) {
      if (features[1] < 43) {
        if (features[8] < 82) {
          if (features[4] < 71) {
            if (features[0] < 13) {
              if (features[1] < 40) {
                return -26975;
              } else {
                return -17518;
              }
            } else {
              if (features[2] < 11) {
                return -23753;
              } else {
                return -26087;
              }
            }
          } else {
            if (features[8] < 41) {
              return -24071;
            } else {
              if (features[7] < 15) {
                return -2063;
              } else {
                return -23254;
              }
            }
          }
        } else {
          if (features[4] < 17) {
            if (features[10] < 5) {
              return -25415;
            } else {
              if (features[4] < 12) {
                return -9552;
              } else {
                return -24107;
              }
            }
          } else {
            if (features[0] < 17) {
              if (features[8] < 116) {
                return -20805;
              } else {
                return -6954;
              }
            } else {
              return -3375;
            }
          }
        }
      } else {
        if (features[4] < 28) {
          if (features[8] < 94) {
            if (features[8] < 33) {
              if (features[1] < 94) {
                return -13468;
              } else {
                return -22113;
              }
            } else {
              if (features[5] < 17) {
                return -25131;
              } else {
                return -17056;
              }
            }
          } else {
            return -509;
          }
        } else {
          if (features[8] < 52) {
            if (features[1] < 53) {
              return -26570;
            } else {
              return -12461;
            }
          } else {
            if (features[6] < 2) {
              return 2592;
            } else {
              return -15279;
            }
          }
        }
      }
    } else {
      if (features[2] < 11) {
        if (features[5] < 5) {
          return -26536;
        } else {
          if (features[2] < 5) {
            if (features[4] < 11) {
              if (features[4] < 8) {
                return -18944;
              } else {
                return -9880;
              }
            } else {
              if (features[7] < 19) {
                return -27664;
              } else {
                return -16097;
              }
            }
          } else {
            if (features[7] < 58) {
              if (features[5] < 39) {
                return -12128;
              } else {
                return -26329;
              }
            } else {
              if (features[0] < 14) {
                return -14260;
              } else {
                return -22096;
              }
            }
          }
        }
      } else {
        if (features[5] < 16) {
          if (features[3] < 21) {
            if (features[4] < 21) {
              return -24132;
            } else {
              return -6576;
            }
          } else {
            return -26291;
          }
        } else {
          return -11002;
        }
      }
    }
  } else {
    if (features[0] < 46) {
      if (features[6] < 18) {
        if (features[9] < 14) {
          if (features[1] < 95) {
            if (features[1] < 43) {
              if (features[8] < 91) {
                return -16117;
              } else {
                return -9902;
              }
            } else {
              if (features[6] < 7) {
                return -13724;
              } else {
                return -23534;
              }
            }
          } else {
            if (features[7] < 15) {
              if (features[3] < 22) {
                return -20708;
              } else {
                return -3020;
              }
            } else {
              return -26484;
            }
          }
        } else {
          if (features[5] < 12) {
            return -19081;
          } else {
            if (features[5] < 38) {
              return -4397;
            } else {
              if (features[1] < 43) {
                return -8871;
              } else {
                return -30212;
              }
            }
          }
        }
      } else {
        if (features[7] < 20) {
          if (features[10] < 13) {
            return -24052;
          } else {
            return -7907;
          }
        } else {
          return -26958;
        }
      }
    } else {
      if (features[6] < 3) {
        if (features[8] < 26) {
          if (features[1] < 68) {
            if (features[5] < 25) {
              if (features[7] < 3) {
                return -13335;
              } else {
                return -25913;
              }
            } else {
              if (features[4] < 15) {
                return 857;
              } else {
                return -19696;
              }
            }
          } else {
            if (features[7] < 22) {
              if (features[0] < 55) {
                return 12231;
              } else {
                return -13579;
              }
            } else {
              return -23962;
            }
          }
        } else {
          if (features[7] < 8) {
            if (features[8] < 44) {
              return -23009;
            } else {
              return -4123;
            }
          } else {
            if (features[5] < 6) {
              return -9687;
            } else {
              return -26038;
            }
          }
        }
      } else {
        return -26792;
      }
    }
  }
}

short tree45(const unsigned char* features) {
  if (features[0] < 25) {
    if (features[0] < 15) {
      if (features[1] < 25) {
        if (features[6] < 1) {
          if (features[2] < 26) {
            if (features[8] < 43) {
              if (features[4] < 3) {
                return -15375;
              } else {
                return -21083;
              }
            } else {
              if (features[7] < 33) {
                return -16216;
              } else {
                return -1958;
              }
            }
          } else {
            if (features[4] < 11) {
              return -24080;
            } else {
              if (features[7] < 6) {
                return -15034;
              } else {
                return 2383;
              }
            }
          }
        } else {
          if (features[11] < 1) {
            if (features[6] < 13) {
              if (features[7] < 5) {
                return -14539;
              } else {
                return -7336;
              }
            } else {
              return -24065;
            }
          } else {
            if (features[7] < 9) {
              if (features[8] < 46) {
                return -18912;
              } else {
                return -13512;
              }
            } else {
              if (features[0] < 7) {
                return -17164;
              } else {
                return -13329;
              }
            }
          }
        }
      } else {
        if (features[6] < 6) {
          if (features[8] < 42) {
            if (features[1] < 30) {
              if (features[4] < 3) {
                return -25781;
              } else {
                return -14691;
              }
            } else {
              if (features[1] < 92) {
                return -11190;
              } else {
                return -27472;
              }
            }
          } else {
            if (features[1] < 51) {
              if (features[0] < 11) {
                return -12485;
              } else {
                return -9164;
              }
            } else {
              if (features[2] < 7) {
                return -12405;
              } else {
                return -27451;
              }
            }
          }
        } else {
          if (features[4] < 8) {
            return -11172;
          } else {
            return -26345;
          }
        }
      }
    } else {
      if (features[0] < 20) {
        if (features[8] < 33) {
          if (features[3] < 6) {
            if (features[9] < 1) {
              if (features[1] < 54) {
                return -8222;
              } else {
                return -26374;
              }
            } else {
              if (features[8] < 29) {
                return -16790;
              } else {
                return -25720;
              }
            }
          } else {
            if (features[3] < 63) {
              if (features[4] < 27) {
                return -13127;
              } else {
                return -9368;
              }
            } else {
              if (features[7] < 8) {
                return -14696;
              } else {
                return -29336;
              }
            }
          }
        } else {
          if (features[7] < 17) {
            if (features[4] < 29) {
              if (features[4] < 5) {
                return -15879;
              } else {
                return -10904;
              }
            } else {
              if (features[8] < 53) {
                return -11635;
              } else {
                return -26445;
              }
            }
          } else {
            if (features[5] < 23) {
              if (features[8] < 117) {
                return -8781;
              } else {
                return -25070;
              }
            } else {
              if (features[3] < 22) {
                return -6698;
              } else {
                return -18647;
              }
            }
          }
        }
      } else {
        if (features[6] < 7) {
          if (features[8] < 66) {
            if (features[1] < 67) {
              if (features[9] < 15) {
                return -12806;
              } else {
                return -21384;
              }
            } else {
              if (features[2] < 6) {
                return -7353;
              } else {
                return -23056;
              }
            }
          } else {
            if (features[5] < 16) {
              if (features[6] < 3) {
                return -14523;
              } else {
                return -24646;
              }
            } else {
              if (features[7] < 10) {
                return -13793;
              } else {
                return -27834;
              }
            }
          }
        } else {
          if (features[11] < 24) {
            if (features[7] < 8) {
              return -14916;
            } else {
              return -24556;
            }
          } else {
            return -11645;
          }
        }
      }
    }
  } else {
    if (features[1] < 58) {
      if (features[10] < 2) {
        if (features[0] < 44) {
          if (features[7] < 3) {
            return -6387;
          } else {
            if (features[4] < 15) {
              if (features[5] < 17) {
                return -16821;
              } else {
                return -8597;
              }
            } else {
              if (features[2] < 48) {
                return -18835;
              } else {
                return -6454;
              }
            }
          }
        } else {
          if (features[7] < 17) {
            if (features[7] < 7) {
              if (features[2] < 15) {
                return -23647;
              } else {
                return -13502;
              }
            } else {
              if (features[0] < 155) {
                return -26696;
              } else {
                return -9134;
              }
            }
          } else {
            if (features[9] < 1) {
              if (features[3] < 60) {
                return -23239;
              } else {
                return -8820;
              }
            } else {
              return -2236;
            }
          }
        }
      } else {
        if (features[5] < 16) {
          if (features[6] < 2) {
            if (features[10] < 23) {
              if (features[2] < 24) {
                return -15969;
              } else {
                return -26230;
              }
            } else {
              return -3377;
            }
          } else {
            if (features[0] < 26) {
              if (features[10] < 6) {
                return -6171;
              } else {
                return -26559;
              }
            } else {
              if (features[4] < 36) {
                return -24052;
              } else {
                return -16712;
              }
            }
          }
        } else {
          if (features[11] < 11) {
            return -25219;
          } else {
            return -11633;
          }
        }
      }
    } else {
      if (features[9] < 1) {
        if (features[0] < 71) {
          if (features[0] < 30) {
            if (features[5] < 15) {
              if (features[7] < 37) {
                return -22161;
              } else {
                return -8396;
              }
            } else {
              return -5303;
            }
          } else {
            if (features[1] < 101) {
              return -25396;
            } else {
              if (features[8] < 24) {
                return -6974;
              } else {
                return -24586;
              }
            }
          }
        } else {
          return -4926;
        }
      } else {
        if (features[9] < 28) {
          return -26667;
        } else {
          return -6179;
        }
      }
    }
  }
}

short tree46(const unsigned char* features) {
  if (features[0] < 17) {
    if (features[6] < 2) {
      if (features[1] < 33) {
        if (features[11] < 1) {
          if (features[1] < 23) {
            if (features[10] < 16) {
              if (features[8] < 19) {
                return -18089;
              } else {
                return -12923;
              }
            } else {
              return -32714;
            }
          } else {
            if (features[6] < 1) {
              if (features[8] < 46) {
                return -12945;
              } else {
                return -24986;
              }
            } else {
              if (features[7] < 3) {
                return -14106;
              } else {
                return -25061;
              }
            }
          }
        } else {
          if (features[1] < 6) {
            if (features[3] < 2) {
              if (features[6] < 1) {
                return -26957;
              } else {
                return -9658;
              }
            } else {
              if (features[5] < 10) {
                return -18743;
              } else {
                return -10387;
              }
            }
          } else {
            if (features[4] < 49) {
              if (features[8] < 77) {
                return -13066;
              } else {
                return -21556;
              }
            } else {
              return -26454;
            }
          }
        }
      } else {
        if (features[4] < 13) {
          if (features[8] < 51) {
            if (features[5] < 10) {
              return -25839;
            } else {
              if (features[7] < 4) {
                return -26134;
              } else {
                return -12201;
              }
            }
          } else {
            return -24946;
          }
        } else {
          if (features[8] < 34) {
            if (features[10] < 2) {
              if (features[2] < 16) {
                return -14616;
              } else {
                return -25783;
              }
            } else {
              return -25190;
            }
          } else {
            return -27085;
          }
        }
      }
    } else {
      if (features[6] < 10) {
        if (features[10] < 1) {
          if (features[2] < 7) {
            if (features[5] < 33) {
              if (features[4] < 5) {
                return -14585;
              } else {
                return -9038;
              }
            } else {
              return -26141;
            }
          } else {
            if (features[3] < 25) {
              if (features[8] < 7) {
                return -11997;
              } else {
                return -21801;
              }
            } else {
              if (features[7] < 8) {
                return -1341;
              } else {
                return -18902;
              }
            }
          }
        } else {
          if (features[0] < 7) {
            if (features[1] < 8) {
              if (features[4] < 5) {
                return -17082;
              } else {
                return -28223;
              }
            } else {
              if (features[8] < 46) {
                return -12282;
              } else {
                return -24477;
              }
            }
          } else {
            if (features[7] < 9) {
              if (features[5] < 14) {
                return -13172;
              } else {
                return -20193;
              }
            } else {
              if (features[5] < 28) {
                return -21918;
              } else {
                return -29012;
              }
            }
          }
        }
      } else {
        if (features[0] < 8) {
          if (features[8] < 6) {
            if (features[6] < 20) {
              return -5940;
            } else {
              return -21644;
            }
          } else {
            return -23716;
          }
        } else {
          return -27310;
        }
      }
    }
  } else {
    if (features[1] < 24) {
      if (features[8] < 37) {
        if (features[2] < 8) {
          if (features[2] < 3) {
            if (features[6] < 1) {
              if (features[1] < 14) {
                return -27990;
              } else {
                return -14097;
              }
            } else {
              if (features[1] < 15) {
                return -6827;
              } else {
                return -23726;
              }
            }
          } else {
            if (features[7] < 6) {
              if (features[11] < 12) {
                return -7142;
              } else {
                return -21925;
              }
            } else {
              if (features[0] < 19) {
                return -13340;
              } else {
                return -24585;
              }
            }
          }
        } else {
          if (features[8] < 30) {
            if (features[10] < 3) {
              if (features[7] < 21) {
                return -26861;
              } else {
                return -15043;
              }
            } else {
              return -14604;
            }
          } else {
            if (features[3] < 43) {
              return -10134;
            } else {
              return -24592;
            }
          }
        }
      } else {
        if (features[4] < 11) {
          if (features[1] < 19) {
            return -10334;
          } else {
            return -26221;
          }
        } else {
          return -27055;
        }
      }
    } else {
      if (features[0] < 19) {
        if (features[3] < 12) {
          if (features[1] < 36) {
            if (features[6] < 1) {
              if (features[8] < 42) {
                return -7638;
              } else {
                return -26055;
              }
            } else {
              if (features[8] < 17) {
                return -26841;
              } else {
                return -19685;
              }
            }
          } else {
            return -27031;
          }
        } else {
          if (features[8] < 10) {
            if (features[3] < 14) {
              return 80;
            } else {
              return -22621;
            }
          } else {
            if (features[11] < 1) {
              return -26975;
            } else {
              if (features[1] < 55) {
                return -24091;
              } else {
                return -11224;
              }
            }
          }
        }
      } else {
        return -26684;
      }
    }
  }
}

short tree47(const unsigned char* features) {
  if (features[1] < 14) {
    if (features[6] < 1) {
      if (features[8] < 42) {
        if (features[4] < 17) {
          if (features[8] < 20) {
            if (features[5] < 7) {
              if (features[1] < 3) {
                return -25382;
              } else {
                return -13047;
              }
            } else {
              if (features[0] < 8) {
                return -8999;
              } else {
                return -22157;
              }
            }
          } else {
            if (features[7] < 17) {
              if (features[1] < 8) {
                return -13392;
              } else {
                return -18134;
              }
            } else {
              if (features[0] < 8) {
                return -10284;
              } else {
                return -23868;
              }
            }
          }
        } else {
          if (features[7] < 8) {
            if (features[3] < 14) {
              return -26898;
            } else {
              if (features[4] < 19) {
                return -6253;
              } else {
                return -19963;
              }
            }
          } else {
            if (features[1] < 8) {
              if (features[4] < 21) {
                return -13660;
              } else {
                return -26324;
              }
            } else {
              if (features[5] < 2) {
                return -9575;
              } else {
                return -26870;
              }
            }
          }
        }
      } else {
        return -26971;
      }
    } else {
      if (features[1] < 10) {
        if (features[2] < 11) {
          if (features[5] < 10) {
            if (features[1] < 9) {
              if (features[8] < 33) {
                return -17992;
              } else {
                return -24653;
              }
            } else {
              if (features[8] < 12) {
                return -24594;
              } else {
                return -8452;
              }
            }
          } else {
            return -24581;
          }
        } else {
          if (features[7] < 12) {
            if (features[1] < 5) {
              if (features[7] < 5) {
                return -7811;
              } else {
                return -21218;
              }
            } else {
              if (features[5] < 12) {
                return 7700;
              } else {
                return -23102;
              }
            }
          } else {
            if (features[3] < 23) {
              return -26821;
            } else {
              return -8112;
            }
          }
        }
      } else {
        if (features[0] < 3) {
          return -13625;
        } else {
          return -24052;
        }
      }
    }
  } else {
    if (features[0] < 8) {
      if (features[8] < 35) {
        if (features[4] < 8) {
          if (features[1] < 26) {
            if (features[3] < 16) {
              if (features[1] < 24) {
                return -23916;
              } else {
                return -14211;
              }
            } else {
              if (features[3] < 27) {
                return -7349;
              } else {
                return -22784;
              }
            }
          } else {
            return -27214;
          }
        } else {
          if (features[6] < 1) {
            if (features[5] < 20) {
              if (features[2] < 5) {
                return -15981;
              } else {
                return -24013;
              }
            } else {
              if (features[3] < 13) {
                return 111;
              } else {
                return -24605;
              }
            }
          } else {
            return -25623;
          }
        }
      } else {
        return -27276;
      }
    } else {
      if (features[1] < 17) {
        if (features[11] < 15) {
          if (features[5] < 2) {
            if (features[8] < 26) {
              return -6073;
            } else {
              return -23363;
            }
          } else {
            return -24997;
          }
        } else {
          return -8386;
        }
      } else {
        return -27031;
      }
    }
  }
}


int boosted_predict(
    unsigned char pm25,
    unsigned char pm10,
    unsigned char no,
    unsigned char no2,
    unsigned char nox,
    unsigned char nh3,
    unsigned char co,
    unsigned char so2,
    unsigned char o3,
    unsigned char benzene,
    unsigned char toluene,
    unsigned char xylene
) {

    unsigned char features[12];
    features[0] = pm25;
    features[1] = pm10;
    features[2] = no;
    features[3] = no2;
    features[4] = nox;
    features[5] = nh3;
    features[6] = co;
    features[7] = so2;
    features[8] = o3;
    features[9] = benzene;
    features[10] = toluene;
    features[11] = xylene;

    int acc[6] = {0, 0, 0, 0, 0, 0};
    acc[0] += tree0(features);
    acc[1] += tree1(features);
    acc[2] += tree2(features);
    acc[3] += tree3(features);
    acc[4] += tree4(features);
    acc[5] += tree5(features);
    acc[0] += tree6(features);
    acc[1] += tree7(features);
    acc[2] += tree8(features);
    acc[3] += tree9(features);
    acc[4] += tree10(features);
    acc[5] += tree11(features);
    acc[0] += tree12(features);
    acc[1] += tree13(features);
    acc[2] += tree14(features);
    acc[3] += tree15(features);
    acc[4] += tree16(features);
    acc[5] += tree17(features);
    acc[0] += tree18(features);
    acc[1] += tree19(features);
    acc[2] += tree20(features);
    acc[3] += tree21(features);
    acc[4] += tree22(features);
    acc[5] += tree23(features);
    acc[0] += tree24(features);
    acc[1] += tree25(features);
    acc[2] += tree26(features);
    acc[3] += tree27(features);
    acc[4] += tree28(features);
    acc[5] += tree29(features);
    acc[0] += tree30(features);
    acc[1] += tree31(features);
    acc[2] += tree32(features);
    acc[3] += tree33(features);
    acc[4] += tree34(features);
    acc[5] += tree35(features);
    acc[0] += tree36(features);
    acc[1] += tree37(features);
    acc[2] += tree38(features);
    acc[3] += tree39(features);
    acc[4] += tree40(features);
    acc[5] += tree41(features);
    acc[0] += tree42(features);
    acc[1] += tree43(features);
    acc[2] += tree44(features);
    acc[3] += tree45(features);
    acc[4] += tree46(features);
    acc[5] += tree47(features);
    int max_idx = 0;
    for (int i = 1; i < 6; ++i) {
        if (acc[i] > acc[max_idx]) max_idx = i;
    }
    return max_idx;
}



