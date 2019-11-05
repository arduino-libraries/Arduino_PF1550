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

#ifndef PF1550_CONTROL_H_
#define PF1550_CONTROL_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "PF1550_Types.h"
#include "interface/PF1550_Io.h"

/******************************************************************************
   CLASS DECLARATION
 ******************************************************************************/

class PF1550_Control
{

public:

  PF1550_Control(interface::PF1550_Io & io);


  /* LDO1 Configuration *******************************************************/
  void setLDO1Voltage   (Ldo1Voltage const ldo1_volt);
  void turnLDO1On       (Ldo1Mode    const mode);
  void turnLDO1Off      (Ldo1Mode    const mode);
  /* LDO2 Configuration *******************************************************/
  void setLDO2Voltage   (Ldo2Voltage const ldo2_volt);
  void turnLDO2On       (Ldo2Mode    const mode);
  void turnLDO2Off      (Ldo2Mode    const mode);
  /* LDO3 Configuration *******************************************************/
  void setLDO3Voltage   (Ldo3Voltage const ldo3_volt);
  void turnLDO3On       (Ldo3Mode    const mode);
  void turnLDO3Off      (Ldo3Mode    const mode);


private:

  interface::PF1550_Io & _io;

};

#endif /* PF1550_CONTROL_H_ */
