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
#include "php_ta.h"

#include <ta_func.h>
#include <ta_common.h>

ZEND_EXTERN_MODULE_GLOBALS(ta)

/*{{{ proto array ta_aroon(MY_FUNC_DOC_PARAMS)
	Aroon */
PHP_FUNCTION(ta_aroon)
{
	zval *zinHigh, *zinLow, *zoutAroonDown;
	double *inHigh, *inLow, *outAroonDown, *outAroonUp;
	int startIdx, endIdx, outBegIdx, outNBElement;
	long optInTimePeriod = 2;
	

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa|l", &zinHigh, &zinLow, &optInTimePeriod) == FAILURE) {
		RETURN_FALSE
	}
	/* XXX check ma type if any*/
	TA_SET_BOUNDABLE(2, 100000, optInTimePeriod);	

	TA_SET_MIN_INT3(endIdx, zend_hash_num_elements(Z_ARRVAL_P(zinHigh)),
		zend_hash_num_elements(Z_ARRVAL_P(zinLow)),
		zend_hash_num_elements(Z_ARRVAL_P(zoutAroonDown)))
	startIdx = 0;

	outAroonUp = emalloc(sizeof(double)*(endIdx+1));
	TA_DBL_ZARR_TO_ARR(zinHigh, inHigh)
	TA_DBL_ZARR_TO_ARR(zinLow, inLow)
	TA_DBL_ZARR_TO_ARR(zoutAroonDown, outAroonDown)

	if (TA_AROON(startIdx, endIdx, inHigh, inLow, (int)optInTimePeriod, &outBegIdx, &outNBElement, outAroonDown, outAroonUp) != TA_SUCCESS) {
		efree(inHigh);
		efree(inLow);
		efree(outAroonDown);
		efree(outAroonUp);

		RETURN_FALSE
	}

	TA_DBL_ARR_TO_ZARR1(outAroonUp, return_value, endIdx, outBegIdx, outNBElement-1)

	efree(inHigh);
	efree(inLow);
	efree(outAroonDown);
	efree(outAroonUp);
}
/*}}}*/
