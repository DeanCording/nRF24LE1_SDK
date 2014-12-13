/////////////////////////////////////////////////////////////////////////////
//
// File: rf_read_register.c
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
// void rf_set_rx_addr(uint8_t * address, uint16_t len, uint8_t rxpipenum)
//
// Description:
//  Sets the device's RX address on the specified pipe
//
// Parameters:
//  uint8_t * address - pointer to the address for the pipe
//  uint16_t len - number of bytes for the address
//  uint8_t rxpipenum - pipe number to which the address should be written
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_set_rx_addr(uint8_t * address, uint16_t len, uint8_t rxpipenum)
{
	//Do not allow writes to pipes that don't exist
	if(rxpipenum > 5)
	{
		return;
	}

	rf_write_register(RF_RX_ADDR_P0 + rxpipenum, address, len); //Write the requested address to the requested RX pipe
}
