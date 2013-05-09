/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_EXT_MCRYPT_H_
#define incl_HPHP_EXT_MCRYPT_H_

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/base/base_includes.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

Variant f_mcrypt_module_open(CStrRef algorithm, CStrRef algorithm_directory, CStrRef mode, CStrRef mode_directory);
bool f_mcrypt_module_close(CObjRef td);
Array f_mcrypt_list_algorithms(CStrRef lib_dir = null_string);
Array f_mcrypt_list_modes(CStrRef lib_dir = null_string);
int64_t f_mcrypt_module_get_algo_block_size(CStrRef algorithm, CStrRef lib_dir = null_string);
int64_t f_mcrypt_module_get_algo_key_size(CStrRef algorithm, CStrRef lib_dir = null_string);
Array f_mcrypt_module_get_supported_key_sizes(CStrRef algorithm, CStrRef lib_dir = null_string);
bool f_mcrypt_module_is_block_algorithm_mode(CStrRef mode, CStrRef lib_dir = null_string);
bool f_mcrypt_module_is_block_algorithm(CStrRef algorithm, CStrRef lib_dir = null_string);
bool f_mcrypt_module_is_block_mode(CStrRef mode, CStrRef lib_dir = null_string);
bool f_mcrypt_module_self_test(CStrRef algorithm, CStrRef lib_dir = null_string);
Variant f_mcrypt_create_iv(int size, int source = 0);
Variant f_mcrypt_encrypt(CStrRef cipher, CStrRef key, CStrRef data, CStrRef mode, CStrRef iv = null_string);
Variant f_mcrypt_decrypt(CStrRef cipher, CStrRef key, CStrRef data, CStrRef mode, CStrRef iv = null_string);
Variant f_mcrypt_cbc(CStrRef cipher, CStrRef key, CStrRef data, int mode, CStrRef iv = null_string);
Variant f_mcrypt_cfb(CStrRef cipher, CStrRef key, CStrRef data, int mode, CStrRef iv = null_string);
Variant f_mcrypt_ecb(CStrRef cipher, CStrRef key, CStrRef data, int mode, CStrRef iv = null_string);
Variant f_mcrypt_ofb(CStrRef cipher, CStrRef key, CStrRef data, int mode, CStrRef iv = null_string);
Variant f_mcrypt_get_block_size(CStrRef cipher, CStrRef module = null_string);
Variant f_mcrypt_get_cipher_name(CStrRef cipher);
Variant f_mcrypt_get_iv_size(CStrRef cipher, CStrRef mode);
int64_t f_mcrypt_get_key_size(CStrRef cipher, CStrRef module);
String f_mcrypt_enc_get_algorithms_name(CObjRef td);
int64_t f_mcrypt_enc_get_block_size(CObjRef td);
int64_t f_mcrypt_enc_get_iv_size(CObjRef td);
int64_t f_mcrypt_enc_get_key_size(CObjRef td);
String f_mcrypt_enc_get_modes_name(CObjRef td);
Array f_mcrypt_enc_get_supported_key_sizes(CObjRef td);
bool f_mcrypt_enc_is_block_algorithm_mode(CObjRef td);
bool f_mcrypt_enc_is_block_algorithm(CObjRef td);
bool f_mcrypt_enc_is_block_mode(CObjRef td);
int64_t f_mcrypt_enc_self_test(CObjRef td);
Variant f_mcrypt_generic(CObjRef td, CStrRef data);
int64_t f_mcrypt_generic_init(CObjRef td, CStrRef key, CStrRef iv);
Variant f_mdecrypt_generic(CObjRef td, CStrRef data);
bool f_mcrypt_generic_deinit(CObjRef td);
bool f_mcrypt_generic_end(CObjRef td);

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_MCRYPT_H_
