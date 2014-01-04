/////////////////////////////////////////////////////////////////////////////
//
// File: rtc2.h
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

#ifndef RTC2_H_
#define RTC2_H_

#include "reg24le1.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in rtc2_configure() function...OR these together to form the rtc2_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define RTC2_CONFIG_OPTION_DISABLE						(0)										//Don't start RTC2
#define RTC2_CONFIG_OPTION_ENABLE						(RTC2CON_ENABLE)						//Start RTC2

#define RTC2_CONFIG_OPTION_COMPARE_MODE_DISABLED		(0x00 << RTC2CON_COMPARE_MODE_SHIFT)	//Configure RTC2 compare in mode 0 (compare disabled)
#define RTC2_CONFIG_OPTION_COMPARE_MODE_1_WRAP_AT_IRQ	(0x02 << RTC2CON_COMPARE_MODE_SHIFT)	//Configure RTC2 compare in mode 2 (wrap at IRQ)
#define RTC2_CONFIG_OPTION_COMPARE_MODE_0_RESET_AT_IRQ	(0x03 << RTC2CON_COMPARE_MODE_SHIFT)	//Configure RTC2 compare in mode 3 (reset at IRQ)

#define RTC2_CONFIG_OPTION_DO_NOT_CAPTURE_ON_RFIRQ		(0)										//Don't capture RTC2 registers on RFIRQ
#define RTC2_CONFIG_OPTION_CAPTURE_ON_RFIRQ				(RTC2CON_ENABLE_EXTERNAL_CAPTURE)		//Capture RTC2 registers on RFIRQ


////////////////////////////
// Function macros
////////////////////////////
#define rtc2_run()			reg_bits_set(RTC2CON, RTC2CON_ENABLE) 			//Run RTC2
#define rtc2_stop()			reg_bits_clear(RTC2CON, RTC2CON_ENABLE)			//Stop RTC2
#define rtc2_is_running()	((RTC2CON & RTC2CON_ENABLE) : true ? false)		//True if RTC2 is running, false otherwise
#define rtc2_sfr_capture()	reg_bits_set(RTC2CON, RTC2CON_SFR_CAPTURE) 		//Captures RTC2 registers


////////////////////////////
// Function prototypes
////////////////////////////
void rtc2_configure(uint8_t rtc2_config_options, uint16_t compare_value);
void rtc2_set_compare_val(uint16_t compare_value);


#endif /* RTC2_H_ */
