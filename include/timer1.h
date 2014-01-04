/////////////////////////////////////////////////////////////////////////////
//
// File: timer1.h
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

#ifndef TIMER1_H_
#define TIMER1_H_

#include "reg24le1.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in timer1_configure() function...OR these together to form the timer1_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TIMER1_CONFIG_OPTION_MODE_0_13_BIT_CTR_TMR			(0x00 << TMOD_MODE1_SHIFT)	//Configure timer 1 in mode 0 (13-bit counter/timer)
#define TIMER1_CONFIG_OPTION_MODE_1_16_BIT_CTR_TMR			(0x01 << TMOD_MODE1_SHIFT)	//Configure timer 1 in mode 1 (16-bit counter/timer)
#define TIMER1_CONFIG_OPTION_MODE_2_8_BIT_AUTO_RLD_TMR		(0x02 << TMOD_MODE1_SHIFT)	//Configure timer 1 in mode 2 (8-bit timer with auto-reload)
#define TIMER1_CONFIG_OPTION_MODE_3_TWO_8_BIT_CTRS_TMRS		(0x03 << TMOD_MODE1_SHIFT)	//Configure timer 1 in mode 3 (two 8-bit counters/timers)

#define TIMER1_CONFIG_OPTION_FUNCTION_TIMER					(0)							//Configure timer 1 as a timer
#define TIMER1_CONFIG_OPTION_FUNCTION_COUNT_EVENTS_ON_T1	(TMOD_CT1)					//Configure timer 1 to count events on T1

#define TIMER1_CONFIG_OPTION_GATE_ALWAYS_RUN_TIMER			(0)							//Configure timer 1 to always run the timer
#define TIMER1_CONFIG_OPTION_GATE_RUN_TIMER_WHEN_IFP_HIGH	(TMOD_GATE1)				//Configure timer 1 to run when IFP is high


////////////////////////////
// Function macros
////////////////////////////
#define timer1_run()					sbit_set(TCON_SB_TR1)		//Run timer 1
#define timer1_stop()					sbit_clear(TCON_SB_TR1)		//Stop timer 1
#define timer1_is_running()				(TCON_SB_TR1)				//True if timer 1 is running, false otherwise
#define timer1_has_overflown()			(TCON_SB_TF1)				//True if timer 1 has overflown, false otherwise
#define timer1_clear_overflow_flag()	sbit_clear(TCON_SB_TF1)		//Clear timer 1 overflow flag (auto-cleared if using an IRQ)
#define timer1_set_t1_val(period)		T1 = period					//Update the value of TH1:TL1


////////////////////////////
// Function prototypes
////////////////////////////
void timer1_configure(uint8_t timer1_config_options, uint16_t t1_val);


#endif /* TIMER1_H_ */
