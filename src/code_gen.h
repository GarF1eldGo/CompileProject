#ifndef _CODE_GEN_H_
#define _CODE_GEN_H_

#include <iostream>
#include "ast.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/Optional.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include <llvm/IR/GlobalVariable.h>
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include <llvm/IR/ValueSymbolTable.h>
#include "llvm/IR/Verifier.h"
#include "llvm/IR/AssemblyAnnotationWriter.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"


// extern exprAST* ROOT;
using namespace std;
static llvm::LLVMContext context;
static llvm::IRBuilder<> builder(context);

/*
class codeGen {
public:

    void generate(translation_unit* root);
    CodeGen();
    ~CodeGen();
};
*/

class codeGen {
public:
    llvm::Module *module;
    stack<llvm::Function*> funStack;
    llvm::Function *printf, *scanf;
    llvm::Function* createPrintf();
    llvm::Function* createScanf();
    void generate(exprAST* ROOT);
    codeGen();

};

llvm::Value* IRError(string msg);

llvm::Value* findValue(const std::string & name);

llvm::Instruction::CastOps getCastInst(llvm::Type* src, llvm::Type* dst);

llvm::Value* typeCast(llvm::Value* src, llvm::Type* dst);

llvm::Type *build_array(Type *array_type, vector<ConstantInt *> array_size);

llvm::Type *build_array_with_size(Type *array_type, vector<ConstantInt *> array_size);
#endif
