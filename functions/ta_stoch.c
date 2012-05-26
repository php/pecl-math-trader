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

/*{{{ proto array ta_stoch(MY_FUNC_DOC_PARAMS)
	Stochastic */
PHP_FUNCTION(ta_stoch)
{
	zval *zinHigh, *zinLow, *zinClose, *zoutSlowK;
	double *inHigh, *inLow, *inClose, *outSlowK, *outSlowD;
	int startIdx, endIdx, outBegIdx, outNBElement;
	long optInFastK_Period = 1, optInSlowK_Period = 1, optInSlowK_MAType, optInSlowD_Period = 1, optInSlowD_MAType;
	

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aaa|lllll", &zinHigh, &zinLow, &zinClose, &optInFastK_Period, &optInSlowK_Period, &optInSlowK_MAType, &optInSlowD_Period, &optInSlowD_MAType) == FAILURE) {
		RETURN_FALSE
	}
	/* XXX check ma type if any*/
	TA_SET_BOUNDABLE(1, 100000, optInFastK_Period);
	TA_SET_BOUNDABLE(1, 100000, optInSlowK_Period);
	TA_SET_BOUNDABLE(1, 100000, optInSlowD_Period);	

	TA_SET_MIN_INT4(endIdx, zend_hash_num_elements(Z_ARRVAL_P(zinHigh)),
		zend_hash_num_elements(Z_ARRVAL_P(zinLow)),
		zend_hash_num_elements(Z_ARRVAL_P(zinClose)),
		zend_hash_num_elements(Z_ARRVAL_P(zoutSlowK)))
	startIdx = 0;

	outSlowD = emalloc(sizeof(double)*(endIdx+1));
	TA_DBL_ZARR_TO_ARR(zinHigh, inHigh)
	TA_DBL_ZARR_TO_ARR(zinLow, inLow)
	TA_DBL_ZARR_TO_ARR(zinClose, inClose)
	TA_DBL_ZARR_TO_ARR(zoutSlowK, outSlowK)

	if (TA_STOCH(startIdx, endIdx, inHigh, inLow, inClose, (int)optInFastK_Period, (int)optInSlowK_Period, (int)optInSlowK_MAType, (int)optInSlowD_Period, (int)optInSlowD_MAType, &outBegIdx, &outNBElement, outSlowK, outSlowD) != TA_SUCCESS) {
		efree(inHigh);
		efree(inLow);
		efree(inClose);
		efree(outSlowK);
		efree(outSlowD);;

		RETURN_FALSE
	}

	TA_DBL_ARR_TO_ZARR1(outSlowD, return_value, endIdx, outBegIdx, outNBElement)

	efree(inHigh);
	efree(inLow);
	efree(inClose);
	efree(outSlowK);
	efree(outSlowD);;
}
/*}}}*/

