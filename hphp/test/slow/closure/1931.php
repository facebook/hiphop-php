<?hh


<<__EntryPoint>>
function main_1931() {
$myfunc = function() {
  echo "hello, world!\n";
}
;
$myfunc();
call_user_func($myfunc);
call_user_func_array($myfunc, array());
$isc = is_callable_with_name($myfunc, false, &$p);
echo "is_callable(\$myfunc) = $isc\n";
var_dump($p);
}
