<?hh

$sql = "DELETE FROM `foo` WHERE `left` BETWEEN {$res->left} AND {$res->right} ORDER BY `level` DESC";

$str = "embedded: {$a_long_object_name->a_long_property_name->an_array_property_name[0]} <- braced expression";

$str = "embedded: {$a_long_array_name[$some_object instanceof SomeClass ? 0 : 1]} <- braced subscript expression";

$str = "string with $foobararray[$looooooooooooooooooooooooooooooooooooooooooooooooong_index] won't break";

$str = "string with $my_object->looooooooooooooooooooooooooooooooooooooooooooooooong_property won't break either";
