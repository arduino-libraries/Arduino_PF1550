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

int PF1550_Control::begin()
{
  return _io.begin();
}

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

void PF1550_Control::setFastChargeCurrent(IFastCharge const i_fast_charge)
{
  uint8_t chg_curr_reg = _io.readRegister(Register::CHARGER_CHG_CURR_CFG);
  chg_curr_reg &= ~REG_CHG_CURR_CFG_CHG_CC_mask;
  chg_curr_reg |= static_cast<uint8_t>(i_fast_charge);
  _io.writeRegister(Register::CHARGER_CHG_CURR_CFG, chg_curr_reg);
}

void PF1550_Control::setFastChargeVoltage(VFastCharge const v_fast_charge)
{
  uint8_t batt_reg = _io.readRegister(Register::CHARGER_BATT_REG);
  batt_reg &= ~REG_BATT_REG_CHCCV_mask;
  batt_reg |= static_cast<uint8_t>(v_fast_charge);
  _io.writeRegister(Register::CHARGER_BATT_REG, batt_reg);
}

void PF1550_Control::setEndOfChargeCurrent(IEndOfCharge const i_end_of_charge)
{
  uint8_t chg_eoc_cnfg = _io.readRegister(Register::CHARGER_CHG_EOC_CNFG);
  chg_eoc_cnfg &= ~REG_CHG_EOC_CNFG_IEOC_mask;
  chg_eoc_cnfg |= static_cast<uint8_t>(i_end_of_charge);
  _io.writeRegister(Register::CHARGER_CHG_EOC_CNFG, chg_eoc_cnfg);
}

void PF1550_Control::setInputCurrentLimit(IInputCurrentLimit const i_input_current_limit)
{
  uint8_t vbus_inlim_cnfg = _io.readRegister(Register::CHARGER_VBUS_INLIM_CNFG);
  vbus_inlim_cnfg &= ~REG_VBUS_INLIM_CNFG_VBUS_LIN_INLIM_mask;
  vbus_inlim_cnfg |= static_cast<uint8_t>(i_input_current_limit);
  _io.writeRegister(Register::CHARGER_VBUS_INLIM_CNFG, vbus_inlim_cnfg);
}

uint8_t PF1550_Control::getDeviceId()
{
  return _io.readRegister(Register::PMIC_DEVICE_ID);
}

void PF1550_Control::onPMICEvent()
{
  /* TODO Implement PMIC Event Handler */
}
