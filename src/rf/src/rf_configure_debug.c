/////////////////////////////////////////////////////////////////////////////
//
// File: rf_configure_debug.c
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
// void rf_configure_debug(bool rx, uint8_t p0_payload_width, bool enable_auto_ack)
//
// Description:
//  Configures the RF block for debugging
//
// Parameters:
//  bool rx - true to operate as RX, false for TX
//  uint8_t p0_payload_width - payload width in number of bytes for pipe 0
//  bool enable_auto_ack - true to enable auto-acknowledge on pipe 0, false to disable
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_configure_debug(bool rx, uint8_t p0_payload_width, bool enable_auto_ack)
{
	uint8_t config;
	uint8_t en_aa;

	config = RF_CONFIG_DEFAULT_VAL | RF_CONFIG_PWR_UP; //Set config to the default value of CONFIG with the PWR_UP bit set

	//Enable auto-ack on pipe 0 if requested
	if(enable_auto_ack != false)
	{
		en_aa = RF_EN_AA_ENAA_P0;
	}
	else
	{
		en_aa = RF_EN_AA_ENAA_NONE;
	}

	//Set the PRIM_RX bit if RX is requested
	if(rx == true)
	{
		config = config | RF_CONFIG_PRIM_RX;
	}

	//Run the full configuration on the device with the above specs and all others as defaults
	rf_configure(config,
				 true,
				 en_aa,
				 RF_EN_RXADDR_DEFAULT_VAL,
				 RF_SETUP_AW_DEFAULT_VAL,
				 RF_SETUP_RETR_DEFAULT_VAL,
				 RF_RF_CH_DEFAULT_VAL,
				 RF_RF_SETUP_DEFAULT_VAL,
				 NULL,
				 NULL,
				 RF_RX_ADDR_P2_DEFAULT_VAL,
				 RF_RX_ADDR_P3_DEFAULT_VAL,
				 RF_RX_ADDR_P4_DEFAULT_VAL,
				 RF_RX_ADDR_P5_DEFAULT_VAL,
				 NULL,
				 p0_payload_width,
				 RF_RX_PW_P1_DEFAULT_VAL,
				 RF_RX_PW_P2_DEFAULT_VAL,
				 RF_RX_PW_P3_DEFAULT_VAL,
				 RF_RX_PW_P4_DEFAULT_VAL,
				 RF_RX_PW_P5_DEFAULT_VAL,
				 RF_DYNPD_DPL_NONE,
				 RF_FEATURE_NONE);
}
