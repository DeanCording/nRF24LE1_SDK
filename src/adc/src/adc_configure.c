/////////////////////////////////////////////////////////////////////////////
//
// File: adc_configure.c
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

#include "adc.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define	ADC_CONFIG_OPTION_ADCCON1_WRITE_MASK	0x03	//Mask for the options used for ADCCON1
#define	ADC_CONFIG_OPTION_ADCCON2_WRITE_MASK	0xFF	//Mask for the options used for ADCCON2
#define	ADC_CONFIG_OPTION_ADCCON3_WRITE_MASK	0xE0	//Mask for the options used for ADCCON3


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void adc_configure(uint16_t adc_config_options)
//
// Description:
//  Configures the ADC
//
// Parameters:
//  uint16_t adc_config_options - ADC configuration options
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void adc_configure(uint16_t adc_config_options)
{
	//Set up the three ADC control registers from adc_config_options (write ADCCON1 last since it can kick off a write)
	ADCCON3 = (ADCCON3 & ~ADC_CONFIG_OPTION_ADCCON3_WRITE_MASK) | (((uint8_t)(adc_config_options >> ADC_CONFIG_OPTION_ADCCON3_OFFSET_SHIFT)) & ADC_CONFIG_OPTION_ADCCON3_WRITE_MASK);
	ADCCON2 = (ADCCON2 & ~ADC_CONFIG_OPTION_ADCCON2_WRITE_MASK) | (((uint8_t)(adc_config_options >> ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)) & ADC_CONFIG_OPTION_ADCCON2_WRITE_MASK);
	ADCCON1 = (ADCCON1 & ~ADC_CONFIG_OPTION_ADCCON1_WRITE_MASK) | (((uint8_t)(adc_config_options >> ADC_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT)) & ADC_CONFIG_OPTION_ADCCON1_WRITE_MASK);

	//In case this is continuous mode, wait 4 clock cycles so the busy flag will be valid when the function returns
	nop(); nop(); nop(); nop(); //4 clock cycles must elapse before busy flag is set (datasheet v1.3, p. 165)
}

