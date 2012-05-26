--TEST--
ta_macd() basic test
--SKIPIF--
<?php
if (!extension_loaded("ta")) die("skip");
--FILE--
<?php

include "data.php";
include "func.php";

$fast_period = 14;

var_dump(ta_aroon(get_data("high", $data0), get_data("low", $data0), $fast_period));
--EXPECT--
