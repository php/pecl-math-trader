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
	if(!preg_match(',^/\*\s*\n.*(TA_.*) - (.*)$,mU', $f, $mm)) {
		echo "desc error with '$f'\n";
		continue;
	}

	$fname = $mm[1];
	$func[$fname] = array();
	$func[$fname]['desc'] = $mm[2];

	if(!preg_match(",TA_RetCode $fname\((.*)\),smU", $f, $mm)) {
		echo "params error with '$f'\n";
		continue;
	}

	$func[$fname]['params'] = array();

	/* parse and normalize the param list first */
	$para = array();
	$para = explode("\n", $mm[1]);
	foreach($para as $p) {
		$p = trim($p);
		$p = preg_replace(',\s+,', ' ', $p);

		$param = array(
			'name' => NULL,
			'type' => NULL,
			'byref' => false,
			'array' => false,
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
		}
		$param['type'] = $mmm[1];

		$func[$fname]['params'][] = $param;
	}
}

print_r($func);

print count($func) . "\n";
