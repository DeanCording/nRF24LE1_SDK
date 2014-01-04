/////////////////////////////////////////////////////////////////////////////
//
// File: acomp.h
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

#ifndef ACOMP_H_
#define ACOMP_H_

#include "reg24le1.h"
#include "adc.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bit shifts used due to the fact that we're using one argument to hold values for 2 different hardware registers use
//  in acomp_configure() function...DO NOT USE THESE DIRECTLY IN USER CODE!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define	ACOMP_CONFIG_OPTION_COMPCON_OFFSET_SHIFT	(0)		//Shift for the options used for ADCCON2...DO NOT USE IN CODE
#define	ACOMP_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT	(5)		//Shift for the options used for ADCCON1...DO NOT USE IN CODE


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in acomp_configure() function...OR these together to form the acomp_config_options argument
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ACOMP_CONFIG_OPTION_DISABLE					(0)																				//Disable the analog comparator
#define ACOMP_CONFIG_OPTION_ENABLE					(COMPCON_ENABLE << ADC_CONFIG_OPTION_COMPCON_OFFSET_SHIFT)						//Enable the analog comparator

#define ACOMP_CONFIG_OPTION_REF_VDD					(0)																				//Set reference to VDD
#define ACOMP_CONFIG_OPTION_REF_EXT_ON_AIN3			((ADC_CONFIG_OPTION_REF_SELECT_EXT_AIN3 << ADC_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT) |\
													 (COMPCON_REF_SEL << ADC_CONFIG_OPTION_COMPCON_OFFSET_SHIFT))					//Set reference to external value on AIN3 or AIN9
#define ACOMP_CONFIG_OPTION_REF_EXT_ON_AIN9			((ADC_CONFIG_OPTION_REF_SELECT_EXT_AIN9 << ADC_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT) |\
													 (COMPCON_REF_SEL << ADC_CONFIG_OPTION_COMPCON_OFFSET_SHIFT))					//Set reference to external value on AIN3 or AIN9

#define ACOMP_CONFIG_OPTION_REF_SCALE_25_PCT		((0x00 << COMPCON_REF_SCALE_SHIFT) << ADC_CONFIG_OPTION_COMPCON_OFFSET_SHIFT)	//Set reference scale to 25%
#define ACOMP_CONFIG_OPTION_REF_SCALE_50_PCT		((0x01 << COMPCON_REF_SCALE_SHIFT) << ADC_CONFIG_OPTION_COMPCON_OFFSET_SHIFT)	//Set reference scale to 50%
#define ACOMP_CONFIG_OPTION_REF_SCALE_75_PCT		((0x02 << COMPCON_REF_SCALE_SHIFT) << ADC_CONFIG_OPTION_COMPCON_OFFSET_SHIFT)	//Set reference scale to 75%
#define ACOMP_CONFIG_OPTION_REF_SCALE_100_PCT		((0x03 << COMPCON_REF_SCALE_SHIFT) << ADC_CONFIG_OPTION_COMPCON_OFFSET_SHIFT)	//Set reference scale to 100%

#define ACOMP_CONFIG_OPTION_POL_NON_INV				(0)																				//Set output polarity to non-inverting
#define ACOMP_CONFIG_OPTION_POL_INV					(COMPCON_POLARITY << ADC_CONFIG_OPTION_COMPCON_OFFSET_SHIFT)					//Set output polarity to inverting


////////////////////////////
// Function prototypes
////////////////////////////
void acomp_configure(uint8_t acomp_config_options, adc_channel_t adc_channel);


#endif /* ACOMP_H_ */
