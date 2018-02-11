/*
	Copyright (c) 2012-2018, Anatol Belski <ab@php.net>
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	- Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	- Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in the
	documentation and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* $Id$ */

#include "php.h"
#include "php_trader.h"

#include <ta_func.h>
#include <ta_common.h>

ZEND_EXTERN_MODULE_GLOBALS(trader)

/* {{{ proto array trader_minmaxindex(array real [, int timePeriod])
	Indexes of lowest and highest values over a specified period */
PHP_FUNCTION(trader_minmaxindex)
{
	int optimalOutAlloc, lookback;
	zval *zinReal;
	double *inReal;
	int startIdx = 0, endIdx = 0, outBegIdx = 0, outNBElement = 0, *outMinIdx = 0, *outMaxIdx = 0;
	zend_long optInTimePeriod = 2;
	

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|l", &zinReal, &optInTimePeriod) == FAILURE) {
		RETURN_FALSE
	}

	
	TRADER_LONG_SET_BOUNDABLE(2, 100000, optInTimePeriod);	

	TRADER_SET_MIN_INT1(endIdx, zend_hash_num_elements(Z_ARRVAL_P(zinReal)))
	endIdx--; /* it's <= in the ta-lib */
	

	lookback = TA_MINMAXINDEX_Lookback((int)optInTimePeriod);
	optimalOutAlloc = (lookback > endIdx) ? 0 : (endIdx - lookback + 1);
	if (optimalOutAlloc > 0) {
		outMinIdx = emalloc(sizeof(double)*optimalOutAlloc);
		outMaxIdx = emalloc(sizeof(double)*optimalOutAlloc);
		TRADER_DBL_ZARR_TO_ARR(zinReal, inReal)

		TRADER_G(last_error) = TA_MINMAXINDEX(startIdx, endIdx, inReal, (int)optInTimePeriod, &outBegIdx, &outNBElement, outMinIdx, outMaxIdx);
		if (TRADER_G(last_error) != TA_SUCCESS) {
			efree(inReal);
			efree(outMinIdx);
			efree(outMaxIdx);

			RETURN_FALSE
		}

		TRADER_DBL_ARR_TO_ZRET2(outMinIdx, outMaxIdx, return_value, endIdx, outBegIdx, outNBElement)

		efree(inReal);
		efree(outMinIdx);
		efree(outMaxIdx);
	} else {
		/* The current input args combination would cause TA-Lib to produce
			 zero output, don't bother making any allocs or calls. */
		TRADER_G(last_error) = TA_BAD_PARAM;
		RETURN_FALSE
	}
}
/* }}} */

