/////////////////////////////////////////////////////////////////////////////
//
// File: rf_read_register_1_byte.c
//
// Copyright S. Brennen Ball, 2011
//
// The author provides no guarantees, warantees, or promises, implied or
//  otherwise.  By using this software you agree to indemnify the author
//  of any damages incurred by using it.
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////

#include "rf.h"
#include "rf_src.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// uint8_t rf_read_register_1_byte(uint8_t regnumber)
//
// Description:
//  Reads the value from a single-byte register (or the first byte from a multi-byte register)
//
// Parameters:
//  uint8_t regnumber - number of the register to be read
//
// Return value:
//  Read value of the requested register
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rf_read_register_1_byte(uint8_t regnumber)
{
	uint8_t reg_val;

	//Read the specified register
	rf_read_register(regnumber, &reg_val, 1);

	return reg_val;
}
