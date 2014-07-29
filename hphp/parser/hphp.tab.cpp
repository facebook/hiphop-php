// @generated

/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         Compilerparse
#define yylex           Compilerlex
#define yyerror         Compilererror
#define yylval          Compilerlval
#define yychar          Compilerchar
#define yydebug         Compilerdebug
#define yynerrs         Compilernerrs
#define yylloc          Compilerlloc

/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "hphp.y"

// macros for bison
#define YYSTYPE HPHP::HPHP_PARSER_NS::Token
#define YYSTYPE_IS_TRIVIAL false
#define YYLTYPE HPHP::Location
#define YYLTYPE_IS_TRIVIAL true
#define YYERROR_VERBOSE
#define YYINITDEPTH 500
#define YYLEX_PARAM _p

#include "hphp/compiler/parser/parser.h"
#include <boost/lexical_cast.hpp>
#include "hphp/util/text-util.h"
#include "hphp/util/logger.h"

#ifdef yyerror
#undef yyerror
#endif
#define yyerror(loc,p,msg) p->parseFatal(loc,msg)

#ifdef YYLLOC_DEFAULT
# undef YYLLOC_DEFAULT
#endif
#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#define YYLLOC_DEFAULT(Current, Rhs, N)                                 \
  do                                                                    \
    if (N) {                                                            \
      (Current).first(YYRHSLOC (Rhs, 1));                               \
      (Current).last (YYRHSLOC (Rhs, N));                               \
    } else {                                                            \
      (Current).line0 = (Current).line1 = YYRHSLOC (Rhs, 0).line1;      \
      (Current).char0 = (Current).char1 = YYRHSLOC (Rhs, 0).char1;      \
    }                                                                   \
  while (0);                                                            \
  _p->setRuleLocation(&Current);

#define YYCOPY(To, From, Count)                  \
  do {                                           \
    YYSIZE_T yyi;                                \
    for (yyi = 0; yyi < (Count); yyi++) {        \
      (To)[yyi] = (From)[yyi];                   \
    }                                            \
    if (From != From ## a) {                     \
      YYSTACK_FREE (From);                       \
    }                                            \
  }                                              \
  while (0)

#define YYCOPY_RESET(To, From, Count)           \
  do                                            \
    {                                           \
      YYSIZE_T yyi;                             \
      for (yyi = 0; yyi < (Count); yyi++) {     \
        (To)[yyi] = (From)[yyi];                \
        (From)[yyi].reset();                    \
      }                                         \
      if (From != From ## a) {                  \
        YYSTACK_FREE (From);                    \
      }                                         \
    }                                           \
  while (0)

#define YYTOKEN_RESET(From, Count)              \
  do                                            \
    {                                           \
      YYSIZE_T yyi;                             \
      for (yyi = 0; yyi < (Count); yyi++) {     \
        (From)[yyi].reset();                    \
      }                                         \
      if (From != From ## a) {                  \
        YYSTACK_FREE (From);                    \
      }                                         \
    }                                           \
  while (0)

# define YYSTACK_RELOCATE_RESET(Stack_alloc, Stack)                     \
  do                                                                    \
    {                                                                   \
      YYSIZE_T yynewbytes;                                              \
      YYCOPY_RESET (&yyptr->Stack_alloc, Stack, yysize);                \
      Stack = &yyptr->Stack_alloc;                                      \
      yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
      yyptr += yynewbytes / sizeof (*yyptr);                            \
    }                                                                   \
  while (0)

#define YYSTACK_CLEANUP                         \
  YYTOKEN_RESET (yyvs, yystacksize);            \
  if (yyvs != yyvsa) {                          \
    YYSTACK_FREE (yyvs);                        \
  }                                             \
  if (yyls != yylsa) {                          \
    YYSTACK_FREE (yyls);                        \
  }                                             \


// macros for rules
#define BEXP(e...) _p->onBinaryOpExp(e);
#define UEXP(e...) _p->onUnaryOpExp(e);

using namespace HPHP::HPHP_PARSER_NS;

typedef HPHP::ClosureType ClosureType;

///////////////////////////////////////////////////////////////////////////////
// helpers

static void scalar_num(Parser *_p, Token &out, const char *num) {
  Token t;
  t.setText(num);
  _p->onScalar(out, T_LNUMBER, t);
}

static void scalar_num(Parser *_p, Token &out, int num) {
  Token t;
  t.setText(boost::lexical_cast<std::string>(num));
  _p->onScalar(out, T_LNUMBER, t);
}

static void scalar_null(Parser *_p, Token &out) {
  Token tnull; tnull.setText("null");
  _p->onConstantValue(out, tnull);
}

static void scalar_file(Parser *_p, Token &out) {
  Token file; file.setText("__FILE__");
  _p->onScalar(out, T_FILE, file);
}

static void scalar_line(Parser *_p, Token &out) {
  Token line; line.setText("__LINE__");
  _p->onScalar(out, T_LINE, line);
}

///////////////////////////////////////////////////////////////////////////////

static void constant_ae(Parser *_p, Token &out, Token &value) {
  const std::string& valueStr = value.text();
  if (valueStr.size() < 3 || valueStr.size() > 5 ||
      (strcasecmp("true", valueStr.c_str()) != 0 &&
       strcasecmp("false", valueStr.c_str()) != 0 &&
       strcasecmp("null", valueStr.c_str()) != 0 &&
       strcasecmp("inf", valueStr.c_str()) != 0 &&
       strcasecmp("nan", valueStr.c_str()) != 0)) {
    HPHP_PARSER_ERROR("User-defined constants are not allowed in user "
                      "attribute expressions", _p);
  }
  _p->onConstantValue(out, value);
}

///////////////////////////////////////////////////////////////////////////////

/**
 * XHP functions: They are defined here, so different parsers don't have to
 * handle XHP rules at all.
 */

static void xhp_tag(Parser *_p, Token &out, Token &label, Token &body) {
  if (!body.text().empty() && body.text() != label.text()) {
    HPHP_PARSER_ERROR("XHP: mismatched tag: '%s' not the same as '%s'",
                      _p, body.text().c_str(), label.text().c_str());
  }

  label.xhpLabel();
  Token name; _p->onName(name, label, Parser::StringName);
  _p->onNewObject(out, name, body);
}

static void xhp_attribute(Parser *_p, Token &out, Token &type, Token &label,
                          Token &def, Token &req) {
  /**
   * The bool, int, float, and string typenames are not given any special
   * treatment by the parser and are treated the same as regular class names
   * (which initially gets marked as type code 5). However, XHP wants to use
   * different type codes for bool, int, float, and string, so we need to fix
   * up the type code here to make XHP happy.
   */
  if (type.num() == 5) {
    auto* str = type.text().c_str();
    if (_p->scanner().isHHSyntaxEnabled()) {
      switch (type.text().size()) {
        case 6:
          if (!strcasecmp(str, "HH\\int")) {
            type.reset(); type.setNum(3);
          }
          break;
        case 7:
          if (!strcasecmp(str, "HH\\bool")) {
            type.reset(); type.setNum(2);
          }
          break;
        case 8:
          if (!strcasecmp(str, "HH\\float")) {
            type.reset(); type.setNum(8);
          } else if (!strcasecmp(str, "HH\\mixed")) {
            type.reset(); type.setNum(6);
          }
          break;
        case 9:
          if (!strcasecmp(str, "HH\\string")) {
            type.reset(); type.setNum(1);
          }
          break;
        default:
          break;
      }
    } else {
      switch (type.text().size()) {
        case 3:
          if (!strcasecmp(str, "int")) {
            type.reset(); type.setNum(3);
          }
          break;
        case 4:
          if (!strcasecmp(str, "bool")) {
            type.reset(); type.setNum(2);
          } else if (!strcasecmp(str, "real")) {
            type.reset(); type.setNum(8);
          }
          break;
        case 5:
          if (!strcasecmp(str, "float")) {
            type.reset(); type.setNum(8);
          } else if (!strcasecmp(str, "mixed")) {
            type.reset(); type.setNum(6);
          }
          break;
        case 6:
          if (!strcasecmp(str, "string")) {
            type.reset(); type.setNum(1);
          } else if (!strcasecmp(str, "double")) {
            type.reset(); type.setNum(8);
          }
          break;
        case 7:
          if (!strcasecmp(str, "integer")) {
            type.reset(); type.setNum(3);
          } else if (!strcasecmp(str, "boolean")) {
            type.reset(); type.setNum(2);
          }
          break;
        default:
          break;
      }
    }
  }

  Token num;  scalar_num(_p, num, type.num());
  Token arr1; _p->onArrayPair(arr1, 0, 0, num, 0);

  Token arr2;
  switch (type.num()) {
    case 5: /* class */ {
      Token cls; _p->onScalar(cls, T_CONSTANT_ENCAPSED_STRING, type);
      _p->onArrayPair(arr2, &arr1, 0, cls, 0);
      break;
    }
    case 7: /* enum */ {
      Token arr;   _p->onArray(arr, type);
      _p->onArrayPair(arr2, &arr1, 0, arr, 0);
      break;
    }
    default: {
      Token tnull; scalar_null(_p, tnull);
      _p->onArrayPair(arr2, &arr1, 0, tnull, 0);
      break;
    }
  }

  Token arr3; _p->onArrayPair(arr3, &arr2, 0, def, 0);
  Token arr4; _p->onArrayPair(arr4, &arr3, 0, req, 0);
  _p->onArray(out, arr4);
  out.setText(label);
}

static void xhp_attribute_list(Parser *_p, Token &out, Token *list,
                               Token &decl) {
  if (decl.num() == 0) {
    decl.xhpLabel();
    if (list) {
      out = *list;
      out.setText(list->text() + ":" + decl.text()); // avoiding vector<string>
    } else {
      out.setText(decl);
    }
  } else {
    Token name; _p->onScalar(name, T_CONSTANT_ENCAPSED_STRING, decl);
    _p->onArrayPair(out, list, &name, decl, 0);
    if (list) {
      out.setText(list->text());
    } else {
      out.setText("");
    }
  }
}

static void xhp_attribute_stmt(Parser *_p, Token &out, Token &attributes) {
  Token modifiers;
  Token fname; fname.setText("__xhpAttributeDeclaration");
  {
    Token m;
    Token m1; m1.setNum(T_PROTECTED); _p->onMemberModifier(m, NULL, m1);
    Token m2; m2.setNum(T_STATIC);    _p->onMemberModifier(modifiers, &m, m2);
  }
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  std::vector<std::string> classes;
  HPHP::split(':', attributes.text().c_str(), classes, true);
  Token arrAttributes; _p->onArray(arrAttributes, attributes);

  Token dummy;

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = -1;
    Token one;     scalar_num(_p, one, "1");
    Token mone;    UEXP(mone, one, '-', 1);
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &mone);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // if ($_ === -1) {
    //   $_ = array_merge(parent::__xhpAttributeDeclaration(),
    //                    attributes);
    // }
    Token parent;  parent.set(T_STRING, "parent");
    Token cls;     _p->onName(cls, parent, Parser::StringName);
    Token fname;   fname.setText("__xhpAttributeDeclaration");
    Token param1;  _p->onCall(param1, 0, fname, dummy, &cls);
    Token params1; _p->onCallParam(params1, NULL, param1, false, false);

    for (unsigned int i = 0; i < classes.size(); i++) {
      Token parent;  parent.set(T_STRING, classes[i]);
      Token cls;     _p->onName(cls, parent, Parser::StringName);
      Token fname;   fname.setText("__xhpAttributeDeclaration");
      Token param;   _p->onCall(param, 0, fname, dummy, &cls);

      Token params; _p->onCallParam(params, &params1, param, false, false);
      params1 = params;
    }

    Token params2; _p->onCallParam(params2, &params1, arrAttributes,
                                   false, false);

    Token name;    name.set(T_STRING, "array_merge");
    Token call;    _p->onCall(call, 0, name, params2, NULL);
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token assign;  _p->onAssign(assign, var, call, 0);
    Token exp;     _p->onExpStatement(exp, assign);
    Token block;   _p->onBlock(block, exp);

    Token tvar2;   tvar2.set(T_VARIABLE, "_");
    Token var2;    _p->onSimpleVariable(var2, tvar2);
    Token one;     scalar_num(_p, one, "1");
    Token mone;    UEXP(mone, one, '-', 1);
    Token cond;    BEXP(cond, var2, mone, T_IS_IDENTICAL);
    Token dummy1, dummy2;
    Token sif;     _p->onIf(sif, cond, block, dummy1, dummy2);
    _p->addStatement(stmts2, stmts1, sif);
  }
  Token stmts3;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts3, stmts2, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts3);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 1;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, nullptr, false);
  }
}

static void xhp_collect_attributes(Parser *_p, Token &out, Token &stmts) {
  Token *attr = _p->xhpGetAttributes();
  if (attr) {
    Token stmt;
    xhp_attribute_stmt(_p, stmt, *attr);
    _p->onClassStatement(out, stmts, stmt);
  } else {
    out = stmts;
  }
}

static void xhp_category_stmt(Parser *_p, Token &out, Token &categories) {
  Token fname;     fname.setText("__xhpCategoryDeclaration");
  Token m1;        m1.setNum(T_PROTECTED);
  Token modifiers; _p->onMemberModifier(modifiers, 0, m1);
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = categories;
    Token arr;     _p->onArray(arr, categories);
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &arr);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts2, stmts1, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts2);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 1;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, nullptr, false);
  }
}

static void xhp_children_decl_tag(Parser *_p, Token &arr, Token &tag) {
  Token num;  scalar_num(_p, num, tag.num());
  Token arr1; _p->onArrayPair(arr1, &arr, 0, num, 0);

  Token name;
  if (tag.num() == 3 || tag.num() == 4) {
    _p->onScalar(name, T_CONSTANT_ENCAPSED_STRING, tag);
  } else if (tag.num() >= 0) {
    scalar_null(_p, name);
  } else {
    HPHP_PARSER_ERROR("XHP: unknown children declaration", _p);
  }
  Token arr2; _p->onArrayPair(arr2, &arr1, 0, name, 0);
  arr = arr2;
}

static void xhp_children_decl(Parser *_p, Token &out, Token &op1, int op,
                              Token *op2) {
  Token num; scalar_num(_p, num, op);
  Token arr; _p->onArrayPair(arr, 0, 0, num, 0);

  if (op2) {
    Token arr1; _p->onArrayPair(arr1, &arr,  0, op1,  0);
    Token arr2; _p->onArrayPair(arr2, &arr1, 0, *op2, 0);
    _p->onArray(out, arr2);
  } else {
    xhp_children_decl_tag(_p, arr, op1);
    _p->onArray(out, arr);
  }
}

static void xhp_children_paren(Parser *_p, Token &out, Token exp, int op) {
  Token num;  scalar_num(_p, num, op);
  Token arr1; _p->onArrayPair(arr1, 0, 0, num, 0);

  Token num5; scalar_num(_p, num5, 5);
  Token arr2; _p->onArrayPair(arr2, &arr1, 0, num5, 0);

  Token arr3; _p->onArrayPair(arr3, &arr2, 0, exp, 0);
  _p->onArray(out, arr3);
}

static void xhp_children_stmt(Parser *_p, Token &out, Token &children) {
  Token fname;     fname.setText("__xhpChildrenDeclaration");
  Token m1;        m1.setNum(T_PROTECTED);
  Token modifiers; _p->onMemberModifier(modifiers, 0, m1);
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = children;
    Token arr;
    if (children.num() == 2) {
      arr = children;
    } else if (children.num() >= 0) {
      scalar_num(_p, arr, children.num());
    } else {
      HPHP_PARSER_ERROR("XHP: XHP unknown children declaration", _p);
    }
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &arr);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts2, stmts1, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts2);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 1;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, nullptr, false);
  }
}

static void only_in_hh_syntax(Parser *_p) {
  if (!_p->scanner().isHHSyntaxEnabled()) {
    HPHP_PARSER_ERROR(
      "Syntax only allowed with -v Eval.EnableHipHopSyntax=true", _p);
  }
}

static void validate_hh_variadic_variant(Parser* _p,
                                         Token& userAttrs, Token& typehint,
                                         Token* mod) {
  if (!userAttrs.text().empty() || !typehint.text().empty() ||
     (mod && !mod->text().empty())) {
    HPHP_PARSER_ERROR("Variadic '...' should be followed by a '$variable'", _p);
  }
  only_in_hh_syntax(_p);
}

// Shapes may not have leading integers in key names, considered as a
// parse time error.  This is because at runtime they are currently
// hphp arrays, which will treat leading integer keys as numbers.
static void validate_shape_keyname(Token& tok, Parser* _p) {
  if (tok.text().empty()) {
    HPHP_PARSER_ERROR("Shape key names may not be empty", _p);
  }
  if (isdigit(tok.text()[0])) {
    HPHP_PARSER_ERROR("Shape key names may not start with integers", _p);
  }
}

///////////////////////////////////////////////////////////////////////////////

static int yylex(YYSTYPE *token, HPHP::Location *loc, Parser *_p) {
  return _p->scan(token, loc);
}


/* Line 189 of yacc.c  */
#line 644 "hphp.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_REQUIRE_ONCE = 258,
     T_REQUIRE = 259,
     T_EVAL = 260,
     T_INCLUDE_ONCE = 261,
     T_INCLUDE = 262,
     T_LAMBDA_ARROW = 263,
     T_LOGICAL_OR = 264,
     T_LOGICAL_XOR = 265,
     T_LOGICAL_AND = 266,
     T_PRINT = 267,
     T_POW_EQUAL = 268,
     T_SR_EQUAL = 269,
     T_SL_EQUAL = 270,
     T_XOR_EQUAL = 271,
     T_OR_EQUAL = 272,
     T_AND_EQUAL = 273,
     T_MOD_EQUAL = 274,
     T_CONCAT_EQUAL = 275,
     T_DIV_EQUAL = 276,
     T_MUL_EQUAL = 277,
     T_MINUS_EQUAL = 278,
     T_PLUS_EQUAL = 279,
     T_YIELD = 280,
     T_AWAIT = 281,
     T_BOOLEAN_OR = 282,
     T_BOOLEAN_AND = 283,
     T_IS_NOT_IDENTICAL = 284,
     T_IS_IDENTICAL = 285,
     T_IS_NOT_EQUAL = 286,
     T_IS_EQUAL = 287,
     T_IS_GREATER_OR_EQUAL = 288,
     T_IS_SMALLER_OR_EQUAL = 289,
     T_SR = 290,
     T_SL = 291,
     T_INSTANCEOF = 292,
     T_UNSET_CAST = 293,
     T_BOOL_CAST = 294,
     T_OBJECT_CAST = 295,
     T_ARRAY_CAST = 296,
     T_STRING_CAST = 297,
     T_DOUBLE_CAST = 298,
     T_INT_CAST = 299,
     T_DEC = 300,
     T_INC = 301,
     T_POW = 302,
     T_CLONE = 303,
     T_NEW = 304,
     T_EXIT = 305,
     T_IF = 306,
     T_ELSEIF = 307,
     T_ELSE = 308,
     T_ENDIF = 309,
     T_LNUMBER = 310,
     T_DNUMBER = 311,
     T_ONUMBER = 312,
     T_STRING = 313,
     T_STRING_VARNAME = 314,
     T_VARIABLE = 315,
     T_NUM_STRING = 316,
     T_INLINE_HTML = 317,
     T_CHARACTER = 318,
     T_BAD_CHARACTER = 319,
     T_ENCAPSED_AND_WHITESPACE = 320,
     T_CONSTANT_ENCAPSED_STRING = 321,
     T_ECHO = 322,
     T_DO = 323,
     T_WHILE = 324,
     T_ENDWHILE = 325,
     T_FOR = 326,
     T_ENDFOR = 327,
     T_FOREACH = 328,
     T_ENDFOREACH = 329,
     T_DECLARE = 330,
     T_ENDDECLARE = 331,
     T_AS = 332,
     T_SWITCH = 333,
     T_ENDSWITCH = 334,
     T_CASE = 335,
     T_DEFAULT = 336,
     T_BREAK = 337,
     T_GOTO = 338,
     T_CONTINUE = 339,
     T_FUNCTION = 340,
     T_CONST = 341,
     T_RETURN = 342,
     T_TRY = 343,
     T_CATCH = 344,
     T_THROW = 345,
     T_USE = 346,
     T_GLOBAL = 347,
     T_PUBLIC = 348,
     T_PROTECTED = 349,
     T_PRIVATE = 350,
     T_FINAL = 351,
     T_ABSTRACT = 352,
     T_STATIC = 353,
     T_VAR = 354,
     T_UNSET = 355,
     T_ISSET = 356,
     T_EMPTY = 357,
     T_HALT_COMPILER = 358,
     T_CLASS = 359,
     T_INTERFACE = 360,
     T_EXTENDS = 361,
     T_IMPLEMENTS = 362,
     T_OBJECT_OPERATOR = 363,
     T_DOUBLE_ARROW = 364,
     T_LIST = 365,
     T_ARRAY = 366,
     T_CALLABLE = 367,
     T_CLASS_C = 368,
     T_METHOD_C = 369,
     T_FUNC_C = 370,
     T_LINE = 371,
     T_FILE = 372,
     T_COMMENT = 373,
     T_DOC_COMMENT = 374,
     T_OPEN_TAG = 375,
     T_OPEN_TAG_WITH_ECHO = 376,
     T_CLOSE_TAG = 377,
     T_WHITESPACE = 378,
     T_START_HEREDOC = 379,
     T_END_HEREDOC = 380,
     T_DOLLAR_OPEN_CURLY_BRACES = 381,
     T_CURLY_OPEN = 382,
     T_DOUBLE_COLON = 383,
     T_NAMESPACE = 384,
     T_NS_C = 385,
     T_DIR = 386,
     T_NS_SEPARATOR = 387,
     T_XHP_LABEL = 388,
     T_XHP_TEXT = 389,
     T_XHP_ATTRIBUTE = 390,
     T_XHP_CATEGORY = 391,
     T_XHP_CATEGORY_LABEL = 392,
     T_XHP_CHILDREN = 393,
     T_XHP_ENUM = 394,
     T_XHP_REQUIRED = 395,
     T_TRAIT = 396,
     T_ELLIPSIS = 397,
     T_INSTEADOF = 398,
     T_TRAIT_C = 399,
     T_HH_ERROR = 400,
     T_FINALLY = 401,
     T_XHP_TAG_LT = 402,
     T_XHP_TAG_GT = 403,
     T_TYPELIST_LT = 404,
     T_TYPELIST_GT = 405,
     T_UNRESOLVED_LT = 406,
     T_COLLECTION = 407,
     T_SHAPE = 408,
     T_TYPE = 409,
     T_UNRESOLVED_TYPE = 410,
     T_NEWTYPE = 411,
     T_UNRESOLVED_NEWTYPE = 412,
     T_COMPILER_HALT_OFFSET = 413,
     T_ASYNC = 414,
     T_FROM = 415,
     T_WHERE = 416,
     T_JOIN = 417,
     T_IN = 418,
     T_ON = 419,
     T_EQUALS = 420,
     T_INTO = 421,
     T_LET = 422,
     T_ORDERBY = 423,
     T_ASCENDING = 424,
     T_DESCENDING = 425,
     T_SELECT = 426,
     T_GROUP = 427,
     T_BY = 428,
     T_LAMBDA_OP = 429,
     T_LAMBDA_CP = 430,
     T_UNRESOLVED_OP = 431
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int line0;
  int char0;
  int line1;
  int char1;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 875 "hphp.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
struct yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (struct yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   15974

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  206
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  252
/* YYNRULES -- Number of rules.  */
#define YYNRULES  879
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1649

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   431

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,   204,     2,   201,    51,    35,   205,
     196,   197,    49,    46,     9,    47,    48,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,   198,
      40,    14,    41,    29,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,   203,    34,     2,   202,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   199,    33,   200,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,    10,    11,    12,    13,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    31,    32,    36,    37,    38,    39,    42,    43,
      44,    45,    53,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    11,    13,    15,    17,
      19,    21,    26,    30,    31,    38,    39,    45,    49,    54,
      59,    62,    64,    66,    68,    70,    72,    74,    76,    78,
      80,    82,    84,    86,    88,    90,    92,    94,    96,    98,
     100,   104,   106,   110,   112,   116,   118,   120,   123,   127,
     132,   134,   137,   141,   146,   148,   151,   155,   160,   162,
     166,   168,   172,   175,   177,   180,   183,   189,   194,   197,
     198,   200,   202,   204,   206,   210,   216,   225,   226,   231,
     232,   239,   240,   251,   252,   257,   260,   264,   267,   271,
     274,   278,   282,   286,   290,   294,   300,   302,   304,   305,
     315,   316,   327,   333,   334,   348,   349,   355,   359,   363,
     366,   369,   372,   375,   378,   381,   385,   388,   391,   395,
     398,   399,   404,   414,   415,   416,   421,   424,   425,   427,
     428,   430,   431,   441,   442,   453,   454,   466,   467,   476,
     477,   487,   488,   496,   497,   506,   507,   515,   516,   525,
     527,   529,   531,   533,   535,   538,   541,   544,   545,   548,
     549,   552,   553,   555,   559,   561,   565,   568,   569,   571,
     574,   579,   581,   586,   588,   593,   595,   600,   602,   607,
     611,   617,   621,   626,   631,   637,   643,   648,   649,   651,
     653,   658,   659,   665,   666,   669,   670,   674,   675,   683,
     690,   693,   699,   704,   705,   710,   716,   724,   731,   738,
     746,   756,   765,   772,   778,   781,   786,   790,   791,   795,
     800,   807,   813,   819,   826,   835,   843,   846,   847,   849,
     852,   855,   859,   864,   869,   873,   875,   877,   880,   885,
     889,   895,   897,   901,   904,   905,   906,   911,   912,   918,
     921,   922,   933,   934,   946,   950,   954,   958,   963,   968,
     972,   978,   981,   984,   985,   992,   998,  1003,  1007,  1009,
    1011,  1015,  1020,  1022,  1024,  1026,  1028,  1033,  1035,  1037,
    1041,  1044,  1045,  1048,  1049,  1051,  1055,  1057,  1059,  1061,
    1063,  1067,  1072,  1077,  1082,  1084,  1086,  1089,  1092,  1095,
    1099,  1103,  1105,  1107,  1109,  1111,  1115,  1117,  1121,  1123,
    1125,  1127,  1128,  1130,  1133,  1135,  1137,  1139,  1141,  1143,
    1145,  1147,  1149,  1150,  1152,  1154,  1156,  1160,  1166,  1168,
    1172,  1178,  1183,  1187,  1191,  1194,  1196,  1198,  1202,  1206,
    1208,  1210,  1211,  1214,  1219,  1223,  1230,  1233,  1237,  1244,
    1246,  1248,  1250,  1257,  1261,  1266,  1273,  1277,  1281,  1285,
    1289,  1293,  1297,  1301,  1305,  1309,  1313,  1317,  1321,  1324,
    1327,  1330,  1333,  1337,  1341,  1345,  1349,  1353,  1357,  1361,
    1365,  1369,  1373,  1377,  1381,  1385,  1389,  1393,  1397,  1401,
    1404,  1407,  1410,  1413,  1417,  1421,  1425,  1429,  1433,  1437,
    1441,  1445,  1449,  1453,  1459,  1464,  1466,  1469,  1472,  1475,
    1478,  1481,  1484,  1487,  1490,  1493,  1495,  1497,  1499,  1503,
    1506,  1508,  1510,  1512,  1518,  1519,  1520,  1532,  1533,  1546,
    1547,  1551,  1552,  1559,  1562,  1567,  1569,  1571,  1577,  1581,
    1587,  1591,  1594,  1595,  1598,  1599,  1604,  1609,  1613,  1618,
    1623,  1628,  1633,  1635,  1637,  1639,  1643,  1646,  1650,  1655,
    1658,  1662,  1664,  1667,  1669,  1672,  1674,  1676,  1678,  1680,
    1682,  1684,  1689,  1694,  1697,  1706,  1717,  1720,  1722,  1726,
    1728,  1731,  1733,  1735,  1737,  1739,  1742,  1747,  1751,  1755,
    1760,  1762,  1765,  1770,  1773,  1780,  1781,  1783,  1788,  1789,
    1792,  1793,  1795,  1797,  1801,  1803,  1807,  1809,  1811,  1815,
    1819,  1821,  1823,  1825,  1827,  1829,  1831,  1833,  1835,  1837,
    1839,  1841,  1843,  1845,  1847,  1849,  1851,  1853,  1855,  1857,
    1859,  1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,  1877,
    1879,  1881,  1883,  1885,  1887,  1889,  1891,  1893,  1895,  1897,
    1899,  1901,  1903,  1905,  1907,  1909,  1911,  1913,  1915,  1917,
    1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1935,  1937,
    1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,  1957,
    1959,  1961,  1963,  1965,  1967,  1969,  1971,  1973,  1975,  1977,
    1979,  1984,  1986,  1988,  1990,  1992,  1994,  1996,  1998,  2000,
    2003,  2005,  2006,  2007,  2009,  2011,  2015,  2016,  2018,  2020,
    2022,  2024,  2026,  2028,  2030,  2032,  2034,  2036,  2038,  2040,
    2042,  2046,  2049,  2051,  2053,  2058,  2062,  2067,  2069,  2071,
    2075,  2079,  2083,  2087,  2091,  2095,  2099,  2103,  2107,  2111,
    2115,  2119,  2123,  2127,  2131,  2135,  2139,  2143,  2146,  2149,
    2152,  2155,  2159,  2163,  2167,  2171,  2175,  2179,  2183,  2187,
    2193,  2198,  2202,  2206,  2210,  2212,  2214,  2216,  2218,  2222,
    2226,  2230,  2233,  2234,  2236,  2237,  2239,  2240,  2246,  2250,
    2254,  2256,  2258,  2260,  2262,  2264,  2268,  2271,  2273,  2275,
    2277,  2279,  2281,  2283,  2286,  2289,  2294,  2298,  2303,  2306,
    2307,  2313,  2317,  2321,  2323,  2327,  2329,  2332,  2333,  2339,
    2343,  2346,  2347,  2351,  2352,  2357,  2360,  2361,  2365,  2369,
    2371,  2372,  2374,  2377,  2380,  2385,  2389,  2393,  2396,  2401,
    2404,  2409,  2411,  2413,  2415,  2417,  2419,  2422,  2427,  2431,
    2436,  2440,  2442,  2444,  2446,  2448,  2451,  2456,  2461,  2465,
    2467,  2469,  2473,  2481,  2488,  2497,  2507,  2516,  2527,  2535,
    2542,  2551,  2553,  2556,  2561,  2566,  2568,  2570,  2575,  2577,
    2578,  2580,  2583,  2585,  2587,  2590,  2595,  2599,  2603,  2604,
    2606,  2609,  2614,  2618,  2621,  2625,  2632,  2633,  2635,  2640,
    2643,  2644,  2650,  2654,  2658,  2660,  2667,  2672,  2677,  2680,
    2683,  2684,  2690,  2694,  2698,  2700,  2703,  2704,  2710,  2714,
    2718,  2720,  2723,  2726,  2728,  2731,  2733,  2738,  2742,  2746,
    2753,  2757,  2759,  2761,  2763,  2768,  2773,  2778,  2783,  2786,
    2789,  2794,  2797,  2800,  2802,  2806,  2810,  2814,  2815,  2818,
    2824,  2831,  2833,  2836,  2838,  2843,  2847,  2848,  2850,  2854,
    2857,  2861,  2863,  2865,  2866,  2867,  2870,  2874,  2876,  2882,
    2886,  2890,  2896,  2900,  2902,  2905,  2906,  2911,  2914,  2917,
    2919,  2921,  2923,  2925,  2930,  2937,  2939,  2948,  2955,  2957
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     207,     0,    -1,    -1,   208,   209,    -1,   209,   210,    -1,
      -1,   228,    -1,   245,    -1,   249,    -1,   254,    -1,   443,
      -1,   122,   196,   197,   198,    -1,   148,   220,   198,    -1,
      -1,   148,   220,   199,   211,   209,   200,    -1,    -1,   148,
     199,   212,   209,   200,    -1,   110,   214,   198,    -1,   110,
     104,   215,   198,    -1,   110,   105,   216,   198,    -1,   225,
     198,    -1,    77,    -1,   154,    -1,   155,    -1,   157,    -1,
     159,    -1,   158,    -1,   180,    -1,   181,    -1,   183,    -1,
     182,    -1,   184,    -1,   185,    -1,   186,    -1,   187,    -1,
     188,    -1,   189,    -1,   190,    -1,   191,    -1,   192,    -1,
     214,     9,   217,    -1,   217,    -1,   218,     9,   218,    -1,
     218,    -1,   219,     9,   219,    -1,   219,    -1,   220,    -1,
     151,   220,    -1,   220,    96,   213,    -1,   151,   220,    96,
     213,    -1,   220,    -1,   151,   220,    -1,   220,    96,   213,
      -1,   151,   220,    96,   213,    -1,   220,    -1,   151,   220,
      -1,   220,    96,   213,    -1,   151,   220,    96,   213,    -1,
     213,    -1,   220,   151,   213,    -1,   220,    -1,   148,   151,
     220,    -1,   151,   220,    -1,   221,    -1,   221,   446,    -1,
     221,   446,    -1,   225,     9,   444,    14,   390,    -1,   105,
     444,    14,   390,    -1,   226,   227,    -1,    -1,   228,    -1,
     245,    -1,   249,    -1,   254,    -1,   199,   226,   200,    -1,
      70,   322,   228,   276,   278,    -1,    70,   322,    30,   226,
     277,   279,    73,   198,    -1,    -1,    88,   322,   229,   270,
      -1,    -1,    87,   230,   228,    88,   322,   198,    -1,    -1,
      90,   196,   324,   198,   324,   198,   324,   197,   231,   268,
      -1,    -1,    97,   322,   232,   273,    -1,   101,   198,    -1,
     101,   331,   198,    -1,   103,   198,    -1,   103,   331,   198,
      -1,   106,   198,    -1,   106,   331,   198,    -1,    27,   101,
     198,    -1,   111,   286,   198,    -1,   117,   288,   198,    -1,
      86,   323,   198,    -1,   119,   196,   440,   197,   198,    -1,
     198,    -1,    81,    -1,    -1,    92,   196,   331,    96,   267,
     266,   197,   233,   269,    -1,    -1,    92,   196,   331,    28,
      96,   267,   266,   197,   234,   269,    -1,    94,   196,   272,
     197,   271,    -1,    -1,   107,   237,   108,   196,   383,    79,
     197,   199,   226,   200,   239,   235,   242,    -1,    -1,   107,
     237,   165,   236,   240,    -1,   109,   331,   198,    -1,   102,
     213,   198,    -1,   331,   198,    -1,   325,   198,    -1,   326,
     198,    -1,   327,   198,    -1,   328,   198,    -1,   329,   198,
      -1,   106,   328,   198,    -1,   330,   198,    -1,   353,   198,
      -1,   106,   352,   198,    -1,   213,    30,    -1,    -1,   199,
     238,   226,   200,    -1,   239,   108,   196,   383,    79,   197,
     199,   226,   200,    -1,    -1,    -1,   199,   241,   226,   200,
      -1,   165,   240,    -1,    -1,    35,    -1,    -1,   104,    -1,
      -1,   244,   243,   445,   246,   196,   282,   197,   450,   311,
      -1,    -1,   315,   244,   243,   445,   247,   196,   282,   197,
     450,   311,    -1,    -1,   410,   314,   244,   243,   445,   248,
     196,   282,   197,   450,   311,    -1,    -1,   260,   257,   250,
     261,   262,   199,   289,   200,    -1,    -1,   410,   260,   257,
     251,   261,   262,   199,   289,   200,    -1,    -1,   124,   258,
     252,   263,   199,   289,   200,    -1,    -1,   410,   124,   258,
     253,   263,   199,   289,   200,    -1,    -1,   160,   259,   255,
     262,   199,   289,   200,    -1,    -1,   410,   160,   259,   256,
     262,   199,   289,   200,    -1,   445,    -1,   152,    -1,   445,
      -1,   445,    -1,   123,    -1,   116,   123,    -1,   115,   123,
      -1,   125,   383,    -1,    -1,   126,   264,    -1,    -1,   125,
     264,    -1,    -1,   383,    -1,   264,     9,   383,    -1,   383,
      -1,   265,     9,   383,    -1,   128,   267,    -1,    -1,   417,
      -1,    35,   417,    -1,   129,   196,   429,   197,    -1,   228,
      -1,    30,   226,    91,   198,    -1,   228,    -1,    30,   226,
      93,   198,    -1,   228,    -1,    30,   226,    89,   198,    -1,
     228,    -1,    30,   226,    95,   198,    -1,   213,    14,   390,
      -1,   272,     9,   213,    14,   390,    -1,   199,   274,   200,
      -1,   199,   198,   274,   200,    -1,    30,   274,    98,   198,
      -1,    30,   198,   274,    98,   198,    -1,   274,    99,   331,
     275,   226,    -1,   274,   100,   275,   226,    -1,    -1,    30,
      -1,   198,    -1,   276,    71,   322,   228,    -1,    -1,   277,
      71,   322,    30,   226,    -1,    -1,    72,   228,    -1,    -1,
      72,    30,   226,    -1,    -1,   281,     9,   411,   317,   457,
     161,    79,    -1,   281,     9,   411,   317,   457,   161,    -1,
     281,   395,    -1,   411,   317,   457,   161,    79,    -1,   411,
     317,   457,   161,    -1,    -1,   411,   317,   457,    79,    -1,
     411,   317,   457,    35,    79,    -1,   411,   317,   457,    35,
      79,    14,   390,    -1,   411,   317,   457,    79,    14,   390,
      -1,   281,     9,   411,   317,   457,    79,    -1,   281,     9,
     411,   317,   457,    35,    79,    -1,   281,     9,   411,   317,
     457,    35,    79,    14,   390,    -1,   281,     9,   411,   317,
     457,    79,    14,   390,    -1,   283,     9,   411,   457,   161,
      79,    -1,   283,     9,   411,   457,   161,    -1,   283,   395,
      -1,   411,   457,   161,    79,    -1,   411,   457,   161,    -1,
      -1,   411,   457,    79,    -1,   411,   457,    35,    79,    -1,
     411,   457,    35,    79,    14,   390,    -1,   411,   457,    79,
      14,   390,    -1,   283,     9,   411,   457,    79,    -1,   283,
       9,   411,   457,    35,    79,    -1,   283,     9,   411,   457,
      35,    79,    14,   390,    -1,   283,     9,   411,   457,    79,
      14,   390,    -1,   285,   395,    -1,    -1,   331,    -1,    35,
     417,    -1,   161,   331,    -1,   285,     9,   331,    -1,   285,
       9,   161,   331,    -1,   285,     9,    35,   417,    -1,   286,
       9,   287,    -1,   287,    -1,    79,    -1,   201,   417,    -1,
     201,   199,   331,   200,    -1,   288,     9,    79,    -1,   288,
       9,    79,    14,   390,    -1,    79,    -1,    79,    14,   390,
      -1,   289,   290,    -1,    -1,    -1,   313,   291,   319,   198,
      -1,    -1,   315,   456,   292,   319,   198,    -1,   320,   198,
      -1,    -1,   314,   244,   243,   445,   196,   293,   280,   197,
     450,   312,    -1,    -1,   410,   314,   244,   243,   445,   196,
     294,   280,   197,   450,   312,    -1,   154,   299,   198,    -1,
     155,   305,   198,    -1,   157,   307,   198,    -1,     4,   125,
     383,   198,    -1,     4,   126,   383,   198,    -1,   110,   265,
     198,    -1,   110,   265,   199,   295,   200,    -1,   295,   296,
      -1,   295,   297,    -1,    -1,   224,   147,   213,   162,   265,
     198,    -1,   298,    96,   314,   213,   198,    -1,   298,    96,
     315,   198,    -1,   224,   147,   213,    -1,   213,    -1,   300,
      -1,   299,     9,   300,    -1,   301,   380,   303,   304,    -1,
     152,    -1,   130,    -1,   383,    -1,   118,    -1,   158,   199,
     302,   200,    -1,   131,    -1,   389,    -1,   302,     9,   389,
      -1,    14,   390,    -1,    -1,    55,   159,    -1,    -1,   306,
      -1,   305,     9,   306,    -1,   156,    -1,   308,    -1,   213,
      -1,   121,    -1,   196,   309,   197,    -1,   196,   309,   197,
      49,    -1,   196,   309,   197,    29,    -1,   196,   309,   197,
      46,    -1,   308,    -1,   310,    -1,   310,    49,    -1,   310,
      29,    -1,   310,    46,    -1,   309,     9,   309,    -1,   309,
      33,   309,    -1,   213,    -1,   152,    -1,   156,    -1,   198,
      -1,   199,   226,   200,    -1,   198,    -1,   199,   226,   200,
      -1,   315,    -1,   118,    -1,   315,    -1,    -1,   316,    -1,
     315,   316,    -1,   112,    -1,   113,    -1,   114,    -1,   117,
      -1,   116,    -1,   115,    -1,   178,    -1,   318,    -1,    -1,
     112,    -1,   113,    -1,   114,    -1,   319,     9,    79,    -1,
     319,     9,    79,    14,   390,    -1,    79,    -1,    79,    14,
     390,    -1,   320,     9,   444,    14,   390,    -1,   105,   444,
      14,   390,    -1,   196,   321,   197,    -1,    68,   385,   388,
      -1,    67,   331,    -1,   372,    -1,   348,    -1,   196,   331,
     197,    -1,   323,     9,   331,    -1,   331,    -1,   323,    -1,
      -1,    27,   331,    -1,    27,   331,   128,   331,    -1,   417,
      14,   325,    -1,   129,   196,   429,   197,    14,   325,    -1,
      28,   331,    -1,   417,    14,   328,    -1,   129,   196,   429,
     197,    14,   328,    -1,   332,    -1,   417,    -1,   321,    -1,
     129,   196,   429,   197,    14,   331,    -1,   417,    14,   331,
      -1,   417,    14,    35,   417,    -1,   417,    14,    35,    68,
     385,   388,    -1,   417,    26,   331,    -1,   417,    25,   331,
      -1,   417,    24,   331,    -1,   417,    23,   331,    -1,   417,
      22,   331,    -1,   417,    21,   331,    -1,   417,    20,   331,
      -1,   417,    19,   331,    -1,   417,    18,   331,    -1,   417,
      17,   331,    -1,   417,    16,   331,    -1,   417,    15,   331,
      -1,   417,    64,    -1,    64,   417,    -1,   417,    63,    -1,
      63,   417,    -1,   331,    31,   331,    -1,   331,    32,   331,
      -1,   331,    10,   331,    -1,   331,    12,   331,    -1,   331,
      11,   331,    -1,   331,    33,   331,    -1,   331,    35,   331,
      -1,   331,    34,   331,    -1,   331,    48,   331,    -1,   331,
      46,   331,    -1,   331,    47,   331,    -1,   331,    49,   331,
      -1,   331,    50,   331,    -1,   331,    65,   331,    -1,   331,
      51,   331,    -1,   331,    45,   331,    -1,   331,    44,   331,
      -1,    46,   331,    -1,    47,   331,    -1,    52,   331,    -1,
      54,   331,    -1,   331,    37,   331,    -1,   331,    36,   331,
      -1,   331,    39,   331,    -1,   331,    38,   331,    -1,   331,
      40,   331,    -1,   331,    43,   331,    -1,   331,    41,   331,
      -1,   331,    42,   331,    -1,   331,    53,   385,    -1,   196,
     332,   197,    -1,   331,    29,   331,    30,   331,    -1,   331,
      29,    30,   331,    -1,   439,    -1,    62,   331,    -1,    61,
     331,    -1,    60,   331,    -1,    59,   331,    -1,    58,   331,
      -1,    57,   331,    -1,    56,   331,    -1,    69,   386,    -1,
      55,   331,    -1,   392,    -1,   347,    -1,   346,    -1,   202,
     387,   202,    -1,    13,   331,    -1,   334,    -1,   337,    -1,
     350,    -1,   110,   196,   371,   395,   197,    -1,    -1,    -1,
     244,   243,   196,   335,   282,   197,   450,   333,   199,   226,
     200,    -1,    -1,   315,   244,   243,   196,   336,   282,   197,
     450,   333,   199,   226,   200,    -1,    -1,    79,   338,   340,
      -1,    -1,   193,   339,   282,   194,   450,   340,    -1,     8,
     331,    -1,     8,   199,   226,   200,    -1,    85,    -1,   441,
      -1,   342,     9,   341,   128,   331,    -1,   341,   128,   331,
      -1,   343,     9,   341,   128,   390,    -1,   341,   128,   390,
      -1,   342,   394,    -1,    -1,   343,   394,    -1,    -1,   172,
     196,   344,   197,    -1,   130,   196,   430,   197,    -1,    66,
     430,   203,    -1,   383,   199,   432,   200,    -1,   383,   199,
     434,   200,    -1,   350,    66,   425,   203,    -1,   351,    66,
     425,   203,    -1,   347,    -1,   441,    -1,    85,    -1,   196,
     332,   197,    -1,   354,   355,    -1,   417,    14,   352,    -1,
     179,    79,   182,   331,    -1,   356,   367,    -1,   356,   367,
     370,    -1,   367,    -1,   367,   370,    -1,   357,    -1,   356,
     357,    -1,   358,    -1,   359,    -1,   360,    -1,   361,    -1,
     362,    -1,   363,    -1,   179,    79,   182,   331,    -1,   186,
      79,    14,   331,    -1,   180,   331,    -1,   181,    79,   182,
     331,   183,   331,   184,   331,    -1,   181,    79,   182,   331,
     183,   331,   184,   331,   185,    79,    -1,   187,   364,    -1,
     365,    -1,   364,     9,   365,    -1,   331,    -1,   331,   366,
      -1,   188,    -1,   189,    -1,   368,    -1,   369,    -1,   190,
     331,    -1,   191,   331,   192,   331,    -1,   185,    79,   355,
      -1,   371,     9,    79,    -1,   371,     9,    35,    79,    -1,
      79,    -1,    35,    79,    -1,   166,   152,   373,   167,    -1,
     375,    50,    -1,   375,   167,   376,   166,    50,   374,    -1,
      -1,   152,    -1,   375,   377,    14,   378,    -1,    -1,   376,
     379,    -1,    -1,   152,    -1,   153,    -1,   199,   331,   200,
      -1,   153,    -1,   199,   331,   200,    -1,   372,    -1,   381,
      -1,   380,    30,   381,    -1,   380,    47,   381,    -1,   213,
      -1,    69,    -1,   104,    -1,   105,    -1,   106,    -1,    27,
      -1,    28,    -1,   107,    -1,   108,    -1,   165,    -1,   109,
      -1,    70,    -1,    71,    -1,    73,    -1,    72,    -1,    88,
      -1,    89,    -1,    87,    -1,    90,    -1,    91,    -1,    92,
      -1,    93,    -1,    94,    -1,    95,    -1,    53,    -1,    96,
      -1,    97,    -1,    98,    -1,    99,    -1,   100,    -1,   101,
      -1,   103,    -1,   102,    -1,    86,    -1,    13,    -1,   123,
      -1,   124,    -1,   125,    -1,   126,    -1,    68,    -1,    67,
      -1,   118,    -1,     5,    -1,     7,    -1,     6,    -1,     4,
      -1,     3,    -1,   148,    -1,   110,    -1,   111,    -1,   120,
      -1,   121,    -1,   122,    -1,   117,    -1,   116,    -1,   115,
      -1,   114,    -1,   113,    -1,   112,    -1,   178,    -1,   119,
      -1,   129,    -1,   130,    -1,    10,    -1,    12,    -1,    11,
      -1,   132,    -1,   134,    -1,   133,    -1,   135,    -1,   136,
      -1,   150,    -1,   149,    -1,   177,    -1,   160,    -1,   163,
      -1,   162,    -1,   173,    -1,   175,    -1,   172,    -1,   223,
     196,   284,   197,    -1,   224,    -1,   152,    -1,   383,    -1,
     117,    -1,   423,    -1,   383,    -1,   117,    -1,   427,    -1,
     196,   197,    -1,   322,    -1,    -1,    -1,    84,    -1,   436,
      -1,   196,   284,   197,    -1,    -1,    74,    -1,    75,    -1,
      76,    -1,    85,    -1,   135,    -1,   136,    -1,   150,    -1,
     132,    -1,   163,    -1,   133,    -1,   134,    -1,   149,    -1,
     177,    -1,   143,    84,   144,    -1,   143,   144,    -1,   389,
      -1,   222,    -1,   130,   196,   393,   197,    -1,    66,   393,
     203,    -1,   172,   196,   345,   197,    -1,   391,    -1,   349,
      -1,   196,   390,   197,    -1,   390,    31,   390,    -1,   390,
      32,   390,    -1,   390,    10,   390,    -1,   390,    12,   390,
      -1,   390,    11,   390,    -1,   390,    33,   390,    -1,   390,
      35,   390,    -1,   390,    34,   390,    -1,   390,    48,   390,
      -1,   390,    46,   390,    -1,   390,    47,   390,    -1,   390,
      49,   390,    -1,   390,    50,   390,    -1,   390,    51,   390,
      -1,   390,    45,   390,    -1,   390,    44,   390,    -1,   390,
      65,   390,    -1,    52,   390,    -1,    54,   390,    -1,    46,
     390,    -1,    47,   390,    -1,   390,    37,   390,    -1,   390,
      36,   390,    -1,   390,    39,   390,    -1,   390,    38,   390,
      -1,   390,    40,   390,    -1,   390,    43,   390,    -1,   390,
      41,   390,    -1,   390,    42,   390,    -1,   390,    29,   390,
      30,   390,    -1,   390,    29,    30,   390,    -1,   224,   147,
     213,    -1,   152,   147,   213,    -1,   224,   147,   123,    -1,
     222,    -1,    78,    -1,   441,    -1,   389,    -1,   204,   436,
     204,    -1,   205,   436,   205,    -1,   143,   436,   144,    -1,
     396,   394,    -1,    -1,     9,    -1,    -1,     9,    -1,    -1,
     396,     9,   390,   128,   390,    -1,   396,     9,   390,    -1,
     390,   128,   390,    -1,   390,    -1,    74,    -1,    75,    -1,
      76,    -1,    85,    -1,   143,    84,   144,    -1,   143,   144,
      -1,    74,    -1,    75,    -1,    76,    -1,   213,    -1,   397,
      -1,   213,    -1,    46,   398,    -1,    47,   398,    -1,   130,
     196,   400,   197,    -1,    66,   400,   203,    -1,   172,   196,
     403,   197,    -1,   401,   394,    -1,    -1,   401,     9,   399,
     128,   399,    -1,   401,     9,   399,    -1,   399,   128,   399,
      -1,   399,    -1,   402,     9,   399,    -1,   399,    -1,   404,
     394,    -1,    -1,   404,     9,   341,   128,   399,    -1,   341,
     128,   399,    -1,   402,   394,    -1,    -1,   196,   405,   197,
      -1,    -1,   407,     9,   213,   406,    -1,   213,   406,    -1,
      -1,   409,   407,   394,    -1,    45,   408,    44,    -1,   410,
      -1,    -1,   413,    -1,   127,   422,    -1,   127,   213,    -1,
     127,   199,   331,   200,    -1,    66,   425,   203,    -1,   199,
     331,   200,    -1,   418,   414,    -1,   196,   321,   197,   414,
      -1,   428,   414,    -1,   196,   321,   197,   414,    -1,   422,
      -1,   382,    -1,   420,    -1,   421,    -1,   415,    -1,   417,
     412,    -1,   196,   321,   197,   412,    -1,   384,   147,   422,
      -1,   419,   196,   284,   197,    -1,   196,   417,   197,    -1,
     382,    -1,   420,    -1,   421,    -1,   415,    -1,   417,   413,
      -1,   196,   321,   197,   413,    -1,   419,   196,   284,   197,
      -1,   196,   417,   197,    -1,   422,    -1,   415,    -1,   196,
     417,   197,    -1,   417,   127,   213,   446,   196,   284,   197,
      -1,   417,   127,   422,   196,   284,   197,    -1,   417,   127,
     199,   331,   200,   196,   284,   197,    -1,   196,   321,   197,
     127,   213,   446,   196,   284,   197,    -1,   196,   321,   197,
     127,   422,   196,   284,   197,    -1,   196,   321,   197,   127,
     199,   331,   200,   196,   284,   197,    -1,   384,   147,   213,
     446,   196,   284,   197,    -1,   384,   147,   422,   196,   284,
     197,    -1,   384,   147,   199,   331,   200,   196,   284,   197,
      -1,   423,    -1,   426,   423,    -1,   423,    66,   425,   203,
      -1,   423,   199,   331,   200,    -1,   424,    -1,    79,    -1,
     201,   199,   331,   200,    -1,   331,    -1,    -1,   201,    -1,
     426,   201,    -1,   422,    -1,   416,    -1,   427,   412,    -1,
     196,   321,   197,   412,    -1,   384,   147,   422,    -1,   196,
     417,   197,    -1,    -1,   416,    -1,   427,   413,    -1,   196,
     321,   197,   413,    -1,   196,   417,   197,    -1,   429,     9,
      -1,   429,     9,   417,    -1,   429,     9,   129,   196,   429,
     197,    -1,    -1,   417,    -1,   129,   196,   429,   197,    -1,
     431,   394,    -1,    -1,   431,     9,   331,   128,   331,    -1,
     431,     9,   331,    -1,   331,   128,   331,    -1,   331,    -1,
     431,     9,   331,   128,    35,   417,    -1,   431,     9,    35,
     417,    -1,   331,   128,    35,   417,    -1,    35,   417,    -1,
     433,   394,    -1,    -1,   433,     9,   331,   128,   331,    -1,
     433,     9,   331,    -1,   331,   128,   331,    -1,   331,    -1,
     435,   394,    -1,    -1,   435,     9,   390,   128,   390,    -1,
     435,     9,   390,    -1,   390,   128,   390,    -1,   390,    -1,
     436,   437,    -1,   436,    84,    -1,   437,    -1,    84,   437,
      -1,    79,    -1,    79,    66,   438,   203,    -1,    79,   127,
     213,    -1,   145,   331,   200,    -1,   145,    78,    66,   331,
     203,   200,    -1,   146,   417,   200,    -1,   213,    -1,    80,
      -1,    79,    -1,   120,   196,   440,   197,    -1,   121,   196,
     417,   197,    -1,   121,   196,   332,   197,    -1,   121,   196,
     321,   197,    -1,     7,   331,    -1,     6,   331,    -1,     5,
     196,   331,   197,    -1,     4,   331,    -1,     3,   331,    -1,
     417,    -1,   440,     9,   417,    -1,   384,   147,   213,    -1,
     384,   147,   123,    -1,    -1,    96,   456,    -1,   173,   445,
      14,   456,   198,    -1,   175,   445,   442,    14,   456,   198,
      -1,   213,    -1,   456,   213,    -1,   213,    -1,   213,   168,
     451,   169,    -1,   168,   448,   169,    -1,    -1,   456,    -1,
     447,     9,   456,    -1,   447,   394,    -1,   447,     9,   161,
      -1,   448,    -1,   161,    -1,    -1,    -1,    30,   456,    -1,
     451,     9,   213,    -1,   213,    -1,   451,     9,   213,    96,
     456,    -1,   213,    96,   456,    -1,    85,   128,   456,    -1,
     224,   147,   213,   128,   456,    -1,   453,     9,   452,    -1,
     452,    -1,   453,   394,    -1,    -1,   172,   196,   454,   197,
      -1,    29,   456,    -1,    55,   456,    -1,   224,    -1,   130,
      -1,   131,    -1,   455,    -1,   130,   168,   456,   169,    -1,
     130,   168,   456,     9,   456,   169,    -1,   152,    -1,   196,
     104,   196,   449,   197,    30,   456,   197,    -1,   196,   456,
       9,   447,   394,   197,    -1,   456,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   730,   730,   730,   739,   741,   744,   745,   746,   747,
     748,   749,   752,   754,   754,   756,   756,   758,   759,   761,
     763,   768,   769,   770,   771,   772,   773,   774,   775,   776,
     777,   778,   779,   780,   781,   782,   783,   784,   785,   786,
     790,   792,   796,   798,   802,   804,   808,   809,   810,   811,
     816,   817,   818,   819,   824,   825,   826,   827,   832,   833,
     837,   838,   840,   843,   849,   856,   863,   867,   873,   875,
     878,   879,   880,   881,   884,   885,   889,   894,   894,   900,
     900,   907,   906,   912,   912,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   932,   930,
     939,   937,   944,   952,   946,   956,   954,   958,   959,   963,
     964,   965,   966,   967,   968,   969,   970,   971,   972,   973,
     981,   981,   986,   992,   996,   996,  1004,  1005,  1009,  1010,
    1014,  1019,  1018,  1031,  1029,  1043,  1041,  1057,  1056,  1075,
    1073,  1092,  1091,  1100,  1098,  1110,  1109,  1121,  1119,  1132,
    1133,  1137,  1140,  1143,  1144,  1145,  1148,  1150,  1153,  1154,
    1157,  1158,  1161,  1162,  1166,  1167,  1172,  1173,  1176,  1177,
    1178,  1182,  1183,  1187,  1188,  1192,  1193,  1197,  1198,  1203,
    1204,  1209,  1210,  1211,  1212,  1215,  1218,  1220,  1223,  1224,
    1228,  1230,  1233,  1236,  1239,  1240,  1243,  1244,  1248,  1254,
    1261,  1263,  1268,  1274,  1278,  1282,  1286,  1291,  1296,  1301,
    1306,  1312,  1321,  1326,  1332,  1334,  1338,  1343,  1347,  1350,
    1353,  1357,  1361,  1365,  1369,  1374,  1382,  1384,  1387,  1388,
    1389,  1390,  1392,  1394,  1399,  1400,  1403,  1404,  1405,  1409,
    1410,  1412,  1413,  1417,  1419,  1422,  1422,  1426,  1425,  1429,
    1433,  1431,  1446,  1443,  1456,  1458,  1460,  1462,  1464,  1466,
    1468,  1472,  1473,  1474,  1477,  1483,  1486,  1492,  1495,  1500,
    1502,  1507,  1512,  1516,  1517,  1523,  1524,  1526,  1530,  1531,
    1536,  1537,  1541,  1542,  1546,  1548,  1554,  1559,  1560,  1562,
    1566,  1567,  1568,  1569,  1573,  1574,  1575,  1576,  1577,  1578,
    1580,  1585,  1588,  1589,  1593,  1594,  1598,  1599,  1602,  1603,
    1606,  1607,  1610,  1611,  1615,  1616,  1617,  1618,  1619,  1620,
    1621,  1625,  1626,  1629,  1630,  1631,  1634,  1636,  1638,  1639,
    1642,  1644,  1649,  1650,  1652,  1653,  1654,  1657,  1661,  1662,
    1666,  1667,  1671,  1672,  1676,  1680,  1685,  1689,  1693,  1698,
    1699,  1700,  1703,  1705,  1706,  1707,  1710,  1711,  1712,  1713,
    1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,
    1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,
    1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,  1754,
    1755,  1757,  1759,  1760,  1761,  1762,  1763,  1764,  1765,  1766,
    1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,  1775,  1776,
    1777,  1778,  1779,  1783,  1787,  1792,  1791,  1806,  1804,  1821,
    1821,  1836,  1836,  1854,  1855,  1860,  1862,  1866,  1870,  1876,
    1880,  1886,  1888,  1892,  1894,  1898,  1902,  1903,  1907,  1914,
    1921,  1923,  1928,  1929,  1930,  1932,  1936,  1940,  1944,  1948,
    1950,  1952,  1954,  1959,  1960,  1965,  1966,  1967,  1968,  1969,
    1970,  1974,  1978,  1982,  1986,  1991,  1996,  2000,  2001,  2005,
    2006,  2010,  2011,  2015,  2016,  2020,  2024,  2028,  2032,  2033,
    2034,  2035,  2039,  2045,  2054,  2067,  2068,  2071,  2074,  2077,
    2078,  2081,  2085,  2088,  2091,  2098,  2099,  2103,  2104,  2106,
    2110,  2111,  2112,  2113,  2114,  2115,  2116,  2117,  2118,  2119,
    2120,  2121,  2122,  2123,  2124,  2125,  2126,  2127,  2128,  2129,
    2130,  2131,  2132,  2133,  2134,  2135,  2136,  2137,  2138,  2139,
    2140,  2141,  2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,
    2150,  2151,  2152,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,  2171,  2172,  2173,  2174,  2175,  2176,  2177,  2178,  2179,
    2180,  2181,  2182,  2183,  2184,  2185,  2186,  2187,  2188,  2189,
    2193,  2198,  2199,  2202,  2203,  2204,  2208,  2209,  2210,  2214,
    2215,  2216,  2220,  2221,  2222,  2225,  2227,  2231,  2232,  2233,
    2234,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,
    2245,  2248,  2253,  2254,  2255,  2257,  2258,  2260,  2261,  2263,
    2264,  2266,  2268,  2270,  2272,  2274,  2275,  2276,  2277,  2278,
    2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,  2288,
    2289,  2290,  2292,  2294,  2296,  2298,  2299,  2302,  2303,  2307,
    2309,  2313,  2316,  2319,  2325,  2326,  2327,  2328,  2329,  2330,
    2331,  2336,  2338,  2342,  2343,  2346,  2347,  2351,  2354,  2356,
    2358,  2362,  2363,  2364,  2365,  2367,  2370,  2374,  2375,  2376,
    2377,  2380,  2381,  2382,  2383,  2384,  2386,  2387,  2392,  2394,
    2397,  2400,  2402,  2404,  2407,  2409,  2413,  2415,  2418,  2421,
    2427,  2429,  2432,  2433,  2438,  2441,  2445,  2445,  2450,  2453,
    2454,  2458,  2459,  2464,  2465,  2469,  2470,  2474,  2475,  2480,
    2482,  2487,  2488,  2489,  2490,  2491,  2492,  2493,  2495,  2498,
    2500,  2504,  2505,  2506,  2507,  2508,  2510,  2512,  2514,  2518,
    2519,  2520,  2524,  2527,  2530,  2533,  2537,  2541,  2548,  2552,
    2556,  2563,  2564,  2569,  2571,  2572,  2575,  2576,  2579,  2580,
    2584,  2585,  2589,  2590,  2591,  2592,  2594,  2597,  2600,  2601,
    2602,  2604,  2606,  2610,  2611,  2612,  2614,  2615,  2616,  2620,
    2622,  2625,  2627,  2628,  2629,  2630,  2633,  2635,  2636,  2640,
    2642,  2645,  2647,  2648,  2649,  2653,  2655,  2658,  2661,  2663,
    2665,  2669,  2670,  2672,  2673,  2679,  2680,  2682,  2684,  2686,
    2688,  2691,  2692,  2693,  2697,  2698,  2699,  2700,  2701,  2702,
    2703,  2704,  2705,  2709,  2710,  2714,  2716,  2724,  2726,  2730,
    2734,  2741,  2742,  2748,  2749,  2756,  2759,  2763,  2766,  2771,
    2776,  2778,  2779,  2780,  2784,  2785,  2789,  2791,  2792,  2794,
    2798,  2801,  2810,  2812,  2816,  2819,  2822,  2830,  2833,  2836,
    2837,  2840,  2843,  2844,  2847,  2851,  2855,  2861,  2871,  2872
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_REQUIRE_ONCE", "T_REQUIRE", "T_EVAL",
  "T_INCLUDE_ONCE", "T_INCLUDE", "T_LAMBDA_ARROW", "','", "T_LOGICAL_OR",
  "T_LOGICAL_XOR", "T_LOGICAL_AND", "T_PRINT", "'='", "T_POW_EQUAL",
  "T_SR_EQUAL", "T_SL_EQUAL", "T_XOR_EQUAL", "T_OR_EQUAL", "T_AND_EQUAL",
  "T_MOD_EQUAL", "T_CONCAT_EQUAL", "T_DIV_EQUAL", "T_MUL_EQUAL",
  "T_MINUS_EQUAL", "T_PLUS_EQUAL", "T_YIELD", "T_AWAIT", "'?'", "':'",
  "T_BOOLEAN_OR", "T_BOOLEAN_AND", "'|'", "'^'", "'&'",
  "T_IS_NOT_IDENTICAL", "T_IS_IDENTICAL", "T_IS_NOT_EQUAL", "T_IS_EQUAL",
  "'<'", "'>'", "T_IS_GREATER_OR_EQUAL", "T_IS_SMALLER_OR_EQUAL", "T_SR",
  "T_SL", "'+'", "'-'", "'.'", "'*'", "'/'", "'%'", "'!'", "T_INSTANCEOF",
  "'~'", "'@'", "T_UNSET_CAST", "T_BOOL_CAST", "T_OBJECT_CAST",
  "T_ARRAY_CAST", "T_STRING_CAST", "T_DOUBLE_CAST", "T_INT_CAST", "T_DEC",
  "T_INC", "T_POW", "'['", "T_CLONE", "T_NEW", "T_EXIT", "T_IF",
  "T_ELSEIF", "T_ELSE", "T_ENDIF", "T_LNUMBER", "T_DNUMBER", "T_ONUMBER",
  "T_STRING", "T_STRING_VARNAME", "T_VARIABLE", "T_NUM_STRING",
  "T_INLINE_HTML", "T_CHARACTER", "T_BAD_CHARACTER",
  "T_ENCAPSED_AND_WHITESPACE", "T_CONSTANT_ENCAPSED_STRING", "T_ECHO",
  "T_DO", "T_WHILE", "T_ENDWHILE", "T_FOR", "T_ENDFOR", "T_FOREACH",
  "T_ENDFOREACH", "T_DECLARE", "T_ENDDECLARE", "T_AS", "T_SWITCH",
  "T_ENDSWITCH", "T_CASE", "T_DEFAULT", "T_BREAK", "T_GOTO", "T_CONTINUE",
  "T_FUNCTION", "T_CONST", "T_RETURN", "T_TRY", "T_CATCH", "T_THROW",
  "T_USE", "T_GLOBAL", "T_PUBLIC", "T_PROTECTED", "T_PRIVATE", "T_FINAL",
  "T_ABSTRACT", "T_STATIC", "T_VAR", "T_UNSET", "T_ISSET", "T_EMPTY",
  "T_HALT_COMPILER", "T_CLASS", "T_INTERFACE", "T_EXTENDS", "T_IMPLEMENTS",
  "T_OBJECT_OPERATOR", "T_DOUBLE_ARROW", "T_LIST", "T_ARRAY", "T_CALLABLE",
  "T_CLASS_C", "T_METHOD_C", "T_FUNC_C", "T_LINE", "T_FILE", "T_COMMENT",
  "T_DOC_COMMENT", "T_OPEN_TAG", "T_OPEN_TAG_WITH_ECHO", "T_CLOSE_TAG",
  "T_WHITESPACE", "T_START_HEREDOC", "T_END_HEREDOC",
  "T_DOLLAR_OPEN_CURLY_BRACES", "T_CURLY_OPEN", "T_DOUBLE_COLON",
  "T_NAMESPACE", "T_NS_C", "T_DIR", "T_NS_SEPARATOR", "T_XHP_LABEL",
  "T_XHP_TEXT", "T_XHP_ATTRIBUTE", "T_XHP_CATEGORY",
  "T_XHP_CATEGORY_LABEL", "T_XHP_CHILDREN", "T_XHP_ENUM", "T_XHP_REQUIRED",
  "T_TRAIT", "\"...\"", "T_INSTEADOF", "T_TRAIT_C", "T_HH_ERROR",
  "T_FINALLY", "T_XHP_TAG_LT", "T_XHP_TAG_GT", "T_TYPELIST_LT",
  "T_TYPELIST_GT", "T_UNRESOLVED_LT", "T_COLLECTION", "T_SHAPE", "T_TYPE",
  "T_UNRESOLVED_TYPE", "T_NEWTYPE", "T_UNRESOLVED_NEWTYPE",
  "T_COMPILER_HALT_OFFSET", "T_ASYNC", "T_FROM", "T_WHERE", "T_JOIN",
  "T_IN", "T_ON", "T_EQUALS", "T_INTO", "T_LET", "T_ORDERBY",
  "T_ASCENDING", "T_DESCENDING", "T_SELECT", "T_GROUP", "T_BY",
  "T_LAMBDA_OP", "T_LAMBDA_CP", "T_UNRESOLVED_OP", "'('", "')'", "';'",
  "'{'", "'}'", "'$'", "'`'", "']'", "'\"'", "'\\''", "$accept", "start",
  "$@1", "top_statement_list", "top_statement", "$@2", "$@3", "ident",
  "use_declarations", "use_fn_declarations", "use_const_declarations",
  "use_declaration", "use_fn_declaration", "use_const_declaration",
  "namespace_name", "namespace_string_base", "namespace_string",
  "namespace_string_typeargs", "class_namespace_string_typeargs",
  "constant_declaration", "inner_statement_list", "inner_statement",
  "statement", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11",
  "try_statement_list", "$@12", "additional_catches",
  "finally_statement_list", "$@13", "optional_finally", "is_reference",
  "function_loc", "function_declaration_statement", "$@14", "$@15", "$@16",
  "class_declaration_statement", "$@17", "$@18", "$@19", "$@20",
  "trait_declaration_statement", "$@21", "$@22", "class_decl_name",
  "interface_decl_name", "trait_decl_name", "class_entry_type",
  "extends_from", "implements_list", "interface_extends_list",
  "interface_list", "trait_list", "foreach_optional_arg",
  "foreach_variable", "for_statement", "foreach_statement",
  "while_statement", "declare_statement", "declare_list",
  "switch_case_list", "case_list", "case_separator", "elseif_list",
  "new_elseif_list", "else_single", "new_else_single",
  "method_parameter_list", "non_empty_method_parameter_list",
  "parameter_list", "non_empty_parameter_list",
  "function_call_parameter_list", "non_empty_fcall_parameter_list",
  "global_var_list", "global_var", "static_var_list",
  "class_statement_list", "class_statement", "$@23", "$@24", "$@25",
  "$@26", "trait_rules", "trait_precedence_rule", "trait_alias_rule",
  "trait_alias_rule_method", "xhp_attribute_stmt", "xhp_attribute_decl",
  "xhp_attribute_decl_type", "xhp_attribute_enum", "xhp_attribute_default",
  "xhp_attribute_is_required", "xhp_category_stmt", "xhp_category_decl",
  "xhp_children_stmt", "xhp_children_paren_expr", "xhp_children_decl_expr",
  "xhp_children_decl_tag", "function_body", "method_body",
  "variable_modifiers", "method_modifiers", "non_empty_member_modifiers",
  "member_modifier", "parameter_modifiers", "parameter_modifier",
  "class_variable_declaration", "class_constant_declaration",
  "expr_with_parens", "parenthesis_expr", "expr_list", "for_expr",
  "yield_expr", "yield_assign_expr", "yield_list_assign_expr",
  "await_expr", "await_assign_expr", "await_list_assign_expr", "expr",
  "expr_no_variable", "lambda_use_vars", "closure_expression", "$@27",
  "$@28", "lambda_expression", "$@29", "$@30", "lambda_body",
  "shape_keyname", "non_empty_shape_pair_list",
  "non_empty_static_shape_pair_list", "shape_pair_list",
  "static_shape_pair_list", "shape_literal", "array_literal",
  "collection_literal", "static_collection_literal", "dim_expr",
  "dim_expr_base", "query_expr", "query_assign_expr", "query_head",
  "query_body", "query_body_clauses", "query_body_clause", "from_clause",
  "let_clause", "where_clause", "join_clause", "join_into_clause",
  "orderby_clause", "orderings", "ordering", "ordering_direction",
  "select_or_group_clause", "select_clause", "group_clause",
  "query_continuation", "lexical_var_list", "xhp_tag", "xhp_tag_body",
  "xhp_opt_end_label", "xhp_attributes", "xhp_children",
  "xhp_attribute_name", "xhp_attribute_value", "xhp_child", "xhp_label_ws",
  "xhp_bareword", "simple_function_call", "fully_qualified_class_name",
  "static_class_name", "class_name_reference", "exit_expr",
  "backticks_expr", "ctor_arguments", "common_scalar", "static_expr",
  "static_class_constant", "scalar", "static_array_pair_list",
  "possible_comma", "hh_possible_comma",
  "non_empty_static_array_pair_list", "common_scalar_ae",
  "static_numeric_scalar_ae", "static_scalar_ae",
  "static_array_pair_list_ae", "non_empty_static_array_pair_list_ae",
  "non_empty_static_scalar_list_ae", "static_shape_pair_list_ae",
  "non_empty_static_shape_pair_list_ae", "static_scalar_list_ae",
  "attribute_static_scalar_list", "non_empty_user_attribute_list",
  "user_attribute_list", "$@31", "non_empty_user_attributes",
  "optional_user_attributes", "property_access",
  "property_access_without_variables", "array_access",
  "dimmable_variable_access", "dimmable_variable_no_calls_access",
  "variable", "dimmable_variable", "callable_variable",
  "object_method_call", "class_method_call", "variable_without_objects",
  "reference_variable", "compound_variable", "dim_offset",
  "simple_indirect_reference", "variable_no_calls",
  "dimmable_variable_no_calls", "assignment_list", "array_pair_list",
  "non_empty_array_pair_list", "collection_init",
  "non_empty_collection_init", "static_collection_init",
  "non_empty_static_collection_init", "encaps_list", "encaps_var",
  "encaps_var_offset", "internal_functions", "variable_list",
  "class_constant", "hh_opt_constraint", "hh_type_alias_statement",
  "hh_name_with_type", "hh_name_with_typevar", "hh_typeargs_opt",
  "hh_non_empty_type_list", "hh_type_list", "hh_func_type_list",
  "hh_opt_return_type", "hh_typevar_list", "hh_shape_member_type",
  "hh_non_empty_shape_member_list", "hh_shape_member_list",
  "hh_shape_type", "hh_type", "hh_type_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    44,
     264,   265,   266,   267,    61,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,    63,
      58,   282,   283,   124,    94,    38,   284,   285,   286,   287,
      60,    62,   288,   289,   290,   291,    43,    45,    46,    42,
      47,    37,    33,   292,   126,    64,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    91,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,    40,    41,    59,   123,
     125,    36,    96,    93,    34,    39
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   206,   208,   207,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   211,   210,   212,   210,   210,   210,   210,
     210,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     214,   214,   215,   215,   216,   216,   217,   217,   217,   217,
     218,   218,   218,   218,   219,   219,   219,   219,   220,   220,
     221,   221,   221,   222,   223,   224,   225,   225,   226,   226,
     227,   227,   227,   227,   228,   228,   228,   229,   228,   230,
     228,   231,   228,   232,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   233,   228,
     234,   228,   228,   235,   228,   236,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     238,   237,   239,   239,   241,   240,   242,   242,   243,   243,
     244,   246,   245,   247,   245,   248,   245,   250,   249,   251,
     249,   252,   249,   253,   249,   255,   254,   256,   254,   257,
     257,   258,   259,   260,   260,   260,   261,   261,   262,   262,
     263,   263,   264,   264,   265,   265,   266,   266,   267,   267,
     267,   268,   268,   269,   269,   270,   270,   271,   271,   272,
     272,   273,   273,   273,   273,   274,   274,   274,   275,   275,
     276,   276,   277,   277,   278,   278,   279,   279,   280,   280,
     280,   280,   280,   280,   281,   281,   281,   281,   281,   281,
     281,   281,   282,   282,   282,   282,   282,   282,   283,   283,
     283,   283,   283,   283,   283,   283,   284,   284,   285,   285,
     285,   285,   285,   285,   286,   286,   287,   287,   287,   288,
     288,   288,   288,   289,   289,   291,   290,   292,   290,   290,
     293,   290,   294,   290,   290,   290,   290,   290,   290,   290,
     290,   295,   295,   295,   296,   297,   297,   298,   298,   299,
     299,   300,   300,   301,   301,   301,   301,   301,   302,   302,
     303,   303,   304,   304,   305,   305,   306,   307,   307,   307,
     308,   308,   308,   308,   309,   309,   309,   309,   309,   309,
     309,   310,   310,   310,   311,   311,   312,   312,   313,   313,
     314,   314,   315,   315,   316,   316,   316,   316,   316,   316,
     316,   317,   317,   318,   318,   318,   319,   319,   319,   319,
     320,   320,   321,   321,   321,   321,   321,   322,   323,   323,
     324,   324,   325,   325,   326,   327,   328,   329,   330,   331,
     331,   331,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   333,   333,   335,   334,   336,   334,   338,
     337,   339,   337,   340,   340,   341,   341,   342,   342,   343,
     343,   344,   344,   345,   345,   346,   347,   347,   348,   349,
     350,   350,   351,   351,   351,   351,   352,   353,   354,   355,
     355,   355,   355,   356,   356,   357,   357,   357,   357,   357,
     357,   358,   359,   360,   361,   362,   363,   364,   364,   365,
     365,   366,   366,   367,   367,   368,   369,   370,   371,   371,
     371,   371,   372,   373,   373,   374,   374,   375,   375,   376,
     376,   377,   378,   378,   379,   379,   379,   380,   380,   380,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     382,   383,   383,   384,   384,   384,   385,   385,   385,   386,
     386,   386,   387,   387,   387,   388,   388,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   391,   391,   391,   392,   392,   392,   392,   392,   392,
     392,   393,   393,   394,   394,   395,   395,   396,   396,   396,
     396,   397,   397,   397,   397,   397,   397,   398,   398,   398,
     398,   399,   399,   399,   399,   399,   399,   399,   400,   400,
     401,   401,   401,   401,   402,   402,   403,   403,   404,   404,
     405,   405,   406,   406,   407,   407,   409,   408,   410,   411,
     411,   412,   412,   413,   413,   414,   414,   415,   415,   416,
     416,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   418,   418,   418,   418,   418,   418,   418,   418,   419,
     419,   419,   420,   420,   420,   420,   420,   420,   421,   421,
     421,   422,   422,   423,   423,   423,   424,   424,   425,   425,
     426,   426,   427,   427,   427,   427,   427,   427,   428,   428,
     428,   428,   428,   429,   429,   429,   429,   429,   429,   430,
     430,   431,   431,   431,   431,   431,   431,   431,   431,   432,
     432,   433,   433,   433,   433,   434,   434,   435,   435,   435,
     435,   436,   436,   436,   436,   437,   437,   437,   437,   437,
     437,   438,   438,   438,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   440,   440,   441,   441,   442,   442,   443,
     443,   444,   444,   445,   445,   446,   446,   447,   447,   448,
     449,   449,   449,   449,   450,   450,   451,   451,   451,   451,
     452,   452,   453,   453,   454,   454,   455,   456,   456,   456,
     456,   456,   456,   456,   456,   456,   456,   456,   457,   457
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     1,     1,     1,     1,
       1,     4,     3,     0,     6,     0,     5,     3,     4,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     1,     2,     3,     4,
       1,     2,     3,     4,     1,     2,     3,     4,     1,     3,
       1,     3,     2,     1,     2,     2,     5,     4,     2,     0,
       1,     1,     1,     1,     3,     5,     8,     0,     4,     0,
       6,     0,    10,     0,     4,     2,     3,     2,     3,     2,
       3,     3,     3,     3,     3,     5,     1,     1,     0,     9,
       0,    10,     5,     0,    13,     0,     5,     3,     3,     2,
       2,     2,     2,     2,     2,     3,     2,     2,     3,     2,
       0,     4,     9,     0,     0,     4,     2,     0,     1,     0,
       1,     0,     9,     0,    10,     0,    11,     0,     8,     0,
       9,     0,     7,     0,     8,     0,     7,     0,     8,     1,
       1,     1,     1,     1,     2,     2,     2,     0,     2,     0,
       2,     0,     1,     3,     1,     3,     2,     0,     1,     2,
       4,     1,     4,     1,     4,     1,     4,     1,     4,     3,
       5,     3,     4,     4,     5,     5,     4,     0,     1,     1,
       4,     0,     5,     0,     2,     0,     3,     0,     7,     6,
       2,     5,     4,     0,     4,     5,     7,     6,     6,     7,
       9,     8,     6,     5,     2,     4,     3,     0,     3,     4,
       6,     5,     5,     6,     8,     7,     2,     0,     1,     2,
       2,     3,     4,     4,     3,     1,     1,     2,     4,     3,
       5,     1,     3,     2,     0,     0,     4,     0,     5,     2,
       0,    10,     0,    11,     3,     3,     3,     4,     4,     3,
       5,     2,     2,     0,     6,     5,     4,     3,     1,     1,
       3,     4,     1,     1,     1,     1,     4,     1,     1,     3,
       2,     0,     2,     0,     1,     3,     1,     1,     1,     1,
       3,     4,     4,     4,     1,     1,     2,     2,     2,     3,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     3,     5,     1,     3,
       5,     4,     3,     3,     2,     1,     1,     3,     3,     1,
       1,     0,     2,     4,     3,     6,     2,     3,     6,     1,
       1,     1,     6,     3,     4,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     3,     2,
       1,     1,     1,     5,     0,     0,    11,     0,    12,     0,
       3,     0,     6,     2,     4,     1,     1,     5,     3,     5,
       3,     2,     0,     2,     0,     4,     4,     3,     4,     4,
       4,     4,     1,     1,     1,     3,     2,     3,     4,     2,
       3,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     4,     4,     2,     8,    10,     2,     1,     3,     1,
       2,     1,     1,     1,     1,     2,     4,     3,     3,     4,
       1,     2,     4,     2,     6,     0,     1,     4,     0,     2,
       0,     1,     1,     3,     1,     3,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     0,     1,     1,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     1,     4,     3,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     3,     3,     3,     1,     1,     1,     1,     3,     3,
       3,     2,     0,     1,     0,     1,     0,     5,     3,     3,
       1,     1,     1,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     3,     4,     2,     0,
       5,     3,     3,     1,     3,     1,     2,     0,     5,     3,
       2,     0,     3,     0,     4,     2,     0,     3,     3,     1,
       0,     1,     2,     2,     4,     3,     3,     2,     4,     2,
       4,     1,     1,     1,     1,     1,     2,     4,     3,     4,
       3,     1,     1,     1,     1,     2,     4,     4,     3,     1,
       1,     3,     7,     6,     8,     9,     8,    10,     7,     6,
       8,     1,     2,     4,     4,     1,     1,     4,     1,     0,
       1,     2,     1,     1,     2,     4,     3,     3,     0,     1,
       2,     4,     3,     2,     3,     6,     0,     1,     4,     2,
       0,     5,     3,     3,     1,     6,     4,     4,     2,     2,
       0,     5,     3,     3,     1,     2,     0,     5,     3,     3,
       1,     2,     2,     1,     2,     1,     4,     3,     3,     6,
       3,     1,     1,     1,     4,     4,     4,     4,     2,     2,
       4,     2,     2,     1,     3,     3,     3,     0,     2,     5,
       6,     1,     2,     1,     4,     3,     0,     1,     3,     2,
       3,     1,     1,     0,     0,     2,     3,     1,     5,     3,
       3,     5,     3,     1,     2,     0,     4,     2,     2,     1,
       1,     1,     1,     4,     6,     1,     8,     6,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     5,     1,     3,     0,     0,     0,     0,     0,
       0,     0,     0,   716,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   790,     0,
     778,   601,     0,   607,   608,   609,    21,   665,   766,    97,
     610,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,     0,     0,     0,   314,   315,
     316,   319,   318,   317,     0,     0,     0,     0,   153,     0,
       0,     0,   614,   616,   617,   611,   612,     0,     0,   618,
     613,     0,   592,    22,    23,    24,    26,    25,     0,   615,
       0,     0,     0,     0,   619,   320,    27,    28,    30,    29,
      31,    32,    33,    34,    35,    36,    37,    38,    39,   431,
       0,    96,    69,   770,   602,     0,     0,     4,    58,    60,
      63,   664,     0,   591,     0,     6,   129,     7,     8,     9,
       0,     0,   312,   351,     0,     0,     0,     0,     0,     0,
       0,   349,   420,   421,   417,   416,   336,   422,     0,     0,
     335,   732,   593,     0,   667,   415,   311,   735,   350,     0,
       0,   733,   734,   731,   761,   765,     0,   405,   666,    10,
     319,   318,   317,     0,     0,    58,   129,     0,   832,   350,
     831,     0,   829,   828,   419,     0,   342,   346,     0,     0,
     389,   390,   391,   392,   414,   412,   411,   410,   409,   408,
     407,   406,   766,   594,     0,   846,   593,     0,   371,   369,
       0,   794,     0,   674,   334,   597,     0,   846,   596,     0,
     606,   773,   772,   598,     0,     0,   600,   413,     0,     0,
       0,     0,   339,     0,    77,   341,     0,     0,    83,    85,
       0,     0,    87,     0,     0,     0,   870,   871,   875,     0,
       0,    58,   869,     0,   872,     0,     0,    89,     0,     0,
       0,     0,   120,     0,     0,     0,     0,     0,     0,    41,
      46,   236,     0,     0,   235,   155,   154,   241,     0,     0,
       0,     0,     0,   843,   141,   151,   786,   790,   815,     0,
     621,     0,     0,     0,   813,     0,    15,     0,    62,   145,
     152,   498,   442,     0,   837,   720,   351,     0,   349,   350,
       0,     0,   603,     0,   604,     0,     0,     0,   119,     0,
       0,    65,   227,     0,    20,   128,     0,   150,   137,   149,
     317,   129,   313,   110,   111,   112,   113,   114,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   778,     0,   109,   769,   769,   117,
     800,     0,     0,     0,     0,     0,   310,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   368,     0,   736,   721,   769,     0,   727,   227,   769,
       0,   771,   762,   786,     0,   129,     0,     0,    91,     0,
     718,   713,   674,     0,     0,     0,     0,   798,     0,   447,
     673,   789,     0,     0,    65,     0,   227,   333,     0,   774,
     721,   729,   599,     0,    69,   191,     0,   430,     0,    94,
       0,     0,   340,     0,     0,     0,     0,     0,    86,   108,
      88,   867,   868,     0,   865,     0,     0,     0,   842,     0,
     115,    90,   118,     0,     0,     0,     0,     0,     0,     0,
     456,     0,   463,   465,   466,   467,   468,   469,   470,   461,
     483,   484,    69,     0,   105,   107,     0,     0,    43,    50,
       0,     0,    45,    54,    47,     0,    17,     0,     0,   237,
       0,    92,     0,     0,    93,   833,     0,     0,   351,   349,
     350,     0,     0,   161,     0,   787,     0,     0,     0,     0,
     620,   814,   665,     0,     0,   812,   670,   811,    61,     5,
      12,    13,   159,     0,     0,   435,     0,     0,   674,     0,
       0,   595,   436,     0,     0,     0,     0,   676,   719,   879,
     332,   402,   740,    74,    68,    70,    71,    72,    73,     0,
     418,   668,   669,    59,   674,     0,   847,     0,     0,     0,
     676,   228,     0,   425,   131,   157,     0,   374,   376,   375,
       0,     0,   372,   373,   377,   379,   378,   394,   393,   396,
     395,   397,   399,   400,   398,   388,   387,   381,   382,   380,
     383,   384,   386,   401,   385,   768,     0,     0,   804,     0,
     674,   836,     0,   835,   738,   761,   143,   147,   139,   129,
       0,     0,   344,   347,   353,   457,   367,   366,   365,   364,
     363,   362,   361,   360,   359,   358,   357,   356,     0,   723,
     722,     0,     0,     0,     0,     0,     0,     0,   830,   343,
     711,   715,   673,   717,     0,     0,   846,     0,   793,     0,
     792,     0,   777,   776,     0,     0,   723,   722,   337,   193,
     195,    69,   433,   338,     0,    69,   175,    78,   341,     0,
       0,     0,     0,     0,   187,   187,    84,     0,     0,     0,
     863,   674,     0,   853,     0,     0,     0,     0,     0,   672,
     610,     0,     0,   592,     0,     0,    63,   623,   591,   628,
       0,   622,    67,   627,     0,     0,   473,     0,     0,   479,
     476,   477,   485,     0,   464,   459,     0,   462,     0,     0,
       0,    51,    18,     0,     0,    55,    19,     0,     0,     0,
      40,    48,     0,   234,   242,   239,     0,     0,   824,   827,
     826,   825,    11,   857,     0,     0,     0,   786,   783,     0,
     446,   823,   822,   821,     0,   817,     0,   818,   820,     0,
       5,     0,     0,   492,   493,   501,   500,     0,     0,   673,
     441,   445,     0,     0,   838,     0,   854,   720,   214,   878,
       0,     0,   737,   721,   728,   767,   673,   849,   845,   229,
     230,   590,   675,   226,     0,   720,     0,     0,   159,   427,
     133,   404,     0,   450,   451,     0,   448,   673,   799,     0,
       0,   227,   161,   159,   157,     0,   778,   354,     0,     0,
     227,   725,   726,   739,   763,   764,     0,     0,     0,   699,
     681,   682,   683,   684,     0,     0,     0,   692,   691,   705,
     674,     0,   713,   797,   796,     0,   775,   721,   730,   605,
       0,   197,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,   167,   168,   179,     0,    69,   177,   102,   187,
       0,   187,     0,     0,   873,     0,     0,   673,   864,   866,
     852,   674,   851,     0,   674,   649,   650,   647,   648,   680,
       0,   674,   672,     0,     0,   444,     0,     0,   806,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   458,     0,     0,     0,   481,
     482,   480,     0,     0,   460,     0,   121,     0,   124,   106,
       0,    42,    52,     0,    44,    56,    49,   238,     0,   834,
      95,     0,     0,   844,   160,   162,   244,     0,     0,   784,
       0,   816,     0,    16,     0,   158,   244,     0,     0,   438,
       0,   835,   839,     0,     0,     0,   879,     0,   218,   216,
       0,   723,   722,   848,     0,     0,   231,    66,     0,   720,
     156,     0,   720,     0,   403,   803,   802,     0,   227,     0,
       0,     0,   159,   135,   606,   724,   227,     0,     0,   687,
     688,   689,   690,   693,   694,   703,     0,   674,   699,     0,
     686,   707,   673,   710,   712,   714,     0,   791,   724,     0,
       0,     0,     0,   194,   434,    80,     0,   341,   167,   169,
     786,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,     0,   860,     0,   862,   673,     0,     0,     0,   625,
     673,   671,     0,   662,     0,   674,     0,   629,   663,   661,
     810,     0,   674,   632,   634,   633,     0,     0,   630,   631,
     635,   637,   636,   652,   651,   654,   653,   655,   657,   658,
     656,   645,   644,   639,   640,   638,   641,   642,   643,   646,
     471,     0,   472,   478,   486,   487,     0,    69,    53,    57,
     240,   859,   856,     0,   311,   788,   786,   345,   348,   352,
       0,    14,   311,   504,     0,     0,   506,   499,   502,     0,
     497,     0,   840,   855,   432,     0,   219,     0,   215,     0,
       0,   227,   233,   232,   854,     0,   244,     0,   720,     0,
     227,     0,   759,   244,   244,     0,     0,   355,   227,     0,
     753,     0,   696,   673,   698,     0,   685,     0,     0,   674,
     704,   795,     0,    69,     0,   190,   176,     0,     0,     0,
     166,    98,   180,     0,     0,   183,     0,   188,   189,    69,
     182,   874,     0,   850,     0,   877,   679,   678,   624,     0,
     673,   443,   626,     0,   449,   673,   805,   660,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   309,     0,     0,
       0,   142,   243,   245,     0,   308,     0,   311,     0,   819,
     146,   495,     0,     0,   437,     0,   222,   213,     0,   221,
     724,   227,     0,   424,   854,   311,   854,     0,   801,     0,
     758,   311,   311,   244,   720,     0,   752,   702,   701,   695,
       0,   697,   673,   706,    69,   196,    76,    81,   100,   170,
       0,   178,   184,    69,   186,   861,     0,     0,   440,     0,
     809,   808,   659,     0,    69,   125,   858,     0,     0,     0,
       0,   164,   275,   273,   277,   592,    26,     0,   269,     0,
     274,   286,     0,   284,   289,     0,   288,     0,   287,     0,
     129,   247,     0,   249,     0,   785,   496,   494,   505,   503,
     223,     0,   212,   220,   227,     0,   756,     0,     0,     0,
     138,   424,   854,   760,   144,   148,   311,     0,   754,     0,
     709,     0,   192,     0,     0,    69,   173,    99,   185,   876,
     677,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     263,     0,     0,   254,   556,   555,   552,   554,   553,   573,
     575,   574,   544,   515,   516,   534,   550,   549,   511,   521,
     522,   524,   523,   543,   527,   525,   526,   528,   529,   530,
     531,   532,   533,   535,   536,   537,   538,   539,   540,   542,
     541,   512,   513,   514,   517,   518,   520,   558,   559,   568,
     567,   566,   565,   564,   563,   551,   570,   560,   561,   562,
     545,   546,   547,   548,   571,   572,   576,   578,   577,   579,
     580,   557,   582,   581,   584,   586,   585,   519,   589,   587,
     588,   583,   569,   510,   281,   507,     0,   255,   302,   303,
     301,   294,     0,   295,   256,   328,     0,     0,     0,     0,
     129,     0,   225,     0,   755,     0,    69,   304,    69,   132,
       0,     0,   140,   854,   700,     0,    69,   171,    82,   101,
       0,   439,   807,   474,   123,   257,   258,   331,   165,     0,
       0,   278,   270,     0,     0,     0,   283,   285,     0,     0,
     290,   297,   298,   296,     0,     0,   246,     0,     0,     0,
       0,   224,   757,     0,   490,   676,     0,     0,    69,   134,
       0,   708,     0,     0,     0,   103,   260,    58,     0,   261,
     262,     0,     0,   276,   280,   508,   509,     0,   271,   299,
     300,   292,   293,   291,   329,   326,   250,   248,   330,     0,
     491,   675,     0,   426,   305,     0,   136,     0,   174,   475,
       0,   127,     0,   311,   279,   282,     0,   720,   252,     0,
     488,   423,   428,   172,     0,     0,   104,   267,     0,   310,
     327,     0,   676,   322,   720,   489,     0,   126,     0,     0,
     266,   854,   720,   200,   323,   324,   325,   879,   321,     0,
       0,     0,   265,     0,   322,     0,   854,     0,   264,   306,
      69,   251,   879,     0,   204,   202,     0,    69,     0,     0,
     205,     0,   201,   253,     0,   307,     0,   208,   199,     0,
     207,   122,   209,     0,   198,   206,     0,   211,   210
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,   117,   770,   529,   175,   268,   487,
     491,   269,   488,   492,   119,   120,   121,   122,   123,   124,
     310,   554,   555,   441,   233,  1353,   447,  1280,  1354,  1571,
     730,   263,   482,  1535,   949,  1117,  1586,   326,   176,   556,
     806,  1003,  1166,   557,   575,   824,   513,   822,   558,   532,
     823,   328,   284,   299,   130,   808,   772,   756,   964,  1300,
    1052,   872,  1488,  1357,   677,   878,   446,   686,   880,  1199,
     670,   861,   864,  1041,  1591,  1592,   546,   547,   569,   570,
     273,   274,   278,  1124,  1232,  1319,  1468,  1577,  1594,  1499,
    1539,  1540,  1541,  1307,  1308,  1309,  1500,  1506,  1548,  1312,
    1313,  1317,  1461,  1462,  1463,  1479,  1621,  1233,  1234,   177,
     132,  1607,  1608,  1466,  1236,   133,   226,   442,   443,   134,
     135,   136,   137,   138,   139,   140,   141,  1338,   142,   805,
    1002,   143,   230,   305,   437,   537,   538,  1075,   539,  1076,
     144,   145,   146,   709,   147,   148,   260,   149,   261,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   720,   721,
     941,   479,   480,   481,   727,  1525,   150,   533,  1327,   534,
     977,   777,  1140,  1137,  1454,  1455,   151,   152,   153,   220,
     227,   313,   427,   154,   899,   713,   155,   900,   797,   788,
     901,   848,  1023,  1025,  1026,  1027,   850,  1178,  1179,   851,
     651,   412,   188,   189,   156,   549,   393,   394,   794,   157,
     221,   179,   159,   160,   161,   162,   163,   164,   165,   606,
     166,   223,   224,   516,   212,   213,   609,   610,  1081,  1082,
     293,   294,   764,   167,   506,   168,   545,   169,   253,   285,
     321,   564,   565,   893,   985,   754,   690,   691,   692,   254,
     255,   790
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1370
static const yytype_int16 yypact[] =
{
   -1370,   124, -1370, -1370,  5515, 13229, 13229,   -69, 13229, 13229,
   13229, 10996, 13229, -1370, 13229, 13229, 13229, 13229, 13229, 13229,
   13229, 13229, 13229, 13229, 13229, 13229, 14735, 14735, 11199, 13229,
   14818,   -65,   -54, -1370, -1370, -1370, -1370, -1370,   121, -1370,
      89, 13229, -1370,   -54,   -49,   -44,     9,   -54, 11402, 15614,
   11605, -1370, 13951, 10184,    29, 13229, 14501,    34, -1370, -1370,
   -1370,   251,   259,    40,   150,   176,   200,   203, -1370, 15614,
     229,   233, -1370, -1370, -1370, -1370, -1370,   276, 13765, -1370,
   -1370, 15614, -1370, -1370, -1370, -1370, -1370, -1370, 15614, -1370,
     287,   239, 15614, 15614, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   13229, -1370, -1370,   246,   297,   314,   314, -1370,   417,   305,
     283, -1370,   265, -1370,    55, -1370,   440, -1370, -1370, -1370,
   15356,   647, -1370, -1370,   285,   291,   296,   298,   315,   327,
    4242, -1370, -1370, -1370, -1370,   441, -1370,   464,   466,   339,
   -1370,    87,   286,   391, -1370, -1370,   679,     2,  2201,   105,
     347,   106,   118,   348,     1, -1370,    80, -1370,   479, -1370,
   -1370, -1370,   400,   359,   410, -1370,   440,   647, 15823,  2366,
   15823, 13229, 15823, 15823,  4197,   365, 15029, 15823,   520, 15614,
     500,   500,   320,   500,   500,   500,   500,   500,   500,   500,
     500,   500, -1370, -1370, 14384,   398, -1370,   421,   443,   443,
   14735, 15073,   368,   566, -1370,   400, 14384,   398,   429,   430,
     382,   122, -1370,   452,   105, 11808, -1370, -1370, 13229,  8763,
     580,    61, 15823,  9778, -1370, 13229, 13229, 15614, -1370, -1370,
    4374,   396, -1370,  4515, 13951, 13951,   432, -1370, -1370,   393,
    3706,   588, -1370,   593, -1370, 15614,   531, -1370,   413,  4916,
     414,   418, -1370,    -9,  5026, 15432, 15474, 15614,    68, -1370,
      64, -1370, 14518,    70, -1370, -1370, -1370,   599,    71, 14735,
   14735, 13229,   425,   455, -1370, -1370, 14601, 11199,    41,   205,
   -1370, 13432, 14735,   308, -1370, 15614, -1370,   -33,   305, -1370,
   -1370, -1370, 14034,   616,   535,    17,   435, 15823,   437,  2074,
    5718, 13229,    49,   433,   318,    49,   282,   269, -1370, 15614,
   13951,   444, 10387, 13951, -1370, -1370, 13495, -1370, -1370, -1370,
   -1370,   440, -1370, -1370, -1370, -1370, -1370, -1370, -1370, 13229,
   13229, 13229, 12011, 13229, 13229, 13229, 13229, 13229, 13229, 13229,
   13229, 13229, 13229, 13229, 13229, 13229, 13229, 13229, 13229, 13229,
   13229, 13229, 13229, 13229, 14818, 13229, -1370, 13229, 13229, -1370,
   13229,  2551, 15614, 15614, 15356,   533,   469,  9981, 13229, 13229,
   13229, 13229, 13229, 13229, 13229, 13229, 13229, 13229, 13229, 13229,
   -1370, -1370,  2847, -1370,   125, 13229, 13229, -1370, 10387, 13229,
   13229,   246,   126, 14601,   446,   440, 12214,  4962, -1370, 13229,
   -1370,   447,   629, 14384,   448,   -11,  3310,   443, 12417, -1370,
   12620, -1370,   454,    -7, -1370,   110, 10387, -1370,  4290, -1370,
     127, -1370, -1370, 13818, -1370, -1370, 12823, -1370, 13229, -1370,
     556,  8966,   641,   456, 15779,   638,    86,    19, -1370, -1370,
   -1370, -1370, -1370, 13951, 14586,   459,   648, 14245, -1370,   476,
   -1370, -1370, -1370,   581, 13229,   582,   583, 13229, 13229, 13229,
   -1370,   418, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   474,
   -1370, -1370, -1370,   468, -1370, -1370, 15614,   482,   657,   220,
   15614,   483,   674,   238,   243, 15492, -1370, 15614, 13229,   443,
      34, -1370, 14245,   605, -1370,   443,    88,    92,   489,   494,
    2108,   495, 15614,   567,   498,   443,    93,   503, 15416, 15614,
   -1370, -1370,   635,  1714,   -27, -1370, -1370, -1370,   305, -1370,
   -1370, -1370,   569,   536,   223, -1370,   246,   577,   697,   510,
     562,   126, -1370, 13951, 13951,   700,   522,   708, -1370, 13951,
       5,   653,     7, -1370, -1370, -1370, -1370, -1370, -1370,  1798,
   -1370, -1370, -1370, -1370,   711,   552, -1370, 14735, 13229,   525,
     714, 15823,   712, -1370, -1370,   600, 14159, 10573,  2851,  4197,
   13229, 13417, 12400,  3073,  3176, 13005, 11989, 14780, 14780, 14780,
   14780,  1165,  1165,  1165,  1165,   818,   818,   453,   453,   453,
     320,   320,   320, -1370,   500, 15823,   524,   526, 15129,   528,
     722, -1370, 13229,   -53,   541,   126, -1370, -1370, -1370,   440,
   13229, 14435, -1370, -1370,  4197, -1370,  4197,  4197,  4197,  4197,
    4197,  4197,  4197,  4197,  4197,  4197,  4197,  4197, 13229,   -53,
     542,   537,  1921,   546,   547,  2250,    96,   543, -1370, 15823,
   14339, -1370, 15614, -1370,   435,     5,   398, 14735, 15823, 14735,
   15173,    37,   130, -1370,   555, 13229, -1370, -1370, -1370,  8560,
      78, -1370, 15823, 15823,   -54, -1370, -1370, -1370, 13229,   658,
    4632, 14245, 15614,  9169,   557,   559, -1370,    48,   639,   597,
   -1370,   757,   574,  3178, 13951, 14245, 14245, 14245, 14245, 14245,
   -1370,   585,    10,   630,   587, 14245,   258, -1370,   637, -1370,
     589, -1370, 15909, -1370, 13229,   594, 15823,   618,   784, 10981,
     801, -1370, 15823, 13862, -1370,   474,   733, -1370,  5921, 14805,
     614,   249, -1370, 15432, 15614,   266, -1370, 15474, 15614, 15614,
   -1370, -1370,  2424, -1370, 15909,   802, 14735,   619, -1370, -1370,
   -1370, -1370, -1370,   723,    54, 14805,   621, 14601, 14684,   804,
   -1370, -1370, -1370, -1370,   623, -1370, 13229, -1370, -1370,  5106,
   -1370, 14805,   628, -1370, -1370, -1370, -1370,   808, 13229, 14034,
   -1370, -1370, 15562,   631, -1370, 13951,   800,    15, -1370, -1370,
      46,  4940, -1370,   133, -1370, -1370, 13951, -1370, -1370,   443,
   15823, -1370, 10590, -1370, 14245,    27,   642, 14805,   569, -1370,
   -1370, 11791, 13229, -1370, -1370, 13229, -1370, 13229, -1370,  2468,
     646, 10387,   567,   569,   600, 15614, 14818,   443,  2811,   649,
   10387, -1370, -1370,   136, -1370, -1370,   823,  3438,  3438, 14339,
   -1370, -1370, -1370, -1370,   650,   214,   651, -1370, -1370, -1370,
     834,   654,   447,   443,   443, 13026, -1370,   142, -1370, -1370,
    2945,   401,   -54,  9778, -1370,  6124,   652,  6327,   655,  4632,
   14735,   656,   716,   443, 15909,   841, -1370, -1370, -1370, -1370,
     309, -1370,   178, 13951, -1370, 13951, 15614, 14586, -1370, -1370,
   -1370,   847, -1370,   663,   711,    72,    72,   797,   797, 15273,
     667,   863, 14245,   730, 15614, 14034,  4683, 15575, 14245, 14245,
   14245, 14245, 14098, 14245, 14245, 14245, 14245, 14245, 14245, 14245,
   14245, 14245, 14245, 14245, 14245, 14245, 14245, 14245, 14245, 14245,
   14245, 14245, 14245, 14245, 14245, 15823, 13229, 13229, 13229, -1370,
   -1370, -1370, 13229, 13229, -1370,   418, -1370,   798, -1370, -1370,
   15614, -1370, -1370, 15614, -1370, -1370, -1370, -1370, 14245,   443,
   -1370, 13951, 15614, -1370,   867, -1370, -1370,    99,   683,   443,
   10793, -1370,  1664, -1370,  5312,   867, -1370,   211,   184, 15823,
     753, -1370, -1370,   688, 13951,   580, 13951,   809,   875,   813,
   13229,   -53,   698, -1370, 14735, 13229, 15823, 15909,   699,    27,
   -1370,   702,    27,   706, 11791, 15823, 15229,   709, 10387,   707,
     710,   713,   569, -1370,   382,   717, 10387,   718, 13229, -1370,
   -1370, -1370, -1370, -1370, -1370,   778,   704,   905, 14339,   772,
   -1370, 14034, 14339, -1370, -1370, -1370, 14735, 15823, -1370,   -54,
     887,   845,  9778, -1370, -1370, -1370,   721, 13229,   716,   443,
   14601,  4632,   724, 14245,  6530,   334,   726, 13229,    23,   244,
   -1370,   751, -1370,   794, -1370, 13905,   895,   729, 14245, -1370,
   14245, -1370,   731, -1370,   799,   920,   735, -1370, -1370, -1370,
   15329,   734,   926, 11182, 11590, 10370, 14245, 15867,  2505,  1750,
   12600,  4276, 14162, 15663, 15663, 15663, 15663,  1407,  1407,  1407,
    1407,   758,   758,    72,    72,    72,   797,   797,   797,   797,
   15823, 13214, 15823, -1370, 15823, -1370,   739, -1370, -1370, -1370,
   15909, -1370,   842, 14805,    65, -1370, 14601, -1370, -1370,  4197,
     737, -1370,   436, -1370,   166, 13229, -1370, -1370, -1370, 13229,
   -1370, 13229, -1370, -1370, -1370,   257,   925, 14245, -1370,  3493,
     744, 10387,   443, 15823,   800,   745, -1370,   746,    27, 13229,
   10387,   747, -1370, -1370, -1370,   742,   749, -1370, 10387,   750,
   -1370, 14339, -1370, 14339, -1370,   754, -1370,   820,   755,   941,
   -1370,   443,   923, -1370,   756, -1370, -1370,   759,   760,   100,
   -1370, -1370, 15909,   762,   765, -1370,  4131, -1370, -1370, -1370,
   -1370, -1370, 13951, -1370, 13951, -1370, 15909, 15371, -1370, 14245,
   14034, -1370, -1370, 14245, -1370, 14245, -1370, 12197, 14245, 13229,
     766,  6733, 13951, -1370,    32, 13951, 14805, -1370, 15376,   810,
   14863, -1370, -1370, -1370,   533, 13859,    73,   469,   102, -1370,
   -1370,   815,  3623,  3909, 15823,   889,   955,   893, 14245, 15909,
     779, 10387,   777,   866,   800,   558,   800,   781, 15823,   782,
   -1370,  1003,  1083, -1370,    27,   785, -1370, -1370,   853, -1370,
   14339, -1370, 14034, -1370, -1370,  8560, -1370, -1370, -1370, -1370,
    9372, -1370, -1370, -1370,  8560, -1370,   786, 14245, 15909,   856,
   15909, 15427, 12197, 12808, -1370, -1370, -1370, 14805, 14805,   975,
      50, -1370, -1370, -1370, -1370,    74,   791,    76, -1370, 13635,
   -1370, -1370,    77, -1370, -1370, 14177, -1370,   793, -1370,   913,
     440, -1370, 13951, -1370,   533, -1370, -1370, -1370, -1370, -1370,
     979, 14245, -1370, 15909, 10387,   803, -1370,   805,   811,   313,
   -1370,   866,   800, -1370, -1370, -1370,  1319,   806, -1370, 14339,
   -1370,   868,  8560,  9575,  9372, -1370, -1370, -1370,  8560, -1370,
   15909, 14245, 14245, 13229,  6936,   814,   817, 14245, 14805, -1370,
   -1370,   424, 15376, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   116, -1370,   810, -1370, -1370, -1370,
   -1370, -1370,    33,   419, -1370,   983,    81, 15614,   913,   984,
     440, 14245, 15909,   807, -1370,   278, -1370, -1370, -1370, -1370,
     812,   313, -1370,   800, -1370, 14339, -1370, -1370, -1370, -1370,
    7139, 15909, 15909, 11387, -1370, -1370, -1370, 15909, -1370,  3254,
      31, -1370, -1370, 14245, 13635, 13635,   944, -1370, 14177, 14177,
     442, -1370, -1370, -1370, 14245,   929, -1370,   821,    82, 14245,
   15614, 15909, -1370,   930, -1370,  1004,  7342,  7545, -1370, -1370,
     313, -1370,  7748,   822,   937,   915, -1370,   933,   874, -1370,
   -1370,   934,   424, -1370, 15909, -1370, -1370,   872, -1370,   992,
   -1370, -1370, -1370, -1370, 15909,  1018, -1370, -1370, 15909,   837,
   -1370,   312,   838, -1370, -1370,  7951, -1370,   836, -1370, -1370,
     840,   876, 15614,   469, -1370, -1370, 14245,    30, -1370,   958,
   -1370, -1370, -1370, -1370, 14805,   614, -1370,   877, 15614,   512,
   15909,   843,  1033,    22,    30, -1370,   964, -1370, 14805,   846,
   -1370,   800,    42, -1370, -1370, -1370, -1370, 13951, -1370,   848,
     850,    84, -1370,   321,    22,   275,   800,   852, -1370, -1370,
   -1370, -1370, 13951,   970,  1039,   976,   321, -1370,  8154,   277,
    1040, 14245, -1370, -1370,  8357, -1370,   977,  1043,   980, 14245,
   15909, -1370,  1044, 14245, -1370, 15909, 14245, 15909, 15909
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1370, -1370, -1370,  -494, -1370, -1370, -1370,    -4, -1370, -1370,
   -1370,   565,   328,   325,    36,  1123,  3291, -1370,  2363, -1370,
    -384, -1370,    21, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,  -520, -1370, -1370,  -164,    20,     3,
   -1370, -1370, -1370,     6, -1370, -1370, -1370, -1370,    11, -1370,
   -1370,   692,   696,   703,   916,   245,  -767,   253,   300,  -525,
      38,  -825, -1370,  -277, -1370, -1370, -1370, -1370,  -639,  -116,
   -1370, -1370, -1370, -1370,  -513, -1370,  -747, -1370,  -320, -1370,
   -1370,   584, -1370,  -900, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,  -287, -1370, -1370, -1370, -1370, -1370,
    -368, -1370,  -141,  -985, -1370, -1369,  -536, -1370,  -154,    13,
    -130,  -523, -1370,  -375, -1370,   -71,   -21,  1054,  -641,  -354,
   -1370, -1370,   -37, -1370, -1370,  3690,   -67,  -245, -1370, -1370,
   -1370, -1370, -1370, -1370,   112,  -743, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   727, -1370, -1370,   153,
   -1370,   632, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   157,
   -1370,   636, -1370, -1370,   375, -1370,   129, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,  -977, -1370,  1877,  1325,  -331,
   -1370, -1370,    95,  2270,  3683, -1370, -1370,   199,  -152,  -566,
   -1370, -1370,   272,  -631,    83, -1370, -1370, -1370, -1370, -1370,
     260, -1370, -1370, -1370,  -300,  -766,  -185,  -171,  -128, -1370,
   -1370,    28, -1370, -1370, -1370, -1370,   -12,  -158, -1370,    51,
   -1370, -1370, -1370,  -373,   835, -1370, -1370, -1370, -1370, -1370,
      25,   303, -1370, -1370,   844,  -299, -1370, -1370,  -317,   -79,
    -190,  -159,   434, -1370, -1080, -1370,   236, -1370, -1370, -1370,
    -216,  -966
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -847
static const yytype_int16 yytable[] =
{
     118,   332,   375,   542,   803,   548,   572,   127,   402,   300,
     128,   229,   404,   303,   304,   129,   258,   131,   222,   849,
    1145,   986,   234,   622,   126,   125,   238,   424,   451,   452,
     646,   397,   158,   603,   456,   769,   980,   868,   429,   306,
    1542,  1001,  1508,   308,  1048,   241,   882,   332,   251,   684,
     669,   329,   430,  1197,   208,   209,  1011,   883,   998,  1368,
      13,   421,    13,   962,   323,   283,  1509,   399,  -744,  1224,
     438,   395,    13,  -748,  1253,    13,  1132,   495,   643,   500,
     503,   987,  1322,  -272,   283,  1372,  1456,    13,   283,   283,
    1515,  1515,   270,  1368,   903,   682,   431,   746,   728,   483,
     392,   746,   758,   395,   566,   758,   664,   518,   758,   758,
      13,   758,  1529,   271,   297,   320,   392,   298,   319,   277,
     392,   931,   932,   933,     3,   988,   283,   181,   288,  -429,
    1503,   225,   791,   414,  1604,  1605,  1606,   934,   309,   314,
     316,   317,   228,  -846,   541,   422,  1504,   235,  -595,   862,
     863,   331,   236,  -741,   290,  -454,   484,  1297,  1298,   202,
     497,  1566,  1074,  1505,   428,   530,   531,   576,   519,   376,
    1225,   395,  -742,   768,  1339,  1226,  1341,    58,    59,    60,
     170,   171,   330,  1227,  -743,   411,   552,  -594,  -779,   202,
     662,  -745,   399,  -780,   291,   292,  -782,   405,  -750,  -746,
     400,  -744,  -747,  -751,   396,   237,  -748,   989,  -781,  -675,
     508,  -217,  -675,   615,   509,   319,  1241,   884,   685,  1228,
    1229,  1198,  1230,   963,  -217,   118,  1190,  -203,   262,   118,
    1510,  1543,   415,   445,   615,   272,   396,   687,   417,  -675,
    1055,   647,  1059,    95,   423,  1165,   332,   574,  1369,  1370,
     435,   458,  1155,   324,   440,  1157,  1255,   158,   615,   439,
     653,   158,  1481,  1261,  1262,  1231,   496,   615,   501,   504,
     615,  1323,  -272,   774,  1373,  1457,   974,  1057,  1058,  1516,
    1557,   401,  1618,   683,   288,   747,  -741,   865,  1177,   748,
     759,   867,  1245,   836,   300,   329,  1125,  1279,  1029,  1325,
     499,   489,   493,   494,   396,  -742,   118,   505,   505,   510,
    1623,   113,  1636,  1523,   515,   563,   734,  -743,   301,   251,
     524,  -779,   283,   131,  -745,   400,  -780,   783,   784,  -782,
     126,   528,  -746,   789,   738,  -747,  1246,  1138,   158,   739,
     623,  -781,   654,  1057,  1058,   950,   279,  1579,   288,   520,
     291,   292,   222,   525,  1624,   288,  1637,  1524,  1030,   614,
     289,   288,   953,  1346,  1133,   792,   525,   613,   283,   283,
     283,   319,   280,   364,   275,   775,   288,  1134,  1060,   793,
     640,   312,   276,  1139,   967,   365,   780,   288,   639,   319,
     776,  1580,   525,   288,   319,   619,   281,   288,   315,   282,
     319,  1180,   525,  1530,   614,  -846,  1187,  1056,  1057,  1058,
    1135,  1257,   656,   663,   291,   292,   667,   319,  1247,   607,
     290,   291,   292,   820,   666,   286,   320,   291,   292,   287,
    -846,   515,  1194,  1057,  1058,   302,  1625,   118,  1638,   301,
    1224,   415,   291,   292,  1200,   311,   641,   318,  1511,   829,
     644,   320,   526,   291,   292,   825,   319,  -846,   818,   291,
     292,   322,   676,   291,   292,  1512,   820,  1289,  1513,   158,
     792,  1551,  1039,  1040,   562,   325,   856,   566,   566,  -846,
     542,    13,  -846,   333,   793,   370,   561,   548,  1552,   334,
     857,  1553,  1054,   741,   335,  1014,   336,   810,    33,    34,
      35,  1009,   361,   362,   363,   548,   364,  -452,   753,   700,
    1017,  1477,  1478,   337,   763,   765,   424,  1347,   365,  1619,
    1620,  1613,   731,  1549,  1550,   338,   735,  1545,  1546,  1351,
     367,   270,   368,   858,   891,   894,  1626,   369,   371,   888,
    1267,  1225,  1268,   398,  -749,  -453,  1226,  -594,    58,    59,
      60,   170,   171,   330,  1227,   403,    72,    73,    74,    75,
      76,   295,  1224,   408,   410,   365,   320,   702,   416,   983,
     392,   419,   283,    79,    80,   420,  -593,   425,   426,   428,
     993,    58,    59,    60,   170,   171,   330,    89,   436,   454,
    1228,  1229,   521,  1230,   449,   799,   527,   463,   464,   465,
     453,    94,  -841,    13,   466,   467,   542,   457,   468,   469,
     459,   460,   462,   502,    95,   521,  1127,   527,   521,   527,
     527,   541,   511,   512,    58,    59,    60,   170,   171,   330,
     543,   544,   550,   615,   551,   560,  1240,    51,   652,  1350,
     -64,  1615,   573,   650,   674,   655,   847,    95,   852,   827,
     438,   661,   681,   866,   678,   693,  1629,   694,   714,   726,
     715,   717,   718,  1225,   729,   118,   733,  1061,  1226,  1062,
      58,    59,    60,   170,   171,   330,  1227,  1189,   875,   118,
     732,   736,   131,   737,   745,   853,   749,   854,  1161,   126,
      95,   750,   755,   752,   757,   771,  1169,   158,  1033,   548,
     760,   766,   548,   773,   877,   778,   779,   781,   873,   782,
    1600,   158,  1228,  1229,   785,  1230,   786,   787,  1484,  -455,
     796,   798,   801,   802,   118,   807,   804,   813,   816,   814,
     952,   817,   542,  1221,   955,   956,    95,   821,   830,   809,
     831,   131,  1067,   833,   886,  1121,  1013,   541,   126,  1071,
     834,    51,   859,  1238,   869,   879,   158,   881,  1340,    58,
      59,    60,   170,   171,   330,   118,   887,   885,  1143,   489,
     789,   889,   127,   493,   959,   128,   936,   904,   981,   992,
     129,   902,   131,   905,   907,   515,   969,   991,   908,   126,
     125,    58,    59,    60,    61,    62,   330,   158,   938,  1275,
     937,  1150,    68,   372,   928,   929,   930,   931,   932,   933,
     942,  1593,   945,   948,   222,  1284,   958,   960,   970,   961,
     966,   283,   978,   934,  1237,    95,   971,   976,  1593,   982,
     984,  1252,  1237,  1022,  1022,   847,  1614,  1018,   999,   373,
    1259,  1042,  1008,  1032,  1051,  1016,  1028,  1031,  1265,   993,
    1045,  1034,  1050,  1047,  1531,  1053,  1065,    95,   548,   118,
    1066,   118,   934,   118,   358,   359,   360,   361,   362,   363,
    1069,   364,  1070,   541,   520,  1174,  1123,  1116,   131,  1126,
     131,  1141,  1063,   365,  1043,   126,  1142,   126,  1146,  1147,
    1352,   158,  1148,   158,  1151,   158,  1154,   873,  1049,  1358,
    1073,  1156,  1158,  1079,  1162,  1160,  1171,  1172,  1299,  1163,
    1364,   542,  1164,  1168,  1173,  1170,  1176,  1183,  1184,  1186,
    1201,  1191,  1202,  1211,  1195,  1204,  1205,  1209,  1208,  1210,
    1216,  1335,  1212,  1128,  1214,  1215,  1220,  1239,  1222,  1248,
    1251,  1263,  1254,  1256,  1260,  1264,  1118,  1266,  1270,  1119,
    1272,  1269,  1271,  1274,  1276,  1237,  1277,  1278,  1122,  1562,
    1281,  1237,  1237,  1282,   548,  1294,  1311,  1326,  1330,  1331,
     118,  1490,  1332,   542,  1336,  1334,  1337,   127,  1342,  1343,
     128,  1349,  1348,  1359,  1361,   129,  1285,   131,  1286,  1367,
    1371,  1464,  1465,  1471,   126,   125,  1485,  1514,  1519,  1547,
    1474,  1475,   158,  1483,  1522,  1469,  1296,  1224,  1555,  1560,
    1476,  1528,  1495,  1561,  1473,  1496,  1569,  1556,  1182,  1321,
    1568,  1572,  1152,  1570,   847,  1509,  1603,  1273,   847,  -268,
    1573,  1575,  1576,  1578,  1583,  1581,  1584,  1595,   118,  1598,
    1601,  1585,  1602,  1610,  1612,  1616,  1237,  1617,    13,  1630,
     118,  1627,   541,  1631,  1639,  1632,  1642,  1643,  1646,  1644,
     740,   951,   954,  1185,  1181,  1597,   618,   131,   616,  1012,
     158,   975,   374,  1611,   126,  1010,   617,  1489,   515,   873,
    1283,  1609,   158,  1324,   743,  1502,  1188,  1224,  1507,  1318,
    1633,  1622,  1526,  1518,  1527,   231,  1480,  1144,  1115,  1113,
     944,  1072,  1532,   724,   625,   332,  1136,   725,  1225,  1167,
    1024,  1175,  1035,  1226,   541,    58,    59,    60,   170,   171,
     330,  1227,   517,  1064,   507,     0,     0,   892,    13,     0,
       0,     0,     0,     0,     0,     0,     0,  1235,     0,     0,
       0,     0,     0,     0,  1565,  1235,     0,     0,     0,   205,
     205,     0,     0,   217,   515,     0,  1467,  1228,  1229,     0,
    1230,     0,     0,     0,     0,     0,     0,   847,     0,   847,
       0,     0,     0,     0,     0,   217,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,  1225,     0,
       0,     0,     0,  1226,     0,    58,    59,    60,   170,   171,
     330,  1227,     0,  1344,     0,  -847,  -847,  -847,  -847,   356,
     357,   358,   359,   360,   361,   362,   363,   118,   364,     0,
       0,   251,     0,     0,     0,     0,  1316,     0,     0,     0,
     365,     0,     0,     0,   131,     0,  1628,  1228,  1229,     0,
    1230,   126,     0,  1634,     0,     0,     0,     0,     0,   158,
     376,     0,     0,     0,  1320,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,   847,     0,  1235,     0,
       0,   118,     0,     0,  1235,  1235,   118,   548,     0,     0,
     118,     0,     0,  1345,     0,     0,     0,     0,   131,     0,
       0,     0,     0,     0,   548,   126,     0,   131,     0,     0,
       0,  1356,   548,   158,   126,  1453,  1520,     0,   158,     0,
       0,  1460,   158,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,  1224,     0,     0,     0,   205,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,     0,   205,
       0,     0,     0,     0,  1470,   847,     0,     0,   118,   118,
     118,   207,   207,     0,   118,   219,     0,     0,     0,  1235,
     118,     0,     0,     0,    13,   131,     0,   217,   217,     0,
       0,   131,   126,   217,  1487,  1356,     0,   131,   126,     0,
     158,   158,   158,     0,   126,     0,   158,     0,  1517,     0,
       0,   789,   158,     0,     0,   205,     0,     0,     0,     0,
       0,     0,   205,   205,     0,     0,   789,     0,     0,   205,
       0,     0,     0,     0,     0,   205,     0,     0,     0,  1588,
       0,     0,     0,     0,  1225,   217,     0,     0,     0,  1226,
       0,    58,    59,    60,   170,   171,   330,  1227,     0,     0,
       0,  1559,     0,   217,     0,     0,   217,  -847,  -847,  -847,
    -847,   926,   927,   928,   929,   930,   931,   932,   933,   332,
       0,     0,     0,   283,     0,     0,     0,     0,     0,     0,
       0,     0,   934,  1228,  1229,     0,  1230,     0,     0,     0,
       0,   847,     0,     0,     0,     0,   118,   217,     0,     0,
       0,     0,     0,     0,     0,  1537,     0,    95,     0,     0,
    1453,  1453,     0,   131,  1460,  1460,     0,     0,     0,     0,
     126,     0,     0,     0,     0,     0,   283,     0,   158,  1482,
       0,     0,   118,   118,     0,     0,   205,     0,   118,   207,
       0,     0,     0,     0,     0,   207,   205,     0,     0,   131,
     131,   207,     0,     0,     0,   131,   126,   126,     0,     0,
       0,     0,   126,     0,   158,   158,     0,     0,     0,     0,
     158,   118,     0,     0,     0,     0,     0,     0,  1587,     0,
       0,     0,     0,     0,     0,     0,   217,   217,   131,     0,
     706,     0,     0,     0,  1599,   126,  1589,     0,     0,     0,
       0,     0,     0,   158,     0,     0,     0,   207,     0,     0,
       0,     0,     0,     0,   207,   207,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,     0,   207,     0,     0,
       0,     0,     0,     0,   118,   706,     0,   540,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,     0,     0,     0,   131,   126,     0,
       0,     0,     0,     0,   126,     0,   158,     0,     0,     0,
       0,     0,   158,     0,     0,     0,   217,   217,     0,     0,
       0,     0,   217,     0,   339,   340,   341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     205,     0,     0,   342,     0,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,     0,   364,     0,     0,
       0,     0,     0,     0,   339,   340,   341,     0,   207,   365,
       0,     0,     0,     0,     0,     0,     0,     0,   207,     0,
       0,     0,     0,   342,   205,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,     0,   364,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   365,
     205,     0,   205,   915,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,   933,     0,   205,   706,     0,     0,     0,   339,   340,
     341,     0,     0,     0,     0,   934,   217,   217,   706,   706,
     706,   706,   706,     0,     0,     0,     0,   342,   706,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
       0,   364,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   365,     0,     0,     0,  1130,     0,   205,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
     205,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   207,     0,   217,     0,     0,     0,     0,     0,
       0,     0,   217,   206,   206,     0,     0,   218,   217,     0,
       0,     0,     0,     0,   767,     0,     0,     0,     0,   217,
       0,     0,     0,     0,     0,     0,     0,   706,     0,     0,
     217,   339,   340,   341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,   217,
     342,     0,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,     0,   364,     0,     0,     0,     0,     0,
       0,     0,   207,     0,   207,     0,   365,     0,     0,     0,
       0,     0,   205,   205,     0,     0,     0,     0,   795,     0,
       0,     0,     0,     0,     0,   207,   217,     0,   217,     0,
     217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   706,     0,     0,   217,     0,
       0,   706,   706,   706,   706,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   706,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   706,   207,   207,   217,     0,     0,   206,   406,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,     0,     0,     0,   540,     0,     0,   217,     0,   217,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
       0,   832,   406,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,     0,     0,   390,   391,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   206,
       0,   219,     0,     0,   217,     0,   206,   206,     0,   205,
       0,     0,     0,   206,     0,     0,     0,     0,     0,   206,
       0,   390,   391,   205,   205,     0,   706,     0,     0,   206,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
       0,   706,     0,   706,   207,   207,     0,     0,     0,     0,
       0,   392,     0,     0,     0,     0,     0,     0,     0,   706,
       0,     0,     0,     0,     0,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,     0,     0,
     540,     0,     0,     0,     0,   392,     0,     0,     0,     0,
       0,   218,     0,     0,     0,     0,   217,     0,     0,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     339,   340,   341,     0,   390,   391,     0,     0,     0,     0,
     706,   552,     0,     0,     0,     0,     0,     0,     0,   342,
     206,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,     0,   364,     0,   751,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,     0,     0,     0,   207,
       0,     0,     0,     0,     0,   217,     0,   217,   392,     0,
       0,     0,   706,   217,   710,     0,   706,     0,   706,     0,
       0,   706,     0,     0,     0,   217,     0,     0,   217,   217,
       0,   217,     0,     0,     0,     0,   540,     0,   217,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   706,     0,     0,     0,   207,   207,     0,     0,   710,
     406,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,     0,     0,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     706,     0,     0,     0,     0,   252,     0,     0,     0,     0,
     217,   217,     0,     0,     0,     0,     0,     0,     0,   390,
     391,     0,     0,     0,   339,   340,   341,     0,     0,     0,
       0,     0,     0,     0,   206,   217,     0,     0,     0,     0,
     835,   207,     0,   342,   706,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,     0,   364,   339,   340,
     341,     0,     0,     0,   706,   706,     0,     0,     0,   365,
     706,   217,     0,   392,     0,   217,     0,   342,   206,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
       0,   364,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   365,   206,   540,   206,   914,   915,   916,
     917,   918,   919,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   206,   710,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     934,     0,   710,   710,   710,   710,   710,     0,     0,     0,
       0,     0,   710,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   706,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,   947,   252,   252,     0,
       0,     0,     0,   252,     0,     0,     0,     0,     0,     0,
       0,     0,   217,   206,   957,     0,   706,     0,    36,     0,
     202,     0,   965,     0,   206,   206,     0,   706,     0,     0,
       0,     0,   706,     0,     0,     0,     0,     0,   965,     0,
       0,     0,     0,     0,     0,     0,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1007,     0,
       0,     0,     0,     0,   611,     0,     0,     0,     0,     0,
       0,   710,     0,   252,  1000,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   706,
       0,     0,     0,   218,     0,    83,    84,   217,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,     0,     0,     0,     0,   711,     0,     0,
     217,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,     0,   217,   206,   206,     0,     0,
     612,     0,   113,     0,   706,     0,     0,     0,     0,     0,
       0,     0,   706,     0,     0,     0,   706,     0,     0,   706,
       0,     0,   711,     0,     0,     0,     0,     0,     0,   710,
       0,     0,   206,     0,     0,   710,   710,   710,   710,   710,
     710,   710,   710,   710,   710,   710,   710,   710,   710,   710,
     710,   710,   710,   710,   710,   710,   710,   710,   710,   710,
     710,   710,     0,     0,     0,     0,   252,   689,     0,     0,
     708,   339,   340,   341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   710,     0,     0,     0,     0,
     342,     0,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   341,   364,   708,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,   365,     0,     0,     0,
     342,     0,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,     0,   364,     0,   252,   252,   206,     0,
       0,     0,   252,   206,     0,     0,   365,     0,     0,     0,
       0,     0,     0,     0,    36,     0,   202,   206,   206,     0,
     710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   710,     0,   710,     0,     0,
       0,   711,     0,     0,     0,   339,   340,   341,     0,     0,
       0,     0,     0,   710,     0,   711,   711,   711,   711,   711,
       0,     0,     0,     0,   342,   711,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,     0,   364,     0,
    1223,    83,    84,   206,    85,    86,    87,     0,     0,     0,
     365,  1015,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   710,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,   708,     0,   638,     0,   113,     0,
       0,     0,     0,     0,     0,     0,   252,   252,   708,   708,
     708,   708,   708,     0,     0,     0,     0,     0,   708,     0,
       0,     0,     0,     0,   711,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   710,   206,     0,     0,
     710,     0,   710,     0,     0,   710,     0,     0,     0,     0,
       0,     0,     0,  1301,     0,  1310,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   710,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,  1038,     0,     0,   252,   206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,   710,     0,     0,   708,     0,     0,
       0,     0,   711,     0,  1365,  1366,     0,     0,   711,   711,
     711,   711,   711,   711,   711,   711,   711,   711,   711,   711,
     711,   711,   711,   711,   711,   711,   711,   711,   711,   711,
     711,   711,   711,   711,   711,     0,     0,   244,   710,     0,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   711,   364,
       0,     0,     0,   245,     0,     0,     0,     0,   710,   710,
       0,   365,     0,     0,   710,  1498,   252,     0,   252,  1310,
     689,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   708,     0,     0,     0,     0,
       0,   708,   708,   708,   708,   708,   708,   708,   708,   708,
     708,   708,   708,   708,   708,   708,   708,   708,   708,   708,
     708,   708,   708,   708,   708,   708,   708,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   708,     0,   711,   252,     0,   174,     0,     0,    81,
     248,    36,    83,    84,     0,    85,    86,    87,   711,   890,
     711,     0,     0,     0,     0,     0,     0,   252,   710,   252,
     249,     0,     0,     0,     0,     0,   711,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   250,     0,     0,     0,     0,     0,
     710,     0,     0,     0,     0,     0,     0,    36,     0,   202,
       0,   710,     0,     0,     0,     0,   710,     0,     0,     0,
       0,     0,   174,     0,     0,    81,     0,     0,    83,    84,
       0,    85,    86,    87,     0,     0,   708,   711,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,   708,     0,   708,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   708,
       0,     0,     0,   710,  1536,     0,     0,     0,     0,     0,
       0,  1596,     0,     0,    83,    84,     0,    85,    86,    87,
       0,     0,     0,     0,     0,  1301,     0,     0,     0,   711,
       0,     0,     0,   711,     0,   711,     0,     0,   711,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   339,   340,   341,     0,     0,   710,   612,
     708,   113,  1019,  1020,  1021,    36,   710,     0,   711,     0,
     710,     0,   342,   710,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   711,   365,     0,
       0,     0,     0,     0,     0,   252,     0,   252,     0,     0,
       0,     0,   708,     0,     0,     0,   708,     0,   708,     0,
       0,   708,     0,     0,     0,   252,     0,     0,   252,     0,
       0,     0,    83,    84,     0,    85,    86,    87,   252,     0,
       0,   711,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   708,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   711,   711,   339,   340,   341,     0,   711,     0,     0,
       0,  1501,     0,     0,     0,     0,     0,     0,     0,     0,
     708,     0,   342,     0,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,   252,     0,     0,   365,     0,
       0,     0,     0,  1250,   708,   178,   180,     0,   182,   183,
     184,   186,   187,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,     0,   211,   214,
       0,     0,     0,     0,   708,   708,     0,     0,     0,     0,
     708,   232,     0,     0,     0,   244,     0,     0,   240,     0,
     243,   711,     0,   259,     0,   264,     0,     0,   707,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   711,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,   711,     0,     0,     0,     0,   711,
       0,     0,     0,   707,     0,     0,     0,     0,     0,     0,
     307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     455,     0,  1574,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1328,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   708,     0,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   711,     0,     0,     0,
       0,     0,     0,     0,   174,     0,     0,    81,   248,     0,
      83,    84,  1538,    85,    86,    87,   708,     0,     0,     0,
       0,   407,     0,     0,     0,     0,     0,   708,   249,     0,
       0,     0,   708,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,   711,   250,     0,     0,     0,     0,     0,     0,   711,
       0,     0,     0,   711,     0,   433,   711,     0,   433,   339,
     340,   341,     0,     0,     0,   232,   444,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   342,   708,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,     0,   364,     0,     0,     0,     0,     0,     0,     0,
     252,   307,   707,     0,   365,     0,     0,   211,     0,     0,
       0,   523,     0,     0,     0,   252,   707,   707,   707,   707,
     707,     0,     0,     0,   708,     0,   707,     0,     0,     0,
       0,   559,   708,     0,     0,     0,   708,     0,     0,   708,
       0,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   577,
     578,   579,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,     0,   604,     0,   605,   605,     0,
     608,     0,     0,     0,     0,     0,     0,   624,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
       0,     0,     0,     0,     0,   605,   642,     0,   571,   605,
     645,     0,     0,     0,     0,   707,   624,     0,     0,   649,
       0,     0,     0,     0,     0,     0,     0,     0,   658,  1329,
     660,     0,     0,     0,     0,     0,   571,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   672,     0,   673,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     712,   339,   340,   341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   716,     0,     0,   719,   722,   723,
     342,  1197,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,     0,   364,   744,     0,     0,   742,     0,
       0,     0,     0,   707,     0,     0,   365,     0,     0,   707,
     707,   707,   707,   707,   707,   707,   707,   707,   707,   707,
     707,   707,   707,   707,   707,   707,   707,   707,   707,   707,
     707,   707,   707,   707,   707,   707,   342,     0,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   707,
     364,     0,   339,   340,   341,     0,     0,     0,   800,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,     0,
     811,   342,     0,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,     0,   364,     0,     0,     0,     0,
       0,     0,   819,     0,     0,     0,     0,   365,     0,     0,
     186,   917,   918,   919,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   931,   932,   933,   828,  1198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   934,     0,     0,   707,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   860,     0,     0,     0,   707,
       0,   707,     0,     0,   874,     0,     0,    36,   232,   202,
       0,     0,     0,     0,     0,     0,     0,   707,   895,   896,
     897,   898,     0,     0,   339,   340,   341,     0,   906,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   342,   935,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,     0,   364,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   707,   365,
     366,     0,     0,     0,    83,    84,     0,    85,    86,    87,
       0,     0,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   979,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   997,     0,   665,
       0,   113,   996,     0,     0,     0,     0,     0,     0,     0,
     707,     0,  1004,     0,   707,  1005,   707,  1006,     0,   707,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
     571,     0,     0,     0,     0,   339,   340,   341,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   707,
       0,     0,     0,     0,   342,  1037,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,     0,   364,     0,
       0,     0,   448,     0,     0,     0,     0,     0,   707,     0,
     365,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1080,  1083,  1084,  1085,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,     0,     0,
       0,     0,   707,     0,     0,     0,  1110,  1111,  1112,     0,
       0,     0,   719,  1114,     0,     0,     0,     0,     0,     0,
       0,  1120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   707,   707,     0,     0,     0,     0,   707,     0,
    1129,     0,     0,     0,     0,     0,     0,   870,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1149,     0,     0,     0,     0,  1153,     0,     0,     0,     0,
       0,     0,     0,   909,   910,   911,     0,     0,   571,     0,
       0,     0,     0,     0,     0,     0,   571,     0,  1129,    36,
       0,   202,   912,   450,   913,   914,   915,   916,   917,   918,
     919,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,     0,  1192,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1196,   934,   203,
       0,  1206,     0,  1207,     0,     0,     0,     0,     0,     0,
       0,   871,   707,     0,     0,     0,     0,     0,     0,  1217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,     0,     0,    81,    82,     0,    83,    84,     0,    85,
      86,    87,     0,     0,   707,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   707,     0,     0,     0,     0,
     707,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,  1242,     0,     0,   204,  1243,
    1249,  1244,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,  1258,
     571,     0,     0,     0,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,     0,     0,     0,   707,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1077,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1288,     0,     0,     0,  1290,     0,  1291,     0,
       0,  1292,     0,     0,     0,     0,     0,     0,     0,  1293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   707,     0,     0,     0,   339,   340,   341,     0,
     707,  1333,     0,     0,   707,     0,     0,   707,     0,     0,
       0,   571,     0,     0,     0,   342,     0,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,     0,   364,
    1360,     0,   339,   340,   341,     0,     0,     0,     0,     0,
       0,   365,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   342,     0,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,  1472,   364,     0,    36,     0,   202,
       0,     0,     0,     0,   571,     0,     0,   365,     0,     0,
       0,     0,     0,     0,     0,     0,   339,   340,   341,     0,
       0,     0,     0,     0,  1491,  1492,     0,     0,     0,     0,
    1497,     0,     0,  1493,     0,   342,     0,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,     0,   364,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   365,     0,     0,    83,    84,     0,    85,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,   461,     0,     0,     0,     0,    10,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    11,    12,     0,     0,     0,     0,   990,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,  1521,     0,     0,     0,    16,   648,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,     0,     0,     0,
      33,    34,    35,    36,    37,    38,  1544,    39,     0,     0,
       0,    40,    41,    42,    43,     0,    44,  1554,    45,     0,
      46,     0,  1558,    47,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    54,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   485,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,    70,    71,     0,    72,    73,
      74,    75,    76,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,    78,    79,    80,    81,    82,  1590,
      83,    84,     0,    85,    86,    87,    88,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,     0,    91,    92,
       0,    93,     0,    94,    95,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,   110,     0,   111,   112,   973,   113,   114,     0,
     115,   116,     0,     0,  1640,     5,     6,     7,     8,     9,
       0,     0,  1645,     0,     0,    10,  1647,     0,     0,  1648,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    15,
       0,     0,     0,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,    39,     0,     0,     0,    40,    41,    42,
      43,     0,    44,     0,    45,     0,    46,     0,     0,    47,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    54,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,    70,    71,     0,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
      78,    79,    80,    81,    82,     0,    83,    84,     0,    85,
      86,    87,    88,     0,     0,    89,     0,     0,    90,     0,
       0,     0,     0,     0,    91,    92,     0,    93,     0,    94,
      95,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,     0,
     111,   112,  1131,   113,   114,     0,   115,   116,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,    15,     0,     0,     0,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,    39,     0,     0,     0,
      40,    41,    42,    43,     0,    44,     0,    45,     0,    46,
       0,     0,    47,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,    68,    69,
       0,     0,     0,     0,    70,    71,     0,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,     0,    83,
      84,     0,    85,    86,    87,    88,     0,     0,    89,     0,
       0,    90,     0,     0,     0,     0,     0,    91,    92,     0,
      93,     0,    94,    95,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,   110,     0,   111,   112,     0,   113,   114,     0,   115,
     116,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,     0,     0,     0,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,    32,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,    39,
       0,     0,     0,    40,    41,    42,    43,     0,    44,     0,
      45,     0,    46,     0,     0,    47,     0,     0,     0,    48,
      49,    50,    51,     0,    53,    54,     0,    55,     0,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
       0,    68,    69,     0,     0,     0,     0,    70,    71,     0,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,   174,    79,    80,    81,
      82,     0,    83,    84,     0,    85,    86,    87,    88,     0,
       0,    89,     0,     0,    90,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,    94,    95,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,   110,     0,   111,   112,   553,   113,
     114,     0,   115,   116,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,     0,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,    32,     0,     0,     0,    33,    34,    35,    36,    37,
      38,     0,    39,     0,     0,     0,    40,    41,    42,    43,
       0,    44,     0,    45,     0,    46,     0,     0,    47,     0,
       0,     0,    48,    49,    50,    51,     0,    53,    54,     0,
      55,     0,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,     0,    68,    69,     0,     0,     0,     0,
      70,    71,     0,    72,    73,    74,    75,    76,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,   174,
      79,    80,    81,    82,     0,    83,    84,     0,    85,    86,
      87,    88,     0,     0,    89,     0,     0,    90,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,    94,    95,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,   110,     0,   111,
     112,   946,   113,   114,     0,   115,   116,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,     0,     0,     0,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,    39,     0,     0,     0,    40,
      41,    42,    43,     0,    44,     0,    45,     0,    46,     0,
       0,    47,     0,     0,     0,    48,    49,    50,    51,     0,
      53,    54,     0,    55,     0,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,     0,    68,    69,     0,
       0,     0,     0,    70,    71,     0,    72,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,   174,    79,    80,    81,    82,     0,    83,    84,
       0,    85,    86,    87,    88,     0,     0,    89,     0,     0,
      90,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,    94,    95,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
     110,     0,   111,   112,  1044,   113,   114,     0,   115,   116,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,    15,     0,     0,     0,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,    32,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,    39,     0,
       0,     0,    40,    41,    42,    43,  1046,    44,     0,    45,
       0,    46,     0,     0,    47,     0,     0,     0,    48,    49,
      50,    51,     0,    53,    54,     0,    55,     0,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,     0,
      68,    69,     0,     0,     0,     0,    70,    71,     0,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,   174,    79,    80,    81,    82,
       0,    83,    84,     0,    85,    86,    87,    88,     0,     0,
      89,     0,     0,    90,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,    94,    95,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,   110,     0,   111,   112,     0,   113,   114,
       0,   115,   116,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,     0,     0,
       0,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,    39,     0,     0,     0,    40,    41,    42,    43,     0,
      44,     0,    45,     0,    46,  1193,     0,    47,     0,     0,
       0,    48,    49,    50,    51,     0,    53,    54,     0,    55,
       0,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,     0,    68,    69,     0,     0,     0,     0,    70,
      71,     0,    72,    73,    74,    75,    76,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,   174,    79,
      80,    81,    82,     0,    83,    84,     0,    85,    86,    87,
      88,     0,     0,    89,     0,     0,    90,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,    94,    95,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,   110,     0,   111,   112,
       0,   113,   114,     0,   115,   116,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,     0,     0,     0,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,    32,     0,     0,     0,    33,    34,    35,
      36,    37,    38,     0,    39,     0,     0,     0,    40,    41,
      42,    43,     0,    44,     0,    45,     0,    46,     0,     0,
      47,     0,     0,     0,    48,    49,    50,    51,     0,    53,
      54,     0,    55,     0,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,     0,    68,    69,     0,     0,
       0,     0,    70,    71,     0,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,   174,    79,    80,    81,    82,     0,    83,    84,     0,
      85,    86,    87,    88,     0,     0,    89,     0,     0,    90,
       0,     0,     0,     0,     0,    91,     0,     0,     0,     0,
      94,    95,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,   110,
       0,   111,   112,  1295,   113,   114,     0,   115,   116,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,     0,     0,     0,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,    39,     0,     0,
       0,    40,    41,    42,    43,     0,    44,     0,    45,     0,
      46,     0,     0,    47,     0,     0,     0,    48,    49,    50,
      51,     0,    53,    54,     0,    55,     0,    57,    58,    59,
      60,    61,    62,    63,     0,    64,    65,    66,     0,    68,
      69,     0,     0,     0,     0,    70,    71,     0,    72,    73,
      74,    75,    76,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,   174,    79,    80,    81,    82,     0,
      83,    84,     0,    85,    86,    87,    88,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,    94,    95,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,   110,     0,   111,   112,  1494,   113,   114,     0,
     115,   116,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,     0,     0,     0,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
       0,     0,     0,    33,    34,    35,    36,    37,    38,     0,
      39,     0,     0,     0,    40,    41,    42,    43,     0,    44,
       0,    45,  1533,    46,     0,     0,    47,     0,     0,     0,
      48,    49,    50,    51,     0,    53,    54,     0,    55,     0,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,     0,    68,    69,     0,     0,     0,     0,    70,    71,
       0,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,   174,    79,    80,
      81,    82,     0,    83,    84,     0,    85,    86,    87,    88,
       0,     0,    89,     0,     0,    90,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,    94,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,   110,     0,   111,   112,     0,
     113,   114,     0,   115,   116,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    15,
       0,     0,     0,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,    39,     0,     0,     0,    40,    41,    42,
      43,     0,    44,     0,    45,     0,    46,     0,     0,    47,
       0,     0,     0,    48,    49,    50,    51,     0,    53,    54,
       0,    55,     0,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    65,    66,     0,    68,    69,     0,     0,     0,
       0,    70,    71,     0,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
     174,    79,    80,    81,    82,     0,    83,    84,     0,    85,
      86,    87,    88,     0,     0,    89,     0,     0,    90,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,    94,
      95,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,     0,
     111,   112,  1563,   113,   114,     0,   115,   116,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,    15,     0,     0,     0,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,    39,     0,     0,     0,
      40,    41,    42,    43,     0,    44,     0,    45,     0,    46,
       0,     0,    47,     0,     0,     0,    48,    49,    50,    51,
       0,    53,    54,     0,    55,     0,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,     0,    68,    69,
       0,     0,     0,     0,    70,    71,     0,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,   174,    79,    80,    81,    82,     0,    83,
      84,     0,    85,    86,    87,    88,     0,     0,    89,     0,
       0,    90,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,    94,    95,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,   110,     0,   111,   112,  1564,   113,   114,     0,   115,
     116,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,     0,     0,     0,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,    32,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,    39,
       0,     0,     0,    40,    41,    42,    43,     0,    44,  1567,
      45,     0,    46,     0,     0,    47,     0,     0,     0,    48,
      49,    50,    51,     0,    53,    54,     0,    55,     0,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
       0,    68,    69,     0,     0,     0,     0,    70,    71,     0,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,   174,    79,    80,    81,
      82,     0,    83,    84,     0,    85,    86,    87,    88,     0,
       0,    89,     0,     0,    90,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,    94,    95,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,   110,     0,   111,   112,     0,   113,
     114,     0,   115,   116,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,     0,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,    32,     0,     0,     0,    33,    34,    35,    36,    37,
      38,     0,    39,     0,     0,     0,    40,    41,    42,    43,
       0,    44,     0,    45,     0,    46,     0,     0,    47,     0,
       0,     0,    48,    49,    50,    51,     0,    53,    54,     0,
      55,     0,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,     0,    68,    69,     0,     0,     0,     0,
      70,    71,     0,    72,    73,    74,    75,    76,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,   174,
      79,    80,    81,    82,     0,    83,    84,     0,    85,    86,
      87,    88,     0,     0,    89,     0,     0,    90,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,    94,    95,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,   110,     0,   111,
     112,  1582,   113,   114,     0,   115,   116,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,     0,     0,     0,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,    39,     0,     0,     0,    40,
      41,    42,    43,     0,    44,     0,    45,     0,    46,     0,
       0,    47,     0,     0,     0,    48,    49,    50,    51,     0,
      53,    54,     0,    55,     0,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,     0,    68,    69,     0,
       0,     0,     0,    70,    71,     0,    72,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,   174,    79,    80,    81,    82,     0,    83,    84,
       0,    85,    86,    87,    88,     0,     0,    89,     0,     0,
      90,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,    94,    95,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
     110,     0,   111,   112,  1635,   113,   114,     0,   115,   116,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,    15,     0,     0,     0,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,    32,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,    39,     0,
       0,     0,    40,    41,    42,    43,     0,    44,     0,    45,
       0,    46,     0,     0,    47,     0,     0,     0,    48,    49,
      50,    51,     0,    53,    54,     0,    55,     0,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,     0,
      68,    69,     0,     0,     0,     0,    70,    71,     0,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,   174,    79,    80,    81,    82,
       0,    83,    84,     0,    85,    86,    87,    88,     0,     0,
      89,     0,     0,    90,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,    94,    95,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,   110,     0,   111,   112,  1641,   113,   114,
       0,   115,   116,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,     0,     0,
       0,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,    39,     0,     0,     0,    40,    41,    42,    43,     0,
      44,     0,    45,     0,    46,     0,     0,    47,     0,     0,
       0,    48,    49,    50,    51,     0,    53,    54,     0,    55,
       0,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,     0,    68,    69,     0,     0,     0,     0,    70,
      71,     0,    72,    73,    74,    75,    76,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,   174,    79,
      80,    81,    82,     0,    83,    84,     0,    85,    86,    87,
      88,     0,     0,    89,     0,     0,    90,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,    94,    95,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,   110,     0,   111,   112,
       0,   113,   114,     0,   115,   116,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,     0,   434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,    32,     0,     0,     0,    33,    34,    35,
      36,    37,    38,     0,    39,     0,     0,     0,    40,    41,
      42,    43,     0,    44,     0,    45,     0,    46,     0,     0,
      47,     0,     0,     0,    48,    49,    50,    51,     0,    53,
      54,     0,    55,     0,    57,    58,    59,    60,   170,   171,
      63,     0,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,   174,    79,    80,    81,    82,     0,    83,    84,     0,
      85,    86,    87,     0,     0,     0,    89,     0,     0,    90,
       0,     0,     0,     0,     0,    91,     0,     0,     0,     0,
      94,    95,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,   110,
       0,   111,   112,     0,   113,   114,     0,   115,   116,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,   675,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,    39,     0,     0,
       0,    40,    41,    42,    43,     0,    44,     0,    45,     0,
      46,     0,     0,    47,     0,     0,     0,    48,    49,    50,
      51,     0,    53,    54,     0,    55,     0,    57,    58,    59,
      60,   170,   171,    63,     0,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,    70,    71,     0,    72,    73,
      74,    75,    76,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,   174,    79,    80,    81,    82,     0,
      83,    84,     0,    85,    86,    87,     0,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,    94,    95,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,   110,     0,   111,   112,     0,   113,   114,     0,
     115,   116,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,   876,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,     0,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
       0,     0,     0,    33,    34,    35,    36,    37,    38,     0,
      39,     0,     0,     0,    40,    41,    42,    43,     0,    44,
       0,    45,     0,    46,     0,     0,    47,     0,     0,     0,
      48,    49,    50,    51,     0,    53,    54,     0,    55,     0,
      57,    58,    59,    60,   170,   171,    63,     0,    64,    65,
      66,     0,     0,     0,     0,     0,     0,     0,    70,    71,
       0,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,   174,    79,    80,
      81,    82,     0,    83,    84,     0,    85,    86,    87,     0,
       0,     0,    89,     0,     0,    90,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,    94,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,   110,     0,   111,   112,     0,
     113,   114,     0,   115,   116,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     0,  1355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,     0,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,    39,     0,     0,     0,    40,    41,    42,
      43,     0,    44,     0,    45,     0,    46,     0,     0,    47,
       0,     0,     0,    48,    49,    50,    51,     0,    53,    54,
       0,    55,     0,    57,    58,    59,    60,   170,   171,    63,
       0,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
     174,    79,    80,    81,    82,     0,    83,    84,     0,    85,
      86,    87,     0,     0,     0,    89,     0,     0,    90,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,    94,
      95,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,     0,
     111,   112,     0,   113,   114,     0,   115,   116,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,     0,  1486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,     0,     0,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,    39,     0,     0,     0,
      40,    41,    42,    43,     0,    44,     0,    45,     0,    46,
       0,     0,    47,     0,     0,     0,    48,    49,    50,    51,
       0,    53,    54,     0,    55,     0,    57,    58,    59,    60,
     170,   171,    63,     0,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,    70,    71,     0,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,   174,    79,    80,    81,    82,     0,    83,
      84,     0,    85,    86,    87,     0,     0,     0,    89,     0,
       0,    90,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,    94,    95,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,   110,     0,   111,   112,     0,   113,   114,     0,   115,
     116,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,     0,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,    32,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,    39,
       0,     0,     0,    40,    41,    42,    43,     0,    44,     0,
      45,     0,    46,     0,     0,    47,     0,     0,     0,    48,
      49,    50,    51,     0,    53,    54,     0,    55,     0,    57,
      58,    59,    60,   170,   171,    63,     0,    64,    65,    66,
       0,     0,     0,     0,     0,     0,     0,    70,    71,     0,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,   174,    79,    80,    81,
      82,     0,    83,    84,     0,    85,    86,    87,     0,     0,
       0,    89,     0,     0,    90,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,    94,    95,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,   110,     0,   111,   112,     0,   113,
     114,     0,   115,   116,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   620,    12,
       0,     0,     0,     0,     0,     0,   621,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,   170,   171,   172,     0,
       0,    65,    66,     0,     0,     0,     0,     0,     0,     0,
     173,    71,     0,    72,    73,    74,    75,    76,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,   174,
      79,    80,    81,    82,     0,    83,    84,     0,    85,    86,
      87,     0,     0,     0,    89,     0,     0,    90,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,    94,    95,
     256,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,   110,     0,     0,
       0,     0,   113,   114,     0,   115,   116,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,   170,
     171,   172,     0,     0,    65,    66,     0,     0,     0,     0,
       0,     0,     0,   173,    71,     0,    72,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,   174,    79,    80,    81,    82,     0,    83,    84,
       0,    85,    86,    87,     0,     0,     0,    89,     0,     0,
      90,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,    94,    95,   256,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
     110,     0,   257,     0,     0,   113,   114,     0,   115,   116,
       5,     6,     7,     8,     9,     0,     0,     0,     0,   912,
      10,   913,   914,   915,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,   933,   567,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,   934,     0,     0,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,   170,   171,   172,     0,     0,    65,    66,     0,
       0,     0,     0,     0,     0,     0,   173,    71,     0,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,   174,    79,    80,    81,    82,
       0,    83,    84,     0,    85,    86,    87,     0,   568,     0,
      89,     0,     0,    90,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,    94,    95,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,   110,   340,   341,     0,     0,   113,   114,
       0,   115,   116,     5,     6,     7,     8,     9,     0,     0,
       0,     0,   342,    10,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   994,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,   365,     0,
       0,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,   170,   171,   172,     0,     0,
      65,    66,     0,     0,     0,     0,     0,     0,     0,   173,
      71,     0,    72,    73,    74,    75,    76,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,   174,    79,
      80,    81,    82,     0,    83,    84,     0,    85,    86,    87,
       0,   995,     0,    89,     0,     0,    90,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,    94,    95,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,   110,     0,     0,     0,
       0,   113,   114,     0,   115,   116,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     620,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,   170,   171,
     172,     0,     0,    65,    66,     0,     0,     0,     0,     0,
       0,     0,   173,    71,     0,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,   174,    79,    80,    81,    82,     0,    83,    84,     0,
      85,    86,    87,     0,     0,     0,    89,     0,     0,    90,
       0,     0,     0,     0,     0,    91,     0,     0,     0,     0,
      94,    95,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,   110,
       0,   339,   340,   341,   113,   114,     0,   115,   116,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
     342,     0,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,     0,   364,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,   365,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,   170,   171,   172,     0,     0,    65,    66,     0,     0,
       0,     0,     0,     0,     0,   173,    71,     0,    72,    73,
      74,    75,    76,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,   174,    79,    80,    81,    82,     0,
      83,    84,     0,    85,    86,    87,     0,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,     0,    91,   939,
     940,     0,     0,    94,    95,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,   110,   910,   911,     0,     0,   113,   114,     0,
     115,   116,     5,     6,     7,     8,     9,     0,     0,     0,
       0,   912,    10,   913,   914,   915,   916,   917,   918,   919,
     920,   921,   922,   923,   924,   925,   926,   927,   928,   929,
     930,   931,   932,   933,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,   934,     0,     0,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    38,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,   170,   171,   172,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,     0,   173,    71,
       0,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,   174,    79,    80,
      81,    82,     0,    83,    84,     0,    85,    86,    87,     0,
       0,     0,    89,     0,     0,    90,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,    94,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,   110,     0,   339,   340,   341,
     113,   114,     0,   115,   116,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,   342,     0,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,     0,
     364,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,   365,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,   170,   171,   172,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
       0,   173,    71,     0,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
     174,    79,    80,    81,    82,     0,    83,    84,     0,    85,
      86,    87,     0,     0,     0,    89,     0,     0,    90,     0,
       0,     0,  1534,     0,    91,     0,     0,     0,     0,    94,
      95,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,     0,
     239,     0,   911,   113,   114,     0,   115,   116,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    10,   912,
       0,   913,   914,   915,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,   933,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,     0,   934,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,     0,     0,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
     170,   171,   172,     0,     0,    65,    66,     0,     0,     0,
       0,     0,     0,     0,   173,    71,     0,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,   174,    79,    80,    81,    82,     0,    83,
      84,     0,    85,    86,    87,     0,     0,     0,    89,     0,
       0,    90,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,    94,    95,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,   110,     0,   242,     0,     0,   113,   114,     0,   115,
     116,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    10,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,     0,   364,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,   365,     0,     0,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,   170,   171,   172,     0,     0,    65,    66,
       0,     0,     0,     0,     0,     0,     0,   173,    71,     0,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,   174,    79,    80,    81,
      82,     0,    83,    84,     0,    85,    86,    87,     0,     0,
       0,    89,     0,     0,    90,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,    94,    95,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,   110,   432,     0,     0,     0,   113,
     114,     0,   115,   116,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    10,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   580,   364,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,    14,    15,     0,
       0,     0,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,   170,   171,   172,     0,
       0,    65,    66,     0,     0,     0,     0,     0,     0,     0,
     173,    71,     0,    72,    73,    74,    75,    76,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,   174,
      79,    80,    81,    82,     0,    83,    84,     0,    85,    86,
      87,     0,     0,     0,    89,     0,     0,    90,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,    94,    95,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,   110,     0,     0,
       0,     0,   113,   114,     0,   115,   116,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    10,   913,   914,
     915,   916,   917,   918,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,   934,     0,     0,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,   170,
     171,   172,     0,     0,    65,    66,     0,     0,     0,     0,
       0,     0,     0,   173,    71,     0,    72,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,   174,    79,    80,    81,    82,     0,    83,    84,
       0,    85,    86,    87,     0,     0,     0,    89,     0,     0,
      90,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,    94,    95,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
     110,     0,     0,     0,     0,   113,   114,     0,   115,   116,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      10,     0,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   657,   364,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,   365,     0,     0,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,   170,   171,   172,     0,     0,    65,    66,     0,
       0,     0,     0,     0,     0,     0,   173,    71,     0,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,   174,    79,    80,    81,    82,
       0,    83,    84,     0,    85,    86,    87,     0,     0,     0,
      89,     0,     0,    90,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,    94,    95,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,   110,     0,     0,     0,     0,   113,   114,
       0,   115,   116,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    10,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,   933,     0,     0,     0,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   934,    14,    15,     0,     0,
       0,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,   170,   171,   172,     0,     0,
      65,    66,     0,     0,     0,     0,     0,     0,     0,   173,
      71,     0,    72,    73,    74,    75,    76,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,   174,    79,
      80,    81,    82,     0,    83,    84,     0,    85,    86,    87,
       0,     0,     0,    89,     0,     0,    90,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,    94,    95,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,   110,     0,   339,   340,
     341,   113,   114,     0,   115,   116,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    10,   342,     0,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
       0,   364,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,   365,     0,    16,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,   170,   171,
     172,     0,     0,    65,    66,     0,     0,     0,     0,     0,
       0,     0,   173,    71,     0,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,   174,    79,    80,    81,    82,     0,    83,    84,     0,
      85,    86,    87,     0,     0,     0,    89,     0,     0,    90,
       0,     0,  1363,     0,     0,    91,     0,     0,     0,     0,
      94,    95,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,   110,
       0,     0,   671,     0,   113,   114,     0,   115,   116,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,     0,   364,     0,
       0,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
     365,     0,    14,    15,     0,     0,     0,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,   170,   171,   172,     0,     0,    65,    66,     0,     0,
       0,     0,     0,     0,     0,   173,    71,     0,    72,    73,
      74,    75,    76,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,   174,    79,    80,    81,    82,     0,
      83,    84,     0,    85,    86,    87,     0,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,    94,    95,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,   110,     0,   339,   340,   341,   113,   114,     0,
     115,   116,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,   342,     0,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,     0,   364,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,   365,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    38,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,   170,   171,   172,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,     0,   173,    71,
       0,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,   174,    79,    80,
      81,    82,     0,    83,    84,     0,    85,    86,    87,     0,
       0,     0,    89,     0,     0,    90,     0,  1219,     0,     0,
       0,    91,     0,     0,     0,     0,    94,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,   110,     0,   339,   340,   341,
     113,   114,     0,   115,   116,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,   342,   812,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,     0,
     364,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,   365,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,     0,     0,     0,    33,    34,    35,    36,
     522,    38,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,   170,   171,   172,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
       0,   173,    71,     0,    72,    73,    74,    75,    76,     0,
       0,     0,    36,     0,     0,    77,     0,     0,     0,     0,
     174,    79,    80,    81,    82,     0,    83,    84,     0,    85,
      86,    87,     0,     0,     0,    89,     0,     0,    90,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,    94,
      95,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,     0,
       0,     0,     0,   113,   114,     0,   115,   116,  1374,  1375,
    1376,  1377,  1378,     0,     0,  1379,  1380,  1381,  1382,    83,
      84,     0,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,  1383,  1384,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,  1385,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1386,  1387,  1388,  1389,  1390,  1391,  1392,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,
    1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,
    1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,
    1432,  1433,     0,     0,  1434,  1435,     0,  1436,  1437,  1438,
    1439,  1440,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1441,  1442,  1443,     0,     0,     0,    83,
      84,     0,    85,    86,    87,  1444,     0,  1445,  1446,     0,
    1447,     0,     0,     0,     0,     0,     0,  1448,  1449,     0,
    1450,     0,  1451,  1452,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   339,   340,
     341,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,   342,     0,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
       0,   364,   339,   340,   341,     0,     0,     0,     0,     0,
       0,     0,     0,   365,     0,     0,     0,     0,   244,     0,
       0,   342,     0,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   245,   364,   295,     0,     0,    83,
      84,     0,    85,    86,    87,     0,     0,   365,     0,     0,
       0,     0,     0,     0,   244,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     245,     0,     0,  -310,   296,     0,     0,     0,     0,     0,
       0,    58,    59,    60,   170,   171,   330,     0,     0,     0,
     244,     0,    36,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   174,     0,     0,
      81,   248,     0,    83,    84,   668,    85,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
       0,   249,     0,     0,     0,   246,   247,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,   174,   943,   250,    81,   248,     0,    83,
      84,     0,    85,    86,    87,     0,  1203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,     0,     0,
       0,   246,   247,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,   174,
       0,   250,    81,   248,     0,    83,    84,     0,    85,    86,
      87,    36,     0,   202,     0,     0,     0,     0,     0,   535,
       0,     0,     0,   249,     0,     0,     0,     0,  1086,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   695,   696,     0,   250,     0,     0,
     697,   203,   698,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   699,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,     0,     0,     0,     0,
       0,     0,   174,   700,     0,    81,    82,     0,    83,    84,
       0,    85,    86,    87,     0,     0,     0,     0,   918,   919,
     920,   921,   922,   923,   924,   925,   926,   927,   928,   929,
     930,   931,   932,   933,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   934,   701,     0,
      72,    73,    74,    75,    76,   536,    36,     0,     0,     0,
       0,   702,     0,     0,     0,     0,   174,    79,    80,    81,
     703,     0,    83,    84,    36,    85,    86,    87,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
     704,     0,     0,     0,     0,    94,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   695,   696,     0,   705,     0,     0,   697,     0,   698,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   699,     0,    83,    84,     0,    85,    86,    87,    33,
      34,    35,    36,     0,     0,     0,     0,     0,     0,  1458,
     700,    83,    84,  1459,    85,    86,    87,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,   809,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,  1315,     0,   701,     0,    72,    73,    74,
      75,    76,     0,     0,     0,   837,   838,     0,   702,     0,
       0,     0,     0,   174,    79,    80,    81,   703,     0,    83,
      84,     0,    85,    86,    87,   839,     0,     0,    89,     0,
       0,     0,     0,   840,   841,   842,    36,   704,     0,     0,
       0,     0,    94,     0,   843,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   705,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,   202,     0,     0,     0,     0,     0,   844,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   845,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,     0,    85,    86,    87,     0,
       0,   203,     0,   826,     0,     0,     0,     0,     0,     0,
       0,   846,    36,     0,   202,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   174,     0,     0,    81,    82,     0,    83,    84,
       0,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      90,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,    36,     0,
     413,     0,     0,   174,     0,   113,    81,    82,     0,    83,
      84,     0,    85,    86,    87,    36,     0,   202,     0,     0,
       0,     0,     0,     0,     0,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   204,     0,     0,     0,   203,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,     0,     0,    83,    84,     0,    85,    86,
      87,     0,     0,    36,     0,     0,   174,     0,     0,    81,
      82,   688,    83,    84,     0,    85,    86,    87,    36,     0,
     202,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   204,     0,     0,   498,   203,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     514,     0,     0,     0,   174,     0,     0,    81,     0,     0,
      83,    84,     0,    85,    86,    87,     0,     0,     0,   174,
       0,     0,    81,    82,     0,    83,    84,     0,    85,    86,
      87,    36,     0,   202,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   204,     0,     0,
       0,   203,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,   968,   202,     0,  -847,  -847,  -847,  -847,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   174,   364,     0,    81,    82,     0,    83,    84,
       0,    85,    86,    87,     0,   365,     0,     0,     0,     0,
       0,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     204,     0,    36,   174,     0,   113,    81,    82,     0,    83,
      84,     0,    85,    86,    87,    36,     0,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   204,     0,     0,     0,   215,   113,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,    81,    82,     0,    83,
      84,     0,    85,    86,    87,     0,   174,     0,     0,    81,
      82,     0,    83,    84,     0,    85,    86,    87,     0,     0,
       0,     0,     0,     0,  1314,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   216,     0,     0,    83,    84,   113,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   339,
     340,   341,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,   342,  1315,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,     0,   364,   339,   340,   341,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,   342,     0,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,   339,
     340,   341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   409,   342,     0,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,     0,   364,   339,   340,   341,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   418,   342,     0,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,   339,
     340,   341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   815,   342,     0,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,     0,   364,   909,   910,   911,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   855,   912,     0,   913,   914,   915,   916,   917,   918,
     919,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   934,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1159,   912,     0,
     913,   914,   915,   916,   917,   918,   919,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,   930,   931,   932,
     933,   909,   910,   911,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   934,     0,     0,     0,     0,     0,
     912,  1068,   913,   914,   915,   916,   917,   918,   919,   920,
     921,   922,   923,   924,   925,   926,   927,   928,   929,   930,
     931,   932,   933,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     0,   934,   909,   910,   911,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     0,   912,  1213,   913,   914,
     915,   916,   917,   918,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   934,    36,  1302,   761,   762,     0,     0,  1287,
       0,     0,     0,     0,     0,     0,  1303,  1304,   327,    36,
      83,    84,     0,    85,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,   174,     0,     0,    81,  1305,     0,
      83,    84,     0,    85,  1306,    87,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,    36,     0,     0,     0,  1362,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    36,
      83,    84,     0,    85,    86,    87,     0,     0,     0,     0,
       0,     0,     0,   486,     0,     0,    83,    84,     0,    85,
      86,    87,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   490,     0,     0,    83,    84,
       0,    85,    86,    87,     0,     0,     0,     0,     0,    36,
       0,     0,     0,   267,     0,     0,    83,    84,     0,    85,
      86,    87,    36,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   611,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,  1078,  -847,
    -847,  -847,  -847,   922,   923,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,     0,    83,    84,     0,    85,
      86,    87,     0,     0,     0,     0,     0,     0,   934,    83,
      84,     0,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    83,    84,
       0,    85,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   339,
     340,   341,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   679,   342,     0,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,     0,   364,   339,   340,   341,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,   342,     0,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   680,   364,   909,   910,   911,
       0,     0,     0,     0,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,   912,  1218,   913,   914,
     915,   916,   917,   918,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   934,     0,     0,     0,     0,     0,   912,     0,
     913,   914,   915,   916,   917,   918,   919,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,   930,   931,   932,
     933,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   934
};

static const yytype_int16 yycheck[] =
{
       4,   131,   156,   302,   570,   305,   323,     4,   166,    88,
       4,    32,   176,    92,    93,     4,    53,     4,    30,   650,
     986,   787,    43,   377,     4,     4,    47,   217,   244,   245,
     403,   159,     4,   364,   250,   529,   779,   678,   223,   110,
       9,   808,     9,   110,   869,    49,   685,   177,    52,    30,
     434,   130,   223,    30,    26,    27,   823,     9,   805,     9,
      45,   213,    45,     9,     9,    69,    33,    66,    66,     4,
       9,    66,    45,    66,  1154,    45,   976,     9,   398,     9,
       9,    35,     9,     9,    88,     9,     9,    45,    92,    93,
       9,     9,    56,     9,    84,     9,   224,     9,   482,   108,
     127,     9,     9,    66,   320,     9,   426,    66,     9,     9,
      45,     9,  1481,    79,    78,   168,   127,    81,   151,    79,
     127,    49,    50,    51,     0,    79,   130,   196,    79,     8,
      14,   196,   127,   204,   112,   113,   114,    65,   110,   114,
     115,   116,   196,   196,   302,   216,    30,   196,   147,    71,
      72,   131,   196,    66,   144,    66,   165,   125,   126,    79,
      96,  1530,   905,    47,   127,   198,   199,   331,   127,   156,
     105,    66,    66,   200,  1254,   110,  1256,   112,   113,   114,
     115,   116,   117,   118,    66,   189,   197,   147,    66,    79,
     197,    66,    66,    66,   145,   146,    66,   177,   196,    66,
     199,   199,    66,   196,   199,   196,   199,   161,    66,   194,
     281,   194,   197,   371,   281,   151,    50,   169,   199,   154,
     155,   198,   157,   169,   197,   229,  1051,   197,   199,   233,
     197,   200,   204,   237,   392,   201,   199,   453,   210,   197,
     879,   405,   881,   178,   216,  1012,   376,   326,   198,   199,
     229,   255,   999,   198,   233,  1002,  1156,   229,   416,   198,
     412,   233,  1342,  1163,  1164,   200,   198,   425,   198,   198,
     428,   198,   198,    50,   198,   198,   770,    99,   100,   198,
     198,   201,   198,   197,    79,   197,   199,   671,  1031,   197,
     197,   675,    35,   197,   373,   374,   197,   197,    84,   197,
     272,   265,   266,   267,   199,   199,   310,   279,   280,   281,
      35,   201,    35,    35,   286,   319,    96,   199,   152,   323,
     292,   199,   326,   310,   199,   199,   199,   543,   544,   199,
     310,   295,   199,   549,    96,   199,    79,   153,   310,    96,
     377,   199,   413,    99,   100,    96,   196,    35,    79,   144,
     145,   146,   364,    84,    79,    79,    79,    79,   144,   371,
      84,    79,    96,  1263,   153,   550,    84,   371,   372,   373,
     374,   151,   196,    53,   123,   152,    79,   166,   200,   550,
     392,    84,   123,   199,   757,    65,   538,    79,   392,   151,
     167,    79,    84,    79,   151,   375,   196,    79,    84,   196,
     151,  1032,    84,  1483,   416,   147,  1047,    98,    99,   100,
     199,  1158,   416,   425,   145,   146,   428,   151,   161,   368,
     144,   145,   146,   613,   428,   196,   168,   145,   146,   196,
     147,   403,    98,    99,   100,   196,   161,   441,   161,   152,
       4,   413,   145,   146,   200,   199,   395,    30,    29,   639,
     399,   168,   144,   145,   146,   619,   151,   199,   610,   145,
     146,   196,   441,   145,   146,    46,   656,  1210,    49,   441,
     655,    29,    71,    72,   205,    35,   661,   693,   694,   196,
     779,    45,   199,   198,   655,   199,   204,   787,    46,   198,
     661,    49,   876,   497,   198,   826,   198,   576,    74,    75,
      76,   821,    49,    50,    51,   805,    53,    66,   512,    85,
     830,   198,   199,   198,   518,   519,   706,  1264,    65,   198,
     199,  1601,   486,  1508,  1509,   198,   490,  1504,  1505,  1272,
      66,   495,    66,   661,   693,   694,  1616,   198,   147,   691,
    1171,   105,  1173,   196,   196,    66,   110,   147,   112,   113,
     114,   115,   116,   117,   118,   196,   132,   133,   134,   135,
     136,   151,     4,   198,    44,    65,   168,   143,   147,   785,
     127,   203,   576,   149,   150,     9,   147,   147,   196,   127,
     796,   112,   113,   114,   115,   116,   117,   163,     8,   196,
     154,   155,   289,   157,   198,   567,   293,   179,   180,   181,
     168,   177,    14,    45,   186,   187,   905,    14,   190,   191,
      79,   198,   198,    14,   178,   312,   970,   314,   315,   316,
     317,   779,   197,   168,   112,   113,   114,   115,   116,   117,
      14,    96,   197,   791,   197,   202,   200,   104,     9,  1270,
     196,  1607,   196,   196,    88,   197,   650,   178,   652,   621,
       9,   197,    14,   674,   198,   196,  1622,     9,   182,   185,
      79,    79,    79,   105,   196,   669,     9,   883,   110,   885,
     112,   113,   114,   115,   116,   117,   118,  1050,   682,   683,
     198,   198,   669,     9,    79,   657,   197,   659,  1008,   669,
     178,   197,   125,   198,   196,   126,  1016,   669,   850,   999,
     197,    66,  1002,   167,   683,   128,     9,   197,   680,   147,
     198,   683,   154,   155,    14,   157,   194,     9,  1349,    66,
       9,   169,   197,     9,   728,   125,    14,   203,   200,   203,
     734,     9,  1031,  1117,   738,   739,   178,   196,   196,   196,
     203,   728,   894,   197,   147,   961,   825,   905,   728,   901,
     203,   104,   197,  1126,    96,   198,   728,   198,   200,   112,
     113,   114,   115,   116,   117,   769,     9,   128,   984,   733,
     986,   197,   769,   737,   746,   769,   182,   147,   782,   791,
     769,   196,   769,   196,   147,   757,   758,   791,   199,   769,
     769,   112,   113,   114,   115,   116,   117,   769,    14,  1183,
     182,   991,   123,   124,    46,    47,    48,    49,    50,    51,
       9,  1577,    79,   199,   826,  1199,    14,   198,    14,    96,
     199,   825,    14,    65,  1124,   178,   203,   199,  1594,   198,
      30,  1151,  1132,   837,   838,   839,  1602,    14,   196,   160,
    1160,   862,   196,     9,   128,   196,   196,   196,  1168,  1065,
     198,   197,   196,   198,  1485,    14,     9,   178,  1158,   863,
     197,   865,    65,   867,    46,    47,    48,    49,    50,    51,
     203,    53,     9,  1031,   144,  1027,     9,    79,   865,   196,
     867,   128,   886,    65,   863,   865,   198,   867,    79,    14,
    1274,   863,    79,   865,   196,   867,   197,   869,   870,  1283,
     904,   199,   196,   907,   197,   196,   128,   203,  1225,   199,
    1294,  1210,   199,   196,     9,   197,   144,    30,    73,   198,
     169,   197,   128,  1075,   198,    30,   197,   128,   197,     9,
    1082,  1251,   197,   970,   200,     9,   197,   200,    96,    14,
     196,   199,   197,   197,   197,   196,   950,   197,   128,   953,
       9,   197,   197,    30,   198,  1255,   197,   197,   962,  1525,
     198,  1261,  1262,   198,  1264,   199,   156,   152,    79,    14,
     974,  1355,    79,  1272,   197,   196,   110,   974,   197,   197,
     974,   128,   197,   197,   128,   974,  1202,   974,  1204,    14,
     199,   198,    79,    14,   974,   974,   128,    14,    14,    55,
     197,   196,   974,   197,   197,  1322,  1222,     4,    79,    79,
     199,   199,   198,     9,  1334,   198,    79,   196,  1039,  1235,
     198,   147,   994,   108,  1028,    33,  1592,  1179,  1032,    96,
      96,   159,    14,   196,   198,   197,   196,    79,  1042,   162,
     197,   165,     9,    79,   198,   197,  1346,   197,    45,    79,
    1054,   199,  1210,    14,    14,    79,    79,    14,    14,    79,
     495,   733,   737,  1042,  1036,  1585,   374,  1054,   372,   824,
    1042,   771,   156,  1598,  1054,   822,   373,  1354,  1050,  1051,
    1196,  1594,  1054,  1237,   500,  1372,  1048,     4,  1456,  1230,
    1626,  1614,  1476,  1468,  1478,    41,  1341,   985,   945,   942,
     725,   902,  1486,   471,   377,  1235,   977,   471,   105,  1014,
     838,  1028,   852,   110,  1272,   112,   113,   114,   115,   116,
     117,   118,   287,   887,   280,    -1,    -1,   693,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1124,    -1,    -1,
      -1,    -1,    -1,    -1,  1528,  1132,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,  1126,    -1,  1320,   154,   155,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,  1171,    -1,  1173,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,   110,    -1,   112,   113,   114,   115,   116,
     117,   118,    -1,   200,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,  1221,    53,    -1,
      -1,  1225,    -1,    -1,    -1,    -1,  1230,    -1,    -1,    -1,
      65,    -1,    -1,    -1,  1221,    -1,  1620,   154,   155,    -1,
     157,  1221,    -1,  1627,    -1,    -1,    -1,    -1,    -1,  1221,
    1237,    -1,    -1,    -1,  1234,    -1,    -1,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,  1270,    -1,  1255,    -1,
      -1,  1275,    -1,    -1,  1261,  1262,  1280,  1577,    -1,    -1,
    1284,    -1,    -1,   200,    -1,    -1,    -1,    -1,  1275,    -1,
      -1,    -1,    -1,    -1,  1594,  1275,    -1,  1284,    -1,    -1,
      -1,  1280,  1602,  1275,  1284,  1309,  1470,    -1,  1280,    -1,
      -1,  1315,  1284,    -1,    -1,    -1,    -1,    -1,  1322,    -1,
      -1,    -1,    -1,     4,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,  1324,  1349,    -1,    -1,  1352,  1353,
    1354,    26,    27,    -1,  1358,    30,    -1,    -1,    -1,  1346,
    1364,    -1,    -1,    -1,    45,  1352,    -1,   244,   245,    -1,
      -1,  1358,  1352,   250,  1353,  1354,    -1,  1364,  1358,    -1,
    1352,  1353,  1354,    -1,  1364,    -1,  1358,    -1,  1467,    -1,
      -1,  1607,  1364,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,   279,   280,    -1,    -1,  1622,    -1,    -1,   286,
      -1,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,  1573,
      -1,    -1,    -1,    -1,   105,   302,    -1,    -1,    -1,   110,
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,  1520,    -1,   320,    -1,    -1,   323,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,  1589,
      -1,    -1,    -1,  1467,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,   154,   155,    -1,   157,    -1,    -1,    -1,
      -1,  1485,    -1,    -1,    -1,    -1,  1490,   364,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1499,    -1,   178,    -1,    -1,
    1504,  1505,    -1,  1490,  1508,  1509,    -1,    -1,    -1,    -1,
    1490,    -1,    -1,    -1,    -1,    -1,  1520,    -1,  1490,   200,
      -1,    -1,  1526,  1527,    -1,    -1,   403,    -1,  1532,   204,
      -1,    -1,    -1,    -1,    -1,   210,   413,    -1,    -1,  1526,
    1527,   216,    -1,    -1,    -1,  1532,  1526,  1527,    -1,    -1,
      -1,    -1,  1532,    -1,  1526,  1527,    -1,    -1,    -1,    -1,
    1532,  1565,    -1,    -1,    -1,    -1,    -1,    -1,  1572,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   453,   454,  1565,    -1,
     457,    -1,    -1,    -1,  1588,  1565,  1573,    -1,    -1,    -1,
      -1,    -1,    -1,  1565,    -1,    -1,    -1,   272,    -1,    -1,
      -1,    -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,
      -1,   286,    -1,    -1,    -1,    -1,    -1,   292,    -1,    -1,
      -1,    -1,    -1,    -1,  1628,   502,    -1,   302,    -1,    -1,
    1634,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1628,    -1,    -1,    -1,    -1,    -1,  1634,  1628,    -1,
      -1,    -1,    -1,    -1,  1634,    -1,  1628,    -1,    -1,    -1,
      -1,    -1,  1634,    -1,    -1,    -1,   543,   544,    -1,    -1,
      -1,    -1,   549,    -1,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,
     567,    -1,    -1,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,   403,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,
      -1,    -1,    -1,    29,   621,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
     657,    -1,   659,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,   680,   681,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    -1,    -1,    65,   693,   694,   695,   696,
     697,   698,   699,    -1,    -1,    -1,    -1,    29,   705,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,   729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,   203,    -1,   746,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   755,    -1,
     757,   758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   567,    -1,   771,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   779,    26,    27,    -1,    -1,    30,   785,    -1,
      -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,   796,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   804,    -1,    -1,
     807,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,   826,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   657,    -1,   659,    -1,    65,    -1,    -1,    -1,
      -1,    -1,   869,   870,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,   680,   883,    -1,   885,    -1,
     887,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   902,    -1,    -1,   905,    -1,
      -1,   908,   909,   910,   911,   912,   913,   914,   915,   916,
     917,   918,   919,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   934,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   958,   757,   758,   961,    -1,    -1,   210,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,   779,    -1,    -1,   984,    -1,   986,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   994,    -1,    -1,
      -1,   200,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
      -1,   826,    -1,    -1,  1031,    -1,   279,   280,    -1,  1036,
      -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,    -1,   292,
      -1,    63,    64,  1050,  1051,    -1,  1053,    -1,    -1,   302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1065,    -1,
      -1,  1068,    -1,  1070,   869,   870,    -1,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1086,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
     905,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,   364,    -1,    -1,    -1,    -1,  1123,    -1,    -1,  1126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    63,    64,    -1,    -1,    -1,    -1,
    1147,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
     403,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    -1,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,   994,
      -1,    -1,    -1,    -1,    -1,  1202,    -1,  1204,   127,    -1,
      -1,    -1,  1209,  1210,   457,    -1,  1213,    -1,  1215,    -1,
      -1,  1218,    -1,    -1,    -1,  1222,    -1,    -1,  1225,  1226,
      -1,  1228,    -1,    -1,    -1,    -1,  1031,    -1,  1235,    -1,
      -1,  1036,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1248,    -1,    -1,    -1,  1050,  1051,    -1,    -1,   502,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,  1272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1287,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
    1297,  1298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   567,  1322,    -1,    -1,    -1,    -1,
     200,  1126,    -1,    29,  1331,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    10,    11,
      12,    -1,    -1,    -1,  1361,  1362,    -1,    -1,    -1,    65,
    1367,  1368,    -1,   127,    -1,  1372,    -1,    29,   621,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,   657,  1210,   659,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,   680,   681,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,   695,   696,   697,   698,   699,    -1,    -1,    -1,
      -1,    -1,   705,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1471,    -1,    -1,  1272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   729,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1499,   746,   200,    -1,  1503,    -1,    77,    -1,
      79,    -1,   755,    -1,   757,   758,    -1,  1514,    -1,    -1,
      -1,    -1,  1519,    -1,    -1,    -1,    -1,    -1,   771,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   804,    -1,   320,   807,    -1,   323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1576,
      -1,    -1,    -1,   826,    -1,   154,   155,  1584,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1598,    -1,    -1,    -1,    -1,    -1,   457,    -1,    -1,
    1607,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,  1622,   869,   870,    -1,    -1,
     199,    -1,   201,    -1,  1631,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1639,    -1,    -1,    -1,  1643,    -1,    -1,  1646,
      -1,    -1,   502,    -1,    -1,    -1,    -1,    -1,    -1,   902,
      -1,    -1,   905,    -1,    -1,   908,   909,   910,   911,   912,
     913,   914,   915,   916,   917,   918,   919,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,   930,   931,   932,
     933,   934,    -1,    -1,    -1,    -1,   453,   454,    -1,    -1,
     457,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   958,    -1,    -1,    -1,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    12,    53,   502,    -1,    -1,    -1,    -1,
      -1,   994,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    -1,   543,   544,  1031,    -1,
      -1,    -1,   549,  1036,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    79,  1050,  1051,    -1,
    1053,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1068,    -1,  1070,    -1,    -1,
      -1,   681,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,  1086,    -1,   695,   696,   697,   698,   699,
      -1,    -1,    -1,    -1,    29,   705,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    -1,
    1123,   154,   155,  1126,   157,   158,   159,    -1,    -1,    -1,
      65,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1147,    -1,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,   681,    -1,   199,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   693,   694,   695,   696,
     697,   698,   699,    -1,    -1,    -1,    -1,    -1,   705,    -1,
      -1,    -1,    -1,    -1,   804,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1209,  1210,    -1,    -1,
    1213,    -1,  1215,    -1,    -1,  1218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1226,    -1,  1228,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,  1248,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,   785,  1272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   796,
      -1,    -1,    -1,    -1,  1287,    -1,    -1,   804,    -1,    -1,
      -1,    -1,   902,    -1,  1297,  1298,    -1,    -1,   908,   909,
     910,   911,   912,   913,   914,   915,   916,   917,   918,   919,
     920,   921,   922,   923,   924,   925,   926,   927,   928,   929,
     930,   931,   932,   933,   934,    -1,    -1,    29,  1331,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,   958,    53,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,  1361,  1362,
      -1,    65,    -1,    -1,  1367,  1368,   883,    -1,   885,  1372,
     887,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   902,    -1,    -1,    -1,    -1,
      -1,   908,   909,   910,   911,   912,   913,   914,   915,   916,
     917,   918,   919,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   934,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   958,    -1,  1053,   961,    -1,   148,    -1,    -1,   151,
     152,    77,   154,   155,    -1,   157,   158,   159,  1068,   161,
    1070,    -1,    -1,    -1,    -1,    -1,    -1,   984,  1471,   986,
     172,    -1,    -1,    -1,    -1,    -1,  1086,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
    1503,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,  1514,    -1,    -1,    -1,    -1,  1519,    -1,    -1,    -1,
      -1,    -1,   148,    -1,    -1,   151,    -1,    -1,   154,   155,
      -1,   157,   158,   159,    -1,    -1,  1053,  1147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1065,    -1,
      -1,  1068,    -1,  1070,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,  1086,
      -1,    -1,    -1,  1576,   200,    -1,    -1,    -1,    -1,    -1,
      -1,  1584,    -1,    -1,   154,   155,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,  1598,    -1,    -1,    -1,  1209,
      -1,    -1,    -1,  1213,    -1,  1215,    -1,    -1,  1218,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    10,    11,    12,    -1,    -1,  1631,   199,
    1147,   201,    74,    75,    76,    77,  1639,    -1,  1248,    -1,
    1643,    -1,    29,  1646,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1287,    65,    -1,
      -1,    -1,    -1,    -1,    -1,  1202,    -1,  1204,    -1,    -1,
      -1,    -1,  1209,    -1,    -1,    -1,  1213,    -1,  1215,    -1,
      -1,  1218,    -1,    -1,    -1,  1222,    -1,    -1,  1225,    -1,
      -1,    -1,   154,   155,    -1,   157,   158,   159,  1235,    -1,
      -1,  1331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1248,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,  1361,  1362,    10,    11,    12,    -1,  1367,    -1,    -1,
      -1,  1371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1287,    -1,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1322,    -1,    -1,    65,    -1,
      -1,    -1,    -1,   200,  1331,     5,     6,    -1,     8,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,  1361,  1362,    -1,    -1,    -1,    -1,
    1367,    41,    -1,    -1,    -1,    29,    -1,    -1,    48,    -1,
      50,  1471,    -1,    53,    -1,    55,    -1,    -1,   457,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1503,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,  1514,    -1,    -1,    -1,    -1,  1519,
      -1,    -1,    -1,   502,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,  1542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1471,    -1,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1576,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,
     154,   155,  1499,   157,   158,   159,  1503,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,  1514,   172,    -1,
      -1,    -1,  1519,    -1,    -1,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,  1631,   196,    -1,    -1,    -1,    -1,    -1,    -1,  1639,
      -1,    -1,    -1,  1643,    -1,   225,  1646,    -1,   228,    10,
      11,    12,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,  1576,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1607,   281,   681,    -1,    65,    -1,    -1,   287,    -1,    -1,
      -1,   291,    -1,    -1,    -1,  1622,   695,   696,   697,   698,
     699,    -1,    -1,    -1,  1631,    -1,   705,    -1,    -1,    -1,
      -1,   311,  1639,    -1,    -1,    -1,  1643,    -1,    -1,  1646,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,   365,    -1,   367,   368,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
      -1,    -1,    -1,    -1,    -1,   395,   396,    -1,   398,   399,
     400,    -1,    -1,    -1,    -1,   804,   406,    -1,    -1,   409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   200,
     420,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,   438,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     457,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   464,    -1,    -1,   467,   468,   469,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,   502,    -1,    -1,   498,    -1,
      -1,    -1,    -1,   902,    -1,    -1,    65,    -1,    -1,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   917,   918,
     919,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   934,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   958,
      53,    -1,    10,    11,    12,    -1,    -1,    -1,   568,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,   612,    -1,    -1,    -1,    -1,    65,    -1,    -1,
     620,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,   638,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,  1053,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,    -1,  1068,
      -1,  1070,    -1,    -1,   681,    -1,    -1,    77,   678,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1086,   695,   696,
     697,   698,    -1,    -1,    10,    11,    12,    -1,   705,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,   714,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1147,    65,
     198,    -1,    -1,    -1,   154,   155,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,   766,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   778,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,   804,    -1,   199,
      -1,   201,   802,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1209,    -1,   812,    -1,  1213,   815,  1215,   817,    -1,  1218,
      -1,   821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     830,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1248,
      -1,    -1,    -1,    -1,    29,   855,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,  1287,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   908,   909,   910,   911,   912,   913,   914,   915,   916,
     917,   918,   919,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   934,    -1,    -1,
      -1,    -1,  1331,    -1,    -1,    -1,   936,   937,   938,    -1,
      -1,    -1,   942,   943,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   958,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1361,  1362,    -1,    -1,    -1,    -1,  1367,    -1,
     970,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     990,    -1,    -1,    -1,    -1,   995,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,  1008,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1016,    -1,  1018,    77,
      -1,    79,    29,   198,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,  1053,  1047,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1057,    65,   117,
      -1,  1068,    -1,  1070,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,  1471,    -1,    -1,    -1,    -1,    -1,    -1,  1086,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,    -1,   151,   152,    -1,   154,   155,    -1,   157,
     158,   159,    -1,    -1,  1503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1514,    -1,    -1,    -1,    -1,
    1519,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,  1135,    -1,    -1,   196,  1139,
    1147,  1141,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1159,
    1160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1576,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1209,    -1,    -1,    -1,  1213,    -1,  1215,    -1,
      -1,  1218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1631,    -1,    -1,    -1,    10,    11,    12,    -1,
    1639,  1248,    -1,    -1,  1643,    -1,    -1,  1646,    -1,    -1,
      -1,  1251,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
    1287,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,  1331,    53,    -1,    77,    -1,    79,
      -1,    -1,    -1,    -1,  1334,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,  1361,  1362,    -1,    -1,    -1,    -1,
    1367,    -1,    -1,  1363,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,   154,   155,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,   198,    -1,    -1,    -1,    -1,    13,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    27,    28,    -1,    -1,    -1,    -1,   199,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,  1471,    -1,    -1,    -1,    52,   197,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,  1503,    81,    -1,    -1,
      -1,    85,    86,    87,    88,    -1,    90,  1514,    92,    -1,
      94,    -1,  1519,    97,    -1,    -1,    -1,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   198,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,  1576,
     154,   155,    -1,   157,   158,   159,   160,    -1,    -1,   163,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,   173,
      -1,   175,    -1,   177,   178,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,    -1,
     204,   205,    -1,    -1,  1631,     3,     4,     5,     6,     7,
      -1,    -1,  1639,    -1,    -1,    13,  1643,    -1,    -1,  1646,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    -1,    85,    86,    87,
      88,    -1,    90,    -1,    92,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,   130,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,    -1,   157,
     158,   159,   160,    -1,    -1,   163,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,   172,   173,    -1,   175,    -1,   177,
     178,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,    -1,   204,   205,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    -1,    90,    -1,    92,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,   160,    -1,    -1,   163,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,   172,   173,    -1,
     175,    -1,   177,   178,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,   196,    -1,   198,   199,    -1,   201,   202,    -1,   204,
     205,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,    -1,
      92,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,
     102,   103,   104,    -1,   106,   107,    -1,   109,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,   120,   121,
      -1,   123,   124,    -1,    -1,    -1,    -1,   129,   130,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,   154,   155,    -1,   157,   158,   159,   160,    -1,
      -1,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,    -1,   204,   205,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      -1,    90,    -1,    92,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,   101,   102,   103,   104,    -1,   106,   107,    -1,
     109,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,    -1,   123,   124,    -1,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,   154,   155,    -1,   157,   158,
     159,   160,    -1,    -1,   163,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,   178,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,    -1,   204,   205,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    -1,    90,    -1,    92,    -1,    94,    -1,
      -1,    97,    -1,    -1,    -1,   101,   102,   103,   104,    -1,
     106,   107,    -1,   109,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,   119,   120,   121,    -1,   123,   124,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,   154,   155,
      -1,   157,   158,   159,   160,    -1,    -1,   163,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,   178,    -1,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
     196,    -1,   198,   199,   200,   201,   202,    -1,   204,   205,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
     103,   104,    -1,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,    -1,
     123,   124,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,    -1,   157,   158,   159,   160,    -1,    -1,
     163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   177,   178,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,   196,    -1,   198,   199,    -1,   201,   202,
      -1,   204,   205,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,    -1,
      90,    -1,    92,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,   101,   102,   103,   104,    -1,   106,   107,    -1,   109,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,   121,    -1,   123,   124,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,    -1,   154,   155,    -1,   157,   158,   159,
     160,    -1,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,    -1,   177,   178,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,   196,    -1,   198,   199,
      -1,   201,   202,    -1,   204,   205,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    -1,    90,    -1,    92,    -1,    94,    -1,    -1,
      97,    -1,    -1,    -1,   101,   102,   103,   104,    -1,   106,
     107,    -1,   109,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,   120,   121,    -1,   123,   124,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,   154,   155,    -1,
     157,   158,   159,   160,    -1,    -1,   163,    -1,    -1,   166,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,
     177,   178,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,    -1,   204,   205,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    -1,    81,    -1,    -1,
      -1,    85,    86,    87,    88,    -1,    90,    -1,    92,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,   103,
     104,    -1,   106,   107,    -1,   109,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,   121,    -1,   123,
     124,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,
     154,   155,    -1,   157,   158,   159,   160,    -1,    -1,   163,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    -1,   177,   178,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,    -1,
     204,   205,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,
      -1,    92,    93,    94,    -1,    -1,    97,    -1,    -1,    -1,
     101,   102,   103,   104,    -1,   106,   107,    -1,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    -1,   123,   124,    -1,    -1,    -1,    -1,   129,   130,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,   154,   155,    -1,   157,   158,   159,   160,
      -1,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,   196,    -1,   198,   199,    -1,
     201,   202,    -1,   204,   205,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    -1,    85,    86,    87,
      88,    -1,    90,    -1,    92,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,   101,   102,   103,   104,    -1,   106,   107,
      -1,   109,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,   119,   120,   121,    -1,   123,   124,    -1,    -1,    -1,
      -1,   129,   130,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,    -1,   157,
     158,   159,   160,    -1,    -1,   163,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,
     178,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,    -1,   204,   205,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    -1,    90,    -1,    92,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,   101,   102,   103,   104,
      -1,   106,   107,    -1,   109,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    -1,   123,   124,
      -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,   160,    -1,    -1,   163,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    -1,   177,   178,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,   196,    -1,   198,   199,   200,   201,   202,    -1,   204,
     205,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,    91,
      92,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,
     102,   103,   104,    -1,   106,   107,    -1,   109,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,   120,   121,
      -1,   123,   124,    -1,    -1,    -1,    -1,   129,   130,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,   154,   155,    -1,   157,   158,   159,   160,    -1,
      -1,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,   196,    -1,   198,   199,    -1,   201,
     202,    -1,   204,   205,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      -1,    90,    -1,    92,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,   101,   102,   103,   104,    -1,   106,   107,    -1,
     109,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,    -1,   123,   124,    -1,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,   154,   155,    -1,   157,   158,
     159,   160,    -1,    -1,   163,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,   178,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,    -1,   204,   205,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    -1,    90,    -1,    92,    -1,    94,    -1,
      -1,    97,    -1,    -1,    -1,   101,   102,   103,   104,    -1,
     106,   107,    -1,   109,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,   119,   120,   121,    -1,   123,   124,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,   154,   155,
      -1,   157,   158,   159,   160,    -1,    -1,   163,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,   178,    -1,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
     196,    -1,   198,   199,   200,   201,   202,    -1,   204,   205,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    -1,    85,    86,    87,    88,    -1,    90,    -1,    92,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
     103,   104,    -1,   106,   107,    -1,   109,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,   119,   120,   121,    -1,
     123,   124,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,    -1,   157,   158,   159,   160,    -1,    -1,
     163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   177,   178,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
      -1,   204,   205,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,    -1,
      90,    -1,    92,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,   101,   102,   103,   104,    -1,   106,   107,    -1,   109,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,   121,    -1,   123,   124,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,    -1,   154,   155,    -1,   157,   158,   159,
     160,    -1,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,    -1,   177,   178,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,   196,    -1,   198,   199,
      -1,   201,   202,    -1,   204,   205,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    -1,    90,    -1,    92,    -1,    94,    -1,    -1,
      97,    -1,    -1,    -1,   101,   102,   103,   104,    -1,   106,
     107,    -1,   109,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,   119,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,   154,   155,    -1,
     157,   158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,
     177,   178,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,   196,
      -1,   198,   199,    -1,   201,   202,    -1,   204,   205,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    -1,    81,    -1,    -1,
      -1,    85,    86,    87,    88,    -1,    90,    -1,    92,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,   103,
     104,    -1,   106,   107,    -1,   109,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,   119,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,
     154,   155,    -1,   157,   158,   159,    -1,    -1,    -1,   163,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    -1,   177,   178,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,   196,    -1,   198,   199,    -1,   201,   202,    -1,
     204,   205,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,
      -1,    92,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,
     101,   102,   103,   104,    -1,   106,   107,    -1,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,   154,   155,    -1,   157,   158,   159,    -1,
      -1,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,   196,    -1,   198,   199,    -1,
     201,   202,    -1,   204,   205,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    -1,    85,    86,    87,
      88,    -1,    90,    -1,    92,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,   101,   102,   103,   104,    -1,   106,   107,
      -1,   109,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,   119,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,    -1,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,
     178,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,   196,    -1,
     198,   199,    -1,   201,   202,    -1,   204,   205,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    -1,    90,    -1,    92,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,   101,   102,   103,   104,
      -1,   106,   107,    -1,   109,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,   120,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    -1,   177,   178,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,   196,    -1,   198,   199,    -1,   201,   202,    -1,   204,
     205,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,    -1,
      92,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,
     102,   103,   104,    -1,   106,   107,    -1,   109,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,   119,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,   154,   155,    -1,   157,   158,   159,    -1,    -1,
      -1,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,   196,    -1,   198,   199,    -1,   201,
     202,    -1,   204,   205,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,    -1,
      -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,   154,   155,    -1,   157,   158,
     159,    -1,    -1,    -1,   163,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,    -1,   204,   205,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,   154,   155,
      -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
     196,    -1,   198,    -1,    -1,   201,   202,    -1,   204,   205,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    29,
      13,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    65,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,    -1,   157,   158,   159,    -1,   161,    -1,
     163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   177,   178,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,   196,    11,    12,    -1,    -1,   201,   202,
      -1,   204,   205,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    29,    13,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    35,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    65,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,    -1,   154,   155,    -1,   157,   158,   159,
      -1,   161,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,    -1,   177,   178,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,   202,    -1,   204,   205,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,   154,   155,    -1,
     157,   158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,
     177,   178,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,   196,
      -1,    10,    11,    12,   201,   202,    -1,   204,   205,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    -1,    -1,    65,    -1,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,    -1,    -1,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,
     154,   155,    -1,   157,   158,   159,    -1,    -1,    -1,   163,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,   188,
     189,    -1,    -1,   177,   178,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,   196,    11,    12,    -1,    -1,   201,   202,    -1,
     204,   205,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    29,    13,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    65,    -1,    -1,
      -1,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,    -1,    -1,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,   154,   155,    -1,   157,   158,   159,    -1,
      -1,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,   196,    -1,    10,    11,    12,
     201,   202,    -1,   204,   205,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    65,    -1,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,    -1,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,    -1,
      -1,    -1,   185,    -1,   172,    -1,    -1,    -1,    -1,   177,
     178,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,   196,    -1,
     198,    -1,    12,   201,   202,    -1,   204,   205,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    65,    -1,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,    -1,    -1,   120,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    -1,   177,   178,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,   196,    -1,   198,    -1,    -1,   201,   202,    -1,   204,
     205,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    65,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,    -1,    -1,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,   154,   155,    -1,   157,   158,   159,    -1,    -1,
      -1,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,
     202,    -1,   204,   205,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    30,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,    -1,
      -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,   154,   155,    -1,   157,   158,
     159,    -1,    -1,    -1,   163,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,   178,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,    -1,   204,   205,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    65,    -1,    -1,    -1,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,   154,   155,
      -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,   178,    -1,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
     196,    -1,    -1,    -1,    -1,   201,   202,    -1,   204,   205,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    35,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    65,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,    -1,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   177,   178,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,
      -1,   204,   205,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    46,    47,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,    -1,   154,   155,    -1,   157,   158,   159,
      -1,    -1,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,    -1,   177,   178,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,   196,    -1,    10,    11,
      12,   201,   202,    -1,   204,   205,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    65,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,   154,   155,    -1,
     157,   158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,
      -1,    -1,   184,    -1,    -1,   172,    -1,    -1,    -1,    -1,
     177,   178,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,   196,
      -1,    -1,   199,    -1,   201,   202,    -1,   204,   205,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,    -1,    -1,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,
     154,   155,    -1,   157,   158,   159,    -1,    -1,    -1,   163,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    -1,   177,   178,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,   196,    -1,    10,    11,    12,   201,   202,    -1,
     204,   205,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    65,
      -1,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,    -1,    -1,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,   154,   155,    -1,   157,   158,   159,    -1,
      -1,    -1,   163,    -1,    -1,   166,    -1,   183,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,   196,    -1,    10,    11,    12,
     201,   202,    -1,   204,   205,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    65,    -1,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    77,    -1,    -1,   143,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,    -1,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,
     178,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,   196,    -1,
      -1,    -1,    -1,   201,   202,    -1,   204,   205,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,   154,
     155,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    53,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,   129,   130,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,    -1,    -1,   154,
     155,    -1,   157,   158,   159,   160,    -1,   162,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,    -1,
     175,    -1,   177,   178,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    55,    53,   151,    -1,    -1,   154,
     155,    -1,   157,   158,   159,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      55,    -1,    -1,   104,   199,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      29,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,   148,    -1,    -1,
     151,   152,    -1,   154,   155,   197,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,   172,    -1,    -1,    -1,   130,   131,   178,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,   148,   192,   196,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   130,   131,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,   148,
      -1,   196,   151,   152,    -1,   154,   155,    -1,   157,   158,
     159,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,    30,    -1,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    46,    47,    -1,   196,    -1,    -1,
      52,   117,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    85,    -1,   151,   152,    -1,   154,   155,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    65,   130,    -1,
     132,   133,   134,   135,   136,   201,    77,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,   154,   155,    77,   157,   158,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    46,    47,    -1,   196,    -1,    -1,    52,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,   154,   155,    -1,   157,   158,   159,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      85,   154,   155,   156,   157,   158,   159,    -1,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,   196,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,   196,    -1,   130,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    46,    47,    -1,   143,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,    66,    -1,    -1,   163,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,   172,    -1,    -1,
      -1,    -1,   177,    -1,    85,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,    -1,   157,   158,   159,    -1,
      -1,   117,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    77,    -1,    79,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   148,    -1,    -1,   151,   152,    -1,   154,   155,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    77,    -1,
     196,    -1,    -1,   148,    -1,   201,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   117,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,   154,   155,    -1,   157,   158,
     159,    -1,    -1,    77,    -1,    -1,   148,    -1,    -1,   151,
     152,    85,   154,   155,    -1,   157,   158,   159,    77,    -1,
      79,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,   196,    -1,    -1,   199,   117,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,
     154,   155,    -1,   157,   158,   159,    -1,    -1,    -1,   148,
      -1,    -1,   151,   152,    -1,   154,   155,    -1,   157,   158,
     159,    77,    -1,    79,    -1,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,   196,    -1,    -1,
      -1,   117,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,   129,    79,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,   148,    53,    -1,   151,   152,    -1,   154,   155,
      -1,   157,   158,   159,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
     196,    -1,    77,   148,    -1,   201,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   117,   201,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,   154,
     155,    -1,   157,   158,   159,    -1,   148,    -1,    -1,   151,
     152,    -1,   154,   155,    -1,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,   196,    -1,    -1,   154,   155,   201,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,    -1,    29,   196,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      29,   128,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    65,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    29,   128,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    77,   118,    79,    80,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   152,    77,
     154,   155,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,
     154,   155,    -1,   157,   158,   159,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    77,    -1,    -1,    -1,   128,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    77,
     154,   155,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,   157,
     158,   159,    -1,    -1,    -1,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   151,    -1,    -1,   154,   155,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,   157,
     158,   159,    77,    -1,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   123,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,   123,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,   154,   155,    -1,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    65,   154,
     155,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   154,   155,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    96,    53,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   207,   208,     0,   209,     3,     4,     5,     6,     7,
      13,    27,    28,    45,    46,    47,    52,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    66,    67,
      68,    69,    70,    74,    75,    76,    77,    78,    79,    81,
      85,    86,    87,    88,    90,    92,    94,    97,   101,   102,
     103,   104,   105,   106,   107,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   119,   120,   121,   122,   123,   124,
     129,   130,   132,   133,   134,   135,   136,   143,   148,   149,
     150,   151,   152,   154,   155,   157,   158,   159,   160,   163,
     166,   172,   173,   175,   177,   178,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     196,   198,   199,   201,   202,   204,   205,   210,   213,   220,
     221,   222,   223,   224,   225,   228,   244,   245,   249,   254,
     260,   315,   316,   321,   325,   326,   327,   328,   329,   330,
     331,   332,   334,   337,   346,   347,   348,   350,   351,   353,
     372,   382,   383,   384,   389,   392,   410,   415,   417,   418,
     419,   420,   421,   422,   423,   424,   426,   439,   441,   443,
     115,   116,   117,   129,   148,   213,   244,   315,   331,   417,
     331,   196,   331,   331,   331,   101,   331,   331,   408,   409,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,    79,   117,   196,   221,   383,   384,   417,   417,
      35,   331,   430,   431,   331,   117,   196,   221,   383,   384,
     385,   416,   422,   427,   428,   196,   322,   386,   196,   322,
     338,   323,   331,   230,   322,   196,   196,   196,   322,   198,
     331,   213,   198,   331,    29,    55,   130,   131,   152,   172,
     196,   213,   224,   444,   455,   456,   179,   198,   328,   331,
     352,   354,   199,   237,   331,   104,   105,   151,   214,   217,
     220,    79,   201,   286,   287,   123,   123,    79,   288,   196,
     196,   196,   196,   213,   258,   445,   196,   196,    79,    84,
     144,   145,   146,   436,   437,   151,   199,   220,   220,   259,
     445,   152,   196,   445,   445,   339,   321,   331,   332,   417,
     226,   199,    84,   387,   436,    84,   436,   436,    30,   151,
     168,   446,   196,     9,   198,    35,   243,   152,   257,   445,
     117,   244,   316,   198,   198,   198,   198,   198,   198,    10,
      11,    12,    29,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    53,    65,   198,    66,    66,   198,
     199,   147,   124,   160,   260,   314,   315,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      63,    64,   127,   412,   413,    66,   199,   414,   196,    66,
     199,   201,   423,   196,   243,   244,    14,   331,   198,   128,
      44,   213,   407,   196,   321,   417,   147,   417,   128,   203,
       9,   394,   321,   417,   446,   147,   196,   388,   127,   412,
     413,   414,   197,   331,    30,   228,     8,   340,     9,   198,
     228,   229,   323,   324,   331,   213,   272,   232,   198,   198,
     198,   456,   456,   168,   196,   104,   456,    14,   213,    79,
     198,   198,   198,   179,   180,   181,   186,   187,   190,   191,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   367,
     368,   369,   238,   108,   165,   198,   151,   215,   218,   220,
     151,   216,   219,   220,   220,     9,   198,    96,   199,   417,
       9,   198,    14,     9,   198,   417,   440,   440,   321,   332,
     417,   197,   168,   252,   129,   417,   429,   430,    66,   127,
     144,   437,    78,   331,   417,    84,   144,   437,   220,   212,
     198,   199,   255,   373,   375,    85,   201,   341,   342,   344,
     384,   423,   441,    14,    96,   442,   282,   283,   410,   411,
     197,   197,   197,   200,   227,   228,   245,   249,   254,   331,
     202,   204,   205,   213,   447,   448,   456,    35,   161,   284,
     285,   331,   444,   196,   445,   250,   243,   331,   331,   331,
      30,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   385,   331,   331,   425,   425,   331,   432,
     433,   123,   199,   213,   422,   423,   258,   259,   257,   244,
      27,    35,   325,   328,   331,   352,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   199,   213,
     422,   425,   331,   284,   425,   331,   429,   243,   197,   331,
     196,   406,     9,   394,   321,   197,   213,    35,   331,    35,
     331,   197,   197,   422,   284,   199,   213,   422,   197,   226,
     276,   199,   331,   331,    88,    30,   228,   270,   198,    28,
      96,    14,     9,   197,    30,   199,   273,   456,    85,   224,
     452,   453,   454,   196,     9,    46,    47,    52,    54,    66,
      85,   130,   143,   152,   172,   196,   221,   222,   224,   349,
     383,   389,   390,   391,   182,    79,   331,    79,    79,   331,
     364,   365,   331,   331,   357,   367,   185,   370,   226,   196,
     236,   220,   198,     9,    96,   220,   198,     9,    96,    96,
     217,   213,   331,   287,   390,    79,     9,   197,   197,   197,
     197,   197,   198,   213,   451,   125,   263,   196,     9,   197,
     197,    79,    80,   213,   438,   213,    66,   200,   200,   209,
     211,   126,   262,   167,    50,   152,   167,   377,   128,     9,
     394,   197,   147,   456,   456,    14,   194,     9,   395,   456,
     457,   127,   412,   413,   414,   200,     9,   394,   169,   417,
     331,   197,     9,   395,    14,   335,   246,   125,   261,   196,
     445,   331,    30,   203,   203,   128,   200,     9,   394,   331,
     446,   196,   253,   256,   251,   243,    68,   417,   331,   446,
     196,   203,   200,   197,   203,   200,   197,    46,    47,    66,
      74,    75,    76,    85,   130,   143,   172,   213,   397,   399,
     402,   405,   213,   417,   417,   128,   412,   413,   414,   197,
     331,   277,    71,    72,   278,   226,   322,   226,   324,    96,
      35,   129,   267,   417,   390,   213,    30,   228,   271,   198,
     274,   198,   274,     9,   169,   128,   147,     9,   394,   197,
     161,   447,   448,   449,   447,   390,   390,   390,   390,   390,
     393,   396,   196,    84,   147,   196,   390,   147,   199,    10,
      11,    12,    29,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    65,   331,   182,   182,    14,   188,
     189,   366,     9,   192,   370,    79,   200,   383,   199,   240,
      96,   218,   213,    96,   219,   213,   213,   200,    14,   417,
     198,    96,     9,   169,   264,   383,   199,   429,   129,   417,
      14,   203,   331,   200,   209,   264,   199,   376,    14,   331,
     341,   213,   198,   456,    30,   450,   411,    35,    79,   161,
     199,   213,   422,   456,    35,   161,   331,   390,   282,   196,
     383,   262,   336,   247,   331,   331,   331,   200,   196,   284,
     263,   262,   261,   445,   385,   200,   196,   284,    14,    74,
      75,    76,   213,   398,   398,   399,   400,   401,   196,    84,
     144,   196,     9,   394,   197,   406,    35,   331,   200,    71,
      72,   279,   322,   228,   200,   198,    89,   198,   267,   417,
     196,   128,   266,    14,   226,   274,    98,    99,   100,   274,
     200,   456,   456,   213,   452,     9,   197,   394,   128,   203,
       9,   394,   393,   213,   341,   343,   345,   197,   123,   213,
     390,   434,   435,   390,   390,   390,    30,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     331,   331,   331,   365,   331,   355,    79,   241,   213,   213,
     390,   456,   213,     9,   289,   197,   196,   325,   328,   331,
     203,   200,   289,   153,   166,   199,   372,   379,   153,   199,
     378,   128,   198,   456,   340,   457,    79,    14,    79,   331,
     446,   196,   417,   331,   197,   282,   199,   282,   196,   128,
     196,   284,   197,   199,   199,   262,   248,   388,   196,   284,
     197,   128,   203,     9,   394,   400,   144,   341,   403,   404,
     399,   417,   322,    30,    73,   228,   198,   324,   266,   429,
     267,   197,   390,    95,    98,   198,   331,    30,   198,   275,
     200,   169,   128,   161,    30,   197,   390,   390,   197,   128,
       9,   394,   197,   128,   200,     9,   394,   390,    30,   183,
     197,   226,    96,   383,     4,   105,   110,   118,   154,   155,
     157,   200,   290,   313,   314,   315,   320,   410,   429,   200,
     200,    50,   331,   331,   331,    35,    79,   161,    14,   390,
     200,   196,   284,   450,   197,   289,   197,   282,   331,   284,
     197,   289,   289,   199,   196,   284,   197,   399,   399,   197,
     128,   197,     9,   394,    30,   226,   198,   197,   197,   197,
     233,   198,   198,   275,   226,   456,   456,   128,   390,   341,
     390,   390,   390,   331,   199,   200,   456,   125,   126,   444,
     265,   383,   118,   130,   131,   152,   158,   299,   300,   301,
     383,   156,   305,   306,   121,   196,   213,   307,   308,   291,
     244,   456,     9,   198,   314,   197,   152,   374,   200,   200,
      79,    14,    79,   390,   196,   284,   197,   110,   333,   450,
     200,   450,   197,   197,   200,   200,   289,   282,   197,   128,
     399,   341,   226,   231,   234,    30,   228,   269,   226,   197,
     390,   128,   128,   184,   226,   383,   383,    14,     9,   198,
     199,   199,     9,   198,     3,     4,     5,     6,     7,    10,
      11,    12,    13,    27,    28,    53,    67,    68,    69,    70,
      71,    72,    73,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   129,   130,   132,   133,   134,   135,
     136,   148,   149,   150,   160,   162,   163,   165,   172,   173,
     175,   177,   178,   213,   380,   381,     9,   198,   152,   156,
     213,   308,   309,   310,   198,    79,   319,   243,   292,   444,
     244,    14,   390,   284,   197,   196,   199,   198,   199,   311,
     333,   450,   200,   197,   399,   128,    30,   228,   268,   269,
     226,   390,   390,   331,   200,   198,   198,   390,   383,   295,
     302,   389,   300,    14,    30,    47,   303,   306,     9,    33,
     197,    29,    46,    49,    14,     9,   198,   445,   319,    14,
     243,   390,   197,    35,    79,   371,   226,   226,   199,   311,
     450,   399,   226,    93,   185,   239,   200,   213,   224,   296,
     297,   298,     9,   200,   390,   381,   381,    55,   304,   309,
     309,    29,    46,    49,   390,    79,   196,   198,   390,   445,
      79,     9,   395,   200,   200,   226,   311,    91,   198,    79,
     108,   235,   147,    96,   389,   159,    14,   293,   196,    35,
      79,   197,   200,   198,   196,   165,   242,   213,   314,   315,
     390,   280,   281,   411,   294,    79,   383,   240,   162,   213,
     198,   197,     9,   395,   112,   113,   114,   317,   318,   280,
      79,   265,   198,   450,   411,   457,   197,   197,   198,   198,
     199,   312,   317,    35,    79,   161,   450,   199,   226,   457,
      79,    14,    79,   312,   226,   200,    35,    79,   161,    14,
     390,   200,    79,    14,    79,   390,    14,   390,   390
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, _p, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).line0   = YYRHSLOC (Rhs, 1).line0;	\
	  (Current).char0 = YYRHSLOC (Rhs, 1).char0;	\
	  (Current).line1    = YYRHSLOC (Rhs, N).line1;		\
	  (Current).char1  = YYRHSLOC (Rhs, N).char1;	\
	}								\
      else								\
	{								\
	  (Current).line0   = (Current).line1   =		\
	    YYRHSLOC (Rhs, 0).line1;				\
	  (Current).char0 = (Current).char1 =		\
	    YYRHSLOC (Rhs, 0).char1;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).line0, (Loc).char0,	\
	      (Loc).line1,  (Loc).char1)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, _p)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, _p); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, _p)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (_p);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, _p)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, _p);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, HPHP::HPHP_PARSER_NS::Parser *_p)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, _p)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , _p);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, _p); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, _p)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (_p);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (HPHP::HPHP_PARSER_NS::Parser *_p);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (HPHP::HPHP_PARSER_NS::Parser *_p)
#else
int
yyparse (_p)
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.line0   = yylloc.line1   = 1;
  yylloc.char0 = yylloc.char1 = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	struct yyalloc *yyptr =
	  (struct yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
      memset(yyptr, 0, YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE_RESET (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 730 "hphp.y"
    { _p->onNewLabelScope(true);
                                         _p->initParseTree();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 733 "hphp.y"
    { _p->popLabelInfo();
                                         _p->finiParseTree();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 740 "hphp.y"
    { _p->addTopStatement((yyvsp[(2) - (2)]));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 741 "hphp.y"
    { ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 744 "hphp.y"
    { _p->nns((yyvsp[(1) - (1)]).num(), (yyvsp[(1) - (1)]).text()); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 745 "hphp.y"
    { _p->nns(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 746 "hphp.y"
    { _p->nns(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 747 "hphp.y"
    { _p->nns(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 748 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 749 "hphp.y"
    { _p->onHaltCompiler();
                                         _p->finiParseTree();
                                         YYACCEPT;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 752 "hphp.y"
    { _p->onNamespaceStart((yyvsp[(2) - (3)]).text(), true);
                                         (yyval).reset();;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 754 "hphp.y"
    { _p->onNamespaceStart((yyvsp[(2) - (3)]).text());;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 755 "hphp.y"
    { _p->onNamespaceEnd(); (yyval) = (yyvsp[(5) - (6)]);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 756 "hphp.y"
    { _p->onNamespaceStart("");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 757 "hphp.y"
    { _p->onNamespaceEnd(); (yyval) = (yyvsp[(4) - (5)]);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 758 "hphp.y"
    { _p->nns(); (yyval).reset();;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 760 "hphp.y"
    { _p->nns(); (yyval).reset();;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 762 "hphp.y"
    { _p->nns(); (yyval).reset();;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 763 "hphp.y"
    { _p->nns();
                                         _p->finishStatement((yyval), (yyvsp[(1) - (2)])); (yyval) = 1;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 768 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 769 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 770 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 771 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 772 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 773 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 774 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 775 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 776 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 777 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 778 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 779 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 780 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 781 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 782 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 783 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 784 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 785 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 786 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 791 "hphp.y"
    { ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 792 "hphp.y"
    { ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 797 "hphp.y"
    { ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 798 "hphp.y"
    { ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 803 "hphp.y"
    { ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 804 "hphp.y"
    { ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 808 "hphp.y"
    { _p->onUse((yyvsp[(1) - (1)]).text(),"");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 809 "hphp.y"
    { _p->onUse((yyvsp[(2) - (2)]).text(),"");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 810 "hphp.y"
    { _p->onUse((yyvsp[(1) - (3)]).text(),(yyvsp[(3) - (3)]).text());;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 812 "hphp.y"
    { _p->onUse((yyvsp[(2) - (4)]).text(),(yyvsp[(4) - (4)]).text());;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 816 "hphp.y"
    { _p->onUseFunction((yyvsp[(1) - (1)]).text(),"");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 817 "hphp.y"
    { _p->onUseFunction((yyvsp[(2) - (2)]).text(),"");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 818 "hphp.y"
    { _p->onUseFunction((yyvsp[(1) - (3)]).text(),(yyvsp[(3) - (3)]).text());;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 820 "hphp.y"
    { _p->onUseFunction((yyvsp[(2) - (4)]).text(),(yyvsp[(4) - (4)]).text());;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 824 "hphp.y"
    { _p->onUseConst((yyvsp[(1) - (1)]).text(),"");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 825 "hphp.y"
    { _p->onUseConst((yyvsp[(2) - (2)]).text(),"");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 826 "hphp.y"
    { _p->onUseConst((yyvsp[(1) - (3)]).text(),(yyvsp[(3) - (3)]).text());;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 828 "hphp.y"
    { _p->onUseConst((yyvsp[(2) - (4)]).text(),(yyvsp[(4) - (4)]).text());;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 832 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 834 "hphp.y"
    { (yyval) = (yyvsp[(1) - (3)]) + (yyvsp[(2) - (3)]) + (yyvsp[(3) - (3)]); (yyval) = (yyvsp[(1) - (3)]).num() | 2;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 837 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = (yyval).num() | 1;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 839 "hphp.y"
    { (yyval).set((yyvsp[(3) - (3)]).num() | 2, _p->nsDecl((yyvsp[(3) - (3)]).text()));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 840 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = (yyval).num() | 2;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 843 "hphp.y"
    { if ((yyvsp[(1) - (1)]).num() & 1) {
                                           (yyvsp[(1) - (1)]).setText(_p->resolve((yyvsp[(1) - (1)]).text(),0));
                                         }
                                         (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 850 "hphp.y"
    { if ((yyvsp[(1) - (2)]).num() & 1) {
                                           (yyvsp[(1) - (2)]).setText(_p->resolve((yyvsp[(1) - (2)]).text(),0));
                                         }
                                         (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 857 "hphp.y"
    { if ((yyvsp[(1) - (2)]).num() & 1) {
                                           (yyvsp[(1) - (2)]).setText(_p->resolve((yyvsp[(1) - (2)]).text(),1));
                                         }
                                         _p->onTypeAnnotation((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 865 "hphp.y"
    { (yyvsp[(3) - (5)]).setText(_p->nsDecl((yyvsp[(3) - (5)]).text()));
                                         _p->onConst((yyval),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 868 "hphp.y"
    { (yyvsp[(2) - (4)]).setText(_p->nsDecl((yyvsp[(2) - (4)]).text()));
                                         _p->onConst((yyval),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 874 "hphp.y"
    { _p->addStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 875 "hphp.y"
    { _p->onStatementListStart((yyval));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 878 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 879 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 880 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 881 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 884 "hphp.y"
    { _p->onBlock((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 888 "hphp.y"
    { _p->onIf((yyval),(yyvsp[(2) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 893 "hphp.y"
    { _p->onIf((yyval),(yyvsp[(2) - (8)]),(yyvsp[(4) - (8)]),(yyvsp[(5) - (8)]),(yyvsp[(6) - (8)]));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 894 "hphp.y"
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 896 "hphp.y"
    { _p->popLabelScope();
                                         _p->onWhile((yyval),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));
                                         _p->onCompleteLabelScope(false);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 900 "hphp.y"
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 903 "hphp.y"
    { _p->popLabelScope();
                                         _p->onDo((yyval),(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]));
                                         _p->onCompleteLabelScope(false);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 907 "hphp.y"
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 909 "hphp.y"
    { _p->popLabelScope();
                                         _p->onFor((yyval),(yyvsp[(3) - (10)]),(yyvsp[(5) - (10)]),(yyvsp[(7) - (10)]),(yyvsp[(10) - (10)]));
                                         _p->onCompleteLabelScope(false);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 912 "hphp.y"
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 914 "hphp.y"
    { _p->popLabelScope();
                                         _p->onSwitch((yyval),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));
                                         _p->onCompleteLabelScope(false);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 917 "hphp.y"
    { _p->onBreakContinue((yyval), true, NULL);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 918 "hphp.y"
    { _p->onBreakContinue((yyval), true, &(yyvsp[(2) - (3)]));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 919 "hphp.y"
    { _p->onBreakContinue((yyval), false, NULL);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 920 "hphp.y"
    { _p->onBreakContinue((yyval), false, &(yyvsp[(2) - (3)]));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 921 "hphp.y"
    { _p->onReturn((yyval), NULL);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 922 "hphp.y"
    { _p->onReturn((yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 923 "hphp.y"
    { _p->onYieldBreak((yyval));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 924 "hphp.y"
    { _p->onGlobal((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 925 "hphp.y"
    { _p->onStatic((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 926 "hphp.y"
    { _p->onEcho((yyval), (yyvsp[(2) - (3)]), 0);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 927 "hphp.y"
    { _p->onUnset((yyval), (yyvsp[(3) - (5)]));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 928 "hphp.y"
    { (yyval).reset(); (yyval) = ';';;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 929 "hphp.y"
    { _p->onEcho((yyval), (yyvsp[(1) - (1)]), 1);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 932 "hphp.y"
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 934 "hphp.y"
    { _p->popLabelScope();
                                         _p->onForEach((yyval),(yyvsp[(3) - (9)]),(yyvsp[(5) - (9)]),(yyvsp[(6) - (9)]),(yyvsp[(9) - (9)]), false);
                                         _p->onCompleteLabelScope(false);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 939 "hphp.y"
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 941 "hphp.y"
    { _p->popLabelScope();
                                         _p->onForEach((yyval),(yyvsp[(3) - (10)]),(yyvsp[(6) - (10)]),(yyvsp[(7) - (10)]),(yyvsp[(10) - (10)]), true);
                                         _p->onCompleteLabelScope(false);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 945 "hphp.y"
    { _p->onBlock((yyval), (yyvsp[(5) - (5)])); (yyval) = T_DECLARE;;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 952 "hphp.y"
    { _p->onCompleteLabelScope(false);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 953 "hphp.y"
    { _p->onTry((yyval),(yyvsp[(2) - (13)]),(yyvsp[(5) - (13)]),(yyvsp[(6) - (13)]),(yyvsp[(9) - (13)]),(yyvsp[(11) - (13)]),(yyvsp[(13) - (13)]));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 956 "hphp.y"
    { _p->onCompleteLabelScope(false);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 957 "hphp.y"
    { _p->onTry((yyval), (yyvsp[(2) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 958 "hphp.y"
    { _p->onThrow((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 959 "hphp.y"
    { _p->onGoto((yyval), (yyvsp[(2) - (3)]), true);
                                         _p->addGoto((yyvsp[(2) - (3)]).text(),
                                                     _p->getLocation(),
                                                     &(yyval));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 963 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 964 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 965 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 966 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 967 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 968 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 969 "hphp.y"
    { _p->onReturn((yyval), &(yyvsp[(2) - (3)])); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 970 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 971 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 972 "hphp.y"
    { _p->onReturn((yyval), &(yyvsp[(2) - (3)])); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 973 "hphp.y"
    { _p->onLabel((yyval), (yyvsp[(1) - (2)]));
                                         _p->addLabel((yyvsp[(1) - (2)]).text(),
                                                      _p->getLocation(),
                                                      &(yyval));
                                         _p->onScopeLabel((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 981 "hphp.y"
    { _p->onNewLabelScope(false);;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 982 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]);;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 991 "hphp.y"
    { _p->onCatch((yyval), (yyvsp[(1) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(8) - (9)]));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 992 "hphp.y"
    { (yyval).reset();;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 996 "hphp.y"
    { _p->onNewLabelScope(false);
                                         _p->pushLabelScope();;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 998 "hphp.y"
    { _p->popLabelScope();
                                         _p->onFinally((yyval), (yyvsp[(3) - (4)]));
                                         _p->onCompleteLabelScope(false);;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1004 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1005 "hphp.y"
    { (yyval).reset();;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1009 "hphp.y"
    { (yyval) = 1;;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1010 "hphp.y"
    { (yyval).reset();;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1014 "hphp.y"
    { _p->pushFuncLocation(); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1019 "hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onNewLabelScope(true);
                                         _p->onFunctionStart((yyvsp[(3) - (3)]));
                                         _p->pushLabelInfo();;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1025 "hphp.y"
    { _p->onFunction((yyval),nullptr,(yyvsp[(8) - (9)]),(yyvsp[(2) - (9)]),(yyvsp[(3) - (9)]),(yyvsp[(6) - (9)]),(yyvsp[(9) - (9)]),nullptr);
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1031 "hphp.y"
    { (yyvsp[(4) - (4)]).setText(_p->nsDecl((yyvsp[(4) - (4)]).text()));
                                         _p->onNewLabelScope(true);
                                         _p->onFunctionStart((yyvsp[(4) - (4)]));
                                         _p->pushLabelInfo();;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1037 "hphp.y"
    { _p->onFunction((yyval),&(yyvsp[(1) - (10)]),(yyvsp[(9) - (10)]),(yyvsp[(3) - (10)]),(yyvsp[(4) - (10)]),(yyvsp[(7) - (10)]),(yyvsp[(10) - (10)]),nullptr);
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1043 "hphp.y"
    { (yyvsp[(5) - (5)]).setText(_p->nsDecl((yyvsp[(5) - (5)]).text()));
                                         _p->onNewLabelScope(true);
                                         _p->onFunctionStart((yyvsp[(5) - (5)]));
                                         _p->pushLabelInfo();;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1049 "hphp.y"
    { _p->onFunction((yyval),&(yyvsp[(2) - (11)]),(yyvsp[(10) - (11)]),(yyvsp[(4) - (11)]),(yyvsp[(5) - (11)]),(yyvsp[(8) - (11)]),(yyvsp[(11) - (11)]),&(yyvsp[(1) - (11)]));
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1057 "hphp.y"
    { (yyvsp[(2) - (2)]).setText(_p->nsDecl((yyvsp[(2) - (2)]).text()));
                                         _p->onClassStart((yyvsp[(1) - (2)]).num(),(yyvsp[(2) - (2)]));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1060 "hphp.y"
    { Token stmts;
                                         if (_p->peekClass()) {
                                           xhp_collect_attributes(_p,stmts,(yyvsp[(7) - (8)]));
                                         } else {
                                           stmts = (yyvsp[(7) - (8)]);
                                         }
                                         _p->onClass((yyval),(yyvsp[(1) - (8)]).num(),(yyvsp[(2) - (8)]),(yyvsp[(4) - (8)]),(yyvsp[(5) - (8)]),
                                                     stmts,0);
                                         if (_p->peekClass()) {
                                           _p->xhpResetAttributes();
                                         }
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1075 "hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onClassStart((yyvsp[(2) - (3)]).num(),(yyvsp[(3) - (3)]));;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1078 "hphp.y"
    { Token stmts;
                                         if (_p->peekClass()) {
                                           xhp_collect_attributes(_p,stmts,(yyvsp[(8) - (9)]));
                                         } else {
                                           stmts = (yyvsp[(8) - (9)]);
                                         }
                                         _p->onClass((yyval),(yyvsp[(2) - (9)]).num(),(yyvsp[(3) - (9)]),(yyvsp[(5) - (9)]),(yyvsp[(6) - (9)]),
                                                     stmts,&(yyvsp[(1) - (9)]));
                                         if (_p->peekClass()) {
                                           _p->xhpResetAttributes();
                                         }
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1092 "hphp.y"
    { (yyvsp[(2) - (2)]).setText(_p->nsDecl((yyvsp[(2) - (2)]).text()));
                                         _p->onClassStart(T_INTERFACE,(yyvsp[(2) - (2)]));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1095 "hphp.y"
    { _p->onInterface((yyval),(yyvsp[(2) - (7)]),(yyvsp[(4) - (7)]),(yyvsp[(6) - (7)]),0);
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1100 "hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onClassStart(T_INTERFACE,(yyvsp[(3) - (3)]));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1103 "hphp.y"
    { _p->onInterface((yyval),(yyvsp[(3) - (8)]),(yyvsp[(5) - (8)]),(yyvsp[(7) - (8)]),&(yyvsp[(1) - (8)]));
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1110 "hphp.y"
    { (yyvsp[(2) - (2)]).setText(_p->nsDecl((yyvsp[(2) - (2)]).text()));
                                         _p->onClassStart(T_TRAIT, (yyvsp[(2) - (2)]));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1113 "hphp.y"
    { Token t_ext;
                                         t_ext.reset();
                                         _p->onClass((yyval),T_TRAIT,(yyvsp[(2) - (7)]),t_ext,(yyvsp[(4) - (7)]),
                                                     (yyvsp[(6) - (7)]), 0);
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1121 "hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onClassStart(T_TRAIT, (yyvsp[(3) - (3)]));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1124 "hphp.y"
    { Token t_ext;
                                         t_ext.reset();
                                         _p->onClass((yyval),T_TRAIT,(yyvsp[(3) - (8)]),t_ext,(yyvsp[(5) - (8)]),
                                                     (yyvsp[(7) - (8)]), &(yyvsp[(1) - (8)]));
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1132 "hphp.y"
    { _p->pushClass(false); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1133 "hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel(); _p->pushTypeScope();
                                         _p->pushClass(true); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1137 "hphp.y"
    { _p->pushClass(false); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1140 "hphp.y"
    { _p->pushClass(false); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1143 "hphp.y"
    { (yyval) = T_CLASS;;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1144 "hphp.y"
    { (yyval) = T_ABSTRACT;;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1145 "hphp.y"
    { (yyval) = T_FINAL;;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1149 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1150 "hphp.y"
    { (yyval).reset();;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1153 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1154 "hphp.y"
    { (yyval).reset();;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1157 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1158 "hphp.y"
    { (yyval).reset();;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1161 "hphp.y"
    { _p->onInterfaceName((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1163 "hphp.y"
    { _p->onInterfaceName((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1166 "hphp.y"
    { _p->onTraitName((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1168 "hphp.y"
    { _p->onTraitName((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1172 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1173 "hphp.y"
    { (yyval).reset();;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1176 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1177 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = 1;;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1178 "hphp.y"
    { _p->onListAssignment((yyval), (yyvsp[(3) - (4)]), NULL);;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1182 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1184 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1187 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1189 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1192 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1194 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1197 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1199 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1209 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1210 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]);;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1211 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1212 "hphp.y"
    { (yyval) = (yyvsp[(3) - (5)]);;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1217 "hphp.y"
    { _p->onCase((yyval),(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1219 "hphp.y"
    { _p->onCase((yyval),(yyvsp[(1) - (4)]),NULL,(yyvsp[(4) - (4)]));;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1220 "hphp.y"
    { (yyval).reset();;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1223 "hphp.y"
    { (yyval).reset();;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1224 "hphp.y"
    { (yyval).reset();;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1229 "hphp.y"
    { _p->onElseIf((yyval),(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1230 "hphp.y"
    { (yyval).reset();;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1235 "hphp.y"
    { _p->onElseIf((yyval),(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1236 "hphp.y"
    { (yyval).reset();;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1239 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1240 "hphp.y"
    { (yyval).reset();;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1243 "hphp.y"
    { (yyval) = (yyvsp[(3) - (3)]);;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1244 "hphp.y"
    { (yyval).reset();;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1252 "hphp.y"
    { _p->onVariadicParam((yyval),&(yyvsp[(1) - (7)]),(yyvsp[(5) - (7)]),(yyvsp[(7) - (7)]),false,
                                                            &(yyvsp[(3) - (7)]),&(yyvsp[(4) - (7)])); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1258 "hphp.y"
    { validate_hh_variadic_variant(
                                          _p, (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), &(yyvsp[(4) - (6)]));
                                        (yyval) = (yyvsp[(1) - (6)]); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1262 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1266 "hphp.y"
    { _p->onVariadicParam((yyval),NULL,(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),false,
                                                            &(yyvsp[(1) - (5)]),&(yyvsp[(2) - (5)])); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1271 "hphp.y"
    { validate_hh_variadic_variant(
                                          _p, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), &(yyvsp[(2) - (4)]));
                                        (yyval).reset(); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1274 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1280 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]),0,
                                                     NULL,&(yyvsp[(1) - (4)]),&(yyvsp[(2) - (4)]));;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1284 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),1,
                                                     NULL,&(yyvsp[(1) - (5)]),&(yyvsp[(2) - (5)]));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1289 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(3) - (7)]),(yyvsp[(5) - (7)]),1,
                                                     &(yyvsp[(7) - (7)]),&(yyvsp[(1) - (7)]),&(yyvsp[(2) - (7)]));;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1294 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),0,
                                                     &(yyvsp[(6) - (6)]),&(yyvsp[(1) - (6)]),&(yyvsp[(2) - (6)]));;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1299 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]),0,
                                                     NULL,&(yyvsp[(3) - (6)]),&(yyvsp[(4) - (6)]));;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1304 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (7)]),(yyvsp[(5) - (7)]),(yyvsp[(7) - (7)]),1,
                                                     NULL,&(yyvsp[(3) - (7)]),&(yyvsp[(4) - (7)]));;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1310 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (9)]),(yyvsp[(5) - (9)]),(yyvsp[(7) - (9)]),1,
                                                     &(yyvsp[(9) - (9)]),&(yyvsp[(3) - (9)]),&(yyvsp[(4) - (9)]));;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1316 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (8)]),(yyvsp[(5) - (8)]),(yyvsp[(6) - (8)]),0,
                                                     &(yyvsp[(8) - (8)]),&(yyvsp[(3) - (8)]),&(yyvsp[(4) - (8)]));;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1324 "hphp.y"
    { _p->onVariadicParam((yyval),&(yyvsp[(1) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(6) - (6)]),
                                        false,&(yyvsp[(3) - (6)]),NULL); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1329 "hphp.y"
    { validate_hh_variadic_variant(
                                          _p, (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), NULL);
                                        (yyval) = (yyvsp[(1) - (5)]); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1333 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1336 "hphp.y"
    { _p->onVariadicParam((yyval),NULL,(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]),
                                                            false,&(yyvsp[(1) - (4)]),NULL); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1340 "hphp.y"
    { validate_hh_variadic_variant(
                                          _p, (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), NULL);
                                        (yyval).reset(); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1343 "hphp.y"
    { (yyval).reset();;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1348 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]),false,
                                                     NULL,&(yyvsp[(1) - (3)]),NULL); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1351 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]),true,
                                                     NULL,&(yyvsp[(1) - (4)]),NULL); ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1355 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(2) - (6)]),(yyvsp[(4) - (6)]),true,
                                                     &(yyvsp[(6) - (6)]),&(yyvsp[(1) - (6)]),NULL); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1359 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(2) - (5)]),(yyvsp[(3) - (5)]),false,
                                                     &(yyvsp[(5) - (5)]),&(yyvsp[(1) - (5)]),NULL); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1363 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)]),false,
                                                     NULL,&(yyvsp[(3) - (5)]),NULL); ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1367 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(6) - (6)]),true,
                                                     NULL,&(yyvsp[(3) - (6)]),NULL); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1372 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (8)]),(yyvsp[(4) - (8)]),(yyvsp[(6) - (8)]),true,
                                                     &(yyvsp[(8) - (8)]),&(yyvsp[(3) - (8)]),NULL); ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1377 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (7)]),(yyvsp[(4) - (7)]),(yyvsp[(5) - (7)]),false,
                                                     &(yyvsp[(7) - (7)]),&(yyvsp[(3) - (7)]),NULL); ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1383 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1384 "hphp.y"
    { (yyval).reset();;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1387 "hphp.y"
    { _p->onCallParam((yyval),NULL,(yyvsp[(1) - (1)]),false,false);;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1388 "hphp.y"
    { _p->onCallParam((yyval),NULL,(yyvsp[(2) - (2)]),true,false);;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1389 "hphp.y"
    { _p->onCallParam((yyval),NULL,(yyvsp[(2) - (2)]),false,true);;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1391 "hphp.y"
    { _p->onCallParam((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),false, false);;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1393 "hphp.y"
    { _p->onCallParam((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),false,true);;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1395 "hphp.y"
    { _p->onCallParam((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),true, false);;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1399 "hphp.y"
    { _p->onGlobalVar((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1400 "hphp.y"
    { _p->onGlobalVar((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1403 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1404 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = 1;;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1405 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]); (yyval) = 1;;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1409 "hphp.y"
    { _p->onStaticVariable((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1411 "hphp.y"
    { _p->onStaticVariable((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1412 "hphp.y"
    { _p->onStaticVariable((yyval),0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1413 "hphp.y"
    { _p->onStaticVariable((yyval),0,(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1418 "hphp.y"
    { _p->onClassStatement((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1419 "hphp.y"
    { (yyval).reset();;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1422 "hphp.y"
    { _p->onClassVariableModifer((yyvsp[(1) - (1)]));;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1423 "hphp.y"
    { _p->onClassVariableStart
                                         ((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1426 "hphp.y"
    { _p->onClassVariableModifer((yyvsp[(1) - (2)]));;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1427 "hphp.y"
    { _p->onClassVariableStart
                                         ((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]),&(yyvsp[(2) - (5)]));;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1429 "hphp.y"
    { _p->onClassVariableStart
                                         ((yyval),NULL,(yyvsp[(1) - (2)]),NULL);;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1433 "hphp.y"
    { _p->onNewLabelScope(true);
                                         _p->onMethodStart((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
                                         _p->pushLabelInfo();;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1439 "hphp.y"
    { _p->onMethod((yyval),(yyvsp[(1) - (10)]),(yyvsp[(9) - (10)]),(yyvsp[(3) - (10)]),(yyvsp[(4) - (10)]),(yyvsp[(7) - (10)]),(yyvsp[(10) - (10)]),nullptr);
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1446 "hphp.y"
    { _p->onNewLabelScope(true);
                                         _p->onMethodStart((yyvsp[(5) - (6)]), (yyvsp[(2) - (6)]));
                                         _p->pushLabelInfo();;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1452 "hphp.y"
    { _p->onMethod((yyval),(yyvsp[(2) - (11)]),(yyvsp[(10) - (11)]),(yyvsp[(4) - (11)]),(yyvsp[(5) - (11)]),(yyvsp[(8) - (11)]),(yyvsp[(11) - (11)]),&(yyvsp[(1) - (11)]));
                                         _p->popLabelInfo();
                                         _p->popTypeScope();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1457 "hphp.y"
    { _p->xhpSetAttributes((yyvsp[(2) - (3)]));;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1459 "hphp.y"
    { xhp_category_stmt(_p,(yyval),(yyvsp[(2) - (3)]));;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1461 "hphp.y"
    { xhp_children_stmt(_p,(yyval),(yyvsp[(2) - (3)]));;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1463 "hphp.y"
    { _p->onClassRequire((yyval), (yyvsp[(3) - (4)]), true); ;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1465 "hphp.y"
    { _p->onClassRequire((yyval), (yyvsp[(3) - (4)]), false); ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1466 "hphp.y"
    { Token t; t.reset();
                                         _p->onTraitUse((yyval),(yyvsp[(2) - (3)]),t); ;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1469 "hphp.y"
    { _p->onTraitUse((yyval),(yyvsp[(2) - (5)]),(yyvsp[(4) - (5)])); ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1472 "hphp.y"
    { _p->onTraitRule((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1473 "hphp.y"
    { _p->onTraitRule((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1474 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1480 "hphp.y"
    { _p->onTraitPrecRule((yyval),(yyvsp[(1) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]));;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1484 "hphp.y"
    { _p->onTraitAliasRuleModify((yyval),(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),
                                                                    (yyvsp[(4) - (5)]));;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1487 "hphp.y"
    { Token t; t.reset();
                                         _p->onTraitAliasRuleModify((yyval),(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),
                                                                    t);;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1494 "hphp.y"
    { _p->onTraitAliasRuleStart((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1495 "hphp.y"
    { Token t; t.reset();
                                         _p->onTraitAliasRuleStart((yyval),t,(yyvsp[(1) - (1)]));;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1500 "hphp.y"
    { xhp_attribute_list(_p,(yyval),
                                         _p->xhpGetAttributes(),(yyvsp[(1) - (1)]));;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1503 "hphp.y"
    { xhp_attribute_list(_p,(yyval), &(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1510 "hphp.y"
    { xhp_attribute(_p,(yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));
                                         (yyval) = 1;;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1512 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = 0;;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1516 "hphp.y"
    { (yyval) = 4;;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1517 "hphp.y"
    { /* This case handles all types other
                                            than "array", "var" and "enum".
                                            For now we just use type code 5;
                                            later xhp_attribute() will fix up
                                            the type code as appropriate. */
                                         (yyval) = 5; (yyval).setText((yyvsp[(1) - (1)]));;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1523 "hphp.y"
    { (yyval) = 6;;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1525 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]); (yyval) = 7;;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1526 "hphp.y"
    { (yyval) = 9; ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1530 "hphp.y"
    { _p->onArrayPair((yyval),  0,0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1532 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1536 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1537 "hphp.y"
    { scalar_null(_p, (yyval));;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1541 "hphp.y"
    { scalar_num(_p, (yyval), "1");;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1542 "hphp.y"
    { scalar_num(_p, (yyval), "0");;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1546 "hphp.y"
    { Token t; scalar_num(_p, t, "1");
                                         _p->onArrayPair((yyval),0,&(yyvsp[(1) - (1)]),t,0);;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1549 "hphp.y"
    { Token t; scalar_num(_p, t, "1");
                                         _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),t,0);;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1554 "hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1559 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = 2;;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1560 "hphp.y"
    { (yyval) = -1;
                                         if ((yyvsp[(1) - (1)]).same("any")) (yyval) = 1;;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1562 "hphp.y"
    { (yyval) = 0;;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1566 "hphp.y"
    { xhp_children_paren(_p, (yyval), (yyvsp[(2) - (3)]), 0);;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1567 "hphp.y"
    { xhp_children_paren(_p, (yyval), (yyvsp[(2) - (4)]), 1);;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1568 "hphp.y"
    { xhp_children_paren(_p, (yyval), (yyvsp[(2) - (4)]), 2);;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1569 "hphp.y"
    { xhp_children_paren(_p, (yyval), (yyvsp[(2) - (4)]), 3);;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1573 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1574 "hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (1)]),0,  0);;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1575 "hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (2)]),1,  0);;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1576 "hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (2)]),2,  0);;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1577 "hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (2)]),3,  0);;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1579 "hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (3)]),4,&(yyvsp[(3) - (3)]));;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1581 "hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (3)]),5,&(yyvsp[(3) - (3)]));;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1585 "hphp.y"
    { (yyval) = -1;
                                         if ((yyvsp[(1) - (1)]).same("any")) (yyval) = 1; else
                                         if ((yyvsp[(1) - (1)]).same("pcdata")) (yyval) = 2;;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1588 "hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel();  (yyval) = (yyvsp[(1) - (1)]); (yyval) = 3;;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1589 "hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel(0); (yyval) = (yyvsp[(1) - (1)]); (yyval) = 4;;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1593 "hphp.y"
    { (yyval).reset();;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1594 "hphp.y"
    { _p->finishStatement((yyval), (yyvsp[(2) - (3)])); (yyval) = 1;;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1598 "hphp.y"
    { (yyval).reset();;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1599 "hphp.y"
    { _p->finishStatement((yyval), (yyvsp[(2) - (3)])); (yyval) = 1;;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1602 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1603 "hphp.y"
    { (yyval).reset();;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1606 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1607 "hphp.y"
    { (yyval).reset();;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1610 "hphp.y"
    { _p->onMemberModifier((yyval),NULL,(yyvsp[(1) - (1)]));;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1612 "hphp.y"
    { _p->onMemberModifier((yyval),&(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1615 "hphp.y"
    { (yyval) = T_PUBLIC;;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1616 "hphp.y"
    { (yyval) = T_PROTECTED;;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1617 "hphp.y"
    { (yyval) = T_PRIVATE;;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1618 "hphp.y"
    { (yyval) = T_STATIC;;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1619 "hphp.y"
    { (yyval) = T_ABSTRACT;;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1620 "hphp.y"
    { (yyval) = T_FINAL;;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1621 "hphp.y"
    { (yyval) = T_ASYNC;;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1625 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1626 "hphp.y"
    { (yyval).reset();;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1629 "hphp.y"
    { (yyval) = T_PUBLIC;;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1630 "hphp.y"
    { (yyval) = T_PROTECTED;;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1631 "hphp.y"
    { (yyval) = T_PRIVATE;;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1635 "hphp.y"
    { _p->onClassVariable((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1637 "hphp.y"
    { _p->onClassVariable((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1638 "hphp.y"
    { _p->onClassVariable((yyval),0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1639 "hphp.y"
    { _p->onClassVariable((yyval),0,(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1643 "hphp.y"
    { _p->onClassConstant((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1645 "hphp.y"
    { _p->onClassConstant((yyval),0,(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1649 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1651 "hphp.y"
    { _p->onNewObject((yyval), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1652 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_CLONE,1);;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1653 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1654 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1657 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1661 "hphp.y"
    { _p->onExprListElem((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1662 "hphp.y"
    { _p->onExprListElem((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1666 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1667 "hphp.y"
    { (yyval).reset();;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1671 "hphp.y"
    { _p->onYield((yyval), (yyvsp[(2) - (2)]));;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1672 "hphp.y"
    { _p->onYieldPair((yyval), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1676 "hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0, true);;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1681 "hphp.y"
    { _p->onListAssignment((yyval), (yyvsp[(3) - (6)]), &(yyvsp[(6) - (6)]), true);;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1685 "hphp.y"
    { _p->onAwait((yyval), (yyvsp[(2) - (2)])); ;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1689 "hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0, true);;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1694 "hphp.y"
    { _p->onListAssignment((yyval), (yyvsp[(3) - (6)]), &(yyvsp[(6) - (6)]), true);;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1698 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1699 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1700 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1704 "hphp.y"
    { _p->onListAssignment((yyval), (yyvsp[(3) - (6)]), &(yyvsp[(6) - (6)]));;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1705 "hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0);;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1706 "hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]), 1);;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1709 "hphp.y"
    { _p->onAssignNew((yyval),(yyvsp[(1) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1710 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_PLUS_EQUAL);;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1711 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MINUS_EQUAL);;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1712 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MUL_EQUAL);;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1713 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_DIV_EQUAL);;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1714 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_CONCAT_EQUAL);;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1715 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MOD_EQUAL);;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1716 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_AND_EQUAL);;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1717 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_OR_EQUAL);;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1718 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_XOR_EQUAL);;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1719 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SL_EQUAL);;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1720 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SR_EQUAL);;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1721 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_POW_EQUAL);;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1722 "hphp.y"
    { UEXP((yyval),(yyvsp[(1) - (2)]),T_INC,0);;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1723 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INC,1);;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1724 "hphp.y"
    { UEXP((yyval),(yyvsp[(1) - (2)]),T_DEC,0);;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1725 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_DEC,1);;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1726 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_BOOLEAN_OR);;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1727 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_BOOLEAN_AND);;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1728 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_OR);;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1729 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_AND);;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1730 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_XOR);;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1731 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'|');;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1732 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'&');;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1733 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'^');;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1734 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'.');;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1735 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'+');;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1736 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'-');;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1737 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'*');;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1738 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'/');;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1739 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_POW);;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1740 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'%');;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1741 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SL);;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1742 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SR);;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1743 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1744 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1745 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'!',1);;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1746 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'~',1);;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1747 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_IDENTICAL);;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1748 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_NOT_IDENTICAL);;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1749 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_EQUAL);;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1750 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_NOT_EQUAL);;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1751 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'<');;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1752 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),
                                              T_IS_SMALLER_OR_EQUAL);;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1754 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'>');;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1755 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),
                                              T_IS_GREATER_OR_EQUAL);;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1758 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_INSTANCEOF);;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1759 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1760 "hphp.y"
    { _p->onQOp((yyval), (yyvsp[(1) - (5)]), &(yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1761 "hphp.y"
    { _p->onQOp((yyval), (yyvsp[(1) - (4)]),   0, (yyvsp[(4) - (4)]));;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1762 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1763 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INT_CAST,1);;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1764 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_DOUBLE_CAST,1);;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1765 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_STRING_CAST,1);;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1766 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_ARRAY_CAST,1);;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1767 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_OBJECT_CAST,1);;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1768 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_BOOL_CAST,1);;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1769 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_UNSET_CAST,1);;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1770 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_EXIT,1);;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1771 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'@',1);;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1772 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1773 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1774 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1775 "hphp.y"
    { _p->onEncapsList((yyval),'`',(yyvsp[(2) - (3)]));;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1776 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_PRINT,1);;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1777 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1778 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1779 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1786 "hphp.y"
    { (yyval) = (yyvsp[(3) - (5)]);;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1787 "hphp.y"
    { (yyval).reset();;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1792 "hphp.y"
    { Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo(); ;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1798 "hphp.y"
    { _p->finishStatement((yyvsp[(10) - (11)]), (yyvsp[(10) - (11)])); (yyvsp[(10) - (11)]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Long,
                                                            nullptr,
                                                            (yyvsp[(2) - (11)]),(yyvsp[(5) - (11)]),(yyvsp[(8) - (11)]),(yyvsp[(10) - (11)]));
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1806 "hphp.y"
    { Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo(); ;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1812 "hphp.y"
    { _p->finishStatement((yyvsp[(11) - (12)]), (yyvsp[(11) - (12)])); (yyvsp[(11) - (12)]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Long,
                                                            &(yyvsp[(1) - (12)]),
                                                            (yyvsp[(3) - (12)]),(yyvsp[(6) - (12)]),(yyvsp[(9) - (12)]),(yyvsp[(11) - (12)]));
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1821 "hphp.y"
    { _p->pushFuncLocation();
                                         Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo();
                                         Token u;
                                         _p->onParam((yyvsp[(1) - (1)]),NULL,u,(yyvsp[(1) - (1)]),0,
                                                     NULL,NULL,NULL);;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 1829 "hphp.y"
    { Token v; Token w;
                                         _p->finishStatement((yyvsp[(3) - (3)]), (yyvsp[(3) - (3)])); (yyvsp[(3) - (3)]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Short,
                                                            nullptr,
                                                            v,(yyvsp[(1) - (3)]),w,(yyvsp[(3) - (3)]));
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 1836 "hphp.y"
    { _p->pushFuncLocation();
                                         Token t;
                                         _p->onNewLabelScope(true);
                                         _p->onClosureStart(t);
                                         _p->pushLabelInfo();;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 1844 "hphp.y"
    { Token u; Token v;
                                         _p->finishStatement((yyvsp[(6) - (6)]), (yyvsp[(6) - (6)])); (yyvsp[(6) - (6)]) = 1;
                                         (yyval) = _p->onClosure(ClosureType::Short,
                                                            nullptr,
                                                            u,(yyvsp[(3) - (6)]),v,(yyvsp[(6) - (6)]));
                                         _p->popLabelInfo();
                                         _p->onCompleteLabelScope(true);;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1854 "hphp.y"
    { (yyval) = _p->onExprForLambda((yyvsp[(2) - (2)]));;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1856 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]); ;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1860 "hphp.y"
    { validate_shape_keyname((yyvsp[(1) - (1)]), _p);
                                        _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)])); ;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1862 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 1869 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0); ;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 1872 "hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0); ;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1879 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0); ;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1882 "hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0); ;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1887 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 1888 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 1893 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 1894 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 1898 "hphp.y"
    { _p->onArray((yyval), (yyvsp[(3) - (4)]), T_ARRAY);;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 1902 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]),T_ARRAY);;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 1903 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(2) - (3)]),T_ARRAY);;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 1908 "hphp.y"
    { Token t;
                                         _p->onName(t,(yyvsp[(1) - (4)]),Parser::StringName);
                                         BEXP((yyval),t,(yyvsp[(3) - (4)]),T_COLLECTION);;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 1915 "hphp.y"
    { Token t;
                                         _p->onName(t,(yyvsp[(1) - (4)]),Parser::StringName);
                                         BEXP((yyval),t,(yyvsp[(3) - (4)]),T_COLLECTION);;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 1922 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 1924 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 1928 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 1929 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 1930 "hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)])); ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 1932 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 1936 "hphp.y"
    { _p->onQuery((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 1940 "hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0, true);;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 1944 "hphp.y"
    { _p->onFromClause((yyval), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 1949 "hphp.y"
    { _p->onQueryBody((yyval), &(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL); ;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 1951 "hphp.y"
    { _p->onQueryBody((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)])); ;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 1953 "hphp.y"
    { _p->onQueryBody((yyval), NULL, (yyvsp[(1) - (1)]), NULL); ;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 1955 "hphp.y"
    { _p->onQueryBody((yyval), NULL, (yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)])); ;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 1959 "hphp.y"
    { _p->onQueryBodyClause((yyval), NULL, (yyvsp[(1) - (1)])); ;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 1961 "hphp.y"
    { _p->onQueryBodyClause((yyval), &(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 1965 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 1966 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 1967 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 1968 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 1969 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 1970 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 1974 "hphp.y"
    { _p->onFromClause((yyval), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 1978 "hphp.y"
    { _p->onLetClause((yyval), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 1982 "hphp.y"
    { _p->onWhereClause((yyval), (yyvsp[(2) - (2)])); ;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 1987 "hphp.y"
    { _p->onJoinClause((yyval), (yyvsp[(2) - (8)]), (yyvsp[(4) - (8)]), (yyvsp[(6) - (8)]), (yyvsp[(8) - (8)])); ;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 1992 "hphp.y"
    { _p->onJoinIntoClause((yyval), (yyvsp[(2) - (10)]), (yyvsp[(4) - (10)]), (yyvsp[(6) - (10)]), (yyvsp[(8) - (10)]), (yyvsp[(10) - (10)])); ;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 1996 "hphp.y"
    { _p->onOrderbyClause((yyval), (yyvsp[(2) - (2)])); ;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2000 "hphp.y"
    { _p->onOrdering((yyval), NULL, (yyvsp[(1) - (1)])); ;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2001 "hphp.y"
    { _p->onOrdering((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2005 "hphp.y"
    { _p->onOrderingExpr((yyval), (yyvsp[(1) - (1)]), NULL); ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2006 "hphp.y"
    { _p->onOrderingExpr((yyval), (yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)])); ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2010 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2011 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2015 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2016 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2020 "hphp.y"
    { _p->onSelectClause((yyval), (yyvsp[(2) - (2)])); ;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2024 "hphp.y"
    { _p->onGroupClause((yyval), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2028 "hphp.y"
    { _p->onIntoClause((yyval), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2032 "hphp.y"
    { _p->onClosureParam((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2033 "hphp.y"
    { _p->onClosureParam((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),1);;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2034 "hphp.y"
    { _p->onClosureParam((yyval),  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2035 "hphp.y"
    { _p->onClosureParam((yyval),  0,(yyvsp[(2) - (2)]),1);;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2042 "hphp.y"
    { xhp_tag(_p,(yyval),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]));;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2045 "hphp.y"
    { Token t1; _p->onArray(t1,(yyvsp[(1) - (2)]));
                                         Token t2; _p->onArray(t2,(yyvsp[(2) - (2)]));
                                         Token file; scalar_file(_p, file);
                                         Token line; scalar_line(_p, line);
                                         _p->onCallParam((yyvsp[(1) - (2)]),NULL,t1,0,0);
                                         _p->onCallParam((yyval), &(yyvsp[(1) - (2)]),t2,0,0);
                                         _p->onCallParam((yyvsp[(1) - (2)]), &(yyvsp[(1) - (2)]),file,0,0);
                                         _p->onCallParam((yyvsp[(1) - (2)]), &(yyvsp[(1) - (2)]),line,0,0);
                                         (yyval).setText("");;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2056 "hphp.y"
    { Token file; scalar_file(_p, file);
                                         Token line; scalar_line(_p, line);
                                         _p->onArray((yyvsp[(4) - (6)]),(yyvsp[(1) - (6)]));
                                         _p->onArray((yyvsp[(5) - (6)]),(yyvsp[(3) - (6)]));
                                         _p->onCallParam((yyvsp[(2) - (6)]),NULL,(yyvsp[(4) - (6)]),0,0);
                                         _p->onCallParam((yyval), &(yyvsp[(2) - (6)]),(yyvsp[(5) - (6)]),0,0);
                                         _p->onCallParam((yyvsp[(2) - (6)]), &(yyvsp[(2) - (6)]),file,0,0);
                                         _p->onCallParam((yyvsp[(2) - (6)]), &(yyvsp[(2) - (6)]),line,0,0);
                                         (yyval).setText((yyvsp[(6) - (6)]).text());;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2067 "hphp.y"
    { (yyval).reset(); (yyval).setText("");;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2068 "hphp.y"
    { (yyval).reset(); (yyval).setText((yyvsp[(1) - (1)]));;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2073 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (4)]),&(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]),0);;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2074 "hphp.y"
    { (yyval).reset();;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2077 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (2)]),0,(yyvsp[(2) - (2)]),0);;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2078 "hphp.y"
    { (yyval).reset();;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2081 "hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2085 "hphp.y"
    { (yyvsp[(1) - (1)]).xhpDecode();
                                         _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2088 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2091 "hphp.y"
    { (yyval).reset();
                                         if ((yyvsp[(1) - (1)]).htmlTrim()) {
                                           (yyvsp[(1) - (1)]).xhpDecode();
                                           _p->onScalar((yyval),
                                           T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));
                                         }
                                       ;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2098 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2099 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2103 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2105 "hphp.y"
    { (yyval) = (yyvsp[(1) - (3)]) + ":" + (yyvsp[(3) - (3)]);;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2107 "hphp.y"
    { (yyval) = (yyvsp[(1) - (3)]) + "-" + (yyvsp[(3) - (3)]);;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2110 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2111 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2112 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2113 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2114 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2115 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2116 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2117 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2118 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2119 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2120 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2121 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2122 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2123 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2124 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2125 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2126 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2127 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 2128 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 2129 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 2130 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 2131 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 2132 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 2133 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 2134 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 2135 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 2136 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 2137 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 2138 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 2139 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 2140 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 2141 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 2142 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 2143 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 2144 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 2145 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 2146 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 2147 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 2148 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 2149 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 2150 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 2151 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 2152 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 2153 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 2154 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 2155 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 2156 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 557:

/* Line 1455 of yacc.c  */
#line 2157 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 2158 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 2159 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 2160 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 2161 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 2162 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 2163 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 2164 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 2165 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 2166 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 2167 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 2168 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 2169 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 2170 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 2171 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 2172 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 2173 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 2174 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 2175 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 2176 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 2177 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 2178 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 2179 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 2180 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 2181 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 2182 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 2183 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 2184 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 2185 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 2186 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 2187 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 2188 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 2189 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 2194 "hphp.y"
    { _p->onCall((yyval),0,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 2198 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 2199 "hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 2202 "hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StringName);;}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 2203 "hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StaticName);;}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 2204 "hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),
                                         Parser::StaticClassExprName);;}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 2208 "hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StringName);;}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 2209 "hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StaticName);;}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 2210 "hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::ExprName);;}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 2214 "hphp.y"
    { (yyval).reset();;}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 2215 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 2216 "hphp.y"
    { (yyval).reset();;}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 2220 "hphp.y"
    { (yyval).reset();;}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 2221 "hphp.y"
    { _p->addEncap((yyval), NULL, (yyvsp[(1) - (1)]), 0);;}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 2222 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 2226 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 2227 "hphp.y"
    { (yyval).reset();;}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 2231 "hphp.y"
    { _p->onScalar((yyval), T_LNUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 2232 "hphp.y"
    { _p->onScalar((yyval), T_DNUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 2233 "hphp.y"
    { _p->onScalar((yyval), T_ONUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 2234 "hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING,  (yyvsp[(1) - (1)]));;}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 2236 "hphp.y"
    { _p->onScalar((yyval), T_LINE,     (yyvsp[(1) - (1)]));;}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 2237 "hphp.y"
    { _p->onScalar((yyval), T_FILE,     (yyvsp[(1) - (1)]));;}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 2238 "hphp.y"
    { _p->onScalar((yyval), T_DIR,      (yyvsp[(1) - (1)]));;}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 2239 "hphp.y"
    { _p->onScalar((yyval), T_CLASS_C,  (yyvsp[(1) - (1)]));;}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 2240 "hphp.y"
    { _p->onScalar((yyval), T_TRAIT_C,  (yyvsp[(1) - (1)]));;}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 2241 "hphp.y"
    { _p->onScalar((yyval), T_METHOD_C, (yyvsp[(1) - (1)]));;}
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 2242 "hphp.y"
    { _p->onScalar((yyval), T_FUNC_C,   (yyvsp[(1) - (1)]));;}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 2243 "hphp.y"
    { _p->onScalar((yyval), T_NS_C,  (yyvsp[(1) - (1)]));;}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 2244 "hphp.y"
    { _p->onScalar((yyval), T_COMPILER_HALT_OFFSET, (yyvsp[(1) - (1)]));;}
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 2247 "hphp.y"
    { _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyvsp[(2) - (3)]));;}
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 2249 "hphp.y"
    { (yyval).setText(""); _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyval));;}
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 2253 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 2254 "hphp.y"
    { _p->onConstantValue((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 2256 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]),T_ARRAY); ;}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 2257 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(2) - (3)]),T_ARRAY); ;}
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 2259 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]),T_ARRAY); ;}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 2260 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 2261 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 2263 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 2265 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_BOOLEAN_OR);;}
    break;

  case 631:

/* Line 1455 of yacc.c  */
#line 2267 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_BOOLEAN_AND);;}
    break;

  case 632:

/* Line 1455 of yacc.c  */
#line 2269 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_OR);;}
    break;

  case 633:

/* Line 1455 of yacc.c  */
#line 2271 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_AND);;}
    break;

  case 634:

/* Line 1455 of yacc.c  */
#line 2273 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_XOR);;}
    break;

  case 635:

/* Line 1455 of yacc.c  */
#line 2274 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'|');;}
    break;

  case 636:

/* Line 1455 of yacc.c  */
#line 2275 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'&');;}
    break;

  case 637:

/* Line 1455 of yacc.c  */
#line 2276 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'^');;}
    break;

  case 638:

/* Line 1455 of yacc.c  */
#line 2277 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'.');;}
    break;

  case 639:

/* Line 1455 of yacc.c  */
#line 2278 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'+');;}
    break;

  case 640:

/* Line 1455 of yacc.c  */
#line 2279 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'-');;}
    break;

  case 641:

/* Line 1455 of yacc.c  */
#line 2280 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'*');;}
    break;

  case 642:

/* Line 1455 of yacc.c  */
#line 2281 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'/');;}
    break;

  case 643:

/* Line 1455 of yacc.c  */
#line 2282 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'%');;}
    break;

  case 644:

/* Line 1455 of yacc.c  */
#line 2283 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SL);;}
    break;

  case 645:

/* Line 1455 of yacc.c  */
#line 2284 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SR);;}
    break;

  case 646:

/* Line 1455 of yacc.c  */
#line 2285 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_POW);;}
    break;

  case 647:

/* Line 1455 of yacc.c  */
#line 2286 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'!',1);;}
    break;

  case 648:

/* Line 1455 of yacc.c  */
#line 2287 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'~',1);;}
    break;

  case 649:

/* Line 1455 of yacc.c  */
#line 2288 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 650:

/* Line 1455 of yacc.c  */
#line 2289 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 651:

/* Line 1455 of yacc.c  */
#line 2291 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_IDENTICAL);;}
    break;

  case 652:

/* Line 1455 of yacc.c  */
#line 2293 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_NOT_IDENTICAL);;}
    break;

  case 653:

/* Line 1455 of yacc.c  */
#line 2295 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_EQUAL);;}
    break;

  case 654:

/* Line 1455 of yacc.c  */
#line 2297 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_NOT_EQUAL);;}
    break;

  case 655:

/* Line 1455 of yacc.c  */
#line 2298 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'<');;}
    break;

  case 656:

/* Line 1455 of yacc.c  */
#line 2300 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),
                                              T_IS_SMALLER_OR_EQUAL);;}
    break;

  case 657:

/* Line 1455 of yacc.c  */
#line 2302 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'>');;}
    break;

  case 658:

/* Line 1455 of yacc.c  */
#line 2305 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),
                                              T_IS_GREATER_OR_EQUAL);;}
    break;

  case 659:

/* Line 1455 of yacc.c  */
#line 2308 "hphp.y"
    { _p->onQOp((yyval), (yyvsp[(1) - (5)]), &(yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 660:

/* Line 1455 of yacc.c  */
#line 2309 "hphp.y"
    { _p->onQOp((yyval), (yyvsp[(1) - (4)]),   0, (yyvsp[(4) - (4)]));;}
    break;

  case 661:

/* Line 1455 of yacc.c  */
#line 2315 "hphp.y"
    { _p->onClassConst((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 1);;}
    break;

  case 662:

/* Line 1455 of yacc.c  */
#line 2317 "hphp.y"
    { (yyvsp[(1) - (3)]).xhpLabel();
                                         _p->onClassConst((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 1);;}
    break;

  case 663:

/* Line 1455 of yacc.c  */
#line 2321 "hphp.y"
    { _p->onClassClass((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 1);;}
    break;

  case 664:

/* Line 1455 of yacc.c  */
#line 2325 "hphp.y"
    { _p->onConstantValue((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 665:

/* Line 1455 of yacc.c  */
#line 2326 "hphp.y"
    { _p->onConstantValue((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 666:

/* Line 1455 of yacc.c  */
#line 2327 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 667:

/* Line 1455 of yacc.c  */
#line 2328 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 668:

/* Line 1455 of yacc.c  */
#line 2329 "hphp.y"
    { _p->onEncapsList((yyval),'"',(yyvsp[(2) - (3)]));;}
    break;

  case 669:

/* Line 1455 of yacc.c  */
#line 2330 "hphp.y"
    { _p->onEncapsList((yyval),'\'',(yyvsp[(2) - (3)]));;}
    break;

  case 670:

/* Line 1455 of yacc.c  */
#line 2332 "hphp.y"
    { _p->onEncapsList((yyval),T_START_HEREDOC,
                                                          (yyvsp[(2) - (3)]));;}
    break;

  case 671:

/* Line 1455 of yacc.c  */
#line 2337 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 672:

/* Line 1455 of yacc.c  */
#line 2338 "hphp.y"
    { (yyval).reset();;}
    break;

  case 673:

/* Line 1455 of yacc.c  */
#line 2342 "hphp.y"
    { (yyval).reset();;}
    break;

  case 674:

/* Line 1455 of yacc.c  */
#line 2343 "hphp.y"
    { (yyval).reset();;}
    break;

  case 675:

/* Line 1455 of yacc.c  */
#line 2346 "hphp.y"
    { only_in_hh_syntax(_p); (yyval).reset();;}
    break;

  case 676:

/* Line 1455 of yacc.c  */
#line 2347 "hphp.y"
    { (yyval).reset();;}
    break;

  case 677:

/* Line 1455 of yacc.c  */
#line 2353 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0);;}
    break;

  case 678:

/* Line 1455 of yacc.c  */
#line 2355 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 679:

/* Line 1455 of yacc.c  */
#line 2357 "hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 680:

/* Line 1455 of yacc.c  */
#line 2358 "hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 681:

/* Line 1455 of yacc.c  */
#line 2362 "hphp.y"
    { _p->onScalar((yyval), T_LNUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 682:

/* Line 1455 of yacc.c  */
#line 2363 "hphp.y"
    { _p->onScalar((yyval), T_DNUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 683:

/* Line 1455 of yacc.c  */
#line 2364 "hphp.y"
    { _p->onScalar((yyval), T_ONUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 684:

/* Line 1455 of yacc.c  */
#line 2365 "hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING,  (yyvsp[(1) - (1)]));;}
    break;

  case 685:

/* Line 1455 of yacc.c  */
#line 2369 "hphp.y"
    { _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyvsp[(2) - (3)]));;}
    break;

  case 686:

/* Line 1455 of yacc.c  */
#line 2371 "hphp.y"
    { (yyval).setText(""); _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyval));;}
    break;

  case 687:

/* Line 1455 of yacc.c  */
#line 2374 "hphp.y"
    { _p->onScalar((yyval),T_LNUMBER,(yyvsp[(1) - (1)]));;}
    break;

  case 688:

/* Line 1455 of yacc.c  */
#line 2375 "hphp.y"
    { _p->onScalar((yyval),T_DNUMBER,(yyvsp[(1) - (1)]));;}
    break;

  case 689:

/* Line 1455 of yacc.c  */
#line 2376 "hphp.y"
    { _p->onScalar((yyval),T_ONUMBER,(yyvsp[(1) - (1)]));;}
    break;

  case 690:

/* Line 1455 of yacc.c  */
#line 2377 "hphp.y"
    { constant_ae(_p,(yyval),(yyvsp[(1) - (1)]));;}
    break;

  case 691:

/* Line 1455 of yacc.c  */
#line 2380 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 692:

/* Line 1455 of yacc.c  */
#line 2381 "hphp.y"
    { constant_ae(_p,(yyval),(yyvsp[(1) - (1)]));;}
    break;

  case 693:

/* Line 1455 of yacc.c  */
#line 2382 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 694:

/* Line 1455 of yacc.c  */
#line 2383 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 695:

/* Line 1455 of yacc.c  */
#line 2385 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]),T_ARRAY);;}
    break;

  case 696:

/* Line 1455 of yacc.c  */
#line 2386 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(2) - (3)]),T_ARRAY);;}
    break;

  case 697:

/* Line 1455 of yacc.c  */
#line 2388 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]),T_ARRAY); ;}
    break;

  case 698:

/* Line 1455 of yacc.c  */
#line 2393 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 699:

/* Line 1455 of yacc.c  */
#line 2394 "hphp.y"
    { (yyval).reset();;}
    break;

  case 700:

/* Line 1455 of yacc.c  */
#line 2399 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0);;}
    break;

  case 701:

/* Line 1455 of yacc.c  */
#line 2401 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 702:

/* Line 1455 of yacc.c  */
#line 2403 "hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 703:

/* Line 1455 of yacc.c  */
#line 2404 "hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 704:

/* Line 1455 of yacc.c  */
#line 2408 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 705:

/* Line 1455 of yacc.c  */
#line 2409 "hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 706:

/* Line 1455 of yacc.c  */
#line 2414 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 707:

/* Line 1455 of yacc.c  */
#line 2415 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 708:

/* Line 1455 of yacc.c  */
#line 2420 "hphp.y"
    {  _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0); ;}
    break;

  case 709:

/* Line 1455 of yacc.c  */
#line 2423 "hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0); ;}
    break;

  case 710:

/* Line 1455 of yacc.c  */
#line 2428 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 711:

/* Line 1455 of yacc.c  */
#line 2429 "hphp.y"
    { (yyval).reset();;}
    break;

  case 712:

/* Line 1455 of yacc.c  */
#line 2432 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(2) - (3)]),T_ARRAY);;}
    break;

  case 713:

/* Line 1455 of yacc.c  */
#line 2433 "hphp.y"
    { Token t; t.reset();
                                         _p->onArray((yyval),t,T_ARRAY);;}
    break;

  case 714:

/* Line 1455 of yacc.c  */
#line 2440 "hphp.y"
    { _p->onUserAttribute((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 715:

/* Line 1455 of yacc.c  */
#line 2442 "hphp.y"
    { _p->onUserAttribute((yyval),  0,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 716:

/* Line 1455 of yacc.c  */
#line 2445 "hphp.y"
    { only_in_hh_syntax(_p);;}
    break;

  case 717:

/* Line 1455 of yacc.c  */
#line 2447 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 718:

/* Line 1455 of yacc.c  */
#line 2450 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 719:

/* Line 1455 of yacc.c  */
#line 2453 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 720:

/* Line 1455 of yacc.c  */
#line 2454 "hphp.y"
    { (yyval).reset();;}
    break;

  case 721:

/* Line 1455 of yacc.c  */
#line 2458 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 722:

/* Line 1455 of yacc.c  */
#line 2460 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 723:

/* Line 1455 of yacc.c  */
#line 2464 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 724:

/* Line 1455 of yacc.c  */
#line 2465 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]);;}
    break;

  case 725:

/* Line 1455 of yacc.c  */
#line 2469 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 726:

/* Line 1455 of yacc.c  */
#line 2470 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 727:

/* Line 1455 of yacc.c  */
#line 2474 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 728:

/* Line 1455 of yacc.c  */
#line 2476 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));;}
    break;

  case 729:

/* Line 1455 of yacc.c  */
#line 2481 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));;}
    break;

  case 730:

/* Line 1455 of yacc.c  */
#line 2483 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));;}
    break;

  case 731:

/* Line 1455 of yacc.c  */
#line 2487 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 732:

/* Line 1455 of yacc.c  */
#line 2488 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 733:

/* Line 1455 of yacc.c  */
#line 2489 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 734:

/* Line 1455 of yacc.c  */
#line 2490 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 735:

/* Line 1455 of yacc.c  */
#line 2491 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 736:

/* Line 1455 of yacc.c  */
#line 2492 "hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 737:

/* Line 1455 of yacc.c  */
#line 2494 "hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 738:

/* Line 1455 of yacc.c  */
#line 2497 "hphp.y"
    { _p->onStaticMember((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 739:

/* Line 1455 of yacc.c  */
#line 2499 "hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 740:

/* Line 1455 of yacc.c  */
#line 2500 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 741:

/* Line 1455 of yacc.c  */
#line 2504 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 742:

/* Line 1455 of yacc.c  */
#line 2505 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 743:

/* Line 1455 of yacc.c  */
#line 2506 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 744:

/* Line 1455 of yacc.c  */
#line 2507 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 745:

/* Line 1455 of yacc.c  */
#line 2509 "hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 746:

/* Line 1455 of yacc.c  */
#line 2511 "hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 747:

/* Line 1455 of yacc.c  */
#line 2513 "hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 748:

/* Line 1455 of yacc.c  */
#line 2514 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 749:

/* Line 1455 of yacc.c  */
#line 2518 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 750:

/* Line 1455 of yacc.c  */
#line 2519 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 751:

/* Line 1455 of yacc.c  */
#line 2520 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 752:

/* Line 1455 of yacc.c  */
#line 2526 "hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(1) - (7)]),(yyvsp[(3) - (7)]),(yyvsp[(6) - (7)]));;}
    break;

  case 753:

/* Line 1455 of yacc.c  */
#line 2529 "hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(1) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]));;}
    break;

  case 754:

/* Line 1455 of yacc.c  */
#line 2532 "hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(1) - (8)]),(yyvsp[(4) - (8)]),(yyvsp[(7) - (8)]));;}
    break;

  case 755:

/* Line 1455 of yacc.c  */
#line 2536 "hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(2) - (9)]),(yyvsp[(5) - (9)]),(yyvsp[(8) - (9)]));;}
    break;

  case 756:

/* Line 1455 of yacc.c  */
#line 2540 "hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(2) - (8)]),(yyvsp[(5) - (8)]),(yyvsp[(7) - (8)]));;}
    break;

  case 757:

/* Line 1455 of yacc.c  */
#line 2544 "hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(2) - (10)]),(yyvsp[(6) - (10)]),(yyvsp[(9) - (10)]));;}
    break;

  case 758:

/* Line 1455 of yacc.c  */
#line 2551 "hphp.y"
    { _p->onCall((yyval),0,(yyvsp[(3) - (7)]),(yyvsp[(6) - (7)]),&(yyvsp[(1) - (7)]));;}
    break;

  case 759:

/* Line 1455 of yacc.c  */
#line 2555 "hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]),&(yyvsp[(1) - (6)]));;}
    break;

  case 760:

/* Line 1455 of yacc.c  */
#line 2559 "hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(4) - (8)]),(yyvsp[(7) - (8)]),&(yyvsp[(1) - (8)]));;}
    break;

  case 761:

/* Line 1455 of yacc.c  */
#line 2563 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 762:

/* Line 1455 of yacc.c  */
#line 2565 "hphp.y"
    { _p->onIndirectRef((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 763:

/* Line 1455 of yacc.c  */
#line 2570 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 764:

/* Line 1455 of yacc.c  */
#line 2571 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 765:

/* Line 1455 of yacc.c  */
#line 2572 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 766:

/* Line 1455 of yacc.c  */
#line 2575 "hphp.y"
    { _p->onSimpleVariable((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 767:

/* Line 1455 of yacc.c  */
#line 2576 "hphp.y"
    { _p->onDynamicVariable((yyval), (yyvsp[(3) - (4)]), 0);;}
    break;

  case 768:

/* Line 1455 of yacc.c  */
#line 2579 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 769:

/* Line 1455 of yacc.c  */
#line 2580 "hphp.y"
    { (yyval).reset();;}
    break;

  case 770:

/* Line 1455 of yacc.c  */
#line 2584 "hphp.y"
    { (yyval) = 1;;}
    break;

  case 771:

/* Line 1455 of yacc.c  */
#line 2585 "hphp.y"
    { (yyval)++;;}
    break;

  case 772:

/* Line 1455 of yacc.c  */
#line 2589 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 773:

/* Line 1455 of yacc.c  */
#line 2590 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 774:

/* Line 1455 of yacc.c  */
#line 2591 "hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 775:

/* Line 1455 of yacc.c  */
#line 2593 "hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 776:

/* Line 1455 of yacc.c  */
#line 2596 "hphp.y"
    { _p->onStaticMember((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 777:

/* Line 1455 of yacc.c  */
#line 2597 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 779:

/* Line 1455 of yacc.c  */
#line 2601 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 780:

/* Line 1455 of yacc.c  */
#line 2603 "hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 781:

/* Line 1455 of yacc.c  */
#line 2605 "hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 782:

/* Line 1455 of yacc.c  */
#line 2606 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 783:

/* Line 1455 of yacc.c  */
#line 2610 "hphp.y"
    { _p->onAListVar((yyval),&(yyvsp[(1) - (2)]),NULL);;}
    break;

  case 784:

/* Line 1455 of yacc.c  */
#line 2611 "hphp.y"
    { _p->onAListVar((yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 785:

/* Line 1455 of yacc.c  */
#line 2613 "hphp.y"
    { _p->onAListSub((yyval),&(yyvsp[(1) - (6)]),(yyvsp[(5) - (6)]));;}
    break;

  case 786:

/* Line 1455 of yacc.c  */
#line 2614 "hphp.y"
    { _p->onAListVar((yyval),NULL,NULL);;}
    break;

  case 787:

/* Line 1455 of yacc.c  */
#line 2615 "hphp.y"
    { _p->onAListVar((yyval),NULL,&(yyvsp[(1) - (1)]));;}
    break;

  case 788:

/* Line 1455 of yacc.c  */
#line 2616 "hphp.y"
    { _p->onAListSub((yyval),NULL,(yyvsp[(3) - (4)]));;}
    break;

  case 789:

/* Line 1455 of yacc.c  */
#line 2621 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 790:

/* Line 1455 of yacc.c  */
#line 2622 "hphp.y"
    { (yyval).reset();;}
    break;

  case 791:

/* Line 1455 of yacc.c  */
#line 2626 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0);;}
    break;

  case 792:

/* Line 1455 of yacc.c  */
#line 2627 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 793:

/* Line 1455 of yacc.c  */
#line 2628 "hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 794:

/* Line 1455 of yacc.c  */
#line 2629 "hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 795:

/* Line 1455 of yacc.c  */
#line 2632 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (6)]),&(yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]),1);;}
    break;

  case 796:

/* Line 1455 of yacc.c  */
#line 2634 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (4)]),  0,(yyvsp[(4) - (4)]),1);;}
    break;

  case 797:

/* Line 1455 of yacc.c  */
#line 2635 "hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),1);;}
    break;

  case 798:

/* Line 1455 of yacc.c  */
#line 2636 "hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(2) - (2)]),1);;}
    break;

  case 799:

/* Line 1455 of yacc.c  */
#line 2641 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 800:

/* Line 1455 of yacc.c  */
#line 2642 "hphp.y"
    { _p->onEmptyCollection((yyval));;}
    break;

  case 801:

/* Line 1455 of yacc.c  */
#line 2646 "hphp.y"
    { _p->onCollectionPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 802:

/* Line 1455 of yacc.c  */
#line 2647 "hphp.y"
    { _p->onCollectionPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]));;}
    break;

  case 803:

/* Line 1455 of yacc.c  */
#line 2648 "hphp.y"
    { _p->onCollectionPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 804:

/* Line 1455 of yacc.c  */
#line 2649 "hphp.y"
    { _p->onCollectionPair((yyval),  0,  0,(yyvsp[(1) - (1)]));;}
    break;

  case 805:

/* Line 1455 of yacc.c  */
#line 2654 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 806:

/* Line 1455 of yacc.c  */
#line 2655 "hphp.y"
    { _p->onEmptyCollection((yyval));;}
    break;

  case 807:

/* Line 1455 of yacc.c  */
#line 2660 "hphp.y"
    { _p->onCollectionPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 808:

/* Line 1455 of yacc.c  */
#line 2662 "hphp.y"
    { _p->onCollectionPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]));;}
    break;

  case 809:

/* Line 1455 of yacc.c  */
#line 2664 "hphp.y"
    { _p->onCollectionPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 810:

/* Line 1455 of yacc.c  */
#line 2665 "hphp.y"
    { _p->onCollectionPair((yyval),  0,  0,(yyvsp[(1) - (1)]));;}
    break;

  case 811:

/* Line 1455 of yacc.c  */
#line 2669 "hphp.y"
    { _p->addEncap((yyval), &(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), -1);;}
    break;

  case 812:

/* Line 1455 of yacc.c  */
#line 2671 "hphp.y"
    { _p->addEncap((yyval), &(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), 0);;}
    break;

  case 813:

/* Line 1455 of yacc.c  */
#line 2672 "hphp.y"
    { _p->addEncap((yyval), NULL, (yyvsp[(1) - (1)]), -1);;}
    break;

  case 814:

/* Line 1455 of yacc.c  */
#line 2674 "hphp.y"
    { _p->addEncap((yyval), NULL, (yyvsp[(1) - (2)]), 0);
                                         _p->addEncap((yyval), &(yyval), (yyvsp[(2) - (2)]), -1); ;}
    break;

  case 815:

/* Line 1455 of yacc.c  */
#line 2679 "hphp.y"
    { _p->onSimpleVariable((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 816:

/* Line 1455 of yacc.c  */
#line 2681 "hphp.y"
    { _p->encapRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 817:

/* Line 1455 of yacc.c  */
#line 2683 "hphp.y"
    { _p->encapObjProp((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 818:

/* Line 1455 of yacc.c  */
#line 2685 "hphp.y"
    { _p->onDynamicVariable((yyval), (yyvsp[(2) - (3)]), 1);;}
    break;

  case 819:

/* Line 1455 of yacc.c  */
#line 2687 "hphp.y"
    { _p->encapArray((yyval), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]));;}
    break;

  case 820:

/* Line 1455 of yacc.c  */
#line 2688 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 821:

/* Line 1455 of yacc.c  */
#line 2691 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_STRING;;}
    break;

  case 822:

/* Line 1455 of yacc.c  */
#line 2692 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_NUM_STRING;;}
    break;

  case 823:

/* Line 1455 of yacc.c  */
#line 2693 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_VARIABLE;;}
    break;

  case 824:

/* Line 1455 of yacc.c  */
#line 2697 "hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_ISSET,1);;}
    break;

  case 825:

/* Line 1455 of yacc.c  */
#line 2698 "hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_EMPTY,1);;}
    break;

  case 826:

/* Line 1455 of yacc.c  */
#line 2699 "hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),'!',1);;}
    break;

  case 827:

/* Line 1455 of yacc.c  */
#line 2700 "hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),'!',1);;}
    break;

  case 828:

/* Line 1455 of yacc.c  */
#line 2701 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INCLUDE,1);;}
    break;

  case 829:

/* Line 1455 of yacc.c  */
#line 2702 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INCLUDE_ONCE,1);;}
    break;

  case 830:

/* Line 1455 of yacc.c  */
#line 2703 "hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_EVAL,1);;}
    break;

  case 831:

/* Line 1455 of yacc.c  */
#line 2704 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_REQUIRE,1);;}
    break;

  case 832:

/* Line 1455 of yacc.c  */
#line 2705 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_REQUIRE_ONCE,1);;}
    break;

  case 833:

/* Line 1455 of yacc.c  */
#line 2709 "hphp.y"
    { _p->onExprListElem((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 834:

/* Line 1455 of yacc.c  */
#line 2710 "hphp.y"
    { _p->onExprListElem((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 835:

/* Line 1455 of yacc.c  */
#line 2715 "hphp.y"
    { _p->onClassConst((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0);;}
    break;

  case 836:

/* Line 1455 of yacc.c  */
#line 2717 "hphp.y"
    { _p->onClassClass((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0);;}
    break;

  case 839:

/* Line 1455 of yacc.c  */
#line 2731 "hphp.y"
    { (yyvsp[(2) - (5)]).setText(_p->nsDecl((yyvsp[(2) - (5)]).text()));
                                         _p->onTypedef((yyval), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                                         _p->popTypeScope(); ;}
    break;

  case 840:

/* Line 1455 of yacc.c  */
#line 2735 "hphp.y"
    { (yyvsp[(2) - (6)]).setText(_p->nsDecl((yyvsp[(2) - (6)]).text()));
                                         _p->onTypedef((yyval), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
                                         _p->popTypeScope(); ;}
    break;

  case 841:

/* Line 1455 of yacc.c  */
#line 2741 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 842:

/* Line 1455 of yacc.c  */
#line 2742 "hphp.y"
    { only_in_hh_syntax(_p); (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 843:

/* Line 1455 of yacc.c  */
#line 2748 "hphp.y"
    { _p->pushTypeScope(); (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 844:

/* Line 1455 of yacc.c  */
#line 2752 "hphp.y"
    { _p->pushTypeScope(); (yyval) = (yyvsp[(1) - (4)]); ;}
    break;

  case 845:

/* Line 1455 of yacc.c  */
#line 2758 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 846:

/* Line 1455 of yacc.c  */
#line 2759 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 847:

/* Line 1455 of yacc.c  */
#line 2763 "hphp.y"
    { Token t; t.reset();
                                         _p->onTypeList((yyvsp[(1) - (1)]), t);
                                         (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 848:

/* Line 1455 of yacc.c  */
#line 2766 "hphp.y"
    { _p->onTypeList((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                                         (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 849:

/* Line 1455 of yacc.c  */
#line 2772 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 850:

/* Line 1455 of yacc.c  */
#line 2777 "hphp.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 851:

/* Line 1455 of yacc.c  */
#line 2778 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 852:

/* Line 1455 of yacc.c  */
#line 2779 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 853:

/* Line 1455 of yacc.c  */
#line 2780 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 854:

/* Line 1455 of yacc.c  */
#line 2784 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 855:

/* Line 1455 of yacc.c  */
#line 2785 "hphp.y"
    { only_in_hh_syntax(_p); (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 856:

/* Line 1455 of yacc.c  */
#line 2790 "hphp.y"
    { _p->addTypeVar((yyvsp[(3) - (3)]).text()); ;}
    break;

  case 857:

/* Line 1455 of yacc.c  */
#line 2791 "hphp.y"
    { _p->addTypeVar((yyvsp[(1) - (1)]).text()); ;}
    break;

  case 858:

/* Line 1455 of yacc.c  */
#line 2793 "hphp.y"
    { _p->addTypeVar((yyvsp[(3) - (5)]).text()); ;}
    break;

  case 859:

/* Line 1455 of yacc.c  */
#line 2794 "hphp.y"
    { _p->addTypeVar((yyvsp[(1) - (3)]).text()); ;}
    break;

  case 860:

/* Line 1455 of yacc.c  */
#line 2800 "hphp.y"
    { validate_shape_keyname((yyvsp[(1) - (3)]), _p); ;}
    break;

  case 861:

/* Line 1455 of yacc.c  */
#line 2805 "hphp.y"
    { ;}
    break;

  case 864:

/* Line 1455 of yacc.c  */
#line 2817 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 865:

/* Line 1455 of yacc.c  */
#line 2819 "hphp.y"
    {;}
    break;

  case 866:

/* Line 1455 of yacc.c  */
#line 2823 "hphp.y"
    { (yyval).setText("array"); ;}
    break;

  case 867:

/* Line 1455 of yacc.c  */
#line 2830 "hphp.y"
    { only_in_hh_syntax(_p);
                                         _p->onTypeSpecialization((yyvsp[(2) - (2)]), '?');
                                         (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 868:

/* Line 1455 of yacc.c  */
#line 2833 "hphp.y"
    { only_in_hh_syntax(_p);
                                         _p->onTypeSpecialization((yyvsp[(2) - (2)]), '@');
                                         (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 869:

/* Line 1455 of yacc.c  */
#line 2836 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 870:

/* Line 1455 of yacc.c  */
#line 2837 "hphp.y"
    { Token t; t.reset();
                                         (yyvsp[(1) - (1)]).setText("array");
                                         _p->onTypeAnnotation((yyval), (yyvsp[(1) - (1)]), t); ;}
    break;

  case 871:

/* Line 1455 of yacc.c  */
#line 2840 "hphp.y"
    { Token t; t.reset();
                                         (yyvsp[(1) - (1)]).setText("callable");
                                         _p->onTypeAnnotation((yyval), (yyvsp[(1) - (1)]), t); ;}
    break;

  case 872:

/* Line 1455 of yacc.c  */
#line 2843 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 873:

/* Line 1455 of yacc.c  */
#line 2845 "hphp.y"
    { (yyvsp[(1) - (4)]).setText("array");
                                         _p->onTypeAnnotation((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); ;}
    break;

  case 874:

/* Line 1455 of yacc.c  */
#line 2848 "hphp.y"
    { _p->onTypeList((yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
                                         (yyvsp[(1) - (6)]).setText("array");
                                         _p->onTypeAnnotation((yyval), (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)])); ;}
    break;

  case 875:

/* Line 1455 of yacc.c  */
#line 2851 "hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel();
                                         Token t; t.reset();
                                         _p->onTypeAnnotation((yyval), (yyvsp[(1) - (1)]), t);
                                         _p->onTypeSpecialization((yyval), 'x'); ;}
    break;

  case 876:

/* Line 1455 of yacc.c  */
#line 2857 "hphp.y"
    { only_in_hh_syntax(_p);
                                        _p->onTypeList((yyvsp[(7) - (8)]), (yyvsp[(4) - (8)]));
                                        _p->onTypeAnnotation((yyval), (yyvsp[(2) - (8)]), (yyvsp[(7) - (8)]));
                                        _p->onTypeSpecialization((yyval), 'f'); ;}
    break;

  case 877:

/* Line 1455 of yacc.c  */
#line 2863 "hphp.y"
    { only_in_hh_syntax(_p);
                                        _p->onTypeList((yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]));
                                        Token t; t.reset(); t.setText("array");
                                        _p->onTypeAnnotation((yyval), t, (yyvsp[(2) - (6)]));
                                        _p->onTypeSpecialization((yyval), 't'); ;}
    break;

  case 878:

/* Line 1455 of yacc.c  */
#line 2871 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 879:

/* Line 1455 of yacc.c  */
#line 2872 "hphp.y"
    { (yyval).reset(); ;}
    break;



/* Line 1455 of yacc.c  */
#line 13004 "hphp.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, _p, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (&yylloc, _p, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, _p, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, _p);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, _p);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, _p, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, _p);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, _p);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
  YYSTACK_CLEANUP;
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2875 "hphp.y"

bool Parser::parseImpl() {
  return yyparse(this) == 0;
}

