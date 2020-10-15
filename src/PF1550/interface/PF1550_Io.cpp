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
#include "PF1550_Io.h"

#include <assert.h>

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

namespace interface
{

/******************************************************************************
   PUBLIC MEMBER FUNCTIONS
 ******************************************************************************/

void PF1550_Io::setBit(Register const reg, uint8_t const bit_pos)
{
  assert(bit_pos < 8);
  uint8_t reg_val;
  readRegister(reg, &reg_val);
  reg_val |= (1<<bit_pos);

  uint8_t i2c_data[2];
  i2c_data[0] = (uint8_t)reg;
  i2c_data[1] = reg_val;
  writeRegister(PF1550_I2C_ADDR, i2c_data, 2, 0);
}

void PF1550_Io::clrBit(Register const reg, uint8_t const bit_pos)
{
  assert(bit_pos < 8);
  uint8_t reg_val;
  readRegister(reg, &reg_val);
  reg_val &= ~(1<<bit_pos);

  uint8_t i2c_data[2];
  i2c_data[0] = (uint8_t)reg;
  i2c_data[1] = reg_val;
  writeRegister(PF1550_I2C_ADDR, i2c_data, 2, 0);
}

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

} /* interface */
