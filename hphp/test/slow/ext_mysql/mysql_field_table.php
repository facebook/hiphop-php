<?hh
<<__EntryPoint>> function main(): void {
require_once('connect.inc');
list($host, $user, $passwd, $db) = connection_settings();
$conn = mysql_connect($host, $user, $passwd);
var_dump(create_test_table($db, 'field_table'));
var_dump(mysql_query(
  "insert into test_field_table (name) values ('test'),('test2')"));

$res = mysql_query('select * from test_field_table');
var_dump(mysql_field_table($res, 1));
}
