<?hh

function junk() { return 2; }
function bar() {
  $x = darray['y' => junk(), 'x' => new stdClass()];
  $x['x']->hehe++;
  $val = $x['x'];
  var_dump(is_null($val));
  var_dump(is_array($x));
}

<<__EntryPoint>>
function main_array_022() {
bar();
}
