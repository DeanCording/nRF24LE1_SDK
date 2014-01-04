/////////////////////////////////////////////////////////////////////////////
//
// File: rng_get_one_byte_and_turn_off.c
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// uint8_t rng_get_one_byte_and_turn_off()
//
// Description:
//  Turns on the RNG, waits for a random number, then turns the RNG back off.  You do not have to call rng_configure() prior
//   to calling this function, as this function does that itself.
//
// Parameters:
//  None
//
// Return value:
//  A random number
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t rng_get_one_byte_and_turn_off()
{
	uint8_t rand_val;

	rng_configure(RNG_CONFIG_OPTION_RUN | RNG_CONFIG_CORRECTOR_ENABLE);
	rand_val = rng_get_next_byte();
	rng_stop();

	return rand_val;
}

