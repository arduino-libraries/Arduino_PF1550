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
  DEVICE_ID         = 0x00,
  OTP_FLAVOR        = 0x01,
  SILICON_REV       = 0x02,
  INT_CATEGORY      = 0x06,
  SW_INT_STAT0      = 0x08,
  SW_INT_MASK0      = 0x09,
  SW_INT_SENSE0     = 0x0A,
  SW_INT_STAT1      = 0x0B,
  SW_INT_MASK1      = 0x0C,
  SW_INT_SENSE1     = 0x0D,
  SW_INT_STAT2      = 0x0E,
  SW_INT_MASK2      = 0x0F,
  SW_INT_SENSE2     = 0x10,
  LDO_INT_STAT0     = 0x18,
  LDO_INT_MASK0     = 0x19,
  LDO_INT_SENSE0    = 0x1A,
  TEMP_INT_STAT0    = 0x20,
  TEMP_INT_MASK0    = 0x21,
  TEMP_INT_SENSE0   = 0x22,
  ONKEY_INT_STAT0   = 0x24,
  ONKEY_INT_MASK0   = 0x25,
  ONKEY_INT_SENSE0  = 0x26,
  MISC_INT_STAT0    = 0x28,
  MISC_INT_MASK0    = 0x29,
  MISC_INT_SENSE0   = 0x2A,
  COINCELL_CONTROL  = 0x30,
  SW1_VOLT          = 0x32,
  SW1_STBY_VOLT     = 0x33,
  SW1_SLP_VOLT      = 0x34,
  SW1_CTRL          = 0x35,
  SW1_CTRL1         = 0x36,
  SW2_VOLT          = 0x38,
  SW2_STBY_VOLT     = 0x39,
  SW2_SLP_VOLT      = 0x3A,
  SW2_CTRL          = 0x3B,
  SW2_CTRL1         = 0x3C,
  SW3_VOLT          = 0x3E,
  SW3_STBY_VOLT     = 0x3F,
  SW3_SLP_VOLT      = 0x40,
  SW3_CTRL          = 0x41,
  SW3_CTRL1         = 0x42,
  VSNVS_CTRL        = 0x48,
  VREFDDR_CTRL      = 0x4A,
  LDO1_VOLT         = 0x4C,
  LDO1_CTRL         = 0x4D,
  LDO2_VOLT         = 0x4F,
  LDO2_CTRL         = 0x50,
  LDO3_VOLT         = 0x52,
  LDO3_CTRL         = 0x53,
  PWRCTRL0          = 0x58,
  PWRCTRL1          = 0x59,
  PWRCTRL2          = 0x5A,
  PWRCTRL3          = 0x5B,
  SW1_PWRDN_SEQ     = 0x5F,
  SW2_PWRDN_SEQ     = 0x60,
  SW3_PWRDN_SEQ     = 0x61,
  LDO1_PWRDN_SEQ    = 0x62,
  LDO2_PWRDN_SEQ    = 0x63,
  LDO3_PWRDN_SEQ    = 0x64,
  VREFDDR_PWRDN_SEQ = 0x65,
  STATE_INFO        = 0x67,
  I2C_ADDR          = 0x68,
  RC_16MHZ          = 0x6B,
  KEY1              = 0x6B,
};

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

} /* PF1550 */

#endif /* PF1550_REGISTER_H_ */
