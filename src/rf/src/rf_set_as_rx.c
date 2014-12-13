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
// void rf_set_as_rx(bool rx_active_mode)
//
// Description:
//  Sets the device as an RX, giving the user the option to go into active or standby mode
//
// Parameters:
//  bool rx_active_mode - true to take to RX active mode (if RX), false otherwise
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_set_as_rx(bool rx_active_mode)
{
	uint8_t config;

	rf_read_register(RF_CONFIG, &config, 1); //Read the current CONFIG value

	//Only update the CONFIG register if the device isn't already an RX
	if((config & RF_CONFIG_PRIM_RX) != RF_CONFIG_PRIM_RX)
	{
		//Set the PRIM_RX bit, then write the old value of CONFIG back to the device
		config |= RF_CONFIG_PRIM_RX;
		rf_write_register(RF_CONFIG, &config, 1);
	}

	//Set the CE pin if active RX mode is requested, and clear it otherwise
	if(rx_active_mode)
	{
		//Since setting CE requires a 4 uS delay, only set it if necessary
		if(!rf_get_ce())
		{
			rf_set_ce();
		}
	}
	else
	{
		rf_clear_ce();
	}
}
