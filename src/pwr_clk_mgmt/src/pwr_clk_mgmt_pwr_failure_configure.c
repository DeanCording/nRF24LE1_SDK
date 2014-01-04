/////////////////////////////////////////////////////////////////////////////
//
// File: pwr_clk_mgmt_pwr_failure_configure.c
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

#include "pwr_clk_mgmt.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define PWR_CLK_MGMT_CLKLF_CONFIG_OPTION_POFCON_MASK		0xF0	//Mask for the options used for POFCON


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void pwr_clk_mgmt_pwr_failure_configure(uint8_t pwr_failure_config_options)
//
// Description:
//  Configures power failure options
//
// Parameters:
//  uint8_t pwr_failure_config_options - power failure configuration options
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void pwr_clk_mgmt_pwr_failure_configure(uint8_t pwr_failure_config_options)
{
	//Set up POFCON register from pwr_failure_config_options
	POFCON = (POFCON & ~PWR_CLK_MGMT_CLKLF_CONFIG_OPTION_POFCON_MASK) | (pwr_failure_config_options & PWR_CLK_MGMT_CLKLF_CONFIG_OPTION_POFCON_MASK);
}
