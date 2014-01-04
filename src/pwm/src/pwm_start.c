/////////////////////////////////////////////////////////////////////////////
//
// File: pwm_start.c
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

#include "pwm.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void pwm_start(pwm_channel_t pwm_channel, uint8_t pwm_duty_cycle)
//
// Description:
//  Starts an ADC conversion on the specified ADC channel
//
// Parameters:
//  adc_channel_t adc_channel - ADC channel with which to run the acquisition
//  uint8_t pwm_duty_cycle - duty cycle at which the PWM should run
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pwm_start(pwm_channel_t pwm_channel, uint8_t pwm_duty_cycle)
{
	//Set the duty cycle and enable the PWM for the requested channel
	if(pwm_channel == PWM_CHANNEL_0)
	{
		PWMDC0 = pwm_duty_cycle;
		reg_bits_set(PWMCON, PWMCON_PWM0_ENABLE);
	}
	else
	{
		PWMDC1 = pwm_duty_cycle;
		reg_bits_set(PWMCON, PWMCON_PWM1_ENABLE);
	}
}
