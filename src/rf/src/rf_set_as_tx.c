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
// void rf_set_as_tx()
//
// Description:
//  Sets the device as a TX
//
// Parameters:
//  None
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_set_as_tx()
{
	uint8_t config;
	uint8_t ce_status = rf_get_ce();

	rf_read_register(RF_CONFIG, &config, 1); //Read the current CONFIG value

	//If the device is already configured as a TX, exit
	if((config & RF_CONFIG_PRIM_RX) == 0)
	{
		return;
	}

	rf_clear_ce(); //Clear the CE pin to enter TX mode

	//Clear the PRIM_RX bit, then write the old value of CONFIG back to the device
	config &= (~RF_CONFIG_PRIM_RX);
	rf_write_register(RF_CONFIG, &config, 1);

	//Set the CE pin if it was set coming into this function
	if(ce_status)
	{
		rf_set_ce();
	}
}
