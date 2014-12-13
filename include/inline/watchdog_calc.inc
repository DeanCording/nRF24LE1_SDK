/* These functions calculate the watchdog value from time values in either
 * seconds or milliseconds. These watchdog values are then fed into
 * watchdog_set_wdsv_count.
 *
 * It is recommended to use it like so:
 * #define TIMEOUT_VAL watchdog_calc_timeout_from_sec(30)
 * ...
 * watchdog_set_wdsv_count(TIMEOUT_VAL);
 *
 * This will generate the most efficient code of simply loading the WDSV
 * register with the right values.
 *
 * The nRF24LE1 can only handle timeouts of at most 512 seconds, do not try to
 * feed higher values. There is no safety mechanism for that in the code as the
 * optimizer barfs on the conditional.
 */

inline uint16_t watchdog_calc_timeout_from_sec(uint16_t sec)
{
	return sec * 128U;
}

inline uint16_t watchdog_calc_timeout_from_ms(uint32_t msec)
{
	//From the formula on p. 104 of v1.6 of the nRF24LE1 datasheet, the equation for the watchdog timeout (in seconds) is given as
	//
	//                     WDSV * 256
	//    WD_timeout (s) = ----------
	//                       32768
	//
	// This then reduces to
	//
	//                     WDSV
	//    WD_timeout (s) = ----
	//                     128
	//
	// Then if we want the watchdog timeout to be in units of milliseconds
	//
	//                      WDSV * 1000
	//    WD_timeout (ms) = -----------
	//                          128
	//
	// Solving for WDSV
	//
	//           WD_timeout (ms) * 128
	//    WDSV = ---------------------
	//                   1000
	//
	// By adding 500 to the numerator before performing the division, the result gets rounded (as 500 is half of 1000, the denominator)
	msec *= 128U;
	msec += 500U;
	return (uint16_t)(msec / 1000U);
}
