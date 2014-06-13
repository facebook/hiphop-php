<?php

// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.arrayiterator.php )
 *
 * This iterator allows to unset and modify values and keys while
 * iterating over Arrays and Objects.
 *
 * When you want to iterate over the same array multiple times you need to
 * instantiate ArrayObject and let it create ArrayIterator instances that
 * refer to it either by using foreach or by calling its getIterator()
 * method manually.
 *
 */
class ArrayIterator implements ArrayAccess, SeekableIterator, Countable {
  private $storage;
  private $flags;

  const STD_PROP_LIST = 1;
  const ARRAY_AS_PROPS = 2;

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.construct.php )
   *
   * Constructs an ArrayIterator object. Warning: This function is currently
   * not documented; only its argument list is available.
   *
   * @array      mixed   The array or object to be iterated on.
   *
   * @return     mixed   An ArrayIterator object.
   */
  public function __construct($array = array(), $flags = 0) {
    if (($array instanceof ArrayObject) || ($array instanceof ArrayIterator)) {
      $this->storage = $array->getArrayCopy();
    } else if (is_object($array)) {
      $this->storage = get_object_vars($array);
    } else {
      $this->storage = (array) $array;
    }
    $this->flags = $flags;
    reset($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.append.php )
   *
   * Appends value as the last element. Warning: This function is currently
   * not documented; only its argument list is available.
   *
   * @value      mixed   The value to append.
   *
   * @return     mixed   No value is returned.
   */
  public function append($value) {
    $this->storage[] = $value;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.asort.php )
   *
   * Sorts an array by values. Warning: This function is currently not
   * documented; only its argument list is available.
   *
   * @return     mixed   No value is returned.
   */
  public function asort() {
    return asort($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.count.php )
   *
   * Gets the number of elements in the array, or the number of public
   * properties in the object. Warning: This function is currently not
   * documented; only its argument list is available.
   *
   * @return     mixed   The number of elements or public properties in the
   *                     associated array or object, respectively.
   */
  public function count() {
    return count($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.current.php )
   *
   * Get the current array entry.
   *
   * @return     mixed   The current array entry.
   */
  public function current() {
    return current($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.getarraycopy.php )
   *
   * Get a copy of an array. Warning: This function is currently not
   * documented; only its argument list is available.
   *
   * @return     mixed   A copy of the array, or array of public properties
   *                     if ArrayIterator refers to an object.
   */
  public function getArrayCopy() {
    return $this->storage;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.getflags.php )
   *
   * Get the current flags. Warning: This function is currently not
   * documented; only its argument list is available.
   *
   * @return     mixed   The current flags.
   */
  public function getFlags() {
    return $this->flags;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.key.php )
   *
   * This function returns the current array key
   *
   * @return     mixed   The current array key.
   */
  public function key() {
    return key($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.ksort.php )
   *
   * Sorts an array by the keys. Warning: This function is currently not
   * documented; only its argument list is available.
   *
   * @return     mixed   No value is returned.
   */
  public function ksort() {
    return ksort($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.natcasesort.php )
   *
   * Sort the entries by values using a case insensitive "natural order"
   * algorithm. Warning: This function is currently not documented; only its
   * argument list is available.
   *
   * @return     mixed   No value is returned.
   */
  public function natcasesort() {
    return natcasesort($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.natsort.php )
   *
   * Sort the entries by values using "natural order" algorithm. Warning:
   * This function is currently not documented; only its argument list is
   * available.
   *
   * @return     mixed   No value is returned.
   */
  public function natsort() {
    return natsort($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.next.php )
   *
   * The iterator to the next entry.
   *
   * @return     mixed   No value is returned.
   */
  public function next() {
    next($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.offsetexists.php )
   *
   * Checks if the offset exists. Warning: This function is currently not
   * documented; only its argument list is available.
   *
   * @index      mixed   The offset being checked.
   *
   * @return     mixed   TRUE if the offset exists, otherwise FALSE
   */
  public function offsetExists($index) {
    return isset($this->storage[$index]);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.offsetget.php )
   *
   * Gets the value from the provided offset. Warning: This function is
   * currently not documented; only its argument list is available.
   *
   * @index      mixed   The offset to get the value from.
   *
   * @return     mixed   The value at offset index.
   */
  public function offsetGet($index) {
    return $this->storage[$index];
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.offsetset.php )
   *
   * Sets a value for a given offset. Warning: This function is currently
   * not documented; only its argument list is available.
   *
   * @index      mixed   The index to set for.
   * @newval     mixed   The new value to store at the index.
   *
   * @return     mixed   No value is returned.
   */
  public function offsetSet($index, $newval) {
    if ($index === null) {
      $this->storage[] = $newval;
    } else {
      $this->storage[$index] = $newval;
    }
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.offsetunset.php )
   *
   * Unsets a value for an offset. Warning: This function is currently not
   * documented; only its argument list is available.
   *
   * @index      mixed   The offset to unset.
   *
   * @return     mixed   No value is returned.
   */
  public function offsetUnset($index) {
    unset($this->storage[$index]);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.rewind.php )
   *
   * This rewinds the iterator to the beginning.
   *
   * @return     mixed   No value is returned.
   */
  public function rewind() {
    reset($this->storage);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.seek.php )
   *
   *
   * @position   mixed   The position to seek to.
   *
   * @return     mixed   No value is returned.
   */
  public function seek($position) {
    if (func_num_args() !== 1) {
      return;
    }
    if ($position < 0 || $position >= count($this->storage)) {
      throw new OutOfBoundsException(
        "Seek position {$position} is out of range"
      );
    }
    reset($this->storage);
    for ($i = 0; $i < $position; $i++) {
      if (!next($this->storage)) {
        break;
      }
    }
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.setflags.php )
   *
   * Sets behaviour flags. Warning: This function is currently not
   * documented; only its argument list is available.
   *
   * @flags      mixed   A bitmask as follows: 0 = Properties of the object
   *                     have their normal functionality when accessed as
   *                     list (var_dump, foreach, etc.). 1 = Array indices
   *                     can be accessed as properties in read/write.
   *
   * @return     mixed   No value is returned.
   */
  public function setFlags($flags) {
    $this->flags = $flags;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.uasort.php )
   *
   * Sort the entries by values using user defined function. Warning: This
   * function is currently not documented; only its argument list is
   * available.
   *
   * @cmp_function
   *             mixed   The compare function used for the sort.
   *
   * @return     mixed   No value is returned.
   */
  public function uasort($cmp_function) {
    return uasort($this->storage, $cmp_function);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.uksort.php )
   *
   * Sort the entries by key using user defined function. Warning: This
   * function is currently not documented; only its argument list is
   * available.
   *
   * @cmp_function
   *             mixed   The compare function used for the sort.
   *
   * @return     mixed   No value is returned.
   */
  public function uksort($cmp_function) {
    return uksort($this->storage, $cmp_function);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/arrayiterator.valid.php )
   *
   * Checks if the array contains any more entries.
   *
   * @return     mixed   No value is returned.
   */
  public function valid() {
    return key($this->storage) !== null;
  }
}
