<?php
// Copyright 2004-present Facebook. All Rights Reserved.
// This file is @generated by
// fbcode/hphp/facebook/tools/code_model/Generate.sh

namespace HH\CodeModel {

/**
 *   condition ? valueIfTrue : valueIfFalse
 */
class ConditionalExpression /*implements IConditionalExpression*/ {
  use Expression;
  use TypedNode;
  use Node;

  private /*?IExpression*/ $condition;
  private /*?IExpression*/ $valueIfTrue;
  private /*?IExpression*/ $valueIfFalse;

  /**
   *   condition ? valueIfTrue : valueIfFalse
   */
  public function getCondition() /*: IExpression*/ {
    if ($this->condition === null) {
      throw new \Exception("Condition is not initialized");
    }
    return $this->condition;
  }
  /**
   *   condition ? valueIfTrue : valueIfFalse
   */
  public function setCondition(/*IExpression*/ $value) /*: this*/ {
    $this->condition = $value;
    return $this;
  }

  /**
   *   condition ? valueIfTrue : valueIfFalse
   */
  public function getValueIfTrue() /*: IExpression*/ {
    if ($this->valueIfTrue === null) {
      throw new \Exception("ValueIfTrue is not initialized");
    }
    return $this->valueIfTrue;
  }
  /**
   *   condition ? valueIfTrue : valueIfFalse
   */
  public function setValueIfTrue(/*IExpression*/ $value) /*: this*/ {
    $this->valueIfTrue = $value;
    return $this;
  }

  /**
   *   condition ? valueIfTrue : valueIfFalse
   */
  public function getValueIfFalse() /*: IExpression*/ {
    if ($this->valueIfFalse === null) {
      throw new \Exception("ValueIfFalse is not initialized");
    }
    return $this->valueIfFalse;
  }
  /**
   *   condition ? valueIfTrue : valueIfFalse
   */
  public function setValueIfFalse(/*IExpression*/ $value) /*: this*/ {
    $this->valueIfFalse = $value;
    return $this;
  }

  /**
   * Returns $visitor->visitConditionalExpression($this) if
   * such a method exists on $visitor.
   * Otherwise returns $visitor->visitExpression($this) if
   * such a method exists on $visitor.
   * Otherwise returns $visitor->visitNode($this) if
   */
  public function accept(/*mixed*/ $visitor) /*: mixed*/ {
    if (method_exists($visitor, "visitConditionalExpression")) {
      // UNSAFE
      return $visitor->visitConditionalExpression($this);
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
    if ($this->condition !== null) {
      yield $this->condition;
    }
    if ($this->valueIfTrue !== null) {
      yield $this->valueIfTrue;
    }
    if ($this->valueIfFalse !== null) {
      yield $this->valueIfFalse;
    }
  }
}
}
