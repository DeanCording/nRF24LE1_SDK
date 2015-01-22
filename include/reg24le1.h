/////////////////////////////////////////////////////////////////////////////
//
// File: reg24le1.h
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

#ifndef REG24LE1_H_
#define REG24LE1_H_

#include <stdint.h>
#include "target_nrf24le1_sdk.h"


///////////////////////////////////////////
// Single-byte __sfrs
///////////////////////////////////////////
__sfr __at 0x80 P0;
__sfr __at 0x81 SP;
__sfr __at 0x82 DPL;
__sfr __at 0x83 DPH;
__sfr __at 0x84 DPL1;
__sfr __at 0x85 DPH1;
__sfr __at 0x87 PCON;
__sfr __at 0x88 TCON;
__sfr __at 0x89 TMOD;
__sfr __at 0x8A TL0;
__sfr __at 0x8B TL1;
__sfr __at 0x8C TH0;
__sfr __at 0x8D TH1;
__sfr __at 0x8F P3CON;
__sfr __at 0x90 P1;
__sfr __at 0x92 DPS;
__sfr __at 0x93 P0DIR;
__sfr __at 0x94 P1DIR;
__sfr __at 0x95 P2DIR;
__sfr __at 0x96 P3DIR;
__sfr __at 0x97 P2CON;
__sfr __at 0x98 S0CON;
__sfr __at 0x99 S0BUF;
__sfr __at 0x9E P0CON;
__sfr __at 0x9F P1CON;
__sfr __at 0xA0 P2;
__sfr __at 0xA1 PWMDC0;
__sfr __at 0xA2 PWMDC1;
__sfr __at 0xA3 CLKCTRL;
__sfr __at 0xA4 PWRDWN;
__sfr __at 0xA5 WUCON;
__sfr __at 0xA6 INTEXP;
__sfr __at 0xA7 MEMCON;
__sfr __at 0xA8 IEN0;
__sfr __at 0xA9 IP0;
__sfr __at 0xAA S0RELL;
__sfr __at 0xAB RTC2CPT01;
__sfr __at 0xAC RTC2CPT10;
__sfr __at 0xAD CLKLFCTRL;
__sfr __at 0xAE OPMCON;
__sfr __at 0xAF WDSV;
__sfr __at 0xB0 P3;
__sfr __at 0xB1 RSTREAS;
__sfr __at 0xB2 PWMCON;
__sfr __at 0xB3 RTC2CON;
__sfr __at 0xB4 RTC2CMP0;
__sfr __at 0xB5 RTC2CMP1;
__sfr __at 0xB6 RTC2CPT00;
__sfr __at 0xB7 SPISRDSZ;
__sfr __at 0xB8 IEN1;
__sfr __at 0xB9 IP1;
__sfr __at 0xBA S0RELH;
__sfr __at 0xBC SPISCON0;
__sfr __at 0xBD SPISCON1;
__sfr __at 0xBE SPISSTAT;
__sfr __at 0xBF SPISDAT;
__sfr __at 0xC0 IRCON;
__sfr __at 0xC1 CCEN;
__sfr __at 0xC2 CCL1;
__sfr __at 0xC3 CCH1;
__sfr __at 0xC4 CCL2;
__sfr __at 0xC5 CCH2;
__sfr __at 0xC6 CCL3;
__sfr __at 0xC7 CCH3;
__sfr __at 0xC8 T2CON;
__sfr __at 0xC9 MPAGE;
__sfr __at 0xC9 _XPAGE; //for SDCC's memory initialization
__sfr __at 0xCA CRCL;
__sfr __at 0xCB CRCH;
__sfr __at 0xCC TL2;
__sfr __at 0xCD TH2;
__sfr __at 0xCE WUOPC1;
__sfr __at 0xCF WUOPC0;
__sfr __at 0xD0 PSW;
__sfr __at 0xD1 ADCCON3;
__sfr __at 0xD2 ADCCON2;
__sfr __at 0xD3 ADCCON1;
__sfr __at 0xD4 ADCDATH;
__sfr __at 0xD5 ADCDATL;
__sfr __at 0xD6 RNGCTL;
__sfr __at 0xD7 RNGDAT;
__sfr __at 0xD8 ADCON;
__sfr __at 0xD9 W2SADR;
__sfr __at 0xDA W2DAT;
__sfr __at 0xDB COMPCON;
__sfr __at 0xDC POFCON;
__sfr __at 0xDD CCPDATIA;
__sfr __at 0xDE CCPDATIB;
__sfr __at 0xDF CCPDATO;
__sfr __at 0xE0 ACC;
__sfr __at 0xE1 W2CON1;
__sfr __at 0xE2 W2CON0;
__sfr __at 0xE4 SPIRCON0;
__sfr __at 0xE5 SPIRCON1;
__sfr __at 0xE6 SPIRSTAT;
__sfr __at 0xE7 SPIRDAT;
__sfr __at 0xE8 RFCON;
__sfr __at 0xE9 MD0;
__sfr __at 0xEA MD1;
__sfr __at 0xEB MD2;
__sfr __at 0xEC MD3;
__sfr __at 0xED MD4;
__sfr __at 0xEE MD5;
__sfr __at 0xEF ARCON;
__sfr __at 0xF0 B;
__sfr __at 0xF8 FSR;
__sfr __at 0xF9 FPCR;
__sfr __at 0xFA FCR;
__sfr __at 0xFC SPIMCON0;
__sfr __at 0xFD SPIMCON1;
__sfr __at 0xFE SPIMSTAT;
__sfr __at 0xFF SPIMDAT;

///////////////////////////////////////////
// Two-byte __sfrs
///////////////////////////////////////////
__sfr16 __at 0xC3C2 CC1;
__sfr16 __at 0xC5C4 CC2;
__sfr16 __at 0xC7C6 CC3;
__sfr16 __at 0xCBCA CRC;
__sfr16 __at 0x8C8A T0;
__sfr16 __at 0x8D8B T1;
__sfr16 __at 0xCDCC T2;
__sfr16 __at 0xBAAA	S0REL;
__sfr16 __at 0xD4D5 ADCDAT;

///////////////////////////////////////////
// __sbit defines for P0 register
///////////////////////////////////////////
__sbit __at 0x80 P0_SB_D0;
__sbit __at 0x81 P0_SB_D1;
__sbit __at 0x82 P0_SB_D2;
__sbit __at 0x83 P0_SB_D3;
__sbit __at 0x84 P0_SB_D4;
__sbit __at 0x85 P0_SB_D5;
__sbit __at 0x86 P0_SB_D6;
__sbit __at 0x87 P0_SB_D7;

///////////////////////////////////////////
// __sbit defines for TCON register
///////////////////////////////////////////
__sbit __at 0x88 TCON_SB_IT0;
__sbit __at 0x89 TCON_SB_IE0;
__sbit __at 0x8A TCON_SB_IT1;
__sbit __at 0x8B TCON_SB_IE1;
__sbit __at 0x8C TCON_SB_TR0;
__sbit __at 0x8D TCON_SB_TF0;
__sbit __at 0x8E TCON_SB_TR1;
__sbit __at 0x8F TCON_SB_TF1;

///////////////////////////////////////////
// __sbit defines for P1 register
///////////////////////////////////////////
__sbit __at 0x90 P1_SB_D0;
__sbit __at 0x91 P1_SB_D1;
__sbit __at 0x92 P1_SB_D2;
__sbit __at 0x93 P1_SB_D3;
__sbit __at 0x94 P1_SB_D4;
__sbit __at 0x95 P1_SB_D5;
__sbit __at 0x96 P1_SB_D6;
__sbit __at 0x97 P1_SB_D7;

///////////////////////////////////////////
// __sbit defines for S0CON register
///////////////////////////////////////////
__sbit __at 0x98 S0CON_SB_RI0;
__sbit __at 0x99 S0CON_SB_TI0;
__sbit __at 0x9A S0CON_SB_RB80;
__sbit __at 0x9B S0CON_SB_TB80;
__sbit __at 0x9C S0CON_SB_REN0;
__sbit __at 0x9D S0CON_SB_SM20;
__sbit __at 0x9E S0CON_SB_SM1;
__sbit __at 0x9F S0CON_SB_SM0;

///////////////////////////////////////////
// __sbit defines for P2 register
///////////////////////////////////////////
__sbit __at 0xA0 P2_SB_D0;
__sbit __at 0xA1 P2_SB_D1;
__sbit __at 0xA2 P2_SB_D2;
__sbit __at 0xA3 P2_SB_D3;
__sbit __at 0xA4 P2_SB_D4;
__sbit __at 0xA5 P2_SB_D5;
__sbit __at 0xA6 P2_SB_D6;
__sbit __at 0xA7 P2_SB_D7;

///////////////////////////////////////////
// __sbit defines for IEN0 register
///////////////////////////////////////////
__sbit __at 0xA8 IEN0_SB_IFP;
__sbit __at 0xA9 IEN0_SB_T0;
__sbit __at 0xAA IEN0_SB_POFIRQ;
__sbit __at 0xAB IEN0_SB_T1;
__sbit __at 0xAC IEN0_SB_UART;
__sbit __at 0xAD IEN0_SB_T2;
__sbit __at 0xAF IEN0_SB_GLOBAL;

///////////////////////////////////////////
// __sbit defines for P3 register
///////////////////////////////////////////
__sbit __at 0xB0 P3_SB_D0;
__sbit __at 0xB1 P3_SB_D1;
__sbit __at 0xB2 P3_SB_D2;
__sbit __at 0xB3 P3_SB_D3;
__sbit __at 0xB4 P3_SB_D4;
__sbit __at 0xB5 P3_SB_D5;
__sbit __at 0xB6 P3_SB_D6;
__sbit __at 0xB7 P3_SB_D7;

///////////////////////////////////////////
// __sbit defines for IEN1 register
///////////////////////////////////////////
__sbit __at 0xB8 IEN1_SB_RFRDY;
__sbit __at 0xB9 IEN1_SB_RFIRQ;
__sbit __at 0xBA IEN1_SB_SPI_2WIRE;
__sbit __at 0xBB IEN1_SB_WUOPIRQ;
__sbit __at 0xBC IEN1_SB_MISCIRQ;
__sbit __at 0xBD IEN1_SB_TICK;
__sbit __at 0xBF IEN1_SB_T2EXTRLD;

///////////////////////////////////////////
// __sbit defines for IRCON register
///////////////////////////////////////////
__sbit __at 0xC0 IRCON_SB_RFRDY;
__sbit __at 0xC1 IRCON_SB_RFIRQ;
__sbit __at 0xC2 IRCON_SB_SPI_2WIRE;
__sbit __at 0xC3 IRCON_SB_WUOPIRQ;
__sbit __at 0xC4 IRCON_SB_MISCIRQ;
__sbit __at 0xC5 IRCON_SB_TICK;
__sbit __at 0xC6 IRCON_SB_TF2;
__sbit __at 0xC7 IRCON_SB_EXF2;

///////////////////////////////////////////
// __sbit defines for T2CON register
///////////////////////////////////////////
__sbit __at 0xC8 T2CON_SB_T2I0;
__sbit __at 0xC9 T2CON_SB_T2I1;
__sbit __at 0xCA T2CON_SB_T2CM;
__sbit __at 0xCB T2CON_SB_T2R0;
__sbit __at 0xCC T2CON_SB_T2R1;
__sbit __at 0xCD T2CON_SB_I2FR;
__sbit __at 0xCE T2CON_SB_I3FR;
__sbit __at 0xCF T2CON_SB_T2PS;

///////////////////////////////////////////
// __sbit defines for PSW register
///////////////////////////////////////////
__sbit __at 0xD7 PSW_SB_CY;
__sbit __at 0xD6 PSW_SB_AC;
__sbit __at 0xD5 PSW_SB_F0;
__sbit __at 0xD4 PSW_SB_RS1;
__sbit __at 0xD3 PSW_SB_RS0;
__sbit __at 0xD2 PSW_SB_OV;
__sbit __at 0xD1 PSW_SB_F1;
__sbit __at 0xD0 PSW_SB_P;

///////////////////////////////////////////
// __sbit defines for ADCON register
///////////////////////////////////////////
__sbit __at 0xDF ADCON_SB_BD;

///////////////////////////////////////////
// __sbit defines for RFCON register
///////////////////////////////////////////
__sbit __at 0xE8 RFCON_SB_RFCE;
__sbit __at 0xE9 RFCON_SB_RFCSN;
__sbit __at 0xEA RFCON_SB_RFCKEN;

///////////////////////////////////////////
// __sbit defines for FSR register
///////////////////////////////////////////
__sbit __at 0xFA FSR_SB_RDISMB;
__sbit __at 0xFB FSR_SB_INFEN;
__sbit __at 0xFC FSR_SB_RDYN;
__sbit __at 0xFD FSR_SB_WEN;
__sbit __at 0xFE FSR_SB_STP;
__sbit __at 0xFF FSR_SB_ENDBG;

///////////////////////////////////////////
// Bit defines for PCON register
///////////////////////////////////////////
#define PCON_IDLE	0x01
#define PCON_STOP	0x02
#define PCON_GF0	0x04
#define PCON_GF1	0x08
#define PCON_PMW	0x10
#define PCON_GF2	0x20
#define PCON_GF3	0x40
#define PCON_SMOD	0x80

///////////////////////////////////////////
// Bit defines for PX registers
///////////////////////////////////////////
#define PX_D0	0x01
#define PX_D1	0x02
#define PX_D2	0x04
#define PX_D3	0x08
#define PX_D4	0x10
#define PX_D5	0x20
#define PX_D6	0x40
#define PX_D7	0x80

///////////////////////////////////////////
// Bit defines for PXDIR registers
///////////////////////////////////////////
#define PXDIR_D0	0x01
#define PXDIR_D1	0x02
#define PXDIR_D2	0x04
#define PXDIR_D3	0x08
#define PXDIR_D4	0x10
#define PXDIR_D5	0x20
#define PXDIR_D6	0x40
#define PXDIR_D7	0x80

///////////////////////////////////////////
// Bit defines for PXCON registers
///////////////////////////////////////////
#define PXCON_BIT_ADDR_SHIFT	0
#define PXCON_BIT_ADDR_MASK		(0x07 << PXCON_BIT_ADDR_SHIFT)
#define PXCON_READ_ADDR			0x08
#define PXCON_IN_OUT			0x10
#define PXCON_PINMODE_SHIFT		5
#define PXCON_PINMODE_MASK		(0x07 << PXCON_PINMODE_SHIFT)

///////////////////////////////////////////
// Bit defines for S0CON register
///////////////////////////////////////////
#define S0CON_RI0			0x01
#define S0CON_TI0			0x02
#define S0CON_RB80			0x04
#define S0CON_TB80			0x08
#define S0CON_REN0			0x10
#define S0CON_SM20			0x20
#define S0CON_MODE_SHIFT	6
#define S0CON_MODE_FIELD	(0x03 << S0CON_MODE_SHIFT)

///////////////////////////////////////////
// Bit defines for ADCON register
///////////////////////////////////////////
#define ADCON_BD	0x80

///////////////////////////////////////////
// Bit defines for RFCON register
///////////////////////////////////////////
#define RFCON_RFCE		0x01
#define RFCON_RFCSN		0x02
#define RFCON_RFCKEN	0x04

///////////////////////////////////////////
// Bit defines for SPIRCON register
///////////////////////////////////////////
#define SPIRCON1_MASK_IRQ_TX_FIFO_READY	0x01
#define SPIRCON1_MASK_IRQ_TX_FIFO_EMPTY	0x02
#define SPIRCON1_MASK_IRQ_RX_FIFO_READY	0x04
#define SPIRCON1_MASK_IRQ_RX_FIFO_FULL	0x08

///////////////////////////////////////////
// Bit defines for SPIRSTAT register
///////////////////////////////////////////
#define SPIRSTAT_IRQ_TX_FIFO_READY	0x01
#define SPIRSTAT_IRQ_TX_FIFO_EMPTY	0x02
#define SPIRSTAT_IRQ_RX_FIFO_READY	0x04
#define SPIRSTAT_IRQ_RX_FIFO_FULL	0x08

///////////////////////////////////////////
// Bit defines for IRCON register
///////////////////////////////////////////
#define IRCON_RFRDY		0x01
#define IRCON_RFIRQ		0x02
#define IRCON_SPI_2WIRE	0x04
#define IRCON_WUOPIRQ	0x08
#define IRCON_MISCIRQ	0x10
#define IRCON_TICK		0x20
#define IRCON_TF2		0x40
#define IRCON_EXF2		0x80

///////////////////////////////////////////
// Bit defines for INTEXP register
///////////////////////////////////////////
#define INTEXP_SSPI_COMPLETED_INT_ENABLE	0x01
#define INTEXP_MSPI_COMPLETED_INT_ENABLE	0x02
#define INTEXP_2WIRE_COMPLETED_INT_ENABLE	0x04
#define INTEXP_GP_INT0_ENABLE				0x08
#define INTEXP_GP_INT1_ENABLE				0x10
#define INTEXP_GP_INT2_ENABLE				0x20

///////////////////////////////////////////
// Bit defines for SPIMCON0 register
///////////////////////////////////////////
#define SPIMCON0_ENABLE			0x01
#define SPIMCON0_CPHA			0x02
#define SPIMCON0_CPOL			0x04
#define SPIMCON0_DATA_ORDER		0x08
#define SPIMCON0_CLK_DIV_SHIFT	4
#define SPIMCON0_CLK_DIV_MASK	(0x03 << SPIMCON0_CLK_DIV_SHIFT)

///////////////////////////////////////////
// Bit defines for SPIMCON1 register
///////////////////////////////////////////
#define SPIMCON1_INT_TX_FIFO_READY_DISABLE	0x01
#define SPIMCON1_INT_TX_FIFO_EMPTY_DISABLE	0x02
#define SPIMCON1_INT_RX_DATA_READY_DISABLE	0x04
#define SPIMCON1_INT_RX_DATA_FULL_DISABLE	0x08

///////////////////////////////////////////
// Bit defines for SPIMSTAT register
///////////////////////////////////////////
#define SPIMSTAT_INT_TX_FIFO_READY_FLAG	0x01
#define SPIMSTAT_INT_TX_FIFO_EMPTY_FLAG	0x02
#define SPIMSTAT_INT_RX_DATA_READY_FLAG	0x04
#define SPIMSTAT_INT_RX_DATA_FULL_FLAG	0x08

///////////////////////////////////////////
// Bit defines for SPISCON0 register
///////////////////////////////////////////
#define SPISCON0_ENABLE						0x01
#define SPISCON0_CPHA						0x02
#define SPISCON0_CPOL						0x04
#define SPISCON0_DATA_ORDER					0x08
#define SPISCON0_INT_SPI_SLAVE_DONE_DISABLE	0x10
#define SPISCON0_INT_CSN_LOW_DISABLE		0x20
#define SPISCON0_INT_CSN_HIGH_DISABLE		0x40

///////////////////////////////////////////
// Bit defines for SPISSTAT register
///////////////////////////////////////////
#define SPISSTAT_INT_SPI_SLAVE_DONE_FLAG	0x01
#define SPISSTAT_INT_CSN_LOW_FLAG			0x10
#define SPISSTAT_INT_CSN_HIGH_FLAG			0x20

///////////////////////////////////////////
// Bit defines for ADCCON1 register
///////////////////////////////////////////
#define ADCCON1_REF_SEL_SHIFT		0
#define ADCCON1_REF_SEL_MASK		(0x03 << ADCCON1_REF_SEL_SHIFT)
#define ADCCON1_CHAN_SEL_SHIFT		2
#define ADCCON1_CHAN_SEL_MASK		(0x0F << ADCCON1_CHAN_SEL_SHIFT)
#define ADCCON1_BUSY_FLAG			0x40
#define ADCCON1_POWER_UP			0x80

///////////////////////////////////////////
// Bit defines for ADCCON2 register
///////////////////////////////////////////
#define ADCCON2_ACQ_TIME_SHIFT			0
#define ADCCON2_ACQ_TIME_MASK			(0x03 << ADCCON2_ACQ_TIME_SHIFT)
#define ADCCON2_SAMPLING_RATE_SHIFT		2
#define ADCCON2_SAMPLING_RATE_MASK		(0x03 << ADCCON2_SAMPLING_RATE_SHIFT)
#define ADCCON2_CONTINUOUS_SAMPLING		0x20
#define ADCCON2_SAMPLING_MODE_SHIFT		6
#define ADCCON2_SAMPLING_MODE_MASK		(0x03 << ADCCON2_SAMPLING_MODE_SHIFT)

///////////////////////////////////////////
// Bit defines for ADCCON3 register
///////////////////////////////////////////
#define ADCCON3_RANGE_FLAG				0x04
#define ADCCON3_OVERFLOW_FLAG			0x08
#define ADCCON3_UNDERFLOW_FLAG			0x10
#define ADCCON3_RESULT_RIGHT_JUSTIFIED	0x20
#define ADCCON3_BIT_RES_SHIFT			6
#define ADCCON3_BIT_RES_MASK			(0x03 << ADCCON3_BIT_RES_SHIFT)

///////////////////////////////////////////
// Bit defines for TCON register
///////////////////////////////////////////
#define TCON_IT0	0x01
#define TCON_IE0	0x02
#define TCON_IT1	0x04
#define TCON_IE1	0x08
#define TCON_TR0	0x10
#define TCON_TF0	0x20
#define TCON_TR1	0x40
#define TCON_TF1	0x80

///////////////////////////////////////////
// Bit defines for TMOD register
///////////////////////////////////////////
#define TMOD_MODE0_SHIFT	0
#define TMOD_MODE0_MASK		(0x03 << TMOD_MODE0_SHIFT)
#define TMOD_CT0			0x04
#define TMOD_GATE0			0x08
#define TMOD_MODE1_SHIFT	4
#define TMOD_MODE1_MASK		(0x03 << TMOD_MODE1_SHIFT)
#define TMOD_CT1			0x40
#define TMOD_GATE1			0x80

///////////////////////////////////////////
// Bit defines for PWMCON register
///////////////////////////////////////////
#define PWMCON_PWM0_ENABLE		0x01
#define PWMCON_PWM1_ENABLE		0x02
#define PWMCON_PRESCALER_SHIFT	2
#define PWMCON_PRESCALER_MASK	(0x0F << PWMCON_PRESCALER_SHIFT)
#define PWMCON_BIT_WIDTH_SHIFT	6
#define PWMCON_BIT_WIDTH_MASK	(0x03 << PWMCON_BIT_WIDTH_SHIFT)

///////////////////////////////////////////
// Bit defines for RNGCTL register
///////////////////////////////////////////
#define RNGCTL_RESULT_READY			0x20
#define RNGCTL_CORRECTOR_ENABLE		0x40
#define RNGCTL_POWER_UP				0x80

///////////////////////////////////////////
// Bit defines for CLKCTRL register
///////////////////////////////////////////
#define CLKCTRL_CLK_FREQ_SHIFT					0
#define CLKCTRL_CLK_FREQ_MASK					(0x07 << CLKCTRL_CLK_FREQ_SHIFT)
#define CLKCTRL_XOSC16M_ACTIVE_WKUP_INT_ENABLE	0x08
#define CLKCTRL_XOSC16M_RCOSC16M_START_SHIFT	4
#define CLKCTRL_XOSC16M_RCOSC16M_START_MASK		(0x03 << CLKCTRL_XOSC16M_RCOSC16M_START_SHIFT)
#define CLKCTRL_CLK_SRC_PIN_XC1_OR_OSC			0x40
#define CLKCTRL_XOSC16M_IN_REG_RET_MODE_ENABLE	0x80

///////////////////////////////////////////
// Bit defines for CLKLFCTRL register
///////////////////////////////////////////
#define CLKLFCTRL_CLKLF_SRC_SHIFT		0
#define CLKLFCTRL_CLKLF_SRC_MASK		(0x07 << CLKLFCTRL_CLKLF_SRC_SHIFT)
#define CLKLFCTRL_IS_CLKLF_SRC_XOSC16M	0x08
#define CLKLFCTRL_IS_CLKLF_READY		0x40
#define CLKLFCTRL_CLKLF_VAL_READ		0x80

///////////////////////////////////////////
// Bit defines for PWRDWN register
///////////////////////////////////////////
#define PWRDWN_PWR_CNTL_SHIFT				0
#define PWRDWN_PWR_CNTL_MASK				(0x07 << PWRDWN_PWR_CNTL_SHIFT)
#define PWRDWN_PWR_IS_WAKE_FROM_COMPARATOR	0x20
#define PWRDWN_PWR_IS_WAKE_FROM_TICK		0x40
#define PWRDWN_PWR_IS_WAKE_FROM_PIN			0x80

///////////////////////////////////////////
// Bit defines for RSTREAS register
///////////////////////////////////////////
#define RSTREAS_RESET_REASON_SHIFT	0
#define RSTREAS_RESET_REASON_MASK	(0x07 << RSTREAS_RESET_REASON_SHIFT)

///////////////////////////////////////////
// Bit defines for OPMCON register
///////////////////////////////////////////
#define OPMCON_WATCHDOG_RESET_ENABLE	0x01
#define OPMCON_RETENTION_LATCH_CONTROL	0x02
#define OPMCON_WAKEUP_PINS_POLARITY		0x04

///////////////////////////////////////////
// Bit defines for POFCON register
///////////////////////////////////////////
#define POFCON_POF_WARNING			0x10
#define POFCON_POF_THRESHOLD_SHIFT	5
#define POFCON_POF_THRESHOLD_MASK	(0x03 << POFCON_POF_THRESHOLD_SHIFT)
#define POFCON_POF_ENABLE			0x80

///////////////////////////////////////////
// Bit defines for WUCON register
///////////////////////////////////////////
#define WUCON_WAKE_ON_MISCIRQ_SHIFT		0
#define WUCON_WAKE_ON_MISCIRQ_MASK		(0x03 << WUCON_WAKE_ON_MISCIRQ_SHIFT)
#define WUCON_WAKE_ON_WUOPIRQ_SHIFT		2
#define WUCON_WAKE_ON_WUOPIRQ_MASK		(0x03 << WUCON_WAKE_ON_WUOPIRQ_SHIFT)
#define WUCON_WAKE_ON_RTC2_TICK_SHIFT	4
#define WUCON_WAKE_ON_RTC2_TICK_MASK	(0x03 << WUCON_WAKE_ON_RTC2_TICK_SHIFT)
#define WUCON_WAKE_ON_RFIRQ_SHIFT		6
#define WUCON_WAKE_ON_RFIRQ_MASK		(0x03 << WUCON_WAKE_ON_RFIRQ_SHIFT)

///////////////////////////////////////////
// Bit defines for WUOPCX registers
///////////////////////////////////////////
#define WUOPCX_PIN0		0x01
#define WUOPCX_PIN1		0x02
#define WUOPCX_PIN2		0x04
#define WUOPCX_PIN3		0x08
#define WUOPCX_PIN4		0x10
#define WUOPCX_PIN5		0x20
#define WUOPCX_PIN6		0x40
#define WUOPCX_PIN7		0x80

///////////////////////////////////////////
// Bit defines for RTC2CON register
///////////////////////////////////////////
#define RTC2CON_ENABLE						0x01
#define RTC2CON_COMPARE_MODE_SHIFT			1
#define RTC2CON_COMPARE_MODE_MASK			(0x03 << RTC2CON_COMPARE_MODE_SHIFT)
#define RTC2CON_ENABLE_EXTERNAL_CAPTURE		0x04
#define RTC2CON_SFR_CAPTURE					0x10

///////////////////////////////////////////
// Bit defines for T2CON register
///////////////////////////////////////////
#define T2CON_INPUT_SEL_SHIFT		0
#define T2CON_INPUT_SEL_MASK		(0x03 << T2CON_INPUT_SEL_SHIFT)
#define T2CON_COMPARE_MODE			0x02
#define T2CON_RELOAD_MODE_SHIFT		3
#define T2CON_RELOAD_MODE_MASK		(0x03 << T2CON_RELOAD_MODE_SHIFT)
#define T2CON_INT2_EDGE				0x20
#define T2CON_INT3_EDGE				0x40
#define T2CON_PRESCALER				0x80

///////////////////////////////////////////
// Bit defines for CCEN register
///////////////////////////////////////////
#define CCEN_CRC_MODE_SHIFT			0
#define CCEN_CRC_MODE_MASK			(0x03 << CCEN_CRC_MODE_SHIFT)
#define CCEN_CC1_MODE_SHIFT			2
#define CCEN_CC1_MODE_MASK			(0x03 << CCEN_CC1_MODE_SHIFT)
#define CCEN_CC2_MODE_SHIFT			4
#define CCEN_CC2_MODE_MASK			(0x03 << CCEN_CC2_MODE_SHIFT)
#define CCEN_CC3_MODE_SHIFT			6
#define CCEN_CC3_MODE_MASK			(0x03 << CCEN_CC3_MODE_SHIFT)

///////////////////////////////////////////
// Bit defines for COMPCON register
///////////////////////////////////////////
#define COMPCON_ENABLE				0x01
#define COMPCON_REF_SEL				0x02
#define COMPCON_REF_SCALE_SHIFT		2
#define COMPCON_REF_SCALE_MASK		(0x03 << COMPCON_REF_SCALE_SHIFT)
#define COMPCON_POLARITY			0x10

///////////////////////////////////////////
// Bit defines for W2CON0 register
///////////////////////////////////////////
#define W2CON0_ENABLE							0x01
#define W2CON0_MASTER_SELECT					0x02
#define W2CON0_CLOCK_FREQUENCY_SHIFT			2
#define W2CON0_CLOCK_FREQUENCY_MASK				(0x03 << W2CON0_CLOCK_FREQUENCY_SHIFT)
#define W2CON0_MASTER_TX_START					0x10
#define W2CON0_SLAVE_DISABLE_IRQ_ON_ADDR_MATCH	0x10
#define W2CON0_MASTER_TX_STOP					0x20
#define W2CON0_SLAVE_DISABLE_IRQ_ON_STOP		0x20
#define W2CON0_SLAVE_CLOCK_STOP					0x40
#define W2CON0_SLAVE_BROADCAST_ENABLE			0x80

///////////////////////////////////////////
// Bit defines for W2CON1 register
///////////////////////////////////////////
#define W2CON1_DATA_READY						0x01
#define W2CON1_LAST_ACK							0x02
#define W2CON1_SLAVE_IRQ_DUE_TO_ADDR_MATCH		0x04
#define W2CON1_SLAVE_IRQ_DUE_TO_STOP			0x08
#define W2CON1_SLAVE_LAST_ADDR_WAS_BROADCAST	0x10
#define W2CON1_DISABLE_INTERRUPTS				0x20

///////////////////////////////////////////
// Bit defines for W2DAT register
///////////////////////////////////////////
#define W2DAT_DIRECTION			0x01
#define W2DAT_ADDRESS_SHIFT		1
#define W2DAT_ADDRESS_MASK		(0x7F << W2DAT_ADDRESS_SHIFT)

///////////////////////////////////////////
// Bit defines for MEMCON register
///////////////////////////////////////////
#define MEMCON_SRAM_DATA_RETENTIVE_MAPPING		0x01
#define MEMCON_SRAM_DATA_NON_RETENTIVE_MAPPING	0x02
#define MEMCON_SRAM_START_LOCATION				0x04

///////////////////////////////////////////
// Bit defines for FSR register
///////////////////////////////////////////
#define FSR_RDISMB	0x04
#define FSR_INFEN	0x08
#define FSR_RDYN	0x10
#define FSR_WEN		0x20
#define FSR_STP		0x40
#define FSR_ENDBG	0x80

///////////////////////////////////////////
// Bit defines for FPCR register
///////////////////////////////////////////
#define FPCR_NUPP_MASK	0x7F


///////////////////////////////////////////
// Additional defines
///////////////////////////////////////////
#define	CCLK_MAX_FREQ_HZ	16000000					//16 MHz clock frequency
#define	CCLK_MAX_FREQ_KHZ	(CCLK_MAX_FREQ_HZ / 1000)	//16 MHz clock frequency
#define	CCLK_MAX_FREQ_MHZ	(CCLK_MAX_FREQ_KHZ / 1000)	//16 MHz clock frequency
#define BIT_TRUE			1							//Simple define for 1
#define BIT_FALSE			0							//Simple define for 0

///////////////////////////////////////////
// define for bool type
///////////////////////////////////////////
#ifndef bool
#define bool uint8_t
#endif
#ifndef false
#define false 0
#endif
#ifndef true
#define true (!false)
#endif

////////////////////////////////////////////////
// Defenitions for nRF24LE1 packages
////////////////////////////////////////////////
#define NRF24LE1_PACKAGE_24_PIN 0
#define NRF24LE1_PACKAGE_32_PIN 1
#define NRF24LE1_PACKAGE_48_PIN 2

/////////////////////////////////////////////////////////////////
// Verify existence of __TARG_PACKAGE_TYPE
/////////////////////////////////////////////////////////////////
#ifndef __TARG_PACKAGE_TYPE
#error "You must define __TARG_PACKAGE_TYPE in the appropriate target_nrf24le1_sdk.h file to use this header file"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
// Verify that __TARG_PACKAGE_TYPE has been set to an appropriate value
//////////////////////////////////////////////////////////////////////////////////////////////
#if (__TARG_PACKAGE_TYPE != NRF24LE1_PACKAGE_24_PIN) && (__TARG_PACKAGE_TYPE != NRF24LE1_PACKAGE_32_PIN) && (__TARG_PACKAGE_TYPE != NRF24LE1_PACKAGE_48_PIN)
#error "__TARG_PACKAGE_TYPE has been defined, but it has been defined to an incorrect value.  Please see #defines NR24LE1_PACKAGE_XX_PIN in include/reg24le1.h"
#endif


///////////////////////////////////////////////////////////////////////////////
// Simple instructions
///////////////////////////////////////////////////////////////////////////////
#define nop() __asm nop __endasm	//No-operation instruction wrapper

///////////////////////////////////////////////////////////////////////////////
// Macros for waiting on bit values
///////////////////////////////////////////////////////////////////////////////
#define wait_for_bit_level_high(bit)	while(!(bit))					//Wait for a bit to go high
#define wait_for_bit_level_low(bit)	    while(bit)						//Wait for a bit to go low
#define wait_for_bit_edge_rising(bit)	wait_for_bit_level_low(bit);\
										wait_for_bit_level_high(bit)	//Wait for a bit to have a rising edge
#define wait_for_bit_edge_falling(bit)	wait_for_bit_level_high(bit);\
										wait_for_bit_level_low(bit)		//Wait for a bit to have a falling edge
#define wait_for_bit_toggle(bit)		if(bit)\
											while(bit);\
										else\
											while(!(bit))				//Wait for a bit to change in value

///////////////////////////////////////////////////////////////////////////////
// Macros for changing bits in registers
///////////////////////////////////////////////////////////////////////////////
#define reg_bits_set(reg, mask)			((reg) |= (mask))	//Set bit(s) in a register
#define reg_bits_clear(reg, mask)		((reg) &= ~(mask))	//Clear bit(s) in a register
#define reg_bits_complement(reg, mask)	((reg) ^= (mask))	//Complement bit(s) in a register

///////////////////////////////////////////////////////////////////////////////
// Macros for changing SBITs
///////////////////////////////////////////////////////////////////////////////
#define sbit_set(sbit_pin_set)					__asm setb _##sbit_pin_set __endasm			//Set an SBIT
#define sbit_clear(sbit_pin_clear)				__asm clr  _##sbit_pin_clear __endasm		//Clear an SBIT
#define sbit_complement(sbit_pin_complement)	__asm cpl  _##sbit_pin_complement __endasm	//Complement an SBIT

#endif
