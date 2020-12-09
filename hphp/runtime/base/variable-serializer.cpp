/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
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

#include "hphp/runtime/base/variable-serializer.h"

#include "hphp/runtime/base/array-iterator.h"
#include "hphp/runtime/base/backtrace.h"
#include "hphp/runtime/base/collections.h"
#include "hphp/runtime/base/comparisons.h"
#include "hphp/runtime/base/execution-context.h"
#include "hphp/runtime/base/mixed-array-defs.h"
#include "hphp/runtime/base/mixed-array.h"
#include "hphp/runtime/base/packed-array-defs.h"
#include "hphp/runtime/base/runtime-option.h"
#include "hphp/runtime/base/tv-refcount.h"
#include "hphp/runtime/base/type-variant.h"
#include "hphp/runtime/base/utf8-decode.h"
#include "hphp/runtime/base/zend-functions.h"
#include "hphp/runtime/base/zend-printf.h"
#include "hphp/runtime/base/zend-string.h"

#include "hphp/runtime/ext/collections/ext_collections.h"
#include "hphp/runtime/ext/json/JSON_parser.h"
#include "hphp/runtime/ext/json/ext_json.h"
#include "hphp/runtime/ext/std/ext_std_closure.h"

#include "hphp/runtime/vm/native-data.h"
#include "hphp/runtime/vm/class-meth-data-ref.h"

#include "hphp/util/exception.h"
#include "hphp/util/rds-local.h"

#include <cmath>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

const StaticString
  s_serializedNativeDataKey("\0native"),
  s_JsonSerializable("JsonSerializable"),
  s_jsonSerialize("jsonSerialize"),
  s_serialize("serialize"),
  s_zero("\0"),
  s_protected_prefix("\0*\0"),
  s_PHP_DebugDisplay("__PHP_DebugDisplay"),
  s_PHP_Incomplete_Class("__PHP_Incomplete_Class"),
  s_PHP_Incomplete_Class_Name("__PHP_Incomplete_Class_Name"),
  s_debugInfo("__debugInfo"),
  s_message("message");

[[noreturn]] NEVER_INLINE
static void throwNestingException() {
  throw ExtendedException("Nesting level too deep - recursive dependency?");
}

///////////////////////////////////////////////////////////////////////////////

VariableSerializer::SavedRefMap::~SavedRefMap() {
  for (auto& i : m_mapping) {
    tvDecRefGen(const_cast<TypedValue*>(&i.first));
  }
}

VariableSerializer::~VariableSerializer() {
}

VariableSerializer::VariableSerializer(Type type, int option /* = 0 */,
                                       int maxRecur /* = 3 */)
  : m_type(type)
  , m_option(option)
  , m_keepDVArrays{type != Type::Serialize}
  , m_maxCount(maxRecur)
{
  if (type == Type::DebuggerSerialize) {
    m_maxLevelDebugger = g_context->debuggerSettings.printLevel;
  }
}

VariableSerializer::ArrayKind
VariableSerializer::getKind(const ArrayData* arr) const {
  assertx(!RuntimeOption::EvalHackArrDVArrs || arr->isNotDVArray());
  if (UNLIKELY(m_forcePHPArrays)) {
    return VariableSerializer::ArrayKind::PHP;
  } else if (UNLIKELY(m_forceHackArrays)) {
    if (arr->isDArray() || arr->isDictType()) {
      return VariableSerializer::ArrayKind::Dict;
    } else if (arr->isVArray() || arr->isVecType()) {
      return VariableSerializer::ArrayKind::Vec;
    }
    assertx(arr->isKeysetType());
    return VariableSerializer::ArrayKind::Keyset;
  }

  auto const respectsLegacyBit = [&] {
    switch (getType()) {
    case Type::PrintR:
    case Type::VarDump:
    case Type::VarExport:
    case Type::Serialize:
    case Type::JSON:
    case Type::DebuggerDump:
    case Type::DebuggerSerialize:
      return true;
    case Type::Internal:
    case Type::DebugDump:
    case Type::PHPOutput:
    case Type::APCSerialize:
      return false;
    }
    always_assert(false);
  }();

  auto const serializesLegacyBit = getType() == Type::Internal ||
    (getType() == Type::Serialize && m_serializeProvenanceAndLegacy);

  if (serializesLegacyBit && arr->isLegacyArray()) {
    assertx(!arr->isKeysetType());
    if (m_keepDVArrays) {
      if (arr->isDictType() || arr->isDArray()) {
        return VariableSerializer::ArrayKind::MarkedDArray;
      }
      if (arr->isVecType() || arr->isVArray()) {
        return VariableSerializer::ArrayKind::MarkedVArray;
      }
    }
    return VariableSerializer::ArrayKind::MarkedDArray;
  }

  if (RuntimeOption::EvalHackArrDVArrs &&
      respectsLegacyBit &&
      arr->isLegacyArray()) {
    assertx(!arr->isKeysetType());
    if (m_keepDVArrays) {
      if (arr->isVecType()) return VariableSerializer::ArrayKind::VArray;
      if (arr->isDictType()) return VariableSerializer::ArrayKind::DArray;
    }
    return VariableSerializer::ArrayKind::PHP;
  }

  if (arr->isDictType()) return VariableSerializer::ArrayKind::Dict;
  if (arr->isVecType()) return VariableSerializer::ArrayKind::Vec;
  if (arr->isKeysetType())   return VariableSerializer::ArrayKind::Keyset;
  assertx(arr->isPHPArrayType());
  if (m_keepDVArrays) {
    if (arr->isVArray()) return VariableSerializer::ArrayKind::VArray;
    if (arr->isDArray()) return VariableSerializer::ArrayKind::DArray;
  }
  return VariableSerializer::ArrayKind::PHP;
}

void VariableSerializer::pushObjectInfo(const String& objClass, char objCode) {
  assertx(objCode == 'O' || objCode == 'V' || objCode == 'K');
  m_objectInfos.emplace_back(
    ObjectInfo { m_objClass, m_objCode, m_rsrcName, m_rsrcId }
  );
  m_objClass = objClass;
  m_objCode = objCode;
  m_rsrcName.reset();
  m_rsrcId = 0;
}

void VariableSerializer::pushResourceInfo(const String& rsrcName, int rsrcId) {
  m_objectInfos.emplace_back(
    ObjectInfo { m_objClass, m_objCode, m_rsrcName, m_rsrcId }
  );
  m_objClass.reset();
  m_objCode = 0;
  m_rsrcName = rsrcName;
  m_rsrcId = rsrcId;
}

void VariableSerializer::popObjectInfo() {
  ObjectInfo &info = m_objectInfos.back();
  m_objClass = info.objClass;
  m_objCode = info.objCode;
  m_rsrcName = info.rsrcName;
  m_rsrcId = info.rsrcId;
  m_objectInfos.pop_back();
}

RDS_LOCAL(VariableSerializer::SerializationLimitWrapper,
    VariableSerializer::serializationSizeLimit);

void VariableSerializer::popResourceInfo() {
  popObjectInfo();
}

String VariableSerializer::serialize(const_variant_ref v, bool ret,
                                     bool keepCount /* = false */) {
  StringBuffer buf;
  m_buf = &buf;
  if (ret) {
    buf.setOutputLimit(serializationSizeLimit->value);
  } else {
    buf.setOutputLimit(StringData::MaxSize);
  }
  m_valueCount = keepCount ? m_valueCount + 1 : 1;
  write(v);
  if (ret) {
    return m_buf->detach();
  } else {
    String str = m_buf->detach();
    g_context->write(str);
  }
  return String();
}

String VariableSerializer::serializeValue(const Variant& v, bool limit) {
  StringBuffer buf;
  m_buf = &buf;
  if (limit) {
    buf.setOutputLimit(serializationSizeLimit->value);
  }
  m_valueCount = 1;
  write(v);
  return m_buf->detach();
}

String VariableSerializer::serializeWithLimit(const Variant& v, int limit) {
  if (m_type == Type::Serialize || m_type == Type::Internal ||
      m_type == Type::JSON || m_type == Type::APCSerialize ||
      m_type == Type::DebuggerSerialize) {
    assertx(false);
    return String();
  }
  StringBuffer buf;
  m_buf = &buf;
  if (serializationSizeLimit->value > 0 &&
      (limit <= 0 || limit > serializationSizeLimit->value)) {
    limit = serializationSizeLimit->value;
  }
  buf.setOutputLimit(limit);
  //Does not need m_valueCount, which is only useful with the unsupported types
  try {
    write(v);
  } catch (StringBufferLimitException& e) {
    return e.m_result;
  }
  return m_buf->detach();
}

///////////////////////////////////////////////////////////////////////////////

void VariableSerializer::write(bool v) {
  switch (m_type) {
  case Type::PrintR:
    if (v) m_buf->append(1);
    break;
  case Type::VarExport:
  case Type::PHPOutput:
  case Type::JSON:
  case Type::DebuggerDump:
    m_buf->append(v ? "true" : "false");
    break;
  case Type::VarDump:
  case Type::DebugDump:
    indent();
    m_buf->append(v ? "bool(true)" : "bool(false)");
    writeRefCount();
    m_buf->append('\n');
    break;
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
  case Type::DebuggerSerialize:
    m_buf->append(v ? "b:1;" : "b:0;");
    break;
  default:
    assertx(false);
    break;
  }
}

void VariableSerializer::write(int64_t v) {
  switch (m_type) {
  case Type::PrintR:
  case Type::VarExport:
  case Type::PHPOutput:
  case Type::JSON:
  case Type::DebuggerDump:
    m_buf->append(v);
    break;
  case Type::VarDump:
    indent();
    m_buf->append("int(");
    m_buf->append(v);
    m_buf->append(")\n");
    break;
  case Type::DebugDump:
    indent();
    m_buf->append("long(");
    m_buf->append(v);
    m_buf->append(')');
    writeRefCount();
    m_buf->append('\n');
    break;
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
  case Type::DebuggerSerialize:
    m_buf->append("i:");
    m_buf->append(v);
    m_buf->append(';');
    break;
  default:
    assertx(false);
    break;
  }
}

void VariableSerializer::write(double v) {
  auto const precision = 14;
  auto const serde_precision = 17;

  switch (m_type) {
  case Type::JSON:
    if (!std::isinf(v) && !std::isnan(v)) {
      char *buf;
      vspprintf(&buf, 0, "%.*k", precision, v);
      m_buf->append(buf);
      if (m_option & k_JSON_PRESERVE_ZERO_FRACTION
          && strchr(buf, '.') == nullptr) {
        m_buf->append(".0");
      }
      free(buf);
    } else {
      json_set_last_error_code(json_error_codes::JSON_ERROR_INF_OR_NAN);

      m_buf->append('0');
    }
    break;
  case Type::VarExport:
  case Type::PHPOutput:
  case Type::PrintR:
  case Type::DebuggerDump:
    {
      char *buf;
      bool isExport = m_type == Type::VarExport || m_type == Type::PHPOutput;
      vspprintf(&buf, 0, isExport ? "%.*H" : "%.*G", precision, v);
      m_buf->append(buf);
      // In PHPOutput mode, we always want doubles to parse as
      // doubles, so make sure there's a decimal point.
      if (m_type == Type::PHPOutput && strpbrk(buf, ".E") == nullptr) {
        m_buf->append(".0");
      }
      free(buf);
    }
    break;
  case Type::VarDump:
  case Type::DebugDump:
    {
      char *buf;
      vspprintf(&buf, 0, "float(%.*G)", precision, v);
      indent();
      m_buf->append(buf);
      free(buf);
      writeRefCount();
      m_buf->append('\n');
    }
    break;
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
  case Type::DebuggerSerialize:
    m_buf->append("d:");
    if (std::isnan(v)) {
      m_buf->append("NAN");
    } else if (std::isinf(v)) {
      if (v < 0) m_buf->append('-');
      m_buf->append("INF");
    } else {
      char *buf;
      vspprintf(&buf, 0, "%.*H", serde_precision, v);
      m_buf->append(buf);
      free(buf);
    }
    m_buf->append(';');
    break;
  default:
    assertx(false);
    break;
  }
}

uint16_t reverse16(uint16_t us) {
  return
    ((us & 0xf) << 12)       | (((us >> 4) & 0xf) << 8) |
    (((us >> 8) & 0xf) << 4) | ((us >> 12) & 0xf);
}

// Potentially need to escape all control characters (< 32) and also "\/<>&'@%
static const bool jsonNoEscape[128] = {
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,
  true,  true,  false, true,  true,  false, false, false,
  true,  true,  true,  true,  true,  true,  true,  false,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  false, true,  false, true,
  false, true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  false, true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
  true,  true,  true,  true,  true,  true,  true,  true,
};

static void appendJsonEscape(StringBuffer& sb,
                             const char *s,
                             int len,
                             int options) {
  if (len == 0) {
    sb.append("\"\"", 2);
    return;
  }

  static const char digits[] = "0123456789abcdef";

  auto const start = sb.size();
  sb.append('"');

  // Do a fast path for ASCII characters that don't need escaping
  int pos = 0;
  do {
    int c = s[pos];
    if (UNLIKELY((unsigned char)c >= 128 || !jsonNoEscape[c])) {
      goto utf8_decode;
    }
    sb.append((char)c);
    pos++;
  } while (pos < len);
  sb.append('"');
  return;

utf8_decode:
  UTF8To16Decoder decoder(s + pos, len - pos, options & k_JSON_FB_LOOSE);
  for (;;) {
    int c = options & k_JSON_UNESCAPED_UNICODE ? decoder.decodeAsUTF8()
                                               : decoder.decode();
    if (c == UTF8_END) {
      sb.append('"');
      break;
    }
    if (c == UTF8_ERROR) {
      json_set_last_error_code(json_error_codes::JSON_ERROR_UTF8);
      // discard the part that has been already decoded.
      sb.resize(start);
      sb.append("null", 4);
      break;
    }
    assertx(c >= 0);
    unsigned short us = (unsigned short)c;
    switch (us) {
    case '"':
      if (options & k_JSON_HEX_QUOT) {
        sb.append("\\u0022", 6);
      } else {
        sb.append("\\\"", 2);
      }
      break;
    case '\\': sb.append("\\\\", 2); break;
    case '/':
      if (options & k_JSON_UNESCAPED_SLASHES) {
        sb.append('/');
      } else {
        sb.append("\\/", 2);
      }
      break;
    case '\b': sb.append("\\b", 2);  break;
    case '\f': sb.append("\\f", 2);  break;
    case '\n': sb.append("\\n", 2);  break;
    case '\r': sb.append("\\r", 2);  break;
    case '\t': sb.append("\\t", 2);  break;
    case '<':
      if (options & k_JSON_HEX_TAG || options & k_JSON_FB_EXTRA_ESCAPES) {
        sb.append("\\u003C", 6);
      } else {
        sb.append('<');
      }
      break;
    case '>':
      if (options & k_JSON_HEX_TAG) {
        sb.append("\\u003E", 6);
      } else {
        sb.append('>');
      }
      break;
    case '&':
      if (options & k_JSON_HEX_AMP) {
        sb.append("\\u0026", 6);
      } else {
        sb.append('&');
      }
      break;
    case '\'':
      if (options & k_JSON_HEX_APOS) {
        sb.append("\\u0027", 6);
      } else {
        sb.append('\'');
      }
      break;
    case '@':
      if (options & k_JSON_FB_EXTRA_ESCAPES) {
        sb.append("\\u0040", 6);
      } else {
        sb.append('@');
      }
      break;
    case '%':
      if (options & k_JSON_FB_EXTRA_ESCAPES) {
        sb.append("\\u0025", 6);
      } else {
        sb.append('%');
      }
      break;
    default:
      if (us >= ' ' &&
          ((options & k_JSON_UNESCAPED_UNICODE) || (us & 127) == us)) {
        sb.append((char)us);
      } else {
        sb.append("\\u", 2);
        us = reverse16(us);
        sb.append(digits[us & ((1 << 4) - 1)]); us >>= 4;
        sb.append(digits[us & ((1 << 4) - 1)]); us >>= 4;
        sb.append(digits[us & ((1 << 4) - 1)]); us >>= 4;
        sb.append(digits[us & ((1 << 4) - 1)]);
      }
      break;
    }
  }
}

void VariableSerializer::write(const char *v, int len /* = -1 */,
                               bool isArrayKey /* = false */,
                               bool noQuotes /* = false */) {
  if (v == nullptr) v = "";
  if (len < 0) len = strlen(v);

  switch (m_type) {
  case Type::PrintR: {
    m_buf->append(v, len);
    break;
  }
  case Type::VarExport: {
    m_buf->append('\'');
    const char *p = v;
    for (int i = 0; i < len; i++, p++) {
      const char c = *p;
      // adapted from Zend php_var_export and php_addcslashes
      if (c == '\0') {
        m_buf->append("' . \"\\0\" . '");
        continue;
      } else if (c == '\'' || c == '\\') {
        m_buf->append('\\');
      }
      m_buf->append(c);
    }
    m_buf->append('\'');
    break;
  }
  case Type::VarDump:
  case Type::DebugDump: {
    indent();
    m_buf->append("string(");
    m_buf->append(len);
    m_buf->append(") \"");
    m_buf->append(v, len);
    m_buf->append('"');
    writeRefCount();
    m_buf->append('\n');
    break;
  }
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
  case Type::DebuggerSerialize:
    m_buf->append("s:");
    m_buf->append(len);
    m_buf->append(":\"");
    m_buf->append(v, len);
    m_buf->append("\";");
    break;
  case Type::JSON: {
    if ((m_option & k_JSON_NUMERIC_CHECK) && !isArrayKey) {
      int64_t lval; double dval;
      auto dt = is_numeric_string(v, len, &lval, &dval, 0);
      if (isIntType(dt)) {
        write(lval);
        return;
      } else if (isDoubleType(dt)) {
        write(dval);
        return;
      }
    }
    appendJsonEscape(*m_buf, v, len, m_option);
    break;
  }
  case Type::DebuggerDump:
  case Type::PHPOutput: {
    if (!noQuotes)
      m_buf->append('"');
    for (int i = 0; i < len; ++i) {
      const unsigned char c = v[i];
      switch (c) {
        case '\n': m_buf->append("\\n"); break;
        case '\r': m_buf->append("\\r"); break;
        case '\t': m_buf->append("\\t"); break;
        case '\\': m_buf->append("\\\\"); break;
        case '$':  m_buf->append("\\$"); break;
        case '"':  m_buf->append("\\\""); break;
        default: {
          if (c >= ' ' && c <= '~') {
            // The range [' ', '~'] contains only printable characters
            // and we've already handled special cases above
            m_buf->append(c);
          } else {
            char buf[5];
            snprintf(buf, sizeof(buf), "\\%03o", c);
            m_buf->append(buf);
          }
        }
      }
    }
    if (!noQuotes)
      m_buf->append('"');
    break;
  }
  default:
    assertx(false);
    break;
  }
}

void VariableSerializer::write(const String& v) {
  if (m_type == Type::APCSerialize &&
      !(m_option & kAPC_PRIME_SERIALIZE) &&
      !v.isNull() &&
      v.get()->isStatic()) {
    union {
      char buf[8];
      StringData *sd;
    } u;
    u.sd = v.get();
    m_buf->append("S:");
    m_buf->append(u.buf, 8);
    m_buf->append(';');
  } else {
    serializeString(v);
  }
}

void VariableSerializer::write(const Object& v) {
  if (!v.isNull() && m_type == Type::JSON) {

    if (v.instanceof(s_JsonSerializable)) {
      assertx(!v->isCollection());
      Variant ret = v->o_invoke_few_args(s_jsonSerialize, 0);
      // for non objects or when $this is not returned
      if (!ret.isObject() || ret.getObjectData() != v.get()) {
        if (ret.isArray() || ret.isObject()) {
          preventOverflow(v, [&ret, this]() {
            write(ret);
          });
        } else {
          // Don't need to check for overflows if ret is of primitive type
          // because the depth does not change.
          write(ret);
        }
        return;
      }
    }
    preventOverflow(v, [&v, this]() {
      if (v->isCollection()) {
        serializeCollection(v.get());
      } else if (v->instanceof(c_Closure::classof())) {
        m_buf->append("null");
        json_set_last_error_code(
          json_error_codes::JSON_ERROR_UNSUPPORTED_TYPE);
        return;
      } else {
        auto props = v->toArray(true, m_ignoreLateInit);
        pushObjectInfo(v->getClassName(), 'O');
        serializeObjProps(props);
        popObjectInfo();
      }
    });
  } else {
    serializeObject(v);
  }
}

void VariableSerializer::preventOverflow(const Object& v,
                                         const std::function<void()>& func) {
  TypedValue tv = make_tv<KindOfObject>(const_cast<ObjectData*>(v.get()));
  if (incNestedLevel(&tv)) {
    writeOverflow(&tv);
  } else {
    func();
  }
  decNestedLevel(&tv);
}

void VariableSerializer::write(const_variant_ref v, bool isArrayKey) {
  if (m_type == Type::DebugDump) {
    setRefCount(v.getRefCount());
  }
  if (!isArrayKey && v.isObject()) {
    write(v.toObject());
    return;
  }
  serializeVariant(v.rval(), isArrayKey);
}

void VariableSerializer::writeNull() {
  switch (m_type) {
  case Type::PrintR:
    // do nothing
    break;
  case Type::VarExport:
  case Type::PHPOutput:
    m_buf->append("NULL");
    break;
  case Type::VarDump:
  case Type::DebugDump:
    indent();
    m_buf->append("NULL");
    writeRefCount();
    m_buf->append('\n');
    break;
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
  case Type::DebuggerSerialize:
    m_buf->append("N;");
    break;
  case Type::JSON:
  case Type::DebuggerDump:
    m_buf->append("null");
    break;
  default:
    assertx(false);
    break;
  }
}

void VariableSerializer::writeOverflow(tv_rval tv) {
  switch (m_type) {
  case Type::PrintR:
    if (!m_objClass.empty()) {
      m_buf->append(m_objClass);
      m_buf->append(" Object\n");
    } else {
      m_buf->append("Array\n");
    }
    m_buf->append(" *RECURSION*");
    break;
  case Type::VarExport:
  case Type::PHPOutput:
    throwNestingException();
  case Type::VarDump:
  case Type::DebugDump:
  case Type::DebuggerDump:
    indent();
    m_buf->append("*RECURSION*\n");
    break;
  case Type::DebuggerSerialize:
    if (m_maxLevelDebugger > 0 && m_levelDebugger > m_maxLevelDebugger) {
      // Not recursion, just cut short of print
      m_buf->append("s:12:\"...(omitted)\";", 20);
      break;
    }
    // fall through
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
    {
      int optId = m_refs[tv].m_id;
      assertx(optId != NO_ID);
      bool isObject = tvIsResource(tv) || tvIsObject(tv);
      if (isObject) {
        m_buf->append("r:");
        m_buf->append(optId);
        m_buf->append(';');
      } else {
        m_buf->append("N;");
      }
    }
    break;
  case Type::JSON:
    json_set_last_error_code(json_error_codes::JSON_ERROR_RECURSION);
    m_buf->append("null");
    break;
  default:
    assertx(false);
    break;
  }
}

void VariableSerializer::writeRefCount() {
  if (m_type == Type::DebugDump) {
    m_buf->append(" refcount(");
    m_buf->append(m_refCount);
    m_buf->append(')');
    m_refCount = 1;
  }
}

void VariableSerializer::writeArrayHeader(int size, bool isVectorData,
                                          VariableSerializer::ArrayKind kind) {
  m_arrayInfos.push_back(ArrayInfo());
  ArrayInfo &info = m_arrayInfos.back();
  info.first_element = true;
  info.indent_delta = 0;
  info.size = size;

  switch (m_type) {
  case Type::DebuggerDump:
  case Type::PrintR:
    if (!m_rsrcName.empty()) {
      m_buf->append("Resource id #");
      m_buf->append(m_rsrcId);
      if (m_type == Type::DebuggerDump) {
        m_buf->append(" of type ");
        m_buf->append(m_rsrcName);
      }
      break;
    } else if (!m_objClass.empty()) {
      m_buf->append(m_objClass);
      m_buf->append(" Object\n");
    } else {
      switch (kind) {
      case ArrayKind::Dict:
        m_buf->append("Dict\n");
        break;
      case ArrayKind::Vec:
        m_buf->append("Vec\n");
        break;
      case ArrayKind::Keyset:
        m_buf->append("Keyset\n");
        break;
      case ArrayKind::PHP:
      case ArrayKind::VArray:
      case ArrayKind::DArray:
      case ArrayKind::MarkedVArray:
      case ArrayKind::MarkedDArray:
        m_buf->append("Array\n");
        break;
      }
    }
    if (m_indent > 0) {
      m_indent += 4;
      indent();
    }
    m_buf->append("(\n");
    m_indent += (info.indent_delta = 4);
    break;
  case Type::VarExport:
  case Type::PHPOutput:
    if (m_indent > 0 && m_rsrcName.empty() && m_keyPrinted) {
      m_buf->append('\n');
      indent();
    }
    if (!m_objClass.empty()) {
      m_buf->append(m_objClass);
      if (m_objCode == 'O') {
        m_buf->append("::__set_state(darray[\n");
      } else {
        assertx(m_objCode == 'V' || m_objCode == 'K');
        m_buf->append(" {\n");
      }
    } else if (!m_rsrcName.empty()) {
      m_buf->append("NULL");
    } else {
      switch (kind) {
      case ArrayKind::Dict:
        if (m_type == Type::PHPOutput && m_dvOverrides) {
          m_buf->append(
            (*m_dvOverrides)[m_dvOverridesIndex] ? "darray [\n" : "dict [\n"
          );
          m_dvOverridesIndex++;
        } else {
          m_buf->append("dict [\n");
        }
        break;
      case ArrayKind::Vec:
        if (m_type == Type::PHPOutput && m_dvOverrides) {
          m_buf->append(
            (*m_dvOverrides)[m_dvOverridesIndex] ? "varray [\n" : "vec [\n"
          );
          m_dvOverridesIndex++;
        } else {
          m_buf->append("vec [\n");
        }
        break;
      case ArrayKind::Keyset:
        m_buf->append("keyset [\n");
        break;
      case ArrayKind::PHP:
        m_buf->append("array (\n");
        break;
      case ArrayKind::VArray: {
        auto const dvarray = RO::EvalHackArrDVArrVarExport ||
                             m_type == Type::PHPOutput;
        m_buf->append(dvarray ? "varray [\n" : "array (\n");
        break;
      }
      case ArrayKind::DArray: {
        auto const dvarray = RO::EvalHackArrDVArrVarExport ||
                             m_type == Type::PHPOutput;
        m_buf->append(dvarray ? "darray [\n" : "array (\n");
        break;
      }
      case ArrayKind::MarkedVArray:
      case ArrayKind::MarkedDArray:
        always_assert(0);
      }
    }
    m_indent += (info.indent_delta = 2);
    break;
  case Type::VarDump:
  case Type::DebugDump:
    indent();
    if (!m_rsrcName.empty()) {
      m_buf->append("resource(");
      m_buf->append(m_rsrcId);
      m_buf->append(") of type (");
      m_buf->append(m_rsrcName);
      m_buf->append(")\n");
      break;
    } else if (!m_objClass.empty()) {
      m_buf->append("object(");
      m_buf->append(m_objClass);
      m_buf->append(") ");
    } else {
      auto const header = [&]() {
        switch (kind) {
          case ArrayKind::Dict:
            return "dict";
          case ArrayKind::Vec:
            return "vec";
          case ArrayKind::Keyset:
            return "keyset";
          case ArrayKind::PHP:
            return "array";
          case ArrayKind::VArray:
          case ArrayKind::MarkedVArray:
            return "varray";
          case ArrayKind::DArray:
          case ArrayKind::MarkedDArray:
            return "darray";
        }
        not_reached();
      }();
      m_buf->append(header);
    }
    m_buf->append('(');
    m_buf->append(size);
    m_buf->append(')');

    // ...so to strictly follow PHP's output
    if (m_type == Type::VarDump) {
      m_buf->append(' ');
    } else {
      writeRefCount();
    }

    m_buf->append("{\n");
    m_indent += (info.indent_delta = 2);
    break;
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
  case Type::DebuggerSerialize:
    if (!m_rsrcName.empty() && m_type == Type::DebuggerSerialize) {
      m_buf->append("L:");
      m_buf->append(m_rsrcId);
      m_buf->append(":");
      m_buf->append((int)m_rsrcName.size());
      m_buf->append(":\"");
      m_buf->append(m_rsrcName);
      m_buf->append("\"{");
    } else if (!m_objClass.empty()) {
      m_buf->append(m_objCode);
      m_buf->append(":");
      m_buf->append((int)m_objClass.size());
      m_buf->append(":\"");
      m_buf->append(m_objClass);
      m_buf->append("\":");
      m_buf->append(size);
      m_buf->append(":{");
    } else {
      switch (kind) {
      case ArrayKind::Dict:
        m_buf->append("D:");
        break;
      case ArrayKind::Vec:
        m_buf->append("v:");
        break;
      case ArrayKind::MarkedVArray:
        m_buf->append("x:");
        break;
      case ArrayKind::MarkedDArray:
        m_buf->append("X:");
        break;
      case ArrayKind::Keyset:
        m_buf->append("k:");
        break;
      case ArrayKind::PHP:
        m_buf->append("a:");
        break;
      case ArrayKind::VArray:
        m_buf->append("y:");
        break;
      case ArrayKind::DArray:
        m_buf->append("Y:");
        break;
      }
      m_buf->append(size);
      m_buf->append(":{");
    }
    break;
  case Type::JSON:
    info.is_vector =
      (m_objClass.empty() || m_objCode == 'V' || m_objCode == 'K') &&
      isVectorData &&
      kind != ArrayKind::Dict;

    if (info.is_vector && m_type == Type::JSON) {
      info.is_vector = (m_option & k_JSON_FORCE_OBJECT)
                       ? false : info.is_vector;
    }

    if (info.is_vector || kind == ArrayKind::Keyset) {
      if (UNLIKELY(RuntimeOption::EvalHackArrCompatSerializeNotices) &&
          kind == ArrayKind::DArray) {
        if (size == 0 && m_edWarn && !m_hasEDWarned) {
          raise_hackarr_compat_notice("JSON encoding empty darray");
          m_hasEDWarned = true;
        } else if (size != 0 && m_vdWarn && !m_hasVDWarned) {
          raise_hackarr_compat_notice("JSON encoding vec-like darray");
          m_hasVDWarned = true;
        }
      }
      m_buf->append('[');
    } else {
      if (UNLIKELY(RuntimeOption::EvalHackArrCompatSerializeNotices) &&
          kind == ArrayKind::DArray && m_ddWarn && !m_hasDDWarned) {
        raise_hackarr_compat_notice("JSON encoding dict-like darray");
        m_hasDDWarned = true;
      }
      m_buf->append('{');
    }

    if (m_type == Type::JSON && (m_option & k_JSON_PRETTY_PRINT) &&
        info.size > 0) {
      m_buf->append("\n");
      m_indent += (info.indent_delta = 4);
    }

    break;
  default:
    assertx(false);
    break;
  }

  // ...so we don't mess up next array output
  if (!m_objClass.empty() || !m_rsrcName.empty()) {
    m_objClass.clear();
    info.is_object = true;
  } else {
    info.is_object = false;
  }
}

void VariableSerializer::writePropertyKey(const String& prop) {
  const char *key = prop.data();
  int kl = prop.size();
  if (!*key && kl) {
    const char *cls = key + 1;
    if (*cls == '*') {
      assertx(key[2] == 0);
      m_buf->append(key + 3, kl - 3);
      const char prot[] = "\":protected";
      int o = m_type == Type::PrintR ? 1 : 0;
      m_buf->append(prot + o, sizeof(prot) - 1 - o);
    } else {
      int l = strlen(cls);
      m_buf->append(cls + l + 1, kl - l - 2);
      int o = m_type == Type::PrintR ? 1 : 0;
      m_buf->append(&"\":\""[o], 3 - 2*o);
      m_buf->append(cls, l);
      const char priv[] = "\":private";
      m_buf->append(priv + o, sizeof(priv) - 1 - o);
    }
  } else {
    m_buf->append(prop);
    if (m_type != Type::PrintR && m_type != Type::DebuggerDump) {
      m_buf->append('"');
    }
  }
}

/* key MUST be a non-reference string or int */
void VariableSerializer::writeArrayKey(
  const Variant& key,
  VariableSerializer::ArrayKind kind
) {
  using AK = VariableSerializer::ArrayKind;
  auto const keyCell = tvAssertPlausible(key.asTypedValue());
  bool const skey = isStringType(keyCell->m_type);

  ArrayInfo &info = m_arrayInfos.back();

  switch (m_type) {
  case Type::DebuggerDump:
  case Type::PrintR: {
    indent();
    if (kind == AK::Keyset) return;
    m_buf->append('[');
    if (info.is_object && skey) {
      writePropertyKey(String{keyCell->m_data.pstr});
    } else {
      m_buf->append(key);
    }
    m_buf->append("] => ");
    break;
  }

  case Type::VarExport:
  case Type::PHPOutput:
    indent();
    if (kind == AK::Vec || kind == AK::Keyset) return;
    if ((kind == AK::VArray || kind == AK::MarkedVArray) &&
        (RO::EvalHackArrDVArrVarExport || m_type == Type::PHPOutput)) {
      return;
    }
    write(key, true);
    m_buf->append(" => ");
    break;

  case Type::VarDump:
  case Type::DebugDump:
    if (kind == AK::Vec || kind == AK::Keyset ||
        kind == AK::VArray || kind == AK::MarkedVArray) {
      return;
    }
    indent();
    m_buf->append('[');
    if (!skey) {
      m_buf->append(keyCell->m_data.num);
    } else {
      m_buf->append('"');
      if (info.is_object) {
        writePropertyKey(String{keyCell->m_data.pstr});
      } else {
        m_buf->append(keyCell->m_data.pstr);
        m_buf->append('"');
      }
    }
    m_buf->append("]=>\n");
    break;

  case Type::APCSerialize:
    if (kind == AK::Vec || kind == AK::Keyset || kind == AK::VArray) return;
    if (skey) {
      write(StrNR(keyCell->m_data.pstr).asString());
      return;
    }

  case Type::Serialize:
  case Type::Internal:
  case Type::DebuggerSerialize:
    if (kind == AK::Vec || kind == AK::MarkedVArray ||
        kind == AK::Keyset || kind == AK::VArray) return;
    write(key);
    break;

  case Type::JSON:
    if (!info.is_vector && kind != ArrayKind::Keyset) {
      if (!info.first_element) {
        m_buf->append(',');
      }
      if (UNLIKELY(m_option & k_JSON_PRETTY_PRINT)) {
        if (!info.first_element) {
          m_buf->append("\n");
        }
        indent();
      }
      if (skey) {
        auto const sdata = keyCell->m_data.pstr;
        const char *k = sdata->data();
        int len = sdata->size();
        if (info.is_object && !*k && len) {
          while (*++k) len--;
          k++;
          len -= 2;
        }
        write(k, len, true);
      } else {
        m_buf->append('"');
        m_buf->append(keyCell->m_data.num);
        m_buf->append('"');
      }
      m_buf->append(':');
      if (UNLIKELY(m_option & k_JSON_PRETTY_PRINT)) {
        m_buf->append(' ');
      }
    }
    break;

  default:
    assertx(false);
    break;
  }
}

void VariableSerializer::writeCollectionKey(
  const Variant& key,
  VariableSerializer::ArrayKind kind
) {
  if (m_type == Type::Serialize ||
      m_type == Type::Internal ||
      m_type == Type::APCSerialize ||
      m_type == Type::DebuggerSerialize) {
    m_valueCount++;
  }
  writeArrayKey(key, kind);
}

void VariableSerializer::writeArrayValue(
  const Variant& value,
  VariableSerializer::ArrayKind kind
) {
  switch (m_type) {
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
  case Type::DebuggerSerialize:
    // Do not count values in keysets because they're also keys, and it's not
    // possible to have back references to keys.
    if (kind != VariableSerializer::ArrayKind::Keyset) {
      m_valueCount++;
    }
    write(value);
    break;

  case Type::DebuggerDump:
  case Type::PrintR:
    write(value);
    m_buf->append('\n');
    break;

  case Type::VarExport:
  case Type::PHPOutput: {
    auto const oldKeyPrinted = m_keyPrinted;
    m_keyPrinted = [&]{
      if (kind == ArrayKind::Vec || kind == ArrayKind::Keyset) return false;
      if ((kind == ArrayKind::VArray || kind == ArrayKind::MarkedVArray) &&
          (RO::EvalHackArrDVArrVarExport || m_type == Type::PHPOutput)) {
        return false;
      }
      return true;
    }();
    SCOPE_EXIT { m_keyPrinted = oldKeyPrinted; };
    write(value);
    m_buf->append(",\n");
    break;
  }

  case Type::JSON: {
    ArrayInfo &info = m_arrayInfos.back();
    if (info.is_vector || kind == ArrayKind::Keyset) {
      if (!info.first_element) {
        m_buf->append(',');
      }
      if (UNLIKELY(m_option & k_JSON_PRETTY_PRINT)) {
        if (!info.first_element) {
          m_buf->append("\n");
        }
        indent();
      }
    }
    write(value);
    break;
  }

  default:
    write(value);
    break;
  }

  ArrayInfo &last_info = m_arrayInfos.back();
  last_info.first_element = false;
}

void VariableSerializer::writeArrayFooter(
  VariableSerializer::ArrayKind kind
) {
  ArrayInfo &info = m_arrayInfos.back();

  m_indent -= info.indent_delta;
  switch (m_type) {
  case Type::DebuggerDump:
  case Type::PrintR:
    if (m_rsrcName.empty()) {
      indent();
      m_buf->append(")\n");
      if (m_indent > 0) {
        m_indent -= 4;
      }
    }
    break;
  case Type::VarExport:
  case Type::PHPOutput:
    if (m_rsrcName.empty()) {
      indent();
    }
    if (info.is_object && m_objCode) {
      if (m_objCode == 'O') {
        m_buf->append("])");
      } else {
        assertx(m_objCode == 'V' || m_objCode == 'K');
        m_buf->append("}");
      }
    } else if (m_rsrcName.empty()) { // for rsrc, only write NULL in arrayHeader
      switch (kind) {
      case ArrayKind::Dict:
      case ArrayKind::Vec:
      case ArrayKind::Keyset:
        m_buf->append(']');
        break;
      case ArrayKind::PHP:
        m_buf->append(')');
        break;
      case ArrayKind::VArray:
      case ArrayKind::DArray: {
        auto const dvarrays = RO::EvalHackArrDVArrVarExport ||
                              m_type == Type::PHPOutput;
        m_buf->append(dvarrays ? ']' : ')');
        break;
      }
      case ArrayKind::MarkedVArray:
      case ArrayKind::MarkedDArray:
        always_assert(0);
      }
    }
    break;
  case Type::VarDump:
  case Type::DebugDump:
    if (m_rsrcName.empty()) {
      indent();
      m_buf->append("}\n");
    }
    break;
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
  case Type::DebuggerSerialize:
    m_buf->append('}');
    break;
  case Type::JSON:
    if (m_type == Type::JSON && (m_option & k_JSON_PRETTY_PRINT) &&
        info.size > 0) {
      m_buf->append("\n");
      indent();
    }
    if (info.is_vector || kind == ArrayKind::Keyset) {
      m_buf->append(']');
    } else {
      m_buf->append('}');
    }
    break;
  default:
    assertx(false);
    break;
  }

  m_arrayInfos.pop_back();
}

void VariableSerializer::writeSerializableObject(const String& clsname,
                                                 const String& serialized) {
  m_buf->append("C:");
  m_buf->append(clsname.size());
  m_buf->append(":\"");
  m_buf->append(clsname.data(), clsname.size());
  m_buf->append("\":");
  m_buf->append(serialized.size());
  m_buf->append(":{");
  m_buf->append(serialized.data(), serialized.size());
  m_buf->append('}');
}

///////////////////////////////////////////////////////////////////////////////

void VariableSerializer::indent() {
  for (int i = 0; i < m_indent; i++) {
    m_buf->append(' ');
  }
}

bool VariableSerializer::incNestedLevel(tv_rval tv) {
  ++m_currentDepth;

  switch (m_type) {
  case Type::VarExport:
  case Type::PHPOutput:
  case Type::PrintR:
  case Type::VarDump:
  case Type::DebugDump:
  case Type::DebuggerDump:
    return ++m_refs[tv].m_count >= m_maxCount;
  case Type::JSON:
    if (m_currentDepth > m_maxDepth) {
      json_set_last_error_code(json_error_codes::JSON_ERROR_DEPTH);
    }
    return ++m_refs[tv].m_count >= m_maxCount;
  case Type::DebuggerSerialize:
    if (m_maxLevelDebugger > 0 && ++m_levelDebugger > m_maxLevelDebugger) {
      return true;
    }
    // fall through
  case Type::Serialize:
  case Type::Internal:
  case Type::APCSerialize:
    {
      auto& ref = m_refs[tv];
      int ct = ++ref.m_count;
      bool isObject = tvIsResource(tv) || tvIsObject(tv);
      if (ref.m_id != NO_ID && isObject) {
        return true;
      }
      ref.m_id = m_valueCount;
      return ct >= (m_maxCount - 1);
    }
    break;
  default:
    assertx(false);
    break;
  }
  return false;
}

void VariableSerializer::decNestedLevel(tv_rval tv) {
  --m_currentDepth;
  --m_refs[tv].m_count;
  if (m_type == Type::DebuggerSerialize && m_maxLevelDebugger > 0) {
    --m_levelDebugger;
  }
}

void VariableSerializer::serializeRFunc(const RFuncData* rfunc) {
  SystemLib::throwInvalidOperationExceptionObject(
    "Unable to serialize reified function pointer"
  );
}

void VariableSerializer::serializeFunc(const Func* func) {
  auto const name = func->fullName();
  switch (getType()) {
    case Type::VarExport:
    case Type::PHPOutput:
      m_buf->append("fun(");
      write(name->data(), name->size());
      m_buf->append(')');
      break;
    case Type::VarDump:
    case Type::DebugDump:
      // TODO (T29639296)
      // For now we use function(foo) to dump function pointers in most cases,
      // and this can be changed in the future.
      indent();
      m_buf->append("function(");
      m_buf->append(name->data());
      m_buf->append(")\n");
      break;
    case Type::PrintR:
    case Type::DebuggerDump:
      m_buf->append("function(");
      m_buf->append(name->data());
      m_buf->append(')');
      break;
    case Type::JSON:
      write(func->nameStr());
      break;
    case Type::Serialize:
    case Type::Internal:
    case Type::APCSerialize:
    case Type::DebuggerSerialize:
      invalidFuncConversion("string");
      break;
  }
}

void VariableSerializer::serializeClass(const Class* cls) {
  switch (getType()) {
    case Type::VarExport:
    case Type::PHPOutput:
      m_buf->append(cls->name());
      m_buf->append("::class");
      break;
    case Type::VarDump:
      if (RuntimeOption::EvalClassAsStringVarDump) {
        write(StrNR(cls->name()));
        break;
      }
      // fall-through
    case Type::DebugDump:
      indent();
      m_buf->append("class(");
      m_buf->append(cls->name());
      m_buf->append(")\n");
      break;
    case Type::PrintR:
    case Type::DebuggerDump:
      m_buf->append("class(");
      m_buf->append(cls->name());
      m_buf->append(')');
      break;
    case Type::JSON:
      write(StrNR(classToStringHelper(cls)));
      break;
    case Type::Serialize:
    case Type::Internal:
    case Type::APCSerialize:
    case Type::DebuggerSerialize:
      write(StrNR(classToStringHelper(cls)));
      break;
  }
}

void VariableSerializer::serializeLazyClass(LazyClassData lcls) {
  switch (getType()) {
    case Type::VarExport:
    case Type::PHPOutput:
      m_buf->append(lcls.name());
      m_buf->append("::class");
      break;
    case Type::VarDump:
      if (RuntimeOption::EvalClassAsStringVarDump) {
        write(StrNR(lcls.name()));
        break;
      }
      // fall-through
    case Type::DebugDump:
      indent();
      m_buf->append("class(");
      m_buf->append(lcls.name());
      m_buf->append(")\n");
      break;
    case Type::PrintR:
    case Type::DebuggerDump:
      m_buf->append("class(");
      m_buf->append(lcls.name());
      m_buf->append(')');
      break;
    case Type::JSON:
    case Type::Serialize:
    case Type::DebuggerSerialize:
      write(StrNR(lazyClassToStringHelper(lcls)));
      break;
    case Type::Internal:
    case Type::APCSerialize: {
      auto cname = lcls.name();
      m_buf->append("l:");
      m_buf->append(cname->size());
      m_buf->append(":\"");
      m_buf->append(cname->data(), cname->size());
      m_buf->append("\";");
      break;
    }
  }
}

void VariableSerializer::serializeClsMeth(
  ClsMethDataRef clsMeth, bool skipNestCheck /* = false */) {
  auto const clsName = clsMeth->getCls()->name();
  auto const funcName = clsMeth->getFunc()->name();
  switch (getType()) {
    case Type::DebuggerDump:
    case Type::PrintR:
      m_buf->append("classMeth{\n    class(");
      m_buf->append(clsName->data());
      m_buf->append(")\n    function(");
      m_buf->append(funcName->data());
      m_buf->append(")\n}");
      break;

    case Type::VarExport:
    case Type::PHPOutput:
      m_buf->append("class_meth(");
      write(clsName->data(), clsName->size());
      m_buf->append(", ");
      write(funcName->data(), funcName->size());
      m_buf->append(')');
      break;

    case Type::VarDump:
    case Type::DebugDump:
      m_buf->append("classMeth{\n    class(");
      m_buf->append(clsName->data());
      m_buf->append(")\n    function(");
      m_buf->append(funcName->data());
      m_buf->append(")\n}\n");
      break;

    case Type::Serialize:
    case Type::Internal:
    case Type::APCSerialize:
    case Type::DebuggerSerialize:
    case Type::JSON: {
      if (!RO::EvalIsCompatibleClsMethType) {
        SystemLib::throwInvalidOperationExceptionObject(
          "Unable to serialize class meth pointer"
        );
      }
      raiseClsMethToVecWarningHelper();
      auto const vec = clsMethToVecHelper(clsMeth);
      serializeArray(vec.get(), skipNestCheck);
      break;
    }
  }
}

void VariableSerializer::serializeRClsMeth(RClsMethData* rclsMeth) {
  SystemLib::throwInvalidOperationExceptionObject(
    "Unable to serialize reified class meth pointer"
  );
}

NEVER_INLINE
void VariableSerializer::serializeVariant(tv_rval tv,
                                          bool isArrayKey /* = false */,
                                          bool skipNestCheck /* = false */,
                                          bool noQuotes /* = false */) {
  switch (type(tv)) {
    case KindOfUninit:
    case KindOfNull:
      assertx(!isArrayKey);
      writeNull();
      return;

    case KindOfBoolean:
      assertx(!isArrayKey);
      write(val(tv).num != 0);
      return;

    case KindOfInt64:
      write(val(tv).num);
      return;

    case KindOfDouble:
      write(val(tv).dbl);
      return;

    case KindOfPersistentString:
    case KindOfString:
      write(val(tv).pstr->data(),
            val(tv).pstr->size(), isArrayKey, noQuotes);
      return;

    case KindOfPersistentVec:
    case KindOfVec:
      assertx(!isArrayKey);
      assertx(val(tv).parr->isVecType());
      serializeArray(val(tv).parr, skipNestCheck);
      return;

    case KindOfPersistentDict:
    case KindOfDict:
      assertx(!isArrayKey);
      assertx(val(tv).parr->isDictType());
      serializeArray(val(tv).parr, skipNestCheck);
      return;

    case KindOfPersistentKeyset:
    case KindOfKeyset:
      assertx(!isArrayKey);
      assertx(val(tv).parr->isKeysetType());
      serializeArray(val(tv).parr, skipNestCheck);
      return;

    case KindOfPersistentDArray:
    case KindOfDArray:
    case KindOfPersistentVArray:
    case KindOfVArray:
      assertx(!isArrayKey);
      assertx(val(tv).parr->isPHPArrayType());
      serializeArray(val(tv).parr, skipNestCheck);
      return;

    case KindOfObject:
      assertx(!isArrayKey);
      serializeObject(val(tv).pobj);
      return;

    case KindOfResource:
      assertx(!isArrayKey);
      serializeResource(val(tv).pres->data());
      return;

    case KindOfRFunc:
      assertx(!isArrayKey);
      serializeRFunc(val(tv).prfunc);
      return;

    case KindOfFunc:
      assertx(!isArrayKey);
      serializeFunc(val(tv).pfunc);
      return;

    case KindOfClass:
      assertx(!isArrayKey);
      serializeClass(val(tv).pclass);
      return;

    case KindOfClsMeth:
      assertx(!isArrayKey);
      serializeClsMeth(val(tv).pclsmeth, skipNestCheck);
      return;

    case KindOfRClsMeth:
      assertx(!isArrayKey);
      serializeRClsMeth(val(tv).prclsmeth);

    case KindOfLazyClass:
      assertx(!isArrayKey);
      serializeLazyClass(val(tv).plazyclass);
      return;

    case KindOfRecord:
      // TODO(T41025646): implement serialization of record
      always_assert(false);
  }
  not_reached();
}

void VariableSerializer::serializeResourceImpl(const ResourceData* res) {
  pushResourceInfo(res->o_getResourceName(), res->getId());
  serializeArray(ArrayData::CreateDict());
  popResourceInfo();
}

void VariableSerializer::serializeResource(const ResourceData* res) {
  TypedValue tv = make_tv<KindOfResource>(const_cast<ResourceHdr*>(res->hdr()));
  if (UNLIKELY(incNestedLevel(&tv))) {
    writeOverflow(&tv);
  } else if (auto trace = dynamic_cast<const CompactTrace*>(res)) {
    auto const trace_array = trace->extract();
    serializeArray(trace_array.get());
  } else {
    serializeResourceImpl(res);
  }
  decNestedLevel(&tv);
}

void VariableSerializer::serializeString(const String& str) {
  if (str) {
    write(str.data(), str.size());
  } else {
    writeNull();
  }
}

void VariableSerializer::serializeArrayImpl(const ArrayData* arr,
                                            bool isVectorData) {
  using AK = VariableSerializer::ArrayKind;
  AK kind = getKind(arr);
  writeArrayHeader(
    arr->size(),
    isVectorData,
    kind
  );

  auto const write_name = [&](const StringData* name) {
    if (m_unitFilename == name) {
      m_buf->append("t;");
    } else {
      write(name->data(), name->size());
    }
  };

  if ((m_type == Type::Internal || m_serializeProvenanceAndLegacy) &&
      arrprov::arrayWantsTag(arr)) {
    auto const tag = arrprov::getTag(arr);
    if (tag.valid()) {
      switch (tag.kind()) {
      case arrprov::Tag::Kind::Invalid: always_assert(false);
      case arrprov::Tag::Kind::Known: {
        m_buf->append("p:");
        write(tag.line());
        write_name(tag.name());
        break;
      }
      case arrprov::Tag::Kind::KnownFuncParam: {
        m_buf->append("pf:");
        write(tag.line());
        write_name(tag.name());
        break;
      }
      case arrprov::Tag::Kind::KnownTraitMerge: {
        m_buf->append("pr:");
        write_name(tag.name());
        break;
      }
      case arrprov::Tag::Kind::KnownLargeEnum: {
        m_buf->append("pe:");
        write_name(tag.name());
        break;
      }
      case arrprov::Tag::Kind::RuntimeLocation:
        m_buf->append("pc:");
        write_name(tag.name());
        break;
      case arrprov::Tag::Kind::RuntimeLocationPoison:
        m_buf->append("pz:");
        write_name(tag.name());
        break;
      }
    }
  }

  IterateKV(
    arr,
    [&](TypedValue k, TypedValue v) {
      writeArrayKey(VarNR(k), kind);
      writeArrayValue(VarNR(v), kind);
    }
  );

  writeArrayFooter(kind);
}

void VariableSerializer::serializeArray(const ArrayData* arr,
                                        bool skipNestCheck /* = false */) {
  if (UNLIKELY(RuntimeOption::EvalHackArrCompatSerializeNotices)) {
    if (UNLIKELY(m_hackWarn && !m_hasHackWarned && arr->isHackArrayType())) {
      raise_hack_arr_compat_serialize_notice(arr);
      m_hasHackWarned = true;
    }
    if (UNLIKELY(m_dictWarn && !m_hasDictWarned && arr->isDictType())) {
      raise_hack_arr_compat_serialize_notice(arr);
      m_hasDictWarned = true;
    }
    if (UNLIKELY(m_keysetWarn && !m_hasKeysetWarned && arr->isKeysetType())) {
      raise_hack_arr_compat_serialize_notice(arr);
      m_hasKeysetWarned = true;
    }
    if (UNLIKELY(m_phpWarn && !m_hasPHPWarned && arr->isPHPArrayType())) {
      raise_hack_arr_compat_serialize_notice(arr);
      m_hasPHPWarned = true;
    }
  }

  const bool isVectorData = arr->isVectorData();

  if (arrprov::arrayWantsTag(arr) && !m_serializeProvenanceAndLegacy &&
      !m_forcePHPArrays && !m_forceHackArrays) {
    auto const source = [&]() -> folly::Optional<SerializationSite> {
      switch (getType()) {
      case VariableSerializer::Type::JSON:
        // json_encode only observes provenance on list-like darrays
        return arr->isVecType() || arr->isVArray() || !isVectorData
          ? folly::none
          : folly::make_optional(SerializationSite::JsonEncode);
      case VariableSerializer::Type::Serialize:
        return SerializationSite::Serialize;
      case VariableSerializer::Type::VarExport:
        return SerializationSite::VarExport;
      case VariableSerializer::Type::PrintR:
        return SerializationSite::PrintR;
      default:
        return folly::none;
      }
    }();
    if (source) raise_array_serialization_notice(*source, arr);
  }

  if (arr->size() == 0 && LIKELY(!arrprov::arrayWantsTag(arr))) {
    auto const kind = getKind(arr);
    writeArrayHeader(0, isVectorData, kind);
    writeArrayFooter(kind);
    return;
  }

  if (!skipNestCheck) {
    TypedValue tv = make_array_like_tv(const_cast<ArrayData*>(arr));
    if (incNestedLevel(&tv)) {
      writeOverflow(&tv);
    } else {
      serializeArrayImpl(arr, isVectorData);
    }
    decNestedLevel(&tv);
  } else {
    // If skipNestCheck, the array is temporary and we should not check or
    // save its pointer. We'll serialize it without its header.
    serializeArrayImpl(arr, isVectorData);
  }
}

void VariableSerializer::serializeObjProps(Array& arr) {
  if (arr.isNull()) {
    writeNull();
    return;
  }

  auto const ad = arr.detach();
  auto const dict = ad->toDict(ad->cowCheck());
  if (dict != ad) decRefArr(ad);
  serializeArray(dict, /*skipNestCheck=*/true);
  decRefArr(dict);
}

void VariableSerializer::serializeCollection(ObjectData* obj) {
  using AK = VariableSerializer::ArrayKind;
  int64_t sz = collections::getSize(obj);
  auto type = obj->collectionType();

  if (isMapCollection(type)) {
    pushObjectInfo(obj->getClassName(),'K');
    writeArrayHeader(sz, false, AK::PHP);
    for (ArrayIter iter(obj); iter; ++iter) {
      writeCollectionKey(iter.first(), AK::PHP);
      writeArrayValue(iter.second(), AK::PHP);
    }
    writeArrayFooter(AK::PHP);

  } else {
    assertx(isVectorCollection(type) ||
            isSetCollection(type) ||
            (type == CollectionType::Pair));
    pushObjectInfo(obj->getClassName(), 'V');
    writeArrayHeader(sz, true, AK::PHP);
    auto ser_type = getType();
    if (ser_type == VariableSerializer::Type::Serialize ||
        ser_type == VariableSerializer::Type::Internal ||
        ser_type == VariableSerializer::Type::APCSerialize ||
        ser_type == VariableSerializer::Type::DebuggerSerialize ||
        ser_type == VariableSerializer::Type::VarExport ||
        ser_type == VariableSerializer::Type::PHPOutput) {
      // For the 'V' serialization format, we don't print out keys
      // for Serialize, APCSerialize, DebuggerSerialize
      bool const should_indent =
        ser_type == VariableSerializer::Type::VarExport ||
        ser_type == VariableSerializer::Type::PHPOutput;
      for (ArrayIter iter(obj); iter; ++iter) {
        if (should_indent) {
          indent();
        }
        writeArrayValue(iter.second(), AK::PHP);
      }
    } else {
      if (isSetCollection(type)) {
        bool const should_indent =
          ser_type == VariableSerializer::Type::PrintR ||
          ser_type == VariableSerializer::Type::DebuggerDump;
        for (ArrayIter iter(obj); iter; ++iter) {
          if (should_indent) {
            indent();
          }
          writeArrayValue(iter.second(), AK::PHP);
        }
      } else {
        for (ArrayIter iter(obj); iter; ++iter) {
          writeCollectionKey(iter.first(), AK::PHP);
          writeArrayValue(iter.second(), AK::PHP);
        }
      }
    }
    writeArrayFooter(AK::PHP);
  }
  popObjectInfo();
}

/* Get properties from the actual object unless we're
 * serializing for var_dump()/print_r() and the object
 * exports a __debugInfo() magic method.
 * In which case, call that and use the array it returns.
 */
Array VariableSerializer::getSerializeProps(const ObjectData* obj) const {
  if (getType() == VariableSerializer::Type::VarExport) {
    Array props = Array::CreateDArray();
    for (ArrayIter iter(obj->toArray(false, true)); iter; ++iter) {
      auto key = iter.first().toString();
      // Jump over any class attribute mangling
      if (key[0] == '\0' && key.size() > 0) {
        int sizeToCut = 0;
        do {
          sizeToCut++;
        } while (key[sizeToCut] != '\0');
        key = key.substr(sizeToCut+1);
      }
      props.set(key, iter.secondVal());
    }
    return props;
  }
  if ((getType() != VariableSerializer::Type::PrintR) &&
      (getType() != VariableSerializer::Type::VarDump)) {
    auto const ignoreLateInit =
      (m_ignoreLateInit ||
       getType() == VariableSerializer::Type::DebugDump ||
       getType() == VariableSerializer::Type::DebuggerDump ||
       getType() == VariableSerializer::Type::DebuggerSerialize);
    return obj->toArray(false, ignoreLateInit);
  }
  auto cls = obj->getVMClass();
  auto debuginfo = cls->lookupMethod(s_debugInfo.get());
  if (!debuginfo) {
    // When ArrayIterator is cast to an array, it returns its array object,
    // however when it's being var_dump'd or print_r'd, it shows its properties
    if (UNLIKELY(obj->instanceof(SystemLib::s_ArrayIteratorClass))) {
      auto ret = Array::CreateDArray();
      obj->o_getArray(ret, false, true);
      return ret;
    }

    // Same with Closure, since it's a dynamic object but still has its own
    // different behavior for var_dump and cast to array
    if (UNLIKELY(obj->instanceof(c_Closure::classof()))) {
      auto ret = Array::CreateDArray();
      obj->o_getArray(ret, false, true);
      return ret;
    }

    return obj->toArray(false, true);
  }
  if (debuginfo->attrs() & (AttrPrivate|AttrProtected|
                            AttrAbstract|AttrStatic)) {
    raise_warning("%s::__debugInfo() must be public and non-static",
                  cls->name()->data());
    return obj->toArray(false, true);
  }
  auto ret = const_cast<ObjectData*>(obj)->invokeDebugInfo();
  if (ret.isArray()) {
    return ret.toArray();
  }
  if (ret.isNull()) {
    return empty_array();
  }
  raise_error("__debugInfo() must return an array");
  not_reached();
}

void VariableSerializer::serializeObjectImpl(const ObjectData* obj) {
  bool handleSleep = false;
  Variant serializableNativeData = init_null();
  Variant ret;
  auto const type = getType();

  if (obj->isCollection()) {
    serializeCollection(const_cast<ObjectData*>(obj));
    return;
  }

  if (LIKELY(type == VariableSerializer::Type::Serialize ||
             type == VariableSerializer::Type::Internal ||
             type == VariableSerializer::Type::APCSerialize)) {
    if (obj->instanceof(SystemLib::s_SerializableClass)) {
      assertx(!obj->isCollection());
      ret =
        const_cast<ObjectData*>(obj)->o_invoke_few_args(s_serialize, 0);
      if (ret.isString()) {
        writeSerializableObject(obj->getClassName(), ret.toString());
      } else if (ret.isNull()) {
        writeNull();
      } else {
        raise_error("%s::serialize() must return a string or NULL",
                    obj->getClassName().data());
      }
      return;
    }
    // Only serialize CPP extension type instances which can actually
    // be deserialized.  Otherwise, raise a warning and serialize
    // null.
    // Similarly, do not try to serialize WaitHandles
    // as they contain internal state via non-NativeData means.
    auto cls = obj->getVMClass();
    if ((cls->instanceCtor() && !cls->isCppSerializable()) ||
        obj->isWaitHandle()) {
      raise_warning("Attempted to serialize unserializable builtin class %s",
                    obj->getVMClass()->preClass()->name()->data());
      serializeVariant(init_null().asTypedValue());
      return;
    }
    if (obj->getVMClass()->rtAttribute(Class::HasSleep)) {
      handleSleep = true;
      ret = const_cast<ObjectData*>(obj)->invokeSleep();
    }
    if (obj->hasNativeData()) {
      auto* ndi = cls->getNativeDataInfo();
      if (ndi->isSerializable()) {
        serializableNativeData = Native::nativeDataSleep(obj);
      }
    }
  } else if (UNLIKELY(type == VariableSerializer::Type::DebuggerSerialize)) {
    // Don't try to serialize a CPP extension class which doesn't
    // support serialization. Just send the class name instead.
    if (obj->isCppBuiltin() && !obj->getVMClass()->isCppSerializable()) {
      write(obj->getClassName());
      return;
    }
    if (obj->hasNativeData() &&
        obj->getVMClass()->getNativeDataInfo()->isSerializable()) {
      serializableNativeData = Native::nativeDataSleep(obj);
    }
  }

  if (UNLIKELY(handleSleep)) {
    assertx(!obj->isCollection());
    if (ret.isArray()) {
      Array wanted = Array::CreateDArray();
      assertx(isArrayLikeType(ret.getType()));
      const Array &props = ret.asCArrRef();
      for (ArrayIter iter(props); iter; ++iter) {
        String memberName = iter.second().toString();
        String propName = memberName;
        auto obj_cls = obj->getVMClass();
        Class* ctx = obj_cls;
        auto attrMask = AttrNone;
        if (memberName.data()[0] == 0) {
          int subLen = memberName.find('\0', 1) + 1;
          if (subLen > 2) {
            if (subLen == 3 && memberName.data()[1] == '*') {
              attrMask = AttrProtected;
              memberName = memberName.substr(subLen);
            } else {
              attrMask = AttrPrivate;
              String cls = memberName.substr(1, subLen - 2);
              ctx = Class::lookup(cls.get());
              if (ctx) {
                memberName = memberName.substr(subLen);
              } else {
                ctx = obj_cls;
              }
            }
          }
        }

        auto const lookup = obj_cls->getDeclPropSlot(ctx, memberName.get());
        auto const slot = lookup.slot;

        if (slot != kInvalidSlot && lookup.accessible) {
          auto propVal = const_cast<ObjectData*>(obj)->propLvalAtOffset(slot);
          auto const& prop = obj_cls->declProperties()[slot];

          if (propVal.type() != KindOfUninit) {
            if (prop.attrs & AttrPrivate) {
              memberName = concat4(s_zero, ctx->nameStr(),
                                   s_zero, memberName);
            } else if (prop.attrs & AttrProtected) {
              memberName = concat(s_protected_prefix, memberName);
            }
            if (!attrMask || (attrMask & prop.attrs) == attrMask) {
              wanted.set(memberName, propVal.tv());
              continue;
            }
          } else if (prop.attrs & AttrLateInit) {
            if (m_ignoreLateInit) {
              continue;
            } else {
              throw_late_init_prop(prop.cls, memberName.get(), false);
            }
          }
        }
        if (!attrMask &&
            UNLIKELY(obj->getAttribute(ObjectData::HasDynPropArr))) {
          auto const prop = obj->dynPropArray()->get(propName.get());
          if (prop.is_init()) {
            wanted.set(propName, prop);
            continue;
          }
        }
        raise_notice("serialize(): \"%s\" returned as member variable from "
                     "__sleep() but does not exist", propName.data());
        wanted.set(propName, init_null());
      }
      pushObjectInfo(obj->getClassName(), 'O');
      if (!serializableNativeData.isNull()) {
        wanted.set(s_serializedNativeDataKey, serializableNativeData);
      }
      serializeObjProps(wanted);
      popObjectInfo();
    } else {
      raise_notice("serialize(): __sleep should return an array only "
                   "containing the names of instance-variables to "
                   "serialize");
      serializeVariant(uninit_null().asTypedValue());
    }
  } else {
    if (type == VariableSerializer::Type::VarExport &&
        obj->instanceof(c_Closure::classof())) {
      write(obj->getClassName());
    } else {
      auto className = obj->getClassName();
      Array properties = getSerializeProps(obj);
      if (type == VariableSerializer::Type::DebuggerSerialize) {
        try {
           auto val = const_cast<ObjectData*>(obj)->invokeToDebugDisplay();
           if (val.isInitialized()) {
             properties.set(s_PHP_DebugDisplay, *val.asTypedValue());
           }
        } catch (const Object &e) {
          assertx(e->instanceof(SystemLib::s_ErrorClass) ||
                  e->instanceof(SystemLib::s_ExceptionClass));
          assertx(
            SystemLib::s_ErrorClass->lookupDeclProp(s_message.get()) == 0 &&
            SystemLib::s_ExceptionClass->lookupDeclProp(s_message.get()) == 0
          );
          auto const message_rval = e->propRvalAtOffset(Slot{0});
          if (isStringType(message_rval.type())) {
            raise_warning("%s::__toDebugDisplay() threw PHP exception "
                          "of class %s with message '%s'",
                          obj->getClassName().data(), e->getClassName().data(),
                          message_rval.val().pstr->data());
          } else {
            raise_warning("%s::__toDebugDisplay() threw PHP exception "
                          "of class %s with non-string message",
                          obj->getClassName().data(), e->getClassName().data());
          }
        } catch (const std::exception &e) {
          raise_warning("%s::__toDebugDisplay() threw C++ exception: %s",
                        obj->getClassName().data(), e.what());
        } catch (...) {
          raise_warning("%s::__toDebugDisplay() threw unknown exception",
                        obj->getClassName().data());
        }
      }
      if (type == VariableSerializer::Type::DebuggerDump) {
        // Expect to display as their stringified classname.
        if (obj->instanceof(c_Closure::classof())) {
          write(obj->getVMClass()->nameStr());
          return;
        }

        // If we have a DebugDisplay prop saved, use it.
        auto const debugDisp = obj->getProp(nullptr, s_PHP_DebugDisplay.get());
        if (debugDisp) {
          serializeVariant(debugDisp, false, false, true);
          return;
        }
        // Otherwise compute it if we have a __toDebugDisplay method.
        auto val = const_cast<ObjectData*>(obj)->invokeToDebugDisplay();
        if (val.isInitialized()) {
          serializeVariant(val.asTypedValue(), false, false, true);
          return;
        }
      }
      if (className.get() == s_PHP_Incomplete_Class.get() &&
          (type == VariableSerializer::Type::Serialize ||
           type == VariableSerializer::Type::Internal ||
           type == VariableSerializer::Type::APCSerialize ||
           type == VariableSerializer::Type::DebuggerSerialize ||
           type == VariableSerializer::Type::DebuggerDump)) {
        auto const cname = obj->getProp(
          nullptr,
          s_PHP_Incomplete_Class_Name.get()
        );
        if (cname && isStringType(cname.type())) {
          pushObjectInfo(StrNR(cname.val().pstr), 'O');
          properties.remove(s_PHP_Incomplete_Class_Name, true);
          serializeObjProps(properties);
          popObjectInfo();
          return;
        }
      }
      pushObjectInfo(className, 'O');
      if (!serializableNativeData.isNull()) {
        properties.set(s_serializedNativeDataKey, serializableNativeData);
      }
      serializeObjProps(properties);
      popObjectInfo();
    }
  }
}

void VariableSerializer::serializeObject(const ObjectData* obj) {
  TypedValue tv = make_tv<KindOfObject>(const_cast<ObjectData*>(obj));
  if (UNLIKELY(incNestedLevel(&tv))) {
    writeOverflow(&tv);
  } else {
    serializeObjectImpl(obj);
  }
  decNestedLevel(&tv);
}

void VariableSerializer::serializeObject(const Object& obj) {
  if (obj) {
    serializeObject(obj.get());
  } else {
    writeNull();
  }
}

}
