/////////////////////////////////////////////////////////////////////////////
//
// File: rf_power_up.c
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
// void rf_power_up(bool rx_active_mode)
//
// Description:
//  Powers up the device, and allows the user to select whether or not to go to RX active mode (if RX is desired)
//
// Parameters:
//  bool rx_active_mode - true to take to RX active mode (if RX), false otherwise
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_power_up(bool rx_active_mode)
{
	uint8_t config;

	rf_read_register(RF_CONFIG, &config, 1); //Get the current value of the CONFIG register

	//rf_power_up_param() will set the PWR_UP bit and write the old value of CONFIG back to the device
	rf_power_up_param(rx_active_mode, config);
}
