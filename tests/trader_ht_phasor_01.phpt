--TEST--
trader_ht_phasor() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--INI--
trader.real_precision=3
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

/* Lookback is 32. */
var_dump(trader_ht_phasor(
	array_slice(get_data("close", $data0), 0, 35)
));
?>
--EXPECT--
array(2) {
  [0]=>
  array(3) {
    [32]=>
    float(2.805)
    [33]=>
    float(3.219)
    [34]=>
    float(1.613)
  }
  [1]=>
  array(3) {
    [32]=>
    float(4.668)
    [33]=>
    float(-0.935)
    [34]=>
    float(-3.103)
  }
}
