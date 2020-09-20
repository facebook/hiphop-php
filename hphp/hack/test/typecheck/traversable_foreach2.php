<?hh // partial
/**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *
 */

/* HH_FIXME[4101] */
function foo2(Traversable $p) {
  foreach ($p as $k => $v) {
    f1($k);
    f2($v);
  }
}

function f1(int $k) {}

function f2(string $v) {}
