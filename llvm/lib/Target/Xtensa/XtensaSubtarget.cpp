//===-- XtensaSubtarget.cpp - Xtensa Subtarget Information --------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Xtensa specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "XtensaSubtarget.h"
#include "XtensaMachineFunctionInfo.h"
#include "Xtensa.h"
#include "XtensaTargetMachine.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "Xtensa-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "XtensaGenSubtargetInfo.inc"

extern bool FixGlobalBaseReg;

void XtensaSubtarget::anchor() { }

XtensaSubtarget::XtensaSubtarget(const Triple &TT, const std::string &CPU,
                             const std::string &FS, bool little,
                             const XtensaTargetMachine &_TM) :
  // XtensaGenSubtargetInfo will display features by llc -march=Xtensa -mcpu=help
  XtensaGenSubtargetInfo(TT, CPU, FS),
  IsLittle(little), TM(_TM), TargetTriple(TT), TSInfo(),
      InstrInfo(
          XtensaInstrInfo::create(initializeSubtargetDependencies(CPU, FS, TM))),
      FrameLowering(XtensaFrameLowering::create(*this)),
      TLInfo(XtensaTargetLowering::create(TM, *this)) {

}

