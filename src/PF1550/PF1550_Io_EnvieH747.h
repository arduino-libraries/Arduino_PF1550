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

#ifndef PF1550_IO_ENVIEH747_H_
#define PF1550_IO_ENVIEH747_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "interface/PF1550_Io.h"

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

namespace PF1550
{

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550_Io_EnvieH747 : public interface::PF1550_Io
{

public:

           PF1550_Io_EnvieH747(uint8_t const i2c_addr = interface::PF1550_I2C_DEFAULT_ADDR);
  virtual ~PF1550_Io_EnvieH747() { }

  virtual int     begin        ()                                      override;
  virtual uint8_t readRegister (Register const reg)                    override;
  virtual void    writeRegister(Register const reg, uint8_t const val) override;

private:

  uint8_t const _i2c_addr;

};

/******************************************************************************
   NAMESPACE
 ******************************************************************************/

} /* PF1550 */

#endif /* PF1550_IO_ENVIEH747_H_ */
