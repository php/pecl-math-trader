--TEST--
trader_aroon() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "data.php";
include "func.php";

$fast_period = 14;

var_dump(trader_aroon(get_data("high", $data0), get_data("low", $data0), $fast_period));
--EXPECT--
