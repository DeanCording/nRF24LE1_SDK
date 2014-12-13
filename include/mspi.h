/////////////////////////////////////////////////////////////////////////////
//
// File: mspi.h
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

#ifndef MSPI_H_
#define MSPI_H_

#include "reg24le1.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bit shifts used due to the fact that we're using one argument to hold values for 2 different hardware registers used
//  in mspi_configure() function...DO NOT USE THESE DIRECTLY IN USER CODE!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define	MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT	(0)		//Shift for the options used for SPIMCON0...DO NOT USE IN CODE
#define	MSPI_CONFIG_OPTION_SPIMCON1_OFFSET_SHIFT	(8)		//Shift for the options used for SPIMCON1...DO NOT USE IN CODE


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use with mspi_configure() function...OR these together to form the mspi_config_options argument
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MSPI_CONFIG_OPTION_ENABLE								((SPIMCON0_ENABLE) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)						//Enables MSPI communication
#define MSPI_CONFIG_OPTION_DISABLE								(0)																					//Disables MSPI communication

#define MSPI_CONFIG_OPTION_CPHA_SAMPLE_ON_MSCK_EDGE_TRAILING	((SPIMCON0_CPHA) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)						//Configures MSPI to sample on trailing edge of MSCK, and shift on leading edge
#define MSPI_CONFIG_OPTION_CPHA_SAMPLE_ON_MSCK_EDGE_LEADING		(0)																					//Configures MSPI to sample on leading edge of MSCK, and shift on trailing edge

#define MSPI_CONFIG_OPTION_CPOL_MSCK_ACTIVE_LOW					((SPIMCON0_CPOL) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)						//Configures the clock polarity to be active low
#define MSPI_CONFIG_OPTION_CPOL_MSCK_ACTIVE_HIGH				(0)																					//Configures the clock polarity to be active high

#define MSPI_CONFIG_OPTION_DATA_ORDER_LSB_FIRST					((SPIMCON0_DATA_ORDER) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)					//Send data with LSb first
#define MSPI_CONFIG_OPTION_DATA_ORDER_MSB_FIRST					(0)																					//Send data with MSb first

#define	MSPI_CONFIG_OPTION_MCLK_IS_CCLK_DIV_2					((0x00 << SPIMCON0_CLK_DIV_SHIFT) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)		//Set the MCLK frequency to CCLK/2  (  8 MHz if CCLK = 16 MHz)
#define	MSPI_CONFIG_OPTION_MCLK_IS_CCLK_DIV_4					((0x01 << SPIMCON0_CLK_DIV_SHIFT) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)		//Set the MCLK frequency to CCLK/4  (  4 MHz if CCLK = 16 MHz)
#define	MSPI_CONFIG_OPTION_MCLK_IS_CCLK_DIV_8					((0x02 << SPIMCON0_CLK_DIV_SHIFT) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)		//Set the MCLK frequency to CCLK/8  (  2 MHz if CCLK = 16 MHz)
#define	MSPI_CONFIG_OPTION_MCLK_IS_CCLK_DIV_16					((0x03 << SPIMCON0_CLK_DIV_SHIFT) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)		//Set the MCLK frequency to CCLK/16 (  1 MHz if CCLK = 16 MHz)
#define	MSPI_CONFIG_OPTION_MCLK_IS_CCLK_DIV_32					((0x04 << SPIMCON0_CLK_DIV_SHIFT) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)		//Set the MCLK frequency to CCLK/32 (500 kHz if CCLK = 16 MHz)
#define	MSPI_CONFIG_OPTION_MCLK_IS_CCLK_DIV_64					((0x05 << SPIMCON0_CLK_DIV_SHIFT) << MSPI_CONFIG_OPTION_SPIMCON0_OFFSET_SHIFT)		//Set the MCLK frequency to CCLK/64 (250 kHz if CCLK = 16 MHz)

#define MSPI_CONFIG_OPTION_TX_FIFO_READY_INT_ENABLE				(0)																					//Enable TX FIFO ready interrupt
#define MSPI_CONFIG_OPTION_TX_FIFO_READY_INT_DISABLE			((SPIMCON1_INT_TX_FIFO_READY_DISABLE) << MSPI_CONFIG_OPTION_SPIMCON1_OFFSET_SHIFT)	//Disable TX FIFO ready interrupt

#define MSPI_CONFIG_OPTION_TX_FIFO_EMPTY_INT_ENABLE				(0)																					//Enable TX FIFO empty interrupt
#define MSPI_CONFIG_OPTION_TX_FIFO_EMPTY_INT_DISABLE			((SPIMCON1_INT_TX_FIFO_EMPTY_DISABLE) << MSPI_CONFIG_OPTION_SPIMCON1_OFFSET_SHIFT)	//Disable TX FIFO empty interrupt

#define MSPI_CONFIG_OPTION_RX_DATA_READY_INT_ENABLE				(0)																					//Enable RX data ready interrupt
#define MSPI_CONFIG_OPTION_RX_DATA_READY_INT_DISABLE			((SPIMCON1_INT_RX_DATA_READY_DISABLE) << MSPI_CONFIG_OPTION_SPIMCON1_OFFSET_SHIFT)	//Disable RX data ready interrupt

#define MSPI_CONFIG_OPTION_RX_FIFO_FULL_INT_ENABLE				(0)																					//Enable RX FIFO full interrupt
#define MSPI_CONFIG_OPTION_RX_FIFO_FULL_INT_DISABLE				((SPIMCON1_INT_RX_DATA_FULL_DISABLE) << MSPI_CONFIG_OPTION_SPIMCON1_OFFSET_SHIFT)	//Disable RX FIFO full interrupt


///////////////////////////////////////////
// Function macros
///////////////////////////////////////////
#define mspi_enable()				(SPIMCON0 |= SPIMCON0_ENABLE)									//Enable MSPI
#define mspi_disable()				(SPIMCON0 &= ~SPIMCON0_ENABLE)									//Disable MSPI
#define	mspi_send(data_to_send)		(SPIMDAT = (data_to_send))										//Sends data_to_send over MSPI
#define	mspi_get()					(SPIMDAT)														//Returns last data received over MSPI
#define	mspi_is_rx_fifo_full()		((SPIMSTAT & SPIMSTAT_INT_RX_DATA_FULL_FLAG)  ? true : false)	//True if RX FIFO is full, false otherwise
#define	mspi_is_rx_data_ready()		((SPIMSTAT & SPIMSTAT_INT_RX_DATA_READY_FLAG) ? true : false)	//True if RX data is ready, false otherwise
#define	mspi_is_tx_fifo_empty()		((SPIMSTAT & SPIMSTAT_INT_TX_FIFO_EMPTY_FLAG) ? true : false)	//True if TX FIFO is empty, false otherwise
#define	mspi_is_tx_fifo_ready()		((SPIMSTAT & SPIMSTAT_INT_TX_FIFO_READY_FLAG) ? true : false)	//True if TX FIFO is ready, false otherwise


///////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////
void mspi_configure(uint16_t mspi_config_options);
uint8_t mspi_read_write(uint8_t mspi_data) __reentrant;

#endif /*MSPI_H_*/
