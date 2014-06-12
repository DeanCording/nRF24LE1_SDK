////////////////////////////////////////////////////////////////////////////////////
//
// File: owi_crc.c
//
// Copyright Aleksandr Svalov (Alarus), 2014
//
// The author provides no guarantees, warantees, or promises, implied or
// otherwise.  By using this software you agree to indemnify the author
// of any damages incurred by using it.
//
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
////////////////////////////////////////////////////////////////////////////////////

#include "owi.h"


////////////////////////////////////////////////////////////////////////////////////
//
// uint8_t owi_crc(uint8_t data, uint8_t seed)
//
// Description:
//  Compute the CRC value of a data set
//
// Parameters:
//  uint8_t data - One byte of data to compute CRC from
//  uint8_t seed - The starting value of the CRC
//
// Return value:
//  uint8_t seed - The CRC of data with seed as initial value
//
////////////////////////////////////////////////////////////////////////////////////
uint8_t owi_crc(uint8_t data, uint8_t seed)
{
	register uint8_t i;
	
	for (i = 8; i; i--)
	{
		if (((seed ^ data) & 0x01))
		{
			seed ^= 0x18;
			seed >>= 1;
			seed |= 0x80;
		}
		else
		{
			seed >>= 1;
		}
		data >>= 1;
	}
	return seed;
}
