/////////////////////////////////////////////////////////////////////////////
//
// File: w2_configure.c
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

#include "w2_src.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define W2_CONFIG_OPTION_W2CON0_MASK	0xFF	//Mask for the options used for W2CON0
#define W2_CONFIG_OPTION_W2CON1_MASK	0x20	//Mask for the options used for W2CON1


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void w2_configure(uint16_t w2_config_options, uint8_t address_in_slave_mode)
//
// Description:
//  Configures 2 wire
//
//  Note: This function sets INTEXP.4, which is the mask bit for the I2C interrupt.  If IEN1.2 is set, this
//   WILL CAUSE AN INTERRUPT TO FIRE when a byte is sent/received over 2-wire.  This IRQ is NOT handled
//   in this code, and will likely cause the SDK 2-wire functions to not work properly.  This is because
//   the IRQ firing automatically clears the interrupt flag that this code uses to determine when bytes
//   have been sent/received (IRCON.2).  It is, therefore, VERY IMPORTANT that you DO NOT SET IEN1.2 if you
//   are using the SDK 2-wire calls.
//
//   This has the potential to impact your code if you want to use either MSPI or SSPI in an interrupt-driven
//   fashion, as you have to set IEN1.2 to get them to fire an interrupt.  You MUST use MSPI and SSPI in
//   polling mode if you want to use the 2-wire calls in this library.
//
// Parameters:
//  uint16_t w2_config_options - 2 wire configuration options
//	uint8_t address_in_slave_mode - address to which the device will respond in slave mode
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void w2_configure(uint16_t w2_config_options, uint8_t address_in_slave_mode)
{
	w2_enable(); //Datasheet v1.6, p. 159 states that you must enable 2 wire before changing anything else

	//Set up the W2CONx registers from w2_config_options
	W2CON0 = (W2CON0 & ~W2_CONFIG_OPTION_W2CON0_MASK) | ((uint8_t)(w2_config_options >> W2_CONFIG_OPTION_W2CON0_OFFSET_SHIFT) & W2_CONFIG_OPTION_W2CON0_MASK);
	W2CON1 = (W2CON1 & ~W2_CONFIG_OPTION_W2CON1_MASK) | ((uint8_t)(w2_config_options >> W2_CONFIG_OPTION_W2CON1_OFFSET_SHIFT) & W2_CONFIG_OPTION_W2CON1_MASK);

	if(!w2_is_in_master_mode())
	{
		W2SADR = address_in_slave_mode;
	}

	//Disable if the user desires (see w2_enable() earlier in function)
	if((w2_config_options & W2_CONFIG_OPTION_ENABLE) == W2_CONFIG_OPTION_DISABLE)
	{
		w2_disable();
	}

	//For whatever reason, it is necessary to read the flag at the interrupt block level (IRCON.2) to determine
	// if a byte has been sent/received.  Polling W2CON1.0 is unreliable for checking this condition, so IRCON.2
	// must be polled until it is set, then W2CON1.0 can be read to see if the interrupt was caused by an RX/TX
	// byte event.
	interrupt_unmask_2wire_completed();
}
