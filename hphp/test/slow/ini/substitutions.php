<?php

<<__EntryPoint>>
function main_substitutions() {
var_dump(ini_get("hhvm.hot_func_count"));
var_dump(ini_get("hhvm.stats.slot_duration"));
var_dump(ini_get("hhvm.server.allowed_exec_cmds"));
var_dump(ini_get("hhvm.env_variables"));
var_dump(ini_get("hhvm.server_variables"));
var_dump(ini_get("hhvm.error_handling.notice_frequency"));
var_dump(ini_get("hhvm.error_handling.warning_frequency"));
var_dump(ini_get("hhvm.enable_xhp"));
var_dump(ini_Get("hhvm.jit_a_size"));
}
