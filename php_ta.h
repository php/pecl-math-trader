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

#ifndef PHP_TA_H
#define PHP_TA_H

extern zend_module_entry ta_module_entry;
#define phpext_ta_ptr &ta_module_entry

#ifdef PHP_WIN32
#	define PHP_TA_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_TA_API __attribute__ ((visibility("default")))
#else
#	define PHP_TA_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/* XXX put that into ini */
#define TA_ROUND_PRECISION 3

PHP_MINIT_FUNCTION(ta);
PHP_MSHUTDOWN_FUNCTION(ta);
PHP_RINIT_FUNCTION(ta);
PHP_RSHUTDOWN_FUNCTION(ta);
PHP_MINFO_FUNCTION(ta);

PHP_FUNCTION(ta_ad);
PHP_FUNCTION(ta_adosc);
PHP_FUNCTION(ta_adx);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(ta)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(ta)
*/

#ifdef ZTS
#define TA_G(v) TSRMG(ta_globals_id, zend_ta_globals *, v)
#else
#define TA_G(v) (ta_globals.v)
#endif

#define TA_ROUND_DOUBLE(x) (((int)((x) * pow(10, TA_ROUND_PRECISION))) / pow(10.0, TA_ROUND_PRECISION))
#define TA_RETURN_DOUBLE(x) RETURN_DOUBLE(TA_ROUND_DOUBLE(x))

#endif	/* PHP_TA_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
