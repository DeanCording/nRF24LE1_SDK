/////////////////////////////////////////////////////////////////////////////
//
// File: mspi_configure.c
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

#include "mspi.h"

///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define	MSPI_CONFIG_OPTION_SPIMCON0_MASK		0x7F	//Mask for the options used for SPIMCON0
#define MSPI_CONFIG_OPTION_SPIMCON1_MASK		0x0F	//Mask for the options used for SPIMCON1


////////////////////////////////////////////////////////////////////////////////
//
// void mspi_configure(uint16_t mspi_config_options)
//
// Description:
//  Configures the MSPI
//
// Parameters:
//  uint16_t mspi_config_options - MSPI configuration options
//
// Return value:
//  None
//
////////////////////////////////////////////////////////////////////////////////
void mspi_configure(uint16_t mspi_config_options)
{
	//Set up SPIMCON0 and SPIMCON1 registers from mspi_config_options
	SPIMCON0 = (SPIMCON0 & ~MSPI_CONFIG_OPTION_SPIMCON0_MASK) | (((uint8_t)(mspi_config_options >> MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)) & MSPI_CONFIG_OPTION_SPIMCON0_MASK);
	SPIMCON1 = (SPIMCON1 & ~MSPI_CONFIG_OPTION_SPIMCON1_MASK) | (((uint8_t)(mspi_config_options >> MSPI_CONFIG_OPTION_SPIMCON1_OFFSET_SHIFT)) & MSPI_CONFIG_OPTION_SPIMCON1_MASK);
}
