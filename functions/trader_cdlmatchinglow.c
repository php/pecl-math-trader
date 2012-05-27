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

/*{{{ proto array trader_cdlmatchinglow(array open, array high, array low, array close)
	Matching Low */
PHP_FUNCTION(trader_cdlmatchinglow)
{
	zval *zinOpen, *zinHigh, *zinLow, *zinClose;
	double *inOpen, *inHigh, *inLow, *inClose;
	int startIdx = 0, endIdx = 0, outBegIdx = 0, outNBElement = 0, *outInteger = 0;
	
	

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aaaa", &zinOpen, &zinHigh, &zinLow, &zinClose) == FAILURE) {
		RETURN_FALSE
	}
	/* XXX check ma type if any*/
		

	TRADER_SET_MIN_INT4(endIdx, zend_hash_num_elements(Z_ARRVAL_P(zinOpen)),
		zend_hash_num_elements(Z_ARRVAL_P(zinHigh)),
		zend_hash_num_elements(Z_ARRVAL_P(zinLow)),
		zend_hash_num_elements(Z_ARRVAL_P(zinClose)))
	endIdx--; /* it's <= in the ta-lib */
	

	outInteger = emalloc(sizeof(double)*(endIdx+1));
	TRADER_DBL_ZARR_TO_ARR(zinOpen, inOpen)
	TRADER_DBL_ZARR_TO_ARR(zinHigh, inHigh)
	TRADER_DBL_ZARR_TO_ARR(zinLow, inLow)
	TRADER_DBL_ZARR_TO_ARR(zinClose, inClose)

	if (TA_CDLMATCHINGLOW(startIdx, endIdx, inOpen, inHigh, inLow, inClose, &outBegIdx, &outNBElement, outInteger) != TA_SUCCESS) {
		efree(inOpen);
		efree(inHigh);
		efree(inLow);
		efree(inClose);
		efree(outInteger);

		RETURN_FALSE
	}

	TRADER_DBL_ARR_TO_ZRET1(outInteger, return_value, endIdx, outBegIdx, outNBElement)

	efree(inOpen);
	efree(inHigh);
	efree(inLow);
	efree(inClose);
	efree(outInteger);
}
/*}}}*/
