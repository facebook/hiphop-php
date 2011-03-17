<?php
/**
 * Automatically generated by running "php schema.php error".
 *
 * You may modify the file, but re-running schema.php against this file will
 * standardize the format without losing your schema changes. It does lose
 * any changes that are not part of schema. Use "note" field to comment on
 * schema itself, and "note" fields are not used in any code generation but
 * only staying within this file.
 */
///////////////////////////////////////////////////////////////////////////////
// Preamble: C++ code inserted at beginning of ext_{name}.h

DefinePreamble(<<<CPP

CPP
);

///////////////////////////////////////////////////////////////////////////////
// Constants
//
// array (
//   'name' => name of the constant
//   'type' => type of the constant
//   'note' => additional note about this constant's schema
// )


///////////////////////////////////////////////////////////////////////////////
// Functions
//
// array (
//   'name'   => name of the function
//   'desc'   => description of the function's purpose
//   'flags'  => attributes of the function, see base.php for possible values
//   'opt'    => optimization callback function's name for compiler
//   'note'   => additional note about this function's schema
//   'return' =>
//      array (
//        'type'  => return type, use Reference for ref return
//        'desc'  => description of the return value
//      )
//   'args'   => arguments
//      array (
//        'name'  => name of the argument
//        'type'  => type of the argument, use Reference for output parameter
//        'value' => default value of the argument
//        'desc'  => description of the argument
//      )
// )

DefineFunction(
  array(
    'name'   => "debug_backtrace",
    'desc'   => "debug_backtrace() generates a PHP backtrace.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => StringVec,
      'desc'   => "Returns an associative array. The possible returned elements are as follows:\n\nPossible returned elements from debug_backtrace() Name Type Description function string The current function name. See also __FUNCTION__. line integer The current line number. See also __LINE__. file string The current file name. See also __FILE__. class string The current class name. See also __CLASS__ object object The current object. type string The current call type. If a method call, \"->\" is returned. If a static method call, \"::\" is returned. If a function call, nothing is returned. args array If inside a function, this lists the functions arguments. If inside an included file, this lists the included file name(s).",
    ),
    'args'   => array(
      array(
        'name'   => "provide_object",
        'type'   => Boolean,
        'value'  => "true",
        'desc'   => "Whether or not to populate the \"object\" index.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "debug_print_backtrace",
    'desc'   => "debug_print_backtrace() prints a PHP backtrace. It prints the function calls, included/required files and eval()ed stuff.\nThis function has no parameters.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
      'desc'   => "No value is returned.",
    ),
  ));

DefineFunction(
  array(
    'name'   => "error_get_last",
    'desc'   => "Gets information about the last error that occurred.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => StringVec,
      'desc'   => "Returns an associative array describing the last error with keys \"type\", \"message\", \"file\" and \"line\". Returns NULL if there hasn't been an error yet.",
    ),
  ));

DefineFunction(
  array(
    'name'   => "error_log",
    'desc'   => "Sends an error message to the web server's error log, a TCP port or to a file.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
      'desc'   => "Returns TRUE on success or FALSE on failure.",
    ),
    'args'   => array(
      array(
        'name'   => "message",
        'type'   => String,
        'desc'   => "The error message that should be logged.",
      ),
      array(
        'name'   => "message_type",
        'type'   => Int32,
        'value'  => "0",
        'desc'   => "Says where the error should go. The possible message types are as follows:\n\nerror_log() log types 0 message is sent to PHP's system logger, using the Operating System's system logging mechanism or a file, depending on what the error_log configuration directive is set to. This is the default option. 1 message is sent by email to the address in the destination parameter. This is the only message type where the fourth parameter, extra_headers is used. 2 No longer an option. 3 message is appended to the file destination. A newline is not automatically added to the end of the message string. 4 message is sent directly to the SAPI logging handler.",
      ),
      array(
        'name'   => "destination",
        'type'   => String,
        'value'  => "null_string",
        'desc'   => "The destination. Its meaning depends on the message_type parameter as described above.",
      ),
      array(
        'name'   => "extra_headers",
        'type'   => String,
        'value'  => "null_string",
        'desc'   => "The extra headers. It's used when the message_type parameter is set to 1. This message type uses the same internal function as mail() does.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "error_reporting",
    'desc'   => "The error_reporting() function sets the error_reporting directive at runtime. PHP has many levels of errors, using this function sets that level for the duration (runtime) of your script. If the optional level is not set, error_reporting() will just return the current error reporting level.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Int32,
      'desc'   => "Returns the old error_reporting level or the current level if no level parameter is given.",
    ),
    'args'   => array(
      array(
        'name'   => "level",
        'type'   => Variant,
        'value'  => "null",
        'desc'   => "The new error_reporting level. It takes on either a bitmask, or named constants. Using named constants is strongly encouraged to ensure compatibility for future versions. As error levels are added, the range of integers increases, so older integer-based error levels will not always behave as expected.\n\nThe available error level constants and the actual meanings of these error levels are described in the predefined constants.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "restore_error_handler",
    'desc'   => "Used after changing the error handler function using set_error_handler(), to revert to the previous error handler (which could be the built-in or a user defined function).",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
      'desc'   => "This function always returns TRUE.",
    ),
  ));

DefineFunction(
  array(
    'name'   => "restore_exception_handler",
    'desc'   => "Used after changing the exception handler function using set_exception_handler(), to revert to the previous exception handler (which could be the built-in or a user defined function).",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
      'desc'   => "This function always returns TRUE.",
    ),
  ));

DefineFunction(
  array(
    'name'   => "set_error_handler",
    'desc'   => "Sets a user function (error_handler) to handle errors in a script.\n\nThis function can be used for defining your own way of handling errors during runtime, for example in applications in which you need to do cleanup of data/files when a critical error happens, or when you need to trigger an error under certain conditions (using trigger_error()).\n\nIt is important to remember that the standard PHP error handler is completely bypassed for the error types specified by error_types unless the callback function returns FALSE. error_reporting() settings will have no effect and your error handler will be called regardless - however you are still able to read the current value of error_reporting and act appropriately. Of particular note is that this value will be 0 if the statement that caused the error was prepended by the @ error-control operator.\n\nAlso note that it is your responsibility to die() if necessary. If the error-handler function returns, script execution will continue with the next statement after the one that caused an error.\n\nThe following error types cannot be handled with a user defined function: E_ERROR, E_PARSE, E_CORE_ERROR, E_CORE_WARNING, E_COMPILE_ERROR, E_COMPILE_WARNING, and most of E_STRICT raised in the file where set_error_handler() is called.\n\nIf errors occur before the script is executed (e.g. on file uploads) the custom error handler cannot be called since it is not registered at that time.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
      'desc'   => "Returns a string containing the previously defined error handler (if any). If the built-in error handler is used NULL is returned. NULL is also returned in case of an error such as an invalid callback. If the previous error handler was a class method, this function will return an indexed array with the class and the method name.",
    ),
    'args'   => array(
      array(
        'name'   => "error_handler",
        'type'   => Variant,
        'desc'   => "The user function needs to accept two parameters: the error code, and a string describing the error. Then there are three optional parameters that may be supplied: the filename in which the error occurred, the line number in which the error occurred, and the context in which the error occurred (an array that points to the active symbol table at the point the error occurred). The function can be shown as:\n\nhandler ( int \$errno , string \$errstr [, string \$errfile [, int \$errline [, array \$errcontext ]]] ) errno The first parameter, errno, contains the level of the error raised, as an integer.",
      ),
      array(
        'name'   => "error_types",
        'type'   => Int32,
        'value'  => "k_E_ALL",
        'desc'   => "The second parameter, errstr, contains the error message, as a string.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "set_exception_handler",
    'desc'   => "Sets the default exception handler if an exception is not caught within a try/catch block. Execution will stop after the exception_handler is called.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => String,
      'desc'   => "Returns the name of the previously defined exception handler, or NULL on error. If no previous handler was defined, NULL is also returned.",
    ),
    'args'   => array(
      array(
        'name'   => "exception_handler",
        'type'   => Variant,
        'desc'   => "Name of the function to be called when an uncaught exception occurs. This function must be defined before calling set_exception_handler(). This handler function needs to accept one parameter, which will be the exception object that was thrown.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "hphp_set_error_page",
    'desc'   => "Displays fatal errors with this PHP document. When 500 fatal error is about to display, it will invoke this PHP page with all global states right at when the error happens. This is useful for gracefully displaying something helpful information to end users when a fatal error has happened. Otherwise, a blank page will be displayed by default.",
    'flags'  =>  HasDocComment | HipHopSpecific,
    'return' => array(
      'type'   => null,
    ),
    'args'   => array(
      array(
        'name'   => "page",
        'type'   => String,
        'desc'   => "Relative path of the PHP document.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "hphp_throw_fatal_error",
    'desc'   => "Raises a fatal error.",
    'flags'  =>  HasDocComment | HipHopSpecific,
    'return' => array(
      'type'   => null,
    ),
    'args'   => array(
      array(
        'name'   => "error_msg",
        'type'   => String,
        'desc'   => "The error message for the fatal.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "hphp_clear_unflushed",
    'desc'   => "Clears any output contents that have not been flushed to networked. This is useful when handling a fatal error. Before displaying a customized PHP page, one may call this function to clear previously written content, so to replay what will be displayed.",
    'flags'  =>  HasDocComment | HipHopSpecific,
    'return' => array(
      'type'   => null,
    ),
  ));

DefineFunction(
  array(
    'name'   => "hphp_debug_caller_info",
    'desc'   => "Retrieves information about the caller that invoked the current function or method",
    'flags'  =>  HasDocComment | HipHopSpecific,
    'return' => array(
      'type'   => StringVec,
      'desc'   => "Returns an associative array. On success, the array will contain two keys 'file' and 'line' which indicate the filename and line number of the callsite that invoked the current function or method.",
    ),
  ));

DefineFunction(
  array(
    'name'   => "trigger_error",
    'desc'   => "Used to trigger a user error condition, it can be used by in conjunction with the built-in error handler, or with a user defined function that has been set as the new error handler (set_error_handler()).\n\nThis function is useful when you need to generate a particular response to an exception at runtime.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
      'desc'   => "This function returns FALSE if wrong error_type is specified, TRUE otherwise.",
    ),
    'args'   => array(
      array(
        'name'   => "error_msg",
        'type'   => String,
        'desc'   => "The designated error message for this error. It's limited to 1024 characters in length. Any additional characters beyond 1024 will be truncated.",
      ),
      array(
        'name'   => "error_type",
        'type'   => Int32,
        'value'  => "k_E_USER_NOTICE",
        'desc'   => "The designated error type for this error. It only works with the E_USER family of constants, and will default to E_USER_NOTICE.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "user_error",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
    ),
    'args'   => array(
      array(
        'name'   => "error_msg",
        'type'   => String,
      ),
      array(
        'name'   => "error_type",
        'type'   => Int32,
        'value'  => "k_E_USER_NOTICE",
      ),
    ),
  ));


///////////////////////////////////////////////////////////////////////////////
// Classes
//
// BeginClass
// array (
//   'name'   => name of the class
//   'desc'   => description of the class's purpose
//   'flags'  => attributes of the class, see base.php for possible values
//   'note'   => additional note about this class's schema
//   'parent' => parent class name, if any
//   'ifaces' => array of interfaces tihs class implements
//   'bases'  => extra internal and special base classes this class requires
//   'footer' => extra C++ inserted at end of class declaration
// )
//
// DefineConstant(..)
// DefineConstant(..)
// ...
// DefineFunction(..)
// DefineFunction(..)
// ...
// DefineProperty
// DefineProperty
//
// array (
//   'name'  => name of the property
//   'type'  => type of the property
//   'flags' => attributes of the property
//   'desc'  => description of the property
//   'note'  => additional note about this property's schema
// )
//
// EndClass()

