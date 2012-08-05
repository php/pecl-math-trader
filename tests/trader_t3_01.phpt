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
  float(60.188)
  [8]=>
  float(59.681)
  [9]=>
  float(59.418)
  [10]=>
  float(59.161)
  [11]=>
  float(58.943)
  [12]=>
  float(58.748)
  [13]=>
  float(58.551)
  [14]=>
  float(58.44)
  [15]=>
  float(58.835)
  [16]=>
  float(59.162)
  [17]=>
  float(60.115)
  [18]=>
  float(60.991)
  [19]=>
  float(61.713)
  [20]=>
  float(62.092)
  [21]=>
  float(62.663)
  [22]=>
  float(63.17)
  [23]=>
  float(64.182)
  [24]=>
  float(65.102)
  [25]=>
  float(65.746)
  [26]=>
  float(65.75)
  [27]=>
  float(65.031)
  [28]=>
  float(64.269)
  [29]=>
  float(63.605)
}