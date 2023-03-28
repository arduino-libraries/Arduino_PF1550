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
  uint8_t i2c_data[2];

  i2c_data[0] = (uint8_t)reg_addr;

  writeRegister(_i2c_addr, i2c_data, 1, 1);

  uint8_t retVal = _wire->requestFrom(_i2c_addr, 1, true);

  if (_debug) {
    _debug->print("requestFrom: ");
    _debug->println(retVal);
  }

  int i = 0;
  while (_wire->available() && i < 1) {
    data[0] = _wire->read();
    i++;
  }

  if (_debug) {
    _debug->println("Read:");
    for (i = 0; i < 1; i++) {
      _debug->println(data[i], HEX);
    }
  }
}

void PF1550_IO::writeRegister(uint8_t slave_addr, uint8_t *data, uint8_t data_len, uint8_t restart)
{
  if (_debug)
  {
    _debug->print("Restart: ");
    _debug->println(restart);
    if (!restart)
    {
      _debug->print("PF1550_IO_C33::writeRegister at address=");
      _debug->print(data[0], HEX);
      _debug->print(" data=");
      _debug->println(data[1], HEX);
      _debug->print("i2c slave address: ");
      _debug->println(slave_addr);
    }
    else
    {
      _debug->print("PF1550_IO_C33::Read from register at address=");
      _debug->println(data[0], HEX);
    }
  }

  _wire->beginTransmission(slave_addr);
  _wire->write(data, data_len);
  uint8_t retVal = _wire->endTransmission(restart == 0 ? true : false);

  if (_debug) {
    _debug->print("End transmission: ");
    _debug->println(retVal);
  }
  /*
    if (_debug) {
    _debug->println("Write:");
    for (int i = 0; i < data_len; i++) {
      _debug->println(data[i], HEX);
    }
    }
  */
}

void PF1550_IO::setBit(Register const reg, uint8_t const bit_pos)
{
  assert(bit_pos < 8);
  uint8_t reg_val;
  readRegister(reg, &reg_val);
  reg_val |= (1<<bit_pos);

  uint8_t i2c_data[2];
  i2c_data[0] = (uint8_t)reg;
  i2c_data[1] = reg_val;
  writeRegister(_i2c_addr, i2c_data, 2, 0);
}

void PF1550_IO::clrBit(Register const reg, uint8_t const bit_pos)
{
  assert(bit_pos < 8);
  uint8_t reg_val;
  readRegister(reg, &reg_val);
  reg_val &= ~(1<<bit_pos);

  uint8_t i2c_data[2];
  i2c_data[0] = (uint8_t)reg;
  i2c_data[1] = reg_val;
  writeRegister(_i2c_addr, i2c_data, 2, 0);
}
