<?php

$path = 'ta-lib/include/ta_func.h';

$c = file_get_contents($path);

/* got function defs with headers */
preg_match_all(',^/\*\s*\* TA\_.*\*/.*TA_RetCode.*\(.*\)\;$,smU', $c, $m, PREG_PATTERN_ORDER);
//preg_match_all(',^/\*\s*.*?\*/\s*TA_.*?\(.*?\)\;,sm', $c, $m);
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

	$tpl = str_replace('MY_FUNC_NAME_LOWER', strtolower($name), $tpl);
	$tpl = str_replace('MY_FUNC_NAME', $name, $tpl);
	$tpl = str_replace('MY_FUNC_DESC', $defs['desc'], $tpl);

	$php_arr_defs = array();
	foreach ($defs['params'] as $p) {
		if ($p['array']) {
			$php_arr_defs[] = "*z$p[name]";
		}
	}
	array_pop($php_arr_defs); // the last is always the out array which is return_value
	$tpl = str_replace('MY_IN_PHP_ARRAY_DEFS', 'zval ' . implode(', ', $php_arr_defs) . ';', $tpl);


	$func_arr_deallocs = array();
	foreach ($defs['params'] as $p) {
		if ($p['array']) {
			$func_arr_deallocs[] = "efree({$p['name']});";
		}
	}
	$tpl = str_replace('MY_FUNC_ARRAY_PARA_DEALLOCS1', implode("\n\t", $func_arr_deallocs) . ';', $tpl);
	$tpl = str_replace('MY_FUNC_ARRAY_PARA_DEALLOCS2', implode("\n\t\t", $func_arr_deallocs) . ';', $tpl);


	$func_arr_defs = array();
	foreach ($defs['params'] as $p) {
		if ($p['array']) {
			$func_arr_defs[] = "*$p[name]";
		}
	}
	$tpl = str_replace('MY_FUNC_ARRAY_PARA_DEFS', 'double ' . implode(', ', $func_arr_defs) . ';', $tpl);


	$func_int_defs = array();
	foreach ($defs['params'] as $p) {
		if ('int' == $p['type'] && !$p['opt']) {
			$func_int_defs[] = "$p[name]" . (NULL != $p['bounds']['min'] ? " = {$p['bounds']['min']}" : '');
		}
	}
	$tpl = str_replace('MY_FUNC_INT_PARA_DEFS', 'int ' . implode(', ', $func_int_defs) . ';', $tpl);
	$tpl = str_replace('MY_FUNC_SET_START_IDX', 'startIdx = 0;', $tpl); // not nice
	/* XXX doubles need to walk in the same way */


	$php_long_defs = array();
	foreach ($defs['params'] as $p) {
		if ('int' == $p['type'] && $p['opt']) {
			$php_long_defs[] = "$p[name]" . (NULL != $p['bounds']['min'] ? " = {$p['bounds']['min']}" : '');
		}
	}
	$php_long_defs_repl = count($php_long_defs) ? 'long ' . implode(', ', $php_long_defs) . ';' : '';
	$tpl = str_replace('MY_IN_PHP_LONG_DEFS', $php_long_defs_repl, $tpl);


	$func_set_boundable = array();
	foreach ($defs['params'] as $p) {
		if (NULL != $p['bounds']['min'] && NULL != $p['bounds']['max']) {
			$func_set_boundable[] = "TA_SET_BOUNDABLE({$p['bounds']['min']}, {$p['bounds']['max']}, {$p['name']});";
		}
	}
	$tpl = str_replace('MY_FUNC_SET_BOUNDABLE', implode("\n\t", $func_set_boundable), $tpl);


	$zend_param_str = $zend_param_str_a = $zend_param_str_l = $zend_param_str_d = '';
	$zend_param_list = '';
	$zend_param_list_a = $zend_param_list_l = $zend_param_list_d = array();
	$func_param_list_a = $func_param_list_l = $func_param_list_d = array();
	foreach ($defs['params'] as $p) {
		if ($p['array']) {
			$zend_param_str_a .= 'a';
			$zend_param_list_a[] = "&{$p['name']}";
			$func_param_list_a[] = $p['name'];
		} else if ($p['opt'] && 'int' == $p['type']) {
			$zend_param_str_l .= 'l';
			$zend_param_list_l[] = "&{$p['name']}";
			$func_param_list_l[] = "(int){$p['name']}";
		} else if ($p['opt'] && 'double' == $p['type']) {
			$zend_param_str_d .= 'd';
			$zend_param_list_d[] = "&{$p['name']}";
			$func_param_list_d[] = ($p['byref'] ? '&' : '') . $p['name'];
		}
	}
	$zend_param_str = substr($zend_param_str_a, 0, strlen($zend_param_str_a)-1);
	if (strlen($zend_param_str_l) || strlen($zend_param_str_d)) {
		$zend_param_str = "$zend_param_str|$zend_param_str_l$zend_param_str_d";
	}
	$tpl = str_replace('MY_ZEND_PARAMS_STR', "\"$zend_param_str\"", $tpl);
	array_pop($zend_param_list_a);
	$result_arr = array_pop($func_param_list_a);
	$zend_param_list = implode(', ', $zend_param_list_a);
	$func_params = 'startIdx, endIdx, ' . implode(', ', $func_param_list_a);
	if (count($zend_param_list_l)) {
		$zend_param_list .= ', ' . implode(', ', $zend_param_list_l);
		$func_params .= ', ' . implode(', ', $func_param_list_l);
	}
	if (count($zend_param_list_d)) {
		$zend_param_list .= ', ' . implode(', ', $zend_param_list_d);
		$func_params .= ', ' . implode(', ', $func_param_list_d);
	}
	/* XXX that order mightbe wrong ) */
	$tpl = str_replace('MY_ZEND_PARAM_LIST', $zend_param_list, $tpl);
	$tpl = str_replace('MY_FUNC_PARAMS', $func_params . ', &outBegIdx, &outNBElement, ' . $result_arr , $tpl);


	$func_arr_allocs = array();
	$func_arr_allocs_str = '';
	foreach ($defs['params'] as $p) {
		if ($p['array']) {
			$func_arr_allocs[] = $p['name'];
		}
	}
	$result_arr = array_pop($func_arr_allocs);
	$func_min_end_idx_arr = $func_arr_allocs;
	foreach ($func_arr_allocs as &$item) {
		$item = "TA_DBL_ZARR_TO_ARR(z$item, $item)";
	}
	unset($item);
	$func_arr_allocs_str = "$result_arr = emalloc(sizeof(double)*(endIdx+1));"
			. "\n\t" . implode("\n\t", $func_arr_allocs);
	$tpl = str_replace('MY_FUNC_ARRAY_PARA_ALLOCS', $func_arr_allocs_str, $tpl);
	$tpl = str_replace('MY_PHP_MAKE_RETURN',
		"TA_DBL_ARR_TO_ZARR($result_arr, return_value, endIdx, outBegIdx, outNBElement)", $tpl);

	foreach ($func_min_end_idx_arr as &$item) {
		$item = "zend_hash_num_elements(Z_ARRVAL_P($item))";
	}
	unset($item);
	$tpl = str_replace('MY_FUNC_SET_MIN_END_IDX',
		"TA_SET_MIN_INT" . count($func_min_end_idx_arr) . "(endIdx, " . implode(",\n\t\t", $func_min_end_idx_arr) . ')', $tpl);

	file_put_contents('functions/' . strtolower($name) . '.c', $tpl);
	//break;
}

