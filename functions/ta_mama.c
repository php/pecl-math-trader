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

/*{{{ proto array ta_mama(MY_FUNC_DOC_PARAMS)
	MESA Adaptive Moving Average */
PHP_FUNCTION(ta_mama)
{
	zval *zinReal, *zoutMAMA;
	double *inReal, *outMAMA, *outFAMA;
	int startIdx, endIdx, outBegIdx, outNBElement;
	
	double optInFastLimit = 0.01, optInSlowLimit = 0.01;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|dd", &zinReal, &optInFastLimit, &optInSlowLimit) == FAILURE) {
		RETURN_FALSE
	}
	/* XXX check ma type if any*/
	TA_SET_BOUNDABLE(0.01, 0.99, optInFastLimit);
	TA_SET_BOUNDABLE(0.01, 0.99, optInSlowLimit);	

	TA_SET_MIN_INT1(endIdx, zend_hash_num_elements(Z_ARRVAL_P(zinReal)))
	startIdx = 0;

	outMAMA = emalloc(sizeof(double)*(endIdx+1));
	outFAMA = emalloc(sizeof(double)*(endIdx+1));
	TA_DBL_ZARR_TO_ARR(zinReal, inReal)

	if (TA_MAMA(startIdx, endIdx, inReal, optInFastLimit, optInSlowLimit, &outBegIdx, &outNBElement, outMAMA, outFAMA) != TA_SUCCESS) {
		efree(inReal);
		efree(outMAMA);
		efree(outFAMA);

		RETURN_FALSE
	}

	TA_DBL_ARR_TO_ZRET2(outMAMA, outFAMA, return_value, endIdx, outBegIdx, outNBElement-1)

	efree(inReal);
	efree(outMAMA);
	efree(outFAMA);
}
/*}}}*/

