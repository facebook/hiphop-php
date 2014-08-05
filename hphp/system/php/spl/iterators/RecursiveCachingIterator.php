<?php

// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from
 * http://php.net/manual/en/class.recursivecachingiterator.php )
 *
 * ...
 *
 */
class RecursiveCachingIterator
  extends CachingIterator
  implements RecursiveIterator {

  private $hasChildren;
  private $getChildren;

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/recursivecachingiterator.construct.php )
   *
   * Constructs a new RecursiveCachingIterator, which consists of a passed
   * in iterator. Warning: This function is currently not documented; only
   * its argument list is available.
   *
   * @iterator   mixed   The iterator being used.
   * @flags      mixed   The flags. Use CALL_TOSTRING to call
   *                     RecursiveCachingIterator::__toString() for every
   *                     element (the default), and/or CATCH_GET_CHILD to
   *                     catch exceptions when trying to get children.
   *
   * @return     mixed   The RecursiveCachingIterator.
   */
  function __construct(
    \Iterator $iterator,
    $flags = RecursiveCachingIterator::CALL_TOSTRING
  ) {
    if (!($iterator instanceof RecursiveIterator)) {
      throw new InvalidArgumentException(
        __CLASS__ . "::__construct() expects parameter 1 ".
        "to be RecursiveIterator, ".
        gettype($iterator) . " given"
      );
    }
    parent::__construct($iterator, $flags);
  }

  function _fetch($check) {
    $valid = parent::_fetch($check);

    if (!$check || $valid) {
      $iterator = $this->getInnerIterator();
      if ($this->hasChildren = $iterator->hasChildren()) {
        $this->getChildren = new RecursiveCachingIterator(
          $iterator->getChildren(),
          $this->getFlags()
        );
      } else {
        $this->getChildren = NULL;
      }
    }

    return $valid;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/recursivecachingiterator.haschildren.php )
   *
   *
   * @return     mixed   TRUE if the inner iterator has children, otherwise
   *                     FALSE
   */
  function hasChildren() {
    return $this->hasChildren;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/recursivecachingiterator.getchildren.php )
   *
   *
   * @return     mixed   The inner iterator's children, as a
   *                     RecursiveCachingIterator.
   */
  function getChildren() {
    return $this->getChildren;
  }
}
