<?hh
<<__EntryPoint>> function bar() {
	try {
		echo "1\n";
		try {
		} finally {
			try {
			} finally {
			}
			echo "2\n";
		}
	} finally {
		try {
			throw new Exception ("");
		} catch (Exception $ab) {
			echo "3\n";
		} finally {
			try {
			} finally {
				echo "4\n";
				try  {
				} finally {
				}
				echo "5\n";
			}
		}
		echo "6\n";
		try {
		} finally {
			while (1) {
				try {
					echo "7\n";
					break;
				} finally {
					echo "8\n";
				}
				echo "bad";
			}
			echo "9\n";
			while (1) {
				try {
					throw new Exception("");
				} catch(Exception $e) {
					echo "10\n";
					break;
				} finally {
					echo "11\n";
				}
				echo "bak\n";
			}
		}
		echo "12\n";
	}
	echo "13\n";
}
