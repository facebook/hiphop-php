<?hh // partial
// generated by idl-to-hni.php

/** Represents an element in an XML document.
 */
<<__NativeData("SimpleXMLElement")>>
class SimpleXMLElement implements ArrayAccess, Traversable, Countable {

  /** @param string $data
   * @param int $options
   * @param bool $data_is_url
   * @param string $ns
   * @param bool $is_prefix
   */
  <<__Native>>
  public function __construct(string $data,
                              int $options = 0,
                              bool $data_is_url = false,
                              string $ns = "",
                              bool $is_prefix = false): void;

  /** @param mixed $index
   * @return bool
   */
  <<__Native>>
  public function offsetExists(mixed $index): bool;

  /** @param mixed $index
   * @return mixed
   */
  <<__Native>>
  public function offsetGet(mixed $index): mixed;

  /** @param mixed $index
   * @param mixed $newvalue
   */
  <<__Native>>
  public function offsetSet(mixed $index,
                            mixed $newvalue): void;

  /** @param mixed $index
   */
  <<__Native>>
  public function offsetUnset(mixed $index): void;

  /** @return mixed
   */
  public function getIterator(): SimpleXMLElementIterator {
    return new SimpleXMLElementIterator($this);
  }

  /** This method counts the number of children of an element.
   * @return int - Returns the number of elements of an element.
   */
  <<__Native>>
  public function count(): int;

  /** @param string $path - An XPath path
   * @return mixed - Returns an array of SimpleXMLElement objects or FALSE in
   * case of an error.
   */
  <<__Native>>
  public function xpath(string $path): mixed;

  /** @param string $prefix
   * @param string $ns
   * @return bool
   */
  <<__Native>>
  public function registerXPathNamespace(string $prefix,
                                         string $ns): bool;

  /** @param string $filename
   * @return mixed
   */
  <<__Native>>
  public function asXML(string $filename = ""): mixed;

  /** @param string $filename
   * @return mixed
   */
  public function saveXML(string $filename = ""): mixed {
    return $this->asXML($filename);
  }

  /** @param bool $recursive
   * @return array
   */
  <<__Native>>
  public function getNamespaces(bool $recursive = false): darray;

  /** @param bool $recursive
   * @param bool $from_root
   * @return array
   */
  <<__Native>>
  public function getDocNamespaces(bool $recursive = false,
                                   bool $from_root = true): darray;

  /** @param string $ns - An XML namespace.
   * @param bool $is_prefix - If is_prefix is TRUE, ns will be regarded as a
   * prefix. If FALSE, ns will be regarded as a namespace URL.
   * @return object - Returns a SimpleXMLElement element, whether the node has
   * children or not.
   */
  <<__Native>>
  public function children(string $ns = "",
                           bool $is_prefix = false): ?object;

  /** @return string
   */
  <<__Native>>
  public function getName(): string;

  /** @param string $ns - An optional namespace for the retrieved attributes
   * @param bool $is_prefix - Default to FALSE
   * @return object
   */
  <<__Native>>
  public function attributes(string $ns = "",
                             bool $is_prefix = false): object;

  /** @param string $qname
   * @param string $value
   * @param mixed $ns
   * @return mixed
   */
  <<__Native>>
  public function addChild(string $qname,
                           string $value = "",
                           mixed $ns = null): mixed;

  /** @param string $qname
   * @param string $value
   * @param string $ns
   */
  <<__Native>>
  public function addAttribute(string $qname,
                               string $value = "",
                               string $ns = ""): void;

  /** @return string
   */
  <<__Native>>
  public function __toString(): string;

}

<<__NativeData("SimpleXMLElementIterator")>>
class SimpleXMLElementIterator implements Iterator {

  <<__Native>>
  public function __construct(?SimpleXMLElement $sxe = null): void;

  /** @return mixed
   */
  <<__Native>>
  public function current(): mixed;

  /** @return mixed
   */
  <<__Native>>
  public function key(): mixed;

  /** @return mixed
   */
  <<__Native>>
  public function next(): mixed;

  /** @return mixed
   */
  <<__Native>>
  public function rewind(): mixed;

  /** @return mixed
   */
  <<__Native>>
  public function valid(): mixed;
}

<<__NativeData("SimpleXMLIterator")>>
class SimpleXMLIterator extends SimpleXMLElement
                        implements RecursiveIterator {

  /** @return object
   */
  <<__Native>>
  public function getChildren(): ?object;

  /** @return bool
   */
  <<__Native>>
  public function hasChildren(): bool;

  /** @return mixed
   */
  <<__Native>>
  public function current(): mixed;

  /** @return mixed
   */
  <<__Native>>
  public function key(): mixed;

  /** @return mixed
   */
  <<__Native>>
  public function next(): mixed;

  /** @return mixed
   */
  <<__Native>>
  public function rewind(): mixed;

  /** @return mixed
   */
  <<__Native>>
  public function valid(): mixed;

}

/** Takes a well-formed XML string and returns it as an object.
 * @param string $data - A well-formed XML string
 * @param string $class_name - You may use this optional parameter so that
 * simplexml_load_string() will return an object of the specified class. That
 * class should extend the SimpleXMLElement class.
 * @param int $options - Since PHP 5.1.0 and Libxml 2.6.0, you may also use
 * the options parameter to specify additional Libxml parameters.
 * @param string $ns
 * @param bool $is_prefix
 * @return mixed - Returns an object of class SimpleXMLElement with properties
 * containing the data held within the xml document. On errors, it will return
 * FALSE.
 */
<<__Native>>
function simplexml_load_string(string $data,
                               string $class_name = "SimpleXMLElement",
                               int $options = 0,
                               string $ns = "",
                               bool $is_prefix = false): mixed;

/** Convert the well-formed XML document in the given file to an object.
 * @param string $filename - Path to the XML file  Libxml 2 unescapes the URI,
 * so if you want to pass e.g. b&c as the URI parameter a, you have to call
 * simplexml_load_file(rawurlencode('http://example.com/?a=' .
 * urlencode('b&c'))). Since PHP 5.1.0 you don't need to do this because PHP
 * will do it for you.
 * @param string $class_name - You may use this optional parameter so that
 * simplexml_load_file() will return an object of the specified class. That
 * class should extend the SimpleXMLElement class.
 * @param int $options - Since PHP 5.1.0 and Libxml 2.6.0, you may also use
 * the options parameter to specify additional Libxml parameters.
 * @param string $ns
 * @param bool $is_prefix
 * @return mixed - Returns an object of class SimpleXMLElement with properties
 * containing the data held within the XML document. On errors, it will return
 * FALSE.
 */
<<__Native>>
function simplexml_load_file(string $filename,
                             string $class_name = "SimpleXMLElement",
                             int $options = 0,
                             string $ns = "",
                             bool $is_prefix = false): mixed;

/** This function takes a node of a DOM document and makes it into a SimpleXML
 * node. This new object can then be used as a native SimpleXML element.
 * @param object $node - A DOM Element node
 * @param string $class_name - You may use this optional parameter so that
 * simplexml_load_file() will return an object of the specified class. That
 * class should extend the SimpleXMLElement class.
 * @return mixed - Returns a SimpleXMLElement or FALSE on failure.
 */
<<__Native>>
function simplexml_import_dom(object $node,
                              string $class_name = "SimpleXMLElement"): mixed;
