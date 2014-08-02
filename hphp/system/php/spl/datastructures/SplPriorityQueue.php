<?php

class _SplPriorityQueueHeap extends SplMaxHeap {
  public function compare($a, $b) {
    return parent::compare($a['priority'], $b['priority']);
  }

  public function top() {
    // I know that the parent routes all requests through top()
    // so this is the only method I need to change.
    $result = parent::top();
    if (($this->flags & SplPriorityQueue::EXTR_BOTH) == SplPriorityQueue::EXTR_BOTH) {
      return $result;
    } else if ($this->flags & SplPriorityQueue::EXTR_DATA) {
      return $result['data'];
    } else if ($this->flags & SplPriorityQueue::EXTR_PRIORITY) {
      return $result['priority'];
    }
    // really zend? NULL?
    return null;
  }
}

// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.splpriorityqueue.php )
 *
 * The SplPriorityQueue class provides the main functionalities of an
 * prioritized queue, implemented using a max heap.
 *
 */
class SplPriorityQueue implements \HH\Iterator, Countable {

  const EXTR_DATA = 1;
  const EXTR_PRIORITY = 2;
  const EXTR_BOTH = 3;

  private $flags = self::EXTR_DATA;
  private $heap;

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.construct.php )
   *
   * This constructs a new empty queue.
   *
   * @return     mixed   No value is returned.
   */
  final public function __init__() {
    $this->heap = new _SplPriorityQueueHeap();
    $this->heap->flags = $this->flags;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.compare.php )
   *
   * Compare priority1 with priority2.
   *
   * @priority1  mixed   The priority of the first node being compared.
   * @priority2  mixed   The priority of the second node being compared.
   *
   * @return     mixed   Result of the comparison, positive integer if
   *                     priority1 is greater than priority2, 0 if they are
   *                     equal, negative integer otherwise.
   *
   *                     Multiple elements with the same priority will get
   *                     dequeued in no particular order.
   */
  public function compare($priority1, $priority2) {
    $this->heap->compare(
      array('priority' => $priority1),
      array('priority' => $priority2)
    );
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.extract.php )
   *
   *
   * @return     mixed   The value or priority (or both) of the extracted
   *                     node, depending on the extract flag.
   */
  public function extract() {
    return $this->heap->extract();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.insert.php )
   *
   * Insert value with the priority priority in the queue.
   *
   * @value      mixed   The value to insert.
   * @priority   mixed   The associated priority.
   *
   * @return     mixed   No value is returned.
   */
  public function insert($value, $priority) {
    $data = array('data' => $value, 'priority' => $priority);
    return $this->heap->insert($data);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.isempty.php )
   *
   *
   * @return     mixed   Returns whether the queue is empty.
   */
  public function isEmpty() {
    return $this->heap->isEmpty();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/splpriorityqueue.recoverfromcorruption.php )
   *
   *
   * @return     mixed   No value is returned.
   */
  public function recoverFromCorruption() {
    return $this->heap->recoverFromCorruption();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.count.php )
   *
   *
   * @return     mixed   Returns the number of elements in the queue.
   */
  public function count() {
    return $this->heap->count();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.current.php )
   *
   * Get the current datastructure node.
   *
   * @return     mixed   The value or priority (or both) of the current node,
   *                     depending on the extract flag.
   */
  public function current() {
    return $this->heap->current();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.key.php )
   *
   * This function returns the current node index
   *
   * @return     mixed   The current node index.
   */
  public function key() {
    return $this->heap->key();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.next.php )
   *
   * Extracts the top node from the queue.
   *
   * @return     mixed   No value is returned.
   */
  public function next() {
    return $this->heap->next();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.rewind.php )
   *
   * This rewinds the iterator to the beginning. This is a no-op for heaps
   * as the iterator is virtual and in fact never moves from the top of the
   * heap.
   *
   * @return     mixed   No value is returned.
   */
  public function rewind() {
    return $this->heap->rewind();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.top.php )
   *
   *
   * @return     mixed   The value or priority (or both) of the top node,
   *                     depending on the extract flag.
   */
  public function top() {
    return $this->heap->top();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splpriorityqueue.valid.php )
   *
   * Checks if the queue contains any more nodes.
   *
   * @return     mixed   Returns TRUE if the queue contains any more nodes,
   *                     FALSE otherwise.
   */
  public function valid() {
    return $this->heap->valid();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/splpriorityqueue.setextractflags.php )
   *
   *
   * @flags      mixed   Defines what is extracted by
   *                     SplPriorityQueue::current(), SplPriorityQueue::top()
   *                     and SplPriorityQueue::extract().
   *                     SplPriorityQueue::EXTR_DATA (0x00000001): Extract
   *                     the data SplPriorityQueue::EXTR_PRIORITY
   *                     (0x00000002): Extract the priority
   *                     SplPriorityQueue::EXTR_BOTH (0x00000003): Extract an
   *                     array containing both
   *
   *                     The default mode is SplPriorityQueue::EXTR_DATA.
   *
   * @return     mixed   No value is returned.
   */
  public function setExtractFlags($flags) {
     $this->flags = $flags;
     $this->heap->flags = $flags;
  }

  public function getExtractFlags() {
     return $this->flags;
  }

  public function __clone() {
    $this->heap = clone $this->heap;
  }

}
