#include "Arduino_PF1550_PMIC.h"

void setup() {
  PMIC.begin();

  PMIC.setLDO1Voltage(PF1550::Ldo1Voltage::V_1_00);
  PMIC.turnLDO1On(PF1550::Ldo1Mode::Normal);
  PMIC.turnLDO1On(PF1550::Ldo1Mode::Standby);

  PMIC.setLDO2Voltage(PF1550::Ldo2Voltage::V_1_80);
  PMIC.turnLDO2On(PF1550::Ldo2Mode::Normal);
  PMIC.turnLDO2On(PF1550::Ldo2Mode::Standby);

  PMIC.setLDO3Voltage(PF1550::Ldo3Voltage::V_1_20);
  PMIC.turnLDO3On(PF1550::Ldo3Mode::Normal);
  PMIC.turnLDO3On(PF1550::Ldo3Mode::Standby);
}


void loop() {
  
}
