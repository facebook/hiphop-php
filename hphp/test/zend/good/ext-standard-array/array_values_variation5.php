<?php
/* Prototype  : array array_values(array $input)
 * Description: Return just the values from the input array 
 * Source code: ext/standard/array.c
 */

/*
 * Test the position of the internal array pointer after a call to array_values
 */

echo "*** Testing array_values() : usage variations ***\n";

$input = array ('one' => 'un', 'two' => 'deux', 'three' => 'trois');

echo "\n-- Call array_values() --\n";
var_dump($result = array_values($input));

echo "-- Position of Internal Pointer in Result: --\n";
echo key($result) . " => " . current($result) . "\n";
echo "\n-- Position of Internal Pointer in Original Array: --\n";
echo key($input) . " => " . current ($input) . "\n";

echo "Done";
?>
