<?php

// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from
 * http://php.net/manual/en/class.recursiveregexiterator.php )
 *
 * This recursive iterator can filter another recursive iterator via a
 * regular expression.
 *
 */
class RecursiveRegexIterator extends RegexIterator
  implements RecursiveIterator {

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/recursiveregexiterator.construct.php )
   *
   * Creates a new regular expression iterator.
   *
   * @iterator   mixed   The recursive iterator to apply this regex filter
   *                     to.
   * @regex      mixed   The regular expression to match.
   * @mode       mixed   Operation mode, see RegexIterator::setMode() for a
   *                     list of modes.
   * @flags      mixed   Special flags, see RegexIterator::setFlags() for a
   *                     list of available flags.
   * @preg_flags mixed   The regular expression flags. These flags depend on
   *                     the operation mode parameter:
   *                - RecursiveRegexIterator::ALL_MATCHES: See preg_match_all().
   *                - RecursiveRegexIterator::GET_MATCH: See preg_match().
   *                - RecursiveRegexIterator::MATCH: See preg_match().
   *                - RecursiveRegexIterator::REPLACE: none.
   *                - RecursiveRegexIterator::SPLIT: See preg_split().
   */
  public function __construct(RecursiveIterator $iterator, $regex,
                              $mode = self::MATCH, $flags = 0,
                              $preg_flags = 0) {
    parent::__construct($iterator, $regex, $mode, $flags, $preg_flags);
  }

  public function accept() {
    return $this->hasChildren() || parent::accept();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/recursiveregexiterator.getchildren.php )
   *
   * Returns an iterator for the current iterator entry.
   *
   * @return     mixed   An iterator for the current entry, if it can be
   *                     iterated over by the inner iterator.
   */
  public function getChildren() {
    if (ini_get("hhvm.spl.recursive_regex_iterator.use_parent_flags") {
      return new RecursiveRegexIterator(
        $this->hasChildren() ? $this->getInnerIterator()->getChildren() : null,
        $this->getRegex(),
        $this->getMode(),
        $this->getFlags(),
        $this->getPregFlags()
      );
    } else {
      return new RecursiveRegexIterator(
        $this->hasChildren() ? $this->getInnerIterator()->getChildren() : null,
        $this->getRegex()
      );
    }
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/recursiveregexiterator.haschildren.php )
   *
   * Returns whether an iterator can be obtained for the current entry. This
   * iterator can be obtained via RecursiveRegexIterator::getChildren().
   *
   * @return     mixed   Returns TRUE if an iterator can be obtained for the
   *                     current entry, otherwise returns FALSE.
   */
  public function hasChildren() {
    return $this->getInnerIterator()->hasChildren();
  }
}
