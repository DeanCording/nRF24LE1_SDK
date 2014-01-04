/////////////////////////////////////////////////////////////////////////////
//
// File: rng_configure.c
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

#include "rng.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define	RNG_CONFIG_OPTION_RNGCTL_MASK	0xC0	//Mask for the options used for RNGCTL


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void rng_configure(uint16_t rng_config_options)
//
// Description:
//  Configures the random number generator
//
// Parameters:
//  uint16_t rng_config_options - RNG configuration options
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rng_configure(uint8_t rng_config_options)
{
	//Set up RNGCTL register from rng_config_options
	RNGCTL = (RNGCTL & ~RNG_CONFIG_OPTION_RNGCTL_MASK) | (rng_config_options & RNG_CONFIG_OPTION_RNGCTL_MASK);
}

