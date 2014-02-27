<?php
	require('connect.inc');
	$test_table_name = 'test_mysqli_class_mysqli_result_interface_table_1'; require('table.inc');

	$mysqli = new my_mysqli($host, $user, $passwd, $db, $port, $socket);
	$mysqli_result = $mysqli->query('SELECT * FROM test_mysqli_class_mysqli_result_interface_table_1');
	$row = $mysqli_result->fetch_row();

	$link = my_mysqli_connect($host, $user, $passwd, $db, $port, $socket);
	$res = mysqli_query($link, 'SELECT * FROM test_mysqli_class_mysqli_result_interface_table_1');
	assert(mysqli_fetch_row($res) === $row);

	printf("Parent class:\n");
	var_dump(get_parent_class($mysqli_result));

	printf("\nMethods:\n");
	$methods = get_class_methods($mysqli_result);
	$expected_methods = array(
		'__construct'           => true,
		'close'                 => true,
		'data_seek'             => true,
		'fetch_array'           => true,
		'fetch_assoc'           => true,
		'fetch_field'           => true,
		'fetch_field_direct'    => true,
		'fetch_fields'          => true,
		'fetch_object'          => true,
		'fetch_row'             => true,
		'field_seek'            => true,
		'free'                  => true,
		'free_result'           => true,
	);
	if ($IS_MYSQLND)
		$expected_methods['fetch_all'] = true;

	foreach ($methods as $k => $method) {
		if (isset($expected_methods[$method])) {
			unset($expected_methods[$method]);
			unset($methods[$k]);
		}
		if ($method == 'mysqli_result') {
			// get_class_method reports different constructor names
			unset($expected_methods['__construct']);
			unset($methods[$k]);
		}
	}

	if (!empty($expected_methods)) {
		printf("Dumping list of missing methods.\n");
		var_dump($expected_methods);
	}
	if (!empty($methods)) {
		printf("Dumping list of unexpected methods.\n");
		var_dump($methods);
	}
	if (empty($expected_methods) && empty($methods))
		printf("ok\n");


	printf("\nClass variables:\n");
	$variables = array_keys(get_class_vars(get_class($mysqli_result)));
	sort($variables);
	foreach ($variables as $k => $var)
		printf("%s\n", $var);

	printf("\nObject variables:\n");
	$variables = array_keys(get_object_vars($mysqli_result));
	foreach ($variables as $k => $var)
		printf("%s\n", $var);

	printf("\nMagic, magic properties:\n");

	assert(($tmp = mysqli_field_tell($res)) === $mysqli_result->current_field);
	printf("mysqli_result->current_field = '%s'/%s ('%s'/%s)\n",
		$mysqli_result->current_field, gettype($mysqli_result->current_field),
		$tmp, gettype($tmp));

	assert(($tmp = mysqli_field_count($link)) === $mysqli_result->field_count);
	printf("mysqli_result->field_count = '%s'/%s ('%s'/%s)\n",
		$mysqli_result->field_count, gettype($mysqli_result->field_count),
		$tmp, gettype($tmp));

	assert(($tmp = mysqli_fetch_lengths($res)) === $mysqli_result->lengths);
	printf("mysqli_result->lengths -> '%s'/%s ('%s'/%s)\n",
		((is_array($mysqli_result->lengths)) ? implode(' ', $mysqli_result->lengths) : 'n/a'),
		gettype($mysqli_result->lengths),
		((is_array($tmp)) ? implode(' ', $tmp) : 'n/a'),
		gettype($tmp));

	assert(($tmp = mysqli_num_rows($res)) === $mysqli_result->num_rows);
	printf("mysqli_result->num_rows = '%s'/%s ('%s'/%s)\n",
		$mysqli_result->num_rows, gettype($mysqli_result->num_rows),
		$tmp, gettype($tmp));

	assert(in_array($mysqli_result->type, array(MYSQLI_STORE_RESULT, MYSQLI_USE_RESULT)));
	printf("mysqli_result->type = '%s'/%s\n",
		((MYSQLI_STORE_RESULT == $mysqli_result->type) ? 'store' : 'use'),
		gettype($mysqli_result->type));

	printf("\nAccess to undefined properties:\n");
	printf("mysqli_result->unknown = '%s'\n", @$mysqli_result->unknown);

	printf("\nConstructor:\n");
	if (!is_object($res = new mysqli_result($link)))
		printf("[001] Expecting object/mysqli_result got %s/%s\n", gettye($res), $res);
	if (!mysqli_query($link, "SELECT id FROM test_mysqli_class_mysqli_result_interface_table_1 ORDER BY id"))
		printf("[003] [%d] %s\n", mysqli_errno($link), mysqli_error($link));

	if (!is_object($res = new mysqli_result($link)))
		printf("[004] [%d] %s\n", mysqli_errno($link), mysqli_error($link));

	if (!is_object($res = new mysqli_result($link, MYSQLI_STORE_RESULT)))
		printf("[005] [%d] %s\n", mysqli_errno($link), mysqli_error($link));

	if (!is_object($res = new mysqli_result($link, MYSQLI_USE_RESULT)))
		printf("[006] [%d] %s\n", mysqli_errno($link), mysqli_error($link));

	if (!is_object($res = new mysqli_result($link, 'invalid')))
		printf("[007] [%d] %s\n", mysqli_errno($link), mysqli_error($link));

	$valid = array(MYSQLI_STORE_RESULT, MYSQLI_USE_RESULT);
	do {
		$mode = mt_rand(-1000, 1000);
	} while (in_array($mode, $valid));

	if ($TEST_EXPERIMENTAL) {
		ob_start();
		if (!is_object($res = new mysqli_result($link, $mode)))
			printf("[008] [%d] %s\n", mysqli_errno($link), mysqli_error($link));
		$content = ob_get_contents();
		ob_end_clean();
		if (!stristr($content, 'Invalid value for resultmode'))
			printf("[009] Expecting warning because of invalid resultmode\n");
	}

	if (!is_object($res = new mysqli_result('foo')))
		printf("[010] [%d] %s\n", mysqli_errno($link), mysqli_error($link));

	if (!is_object($res = @new mysqli_result($link, MYSQLI_STORE_RESULT, 1)))
		printf("[011] [%d] %s\n", mysqli_errno($link), mysqli_error($link));

	print "done!";
?>