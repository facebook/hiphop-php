<?php
// TODO: Add more encodings

//$debug=true;
ini_set('include_path','.');
include_once('common.inc');


// Test string
$euc_jp = b'0123この文字列は日本語です。EUC-JPを使っています。0123日本語は面倒臭い。';

// EUC-JP - With encoding parameter
mb_internal_encoding('UTF-8') or print("mb_internal_encoding() failed\n");

echo  "== POSITIVE OFFSET ==\n";
print  mb_stripos($euc_jp,b'日本語', 0, 'EUC-JP') . "\n";
print  mb_stripos($euc_jp, b'0', 0,     'EUC-JP') . "\n";
print  mb_stripos($euc_jp, 3, 0,       'EUC-JP') . "\n";
print  mb_stripos($euc_jp, 0, 0,       'EUC-JP') . "\n";
print  mb_stripos($euc_jp,b'日本語', 15, 'EUC-JP') . "\n";
print  mb_stripos($euc_jp, b'0', 15,     'EUC-JP') . "\n";
print  mb_stripos($euc_jp, 3, 15,       'EUC-JP') . "\n";
print  mb_stripos($euc_jp, 0, 15,       'EUC-JP') . "\n";

// Negative offset
// Note: PHP Warning - offset is negative.
// Note: For offset(-15). It does not return position of latter string. (ie the same result as -50)
echo "== NEGATIVE OFFSET ==\n";
$r = mb_stripos($euc_jp,b'日本語', -15, 'EUC-JP');
($r === FALSE) ? print "OK_NEGATIVE_OFFSET\n" : print "NG_NEGATIVE_OFFSET\n";
$r = mb_stripos($euc_jp, b'0', -15,     'EUC-JP');
($r === FALSE) ? print "OK_NEGATIVE_OFFSET\n" : print "NG_NEGATIVE_OFFSET\n";
$r = mb_stripos($euc_jp, 3, -15,       'EUC-JP');
($r === FALSE) ? print "OK_NEGATIVE_OFFSET\n" : print "NG_NEGATIVE_OFFSET\n";
$r = mb_stripos($euc_jp, 0, -15,       'EUC-JP');
($r === FALSE) ? print "OK_NEGATIVE_OFFSET\n" : print "NG_NEGATIVE_OFFSET\n";
$r = mb_stripos($euc_jp,b'日本語', -50, 'EUC-JP');
($r === FALSE) ? print "OK_NEGATIVE_OFFSET\n" : print "NG_NEGATIVE_OFFSET\n";
$r = mb_stripos($euc_jp, b'0', -50,     'EUC-JP');
($r === FALSE) ? print "OK_NEGATIVE_OFFSET\n" : print "NG_NEGATIVE_OFFSET\n";
$r = mb_stripos($euc_jp, 3, -50,       'EUC-JP');
($r === FALSE) ? print "OK_NEGATIVE_OFFSET\n" : print "NG_NEGATIVE_OFFSET\n";
$r = mb_stripos($euc_jp, 0, -50,       'EUC-JP');
($r === FALSE) ? print "OK_NEGATIVE_OFFSET\n" : print "NG_NEGATIVE_OFFSET\n";

// Out of range - should return false
print ("== OUT OF RANGE ==\n");
$r =  mb_stripos($euc_jp,b'日本語', 40, 'EUC-JP');
($r === FALSE) ? print "OK_OUT_RANGE\n"     : print "NG_OUT_RANGE\n";
$r =  mb_stripos($euc_jp, b'0', 40,     'EUC-JP');
($r === FALSE) ? print "OK_OUT_RANGE\n"     : print "NG_OUT_RANGE\n";
$r =  mb_stripos($euc_jp, 3, 40,       'EUC-JP');
($r === FALSE) ? print "OK_OUT_RANGE\n"     : print "NG_OUT_RANGE\n";
$r =   mb_stripos($euc_jp, 0, 40,       'EUC-JP');
($r === FALSE) ? print "OK_OUT_RANGE\n"     : print "NG_OUT_RANGE\n";
// Note: Returned NULL string
// echo gettype($r). ' val '. $r ."\n"; 


// Non-existent
echo "== NON-EXISTENT ==\n";
$r = mb_stripos($euc_jp, b'韓国語', 0, 'EUC-JP');
($r === FALSE) ? print "OK_STR\n"     : print "NG_STR\n";
$r = mb_stripos($euc_jp, b"\n",     0, 'EUC-JP');
($r === FALSE) ? print "OK_NEWLINE\n" : print "NG_NEWLINE\n";


// EUC-JP - No encoding parameter
echo "== NO ENCODING PARAMETER ==\n";
mb_internal_encoding('EUC-JP')  or print("mb_internal_encoding() failed\n");

print  mb_stripos($euc_jp,b'日本語', 0) . "\n";
print  mb_stripos($euc_jp, b'0', 0) . "\n";
print  mb_stripos($euc_jp, 3, 0) . "\n";
print  mb_stripos($euc_jp, 0, 0) . "\n";

$r = mb_stripos($euc_jp,b'韓国語', 0);
($r === FALSE) ? print "OK_STR\n"     : print "NG_STR\n";
$r = mb_stripos($euc_jp,b"\n", 0);
($r === FALSE) ? print "OK_NEWLINE\n" : print "NG_NEWLINE\n";

// EUC-JP - No offset and encoding parameter
echo "== NO OFFSET AND ENCODING PARAMETER ==\n";
mb_internal_encoding('EUC-JP')  or print("mb_internal_encoding() failed\n");

print  mb_stripos($euc_jp,b'日本語') . "\n";
print  mb_stripos($euc_jp, b'0') . "\n";
print  mb_stripos($euc_jp, 3) . "\n";
print  mb_stripos($euc_jp, 0) . "\n";

$r = mb_stripos($euc_jp,b'韓国語');
($r === FALSE) ? print "OK_STR\n"     : print "NG_STR\n";
$r = mb_stripos($euc_jp,b"\n");
($r === FALSE) ? print "OK_NEWLINE\n" : print "NG_NEWLINE\n";


// Invalid Parameters
echo "== INVALID PARAMETER TEST ==\n";

try { $r = mb_stripos($euc_jp,'','EUC-JP'); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }
($r === FALSE) ? print("OK_NULL\n") : print("NG_NULL\n");
try { $r = mb_stripos($euc_jp, $t_ary, 'EUC-JP'); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }
($r === FALSE) ? print("OK_ARRAY\n") : print("NG_ARRAY\n");
try { $r = mb_stripos($euc_jp, $t_obj, 'EUC-JP'); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }
($r === FALSE) ? print("OK_OBJECT\n") : print("NG_OBJECT\n");
try { $r = mb_stripos($euc_jp, $t_obj, 'BAD_ENCODING'); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }
($r === FALSE) ? print("OK_BAD_ENCODING\n") : print("NG_BAD_ENCODING\n");


?>

