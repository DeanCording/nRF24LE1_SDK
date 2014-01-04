/////////////////////////////////////////////////////////////////////////////
//
// File: pwr_clk_mgmt_wakeup_sources_configure.c
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void pwr_clk_mgmt_wakeup_sources_configure(uint8_t wakeup_sources_config_options, uint16_t wakeup_on_pin_config_options)
//
// Description:
//  Configures wakeup sources
//
// Parameters:
//  uint8_t wakeup_sources_config_options - wakeup sources configuration options
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void pwr_clk_mgmt_wakeup_sources_configure(uint8_t wakeup_sources_config_options)
{
	//Set up WUCON register from wakeup_sources_config_options
	WUCON = wakeup_sources_config_options;
}
