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

#ifndef incl_HPHP_VM_CODE_GEN_CF_H_
#define incl_HPHP_VM_CODE_GEN_CF_H_

#include "hphp/runtime/vm/jit/smashable-instr.h"
#include "hphp/runtime/vm/jit/string-tag.h"
#include "hphp/runtime/vm/jit/vasm-gen.h"
#include "hphp/runtime/vm/jit/vasm-instr.h"
#include "hphp/runtime/vm/jit/vasm-reg.h"

namespace HPHP { namespace jit {

///////////////////////////////////////////////////////////////////////////////

namespace code_gen_detail {

///////////////////////////////////////////////////////////////////////////////

template <class Then>
void ifThen(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
            Then thenBlock, StringTag tag) {
  auto then = vcold.makeBlock();
  auto done = vmain.makeBlock();

  vmain << jcc{cc, sf, {done, then}, tag};

  vcold = then;
  thenBlock(vcold);
  if (!vcold.closed()) vcold << jmp{done};

  vmain = done;
}

template <class Then, class Else>
void ifThenElse(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
                Then thenBlock, Else elseBlock, StringTag tag) {
  auto elze = vmain.makeBlock();
  auto then = vcold.makeBlock();
  auto done = vmain.makeBlock();

  vmain << jcc{cc, sf, {elze, then}, tag};

  vmain = elze;
  elseBlock(vmain);
  if (!vmain.closed()) vmain << jmp{done};

  vcold = then;
  thenBlock(vcold);
  if (!vcold.closed()) vcold << jmp{done};

  vmain = done;
}

template <class Then, class Else>
Vreg cond(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
          Vreg dst, Then thenBlock, Else elseBlock, StringTag tag) {
  auto elze = vmain.makeBlock();
  auto then = vcold.makeBlock();
  auto done = vmain.makeBlock();

  vmain << jcc{cc, sf, {elze, then}, tag};

  vmain = elze;
  auto r1 = elseBlock(vmain);
  vmain << phijmp{done, vmain.makeTuple({r1})};

  vcold = then;
  auto r2 = thenBlock(vcold);
  vcold << phijmp{done, vcold.makeTuple({r2})};

  vmain = done;
  vmain << phidef{vmain.makeTuple({dst})};
  return dst;
}

///////////////////////////////////////////////////////////////////////////////

}

///////////////////////////////////////////////////////////////////////////////
// Conditionals.
//
// Each conditional control-flow helper comes in three flavors:
//    - Emit `thenBlock' to `vmain' (along with all other blocks).
//    - Emit `thenBlock' to `vcold' (with all other blocks in `vmain').
//    - Emit `thenBlock' to `unlikely ? vcold : vmain'.

/*
 * Generate an if-then block construct.
 *
 * Tests `sf' for the branch condition `cc', and jumps to the code generated by
 * the `thenBlock' lambda if the condition holds.  A jmp past the construct is
 * emitted if `thenBlock' is not terminated.
 *
 * `thenBlock' takes a single argument: the Vout to emit to.
 */
template <class Then>
void ifThen(Vout& vmain, ConditionCode cc, Vreg sf, Then thenBlock,
            StringTag tag = StringTag{}) {
  code_gen_detail::ifThen(vmain, vmain, cc, sf, thenBlock, tag);
}

template <class Then>
void unlikelyIfThen(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
                    Then thenBlock, StringTag tag = StringTag{}) {
  code_gen_detail::ifThen(vmain, vcold, cc, sf, thenBlock, tag);
}

template <class Then>
void ifThen(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
            Then thenBlock, bool unlikely, StringTag tag = StringTag{}) {
  code_gen_detail::ifThen(vmain, unlikely ? vcold : vmain,
                          cc, sf, thenBlock, tag);
}

/*
 * Like the above flavors of ifThen(), except with a block label instead of a
 * block-emitting lambda.
 */
inline void ifThen(Vout& v, ConditionCode cc, Vreg sf, Vlabel then,
                   StringTag tag = StringTag{}) {
  auto const done = v.makeBlock();
  v << jcc{cc, sf, {done, then}, tag};
  v = done;
}

/*
 * Generate an if-then-else block construct.
 *
 * Like ifThen(), except that in addition, we jump to the code generated by
 * `elseBlock' if the condition does not hold.
 *
 * `elseBlock' takes the same arguments as `thenBlock', and we likewise close
 * it with a jmp to past the construct if it is not terminated.
 */
template <class Then, class Else>
void ifThenElse(Vout& vmain, ConditionCode cc, Vreg sf,
                Then thenBlock, Else elseBlock, StringTag tag = StringTag{}) {
  code_gen_detail::ifThenElse(vmain, vmain, cc, sf, thenBlock, elseBlock, tag);
}

template <class Then, class Else>
void unlikelyIfThenElse(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
                        Then thenBlock, Else elseBlock,
                        StringTag tag = StringTag{}) {
  code_gen_detail::ifThenElse(vmain, vcold, cc, sf, thenBlock, elseBlock, tag);
}

template <class Then, class Else>
void ifThenElse(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
                Then thenBlock, Else elseBlock, bool unlikely,
                StringTag tag = StringTag{}) {
  code_gen_detail::ifThenElse(vmain, unlikely ? vcold : vmain,
                              cc, sf, thenBlock, elseBlock, tag);
}

/*
 * Generate an if-then-else block construct with a single dst.
 *
 * Like ifThenElse(), except that the blocks are expected to return a dst Vreg.
 * The dsts are phi'd into `dst'.
 *
 * Returns `dst' unaltered, for convenience.
 */
template <class Then, class Else>
Vreg cond(Vout& vmain, ConditionCode cc, Vreg sf,
          Vreg dst, Then thenBlock, Else elseBlock,
          StringTag tag = StringTag{}) {
  return code_gen_detail::cond(vmain, vmain, cc, sf, dst,
                               thenBlock, elseBlock, tag);
}

template <class Then, class Else>
Vreg unlikelyCond(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
                  Vreg dst, Then thenBlock, Else elseBlock,
                  StringTag tag = StringTag{}) {
  return code_gen_detail::cond(vmain, vcold, cc, sf, dst,
                               thenBlock, elseBlock, tag);
}

template <class Then, class Else>
Vreg cond(Vout& vmain, Vout& vcold, ConditionCode cc, Vreg sf,
          Vreg dst, Then thenBlock, Else elseBlock, bool unlikely,
          StringTag tag = StringTag{}) {
  return code_gen_detail::cond(vmain, unlikely ? vcold : vmain,
                               cc, sf, dst, thenBlock, elseBlock, tag);
}

///////////////////////////////////////////////////////////////////////////////

/*
 * Emit an if-then-else where each side of the branch may collapse to a no-op
 * once it has executed once.
 *
 * Once both sides have executed, we collapse the whole structure into a no-op.
 * Note that we don't induce any atomicity, so each side of the branch executes
 * "at most once per thread" rather than "exactly once".
 *
 * Lambda signatures:
 *    void do_branch(Vout& v, Vlabel next, Vlabel taken);
 *    void do_then(Vout& v);
 *    void do_else(Vout& v);
 */
template<typename Branch, typename Then, typename Else>
void implodingIFTE(Vout& v, Vout& vc, Branch do_branch,
                   Then do_then, Else do_else) {
  // Emit a smashable jump forward, getting a handle to the jump instruction's
  // eventual address as well as its eventual target.  Once we've visited both
  // paths, we'll smash over this jump to completely skip this sequence.
  auto const branch = v.makeBlock();
  auto const end = v.makeBlock();
  auto const jmp_watch = v.makeAddr();
  auto const end_watch = v.makeAddr();
  v << jmps{{branch, end}, jmp_watch, end_watch};
  v = branch;

  auto const mov_watch = v.makeAddr();
  auto const bitsq = v.makeReg();
  auto const bits = v.makeReg();
  auto const mov_addr = v.makeReg();

  // Load a smashable byte of data out of the instruction stream, and save the
  // address of the mov instruction.
  v << movqs{0x0, bitsq, mov_watch};
  v << movtqb{bitsq, bits};
  v << leav{mov_watch, mov_addr};

  auto const next = v.makeBlock();
  auto const taken = v.makeBlock();
  do_branch(v, next, taken);

  auto const done = v.makeBlock();

  auto const gen_side = [&] (Vout& v, Vout& vc, auto&& do_side,
                             Vlabel side, uint8_t bit_imm) {
    v = side;
    auto const skip = v.makeBlock();
    auto const after = v.makeBlock();
    auto const slow = vc.makeBlock();

    // Test the "side taken" bit in the inline data.  If it's set, skip all of
    // this work.
    auto const sf = v.makeReg();
    v << testbi{bit_imm, bits, sf};
    v << jcc{CC_Z, sf, {skip, slow}};

    v = skip;
    v << phijmp{after, v.makeTuple({bits})};

    vc = slow;
    auto const updated = vc.makeReg();
    auto const sf2 = vc.makeReg();

    // If it's not set, smash the immediate so that the bit is set, then
    // actually perform the work of this side of the branch.
    vc << orbi{bit_imm, bits, updated, sf2};
    vc << vcall{
      CallSpec::direct(smashMovq),
      vc.makeVcallArgs({{mov_addr, updated}}),
      vc.makeTuple({})
    };
    do_side(vc);
    vc << phijmp{after, vc.makeTuple({updated})};

    // Phi some stuff.
    v = after;
    auto const def = v.makeReg();
    v << phidef{v.makeTuple({def})};
    v << phijmp{done, v.makeTuple({def})};
  };
  gen_side(v, vc, do_else, next, 0b01);
  gen_side(v, vc, do_then, taken, 0b10);

  v = done;
  auto const bits_out = v.makeReg();
  v << phidef{v.makeTuple({bits_out})};

  auto const implode = v.makeBlock();

  // Check to see if both bits are set.
  auto const sf = v.makeReg();
  v << cmpbi{0b11, bits_out, sf};
  v << jcc{CC_Z, sf, {end, implode}};

  v = implode;
  auto const jmp_addr = v.makeReg();
  auto const end_addr = v.makeReg();

  // If so, smash the jmp so that it points to the return address of this call
  // to smash the jmp.
  v << leav{jmp_watch, jmp_addr};
  v << leav{end_watch, end_addr};
  v << vcall{
    CallSpec::direct(smashJmp),
    vc.makeVcallArgs({{jmp_addr, end_addr}}),
    vc.makeTuple({})
  };
  v << jmp{end};

  v = end;
}

///////////////////////////////////////////////////////////////////////////////

/*
 * Generate a do-while loop.
 *
 * The `regs' list is the list of initial loop registers, which will be phi'd
 * appropriately for the loop.
 *
 * `loopBlock' is the lambda responsible for generating the code.  It takes
 * both the input phidef and output phijmp loop registers as arguments, and
 * should return a single SF Vreg to be tested against `cc'.
 *
 * `count' is an optional hint specifying how many times the loop is
 * likely to execute. This will be used to adjust the block weights
 * appropriately.
 */
template <class Loop>
VregList doWhile(Vout& v, ConditionCode cc,
                 const VregList& regs, Loop loopBlock,
                 int64_t count = 10) {
  auto loop = v.makeBlock();
  auto const done = v.makeBlock();
  auto loopSplit = v.makeBlock();
  auto const doneSplit = v.makeBlock();

  if (count >= 0) {
    loop.addWeightScale(count);
    loopSplit.addWeightScale(count > 0 ? (count - 1) : 0);
  }

  auto const freshRegs = [&] {
    auto copy = regs;
    for (auto& reg : copy) reg = v.makeReg();
    return copy;
  };
  auto in = freshRegs(), out = freshRegs();

  v << phijmp{loop, v.makeTuple(regs)};

  v = loop;
  v << phidef{v.makeTuple(in)};
  auto const sf = loopBlock(in, out);
  v << jcc{cc, sf, {doneSplit, loopSplit}};

  v = loopSplit;
  v << phijmp{loop, v.makeTuple(out)};

  v = doneSplit;
  v << phijmp{done, v.makeTuple(out)};

  v = done;
  auto fout = freshRegs();
  v << phidef{v.makeTuple(fout)};

  return fout;
}

///////////////////////////////////////////////////////////////////////////////

}}

#endif
