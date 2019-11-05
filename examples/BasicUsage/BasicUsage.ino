#include "PF1550.h"

void setup() {
  PMIC.begin();
/*
  PMIC.setLDO1Voltage(PF1550::Ldo1Voltage::V_1_00);
  PMIC.turnLDO1On(PF1550::Ldo1Mode::Normal);
  PMIC.turnLDO1On(PF1550::Ldo1Mode::Standby);

  PMIC.setLDO2Voltage(PF1550::Ldo2Voltage::V_1_80);
  PMIC.turnLDO2On(PF1550::Ldo2Mode::Normal);
  PMIC.turnLDO2On(PF1550::Ldo2Mode::Standby);

  PMIC.setLDO3Voltage(PF1550::Ldo3Voltage::V_1_20);
  PMIC.turnLDO3On(PF1550::Ldo3Mode::Normal);
  PMIC.turnLDO3On(PF1550::Ldo3Mode::Standby);
*/
  PMIC.configLDO1(Ldo1Voltage::V_1_00, true, true, false);
  PMIC.configLDO2(Ldo2Voltage::V_1_80, true, true, false);
  PMIC.configLDO3(Ldo3Voltage::V_1_20, true, true, false);

  PMIC.configCharger(IFastCharge::I_500_mA,
                     VFastCharge::V_3_80,
                     IEndOfCharge::I_5_mA,
                     IInputCurrentLimit::I_100_mA);
}


void loop() {
  
}
