/////////////////////////////////////////////////////////////////////////////
//
// File: rf_configure_debug_lite.c
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
// void rf_configure_debug_lite(bool rx, uint8_t p0_payload_width)
//
// Description:
//  Minimal configuration for RF block
//
// Parameters:
//  bool rx - true to operate as RX, false for TX
//  uint8_t p0_payload_width - payload width in number of bytes for pipe 0 (set to 0 for TX)
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_configure_debug_lite(bool rx, uint8_t p0_payload_width)
{
	uint8_t config;

	rf_spi_configure_enable(); //Enable RF SPI

	//Disable auto-ack on all pipes
	config = 0;
	rf_write_register(RF_EN_AA, &config, 1); //Turn auto-acknowledge off
	rf_write_register(RF_SETUP_RETR, &config, 1); //Turn auto-retransmit off

	//Set up pipe 0's payload width and power up the device (if RX is requested, go to active mode)
	config = RF_CONFIG_DEFAULT_VAL; //Set config to the default value of the CONFIG register

	//Set up pipe 0's payload width
	rf_write_register(RF_RX_PW_P0, &p0_payload_width, 1);

	//Set the PRIM_RX bit
	if(rx != false)
	{
		config |= RF_CONFIG_PRIM_RX;
	}

	rf_power_up_param(true, config);
}
