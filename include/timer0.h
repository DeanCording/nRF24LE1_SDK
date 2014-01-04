/////////////////////////////////////////////////////////////////////////////
//
// File: timer0.h
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

#ifndef TIMER0_H_
#define TIMER0_H_

#include "reg24le1.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in timer0_configure() function...OR these together to form the timer0_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TIMER0_CONFIG_OPTION_MODE_0_13_BIT_CTR_TMR			(0x00 << TMOD_MODE0_SHIFT)	//Configure timer 0 in mode 0 (13-bit counter/timer)
#define TIMER0_CONFIG_OPTION_MODE_1_16_BIT_CTR_TMR			(0x01 << TMOD_MODE0_SHIFT)	//Configure timer 0 in mode 1 (16-bit counter/timer)
#define TIMER0_CONFIG_OPTION_MODE_2_8_BIT_AUTO_RLD_TMR		(0x02 << TMOD_MODE0_SHIFT)	//Configure timer 0 in mode 2 (8-bit timer with auto-reload)
#define TIMER0_CONFIG_OPTION_MODE_3_TWO_8_BIT_CTRS_TMRS		(0x03 << TMOD_MODE0_SHIFT)	//Configure timer 0 in mode 3 (two 8-bit counters/timers)

#define TIMER0_CONFIG_OPTION_FUNCTION_TIMER					(0)							//Configure timer 0 as a timer
#define TIMER0_CONFIG_OPTION_FUNCTION_COUNT_EVENTS_ON_T0	(TMOD_CT0)					//Configure timer 0 to count events on T0

#define TIMER0_CONFIG_OPTION_GATE_ALWAYS_RUN_TIMER			(0)							//Configure timer 0 to always run the timer
#define TIMER0_CONFIG_OPTION_GATE_RUN_TIMER_WHEN_IFP_HIGH	(TMOD_GATE0)				//Configure timer 0 to run when IFP is high


////////////////////////////
// Function macros
////////////////////////////
#define timer0_run()					sbit_set(TCON_SB_TR0)		//Run timer 0
#define timer0_stop()					sbit_clear(TCON_SB_TR0)		//Stop timer 0
#define timer0_is_running()				(TCON_SB_TR0)				//True if timer 0 is running, false otherwise
#define timer0_has_overflown()			(TCON_SB_TF0)				//True if timer 0 has overflown, false otherwise
#define timer0_clear_overflow_flag()	sbit_clear(TCON_SB_TF0)		//Clear timer 0 overflow flag (auto-cleared if using an IRQ)
#define timer0_set_t0_val(period)		T0 = period					//Update the value of TH0:TL0


////////////////////////////
// Function prototypes
////////////////////////////
void timer0_configure(uint8_t timer0_config_options, uint16_t t0_val);


#endif /* TIMER0_H_ */
