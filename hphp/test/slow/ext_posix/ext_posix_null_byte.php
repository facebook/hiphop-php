<?php


<<__EntryPoint>>
function main_ext_posix_null_byte() {
$file = '/etc/passwd'.chr(0).'asdf';

var_dump(posix_access($file));
var_dump(posix_mkfifo($file, 0644));
var_dump(posix_mknod($file, 0644));
}
