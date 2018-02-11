--TEST--
trader.real_round_mode basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

var_dump(ini_get('trader.real_round_mode')); //initial HALF_DOWN

ini_set('trader.real_round_mode', 'HALF_UP');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 'HALF_DOWN');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 'HALF_EVEN');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 'HALF_ODD');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 'half_up');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 'half_down');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 'half_even');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 'half_odd');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 'schnitzel');
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', array());
var_dump(ini_get('trader.real_round_mode'));

ini_set('trader.real_round_mode', 42);
var_dump(ini_get('trader.real_round_mode'));

echo "done";
--EXPECTF--
string(9) "HALF_DOWN"
string(7) "HALF_UP"
string(9) "HALF_DOWN"
string(9) "HALF_EVEN"
string(8) "HALF_ODD"
string(7) "half_up"
string(9) "half_down"
string(9) "half_even"
string(8) "half_odd"

Warning: ini_set(): Invalid value 'schnitzel' for trader.real_round_mode in %strader_ini_01.php on line %d
string(8) "half_odd"

Warning: ini_set() expects parameter 2 to be string, array given in %strader_ini_01.php on line %d
string(8) "half_odd"

Warning: ini_set(): Invalid value '42' for trader.real_round_mode in %strader_ini_01.php on line %d
string(8) "half_odd"
done
