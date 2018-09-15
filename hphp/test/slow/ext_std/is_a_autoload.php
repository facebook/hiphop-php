<?php


<<__EntryPoint>>
function main_is_a_autoload() {
spl_autoload_register(
  function($class) {
    var_dump('Autoload: '.$class);
    return false;
  }
);

var_dump(is_a(1, 'Foo'));
var_dump(is_a(2, 'Foo', false));
var_dump(is_a(3, 'Foo', true));

var_dump(is_a('a', 'Foo'));
var_dump(is_a('b', 'Foo', false));
var_dump(is_a('c', 'Foo', true));
}
