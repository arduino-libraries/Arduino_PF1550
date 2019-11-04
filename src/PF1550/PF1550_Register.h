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

#ifndef PF1550_REGISTER_H_
#define PF1550_REGISTER_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include <stdint.h>

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

namespace PF1550
{

/******************************************************************************
   TYPEDEF
 ******************************************************************************/

enum class Register : uint8_t
{
  /* PMIC Register Adresses */
  PMIC_DEVICE_ID         = 0x00,
  PMIC_OTP_FLAVOR        = 0x01,
  PMIC_SILICON_REV       = 0x02,
  PMIC_INT_CATEGORY      = 0x06,
  PMIC_SW_INT_STAT0      = 0x08,
  PMIC_SW_INT_MASK0      = 0x09,
  PMIC_SW_INT_SENSE0     = 0x0A,
  PMIC_SW_INT_STAT1      = 0x0B,
  PMIC_SW_INT_MASK1      = 0x0C,
  PMIC_SW_INT_SENSE1     = 0x0D,
  PMIC_SW_INT_STAT2      = 0x0E,
  PMIC_SW_INT_MASK2      = 0x0F,
  PMIC_SW_INT_SENSE2     = 0x10,
  PMIC_LDO_INT_STAT0     = 0x18,
  PMIC_LDO_INT_MASK0     = 0x19,
  PMIC_LDO_INT_SENSE0    = 0x1A,
  PMIC_TEMP_INT_STAT0    = 0x20,
  PMIC_TEMP_INT_MASK0    = 0x21,
  PMIC_TEMP_INT_SENSE0   = 0x22,
  PMIC_ONKEY_INT_STAT0   = 0x24,
  PMIC_ONKEY_INT_MASK0   = 0x25,
  PMIC_ONKEY_INT_SENSE0  = 0x26,
  PMIC_MISC_INT_STAT0    = 0x28,
  PMIC_MISC_INT_MASK0    = 0x29,
  PMIC_MISC_INT_SENSE0   = 0x2A,
  PMIC_COINCELL_CONTROL  = 0x30,
  PMIC_SW1_VOLT          = 0x32,
  PMIC_SW1_STBY_VOLT     = 0x33,
  PMIC_SW1_SLP_VOLT      = 0x34,
  PMIC_SW1_CTRL          = 0x35,
  PMIC_SW1_CTRL1         = 0x36,
  PMIC_SW2_VOLT          = 0x38,
  PMIC_SW2_STBY_VOLT     = 0x39,
  PMIC_SW2_SLP_VOLT      = 0x3A,
  PMIC_SW2_CTRL          = 0x3B,
  PMIC_SW2_CTRL1         = 0x3C,
  PMIC_SW3_VOLT          = 0x3E,
  PMIC_SW3_STBY_VOLT     = 0x3F,
  PMIC_SW3_SLP_VOLT      = 0x40,
  PMIC_SW3_CTRL          = 0x41,
  PMIC_SW3_CTRL1         = 0x42,
  PMIC_VSNVS_CTRL        = 0x48,
  PMIC_VREFDDR_CTRL      = 0x4A,
  PMIC_LDO1_VOLT         = 0x4C,
  PMIC_LDO1_CTRL         = 0x4D,
  PMIC_LDO2_VOLT         = 0x4F,
  PMIC_LDO2_CTRL         = 0x50,
  PMIC_LDO3_VOLT         = 0x52,
  PMIC_LDO3_CTRL         = 0x53,
  PMIC_PWRCTRL0          = 0x58,
  PMIC_PWRCTRL1          = 0x59,
  PMIC_PWRCTRL2          = 0x5A,
  PMIC_PWRCTRL3          = 0x5B,
  PMIC_SW1_PWRDN_SEQ     = 0x5F,
  PMIC_SW2_PWRDN_SEQ     = 0x60,
  PMIC_SW3_PWRDN_SEQ     = 0x61,
  PMIC_LDO1_PWRDN_SEQ    = 0x62,
  PMIC_LDO2_PWRDN_SEQ    = 0x63,
  PMIC_LDO3_PWRDN_SEQ    = 0x64,
  PMIC_VREFDDR_PWRDN_SEQ = 0x65,
  PMIC_STATE_INFO        = 0x67,
  PMIC_I2C_ADDR          = 0x68,
  PMIC_RC_16MHZ          = 0x6B,
  PMIC_KEY1              = 0x6B,
  /* Charger Register Adresses */
  CHARGER_CHG_INT           = 0x80 + 0x00,
  CHARGER_CHG_INT_MASK      = 0x80 + 0x02,
  CHARGER_CHG_INT_OK        = 0x80 + 0x04,
  CHARGER_VBUS_SNS          = 0x80 + 0x06,
  CHARGER_CHG_SNS           = 0x80 + 0x07,
  CHARGER_BATT_SNS          = 0x80 + 0x08,
  CHARGER_CHG_OPER          = 0x80 + 0x09,
  CHARGER_CHG_TMR           = 0x80 + 0x0A,
  CHARGER_CHG_EOC_CNFG      = 0x80 + 0x0D,
  CHARGER_CHG_CURR_CFG      = 0x80 + 0x0E,
  CHARGER_BATT_REG          = 0x80 + 0x0F,
  CHARGER_BATFET_CNFG       = 0x80 + 0x11,
  CHARGER_THM_REG_CNFG      = 0x80 + 0x12,
  CHARGER_VBUS_INLIM_CNFG   = 0x80 + 0x14,
  CHARGER_VBUS_LIN_DPM      = 0x80 + 0x15,
  CHARGER_USB_PHY_LDO_CNFG  = 0x80 + 0x16,
  CHARGER_DBNC_DELAY_TIME   = 0x80 + 0x18,
  CHARGER_CHG_INT_CNFG      = 0x80 + 0x19,
  CHARGER_THM_ADJ_SETTING   = 0x80 + 0x1A,
  CHARGER_VBUS2SYS_CNFG     = 0x80 + 0x1B,
  CHARGER_LED_PWM           = 0x80 + 0x1C,
  CHARGER_FAULT_BATFET_CNFG = 0x80 + 0x1D,
  CHARGER_LED_CNFG          = 0x80 + 0x1E,
  CHARGER_CHGR_KEY2         = 0x80 + 0x1F,
};

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

} /* PF1550 */

#endif /* PF1550_REGISTER_H_ */
