<?php
// Copyright 2004-present Facebook. All Rights Reserved.
// This file is @generated by
// fbcode/hphp/facebook/tools/code_model/Generate.sh

namespace HH\CodeModel {

/**
 *  class {arguments}
 */
class CollectionInitializerExpression
  /*implements ICollectionInitializerExpression*/ {
  use Expression;
  use TypedNode;
  use Node;

  private /*?ITypeExpression*/ $class;
  private /*?Vector<IExpression>*/ $arguments;

  /**
   *  class {arguments}
   */
  public function getClass() /*: ITypeExpression*/ {
    if ($this->class === null) {
      throw new \Exception("Class is not initialized");
    }
    return $this->class;
  }
  /**
   *  class {arguments}
   */
  public function setClass(/*ITypeExpression*/ $value) /*: this*/ {
    $this->class = $value;
    return $this;
  }

  /**
   *  class {arguments}
   */
  public function getArguments() /*: Vector<IExpression>*/ {
    if ($this->arguments === null) {
      $this->arguments = Vector {};
    }
    return $this->arguments;
  }
  /**
   *  class {arguments}
   */
  public function setArguments(/*Vector<IExpression>*/ $value) /*: this*/ {
    $this->arguments = $value;
    return $this;
  }

  /**
   * Returns $visitor->visitCollectionInitializerExpression($this) if
   * such a method exists on $visitor.
   * Otherwise returns $visitor->visitExpression($this) if
   * such a method exists on $visitor.
   * Otherwise returns $visitor->visitNode($this) if
   */
  public function accept(/*mixed*/ $visitor) /*: mixed*/ {
    if (method_exists($visitor, "visitCollectionInitializerExpression")) {
      // UNSAFE
      return $visitor->visitCollectionInitializerExpression($this);
    } else if (method_exists($visitor, "visitExpression")) {
      // UNSAFE
      return $visitor->visitExpression($this);
    } else {
      return $visitor->visitNode($this);
    }
  }

  /**
   * Yields a list of nodes that are children of this node.
   * A node has exactly one parent, so doing a depth
   * first traversal of a node graph using getChildren will
   * traverse a spanning tree.
   */
  public function getChildren() /*: Continuation<INode>*/ {
    if ($this->class !== null) {
      yield $this->class;
    }
    if ($this->arguments !== null) {
      foreach ($this->arguments as $elem) {
        yield $elem;
      }
    }
  }
}
}
