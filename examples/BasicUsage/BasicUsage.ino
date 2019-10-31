#include "Arduino_PF1550_PMIC.h"

void setup() {
  PMIC.begin();

  PMIC.setLDO1Voltage(PF1550::Ldo1Voltage::V_1_00);
  PMIC.turnLDO1On(PF1550::Ldo1Mode::Normal);
  PMIC.turnLDO1On(PF1550::Ldo1Mode::Standby);

  PMIC.setLDO2Voltage(PF1550::Ldo2Voltage::V_1_80);
  PMIC.turnLDO2On(PF1550::Ldo2Mode::Normal);
  PMIC.turnLDO2On(PF1550::Ldo2Mode::Standby);
}


void loop() {
  
}
