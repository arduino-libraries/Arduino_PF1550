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

#ifndef PF1550_IO_NICLA_VISION_H_
#define PF1550_IO_NICLA_VISION_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "PF1550_IO.h"

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550_IO_Nicla_Vision : public PF1550_IO
{
public:
  PF1550_IO_Nicla_Vision(arduino::HardwareI2C * wire, uint8_t const i2c_addr) : PF1550_IO(wire, i2c_addr) { }
  virtual ~PF1550_IO_Nicla_Vision() { }


protected:
  virtual void derived_begin() override { }
};

#endif /* PF1550_IO_NICLA_VISION_H_ */
