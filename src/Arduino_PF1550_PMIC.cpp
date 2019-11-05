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

#include "Arduino_PF1550_PMIC.h"

#include "PF1550/PF1550_Io_EnvieH747.h"

/******************************************************************************
   CTOR/DTOR
 ******************************************************************************/

Arduino_PF1550_PMIC::Arduino_PF1550_PMIC(interface::PF1550_Io & io)
: _control(io)
{

}

/******************************************************************************
   PUBLIC MEMBER FUNCTIONS
 ******************************************************************************/

int Arduino_PF1550_PMIC::begin()
{
  return _control.begin();
}

void Arduino_PF1550_PMIC::configLDO1(Ldo1Voltage ldo_1_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep)
{
  _control.setLDO1Voltage(ldo_1_volt);

  if(enable)            _control.turnLDO1On (Ldo1Mode::Normal);
  else                  _control.turnLDO1Off(Ldo1Mode::Normal);
  if(enable_in_standby) _control.turnLDO1On (Ldo1Mode::Standby);
  else                  _control.turnLDO1Off(Ldo1Mode::Standby);
  if(enable_in_sleep)   _control.turnLDO1On (Ldo1Mode::Sleep);
  else                  _control.turnLDO1Off(Ldo1Mode::Sleep);
}

void Arduino_PF1550_PMIC::configLDO2(Ldo2Voltage ldo_2_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep)
{
  _control.setLDO2Voltage(ldo_2_volt);

  if(enable)            _control.turnLDO2On (Ldo2Mode::Normal);
  else                  _control.turnLDO2Off(Ldo2Mode::Normal);
  if(enable_in_standby) _control.turnLDO2On (Ldo2Mode::Standby);
  else                  _control.turnLDO2Off(Ldo2Mode::Standby);
  if(enable_in_sleep)   _control.turnLDO2On (Ldo2Mode::Sleep);
  else                  _control.turnLDO2Off(Ldo2Mode::Sleep);
}

void Arduino_PF1550_PMIC::configLDO3(Ldo3Voltage ldo_3_volt, bool const enable, bool const enable_in_standby, bool const enable_in_sleep)
{
  _control.setLDO3Voltage(ldo_3_volt);

  if(enable)            _control.turnLDO3On (Ldo3Mode::Normal);
  else                  _control.turnLDO3Off(Ldo3Mode::Normal);
  if(enable_in_standby) _control.turnLDO3On (Ldo3Mode::Standby);
  else                  _control.turnLDO3Off(Ldo3Mode::Standby);
  if(enable_in_sleep)   _control.turnLDO3On (Ldo3Mode::Sleep);
  else                  _control.turnLDO3Off(Ldo3Mode::Sleep);
}

void Arduino_PF1550_PMIC::configCharger(IFastCharge        const i_fast_charge,
                                        VFastCharge        const v_fast_charge,
                                        IEndOfCharge       const i_end_of_charge,
                                        IInputCurrentLimit const i_input_current_limit)
{
  _control.setFastChargeCurrent (i_fast_charge);
  _control.setFastChargeVoltage (v_fast_charge);
  _control.setEndOfChargeCurrent(i_end_of_charge);
  _control.setInputCurrentLimit (i_input_current_limit);
}

/******************************************************************************
   EXTERN DEFINITION
 ******************************************************************************/

static PF1550_Io_EnvieH747 io;

Arduino_PF1550_PMIC PMIC(io);
