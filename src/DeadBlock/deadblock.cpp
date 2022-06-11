#include <iostream>
#include <set>

#include "llvm/ADT/DepthFirstIterator.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace std;
using namespace llvm;
namespace {
struct DeadBlock : public FunctionPass {
  static char ID;
  DeadBlock() : FunctionPass(ID) {}

  virtual bool runOnFunction(llvm::Function& F) override {
    for (auto it = F.begin(); it != F.end(); ++it) {
      BasicBlock& bb = *it;
      IRBuilder<> Builder(bb.getTerminator());
      auto br = dyn_cast<BranchInst>(bb.getTerminator());

      if (br && br->isConditional() && isa<Constant>(br->getCondition())) {
        BasicBlock* dest1 = br->getSuccessor(0);
        BasicBlock* dest2 = br->getSuccessor(1);
        ConstantInt* cond = dyn_cast<ConstantInt>(br->getCondition());
        BasicBlock* destination = cond->getZExtValue() ? dest1 : dest2;
        BasicBlock* olddest = cond->getZExtValue() ? dest2 : dest1;
        olddest->removePredecessor(&bb);
        Builder.CreateBr(destination);
        br->eraseFromParent();
      }
    }

    bool changed = false;

    llvm::df_iterator_default_set<BasicBlock*> visitedSet;
    llvm::df_iterator_default_set<BasicBlock*> unreachableSet;

    for (auto i = df_ext_begin<BasicBlock*, llvm::df_iterator_default_set<BasicBlock*>>(&F.getEntryBlock(), visitedSet), e = df_ext_end<BasicBlock*, llvm::df_iterator_default_set<BasicBlock*>>(&F.getEntryBlock(), visitedSet); i != e; i++)
      ;

    for (BasicBlock& BB : F) {
      if (visitedSet.find(&BB) == visitedSet.end()) {
        unreachableSet.insert(&BB);
      }
    }

    if (!unreachableSet.empty()) {
      changed = true;
    }

    for (BasicBlock* BB : unreachableSet) {
      for (auto i = succ_begin(BB); i != succ_end(BB); i++) {
        i->removePredecessor(BB);
      }
      BB->eraseFromParent();
    }

    return changed;
  };
};
}  // namespace
char DeadBlock::ID = 0;
static RegisterPass<DeadBlock> X("deadblock", "Dead blocks elimination pass", true, false);