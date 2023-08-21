//===-- XtensaMachineFunctionInfo.cpp - Private data used for Xtensa -*- C++ -*-===//
//
//                    The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Xtensa specific subclass of MachineFunctionInfo.
//
//===----------------------------------------------------------------------===//

#include "XtensaMachineFunctionInfo.h"

#include "XtensaInstrInfo.h"
#include "XtensaSubtarget.h"
#include "llvm/IR/Function.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

using namespace llvm;

bool FixGlobalBaseReg;

XtensaMachineFunctionInfo::~XtensaMachineFunctionInfo() { }

void XtensaMachineFunctionInfo::anchor() { }