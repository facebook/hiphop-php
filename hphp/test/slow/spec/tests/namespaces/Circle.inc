<?hh

/*
   +-------------------------------------------------------------+
   | Copyright (c) 2014 Facebook, Inc. (http://www.facebook.com) |
   +-------------------------------------------------------------+
*/

namespace Graphics\D2
{

class Circle
{
	private $center;
	private $radius;

	public function __construct($x = 0, $y = 0, $radius = 0)
	{
		$this->center = new Point($x, $y);
		$this->radius = $radius;
	}

	public function __toString()
	{
		return '[' . (string)($this->center) . ':' . (string)($this->radius) . ']';
	}
}

}
