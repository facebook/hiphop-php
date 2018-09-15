<?hh // strict

class FooIsNotBrokenTest extends FooTest {
  <<
    Override
  >>
  public function foo(): int {
    return 5;
  }

  <<
    DataProvider('provideFooEnvironment'),
    ExpectedException('FooIsBrokenException'),
    ExpectedExceptionCode(
      'ErrorCode::FOO_IS_BROKEN_AND_CANNOT_POSSIBLY_BE_FIXED',
    )
  >>
  public function testFoo(FooEnvironment $env) {
    if ($env->isFooBroken()) {
      throw new FooIsBrokenException();
    }
  }
}
