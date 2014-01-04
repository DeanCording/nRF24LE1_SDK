/////////////////////////////////////////////////////////////////////////////
//
// File: pwm.h
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

#ifndef PWM_H_
#define PWM_H_

#include "reg24le1.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use with pwm_configure() function...OR these together to form the pwm_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PWM_CONFIG_OPTION_PRESCALER_VAL_0	(0x00 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 0
#define PWM_CONFIG_OPTION_PRESCALER_VAL_1	(0x01 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 1
#define PWM_CONFIG_OPTION_PRESCALER_VAL_2	(0x02 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 2
#define PWM_CONFIG_OPTION_PRESCALER_VAL_3	(0x03 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 3
#define PWM_CONFIG_OPTION_PRESCALER_VAL_4	(0x04 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 4
#define PWM_CONFIG_OPTION_PRESCALER_VAL_5	(0x05 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 5
#define PWM_CONFIG_OPTION_PRESCALER_VAL_6	(0x06 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 6
#define PWM_CONFIG_OPTION_PRESCALER_VAL_7	(0x07 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 7
#define PWM_CONFIG_OPTION_PRESCALER_VAL_8	(0x08 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 8
#define PWM_CONFIG_OPTION_PRESCALER_VAL_9	(0x09 << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 9
#define PWM_CONFIG_OPTION_PRESCALER_VAL_10	(0x0A << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 10
#define PWM_CONFIG_OPTION_PRESCALER_VAL_11	(0x0B << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 11
#define PWM_CONFIG_OPTION_PRESCALER_VAL_12	(0x0C << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 12
#define PWM_CONFIG_OPTION_PRESCALER_VAL_13	(0x0D << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 13
#define PWM_CONFIG_OPTION_PRESCALER_VAL_14	(0x0E << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 14
#define PWM_CONFIG_OPTION_PRESCALER_VAL_15	(0x0F << PWMCON_PRESCALER_SHIFT)	//Sets PWM prescaler to 15

#define PWM_CONFIG_OPTION_WIDTH_5_BITS		(0x00 << PWMCON_BIT_WIDTH_SHIFT)	//Sets PWM period width to 5 bits
#define PWM_CONFIG_OPTION_WIDTH_6_BITS		(0x01 << PWMCON_BIT_WIDTH_SHIFT)	//Sets PWM period width to 6 bits
#define PWM_CONFIG_OPTION_WIDTH_7_BITS		(0x02 << PWMCON_BIT_WIDTH_SHIFT)	//Sets PWM period width to 7 bits
#define PWM_CONFIG_OPTION_WIDTH_8_BITS		(0x03 << PWMCON_BIT_WIDTH_SHIFT)	//Sets PWM period width to 8 bits


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// PWM channel defines for use in pwm_start() function - use only one member as the pwm_channel argument
/////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	PWM_CHANNEL_0,
	PWM_CHANNEL_1
}pwm_channel_t;


////////////////////////////
// Function prototypes
////////////////////////////
void pwm_configure(uint8_t pwm_config_options);
void pwm_start(pwm_channel_t pwm_channel, uint8_t pwm_duty_cycle);


#endif /* PWM_H_ */
