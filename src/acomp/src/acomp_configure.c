/////////////////////////////////////////////////////////////////////////////
//
// File: acomp_configure.c
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

#include "acomp.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define ACOMP_CONFIG_OPTION_COMPCON_WRITE_MASK	0x1F	//Mask for the options used for COMPCON
#define ACOMP_CONFIG_OPTION_ADCCON1_WRITE_MASK	0x03	//Mask for the options used for ADCCON1


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void acomp_configure(uint8_t timer0_config_options, adc_channel_t adc_channel)
//
// Description:
//  Configures the analog comparator
//
// Parameters:
//  uint8_t acomp_config_options - analog comparator configuration options
//  adc_channel_t adc_channel - ADC channel with which to run the comparison
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void acomp_configure(uint8_t acomp_config_options, adc_channel_t adc_channel)
{
	adc_set_input_channel(adc_channel);

	//If the reference selection is AIN3 or AIN9, then set up ADCCON1
	if((acomp_config_options & (COMPCON_REF_SEL << ACOMP_CONFIG_OPTION_COMPCON_OFFSET_SHIFT)) != ACOMP_CONFIG_OPTION_REF_VDD)
	{
		ADCCON1 = (ADCCON1 & ~ACOMP_CONFIG_OPTION_ADCCON1_WRITE_MASK) | ((acomp_config_options >> ACOMP_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT) & ACOMP_CONFIG_OPTION_ADCCON1_WRITE_MASK);
	}

	//Set up COMPCON register from acomp_config_options
	COMPCON = (COMPCON & ~ACOMP_CONFIG_OPTION_COMPCON_WRITE_MASK) | ((acomp_config_options >> ACOMP_CONFIG_OPTION_COMPCON_OFFSET_SHIFT) & ACOMP_CONFIG_OPTION_COMPCON_WRITE_MASK);
}
