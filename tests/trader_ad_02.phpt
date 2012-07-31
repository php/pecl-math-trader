--TEST--
trader_ad() fail test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

var_dump(trader_ad(array(), array(), array(), array()));
--EXPECT--
bool(false)
