//===-- XtensaFrameLowering.h - Frame Information for Xtensa --------*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Xtensa_XtensaFRAMELOWERING_H
#define LLVM_LIB_TARGET_Xtensa_XtensaFRAMELOWERING_H

#include "Xtensa.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class XtensaSubtarget;

class XtensaFrameLowering : public TargetFrameLowering {
protected:
  const XtensaSubtarget &STI;

public:
  explicit XtensaFrameLowering(const XtensaSubtarget &sti, unsigned Alignment)
    : TargetFrameLowering(StackGrowsDown, Alignment, 0, Alignment),
      STI(sti) { }

  static const XtensaFrameLowering *create(const XtensaSubtarget &ST);

  bool hasFP(const MachineFunction &MF) const override;

};

// Create XtensaFrameLowering objects.
const XtensaFrameLowering *createXtensaSEFrameLowering(const XtensaSubtarget &ST);

} // End llvm namespace

#endif
