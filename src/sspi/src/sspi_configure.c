/////////////////////////////////////////////////////////////////////////////
//
// File: sspi_configure.c
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

#include "sspi.h"

///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define	SSPI_CONFIG_OPTION_SPISCON0_MASK		0x7F	//Mask for the options used for SPISCON0


////////////////////////////////////////////////////////////////////////////////
//
// void sspi_configure(uint8_t sspi_config_options) __reentrant
//
// Description:
//  Configures the SSPI
//
// Parameters:
//  uint8_t sspi_config_options - SSPI configuration options
//
// Return value:
//  None
//
////////////////////////////////////////////////////////////////////////////////
void sspi_configure(uint8_t sspi_config_options) __reentrant
{
	//Set up SPISCON0 register from sspi_config_options
	SPISCON0 = (SPISCON0 & ~SSPI_CONFIG_OPTION_SPISCON0_MASK) | (sspi_config_options & SSPI_CONFIG_OPTION_SPISCON0_MASK);
}
