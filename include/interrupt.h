/////////////////////////////////////////////////////////////////////////////
//
// File: interrupt.h
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

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "reg24le1.h"


///////////////////////////////////////////////////////////////////////////////
// Interrupt Vector Locations
///////////////////////////////////////////////////////////////////////////////
#define INTERRUPT_VECTOR_IFP			0   //interrupt from pin
#define INTERRUPT_VECTOR_T0				1   //timer0 overflow
#define INTERRUPT_VECTOR_PWR_FAIL		2   //power failure
#define INTERRUPT_VECTOR_T1				3   //timer1 overflow
#define INTERRUPT_VECTOR_UART			4   //UART receive & transmit interrupt
#define INTERRUPT_VECTOR_T2				5   //timer2 overflow
#define INTERRUPT_VECTOR_RFRDY			8   //RF SPI ready interrupt
#define INTERRUPT_VECTOR_RFIRQ			9   //RF interrupt
#define INTERRUPT_VECTOR_SPI_2WIRE		10  //SPI/2-wire interrupt
#define INTERRUPT_VECTOR_WU_ON_PIN		11  //wakeup on pin interrupt
#define INTERRUPT_VECTOR_XOSC_ADC_RNG	12  //XOSC/ADC/RNG interrupt
#define INTERRUPT_VECTOR_RTC2			13  //wakeup from RTC2


///////////////////////////////////////////////////////////////////////////////
// Interrupt enable/disable macros
///////////////////////////////////////////////////////////////////////////////
#define interrupt_control_global_enable()			sbit_set(IEN0_SB_GLOBAL)		//Enables the global interrupt control bit
#define interrupt_control_global_disable()			sbit_clear(IEN0_SB_GLOBAL)		//Disables the global interrupt control bit
#define interrupt_control_ifp_enable()				sbit_set(IEN0_SB_IFP)			//Enables the interrupt from pin control bit
#define interrupt_control_ifp_disable()				sbit_clear(IEN0_SB_IFP)			//Disables the interrupt from pin control bit
#define interrupt_control_t0_enable()				sbit_set(IEN0_SB_T0)			//Enables the timer 0 interrupt control bit
#define interrupt_control_t0_disable()				sbit_clear(IEN0_SB_T0)			//Disables the timer 0 interrupt control bit
#define interrupt_control_pwr_fail_enable()			sbit_set(IEN0_SB_POFIRQ)		//Enables the power failure interrupt control bit
#define interrupt_control_pwr_fail_disable()		sbit_clear(IEN0_SB_POFIRQ)		//Disables the power failure interrupt control bit
#define interrupt_control_t1_enable()				sbit_set(IEN0_SB_T1)			//Enables the timer 1 interrupt control bit
#define interrupt_control_t1_disable()				sbit_clear(IEN0_SB_T1)			//Disables the timer 1 interrupt control bit
#define interrupt_control_uart_enable()				sbit_set(IEN0_SB_UART)			//Enables the UART interrupt control bit
#define interrupt_control_uart_disable()			sbit_clear(IEN0_SB_UART)		//Enables the UART interrupt control bit
#define interrupt_control_t2_enable()				sbit_set(IEN0_SB_T2)			//Enables the timer 2 interrupt control bit
#define interrupt_control_t2_disable()				sbit_clear(IEN0_SB_T2)			//Disables the timer 2 interrupt control bit
#define interrupt_control_rfrdy_enable()			sbit_set(IEN1_SB_RFRDY)			//Enables the RF SPI ready interrupt control bit
#define interrupt_control_rfrdy_disable()			sbit_clear(IEN1_SB_RFRDY)		//Disables the RF SPI ready interrupt control bit
#define interrupt_control_rfirq_enable()			sbit_set(IEN1_SB_RFIRQ)			//Enables the RF communication interrupt control bit
#define interrupt_control_rfirq_disable()			sbit_clear(IEN1_SB_RFIRQ)		//Disables the RF communication interrupt control bit
#define interrupt_control_spi_2wire_enable()		sbit_set(IEN1_SB_SPI_2WIRE)		//Enables the SPI/2 wire interrupt control bit
#define interrupt_control_spi_2wire_disable()		sbit_clear(IEN1_SB_SPI_2WIRE)	//Disables the SPI/2 wire interrupt control bit
#define interrupt_control_wu_on_pin_enable()		sbit_set(IEN1_SB_WUOPIRQ)		//Enables the wake-up on pin interrupt control bit
#define interrupt_control_wu_on_pin_disable()		sbit_clear(IEN1_SB_WUOPIRQ)		//Disables the wake-up on pin interrupt control bit
#define interrupt_control_xosc_adc_rng_enable()		sbit_set(IEN1_SB_MISCIRQ)		//Enables the X0SC16M started/ADC ready/RNG ready interrupt control bit
#define interrupt_control_xosc_adc_rng_disable()	sbit_clear(IEN1_SB_MISCIRQ)		//Disables the X0SC16M started/ADC ready/RNG ready interrupt control bit
#define interrupt_control_rtc2_enable()				sbit_set(IEN1_SB_TICK)			//Enables the internal wakeup from RTC2 interrupt control bit
#define interrupt_control_rtc2_disable()			sbit_clear(IEN1_SB_TICK)		//Disables the internal wakeup from RTC2 interrupt control bit


///////////////////////////////////////////////////////////////////////////////////
// Macros to save and restore the global interrupt flag into a user-specified sbit
///////////////////////////////////////////////////////////////////////////////////
#define interrupt_save_global_flag(local_sbit)		local_sbit = IEN0_SB_GLOBAL
#define interrupt_restore_global_flag(local_sbit)	IEN0_SB_GLOBAL = local_sbit


///////////////////////////////////////////////////////////////////////////////
// cli()/sti() instructions
///////////////////////////////////////////////////////////////////////////////
#define cli()	interrupt_control_global_disable()
#define sti()	interrupt_control_global_enable()


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Interrupt function headers, which can be used in both prototypes and definitions (these do not incorporate __using(<bank>) directives)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define interrupt_isr_ifp()				void isr_ifp()				__interrupt(INTERRUPT_VECTOR_IFP)			//Interrupt from pin interrupt function header
#define interrupt_isr_t0()				void isr_t0()				__interrupt(INTERRUPT_VECTOR_T0)			//Timer 0 interrupt function header
#define interrupt_isr_pwr_fail()		void isr_pwr_fail()			__interrupt(INTERRUPT_VECTOR_PWR_FAIL)		//Power failure interrupt function header
#define interrupt_isr_t1()				void isr_t1() 				__interrupt(INTERRUPT_VECTOR_T1)			//Timer 1 interrupt function header
#define interrupt_isr_uart()			void isr_uart()				__interrupt(INTERRUPT_VECTOR_UART)			//UART interrupt function header
#define interrupt_isr_t2()				void isr_t2()				__interrupt(INTERRUPT_VECTOR_T2)			//Timer 2 interrupt function header
#define interrupt_isr_rfrdy()			void isr_rfrdy()			__interrupt(INTERRUPT_VECTOR_RFRDY)			//RF SPI ready interrupt function header
#define interrupt_isr_rfirq()			void isr_rfirq()			__interrupt(INTERRUPT_VECTOR_RFIRQ)			//RF communication interrupt function header
#define interrupt_isr_spi_2wire()		void isr_spi()				__interrupt(INTERRUPT_VECTOR_SPI_2WIRE)		//SPI/2 wire interrupt function header
#define interrupt_isr_wu_on_pin()		void isr_wu_on_pin()		__interrupt(INTERRUPT_VECTOR_WU_ON_PIN)		//Wake-up on pin interrupt function header
#define interrupt_isr_xosc_adc_rng()	void isr_xosc_adc_rng()		__interrupt(INTERRUPT_VECTOR_XOSC_ADC_RNG)	//X0SC16M started/ADC ready/RNG ready interrupt function header
#define interrupt_isr_rtc2()			void isr_rtc2()				__interrupt(INTERRUPT_VECTOR_RTC2)			//Internal wakeup from RTC2 interrupt function header


///////////////////////////////////////////////////////////////////////////////
// Macros to check interrupt flags
///////////////////////////////////////////////////////////////////////////////
#define interrupt_is_flag_active_uart_tx()		(S0CON_SB_TI0)			//Waits for UART TX interrupt flag
#define interrupt_is_flag_active_uart_rx()		(S0CON_SB_RI0)			//Waits for UART RX interrupt flag
#define interrupt_is_flag_active_rfrdy()		(IRCON_SB_RFRDY)		//Waits for RFRDY interrupt flag
#define interrupt_is_flag_active_rfirq()		(IRCON_SB_RFIRQ)		//Waits for RFIRQ interrupt flag
#define interrupt_is_flag_active_spi_2wire()	(IRCON_SB_SPI_2WIRE)	//Waits for SPI/2-WIRE interrupt flag
#define interrupt_is_flag_active_wuopirq()		(IRCON_SB_WUOPIRQ)		//Waits for wake-up on pin interrupt flag
#define interrupt_is_flag_active_miscirq()		(IRCON_SB_MISCIRQ)		//Waits for misc interrupt (X16IRQ, ADCIRQ, RNGIRQ) flag
#define interrupt_is_flag_active_tick()			(IRCON_SB_TICK)			//Waits for tick interrupt (X16IRQ, ADCIRQ, RNGIRQ) flag
#define interrupt_is_flag_active_tf2()			(IRCON_SB_TF2)			//Waits for TF2 (timer 2 overflow) interrupt flag
#define interrupt_is_flag_active_exf2()			(IRCON_SB_EXF2)			//Waits for TF2 (timer 2 external reload) interrupt flag


///////////////////////////////////////////////////////////////////////////////
// Macros to poll interrupt flags
///////////////////////////////////////////////////////////////////////////////
#define interrupt_wait_for_uart_tx()	while(!interrupt_is_flag_active_uart_tx())		//Waits for UART TX interrupt flag
#define interrupt_wait_for_uart_rx()	while(!interrupt_is_flag_active_uart_rx())		//Waits for UART RX interrupt flag
#define interrupt_wait_for_rfrdy()		while(!interrupt_is_flag_active_rfrdy())		//Waits for RFRDY interrupt flag
#define interrupt_wait_for_rfirq()		while(!interrupt_is_flag_active_rfirq())		//Waits for RFIRQ interrupt flag
#define interrupt_wait_for_spi_2wire()	while(!interrupt_is_flag_active_spi_2wire())	//Waits for SPI/2-WIRE interrupt flag
#define interrupt_wait_for_wuopirq()	while(!interrupt_is_flag_active_wuopirq())		//Waits for wake-up on pin interrupt flag
#define interrupt_wait_for_miscirq()	while(!interrupt_is_flag_active_miscirq())		//Waits for misc interrupt (X16IRQ, ADCIRQ, RNGIRQ) flag
#define interrupt_wait_for_tick()		while(!interrupt_is_flag_active_tick())			//Waits for tick interrupt (X16IRQ, ADCIRQ, RNGIRQ) flag
#define interrupt_wait_for_tf2()		while(!interrupt_is_flag_active_tf2())			//Waits for TF2 (timer 2 overflow) interrupt flag
#define interrupt_wait_for_exf2()		while(!interrupt_is_flag_active_exf2())			//Waits for TF2 (timer 2 external reload) interrupt flag


///////////////////////////////////////////////////////////////////////////////
// Interrupt-clearing macros
///////////////////////////////////////////////////////////////////////////////
#define interrupt_clear_uart_tx()		sbit_clear(S0CON_SB_TI0)		//Clears UART TX interrupt flag
#define interrupt_clear_uart_rx()		sbit_clear(S0CON_SB_RI0)		//Clears UART RX interrupt flag
#define interrupt_clear_rfrdy()			sbit_clear(IRCON_SB_RFRDY)		//Clears RFRDY interrupt flag
#define interrupt_clear_rfirq()			sbit_clear(IRCON_SB_RFIRQ)		//Clears RFIRQ interrupt flag
#define interrupt_clear_spi_2wire()		sbit_clear(IRCON_SB_SPI_2WIRE)	//Clears SPI/2-WIRE interrupt flag
#define interrupt_clear_wuopirq()		sbit_clear(IRCON_SB_WUOPIRQ)	//Clears wake-up on pin interrupt flag
#define interrupt_clear_miscirq()		sbit_clear(IRCON_SB_MISCIRQ)	//Clears misc interrupt (XOSC16IRQ, ADCIRQ, RNGIRQ) flag
#define interrupt_clear_tick()			sbit_clear(IRCON_SB_TICK)		//Clears tick interrupt flag
#define interrupt_clear_tf2()			sbit_clear(IRCON_SB_TF2)		//Clears TF2 (timer 2 overflow) interrupt flag
#define interrupt_clear_exf2()			sbit_clear(IRCON_SB_EXF2)		//Clears TF2 (timer 2 external reload) interrupt flag


///////////////////////////////////////////////////////////////////////////////
// Macros to unmask interrupts in the INTEXP register
///////////////////////////////////////////////////////////////////////////////
#define interrupt_unmask_sspi_completed()		reg_bits_set(INTEXP, INTEXP_SSPI_COMPLETED_INT_ENABLE)		//Unmasks SSPI completed interrupt in INTEXP
#define interrupt_mask_sspi_completed()			reg_bits_clear(INTEXP, INTEXP_SSPI_COMPLETED_INT_ENABLE)	//Masks SSPI completed interrupt in INTEXP
#define interrupt_unmask_mspi_completed()		reg_bits_set(INTEXP, INTEXP_MSPI_COMPLETED_INT_ENABLE)		//Unmasks MSPI completed interrupt in INTEXP
#define interrupt_mask_mspi_completed()			reg_bits_clear(INTEXP, INTEXP_MSPI_COMPLETED_INT_ENABLE)	//Masks MSPI completed interrupt in INTEXP
#define interrupt_unmask_2wire_completed()		reg_bits_set(INTEXP, INTEXP_2WIRE_COMPLETED_INT_ENABLE)		//Unmasks MSPI completed interrupt in INTEXP
#define interrupt_mask_2wire_completed()		reg_bits_clear(INTEXP, INTEXP_2WIRE_COMPLETED_INT_ENABLE)	//Masks MSPI completed interrupt in INTEXP
#define interrupt_unmask_gpint_ifp(gpint_sel)	reg_bits_set(INTEXP, gpint_sel)								//Unmasks specified GPINTX interrupt from pin(s) in INTEXP
#define interrupt_mask_gpint_ifp(gpint_sel)		reg_bits_clear(INTEXP, gpint_sel)							//Masks specified GPINTX interrupt from pin(s) in INTEXP
#define interrupt_unmask_gpint0_ifp()			interrupt_unmask_gpint_ifp(INTEXP_GP_INT0_ENABLE)			//Unmasks GPINT0 interrupt from pin in INTEXP
#define interrupt_mask_gpint0_ifp()				interrupt_mask_gpint_ifp(INTEXP_GP_INT0_ENABLE)				//Masks GPINT0 interrupt from pin in INTEXP
#define interrupt_unmask_gpint1_ifp()			interrupt_unmask_gpint_ifp(INTEXP_GP_INT1_ENABLE)			//Unmasks GPINT1 interrupt from pin in INTEXP
#define interrupt_mask_gpint1_ifp()				interrupt_mask_gpint_ifp(INTEXP_GP_INT1_ENABLE)				//Masks GPINT1 interrupt from pin in INTEXP
#define interrupt_unmask_gpint2_ifp()			interrupt_unmask_gpint_ifp(INTEXP_GP_INT2_ENABLE)			//Unmasks GPINT2 interrupt from pin in INTEXP
#define interrupt_mask_gpint2_ifp()				interrupt_mask_gpint_ifp(INTEXP_GP_INT2_ENABLE)				//Masks GPINT2 interrupt from pin in INTEXP


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in interrupt_configure_ifp() function...OR these together to form the ifp_int_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INTERRUPT_IFP_CONFIG_OPTION_DISABLE				(0)			//Disable interrupt on pin function
#define INTERRUPT_IFP_CONFIG_OPTION_ENABLE				(0x80)		//Enable interrupt on pin function
#define INTERRUPT_IFP_CONFIG_OPTION_TYPE_LOW_LEVEL		(0)			//Configure interrupt to occur on a low-level value
#define INTERRUPT_IFP_CONFIG_OPTION_TYPE_FALLING_EDGE	(TCON_IT0)	//Configure interrupt to occur on a falling-edge


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enumeration to hold indices for GPINTx enables for use in interrupt_configure_ifp()...use only one as interrupt_if_input argument
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	INTERRUPT_IFP_INPUT_GPINT0 = INTEXP_GP_INT0_ENABLE, //P0.0 on 24-pin, P0.5 on 32-pin, P1.2 on 48-pin
	INTERRUPT_IFP_INPUT_GPINT1 = INTEXP_GP_INT1_ENABLE,	//P0.2 on 24-pin, P0.6 on 32-pin, P1.3 on 48-pin
	INTERRUPT_IFP_INPUT_GPINT2 = INTEXP_GP_INT2_ENABLE	//Not present on 24-pin or 32-pin, P1.4 on 48-pin
} interrupt_ifp_input_t;

/////////////////////////////////////////////////////////////////////////////////////////////////
// Enumeration to hold indices for interrupt priority groups for use in interrupt_set_priority()
/////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	INTERRUPT_PRIORITY_GROUP_IFP_RFRDY				= 0,
	INTERRUPT_PRIORITY_GROUP_TF0_RFIRQ				= 1,
	INTERRUPT_PRIORITY_GROUP_POFIRQ_MSDONE_SSDONE	= 2,
	INTERRUPT_PRIORITY_GROUP_TF1_WUOPIRQ			= 3,
	INTERRUPT_PRIORITY_GROUP_RI0_TI0_MISCIRQ		= 4,
	INTERRUPT_PRIORITY_GROUP_TF2_EXF2_TICK			= 5,

	INTERRUPT_PRIORITY_GROUP_NUM					= 6	//Do not use this value
} interrupt_priority_group_t;

/////////////////////////////////////////////////////////////////////////////////////////////////
// Enumeration to hold indices for interrupt priority levels for use in interrupt_set_priority()
/////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	INTERRUPT_PRIORITY_LEVEL_0		= 0,	//Lowest priority
	INTERRUPT_PRIORITY_LEVEL_1		= 1,
	INTERRUPT_PRIORITY_LEVEL_2		= 2,
	INTERRUPT_PRIORITY_LEVEL_3		= 3,	//Highest priority

	INTERRUPT_PRIORITY_LEVEL_NUM	= 4		//Do not use this value
} interrupt_priority_level_t;


///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////
bool interrupt_configure_ifp(interrupt_ifp_input_t interrupt_if_input, uint8_t ifp_int_config_options);
void interrupt_set_priority(interrupt_priority_group_t interrupt_priority_group, interrupt_priority_level_t interrupt_priority_level);


#endif /*INTERRUPT_H_*/
