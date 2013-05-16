<?php
/* Prototype  : bool array_multisort(array ar1 [, SORT_ASC|SORT_DESC [, SORT_REGULAR|SORT_NUMERIC|SORT_STRING|SORT_NATURAL|SORT_FLAG_CASE]] [, array ar2 [, SORT_ASC|SORT_DESC [, SORT_REGULAR|SORT_NUMERIC|SORT_STRING|SORT_NATURAL|SORT_FLAG_CASE], ...])
 * Description: Sort multiple arrays at once similar to how ORDER BY clause works in SQL 
 * Source code: ext/standard/array.c
 * Alias to functions: 
 */

echo "*** Testing array_multisort() : natural sorting\n";

$a = array(
	'Second',
	'First',
	'Twentieth',
	'Tenth',
	'Third',
);

$b = array(
	'2 a',
	'1 b',
	'20 c',
	'10 d',
	'3 e',
);

array_multisort($b, SORT_NATURAL, $a);

var_dump($a, $b);

?>
===DONE===