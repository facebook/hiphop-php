<?hh

// Test casting a ImmVector to bool.

function main() {
  var_dump((bool) ImmVector {1, 2, 3});
  var_dump((bool) ImmVector {});
}


<<__EntryPoint>>
function main_to_bool() {
main();
}
