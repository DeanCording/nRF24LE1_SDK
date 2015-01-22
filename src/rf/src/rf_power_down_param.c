/////////////////////////////////////////////////////////////////////////////
//
// File: rf_power_down_param.c
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
// void rf_power_down_param(uint8_t config)
//
// Description:
//  Powers down the device, but allows the user to pass in the value sent to the CONFIG register
//
// Parameters:
//  uint8_t config - value to be written to the CONFIG register (the PWR_UP bit will obviously be cleared)
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_power_down_param(uint8_t config)
{
	rf_clear_ce(); //Ensure the CE pin is cleared

	config &= (~RF_CONFIG_PWR_UP); //Use the passed in value of CONFIG and ensure the PWR_UP bit is cleared, then write the register
	rf_write_register(RF_CONFIG, &config, 1);
}
