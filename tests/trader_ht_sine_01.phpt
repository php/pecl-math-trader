--TEST--
trader_ht_sine() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--INI--
trader.real_precision=3
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

/* Lookback is 63. */
var_dump(trader_ht_sine(
	array_slice(get_data("close", $data0), 0, 65)
));
?>
--EXPECT--
array(2) {
  [0]=>
  array(2) {
    [63]=>
    float(0.456)
    [64]=>
    float(0.833)
  }
  [1]=>
  array(2) {
    [63]=>
    float(0.952)
    [64]=>
    float(0.98)
  }
}
