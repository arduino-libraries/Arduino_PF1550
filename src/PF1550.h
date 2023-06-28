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

#ifndef ARDUINO_PF1550_H_
#define ARDUINO_PF1550_H_

#define PF1550_I2C_ADDR (PF1550_I2C_DEFAULT_ADDR)

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include <Arduino.h>

#include "PF1550/PF1550_IO.h"
#include "PF1550/PF1550_Types.h"
#include "PF1550/PF1550_Control.h"
#include "PF1550/PF1550_Register.h"

/******************************************************************************
   EXTERN DECLARATION
 ******************************************************************************/

class PF1550;
extern PF1550 PMIC;

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550
{
public:

  PF1550(PF1550_IO & io);

  int begin();

  void debug(Stream& stream);

  void setPMICbit(Register const reg_addr, uint8_t const posBit);
  void writePMICreg(Register const reg_addr, uint8_t const val);
  uint8_t readPMICreg(Register const reg_addr);

  void configLDO1(Ldo1Voltage const ldo_1_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep);
  void configLDO2(Ldo2Voltage const ldo_2_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep);
  void configLDO3(Ldo3Voltage const ldo_3_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep);

  void configSw1(Sw1Voltage      const sw1_volt,
                 Sw1Voltage      const sw1_volt_standby,
                 Sw1Voltage      const sw1_volt_sleep,
                 Sw1CurrentLimit const sw1_current_limit,
                 bool            const enable,
                 bool            const enable_in_standby,
                 bool            const enable_in_sleep)
#if defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) || defined(ARDUINO_NICLA_VISION)
                 __attribute__ ((error("Erroneous usage of this API can cause board damage.")))
#elif defined(ARDUINO_PORTENTA_C33)
                __attribute__ ((warning("Using this API you can turn off ESP32 (WiFi), SE051 (Crypto) and Ethernet PHY. Proceed with caution.")))
#endif
                 ;

  void configSw2(Sw2Voltage      const sw2_volt,
                 Sw2Voltage      const sw2_volt_standby,
                 Sw2Voltage      const sw2_volt_sleep,
                 Sw2CurrentLimit const sw2_current_limit,
                 bool            const enable,
                 bool            const enable_in_standby,
                 bool            const enable_in_sleep);

  void configCharger(IFastCharge        const i_fast_charge,
                     VFastCharge        const v_fast_charge,
                     IEndOfCharge       const i_end_of_charge,
                     IInputCurrentLimit const i_input_current_limit);

  uint8_t getDeviceId() { return _control.getDeviceId(); }

  /* Static function registered to be executed from within external interrupt ISR */
  static void ISR_onPMICEvent() { PMIC.onPMICEvent(); }
  /* Actual PMIC event ISR handler with access to member variables */
  inline void onPMICEvent() { _control.onPMICEvent(); }


private:
  PF1550_Control _control;
  Stream* _debug;
};

#endif /* ARDUINO_PF1550_H_ */
