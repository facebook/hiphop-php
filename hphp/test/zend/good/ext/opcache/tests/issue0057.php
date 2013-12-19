<?php

class ZException extends Exception {
}

function dummy($query) {
    try {
        switch ($query) {
            case 1;
            break;
            case 2;
            break;
        default:
            throw new Exception('exception');
        }
    } catch (ZException $e) {
        return NULL;
    }
}

try {
    dummy(0);
} catch (Exception $e) {
    echo $e->getMessage();
}

?>