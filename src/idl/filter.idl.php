<?php
/**
 * Automatically generated by running "php schema.php apc".
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
//mixed filter_input ( int $type , string $variable_name [, int $filter = FILTER_DEFAULT [, mixed $options ]] )



DefineConstant( array( 'name'   => "INPUT_GET", 'type'   => Int64,));
DefineConstant( array( 'name'   => "INPUT_POST", 'type'   => Int64,));
DefineConstant( array( 'name'   => "INPUT_COOKIE", 'type'   => Int64,));
DefineConstant( array( 'name'   => "INPUT_SERVER", 'type'   => Int64,));
DefineConstant( array( 'name'   => "INPUT_SESSION", 'type'   => Int64,));
DefineConstant( array( 'name'   => "INPUT_ENV", 'type'   => Int64,));


DefineConstant( array ( 'name' => 'FILTER_VALIDATE_BOOLEAN', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_VALIDATE_EMAIL', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_VALIDATE_FLOAT', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_VALIDATE_INT', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_VALIDATE_IP', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_VALIDATE_REGEXP', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_VALIDATE_URL', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_EMAIL', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_ENCODED', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_MAGIC_QUOTES', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_NUMBER_FLOAT', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_NUMBER_INT', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_SPECIAL_CHARS', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_FULL_SPECIAL_CHARS', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_STRING', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_STRIPPED', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_URL', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_UNSAFE_RAW', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_STRIP_LOW', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_STRIP_HIGH', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_ALLOW_FRACTION', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_ALLOW_THOUSAND', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_ALLOW_SCIENTIFIC', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_NO_ENCODE_QUOTES', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_ENCODE_LOW', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_ENCODE_HIGH', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_ENCODE_AMP', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_NULL_ON_FAILURE', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_ALLOW_OCTAL', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_ALLOW_HEX', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_IPV4', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_IPV6', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_NO_PRIV_RANGE', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_NO_RES_RANGE', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_PATH_REQUIRED', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_QUERY_REQUIRED', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_DEFAULT', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_EMPTY_STRING_NULL', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_HOST_REQUIRED', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_SCHEME_REQUIRED', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FLAG_STRIP_BACKTICK', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_FORCE_ARRAY', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_REQUIRE_ARRAY', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_REQUIRE_SCALAR', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_LAST', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_VALIDATE_ALL', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_VALIDATE_LAST', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_SANITIZE_ALL', 'type' => Int64,));
DefineConstant( array ( 'name' => 'FILTER_CALLBACK', 'type' => Int64,));

/**
DefineConstant( array( 'name'   => "FILTER_VALIDATE_BOOLEAN", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_VALIDATE_EMAIL", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_VALIDATE_FLOAT", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_VALIDATE_INT", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_VALIDATE_IP", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_VALIDATE_REGEXP", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_VALIDATE_URL", 'type'   => Int64,));

DefineConstant( array( 'name'   => "FILTER_SANITIZE_EMAIL", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_ENCODED", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_MAGIC_QUOTES", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_NUMBER_FLOAT", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_NUMBER_INT", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_SPECIAL_CHARS", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_FULL_SPECIAL_CHARS", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_STRING", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_STRIPPED", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_SANITIZE_URL", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_UNSAFE_RAW", 'type'   => Int64,));

DefineConstant( array( 'name'   => "FILTER_FLAG_STRIP_LOW", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_STRIP_HIGH", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_ALLOW_FRACTION", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_ALLOW_THOUSAND", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_ALLOW_SCIENTIFIC", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_NO_ENCODE_QUOTES", 'type'   => Int64,));

DefineConstant( array( 'name'   => "FILTER_FLAG_ENCODE_LOW", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_ENCODE_HIGH", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_ENCODE_AMP", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_NULL_ON_FAILURE", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_ALLOW_OCTAL", 'type'   => Int64,));

DefineConstant( array( 'name'   => "FILTER_FLAG_ALLOW_HEX", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_IPV4", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_IPV6", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_NO_PRIV_RANGE", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_NO_RES_RANGE", 'type'   => Int64,));

DefineConstant( array( 'name'   => "FILTER_FLAG_PATH_REQUIRED", 'type'   => Int64,));
DefineConstant( array( 'name'   => "FILTER_FLAG_QUERY_REQUIRED", 'type'   => Int64,));
*/

DefineFunction(
  array(
    'name'   => "filter_input",
    'desc'   => "Gets a specific external variable by name and optionally filters it",
    'flags'  =>  HasDocComment | AllowIntercept,
    'return' => array(
      'type'   => Variant ,
      'desc'   => "Value of the requested variable on success, FALSE if the filter fails, or NULL if the variable_name variable is not set. If the flag FILTER_NULL_ON_FAILURE is used, it returns FALSE if the variable is not set and NULL if the filter fails. ",
    ),

    'args'   => array(
      array(
        'name'   => "type",
        'type'   => Int64,
        'desc'   => "One of INPUT_GET, INPUT_POST, INPUT_COOKIE, INPUT_SERVER, or INPUT_ENV. ",
      ),

      array(
        'name'   => "variable_name",
        'type'   => String,
        'desc'   => "Name of a variable to get. ",
      ),

      array(
        'name'   => "filter",
        'type'   => Int64,
        'value'  => "0",
        'desc'   => "The ID of the filter to apply. The Types of filters manual page lists the available filters. ",
      ),
      array(
        'name'   => "options",
        'type'   => Variant,
        'value'  => "0",
        'desc'   => "The ID of the filter to apply. The Types of filters manual page lists the available filters. ",
      ),
    ),
    'taint_observer' => array(
      'set_mask'   => "TAINT_BIT_NONE",
      'clear_mask' => "TAINT_BIT_NONE",
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

