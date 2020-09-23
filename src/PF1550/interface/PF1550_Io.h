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

#include "Arduino.h"
#include "../PF1550_Register.h"

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

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

  virtual int     begin        ()                                                                     = 0;
  virtual void    debug        (Stream& stream)                                                       = 0;
  virtual void    readRegister (Register const reg_addr, uint8_t *data)                               = 0;
  virtual void    writeRegister(uint8_t slave_addr, uint8_t *data, uint8_t data_len, uint8_t restart) = 0;
  virtual void    setSTANDBY   ()                                                                     = 0;
  virtual void    clrSTANDBY   ()                                                                     = 0;

          void    setBit       (Register const reg, uint8_t const bit_pos);
          void    clrBit       (Register const reg, uint8_t const bit_pos);

};

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

} /* interface */

#endif /* ARDUINO_PF1550_INTERFACE_PF1550_IO_H_ */
