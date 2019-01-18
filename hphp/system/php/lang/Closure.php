<?hh
// generated by idl-to-hni.php

/* Used as the base class for all closures
 */
<<__NativeData("Closure")>>
class Closure {

  public final function __construct() {
    trigger_error("Can't create a Closure directly", E_ERROR);
  }

  /* @param mixed $name
   * @return mixed
   */
  public final function __get($name) {
    trigger_error("Closure object cannot have properties", E_RECOVERABLE_ERROR);
  }

  /* @param mixed $name
   * @param mixed $value
   * @return mixed
   */
  public final function __set($name, $value) {
    trigger_error("Closure object cannot have properties", E_RECOVERABLE_ERROR);
  }

  /* @param mixed $name
   * @return bool
   */
  public final function __isset($name) {
    trigger_error("Closure object cannot have properties", E_RECOVERABLE_ERROR);
    return false;
  }

  /* @param mixed $name
   * @return mixed
   */
  public final function __unset($name) {
    trigger_error("Closure object cannot have properties", E_RECOVERABLE_ERROR);
  }

  /* @return array
   */
  <<__Native>>
  public final function __debuginfo(): array;

  /* @param Closure $closure
   * @param object $newthis or null
   * @param (object | classname | null) $newscope
   * @return object
   */
  <<__Deprecated('This function is scheduled for removal')>>
  public final static function bind(Closure $closure,
                                    $newthis,
                                    $newscope = "static") {
    return $closure->bindto($newthis, $newscope);
  }

  /* @param object $newthis or null
   * @param (object | classname | null) $newscope
   * @return object
   */
  <<__Native, __Deprecated('This function is scheduled for removal')>>
  public final function bindto(?object $newthis,
                               mixed $newscope = "static"): ?object;

  /* Binds and calls the closure. Temporarily binds the closure to newthis, and
   * calls it with any given parameters.
   * @param mixed $newthis - The object to bind the closure to for the duration
   * of the call.
   * @return mixed - Returns the return value of the closure.
   */
  <<__Native, __Deprecated('This function is scheduled for removal')>>
  public final function call(mixed $newthis,
                             ...$argv): mixed;
}
