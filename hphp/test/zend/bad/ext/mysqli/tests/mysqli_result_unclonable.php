<?php
	require_once("connect.inc");

	if (!$link = my_mysqli_connect($host, $user, $passwd, $db, $port, $socket))
		printf("[001] Cannot connect to the server using host=%s, user=%s, passwd=***, dbname=%s, port=%s, socket=%s\n",
			$host, $user, $db, $port, $socket);

	if (!($res = mysqli_query($link, "SELECT 'good' AS morning")))
		printf("[002] [%d] %s\n", mysqli_errno($link), mysqli_error($link));

	$res_clone = clone $res;
	print "done!";
?>