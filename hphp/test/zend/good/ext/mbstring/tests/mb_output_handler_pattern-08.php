<?hh
<<__EntryPoint>>
function main_entry(): void {
  mb_http_output("EUC-JP");
  header("Content-Type: text/plain");
  ob_start();
  ob_start('mb_output_handler');
  echo "テスト";
  ob_end_flush();
  var_dump(bin2hex(ob_get_clean()));
}
