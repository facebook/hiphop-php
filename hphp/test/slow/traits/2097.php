<?php
trait t1 {
 static public $x = INIT1;
 }
trait t2 {
 static public $y = INIT2;
 }
trait t {
 use t1, t2;
 }
class c {
 use t;
 }


<<__EntryPoint>>
function main_2097() {
define('INIT1', "1");
define('INIT2', "2");
var_dump(c::$x);
var_dump(c::$y);
}
