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

#ifndef TA_PHP_FUNC_H
#define TA_PHP_FUNC_H

PHP_FUNCTION(ta_acos);
PHP_FUNCTION(ta_ad);
PHP_FUNCTION(ta_add);
PHP_FUNCTION(ta_adosc);
PHP_FUNCTION(ta_adx);
PHP_FUNCTION(ta_adxr);
PHP_FUNCTION(ta_apo);
PHP_FUNCTION(ta_aroon);
PHP_FUNCTION(ta_aroonosc);
PHP_FUNCTION(ta_asin);
PHP_FUNCTION(ta_atan);
PHP_FUNCTION(ta_atr);
PHP_FUNCTION(ta_avgprice);
PHP_FUNCTION(ta_bbands);
PHP_FUNCTION(ta_beta);
PHP_FUNCTION(ta_bop);
PHP_FUNCTION(ta_cci);
PHP_FUNCTION(ta_cdl2crows);
PHP_FUNCTION(ta_cdl3blackcrows);
PHP_FUNCTION(ta_cdl3inside);
PHP_FUNCTION(ta_cdl3linestrike);
PHP_FUNCTION(ta_cdl3outside);
PHP_FUNCTION(ta_cdl3starsinsouth);
PHP_FUNCTION(ta_cdl3whitesoldiers);
PHP_FUNCTION(ta_cdlabandonedbaby);
PHP_FUNCTION(ta_cdladvanceblock);
PHP_FUNCTION(ta_cdlbelthold);
PHP_FUNCTION(ta_cdlbreakaway);
PHP_FUNCTION(ta_cdlclosingmarubozu);
PHP_FUNCTION(ta_cdlconcealbabyswall);
PHP_FUNCTION(ta_cdlcounterattack);
PHP_FUNCTION(ta_cdldarkcloudcover);
PHP_FUNCTION(ta_cdldoji);
PHP_FUNCTION(ta_cdldojistar);
PHP_FUNCTION(ta_cdldragonflydoji);
PHP_FUNCTION(ta_cdlengulfing);
PHP_FUNCTION(ta_cdleveningdojistar);
PHP_FUNCTION(ta_cdleveningstar);
PHP_FUNCTION(ta_cdlgapsidesidewhite);
PHP_FUNCTION(ta_cdlgravestonedoji);
PHP_FUNCTION(ta_cdlhammer);
PHP_FUNCTION(ta_cdlhangingman);
PHP_FUNCTION(ta_cdlharami);
PHP_FUNCTION(ta_cdlharamicross);
PHP_FUNCTION(ta_cdlhighwave);
PHP_FUNCTION(ta_cdlhikkake);
PHP_FUNCTION(ta_cdlhikkakemod);
PHP_FUNCTION(ta_cdlhomingpigeon);
PHP_FUNCTION(ta_cdlidentical3crows);
PHP_FUNCTION(ta_cdlinneck);
PHP_FUNCTION(ta_cdlinvertedhammer);
PHP_FUNCTION(ta_cdlkicking);
PHP_FUNCTION(ta_cdlkickingbylength);
PHP_FUNCTION(ta_cdlladderbottom);
PHP_FUNCTION(ta_cdllongleggeddoji);
PHP_FUNCTION(ta_cdllongline);
PHP_FUNCTION(ta_cdlmarubozu);
PHP_FUNCTION(ta_cdlmatchinglow);
PHP_FUNCTION(ta_cdlmathold);
PHP_FUNCTION(ta_cdlmorningdojistar);
PHP_FUNCTION(ta_cdlmorningstar);
PHP_FUNCTION(ta_cdlonneck);
PHP_FUNCTION(ta_cdlpiercing);
PHP_FUNCTION(ta_cdlrickshawman);
PHP_FUNCTION(ta_cdlrisefall3methods);
PHP_FUNCTION(ta_cdlseparatinglines);
PHP_FUNCTION(ta_cdlshootingstar);
PHP_FUNCTION(ta_cdlshortline);
PHP_FUNCTION(ta_cdlspinningtop);
PHP_FUNCTION(ta_cdlstalledpattern);
PHP_FUNCTION(ta_cdlsticksandwich);
PHP_FUNCTION(ta_cdltakuri);
PHP_FUNCTION(ta_cdltasukigap);
PHP_FUNCTION(ta_cdlthrusting);
PHP_FUNCTION(ta_cdltristar);
PHP_FUNCTION(ta_cdlunique3river);
PHP_FUNCTION(ta_cdlupsidegap2crows);
PHP_FUNCTION(ta_cdlxsidegap3methods);
PHP_FUNCTION(ta_ceil);
PHP_FUNCTION(ta_cmo);
PHP_FUNCTION(ta_correl);
PHP_FUNCTION(ta_cos);
PHP_FUNCTION(ta_cosh);
PHP_FUNCTION(ta_dema);
PHP_FUNCTION(ta_div);
PHP_FUNCTION(ta_dx);
PHP_FUNCTION(ta_ema);
PHP_FUNCTION(ta_exp);
PHP_FUNCTION(ta_floor);
PHP_FUNCTION(ta_ht_dcperiod);
PHP_FUNCTION(ta_ht_dcphase);
PHP_FUNCTION(ta_ht_phasor);
PHP_FUNCTION(ta_ht_sine);
PHP_FUNCTION(ta_ht_trendline);
PHP_FUNCTION(ta_ht_trendmode);
PHP_FUNCTION(ta_kama);
PHP_FUNCTION(ta_linearreg);
PHP_FUNCTION(ta_linearreg_angle);
PHP_FUNCTION(ta_linearreg_intercept);
PHP_FUNCTION(ta_linearreg_slope);
PHP_FUNCTION(ta_ln);
PHP_FUNCTION(ta_log10);
PHP_FUNCTION(ta_ma);
PHP_FUNCTION(ta_macd);
PHP_FUNCTION(ta_macdext);
PHP_FUNCTION(ta_macdfix);
PHP_FUNCTION(ta_mama);
PHP_FUNCTION(ta_mavp);
PHP_FUNCTION(ta_max);
PHP_FUNCTION(ta_maxindex);
PHP_FUNCTION(ta_medprice);
PHP_FUNCTION(ta_mfi);
PHP_FUNCTION(ta_midpoint);
PHP_FUNCTION(ta_midprice);
PHP_FUNCTION(ta_min);
PHP_FUNCTION(ta_minindex);
PHP_FUNCTION(ta_minmax);
PHP_FUNCTION(ta_minmaxindex);
PHP_FUNCTION(ta_minus_di);
PHP_FUNCTION(ta_minus_dm);
PHP_FUNCTION(ta_mom);
PHP_FUNCTION(ta_mult);
PHP_FUNCTION(ta_natr);
PHP_FUNCTION(ta_obv);
PHP_FUNCTION(ta_plus_di);
PHP_FUNCTION(ta_plus_dm);
PHP_FUNCTION(ta_ppo);
PHP_FUNCTION(ta_roc);
PHP_FUNCTION(ta_rocp);
PHP_FUNCTION(ta_rocr);
PHP_FUNCTION(ta_rocr100);
PHP_FUNCTION(ta_rsi);
PHP_FUNCTION(ta_sar);
PHP_FUNCTION(ta_sarext);
PHP_FUNCTION(ta_sin);
PHP_FUNCTION(ta_sinh);
PHP_FUNCTION(ta_sma);
PHP_FUNCTION(ta_sqrt);
PHP_FUNCTION(ta_stddev);
PHP_FUNCTION(ta_stoch);
PHP_FUNCTION(ta_stochf);
PHP_FUNCTION(ta_stochrsi);
PHP_FUNCTION(ta_sub);
PHP_FUNCTION(ta_sum);
PHP_FUNCTION(ta_t3);
PHP_FUNCTION(ta_tan);
PHP_FUNCTION(ta_tanh);
PHP_FUNCTION(ta_tema);
PHP_FUNCTION(ta_trange);
PHP_FUNCTION(ta_trima);
PHP_FUNCTION(ta_trix);
PHP_FUNCTION(ta_tsf);
PHP_FUNCTION(ta_typprice);
PHP_FUNCTION(ta_ultosc);
PHP_FUNCTION(ta_var);
PHP_FUNCTION(ta_wclprice);
PHP_FUNCTION(ta_willr);
PHP_FUNCTION(ta_wma);

#endif /* TA_PHP_FUNC_H */
