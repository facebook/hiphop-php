<?php
/* Prototype  : array array_diff_assoc(array $arr1, array $arr2 [, array ...])
 * Description: Returns the entries of arr1 that have values which are not 
 * present in any of the others arguments but do additional checks whether 
 * the keys are equal 
 * Source code: ext/standard/array.c
 */

/*
 * Test how array_diff_assoc() compares binary data
 */

echo "*** Testing array_diff_assoc() : usage variations ***\n";

$array1 = array( b"1", 
                 b"hello", 
                 "world", 
                 "str1" => "hello", 
                 "str2" => "world");

$array2 = array( b"1" => 'hello',
                 b"world",
                 "hello", 
                 'test');

var_dump(array_diff_assoc($array1, $array2));
var_dump(array_diff_assoc($array2, $array1));

echo "Done";
?>
