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

#include "PF1550_Control.h"

/******************************************************************************
   CTOR/DTOR
 ******************************************************************************/

PF1550_Control::PF1550_Control(interface::PF1550_Io & io)
: _io(io)
{

}

/******************************************************************************
   PUBLIC MEMBER FUNCTIONS
 ******************************************************************************/

void PF1550_Control::setLDO1Voltage(Ldo1Voltage const ldo1_volt)
{
  _io.writeRegister(Register::PMIC_LDO1_VOLT, static_cast<uint8_t>(ldo1_volt));
}

void PF1550_Control::turnLDO1On(Ldo1Mode const mode)
{
  _io.setBit(Register::PMIC_LDO1_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::turnLDO1Off(Ldo1Mode const mode)
{
  _io.clrBit(Register::PMIC_LDO1_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::setLDO2Voltage(Ldo2Voltage const ldo2_volt)
{
  _io.writeRegister(Register::PMIC_LDO2_VOLT, static_cast<uint8_t>(ldo2_volt));
}

void PF1550_Control::turnLDO2On(Ldo2Mode const mode)
{
  _io.setBit(Register::PMIC_LDO2_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::turnLDO2Off(Ldo2Mode const mode)
{
  _io.clrBit(Register::PMIC_LDO2_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::setLDO3Voltage(Ldo3Voltage const ldo3_volt)
{
  _io.writeRegister(Register::PMIC_LDO3_VOLT, static_cast<uint8_t>(ldo3_volt));
}

void PF1550_Control::turnLDO3On(Ldo3Mode const mode)
{
  _io.setBit(Register::PMIC_LDO3_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::turnLDO3Off(Ldo3Mode const mode)
{
  _io.clrBit(Register::PMIC_LDO3_CTRL, static_cast<uint8_t>(mode));
}
