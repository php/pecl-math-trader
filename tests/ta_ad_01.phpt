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
array(30) {
  [0]=>
  float(4774.134)
  [1]=>
  float(-4854.571)
  [2]=>
  float(-12033.929)
  [3]=>
  float(-18263.911)
  [4]=>
  float(-20983.124)
  [5]=>
  float(-39952.595)
  [6]=>
  float(-48761.486)
  [7]=>
  float(-52761.344)
  [8]=>
  float(-47293.262)
  [9]=>
  float(-48537.697)
  [10]=>
  float(-47198.262)
  [11]=>
  float(-49555.401)
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
  float(-32430.772)
  [18]=>
  float(-25121.247)
  [19]=>
  float(-27136.971)
  [20]=>
  float(-18021.276)
  [21]=>
  float(-20165.276)
  [22]=>
  float(-17971.394)
  [23]=>
  float(-33071.292)
  [24]=>
  float(-36977.478)
  [25]=>
  float(-46736.665)
  [26]=>
  float(-55496.348)
  [27]=>
  float(-58778.032)
  [28]=>
  float(-63909.979)
  [29]=>
  float(-56552.876)
}
