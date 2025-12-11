#include "sample_data.h"

/**
 * O2 > 6
 * 6.5 < pH < 8.5
 * TDS < 600
 */

// Global volatile variable to return result
volatile char result = -1;

char potable_check(long o2, long pH, long tds) {
  return o2 > O2_MIN && (pH < PH_MAX && pH > PH_MIN) && tds < TDS_MAX;
}

char Read_Sensor_Values_Run_Check() {
  long pH, o2, tds;
  char potable, golden_reference;

  unsigned short data_sample;
  char GPIO;

  pH = pH_Sensor_Sample_Input;
  o2 = O2_Sensor_Sample_Input;
  tds = TDS_Sensor_Sample_Input;
  potable = potable_check(o2, pH, tds);
  golden_reference = Golden_Reference_Potability;
  
  if (potable) {
    GPIO = 1;
    return GPIO;
  }

  GPIO = 0;
  return GPIO;
}

int main() {
  result = Read_Sensor_Values_Run_Check();
  return 0;
}
