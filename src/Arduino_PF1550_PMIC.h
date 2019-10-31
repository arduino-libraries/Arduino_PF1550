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

#ifndef ARDUINO_PF1550_PMIC_H_
#define ARDUINO_PF1550_PMIC_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "PF1550/PF1550_IO.h"
#include "PF1550/PF1550_Const.h"

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class Arduino_PF1550_PMIC
{
public:

  Arduino_PF1550_PMIC();

  int begin();

  void setLDO1Voltage(PF1550::LDO_1_Voltage const ldo1_volt);

private:

  PF1550::PF1550_IO _io;

};

/******************************************************************************
   EXTERN DECLARATION
 ******************************************************************************/

extern Arduino_PF1550_PMIC PMIC;

#endif /* ARDUINO_PF1550_PMIC_H_ */
