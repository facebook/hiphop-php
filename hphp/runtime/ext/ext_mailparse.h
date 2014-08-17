/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2014 Facebook, Inc. (http://www.facebook.com)     |
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

#ifndef incl_HPHP_EXT_MAILPARSE_H_
#define incl_HPHP_EXT_MAILPARSE_H_

#include "hphp/runtime/base/base-includes.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

bool HHVM_FUNCTION(mail,
  const String& to, const String& subject, const String& message,
  const String& additional_headers = null_string,
  const String& additional_parameters = null_string);
int64_t HHVM_FUNCTION(ezmlm_hash, const String& addr);
Resource HHVM_FUNCTION(mailparse_msg_create);
bool HHVM_FUNCTION(mailparse_msg_free, const Resource& mimemail);
Variant HHVM_FUNCTION(mailparse_msg_parse_file, const String& filename);
bool HHVM_FUNCTION(mailparse_msg_parse, const Resource& mimemail,
  const String& data);
Variant HHVM_FUNCTION(mailparse_msg_extract_part_file,
  const Resource& mimemail, const Variant& filename,
  const Variant& callbackfunc = "");
Variant HHVM_FUNCTION(mailparse_msg_extract_whole_part_file,
  const Resource& mimemail, const Variant& filename,
  const Variant& callbackfunc = "");
Variant HHVM_FUNCTION(mailparse_msg_extract_part,
  const Resource& mimemail, const Variant& msgbody,
  const Variant& callbackfunc = "");
Array HHVM_FUNCTION(mailparse_msg_get_part_data,
  const Resource& mimemail);
Variant HHVM_FUNCTION(mailparse_msg_get_part, const Resource& mimemail,
  const String& mimesection);
Array HHVM_FUNCTION(mailparse_msg_get_structure, const Resource& mimemail);
Array HHVM_FUNCTION(mailparse_rfc822_parse_addresses, const String& addresses);
bool HHVM_FUNCTION(mailparse_stream_encode,
  const Resource& sourcefp, const Resource& destfp, const String& encoding);
Variant HHVM_FUNCTION(mailparse_uudecode_all, const Resource& fp);
Variant HHVM_FUNCTION(mailparse_determine_best_xfer_encoding,
  const Resource& fp);

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_MAILPARSE_H_
