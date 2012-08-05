--TEST--
trader_add() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

var_dump(trader_add(get_data("high", $data1), get_data("low", $data1)));

--EXPECT--
array(30) {
  [0]=>
  float(123.71)
  [1]=>
  float(122.74)
  [2]=>
  float(122.38)
  [3]=>
  float(119.4)
  [4]=>
  float(118.64)
  [5]=>
  float(121.61)
  [6]=>
  float(117.97)
  [7]=>
  float(117.02)
  [8]=>
  float(116.55)
  [9]=>
  float(117.52)
  [10]=>
  float(116.58)
  [11]=>
  float(116.51)
  [12]=>
  float(116.38)
  [13]=>
  float(116.08)
  [14]=>
  float(115.88)
  [15]=>
  float(118.44)
  [16]=>
  float(117.83)
  [17]=>
  float(120.63)
  [18]=>
  float(121.96)
  [19]=>
  float(123.6)
  [20]=>
  float(122.53)
  [21]=>
  float(125.99)
  [22]=>
  float(126.85)
  [23]=>
  float(129.73)
  [24]=>
  float(130.41)
  [25]=>
  float(131.68)
  [26]=>
  float(128.44)
  [27]=>
  float(125.28)
  [28]=>
  float(124.29)
  [29]=>
  float(123.95)
}