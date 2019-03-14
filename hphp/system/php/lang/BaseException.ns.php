<?hh // partial
namespace __SystemLib {
// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.exception.php )
 *
 * Exception is the base class for all Exceptions.
 *
 */
trait BaseException {
  require implements \Throwable;

  /**
   * throwable_init() and createAndConstructThrowable() depend on the order
   * of properties below:
   */
  protected string $message = ''; // exception message
  private string $string = '';    // php5 has this, we don't use it
  protected int $code = 0;        // user defined exception code
  protected string $file;         // source filename of exception
  protected int $line;            // source line of exception
  private $trace = varray[];       // full stacktrace
  private ?\Exception $previous = null;
  protected $userMetadata = null;

  /*
   * There is no constructor in this trait-- It should be possible to extend
   * Exception and add a PHP4 constructor, traits play poorly with PHP4
   * constructors.
   */

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.getmessage.php )
   *
   * Returns the Exception message.
   *
   * @return     mixed   Returns the Exception message as a string.
   */
  <<__Rx, __OnlyRxIfImpl(HH\Rx\Exception::class), __MaybeMutable>>
  public function getMessage() {
    return $this->message;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.getprevious.php )
   *
   * Returns previous Exception (the third parameter of
   * Exception::__construct()).
   *
   * @return     mixed   Returns the previous Exception if available or NULL
   *                     otherwise.
   */
  final public function getPrevious() {
    return $this->previous;
  }

  final public function setPrevious(\Throwable $previous) {
    $this->previous = $previous;
  }

  final public function setPreviousChain(\Throwable $previous) {
    $cur = $this;
    $cycle = array();
    $cycle[\spl_object_hash($cur)] = true;
    $next = $cur->getPrevious();
    while ($next is \Throwable &&
      !\array_key_exists(\spl_object_hash($next), $cycle)) {
      $cycle[\spl_object_hash($next)] = true;
      $cur = $next;
      $next = $cur->getPrevious();
    }
    $cur->setPrevious($previous);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.getcode.php )
   *
   * Returns the Exception code.
   *
   * @return     mixed   Returns the exception code as integer in Exception
   *                     but possibly as other type in Exception descendants
   *                     (for example as string in PDOException).
   */
  <<__Rx, __OnlyRxIfImpl(HH\Rx\Exception::class), __MaybeMutable>>
  public function getCode() {
    return $this->code;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.getfile.php )
   *
   * Get the name of the file the exception was created.
   *
   * @return     mixed   Returns the filename in which the exception was
   *                     created.
   */
  <<__Rx, __MaybeMutable>>
  final public function getFile() {
    return $this->file;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.getline.php )
   *
   * Get line number where the exception was created.
   *
   * @return     mixed   Returns the line number where the exception was
   *                     created.
   */
  <<__Rx, __MaybeMutable>>
  final public function getLine() {
    return $this->line;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.gettrace.php )
   *
   * Returns the Exception stack trace.
   *
   * @return     mixed   Returns the Exception stack trace as an array.
   */
  final public function getTrace() {
    if (\is_resource($this->trace)) {
      $this->trace = \__SystemLib\extract_trace($this->trace);
    }
    return $this->trace;
  }

  /**
   * Modifies the exception's trace by prepending the provided trace.
   * Does not modify file, line, etc.
   */
  final protected function __prependTrace(\HH\Container $trace): void {
    $this->trace = varray(
      \array_merge(
        \array_values($trace),
        $this->getTrace(),
      )
    );
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.gettraceasstring.php )
   *
   * Returns the Exception stack trace as a string.
   *
   * @return     mixed   Returns the Exception stack trace as a string.
   */
  final public function getTraceAsString() {
    $i = 0;
    $s = "";
    foreach ($this->getTrace() as $frame) {
      if (!\is_array($frame)) continue;
      $s .= "#$i " .
        (isset($frame['file']) ? $frame['file'] : "") . "(" .
        (isset($frame['line']) ? $frame['line'] : "") . "): " .
        (isset($frame['class']) ? $frame['class'] . $frame['type'] : "") .
        $frame['function'] . "()\n";
      $i++;
    }
    $s .= "#$i {main}";
    return $s;
  }

  /**
   * Set metadata property on this exception
   */
  final public function setUserMetadata(mixed $user_metadata): void {
    $this->userMetadata = $user_metadata;
  }

  /**
   * Get metadata from this exception
   */
  final public function getUserMetadata(): mixed {
    return $this->userMetadata;
  }

  public function __toString() {
    return $this->toString();
  }

  /* Overrideable */
  // formated string for display
  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/exception.tostring.php )
   *
   * Returns the string representation of the exception.
   *
   * @return     mixed   Returns the string representation of the exception.
   */
  public function toString() {
    $res = "";
    $lst = array();
    $ex = $this;
    while ($ex != null && !\array_key_exists(\spl_object_hash($ex), $lst)) {
      $lst[\spl_object_hash($ex)] = $ex;
      $ex = $ex->getPrevious();
    }
    $lst = \array_reverse($lst);
    $first = true;
    foreach ($lst as $ex) {
      if (!$first) {
        $res .= "\n\nNext ";
      }
      $cls = \get_class($ex);
      if (\substr($cls, 0, \strlen("__SystemLib\\")) === "__SystemLib\\") {
        $cls = \substr($cls, \strlen("__SystemLib\\"));
      }
      $res .= $ex is \Error
        ? $cls . ": " . $ex->getMessage()
        : "exception '" . $cls . "' with message '" . $ex->getMessage() .  "'";
      $res .=  " in " . $ex->getFile() . ":" .
        $ex->getLine() . "\nStack trace:\n" . $ex->getTraceAsString();
      $first = false;
    }
    return $res;
  }

  final private function __clone() {
    \trigger_error("Trying to clone an uncloneable object of class " .
                   \get_class($this), \E_USER_ERROR);
  }
}
}
