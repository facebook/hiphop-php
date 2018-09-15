<?hh
/**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *
 */

function testmap(): Map<mixed, int> {
  $m = Map{"s" => 1, "t" => 2};
  $m[2] = 100;
  return $m;
}

function testarray(): array<mixed, int> {
  $a = array("s" => 1, "t" => 2);
  $a[2] = 100;
  return $a;
}
