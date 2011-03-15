/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
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

#ifndef PHP_SOAP_XML_H
#define PHP_SOAP_XML_H

#include <util/base.h>
#include <runtime/ext/ext_simplexml_include.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

typedef std::map<std::string, xmlDocPtr> xmlDocMap;
typedef std::map<std::string, xmlNodePtr> xmlNodeMap;

#define get_attribute(node, name) get_attribute_ex(node, name, NULL)
#define get_node(node, name) get_node_ex(node, name, NULL)
#define get_node_recursive(node, name) get_node_recursive_ex(node, name, NULL)
#define get_node_with_attribute(node, name, attr, val) \
  get_node_with_attribute_ex(node, name, NULL, attr, val, NULL)
#define get_node_with_attribute_recursive(node, name, attr, val) \
  get_node_with_attribute_recursive_ex(node, name, NULL, attr, val, NULL)
#define node_is_equal(node, name) node_is_equal_ex(node, name, NULL)
#define attr_is_equal(node, name) attr_is_equal_ex(node, name, NULL)

#define NS_STRING(ns) (ns.empty() ? NULL : BAD_CAST(ns.c_str()))

xmlDocPtr soap_xmlParseFile(const char *filename, bool removeEmptyText);
xmlDocPtr soap_xmlParseMemory(const void *buf, size_t size,
                              bool removeEmptyText);

xmlNsPtr attr_find_ns(xmlAttrPtr node);
xmlNsPtr node_find_ns(xmlNodePtr node);
bool attr_is_equal_ex(xmlAttrPtr node, char *name, char *ns);
bool node_is_equal_ex(xmlNodePtr node, char *name, char *ns);
xmlAttrPtr get_attribute_ex(xmlAttrPtr node,char *name, char *ns);
xmlNodePtr get_node_ex(xmlNodePtr node,char *name, char *ns);
xmlNodePtr get_node_recursive_ex(xmlNodePtr node,char *name, char *ns);
xmlNodePtr get_node_with_attribute_ex
(xmlNodePtr node, char *name, char *name_ns, char *attribute, char *value,
 char *attr_ns);
xmlNodePtr get_node_with_attribute_recursive_ex
(xmlNodePtr node, char *name, char *name_ns, char *attribute, char *value,
 char *attr_ns);
void parse_namespace(const xmlChar *inval, std::string &value,
                     std::string &ns);

#define FOREACHATTRNODE(n,c,i)      FOREACHATTRNODEEX(n,c,NULL,i)
#define FOREACHATTRNODEEX(n,c,ns,i)             \
  do {                                          \
    if (n == NULL) {                            \
      break;                                    \
    }                                           \
    if (c) {                                    \
      i = get_attribute_ex(n,c,ns);             \
    } else {                                    \
      i = n;                                    \
    }                                           \
    if (i != NULL) {                            \
      n = i;

#define FOREACHNODE(n,c,i)      FOREACHNODEEX(n,c,NULL,i)
#define FOREACHNODEEX(n,c,ns,i)                 \
  do {                                          \
    if (n == NULL) {                            \
      break;                                    \
    }                                           \
    if (c!=NULL) {                              \
      i = get_node_ex(n,c,NULL);                \
    } else {                                    \
      i = n;                                    \
    }                                           \
    if (i != NULL) {                            \
      n = i;

#define ENDFOREACH(n)                           \
  }                                             \
} while ((n = n->next));

///////////////////////////////////////////////////////////////////////////////
}

#endif
