<?hh


<<__EntryPoint>>
function main_113() {
$foo = 1 + "10.5";
$foo__str = (string)($foo);
print("$foo__str ");
$foo = 1 + "-1.3e3";
$foo__str = (string)($foo);
print("$foo__str ");
$foo = 1 + "bob-1.3e3";
print("$foo ");
$foo = 1 + "bob3";
print("$foo ");
$foo = 1 + "10 Small Pigs";
print("$foo ");
$foo = 4 + "10.2 Little Piggies";
$foo__str = (string)($foo);
print("$foo__str ");
$foo = "10.0 pigs " + 1;
$foo__str = (string)($foo);
print("$foo__str ");
$foo = "10.0 pigs " + 1.0;
$foo__str = (string)($foo);
print("$foo__str ");
}
