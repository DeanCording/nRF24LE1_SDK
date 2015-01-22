/////////////////////////////////////////////////////////////////////////////
//
// File: rf_power_up_param.c
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
#include "pwr_clk_mgmt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void rf_power_up_param(bool rx_active_mode, uint8_t config)
//
// Description:
//  Powers up the device, but allows the user to pass in the value sent to the CONFIG register, as well as whether or not to go to
//   RX active mode (if RX is desired)
//
// Parameters:
//  bool rx_active_mode - true to take to RX active mode (if RX), false otherwise
//  uint8_t config - value to be written to the CONFIG register (the PWR_UP bit will obviously be cleared)
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_power_up_param(bool rx_active_mode, uint8_t config)
{
	//Force the value of PWR_UP set in the passed in version of config, then write the value
	config |= RF_CONFIG_PWR_UP;
	rf_write_register(RF_CONFIG, &config, 1);

	while(!pwr_clk_mgmt_is_cclk_src_xosc16m()); //wait for the clock to get switched to the 16 MHz crystal, otherwise the RF can't be run

	//Operate CE based on whether RX standby/RX active/TX is requested
	if((config & RF_CONFIG_PRIM_RX) == 0)
	{
		rf_clear_ce(); //Clear CE for TX mode
	}
	else
	{
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

	delay_us(1); //Delay for power up
}
