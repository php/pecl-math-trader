--TEST--
trader.real_round_mode ini setting
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--INI--
trader.real_round_mode=HALF_ODD
--FILE--
<?php
var_dump(ini_get('trader.real_round_mode'));
echo 'done';
--EXPECT--
string(8) "HALF_ODD"
done
