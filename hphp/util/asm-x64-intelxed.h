/*
   +----------------------------------------------------------------------+
   | INTEL CONFIDENTIAL                                                   |
   | Copyright (c) 2018 Intel Corporation                                 |
   +----------------------------------------------------------------------+
   | This software and the related documents are Intel copyrighted        |
   | materials, and your use of them is governed by the express license   |
   | under which they were provided to you (License).                     |
   | Unless the License provides otherwise, you may not use, modify, copy,|
   | publish, distribute, disclose or transmit this software or the       |
   | related documents without Intel's prior written permission.          |
   | This software and the related documents are provided as is, with no  |
   | express or implied warranties, other than those that are expressly   |
   | stated in the License.                                               |
   +----------------------------------------------------------------------+
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
#ifndef incl_HPHP_UTIL_ASM_X64_INTELXED_H_
#define incl_HPHP_UTIL_ASM_X64_INTELXED_H_

extern "C" {
    #include <xed-interface.h>
}
/*
 * A macro assembler for x64, based on the Intel XED library, that strives
 * for low coupling to the runtime environment and ease of extendability.
 */
namespace HPHP { namespace jit {

struct XedInit {
  XedInit() {
      xed_tables_init();
  }
};

// *(reg + x)
struct MemoryRef {
  /*
   * The default value of MemoryRef::segment should be XED_REG_DS, but Xed fails
   * to encode lea(r, m) if the value of m.segment is not XED_REG_INVALID.
   * XED_RED_INVALID is a safe default value for m.segment, it will produce
   * the same output as assigning it XED_REG_DS when emitting all other
   * instructions and it will also work for lea(r ,m).
   */
  explicit MemoryRef(DispReg dr) : r(dr), segment(XED_REG_INVALID) {}
  explicit MemoryRef(IndexedDispReg idr) : r(idr),
                                           segment(XED_REG_INVALID) {}
  IndexedDispReg r;
  xed_reg_enum_t segment;
  void fs() { segment = XED_REG_FS; }
  void gs() { segment = XED_REG_GS; }
};

//////////////////////////////////////////////////////////////////////

#define SZ_TO_BITS(sz)                    (sz << 3)
#define BITS_TO_SZ(bits)                  (bits >> 3)

typedef bool(*immFitFunc)(int64_t, int);
#define IMMFITFUNC_SIGNED                 deltaFits
#define IMMFITFUNC_UNSIGNED               (immFitFunc) magFits

struct XedOperand
{
  xed_encoder_operand_t op;

  union xed_imm_value {
    int8_t    b;
    uint8_t   ub;
    int16_t   w;
    int32_t   l;
    int64_t   q;
    uint64_t uq;

    template<typename immtype>
    xed_imm_value(const immtype& imm, int immSize) {
      uq = 0;
      switch(immSize) {
        case sz::byte:
          b = imm.b(); break;
        case sz::word:
          w = imm.w(); break;
        case sz::dword:
          l = imm.l(); break;
        case sz::qword:
          q = imm.q();
      }
    }
  };

  inline xed_reg_enum_t xedFromReg (const Reg64& reg) {
    return xed_reg_enum_t(int(reg) + XED_REG_RAX);
  }

  inline xed_reg_enum_t xedFromReg (const Reg32& reg) {
    return xed_reg_enum_t(int(reg) + XED_REG_EAX);
  }

  inline xed_reg_enum_t xedFromReg (const Reg16& reg) {
    return xed_reg_enum_t(int(reg) + XED_REG_AX);
  }

  inline xed_reg_enum_t xedFromReg (const Reg8& reg) {
    int regid = int(reg);
    if((regid & 0x80) == 0) {
      return xed_reg_enum_t(regid + XED_REG_AL);
    }
    return xed_reg_enum_t((regid - 0x84) + XED_REG_AH);
  }

  inline xed_reg_enum_t xedFromReg (const RegXMM& reg) {
    return xed_reg_enum_t(int(reg) + XED_REG_XMM0);
  }

  xed_enc_displacement_t xedDispFromValue(intptr_t value) {
    if (value == 0) {
      return {0, 0};
    }
    if(deltaFits(value, sz::byte)) {
       return {(xed_uint64_t)safe_cast<int8_t>(value), SZ_TO_BITS(sz::byte)};
    }
    return {(xed_uint64_t)safe_cast<int32_t>(value), SZ_TO_BITS(sz::dword)};
  }

  xed_enc_displacement_t xedDispFromValue(intptr_t value, int64_t offset) {
    return xedDispFromValue(value - offset);
  }

  template<typename regtype>
  explicit XedOperand(const regtype& reg) {
    op = xed_reg(xedFromReg(reg));
  }

  explicit XedOperand(xed_reg_enum_t reg) {
    op = xed_reg(reg);
  }

  explicit XedOperand(const MemoryRef& m, int memSize) {
    xed_reg_enum_t base = (int(m.r.base) != -1 ?
                            xedFromReg(m.r.base) : XED_REG_INVALID);
    xed_reg_enum_t index = (int(m.r.index) != -1 ?
                            xedFromReg(m.r.index) : XED_REG_INVALID);
    op = xed_mem_gbisd(m.segment, base, index, m.r.scale,
                       xedDispFromValue(m.r.disp), SZ_TO_BITS(memSize));
  }

  explicit XedOperand(const RIPRelativeRef& r, int memSize, int64_t offset) {
    op = xed_mem_bd(XED_REG_RIP, xedDispFromValue(r.r.disp, offset),
                    SZ_TO_BITS(memSize));
  }

  template<typename immtype>
  explicit XedOperand(const immtype& immed, int immSize) {
    op = xed_imm0(xed_imm_value(immed, immSize).uq, SZ_TO_BITS(immSize));
  }

  explicit XedOperand(CodeAddress address, int size) {
    int64_t target = (int64_t)address;
    assert(deltaFits(target, size) &&
           "Relative address doesn't fit selected size");
    op = xed_relbr((int32_t)target, SZ_TO_BITS(size));
  }

  template<typename immtype>
  explicit XedOperand(const immtype& immed, int immSizes, immFitFunc func) {
    immSizes = reduceImmSize(immed.q(), immSizes, func);
    op = xed_imm0(xed_imm_value(immed, immSizes).uq, SZ_TO_BITS(immSizes));
  }

  inline int reduceImmSize(int64_t value, int allowedSizes, immFitFunc func) {
    for (int crtSize = sz::byte; crtSize < sz::qword; crtSize <<= 1) {
      if((allowedSizes & crtSize) && (*func)(value, crtSize))
        return crtSize;
      }
    assert((allowedSizes & sz::qword) &&
           "Could not find an optimal size for Immed");
    return sz::qword;
  }
};

#define XED_REG(reg)                      XedOperand(reg).op
#define XED_IMM(imm, size)                XedOperand(imm, size).op
#define XED_IMM_RED(imm, sizes, redfunc)  XedOperand(imm, sizes, redfunc).op
#define XED_MEMREF(m, size)               XedOperand(m, size).op
#define XED_MEMREF_RIP(m, size, offset)   XedOperand(m, size, offset).op
#define XED_BRREL(p, size)                XedOperand((CodeAddress)p, size).op

///////////////////////////////////////////////////////////////////////////////

struct Label;

/**
 * Copyright (c) 2009, Andrew J. Paroski
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The names of the contributors may not be used to endorse or promote
 *       products derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL ANDREW J. PAROSKI BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

struct X64Assembler {
private:
  friend struct Label;

  /*
   * Type for register numbers, independent of the size we're going to
   * be using it as. Also, the same register number may mean different
   * physical registers for different instructions (e.g. xmm0 and rax
   * are both 0). Only for internal use in X64Assembler.
   */
  enum class RegNumber : int {};
  static const RegNumber noreg = RegNumber(-1);

  constexpr static xed_state_t s_xedState = {
        XED_MACHINE_MODE_LONG_64,
        XED_ADDRESS_WIDTH_64b
  };

public:
  explicit X64Assembler(CodeBlock& cb) : codeBlock(cb) {}

  X64Assembler(const X64Assembler&) = delete;
  X64Assembler& operator=(const X64Assembler&) = delete;

  CodeBlock& code() const { return codeBlock; }

  CodeAddress base() const {
    return codeBlock.base();
  }

  CodeAddress frontier() const {
    return codeBlock.frontier();
  }

  CodeAddress toDestAddress(CodeAddress addr) const {
    return codeBlock.toDestAddress(addr);
  }

  void setFrontier(CodeAddress newFrontier) {
    codeBlock.setFrontier(newFrontier);
  }

  size_t capacity() const {
    return codeBlock.capacity();
  }

  size_t used() const {
    return codeBlock.used();
  }

  size_t available() const {
    return codeBlock.available();
  }

  bool contains(CodeAddress addr) const {
    return codeBlock.contains(addr);
  }

  bool empty() const {
    return codeBlock.empty();
  }

  void clear() {
    codeBlock.clear();
  }

  bool canEmit(size_t nBytes) const {
    assert(capacity() >= used());
    return nBytes < (capacity() - used());
  }

  /*
   * The following section defines the main interface for emitting
   * x64.
   *
   * Simple Examples:
   *
   *   a.  movq   (rax, rbx);       // order is AT&T: src, dest
   *   a.  loadq  (*rax, rbx);      // loads from *rax
   *   a.  loadq  (rax[0], rbx);    // also loads from *rax
   *   a.  storeq (rcx, rax[0xc]);  // store to rax + 0xc
   *   a.  addq   (0x1, rbx);       // increment rbx
   *
   * Addressing with index registers:
   *
   *   a.  movl   (index, ecx);
   *   a.  loadq  (*rax, rbx);
   *   a.  storeq (rbx, rbx[rcx*8]);
   *   a.  call   (rax);            // indirect call
   *
   */
#define XED_INVERSE(x, y)   y, x

#define BYTE_LOAD_OP(name, instr)                                     \
  void name##b(MemoryRef m, Reg8 r)     { xedInstrMR(instr, m, r); }

#define LOAD_OP(name, instr)                                          \
  void name##q(MemoryRef m, Reg64 r) { xedInstrMR(instr, m, r); }     \
  void name##l(MemoryRef m, Reg32 r) { xedInstrMR(instr, m, r); }     \
  void name##w(MemoryRef m, Reg16 r) { xedInstrMR(instr, m, r); }     \
  void name##q(RIPRelativeRef m, Reg64 r) { xedInstrMR(instr, m, r); }\
  BYTE_LOAD_OP(name, instr)

#define BYTE_STORE_OP(name, instr)                                    \
  void name##b(Reg8 r, MemoryRef m)  { xedInstrRM(instr, r, m); }     \
  void name##b(Immed i, MemoryRef m) { xedInstrIM(instr, i, m,        \
                                                  sz::byte); }

#define STORE_OP(name, instr)                                         \
  void name##w(Immed i, MemoryRef m) {                                \
    xedInstrIM(instr, i, m, IMMPROP(sz::word,                         \
                                    sz::word | sz::byte,              \
                                    IMMFITFUNC_SIGNED), sz::word);    \
  }                                                                   \
  void name##l(Immed i, MemoryRef m) {                                \
    xedInstrIM(instr, i, m, IMMPROP(sz::dword,                        \
                                    sz::dword | sz::byte,             \
                                    IMMFITFUNC_SIGNED), sz::dword);   \
  }                                                                   \
  void name##w(Reg16 r, MemoryRef m) { xedInstrRM(instr, r, m); }     \
  void name##l(Reg32 r, MemoryRef m) { xedInstrRM(instr, r, m); }     \
  void name##q(Reg64 r, MemoryRef m) { xedInstrRM(instr, r, m); }     \
  BYTE_STORE_OP(name, instr)

#define BYTE_REG_OP(name, instr)                                      \
  void name##b(Reg8 r1, Reg8 r2) { xedInstrRR(instr, r1, r2);}        \
  void name##b(Immed i, Reg8 r)  { xedInstrIR(instr, i, r); }

#define REG_OP(name, instr)                                           \
  void name##q(Reg64 r1, Reg64 r2)   { xedInstrRR(instr, r1, r2); }   \
  void name##l(Reg32 r1, Reg32 r2)   { xedInstrRR(instr, r1, r2); }   \
  void name##w(Reg16 r1, Reg16 r2)   { xedInstrRR(instr, r1, r2); }   \
  void name##l(Immed i, Reg32 r) {                                    \
    xedInstrIR(instr, i, r, IMMPROP(sz::dword,                        \
                                    sz::dword | sz::byte,             \
                                    IMMFITFUNC_SIGNED));              \
  }                                                                   \
  void name##w(Immed i, Reg16 r) {                                    \
    xedInstrIR(instr, i, r, IMMPROP(sz::word,                         \
                                    sz::word | sz::byte,              \
                                    IMMFITFUNC_SIGNED));              \
  }                                                                   \
  BYTE_REG_OP(name, instr)

#define IMM64_STORE_OP(name, instr)                                   \
  void name##q(Immed i, MemoryRef m) {                                \
    xedInstrIM(instr, i, m, IMMPROP(sz::dword,                        \
                                    sz::dword | sz::byte,             \
                                    IMMFITFUNC_SIGNED), sz::qword);   \
  }

#define IMM64R_OP(name, instr)                                        \
  void name##q(Immed imm, Reg64 r) {                                  \
    always_assert(imm.fits(sz::dword));                               \
    xedInstrIR(instr, imm, r, IMMPROP(sz::dword,                      \
                                      sz::dword | sz::byte,           \
                                      IMMFITFUNC_SIGNED));            \
  }

#define FULL_OP(name, instr)                                          \
  LOAD_OP(name, instr)                                                \
  STORE_OP(name, instr)                                               \
  REG_OP(name, instr)                                                 \
  IMM64_STORE_OP(name, instr)                                         \
  IMM64R_OP(name, instr)

  // We rename x64's mov to store and load for improved code
  // readability.
#define IMMPROP(size, allsizes, func) size
  LOAD_OP        (load, XED_ICLASS_MOV)
  STORE_OP       (store,XED_ICLASS_MOV)
  IMM64_STORE_OP (store,XED_ICLASS_MOV)
  REG_OP         (mov,  XED_ICLASS_MOV)
  FULL_OP        (test, XED_ICLASS_TEST)
#undef IMMPROP

#define IMMPROP(size, allsizes, func) allsizes, func
  FULL_OP(add, XED_ICLASS_ADD)
  FULL_OP(xor, XED_ICLASS_XOR)
  FULL_OP(sub, XED_ICLASS_SUB)
  FULL_OP(and, XED_ICLASS_AND)
  FULL_OP(or,  XED_ICLASS_OR)
  FULL_OP(cmp, XED_ICLASS_CMP)
  FULL_OP(sbb, XED_ICLASS_SBB)
#undef IMMPROP

#undef IMM64_OP
#undef IMM64R_OP
#undef FULL_OP
#undef REG_OP
#undef STORE_OP
#undef LOAD_OP
#undef BYTE_LOAD_OP
#undef BYTE_STORE_OP
#undef BYTE_REG_OP

  // 64-bit immediates work with mov to a register.
  void movq(Immed64 imm, Reg64 r) { xedInstrIR(XED_ICLASS_MOV, imm, r); }

  // movzbx is a special snowflake. We don't have movzbq because it behaves
  // exactly the same as movzbl but takes an extra byte.
  void loadzbl(MemoryRef m, Reg32 r)        { xedInstrMR(XED_ICLASS_MOVZX,
                                                         m, r, sz::byte); }
  void movzbl(Reg8 src, Reg32 dest)         { xedInstrRR(XED_ICLASS_MOVZX,
                                                         src, dest); }
  void movsbl(Reg8 src, Reg32 dest)         { xedInstrRR(XED_ICLASS_MOVSX,
                                                         src, dest); }
  void movzwl(Reg16 src, Reg32 dest)        { xedInstrRR(XED_ICLASS_MOVZX,
                                                         src, dest); }

  void loadsbq(MemoryRef m, Reg64 r)        { xedInstrMR(XED_ICLASS_MOVSX,
                                                         m, r); }
  void movsbq(Reg8 src, Reg64 dest)         { xedInstrRR(XED_ICLASS_MOVSX,
                                                         src, dest); }

  void lea(MemoryRef p, Reg64 reg)       { xedInstrMR(XED_ICLASS_LEA, p, reg); }
  void lea(RIPRelativeRef p, Reg64 reg)  { xedInstrMR(XED_ICLASS_LEA, p, reg); }

  void xchgq(Reg64 r1, Reg64 r2) { xedInstrRR(XED_ICLASS_XCHG, r1, r2); }
  void xchgl(Reg32 r1, Reg32 r2) { xedInstrRR(XED_ICLASS_XCHG, r1, r2); }
  void xchgb(Reg8 r1, Reg8 r2)   { xedInstrRR(XED_ICLASS_XCHG, r1, r2); }

  void imul(Reg64 r1, Reg64 r2)  { xedInstrRR(XED_ICLASS_IMUL, r1, r2); }

  void push(Reg64 r)  { xedInstrR(XED_ICLASS_PUSH,  r); }
  void pushl(Reg32 r) { xedInstrR(XED_ICLASS_PUSH,  r); }
  void pop (Reg64 r)  { xedInstrR(XED_ICLASS_POP,   r); }
  void idiv(Reg64 r)  { xedInstrR(XED_ICLASS_IDIV,  r); }
  void incq(Reg64 r)  { xedInstrR(XED_ICLASS_INC,   r); }
  void incl(Reg32 r)  { xedInstrR(XED_ICLASS_INC,   r); }
  void incw(Reg16 r)  { xedInstrR(XED_ICLASS_INC,   r); }
  void decq(Reg64 r)  { xedInstrR(XED_ICLASS_DEC,   r); }
  void decl(Reg32 r)  { xedInstrR(XED_ICLASS_DEC,   r); }
  void decw(Reg16 r)  { xedInstrR(XED_ICLASS_DEC,   r); }
  void notb(Reg8 r)   { xedInstrR(XED_ICLASS_NOT,   r); }
  void not(Reg64 r)   { xedInstrR(XED_ICLASS_NOT,   r); }
  void neg(Reg64 r)   { xedInstrR(XED_ICLASS_NEG,   r); }
  void negb(Reg8 r)   { xedInstrR(XED_ICLASS_NEG,   r); }
  void ret()          { xedInstr(XED_ICLASS_RET_NEAR); }
  void ret(Immed i)   { xedInstrI(XED_ICLASS_IRET, i,
                                                    sz::word); }
  void cqo()          { xedInstr(XED_ICLASS_CQO); }
  void nop()          { xedInstr(XED_ICLASS_NOP,    sz::byte); }
  void int3()         { xedInstr(XED_ICLASS_INT3,   sz::byte); }
  void ud2()          { xedInstr(XED_ICLASS_UD2,    sz::byte); }
  void pushf()        { xedInstr(XED_ICLASS_PUSHF,  sz::word); }
  void popf()         { xedInstr(XED_ICLASS_POPF,   sz::word); }
  void lock()         { assert(false); }

  void push(MemoryRef m)      { xedInstrM(XED_ICLASS_PUSH,m); }
  void pop (MemoryRef m)      { xedInstrM(XED_ICLASS_POP, m); }
  void incq(MemoryRef m)      { xedInstrM(XED_ICLASS_INC, m); }
  void incl(MemoryRef m)      { xedInstrM(XED_ICLASS_INC, m, sz::dword); }
  void incw(MemoryRef m)      { xedInstrM(XED_ICLASS_INC, m, sz::word); }
  void decqlock(MemoryRef m)  { xedInstrM(XED_ICLASS_DEC_LOCK, m); }
  void decq(MemoryRef m)      { xedInstrM(XED_ICLASS_DEC, m); }
  void decl(MemoryRef m)      { xedInstrM(XED_ICLASS_DEC, m, sz::dword); }
  void decw(MemoryRef m)      { xedInstrM(XED_ICLASS_DEC, m, sz::word); }

  //special case for push(imm)
  void push(Immed64 i) {
    XedOperand oper(i, sz::byte | sz::word | sz::dword, IMMFITFUNC_SIGNED);
    xedEmit1(XED_ICLASS_PUSH, oper.op, oper.op.width_bits < 32 ? 16 : 64);
  }

  void movups(RegXMM x, MemoryRef m)        { xedInstrRM(XED_ICLASS_MOVUPS,
                                                         x, m, sz::qword * 2); }
  void movups(MemoryRef m, RegXMM x)        { xedInstrMR(XED_ICLASS_MOVUPS,
                                                         m, x, sz::qword * 2); }
  void movdqu(RegXMM x, MemoryRef m)        { xedInstrRM(XED_ICLASS_MOVDQU,
                                                         x, m); }
  void movdqu(MemoryRef m, RegXMM x)        { xedInstrMR(XED_ICLASS_MOVDQU,
                                                         m, x); }
  void movdqa(RegXMM x, RegXMM y)           { xedInstrRR(XED_ICLASS_MOVDQA,
                                                         XED_INVERSE(x, y)); }
  void movdqa(RegXMM x, MemoryRef m)        { xedInstrRM(XED_ICLASS_MOVDQA,
                                                         x, m); }
  void movdqa(MemoryRef m, RegXMM x)        { xedInstrMR(XED_ICLASS_MOVDQA,
                                                         m, x); }
  void movsd (RegXMM x, RegXMM y)           { xedInstrRR(XED_ICLASS_MOVSD_XMM,
                                                         XED_INVERSE(x, y)); }
  void movsd (RegXMM x, MemoryRef m)        { xedInstrRM(XED_ICLASS_MOVSD_XMM,
                                                         x, m); }
  void movsd (MemoryRef m, RegXMM x)        { xedInstrMR(XED_ICLASS_MOVSD_XMM,
                                                         m, x); }
  void movsd (RIPRelativeRef m, RegXMM x)   { xedInstrMR(XED_ICLASS_MOVSD_XMM,
                                                         m, x); }
  void lddqu (MemoryRef m, RegXMM x)        { xedInstrMR(XED_ICLASS_LDDQU,
                                                         m, x); }
  void unpcklpd(RegXMM s, RegXMM d)         { xedInstrRR(XED_ICLASS_UNPCKLPD,
                                                         XED_INVERSE(s, d)); }

  void rorq  (Immed i, Reg64 r) { xedInstrIR(XED_ICLASS_ROR, i, r, sz::byte); }
  void shlq  (Immed i, Reg64 r) { xedInstrIR(XED_ICLASS_SHL, i, r, sz::byte); }
  void shrq  (Immed i, Reg64 r) { xedInstrIR(XED_ICLASS_SHR, i, r, sz::byte); }
  void sarq  (Immed i, Reg64 r) { xedInstrIR(XED_ICLASS_SAR, i, r, sz::byte); }
  void shll  (Immed i, Reg32 r) { xedInstrIR(XED_ICLASS_SHL, i, r, sz::byte); }
  void shrl  (Immed i, Reg32 r) { xedInstrIR(XED_ICLASS_SHR, i, r, sz::byte); }
  void shlw  (Immed i, Reg16 r) { xedInstrIR(XED_ICLASS_SHL, i, r, sz::byte); }
  void shrw  (Immed i, Reg16 r) { xedInstrIR(XED_ICLASS_SHR, i, r, sz::byte); }

  void shlq (Reg64 r) { xedInstrRR_CL(XED_ICLASS_SHL, r); }
  void shrq (Reg64 r) { xedInstrRR_CL(XED_ICLASS_SHR, r); }
  void sarq (Reg64 r) { xedInstrRR_CL(XED_ICLASS_SAR, r); }

  void roundsd (RoundDirection d, RegXMM src, RegXMM dst) {
    Immed i((int)d);
    xedInstrIRR(XED_ICLASS_ROUNDSD, dst, src, i, sz::byte);
  }

  void cmpsd(RegXMM src, RegXMM dst, ComparisonPred pred) {
    Immed i((int)pred);
    xedInstrIRR(XED_ICLASS_CMPSD_XMM, dst, src, i, sz::byte);
  }

  /*
   * Control-flow directives.  Primitive labeling/patching facilities
   * are available, as well as slightly higher-level ones via the
   * Label class.
   */

  bool jmpDeltaFits(CodeAddress dest) {
    int64_t delta = dest - (codeBlock.frontier() + 5);
    return deltaFits(delta, sz::dword);
  }

  void jmp(Reg64 r)            { xedInstrR(XED_ICLASS_JMP,        r); }
  void jmp(MemoryRef m)        { xedInstrM(XED_ICLASS_JMP,        m); }
  void jmp(RIPRelativeRef m)   { xedInstrM(XED_ICLASS_JMP,        m); }
  void call(Reg64 r)           { xedInstrR(XED_ICLASS_CALL_NEAR,  r); }
  void call(MemoryRef m)       { xedInstrM(XED_ICLASS_CALL_NEAR,  m); }
  void call(RIPRelativeRef m)  { xedInstrM(XED_ICLASS_CALL_NEAR,  m); }

  void jmp8(CodeAddress dest)  { xedInstrRelBr(XED_ICLASS_JMP,
                                               dest, sz::byte); }

  void jmp(CodeAddress dest) {
    xedInstrRelBr(XED_ICLASS_JMP, dest, sz::dword);
  }

  void call(CodeAddress dest) {
    xedInstrRelBr(XED_ICLASS_CALL_NEAR, dest, sz::dword);
  }

  void jcc(ConditionCode cond, CodeAddress dest) {
    xedInstrRelBr(ccToXedJump(cond), dest, sz::dword);
  }

  void jcc8(ConditionCode cond, CodeAddress dest) {
    xedInstrRelBr(ccToXedJump(cond), dest, sz::dword);
  }

  void jmpAuto(CodeAddress dest) {
    auto delta = dest - (codeBlock.frontier() + 2);
    if (deltaFits(delta, sz::byte)) {
      jmp8(dest);
    } else {
      jmp(dest);
    }
  }

  void jccAuto(ConditionCode cc, CodeAddress dest) {
    auto delta = dest - (codeBlock.frontier() + 2);
    if (deltaFits(delta, sz::byte)) {
      jcc8(cc, dest);
    } else {
      jcc(cc, dest);
    }
  }

  void call(Label&);
  void jmp(Label&);
  void jmp8(Label&);
  void jcc(ConditionCode, Label&);
  void jcc8(ConditionCode, Label&);

#define CCS \
  CC(o,   CC_O)         \
  CC(no,  CC_NO)        \
  CC(nae, CC_NAE)       \
  CC(ae,  CC_AE)        \
  CC(nb,  CC_NB)        \
  CC(e,   CC_E)         \
  CC(z,   CC_Z)         \
  CC(ne,  CC_NE)        \
  CC(nz,  CC_NZ)        \
  CC(b,   CC_B)         \
  CC(be,  CC_BE)        \
  CC(nbe, CC_NBE)       \
  CC(s,   CC_S)         \
  CC(ns,  CC_NS)        \
  CC(p,   CC_P)         \
  CC(np,  CC_NP)        \
  CC(nge, CC_NGE)       \
  CC(g,   CC_G)         \
  CC(l,   CC_L)         \
  CC(ge,  CC_GE)        \
  CC(nl,  CC_NL)        \
  CC(ng,  CC_NG)        \
  CC(le,  CC_LE)        \
  CC(nle, CC_NLE)

#define CC(_nm, _code)                                        \
  void j ## _nm(CodeAddress dest)      { jcc(_code, dest); }  \
  void j ## _nm ## 8(CodeAddress dest) { jcc8(_code, dest); } \
  void j ## _nm(Label&);                                      \
  void j ## _nm ## 8(Label&);
  CCS
#undef CC
  void setcc(int cc, Reg8 byteReg) {
    xedInstrR(ccToXedSetCC(cc), byteReg);
  }

#define CC(_nm, _cond)                          \
  void set ## _nm(Reg8 byteReg) {               \
    setcc(_cond, byteReg);                      \
  }
  CCS
#undef CC

  void psllq(Immed i, RegXMM r) { xedInstrIR(XED_ICLASS_PSLLQ, i, r,
                                             sz::byte); }
  void psrlq(Immed i, RegXMM r) { xedInstrIR(XED_ICLASS_PSRLQ, i, r,
                                             sz::byte); }

  void movq_rx(Reg64 rSrc, RegXMM rdest) {
    xedInstrRR(XED_ICLASS_MOVQ, XED_INVERSE(rdest, rSrc));
  }
  void movq_xr(RegXMM rSrc, Reg64 rdest) {
    xedInstrRR(XED_ICLASS_MOVQ, rSrc, rdest);
  }

  void addsd(RegXMM src, RegXMM srcdest) {
    xedInstrRR(XED_ICLASS_ADDSD, srcdest, src);
  }
  void mulsd(RegXMM src, RegXMM srcdest) {
    xedInstrRR(XED_ICLASS_MULSD, srcdest, src);
  }
  void subsd(RegXMM src, RegXMM srcdest) {
    xedInstrRR(XED_ICLASS_SUBSD, srcdest, src);
  }
  void pxor(RegXMM src, RegXMM srcdest) {
    xedInstrRR(XED_ICLASS_PXOR, srcdest, src);
  }
  void cvtsi2sd(Reg64 src, RegXMM dest) {
    xedInstrRR(XED_ICLASS_CVTSI2SD, XED_INVERSE(dest, src));
  }
  void cvtsi2sd(MemoryRef m, RegXMM dest) {
    xedInstrMR(XED_ICLASS_CVTSI2SD, m, dest);
  }
  void ucomisd(RegXMM l, RegXMM r) {
    xedInstrRR(XED_ICLASS_UCOMISD, l, r);
  }
  void sqrtsd(RegXMM src, RegXMM dest) {
    xedInstrRR(XED_ICLASS_SQRTSD, dest, src);
  }

  void divsd(RegXMM src, RegXMM srcdest) {
    xedInstrRR(XED_ICLASS_DIVSD, srcdest, src);
  }
  void cvttsd2siq(RegXMM src, Reg64 dest) {
    xedInstrRR(XED_ICLASS_CVTTSD2SI, XED_INVERSE(dest, src));
  }

  /*
   * The following utility functions do more than emit specific code.
   * (E.g. combine common idioms or patterns, smash code, etc.)
   */

  void emitImmReg(Immed64 imm, Reg64 dest) {
    if (imm.q() == 0) {
      // Zeros the top bits also.
      xorl  (r32(dest), r32(dest));
      return;
    }
    if (LIKELY(imm.q() > 0 && imm.fits(sz::dword))) {
      // This will zero out the high-order bits.
      movl (imm.l(), r32(dest));
      return;
    }
    movq (imm.q(), dest);
  }

  static void patchJcc(CodeAddress jmp, CodeAddress from, CodeAddress dest) {
    assert(jmp[0] == 0x0F && (jmp[1] & 0xF0) == 0x80);
    ssize_t diff = dest - (from + 6);
    *(int32_t*)(jmp + 2) = safe_cast<int32_t>(diff);
  }

  static void patchJcc8(CodeAddress jmp, CodeAddress from, CodeAddress dest) {
    assert((jmp[0] & 0xF0) == 0x70);
    ssize_t diff = dest - (from + 2);  // one for opcode, one for offset
    *(int8_t*)(jmp + 1) = safe_cast<int8_t>(diff);
  }

  static void patchJmp(CodeAddress jmp, CodeAddress from, CodeAddress dest) {
    assert(jmp[0] == 0xE9);
    ssize_t diff = dest - (from + 5);
    *(int32_t*)(jmp + 1) = safe_cast<int32_t>(diff);
  }

  static void patchJmp8(CodeAddress jmp, CodeAddress from, CodeAddress dest) {
    assert(jmp[0] == 0xEB);
    ssize_t diff = dest - (from + 2);  // one for opcode, one for offset
    *(int8_t*)(jmp + 1) = safe_cast<int8_t>(diff);
  }

  static void patchCall(CodeAddress call, CodeAddress from, CodeAddress dest) {
    assert(call[0] == 0xE8);
    ssize_t diff = dest - (from + 5);
    *(int32_t*)(call + 1) = safe_cast<int32_t>(diff);
  }

private:
  //Xed conversion funcs
#define CC_TO_XED_ARRAY(xed_instr) {                            \
    XED_ICLASS_##xed_instr##O,    /*CC_O                  */    \
    XED_ICLASS_##xed_instr##NO,   /*CC_NO                 */    \
    XED_ICLASS_##xed_instr##B,    /*CC_B, CC_NAE          */    \
    XED_ICLASS_##xed_instr##NB,   /*CC_AE, CC_NB, CC_NC   */    \
    XED_ICLASS_##xed_instr##Z,    /*CC_E, CC_Z            */    \
    XED_ICLASS_##xed_instr##NZ,   /*CC_NE, CC_NZ          */    \
    XED_ICLASS_##xed_instr##BE,   /*CC_BE, CC_NA          */    \
    XED_ICLASS_##xed_instr##NBE,  /*CC_A, CC_NBE          */    \
    XED_ICLASS_##xed_instr##S,    /*CC_S                  */    \
    XED_ICLASS_##xed_instr##NS,   /*CC_NS                 */    \
    XED_ICLASS_##xed_instr##P,    /*CC_P                  */    \
    XED_ICLASS_##xed_instr##NP,   /*CC_NP                 */    \
    XED_ICLASS_##xed_instr##L,    /*CC_L, CC_NGE          */    \
    XED_ICLASS_##xed_instr##NL,   /*CC_GE, CC_NL          */    \
    XED_ICLASS_##xed_instr##LE,   /*CC_LE, CC_NG          */    \
    XED_ICLASS_##xed_instr##NLE   /*CC_G, CC_NLE          */    \
  }

  ALWAYS_INLINE
  xed_iclass_enum_t ccToXedJump(ConditionCode c) {
    assert(c != CC_None);
    static xed_iclass_enum_t jumps[] = CC_TO_XED_ARRAY(J);
    return jumps[(int)c];
  }

  ALWAYS_INLINE
  xed_iclass_enum_t ccToXedSetCC(int c) {
    assert(c != -1);
    static xed_iclass_enum_t setccs[] = CC_TO_XED_ARRAY(SET);
    return setccs[c];
  }

  ALWAYS_INLINE
  xed_iclass_enum_t ccToXedCMov(ConditionCode c) {
    assert(c != CC_None);
    static xed_iclass_enum_t cmovs[] = CC_TO_XED_ARRAY(CMOV);
    return cmovs[(int)c];
  }

  //Xed Emit funcs

#define DECLARE_UNUSED(type, name)  type name; static_cast<void>(name)

#define XED_EMIT_BEGIN()                                                    \
  xed_encoder_instruction_t instruction;                                    \
  xed_encoder_request_t request;                                            \
  uint32_t encodedSize = 0;                                                 \
  DECLARE_UNUSED(xed_error_enum_t, xedError);                               \
  DECLARE_UNUSED(xed_bool_t, convert_ok)

#define XED_EMIT_ENCODE()                                                   \
  xed_encoder_request_zero(&request);                                       \
  convert_ok = xed_convert_to_encoder_request(&request, &instruction);      \
  assert(convert_ok);                                                       \
  xedError = xed_encode(&request, destination, XED_MAX_INSTRUCTION_BYTES,   \
                        &encodedSize)

#define XED_ASSERT_ERR(args)                                                \
  assert_flog(xedError == XED_ERROR_NONE,                                   \
              "XED: Error when encoding {}(" args ")"                       \
              "with effOpSize({}): {}",                                     \
              xed_iclass_enum_t2str(instr),                                 \
              effOperandSizeBits,                                           \
              xed_error_enum_t2str(xedError))

#define XED_UPDATE_CODEBLOCK(call)                                          \
  codeBlock.assertCanEmit(XED_MAX_INSTRUCTION_BYTES);                       \
  codeBlock.moveFrontier(call)

  ALWAYS_INLINE
  uint32_t xedEmit0(xed_iclass_enum_t instr,
                    xed_uint_t effOperandSizeBits,
                    CodeAddress destination) {
    XED_EMIT_BEGIN();
    xed_inst0(&instruction, s_xedState, instr, effOperandSizeBits);
    XED_EMIT_ENCODE();
    XED_ASSERT_ERR("");
    return encodedSize;
  }

  ALWAYS_INLINE
  void xedEmit0(xed_iclass_enum_t instr, xed_uint_t effOperandSizeBits = 0) {
    XED_UPDATE_CODEBLOCK(xedEmit0(instr, effOperandSizeBits, frontier()));
  }

  ALWAYS_INLINE
  uint32_t xedEmit1(xed_iclass_enum_t instr,
                        const xed_encoder_operand_t& op,
                        xed_uint_t effOperandSizeBits,
                        CodeAddress destination) {
    XED_EMIT_BEGIN();
    xed_inst1(&instruction, s_xedState, instr, effOperandSizeBits, op);
    XED_EMIT_ENCODE();
    XED_ASSERT_ERR("arg");
    return encodedSize;
  }

  ALWAYS_INLINE
  void xedEmit1(xed_iclass_enum_t instr, const xed_encoder_operand_t& op,
                    xed_uint_t effOperandSizeBits = 0) {
    XED_UPDATE_CODEBLOCK(xedEmit1(instr, op, effOperandSizeBits, frontier()));
  }

  ALWAYS_INLINE
  uint32_t xedEmit2(xed_iclass_enum_t instr,
                    const xed_encoder_operand_t& op_1,
                    const xed_encoder_operand_t& op_2,
                    xed_uint_t effOperandSizeBits,
                    CodeAddress destination) {
    XED_EMIT_BEGIN();
    xed_inst2(&instruction, s_xedState, instr, effOperandSizeBits, op_1, op_2);
    XED_EMIT_ENCODE();
    XED_ASSERT_ERR("arg, arg");
    return encodedSize;
  }

  ALWAYS_INLINE
  void xedEmit2(xed_iclass_enum_t instr, const xed_encoder_operand_t& op_1,
                const xed_encoder_operand_t& op_2,
                xed_uint_t effOperandSizeBits = 0) {
    XED_UPDATE_CODEBLOCK(xedEmit2(instr, op_1, op_2, effOperandSizeBits,
                         frontier()));
  }

  ALWAYS_INLINE
  uint32_t xedEmit3(xed_iclass_enum_t instr,
                    const xed_encoder_operand_t& op_1,
                    const xed_encoder_operand_t& op_2,
                    const xed_encoder_operand_t& op_3,
                    xed_uint_t effOperandSizeBits,
                    CodeAddress destination) {
    XED_EMIT_BEGIN();
    xed_inst3(&instruction, s_xedState, instr, effOperandSizeBits,
              op_1, op_2, op_3);
    XED_EMIT_ENCODE();
    XED_ASSERT_ERR("arg, arg, arg");
    return encodedSize;
  }

  ALWAYS_INLINE
  void xedEmit3(xed_iclass_enum_t instr,
                const xed_encoder_operand_t& op_1,
                const xed_encoder_operand_t& op_2,
                const xed_encoder_operand_t& op_3,
                xed_uint_t effOperandSizeBits = 0) {
    XED_UPDATE_CODEBLOCK(xedEmit3(instr, op_1, op_2, op_3, effOperandSizeBits,
                         frontier()));
  }

public:
  void emitInt3s(int n) {
    if (n == 0) return;
    static uint8_t instr = 0;
    static uint32_t int3size = xedEmit0(XED_ICLASS_INT3, sz::byte, &instr);
    static_cast<void> (int3size);
    assert(int3size == 1);
    for (auto i = 0; i < n; ++i) {
      byte(instr);
    }
  }

  void emitNop(int n) {
    if (n == 0) return;
    static const xed_iclass_enum_t nops[] = {
      XED_ICLASS_INVALID,
      XED_ICLASS_NOP,
      XED_ICLASS_NOP2,
      XED_ICLASS_NOP3,
      XED_ICLASS_NOP4,
      XED_ICLASS_NOP5,
      XED_ICLASS_NOP6,
      XED_ICLASS_NOP7,
      XED_ICLASS_NOP8,
      XED_ICLASS_NOP9,
    };
    // While n >= 9, emit 9 byte NOPs
    while (n >= 9) {
      xedInstr(XED_ICLASS_NOP9, 0);
      n -= 9;
    }
    // Emit remaining NOPs (if any)
    if(n) {
      xedInstr(nops[n], 0);
    }
  }

  void pad() {
    auto remaining = available();
    static uint32_t int3 = 0;
    static uint32_t ud2 = 0;
    static uint32_t int3_size = xedEmit0(XED_ICLASS_INT3, 0,
                                         (CodeAddress)&int3);
    static uint32_t ud2_size = xedEmit0(XED_ICLASS_UD2, 0,
                                        (CodeAddress)&ud2);
    while(remaining >= ud2_size) {
      bytes(ud2_size, (uint8_t*)&ud2);
      remaining -= ud2_size;
    }
    while(remaining >= int3_size) {
      bytes(int3_size, (uint8_t*)&int3);
      remaining -= int3_size;
    }
    assertx(available() == 0);
  }
  /*
   * Low-level emitter functions.
   *
   * These functions are the core of the assembler, and can also be
   * used directly.
   */

  void byte(uint8_t b) {
    codeBlock.byte(b);
  }
  void word(uint16_t w) {
    codeBlock.word(w);
  }
  void dword(uint32_t dw) {
    codeBlock.dword(dw);
  }
  void qword(uint64_t qw) {
    codeBlock.qword(qw);
  }
  void bytes(size_t n, const uint8_t* bs) {
    codeBlock.bytes(n, bs);
  }

public:
  /*
   * The following functions use a naming convention for an older API
   * to the assembler; conditional loads and moves haven't yet been
   * ported.
   */

  // CMOVcc [rbase + off], rdest
  inline void cload_reg64_disp_reg64(ConditionCode cc, Reg64 rbase,
                                     int off, Reg64 rdest) {
    MemoryRef m(DispReg(rbase, off));
    xedInstrMR(ccToXedCMov(cc), m, rdest);
  }
  inline void cload_reg64_disp_reg32(ConditionCode cc, Reg64 rbase,
                                     int off, Reg32 rdest) {
    MemoryRef m(DispReg(rbase, off));
    xedInstrMR(ccToXedCMov(cc), m, rdest);
  }
  inline void cmov_reg64_reg64(ConditionCode cc, Reg64 rsrc, Reg64 rdest) {
    xedInstrRR(ccToXedCMov(cc), rsrc, rdest);
  }

private:
  RegNumber rn(Reg8 r)   { return RegNumber(int(r)); }
  RegNumber rn(Reg16 r)  { return RegNumber(int(r)); }
  RegNumber rn(Reg32 r)  { return RegNumber(int(r)); }
  RegNumber rn(Reg64 r)  { return RegNumber(int(r)); }
  RegNumber rn(RegXMM r) { return RegNumber(int(r)); }

  // Caches sizes for instruction types in a certain xedInstr* context.
  // This helps with instructions where you need to know in advance
  // the length of the instruction being emitted (such as when one of
  // the operands is RIP_RELATIVE) by caching the size of the instruction
  // and removing the need to call xedEmit twice each time (once to get
  // the size, and once to actually emit the instruction).

#define XED_MEMOIZE_LEN(call)                                       \
  uint32_t instrLen;                                                \
  static std::unordered_map<int32_t,                                \
                            uint32_t> instrLengths;                 \
  auto res = instrLengths.find(int32_t(instr));                     \
  if(res != instrLengths.end()) {                                   \
    instrLen = res->second;                                         \
  } else {                                                          \
    codeBlock.assertCanEmit(XED_MAX_INSTRUCTION_BYTES);             \
    instrLen = call;                                                \
    instrLengths.insert({int32_t(instr), instrLen});                \
  }

#define XED_WRAP_IMPL() \
  XED_WRAP_X(64)        \
  XED_WRAP_X(32)        \
  XED_WRAP_X(16)        \
  XED_WRAP_X(8)

  // instr(reg)

#define XED_INSTR_WRAPPER_IMPL(bitsize)                             \
  ALWAYS_INLINE                                                     \
  void xedInstrR(xed_iclass_enum_t instr, const Reg##bitsize& r) {  \
    xedEmit1(instr, XED_REG(r), bitsize);                           \
  }

#define XED_WRAP_X XED_INSTR_WRAPPER_IMPL
  XED_WRAP_IMPL()
#undef XED_WRAP_X

  // instr(imm, reg)

#define XED_INSTIR_WRAPPER_IMPL(bitsize)                            \
  ALWAYS_INLINE                                                     \
  void xedInstrIR(xed_iclass_enum_t instr, const Immed& i,          \
                  const Reg##bitsize& r,                            \
                  int immSize = BITS_TO_SZ(bitsize)) {              \
    xedEmit2(instr, XED_REG(r), XED_IMM(i, immSize), bitsize);      \
  }                                                                 \
  ALWAYS_INLINE                                                     \
  void xedInstrIR(xed_iclass_enum_t instr, const Immed& i,          \
                  const Reg##bitsize& r,                            \
                  int immSize, immFitFunc fitFunc) {                \
    xedEmit2(instr, XED_REG(r),                                     \
             XED_IMM_RED(i, immSize, fitFunc), bitsize);            \
  }

#define XED_WRAP_X XED_INSTIR_WRAPPER_IMPL
  XED_WRAP_IMPL()
#undef XED_WRAP_X

  ALWAYS_INLINE
  void xedInstrIR(xed_iclass_enum_t instr, const Immed64& i, const Reg64& r) {
    xedEmit2(instr, XED_REG(r), XED_IMM(i, sz::qword), SZ_TO_BITS(sz::qword));
  }

  ALWAYS_INLINE
  void xedInstrIR(xed_iclass_enum_t instr, const Immed& i,
                  const RegXMM& r, int immSize) {
    xedEmit2(instr, XED_REG(r), XED_IMM(i, immSize));
  }

  // instr(reg, reg)

#define XED_INSTRR_WRAPPER_IMPL(bitsize)                            \
  ALWAYS_INLINE                                                     \
  void xedInstrRR(xed_iclass_enum_t instr, const Reg##bitsize& r1,  \
                  const Reg##bitsize& r2) {                         \
    xedEmit2(instr, XED_REG(r2), XED_REG(r1), bitsize);             \
  }

#define XED_WRAP_X XED_INSTRR_WRAPPER_IMPL
  XED_WRAP_IMPL()
#undef XED_WRAP_X

  ALWAYS_INLINE
  void xedInstrRR_CL(xed_iclass_enum_t instr, const Reg64& r) {
    xedEmit2(instr, XED_REG(r), XED_REG(XED_REG_CL), SZ_TO_BITS(sz::qword));
  }

  ALWAYS_INLINE
  void xedInstrRR(xed_iclass_enum_t instr, const Reg8& r1, const Reg32& r2) {
    xedEmit2(instr, XED_REG(r2), XED_REG(r1), SZ_TO_BITS(sz::byte));
  }

  ALWAYS_INLINE
  void xedInstrRR(xed_iclass_enum_t instr, const Reg16& r1, const Reg32& r2) {
    xedEmit2(instr, XED_REG(r2), XED_REG(r1), SZ_TO_BITS(sz::word));
  }

  ALWAYS_INLINE
  void xedInstrRR(xed_iclass_enum_t instr, const Reg8& r1, const Reg64& r2) {
    xedEmit2(instr, XED_REG(r2), XED_REG(r1), SZ_TO_BITS(sz::byte));
  }

  ALWAYS_INLINE
  void xedInstrRR(xed_iclass_enum_t instr, const Reg64& r1, const RegXMM& r2) {
    xedEmit2(instr, XED_REG(r2), XED_REG(r1));
  }

  ALWAYS_INLINE
  void xedInstrRR(xed_iclass_enum_t instr, const RegXMM& r1, const Reg64& r2) {
    xedEmit2(instr, XED_REG(r2), XED_REG(r1));
  }


  // most instr(xmm_1, xmm_2) instructions take operands in reverse order
  // compared to instr(reg_1, reg_2): source and destination are swapped
  ALWAYS_INLINE
  void xedInstrRR(xed_iclass_enum_t instr, const RegXMM& r1, const RegXMM& r2) {
    xedEmit2(instr, XED_REG(r1), XED_REG(r2));
  }

  // instr(imm)

  ALWAYS_INLINE
  void xedInstrI(xed_iclass_enum_t instr, const Immed& i, int immSize) {
      xedEmit1(instr, XED_IMM(i, immSize), SZ_TO_BITS(immSize));
  }

  // instr(mem)

  ALWAYS_INLINE
  void xedInstrM(xed_iclass_enum_t instr, const MemoryRef& m,
                 int size = sz::qword) {
      xedEmit1(instr, XED_MEMREF(m, size), SZ_TO_BITS(size));
  }

  ALWAYS_INLINE
  void xedInstrM(xed_iclass_enum_t instr, const RIPRelativeRef& m,
                 int size = sz::qword) {
    XED_MEMOIZE_LEN(xedEmit1(instr, XED_MEMREF_RIP(m, size, 0),
                             SZ_TO_BITS(size), frontier()));
    xedEmit1(instr, XED_MEMREF_RIP(m, size,
             (int64_t)frontier() + (int64_t)instrLen), SZ_TO_BITS(size));
  }

  // instr(imm, mem)

  ALWAYS_INLINE
  void xedInstrIM(xed_iclass_enum_t instr, const Immed& i, const MemoryRef& m,
                  int size = sz::qword) {
      xedEmit2(instr,  XED_MEMREF(m, size), XED_IMM(i, size),
               SZ_TO_BITS(size));
  }

  ALWAYS_INLINE
  void xedInstrIM(xed_iclass_enum_t instr, const Immed& i, const MemoryRef& m,
                  int immSize, int memSize) {
      xedEmit2(instr,  XED_MEMREF(m, memSize), XED_IMM(i, immSize),
               SZ_TO_BITS(memSize));
  }

  ALWAYS_INLINE
  void xedInstrIM(xed_iclass_enum_t instr, const Immed& i, const MemoryRef& m,
                  int immSize, immFitFunc fitFunc, int memSize) {
      xedEmit2(instr, XED_MEMREF(m, memSize), XED_IMM_RED(i, immSize, fitFunc),
               SZ_TO_BITS(memSize));
  }

  // instr(mem, reg)

#define XED_INSTMR_WRAPPER_IMPL(bitsize)                              \
  ALWAYS_INLINE                                                       \
  void xedInstrMR(xed_iclass_enum_t instr, const MemoryRef& m,        \
                  const Reg##bitsize& r,                              \
                  int memSize = BITS_TO_SZ(bitsize)) {                \
    xedEmit2(instr, XED_REG(r), XED_MEMREF(m, memSize), bitsize);     \
  }                                                                   \
  ALWAYS_INLINE                                                       \
  void xedInstrMR(xed_iclass_enum_t instr, const RIPRelativeRef& m,   \
                  const Reg##bitsize& r) {                            \
    XED_MEMOIZE_LEN(xedEmit2(instr, XED_REG(r),                       \
                             XED_MEMREF_RIP(m,                        \
                             BITS_TO_SZ(bitsize), 0), bitsize,        \
                             frontier()));                            \
    xedEmit2(instr, XED_REG(r),                                       \
             XED_MEMREF_RIP(m, BITS_TO_SZ(bitsize),                   \
             (int64_t)frontier() + (int64_t)instrLen), bitsize);      \
  }

#define XED_WRAP_X XED_INSTMR_WRAPPER_IMPL
  XED_WRAP_IMPL()
#undef XED_WRAP_X

  ALWAYS_INLINE
  void xedInstrMR(xed_iclass_enum_t instr, const MemoryRef& m,
                  const RegXMM& r, int memSize = sz::qword) {
    xedEmit2(instr, XED_REG(r), XED_MEMREF(m, memSize));
  }

  ALWAYS_INLINE                                                       \
  void xedInstrMR(xed_iclass_enum_t instr, const RIPRelativeRef& m,   \
                  const RegXMM& r, int memSize = sz::qword) {         \
    XED_MEMOIZE_LEN(xedEmit2(instr, XED_REG(r),                       \
                             XED_MEMREF_RIP(m, memSize, 0), 0,        \
                             frontier()));                            \
    xedEmit2(instr, XED_REG(r),                                       \
             XED_MEMREF_RIP(m, memSize, (int64_t)frontier() +         \
             (int64_t)instrLen));                                     \
  }

  // instr(reg, mem)

#define XED_INSTRM_WRAPPER_IMPL(bitsize)                            \
  ALWAYS_INLINE                                                     \
  void xedInstrRM(xed_iclass_enum_t instr, const Reg##bitsize& r,   \
                  const MemoryRef& m) {                             \
    xedEmit2(instr, XED_MEMREF(m, BITS_TO_SZ(bitsize)), XED_REG(r), \
             bitsize);                                              \
  }

#define XED_WRAP_X XED_INSTRM_WRAPPER_IMPL
  XED_WRAP_IMPL()
#undef XED_WRAP_X

  ALWAYS_INLINE
  void xedInstrRM(xed_iclass_enum_t instr, const RegXMM& r,
                  const MemoryRef& m, int memSize = sz::qword) {
    xedEmit2(instr, XED_MEMREF(m, memSize), XED_REG(r));
  }

  // instr(xmm, xmm, imm)

  ALWAYS_INLINE
  void xedInstrIRR(xed_iclass_enum_t instr, const RegXMM& r1, const RegXMM& r2,
                   const Immed& i, int immSize) {
    xedEmit3(instr, XED_REG(r1), XED_REG(r2), XED_IMM(i, immSize));
  }

  // instr(relbr)

  void xedInstrRelBr(xed_iclass_enum_t instr, CodeAddress dest, int size)
  {
    XED_MEMOIZE_LEN(xedEmit1(instr, XED_BRREL((CodeAddress)0, size), 0,
                    frontier()));
    auto target = dest - (codeBlock.frontier() + instrLen);
    xedEmit1(instr, XED_BRREL(target, size));
  }

  // instr()

  ALWAYS_INLINE
  void xedInstr(xed_iclass_enum_t instr, int size = sz::qword) {
    xedEmit0(instr, SZ_TO_BITS(size));
  }

  CodeBlock& codeBlock;
};

}}

#endif
