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

#ifndef PF1550_IO_C33_H_
#define PF1550_IO_C33_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "Arduino.h"
#include "interface/PF1550_Io.h"

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550_Io_C33 : public interface::PF1550_Io
{
public:
  PF1550_Io_C33(uint8_t const i2c_addr);
  virtual ~PF1550_Io_C33() { }

  virtual int  begin        () override;
  virtual void debug        (Stream& stream) override;
  virtual void readRegister (Register const reg_addr, uint8_t * data) override;
  virtual void writeRegister(uint8_t slave_addr, uint8_t * data, uint8_t data_len, uint8_t restart) override;
  virtual void setSTANDBY   () override { }
  virtual void clrSTANDBY   () override { }


private:

  uint8_t const _i2c_addr;
  Stream * _debug;
};

#endif /* PF1550_IO_C33_H_ */
