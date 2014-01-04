/////////////////////////////////////////////////////////////////////////////
//
// File: interrupt_configure_ifp.c
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

#include "interrupt.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define INTERRUPT_IFP_CONFIG_TCON_MASK				0x01	//Mask for the options used for TCON
#define INTERRUPT_IFP_CONFIG_INTEXP_MASK			0x38	//Mask for the options used for INTEXP
#define INTERRUPT_IFP_CONFIG_INTEXP_GPINTX_MASK		(INTERRUPT_IFP_INPUT_GPINT0 | INTERRUPT_IFP_INPUT_GPINT1 | INTERRUPT_IFP_INPUT_GPINT2)	//Mask for the GPINTX bits in INTEXP


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void interrupt_configure_ifp(interrupt_ifp_input_t interrupt_ifp_input, uint8_t ifp_int_config_options)
//
// Description:
//  Configures the interrupt from pin block (bit INTEXP[0] must also be set outside this function to fully-enable interrupts from SSPI).
//   According to Table 47 on p. 100 of v1.6 of the datasheet, only one GPINT pin may be enabled at a time, and this function attempts
//   to heed that warning.
//
// Parameters:
//	interrupt_ifp_input_t interrupt_ifp_input - the GPINT to configure
//  uint16_t ifp_int_config_options - IFP configuration options
//
// Return value:
//  False if the user is trying to enable more than one input at a time, true otherwise
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool interrupt_configure_ifp(interrupt_ifp_input_t interrupt_ifp_input, uint8_t ifp_int_config_options)
{
	//Try to enable/disable the pin interrupt
	if(ifp_int_config_options & INTERRUPT_IFP_CONFIG_OPTION_ENABLE)
	{
		//Enabling, so set the appropriate bit in the INTEXP register (this will clear any other enabled interrupts if successful)
		if(interrupt_ifp_input == INTERRUPT_IFP_INPUT_GPINT0)
		{
			INTEXP = (INTEXP & ~INTERRUPT_IFP_CONFIG_INTEXP_GPINTX_MASK) | INTERRUPT_IFP_INPUT_GPINT0;
		}
		else if(interrupt_ifp_input == INTERRUPT_IFP_INPUT_GPINT1)
		{
			INTEXP = (INTEXP & ~INTERRUPT_IFP_CONFIG_INTEXP_GPINTX_MASK) | INTERRUPT_IFP_INPUT_GPINT1;
		}
		else if(interrupt_ifp_input == INTERRUPT_IFP_INPUT_GPINT2)
		{
			INTEXP = (INTEXP & ~INTERRUPT_IFP_CONFIG_INTEXP_GPINTX_MASK) | INTERRUPT_IFP_INPUT_GPINT2;
		}
		else
		{
			//The user is trying to enable an illegal pin or multiple pins, so return false
			return false;
		}

		//Set up TCON register
		TCON = (TCON & ~INTERRUPT_IFP_CONFIG_TCON_MASK) | (ifp_int_config_options & INTERRUPT_IFP_CONFIG_TCON_MASK);
	}
	else
	{
		//Disabling, so clear all the enable bits in the INTEXP register (only one should be enabled, anyway)
		if((interrupt_ifp_input == INTERRUPT_IFP_INPUT_GPINT0) || (interrupt_ifp_input == INTERRUPT_IFP_INPUT_GPINT1) || (interrupt_ifp_input == INTERRUPT_IFP_INPUT_GPINT2))
		{
			INTEXP = (INTEXP & ~INTERRUPT_IFP_CONFIG_INTEXP_GPINTX_MASK);
		}
		else
		{
			//The user is trying to disable an illegal pin or multiple pins, so return false
			return false;
		}
	}

	return true;
}
