<?php

function a() {
  $transport = array("foot", "bike", "car", "plane");
  var_dump(current($transport));
  var_dump(next($transport));
  var_dump(current($transport));
  var_dump(prev($transport));
  var_dump(end($transport));
  var_dump(current($transport));
}

function b() {
  $arr = array();
  var_dump(current($arr));
  var_dump(current(array()));
}

function c() {
  $arr = array(array());
  var_dump(current($arr));
}


<<__EntryPoint>>
function main_current() {
a();
b();
c();
}
