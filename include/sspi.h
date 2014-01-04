/////////////////////////////////////////////////////////////////////////////
//
// File: sspi.h
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

#ifndef SSPI_H_
#define SSPI_H_

#include "reg24le1.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use with sspi_configure() function...OR these together to form the sspi_config_options argument
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define SSPI_CONFIG_OPTION_ENABLE								(SPISCON0_ENABLE)						//Enables SSPI communication
#define SSPI_CONFIG_OPTION_DISABLE								(0)										//Disables SSPI communication

#define SSPI_CONFIG_OPTION_CPHA_SAMPLE_ON_MSCK_EDGE_TRAILING	(SPISCON0_CPHA)							//Configures SSPI to sample on trailing edge of MSCK, and shift on leading edge
#define SSPI_CONFIG_OPTION_CPHA_SAMPLE_ON_MSCK_EDGE_LEADING		(0)										//Configures SSPI to sample on leading edge of MSCK, and shift on trailing edge

#define SSPI_CONFIG_OPTION_CPOL_MSCK_ACTIVE_LOW					(SPISCON0_CPOL)							//Configures the clock polarity to be active low
#define SSPI_CONFIG_OPTION_CPOL_MSCK_ACTIVE_HIGH				(0)										//Configures the clock polarity to be active high

#define SSPI_CONFIG_OPTION_DATA_ORDER_LSB_FIRST					(SPISCON0_DATA_ORDER)					//Send data with LSb first
#define SSPI_CONFIG_OPTION_DATA_ORDER_MSB_FIRST					(0)										//Send data with MSb first

#define SSPI_CONFIG_OPTION_SPI_SLAVE_DONE_INT_ENABLE			(0)										//Enable SPI slave done interrupt
#define SSPI_CONFIG_OPTION_SPI_SLAVE_DONE_INT_DISABLE			(SPISCON0_INT_SPI_SLAVE_DONE_DISABLE)	//Disable SPI slave done interrupt

#define SSPI_CONFIG_OPTION_CSN_LOW_INT_ENABLE					(0)										//Enable CSN low interrupt
#define SSPI_CONFIG_OPTION_CSN_LOW_INT_DISABLE					(SPISCON0_INT_CSN_LOW_DISABLE)			//Disable CSN low interrupt

#define SSPI_CONFIG_OPTION_CSN_HIGH_INT_ENABLE					(0)										//Enable CSN high interrupt
#define SSPI_CONFIG_OPTION_CSN_HIGH_INT_DISABLE					(SPISCON0_INT_CSN_HIGH_DISABLE)			//Disable CSN high interrupt


///////////////////////////////////////////
// Function macros
///////////////////////////////////////////
#define sspi_enable()							(SPISCON0 |= SPISCON0_ENABLE)									//Enable SSPI
#define sspi_disable()							(SPISCON0 &= ~SPISCON0_ENABLE)									//Disable SSPI
#define	sspi_send_data(data_to_send)			(SPISDAT = (data_to_send))										//Sends data_to_send over SSPI
#define	sspi_get_data()							(SPISDAT)														//Returns last data received over SSPI
#define sspi_get_status()						(SPISSTAT)														//Returns status of slave SPI

//For the following macros, use sspi_get_status() to read SPISSTAT into temporary variable, and use the variable as the argument to the macro
#define	sspi_is_spi_slave_done(spisstat_val)	((spisstat_val & SPISSTAT_INT_SPI_SLAVE_DONE_FLAG) ? true : false)	//True if TX FIFO is empty, false otherwise
#define	sspi_is_csn_low(spisstat_val)			((spisstat_val & SPISSTAT_INT_CSN_LOW_FLAG)  ? true : false)		//True if RX FIFO is full, false otherwise
#define	sspi_is_csn_high(spisstat_val)			((spisstat_val & SPISSTAT_INT_CSN_HIGH_FLAG) ? true : false)		//True if RX data is ready, false otherwise


///////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////
void sspi_configure(uint8_t sspi_config_options);
uint8_t sspi_read_write(uint8_t sspi_data) __reentrant;

#endif /*SSPI_H_*/
