<?php

var_dump(metaphone());
var_dump(metaphone(""));
var_dump(metaphone(-1));
var_dump(metaphone(-1, -1));

var_dump(metaphone("valid phrase", -1));
var_dump(metaphone("valid phrase", 0));
var_dump(metaphone("valid phrase", 10000));

$array = array(
"They fell forward, grovelling heedlessly on the cold earth.", 
"But the shadow of horror wheeled and returned, passing lower now, right above them, sweeping the fen-reek with its ghastly wings.",
"And then it was gone, flying back to Mordor with the speed of the wrath of Sauron; and behind it the wind roared away, leaving the Dead Marshes bare and bleak.",
"The naked waste, as far as the eye could pierce, even to the distant menace of the mountains, was dappled with the fitful moonlight."
);

foreach($array as $str) {
	var_dump(metaphone($str));
}

echo "Done\n";
?>