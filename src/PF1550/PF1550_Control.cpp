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

#include "util/PF1550_Util.h"

#include "PF1550.h"

/******************************************************************************
   CTOR/DTOR
 ******************************************************************************/

PF1550_Control::PF1550_Control(PF1550_IO & io)
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

void PF1550_Control::debug(Stream& stream)
{
  _debug = &stream;
  _io.debug(stream);
}

void PF1550_Control::setBit(Register const reg, uint8_t const bit_pos)
{
  _io.setBit(reg, bit_pos);
}

void PF1550_Control::clrBit(Register const reg, uint8_t const bit_pos)
{
  _io.clrBit(reg, bit_pos);
}

void PF1550_Control::writeReg(Register const reg_addr, uint8_t const val)
{
  if (_debug) {
    _debug->print("PF1550_Control::writeReg at address = ");
    _debug->print(static_cast<uint8_t>(reg_addr), HEX);
    _debug->print(" data=");
    _debug->println(val, HEX);
  }

  _io.writeRegister(reg_addr, val);
}

void PF1550_Control::readReg(Register const reg_addr, uint8_t *data)
{
  _io.readRegister(reg_addr, data);
}

void PF1550_Control::setLDO1Voltage(Ldo1Voltage const ldo1_volt)
{
  writeReg(Register::PMIC_LDO1_VOLT, static_cast<uint8_t>(ldo1_volt));
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
  writeReg(Register::PMIC_LDO2_VOLT, static_cast<uint8_t>(ldo2_volt));
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
  writeReg(Register::PMIC_LDO3_VOLT, static_cast<uint8_t>(ldo3_volt));
}

void PF1550_Control::turnLDO3On(Ldo3Mode const mode)
{
  _io.setBit(Register::PMIC_LDO3_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::turnLDO3Off(Ldo3Mode const mode)
{
  _io.clrBit(Register::PMIC_LDO3_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::setSw1Voltage(Sw1Voltage const sw1_volt)
{
  writeReg(Register::PMIC_SW1_VOLT, static_cast<uint8_t>(sw1_volt));
}

void PF1550_Control::setSw1VoltageStandby(Sw1Voltage const sw1_volt_standby)
{
  writeReg(Register::PMIC_SW1_STBY_VOLT, static_cast<uint8_t>(sw1_volt_standby));
}

void PF1550_Control::setSw1VoltageSleep(Sw1Voltage const sw1_volt_sleep)
{
  writeReg(Register::PMIC_SW1_SLP_VOLT, static_cast<uint8_t>(sw1_volt_sleep));
}

void PF1550_Control::setSw1CurrentLimit(Sw1CurrentLimit const sw1_current_limit)
{
  uint8_t sw1_ctrl1_reg;
  _io.readRegister(Register::PMIC_SW1_CTRL1, &sw1_ctrl1_reg);
  sw1_ctrl1_reg &= ~REG_SW1_CTRL1_SW1_ILIM_mask;
  sw1_ctrl1_reg |= static_cast<uint8_t>(sw1_current_limit);

  writeReg(Register::PMIC_SW1_CTRL1, sw1_ctrl1_reg);
}

void PF1550_Control::turnSw1On(Sw1Mode const mode)
{
  _io.setBit(Register::PMIC_SW1_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::turnSw1Off(Sw1Mode const mode)
{
  _io.clrBit(Register::PMIC_SW1_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::setSw2Voltage(Sw2Voltage const sw2_volt)
{
  writeReg(Register::PMIC_SW2_VOLT, static_cast<uint8_t>(sw2_volt));
}

void PF1550_Control::setSw2VoltageStandby(Sw2Voltage const sw2_volt_standby)
{
  writeReg(Register::PMIC_SW2_STBY_VOLT, static_cast<uint8_t>(sw2_volt_standby));
}

void PF1550_Control::setSw2VoltageSleep(Sw2Voltage const sw2_volt_sleep)
{
  writeReg(Register::PMIC_SW2_SLP_VOLT, static_cast<uint8_t>(sw2_volt_sleep));
}

void PF1550_Control::setSw2CurrentLimit(Sw2CurrentLimit const sw2_current_limit)
{
  uint8_t sw2_ctrl1_reg;
  _io.readRegister(Register::PMIC_SW2_CTRL1, &sw2_ctrl1_reg);
  sw2_ctrl1_reg &= ~REG_SW2_CTRL1_SW2_ILIM_mask;
  sw2_ctrl1_reg |= static_cast<uint8_t>(sw2_current_limit);

  writeReg(Register::PMIC_SW2_CTRL1, sw2_ctrl1_reg);
}

void PF1550_Control::turnSw2On(Sw2Mode const mode)
{
  _io.setBit(Register::PMIC_SW2_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::turnSw2Off(Sw2Mode const mode)
{
  _io.clrBit(Register::PMIC_SW2_CTRL, static_cast<uint8_t>(mode));
}

void PF1550_Control::setFastChargeCurrent(IFastCharge const i_fast_charge)
{
  uint8_t chg_curr_reg;
  _io.readRegister(Register::CHARGER_CHG_CURR_CFG, &chg_curr_reg);
  chg_curr_reg &= ~REG_CHG_CURR_CFG_CHG_CC_mask;
  chg_curr_reg |= static_cast<uint8_t>(i_fast_charge);

  writeReg(Register::CHARGER_CHG_CURR_CFG, chg_curr_reg);
}

void PF1550_Control::setFastChargeVoltage(VFastCharge const v_fast_charge)
{
  uint8_t batt_reg;
  _io.readRegister(Register::CHARGER_BATT_REG, &batt_reg);
  batt_reg &= ~REG_BATT_REG_CHCCV_mask;
  batt_reg |= static_cast<uint8_t>(v_fast_charge);

  writeReg(Register::CHARGER_BATT_REG, batt_reg);
}

void PF1550_Control::setEndOfChargeCurrent(IEndOfCharge const i_end_of_charge)
{
  uint8_t chg_eoc_cnfg;
  _io.readRegister(Register::CHARGER_CHG_EOC_CNFG, &chg_eoc_cnfg);
  chg_eoc_cnfg &= ~REG_CHG_EOC_CNFG_IEOC_mask;
  chg_eoc_cnfg |= static_cast<uint8_t>(i_end_of_charge);

  writeReg(Register::CHARGER_CHG_EOC_CNFG, chg_eoc_cnfg);
}

void PF1550_Control::setInputCurrentLimit(IInputCurrentLimit const i_input_current_limit)
{
  uint8_t vbus_inlim_cnfg;
  _io.readRegister(Register::CHARGER_VBUS_INLIM_CNFG, &vbus_inlim_cnfg);
  vbus_inlim_cnfg &= ~REG_VBUS_INLIM_CNFG_VBUS_LIN_INLIM_mask;
  vbus_inlim_cnfg |= static_cast<uint8_t>(i_input_current_limit);

  writeReg(Register::CHARGER_VBUS_INLIM_CNFG, vbus_inlim_cnfg);
}

uint8_t PF1550_Control::getDeviceId()
{
  uint8_t deviceId;
  _io.readRegister(Register::PMIC_DEVICE_ID, &deviceId);
  return deviceId;
}

void PF1550_Control::onPMICEvent()
{
  /* Retrieve the source of the interrupt */
  uint8_t int_category;
  _io.readRegister(Register::PMIC_INT_CATEGORY, &int_category);
  
  /* Call the appropriate event handler */
  if(isBitSet(int_category, REG_INT_CATEGORY_CHG_INT_bp  )) onChargerEvent           ();
  if(isBitSet(int_category, REG_INT_CATEGORY_SW1_INT_bp  )) onSwitch1Event           ();
  if(isBitSet(int_category, REG_INT_CATEGORY_SW2_INT_bp  )) onSwitch2Event           ();
  if(isBitSet(int_category, REG_INT_CATEGORY_SW3_INT_bp  )) onSwitch3Event           ();
  if(isBitSet(int_category, REG_INT_CATEGORY_LDO_INT_bp  )) onLdoEvent               ();
  if(isBitSet(int_category, REG_INT_CATEGORY_ONKEY_INT_bp)) onOnKeyEvent             ();
  if(isBitSet(int_category, REG_INT_CATEGORY_TEMP_INT_bp )) onTemperatureMonitorEvent();
  if(isBitSet(int_category, REG_INT_CATEGORY_MISC_INT_bp )) onMiscellaneousEvent     ();
}

/******************************************************************************
   PRIVATE MEMBER FUNCTIONS
 ******************************************************************************/

void PF1550_Control::onChargerEvent()
{
  /* TODO */
}

void PF1550_Control::onSwitch1Event()
{
  /* TODO */
}

void PF1550_Control::onSwitch2Event()
{
  /* TODO */
}

void PF1550_Control::onSwitch3Event()
{
  /* TODO */
}

void PF1550_Control::onLdoEvent()
{
  /* TODO */
}

void PF1550_Control::onOnKeyEvent()
{
  /* TODO */
}

void PF1550_Control::onTemperatureMonitorEvent()
{
  /* TODO */
}

void PF1550_Control::onMiscellaneousEvent()
{
  /* TODO */
}
