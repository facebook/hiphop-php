<?hh //strict

/**
 * Test AKempty promotion if assignment happens inside an expression, not on
 * statement level.
 */
function test(): void {
  $a = array();
  if ($a[] = 'aaa') {

  }
  f($a);
}

function f(int $_): void {}
