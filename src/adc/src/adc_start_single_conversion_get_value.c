/////////////////////////////////////////////////////////////////////////////
//
// File: adc_start_conversion_get_value.c
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// uint8_t adc_start_conversion_get_value(adc_channel_t adc_channel)
//
// Description:
//  Starts an ADC conversion on the specified ADC channel and returns the value when finished.  It is unnecessary to call adc_set_input_channel()
//   or adc_start_conversion() before using this function, as this function does that itself.  This function should only be used with single step
//   acquisition mode.
//
// Parameters:
//  adc_channel_t adc_channel - ADC channel with which to run the acquisition
//
// Return value:
//  Value of last conversion
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t adc_start_single_conversion_get_value(adc_channel_t adc_channel)
{
	adc_start_single_conversion(adc_channel);

	while(adc_is_conversion_in_progress());

	return adc_get_result();
}
