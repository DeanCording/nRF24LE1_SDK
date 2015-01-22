/////////////////////////////////////////////////////////////////////////////
//
// File: rf.h
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

#ifndef RF_H_
#define RF_H_

#include <stddef.h>
#include "reg24le1.h"
#include "interrupt.h"
#include "delay.h"


////////////////////////////////////////////////////////////////////////////////////
// SPI commands
////////////////////////////////////////////////////////////////////////////////////
//SPI command defines
#define RF_R_REGISTER			0x00	//Read register command
#define RF_W_REGISTER			0x20	//Write register command
#define RF_R_RX_PAYLOAD			0x61	//Read RX payload command
#define RF_W_TX_PAYLOAD			0xA0	//Write TX payload command
#define RF_FLUSH_TX				0xE1	//Flush TX FIFO command
#define RF_FLUSH_RX				0xE2	//Flush RX FIFO command
#define RF_REUSE_TX_PL			0xE3	//Reuse last TX payload command
#define RF_R_RX_PL_WID			0x60	//Read RX payload width command
#define RF_W_ACK_PAYLOAD		0xA1	//Write acknowledge payload command
#define RF_W_TX_PAYLOAD_NOACK	0xB0	//Read RX payload width command
#define RF_NOP					0xFF	//No operation command

//SPI command data mask defines
#define RF_R_REGISTER_DATA		0x1F	//Mask for read register command data
#define RF_W_REGISTER_DATA		0x1F	//Mask for write register command data
#define RF_W_ACK_PAYLOAD_PIPE	0x07	//Mask for write ACK payload command data


////////////////////////////////////////////////////////////////////////////////////
// Register definitions
////////////////////////////////////////////////////////////////////////////////////
#define RF_CONFIG				0x00
#define RF_EN_AA				0x01
#define RF_EN_RXADDR				0x02
#define RF_SETUP_AW				0x03
#define RF_SETUP_RETR				0x04
#define RF_RF_CH				0x05
#define RF_RF_SETUP				0x06
#define RF_STATUS				0x07
#define RF_OBSERVE_TX				0x08
#define RF_RPD					0x09
#define RF_RX_ADDR_P0				0x0A
#define RF_RX_ADDR_P1				0x0B
#define RF_RX_ADDR_P2				0x0C
#define RF_RX_ADDR_P3				0x0D
#define RF_RX_ADDR_P4				0x0E
#define RF_RX_ADDR_P5				0x0F
#define RF_TX_ADDR				0x10
#define RF_RX_PW_P0				0x11
#define RF_RX_PW_P1				0x12
#define RF_RX_PW_P2				0x13
#define RF_RX_PW_P3				0x14
#define RF_RX_PW_P4				0x15
#define RF_RX_PW_P5				0x16
#define RF_FIFO_STATUS				0x17
#define RF_DYNPD				0x1C
#define RF_FEATURE				0x1D


////////////////////////////////////////////////////////////////////////////////////
// Default register values
//
// Below are the defines for each register's default value in the RF section. Multi-byte
//   registers use notation _BX_, "X" is the byte number.
////////////////////////////////////////////////////////////////////////////////////
#define RF_CONFIG_DEFAULT_VAL			0x08
#define RF_EN_AA_DEFAULT_VAL			0x3F
#define RF_EN_RXADDR_DEFAULT_VAL		0x03
#define RF_SETUP_AW_DEFAULT_VAL			0x03
#define RF_SETUP_RETR_DEFAULT_VAL		0x03
#define RF_RF_CH_DEFAULT_VAL			0x02
#define RF_RF_SETUP_DEFAULT_VAL			0x0F
#define RF_STATUS_DEFAULT_VAL			0x0E
#define RF_OBSERVE_TX_DEFAULT_VAL		0x00
#define RF_RPD_DEFAULT_VAL			0x00
#define RF_RX_ADDR_P0_B0_DEFAULT_VAL		0xE7
#define RF_RX_ADDR_P0_B1_DEFAULT_VAL		0xE7
#define RF_RX_ADDR_P0_B2_DEFAULT_VAL		0xE7
#define RF_RX_ADDR_P0_B3_DEFAULT_VAL		0xE7
#define RF_RX_ADDR_P0_B4_DEFAULT_VAL		0xE7
#define RF_RX_ADDR_P1_B0_DEFAULT_VAL		0xC2
#define RF_RX_ADDR_P1_B1_DEFAULT_VAL		0xC2
#define RF_RX_ADDR_P1_B2_DEFAULT_VAL		0xC2
#define RF_RX_ADDR_P1_B3_DEFAULT_VAL		0xC2
#define RF_RX_ADDR_P1_B4_DEFAULT_VAL		0xC2
#define RF_RX_ADDR_P2_DEFAULT_VAL		0xC3
#define RF_RX_ADDR_P3_DEFAULT_VAL		0xC4
#define RF_RX_ADDR_P4_DEFAULT_VAL		0xC5
#define RF_RX_ADDR_P5_DEFAULT_VAL		0xC6
#define RF_TX_ADDR_B0_DEFAULT_VAL		0xE7
#define RF_TX_ADDR_B1_DEFAULT_VAL		0xE7
#define RF_TX_ADDR_B2_DEFAULT_VAL		0xE7
#define RF_TX_ADDR_B3_DEFAULT_VAL		0xE7
#define RF_TX_ADDR_B4_DEFAULT_VAL		0xE7
#define RF_RX_PW_P0_DEFAULT_VAL			0x00
#define RF_RX_PW_P1_DEFAULT_VAL			0x00
#define RF_RX_PW_P2_DEFAULT_VAL			0x00
#define RF_RX_PW_P3_DEFAULT_VAL			0x00
#define RF_RX_PW_P4_DEFAULT_VAL			0x00
#define RF_RX_PW_P5_DEFAULT_VAL			0x00
#define RF_FIFO_STATUS_DEFAULT_VAL		0x11
#define RF_DYNPD_DEFAULT_VAL			0x00
#define RF_FEATURE_DEFAULT_VAL			0x00


////////////////////////////////////////////////////////////////////////////////////
// Register bitwise definitions
////////////////////////////////////////////////////////////////////////////////////
//CONFIG register bitwise definitions
#define RF_CONFIG_RESERVED			0x80
#define	RF_CONFIG_MASK_RX_DR			0x40
#define	RF_CONFIG_MASK_TX_DS			0x20
#define	RF_CONFIG_MASK_MAX_RT			0x10
#define	RF_CONFIG_EN_CRC			0x08
#define	RF_CONFIG_CRCO				0x04
#define	RF_CONFIG_PWR_UP			0x02
#define	RF_CONFIG_PRIM_RX			0x01

//EN_AA register bitwise definitions
#define RF_EN_AA_RESERVED			0xC0
#define RF_EN_AA_ENAA_ALL			0x3F
#define RF_EN_AA_ENAA_P5			0x20
#define RF_EN_AA_ENAA_P4			0x10
#define RF_EN_AA_ENAA_P3			0x08
#define RF_EN_AA_ENAA_P2			0x04
#define RF_EN_AA_ENAA_P1			0x02
#define RF_EN_AA_ENAA_P0			0x01
#define RF_EN_AA_ENAA_NONE			0x00

//EN_RXADDR register bitwise definitions
#define RF_EN_RXADDR_RESERVED			0xC0
#define RF_EN_RXADDR_ERX_ALL			0x3F
#define RF_EN_RXADDR_ERX_P5			0x20
#define RF_EN_RXADDR_ERX_P4			0x10
#define RF_EN_RXADDR_ERX_P3			0x08
#define RF_EN_RXADDR_ERX_P2			0x04
#define RF_EN_RXADDR_ERX_P1			0x02
#define RF_EN_RXADDR_ERX_P0			0x01
#define RF_EN_RXADDR_ERX_NONE			0x00

//SETUP_AW register bitwise definitions
#define RF_SETUP_AW_RESERVED			0xFC
#define RF_SETUP_AW				0x03
#define RF_SETUP_AW_5BYTES			0x03
#define RF_SETUP_AW_4BYTES			0x02
#define RF_SETUP_AW_3BYTES			0x01
#define RF_SETUP_AW_ILLEGAL			0x00

//SETUP_RETR register bitwise definitions
#define RF_SETUP_RETR_ARD			0xF0
#define RF_SETUP_RETR_ARD_4000			0xF0
#define RF_SETUP_RETR_ARD_3750			0xE0
#define RF_SETUP_RETR_ARD_3500			0xD0
#define RF_SETUP_RETR_ARD_3250			0xC0
#define RF_SETUP_RETR_ARD_3000			0xB0
#define RF_SETUP_RETR_ARD_2750			0xA0
#define RF_SETUP_RETR_ARD_2500			0x90
#define RF_SETUP_RETR_ARD_2250			0x80
#define RF_SETUP_RETR_ARD_2000			0x70
#define RF_SETUP_RETR_ARD_1750			0x60
#define RF_SETUP_RETR_ARD_1500			0x50
#define RF_SETUP_RETR_ARD_1250			0x40
#define RF_SETUP_RETR_ARD_1000			0x30
#define RF_SETUP_RETR_ARD_750			0x20
#define RF_SETUP_RETR_ARD_500			0x10
#define RF_SETUP_RETR_ARD_250			0x00
#define RF_SETUP_RETR_ARC			0x0F
#define RF_SETUP_RETR_ARC_15			0x0F
#define RF_SETUP_RETR_ARC_14			0x0E
#define RF_SETUP_RETR_ARC_13			0x0D
#define RF_SETUP_RETR_ARC_12			0x0C
#define RF_SETUP_RETR_ARC_11			0x0B
#define RF_SETUP_RETR_ARC_10			0x0A
#define RF_SETUP_RETR_ARC_9			0x09
#define RF_SETUP_RETR_ARC_8			0x08
#define RF_SETUP_RETR_ARC_7			0x07
#define RF_SETUP_RETR_ARC_6			0x06
#define RF_SETUP_RETR_ARC_5			0x05
#define RF_SETUP_RETR_ARC_4			0x04
#define RF_SETUP_RETR_ARC_3			0x03
#define RF_SETUP_RETR_ARC_2			0x02
#define RF_SETUP_RETR_ARC_1			0x01
#define RF_SETUP_RETR_ARC_0			0x00
#define RF_SETUP_RETR_DISABLE			0x00

//RF_CH register bitwise definitions
#define RF_RF_CH_RESERVED			0x80
#define RF_RF_CH_MAX_CHAN_NUM			 127

//RF_SETUP register bitwise definitions
#define RF_RF_SETUP_CONT_WAVE			0x80
#define RF_RF_SETUP_RESERVED			0x40
#define RF_RF_SETUP_RF_DR			0x28
#define RF_RF_SETUP_RF_DR_LOW			0x20
#define RF_RF_SETUP_PLL_LOCK			0x10
#define RF_RF_SETUP_RF_DR_HIGH			0x08
#define RF_RF_SETUP_RF_PWR			0x06
#define RF_RF_SETUP_RF_PWR_0_DBM		0x06
#define RF_RF_SETUP_RF_PWR_NEG_6_DBM 		0x04
#define RF_RF_SETUP_RF_PWR_NEG_12_DBM		0x02
#define RF_RF_SETUP_RF_PWR_NEG_18_DBM		0x00
//The following can be used in lieu of RF_RF_SETUP_RF_DR_LOW and RF_RF_SETUP_RF_DR_HIGH to set the data rate
#define RF_RF_SETUP_RF_DR_2_MBPS		RF_RF_SETUP_RF_DR_HIGH
#define RF_RF_SETUP_RF_DR_1_MBPS		0
#define RF_RF_SETUP_RF_DR_250_KBPS		RF_RF_SETUP_RF_DR_LOW

//STATUS register bitwise definitions
#define RF_STATUS_RESERVED			0x80
#define RF_STATUS_IRQ_MASKS			(RF_STATUS_RX_DR | RF_STATUS_TX_DS | RF_STATUS_MAX_RT)
#define RF_STATUS_RX_DR				0x40
#define RF_STATUS_TX_DS				0x20
#define RF_STATUS_MAX_RT			0x10
#define RF_STATUS_RX_P_NO			0x0E
#define RF_STATUS_RX_P_NO_RX_FIFO_EMPTY		0x0E
#define RF_STATUS_RX_P_NO_UNUSED		0x0C
#define RF_STATUS_RX_P_NO_5			0x0A
#define RF_STATUS_RX_P_NO_4			0x08
#define RF_STATUS_RX_P_NO_3			0x06
#define RF_STATUS_RX_P_NO_2			0x04
#define RF_STATUS_RX_P_NO_1			0x02
#define RF_STATUS_RX_P_NO_0			0x00
#define RF_STATUS_TX_FULL			0x01

//OBSERVE_TX register bitwise definitions
#define RF_OBSERVE_TX_PLOS_CNT			0xF0
#define RF_OBSERVE_TX_ARC_CNT			0x0F

//RPD register bitwise definitions
#define RF_RPD_RESERVED				0xFE
#define RF_RPD_RPD				0x01

//RX_PW_P0 register bitwise definitions
#define RF_RX_PW_P0_RESERVED			0xC0

//RX_PW_P0 register bitwise definitions
#define RF_RX_PW_P0_RESERVED			0xC0

//RX_PW_P1 register bitwise definitions
#define RF_RX_PW_P1_RESERVED			0xC0

//RX_PW_P2 register bitwise definitions
#define RF_RX_PW_P2_RESERVED			0xC0

//RX_PW_P3 register bitwise definitions
#define RF_RX_PW_P3_RESERVED			0xC0

//RX_PW_P4 register bitwise definitions
#define RF_RX_PW_P4_RESERVED			0xC0

//RX_PW_P5 register bitwise definitions
#define RF_RX_PW_P5_RESERVED			0xC0

//FIFO_STATUS register bitwise definitions
#define RF_FIFO_STATUS_RESERVED		0x8C
#define RF_FIFO_STATUS_TX_REUSE		0x40
#define RF_FIFO_STATUS_TX_FULL		0x20
#define RF_FIFO_STATUS_TX_EMPTY		0x10
#define RF_FIFO_STATUS_RX_FULL		0x02
#define RF_FIFO_STATUS_RX_EMPTY		0x01

//DYNPD register bitwise definitions
#define RF_DYNPD_RESERVED	0xC0
#define RF_DYNPD_DPL_ALL	0x3F
#define RF_DYNPD_DPL_P5		0x20
#define RF_DYNPD_DPL_P4		0x10
#define RF_DYNPD_DPL_P3		0x08
#define RF_DYNPD_DPL_P2		0x04
#define RF_DYNPD_DPL_P1		0x02
#define RF_DYNPD_DPL_P0		0x01
#define RF_DYNPD_DPL_NONE	0x00

//FEATURE register bitwise definitions
#define RF_FEATURE_RESERVED		0xF8
#define RF_FEATURE_ALL			0x07
#define RF_FEATURE_EN_DPL		0x04
#define RF_FEATURE_EN_ACK_PAY	0x02
#define RF_FEATURE_EN_DYN_ACK	0x01
#define RF_FEATURE_NONE			0x00


////////////////////////////////////////////////////////////////////////////////////
// Function macros
////////////////////////////////////////////////////////////////////////////////////
#define rf_clear_ce()	sbit_clear(RFCON_SB_RFCE)	//Clears the CE pin
#define rf_set_ce()		sbit_set(RFCON_SB_RFCE);\
						delay_us(4)					//Sets the CE pin, waits 4 us until we can use SPI again
#define rf_get_ce()		RFCON_SB_RFCE				//Gets the value of the CE pin
#define rf_get_csn()	RFCON_SB_RFCSN				//Gets the value of the CSN pin
#define rf_get_cken()	RFCON_SB_RFCKEN				//Gets the value of the CKEN pin

#define rf_nop()				rf_spi_execute_command(RF_NOP, NULL, 0, true)			//nop command wrapper
#define rf_flush_tx()			rf_spi_execute_command(RF_FLUSH_TX, NULL, 0, true)		//flush tx command wrapper
#define rf_flush_rx()			rf_spi_execute_command(RF_FLUSH_RX, NULL, 0, true)		//flush rx command wrapper
#define rf_reuse_tx_pl()		rf_spi_execute_command(RF_REUSE_TX_PL, NULL, 0, true)	//reuse tx payload command wrapper
#define rf_get_status()			rf_nop()												//get status register (wrapper of nop function)

#define rf_irq_tx_ds_active()	((rf_get_status() & RF_STATUS_TX_DS)  ? true : false)	//true if a payload has been sent from the TX FIFO
#define rf_irq_rx_dr_active()	((rf_get_status() & RF_STATUS_RX_DR)  ? true : false)	//true if the RX FIFO has received a payload
#define rf_irq_max_rt_active()	((rf_get_status() & RF_STATUS_MAX_RT) ? true : false)	//true if the maximum amount of TX retries has been reached
#define rf_irq_pin_active()		(IRCON_SB_RFIRQ)										//true if the IRQ pin from the 24L01 is active

#define rf_get_pipe_num_from_status_val(status_val)					((status_val) & RF_STATUS_RX_P_NO)												//return the pipe that is active in the STATUS register value...NOTE THAT THIS IS NOT SHIFTED DOWN BY ONE BIT
#define rf_get_pipe_num_shifted_from_status_val(status_val)			(rf_get_pipe_num_from_status_val(status_val) >> 1)								//return the pipe that is active in the STATUS register value...NOTE THAT THIS IS SHIFTED DOWN BY ONE BIT TO GET INT VERSION
#define rf_is_rxed_packet_on_pipe(status_val, pipe_val)				((rf_get_pipe_num_from_status_val(status_val) == (pipe_val)) ? true : false)	//true if the supplied pipe define is equal to the RX_P_NO field in STATUS register value
#define rf_is_rx_fifo_empty_in_status_val(status_val)				rf_is_rxed_packet_on_pipe(status_val, RF_STATUS_RX_P_NO_RX_FIFO_EMPTY)			//true if the RX FIFO is empty in STATUS register value
#define rf_is_rxed_payload_on_pipe_0_in_status_val(status_val)		rf_is_rxed_packet_on_pipe((status_val), RF_STATUS_RX_P_NO_0)					//true if the payload at the front of the RX FIFO is on pipe 0 in STATUS register value
#define rf_is_rxed_payload_on_pipe_1_in_status_val(status_val)		rf_is_rxed_packet_on_pipe((status_val), RF_STATUS_RX_P_NO_1)					//true if the payload at the front of the RX FIFO is on pipe 1 in STATUS register value
#define rf_is_rxed_payload_on_pipe_2_in_status_val(status_val)		rf_is_rxed_packet_on_pipe((status_val), RF_STATUS_RX_P_NO_2)					//true if the payload at the front of the RX FIFO is on pipe 2 in STATUS register value
#define rf_is_rxed_payload_on_pipe_3_in_status_val(status_val)		rf_is_rxed_packet_on_pipe((status_val), RF_STATUS_RX_P_NO_3)					//true if the payload at the front of the RX FIFO is on pipe 3 in STATUS register value
#define rf_is_rxed_payload_on_pipe_4_in_status_val(status_val)		rf_is_rxed_packet_on_pipe((status_val), RF_STATUS_RX_P_NO_4)					//true if the payload at the front of the RX FIFO is on pipe 4 in STATUS register value
#define rf_is_rxed_payload_on_pipe_5_in_status_val(status_val)		rf_is_rxed_packet_on_pipe((status_val), RF_STATUS_RX_P_NO_5)					//true if the payload at the front of the RX FIFO is on pipe 5 in STATUS register value
#define rf_is_tx_ds_active_in_status_val(status_val)				((status_val) & RF_STATUS_TX_DS)												//true if TX_DS bit is active in STATUS register value
#define rf_is_rx_dr_active_in_status_val(status_val)				((status_val) & RF_STATUS_RX_DR)												//true if RX_DR bit is active in STATUS register value
#define rf_is_max_rt_active_in_status_val(status_val)				((status_val) & RF_STATUS_MAX_RT)												//true if MAX_RT bit is active in STATUS register value
#define rf_is_tx_fifo_full_in_status_val(status_val)				((status_val) & RF_STATUS_TX_FULL)												//true if TX_FULL bit is active in STATUS regiser value

#define rf_is_config_rx()			((rf_read_register_1_byte(RF_CONFIG) & RF_CONFIG_PRIM_RX) ? 1 : 0)
#define rf_is_config_tx()			(!rf_is_config_rx())
#define rf_is_config_powered_up		((rf_read_register_1_byte(RF_CONFIG) & RF_CONFIG_PWR_UP) ? 1 : 0)
#define rf_is_config_powered_down	(!rf_is_config_powered_up())

////////////////////////////////////////////////////////////////////////////////////
// Function prototypes
////////////////////////////////////////////////////////////////////////////////////
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
				  uint8_t feature);

void rf_configure_debug(bool rx, uint8_t p0_payload_width, bool enable_auto_ack);
void rf_configure_debug_lite(bool rx, uint8_t p0_payload_width);

void rf_power_up(bool rx_active_mode);
void rf_power_up_param(bool rx_active_mode, uint8_t config);
void rf_power_down();
void rf_power_down_param(uint8_t config);

void rf_set_output_power(uint8_t);
void rf_set_data_rate(uint8_t);

uint8_t rf_write_register(uint8_t regnumber, uint8_t * dataptr, uint16_t len);
uint8_t rf_read_register(uint8_t regnumber, uint8_t * dataptr, uint16_t len);
uint8_t rf_read_register_1_byte(uint8_t regnumber);

void rf_set_tx_addr(uint8_t * address, uint16_t len);
void rf_set_rx_addr(uint8_t * address, uint16_t len, uint8_t rxpipenum);

void rf_set_as_rx(bool rx_active_mode);
void rf_set_as_tx();

uint8_t rf_read_rx_payload(uint8_t * dataptr, uint16_t len);
uint8_t rf_write_tx_payload(uint8_t * dataptr, uint16_t len, bool transmit);
uint8_t rf_write_tx_payload_noack(uint8_t * dataptr, uint16_t len, bool transmit);

uint8_t rf_read_rx_payload_width(uint8_t * dataptr);
uint8_t rf_write_tx_ack_payload(uint8_t * dataptr, uint16_t len);

void rf_transmit();
void rf_get_all_registers(uint8_t * dataptr);
void rf_spi_configure_enable();
void rf_irq_clear_all();
void rf_irq_clear(uint8_t irq_mask);
bool rf_is_rpd_active();
void rf_set_rf_channel(uint8_t channel);

bool rf_tx_fifo_is_full();
bool rf_tx_fifo_is_empty();
bool rf_rx_fifo_is_full();
bool rf_rx_fifo_is_empty();

uint8_t rf_spi_execute_command(uint8_t instruction, uint8_t * dataptr, uint16_t len, bool copydata);

#endif /*RF_H_*/
