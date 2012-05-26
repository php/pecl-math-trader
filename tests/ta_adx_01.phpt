--TEST--
ta_adx() basic test
--FILE--
<?php

include "tests/data.php";
include "tests/func.php";

$time_period = 14;

var_dump(ta_adx(get_data("high", $data), get_data("low", $data), get_data("close", $data), $time_period)) . "\n";
--EXPECT--

