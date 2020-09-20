<?hh
/* Prototype  : proto bool feof(resource fp)
 * Description: Test for end-of-file on a file pointer 
 * Source code: ext/standard/file.c
 * Alias to functions: gzeof
 */
<<__EntryPoint>> function main(): void {
echo "*** Testing feof() : basic functionality ***\n";
$tmpFile1 = __SystemLib\hphp_test_tmppath('tmp1');
$h = fopen($tmpFile1, 'wb');
$count = 10;
for ($i = 1; $i <= $count; $i++) {
   fwrite($h, "some data $i\n");
}
fclose($h);

echo "\n*** testing reading complete file using feof to stop ***\n";
$h = fopen($tmpFile1, 'rb');

//feof is not set to true until you try to read past the end of file.
//so fgets will be called even if we are at the end of the file on
//last time to set the eof flag but it will fail to read.
$lastline = "";
while (!feof($h)) {
   $previousLine = $lastline;
   $lastline = fgets($h);
}
echo $previousLine;
var_dump($lastline); // this should be false 
fclose($h);

$tmpFile2 = __SystemLib\hphp_test_tmppath('tmp2');
$h = fopen($tmpFile2, 'wb+');
$count = 10;
echo "*** writing $count lines, testing feof ***\n";
for ($i = 1; $i <=$count; $i++) {
   fwrite($h, "some data $i\n");
   var_dump(feof($h));
}

echo "*** testing feof on unclosed file after a read ***\n";

fread($h, 100);
var_dump(feof($h));

$eofPointer = ftell($h);

echo "*** testing feof after a seek to near the beginning ***\n";
fseek($h, 20, SEEK_SET);
var_dump(feof($h));

echo "*** testing feof after a seek to end ***\n";
fseek($h, $eofPointer, SEEK_SET);
var_dump(feof($h));

echo "*** testing feof after a seek passed the end ***\n";
fseek($h, $eofPointer + 1000, SEEK_SET);
var_dump(feof($h));

echo "*** closing file, testing eof ***\n";
fclose($h);
feof($h);
unlink($tmpFile1);
unlink($tmpFile2);

echo "Done";
}
