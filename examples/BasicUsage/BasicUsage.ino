#include "Arduino_PF1550_PMIC.h"

void setup() {
  PMIC.begin();

  PMIC.setLDO1Voltage(PF1550::Ldo1Voltage::V_1_00);
  PMIC.turnLDO1On(PF1550::Ldo1Mode::Normal);
  PMIC.turnLDO1On(PF1550::Ldo1Mode::Standby);
}


void loop() {
  
}
