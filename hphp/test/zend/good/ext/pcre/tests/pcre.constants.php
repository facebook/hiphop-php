<?hh
<<__EntryPoint>> function main(): void {
echo "PCRE constants test\n"; 

echo "PREG_PATTERN_ORDER= ", PREG_PATTERN_ORDER, "\n";
echo "PREG_OFFSET_CAPTURE= ", PREG_OFFSET_CAPTURE, "\n";
echo "PREG_SPLIT_NO_EMPTY= ", PREG_SPLIT_NO_EMPTY, "\n"; 
echo "PREG_SPLIT_DELIM_CAPTURE= ", PREG_SPLIT_DELIM_CAPTURE, "\n";
echo "PREG_SPLIT_OFFSET_CAPTURE= ", PREG_SPLIT_OFFSET_CAPTURE, "\n";
echo "PREG_GREP_INVERT= ", PREG_GREP_INVERT, "\n";
echo "PREG_NO_ERROR= ", PREG_NO_ERROR, "\n";
echo "PREG_INTERNAL_ERROR= ", PREG_INTERNAL_ERROR, "\n";
echo "PREG_BACKTRACK_LIMIT_ERROR= ", PREG_BACKTRACK_LIMIT_ERROR, "\n";
echo "PREG_RECURSION_LIMIT_ERROR= ", PREG_RECURSION_LIMIT_ERROR, "\n";
echo "PREG_BAD_UTF8_ERROR= ", PREG_BAD_UTF8_ERROR, "\n";
echo "===Done===";
}
