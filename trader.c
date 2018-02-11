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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_trader.h"

#include <ta_func.h>
#include <ta_common.h>

ZEND_DECLARE_MODULE_GLOBALS(trader)

/* True global resources - no need for thread safety here */
static int le_trader;

#ifndef PHP_FE_END
#define PHP_FE_END { NULL, NULL, NULL, 0, 0 }
#endif

/* {{{ trader_arginfo */
ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_acos, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ad, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_ARRAY_INFO(0,  volume, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_add, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  real0, 0)
	ZEND_ARG_ARRAY_INFO(0,  real1, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_adosc, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_ARRAY_INFO(0,  volume, 0)
	ZEND_ARG_INFO(0,  fastPeriod)
	ZEND_ARG_INFO(0,  slowPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_adx, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_adxr, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_apo, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  fastPeriod)
	ZEND_ARG_INFO(0,  slowPeriod)
	ZEND_ARG_INFO(0,  mAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_aroon, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_aroonosc, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_asin, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_atan, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_atr, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_avgprice, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_bbands, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
	ZEND_ARG_INFO(0,  nbDevUp)
	ZEND_ARG_INFO(0,  nbDevDn)
	ZEND_ARG_INFO(0,  mAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_beta, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  real0, 0)
	ZEND_ARG_ARRAY_INFO(0,  real1, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_bop, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cci, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdl2crows, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdl3blackcrows, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdl3inside, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdl3linestrike, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdl3outside, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdl3starsinsouth, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdl3whitesoldiers, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlabandonedbaby, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  penetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdladvanceblock, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlbelthold, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlbreakaway, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlclosingmarubozu, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlconcealbabyswall, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlcounterattack, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdldarkcloudcover, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  penetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdldoji, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdldojistar, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdldragonflydoji, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlengulfing, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdleveningdojistar, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  penetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdleveningstar, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  penetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlgapsidesidewhite, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlgravestonedoji, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlhammer, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlhangingman, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlharami, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlharamicross, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlhighwave, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlhikkake, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlhikkakemod, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlhomingpigeon, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlidentical3crows, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlinneck, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlinvertedhammer, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlkicking, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlkickingbylength, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlladderbottom, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdllongleggeddoji, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdllongline, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlmarubozu, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlmatchinglow, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlmathold, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  penetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlmorningdojistar, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  penetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlmorningstar, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  penetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlonneck, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlpiercing, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlrickshawman, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlrisefall3methods, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlseparatinglines, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlshootingstar, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlshortline, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlspinningtop, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlstalledpattern, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlsticksandwich, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdltakuri, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdltasukigap, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlthrusting, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdltristar, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlunique3river, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlupsidegap2crows, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cdlxsidegap3methods, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  open, 0)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ceil, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cmo, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_correl, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  real0, 0)
	ZEND_ARG_ARRAY_INFO(0,  real1, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cos, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_cosh, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_dema, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_div, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  real0, 0)
	ZEND_ARG_ARRAY_INFO(0,  real1, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_dx, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ema, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_exp, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_floor, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ht_dcperiod, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ht_dcphase, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ht_phasor, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ht_sine, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ht_trendline, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ht_trendmode, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_kama, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_linearreg, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_linearreg_angle, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_linearreg_intercept, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_linearreg_slope, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ln, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_log10, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ma, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
	ZEND_ARG_INFO(0,  mAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_macd, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  fastPeriod)
	ZEND_ARG_INFO(0,  slowPeriod)
	ZEND_ARG_INFO(0,  signalPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_macdext, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  fastPeriod)
	ZEND_ARG_INFO(0,  fastMAType)
	ZEND_ARG_INFO(0,  slowPeriod)
	ZEND_ARG_INFO(0,  slowMAType)
	ZEND_ARG_INFO(0,  signalPeriod)
	ZEND_ARG_INFO(0,  signalMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_macdfix, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  signalPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_mama, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  fastLimit)
	ZEND_ARG_INFO(0,  slowLimit)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_mavp, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_ARRAY_INFO(0,  periods, 0)
	ZEND_ARG_INFO(0,  minPeriod)
	ZEND_ARG_INFO(0,  maxPeriod)
	ZEND_ARG_INFO(0,  mAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_max, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_maxindex, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_medprice, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_mfi, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_ARRAY_INFO(0,  volume, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_midpoint, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_midprice, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_min, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_minindex, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_minmax, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_minmaxindex, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_minus_di, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_minus_dm, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_mom, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_mult, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  real0, 0)
	ZEND_ARG_ARRAY_INFO(0,  real1, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_natr, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_obv, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_ARRAY_INFO(0,  volume, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_plus_di, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_plus_dm, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ppo, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  fastPeriod)
	ZEND_ARG_INFO(0,  slowPeriod)
	ZEND_ARG_INFO(0,  mAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_roc, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_rocp, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_rocr, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_rocr100, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_rsi, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_sar, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_INFO(0,  acceleration)
	ZEND_ARG_INFO(0,  maximum)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_sarext, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_INFO(0,  startValue)
	ZEND_ARG_INFO(0,  offsetOnReverse)
	ZEND_ARG_INFO(0,  accelerationInitLong)
	ZEND_ARG_INFO(0,  accelerationLong)
	ZEND_ARG_INFO(0,  accelerationMaxLong)
	ZEND_ARG_INFO(0,  accelerationInitShort)
	ZEND_ARG_INFO(0,  accelerationShort)
	ZEND_ARG_INFO(0,  accelerationMaxShort)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_sin, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_sinh, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_sma, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_sqrt, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_stddev, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
	ZEND_ARG_INFO(0,  nbDev)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_stoch, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  fastK_Period)
	ZEND_ARG_INFO(0,  slowK_Period)
	ZEND_ARG_INFO(0,  slowK_MAType)
	ZEND_ARG_INFO(0,  slowD_Period)
	ZEND_ARG_INFO(0,  slowD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_stochf, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  fastK_Period)
	ZEND_ARG_INFO(0,  fastD_Period)
	ZEND_ARG_INFO(0,  fastD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_stochrsi, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
	ZEND_ARG_INFO(0,  fastK_Period)
	ZEND_ARG_INFO(0,  fastD_Period)
	ZEND_ARG_INFO(0,  fastD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_sub, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0,  real0, 0)
	ZEND_ARG_ARRAY_INFO(0,  real1, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_sum, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_t3, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
	ZEND_ARG_INFO(0,  vFactor)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_tan, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_tanh, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_tema, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_trange, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_trima, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_trix, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_tsf, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_typprice, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_ultosc, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod1)
	ZEND_ARG_INFO(0,  timePeriod2)
	ZEND_ARG_INFO(0,  timePeriod3)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_var, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
	ZEND_ARG_INFO(0,  nbDev)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_wclprice, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_willr, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0,  high, 0)
	ZEND_ARG_ARRAY_INFO(0,  low, 0)
	ZEND_ARG_ARRAY_INFO(0,  close, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_wma, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0,  real, 0)
	ZEND_ARG_INFO(0,  timePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_set_unstable_period, 0, 0, 2)
	ZEND_ARG_INFO(0,  functionId)
	ZEND_ARG_INFO(0,  unstablePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_get_unstable_period, 0, 0, 1)
	ZEND_ARG_INFO(0,  functionId)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_set_compat, 0, 0, 1)
	ZEND_ARG_INFO(0,  compat)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_get_compat, 0, 0, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_trader_errno, 0, 0, 0)
ZEND_END_ARG_INFO();
/* }}} */

/* {{{ trader_functions[]
 *
 * Every user visible function must have an entry in trader_functions[].
 */
const zend_function_entry trader_functions[] = {
	PHP_FE(trader_acos, arg_info_trader_acos)
	PHP_FE(trader_ad, arg_info_trader_ad)
	PHP_FE(trader_add, arg_info_trader_add)
	PHP_FE(trader_adosc, arg_info_trader_adosc)
	PHP_FE(trader_adx, arg_info_trader_adx)
	PHP_FE(trader_adxr, arg_info_trader_adxr)
	PHP_FE(trader_apo, arg_info_trader_apo)
	PHP_FE(trader_aroon, arg_info_trader_aroon)
	PHP_FE(trader_aroonosc, arg_info_trader_aroonosc)
	PHP_FE(trader_asin, arg_info_trader_asin)
	PHP_FE(trader_atan, arg_info_trader_atan)
	PHP_FE(trader_atr, arg_info_trader_atr)
	PHP_FE(trader_avgprice, arg_info_trader_avgprice)
	PHP_FE(trader_bbands, arg_info_trader_bbands)
	PHP_FE(trader_beta, arg_info_trader_beta)
	PHP_FE(trader_bop, arg_info_trader_bop)
	PHP_FE(trader_cci, arg_info_trader_cci)
	PHP_FE(trader_cdl2crows, arg_info_trader_cdl2crows)
	PHP_FE(trader_cdl3blackcrows, arg_info_trader_cdl3blackcrows)
	PHP_FE(trader_cdl3inside, arg_info_trader_cdl3inside)
	PHP_FE(trader_cdl3linestrike, arg_info_trader_cdl3linestrike)
	PHP_FE(trader_cdl3outside, arg_info_trader_cdl3outside)
	PHP_FE(trader_cdl3starsinsouth, arg_info_trader_cdl3starsinsouth)
	PHP_FE(trader_cdl3whitesoldiers, arg_info_trader_cdl3whitesoldiers)
	PHP_FE(trader_cdlabandonedbaby, arg_info_trader_cdlabandonedbaby)
	PHP_FE(trader_cdladvanceblock, arg_info_trader_cdladvanceblock)
	PHP_FE(trader_cdlbelthold, arg_info_trader_cdlbelthold)
	PHP_FE(trader_cdlbreakaway, arg_info_trader_cdlbreakaway)
	PHP_FE(trader_cdlclosingmarubozu, arg_info_trader_cdlclosingmarubozu)
	PHP_FE(trader_cdlconcealbabyswall, arg_info_trader_cdlconcealbabyswall)
	PHP_FE(trader_cdlcounterattack, arg_info_trader_cdlcounterattack)
	PHP_FE(trader_cdldarkcloudcover, arg_info_trader_cdldarkcloudcover)
	PHP_FE(trader_cdldoji, arg_info_trader_cdldoji)
	PHP_FE(trader_cdldojistar, arg_info_trader_cdldojistar)
	PHP_FE(trader_cdldragonflydoji, arg_info_trader_cdldragonflydoji)
	PHP_FE(trader_cdlengulfing, arg_info_trader_cdlengulfing)
	PHP_FE(trader_cdleveningdojistar, arg_info_trader_cdleveningdojistar)
	PHP_FE(trader_cdleveningstar, arg_info_trader_cdleveningstar)
	PHP_FE(trader_cdlgapsidesidewhite, arg_info_trader_cdlgapsidesidewhite)
	PHP_FE(trader_cdlgravestonedoji, arg_info_trader_cdlgravestonedoji)
	PHP_FE(trader_cdlhammer, arg_info_trader_cdlhammer)
	PHP_FE(trader_cdlhangingman, arg_info_trader_cdlhangingman)
	PHP_FE(trader_cdlharami, arg_info_trader_cdlharami)
	PHP_FE(trader_cdlharamicross, arg_info_trader_cdlharamicross)
	PHP_FE(trader_cdlhighwave, arg_info_trader_cdlhighwave)
	PHP_FE(trader_cdlhikkake, arg_info_trader_cdlhikkake)
	PHP_FE(trader_cdlhikkakemod, arg_info_trader_cdlhikkakemod)
	PHP_FE(trader_cdlhomingpigeon, arg_info_trader_cdlhomingpigeon)
	PHP_FE(trader_cdlidentical3crows, arg_info_trader_cdlidentical3crows)
	PHP_FE(trader_cdlinneck, arg_info_trader_cdlinneck)
	PHP_FE(trader_cdlinvertedhammer, arg_info_trader_cdlinvertedhammer)
	PHP_FE(trader_cdlkicking, arg_info_trader_cdlkicking)
	PHP_FE(trader_cdlkickingbylength, arg_info_trader_cdlkickingbylength)
	PHP_FE(trader_cdlladderbottom, arg_info_trader_cdlladderbottom)
	PHP_FE(trader_cdllongleggeddoji, arg_info_trader_cdllongleggeddoji)
	PHP_FE(trader_cdllongline, arg_info_trader_cdllongline)
	PHP_FE(trader_cdlmarubozu, arg_info_trader_cdlmarubozu)
	PHP_FE(trader_cdlmatchinglow, arg_info_trader_cdlmatchinglow)
	PHP_FE(trader_cdlmathold, arg_info_trader_cdlmathold)
	PHP_FE(trader_cdlmorningdojistar, arg_info_trader_cdlmorningdojistar)
	PHP_FE(trader_cdlmorningstar, arg_info_trader_cdlmorningstar)
	PHP_FE(trader_cdlonneck, arg_info_trader_cdlonneck)
	PHP_FE(trader_cdlpiercing, arg_info_trader_cdlpiercing)
	PHP_FE(trader_cdlrickshawman, arg_info_trader_cdlrickshawman)
	PHP_FE(trader_cdlrisefall3methods, arg_info_trader_cdlrisefall3methods)
	PHP_FE(trader_cdlseparatinglines, arg_info_trader_cdlseparatinglines)
	PHP_FE(trader_cdlshootingstar, arg_info_trader_cdlshootingstar)
	PHP_FE(trader_cdlshortline, arg_info_trader_cdlshortline)
	PHP_FE(trader_cdlspinningtop, arg_info_trader_cdlspinningtop)
	PHP_FE(trader_cdlstalledpattern, arg_info_trader_cdlstalledpattern)
	PHP_FE(trader_cdlsticksandwich, arg_info_trader_cdlsticksandwich)
	PHP_FE(trader_cdltakuri, arg_info_trader_cdltakuri)
	PHP_FE(trader_cdltasukigap, arg_info_trader_cdltasukigap)
	PHP_FE(trader_cdlthrusting, arg_info_trader_cdlthrusting)
	PHP_FE(trader_cdltristar, arg_info_trader_cdltristar)
	PHP_FE(trader_cdlunique3river, arg_info_trader_cdlunique3river)
	PHP_FE(trader_cdlupsidegap2crows, arg_info_trader_cdlupsidegap2crows)
	PHP_FE(trader_cdlxsidegap3methods, arg_info_trader_cdlxsidegap3methods)
	PHP_FE(trader_ceil, arg_info_trader_ceil)
	PHP_FE(trader_cmo, arg_info_trader_cmo)
	PHP_FE(trader_correl, arg_info_trader_correl)
	PHP_FE(trader_cos, arg_info_trader_cos)
	PHP_FE(trader_cosh, arg_info_trader_cosh)
	PHP_FE(trader_dema, arg_info_trader_dema)
	PHP_FE(trader_div, arg_info_trader_div)
	PHP_FE(trader_dx, arg_info_trader_dx)
	PHP_FE(trader_ema, arg_info_trader_ema)
	PHP_FE(trader_exp, arg_info_trader_exp)
	PHP_FE(trader_floor, arg_info_trader_floor)
	PHP_FE(trader_ht_dcperiod, arg_info_trader_ht_dcperiod)
	PHP_FE(trader_ht_dcphase, arg_info_trader_ht_dcphase)
	PHP_FE(trader_ht_phasor, arg_info_trader_ht_phasor)
	PHP_FE(trader_ht_sine, arg_info_trader_ht_sine)
	PHP_FE(trader_ht_trendline, arg_info_trader_ht_trendline)
	PHP_FE(trader_ht_trendmode, arg_info_trader_ht_trendmode)
	PHP_FE(trader_kama, arg_info_trader_kama)
	PHP_FE(trader_linearreg, arg_info_trader_linearreg)
	PHP_FE(trader_linearreg_angle, arg_info_trader_linearreg_angle)
	PHP_FE(trader_linearreg_intercept, arg_info_trader_linearreg_intercept)
	PHP_FE(trader_linearreg_slope, arg_info_trader_linearreg_slope)
	PHP_FE(trader_ln, arg_info_trader_ln)
	PHP_FE(trader_log10, arg_info_trader_log10)
	PHP_FE(trader_ma, arg_info_trader_ma)
	PHP_FE(trader_macd, arg_info_trader_macd)
	PHP_FE(trader_macdext, arg_info_trader_macdext)
	PHP_FE(trader_macdfix, arg_info_trader_macdfix)
	PHP_FE(trader_mama, arg_info_trader_mama)
	PHP_FE(trader_mavp, arg_info_trader_mavp)
	PHP_FE(trader_max, arg_info_trader_max)
	PHP_FE(trader_maxindex, arg_info_trader_maxindex)
	PHP_FE(trader_medprice, arg_info_trader_medprice)
	PHP_FE(trader_mfi, arg_info_trader_mfi)
	PHP_FE(trader_midpoint, arg_info_trader_midpoint)
	PHP_FE(trader_midprice, arg_info_trader_midprice)
	PHP_FE(trader_min, arg_info_trader_min)
	PHP_FE(trader_minindex, arg_info_trader_minindex)
	PHP_FE(trader_minmax, arg_info_trader_minmax)
	PHP_FE(trader_minmaxindex, arg_info_trader_minmaxindex)
	PHP_FE(trader_minus_di, arg_info_trader_minus_di)
	PHP_FE(trader_minus_dm, arg_info_trader_minus_dm)
	PHP_FE(trader_mom, arg_info_trader_mom)
	PHP_FE(trader_mult, arg_info_trader_mult)
	PHP_FE(trader_natr, arg_info_trader_natr)
	PHP_FE(trader_obv, arg_info_trader_obv)
	PHP_FE(trader_plus_di, arg_info_trader_plus_di)
	PHP_FE(trader_plus_dm, arg_info_trader_plus_dm)
	PHP_FE(trader_ppo, arg_info_trader_ppo)
	PHP_FE(trader_roc, arg_info_trader_roc)
	PHP_FE(trader_rocp, arg_info_trader_rocp)
	PHP_FE(trader_rocr, arg_info_trader_rocr)
	PHP_FE(trader_rocr100, arg_info_trader_rocr100)
	PHP_FE(trader_rsi, arg_info_trader_rsi)
	PHP_FE(trader_sar, arg_info_trader_sar)
	PHP_FE(trader_sarext, arg_info_trader_sarext)
	PHP_FE(trader_sin, arg_info_trader_sin)
	PHP_FE(trader_sinh, arg_info_trader_sinh)
	PHP_FE(trader_sma, arg_info_trader_sma)
	PHP_FE(trader_sqrt, arg_info_trader_sqrt)
	PHP_FE(trader_stddev, arg_info_trader_stddev)
	PHP_FE(trader_stoch, arg_info_trader_stoch)
	PHP_FE(trader_stochf, arg_info_trader_stochf)
	PHP_FE(trader_stochrsi, arg_info_trader_stochrsi)
	PHP_FE(trader_sub, arg_info_trader_sub)
	PHP_FE(trader_sum, arg_info_trader_sum)
	PHP_FE(trader_t3, arg_info_trader_t3)
	PHP_FE(trader_tan, arg_info_trader_tan)
	PHP_FE(trader_tanh, arg_info_trader_tanh)
	PHP_FE(trader_tema, arg_info_trader_tema)
	PHP_FE(trader_trange, arg_info_trader_trange)
	PHP_FE(trader_trima, arg_info_trader_trima)
	PHP_FE(trader_trix, arg_info_trader_trix)
	PHP_FE(trader_tsf, arg_info_trader_tsf)
	PHP_FE(trader_typprice, arg_info_trader_typprice)
	PHP_FE(trader_ultosc, arg_info_trader_ultosc)
	PHP_FE(trader_var, arg_info_trader_var)
	PHP_FE(trader_wclprice, arg_info_trader_wclprice)
	PHP_FE(trader_willr, arg_info_trader_willr)
	PHP_FE(trader_wma, arg_info_trader_wma)
	PHP_FE(trader_set_unstable_period, arg_info_trader_set_unstable_period)
	PHP_FE(trader_get_unstable_period, arg_info_trader_get_unstable_period)
	PHP_FE(trader_set_compat, arg_info_trader_set_compat)
	PHP_FE(trader_get_compat, arg_info_trader_get_compat)
	PHP_FE(trader_errno, arg_info_trader_errno)
	PHP_FE_END
};
/* }}} */

/* {{{ trader_module_entry
 */
zend_module_entry trader_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"trader",
	trader_functions,
	PHP_MINIT(trader),
	PHP_MSHUTDOWN(trader),
	NULL,
	NULL,
	PHP_MINFO(trader),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_TRADER_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TRADER
ZEND_GET_MODULE(trader)
#endif

/* {{{ PHP_INI
 */
static PHP_INI_MH(OnUpdateTraderRealRoundMode)
{
#if PHP_MAJOR_VERSION >= 7
	size_t new_len = new_value->len+1;
	char *new_val = new_value->val;
#else
	int new_len = new_value_length+1;
	char *new_val = new_value;
#endif

	if ((new_len >= sizeof("HALF_UP")) && (strncasecmp(new_val, "HALF_UP", sizeof("HALF_UP")) == 0)) {
		TRADER_G(real_round_mode) = PHP_ROUND_HALF_UP;
	} else if ((new_len >= sizeof("HALF_DOWN")) && (strncasecmp(new_val, "HALF_DOWN", sizeof("HALF_DOWN")) == 0)) {
		TRADER_G(real_round_mode) = PHP_ROUND_HALF_DOWN;
	} else if ((new_len >= sizeof("HALF_EVEN")) && (strncasecmp(new_val, "HALF_EVEN", sizeof("HALF_EVEN")) == 0)) {
		TRADER_G(real_round_mode) = PHP_ROUND_HALF_EVEN;
	} else if ((new_len >= sizeof("HALF_ODD")) && (strncasecmp(new_val, "HALF_ODD", sizeof("HALF_ODD")) == 0)) {
		TRADER_G(real_round_mode) = PHP_ROUND_HALF_ODD;
	} else {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid value '%s' for trader.real_round_mode", new_val);
		return FAILURE;
	}

	return SUCCESS;
}

PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("trader.real_precision", "3", PHP_INI_ALL, OnUpdateLong, real_precision, zend_trader_globals, trader_globals)
    PHP_INI_ENTRY("trader.real_round_mode", "HALF_DOWN", PHP_INI_ALL, OnUpdateTraderRealRoundMode)
PHP_INI_END()
/* }}} */ 

/* {{{ php_trader_globals_ctor
 */
static void php_trader_globals_ctor(zend_trader_globals *trader_globals)
{
	trader_globals->real_precision = TRADER_DEFAULT_REAL_PRECISION;
	trader_globals->last_error = TA_SUCCESS;
	trader_globals->real_round_mode = TRADER_DEFAULT_REAL_ROUND_MODE;
}
/* }}} */

/* {{{ php_trader_globals_dtor
 */
static void php_trader_globals_dtor(zend_trader_globals *trader_globals)
{
	/* pass */
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(trader)
{
	ZEND_INIT_MODULE_GLOBALS(trader, php_trader_globals_ctor, php_trader_globals_dtor);

	REGISTER_INI_ENTRIES();

	if (TA_SUCCESS != TA_Initialize()) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Trader initialization failed");
		return FAILURE;
	}

	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_SMA", TA_MAType_SMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_EMA", TA_MAType_EMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_WMA", TA_MAType_WMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_DEMA", TA_MAType_DEMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_TEMA", TA_MAType_TEMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_TRIMA", TA_MAType_TRIMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_KAMA", TA_MAType_KAMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_MAMA", TA_MAType_MAMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_MA_TYPE_T3", TA_MAType_T3, CONST_CS | CONST_PERSISTENT);

	REGISTER_DOUBLE_CONSTANT("TRADER_REAL_MIN", TA_REAL_MIN, CONST_CS | CONST_PERSISTENT);
	REGISTER_DOUBLE_CONSTANT("TRADER_REAL_MAX", TA_REAL_MAX, CONST_CS | CONST_PERSISTENT);

	REGISTER_DOUBLE_CONSTANT("TRADER_INTEGER_MIN", TA_INTEGER_MIN, CONST_CS | CONST_PERSISTENT);
	REGISTER_DOUBLE_CONSTANT("TRADER_INTEGER_MAX", TA_INTEGER_MAX, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_ADX", TA_FUNC_UNST_ADX, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_ADXR", TA_FUNC_UNST_ADXR, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_ATR", TA_FUNC_UNST_ATR, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_CMO", TA_FUNC_UNST_CMO, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_DX", TA_FUNC_UNST_DX, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_EMA", TA_FUNC_UNST_EMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_HT_DCPERIOD", TA_FUNC_UNST_HT_DCPERIOD, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_HT_DCPHASE", TA_FUNC_UNST_HT_DCPHASE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_HT_PHASOR", TA_FUNC_UNST_HT_PHASOR, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_HT_SINE", TA_FUNC_UNST_HT_SINE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_HT_TRENDLINE", TA_FUNC_UNST_HT_TRENDLINE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_HT_TRENDMODE", TA_FUNC_UNST_HT_TRENDMODE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_KAMA", TA_FUNC_UNST_KAMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_MAMA", TA_FUNC_UNST_MAMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_MFI", TA_FUNC_UNST_MFI, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_MINUS_DI", TA_FUNC_UNST_MINUS_DI, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_MINUS_DM", TA_FUNC_UNST_MINUS_DM, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_NATR", TA_FUNC_UNST_NATR, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_PLUS_DI", TA_FUNC_UNST_PLUS_DI, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_PLUS_DM", TA_FUNC_UNST_PLUS_DM, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_RSI", TA_FUNC_UNST_RSI, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_STOCHRSI", TA_FUNC_UNST_STOCHRSI, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_T3", TA_FUNC_UNST_T3, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_ALL", TA_FUNC_UNST_ALL, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_FUNC_UNST_NONE", TA_FUNC_UNST_NONE, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TRADER_COMPATIBILITY_DEFAULT", TA_COMPATIBILITY_DEFAULT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_COMPATIBILITY_METASTOCK", TA_COMPATIBILITY_METASTOCK, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("TRADER_ERR_SUCCESS", TA_SUCCESS, CONST_CS | CONST_PERSISTENT); /* No error */
	REGISTER_LONG_CONSTANT("TRADER_ERR_LIB_NOT_INITIALIZE", TA_LIB_NOT_INITIALIZE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_BAD_PARAM", TA_BAD_PARAM, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_ALLOC_ERR", TA_ALLOC_ERR, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_GROUP_NOT_FOUND", TA_GROUP_NOT_FOUND, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_FUNC_NOT_FOUND", TA_FUNC_NOT_FOUND, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_INVALID_HANDLE", TA_INVALID_HANDLE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_INVALID_PARAM_HOLDER", TA_INVALID_PARAM_HOLDER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_INVALID_PARAM_HOLDER_TYPE", TA_INVALID_PARAM_HOLDER_TYPE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_INVALID_PARAM_FUNCTION", TA_INVALID_PARAM_FUNCTION, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_INPUT_NOT_ALL_INITIALIZE", TA_INPUT_NOT_ALL_INITIALIZE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_OUTPUT_NOT_ALL_INITIALIZE", TA_OUTPUT_NOT_ALL_INITIALIZE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_OUT_OF_RANGE_START_INDEX", TA_OUT_OF_RANGE_START_INDEX, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_OUT_OF_RANGE_END_INDEX", TA_OUT_OF_RANGE_END_INDEX, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_INVALID_LIST_TYPE", TA_INVALID_LIST_TYPE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_BAD_OBJECT", TA_BAD_OBJECT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_NOT_SUPPORTED", TA_NOT_SUPPORTED, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_INTERNAL_ERROR", TA_INTERNAL_ERROR, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TRADER_ERR_UNKNOWN_ERROR", TA_UNKNOWN_ERR, CONST_CS | CONST_PERSISTENT);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(trader)
{
	UNREGISTER_INI_ENTRIES();
#ifdef ZTS
	    ts_free_id(trader_globals_id);
#else
		php_trader_globals_dtor(&trader_globals TSRMLS_CC);
#endif

	if (TA_SUCCESS != TA_Shutdown()) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Trader shutdown failed");
		return FAILURE;
	}

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(trader)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Trader Technical Analysis Library Support", "enabled");
	php_info_print_table_header(2, "Version", PHP_TRADER_VERSION);
	php_info_print_table_header(2, "TA-Lib version", TA_GetVersionString());
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
