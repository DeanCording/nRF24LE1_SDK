/////////////////////////////////////////////////////////////////////////////
//
// File: rf_set_data_rate.c
//
// Copyright Dean Cording, 2013
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
// void rf_set_data_rate(uint8_t data_rate)
//
// Description:
//  Sets the data transmission rate of the device (250kbps, 1Mbps, 2Mbps)
//
// Parameters:
//  uint8_t power - new power level RF_RF_SETUP_RF_DR_[250_KBPS|1_MBPS|2_MBPS]
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rf_set_data_rate(uint8_t data_rate)
{
  
  if ((data_rate == RF_RF_SETUP_RF_DR_250_KBPS) ||
      (data_rate == RF_RF_SETUP_RF_DR_1_MBPS) ||
      (data_rate == RF_RF_SETUP_RF_DR_2_MBPS)) {
    
    uint8_t rf_setup = rf_read_register_1_byte(RF_RF_SETUP) & ~RF_RF_SETUP_RF_DR;
    rf_setup = (rf_setup & ~RF_RF_SETUP_RF_PWR) | data_rate;
    rf_write_register(RF_RF_SETUP, &rf_setup, 1);
  }
}
