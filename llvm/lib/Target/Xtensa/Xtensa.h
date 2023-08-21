//===-- Xtensa.h - Top-level interface for Xtensa representation ----*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===
//
// This file contains the entry points for global functions defined in
//  the LLVM Xtensa backend.
//
//===----------------------------------------------------------------------===
#ifndef LLVM_LIB_TARGET_Xtensa_Xtensa_H
#define LLVM_LIB_TARGET_Xtensa_Xtensa_H

#include "MCTargetDesc/XtensaMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class XtensaTargetMachine;
  class FunctionPass;
}

#define ENABLE_GPRESTORE 
#endif
