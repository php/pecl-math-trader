--TEST--
ta_ad() basic test
--SKIPIF--
if (!extension_loaded("ta")) die("skip");
--FILE--
<?php

include "data.php";
include "func.php";

var_dump(ta_ad(get_data("high", $data1), get_data("low", $data1), get_data("close", $data1), get_data("volume", $data1)));
--EXPECT--
