#include "Arduino_PMIC.h"
#include "PF1550/PF1550_Register.h"

#define Serial Serial1

void setup() {
  Serial.begin(115200);
  while(!Serial);

  PMIC.begin();

  PMIC.debug(Serial);

  PMIC.writePMICreg(Register::CHARGER_CHG_EOC_CNFG, 0x41);
  uint8_t regVal = PMIC.readPMICreg(Register::CHARGER_CHG_EOC_CNFG);

  Serial.print("Register value: ");
  Serial.println(regVal);

}


void loop() {
  
}