<?php


<<__EntryPoint>>
function main_minmax_splat() {
$arr = [2, 3];
var_dump(min(1, ...$arr));
var_dump(max(1, ...$arr));
}
