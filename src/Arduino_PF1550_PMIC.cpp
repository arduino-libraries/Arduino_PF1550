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

Arduino_PF1550_PMIC::Arduino_PF1550_PMIC(PF1550::interface::PF1550_Io & io)
: _io(io)
{

}

/******************************************************************************
   PUBLIC MEMBER FUNCTIONS
 ******************************************************************************/

int Arduino_PF1550_PMIC::begin()
{
  _io.begin();
  return 1;
}

void Arduino_PF1550_PMIC::setLDO1Voltage(PF1550::Ldo1Voltage const ldo1_volt)
{
  _io.writeRegister(PF1550::Register::PMIC_LDO1_VOLT, static_cast<uint8_t>(ldo1_volt));
}

void Arduino_PF1550_PMIC::turnLDO1On(PF1550::Ldo1Mode const mode)
{
  _io.setBit(PF1550::Register::PMIC_LDO1_CTRL, static_cast<uint8_t>(mode));
}

void Arduino_PF1550_PMIC::turnLDO1Off(PF1550::Ldo1Mode const mode)
{
  _io.clrBit(PF1550::Register::PMIC_LDO1_CTRL, static_cast<uint8_t>(mode));
}

void Arduino_PF1550_PMIC::setLDO2Voltage(PF1550::Ldo2Voltage const ldo2_volt)
{
  _io.writeRegister(PF1550::Register::PMIC_LDO2_VOLT, static_cast<uint8_t>(ldo2_volt));
}

void Arduino_PF1550_PMIC::turnLDO2On(PF1550::Ldo2Mode const mode)
{
  _io.setBit(PF1550::Register::PMIC_LDO2_CTRL, static_cast<uint8_t>(mode));
}

void Arduino_PF1550_PMIC::turnLDO2Off(PF1550::Ldo2Mode const mode)
{
  _io.clrBit(PF1550::Register::PMIC_LDO2_CTRL, static_cast<uint8_t>(mode));
}

void Arduino_PF1550_PMIC::setLDO3Voltage(PF1550::Ldo3Voltage const ldo3_volt)
{
  _io.writeRegister(PF1550::Register::PMIC_LDO3_VOLT, static_cast<uint8_t>(ldo3_volt));
}

void Arduino_PF1550_PMIC::turnLDO3On(PF1550::Ldo3Mode const mode)
{
  _io.setBit(PF1550::Register::PMIC_LDO3_CTRL, static_cast<uint8_t>(mode));
}

void Arduino_PF1550_PMIC::turnLDO3Off(PF1550::Ldo3Mode const mode)
{
  _io.clrBit(PF1550::Register::PMIC_LDO3_CTRL, static_cast<uint8_t>(mode));
}

void Arduino_PF1550_PMIC::setFastChargeCurrent(PF1550::IFastCharge const i_fast_charge)
{
  uint8_t chg_curr_reg = _io.readRegister(PF1550::Register::CHARGER_CHG_CURR_CFG);
  chg_curr_reg &= ~REG_CHG_CURR_CFG_CHG_CC_mask;
  chg_curr_reg |= static_cast<uint8_t>(i_fast_charge);
  _io.writeRegister(PF1550::Register::CHARGER_CHG_CURR_CFG, chg_curr_reg);
}

void Arduino_PF1550_PMIC::setFastChargeVoltage(PF1550::VFastCharge const v_fast_charge)
{
  uint8_t batt_reg = _io.readRegister(PF1550::Register::CHARGER_BATT_REG);
  batt_reg &= ~REG_BATT_REG_CHCCV_mask;
  batt_reg |= static_cast<uint8_t>(v_fast_charge);
  _io.writeRegister(PF1550::Register::CHARGER_BATT_REG, batt_reg);
}

void Arduino_PF1550_PMIC::setEndOfChargeCurrent(PF1550::IEndOfCharge const i_end_of_charge)
{
  uint8_t chg_eoc_cnfg = _io.readRegister(PF1550::Register::CHARGER_CHG_EOC_CNFG);
  chg_eoc_cnfg &= ~REG_CHG_EOC_CNFG_IEOC_mask;
  chg_eoc_cnfg |= static_cast<uint8_t>(i_end_of_charge);
  _io.writeRegister(PF1550::Register::CHARGER_CHG_EOC_CNFG, chg_eoc_cnfg);
}

void Arduino_PF1550_PMIC::setInputCurrentLimit(PF1550::IInputCurrentLimit const i_input_current_limit)
{
  uint8_t vbus_inlim_cnfg = _io.readRegister(PF1550::Register::CHARGER_VBUS_INLIM_CNFG);
  vbus_inlim_cnfg &= ~REG_VBUS_INLIM_CNFG_VBUS_LIN_INLIM_mask;
  vbus_inlim_cnfg |= static_cast<uint8_t>(i_input_current_limit);
  _io.writeRegister(PF1550::Register::CHARGER_VBUS_INLIM_CNFG, vbus_inlim_cnfg);
}

/******************************************************************************
   EXTERN DEFINITION
 ******************************************************************************/

static PF1550::PF1550_Io_EnvieH747 io;

Arduino_PF1550_PMIC PMIC(io);
