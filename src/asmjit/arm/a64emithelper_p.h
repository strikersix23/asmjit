// This file is part of AsmJit project <https://asmjit.com>
//
// See <asmjit/core.h> or LICENSE.md for license and copyright information
// SPDX-License-Identifier: Zlib

#ifndef ASMJIT_ARM_A64EMITHELPER_P_H_INCLUDED
#define ASMJIT_ARM_A64EMITHELPER_P_H_INCLUDED

#include "../core/api-config.h"

#include "../core/emithelper_p.h"
#include "../core/func.h"
#include "../arm/a64emitter.h"
#include "../arm/a64operand.h"

ASMJIT_BEGIN_SUB_NAMESPACE(a64)

//! \cond INTERNAL
//! \addtogroup asmjit_a64
//! \{

class EmitHelper : public BaseEmitHelper {
public:
  ASMJIT_INLINE_NODEBUG explicit EmitHelper(BaseEmitter* emitter = nullptr) noexcept
    : BaseEmitHelper(emitter) {}

  ASMJIT_INLINE_NODEBUG virtual ~EmitHelper() noexcept = default;

  Error emitRegMove(
    const Operand_& dst_,
    const Operand_& src_, TypeId typeId, const char* comment = nullptr) override;

  Error emitRegSwap(
    const Reg& a,
    const Reg& b, const char* comment = nullptr) override;

  Error emitArgMove(
    const Reg& dst_, TypeId dstTypeId,
    const Operand_& src_, TypeId srcTypeId, const char* comment = nullptr) override;

  Error emitProlog(const FuncFrame& frame);
  Error emitEpilog(const FuncFrame& frame);
};

void initEmitterFuncs(BaseEmitter* emitter);

[[maybe_unused]]
static inline void updateEmitterFuncs(BaseEmitter* emitter) noexcept { DebugUtils::unused(emitter); }

//! \}
//! \endcond

ASMJIT_END_SUB_NAMESPACE

#endif // ASMJIT_ARM_A64EMITHELPER_P_H_INCLUDED
