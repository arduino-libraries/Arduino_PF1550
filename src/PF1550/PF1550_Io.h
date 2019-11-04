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

#ifndef PF1550_IO_H
#define PF1550_IO_H

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "PF1550_Register.h"

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

namespace PF1550
{

/******************************************************************************
   CONSTANTS
 ******************************************************************************/

static uint8_t const PF1550_I2C_DEFAULT_ADDR = 0x08;

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550_Io
{

public:

  PF1550_Io(uint8_t const i2c_addr = PF1550_I2C_DEFAULT_ADDR);

  int     begin        ();

  uint8_t readRegister (Register const reg);
  void    writeRegister(Register const reg, uint8_t const val);

  void    setBit       (Register const reg, uint8_t const bit_pos);
  void    clrBit       (Register const reg, uint8_t const bit_pos);

private:

  uint8_t _i2c_addr;

};

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

} /* PF1550 */

#endif /* PF1550_IO_H */
