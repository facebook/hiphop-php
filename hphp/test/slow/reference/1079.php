<?php

function f(&$a) {
 $a = 'ok';
}
 class T {
 public $b = 10;
}

 <<__EntryPoint>>
function main_1079() {
$a = new T();
 $a->b = 10;
 f($a->b);
 var_dump($a);
}
