<?hh
/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the MIT license found in the
 *  LICENSE file in the hphp/hsl/ subdirectory of this source tree.
 *
 */

namespace HH\Lib\OS;

use namespace HH\Lib\_Private\_OS;

/** Start a socket connection.
 *
 * See `man 2 connect` for details.
 *
 * @see `socket()`
 * @see `bind()`
 * @see `listen()`
 * @see `accept()`
 */
function connect(FileDescriptor $fd, sockaddr $sa): void {
  _OS\wrap_impl(
    () ==> _OS\connect($fd, _OS\native_sockaddr_from_sockaddr($sa)),
  );
}
