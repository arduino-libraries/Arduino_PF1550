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

#include "PF1550_Io_EnvieH747.h"
#include "PF1550.h"
#include <Arduino.h>
#include <Wire.h>

/******************************************************************************
   CTOR/DTOR
 ******************************************************************************/

PF1550_Io_EnvieH747::PF1550_Io_EnvieH747(uint8_t const i2c_addr)
: _i2c_addr(i2c_addr)
{

}

/******************************************************************************
   PUBLIC MEMBER FUNCTIONS
 ******************************************************************************/

int PF1550_Io_EnvieH747::begin()
{
  Wire1.begin();
  return 1;
}

uint8_t PF1550_Io_EnvieH747::readRegister(Register const reg)
{
  Wire1.beginTransmission(_i2c_addr >> 1);
  Wire1.write(static_cast<uint8_t>(reg));
  Wire1.endTransmission();
  Wire1.requestFrom(_i2c_addr >> 1, 1);
  uint8_t const reg_val = Wire1.available() ? Wire1.read() : 0;
  return reg_val;
}

void PF1550_Io_EnvieH747::writeRegister(Register const reg, uint8_t const val)
{
  Wire1.beginTransmission(_i2c_addr >> 1);
  Wire1.write(static_cast<uint8_t>(reg));
  Wire1.write(val);
  Wire1.endTransmission();
}

void PF1550_Io_EnvieH747::setSTANDBY()
{
  /* TODO: Use STM32H7 HAL to set PJ0 */
}

void PF1550_Io_EnvieH747::clrSTANDBY()
{
  /* TODO: Use STM32H7 HAL to clr PJ0 */
}
