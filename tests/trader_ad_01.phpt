--TEST--
trader_ad() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

var_dump(trader_ad(get_data("high", $data1), get_data("low", $data1), get_data("close", $data1), get_data("volume", $data1)));

--EXPECT--
array(30) {
  [0]=>
  float(4774.134)
  [1]=>
  float(-4854.572)
  [2]=>
  float(-12033.93)
  [3]=>
  float(-18263.911)
  [4]=>
  float(-20983.124)
  [5]=>
  float(-39952.595)
  [6]=>
  float(-48761.487)
  [7]=>
  float(-52761.344)
  [8]=>
  float(-47293.262)
  [9]=>
  float(-48537.697)
  [10]=>
  float(-47198.262)
  [11]=>
  float(-49555.402)
  [12]=>
  float(-49847.973)
  [13]=>
  float(-49309.973)
  [14]=>
  float(-47345.558)
  [15]=>
  float(-50863.058)
  [16]=>
  float(-48770.302)
  [17]=>
  float(-32430.773)
  [18]=>
  float(-25121.247)
  [19]=>
  float(-27136.972)
  [20]=>
  float(-18021.277)
  [21]=>
  float(-20165.277)
  [22]=>
  float(-17971.394)
  [23]=>
  float(-33071.293)
  [24]=>
  float(-36977.478)
  [25]=>
  float(-46736.666)
  [26]=>
  float(-55496.349)
  [27]=>
  float(-58778.033)
  [28]=>
  float(-63909.98)
  [29]=>
  float(-56552.876)
}