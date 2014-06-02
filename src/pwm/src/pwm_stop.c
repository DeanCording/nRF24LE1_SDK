/////////////////////////////////////////////////////////////////////////////
//
// File: pwm_stop.c
//
// Copyright Aleksandr Svalov (Alarus), 2014
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
// void pwm_stop(pwm_channel_t pwm_channel)
//
// Description:
//  Stop a PWM conversion on the specified PWM channel
//
// Parameters:
//  pwm_channel_t pwm_channel - PWM channel with which to stop the acquisition
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pwm_stop(pwm_channel_t pwm_channel)
{
	//Disable the PWM for the requested channel
	if(pwm_channel == PWM_CHANNEL_0)
	{
		reg_bits_clear(PWMCON, PWMCON_PWM0_ENABLE);
	}
	else
	{
		reg_bits_clear(PWMCON, PWMCON_PWM1_ENABLE);
	}
}
