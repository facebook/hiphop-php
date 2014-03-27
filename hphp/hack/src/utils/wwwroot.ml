(**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the "hack" directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 *)


(**
 * Checks if x is a www directory by looking for ".hhconfig".
 *)
let is_www_directory (path : Path.path) : bool =
   let arcconfig = Path.concat path ".hhconfig" in
   Path.file_exists arcconfig

let assert_www_directory (path : Path.path) : unit =
   if not (Path.file_exists path && Path.is_directory path)
   then begin
     Printf.fprintf stderr "Error: %s is not a directory\n" (Path.string_of_path path);
     flush stderr;
     exit 1
   end;
   if not (is_www_directory path)
   then begin
     Printf.fprintf stderr
"Error: could not find a .hhconfig file in %s \
 or any of its parent directories. \
 Do you have a .hhconfig in your code's root directory?\n"
       (Path.string_of_path path);
     flush stderr;
     exit 1
   end
