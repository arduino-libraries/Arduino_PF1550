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

#ifndef ARDUINO_PF1550_INTERFACE_PF1550_IO_H_
#define ARDUINO_PF1550_INTERFACE_PF1550_IO_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "../PF1550_Register.h"

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

namespace PF1550
{

namespace interface
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

  virtual ~PF1550_Io() { }

  virtual int     begin        ()                                      = 0;
  virtual uint8_t readRegister (Register const reg)                    = 0;
  virtual void    writeRegister(Register const reg, uint8_t const val) = 0;

          void    setBit       (Register const reg, uint8_t const bit_pos);
          void    clrBit       (Register const reg, uint8_t const bit_pos);

};

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

} /* interface */

} /* PF1550 */

#endif /* ARDUINO_PF1550_INTERFACE_PF1550_IO_H_ */
