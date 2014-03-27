<?hh
/**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the "hack" directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

function do_something(): void {
}

class X {
  private mixed $x;

  public function __construct() {
    $this->x = '';
  }

  public function getX(): int {
    if(is_int($this->x)) {
      return $this->x;
    }
    return 0;
  }
}
