<?hh

const FOO = darray["garbage" => varray[1, 2, 3]];

<<__EntryPoint>>
function main() {
  var_dump(\HH\get_provenance(FOO["garbage"]));
}
