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

#include <Arduino.h>

#include "api/HardwareI2C.h"

#include "PF1550_Register.h"

/******************************************************************************
   CONSTANTS
 ******************************************************************************/

static uint8_t const PF1550_I2C_DEFAULT_ADDR = 0x08;

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550_IO
{
public:

  PF1550_IO(arduino::HardwareI2C * wire, uint8_t const i2c_addr);
  virtual ~PF1550_IO() { }


  void debug (Stream& stream) { _debug = &stream; }


  int begin();

  void readRegister (Register const reg_addr, uint8_t * data);
  void writeRegister(Register const reg_addr, uint8_t const data);

  void setBit(Register const reg, uint8_t const bit_pos);
  void clrBit(Register const reg, uint8_t const bit_pos);


protected:
  virtual int derived_begin() = 0;

private:
  arduino::HardwareI2C * _wire;
  uint8_t const _i2c_addr;
  Stream * _debug;
};

#endif /* ARDUINO_PF1550_INTERFACE_PF1550_IO_H_ */
