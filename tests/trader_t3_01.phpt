--TEST--
trader_t3() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

var_dump(trader_t3(get_data("high", $data1)));
--EXPECT--
array(24) {
  [6]=>
  float(60.819)
  [7]=>
  float(60.187)
  [8]=>
  float(59.681)
  [9]=>
  float(59.417)
  [10]=>
  float(59.16)
  [11]=>
  float(58.942)
  [12]=>
  float(58.747)
  [13]=>
  float(58.55)
  [14]=>
  float(58.439)
  [15]=>
  float(58.835)
  [16]=>
  float(59.162)
  [17]=>
  float(60.114)
  [18]=>
  float(60.991)
  [19]=>
  float(61.712)
  [20]=>
  float(62.091)
  [21]=>
  float(62.662)
  [22]=>
  float(63.169)
  [23]=>
  float(64.181)
  [24]=>
  float(65.102)
  [25]=>
  float(65.745)
  [26]=>
  float(65.749)
  [27]=>
  float(65.03)
  [28]=>
  float(64.269)
  [29]=>
  float(63.605)
}
