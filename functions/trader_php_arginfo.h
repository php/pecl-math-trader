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

#ifndef TA_PHP_ARGINFO_H
#define TA_PHP_ARGINFO_H

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_acos, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ad, 0, 0, 4)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, inVolume)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_add, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adosc, 0, 0, 4)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, inVolume)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInSlowPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adx, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adxr, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_apo, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInSlowPeriod)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_aroon, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_aroonosc, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_asin, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_atan, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_atr, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_avgprice, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_bbands, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInNbDevUp)
	ZEND_ARG_INFO(0, optInNbDevDn)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_beta, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_bop, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cci, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl2crows, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3blackcrows, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3inside, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3linestrike, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3outside, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3starsinsouth, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3whitesoldiers, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlabandonedbaby, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdladvanceblock, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlbelthold, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlbreakaway, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlclosingmarubozu, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlconcealbabyswall, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlcounterattack, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdldarkcloudcover, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdldoji, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdldojistar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdldragonflydoji, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlengulfing, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdleveningdojistar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdleveningstar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlgapsidesidewhite, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlgravestonedoji, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhammer, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhangingman, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlharami, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlharamicross, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhighwave, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhikkake, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhikkakemod, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhomingpigeon, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlidentical3crows, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlinneck, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlinvertedhammer, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlkicking, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlkickingbylength, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlladderbottom, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdllongleggeddoji, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdllongline, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmarubozu, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmatchinglow, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmathold, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmorningdojistar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmorningstar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlonneck, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlpiercing, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlrickshawman, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlrisefall3methods, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlseparatinglines, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlshootingstar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlshortline, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlspinningtop, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlstalledpattern, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlsticksandwich, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdltakuri, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdltasukigap, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlthrusting, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdltristar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlunique3river, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlupsidegap2crows, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlxsidegap3methods, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ceil, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cmo, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_correl, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cos, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cosh, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_dema, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_div, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_dx, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ema, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_exp, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_floor, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_dcperiod, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_dcphase, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_phasor, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_sine, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_trendline, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_trendmode, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_kama, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_linearreg, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_linearreg_angle, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_linearreg_intercept, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_linearreg_slope, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ln, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_log10, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ma, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_macd, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInSlowPeriod)
	ZEND_ARG_INFO(0, optInSignalPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_macdext, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInFastMAType)
	ZEND_ARG_INFO(0, optInSlowPeriod)
	ZEND_ARG_INFO(0, optInSlowMAType)
	ZEND_ARG_INFO(0, optInSignalPeriod)
	ZEND_ARG_INFO(0, optInSignalMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_macdfix, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInSignalPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mama, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastLimit)
	ZEND_ARG_INFO(0, optInSlowLimit)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mavp, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, inPeriods)
	ZEND_ARG_INFO(0, optInMinPeriod)
	ZEND_ARG_INFO(0, optInMaxPeriod)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_max, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_maxindex, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_medprice, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mfi, 0, 0, 4)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, inVolume)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_midpoint, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_midprice, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_min, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minindex, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minmax, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minmaxindex, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minus_di, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minus_dm, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mom, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mult, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_natr, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_obv, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, inVolume)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_plus_di, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_plus_dm, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ppo, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInSlowPeriod)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_roc, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_rocp, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_rocr, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_rocr100, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_rsi, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sar, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInAcceleration)
	ZEND_ARG_INFO(0, optInMaximum)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sarext, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInStartValue)
	ZEND_ARG_INFO(0, optInOffsetOnReverse)
	ZEND_ARG_INFO(0, optInAccelerationInitLong)
	ZEND_ARG_INFO(0, optInAccelerationLong)
	ZEND_ARG_INFO(0, optInAccelerationMaxLong)
	ZEND_ARG_INFO(0, optInAccelerationInitShort)
	ZEND_ARG_INFO(0, optInAccelerationShort)
	ZEND_ARG_INFO(0, optInAccelerationMaxShort)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sin, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sinh, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sma, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sqrt, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_stddev, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInNbDev)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_stoch, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInFastK_Period)
	ZEND_ARG_INFO(0, optInSlowK_Period)
	ZEND_ARG_INFO(0, optInSlowK_MAType)
	ZEND_ARG_INFO(0, optInSlowD_Period)
	ZEND_ARG_INFO(0, optInSlowD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_stochf, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInFastK_Period)
	ZEND_ARG_INFO(0, optInFastD_Period)
	ZEND_ARG_INFO(0, optInFastD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_stochrsi, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInFastK_Period)
	ZEND_ARG_INFO(0, optInFastD_Period)
	ZEND_ARG_INFO(0, optInFastD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sub, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sum, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_t3, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInVFactor)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_tan, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_tanh, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_tema, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_trange, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_trima, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_trix, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_tsf, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_typprice, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ultosc, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod1)
	ZEND_ARG_INFO(0, optInTimePeriod2)
	ZEND_ARG_INFO(0, optInTimePeriod3)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_var, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInNbDev)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_wclprice, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_willr, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_wma, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

#endif /* TA_PHP_ARGINFO_H */

