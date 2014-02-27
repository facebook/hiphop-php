<?php
// Copyright 2004-present Facebook. All Rights Reserved.
// This file is @generated by
// fbcode/hphp/facebook/tools/code_model/Generate.sh

namespace HH\CodeModel {

/**
 *  finally block
 */
class FinallyStatement /*implements IFinallyStatement*/ {
  use Statement;
  use Node;

  private /*?IBlockStatement*/ $block;

  /**
   *  finally block
   */
  public function getBlock() /*: IBlockStatement*/ {
    if ($this->block === null) {
      throw new \Exception("Block is not initialized");
    }
    return $this->block;
  }
  /**
   *  finally block
   */
  public function setBlock(/*IBlockStatement*/ $value) /*: this*/ {
    $this->block = $value;
    return $this;
  }

  /**
   * Returns $visitor->visitFinallyStatement($this) if
   * such a method exists on $visitor.
   * Otherwise returns $visitor->visitStatement($this) if
   * such a method exists on $visitor.
   * Otherwise returns $visitor->visitNode($this) if
   */
  public function accept(/*mixed*/ $visitor) /*: mixed*/ {
    if (method_exists($visitor, "visitFinallyStatement")) {
      // UNSAFE
      return $visitor->visitFinallyStatement($this);
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
    if ($this->block !== null) {
      yield $this->block;
    }
  }
}
}
