/////////////////////////////////////////////////////////////////////////////
//
// File: rf_get_all_registers.c
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
// void rf_get_all_registers(uint8_t * dataptr)
//
// Description:
//  Reads all the registers from RF and copies them to dataptr
//
// Parameters:
//  uint8_t * dataptr - pointer to which received register data will be copied (should be at least 36 bytes long)
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_get_all_registers(uint8_t * dataptr)
{
	uint8_t i, j, k = 0;
	uint8_t buffer[5];

	//There are 0x18 registers in the device (some are one byte, and others are up to 5 bytes)
	for(i = 0; i <= 0x17; i++)
	{
		rf_read_register(i, buffer, 5); //Get the register value

		//Loop for 5 bytes in case we're copying a 5-byte value
		for(j = 0; j < 5; j++)
		{
			//Update the value in the pointer, and then update k (which acts as the index of the next write)
			dataptr[k] = buffer[j];
			k++;

			//If the current address isn't RX_ADDR_P0, RX_ADDR_P1, or TX_ADDR, then break, since the other registers are only 1 byte long
			if((i != RF_RX_ADDR_P0) && (i != RF_RX_ADDR_P1) && (i != RF_TX_ADDR))
			{
				break;
			}
		}
	}
}
