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

#include "hphp/runtime/ext/ext_string.h"
#include "hphp/runtime/base/string-buffer.h"
#include "hphp/runtime/base/zend-string.h"
#include "hphp/runtime/base/zend-url.h"
#include "hphp/runtime/base/zend-printf.h"
#include "hphp/runtime/base/zend-scanf.h"
#include "hphp/runtime/base/bstring.h"
#include "hphp/runtime/base/request-local.h"
#include "hphp/util/lock.h"
#include <locale.h>
#include "hphp/runtime/server/http-request-handler.h"
#include "hphp/runtime/server/http-protocol.h"
#include "hphp/runtime/ext/ext_math.h"
#include "hphp/runtime/ext/ext_variable.h"

namespace HPHP {

static Mutex s_mutex;
///////////////////////////////////////////////////////////////////////////////

template <class Op> ALWAYS_INLINE
String stringForEachBuffered(uint32_t bufLen, const String& str, Op action) {
  StringBuffer sb(bufLen);
  StringSlice sl  = str.slice();
  const char* src = sl.begin();
  const char* end = sl.end();

  for (; src < end; ++src) {
    action(sb, src, end);
  }

  return sb.detach();
}

template <bool mutate, class Op> ALWAYS_INLINE
String stringForEach(uint32_t len, const String& str, Op action) {
  String ret = mutate ? str : String(len, ReserveString);

  StringSlice srcSlice = str.slice();
  auto const dstSlice = ret.bufferSlice();

  const char* src = srcSlice.begin();
  const char* end = srcSlice.end();

  char* dst = dstSlice.begin();

  for (; src != end; ++src, ++dst) {
    *dst = action(*src);
  }

  if (!mutate) ret->setSize(len);
  return ret;
}

template <class Op> ALWAYS_INLINE
String stringForEachFast(const String& str, Op action) {
  if (str.empty()) {
    return str;
  }

  if (str->getCount() == 1) {
    return stringForEach<true>(str.size(), str, action);
  }

  return stringForEach<false>(str.size(), str, action);
}

String f_addcslashes(const String& str, const String& charlist) {
  if (str.empty() || (!charlist.isNull() && charlist->empty())) {
    return str;
  }

  int masklen = charlist.isNull() ? 10 : charlist.size();
  const char* list = charlist.isNull() ? "\\\x00\x01..\x1f\x7f..\xff"
                                       : charlist.c_str();

  char flags[256];
  string_charmask(list, masklen, flags);

  return stringForEachBuffered(str.size(), str,
    [&] (StringBuffer& ret, const char* src, const char* end) {
      int c = (unsigned char)*src;

      if (flags[c]) {
        ret.append('\\');
        if ((c < 32) || (c > 126)) {
          switch (c) {
            case '\n': ret.append('n'); break;
            case '\t': ret.append('t'); break;
            case '\r': ret.append('r'); break;
            case '\a': ret.append('a'); break;
            case '\v': ret.append('v'); break;
            case '\b': ret.append('b'); break;
            case '\f': ret.append('f'); break;
            default: ret.append((char)('0' + (c / 64))); c %= 64;
                     ret.append((char)('0' + (c /  8))); c %=  8;
                     ret.append((char)('0' + c));
          }
          return;
        }
      }
      ret.append((char)c);
    });
}

String f_stripcslashes(const String& str) {
  if (str.empty()) {
    return str;
  }

  return stringForEachBuffered(str.size(), str,
    [&] (StringBuffer& ret, const char*& src, const char* end) {
      char c;
      const char* p;

      if (*src != '\\' || src + 1 == end) {
        ret.append(*src);
        return;
      }

      switch (*++src) {
        case 'n': ret.append('\n'); break;
        case 'r': ret.append('\r'); break;
        case 'a': ret.append('\a'); break;
        case 't': ret.append('\t'); break;
        case 'v': ret.append('\v'); break;
        case 'b': ret.append('\b'); break;
        case 'f': ret.append('\f'); break;
        case '\\': ret.append('\\'); break;
        case 'x':
          if (src + 1 == end || !isxdigit(src[1])) {
            ret.append(*src);
            break;
          }

          for (c = 0, ++src, p = src + 2; src < p && src < end &&
               isxdigit(*src); ++src) {
            c *= 16;
            c += (*src < 'A' ? *src - '0' :
                  *src < 'a' ? *src - 'A' + 10 :
                               *src - 'a' + 10);
          }
          ret.append(c);
          src--;
          break;

        default:
          if (*src < '0' || '7' < *src) {
            // The character after the slash is nothing special. Append it
            // unchanged to the result.
            ret.append(*src);
            break;
          }

          // Decode a base 8 number up to 3 characters long.
          for (c = 0, p = src + 3; src < p && src < end && '0' <= *src &&
               *src < '8'; ++src) {
            c *= 8;
            c += (*src - '0');
          }
          ret.append(c);
          src--;
      }
    });
}

String f_addslashes(const String& str) {
  if (str.empty()) {
    return str;
  }

  return stringForEachBuffered(str.size(), str,
    [&] (StringBuffer& ret, const char* src, const char* end) {
      switch (*src) {
        case '\0':
          ret.append('\\');
          ret.append('0');
          break;
        case '\\': case '\"': case '\'':
          ret.append('\\');
          /* fall through */
        default:
          ret.append(*src);
      }
    });
}

String f_stripslashes(const String& str) {
  if (str.empty()) {
    return str;
  }

  return stringForEachBuffered(str.size(), str,
    [&] (StringBuffer& ret, const char*& src, const char* end) {
      if (*src == '\\' && *++src == '0') {
        ret.append('\0');
        return;
      }
      ret.append(*src);
    });
}

String f_bin2hex(const String& str) {
  if (str.empty()) {
    return str;
  }

  return stringForEachBuffered(str.size(), str,
    [&] (StringBuffer& ret, const char* src, const char* end) {
      static char hexconvtab[] = "0123456789abcdef";
      ret.append(hexconvtab[(unsigned char)*src >> 4]);
      ret.append(hexconvtab[(unsigned char)*src & 15]);
    });
}

Variant f_hex2bin(const String& str) {
  if (str.empty()) {
    return str;
  }

  if (str.size() % 2) {
    raise_warning("hex2bin: malformed input");
    return false;
  }

  StringBuffer ret(str.size() / 2 + 1);

  StringSlice sl  = str.slice();
  const char* src = sl.begin();
  const char* end = sl.end();

  for (; src != end; ++src) {
    int val;
    if (isdigit(*src))                   val = 16 * (*src++ - '0');
    else if ('a' <= *src && *src <= 'f') val = 16 * (*src++ - 'a' + 10);
    else if ('A' <= *src && *src <= 'F') val = 16 * (*src++ - 'A' + 10);
    else {
      raise_warning("hex2bin: malformed input");
      return false;
    }

    if (isdigit(*src))                   val += (*src - '0');
    else if ('a' <= *src && *src <= 'f') val += (*src - 'a' + 10);
    else if ('A' <= *src && *src <= 'F') val += (*src - 'A' + 10);
    else {
      raise_warning("hex2bin: malformed input");
      return false;
    }

    ret.append((char)val);
  }

  return ret.detach();
}

const StaticString
  s_nl("\n"),
  s_br("<br />\n"),
  s_non_xhtml_br("<br>\n");

String f_nl2br(const String& str, bool is_xhtml /* = true */) {
  if (is_xhtml) {
    return string_replace(str, s_nl, s_br);
  } else {
    return string_replace(str, s_nl, s_non_xhtml_br);
  }
}

String f_quotemeta(const String& str) {
  if (str.empty()) {
    return str;
  }

  return stringForEachBuffered(str.size(), str,
    [&] (StringBuffer& ret, const char* src, const char* end) {
      switch (*src) {
        case '.': case '\\': case '+': case '*': case '?': case '[': case ']':
        case '^': case '$': case '(': case ')':
          ret.append('\\');
          /* fall through */
        default:
          ret.append(*src);
      }
    });
}

String f_str_shuffle(const String& str) {
  if (str.size() <= 1) {
    return str;
  }

  String ret = str->getCount() == 1 ? str : String(str, CopyString);
  char* buf  = ret->mutableData();
  int left   = ret->size();

  while (--left) {
    int idx = f_rand(0, left);
    if (idx != left) {
      char temp = buf[left];
      buf[left] = buf[idx];
      buf[idx] = temp;
    }
  }
  return ret;
}

String f_strrev(const String& str) {
  auto len = str.size();

  if (str->getCount() == 1) {
    char* sdata = str->mutableData();
    for (int i = 0; i < len / 2; ++i) {
      char temp = sdata[i];
      sdata[i] = sdata[len - i - 1];
      sdata[len - i - 1] = temp;
    }
    return str;
  }

  String ret(len, ReserveString);

  const char* data = str.data();
  char* dest = ret->mutableData();

  for (int i = 0; i < len; ++i) {
    dest[i] = data[len - i - 1];
  }

  ret->setSize(len);
  return ret;
}

String f_strtolower(String str) {
  return stringForEachFast(str, tolower);
}

String f_strtoupper(String str) {
  return stringForEachFast(str, toupper);
}

template <class OpTo, class OpIs> ALWAYS_INLINE
String stringToCaseFirst(const String& str, OpTo tocase, OpIs iscase) {
  if (str.empty() || iscase(str[0])) {
    return str;
  }

  if (str->getCount() == 1) {
    char* sdata = str->mutableData();
    sdata[0] = tocase(sdata[0]);
    return str;
  }

  String ret(str, CopyString);
  char* first = ret->mutableData();

  *first = tocase(*first);
  return ret;
}

String f_ucfirst(String str) {
  return stringToCaseFirst(str, toupper, isupper);
}

String f_lcfirst(String str) {
  return stringToCaseFirst(str, tolower, islower);
}

String f_ucwords(String str) {
  char last = ' ';
  return stringForEachFast(str, [&] (char c) {
    char ret = isspace(last) ? toupper(c) : c;
    last = c;
    return ret;
  });
}

String f_strip_tags(const String& str, const String& allowable_tags /* = "" */) {
  return StringUtil::StripHTMLTags(str, allowable_tags);
}

template <bool left, bool right> ALWAYS_INLINE
String stringTrim(const String& str, const String& charlist) {
  char flags[256];
  string_charmask(charlist.c_str(), charlist.size(), flags);

  auto len = str.size();
  int start = 0, end = len - 1;

  if (left) {
    for (; start < len && flags[(unsigned char)str[start]]; ++start)
      /* do nothing */;
  }

  if (right) {
    for (; end >= start && flags[(unsigned char)str[end]]; --end) {}
  }

  if (str->getCount() == 1) {
    int slen = end - start + 1;
    if (start) {
      char* sdata = str->mutableData();
      for (int idx = 0; start < len;) sdata[idx++] = sdata[start++];
    }
    str->setSize(slen);
    return str;
  }

  return str.substr(start, end - start + 1);
}

String f_trim(String str, const String& charlist /* = k_HPHP_TRIM_CHARLIST */) {
  return stringTrim<true,true>(str, charlist);
}

String f_ltrim(String str, const String& charlist /* = k_HPHP_TRIM_CHARLIST */) {
  return stringTrim<true,false>(str, charlist);
}

String f_rtrim(String str, const String& charlist /* = k_HPHP_TRIM_CHARLIST */) {
  return stringTrim<false,true>(str, charlist);
}

String f_chop(String str, const String& charlist /* = k_HPHP_TRIM_CHARLIST */) {
  return stringTrim<false,true>(str, charlist);
}

Variant f_explode(const String& delimiter, const String& str, int limit /* = 0x7FFFFFFF */) {
  return StringUtil::Explode(str, delimiter, limit);
}

String f_implode(CVarRef arg1, CVarRef arg2 /* = null_variant */) {
  Array items;
  String delim;
  if (isContainer(arg1)) {
    items = arg1;
    delim = arg2.toString();
  } else if (isContainer(arg2)) {
    items = arg2;
    delim = arg1.toString();
  } else {
    throw_bad_type_exception("expected a container as one of the arguments");
    return String();
  }
  return StringUtil::Implode(items, delim);
}

String f_join(CVarRef glue, CVarRef pieces /* = null_variant */) {
  return f_implode(glue, pieces);
}

Variant f_str_split(const String& str, int split_length /* = 1 */) {
  return StringUtil::Split(str, split_length);
}

Variant f_chunk_split(const String& body, int chunklen /* = 76 */,
                      const String& end /* = "\r\n" */) {
  return StringUtil::ChunkSplit(body, chunklen, end);
}

class TokenizerData : public RequestEventHandler {
public:
  String str;
  int pos;
  int mask[256];

  virtual void requestInit() {
    str.reset();
    pos = 0;
    memset(&mask, 0, sizeof(mask));
  }
  virtual void requestShutdown() {
    requestInit();
  }
};
IMPLEMENT_STATIC_REQUEST_LOCAL(TokenizerData, s_tokenizer_data);

Variant f_strtok(const String& str, CVarRef token /* = null_variant */) {
  String stoken;
  if (!token.isNull()) {
    s_tokenizer_data->str = str;
    s_tokenizer_data->pos = 0;
    stoken = token.toString();
  } else {
    stoken = str;
  }

  String sstr = s_tokenizer_data->str;
  int pos = s_tokenizer_data->pos;
  if (pos >= sstr.size()) {
    return false;
  }

  // set up mask
  int *mask = s_tokenizer_data->mask;
  for (int i = 0; i < stoken.size(); i++) {
    mask[(unsigned char)stoken.data()[i]] = 1;
  }

  // skip leading delimiters
  const char *s0 = sstr.data();
  int i = pos;
  for (; i < sstr.size(); i++) {
    if (!mask[(unsigned char)s0[i]]) {
      break;
    }
  }
  int pos0 = i;
  for (; i < sstr.size(); i++) {
    if (mask[(unsigned char)s0[i]]) {
      break;
    }
  }

  String ret(s0 + pos0, i - pos0, CopyString);
  s_tokenizer_data->pos = i + 1;

  // reset mask
  for (int i = 0; i < stoken.size(); i++) {
    mask[(unsigned char)stoken.data()[i]] = 0;
  }
  return ret;
}

static
Variant str_replace(CVarRef search, CVarRef replace, const String& subject,
                    int &count, bool caseSensitive) {
  if (search.is(KindOfArray)) {
    String ret = subject;

    Array searchArr = search.toArray();
    if (replace.is(KindOfArray)) {
      Array replArr = replace.toArray();
      ArrayIter replIter(replArr);
      for (ArrayIter iter(searchArr); iter; ++iter) {
        if (replIter) {
          ret = string_replace(ret, iter.second().toString(),
                               replIter.second().toString(),
                               count, caseSensitive);
          ++replIter;
        } else {
          ret = string_replace(ret, iter.second().toString(),
                               "", count, caseSensitive);
        }
      }
      return ret;
    }

    String repl = replace.toString();
    for (ArrayIter iter(searchArr); iter; ++iter) {
      ret = string_replace(ret, iter.second().toString(), repl, count,
                           caseSensitive);
    }
    return ret;
  }

  if (replace.is(KindOfArray)) {
    raise_notice("Array to string conversion");
  }
  return string_replace(subject, search.toString(), replace.toString(), count,
                        caseSensitive);
}

static Variant str_replace(CVarRef search, CVarRef replace, CVarRef subject,
                           int &count, bool caseSensitive) {
  if (subject.is(KindOfArray)) {
    Array arr = subject.toArray();
    Array ret;
    for (ArrayIter iter(arr); iter; ++iter) {
      if (iter.second().is(KindOfArray) || iter.second().is(KindOfObject)) {
        ret.set(iter.first(), iter.second());
        continue;
      }

      String replaced = str_replace(search, replace, iter.second().toString(),
                                    count, caseSensitive);
      ret.set(iter.first(), replaced);
    }
    return ret;
  }
  return str_replace(search, replace, subject.toString(), count,
                     caseSensitive);
}

Variant f_str_replace(CVarRef search, CVarRef replace, CVarRef subject,
                      VRefParam count /* = null */) {
  int nCount = 0;
  Variant ret = str_replace(search, replace, subject, nCount, true);
  count = nCount;
  return ret;
}

Variant f_str_ireplace(CVarRef search, CVarRef replace, CVarRef subject,
                       VRefParam count /* = null */) {
  int nCount = 0;
  Variant ret = str_replace(search, replace, subject, nCount, false);
  count = nCount;
  return ret;
}

Variant f_substr_replace(CVarRef str, CVarRef replacement, CVarRef start,
                         CVarRef length /* = 0x7FFFFFFF */) {
  if (!str.is(KindOfArray)) {
    String repl;
    if (replacement.is(KindOfArray)) {
      repl = replacement[0].toString();
    } else {
      repl = replacement.toString();
    }
    if (start.is(KindOfArray)) {
      if (!length.is(KindOfArray)) {
        throw_invalid_argument("start and length should be of same type - "
                               "numerical or array");
        return str;
      }
      Array startArr = start.toArray();
      Array lengthArr = length.toArray();
      if (startArr.size() != lengthArr.size()) {
        throw_invalid_argument("start and length: (different item count)");
        return str;
      }
      throw_invalid_argument("start and length as arrays not implemented");
      return str;
    }
    return string_replace(str.toString(), start.toInt32(), length.toInt32(),
                          repl);
  }

  Array ret;
  Array strArr = str.toArray();
  Array startArr = start.toArray();
  Array lengthArr = length.toArray();
  ArrayIter startIter(startArr);
  ArrayIter lengthIter(lengthArr);

  if (replacement.is(KindOfArray)) {
    Array replArr = replacement.toArray();
    ArrayIter replIter(replArr);
    for (ArrayIter iter(strArr); iter;
         ++iter, ++startIter, ++lengthIter) {
      int nStart = startIter.second().toInt32();
      int nLength = lengthIter.second().toInt32();
      String repl = empty_string;
      if (replIter) {
        repl = replIter.second().toString();
        ++replIter;
      }
      auto s2 = string_replace(iter.second().toString(), nStart, nLength, repl);
      ret.append(s2);
    }
  } else {
    String repl = replacement.toString();
    for (ArrayIter iter(strArr); iter;
         ++iter, ++startIter, ++lengthIter) {
      int nStart = startIter.second().toInt32();
      int nLength = lengthIter.second().toInt32();
      auto s2 = string_replace(iter.second().toString(), nStart, nLength, repl);
      ret.append(s2);
    }
  }
  return ret;
}

Variant f_substr(const String& str, int start, int length /* = 0x7FFFFFFF */) {
  String ret = str.substr(start, length, true);
  if (ret.isNull()) return false;
  return ret;
}

String f_str_pad(const String& input, int pad_length, const String& pad_string /* = " " */,
                        int pad_type /* = k_STR_PAD_RIGHT */) {
  return StringUtil::Pad(input, pad_length, pad_string,
                         (StringUtil::PadType)pad_type);
}

String f_str_repeat(const String& input, int multiplier) {
  if (input.empty()) {
    return input;
  }

  if (multiplier < 0) {
    raise_warning("Second argument has to be greater than or equal to 0");
    return String();
  }

  if (multiplier == 0) {
    return String("", CopyString);
  }

  if (input.size() == 1) {
    String ret(input.size() * multiplier, ReserveString);

    memset(ret->mutableData(), *input->data(), multiplier);
    ret->setSize(multiplier);
    return ret;
  }

  StringBuffer ret(input.size() * multiplier);

  while (multiplier--) {
    ret.append(input);
  }

  return ret.detach();
}

///////////////////////////////////////////////////////////////////////////////

Variant f_printf(int _argc, const String& format, CArrRef _argv /* = null_array */) {
  int len = 0; char *output = string_printf(format.data(), format.size(),
                                            _argv, &len);
  if (output == NULL) return false;
  echo(output, len); free(output);
  return len;
}

Variant f_vprintf(const String& format, CArrRef args) {
  int len = 0; char *output = string_printf(format.data(), format.size(),
                                            args, &len);
  if (output == NULL) return false;
  echo(output, len); free(output);
  return len;
}

Variant f_sprintf(int _argc, const String& format, CArrRef _argv /* = null_array */) {
  int len = 0;
  char *output = string_printf(format.data(), format.size(), _argv, &len);
  if (output == NULL) return false;
  return String(output, len, AttachString);
}

Variant f_vsprintf(const String& format, CArrRef args) {
  int len = 0;
  char *output = string_printf(format.data(), format.size(), args, &len);
  if (output == NULL) return false;
  return String(output, len, AttachString);
}

Variant f_sscanf(int _argc, const String& str, const String& format, CArrRef _argv /* = null_array */) {
  Variant ret;
  int result;
  result = string_sscanf(str.c_str(), format.c_str(), _argv.size(), ret);
  if (SCAN_ERROR_WRONG_PARAM_COUNT == result) return uninit_null();
  if (_argv.empty()) return ret;

  if (ret.isArray()) {
    Array retArray = ret.toArray();
    for (int i = 0; i < retArray.size(); i++) {
      ((Array&)_argv).lvalAt(i) = retArray[i];
    }
    return retArray.size();
  }
  if (ret.isNull()) return 0;
  return ret;
}

String f_chr(int64_t ascii) {
  char buf[2]; buf[0] = ascii; buf[1] = 0;
  return String(buf, 1, CopyString);
}

int64_t f_ord(const String& str) {
  return (int64_t)(unsigned char)str[0];
}

Variant f_money_format(const String& format, double number) {
  String s = StringUtil::MoneyFormat(format.c_str(), number);
  if (s.isNull()) return false;
  return s;
}

String f_number_format(double number, int decimals /* = 0 */,
                       CVarRef dec_point /* = "." */,
                       CVarRef thousands_sep /* = "," */) {
  char ch_dec_point = '.';
  if (!dec_point.isNull()) {
    const String& s = dec_point.toString();
    if (s.size() >= 1) {
      ch_dec_point = s[0];
    } else {
      ch_dec_point = 0;
    }
  }
  char ch_thousands_sep = ',';
  if (!thousands_sep.isNull()) {
    const String& s = thousands_sep.toString();
    if (s.size() >= 1) {
      ch_thousands_sep = s[0];
    } else {
      ch_thousands_sep = 0;
    }
  }
  char *ret = string_number_format(number, decimals, ch_dec_point,
                                   ch_thousands_sep);
  return String(ret, AttachString);
}

int64_t f_strcmp(const String& str1, const String& str2) {
  return string_strcmp(str1.data(), str1.size(), str2.data(), str2.size());
}

Variant f_strncmp(const String& str1, const String& str2, int len) {
  if (len < 0) {
    raise_warning("Length must be greater than or equal to 0");
    return false;
  }
  return string_strncmp(str1.data(), str1.size(), str2.data(), str2.size(),
                        len);
}

int64_t f_strnatcmp(const String& str1, const String& str2) {
  return string_natural_cmp(str1.data(), str1.size(), str2.data(), str2.size(),
                            false);
}

int64_t f_strcasecmp(const String& str1, const String& str2) {
  return bstrcasecmp(str1.data(), str1.size(), str2.data(), str2.size());
}

Variant f_strncasecmp(const String& str1, const String& str2, int len) {
  if (len < 0) {
    raise_warning("Length must be greater than or equal to 0");
    return false;
  }
  return string_strncasecmp(str1.data(), str1.size(), str2.data(), str2.size(),
                            len);
}

int64_t f_strnatcasecmp(const String& str1, const String& str2) {
  return string_natural_cmp(str1.data(), str1.size(), str2.data(), str2.size(),
                            true);
}

int64_t f_strcoll(const String& str1, const String& str2) {
  return strcoll(str1.c_str(), str2.c_str());
}

Variant f_substr_compare(const String& main_str, const String& str, int offset,
                         int length /* = INT_MAX */,
                         bool case_insensitivity /* = false */) {
  int s1_len = main_str.size();
  int s2_len = str.size();

  if (length <= 0) {
    raise_warning("The length must be greater than zero");
    return false;
  }

  if (offset < 0) {
    offset = s1_len + offset;
    if (offset < 0) offset = 0;
  }

  if (offset >= s1_len) {
    raise_warning("The start position cannot exceed initial string length");
    return false;
  }

  int cmp_len = s1_len - offset;
  if (cmp_len < s2_len) cmp_len = s2_len;
  if (cmp_len > length) cmp_len = length;

  const char *s1 = main_str.data();
  if (case_insensitivity) {
    return bstrcasecmp(s1 + offset, cmp_len, str.data(), cmp_len);
  }
  return string_ncmp(s1 + offset, str.data(), cmp_len);
}

Variant f_strstr(const String& haystack, CVarRef needle,
                 bool before_needle /* = false */) {
  Variant ret = f_strpos(haystack, needle);
  if (same(ret, false)) {
    return false;
  }
  if (before_needle) {
    return haystack.substr(0, ret.toInt32());
  } else {
    return haystack.substr(ret.toInt32());
  }
}

Variant f_stristr(const String& haystack, CVarRef needle) {
  Variant ret = f_stripos(haystack, needle);
  if (same(ret, false)) {
    return false;
  }
  return haystack.substr(ret.toInt32());
}

Variant f_strpbrk(const String& haystack, const String& char_list) {
  if (char_list.empty()) {
    throw_invalid_argument("char_list: (empty)");
    return false;
  }
  const char *p = strpbrk(haystack.c_str(), char_list.c_str());
  if (p) {
    return String(p, CopyString);
  }
  return false;
}

Variant f_strchr(const String& haystack, CVarRef needle) {
  return f_strstr(haystack, needle);
}

Variant f_strpos(const String& haystack, CVarRef needle, int offset /* = 0 */) {
  if (offset < 0 || offset > haystack.size()) {
    raise_warning("Offset not contained in string");
    return false;
  }
  int pos;
  if (needle.isString()) {
    String n(needle.toString());
    if (n.length() == 0) {
      raise_warning("Empty delimiter");
      return false;
    }
    pos = haystack.find(n, offset);
  } else {
    pos = haystack.find(needle.toByte(), offset);
  }
  if (pos >= 0) return pos;
  return false;
}

Variant f_stripos(const String& haystack, CVarRef needle, int offset /* = 0 */) {
  if (offset < 0 || offset > haystack.size()) {
    raise_warning("Offset not contained in string");
    return false;
  }
  int pos;
  if (needle.isString()) {
    pos = haystack.find(needle.toString(), offset, false);
  } else {
    pos = haystack.find(needle.toByte(), offset, false);
  }
  if (pos >= 0) return pos;
  return false;
}

static bool is_valid_strrpos_args(
    const String& haystack,
    CVarRef needle,
    int offset) {
  if (haystack.size() == 0) {
    return false;
  }
  if (needle.isString() && needle.toString().size() == 0) {
    return false;
  }
  if (offset < -haystack.size() || offset > haystack.size()) {
    raise_warning("Offset is greater than the length of haystack string");
    return false;
  }
  return true;
}

Variant f_strrchr(const String& haystack, CVarRef needle) {
  if (haystack.size() == 0) {
    return false;
  }

  int pos;
  if (needle.isString() && needle.toString().size() > 0) {
    pos = haystack.rfind(needle.toString().data()[0], false);
  } else {
    pos = haystack.rfind(needle.toByte(), false);
  }
  if (pos < 0) return false;
  return haystack.substr(pos);
}

Variant f_strrpos(const String& haystack, CVarRef needle, int offset /* = 0 */) {
  if (!is_valid_strrpos_args(haystack, needle, offset)) {
    return false;
  }
  int pos;
  if (needle.isString()) {
    pos = haystack.rfind(needle.toString(), offset);
  } else {
    pos = haystack.rfind(needle.toByte(), offset);
  }
  if (pos >= 0) return pos;
  return false;
}

Variant f_strripos(const String& haystack, CVarRef needle, int offset /* = 0 */) {
  if (!is_valid_strrpos_args(haystack, needle, offset)) {
    return false;
  }
  int pos;
  if (needle.isString()) {
    pos = haystack.rfind(needle.toString(), offset, false);
  } else {
    pos = haystack.rfind(needle.toByte(), offset, false);
  }
  if (pos >= 0) return pos;
  return false;
}

Variant f_substr_count(const String& haystack, const String& needle, int offset /* = 0 */,
                       int length /* = 0x7FFFFFFF */) {
  int lenNeedle = needle.size();
  if (lenNeedle == 0) {
    throw_invalid_argument("needle: (empty)");
    return false;
  }

  if (offset < 0 || offset > haystack.size()) {
    throw_invalid_argument("offset: (out of range)");
    return false;
  }
  if (length == 0x7FFFFFFF) {
    length = haystack.size() - offset;
  } else if (length <= 0 || length > haystack.size() - offset) {
    throw_invalid_argument("length: (out of range)");
    return false;
  }

  int count = 0;
  int posMax = offset + length - lenNeedle;
  for (int pos = haystack.find(needle, offset);
       pos != -1 && pos <= posMax;
       pos = haystack.find(needle, pos + lenNeedle)) {
    ++count;
  }
  return count;
}

Variant f_strspn(const String& str1, const String& str2, int start /* = 0 */,
                 int length /* = 0x7FFFFFFF */) {
  const char *s1 = str1.data();
  const char *s2 = str2.data();
  int s1_len = str1.size();
  int s2_len = str2.size();

  if (!string_substr_check(s1_len, start, length)) {
    return false;
  }

  s1 += start;
  for (int pos = 0; pos < length; ++pos) {
    if (memchr(s2, *(s1++), s2_len) == NULL) return pos;
  }

  return length;
}

Variant f_strcspn(const String& str1, const String& str2, int start /* = 0 */,
                  int length /* = 0x7FFFFFFF */) {
  const char *s1 = str1.data();
  const char *s2 = str2.data();
  int s1_len = str1.size();
  int s2_len = str2.size();

  if (!string_substr_check(s1_len, start, length)) {
    return false;
  }

  s1 += start;
  for (int pos = 0; pos < length; ++pos) {
    if (memchr(s2, *(s1++), s2_len) != NULL) return pos;
  }

  return length;
}

Variant f_strlen(CVarRef vstr) {
  auto const cell = vstr.asCell();
  switch (cell->m_type) {
  case KindOfString:
  case KindOfStaticString:
    return Variant(cell->m_data.pstr->size());
  case KindOfArray:
    raise_warning("strlen() expects parameter 1 to be string, array given");
    return uninit_null();
  case KindOfResource:
    raise_warning("strlen() expects parameter 1 to be string, resource given");
    return uninit_null();
  case KindOfObject:
    if (!f_method_exists(vstr, "__toString")) {
      raise_warning("strlen() expects parameter 1 to be string, object given");
      return uninit_null();
    } //else fallback to default
  default:
    const String& str = vstr.toString();
    return Variant(str.size());
  }
}

Array f_str_getcsv(const String& str,
                   const String& delimiter /* = "," */,
                   const String& enclosure /* = "\"" */,
                   const String& escape /* = "\\" */) {
  if (str.empty()) {
    return Array::Create(null_variant);
  }

  auto check_arg = [](const String& arg, char default_arg) {
    return arg.size() > 0 ? arg[0] : default_arg;
  };

  char delimiter_char = check_arg(delimiter, ',');
  char enclosure_char = check_arg(enclosure, '"');
  char escape_char = check_arg(escape, '\\');

  auto dummy = NEWOBJ(PlainFile)();
  auto wrapper = Resource(dummy);
  return dummy->readCSV(0, delimiter_char, enclosure_char, escape_char, &str);
}

Variant f_count_chars(const String& str, int64_t mode /* = 0 */) {
  int chars[256];
  memset((void*)chars, 0, sizeof(chars));
  const unsigned char *buf = (const unsigned char *)str.data();
  for (int len = str.size(); len > 0; len--) {
    chars[*buf++]++;
  }

  Array retarr;
  char retstr[256];
  int retlen = 0;
  switch (mode) {
  case 0:
    for (int inx = 0; inx < 256; inx++) {
      retarr.set(inx, chars[inx]);
    }
    return retarr;
  case 1:
    for (int inx = 0; inx < 256; inx++) {
      if (chars[inx] != 0) {
        retarr.set(inx, chars[inx]);
      }
    }
    return retarr;
  case 2:
    for (int inx = 0; inx < 256; inx++) {
      if (chars[inx] == 0) {
        retarr.set(inx, chars[inx]);
      }
    }
    return retarr;
  case 3:
    for (int inx = 0; inx < 256; inx++) {
      if (chars[inx] != 0) {
        retstr[retlen++] = inx;
      }
    }
    return String(retstr, retlen, CopyString);
  case 4:
    for (int inx = 0; inx < 256; inx++) {
      if (chars[inx] == 0) {
        retstr[retlen++] = inx;
      }
    }
    return String(retstr, retlen, CopyString);
  }

  throw_invalid_argument("mode: %" PRId64, mode);
  return false;
}

/**
 * Counts the number of words inside a string. If format of 1 is specified,
 * then the function will return an array containing all the words
 * found inside the string. If format of 2 is specified, then the function
 * will return an associated array where the position of the word is the key
 * and the word itself is the value.
 *
 * For the purpose of this function, 'word' is defined as a locale dependent
 * string containing alphabetic characters, which also may contain, but not
 * start with "'" and "-" characters.
 */
Variant f_str_word_count(const String& str, int64_t format /* = 0 */,
                         const String& charlist /* = "" */) {
  int str_len = str.size();
  switch (format) {
  case 1:
  case 2:
    if (!str_len) {
      return Array::Create();
    }
    break;
  case 0:
    if (!str_len) {
      return 0LL;
    }
    break;
  default:
    throw_invalid_argument("format: %" PRId64, format);
    return false;
  }

  char ch[256];
  const char *char_list = charlist.data();
  if (*char_list) {
    string_charmask(char_list, charlist.size(), ch);
  } else {
    char_list = NULL;
  }

  int word_count = 0;
  const char *s0 = str.data();
  const char *p = s0;
  const char *e = p + str_len;

  // first character cannot be ' or -, unless explicitly allowed by the user
  if ((*p == '\'' && (!char_list || !ch[(int)'\''])) ||
      (*p == '-' && (!char_list || !ch[(int)'-']))) {
    p++;
  }

  // last character cannot be -, unless explicitly allowed by the user
  if (*(e - 1) == '-' && (!char_list || !ch[(int)'-'])) {
    e--;
  }

  Array ret;
  while (p < e) {
    const char *s = p;
    while (p < e &&
           (isalpha(*p) || (char_list && ch[(unsigned char)*p]) ||
            *p == '\'' || *p == '-')) {
      p++;
    }
    if (p > s) {
      switch (format) {
      case 1:
        ret.append(String(s, p - s, CopyString));
        break;
      case 2:
        ret.set((int)(s - s0), String(s, p - s, CopyString));
        break;
      default:
        word_count++;
        break;
      }
    }
    p++;
  }

  if (!format) {
    return word_count;
  }
  return ret.isNull() ? Array::Create() : ret;
}

int64_t f_levenshtein(const String& str1, const String& str2, int cost_ins /* = 1 */,
                         int cost_rep /* = 1 */, int cost_del /* = 1 */) {
  return string_levenshtein(str1.data(), str1.size(), str2.data(), str2.size(),
                            cost_ins, cost_rep, cost_del);
}

int64_t f_similar_text(const String& first, const String& second,
                       VRefParam percent /* = uninit_null() */) {
  float p;
  int ret = string_similar_text(first.data(), first.size(),
                                second.data(), second.size(), &p);
  percent = p;
  return ret;
}

Variant f_soundex(const String& str) {
  if (str.empty()) return false;
  return String(string_soundex(str.c_str()), AttachString);
}

Variant f_metaphone(const String& str, int phones /* = 0 */) {
  char *ret = string_metaphone(str.data(), str.size(), 0, 1);
  if (ret) {
    return String(ret, AttachString);
  }
  return false;
}

String f_html_entity_decode(const String& str, int flags /* = k_ENT_COMPAT */,
                            const String& charset /* = "ISO-8859-1" */) {
  const char *scharset = charset.data();
  if (!*scharset) scharset = "UTF-8";
  return StringUtil::HtmlDecode(str, StringUtil::toQuoteStyle(flags),
                                scharset, true);
}

String f_htmlentities(const String& str, int flags /* = k_ENT_COMPAT */,
                      const String& charset /* = "ISO-8859-1" */,
                      bool double_encode /* = true */) {
  // dropping double_encode parameters and see runtime/base/zend-html.h
  const char *scharset = charset.data();
  if (!*scharset) scharset = "UTF-8";
  return StringUtil::HtmlEncode(str, StringUtil::toQuoteStyle(flags),
                                scharset, true);
}

String f_htmlspecialchars_decode(const String& str,
                                 int flags /* = k_ENT_COMPAT */) {
  return StringUtil::HtmlDecode(str, StringUtil::toQuoteStyle(flags),
                                "UTF-8", false);
}

String f_htmlspecialchars(const String& str, int flags /* = k_ENT_COMPAT */,
                          const String& charset /* = "ISO-8859-1" */,
                          bool double_encode /* = true */) {
  // dropping double_encode parameters and see runtime/base/zend-html.h
  const char *scharset = charset.data();
  if (!*scharset) scharset = "UTF-8";
  return StringUtil::HtmlEncode(str, StringUtil::toQuoteStyle(flags),
                                scharset, false);
}

String f_fb_htmlspecialchars(const String& str, int flags /* = k_ENT_COMPAT */,
                             const String& charset /* = "ISO-8859-1" */,
                             CArrRef extra /* = Array() */) {
  return StringUtil::HtmlEncodeExtra(str, StringUtil::toQuoteStyle(flags),
                                     charset.data(), false, extra);
}

String f_quoted_printable_encode(const String& str) {
  return StringUtil::QuotedPrintableEncode(str);
}

String f_quoted_printable_decode(const String& str) {
  return StringUtil::QuotedPrintableDecode(str);
}

Variant f_convert_uudecode(const String& data) {
  String ret = StringUtil::UUDecode(data);
  if (ret.isNull()) {
    return false; // bad format
  }
  return ret;
}

Variant f_convert_uuencode(const String& data) {
  if (data.empty()) return false;
  return StringUtil::UUEncode(data);
}

String f_str_rot13(const String& str) {
  return StringUtil::ROT13(str);
}

int64_t f_crc32(const String& str) {
  return (uint32_t)StringUtil::CRC32(str);
}

String f_crypt(const String& str, const String& salt /* = "" */) {
  return StringUtil::Crypt(str, salt.c_str());
}

String f_md5(const String& str, bool raw_output /* = false */) {
  return StringUtil::MD5(str, raw_output);
}

String f_sha1(const String& str, bool raw_output /* = false */) {
  return StringUtil::SHA1(str, raw_output);
}

Variant f_strtr(const String& str, CVarRef from, CVarRef to /* = null_variant */) {
  if (str.empty()) {
    return str;
  }

  if (!to.isNull()) {
    return StringUtil::Translate(str, from.toString(), to.toString());
  }

  if (!from.is(KindOfArray)) {
    throw_invalid_argument("2nd argument: (not array)");
    return false;
  }

  int maxlen = 0;
  int minlen = -1;
  Array arr = from.toArray();

  if (arr.empty()) {
    // Nothing to translate
    return str;
  }

  for (ArrayIter iter(arr); iter; ++iter) {
    String search = iter.first();
    int len = search.size();
    if (len < 1) return false;
    if (maxlen < len) maxlen = len;
    if (minlen == -1 || minlen > len) minlen = len;
  }

  const char *s = str.data();
  int slen = str.size();
  String key(maxlen, ReserveString);

  StringBuffer result(slen);
  for (int pos = 0; pos < slen; ) {
    if ((pos + maxlen) > slen) {
      maxlen = slen - pos;
    }
    bool found = false;
    memcpy(key.bufferSlice().ptr, s + pos, maxlen);
    for (int len = maxlen; len >= minlen; len--) {
      key.setSize(len);
      if (arr.exists(key)) {
        String replace = arr[key].toString();
        if (!replace.empty()) {
          result.append(replace);
        }
        pos += len;
        found = true;
        break;
      }
    }
    if (!found) {
      result.append(s[pos++]);
    }
  }
  return result.detach();
}

void f_parse_str(const String& str, VRefParam arr /* = null */) {
  Variant result;

  HttpProtocol::DecodeParameters(result, str.data(), str.size());

  if(!arr.isReferenced()) {
    f_extract(result.toArray());
    return;
  }

  arr = result.toArray();
}

Variant f_setlocale(int _argc, int category, CVarRef locale, CArrRef _argv /* = null_array */) {
  Array argv = _argv;
  if (locale.is(KindOfArray)) {
    if (!argv.empty()) throw_invalid_argument("locale: not string)");
    argv = locale; // ignore _argv
  }

  for (int i = -1; i < argv.size(); i++) {
    String slocale;
    if (i == -1) {
      if (locale.is(KindOfArray)) continue;
      slocale = locale.toString();
    } else {
      slocale = argv[i].toString();
    }

    const char *loc = slocale.c_str();
    if (slocale.size() >= 255) {
      throw_invalid_argument("locale name is too long: %s", loc);
      return false;
    }
    if (strcmp("0", loc) == 0) {
      loc = NULL;
    }
    {
      Lock lock(s_mutex);
      const char *retval = setlocale(category, loc);
      if (retval) {
        return String(retval, CopyString);
      }
    }
  }
  return false;
}

const StaticString
  s_decimal_point("decimal_point"),
  s_thousands_sep("thousands_sep"),
  s_int_curr_symbol("int_curr_symbol"),
  s_currency_symbol("currency_symbol"),
  s_mon_decimal_point("mon_decimal_point"),
  s_mon_thousands_sep("mon_thousands_sep"),
  s_positive_sign("positive_sign"),
  s_negative_sign("negative_sign"),
  s_int_frac_digits("int_frac_digits"),
  s_frac_digits("frac_digits"),
  s_p_cs_precedes("p_cs_precedes"),
  s_p_sep_by_space("p_sep_by_space"),
  s_n_cs_precedes("n_cs_precedes"),
  s_n_sep_by_space("n_sep_by_space"),
  s_p_sign_posn("p_sign_posn"),
  s_n_sign_posn("n_sign_posn"),
  s_grouping("grouping"),
  s_mon_grouping("mon_grouping");

Array f_localeconv() {
  struct lconv currlocdata;
  {
    Lock lock(s_mutex);
    struct lconv *res = localeconv();
    currlocdata = *res;
  }

  Array ret;
#define SET_LOCALE_STRING(x) ret.set(s_ ## x, String(currlocdata.x, CopyString))
  SET_LOCALE_STRING(decimal_point);
  SET_LOCALE_STRING(thousands_sep);
  SET_LOCALE_STRING(int_curr_symbol);
  SET_LOCALE_STRING(currency_symbol);
  SET_LOCALE_STRING(mon_decimal_point);
  SET_LOCALE_STRING(mon_thousands_sep);
  SET_LOCALE_STRING(positive_sign);
  SET_LOCALE_STRING(negative_sign);
#define SET_LOCALE_INTEGER(x) ret.set(s_ ## x, currlocdata.x)
  SET_LOCALE_INTEGER(int_frac_digits);
  SET_LOCALE_INTEGER(frac_digits);
  SET_LOCALE_INTEGER(p_cs_precedes);
  SET_LOCALE_INTEGER(p_sep_by_space);
  SET_LOCALE_INTEGER(n_cs_precedes);
  SET_LOCALE_INTEGER(n_sep_by_space);
  SET_LOCALE_INTEGER(p_sign_posn);
  SET_LOCALE_INTEGER(n_sign_posn);

  Array grouping, mon_grouping;

  /* Grab the grouping data out of the array */
  int len = strlen(currlocdata.grouping);
  for (int i = 0; i < len; i++) {
    grouping.set(i, currlocdata.grouping[i]);
  }
  ret.set(s_grouping, grouping);

  /* Grab the monetary grouping data out of the array */
  len = strlen(currlocdata.mon_grouping);
  for (int i = 0; i < len; i++) {
    mon_grouping.set(i, currlocdata.mon_grouping[i]);
  }
  ret.set(s_mon_grouping, mon_grouping);

  return ret;
}

String f_nl_langinfo(int item) {
  return nl_langinfo(item);
}

String f_convert_cyr_string(const String& str, const String& from, const String& to) {
  char ch_from = from[0];
  char ch_to = to[0];
  char *ret = string_convert_cyrillic_string(str.data(), str.size(),
                                             ch_from, ch_to);
  return String(ret, str.size(), AttachString);
}

#define ENT_HTML_QUOTE_NONE     0
#define ENT_HTML_QUOTE_SINGLE   1
#define ENT_HTML_QUOTE_DOUBLE   2

static const HtmlBasicEntity basic_entities[] = {
  { '"',  "&quot;",   6,  ENT_HTML_QUOTE_DOUBLE },
  { '\'', "&#039;",   6,  ENT_HTML_QUOTE_SINGLE },
  { '\'', "&#39;",    5,  ENT_HTML_QUOTE_SINGLE },
  { '<',  "&lt;",     4,  0 },
  { '>',  "&gt;",     4,  0 },
  { 0, NULL, 0, 0 }
};

const StaticString
  s_amp("&"),
  s_ampsemi("&amp;");

Array f_get_html_translation_table(int table /* = 0 */,
                                   int flags /* = k_ENT_COMPAT */,
                                   const String& encoding /* = "UTF-8" */) {
  using namespace entity_charset_enum;

  auto charset = determine_charset(encoding.data());
  if (charset == cs_unknown) {
    charset = cs_utf_8;
    if (!encoding.empty()) {
      raise_warning("get_html_translation_table(): charset `%s' not supported"
                    ", assuming utf-8", encoding.data());
    }
  }

  const int HTML_SPECIALCHARS = 0;
  const int HTML_ENTITIES = 1;

  Array ret;
  switch (table) {
  case HTML_ENTITIES: {
    auto entity_map = html_get_entity_map();

    for (int j = 0; entity_map[j].charset != cs_terminator; j++) {
      const html_entity_map &em = entity_map[j];
      if (em.charset != charset)
        continue;

      for (int i = 0; i <= em.endchar - em.basechar; i++) {
        char buffer[16];

        if (em.table[i] == NULL)
          continue;
        /* what about wide chars here ?? */
        snprintf(buffer, sizeof(buffer), "&%s;", em.table[i]);
        ret.set(String::FromChar(i + em.basechar),
                String(buffer, CopyString));
      }
    }
    /* fall thru */
  }
  case HTML_SPECIALCHARS:
    for (int j = 0; basic_entities[j].charcode != 0; j++) {
      if (basic_entities[j].flags &&
          (flags & basic_entities[j].flags) == 0)
        continue;

      ret.set(String::FromChar(basic_entities[j].charcode),
              basic_entities[j].entity);
    }
    ret.set(s_amp, s_ampsemi);
    break;
  }

  return ret;
}

String f_hebrev(const String& hebrew_text, int max_chars_per_line /* = 0 */) {
  if (hebrew_text.empty()) return hebrew_text;
  return string_convert_hebrew_string(hebrew_text, max_chars_per_line, false);
}

String f_hebrevc(const String& hebrew_text, int max_chars_per_line /* = 0 */) {
  if (hebrew_text.empty()) return hebrew_text;
  return string_convert_hebrew_string(hebrew_text, max_chars_per_line, true);
}

///////////////////////////////////////////////////////////////////////////////
}
