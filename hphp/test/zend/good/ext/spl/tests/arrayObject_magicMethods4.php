<?hh
class C {
    public $a = 1;
    public $b = 2;
    public $c = 3;

    private $priv = 'secret';
}

class UsesMagic extends ArrayObject {

    public $b = "This should not be in the storage";

    function __get($name) {
        $args = func_get_args();
        echo "In " . __METHOD__ . "(" . implode($args, ',') . ")\n";
    }
    function __set($name, $value) {
        $args = func_get_args();
        echo "In " . __METHOD__ . "(" . implode($args, ',') . ")\n";
    }
    function __isset($name) {
        $args = func_get_args();
        echo "In " . __METHOD__ . "(" . implode($args, ',') . ")\n";
    }
    function __unset($name) {
        $args = func_get_args();
        echo "In " . __METHOD__ . "(" . implode($args, ',') . ")\n";
    }

}
<<__EntryPoint>> function main(): void {
$obj = new C;
$ao = new UsesMagic($obj);
echo "\n--> Write existent, non-existent and dynamic:\n";
$ao['a'] = 'changed';
$ao['dynamic'] = 'new';
$ao['dynamic'] = 'new.changed';
echo "  Original wrapped object:\n";
var_dump($obj);
echo "  Wrapping ArrayObject:\n";
var_dump($ao);

echo "\n--> Read existent, non-existent and dynamic:\n";
var_dump($ao['a']);
var_dump($ao['nonexistent']);
var_dump($ao['dynamic']);
echo "  Original wrapped object:\n";
var_dump($obj);
echo "  Wrapping ArrayObject:\n";
var_dump($ao);

echo "\n--> isset existent, non-existent and dynamic:\n";
var_dump(isset($ao['a']));
var_dump(isset($ao['nonexistent']));
var_dump(isset($ao['dynamic']));
echo "  Original wrapped object:\n";
var_dump($obj);
echo "  Wrapping ArrayObject:\n";
var_dump($ao);

echo "\n--> Unset existent, non-existent and dynamic:\n";
unset($ao['a']);
try { unset($ao['nonexistent']); } catch (Exception $e) { echo $e->getMessage()."\n"; }
unset($ao['dynamic']);
echo "  Original wrapped object:\n";
var_dump($obj);
echo "  Wrapping ArrayObject:\n";
var_dump($ao);
}
