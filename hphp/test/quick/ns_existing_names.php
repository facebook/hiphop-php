<?hh

namespace A;
const CO = "a";
function f() { return "a"; }

namespace B;
const CO = "b";
function f() { return "b"; }

use A\f;
use A\CO;
<<__EntryPoint>> function main(): void {
\var_dump(f());
\var_dump(CO);
}
