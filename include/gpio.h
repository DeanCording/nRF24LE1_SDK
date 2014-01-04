/////////////////////////////////////////////////////////////////////////////
//
// File: gpio.h
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

#ifndef GPIO_H_
#define GPIO_H_

#include "reg24le1.h"

///////////////////////////////////////////
// Compilation defines
///////////////////////////////////////////
// Verify existence of __TARG_PACKAGE_TYPE
#ifndef __TARG_PACKAGE_TYPE
#error "You must define __TARG_PACKAGE_TYPE in the appropriate target_nrf24le1_sdk.h file to use this header file"
#endif

// Verify that __TARG_PACKAGE_TYPE has been set to an appropriate value
#if (__TARG_PACKAGE_TYPE != NRF24LE1_PACKAGE_24_PIN) && (__TARG_PACKAGE_TYPE != NRF24LE1_PACKAGE_32_PIN) && (__TARG_PACKAGE_TYPE != NRF24LE1_PACKAGE_48_PIN)
#error "__TARG_PACKAGE_TYPE has been defined, but it has been defined to an incorrect value.  Please see #defines NR24LE1_PACKAGE_XX_PIN in include/reg24le1.h"
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in gpio_pin_configure() function...OR these together to form the gpio_pin_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_CONFIG_OPTION_DIR_INPUT									(0 << 0)						//Set the GPIO as an input
#define GPIO_PIN_CONFIG_OPTION_DIR_OUTPUT									(1 << 0)						//Set the GPIO as an output

#define GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_CLEAR								(0 << 1)						//If setting the GPIO as an output, clear its value
#define GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_SET								(1 << 1)						//If setting the GPIO as an output, set its value

#define GPIO_PIN_CONFIG_OPTION_PIN_MODE_INPUT_BUFFER_ON_NO_RESISTORS		(0x00 << PXCON_PINMODE_SHIFT)	//If setting the GPIO as an input, turn on the buffer and turn off the pull up/down resistors
#define GPIO_PIN_CONFIG_OPTION_PIN_MODE_INPUT_BUFFER_ON_PULL_DOWN_RESISTOR	(0x01 << PXCON_PINMODE_SHIFT)	//If setting the GPIO as an input, turn on the buffer and turn on the pull down resistor
#define GPIO_PIN_CONFIG_OPTION_PIN_MODE_INPUT_BUFFER_ON_PULL_UP_RESISTOR	(0x02 << PXCON_PINMODE_SHIFT)	//If setting the GPIO as an input, turn on the buffer and turn on the pull up resistor
#define GPIO_PIN_CONFIG_OPTION_PIN_MODE_INPUT_BUFFER_OFF					(0x03 << PXCON_PINMODE_SHIFT)	//If setting the GPIO as an input, turn off the buffer and the pull up/down resistors

#define GPIO_PIN_CONFIG_OPTION_PIN_MODE_OUTPUT_BUFFER_NORMAL_DRIVE_STRENGTH	(0x00 << PXCON_PINMODE_SHIFT)	//If setting the GPIO as an output, set the output buffer to normal drive strength
#define GPIO_PIN_CONFIG_OPTION_PIN_MODE_OUTPUT_BUFFER_HIGH_DRIVE_STRENGTH	(0x03 << PXCON_PINMODE_SHIFT)	//If setting the GPIO as an output, set the output buffer to high drive strength


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin id defines for use in gpio_pin_configure() function - use only one member as the gpio_pin_id argument
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	GPIO_PIN_ID_P0_0,
	GPIO_PIN_ID_P0_1,
	GPIO_PIN_ID_P0_2,
	GPIO_PIN_ID_P0_3,
	GPIO_PIN_ID_P0_4,
	GPIO_PIN_ID_P0_5,
	GPIO_PIN_ID_P0_6,
	GPIO_PIN_ID_P0_7,
	GPIO_PIN_ID_P1_0,
	GPIO_PIN_ID_P1_1,
	GPIO_PIN_ID_P1_2,
	GPIO_PIN_ID_P1_3,
	GPIO_PIN_ID_P1_4,
	GPIO_PIN_ID_P1_5,
	GPIO_PIN_ID_P1_6,
	GPIO_PIN_ID_P1_7,
	GPIO_PIN_ID_P2_0,
	GPIO_PIN_ID_P2_1,
	GPIO_PIN_ID_P2_2,
	GPIO_PIN_ID_P2_3,
	GPIO_PIN_ID_P2_4,
	GPIO_PIN_ID_P2_5,
	GPIO_PIN_ID_P2_6,
	GPIO_PIN_ID_P2_7,
	GPIO_PIN_ID_P3_0,
	GPIO_PIN_ID_P3_1,
	GPIO_PIN_ID_P3_2,
	GPIO_PIN_ID_P3_3,
	GPIO_PIN_ID_P3_4,
	GPIO_PIN_ID_P3_5,
	GPIO_PIN_ID_P3_6,

	GPIO_PIN_ID_NUM,
	GPIO_PIN_ID_INVALID = 0xFF
} gpio_pin_id_t;


///////////////////////////////////////
// GPIO pin defines for 24-pin variety
///////////////////////////////////////
#if (__TARG_PACKAGE_TYPE == NRF24LE1_PACKAGE_24_PIN)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin id function defines (these can be used in place of the GPIO_PIN_ID_* values above in gpio_pin_configure())
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_ID_FUNC_GPINT0		GPIO_PIN_ID_P0_0
#define GPIO_PIN_ID_FUNC_GPINT1		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_GPINT2		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_TXD		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_RXD		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_CLKLF1		GPIO_PIN_ID_P0_0
#define GPIO_PIN_ID_FUNC_CLKLF2		GPIO_PIN_ID_P0_1
#define GPIO_PIN_ID_FUNC_MSCK		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_MMOSI		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_MMISO		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_FSCK		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_FMOSI		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_FMISO		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_FCSN		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_SSCK		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_SMOSI		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_SMISO		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_SCSN		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_OCITCK		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_OCITMS		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_OCITDI		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_OCITDO		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_OCITO		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_W2SCL		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_W2SDA		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_PWM0		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_PWM1		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_AIN0		GPIO_PIN_ID_P0_0
#define GPIO_PIN_ID_FUNC_AIN1		GPIO_PIN_ID_P0_1
#define GPIO_PIN_ID_FUNC_AIN2		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_AIN3		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_AIN4		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_AIN5		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_AIN6		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_AIN7		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_AIN8		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_AIN9		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_AIN10		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_AIN11		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_AIN12		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_AIN13		GPIO_PIN_ID_INVALID

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin function register defines (these can be used in gpio_pins_val_set/clear/complement() as the first argument)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_REG_FUNC_GPINT0	P0
#define GPIO_PIN_REG_FUNC_GPINT1	P0
#define GPIO_PIN_REG_FUNC_TXD		P0
#define GPIO_PIN_REG_FUNC_RXD		P0
#define GPIO_PIN_REG_FUNC_CLKLF1	P0
#define GPIO_PIN_REG_FUNC_CLKLF2	P0
#define GPIO_PIN_REG_FUNC_MSCK		P0
#define GPIO_PIN_REG_FUNC_MMOSI		P0
#define GPIO_PIN_REG_FUNC_MMISO		P0
#define GPIO_PIN_REG_FUNC_FSCK		P0
#define GPIO_PIN_REG_FUNC_FMOSI		P0
#define GPIO_PIN_REG_FUNC_FMISO		P0
#define GPIO_PIN_REG_FUNC_FCSN		P0
#define GPIO_PIN_REG_FUNC_SSCK		P0
#define GPIO_PIN_REG_FUNC_SMOSI		P0
#define GPIO_PIN_REG_FUNC_SMISO		P0
#define GPIO_PIN_REG_FUNC_SCSN		P0
#define GPIO_PIN_REG_FUNC_OCITCK	P0
#define GPIO_PIN_REG_FUNC_OCITMS	P0
#define GPIO_PIN_REG_FUNC_OCITDI	P0
#define GPIO_PIN_REG_FUNC_OCITDO	P0
#define GPIO_PIN_REG_FUNC_OCITO		P0
#define GPIO_PIN_REG_FUNC_W2SCL		P0
#define GPIO_PIN_REG_FUNC_W2SDA		P0
#define GPIO_PIN_REG_FUNC_PWM0		P0
#define GPIO_PIN_REG_FUNC_PWM1		P0
#define GPIO_PIN_REG_FUNC_AIN0		P0
#define GPIO_PIN_REG_FUNC_AIN1		P0
#define GPIO_PIN_REG_FUNC_AIN2		P0
#define GPIO_PIN_REG_FUNC_AIN3		P0
#define GPIO_PIN_REG_FUNC_AIN4		P0
#define GPIO_PIN_REG_FUNC_AIN5		P0
#define GPIO_PIN_REG_FUNC_AIN6		P0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin function pin mask defines (these can be used in gpio_pins_val_set/clear/complement() as the second argument)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_MASK_FUNC_GPINT0	PX_D0
#define GPIO_PIN_MASK_FUNC_GPINT1	PX_D2
#define GPIO_PIN_MASK_FUNC_TXD		PX_D5
#define GPIO_PIN_MASK_FUNC_RXD		PX_D6
#define GPIO_PIN_MASK_FUNC_CLKLF1	PX_D0
#define GPIO_PIN_MASK_FUNC_CLKLF2	PX_D1
#define GPIO_PIN_MASK_FUNC_MSCK		PX_D2
#define GPIO_PIN_MASK_FUNC_MMOSI	PX_D3
#define GPIO_PIN_MASK_FUNC_MMISO	PX_D4
#define GPIO_PIN_MASK_FUNC_FSCK		PX_D2
#define GPIO_PIN_MASK_FUNC_FMOSI	PX_D3
#define GPIO_PIN_MASK_FUNC_FMISO	PX_D4
#define GPIO_PIN_MASK_FUNC_FCSN		PX_D5
#define GPIO_PIN_MASK_FUNC_SSCK		PX_D2
#define GPIO_PIN_MASK_FUNC_SMOSI	PX_D3
#define GPIO_PIN_MASK_FUNC_SMISO	PX_D4
#define GPIO_PIN_MASK_FUNC_SCSN		PX_D5
#define GPIO_PIN_MASK_FUNC_OCITCK	PX_D2
#define GPIO_PIN_MASK_FUNC_OCITMS	PX_D3
#define GPIO_PIN_MASK_FUNC_OCITDI	PX_D4
#define GPIO_PIN_MASK_FUNC_OCITDO	PX_D5
#define GPIO_PIN_MASK_FUNC_OCITO	PX_D6
#define GPIO_PIN_MASK_FUNC_W2SCL	PX_D5
#define GPIO_PIN_MASK_FUNC_W2SDA	PX_D6
#define GPIO_PIN_MASK_FUNC_PWM0		PX_D3
#define GPIO_PIN_MASK_FUNC_PWM1		PX_D6
#define GPIO_PIN_MASK_FUNC_AIN0		PX_D0
#define GPIO_PIN_MASK_FUNC_AIN1		PX_D1
#define GPIO_PIN_MASK_FUNC_AIN2		PX_D2
#define GPIO_PIN_MASK_FUNC_AIN3		PX_D3
#define GPIO_PIN_MASK_FUNC_AIN4		PX_D4
#define GPIO_PIN_MASK_FUNC_AIN5		PX_D5
#define GPIO_PIN_MASK_FUNC_AIN6		PX_D6

/////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin sbit defines (these can be used in gpio_pin_val_sbit_set/clear/complement())
/////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_SBIT_FUNC_GPINT0	P0_SB_D0
#define GPIO_PIN_SBIT_FUNC_GPINT1	P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_TXD		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_RXD		P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_CLKLF1	P0_SB_D0
#define GPIO_PIN_SBIT_FUNC_CLKLF2	P0_SB_D1
#define GPIO_PIN_SBIT_FUNC_MSCK		P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_MMOSI	P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_MMISO	P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_FSCK		P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_FMOSI	P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_FMISO	P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_FCSN		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_SSCK		P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_SMOSI	P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_SMISO	P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_SCSN		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_OCITCK	P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_OCITMS	P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_OCITDI	P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_OCITDO	P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_OCITO	P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_W2SCL	P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_W2SDA	P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_PWM0		P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_PWM1		P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_AIN0		P0_SB_D0
#define GPIO_PIN_SBIT_FUNC_AIN1		P0_SB_D1
#define GPIO_PIN_SBIT_FUNC_AIN2		P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_AIN3		P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_AIN4		P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_AIN5		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_AIN6		P0_SB_D6
#endif

///////////////////////////////////////
// GPIO pin defines for 32-pin variety
///////////////////////////////////////
#if (__TARG_PACKAGE_TYPE == NRF24LE1_PACKAGE_32_PIN)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin id function defines (these can be used in place of the GPIO_PIN_ID_* values above in gpio_pin_configure())
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_ID_FUNC_GPINT0		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_GPINT1		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_GPINT2		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_TXD		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_RXD		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_CLKLF1		GPIO_PIN_ID_P0_0
#define GPIO_PIN_ID_FUNC_CLKLF2		GPIO_PIN_ID_P0_1
#define GPIO_PIN_ID_FUNC_MSCK		GPIO_PIN_ID_P1_4
#define GPIO_PIN_ID_FUNC_MMOSI		GPIO_PIN_ID_P1_5
#define GPIO_PIN_ID_FUNC_MMISO		GPIO_PIN_ID_P1_6
#define GPIO_PIN_ID_FUNC_FSCK		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_FMOSI		GPIO_PIN_ID_P0_7
#define GPIO_PIN_ID_FUNC_FMISO		GPIO_PIN_ID_P1_0
#define GPIO_PIN_ID_FUNC_FCSN		GPIO_PIN_ID_P1_1
#define GPIO_PIN_ID_FUNC_SSCK		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_SMOSI		GPIO_PIN_ID_P0_7
#define GPIO_PIN_ID_FUNC_SMISO		GPIO_PIN_ID_P1_0
#define GPIO_PIN_ID_FUNC_SCSN		GPIO_PIN_ID_P1_1
#define GPIO_PIN_ID_FUNC_OCITCK		GPIO_PIN_ID_P0_7
#define GPIO_PIN_ID_FUNC_OCITMS		GPIO_PIN_ID_P1_0
#define GPIO_PIN_ID_FUNC_OCITDI		GPIO_PIN_ID_P1_1
#define GPIO_PIN_ID_FUNC_OCITDO		GPIO_PIN_ID_P1_2
#define GPIO_PIN_ID_FUNC_OCITO		GPIO_PIN_ID_P1_3
#define GPIO_PIN_ID_FUNC_W2SCL		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_W2SDA		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_PWM0		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_PWM1		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_AIN0		GPIO_PIN_ID_P0_0
#define GPIO_PIN_ID_FUNC_AIN1		GPIO_PIN_ID_P0_1
#define GPIO_PIN_ID_FUNC_AIN2		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_AIN3		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_AIN4		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_AIN5		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_AIN6		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_AIN7		GPIO_PIN_ID_P0_7
#define GPIO_PIN_ID_FUNC_AIN8		GPIO_PIN_ID_P1_0
#define GPIO_PIN_ID_FUNC_AIN9		GPIO_PIN_ID_P1_1
#define GPIO_PIN_ID_FUNC_AIN10		GPIO_PIN_ID_P1_2
#define GPIO_PIN_ID_FUNC_AIN11		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_AIN12		GPIO_PIN_ID_INVALID
#define GPIO_PIN_ID_FUNC_AIN13		GPIO_PIN_ID_INVALID

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin function register defines (these can be used in gpio_pins_val_set/clear/complement() as the first argument)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_REG_FUNC_GPINT0	P0
#define GPIO_PIN_REG_FUNC_GPINT1	P0
#define GPIO_PIN_REG_FUNC_TXD		P0
#define GPIO_PIN_REG_FUNC_RXD		P0
#define GPIO_PIN_REG_FUNC_CLKLF1	P0
#define GPIO_PIN_REG_FUNC_CLKLF2	P0
#define GPIO_PIN_REG_FUNC_MSCK		P1
#define GPIO_PIN_REG_FUNC_MMOSI		P1
#define GPIO_PIN_REG_FUNC_MMISO		P1
#define GPIO_PIN_REG_FUNC_FSCK		P0
#define GPIO_PIN_REG_FUNC_FMOSI		P0
#define GPIO_PIN_REG_FUNC_FMISO		P1
#define GPIO_PIN_REG_FUNC_FCSN		P1
#define GPIO_PIN_REG_FUNC_SSCK		P0
#define GPIO_PIN_REG_FUNC_SMOSI		P0
#define GPIO_PIN_REG_FUNC_SMISO		P1
#define GPIO_PIN_REG_FUNC_SCSN		P1
#define GPIO_PIN_REG_FUNC_OCITCK	P0
#define GPIO_PIN_REG_FUNC_OCITMS	P1
#define GPIO_PIN_REG_FUNC_OCITDI	P1
#define GPIO_PIN_REG_FUNC_OCITDO	P1
#define GPIO_PIN_REG_FUNC_OCITO		P1
#define GPIO_PIN_REG_FUNC_W2SCL		P0
#define GPIO_PIN_REG_FUNC_W2SDA		P0
#define GPIO_PIN_REG_FUNC_PWM0		P0
#define GPIO_PIN_REG_FUNC_PWM1		P0
#define GPIO_PIN_REG_FUNC_AIN0		P0
#define GPIO_PIN_REG_FUNC_AIN1		P0
#define GPIO_PIN_REG_FUNC_AIN2		P0
#define GPIO_PIN_REG_FUNC_AIN3		P0
#define GPIO_PIN_REG_FUNC_AIN4		P0
#define GPIO_PIN_REG_FUNC_AIN5		P0
#define GPIO_PIN_REG_FUNC_AIN6		P0
#define GPIO_PIN_REG_FUNC_AIN7		P0
#define GPIO_PIN_REG_FUNC_AIN8		P1
#define GPIO_PIN_REG_FUNC_AIN9		P1
#define GPIO_PIN_REG_FUNC_AIN10		P1

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin function pin mask defines (these can be used in gpio_pins_val_set/clear/complement() as the second argument)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_MASK_FUNC_GPINT0	PX_D5
#define GPIO_PIN_MASK_FUNC_GPINT1	PX_D6
#define GPIO_PIN_MASK_FUNC_TXD		PX_D3
#define GPIO_PIN_MASK_FUNC_RXD		PX_D4
#define GPIO_PIN_MASK_FUNC_CLKLF1	PX_D0
#define GPIO_PIN_MASK_FUNC_CLKLF2	PX_D1
#define GPIO_PIN_MASK_FUNC_MSCK		PX_D4
#define GPIO_PIN_MASK_FUNC_MMOSI	PX_D5
#define GPIO_PIN_MASK_FUNC_MMISO	PX_D6
#define GPIO_PIN_MASK_FUNC_FSCK		PX_D5
#define GPIO_PIN_MASK_FUNC_FMOSI	PX_D7
#define GPIO_PIN_MASK_FUNC_FMISO	PX_D0
#define GPIO_PIN_MASK_FUNC_FCSN		PX_D1
#define GPIO_PIN_MASK_FUNC_SSCK		PX_D5
#define GPIO_PIN_MASK_FUNC_SMOSI	PX_D7
#define GPIO_PIN_MASK_FUNC_SMISO	PX_D0
#define GPIO_PIN_MASK_FUNC_SCSN		PX_D1
#define GPIO_PIN_MASK_FUNC_OCITCK	PX_D7
#define GPIO_PIN_MASK_FUNC_OCITMS	PX_D0
#define GPIO_PIN_MASK_FUNC_OCITDI	PX_D1
#define GPIO_PIN_MASK_FUNC_OCITDO	PX_D2
#define GPIO_PIN_MASK_FUNC_OCITO	PX_D3
#define GPIO_PIN_MASK_FUNC_W2SCL	PX_D4
#define GPIO_PIN_MASK_FUNC_W2SDA	PX_D5
#define GPIO_PIN_MASK_FUNC_PWM0		PX_D2
#define GPIO_PIN_MASK_FUNC_PWM1		PX_D3
#define GPIO_PIN_MASK_FUNC_AIN0		PX_D0
#define GPIO_PIN_MASK_FUNC_AIN1		PX_D1
#define GPIO_PIN_MASK_FUNC_AIN2		PX_D2
#define GPIO_PIN_MASK_FUNC_AIN3		PX_D3
#define GPIO_PIN_MASK_FUNC_AIN4		PX_D4
#define GPIO_PIN_MASK_FUNC_AIN5		PX_D5
#define GPIO_PIN_MASK_FUNC_AIN6		PX_D6
#define GPIO_PIN_MASK_FUNC_AIN7		PX_D7
#define GPIO_PIN_MASK_FUNC_AIN8		PX_D0
#define GPIO_PIN_MASK_FUNC_AIN9		PX_D1
#define GPIO_PIN_MASK_FUNC_AIN10	PX_D2

/////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin sbit defines (these can be used in gpio_pin_val_sbit_set/clear/complement())
/////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_SBIT_FUNC_GPINT0	P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_GPINT1	P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_TXD		P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_RXD		P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_CLKLF1	P0_SB_D0
#define GPIO_PIN_SBIT_FUNC_CLKLF2	P0_SB_D1
#define GPIO_PIN_SBIT_FUNC_MSCK		P1_SB_D4
#define GPIO_PIN_SBIT_FUNC_MMOSI	P1_SB_D5
#define GPIO_PIN_SBIT_FUNC_MMISO	P1_SB_D6
#define GPIO_PIN_SBIT_FUNC_FSCK		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_FMOSI	P0_SB_D7
#define GPIO_PIN_SBIT_FUNC_FMISO	P1_SB_D0
#define GPIO_PIN_SBIT_FUNC_FCSN		P1_SB_D1
#define GPIO_PIN_SBIT_FUNC_SSCK		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_SMOSI	P0_SB_D7
#define GPIO_PIN_SBIT_FUNC_SMISO	P1_SB_D0
#define GPIO_PIN_SBIT_FUNC_SCSN		P1_SB_D1
#define GPIO_PIN_SBIT_FUNC_OCITCK	P0_SB_D7
#define GPIO_PIN_SBIT_FUNC_OCITMS	P1_SB_D0
#define GPIO_PIN_SBIT_FUNC_OCITDI	P1_SB_D1
#define GPIO_PIN_SBIT_FUNC_OCITDO	P1_SB_D2
#define GPIO_PIN_SBIT_FUNC_OCITO	P1_SB_D3
#define GPIO_PIN_SBIT_FUNC_W2SCL	P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_W2SDA	P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_PWM0		P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_PWM1		P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_AIN0		P0_SB_D0
#define GPIO_PIN_SBIT_FUNC_AIN1		P0_SB_D1
#define GPIO_PIN_SBIT_FUNC_AIN2		P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_AIN3		P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_AIN4		P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_AIN5		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_AIN6		P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_AIN7		P0_SB_D7
#define GPIO_PIN_SBIT_FUNC_AIN8		P1_SB_D0
#define GPIO_PIN_SBIT_FUNC_AIN9		P1_SB_D1
#define GPIO_PIN_SBIT_FUNC_AIN10	P1_SB_D2
#endif

///////////////////////////////////////
// GPIO pin defines for 48-pin variety
///////////////////////////////////////
#if (__TARG_PACKAGE_TYPE == NRF24LE1_PACKAGE_48_PIN)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin id function defines (these can be used in place of the GPIO_PIN_ID_* values above in gpio_pin_configure())
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_ID_FUNC_GPINT0		GPIO_PIN_ID_P1_2
#define GPIO_PIN_ID_FUNC_GPINT1		GPIO_PIN_ID_P1_3
#define GPIO_PIN_ID_FUNC_GPINT2		GPIO_PIN_ID_P1_4
#define GPIO_PIN_ID_FUNC_TXD		GPIO_PIN_ID_P1_0
#define GPIO_PIN_ID_FUNC_RXD		GPIO_PIN_ID_P1_1
#define GPIO_PIN_ID_FUNC_CLKLF1		GPIO_PIN_ID_P0_0
#define GPIO_PIN_ID_FUNC_CLKLF2		GPIO_PIN_ID_P0_1
#define GPIO_PIN_ID_FUNC_MSCK		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_MMOSI		GPIO_PIN_ID_P0_7
#define GPIO_PIN_ID_FUNC_MMISO		GPIO_PIN_ID_P1_0
#define GPIO_PIN_ID_FUNC_FSCK		GPIO_PIN_ID_P1_2
#define GPIO_PIN_ID_FUNC_FMOSI		GPIO_PIN_ID_P1_5
#define GPIO_PIN_ID_FUNC_FMISO		GPIO_PIN_ID_P1_6
#define GPIO_PIN_ID_FUNC_FCSN		GPIO_PIN_ID_P2_0
#define GPIO_PIN_ID_FUNC_SSCK		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_SMOSI		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_SMISO		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_SCSN		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_OCITCK		GPIO_PIN_ID_P1_1
#define GPIO_PIN_ID_FUNC_OCITMS		GPIO_PIN_ID_P1_2
#define GPIO_PIN_ID_FUNC_OCITDI		GPIO_PIN_ID_P1_3
#define GPIO_PIN_ID_FUNC_OCITDO		GPIO_PIN_ID_P1_4
#define GPIO_PIN_ID_FUNC_OCITO		GPIO_PIN_ID_P1_5
#define GPIO_PIN_ID_FUNC_W2SCL		GPIO_PIN_ID_P1_2
#define GPIO_PIN_ID_FUNC_W2SDA		GPIO_PIN_ID_P1_3
#define GPIO_PIN_ID_FUNC_PWM0		GPIO_PIN_ID_P0_7
#define GPIO_PIN_ID_FUNC_PWM1		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_AIN0		GPIO_PIN_ID_P0_0
#define GPIO_PIN_ID_FUNC_AIN1		GPIO_PIN_ID_P0_1
#define GPIO_PIN_ID_FUNC_AIN2		GPIO_PIN_ID_P0_2
#define GPIO_PIN_ID_FUNC_AIN3		GPIO_PIN_ID_P0_3
#define GPIO_PIN_ID_FUNC_AIN4		GPIO_PIN_ID_P0_4
#define GPIO_PIN_ID_FUNC_AIN5		GPIO_PIN_ID_P0_5
#define GPIO_PIN_ID_FUNC_AIN6		GPIO_PIN_ID_P0_6
#define GPIO_PIN_ID_FUNC_AIN7		GPIO_PIN_ID_P0_7
#define GPIO_PIN_ID_FUNC_AIN8		GPIO_PIN_ID_P1_0
#define GPIO_PIN_ID_FUNC_AIN9		GPIO_PIN_ID_P1_1
#define GPIO_PIN_ID_FUNC_AIN10		GPIO_PIN_ID_P1_2
#define GPIO_PIN_ID_FUNC_AIN11		GPIO_PIN_ID_P1_3
#define GPIO_PIN_ID_FUNC_AIN12		GPIO_PIN_ID_P1_4
#define GPIO_PIN_ID_FUNC_AIN13		GPIO_PIN_ID_P1_5

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin function register defines (these can be used in gpio_pins_val_set/clear/complement() as the first argument)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_REG_FUNC_GPINT0	P1
#define GPIO_PIN_REG_FUNC_GPINT1	P1
#define GPIO_PIN_REG_FUNC_GPINT2	P1
#define GPIO_PIN_REG_FUNC_TXD		P1
#define GPIO_PIN_REG_FUNC_RXD		P1
#define GPIO_PIN_REG_FUNC_CLKLF1	P0
#define GPIO_PIN_REG_FUNC_CLKLF2	P0
#define GPIO_PIN_REG_FUNC_MSCK		P0
#define GPIO_PIN_REG_FUNC_MMOSI		P0
#define GPIO_PIN_REG_FUNC_MMISO		P1
#define GPIO_PIN_REG_FUNC_FSCK		P1
#define GPIO_PIN_REG_FUNC_FMOSI		P1
#define GPIO_PIN_REG_FUNC_FMISO		P1
#define GPIO_PIN_REG_FUNC_FCSN		P2
#define GPIO_PIN_REG_FUNC_SSCK		P0
#define GPIO_PIN_REG_FUNC_SMOSI		P0
#define GPIO_PIN_REG_FUNC_SMISO		P0
#define GPIO_PIN_REG_FUNC_SCSN		P0
#define GPIO_PIN_REG_FUNC_OCITCK	P1
#define GPIO_PIN_REG_FUNC_OCITMS	P1
#define GPIO_PIN_REG_FUNC_OCITDI	P1
#define GPIO_PIN_REG_FUNC_OCITDO	P1
#define GPIO_PIN_REG_FUNC_OCITO		P1
#define GPIO_PIN_REG_FUNC_W2SCL		P1
#define GPIO_PIN_REG_FUNC_W2SDA		P1
#define GPIO_PIN_REG_FUNC_PWM0		P0
#define GPIO_PIN_REG_FUNC_PWM1		P0
#define GPIO_PIN_REG_FUNC_AIN0		P0
#define GPIO_PIN_REG_FUNC_AIN1		P0
#define GPIO_PIN_REG_FUNC_AIN2		P0
#define GPIO_PIN_REG_FUNC_AIN3		P0
#define GPIO_PIN_REG_FUNC_AIN4		P0
#define GPIO_PIN_REG_FUNC_AIN5		P0
#define GPIO_PIN_REG_FUNC_AIN6		P0
#define GPIO_PIN_REG_FUNC_AIN7		P0
#define GPIO_PIN_REG_FUNC_AIN8		P1
#define GPIO_PIN_REG_FUNC_AIN9		P1
#define GPIO_PIN_REG_FUNC_AIN10		P1
#define GPIO_PIN_REG_FUNC_AIN11		P1
#define GPIO_PIN_REG_FUNC_AIN12		P1
#define GPIO_PIN_REG_FUNC_AIN13		P1

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin function pin mask defines (these can be used in gpio_pins_val_set/clear/complement() as the second argument)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_MASK_FUNC_GPINT0	PX_D2
#define GPIO_PIN_MASK_FUNC_GPINT1	PX_D3
#define GPIO_PIN_MASK_FUNC_GPINT2	PX_D4
#define GPIO_PIN_MASK_FUNC_TXD		PX_D0
#define GPIO_PIN_MASK_FUNC_RXD		PX_D1
#define GPIO_PIN_MASK_FUNC_CLKLF1	PX_D0
#define GPIO_PIN_MASK_FUNC_CLKLF2	PX_D1
#define GPIO_PIN_MASK_FUNC_MSCK		PX_D6
#define GPIO_PIN_MASK_FUNC_MMOSI	PX_D7
#define GPIO_PIN_MASK_FUNC_MMISO	PX_D0
#define GPIO_PIN_MASK_FUNC_FSCK		PX_D2
#define GPIO_PIN_MASK_FUNC_FMOSI	PX_D5
#define GPIO_PIN_MASK_FUNC_FMISO	PX_D6
#define GPIO_PIN_MASK_FUNC_FCSN		PX_D0
#define GPIO_PIN_MASK_FUNC_SSCK		PX_D2
#define GPIO_PIN_MASK_FUNC_SMOSI	PX_D3
#define GPIO_PIN_MASK_FUNC_SMISO	PX_D4
#define GPIO_PIN_MASK_FUNC_SCSN		PX_D5
#define GPIO_PIN_MASK_FUNC_OCITCK	PX_D1
#define GPIO_PIN_MASK_FUNC_OCITMS	PX_D2
#define GPIO_PIN_MASK_FUNC_OCITDI	PX_D3
#define GPIO_PIN_MASK_FUNC_OCITDO	PX_D4
#define GPIO_PIN_MASK_FUNC_OCITO	PX_D5
#define GPIO_PIN_MASK_FUNC_W2SCL	PX_D2
#define GPIO_PIN_MASK_FUNC_W2SDA	PX_D3
#define GPIO_PIN_MASK_FUNC_PWM0		PX_D7
#define GPIO_PIN_MASK_FUNC_PWM1		PX_D6
#define GPIO_PIN_MASK_FUNC_AIN0		PX_D0
#define GPIO_PIN_MASK_FUNC_AIN1		PX_D1
#define GPIO_PIN_MASK_FUNC_AIN2		PX_D2
#define GPIO_PIN_MASK_FUNC_AIN3		PX_D3
#define GPIO_PIN_MASK_FUNC_AIN4		PX_D4
#define GPIO_PIN_MASK_FUNC_AIN5		PX_D5
#define GPIO_PIN_MASK_FUNC_AIN6		PX_D6
#define GPIO_PIN_MASK_FUNC_AIN7		PX_D7
#define GPIO_PIN_MASK_FUNC_AIN8		PX_D0
#define GPIO_PIN_MASK_FUNC_AIN9		PX_D1
#define GPIO_PIN_MASK_FUNC_AIN10	PX_D2
#define GPIO_PIN_MASK_FUNC_AIN11	PX_D3
#define GPIO_PIN_MASK_FUNC_AIN12	PX_D4
#define GPIO_PIN_MASK_FUNC_AIN13	PX_D5

/////////////////////////////////////////////////////////////////////////////////////////
// GPIO pin sbit defines (these can be used in gpio_pin_val_sbit_set/clear/complement())
/////////////////////////////////////////////////////////////////////////////////////////
#define GPIO_PIN_SBIT_FUNC_GPINT0	P1_SB_D2
#define GPIO_PIN_SBIT_FUNC_GPINT1	P1_SB_D3
#define GPIO_PIN_SBIT_FUNC_GPINT2	P1_SB_D4
#define GPIO_PIN_SBIT_FUNC_TXD		P1_SB_D0
#define GPIO_PIN_SBIT_FUNC_RXD		P1_SB_D1
#define GPIO_PIN_SBIT_FUNC_CLKLF1	P0_SB_D0
#define GPIO_PIN_SBIT_FUNC_CLKLF2	P0_SB_D1
#define GPIO_PIN_SBIT_FUNC_MSCK		P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_MMOSI	P0_SB_D7
#define GPIO_PIN_SBIT_FUNC_MMISO	P1_SB_D0
#define GPIO_PIN_SBIT_FUNC_FSCK		P1_SB_D2
#define GPIO_PIN_SBIT_FUNC_FMOSI	P1_SB_D5
#define GPIO_PIN_SBIT_FUNC_FMISO	P1_SB_D6
#define GPIO_PIN_SBIT_FUNC_FCSN		P2_SB_D0
#define GPIO_PIN_SBIT_FUNC_SSCK		P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_SMOSI	P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_SMISO	P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_SCSN		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_OCITCK	P1_SB_D1
#define GPIO_PIN_SBIT_FUNC_OCITMS	P1_SB_D2
#define GPIO_PIN_SBIT_FUNC_OCITDI	P1_SB_D3
#define GPIO_PIN_SBIT_FUNC_OCITDO	P1_SB_D4
#define GPIO_PIN_SBIT_FUNC_OCITO	P1_SB_D5
#define GPIO_PIN_SBIT_FUNC_W2SCL	P1_SB_D2
#define GPIO_PIN_SBIT_FUNC_W2SDA	P1_SB_D3
#define GPIO_PIN_SBIT_FUNC_PWM0		P0_SB_D7
#define GPIO_PIN_SBIT_FUNC_PWM1		P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_AIN0		P0_SB_D0
#define GPIO_PIN_SBIT_FUNC_AIN1		P0_SB_D1
#define GPIO_PIN_SBIT_FUNC_AIN2		P0_SB_D2
#define GPIO_PIN_SBIT_FUNC_AIN3		P0_SB_D3
#define GPIO_PIN_SBIT_FUNC_AIN4		P0_SB_D4
#define GPIO_PIN_SBIT_FUNC_AIN5		P0_SB_D5
#define GPIO_PIN_SBIT_FUNC_AIN6		P0_SB_D6
#define GPIO_PIN_SBIT_FUNC_AIN7		P0_SB_D7
#define GPIO_PIN_SBIT_FUNC_AIN8		P1_SB_D0
#define GPIO_PIN_SBIT_FUNC_AIN9		P1_SB_D1
#define GPIO_PIN_SBIT_FUNC_AIN10	P1_SB_D2
#define GPIO_PIN_SBIT_FUNC_AIN11	P1_SB_D3
#define GPIO_PIN_SBIT_FUNC_AIN12	P1_SB_D4
#define GPIO_PIN_SBIT_FUNC_AIN13	P1_SB_D5
#endif


/////////////////////////////////////////////////////////////
// Pin direction macros
/////////////////////////////////////////////////////////////
#define gpio_pins_dir_input(gpio_reg, pins_mask)	reg_bits_set(gpio_reg, pins_mask)				//Configures pins whose bits are set in pins_mask on GPIO port gpio_reg to input(s)
#define gpio_pins_dir_output(gpio_reg, pins_mask)	reg_bits_clear(gpio_reg, pins_mask)				//Configures pins whose bits are set in pins_mask on GPIO port gpio_reg to output(s)

//////////////////////////////////////////////////////////////////
// Pin value macros for GPIO SBITs (can only modify one GPIO pin)
//////////////////////////////////////////////////////////////////
#define gpio_pin_val_sbit_set(sbit_pin_set)					sbit_set(sbit_pin_set)					//Sets the output value of a single SBIT pin (i.e., P0_SB_D0)
#define gpio_pin_val_sbit_clear(sbit_pin_clear)				sbit_clear(sbit_pin_clear)				//Clears the output value of a single SBIT pin (i.e., P0_SB_D0)
#define gpio_pin_val_sbit_complement(sbit_pin_complement)	sbit_complement(sbit_pin_complement)	//Complements the output value of a single SBIT pin (i.e., P0_SB_D0)

//////////////////////////////////////////////////////////////////////////////
// Pin value macros for GPIO registers (can modify all GPIOs in the register)
//////////////////////////////////////////////////////////////////////////////
#define gpio_pins_val_set(gpio_reg, pins_mask)			reg_bits_set(gpio_reg, pins_mask)			//Sets the output values of pins whose bits are set in pins_mask on GPIO port gpio_reg
#define gpio_pins_val_clear(gpio_reg, pins_mask)		reg_bits_clear(gpio_reg, pins_mask)			//Clears the output values of pins whose bits are set in pins_mask on GPIO port gpio_reg
#define gpio_pins_val_complement(gpio_reg, pins_mask)	reg_bits_complement(gpio_reg, pins_mask)	//Complements the output values of pins whose bits are set in pins_mask on GPIO port gpio_reg


///////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////
void gpio_pin_configure(gpio_pin_id_t gpio_pin_id, uint8_t gpio_pin_config_options);
void gpio_pin_val_set(gpio_pin_id_t gpio_pin_id);
void gpio_pin_val_clear(gpio_pin_id_t gpio_pin_id);
void gpio_pin_val_write(gpio_pin_id_t gpio_pin_id, bool value);
bool gpio_pin_val_read(gpio_pin_id_t gpio_pin_id);
void gpio_pin_val_complement(gpio_pin_id_t gpio_pin_id);
void gpio_pin_dir_input(gpio_pin_id_t gpio_pin_id, uint8_t gpio_pin_config_options);
void gpio_pin_dir_output(gpio_pin_id_t gpio_pin_id, uint8_t gpio_pin_config_options);

#endif /*GPIO_H_*/
