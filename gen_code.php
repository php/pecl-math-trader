<?php

$path = 'ta-lib/include/ta_func.h';

$c = file_get_contents($path);

/* got function defs with headers */
preg_match_all(',^/\*\s*\* TA\_.*\*/.*TA_RetCode.*\(.*\)\;$,smU', $c, $m, PREG_PATTERN_ORDER);
//preg_match_all(',^/\*\s*.*?\*/\s*TRADER_.*?\(.*?\)\;,sm', $c, $m);
//preg_match_all(',^/\*\s\n(.*?)\n\s\*/$,sm', $c, $m);
//preg_match_all(',/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+/,s', $c, $m);

//array_shift($m[0]);

/* parse all the function stuff out */
$func = array();
foreach ($m[0] as $f) {
	if (!preg_match(',^/\*\s*\n.*(TA_.*) - (.*)$,mU', $f, $mm)) {
		echo "desc error with '$f'\n";
		continue;
	}

	$fname = $mm[1];
	$func[$fname] = array();
	$func[$fname]['desc'] = $mm[2];

	if (!preg_match(",TA_RetCode $fname\((.*)\),smU", $f, $mm)) {
		echo "params error with '$f'\n";
		continue;
	}

	$func[$fname]['params'] = array();

	/* parse and normalize the param list first */
	$para = array();
	$para = explode("\n", $mm[1]);
	foreach ($para as $p) {
		$p = trim($p);
		$p = preg_replace(',\s+,', ' ', $p);

		$param = array(
			'name' => NULL,
			'type' => NULL,
			'byref' => false,
			'array' => false,
			'opt' => false,
			'bounds' => array(
				'min' => NULL,
				'max' => NULL,
			),
		);

		if (preg_match("%(.*) ([^,]+),? /\* From (.*) to (.*) \*/%", $p, $mmm)) {
			/* have bounds, lets save it*/
			$param['bounds']['min'] = $mmm[3];
			$param['bounds']['max'] = $mmm[4];
		} else if (!preg_match("%(.*) ([^,]+),?%", $p, $mmm)) {
			echo "param error with '$f' and '$p'\n";
			continue;
		}
		//print_r($mmm);

		if ('*' == $mmm[2][0]) {
			$param['byref'] = true;
			$param['name'] = substr($mmm[2], 1);
		} else if (']' == $mmm[2][strlen($mmm[2])-1]) {
			$param['byref'] = true;
			$param['array'] = true;
			$param['name'] = substr($mmm[2], 0, strlen($mmm[2])-2);
		} else {
			$param['name'] = $mmm[2];
			$param['byref'] = 'out' == substr($param['name'], 0, 3);
		}
		$param['type'] = $mmm[1];
		$param['opt'] = 'opt' == substr($param['name'], 0, 3);

		$func[$fname]['params'][] = $param;
	}
}

/*print_r($func);*/
/*print count($func) . "\n";*/

/* got the function data, let's go generate code  */
foreach ($func as $name => $defs) {
	$tpl = file_get_contents('functions/function.tpl');

	$php_func = str_replace('ta_', 'trader_', strtolower($name)); 
	$tpl = str_replace('MY_FUNC_NAME_LOWER', $php_func, $tpl);
	$tpl = str_replace('MY_FUNC_NAME', $name, $tpl);
	$tpl = str_replace('MY_FUNC_DESC', $defs['desc'], $tpl);

	$php_arr_defs = array();
	foreach ($defs['params'] as $p) {
		if ($p['array']) {
			if (substr($p["name"], 0, 3) !== "out") {
				$php_arr_defs[] = "*z$p[name]";
			}
		}
	}
//	array_pop($php_arr_defs); // the last is always the out array which is return_value
	$tpl = str_replace('MY_IN_PHP_ARRAY_DEFS', 'zval ' . implode(', ', $php_arr_defs) . ';', $tpl);


	$func_arr_deallocs = array();
	foreach ($defs['params'] as $p) {
		if ($p['array']) {
			$func_arr_deallocs[] = "efree({$p['name']});";
		}
	}
	$tpl = str_replace('MY_FUNC_ARRAY_PARA_DEALLOCS1', implode("\n\t\t", $func_arr_deallocs), $tpl);
	$tpl = str_replace('MY_FUNC_ARRAY_PARA_DEALLOCS2', implode("\n\t\t\t", $func_arr_deallocs), $tpl);


	$func_arr_defs = array();
	foreach ($defs['params'] as $p) {
		if (('double' == $p['type'] || 'const double' == $p['type']) && $p['array']) {
			$func_arr_defs[] = "*$p[name]";
		}
	}
	$tpl = str_replace('MY_FUNC_ARRAY_PARA_DEFS', 'double ' . implode(', ', $func_arr_defs) . ';', $tpl);


	$func_int_defs = array();
	foreach ($defs['params'] as $p) {
		if (('int' == $p['type'] || 'TA_MAType' == $p['type']) && !$p['opt']) {
			$ar = $p['array'] ? '*' : '';
			$func_int_defs[] = "$ar$p[name]" . (NULL != $p['bounds']['min'] ? " = {$p['bounds']['min']}" : ' = 0');
		}
	}
	$tpl = str_replace('MY_FUNC_INT_PARA_DEFS', 'int ' . implode(', ', $func_int_defs) . ';', $tpl);
	/*$tpl = str_replace('MY_FUNC_SET_START_IDX', 'startIdx = 0;', $tpl);*/ // not nice
	$tpl = str_replace('MY_FUNC_SET_START_IDX', '', $tpl);
	/* XXX doubles need to walk in the same way */


	$php_long_defs = array();
	foreach ($defs['params'] as $p) {
		if (('int' == $p['type']  || 'TA_MAType' == $p['type']) && $p['opt']) {
			$php_long_defs[] = "$p[name]" . (NULL != $p['bounds']['min'] ? " = {$p['bounds']['min']}" : ' = 0');
		}
	}
	$php_long_defs_repl = count($php_long_defs) ? 'zend_long ' . implode(', ', $php_long_defs) . ';' : '';
	$tpl = str_replace('MY_IN_PHP_LONG_DEFS', $php_long_defs_repl, $tpl);

	$php_dbl_defs = array();
	foreach ($defs['params'] as $p) {
		if ('double' == $p['type'] && $p['opt']) {
			$php_dbl_defs[] = "$p[name]" . (NULL != $p['bounds']['min'] ? " = {$p['bounds']['min']}" : '');
		}
	}
	$php_dbl_defs_repl = count($php_dbl_defs) ? 'double ' . implode(', ', $php_dbl_defs) . ';' : '';
	$tpl = str_replace('MY_IN_PHP_DOUBLE_DEFS', $php_dbl_defs_repl, $tpl);


	$func_set_boundable = array();
	foreach ($defs['params'] as $p) {
		if (NULL != $p['bounds']['min'] && NULL != $p['bounds']['max']) {
			if ('double' == $p['type']) {
				$func_set_boundable[] = "TRADER_DBL_SET_BOUNDABLE({$p['bounds']['min']}, {$p['bounds']['max']}, {$p['name']});";
			} else {
				$func_set_boundable[] = "TRADER_LONG_SET_BOUNDABLE({$p['bounds']['min']}, {$p['bounds']['max']}, {$p['name']});";
			}
		}
	}
	$tpl = str_replace('MY_FUNC_SET_BOUNDABLE', implode("\n\t", $func_set_boundable), $tpl);


	$zend_param_str = '';
	$zend_param_list = array();
	$zend_fast_params = array("min_cnt" => 0, "opt_cnt" => 0, "it" => array());
	$func_param_list = array();
	$ar_count = 0;
	$ar_breaks = false;
	$pipe_set = false;
	$last_was_ar = true;
	foreach ($defs['params'] as $p) {
		if (in_array($p['name'], array('startIdx', 'endIdx'))) {
			$func_param_list[] = $p['name'];
		} else if (in_array($p['name'], array('outBegIdx', 'outNBElement'))) {
			$func_param_list[] = "&{$p['name']}";
		} else if ($p['array']) {
			/* Special case for for trader_ht_* functions with two out params with no naming scheme. */
			if (!in_array($p["name"], array("outLeadSine", "outInPhase"))) {
				$last_was_ar = true;
				$zend_param_str .= 'a';

				$ar_count++;

				$zend_param_list[] = "&z{$p['name']}";
				$zend_fast_params["it"][] = "Z_PARAM_ARRAY(z{$p['name']})";
				//$zend_fast_params["it"][] = "Z_PARAM_ARRAY_EX(z{$p['name']}, 0, 1)";
				$zend_fast_params["min_cnt"]++;
			}

			$func_param_list[] = $p['name'];
		} else if ($p['opt'] && ('int' == $p['type'] || 'TA_MAType' == $p['type'])) {
			$last_was_ar = false;
			if(!$pipe_set && !$ar_breaks && $ar_count > 0) {
				$zend_param_str .= '|';
				$zend_fast_params["it"][] = "Z_PARAM_OPTIONAL";
				$pipe_set = true;
			}
			$zend_param_str .= 'l';
			
			$ar_breaks = true;
			$ar_count = 0;
			$zend_param_list[] = "&{$p['name']}";

			$zend_fast_params["it"][] = "Z_PARAM_LONG({$p['name']})";
			$zend_fast_params["opt_cnt"]++;

			$func_param_list[] = "(int){$p['name']}";
		} else if ($p['opt'] && 'double' == $p['type']) {
			$last_was_ar = false;
			if(!$pipe_set && !$ar_breaks && $ar_count > 0) {
				$zend_param_str .= '|';
				$zend_fast_params["it"][] = "Z_PARAM_OPTIONAL";
				$pipe_set = true;
			}
			$zend_param_str .= 'd';

			$ar_breaks = true;
			$ar_count = 0;
			$zend_param_list[] = "&{$p['name']}";

			$zend_fast_params["it"][] = "Z_PARAM_DOUBLE({$p['name']})";
			$zend_fast_params["opt_cnt"]++;

			$func_param_list[] = ($p['byref'] ? '&' : '') . $p['name'];
		}
	}
	$zend_param_str = substr($zend_param_str, 0, strlen($zend_param_str) - ($ar_breaks ? $ar_count : 1));
	$tpl = str_replace('MY_ZEND_PARAMS_STR', "\"$zend_param_str\"", $tpl);

	if ($ar_breaks) {
		$zpl = $zend_param_list;
		end($zpl);
		$m = $l = $ar_count;
		while (false !== ($k = key($zpl)) && $m > 0) {
			unset($zend_param_list[$k]);
			unset($zend_param_list[$k]);
			$m--;
			prev($zpl);
		}
		$ar_count = $m;
		$zpl = $zend_fast_params["it"];
		end($zpl);
		while (false !== ($k = key($zpl)) && $l > 0) {
			unset($zend_fast_params["it"][$k]);
			$l--;
			$zend_fast_params["min_cnt"]--;
			prev($zpl);
		}
	} else {
		array_pop($zend_param_list);
		array_pop($zend_fast_params["it"]);
		$zend_fast_params["min_cnt"]--;
	}
	$zend_params = implode(', ', $zend_param_list);
	$tpl = str_replace('MY_ZEND_PARAM_LIST', $zend_params, $tpl);
	$func_params = implode(', ', $func_param_list);
	$tpl = str_replace('MY_FUNC_PARAMS', $func_params, $tpl);
	$zend_fast = "ZEND_PARSE_PARAMETERS_START(" . $zend_fast_params['min_cnt'] . ", " . ($zend_fast_params['min_cnt'] + $zend_fast_params['opt_cnt']) . ")\n\t\t" . implode("\n\t\t", $zend_fast_params["it"]) . "\n\tZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);";
	$tpl = str_replace("MY_ZEND_FAST_ZPP", $zend_fast, $tpl);


	$rets = array();
	$rets_start = false;
	foreach ($defs['params'] as $p) {
		if (!$rets_start) {
			if ('outNBElement' != $p['name']) {
				continue;
			} else {
				$rets_start = true;
			}
		}
		if ('outNBElement' != $p['name']) {
			$rets[] = $p['name'];
		}
	}
	$count_rets = count($rets) ;
	$tpl = str_replace('MY_PHP_MAKE_RETURN',
		"TRADER_DBL_ARR_TO_ZRET$count_rets(" . implode(', ', $rets) 
		. ", return_value, endIdx, outBegIdx, outNBElement)", $tpl);
	
	$func_arr_allocs = array();
	$func_arr_allocs_str = '';
	foreach ($defs['params'] as $p) {
		if ($p['array']) {
			$func_arr_allocs[] = $p['name'];
		}
	}
	while ($count_rets > 0) {
		array_pop($func_arr_allocs);
		$count_rets--;
	}
	$func_min_end_idx_arr = $func_arr_allocs;
	foreach ($func_arr_allocs as &$item) {
		$item = "TRADER_DBL_ZARR_TO_ARR(z$item, $item)";
	}
	unset($item);
	$func_arr_allocs_s = array();
	foreach($rets as $ret) {
		$func_arr_allocs_s[] = "$ret = emalloc(sizeof(double)*optimalOutAlloc);";
	}
	$func_arr_allocs_str = implode("\n\t\t", $func_arr_allocs_s) . "\n\t\t" . implode("\n\t\t", $func_arr_allocs);
	$tpl = str_replace('MY_FUNC_ARRAY_PARA_ALLOCS', $func_arr_allocs_str, $tpl);

	foreach ($func_min_end_idx_arr as &$item) {
		$item = "zend_hash_num_elements(Z_ARRVAL_P(z$item))";
	}
	unset($item);
	$min_end_idx_str = "TRADER_SET_MIN_INT" . count($func_min_end_idx_arr)
					 . "(endIdx, " . implode(",\n\t\t", $func_min_end_idx_arr) . ')';
	$min_end_idx_str .= "\n\tendIdx--; /* it's <= in the ta-lib */";
	//$min_end_idx_str .= "\n\tendIdx = (endIdx < 0) ? 0 : endIdx;";
	$tpl = str_replace('MY_FUNC_SET_MIN_END_IDX', $min_end_idx_str, $tpl);

	$opt_pcnt = 0;
	$doc_args = array();
	foreach ($defs['params'] as $p) {
		if (in_array($p['name'], array('startIdx', 'endIdx'))) {
			continue;
		}
		if ('outBegIdx' == $p['name']) {
			break;
		}
		if ($p['opt']) {
			$opt_pcnt++;
		}
		$arg_name = '';
		$arg_name .= $p['array'] ? 'array' : ($p['type'] == 'int' || $p['type'] == 'TA_MAType' ? 'int' : 'float');
		$arg_name .= ' ' . lcfirst($p['opt'] ? substr($p['name'], 5) : substr($p['name'], 2));
		$doc_args[] =  $arg_name;
	}
	$mandatory_pcnt = count($doc_args) - $opt_pcnt;
	$arg_doc_line = '';
	for ($k = 0; $k < count($doc_args); $k++) {
		$pref = $k < $mandatory_pcnt ? ($k > 0 ? ', ' : '') : ($k > 0 ? ' [, ' : ' [ ');
		$arg_doc_line .= $pref . $doc_args[$k];
	}
	if ($opt_pcnt > 0) {
		$arg_doc_line .= str_repeat(']', $opt_pcnt);
	}
	$tpl = str_replace('MY_FUNC_DOC_PARAMS', $arg_doc_line, $tpl);

	$ma_type_checks = array();
	foreach ($defs['params'] as $p) {
		if ('TA_MAType' == $p['type']) {
			$ma_type_checks[] = "TRADER_CHECK_MA_TYPE({$p['name']})";
		}
	}
	$tpl = str_replace('MY_FUNC_CHECK_MA_TYPES', implode("\n", $ma_type_checks), $tpl);

	$lb = array();
	foreach ($defs['params'] as $p) {
		if ($p['opt']) {
			/* usually time periods or ma types which are long*/
			$cast = in_array($p['type'], array('TA_MAType', 'int')) ? '(int)' : '';

			$lb[] = $cast . $p['name'];
		}
	}
	$opt_alloc = array();
	$opt_alloc[] = 'lookback = ' . $name . '_Lookback(' . implode(', ', $lb) . ');';
	$opt_alloc[] = "\toptimalOutAlloc = (lookback > endIdx) ? 0 : (endIdx - lookback + 1);";
	$tpl = str_replace('MY_FUNC_OPTIMAL_OUT_ALLOC', implode("\n", $opt_alloc) , $tpl);

	file_put_contents('functions/' . $php_func . '.c', $tpl);
	//break;
}


$func_header = array();
$tpl = file_get_contents('functions/trader_php_func.h.tpl');
foreach ($func as $name => $defs) {
	$php_func = str_replace('ta_', 'trader_', strtolower($name));
	$func_header[] = 'PHP_FUNCTION(' . $php_func . ');';
}
$tpl = str_replace('HEADER_CONTENT', implode("\n", $func_header), $tpl);
file_put_contents('functions/trader_php_func.h', $tpl);


$fe_header = array();
$tpl = file_get_contents('functions/trader_php_fe.h.tpl');
foreach ($func as $name => $defs) {
	$php_func = str_replace('ta_', 'trader_', strtolower($name));
	$fe_header[] = "\tPHP_FE($php_func, arg_info_$php_func)";
	//$fe_header[] = "\tPHP_FE($php_func, NULL)";
}
$tpl = str_replace('HEADER_CONTENT', implode("\n", $fe_header), $tpl);
file_put_contents('functions/trader_php_fe.h', $tpl);


$arginfo_header = array();
$tpl = file_get_contents('functions/trader_php_arginfo.h.tpl');
foreach ($func as $name => $defs) {
	$php_func = str_replace('ta_', 'trader_', strtolower($name));
	$tmp = '';
	
	$mandatory_pcnt = 0;
	foreach ($defs['params'] as $p) {
		if (in_array($p['name'], array('startIdx', 'endIdx'))) {
			continue;
		}
		if ('outBegIdx' == $p['name']) {
			break;
		}
		if (!$p['opt']) {
			$mandatory_pcnt++;
		}
		/*$type_hint = $p['array'] ? 'IS_ARRAY' : ($p['type'] == 'int' || $p['type'] == 'TA_MAType' ? 'IS_LONG' : 'IS_DOUBLE');*/
		$arg_name = ' ' . lcfirst($p['opt'] ? substr($p['name'], 5) : substr($p['name'], 2));
		if ($p['array']) {
			$allow_null = (int)$p['opt'];
			$tmp .= "\tZEND_ARG_ARRAY_INFO(0, $arg_name, $allow_null)\n";
		} else {
			$tmp .= "\tZEND_ARG_INFO(0, $arg_name)\n";
		}
	}

	$tmp .= "ZEND_END_ARG_INFO();";
	$tmp = "ZEND_BEGIN_ARG_INFO_EX(arg_info_$php_func, 0, 0, $mandatory_pcnt)\n$tmp";
	$arginfo_header[] = $tmp;
}
$tpl = str_replace('HEADER_CONTENT', implode("\n\n", $arginfo_header), $tpl);
file_put_contents('functions/trader_php_arginfo.h', $tpl);

