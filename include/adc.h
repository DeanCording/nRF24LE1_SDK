/////////////////////////////////////////////////////////////////////////////
//
// File: adc.h
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

#ifndef ADC_H_
#define ADC_H_

#include "reg24le1.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bit shifts used due to the fact that we're using one argument to hold values for 3 different hardware registers used
//  in adc_configure() function...DO NOT USE THESE DIRECTLY IN USER CODE!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define	ADC_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT	(8)		//Shift for the options used for ADCCON1...DO NOT USE IN CODE
#define	ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT	(0)		//Shift for the options used for ADCCON2...DO NOT USE IN CODE
#define	ADC_CONFIG_OPTION_ADCCON3_OFFSET_SHIFT	(8)		//Shift for the options used for ADCCON3...DO NOT USE IN CODE


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in adc_configure() function...OR these together to form the adc_config_options argument
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ADC_CONFIG_OPTION_ACQ_TIME_750_NS						((0x00 << ADCCON2_ACQ_TIME_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)		//Sets the ADC acquisition time to 750 ns
#define ADC_CONFIG_OPTION_ACQ_TIME_3_US							((0x01 << ADCCON2_ACQ_TIME_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)		//Sets the ADC acquisition time to 3 us
#define ADC_CONFIG_OPTION_ACQ_TIME_12_US						((0x02 << ADCCON2_ACQ_TIME_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)		//Sets the ADC acquisition time to 12 us
#define ADC_CONFIG_OPTION_ACQ_TIME_36_US						((0x03 << ADCCON2_ACQ_TIME_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)		//Sets the ADC acquisition time to 36 us

#define ADC_CONFIG_OPTION_CONTINUOUS_SAMPLING_RATE_2_KSPS		((0x00 << ADCCON2_SAMPLING_RATE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//When using continuous sampling, sets sample rate to 2 ksps
#define ADC_CONFIG_OPTION_CONTINUOUS_SAMPLING_RATE_4_KSPS		((0x01 << ADCCON2_SAMPLING_RATE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//When using continuous sampling, sets sample rate to 4 ksps
#define ADC_CONFIG_OPTION_CONTINUOUS_SAMPLING_RATE_8_KSPS		((0x02 << ADCCON2_SAMPLING_RATE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//When using continuous sampling, sets sample rate to 8 ksps
#define ADC_CONFIG_OPTION_CONTINUOUS_SAMPLING_RATE_16_KSPS		((0x03 << ADCCON2_SAMPLING_RATE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//When using continuous sampling, sets sample rate to 16 ksps

#define ADC_CONFIG_OPTION_SINGLE_STEP_POWER_DOWN_DELAY_0_US		((0x00 << ADCCON2_SAMPLING_RATE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//When using single step sampling, sets power down delay after conversion to 0 us
#define ADC_CONFIG_OPTION_SINGLE_STEP_POWER_DOWN_DELAY_16_US	((0x01 << ADCCON2_SAMPLING_RATE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//When using single step sampling, sets power down delay after conversion to 16 us
#define ADC_CONFIG_OPTION_SINGLE_STEP_POWER_DOWN_DELAY_24_US	((0x02 << ADCCON2_SAMPLING_RATE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//When using single step sampling, sets power down delay after conversion to 24 us
#define ADC_CONFIG_OPTION_SINGLE_STEP_POWER_DOWN_DELAY_INF		((0x03 << ADCCON2_SAMPLING_RATE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//When using single step sampling, leaves ADC powered up after conversion

#define ADC_CONFIG_OPTION_SAMPLING_CONTINUOUS					((ADCCON2_CONTINUOUS_SAMPLING) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)			//Sets the ADC to sample continuously
#define ADC_CONFIG_OPTION_SAMPLING_SINGLE_STEP					(0)																					//Sets the ADC to sample once

#define ADC_CONFIG_OPTION_SAMPLING_MODE_SINGLE_ENDED			((0x00 << ADCCON2_SAMPLING_MODE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//Sets the ADC to sample in single-ended mode
#define ADC_CONFIG_OPTION_SAMPLING_MODE_DIFFERENTIAL_WITH_AIN2	((0x01 << ADCCON2_SAMPLING_MODE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//Sets the ADC to sample in differential mode with AIN2 as the other input
#define ADC_CONFIG_OPTION_SAMPLING_MODE_DIFFERENTIAL_WITH_AIN6	((0x02 << ADCCON2_SAMPLING_MODE_SHIFT) << ADC_CONFIG_OPTION_ADCCON2_OFFSET_SHIFT)	//Sets the ADC to sample in differential mode with AIN6 as the other input

#define ADC_CONFIG_OPTION_RESULT_JUSTIFICATION_RIGHT			(ADCCON3_RESULT_RIGHT_JUSTIFIED << ADC_CONFIG_OPTION_ADCCON3_OFFSET_SHIFT)			//Aligns the ADC output in ADCDAT to the right
#define ADC_CONFIG_OPTION_RESULT_JUSTIFICATION_LEFT				(0)																					//Aligns the ADC output in ADCDAT to the left

#define ADC_CONFIG_OPTION_RESOLUTION_6_BITS						((0x00 << ADCCON3_BIT_RES_SHIFT) << ADC_CONFIG_OPTION_ADCCON3_OFFSET_SHIFT)			//Sets the ADC to 6 bits of resolution
#define ADC_CONFIG_OPTION_RESOLUTION_8_BITS						((0x01 << ADCCON3_BIT_RES_SHIFT) << ADC_CONFIG_OPTION_ADCCON3_OFFSET_SHIFT)			//Sets the ADC to 8 bits of resolution
#define ADC_CONFIG_OPTION_RESOLUTION_10_BITS					((0x02 << ADCCON3_BIT_RES_SHIFT) << ADC_CONFIG_OPTION_ADCCON3_OFFSET_SHIFT)			//Sets the ADC to 10 bits of resolution
#define ADC_CONFIG_OPTION_RESOLUTION_12_BITS					((0x03 << ADCCON3_BIT_RES_SHIFT) << ADC_CONFIG_OPTION_ADCCON3_OFFSET_SHIFT)			//Sets the ADC to 12 bits of resolution

#define ADC_CONFIG_OPTION_REF_SELECT_INT_1_2V					((0x00 << ADCCON1_REF_SEL_SHIFT) << ADC_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT)			//Sets the ADC use the internal 1.2V reference as the ADC reference voltage
#define ADC_CONFIG_OPTION_REF_SELECT_VDD						((0x01 << ADCCON1_REF_SEL_SHIFT) << ADC_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT)			//Sets the ADC use VDD as the ADC reference voltage
#define ADC_CONFIG_OPTION_REF_SELECT_EXT_AIN3					((0x02 << ADCCON1_REF_SEL_SHIFT) << ADC_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT)			//Sets the ADC use AIN3 as the ADC reference voltage
#define ADC_CONFIG_OPTION_REF_SELECT_EXT_AIN9					((0x03 << ADCCON1_REF_SEL_SHIFT) << ADC_CONFIG_OPTION_ADCCON1_OFFSET_SHIFT)			//Sets the ADC use AIN9 as the ADC reference voltage


////////////////////////////////////////////////////////////////////////////
// Enumeration to hold indices for ADC channels
////////////////////////////////////////////////////////////////////////////
typedef enum
{
	ADC_CHANNEL_AIN0			= 0x00,
	ADC_CHANNEL_AIN1			= 0x01,
	ADC_CHANNEL_AIN2			= 0x02,
	ADC_CHANNEL_AIN3			= 0x03,
	ADC_CHANNEL_AIN4			= 0x04,
	ADC_CHANNEL_AIN5			= 0x05,
	ADC_CHANNEL_AIN6			= 0x06,
	ADC_CHANNEL_AIN7			= 0x07,
	ADC_CHANNEL_AIN8			= 0x08,
	ADC_CHANNEL_AIN9			= 0x09,
	ADC_CHANNEL_AIN10			= 0x0A,
	ADC_CHANNEL_AIN11			= 0x0B,
	ADC_CHANNEL_AIN12			= 0x0C,
	ADC_CHANNEL_AIN13			= 0x0D,
	ADC_CHANNEL_1_THIRD_VDD		= 0x0E,
	ADC_CHANNEL_2_THIRDS_VDD	= 0x0F
} adc_channel_t;


///////////////////////////////////////////
// Function macros
///////////////////////////////////////////
#define adc_power_up()							(ADCCON1 |= ADCCON1_POWER_UP)							//Powers up the ADC
#define adc_power_down()						(ADCCON1 &= (~ADCCON1_POWER_UP))						//Powers down the ADC
#define adc_is_conversion_in_progress()			((ADCCON1 & ADCCON1_BUSY_FLAG) == ADCCON1_BUSY_FLAG)	//Returns true if an ADC conversion is in progress
#define adc_get_result()						(ADCDAT)												//Returns the result of the last ADC conversion (assumes right justification)


///////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////
void adc_configure(uint16_t adc_config_options);
void adc_set_input_channel(adc_channel_t adc_channel);
void adc_start_single_conversion(adc_channel_t adc_channel);
uint16_t adc_start_single_conversion_get_value(adc_channel_t adc_channel);


#endif /* ADC_H_ */
