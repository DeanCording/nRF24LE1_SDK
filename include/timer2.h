/////////////////////////////////////////////////////////////////////////////
//
// File: timer2.h
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

#ifndef TIMER2_H_
#define TIMER2_H_

#include "reg24le1.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bit shifts used due to the fact that we're using one argument to hold values for 2 different hardware registers use
//  in timer2_configure_<x>() functions...DO NOT USE THESE DIRECTLY IN USER CODE!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define	TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT	(0)		//Shift for the options used for TCON2...DO NOT USE IN CODE
#define	TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT	(8)		//Shift for the options used for CCEN...DO NOT USE IN CODE


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in timer2_configure_<x>() functions...OR these together to form the timer2_config_options argument
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TIMER2_CONFIG_OPTION_MODE_STOPPED						((0x00 << T2CON_INPUT_SEL_SHIFT) << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)	//Stop the timer (no input)
#define TIMER2_CONFIG_OPTION_MODE_TIMER							((0x01 << T2CON_INPUT_SEL_SHIFT) << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)	//Set the input to f/12 or f/24 (set by option TIMER2_CONFIG_OPTION_PRESCALER_DIV_*)
#define TIMER2_CONFIG_OPTION_MODE_EVENT_COUNTER					((0x02 << T2CON_INPUT_SEL_SHIFT) << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)	//Set the input to the falling edge of T2
#define TIMER2_CONFIG_OPTION_MODE_GATED_TIMER					((0x03 << T2CON_INPUT_SEL_SHIFT) << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)	//Set the input to f/12 or f/24 gated by T2

#define TIMER2_CONFIG_OPTION_RELOAD_DISABLED					((0x00 << T2CON_RELOAD_MODE_SHIFT) << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)	//Do not automatically reload the timer
#define TIMER2_CONFIG_OPTION_RELOAD_ON_OVERFLOW					((0x02 << T2CON_RELOAD_MODE_SHIFT) << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)	//Reload the timer on an overflow
#define TIMER2_CONFIG_OPTION_RELOAD_ON_T2EX_FALL				((0x03 << T2CON_RELOAD_MODE_SHIFT) << TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)	//Reload the timer on a falling edge of T2EX (frequency of CLKLF/2)

#define TIMER2_CONFIG_OPTION_PRESCALER_DIV_SHIFT				(7 + TIMER2_CONFIG_OPTION_TCON2_OFFSET_SHIFT)									//Shift for prescaler option below (do not use this option)
#define TIMER2_CONFIG_OPTION_PRESCALER_DIV_MASK					(1 << TIMER2_CONFIG_OPTION_PRESCALER_DIV_SHIFT)									//Mask for prescaler option below (do not use this option)
#define TIMER2_CONFIG_OPTION_PRESCALER_DIV_12					(0 << TIMER2_CONFIG_OPTION_PRESCALER_DIV_SHIFT)									//Set prescaler to divide CCLK by 12
#define TIMER2_CONFIG_OPTION_PRESCALER_DIV_24					(1 << TIMER2_CONFIG_OPTION_PRESCALER_DIV_SHIFT)									//Set prescaler to divide CCLK by 24

#define TIMER2_CONFIG_OPTION_CMP_CAPT_CRC_DISABLED				((0x00 << CCEN_CRC_MODE_SHIFT) << TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)		//Disable compare/capture for CRC register
#define TIMER2_CONFIG_OPTION_CMP_CAPT_CRC_CAPT_ON_WRITE_TO_CRCL	((0x03 << CCEN_CRC_MODE_SHIFT) << TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)		//Enable capturing the value of TH2 into CRC when a write is done to CRCL

#define TIMER2_CONFIG_OPTION_CMP_CAPT_CC1_DISABLED				((0x00 << CCEN_CC1_MODE_SHIFT) << TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)		//Disable compare/capture for CC1 register
#define TIMER2_CONFIG_OPTION_CMP_CAPT_CC1_CAPT_ON_WRITE_TO_CCL1	((0x03 << CCEN_CC1_MODE_SHIFT) << TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)		//Enable capturing the value of TH2 into CC1 when a write is done to CCL1

#define TIMER2_CONFIG_OPTION_CMP_CAPT_CC2_DISABLED				((0x00 << CCEN_CC2_MODE_SHIFT) << TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)		//Disable compare/capture for CC2 register
#define TIMER2_CONFIG_OPTION_CMP_CAPT_CC2_CAPT_ON_WRITE_TO_CCL2	((0x03 << CCEN_CC2_MODE_SHIFT) << TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)		//Enable capturing the value of TH2 into CC1 when a write is done to CCL2

#define TIMER2_CONFIG_OPTION_CMP_CAPT_CC3_DISABLED				((0x00 << CCEN_CC3_MODE_SHIFT) << TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)		//Disable compare/capture for CC3 register
#define TIMER2_CONFIG_OPTION_CMP_CAPT_CC3_CAPT_ON_WRITE_TO_CCL3	((0x03 << CCEN_CC3_MODE_SHIFT) << TIMER2_CONFIG_OPTION_CCEN_OFFSET_SHIFT)		//Enable capturing the value of TH2 into CC1 when a write is done to CCL3


////////////////////////////
// Function macros
////////////////////////////
#define timer2_run_as_timer()				sbit_clear(T2CON_SB_T2I1); sbit_set(T2CON_SB_T2I0)										//Run timer 2 in timer mode
#define timer2_run_as_event_counter()		sbit_set(T2CON_SB_T2I1); sbit_clear(T2CON_SB_T2I0)										//Run timer 2 in event counter mode
#define timer2_run_as_gated_timer()			sbit_set(T2CON_SB_T2I1); sbit_set(T2CON_SB_T2I0)										//Run timer 2 in gated timer mode
#define timer2_stop()						sbit_clear(T2CON_SB_T2I1); sbit_clear(T2CON_SB_T2I0)									//Stop timer 2
#define timer2_is_running()					(T2CON_SB_T2I0 || T2CON_SB_T2I1)														//True if timer 2 is running, false otherwise
#define timer2_set_crc_val(period)			CRC = period																			//Update the value of CRCH:CRCL
#define timer2_set_t2_val(period)			T2 = period																				//Update the value of TH2:TL2
#define timer2_set_crc_and_t2_vals(period)	timer2_set_crc_val(period); timer2_set_t2_val(period)									//Update both CRC and T2 with the same value


////////////////////////////
// Function prototypes
////////////////////////////
void timer2_configure_manual_reload_calc(uint16_t timer2_config_options, uint16_t auto_reload_or_compare_time);
void timer2_configure_auto_reload_calc(uint16_t timer2_config_options, float auto_reload_or_compare_period_in_seconds);
uint16_t timer2_calc_crc_val(float period_in_seconds, bool t2ps_bit_val);
float timer2_calc_actual_period(uint16_t crc, bool t2ps_bit_val);


#endif /* TIMER2_H_ */
