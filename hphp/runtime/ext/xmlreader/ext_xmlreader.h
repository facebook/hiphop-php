/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2015 Facebook, Inc. (http://www.facebook.com)     |
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

#ifndef incl_HPHP_EXT_XMLREADER_H_
#define incl_HPHP_EXT_XMLREADER_H_

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/base/file.h"
#include "hphp/runtime/base/req-ptr.h"
#include <libxml/tree.h>
#include <libxml/xmlreader.h>
#include <libxml/uri.h>

typedef int (*xmlreader_read_int_t)(xmlTextReaderPtr reader);
typedef unsigned char *(*xmlreader_read_char_t)(xmlTextReaderPtr reader);
typedef const unsigned char *(*xmlreader_read_const_char_t)(xmlTextReaderPtr reader);
typedef unsigned char *(*xmlreader_read_one_char_t)(xmlTextReaderPtr reader, const unsigned char *);
namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

extern const int64_t q_XMLReader$$NONE;
extern const int64_t q_XMLReader$$ELEMENT;
extern const int64_t q_XMLReader$$ATTRIBUTE;
extern const int64_t q_XMLReader$$TEXT;
extern const int64_t q_XMLReader$$CDATA;
extern const int64_t q_XMLReader$$ENTITY_REF;
extern const int64_t q_XMLReader$$ENTITY;
extern const int64_t q_XMLReader$$PI;
extern const int64_t q_XMLReader$$COMMENT;
extern const int64_t q_XMLReader$$DOC;
extern const int64_t q_XMLReader$$DOC_TYPE;
extern const int64_t q_XMLReader$$DOC_FRAGMENT;
extern const int64_t q_XMLReader$$NOTATION;
extern const int64_t q_XMLReader$$WHITESPACE;
extern const int64_t q_XMLReader$$SIGNIFICANT_WHITESPACE;
extern const int64_t q_XMLReader$$END_ELEMENT;
extern const int64_t q_XMLReader$$END_ENTITY;
extern const int64_t q_XMLReader$$XML_DECLARATION;
extern const int64_t q_XMLReader$$LOADDTD;
extern const int64_t q_XMLReader$$DEFAULTATTRS;
extern const int64_t q_XMLReader$$VALIDATE;
extern const int64_t q_XMLReader$$SUBST_ENTITIES;

///////////////////////////////////////////////////////////////////////////////
// class XMLReader

struct XMLReader {
public:
  XMLReader();
  ~XMLReader();
  void close();
  String read_string_func(xmlreader_read_char_t internal_function);
  bool bool_func_no_arg(xmlreader_read_int_t internal_function);
  Variant string_func_string_arg(String value,
                                 xmlreader_read_one_char_t internal_function);
  bool set_relaxng_schema(String source, int type);

  req::ptr<File> m_stream; // input stream
  xmlTextReaderPtr m_ptr;
  xmlParserInputBufferPtr m_input;
  void* m_schema;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_XMLREADER_H_
