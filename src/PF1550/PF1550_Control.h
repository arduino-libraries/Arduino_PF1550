/*
  Copyright (c) 2019 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef PF1550_CONTROL_H_
#define PF1550_CONTROL_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "PF1550_Types.h"
#include "interface/PF1550_Io.h"

/******************************************************************************
   CONSTANT
 ******************************************************************************/

static uint8_t const PF1550_DEVICE_ID = 0b01111100;

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550_Control
{

public:

  PF1550_Control(interface::PF1550_Io & io);


  int begin();

  void writeReg(Register const addr, uint8_t val);
  uint8_t readReg(Register const addr);

  /* LDO1 Configuration *******************************************************/
  void setLDO1Voltage   (Ldo1Voltage const ldo1_volt);
  void turnLDO1On       (Ldo1Mode    const mode);
  void turnLDO1Off      (Ldo1Mode    const mode);
  /* LDO2 Configuration *******************************************************/
  void setLDO2Voltage   (Ldo2Voltage const ldo2_volt);
  void turnLDO2On       (Ldo2Mode    const mode);
  void turnLDO2Off      (Ldo2Mode    const mode);
  /* LDO3 Configuration *******************************************************/
  void setLDO3Voltage   (Ldo3Voltage const ldo3_volt);
  void turnLDO3On       (Ldo3Mode    const mode);
  void turnLDO3Off      (Ldo3Mode    const mode);

  /* SW2 Configuration ********************************************************/
  void setSw2Voltage       (Sw2Voltage      const sw2_volt);
  void setSw2VoltageStandby(Sw2Voltage      const sw2_volt_standby);
  void setSw2VoltageSleep  (Sw2Voltage      const sw2_volt_sleep);
  void setSw2CurrentLimit  (Sw2CurrentLimit const sw2_current_limit);
  void turnSw2On           (Sw2Mode         const mode);
  void turnSw2Off          (Sw2Mode         const mode);

  /* Charger Configuration ****************************************************/
  void setFastChargeCurrent (IFastCharge        const i_fast_charge);
  void setFastChargeVoltage (VFastCharge        const v_fast_charge);
  void setEndOfChargeCurrent(IEndOfCharge       const i_end_of_charge);
  void setInputCurrentLimit (IInputCurrentLimit const i_input_current_limit);

  /* Miscellaneous ************************************************************/
  uint8_t getDeviceId();

  /* Interrupt Service Handler for PMIC interrupt *****************************/
  void onPMICEvent();

private:

  interface::PF1550_Io & _io;

  void onChargerEvent();
  void onSwitch1Event();
  void onSwitch2Event();
  void onSwitch3Event();
  void onLdoEvent();
  void onOnKeyEvent();
  void onTemperatureMonitorEvent();
  void onMiscellaneousEvent();

};

#endif /* PF1550_CONTROL_H_ */
