<?hh



<<__EntryPoint>>
function main_844() {
$i = 0;
 print ++$i;
 print "\t";
 print (true==true) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==true) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = true;
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == true	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==false) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==false) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = false;
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == false	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==1) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==1) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = 1;
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == 1	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==0) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==0) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = 0;
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == 0	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==-1) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==-1) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = -1;
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == -1	";
 print "\n";
 print ++$i;
 print "\t";
 print (true=='1') ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a =='1') ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = '1';
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == '1'	";
 print "\n";
 print ++$i;
 print "\t";
 print (true=='0') ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a =='0') ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = '0';
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == '0'	";
 print "\n";
 print ++$i;
 print "\t";
 print (true=='-1') ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a =='-1') ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = '-1';
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == '-1'	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==null) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==null) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = null;
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == null	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==__hhvm_intrinsics\dummy_cast_to_kindofarray(vec[])) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==__hhvm_intrinsics\dummy_cast_to_kindofarray(vec[])) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = __hhvm_intrinsics\dummy_cast_to_kindofarray(vec[]);
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array()	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==varray[1]) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==varray[1]) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = varray[1];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array(1)	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==varray[2]) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==varray[2]) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = varray[2];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array(2)	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==varray['1']) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==varray['1']) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = varray['1'];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array('1')	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==darray['0' => '1']) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==darray['0' => '1']) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = darray['0' => '1'];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array('0' => '1')	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==varray['a']) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==varray['a']) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = varray['a'];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array('a')	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==darray['a' => 1]) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==darray['a' => 1]) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = darray['a' => 1];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array('a' => 1)	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==darray['b' => 1]) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==darray['b' => 1]) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = darray['b' => 1];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array('b' => 1)	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==darray['a' => 1, 'b' => 2]) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==darray['a' => 1, 'b' => 2]) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = darray['a' => 1, 'b' => 2];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array('a' => 1, 'b' => 2)	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==varray[darray['a' => 1]]) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==varray[darray['a' => 1]]) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = varray[darray['a' => 1]];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array(array('a' => 1))	";
 print "\n";
 print ++$i;
 print "\t";
 print (true==varray[darray['b' => 1]]) ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a ==varray[darray['b' => 1]]) ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = varray[darray['b' => 1]];
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == array(array('b' => 1))	";
 print "\n";
 print ++$i;
 print "\t";
 print (true=='php') ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a =='php') ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = 'php';
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == 'php'	";
 print "\n";
 print ++$i;
 print "\t";
 print (true=='') ? 'Y' : 'N';
 $a = 1;
 $a = 't';
 $a = true;
 print ($a =='') ? 'Y' : 'N';
 $b = 1;
 $b = 't';
 $b = '';
 print (true==$b) ? 'Y' : 'N';
 print ($a ==$b) ? 'Y' : 'N';
 print "\t";
 print "true == ''	";
 print "\n";
}
