/////////////////////////////////////////////////////////////////////////////
//
// File: rng.h
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

#ifndef RNG_H_
#define RNG_H_

#include "reg24le1.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in rng_configure() function...OR these together to form the rng_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define RNG_CONFIG_OPTION_STOP			(0)							//Disable the RNG
#define RNG_CONFIG_OPTION_RUN			(RNGCTL_POWER_UP)			//Enable the RNG

#define RNG_CONFIG_CORRECTOR_DISABLE	(0)							//Enable the digital bias corrector (takes more time, but gives proper statistical distribution
#define RNG_CONFIG_CORRECTOR_ENABLE		(RNGCTL_CORRECTOR_ENABLE)	//Disable the digital bias corrector (takes less time, but may not give proper statistical distribution


////////////////////////////
// Function macros
////////////////////////////
#define rng_run()						reg_bits_set(RNGCTL, RNGCTL_POWER_UP)					//Run RNG
#define rng_stop()						reg_bits_clear(RNGCTL, RNGCTL_POWER_UP)					//Stop RNG
#define rng_enable_bias_corrector()		reg_bits_set(RNGCTL, RNGCTL_CORRECTOR_ENABLE)			//Enable the digital bias corrector
#define rng_disable_bias_corrector()	reg_bits_clear(RNGCTL, RNGCTL_CORRECTOR_ENABLE)			//Disable the digital bias corrector
#define rng_is_result_ready()			((RNGCTL & RNGCTL_RESULT_READY) == RNGCTL_RESULT_READY)	//True if a random number has been generated, false otherwise
#define rng_get_result()				(RNGDAT)												//Returns the random number that was generated


////////////////////////////
// Function prototypes
////////////////////////////
void rng_configure(uint8_t rng_config_options);
uint8_t rng_get_next_byte();
uint8_t rng_get_one_byte_and_turn_off();


#endif /* RNG_H_ */
