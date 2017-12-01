/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2017 Qualcomm Datacenter Technologies, Inc.            |
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

#include "hphp/runtime/vm/jit/relocation.h"

#include "hphp/runtime/vm/jit/abi-arm.h"
#include "hphp/runtime/vm/jit/align-arm.h"
#include "hphp/runtime/vm/jit/asm-info.h"
#include "hphp/runtime/vm/jit/cg-meta.h"
#include "hphp/runtime/vm/jit/containers.h"
#include "hphp/runtime/vm/jit/fixup.h"
#include "hphp/runtime/vm/jit/ir-opcode.h"
#include "hphp/runtime/vm/jit/service-requests.h"
#include "hphp/runtime/vm/jit/smashable-instr.h"
#include "hphp/runtime/vm/jit/smashable-instr-arm.h"

#include "hphp/vixl/a64/macro-assembler-a64.h"

namespace HPHP { namespace jit { namespace arm {

using namespace vixl;

namespace {

TRACE_SET_MOD(mcg);

//////////////////////////////////////////////////////////////////////

/*
 * See relocation.h for an overview. A note about adjusting for
 * relocation: for ARM, this includes the following
 *
 *   PC Relative
 *     ADR/ADRP - Builds PC relatative addresses.
 *     B[.<cc>] (immediate) - Branch to a PC relative address.
 *     LDR (literal) - Loads a literal from a PC relative address.
 *
 *   Immediates
 *     MOV/MOVK - Used to build up targets 16 bits at a time.
 *     LDR (literal) - The literal loaded may be a target address.
 *
 * adjustCodeForRelocation must support updating live instructions.
 * For ARM, we can update a single instruction or a 64 bit literal
 * in the instruction stream atomically. We can't, however, update
 * multiple instructions atomically since there may be a thread
 * executing instructions within that range. Therefore, MOV/MOVK
 * instructions can't be adjusted for live ranges of instructions.
 * Any emitted code that uses MOV/MOVK and which must be adjusted
 * while live, should instead use LDR (literal). Smashables use this
 * approach; they embed a literal in the instruction stream which
 * can then be updated atomically. At the time of this writing, only
 * the vasm opcode (leap) produces a live region that must be updated,
 * and so it uses an approach with LDR (literal) instead of MOV/MOVK.
 */

//////////////////////////////////////////////////////////////////////

using InstrSet = std::unordered_set<Instruction*>;
struct JmpOutOfRange : std::exception {};

/*
 * Maintains various state during relocation.
 */
struct Env {
  explicit Env(RelocationInfo& rel,
               CodeBlock& srcBlock, CodeBlock& destBlock,
               TCA start, TCA end, CGMeta& meta, TCA* exitAddr)
    : rel(rel)
    , srcBlock(srcBlock)
    , destBlock(destBlock)
    , start(start)
    , end(end)
    , meta(meta)
    , exitAddr(exitAddr)
    , updateInternalRefs(false)
  {
    if (exitAddr) *exitAddr = nullptr;
  }

  RelocationInfo& rel;
  CodeBlock& srcBlock;
  CodeBlock& destBlock;
  const TCA start, end;
  const CGMeta& meta;
  TCA* exitAddr;
  bool updateInternalRefs;

  /*
   * Maintains a list of any instruction that failed to be adjusted because
   * it was too far. Failing to adjust will trigger a retry and that insruction
   * will be relocated to a PIC form.
   */
  InstrSet far;

  /*
   * Simple relocation just copies src instructions to dest instructions.
   * If a src instruction(s) are actually rewritten, then those src
   * instructions are tracked in this list.
   */
  InstrSet rewrites;
};

//////////////////////////////////////////////////////////////////////

/*
 * Identifies all of the instruction words in a range which are embedded
 * literals. This set of literals is used during relocation and adjusting to
 * indicate that they should not be analyzed as instructions.
 */
InstrSet findLiterals(Instruction* start, Instruction* end) {
  InstrSet literals;
  for (auto instr = start; instr < end; instr = instr->NextInstruction()) {
    if (literals.count(instr)) continue;
    if (instr->IsLoadLiteral()) {
      /*
       * Get the address of the literal instruction words. Add both words.
       * Also check if these instruction words are themselves LDR literals
       * whose literals may have been accidentally added.
       */
      auto addLiteral = [&] (Instruction* lit) {
        if (lit >= start && lit < end) {
          if (!literals.count(lit)) {
            literals.insert(lit);
          }
          if (lit->IsLoadLiteral()) {
            auto oops = Instruction::Cast(lit->LiteralAddress());
            literals.erase(oops);
            if (lit->Mask(LoadLiteralMask) == LDR_x_lit) {
              literals.erase(oops->NextInstruction());
            }
          }
        }
      };

      auto la = Instruction::Cast(instr->LiteralAddress());
      addLiteral(la);
      if (instr->Mask(LoadLiteralMask) == LDR_x_lit)
        addLiteral(la->NextInstruction());
    }
  }
  return literals;
}

/*
 * Returns true if the instruction sequence is a smashable jcc/jmp and the
 * sequence is relocated as a simple PC relative branch. Otherwise return false
 * so that the individual instructions in the sequence can be relocated
 * one-by-one.
 *
 * NOTE: This helper will optimize sequences that are not smashables but which
 *       are identical to smashables. Namely the sequences emitted for
 *       jmp{} and jcc{} which use LDR literals for easy of patching at the
 *       end of the translation. It's important to note that a smashable-like
 *       sequence can be optimized during static relocation, but that an
 *       actual smashable can't be optimized until live relocation and then
 *       only if it has been smashed. Currently there is no means to know
 *       if a smashable has been smashed, and so this optimization of
 *       smashables during live relocation is not yet performed at all.
 *
 * destCount, srcCount and rewrites are updated to reflect when an
 * instruction(s) is rewritten to a different instruction sequence.
 */
bool relocateSmashable(Env& env, TCA srcAddr, TCA destAddr,
                       size_t& srcCount, size_t& destCount) {

  auto const srcAddrActual = env.srcBlock.toDestAddress(srcAddr);
  auto const src = Instruction::Cast(srcAddrActual);

  if (env.far.count(src)) return false;

  /*
   * A smashable jcc looks exactly like a smashable jmp with a preceding
   * conditional branch. The checks below determine if there is a smashable
   * jmp that can be optimized. It's important to not simply analyze this
   * smashable jmp without first considering if it's part of a jcc.
   */
  auto target = smashableJmpTarget(srcAddrActual);
  if (target) {
    // Look up the smashable (jmp, jcc, etc) from the target. Note this is
    // an actual address, and so we'll use the offset with the (potentially)
    // virtual srcAddr when we search through smashableLocation.
    auto smashableLocations =
      getSmashablesFromTargetAddr(srcAddrActual + kSmashJmpTargetOff);
    for (auto smashableLocation : smashableLocations) {
      auto slAddrActual = reinterpret_cast<TCA>(smashableLocation);
      auto slAddr = srcAddr + (slAddrActual - srcAddrActual);
      if (env.meta.smashableLocations.count(slAddr)) {
        FTRACE(3, "Can't optimize this smashable: {}.\n", slAddr);
        target = nullptr;
        break;
      }
    }
  }

  assertx(((uint64_t)target & 3) == 0);

  if (!target) return false;

  auto adjusted = env.rel.adjustedAddressAfter(target);
  if (!adjusted) adjusted = target;
  auto const imm =
    static_cast<int64_t>(adjusted - destAddr) >> kInstructionSizeLog2;

  if (!is_int26(imm)) return false;

  vixl::MacroAssembler a { env.destBlock };
  env.destBlock.setFrontier(destAddr);
  a.b(imm);
  srcCount = smashableJmpLen() >> kInstructionSizeLog2;
  destCount = 1;
  for (auto i = src;
       i < src + (srcCount << kInstructionSizeLog2);
       i = i->NextInstruction()) {
    env.rewrites.insert(i);
  }
  env.updateInternalRefs = true;
  FTRACE(3,
         "Relocated and optimized smashable at src {} with target {} to {}.\n",
         srcAddrActual, target, env.destBlock.toDestAddress(destAddr));

  return true;
}

/*
 * Returns true if the source is a PC relative instruction. Relocates the
 * that instruction, adjusting the offsets in the instruction. If the new
 * offset cannot be encoded, then the instruction is changed into a multi-
 * instruction sequence, overwritting the original PC relative instruction
 * that was initially copied. The following are the PC relative instructions:
 *   ADR/ADRP
 *   LDR (literal)
 *   B.<cc> (immediate)
 *   B (immediate)
 *
 * destCount, srcCount and rewrites are updated to reflect when an
 * instruction(s) is rewritten to a different instruction sequence.
 */
bool relocatePCRelative(Env& env, TCA srcAddr, TCA destAddr,
                        size_t& /*srcCount*/, size_t& destCount) {

  auto const srcFrom = Instruction::Cast(srcAddr);
  auto const destFrom = Instruction::Cast(destAddr);

  auto const srcAddrActual = env.srcBlock.toDestAddress(srcAddr);
  auto const destAddrActual = env.destBlock.toDestAddress(destAddr);
  auto const src = Instruction::Cast(srcAddrActual);
  auto const dest = Instruction::Cast(destAddrActual);

  if (!(src->IsPCRelAddressing() ||
        src->IsLoadLiteral() ||
        src->IsCondBranchImm() ||
        src->IsUncondBranchImm() ||
        src->IsCompareBranch() ||
        src->IsTestBranch())) return false;

  auto target = reinterpret_cast<TCA>(src->ImmPCOffsetTarget(srcFrom));

  // If the target is outside of the range of this relocation,
  // then update it.
  if ((target < env.start) || (target >= env.end)) {
    /*
     * Calculate the new offset and determine if it can be encoded
     * in a PC relative instruciton or if it needs to be converted
     * to make use of an absolute target.
     * Note: Use the VIXL scratch registers when transforming. Their
     *       scope is just a single macroassembler directive, whereas
     *       the scope of rAsm is an entire vasm instruction.
     */
    auto imm = static_cast<int64_t>(src->ImmPCOffsetTarget(srcFrom) - dest);
    bool isRelative = true;
    if (src->IsPCRelAddressing()) {
      if (!is_int21(imm) || env.far.count(src)) {
        env.destBlock.setFrontier(destAddr);
        destCount--;

        vixl::MacroAssembler a { env.destBlock };
        auto const dst = vixl::Register(src->Rd(), 64);
        a.Mov(dst, src->ImmPCOffsetTarget(srcFrom));

        destCount += (env.destBlock.frontier() - destAddr)
                     >> kInstructionSizeLog2;
        isRelative = false;
      }
    } else if (src->IsLoadLiteral()) {
      if (!is_int19(imm) || env.far.count(src)) {
        env.destBlock.setFrontier(destAddr);
        destCount--;

        vixl::MacroAssembler a { env.destBlock };
        a.SetScratchRegisters(vixl::NoReg, vixl::NoReg);
        auto const dst = vixl::Register(src->Rd(), 64);
        auto const tmp = dst.Is(rVixlScratch0)
          ? rVixlScratch1 : rVixlScratch0;
        a.Mov(tmp, src->ImmPCOffsetTarget(srcFrom));
        a.Ldr(dst, vixl::MemOperand(tmp));
        a.SetScratchRegisters(rVixlScratch0, rVixlScratch1);

        destCount += (env.destBlock.frontier() - destAddr)
                     >> kInstructionSizeLog2;
        isRelative = false;
      }
    } else if (src->IsCondBranchImm()) {
      imm >>= kInstructionSizeLog2;
      if (!is_int19(imm) || env.far.count(src)) {
        env.destBlock.setFrontier(destAddr);
        destCount--;

        vixl::MacroAssembler a { env.destBlock };
        vixl::Label end;
        auto const cond = static_cast<Condition>(src->ConditionBranch());
        auto const tmp = rVixlScratch0;
        a.SetScratchRegisters(vixl::NoReg, vixl::NoReg);
        a.B(&end, vixl::InvertCondition(cond));
        a.Mov(tmp, src->ImmPCOffsetTarget(srcFrom));
        a.Br(tmp);
        a.bind(&end);
        a.SetScratchRegisters(rVixlScratch0, rVixlScratch1);

        destCount += (env.destBlock.frontier() - destAddr)
                     >> kInstructionSizeLog2;
        isRelative = false;
      }
    } else if (src->IsUncondBranchImm()) {
      imm >>= kInstructionSizeLog2;
      if (!is_int26(imm) || env.far.count(src)) {
        env.destBlock.setFrontier(destAddr);
        destCount--;

        vixl::MacroAssembler a { env.destBlock };
        a.SetScratchRegisters(vixl::NoReg, vixl::NoReg);
        auto const tmp = rVixlScratch0;
        a.Mov(tmp, src->ImmPCOffsetTarget(srcFrom));
        a.Br(tmp);
        a.SetScratchRegisters(rVixlScratch0, rVixlScratch1);

        destCount += (env.destBlock.frontier() - destAddr)
                     >> kInstructionSizeLog2;
        isRelative = false;
      }
    } else if (src->IsCompareBranch()) {
      imm >>= kInstructionSizeLog2;
      if (!is_int19(imm) || env.far.count(src)) {
        env.destBlock.setFrontier(destAddr);
        destCount--;

        vixl::MacroAssembler a { env.destBlock };
        vixl::Label end;
        auto const rt = vixl::Register(src->Rt(), 64);
        auto const tmp = rVixlScratch0;
        a.SetScratchRegisters(vixl::NoReg, vixl::NoReg);
        if (src->Mask(CompareBranchMask) == CBZ_x) {
          a.Cbnz(rt, &end);
        } else {
          a.Cbz(rt, &end);
        }
        a.Mov(tmp, src->ImmPCOffsetTarget(srcFrom));
        a.Br(tmp);
        a.bind(&end);
        a.SetScratchRegisters(rVixlScratch0, rVixlScratch1);

        destCount += (env.destBlock.frontier() - destAddr)
                     >> kInstructionSizeLog2;
        isRelative = false;
      }
    } else if (src->IsTestBranch()) {
      imm >>= kInstructionSizeLog2;
      if (!is_int14(imm) || env.far.count(src)) {
        env.destBlock.setFrontier(destAddr);
        destCount--;

        vixl::MacroAssembler a { env.destBlock };
        vixl::Label end;
        auto const bit_pos = src->ImmTestBranchBit40();
        auto const rt = vixl::Register(src->Rt(), 64);
        auto const tmp = rVixlScratch0;
        a.SetScratchRegisters(vixl::NoReg, vixl::NoReg);
        if (src->Mask(TestBranchMask) == TBZ) {
          a.Tbnz(rt, bit_pos, &end);
        } else {
          a.Tbz(rt, bit_pos, &end);
        }
        a.Mov(tmp, src->ImmPCOffsetTarget(srcFrom));
        a.Br(tmp);
        a.bind(&end);
        a.SetScratchRegisters(rVixlScratch0, rVixlScratch1);

        destCount += (env.destBlock.frontier() - destAddr)
                     >> kInstructionSizeLog2;
        isRelative = false;
      }
    }

    // Update offset if it was NOT converted from relative to absolute
    if (isRelative) {
      dest->SetImmPCOffsetTarget(src->ImmPCOffsetTarget(srcFrom), destFrom);
    } else {
      // Otherwise it was rewritten to absolute, and this
      // internal reference must be updated later.
      env.rewrites.insert(src);
      env.updateInternalRefs = true;
    }
  }

  // Update the exitAddr if it was requested for this translation.
  if ((src->IsCondBranchImm() ||
       src->IsUncondBranchImm() ||
       src->IsCompareBranch() ||
       src->IsTestBranch()) &&
      env.exitAddr) {
    *env.exitAddr = target;
  }

  return true;
}

/*
 * Returns true if the instruction sequence builds up an absolute
 * immediate via a MOV/MOVK and can be replaced with a single PC
 * relative instruction. The following instruction sequences are supported:
 *   MOV/MOVK, LDR to LDR literal
 *   MOV/MOVK, BR<L> to B<L>
 *   MOV/MOVK absolute to ADR
 *
 * destCount, srcCount and rewrites are updated to reflect when an
 * instruction(s) is rewritten to a different instruction sequence.
 */
bool relocateImmediate(Env& env, TCA srcAddr, TCA destAddr,
                       size_t& srcCount, size_t& destCount) {

  auto const srcAddrActual = env.srcBlock.toDestAddress(srcAddr);
  auto const destAddrActual = env.destBlock.toDestAddress(destAddr);
  auto const src = Instruction::Cast(srcAddrActual);
  auto const dest = Instruction::Cast(destAddrActual);

  if (!src->IsMovz()) return false;

  const auto rd = src->Rd();
  uint64_t target = src->ImmMoveWide() << (16 * src->ShiftMoveWide());
  auto next = src->NextInstruction();
  while (next->IsMovk()) {
    if (next->Rd() == rd) {
      target |= next->ImmMoveWide() << (16 * next->ShiftMoveWide());
    }
    next = next->NextInstruction();
  }

  auto adjusted = env.rel.adjustedAddressAfter(reinterpret_cast<TCA>(target));
  if (!adjusted) { adjusted = reinterpret_cast<TCA>(target); }
  auto imm = static_cast<int64_t>(Instruction::Cast(adjusted) - dest);
  bool isAbsolute = true;

  /*
   * If the next instruction after a sequence of MOV/MOVK uses the
   * target, see if the entire sequence can be converted to a
   * single PC relative instruction. Supported transformations include:
   *   MOV/MOVK, LDR to LDR literal
   *   MOV/MOVK, BR<L> to B<L>
   *   MOV/MOVK absolute to ADR
   */
  if (next->Mask(LoadStoreUnsignedOffsetMask) == LDR_x_unsigned &&
      next->Rn() == rd && !next->ImmShiftLS()) {
    // Only transform if the MOV/MOVK sequence def'd a vixl scratch,
    // otherwise we run the risk of not def'ing a live register.
    auto const tmp = vixl::Register(rd, 64);
    if (tmp.Is(rVixlScratch0) || tmp.Is(rVixlScratch1)) {
      env.destBlock.setFrontier(destAddr);
      destCount--;

      vixl::MacroAssembler a { env.destBlock };
      vixl::Label target;
      auto const dst = vixl::Register(next->Rd(), 64);
      a.Ldr(dst, &target);

      auto savedFrontier = env.destBlock.frontier();
      env.destBlock.setFrontier(adjusted);
      a.bind(&target);
      env.destBlock.setFrontier(savedFrontier);

      destCount += (env.destBlock.frontier() - destAddr)
                   >> kInstructionSizeLog2;
      srcCount = ((next - src) >> kInstructionSizeLog2) + 1;
      isAbsolute = false;

      // Add range of source instructions to rewrites (MOV/MOVKs/LDR)
      for (auto i = src;
           i < next->NextInstruction();
           i = i->NextInstruction()) {
        env.rewrites.insert(i);
      }
    }
  } else if (next->IsUncondBranchReg() && next->Rn() == rd) {
    imm >>= kInstructionSizeLog2;
    // Only transform if the MOV/MOVK sequence def'd a vixl scratch,
    // otherwise we run the risk of not def'ing a live register.
    auto const dst = vixl::Register(rd, 64);
    if (dst.Is(rVixlScratch0) || dst.Is(rVixlScratch1)) {
      if (is_int26(imm)) {
        env.destBlock.setFrontier(destAddr);
        destCount--;

        vixl::MacroAssembler a { env.destBlock };
        if (next->Mask(UnconditionalBranchToRegisterMask) == BR) {
          a.b(imm);
        } else {
          a.bl(imm);
        }

        destCount += (env.destBlock.frontier() - destAddr)
                     >> kInstructionSizeLog2;
        srcCount = ((next - src) >> kInstructionSizeLog2) + 1;
        isAbsolute = false;

        // Add range of source instructions to rewrites (MOV/MOVKs/B<L>)
        // Note: next points past the MOV/MOVK sequence to the B<L>. We're
        //       replacing all of them so iterate past next for the B<L>.
        for (auto i = src;
             i < next->NextInstruction();
             i = i->NextInstruction()) {
          env.rewrites.insert(i);
        }
      }
    }
  } else {
    if (is_int21(imm)) {
      env.destBlock.setFrontier(destAddr);
      destCount--;

      vixl::MacroAssembler a { env.destBlock };
      auto const dst = vixl::Register(rd, 64);
      a.adr(dst, imm);

      destCount += (env.destBlock.frontier() - destAddr)
                   >> kInstructionSizeLog2;
      srcCount = (next - src) >> kInstructionSizeLog2;
      isAbsolute = false;

      // Add range of source instructions to rewrites (MOV/MOVKs)
      for (auto i = src; i < next; i = i->NextInstruction()) {
        env.rewrites.insert(i);
      }
    }
  }
  // If we did NOT convert to a PC relative instruction sequence, then
  // see if we need to adjust the target of the mov/movk sequence now.
  if (isAbsolute) {
    if (adjusted != reinterpret_cast<TCA>(target)) {
      env.destBlock.setFrontier(destAddr);
      destCount--;

      vixl::MacroAssembler a { env.destBlock };
      auto const dst = vixl::Register(rd, 64);
      a.Mov(dst, adjusted);

      destCount += (env.destBlock.frontier() - destAddr)
                   >> kInstructionSizeLog2;
      srcCount = (next - src) >> kInstructionSizeLog2;

      // Add range of source instructions to rewrites (MOV/MOVKs)
      for (auto i = src; i < next; i = i->NextInstruction()) {
        env.rewrites.insert(i);
      }
    } else if ((reinterpret_cast<TCA>(target) >= srcAddr) &&
               (reinterpret_cast<TCA>(target) < env.end)) {
      // Otherwise if the target wasn't adjusted because it's an addresses
      // within this translation that we have yet relocated, then mark the
      // internal ref to be updated later.
      env.updateInternalRefs = true;
    }
  } else {
    // Otherwise we rewrote the instruction sequence which can trigger internal
    // reference to need updating later.
    env.updateInternalRefs = true;
  }

  return true;
}

/*
 * Relocates padding. Service request stubs are padded out so that
 * they are always a fixed size. However, the relocation feature can
 * request that a large swath of instructions be translated and there can
 * be multiple service request stubs within. This helper function detects
 * padding in the source translation and then finds the boundaries of its
 * service request stub. It then determines how much padding is required
 * in the output. This may sound like a trivial problem, but on ARM service
 * requests stubs can grow/shrink due to branch distances. Therfore the
 * destination may contain a different amount of padding.
 */
bool relocatePadding(Env& env, TCA srcAddr, TCA destAddr,
                     size_t& srcCount, size_t& destCount,
                     TCA destStart) {

  auto const srcAddrActual = env.srcBlock.toDestAddress(srcAddr);
  auto src = Instruction::Cast(srcAddrActual);

  if (src->Mask(ExceptionMask) != BRK) return false;

  // Check to see if this is a stub and determine its start.
  auto const srcAddrBegin = [&] {
    for (auto addr : env.meta.reusedStubs) {
      if ((srcAddr >= addr) && (srcAddr < (addr + svcreq::stub_size()))) {
        return addr;
      }
    }
    return (TCA)nullptr;
  }();
  if (!srcAddrBegin) return false;

  // Add the src padding to the rewrites.
  src = src->NextInstruction();
  env.rewrites.insert(src);
  while (src->Mask(ExceptionMask) == BRK) {
    src = src->NextInstruction();
    env.rewrites.insert(src);
    srcCount++;
  }

  // Pad out the remainder of the dest service request stub
  auto const destAddrBegin = srcAddrBegin == env.start ?
    destStart : env.rel.adjustedAddressAfter(srcAddrBegin);
  assertx(destAddrBegin);

  destAddr += kInstructionSize;
  vixl::MacroAssembler a { env.destBlock };
  while ((destAddr - destAddrBegin) < svcreq::stub_size()) {
    a.Brk(1);
    destAddr += kInstructionSize;
    destCount++;
  }

  return true;
}

size_t relocateImpl(Env& env) {
  auto destStart = env.destBlock.frontier();
  size_t asmCount{0};

  /*
   * These sets track instruction words within the source sequence which should
   * be ignored during the analysis. Literals are copied and ignored even though
   * they sometimes coincedently hold valid encodings of instructions. Any
   * source instructions which are transformed should also be ignored when
   * adjusting internal refs since they have correct PC relative offsets and
   * immediate already.
   */
  try {
    // Find the literals embedded within the range
    InstrSet literals =
      findLiterals(Instruction::Cast(env.srcBlock.toDestAddress(env.start)),
                   Instruction::Cast(env.srcBlock.toDestAddress(env.end)));

    // Relocate each instruction to the destination.
    size_t srcCount, destCount;
    for (auto srcAddr = env.start;
         srcAddr < env.end;
         srcAddr += srcCount << kInstructionSizeLog2) {
      auto const src = Instruction::Cast(env.srcBlock.toDestAddress(srcAddr));
      auto destAddr = env.destBlock.frontier();
      srcCount = 1;
      destCount = 1;

      // Initially copy the instruction word
      env.destBlock.bytes(kInstructionSize,
                          env.srcBlock.toDestAddress(srcAddr));

      // If it's not a literal, then attempt any special relocations
      if (!literals.count(src) &&
          !relocateSmashable(env, srcAddr, destAddr, srcCount, destCount) &&
          !relocatePCRelative(env, srcAddr, destAddr, srcCount, destCount) &&
          !relocateImmediate(env, srcAddr, destAddr, srcCount, destCount) &&
          !relocatePadding(env, srcAddr, destAddr, srcCount, destCount,
                           destStart)) {
        // Do nothing, as the instruction word was initially copied above
      }

      // If we just copied the first instruction of a smashableMovq, then it may
      // have an internal reference that'll need to be adjusted below.
      if (!literals.count(src) &&
          isSmashableMovq(env.srcBlock.toDestAddress(srcAddr))) {
        env.updateInternalRefs = true;
      }

      if (srcAddr == env.start) {
        /*
         * For the start of the range, we only want to overwrite the "after"
         * address (since the "before" address could belong to the previous
         * tracelet, which could be being relocated to a completely different
         * address. recordRange will do that for us, so just make sure we
         * have the right address setup.
         */
        destStart = destAddr;
      } else {
        env.rel.recordAddress(srcAddr, destAddr, 0);
      }

      // Update the destAddr and reset the frontier
      destAddr += destCount << kInstructionSizeLog2;
      assertx(destAddr <= env.destBlock.frontier());
      env.destBlock.setFrontier(destAddr);

      asmCount += destCount;
    } // while (src != env.end)

    env.rel.recordRange(env.start, env.end, destStart,
                        env.destBlock.frontier());

    /*
     * Finally update any internal refs if needed. This indicates that the
     * range of instructions grew/shrank and therefore the internal refs
     * may be off.
     */
    if (env.updateInternalRefs) {
      bool ok = true;
      for (auto srcAddr = env.start;
           srcAddr < env.end;
           srcAddr += kInstructionSize) {
        auto const srcFrom = Instruction::Cast(srcAddr);
        auto const src = Instruction::Cast(env.srcBlock.toDestAddress(srcAddr));

        // Adjust this instruction if A) it wasn't written from a pc relative
        // instruction to an absolute (or vice-versa) and B) it isn't a literal.
        if (!env.rewrites.count(src) && !literals.count(src)) {
          auto const destAddr = env.rel.adjustedAddressAfter(srcAddr);
          auto const destFrom = Instruction::Cast(destAddr);
          auto const dest =
            Instruction::Cast(env.destBlock.toDestAddress(destAddr));
          /*
           * PC Relative
           *   ADR/ADRP
           *   LDR (literal)
           *   B[.<cc>] (immediate)
           *   CB[N]Z
           *   TB[N]Z
           */
          if (src->IsPCRelAddressing() ||
              src->IsLoadLiteral() ||
              src->IsCondBranchImm() ||
              src->IsUncondBranchImm() ||
              src->IsCompareBranch() ||
              src->IsTestBranch()) {
            auto const old_target =
              reinterpret_cast<TCA>(src->ImmPCOffsetTarget(srcFrom));
            auto const adjusted_target =
              env.rel.adjustedAddressAfter(old_target);
            auto const new_target =
              adjusted_target ? adjusted_target : old_target;

            /*
             * Calculate the new offset and update. At this stage, we've already
             * relocated and now we're just adjusting an internal reference.
             * Therefore we can't change relative instructions to absolute, as
             * that would change the code size. Our only recourse is to mark it
             * as far and then retry the entire relocation again.
             */
            auto const imm =
              static_cast<int64_t>(Instruction::Cast(new_target) - dest);
            if ((src->IsPCRelAddressing() && !is_int21(imm)) ||
                (src->IsLoadLiteral() && !is_int19(imm)) ||
                (src->IsCondBranchImm() &&
                 !is_int19(imm >> kInstructionSizeLog2)) ||
                (src->IsUncondBranchImm() &&
                 !is_int26(imm >> kInstructionSizeLog2)) ||
                (src->IsCompareBranch() &&
                 !is_int19(imm >> kInstructionSizeLog2)) ||
                (src->IsTestBranch() &&
                 !is_int14(imm >> kInstructionSizeLog2))) {
              FTRACE(3,
                     "relocate: PC relative instruction at {} has",
                     "internal reference 0x{:08x} which can't be adjusted.",
                     "Will try again and far.\n",
                     (uint64_t)src, imm);
              env.far.insert(src);
              ok = false;
            } else {
              dest->SetImmPCOffsetTarget(Instruction::Cast(new_target),
                                         destFrom);
            }
          }

          /*
           * Immediates
           *   LDR (literal)
           *   MOV/MOVK
           */
          if (src->IsLoadLiteral()) {
            if (src->Mask(LoadLiteralMask) == LDR_w_lit) {
              auto addr = reinterpret_cast<uint32_t*>(dest->LiteralAddress());
              auto target = *addr;
              auto adjusted =
                env.rel.adjustedAddressAfter(reinterpret_cast<TCA>(target));
              if (adjusted) {
                patchTarget32(reinterpret_cast<TCA>(addr), adjusted);
              }
            } else {
              auto addr = reinterpret_cast<TCA*>(dest->LiteralAddress());
              auto target = *addr;
              auto adjusted = env.rel.adjustedAddressAfter(target);
              if (!adjusted) {
                // Consider the case of a non-initialized mcprep smashableMovq
                target = reinterpret_cast<TCA>((uint64_t(target) >> 1));
                adjusted = env.rel.adjustedAddressAfter(target);
                if (adjusted) {
                  adjusted = reinterpret_cast<TCA>(
                    (uint64_t(adjusted) << 1) | 1
                  );
                }
                if (adjusted) {
                  patchTarget64(reinterpret_cast<TCA>(addr), adjusted);
                }
              }
            }
          } else if (src->IsMovz()) {
            int length = 1;
            const auto rd = src->Rd();
            uint64_t target = src->ImmMoveWide() << (16 * src->ShiftMoveWide());
            auto next = src->NextInstruction();
            while ((next->IsMovk() && (next->Rd() == rd)) || next->IsNop()) {
              if (next->IsMovk()) {
                target |= next->ImmMoveWide() << (16 * next->ShiftMoveWide());
              }
              length++;
              next = next->NextInstruction();
            }
            // Adjust the mov/movk sequence if necessary
            auto adjusted = env.rel.adjustedAddressAfter(
              reinterpret_cast<TCA>(target)
            );
            if (adjusted) {
              // Save the frontier for restoration below.
              auto savedFrontier = env.destBlock.frontier();
              env.destBlock.setFrontier(destAddr);

              // Write the new mov/movk sequence.
              vixl::MacroAssembler a { env.destBlock };
              auto const dst = vixl::Register(rd, 64);
              a.Mov(dst, adjusted);

              // If the new sequence is longer than the original, then we must
              // gracefully fail.
              length -= (env.destBlock.frontier() - destAddr)
                        >> kInstructionSizeLog2;
              if (length < 0) {
                ok = false;
                env.far.insert(src);
              }

              // If the sequence is shorter, then pad with nops
              while (length > 0) {
                a.nop();
                length--;
              }

              // Restore the frontier
              env.destBlock.setFrontier(savedFrontier);
            }
          }
        }
      }
      if (!ok) {
        throw JmpOutOfRange();
      }
    }
    env.rel.markAddressImmediates(env.meta.addressImmediates);
  } catch (...) {
    env.rel.rewind(env.start, env.end);
    env.destBlock.setFrontier(destStart);
    throw;
  }
  env.destBlock.sync(destStart);

  return asmCount;
}

//////////////////////////////////////////////////////////////////////

}

//////////////////////////////////////////////////////////////////////

void adjustInstruction(RelocationInfo& rel, Instruction* instr,
                       bool live) {
  /*
   * PC Relative
   *   ADR/ADRP
   *   LDR (literal)
   *   B[.<cc>] (immediate)
   *   CB[N]Z
   *   TB[N]Z
   */
  if (instr->IsPCRelAddressing() ||
      instr->IsLoadLiteral() ||
      instr->IsCondBranchImm() ||
      instr->IsUncondBranchImm() ||
      instr->IsCompareBranch() ||
      instr->IsTestBranch()) {

    auto const target = reinterpret_cast<TCA>(instr->ImmPCOffsetTarget());
    auto const adjusted = rel.adjustedAddressAfter(target);
    if (adjusted) {
      /*
       * Calculate the new offset and determine if it can be encoded.
       * We're adjusting, not relocating. So if the offset can't be
       * encoded, our only recourse is to assert.
       */
      auto imm = static_cast<int64_t>(Instruction::Cast(adjusted) - instr);
      if (instr->IsPCRelAddressing()) {
        always_assert_flog(is_int21(imm),
          "Can't adjust ADR, imm won't fit in 21 bits.\n");
      } else if (instr->IsLoadLiteral()) {
        always_assert_flog(is_int19(imm),
          "Can't adjust LDR literal, imm won't fit in 19 bits.\n");
      } else if (instr->IsCondBranchImm()) {
        imm >>= kInstructionSizeLog2;
        always_assert_flog(is_int19(imm),
          "Can't adjust B.<cc>, imm won't fit in 19 bits.\n");
      } else if (instr->IsUncondBranchImm()) {
        imm >>= kInstructionSizeLog2;
        always_assert_flog(is_int26(imm),
          "Can't adjust B, imm won't fit in 26 bits.\n");
      } else if (instr->IsCompareBranch()) {
        imm >>= kInstructionSizeLog2;
        always_assert_flog(is_int19(imm),
          "Can't adjust CB[N]Z, imm won't fit in 19 bits.\n");
      } else if (instr->IsTestBranch()) {
        imm >>= kInstructionSizeLog2;
        always_assert_flog(is_int14(imm),
          "Can't adjust TB[N]Z, imm won't fit in 14 bits.\n");
      }

      // Update offset
      instr->SetImmPCOffsetTarget(Instruction::Cast(adjusted));
      auto const begin = reinterpret_cast<TCA>(instr);
      DataBlock::syncDirect(begin, begin + kInstructionSize);
    }
  }

  /*
   * Immediates
   *   LDR (literal)
   *   MOV/MOVK
   *
   * Note: We can't atomically rewrite multiple instructions, so we
   *       assert when attempting to adjust MOV/MOVK when live.
   */
  if (instr->IsLoadLiteral()) {
    if (instr->Mask(LoadLiteralMask) == LDR_w_lit) {
      auto addr = reinterpret_cast<uint32_t*>(instr->LiteralAddress());
      auto target = *addr;
      auto adjusted = rel.adjustedAddressAfter(reinterpret_cast<TCA>(target));
      if (adjusted) patchTarget32(reinterpret_cast<TCA>(addr), adjusted);
    } else {
      auto addr = reinterpret_cast<TCA*>(instr->LiteralAddress());
      auto target = *addr;
      auto adjusted = rel.adjustedAddressAfter(target);
      if (adjusted) patchTarget64(reinterpret_cast<TCA>(addr), adjusted);
    }
  } else if (instr->IsMovz()) {
    const auto rd = instr->Rd();
    uint64_t target = instr->ImmMoveWide() << (16 * instr->ShiftMoveWide());
    auto next = instr->NextInstruction();
    size_t length = 1;
    while ((next->IsMovk() && (next->Rd() == rd)) || next->IsNop()) {
      if (next->IsMovk()) {
        target |= next->ImmMoveWide() << (16 * next->ShiftMoveWide());
      }
      length++;
      next = next->NextInstruction();
    }
    auto adjusted = (uint64_t)rel.adjustedAddressAfter(
      reinterpret_cast<TCA>(target)
    );
    if (adjusted) {
      always_assert_flog(!live, "Can't adjust MOV/MOVK for a live region.\n");

      // Create a temporary CodeBlock over the mov/movk sequence
      CodeBlock movBlock;
      auto const movStart = reinterpret_cast<TCA>(instr);
      movBlock.init(movStart, length << kInstructionSizeLog2, "mov/movk");

      // Write the new mov/movk sequence
      vixl::MacroAssembler a { movBlock };
      auto const dst = vixl::Register(rd, 64);
      a.Mov(dst, adjusted);

      // If the sequence is shorter, then pad with nops
      length -= (movBlock.frontier() - movStart) >> kInstructionSizeLog2;
      while (length > 0) {
        a.nop();
        length--;
      }

      // Sync the region
      movBlock.sync();
    }
  }
}

void adjustInstructions(RelocationInfo& rel,
                        Instruction* start, Instruction* end,
                        bool live) {
  // Find the literals
  InstrSet literals = findLiterals(start, end);

  // Adjust the instructions
  for (auto instr = start; instr < end; instr = instr->NextInstruction()) {
    if (!literals.count(instr)) {
      adjustInstruction(rel, instr, live);
    }
  }
}

//////////////////////////////////////////////////////////////////////

/*
 * This should be called after calling relocate on all relevant ranges. It
 * will adjust all references into the original src ranges to point into the
 * corresponding relocated ranges.
 */
void adjustForRelocation(RelocationInfo& rel) {
  for (const auto& range : rel.srcRanges()) {
    adjustForRelocation(rel, range.first, range.second);
  }
}

/*
 * This will update a single range that was not relocated, but that
 * might refer to relocated code (such as the cold code corresponding
 * to a tracelet). Unless its guaranteed to be all position independent,
 * its "fixups" should have been passed into a relocate call earlier.
 */
void adjustForRelocation(RelocationInfo& rel, TCA srcStart, TCA srcEnd) {
  auto start = Instruction::Cast(rel.adjustedAddressAfter(srcStart));
  auto end = Instruction::Cast(rel.adjustedAddressBefore(srcEnd));

  if (!start) {
    start = Instruction::Cast(srcStart);
    end = Instruction::Cast(srcEnd);
  } else {
    always_assert(end);
  }

  adjustInstructions(rel, start, end, false);
}

/*
 * Adjust potentially live references that point into the relocated area. Must
 * not be called until its safe to run the relocated code.
 */
void adjustCodeForRelocation(RelocationInfo& rel, CGMeta& meta) {
  for (auto addr : meta.reusedStubs) {
    auto start = Instruction::Cast(addr);
    auto end = start;

    while (end->Mask(ExceptionMask) != BRK) {
      end = end->NextInstruction();
    }

    adjustInstructions(rel, start, end, true);
  }

  for (auto codePtr : meta.codePointers) {
    if (auto adjusted = rel.adjustedAddressAfter(*codePtr)) {
      *codePtr = adjusted;
    }
  }
}

void adjustMetaDataForRelocation(RelocationInfo& rel, AsmInfo* /*asmInfo*/,
                                 CGMeta& meta) {
  for (auto& li : meta.literals) {
    if (auto adjusted = rel.adjustedAddressAfter((TCA)li.second)) {
      li.second = (uint64_t*)adjusted;
    }
  }

  decltype(meta.smashableLocations) updatedSL;
  for (auto sl : meta.smashableLocations) {
    if (auto adjusted = rel.adjustedAddressAfter(sl)) {
      updatedSL.insert(adjusted);
    } else {
      updatedSL.insert(sl);
    }
  }
  updatedSL.swap(meta.smashableLocations);

  decltype(meta.codePointers) updatedCP;
  for (auto cp : meta.codePointers) {
    if (auto adjusted = (TCA*)rel.adjustedAddressAfter((TCA)cp)) {
      updatedCP.emplace(adjusted);
    } else {
      updatedCP.emplace(cp);
    }
  }
  updatedCP.swap(meta.codePointers);
}

void findFixups(TCA start, TCA end, CGMeta& meta) {
  for (auto instr = Instruction::Cast(start);
       instr < Instruction::Cast(end);
       instr = instr->NextInstruction()) {
    // If instruction is a call
    if ((instr->Mask(UnconditionalBranchMask) == BL) ||
        (instr->Mask(UnconditionalBranchToRegisterMask) == BLR)) {
      if (auto fixup = FixupMap::findFixup(start)) {
        meta.fixups.emplace_back(start, *fixup);
      }
      if (auto ct = getCatchTrace(start)) {
        meta.catches.emplace_back(start, *ct);
      }
    }
  }
}

/*
 * Relocate code in the range start, end into dest, and record
 * information about what was done to rel.
 * On exit, internal references (references into the source range)
 * will have been adjusted (ie they are still references into the
 * relocated code). External code references continue to point to
 * the same address as before relocation.
 */
size_t relocate(RelocationInfo& rel,
                CodeBlock& destBlock,
                TCA start, TCA end,
                CodeBlock& srcBlock,
                CGMeta& meta,
                TCA* exitAddr,
                AreaIndex) {
  while (true) {
    try {
      Env env(rel, srcBlock, destBlock, start, end, meta, exitAddr);
      return relocateImpl(env);
    } catch (JmpOutOfRange& j) {
    }
  }
}

//////////////////////////////////////////////////////////////////////

}}}
