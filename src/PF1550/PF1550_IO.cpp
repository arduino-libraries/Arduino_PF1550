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
#include "PF1550_IO.h"

#include <assert.h>

/******************************************************************************
   CTOR/DTOR
 ******************************************************************************/

PF1550_IO::PF1550_IO(arduino::HardwareI2C * wire, uint8_t const i2c_addr)
: _wire{wire}
, _i2c_addr{i2c_addr}
, _debug{nullptr}
{

}

/******************************************************************************
   PUBLIC MEMBER FUNCTIONS
 ******************************************************************************/

int PF1550_IO::begin()
{
  _wire->begin();
  _wire->setClock(100000);
  return derived_begin();
}

void PF1550_IO::readRegister(Register const reg_addr, uint8_t * data)
{
  _wire->beginTransmission(_i2c_addr);
  _wire->write(static_cast<uint8_t>(reg_addr));
  _wire->endTransmission(false); /* No Stop. */

  _wire->requestFrom(_i2c_addr, 1, true);
  while (_wire->available() < 1) { }
  *data = _wire->read();
}

void PF1550_IO::writeRegister(Register const reg_addr, uint8_t const data)
{
  _wire->beginTransmission(_i2c_addr);
  _wire->write(static_cast<uint8_t>(reg_addr));
  _wire->write(data);
  _wire->endTransmission(true);
}

void PF1550_IO::setBit(Register const reg, uint8_t const bit_pos)
{
  assert(bit_pos < 8);
  uint8_t reg_val;
  readRegister(reg, &reg_val);
  reg_val |= (1<<bit_pos);

  writeRegister(reg, reg_val);
}

void PF1550_IO::clrBit(Register const reg, uint8_t const bit_pos)
{
  assert(bit_pos < 8);
  uint8_t reg_val;
  readRegister(reg, &reg_val);
  reg_val &= ~(1<<bit_pos);

  writeRegister(reg, reg_val);
}
