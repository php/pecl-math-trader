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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_ta.h"

#include <ta_func.h>
#include <ta_common.h>

ZEND_DECLARE_MODULE_GLOBALS(ta)

/* True global resources - no need for thread safety here */
static int le_ta;

/* {{{ ta_arginfo */
ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ad, 0, 0, 4)
	ZEND_ARG_INFO(0, high)
	ZEND_ARG_INFO(0, low)
	ZEND_ARG_INFO(0, close)
	ZEND_ARG_INFO(0, volume)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adosc, 0, 0, 4)
	ZEND_ARG_INFO(0, high)
	ZEND_ARG_INFO(0, low)
	ZEND_ARG_INFO(0, close)
	ZEND_ARG_INFO(0, volume)
	ZEND_ARG_INFO(0, fast_period)
	ZEND_ARG_INFO(0, slow_period)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adx, 0, 0, 3)
	ZEND_ARG_INFO(0, high)
	ZEND_ARG_INFO(0, low)
	ZEND_ARG_INFO(0, close)
	ZEND_ARG_INFO(0, time_period)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adxr, 0, 0, 3)
	ZEND_ARG_INFO(0, high)
	ZEND_ARG_INFO(0, low)
	ZEND_ARG_INFO(0, close)
	ZEND_ARG_INFO(0, time_period)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_apo, 0, 0, 1)
	ZEND_ARG_INFO(0, high)
	ZEND_ARG_INFO(0, fast_period)
	ZEND_ARG_INFO(0, slow_period)
	ZEND_ARG_INFO(0, ma_type)
ZEND_END_ARG_INFO();
/* }}} */

/* {{{ ta_functions[]
 *
 * Every user visible function must have an entry in ta_functions[].
 */
const zend_function_entry ta_functions[] = {
	PHP_FE(ta_ad, arg_info_ta_ad)
	PHP_FE(ta_adosc, arg_info_ta_adosc)
	PHP_FE(ta_adx, arg_info_ta_adx)
	PHP_FE(ta_adxr, arg_info_ta_adxr)
	PHP_FE(ta_apo, arg_info_ta_apo)
	PHP_FE_END
};
/* }}} */

/* {{{ ta_module_entry
 */
zend_module_entry ta_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"ta",
	ta_functions,
	PHP_MINIT(ta),
	PHP_MSHUTDOWN(ta),
	PHP_RINIT(ta),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(ta),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(ta),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TA
ZEND_GET_MODULE(ta)
#endif

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("ta.real_precision", "3", PHP_INI_ALL, OnUpdateLong, real_precision, zend_ta_globals, ta_globals)
PHP_INI_END()
/* }}} */

/* {{{ php_ta_globals_ctor
 */
static void php_ta_globals_ctor(zend_ta_globals *ta_globals)
{
	ta_globals->real_precision = TA_DEFAULT_REAL_PRECISION;
}
/* }}} */

/* {{{ php_ta_globals_dtor
 */
static void php_ta_globals_dtor(zend_ta_globals *ta_globals)
{
	/* pass */
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(ta)
{
	ZEND_INIT_MODULE_GLOBALS(ta, php_ta_globals_ctor, php_ta_globals_dtor);

	REGISTER_INI_ENTRIES();

	REGISTER_LONG_CONSTANT("TA_MA_TYPE_SMA", TA_MAType_SMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_EMA", TA_MAType_EMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_WMA", TA_MAType_WMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_DEMA", TA_MAType_DEMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_TEMA", TA_MAType_TEMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_TRIMA", TA_MAType_TRIMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_KAMA", TA_MAType_KAMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_MAMA", TA_MAType_MAMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_T3", TA_MAType_T3, CONST_CS | CONST_PERSISTENT);

	REGISTER_DOUBLE_CONSTANT("TA_REAL_MIN", TA_REAL_MIN, CONST_CS | CONST_PERSISTENT);
	REGISTER_DOUBLE_CONSTANT("TA_REAL_MAX", TA_REAL_MAX, CONST_CS | CONST_PERSISTENT);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(ta)
{
	UNREGISTER_INI_ENTRIES();
#ifdef ZTS
	    ts_free_id(ta_globals_id);
#else
		php_ta_globals_dtor(&ta_globals TSRMLS_CC);
#endif

	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(ta)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(ta)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(ta)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Technical Analysis Library Support", "enabled");
	php_info_print_table_header(2, "Version", TA_PHP_VERSION);
	php_info_print_table_header(2, "TA-Lib version", TA_GetVersionString());
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */

/*{{{ proto array ta_ad(array high, array low, array close, array volume)
	Accumulation/Distribution Line (AD) */
PHP_FUNCTION(ta_ad)
{
	zval *high_in, *low_in, *close_in, *vol_in;
	double *high, *low, *close, *vol, *result;
	int startidx = 0, endidx, outbegidx, outnbeelem;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aaaa", &high_in, &low_in, &close_in, &vol_in) == FAILURE) {
		RETURN_FALSE
	}

	TA_SET_MIN_INT4(endidx, zend_hash_num_elements(Z_ARRVAL_P(high_in)),
				zend_hash_num_elements(Z_ARRVAL_P(low_in)),
				zend_hash_num_elements(Z_ARRVAL_P(close_in)),
				zend_hash_num_elements(Z_ARRVAL_P(vol_in)));
	endidx--;

	TA_DBL_ZARR_TO_ARR(high_in, high)
	TA_DBL_ZARR_TO_ARR(low_in, low)
	TA_DBL_ZARR_TO_ARR(close_in, close)
	TA_DBL_ZARR_TO_ARR(vol_in, vol)
	result = emalloc(sizeof(double)*(endidx+1));

	if (TA_AD(startidx, endidx, high, low, close, vol, &outbegidx, &outnbeelem, result) != TA_SUCCESS) {
		TA_EFREE5(high, low, close, vol, result)
		RETURN_FALSE
	}
	
	TA_DBL_ARR_TO_ZARR(result, return_value, endidx, outbegidx, outnbeelem-1)

	TA_EFREE5(high, low, close, vol, result)
}
/*}}}*/

/*{{{ proto array ta_adosc(array high, array low, array close, array volume[, int fast_period, [int slow_period]])
	Accumulation/Distribution Oscillator */
PHP_FUNCTION(ta_adosc)
{
	zval *high_in, *low_in, *close_in, *vol_in;
	double *high, *low, *close, *vol, *result;
	int startidx = 0, endidx, outbegidx, outnbeelem;
	long fast_period, slow_period;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aaaa|ll", &high_in, &low_in, &close_in, &vol_in, &fast_period, &slow_period) == FAILURE) {
		RETURN_FALSE
	}

	TA_SET_PERIOD(2, 100000, fast_period)
	TA_SET_PERIOD(2, 100000, slow_period)

	TA_SET_MIN_INT4(endidx, zend_hash_num_elements(Z_ARRVAL_P(high_in)),
				zend_hash_num_elements(Z_ARRVAL_P(low_in)),
				zend_hash_num_elements(Z_ARRVAL_P(close_in)),
				zend_hash_num_elements(Z_ARRVAL_P(vol_in)));
	endidx--;

	TA_DBL_ZARR_TO_ARR(high_in, high)
	TA_DBL_ZARR_TO_ARR(low_in, low)
	TA_DBL_ZARR_TO_ARR(close_in, close)
	TA_DBL_ZARR_TO_ARR(vol_in, vol)
	result = emalloc(sizeof(double)*(endidx));

	if (TA_ADOSC(startidx, endidx, high, low, close, vol, (int)fast_period, (int)slow_period, &outbegidx, &outnbeelem, result) != TA_SUCCESS) {
		TA_EFREE5(high, low, close, vol, result)
		RETURN_FALSE
	}

	TA_DBL_ARR_TO_ZARR(result, return_value, endidx, outbegidx, outnbeelem)

	TA_EFREE5(high, low, close, vol, result)
}
/*}}}*/

/*{{{ proto array ta_adx(array high, array low, array close [, int time_period]) 
 	Directional Movement - Average Index */
PHP_FUNCTION(ta_adx)
{
	zval *high_in, *low_in, *close_in;
	double *high, *low, *close, *result;
	int startidx = 0, endidx, outbegidx, outnbeelem;
	long time_period;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aaa|l", &high_in, &low_in, &close_in, &time_period) == FAILURE) {
		RETURN_FALSE
	}

	TA_SET_PERIOD(2, 100000, time_period)

	TA_SET_MIN_INT3(endidx, zend_hash_num_elements(Z_ARRVAL_P(high_in)),
				zend_hash_num_elements(Z_ARRVAL_P(low_in)),
				zend_hash_num_elements(Z_ARRVAL_P(close_in)));
	endidx--;

	TA_DBL_ZARR_TO_ARR(high_in, high)
	TA_DBL_ZARR_TO_ARR(low_in, low)
	TA_DBL_ZARR_TO_ARR(close_in, close)
	result = emalloc(sizeof(double)*endidx);

	if (TA_ADX(startidx, endidx, high, low, close, (int)time_period, &outbegidx, &outnbeelem, result) != TA_SUCCESS) {
		TA_EFREE4(high, low, close, result)
		RETURN_FALSE
	}

	TA_DBL_ARR_TO_ZARR(result, return_value, endidx, outbegidx, outnbeelem)

	/*printf("startidx %d, endidx %d, outbegidx %d, outnbeelem %d\n", startidx, endidx, outbegidx, outnbeelem);*/

	TA_EFREE4(high, low, close, result)
}
/*}}}*/

/*{{{ proto array ta_adxr(array high, array low, array close, int time_period) 
	Directional Movement - Average Index Rating */
PHP_FUNCTION(ta_adxr)
{
	zval *high_in, *low_in, *close_in;
	double *high, *low, *close, *result;
	int startidx = 0, endidx, outbegidx, outnbeelem;
	long time_period;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aaa|l", &high_in, &low_in, &close_in, &time_period) == FAILURE) {
		return;
	}

	TA_SET_PERIOD(2, 100000, time_period)

	TA_SET_MIN_INT3(endidx, zend_hash_num_elements(Z_ARRVAL_P(high_in)),
				zend_hash_num_elements(Z_ARRVAL_P(low_in)),
				zend_hash_num_elements(Z_ARRVAL_P(close_in)));
	endidx--;

	TA_DBL_ZARR_TO_ARR(high_in, high)
	TA_DBL_ZARR_TO_ARR(low_in, low)
	TA_DBL_ZARR_TO_ARR(close_in, close)
	result = emalloc(sizeof(double)*endidx);

	if (TA_ADXR(startidx, endidx, high, low, close, (int)time_period, &outbegidx, &outnbeelem, result) != TA_SUCCESS) {
		TA_EFREE4(high, low, close, result)
		RETURN_FALSE;
	}

	TA_DBL_ARR_TO_ZARR(result, return_value, endidx, outbegidx, outnbeelem)

	TA_EFREE4(high, low, close, result)
}
/*}}}*/

/*{{{ proto array ta_apo(array price, int fast_period, int slow_period, int ma_type)
	Price Oscillator - Absolute */
PHP_FUNCTION(ta_apo)
{
	zval *price_in;
	double *result, *price;
	int startidx = 0, endidx, outbegidx, outnbeelem;
	long fast_period, slow_period, ma_type = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|lll", &price_in, &fast_period, &slow_period, &ma_type) == FAILURE) {
		return;
	}

	TA_SET_PERIOD(2, 100000, fast_period)
	TA_SET_PERIOD(2, 100000, slow_period)
	/* XXX check ma type */

	endidx = zend_hash_num_elements(Z_ARRVAL_P(price_in));

	TA_DBL_ZARR_TO_ARR(price_in, price)
	result = emalloc(sizeof(double)*endidx);

	if (TA_APO(startidx, endidx, price, (int)fast_period, (int)slow_period, (int)ma_type, &outbegidx, &outnbeelem, result) != TA_SUCCESS) {
		TA_EFREE2(price, result)
		RETURN_FALSE;
	}

	TA_DBL_ARR_TO_ZARR(result, return_value, endidx, outbegidx, outnbeelem)

	TA_EFREE2(price, result)
}
/*}}}*/

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
