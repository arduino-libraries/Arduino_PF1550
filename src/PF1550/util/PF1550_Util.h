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

#ifndef PF1550_UTIL_H_
#define PF1550_UTIL_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>

/******************************************************************************
   FUNCTION PROTOTYPES
 ******************************************************************************/

inline bool isBitSet(uint8_t const val, uint8_t const bit_pos)
{
  uint8_t const bit_mask = (1 << bit_pos);
  return ((val & bit_mask) == bit_mask);
}

inline bool isBitClr(uint8_t const val, uint8_t const bit_pos)
{
  return !isBitSet(val, bit_pos);
}

#endif /* PF1550_UTIL_H_ */
