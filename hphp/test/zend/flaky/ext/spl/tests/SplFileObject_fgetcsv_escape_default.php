<?php
$fp = fopen('SplFileObject__fgetcsv7.csv', 'w+');
fwrite($fp, '"aa\"","bb","\"c"');
fclose($fp);

$fo = new SplFileObject('SplFileObject__fgetcsv7.csv');
var_dump($fo->fgetcsv());
?>
<?php
unlink('SplFileObject__fgetcsv7.csv');
?>