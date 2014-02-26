<?php
// Copyright 2004-present Facebook. All Rights Reserved.
// This file is @generated by
// fbcode/hphp/facebook/tools/code_model/Generate.sh

namespace HH\CodeModel {

/**
 *  modifiers [typeAnnotation] expressions;
 */
class ClassVariableStatement /*implements IClassVariableStatement*/ {
  use Statement;
  use Node;

  private /*?Vector<IModifier>*/ $modifiers;
  private /*?ITypeExpression*/ $typeAnnotation;
  private /*?Vector<IExpression>*/ $expressions;

  /**
   *  modifiers [typeAnnotation] expressions;
   */
  public function getModifiers() /*: Vector<IModifier>*/ {
    if ($this->modifiers === null) {
      $this->modifiers = Vector {};
    }
    return $this->modifiers;
  }
  /**
   *  modifiers [typeAnnotation] expressions;
   */
  public function setModifiers(/*Vector<IModifier>*/ $value)
     /*: this*/ {
    $this->modifiers = $value;
    return $this;
  }

  /**
   *  modifiers [typeAnnotation] expressions;
   */
  public function getTypeAnnotation() /*: ?ITypeExpression*/ {
    return $this->typeAnnotation;
  }
  /**
   *  modifiers [typeAnnotation] expressions;
   */
  public function setTypeAnnotation(/*?ITypeExpression*/ $value) /*: this*/ {
    $this->typeAnnotation = $value;
    return $this;
  }

  /**
   *  modifiers [typeAnnotation] expressions;
   */
  public function getExpressions() /*: Vector<IExpression>*/ {
    if ($this->expressions === null) {
      $this->expressions = Vector {};
    }
    return $this->expressions;
  }
  /**
   *  modifiers [typeAnnotation] expressions;
   */
  public function setExpressions(/*Vector<IExpression>*/ $value)
     /*: this*/ {
    $this->expressions = $value;
    return $this;
  }

  /**
   * Returns $visitor->visitClassVariableStatement($this) if
   * such a method exists on $visitor.
   * Otherwise returns $visitor->visitStatement($this) if
   * such a method exists on $visitor.
   * Otherwise returns $visitor->visitNode($this) if
   */
  public function accept(/*mixed*/ $visitor) /*: mixed*/ {
    if (method_exists($visitor, "visitClassVariableStatement")) {
      // UNSAFE
      return $visitor->visitClassVariableStatement($this);
    } else if (method_exists($visitor, "visitStatement")) {
      // UNSAFE
      return $visitor->visitStatement($this);
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
    if ($this->modifiers !== null) {
      foreach ($this->modifiers as $elem) {
        yield $elem;
      }
    }
    if ($this->typeAnnotation !== null) {
      yield $this->typeAnnotation;
    }
    if ($this->expressions !== null) {
      foreach ($this->expressions as $elem) {
        yield $elem;
      }
    }
  }
}
}
