<?php

<<__EntryPoint>>
function main_config_overrides() {
var_dump(ini_get("hhvm.proxy.percentage"));
var_dump(ini_get("hhvm.server.thread_count"));
var_dump(ini_get("hhvm.log.level"));
}
