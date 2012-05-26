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

#ifndef TA_PHP_FE_H
#define TA_PHP_FE_H
const zend_function_entry ta_functions[] = {
	PHP_FE(ta_acos, arg_info_ta_acos)
	PHP_FE(ta_ad, arg_info_ta_ad)
	PHP_FE(ta_add, arg_info_ta_add)
	PHP_FE(ta_adosc, arg_info_ta_adosc)
	PHP_FE(ta_adx, arg_info_ta_adx)
	PHP_FE(ta_adxr, arg_info_ta_adxr)
	PHP_FE(ta_apo, arg_info_ta_apo)
	PHP_FE(ta_aroon, arg_info_ta_aroon)
	PHP_FE(ta_aroonosc, arg_info_ta_aroonosc)
	PHP_FE(ta_asin, arg_info_ta_asin)
	PHP_FE(ta_atan, arg_info_ta_atan)
	PHP_FE(ta_atr, arg_info_ta_atr)
	PHP_FE(ta_avgprice, arg_info_ta_avgprice)
	PHP_FE(ta_bbands, arg_info_ta_bbands)
	PHP_FE(ta_beta, arg_info_ta_beta)
	PHP_FE(ta_bop, arg_info_ta_bop)
	PHP_FE(ta_cci, arg_info_ta_cci)
	PHP_FE(ta_cdl2crows, arg_info_ta_cdl2crows)
	PHP_FE(ta_cdl3blackcrows, arg_info_ta_cdl3blackcrows)
	PHP_FE(ta_cdl3inside, arg_info_ta_cdl3inside)
	PHP_FE(ta_cdl3linestrike, arg_info_ta_cdl3linestrike)
	PHP_FE(ta_cdl3outside, arg_info_ta_cdl3outside)
	PHP_FE(ta_cdl3starsinsouth, arg_info_ta_cdl3starsinsouth)
	PHP_FE(ta_cdl3whitesoldiers, arg_info_ta_cdl3whitesoldiers)
	PHP_FE(ta_cdlabandonedbaby, arg_info_ta_cdlabandonedbaby)
	PHP_FE(ta_cdladvanceblock, arg_info_ta_cdladvanceblock)
	PHP_FE(ta_cdlbelthold, arg_info_ta_cdlbelthold)
	PHP_FE(ta_cdlbreakaway, arg_info_ta_cdlbreakaway)
	PHP_FE(ta_cdlclosingmarubozu, arg_info_ta_cdlclosingmarubozu)
	PHP_FE(ta_cdlconcealbabyswall, arg_info_ta_cdlconcealbabyswall)
	PHP_FE(ta_cdlcounterattack, arg_info_ta_cdlcounterattack)
	PHP_FE(ta_cdldarkcloudcover, arg_info_ta_cdldarkcloudcover)
	PHP_FE(ta_cdldoji, arg_info_ta_cdldoji)
	PHP_FE(ta_cdldojistar, arg_info_ta_cdldojistar)
	PHP_FE(ta_cdldragonflydoji, arg_info_ta_cdldragonflydoji)
	PHP_FE(ta_cdlengulfing, arg_info_ta_cdlengulfing)
	PHP_FE(ta_cdleveningdojistar, arg_info_ta_cdleveningdojistar)
	PHP_FE(ta_cdleveningstar, arg_info_ta_cdleveningstar)
	PHP_FE(ta_cdlgapsidesidewhite, arg_info_ta_cdlgapsidesidewhite)
	PHP_FE(ta_cdlgravestonedoji, arg_info_ta_cdlgravestonedoji)
	PHP_FE(ta_cdlhammer, arg_info_ta_cdlhammer)
	PHP_FE(ta_cdlhangingman, arg_info_ta_cdlhangingman)
	PHP_FE(ta_cdlharami, arg_info_ta_cdlharami)
	PHP_FE(ta_cdlharamicross, arg_info_ta_cdlharamicross)
	PHP_FE(ta_cdlhighwave, arg_info_ta_cdlhighwave)
	PHP_FE(ta_cdlhikkake, arg_info_ta_cdlhikkake)
	PHP_FE(ta_cdlhikkakemod, arg_info_ta_cdlhikkakemod)
	PHP_FE(ta_cdlhomingpigeon, arg_info_ta_cdlhomingpigeon)
	PHP_FE(ta_cdlidentical3crows, arg_info_ta_cdlidentical3crows)
	PHP_FE(ta_cdlinneck, arg_info_ta_cdlinneck)
	PHP_FE(ta_cdlinvertedhammer, arg_info_ta_cdlinvertedhammer)
	PHP_FE(ta_cdlkicking, arg_info_ta_cdlkicking)
	PHP_FE(ta_cdlkickingbylength, arg_info_ta_cdlkickingbylength)
	PHP_FE(ta_cdlladderbottom, arg_info_ta_cdlladderbottom)
	PHP_FE(ta_cdllongleggeddoji, arg_info_ta_cdllongleggeddoji)
	PHP_FE(ta_cdllongline, arg_info_ta_cdllongline)
	PHP_FE(ta_cdlmarubozu, arg_info_ta_cdlmarubozu)
	PHP_FE(ta_cdlmatchinglow, arg_info_ta_cdlmatchinglow)
	PHP_FE(ta_cdlmathold, arg_info_ta_cdlmathold)
	PHP_FE(ta_cdlmorningdojistar, arg_info_ta_cdlmorningdojistar)
	PHP_FE(ta_cdlmorningstar, arg_info_ta_cdlmorningstar)
	PHP_FE(ta_cdlonneck, arg_info_ta_cdlonneck)
	PHP_FE(ta_cdlpiercing, arg_info_ta_cdlpiercing)
	PHP_FE(ta_cdlrickshawman, arg_info_ta_cdlrickshawman)
	PHP_FE(ta_cdlrisefall3methods, arg_info_ta_cdlrisefall3methods)
	PHP_FE(ta_cdlseparatinglines, arg_info_ta_cdlseparatinglines)
	PHP_FE(ta_cdlshootingstar, arg_info_ta_cdlshootingstar)
	PHP_FE(ta_cdlshortline, arg_info_ta_cdlshortline)
	PHP_FE(ta_cdlspinningtop, arg_info_ta_cdlspinningtop)
	PHP_FE(ta_cdlstalledpattern, arg_info_ta_cdlstalledpattern)
	PHP_FE(ta_cdlsticksandwich, arg_info_ta_cdlsticksandwich)
	PHP_FE(ta_cdltakuri, arg_info_ta_cdltakuri)
	PHP_FE(ta_cdltasukigap, arg_info_ta_cdltasukigap)
	PHP_FE(ta_cdlthrusting, arg_info_ta_cdlthrusting)
	PHP_FE(ta_cdltristar, arg_info_ta_cdltristar)
	PHP_FE(ta_cdlunique3river, arg_info_ta_cdlunique3river)
	PHP_FE(ta_cdlupsidegap2crows, arg_info_ta_cdlupsidegap2crows)
	PHP_FE(ta_cdlxsidegap3methods, arg_info_ta_cdlxsidegap3methods)
	PHP_FE(ta_ceil, arg_info_ta_ceil)
	PHP_FE(ta_cmo, arg_info_ta_cmo)
	PHP_FE(ta_correl, arg_info_ta_correl)
	PHP_FE(ta_cos, arg_info_ta_cos)
	PHP_FE(ta_cosh, arg_info_ta_cosh)
	PHP_FE(ta_dema, arg_info_ta_dema)
	PHP_FE(ta_div, arg_info_ta_div)
	PHP_FE(ta_dx, arg_info_ta_dx)
	PHP_FE(ta_ema, arg_info_ta_ema)
	PHP_FE(ta_exp, arg_info_ta_exp)
	PHP_FE(ta_floor, arg_info_ta_floor)
	PHP_FE(ta_ht_dcperiod, arg_info_ta_ht_dcperiod)
	PHP_FE(ta_ht_dcphase, arg_info_ta_ht_dcphase)
	PHP_FE(ta_ht_phasor, arg_info_ta_ht_phasor)
	PHP_FE(ta_ht_sine, arg_info_ta_ht_sine)
	PHP_FE(ta_ht_trendline, arg_info_ta_ht_trendline)
	PHP_FE(ta_ht_trendmode, arg_info_ta_ht_trendmode)
	PHP_FE(ta_kama, arg_info_ta_kama)
	PHP_FE(ta_linearreg, arg_info_ta_linearreg)
	PHP_FE(ta_linearreg_angle, arg_info_ta_linearreg_angle)
	PHP_FE(ta_linearreg_intercept, arg_info_ta_linearreg_intercept)
	PHP_FE(ta_linearreg_slope, arg_info_ta_linearreg_slope)
	PHP_FE(ta_ln, arg_info_ta_ln)
	PHP_FE(ta_log10, arg_info_ta_log10)
	PHP_FE(ta_ma, arg_info_ta_ma)
	PHP_FE(ta_macd, arg_info_ta_macd)
	PHP_FE(ta_macdext, arg_info_ta_macdext)
	PHP_FE(ta_macdfix, arg_info_ta_macdfix)
	PHP_FE(ta_mama, arg_info_ta_mama)
	PHP_FE(ta_mavp, arg_info_ta_mavp)
	PHP_FE(ta_max, arg_info_ta_max)
	PHP_FE(ta_maxindex, arg_info_ta_maxindex)
	PHP_FE(ta_medprice, arg_info_ta_medprice)
	PHP_FE(ta_mfi, arg_info_ta_mfi)
	PHP_FE(ta_midpoint, arg_info_ta_midpoint)
	PHP_FE(ta_midprice, arg_info_ta_midprice)
	PHP_FE(ta_min, arg_info_ta_min)
	PHP_FE(ta_minindex, arg_info_ta_minindex)
	PHP_FE(ta_minmax, arg_info_ta_minmax)
	PHP_FE(ta_minmaxindex, arg_info_ta_minmaxindex)
	PHP_FE(ta_minus_di, arg_info_ta_minus_di)
	PHP_FE(ta_minus_dm, arg_info_ta_minus_dm)
	PHP_FE(ta_mom, arg_info_ta_mom)
	PHP_FE(ta_mult, arg_info_ta_mult)
	PHP_FE(ta_natr, arg_info_ta_natr)
	PHP_FE(ta_obv, arg_info_ta_obv)
	PHP_FE(ta_plus_di, arg_info_ta_plus_di)
	PHP_FE(ta_plus_dm, arg_info_ta_plus_dm)
	PHP_FE(ta_ppo, arg_info_ta_ppo)
	PHP_FE(ta_roc, arg_info_ta_roc)
	PHP_FE(ta_rocp, arg_info_ta_rocp)
	PHP_FE(ta_rocr, arg_info_ta_rocr)
	PHP_FE(ta_rocr100, arg_info_ta_rocr100)
	PHP_FE(ta_rsi, arg_info_ta_rsi)
	PHP_FE(ta_sar, arg_info_ta_sar)
	PHP_FE(ta_sarext, arg_info_ta_sarext)
	PHP_FE(ta_sin, arg_info_ta_sin)
	PHP_FE(ta_sinh, arg_info_ta_sinh)
	PHP_FE(ta_sma, arg_info_ta_sma)
	PHP_FE(ta_sqrt, arg_info_ta_sqrt)
	PHP_FE(ta_stddev, arg_info_ta_stddev)
	PHP_FE(ta_stoch, arg_info_ta_stoch)
	PHP_FE(ta_stochf, arg_info_ta_stochf)
	PHP_FE(ta_stochrsi, arg_info_ta_stochrsi)
	PHP_FE(ta_sub, arg_info_ta_sub)
	PHP_FE(ta_sum, arg_info_ta_sum)
	PHP_FE(ta_t3, arg_info_ta_t3)
	PHP_FE(ta_tan, arg_info_ta_tan)
	PHP_FE(ta_tanh, arg_info_ta_tanh)
	PHP_FE(ta_tema, arg_info_ta_tema)
	PHP_FE(ta_trange, arg_info_ta_trange)
	PHP_FE(ta_trima, arg_info_ta_trima)
	PHP_FE(ta_trix, arg_info_ta_trix)
	PHP_FE(ta_tsf, arg_info_ta_tsf)
	PHP_FE(ta_typprice, arg_info_ta_typprice)
	PHP_FE(ta_ultosc, arg_info_ta_ultosc)
	PHP_FE(ta_var, arg_info_ta_var)
	PHP_FE(ta_wclprice, arg_info_ta_wclprice)
	PHP_FE(ta_willr, arg_info_ta_willr)
	PHP_FE(ta_wma, arg_info_ta_wma)
	PHP_FE_END
};

#endif /* TA_PHP_FE_H */
