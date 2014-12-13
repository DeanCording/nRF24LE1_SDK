#include "pwr_clk_mgmt.h"

/* Setup the watchdog to start working, this mostly enables the clock source
 * and waits until it is initialized.
 *
 * Please note that this uses the RCOSC32K clock source and it will conflict
 * with other clock sources if you intend to use another source.
 */
inline void watchdog_setup(void)
{
	if (!pwr_clk_mgmt_is_clklf_enabled())
	{
		//CLKLF is not running, so enable RCOSC32K and wait until it is ready
		pwr_clk_mgmt_clklf_configure(PWR_CLK_MGMT_CLKLF_CONFIG_OPTION_CLK_SRC_RCOSC32K);
		pwr_clk_mgmt_wait_until_clklf_is_ready();
	}
}
