<?hh // partial

namespace {

// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.errorexception.php )
 *
 * An Error Exception.
 *
 */
class ErrorException extends Exception {
  protected $severity;
  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/errorexception.construct.php )
   *
   * Constructs the Exception.
   *
   * @message    mixed   The Exception message to throw.
   * @code       mixed   The Exception code.
   * @severity   mixed   The severity level of the exception.
   * @filename   mixed   The filename where the exception is thrown.
   * @lineno     mixed   The line number where the exception is thrown.
   * @previous   mixed   The previous exception used for the exception
   *                     chaining.
   */
  <<__Pure>>
  public function __construct($message = "", $code = 0, $severity = 0,
                              $filename = null, $lineno = null, <<__MaybeMutable>> Exception $previous = null) {
    parent::__construct($message, $code, $previous);
    $this->severity = $severity;
    if ($filename !== null) {
      $this->file = $filename;
    }
    if ($lineno !== null) {
      $this->line = $lineno;
    }
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/errorexception.getseverity.php )
   *
   * Returns the severity of the exception.
   *
   * @return     mixed   Returns the severity level of the exception.
   */
  <<__Pure, __MaybeMutable>>
  final public function getSeverity() { return $this->severity; }
}

}
