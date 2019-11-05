#include "Arduino_PMIC.h"

void setup() {
  PMIC.begin();

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
