<?hh


<<__EntryPoint>>
function main_1428() {
$a = "123.456" / 123;
var_dump($a);
$a = "123.456" / 456.123;
var_dump($a);
$a = "123.456" / "123";
var_dump($a);
$a = "123.456" / "456.123";
var_dump($a);
$a = "123.456";
$a /= 123;
var_dump($a);
$a = "123.456";
$a /= 456.123;
var_dump($a);
$a = "123.456";
$a /= "123";
var_dump($a);
$a = "123.456";
$a /= "456.123";
var_dump($a);
$a = "123" / 123;
var_dump($a);
$a = "123" / "123";
var_dump($a);
$a = "321" / 123;
var_dump($a);
$a = "321" / 123.456;
var_dump($a);
}
