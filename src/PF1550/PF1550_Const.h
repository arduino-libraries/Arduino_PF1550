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

#ifndef PF1550_CONST_H_
#define PF1550_CONST_H_

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
   DEFINE
 ******************************************************************************/

/* LDO1_CTRL ******************************************************************/
#define REG_LDO1_CTRL_VLDO1_EN_bp       (0)
#define REG_LDO1_CTRL_VLDO1_STBY_EN_bp  (1)
#define REG_LDO1_CTRL_VLDO1_OMODE_bp    (2)

/* LDO2_CTRL ******************************************************************/
#define REG_LDO2_CTRL_VLDO2_EN_bp       (0)
#define REG_LDO2_CTRL_VLDO2_STBY_EN_bp  (1)
#define REG_LDO2_CTRL_VLDO2_OMODE_bp    (2)

/* LDO3_CTRL ******************************************************************/
#define REG_LDO3_CTRL_VLDO3_EN_bp       (0)
#define REG_LDO3_CTRL_VLDO3_STBY_EN_bp  (1)
#define REG_LDO3_CTRL_VLDO3_OMODE_bp    (2)

/* CHG_CURR_CFG ***************************************************************/
#define REG_CHG_CURR_CFG_CHG_CC_mask    (0x1F)

/* BATT_REG *******************************************************************/
#define REG_BATT_REG_CHCCV_mask         (0x3F)

/******************************************************************************
   TYPEDEF
 ******************************************************************************/

enum class Ldo1Voltage : uint8_t
{
  V_0_75 = 0x00,
  V_0_80 = 0x01,
  V_0_85 = 0x02,
  V_0_90 = 0x03,
  V_0_95 = 0x04,
  V_1_00 = 0x05,
  V_1_05 = 0x06,
  V_1_10 = 0x07,
  V_1_15 = 0x08,
  V_1_20 = 0x09,
  V_1_25 = 0x0A,
  V_1_30 = 0x0B,
  V_1_35 = 0x0C,
  V_1_40 = 0x0D,
  V_1_45 = 0x0E,
  V_1_50 = 0x0F,
  V_1_80 = 0x10,
  V_1_90 = 0x11,
  V_2_00 = 0x12,
  V_2_10 = 0x13,
  V_2_20 = 0x14,
  V_2_30 = 0x15,
  V_2_40 = 0x16,
  V_2_50 = 0x17,
  V_2_60 = 0x18,
  V_2_70 = 0x19,
  V_2_80 = 0x1A,
  V_2_90 = 0x1B,
  V_3_00 = 0x1C,
  V_3_10 = 0x1D,
  V_3_20 = 0x1E,
  V_3_30 = 0x1F,
};

enum class Ldo1Mode : uint8_t
{
  Normal  = REG_LDO1_CTRL_VLDO1_EN_bp,
  Standby = REG_LDO1_CTRL_VLDO1_STBY_EN_bp,
  Sleep   = REG_LDO1_CTRL_VLDO1_OMODE_bp,
};

enum class Ldo2Voltage : uint8_t
{
  V_1_80 = 0x00,
  V_1_90 = 0x01,
  V_2_00 = 0x02,
  V_2_10 = 0x03,
  V_2_20 = 0x04,
  V_2_30 = 0x05,
  V_2_40 = 0x06,
  V_2_50 = 0x07,
  V_2_60 = 0x08,
  V_2_70 = 0x09,
  V_2_80 = 0x0A,
  V_2_90 = 0x0B,
  V_3_00 = 0x0C,
  V_3_10 = 0x0D,
  V_3_20 = 0x0E,
  V_3_30 = 0x0F,
};

enum class Ldo2Mode : uint8_t
{
  Normal  = REG_LDO2_CTRL_VLDO2_EN_bp,
  Standby = REG_LDO2_CTRL_VLDO2_STBY_EN_bp,
  Sleep   = REG_LDO2_CTRL_VLDO2_OMODE_bp,
};

typedef Ldo1Voltage Ldo3Voltage; /* LDO1 and LDO3 have the same voltage steps */

enum class Ldo3Mode : uint8_t
{
  Normal  = REG_LDO3_CTRL_VLDO3_EN_bp,
  Standby = REG_LDO3_CTRL_VLDO3_STBY_EN_bp,
  Sleep   = REG_LDO3_CTRL_VLDO3_OMODE_bp,
};

enum class IFastCharge : uint8_t
{
  I_100_mA  = 0x00,
  I_150_mA  = 0x01,
  I_200_mA  = 0x02,
  I_250_mA  = 0x03,
  I_300_mA  = 0x04,
  I_350_mA  = 0x05,
  I_400_mA  = 0x06,
  I_450_mA  = 0x07,
  I_500_mA  = 0x08,
  I_550_mA  = 0x09,
  I_600_mA  = 0x0A,
  I_650_mA  = 0x0B,
  I_700_mA  = 0x0C,
  I_750_mA  = 0x0D,
  I_800_mA  = 0x0E,
  I_850_mA  = 0x0F,
  I_900_mA  = 0x10,
  I_950_mA  = 0x11,
  I_1000_mA = 0x12,
};

enum class VFastCharge : uint8_t
{
  V_3_50 = 0x08,
  V_3_52 = 0x09,
  V_3_54 = 0x0A,
  V_3_56 = 0x0B,
  V_3_58 = 0x0C,
  V_3_60 = 0x0D,
  V_3_62 = 0x0E,
  V_3_64 = 0x0F,
  V_3_66 = 0x10,
  V_3_68 = 0x11,
  V_3_70 = 0x12,
  V_3_72 = 0x13,
  V_3_74 = 0x14,
  V_3_76 = 0x15,
  V_3_78 = 0x16,
  V_3_80 = 0x17,
  V_3_82 = 0x18,
  V_3_84 = 0x19,
  V_3_86 = 0x1A,
  V_3_88 = 0x1B,
  V_3_90 = 0x1C,
  V_3_92 = 0x1D,
  V_3_94 = 0x1E,
  V_3_96 = 0x1F,
  V_3_98 = 0x20,
  V_4_00 = 0x21,
  V_4_02 = 0x22,
  V_4_04 = 0x23,
  V_4_06 = 0x24,
  V_4_08 = 0x25,
  V_4_10 = 0x26,
  V_4_12 = 0x27,
  V_4_14 = 0x28,
  V_4_16 = 0x29,
  V_4_18 = 0x2A,
  V_4_20 = 0x2B,
  V_4_22 = 0x2C,
  V_4_24 = 0x2D,
  V_4_26 = 0x2E,
  V_4_28 = 0x2F,
  V_4_30 = 0x30,
  V_4_32 = 0x31,
  V_4_34 = 0x32,
  V_4_36 = 0x33,
  V_4_38 = 0x34,
  V_4_40 = 0x35,
  V_4_42 = 0x36,
  V_4_44 = 0x37,
};

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

} /* PF1550 */

#endif /* PF1550_CONST_H_ */
