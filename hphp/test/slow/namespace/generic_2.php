<?hh


namespace NSTest;

function f<T>(\T $x, bool $b): int {
  echo "namespaces are fun\n";
  return 1;
}
<<__EntryPoint>> function main(): void {
f(1, true);
}
