--TEST--
ta_ad() fail test
--SKIPIF--
<?php
if (!extension_loaded("ta")) die("skip");
--FILE--
<?php

include "data.php";
include "func.php";

var_dump(ta_ad(array(), array(), array(), array()));
--EXPECT--
array(0) {
}
