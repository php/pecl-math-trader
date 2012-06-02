<?php

function get_data($key, $data) {
	$retval = array();

	foreach ($data as $bar) {
		$retval[] = $bar[$key];
	}

	return $retval;
}

