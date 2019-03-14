<?php
/* Prototype  : proto int iconv_strrpos(string haystack, string needle [, string charset])
 * Description: Find position of last occurrence of a string within another 
 * Source code: ext/iconv/iconv.c
 */

/*
 * Pass iconv_strrpos() an incorrect number of arguments
 */

echo "*** Testing iconv_strrpos() : error conditions ***\n";


//Test iconv_strrpos with one more than the expected number of arguments
echo "\n-- Testing iconv_strrpos() function with more than expected no. of arguments --\n";
$haystack = 'string_val';
$needle = 'string_val';
$encoding = 'string_val';
$extra_arg = 10;
try { var_dump( iconv_strrpos($haystack, $needle, $encoding, $extra_arg) ); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }

// Testing iconv_strrpos with one less than the expected number of arguments
echo "\n-- Testing iconv_strrpos() function with less than expected no. of arguments --\n";
$haystack = 'string_val';
try { var_dump( iconv_strrpos($haystack) ); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }

echo "Done";
?>
