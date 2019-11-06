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

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "PF1550.h"

#include "PF1550/PF1550_Io_EnvieH747.h"

/******************************************************************************
   CTOR/DTOR
 ******************************************************************************/

PF1550::PF1550(interface::PF1550_Io & io)
: _control(io)
{

}

/******************************************************************************
   PUBLIC MEMBER FUNCTIONS
 ******************************************************************************/

int PF1550::begin()
{
  return _control.begin();
}

void PF1550::configLDO1(Ldo1Voltage const ldo_1_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep)
{
  _control.setLDO1Voltage(ldo_1_volt);

  if(enable)            _control.turnLDO1On (Ldo1Mode::Normal);
  else                  _control.turnLDO1Off(Ldo1Mode::Normal);
  if(enable_in_standby) _control.turnLDO1On (Ldo1Mode::Standby);
  else                  _control.turnLDO1Off(Ldo1Mode::Standby);
  if(enable_in_sleep)   _control.turnLDO1On (Ldo1Mode::Sleep);
  else                  _control.turnLDO1Off(Ldo1Mode::Sleep);
}

void PF1550::configLDO2(Ldo2Voltage const ldo_2_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep)
{
  _control.setLDO2Voltage(ldo_2_volt);

  if(enable)            _control.turnLDO2On (Ldo2Mode::Normal);
  else                  _control.turnLDO2Off(Ldo2Mode::Normal);
  if(enable_in_standby) _control.turnLDO2On (Ldo2Mode::Standby);
  else                  _control.turnLDO2Off(Ldo2Mode::Standby);
  if(enable_in_sleep)   _control.turnLDO2On (Ldo2Mode::Sleep);
  else                  _control.turnLDO2Off(Ldo2Mode::Sleep);
}

void PF1550::configLDO3(Ldo3Voltage const ldo_3_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep)
{
  _control.setLDO3Voltage(ldo_3_volt);

  if(enable)            _control.turnLDO3On (Ldo3Mode::Normal);
  else                  _control.turnLDO3Off(Ldo3Mode::Normal);
  if(enable_in_standby) _control.turnLDO3On (Ldo3Mode::Standby);
  else                  _control.turnLDO3Off(Ldo3Mode::Standby);
  if(enable_in_sleep)   _control.turnLDO3On (Ldo3Mode::Sleep);
  else                  _control.turnLDO3Off(Ldo3Mode::Sleep);
}

void PF1550::configSw2(Sw2Voltage      const sw2_volt,
                       Sw2Voltage      const sw2_volt_standby,
                       Sw2Voltage      const sw2_volt_sleep,
                       Sw2CurrentLimit const sw2_current_limit,
                       bool            const enable,
                       bool            const enable_in_standby,
                       bool            const enable_in_sleep)
{
  _control.setSw2Voltage       (sw2_volt);
  _control.setSw2VoltageStandby(sw2_volt_standby);
  _control.setSw2VoltageSleep  (sw2_volt_sleep);
  _control.setSw2CurrentLimit  (sw2_current_limit);

  if(enable)            _control.turnSw2On (Sw2Mode::Normal);
  else                  _control.turnSw2Off(Sw2Mode::Normal);
  if(enable_in_standby) _control.turnSw2On (Sw2Mode::Standby);
  else                  _control.turnSw2Off(Sw2Mode::Standby);
  if(enable_in_sleep)   _control.turnSw2On (Sw2Mode::Sleep);
  else                  _control.turnSw2Off(Sw2Mode::Sleep);
}

void PF1550::configCharger(IFastCharge        const i_fast_charge,
                                        VFastCharge        const v_fast_charge,
                                        IEndOfCharge       const i_end_of_charge,
                                        IInputCurrentLimit const i_input_current_limit)
{
  _control.setFastChargeCurrent (i_fast_charge);
  _control.setFastChargeVoltage (v_fast_charge);
  _control.setEndOfChargeCurrent(i_end_of_charge);
  _control.setInputCurrentLimit (i_input_current_limit);
}

void PF1550::ISR_onPMICEvent()
{
  PMIC.ISR_onPMICEvent();
}

/******************************************************************************
   EXTERN DEFINITION
 ******************************************************************************/

static PF1550_Io_EnvieH747 io;

PF1550 PMIC(io);
