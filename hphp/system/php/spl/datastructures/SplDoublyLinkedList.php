<?php

class _SplDoublyLinkedListNode {
  public $data = null;
  public $next = null;
  public $prev = null;
}

// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.spldoublylinkedlist.php )
 *
 * The SplDoublyLinkedList class provides the main functionalities of a
 * doubly linked list.
 *
 */
class SplDoublyLinkedList
  implements \HH\Iterator, ArrayAccess, Countable, Serializable {

  const IT_MODE_LIFO = 2;
  const IT_MODE_FIFO = 0;
  const IT_MODE_DELETE = 1;
  const IT_MODE_KEEP = 0;

  protected $head = null;
  protected $tail = null;
  protected $key = 0;
  protected $current = null;
  protected $count = 0;
  protected $mode = 0;

  public function add($index, $value) {
    if ((!is_int($index) && !is_numeric($index)) ||
        $index < 0 || $index > $this->count()) {
      throw new OutOfRangeException(
        "Offset invalid or out of range"
      );
    }
    if ($index == $this->count()) {
      // End of list, simply push it
      $this->push($value);
    } else {
      $pos = $this->head;
      for ($i = 0; $i < $index; ++$i) {
        // Fetch element to insert before
        $pos = $pos->next;
      }
      $node = new _SplDoublyLinkedListNode;
      $node->data = $value;
      $node->prev = $pos->prev;
      $node->next = $pos;
      if ($node->prev === null) {
        $this->head = $node;
      } else {
        $pos->prev->next = $node;
      }
      $pos->prev = $node;
      ++$this->count;
    }
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.bottom.php )
   *
   *
   * @return     mixed   The value of the first node.
   */
  public function bottom() {
    if ($this->head === null) {
      throw new RuntimeException("Can't shift from an empty datastructure");
    }
    return $this->head->data;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.top.php )
   *
   *
   * @return     mixed   The value of the last node.
   */
  public function top() {
    if ($this->tail === null) {
      throw new RuntimeException("Can't pop from an empty datastructure");
    }
    return $this->tail->data;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.isempty.php
   * )
   *
   *
   * @return     mixed   Returns whether the doubly linked list is empty.
   */
  public function isEmpty() {
    return !$this->count;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.push.php )
   *
   * Pushes value at the end of the doubly linked list.
   *
   * @value      mixed   The value to push.
   *
   * @return     mixed   No value is returned.
   */
  public function push($value) {
    $node = new _SplDoublyLinkedListNode;
    $node->data = $value;

    if ($this->isEmpty()) {
      $this->head = $node;
    } else {
      $node->prev = $this->tail;
      $this->tail->next = $node;
    }
    $this->tail = $node;

    ++$this->count;
    return;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.pop.php )
   *
   *
   * @return     mixed   The value of the popped node.
   */
  public function pop() {
    $retval = $this->top();
    $this->tail = $this->tail->prev;
    --$this->count;
    return $retval;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.unshift.php
   * )
   *
   * Prepends value at the beginning of the doubly linked list.
   *
   * @value      mixed   The value to unshift.
   *
   * @return     mixed   No value is returned.
   */
  public function unshift($value) {
    $node = new _SplDoublyLinkedListNode;
    $node->data = $value;

    if ($this->isEmpty()) {
      $this->head = $this->tail = $node;
    } else {
      $node->next = $this->head;
      $this->head->prev = $node;
      $this->head = $node;
    }

    ++$this->count;
    return;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.shift.php )
   *
   *
   * @return     mixed   The value of the shifted node.
   */
  public function shift() {
    $retval = $this->bottom();
    $this->head = $this->head->next;
    --$this->count;
    return $retval;
  }


  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.current.php
   * )
   *
   * Get the current doubly linked list node.
   *
   * @return     mixed   The current node value.
   */
  public function current() {
    if (!$this->valid()) {
      return null;
    }
    return $this->current->data;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.key.php )
   *
   * This function returns the current node index
   *
   * @return     mixed   The current node index.
   */
  public function key() {
    return $this->key;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.next.php )
   *
   * Move the iterator to the next node.
   *
   * @return     mixed   No value is returned.
   */
  public function next() {
    if ($this->mode & self::IT_MODE_DELETE) {
      --$this->count;
      if ($this->current->prev !== null) {
        $this->current->prev->next = $this->current->next;
      }
      if ($this->current->next !== null) {
        $this->current->next->prev = $this->current->prev;
      }
    }

    if ($this->mode & self::IT_MODE_LIFO) {
      --$this->key;
      $this->current = $this->current ? $this->current->prev : null;
    } else {
      if (!$this->mode & self::IT_MODE_DELETE) {
        ++$this->key;
      }
      $this->current = $this->current ? $this->current->next : null;
    }
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.prev.php )
   *
   * Move the iterator to the previous node.
   *
   * @return     mixed   No value is returned.
   */
  public function prev() {
    if ($this->mode & self::IT_MODE_DELETE) {
      --$this->count;
      if ($this->current->prev !== null) {
        $this->current->prev->next = $this->current->next;
      }
      if ($this->current->next !== null) {
        $this->current->next->prev = $this->current->prev;
      }
    }

    if ($this->mode & self::IT_MODE_LIFO) {
      if (!$this->mode & self::IT_MODE_DELETE) {
        ++$this->key;
      }
      $this->current = $this->current ? $this->current->next : null;
    } else {
      --$this->key;
      $this->current = $this->current ? $this->current->prev : null;
    }
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.rewind.php )
   *
   * This rewinds the iterator to the beginning.
   *
   * @return     mixed   No value is returned.
   */
  public function rewind() {
    if ($this->mode & self::IT_MODE_LIFO) {
      $this->key = $this->count - 1;
      $this->current = $this->tail;
    } else {
      $this->key = 0;
      $this->current = $this->head;
    }
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.valid.php )
   *
   * Checks if the doubly linked list contains any more nodes.
   *
   * @return     mixed   Returns TRUE if the doubly linked list contains any
   *                     more nodes, FALSE otherwise.
   */
  public function valid() {
    return $this->current !== null;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/spldoublylinkedlist.getiteratormode.php )
   *
   *
   * @return     mixed   Returns the different modes and flags that affect
   *                     the iteration.
   */
  public function getIteratorMode() {
    return $this->mode;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/spldoublylinkedlist.setiteratormode.php )
   *
   *
   * @mode       mixed   There are two orthogonal sets of modes that can be
   *                     set: The direction of the iteration (either one or
   *                     the other): SplDoublyLinkedList::IT_MODE_LIFO (Stack
   *                     style) SplDoublyLinkedList::IT_MODE_FIFO (Queue
   *                     style) The behavior of the iterator (either one or
   *                     the other): SplDoublyLinkedList::IT_MODE_DELETE
   *                     (Elements are deleted by the iterator)
   *                     SplDoublyLinkedList::IT_MODE_KEEP (Elements are
   *                     traversed by the iterator)
   *
   *                     The default mode is:
   *                     SplDoublyLinkedList::IT_MODE_FIFO |
   *                     SplDoublyLinkedList::IT_MODE_KEEP
   *
   * @return     mixed   No value is returned.
   */
  public function setIteratorMode($mode) {
    $this->mode = $mode;
  }


  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/spldoublylinkedlist.offsetexists.php )
   *
   *
   * @index      mixed   The index being checked.
   *
   * @return     mixed   TRUE if the requested index exists, otherwise FALSE
   */
  public function offsetExists($index) {
    return $index < $this->count;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/spldoublylinkedlist.offsetget.php )
   *
   *
   * @index      mixed   The index with the value.
   *
   * @return     mixed   The value at the specified index.
   */
  public function offsetGet($index) {
    if (!is_int($index) && !is_numeric($index)) {
      throw new OutOfRangeException("Offset invalid or out of range");
    }
    $node = $this->head;
    for ($i = 0; $i < $index && $node !== null; ++$i) {
      $node = $node->next;
    }
    if (!$node) {
      throw new OutOfRangeException("Offset invalid or out of range");
    }
    return $node->data;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/spldoublylinkedlist.offsetset.php )
   *
   * Sets the value at the specified index to newval.
   *
   * @index      mixed   The index being set.
   * @newval     mixed   The new value for the index.
   *
   * @return     mixed   No value is returned.
   */
  public function offsetSet($index, $newval) {
    if ($index === null) {
      $index = $this->count;
    }
    if ($this->isEmpty()) {
      $node = new _SplDoublyLinkedListNode;
      $this->head = $node;
      $this->tail = $node;
      ++$this->count;
    }
    $node = $this->head;
    for ($i = 0; $i < $index; ++$i) {
      if ($node->next === null) {
        ++$this->count;
        $node->next = new _SplDoublyLinkedListNode;
        $node->next->prev = $node;
        $this->tail = $node->next;
      }
      $node = $node->next;
    }
    $node->data = $newval;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/spldoublylinkedlist.offsetunset.php )
   *
   * Unsets the value at the specified index.
   *
   * @index      mixed   The index being unset.
   *
   * @return     mixed   No value is returned.
   */
  public function offsetUnset($index) {
    if (!is_int($index) && !is_numeric($index)) {
      throw new OutOfRangeException("Offset invalid or out of range");
    }
    $node = $this->head;
    for ($i = 0; $i < $index; ++$i) {
      if (!$node) {
        throw new OutOfRangeException("Offset out of range");
      }
      $node = $node->next;
    }

    if (!$node) {
      throw new OutOfRangeException("Offset out of range");
    }

    --$this->count;
    if ($node->prev) {
      $node->prev->next = $node->next;
    } else {
      $this->head = $node->next;
    }

    if ($node->next) {
      $node->next->prev = $node->prev;
    } else {
      $this->tail = $node->prev;
    }
  }


  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/spldoublylinkedlist.count.php )
   *
   *
   * @return     mixed   Returns the number of elements in the doubly linked
   *                     list.
   */
  public function count() {
    return $this->count;
  }


  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/spldoublylinkedlist.serialize.php )
   *
   * Serializes the storage. WarningThis function is currently not
   * documented; only its argument list is available.
   *
   * @return     mixed   The serialized string.
   */
  public function serialize() {
    $data = array();
    foreach ($this as $val) {
      $data[] = $val;
    }
    return serialize(array($data, $this->mode));
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/spldoublylinkedlist.unserialize.php )
   *
   * Unserializes the storage, from SplDoublyLinkedList::serialize().
   * WarningThis function is currently not documented; only its argument list
   * is available.
   *
   * @serialized mixed   The serialized string.
   *
   * @return     mixed   No value is returned.
   */
  public function unserialize($serialized) {
    list($data, $this->mode) = unserialize($serialized);
    foreach ($data as $elem) {
      $this->push($elem);
    }
  }
}
