/*
	Copyright (c) 2012, Anatoliy Belsky <ab@php.net>
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

/*{{{ proto array trader_macdfix(MY_FUNC_DOC_PARAMS)
	Moving Average Convergence/Divergence Fix 12/26 */
PHP_FUNCTION(trader_macdfix)
{
	zval *zinReal, *zoutMACD, *zoutMACDSignal;
	double *inReal, *outMACD, *outMACDSignal, *outMACDHist;
	int startIdx = 0, endIdx = 0, outBegIdx = 0, outNBElement = 0;
	long optInSignalPeriod = 1;
	

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|l", &zinReal, &optInSignalPeriod) == FAILURE) {
		RETURN_FALSE
	}
	/* XXX check ma type if any*/
	TRADER_SET_BOUNDABLE(1, 100000, optInSignalPeriod);	

	TRADER_SET_MIN_INT1(endIdx, zend_hash_num_elements(Z_ARRVAL_P(zinReal)))
	endIdx--; /* it's <= in the ta-lib */
	

	outMACD = emalloc(sizeof(double)*(endIdx+1));
	outMACDSignal = emalloc(sizeof(double)*(endIdx+1));
	outMACDHist = emalloc(sizeof(double)*(endIdx+1));
	TRADER_DBL_ZARR_TO_ARR(zinReal, inReal)

	if (TA_MACDFIX(startIdx, endIdx, inReal, (int)optInSignalPeriod, &outBegIdx, &outNBElement, outMACD, outMACDSignal, outMACDHist) != TA_SUCCESS) {
		efree(inReal);
		efree(outMACD);
		efree(outMACDSignal);
		efree(outMACDHist);

		RETURN_FALSE
	}

	TRADER_DBL_ARR_TO_ZRET3(outMACD, outMACDSignal, outMACDHist, return_value, endIdx, outBegIdx, outNBElement)

	efree(inReal);
	efree(outMACD);
	efree(outMACDSignal);
	efree(outMACDHist);
}
/*}}}*/

