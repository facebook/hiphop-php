<?hh

unset($foo);
$baz = $qux;

unset(
  $foo,
  $bar,
);
$baz = $qux;

unset(
  $foo,
  $bar
);
$baz = $qux;

unset(
  $the_quick_brown_fox_jumped_over_the_lazy_dog,
  $grump_wizards_make_toxic_brew_for_the_evil_queen_and_jack
);
$baz = $qux;

unset(
  $the_quick_brown_fox_jumped_over_the_lazy_dog,
  $grump_wizards_make_toxic_brew_for_the_evil_queen_and_jack,
);
$baz = $qux;
