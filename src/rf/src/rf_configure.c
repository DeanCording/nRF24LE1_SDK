/////////////////////////////////////////////////////////////////////////////
//
// File: rf_configure.c
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

#include "rf.h"
#include "rf_src.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void rf_configure(uint8_t config,
//				  	 bool opt_rx_active_mode,
//				  	 uint8_t en_aa,
//				  	 uint8_t en_rxaddr,
//				  	 uint8_t setup_aw,
//				  	 uint8_t setup_retr,
//				  	 uint8_t rf_ch,
//				  	 uint8_t rf_setup,
//				  	 uint8_t * rx_addr_p0,
//				  	 uint8_t * rx_addr_p1,
//				  	 uint8_t rx_addr_p2,
//				 	 uint8_t rx_addr_p3,
//					 uint8_t rx_addr_p4,
//					 uint8_t rx_addr_p5,
//					 uint8_t * tx_addr,
//					 uint8_t rx_pw_p0,
//					 uint8_t rx_pw_p1,
//					 uint8_t rx_pw_p2,
//					 uint8_t rx_pw_p3,
//					 uint8_t rx_pw_p4,
//					 uint8_t rx_pw_p5)
//
// Description:
//  Configures the RF block
//
// Parameters:
//  uint8_t config - value for CONFIG register
//  bool opt_rx_active_mode - true to bring up device in active RX mode
//  uint8_t en_aa - value for EN_AA register
//  uint8_t en_rxaddr - value for EN_RXADDR register
//  uint8_t setup_aw - value for SETUP_AW register
//  uint8_t setup_retr - value for SETUP_RETR register
//  uint8_t rf_ch - value for RF_CH register
//  uint8_t rf_setup - value for RF_SETUP register
//  uint8_t * rx_addr_p0 - pointer to array for the RX address for pipe 0
//  uint8_t * rx_addr_p1 - pointer to array for the RX address for pipe 1
//  uint8_t rx_addr_p2 - value for RX_ADDR_P2 register
//  uint8_t rx_addr_p3 - value for RX_ADDR_P3 register
//  uint8_t rx_addr_p4 - value for RX_ADDR_P4 register
//  uint8_t rx_addr_p5 - value for RX_ADDR_P5 register
//  uint8_t * tx_addr - pointer to array for the TX address
//  uint8_t rx_pw_p0 - value for RX_PW_P0 register
//  uint8_t rx_pw_p1 - value for RX_PW_P1 register
//  uint8_t rx_pw_p2 - value for RX_PW_P2 register
//  uint8_t rx_pw_p3 - value for RX_PW_P3 register
//  uint8_t rx_pw_p4 - value for RX_PW_P4 register
//  uint8_t rx_pw_p5 - value for RX_PW_P5 register
//  uint8_t dynpd - value for DYNPD register
//  uint8_t feature - value for FEATURE register
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_configure(uint8_t config,
				  bool opt_rx_active_mode,
				  uint8_t en_aa,
				  uint8_t en_rxaddr,
				  uint8_t setup_aw,
				  uint8_t setup_retr,
				  uint8_t rf_ch,
				  uint8_t rf_setup,
				  uint8_t * rx_addr_p0,
				  uint8_t * rx_addr_p1,
				  uint8_t rx_addr_p2,
				  uint8_t rx_addr_p3,
				  uint8_t rx_addr_p4,
				  uint8_t rx_addr_p5,
				  uint8_t * tx_addr,
				  uint8_t rx_pw_p0,
				  uint8_t rx_pw_p1,
				  uint8_t rx_pw_p2,
				  uint8_t rx_pw_p3,
				  uint8_t rx_pw_p4,
				  uint8_t rx_pw_p5,
				  uint8_t dynpd,
				  uint8_t feature)
{
	uint8_t buffer[5];

	//Enable RF SPI
	rf_spi_configure_enable();

	buffer[0] = en_aa;
	rf_write_register(RF_EN_AA, buffer, 1);

	buffer[0] = en_rxaddr;
	rf_write_register(RF_EN_RXADDR, buffer, 1);

	buffer[0] = setup_aw;
	rf_write_register(RF_SETUP_AW, buffer, 1);

	buffer[0] = setup_retr;
	rf_write_register(RF_SETUP_RETR, buffer, 1);

	buffer[0] = rf_ch;
	rf_write_register(RF_RF_CH, buffer, 1);

	buffer[0] = rf_setup;
	rf_write_register(RF_RF_SETUP, buffer, 1);

	//Set up the RX pipe 0 address if the passed in pointer is not NULL
	if(rx_addr_p0 != NULL)
	{
		rf_set_rx_addr(rx_addr_p0, 5, 0);
	}
	else
	{
		buffer[0] = RF_RX_ADDR_P0_B0_DEFAULT_VAL;
		buffer[1] = RF_RX_ADDR_P0_B1_DEFAULT_VAL;
		buffer[2] = RF_RX_ADDR_P0_B2_DEFAULT_VAL;
		buffer[3] = RF_RX_ADDR_P0_B3_DEFAULT_VAL;
		buffer[4] = RF_RX_ADDR_P0_B4_DEFAULT_VAL;

		rf_set_rx_addr(buffer, 5, 0);
	}

	//Set up the RX pipe 1 address if the passed in pointer is not NULL
	if(rx_addr_p1 != NULL)
	{
		rf_set_rx_addr(rx_addr_p1, 5, 1);
	}
	else
	{
		buffer[0] = RF_RX_ADDR_P1_B0_DEFAULT_VAL;
		buffer[1] = RF_RX_ADDR_P1_B1_DEFAULT_VAL;
		buffer[2] = RF_RX_ADDR_P1_B2_DEFAULT_VAL;
		buffer[3] = RF_RX_ADDR_P1_B3_DEFAULT_VAL;
		buffer[4] = RF_RX_ADDR_P1_B4_DEFAULT_VAL;

		rf_set_rx_addr(buffer, 5, 1);
	}

	buffer[0] = rx_addr_p2;
	rf_set_rx_addr(buffer, 1, 2);

	buffer[0] = rx_addr_p3;
	rf_set_rx_addr(buffer, 1, 3);

	buffer[0] = rx_addr_p4;
	rf_set_rx_addr(buffer, 1, 4);

	buffer[0] = rx_addr_p5;
	rf_set_rx_addr(buffer, 1, 5);

	//Set up the TX address if the passed in pointer is not NULL
	if(tx_addr != NULL)
	{
		rf_set_tx_addr(tx_addr, 5);
	}
	else
	{
		buffer[0] = RF_TX_ADDR_B0_DEFAULT_VAL;
		buffer[1] = RF_TX_ADDR_B1_DEFAULT_VAL;
		buffer[2] = RF_TX_ADDR_B2_DEFAULT_VAL;
		buffer[3] = RF_TX_ADDR_B3_DEFAULT_VAL;
		buffer[4] = RF_TX_ADDR_B4_DEFAULT_VAL;

		rf_set_tx_addr(buffer, 5);
	}

	buffer[0] = rx_pw_p0;
	rf_write_register(RF_RX_PW_P0, buffer, 1);

	buffer[0] = rx_pw_p1;
	rf_write_register(RF_RX_PW_P1, buffer, 1);

	buffer[0] = rx_pw_p2;
	rf_write_register(RF_RX_PW_P2, buffer, 1);

	buffer[0] = rx_pw_p3;
	rf_write_register(RF_RX_PW_P3, buffer, 1);

	buffer[0] = rx_pw_p4;
	rf_write_register(RF_RX_PW_P4, buffer, 1);

	buffer[0] = rx_pw_p5;
	rf_write_register(RF_RX_PW_P5, buffer, 1);

	buffer[0] = dynpd;
	rf_write_register(RF_DYNPD, buffer, 1);

	buffer[0] = feature;
	rf_write_register(RF_FEATURE, buffer, 1);

	//Set up the CONFIG register and power up/down as requested
	if((config & RF_CONFIG_PWR_UP) != 0)
	{
		rf_power_up_param(opt_rx_active_mode, config);
	}
	else
	{
		rf_power_down_param(config);
	}
}
