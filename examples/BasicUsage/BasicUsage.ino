#include "Arduino_PF1550_PMIC.h"

void setup() {
  PMIC.begin();

  PMIC.setLDO1Voltage(PF1550::LDO_1_Voltage::V_1_00);
}


void loop() {
  
}
