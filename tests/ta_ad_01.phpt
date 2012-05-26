--TEST--
ta_ad() basic test
--SKIPIF--
if (!extension_loaded("ta")) die("skip");
--FILE--
<?php

include "tests/data.php";
include "tests/func.php";

echo ta_ad(62.05, 60.69, 60.81, 11.692);
--EXPECT--
-9.628
