<?php
include "connect.inc";

$tmp    = NULL;
$link   = NULL;

if (!is_null($tmp = @mysql_tablename()))
	printf("[001] Expecting NULL, got %s/%s\n", gettype($tmp), $tmp);

if (null !== ($tmp = @mysql_tablename($link)))
	printf("[002] Expecting NULL, got %s/%s\n", gettype($tmp), $tmp);

require('table.inc');
if (!$res = mysql_query("SELECT id, label FROM test ORDER BY id LIMIT 2", $link)) {
	printf("[003] [%d] %s\n", mysql_errno($link), mysql_error($link));
}

if (NULL !== ($tmp = mysql_tablename($res)))
	printf("[004] Expecting NULL, got %s/%s\n", gettype($tmp), $tmp);

if (false !== ($tmp = mysql_tablename($res, -1)))
	printf("[005] Expecting boolean/false, got %s/%s\n", gettype($tmp), $tmp);

var_dump(mysql_tablename($res, 0));

if (false !== ($tmp = mysql_tablename($res, 2)))
	printf("[00%d] Expecting boolean/false, got %s/%s\n", gettype($tmp), $tmp);

mysql_free_result($res);

var_dump(mysql_tablename($res, 0));

mysql_close($link);
print "done!";
?>
