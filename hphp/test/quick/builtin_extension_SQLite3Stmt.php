<?hh

include __DIR__."/builtin_extensions.inc";

class A_SQLite3Stmt extends SQLite3Stmt {
  public $___x;
}
test("SQLite3Stmt", new SQLite3(":memory:"), "CREATE TABLE test (column);");
