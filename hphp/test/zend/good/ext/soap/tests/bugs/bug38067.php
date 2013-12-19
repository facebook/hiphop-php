<?php
function Test($param) {
	global $g;
	$g = $param->str;
	return $g;
}

class TestSoapClient extends SoapClient {
  function __construct($wsdl, $opt) {
    parent::__construct($wsdl, $opt);
    $this->server = new SoapServer($wsdl, $opt);
    $this->server->addFunction('Test');
  }

  function __doRequest($request, $location, $action, $version, $one_way = 0) {
    ob_start();
    $this->server->handle($request);
    $response = ob_get_contents();
    ob_end_clean();
    return $response;
  }
}

$client = new TestSoapClient(dirname(__FILE__).'/bug38067.wsdl',
	array('encoding' => 'ISO-8859-1'));
$str = 'test: �';
$res = $client->Test(array('str'=>$str));
echo $str."\n";
echo $res."\n";
echo $g."\n";
?>