/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2014 Facebook, Inc. (http://www.facebook.com)     |
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

#ifndef incl_HPHP_COMPILER_GENERATION_LABEL_H
#define incl_HPHP_COMPILER_GENERATION_LABEL_H

namespace HPHP {

class Expression;

class GenerationLabel {
 public:
  explicit GenerationLabel(Expression* e);

  int id() const;
  void setNew();
  void setExpression(Expression* e);

 private:
  int m_id;
  int m_generation;
  Expression* m_owner;
};

}

#endif
