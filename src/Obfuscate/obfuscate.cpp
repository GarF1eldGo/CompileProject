#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "llvm/ADT/SmallVector.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Pass.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {
bool encrypt(std::string &s) {
  static std::set<std::string> encrypted;

  if (encrypted.find(s) == encrypted.end()) {
    std::string new_s = s;
    encrypted.insert(new_s);
    for (int i = 0; i < s.length() - 1; i++) {
      s[i] ^= 42;
    }
    if (encrypted.find(s) == encrypted.end()) {
      return true;
    } else {
      s = new_s;
      return false;
    }
  } else {
    return false;
  }
}

struct ObfuscatePass : public ModulePass {
  static char ID;
  ObfuscatePass() : ModulePass(ID) {}

  virtual bool runOnModule(Module &M) {
    for (GlobalValue &GV : M.globals()) {
      GlobalVariable *GVar = dyn_cast<GlobalVariable>(&GV);
      if (GVar == nullptr) {
        continue;
      }
      std::vector<std::pair<Instruction *, User *>> Target;
      bool hasExceptCallInst = false;
      for (User *Usr : GVar->users()) {
        // Get instruction.
        Instruction *Inst = dyn_cast<Instruction>(Usr);
        if (Inst == nullptr) {
          for (User *DirecUsr : Usr->users()) {
            Inst = dyn_cast<Instruction>(DirecUsr);
            if (Inst == nullptr) {
              continue;
            }
            if (!isa<CallInst>(Inst)) {
              hasExceptCallInst = true;
              Target.clear();
            } else {
              Target.emplace_back(std::pair<Instruction *, User *>(Inst, Usr));
            }
          }
        }
      }
      if (hasExceptCallInst == false && Target.size() == 1) {
        for (auto &T : Target) {
          obfuscateString(M, T.first, T.second, GVar);
        }
        GVar->setConstant(false);
      }
    }
    return true;
  }
  void obfuscateString(Module &M, Instruction *Inst, Value *Usr, GlobalVariable *GVar) {
    ConstantDataArray *GVarArr = dyn_cast<ConstantDataArray>(GVar->getInitializer());
    if (GVarArr == nullptr) {
      return;
    }
    std::string Origin;
    if (GVarArr->isString(8)) {
      Origin = GVarArr->getAsString().str();
    } else if (GVarArr->isCString()) {
      Origin = GVarArr->getAsCString().str();
    }
    if (encrypt(Origin)) {
      Constant *NewConstStr = ConstantDataArray::getString(GVarArr->getContext(), StringRef(Origin), false);
      GVarArr->replaceAllUsesWith(NewConstStr);
    }

    IRBuilder<> builder(Inst);
    Type *Int8PtrTy = builder.getInt8PtrTy();
    SmallVector<Type *, 1> FuncArgs = {Int8PtrTy};
    FunctionType *FuncType = FunctionType::get(Int8PtrTy, FuncArgs, false);
    FunctionCallee DecryptFunc = M.getOrInsertFunction("__decrypt", FuncType);
    SmallVector<Value *, 1> CallArgs = {Usr};
    CallInst *DecryptInst = builder.CreateCall(DecryptFunc, CallArgs);
    FunctionCallee EncryptFunc = M.getOrInsertFunction("__encrypt", FuncType);
    CallInst *EncryptInst = CallInst::Create(EncryptFunc, CallArgs);
    EncryptInst->insertAfter(Inst);
  }
};
}  // namespace

char ObfuscatePass::ID = 0;
static RegisterPass<ObfuscatePass> X("obfstr", "obfuscate string");