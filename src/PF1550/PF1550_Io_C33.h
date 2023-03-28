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

#include "interface/PF1550_Io.h"

#include "PF1550_Defines.h"

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550_Io_C33 : public interface::PF1550_Io
{
public:
  PF1550_Io_C33(arduino::HardwareI2C * wire, uint8_t const i2c_addr) : interface::PF1550_Io(wire, i2c_addr) { }
  virtual ~PF1550_Io_C33() { }


protected:
  virtual int derived_begin() override
  {
    /* Enable LED. */
    setBit(Register::CHARGER_LED_PWM, REG_LED_PWM_LED_EN_bp);
    /* Allow LED control by software. */
    setBit(Register::CHARGER_LED_CNFG, REG_LED_CNFG_LEDOVRD_bp);
  }

};

#endif /* PF1550_IO_C33_H_ */
