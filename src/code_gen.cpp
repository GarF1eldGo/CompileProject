#include "code_gen.h"

#include <iostream>

#include "ast.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"
//#define DEBUG
// #include "llvm/ADT/APFloat.h"
// #include "llvm/ADT/Optional.h"
// #include "llvm/ADT/STLExtras.h"
// #include "llvm/IR/BasicBlock.h"
// #include "llvm/IR/Constants.h"
// #include "llvm/IR/DerivedTypes.h"
// #include "llvm/IR/Function.h"
// #include "llvm/IR/Instructions.h"
// #include "llvm/IR/IRBuilder.h"
// #include "llvm/IR/LLVMContext.h"
// #include "llvm/IR/LegacyPassManager.h"
// #include "llvm/IR/Module.h"
// #include "llvm/IR/Type.h"
// #include "llvm/IR/Verifier.h"
// #include "llvm/IR/AssemblyAnnotationWriter.h"
// #include "llvm/Support/FileSystem.h"
// #include "llvm/Support/Host.h"
// #include "llvm/Support/raw_ostream.h"
// #include "llvm/Support/TargetRegistry.h"
// #include "llvm/Support/raw_os_ostream.h"
// #include "llvm/Support/TargetSelect.h"
// #include "llvm/Target/TargetMachine.h"
// #include "llvm/Target/TargetOptions.h"

// CodeGen *generator;

// CodeGen::CodeGen(/* args */) {

// }

// CodeGen::~CodeGen() {

// }
llvm::Function* codeGen::createPrintf() {
  std::vector<llvm::Type*> arg_types;
  arg_types.push_back(builder.getInt8PtrTy());
  auto printf_type = llvm::FunctionType::get(
      builder.getInt32Ty(), llvm::makeArrayRef(arg_types), true);
  auto func =
      llvm::Function::Create(printf_type, llvm::Function::ExternalLinkage,
                             llvm::Twine("printf"), this->module);
  func->setCallingConv(llvm::CallingConv::C);
  return func;
  // return nullptr;
}

llvm::Function* codeGen::createScanf() {
  std::vector<llvm::Type*> arg_types;
  arg_types.push_back(builder.getInt8PtrTy());
  auto scanf_type = llvm::FunctionType::get(
      builder.getInt32Ty(), llvm::makeArrayRef(arg_types), true);
  auto func =
      llvm::Function::Create(scanf_type, llvm::Function::ExternalLinkage,
                             llvm::Twine("scanf"), this->module);
  func->setCallingConv(llvm::CallingConv::C);
  return func;
  // return nullptr;
}

codeGen::codeGen() {
  this->module = new llvm::Module("module", context);
  this->printf = this->createPrintf();
  this->scanf = this->createScanf();
}

void codeGen::generate(exprAST* ROOT) {
  ROOT->CodeGen();
  this->module->print(llvm::outs(), nullptr);

  // this->module->dump();
}

codeGen* generator = new codeGen();

Type* get_type(int type) {
  switch (type) {
    case 1:
      return llvm::Type::getVoidTy(context);
    case 2:
      return llvm::Type::getInt8Ty(context);
    case 3:
      return llvm::Type::getInt16Ty(context);
    case 4:
      return llvm::Type::getInt32Ty(context);
    case 5:
      return llvm::Type::getInt64Ty(context);
    case 6:
      return llvm::Type::getFloatTy(context);
    case 7:
      return llvm::Type::getDoubleTy(context);
  }
}

llvm::Value* IRError(string msg) {
  cout << msg << endl;
  return nullptr;
}

string type2str(Value* x) {
  std::string type_str;
  llvm::raw_string_ostream rso(type_str);
  x->getType()->print(rso);
  return rso.str();
}

llvm::Value* findValue(const std::string& name) {
  // llvm::Value * result =
  // generator->funStack.top()->getValueSymbolTable()->lookup(name);
  llvm::Value* result =
      builder.GetInsertBlock()->getParent()->getValueSymbolTable()->lookup(
          name);
  // result = result->load();
  // result =
  // llvm::LoadInst::LoadInst(result->getType()->getPointerElementType(),
  // result, "load", builder.GetInsertBlock());
  if (result != nullptr) {
    return result;
  }
  result = generator->module->getGlobalVariable(name, true);
  if (result == nullptr) {
    return IRError("variable or function undefined!");
  }
  return result;
}

llvm::Value* primary_expression::CodeGen() {
#ifdef DEBUG
  cout << "primary_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      // llvm::Value* tmp = this->children[0]->CodeGen();
      llvm::Value* rs = findValue(
          (dynamic_cast<identifierAST*>(this->children[0]))->identifier);
      if (rs == nullptr) {
        return IRError("primary_expression error in leaf node: IDENTIFIER");
      } else {
        return rs;
        // if (rs->getType()->isPointerTy() &&
        // (rs->getType()->getPointerElementType()->isArrayTy())) {
        //   return builder.CreateLoad(rs->getType()->getPointerElementType(),
        //   rs, "tmpvar");
        // }
        // else{
        //   return rs;
        // }
      }
    }
    case 2: {
      // llvm::Value* tmp = this->children[0]->CodeGen();
      // if(tmp == nullptr){
      //     return IRError("postfix_expression error in leaf node:
      //     primary_expression");
      // }
      if ((dynamic_cast<constantAST*>(this->children[0]))->type == 1) {
        // return
        // builder.getInt32((int)((dynamic_cast<constantAST*>(this->children[0]))->value));
        return llvm::ConstantInt::get(
            builder.getInt32Ty(),
            (int)(dynamic_cast<constantAST*>(this->children[0])->value));
      } else {
        return llvm::ConstantFP::get(
            builder.getFloatTy(),
            llvm::APFloat(
                (float)((dynamic_cast<constantAST*>(this->children[0]))
                            ->value)));
      }
    }
    case 3: {
      string str = (dynamic_cast<stringAST*>(this->children[0])->value);
      llvm::Constant* strConst =
          llvm::ConstantDataArray::getString(context, str);
      llvm::Value* globalVar = new llvm::GlobalVariable(
          *generator->module, strConst->getType(), true,
          llvm::GlobalValue::PrivateLinkage, strConst, "_Const_String_");
      vector<llvm::Value*> indexList;
      indexList.push_back(builder.getInt32(0));
      indexList.push_back(builder.getInt32(0));
      // indexList.push_back(builder.getInt32(str.length()-1));
      //  var value
      llvm::Value* varPtr = builder.CreateInBoundsGEP(
          globalVar, llvm::ArrayRef<llvm::Value*>(indexList), "tmpvar");
      return varPtr;
    }
    case 4: {
      llvm::Value* tmp = this->children[1]->CodeGen();
      if (tmp == nullptr) {
        return IRError("primary_expression error in leaf node: expression");
      } else {
        return tmp;
      }
    }
    case 5: {
      return llvm::ConstantInt::get(
          builder.getInt8Ty(),
          (uint8_t)(dynamic_cast<charAST*>(this->children[0])->value));
    }
  }
  return nullptr;
}

llvm::Value* postfix_expression::CodeGen() {
#ifdef DEBUG
  cout << "postfix_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      // cout<<"pr okk~"<<endl;
      if (tmp == nullptr) {
        return IRError(
            "postfix_expression error in leaf node: primary_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* ary = this->children[0]->CodeGen();
      llvm::Value* index = this->children[2]->CodeGen();
      llvm::Value* aryvalue = nullptr;
      llvm::Value* indexvalue = nullptr;
      if (ary == nullptr || index == nullptr) {
        return IRError(
            "postfix_expression error in leaf node: postfix_expression or "
            "expression");
      } else {
        if (ary->getType()->isPointerTy() &&
            !(ary->getType()->getPointerElementType()->isArrayTy())) {
          aryvalue = builder.CreateLoad(ary->getType()->getPointerElementType(),
                                        ary, "tmpvar");
        } else {
          aryvalue = ary;
        }
        if (index->getType()->isPointerTy() &&
            !(index->getType()->getPointerElementType()->isArrayTy())) {
          indexvalue = builder.CreateLoad(
              index->getType()->getPointerElementType(), index, "tmpvar");
        } else {
          indexvalue = index;
        }
      }
      if (indexvalue->getType() != llvm::Type::getInt32Ty(context)) {
        return IRError(
            "postfix_expression error: only int type can be used as index");
      } else {
        // id [][]...[]
        //  if(ary->getType() ==
        //  llvm::Type::getInt32PtrTy(context)||ary->getType() ==
        //  llvm::Type::getInt8PtrTy(context)||ary->getType() ==
        //  llvm::Type::getInt1PtrTy(context)||ary->getType() ==
        //  llvm::Type::getFloatPtrTy(context)){
        //    vector<llvm::Value*> indexList;
        //    indexList.push_back(builder.getInt32(0));
        //    indexList.push_back(index);
        //    llvm::Value * varPtr = builder.CreateInBoundsGEP(ary,
        //    llvm::ArrayRef<llvm::Value*>(indexList), "tmpvar"); return
        //    builder.CreateLoad(varPtr->getType()->getPointerElementType(),
        //    varPtr, "tmpvar");
        //  }
        //  //id []
        //  else{
        //    llvm::Value* ary_real =
        //    findValue((dynamic_cast<identifierAST*>(this->children[0]))->identifier);
        //    vector<llvm::Value*> indexList;
        //    indexList.push_back(builder.getInt32(0));
        //    indexList.push_back(index);
        //    llvm::Value * varPtr = builder.CreateInBoundsGEP(ary_real,
        //    llvm::ArrayRef<llvm::Value*>(indexList), "tmpvar"); return
        //    builder.CreateLoad(varPtr->getType()->getPointerElementType(),
        //    varPtr, "tmpvar");
        //  }
        vector<llvm::Value*> indexList;
        indexList.push_back(builder.getInt32(0));
        indexList.push_back(indexvalue);
        llvm::Value* varPtr = builder.CreateInBoundsGEP(
            aryvalue, llvm::ArrayRef<llvm::Value*>(indexList), "tmpvar");
        return varPtr;
      }
    }
    case 3: {
      // llvm::Value* func = this->children[0]->CodeGen();
      if (dynamic_cast<identifierAST*>(
              dynamic_cast<primary_expression*>(
                  dynamic_cast<postfix_expression*>(this->children[0])
                      ->children[0])
                  ->children[0])
                  ->identifier.compare("printf") == 0 ||
          dynamic_cast<identifierAST*>(
              dynamic_cast<primary_expression*>(
                  dynamic_cast<postfix_expression*>(this->children[0])
                      ->children[0])
                  ->children[0])
                  ->identifier.compare("scanf") == 0) {
        return IRError(
            "postfix_expression error: printf() or scanf() is not allowed");
      } else {
        //      llvm::Function* func_real =
        //      generator->module->getFunction((dynamic_cast<identifierAST*>(this->children[0]))->identifier);
        llvm::Function* func_real = generator->module->getFunction(
            dynamic_cast<identifierAST*>(
                dynamic_cast<primary_expression*>(
                    dynamic_cast<postfix_expression*>(this->children[0])
                        ->children[0])
                    ->children[0])
                ->identifier);
        if (func_real == nullptr) {
          return IRError("postfix_expression error: undefined function");
        } else {
          if (func_real->getFunctionType()->getReturnType() ==
              Type::getVoidTy(context)) {
            return builder.CreateCall(func_real, vector<llvm::Value*>(), "");
          } else {
            return builder.CreateCall(func_real, vector<llvm::Value*>(),
                                      "tmpcall");
          }
        }
      }
    }
    case 4: {
      // llvm::Value* func = this->children[0]->CodeGen();
      vector<llvm::Value*>* arg =
          (dynamic_cast<argument_expression_list*>(this->children[2]))
              ->ArgGen();
      if (arg == nullptr) {
        return IRError(
            "postfix_expression error in leaf node: argument_expression_list");
      } else {
        if (dynamic_cast<identifierAST*>(
                dynamic_cast<primary_expression*>(
                    dynamic_cast<postfix_expression*>(this->children[0])
                        ->children[0])
                    ->children[0])
                ->identifier.compare("printf") == 0) {
          for (int i = 1; i <= arg->size() - 1; i++) {
            llvm::Value* tmpvalue;
            if ((*arg)[i]->getType()->isPointerTy()) {
              tmpvalue = builder.CreateLoad(
                  (*arg)[i]->getType()->getPointerElementType(), (*arg)[i],
                  "tmpvar");
            } else {
              tmpvalue = (*arg)[i];
            }
            (*arg)[i] = tmpvalue;
            if ((*arg)[i]->getType() == Type::getFloatTy(context)) {
              (*arg)[i] = builder.CreateFPExt(
                  (*arg)[i], Type::getDoubleTy(context), "tmpdouble");
            }
          }
          return builder.CreateCall(generator->printf, *arg, "printf");
        } else if (dynamic_cast<identifierAST*>(
                       dynamic_cast<primary_expression*>(
                           dynamic_cast<postfix_expression*>(this->children[0])
                               ->children[0])
                           ->children[0])
                       ->identifier.compare("scanf") == 0) {
          return builder.CreateCall(generator->scanf, *arg, "scanf");
        } else {
          for (int i = 0; i <= arg->size() - 1; i++) {
            llvm::Value* tmpvalue;
            if ((*arg)[i]->getType()->isPointerTy() &&
                !(*arg)[i]->getType()->getPointerElementType()->isArrayTy() &&
                (*arg)[i]->getType()->getPointerElementType() !=
                    llvm::Type::getInt8Ty(context)) {
              tmpvalue = builder.CreateLoad(
                  (*arg)[i]->getType()->getPointerElementType(), (*arg)[i],
                  "tmpvar");
            } else {
              tmpvalue = (*arg)[i];
            }
            (*arg)[i] = tmpvalue;
          }
          llvm::Function* func_real = generator->module->getFunction(
              dynamic_cast<identifierAST*>(
                  dynamic_cast<primary_expression*>(
                      dynamic_cast<postfix_expression*>(this->children[0])
                          ->children[0])
                      ->children[0])
                  ->identifier);
          if (func_real == nullptr) {
            return IRError("postfix_expression error: undefined function");
          } else {
            if (func_real->getFunctionType()->getReturnType() ==
                Type::getVoidTy(context)) {
              return builder.CreateCall(func_real, *arg, "");
            } else {
              return builder.CreateCall(func_real, *arg, "tmpcall");
            }
          }
        }
      }
    }
    case 5: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      llvm::Value* tmpvalue = nullptr;
      if (tmp == nullptr) {
        return IRError(
            "postfix_expression error in leaf node: postfix_expression");
      } else {
        if (tmp->getType()->isPointerTy() &&
            !(tmp->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                        tmp, "tmpvar");
        } else {
          tmpvalue = tmp;
        }
      }

      if (tmpvalue->getType() == llvm::Type::getInt32Ty(context)) {
        llvm::Value* result =
            builder.CreateAdd(tmpvalue, builder.getInt32(1), "tmpAdd");
        builder.CreateStore(result, tmp, "tmpstore");
        return result;
      } else if (tmpvalue->getType() == llvm::Type::getFloatTy(context)) {
        llvm::Value* result =
            builder.CreateFAdd(tmpvalue,
                               llvm::ConstantFP::get(builder.getFloatTy(),
                                                     llvm::APFloat((float)1)),
                               "tmpAddf");
        builder.CreateStore(result, tmp, "tmpstore");
        return result;
      } else {
        return IRError(
            "postfix_expression error: bool/char type could not associate with "
            "'++' operator");
      }
    }
    case 6: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      llvm::Value* tmpvalue = nullptr;
      if (tmp == nullptr) {
        return IRError(
            "postfix_expression error in leaf node: postfix_expression");
      } else {
        if (tmp->getType()->isPointerTy() &&
            !(tmp->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                        tmp, "tmpvar");
        } else {
          tmpvalue = tmp;
        }
      }
      if (tmpvalue->getType() == llvm::Type::getInt32Ty(context)) {
        llvm::Value* result =
            builder.CreateSub(tmpvalue, builder.getInt32(1), "tmpSub");
        builder.CreateStore(result, tmp, "tmpstore");
        return result;
      } else if (tmpvalue->getType() == llvm::Type::getFloatTy(context)) {
        llvm::Value* result =
            builder.CreateFSub(tmpvalue,
                               llvm::ConstantFP::get(builder.getFloatTy(),
                                                     llvm::APFloat((float)1)),
                               "tmpSubf");
        builder.CreateStore(result, tmp, "tmpstore");
        return result;
      } else {
        return IRError(
            "postfix_expression error: bool/char type could not associate with "
            "'--' operator");
      }
    }
      return nullptr;
  }
}

llvm::Value* argument_expression_list::CodeGen() {
#ifdef DEBUG
  cout << "argument_expression_list type:" << this->type << endl;
#endif
  // switch(this->type){
  //     case 1:
  //         llvm::Value* tmp = this->children[0]->CodeGen();
  //         if(tmp == nullptr){
  //             cout<<"argument_expression_list error in leaf node:
  //             assignment_expression"<<endl; return nullptr;
  //         }
  //         else{
  //             vector<llvm::Value *> * args = new vector<llvm::Value *>;
  //             args->push_back(tmp);
  //             return tmp;
  //         }
  //     case 2:
  //         vector<llvm::Value *> * children_args =
  //         this->children[0]->ArgGen(); llvm::Value* tmp =
  //         this->children[2]->CodeGen();

  // }
  return nullptr;
}

vector<llvm::Value*>* argument_expression_list::ArgGen() {
#ifdef DEBUG
  cout << "argument_expression_list type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        cout << "argument_expression_list error in leaf node: "
                "assignment_expression"
             << endl;
        return nullptr;
      } else {
        vector<llvm::Value*>* args = new vector<llvm::Value*>;
        args->push_back(tmp);
        return args;
      }
    }
    case 2: {
      vector<llvm::Value*>* children_args =
          (dynamic_cast<argument_expression_list*>(this->children[0]))
              ->ArgGen();
      llvm::Value* tmp = this->children[2]->CodeGen();
      if (children_args == nullptr || tmp == nullptr) {
        cout << "argument_expression_list error in leaf node: "
                "argument_expression_list or assignment_expression"
             << endl;
        return nullptr;
      } else {
        children_args->push_back(tmp);
        return children_args;
      }
    }
  }
  return nullptr;
}

llvm::Value* unary_expression::CodeGen() {
#ifdef DEBUG
  cout << "unary_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "unary_expression error in leaf node: postfix_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp = this->children[1]->CodeGen();
      llvm::Value* tmpvalue = nullptr;
      if (tmp == nullptr) {
        return IRError("unary_expression error in leaf node: unary_expression");
      } else {
        if (tmp->getType()->isPointerTy() &&
            !(tmp->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                        tmp, "tmpvar");
        } else {
          tmpvalue = tmp;
        }
      }
      if (tmpvalue->getType() == llvm::Type::getInt32Ty(context)) {
        llvm::Value* result =
            builder.CreateAdd(tmpvalue, builder.getInt32(1), "tmpAdd");
        builder.CreateStore(result, tmp, "tmpstore");
        return result;
      } else if (tmpvalue->getType() == llvm::Type::getFloatTy(context)) {
        llvm::Value* result =
            builder.CreateFAdd(tmpvalue,
                               llvm::ConstantFP::get(builder.getFloatTy(),
                                                     llvm::APFloat((float)1)),
                               "tmpAddf");
        builder.CreateStore(result, tmp, "tmpstore");
        return result;
      } else {
        return IRError(
            "unary_expression error: bool/char type could not associate with "
            "'++' operator");
      }
    }
    case 3: {
      llvm::Value* tmp = this->children[1]->CodeGen();
      llvm::Value* tmpvalue = nullptr;
      if (tmp == nullptr) {
        return IRError("unary_expression error in leaf node: unary_expression");
      } else {
        if (tmp->getType()->isPointerTy() &&
            !(tmp->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                        tmp, "tmpvar");
        } else {
          tmpvalue = tmp;
        }
      }
      if (tmpvalue->getType() == llvm::Type::getInt32Ty(context)) {
        llvm::Value* result =
            builder.CreateSub(tmpvalue, builder.getInt32(1), "tmpSub");
        builder.CreateStore(result, tmp, "tmpstore");
        return result;
      } else if (tmpvalue->getType() == llvm::Type::getFloatTy(context)) {
        llvm::Value* result =
            builder.CreateFSub(tmpvalue,
                               llvm::ConstantFP::get(builder.getFloatTy(),
                                                     llvm::APFloat((float)1)),
                               "tmpSubf");
        builder.CreateStore(result, tmp, "tmpstore");
        return result;
      } else {
        return IRError(
            "unary_expression error: bool/char type could not associate with "
            "'--' operator");
      }
    }
    case 4: {
      llvm::Value* tmp = this->children[1]->CodeGen();
      llvm::Value* tmpvalue = nullptr;
      if (tmp == nullptr) {
        return IRError("unary_expression error in leaf node: cast_expression");
      } else {
        if (tmp->getType()->isPointerTy() &&
            !(tmp->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                        tmp, "tmpvar");
        } else {
          tmpvalue = tmp;
        }
      }
      if (tmpvalue->getType() == llvm::Type::getInt8Ty(context)) {
        return IRError(
            "unary_expression error: char type could not associate with "
            "unary_operator");
      } else {
        // llvm::Value* rs = this->children[0]->CodeGen();
        if ((dynamic_cast<operatorAST*>(this->children[0]))->op.compare("-") ==
            0) {
          if (tmpvalue->getType() == llvm::Type::getInt32Ty(context)) {
            return builder.CreateNeg(tmpvalue, "tmpNeg");
          } else if (tmpvalue->getType() == llvm::Type::getFloatTy(context)) {
            return builder.CreateFNeg(tmpvalue, "tmpNegf");
          } else {
            return IRError(
                "unary_expression error: bool type could not associate with "
                "'-' operator");
          }
        } else if ((dynamic_cast<operatorAST*>(this->children[0]))
                       ->op.compare("!") == 0) {
          if (tmpvalue->getType() == llvm::Type::getInt1Ty(context)) {
            return builder.CreateNot(tmpvalue, "tmpNot");
          } else {
            return IRError(
                "unary_expression error: int/float type could not associate "
                "with '!' operator");
          }
        } else if ((dynamic_cast<operatorAST*>(this->children[0]))
                       ->op.compare("&") == 0) {
          return tmp;
        } else {
          return IRError("unary_expression error: illegal operator");
        }
      }
    }
    case 5: {
      llvm::Value* tmp = this->children[1]->CodeGen();
      llvm::Value* tmpvalue = nullptr;

      if (tmp == nullptr) {
        return IRError("unary_expression error in leaf node: unary_expression");
      } else {
        if (tmp->getType()->isPointerTy() &&
            !(tmp->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                        tmp, "tmpvar");
        } else {
          tmpvalue = tmp;
        }
      }
      if (tmpvalue->getType() == llvm::Type::getInt1Ty(context)) {
        return builder.getInt32(1);
      } else if (tmpvalue->getType() == llvm::Type::getInt32Ty(context)) {
        return builder.getInt32(4);
      } else if (tmpvalue->getType() == llvm::Type::getFloatTy(context)) {
        return builder.getInt32(4);
      } else if (tmpvalue->getType() == llvm::Type::getInt8Ty(context)) {
        return builder.getInt32(1);
      } else {
        return IRError(
            "unary_expression type error with leaf node: unary_expression");
      }
    }
    case 6: {
      // llvm::Value* tmp = this->children[1]->CodeGen();
      // if(tmp == nullptr){
      //   return IRError("unary_expression error in leaf node: type_name");
      // }
      if (dynamic_cast<typeAST*>(
              (dynamic_cast<nonleafAST*>(this->children[2])->children)[0])
              ->type == 8) {
        return builder.getInt32(1);
      } else if (dynamic_cast<typeAST*>(
                     (dynamic_cast<nonleafAST*>(this->children[2])
                          ->children)[0])
                     ->type == 4) {
        return builder.getInt32(4);
      } else if (dynamic_cast<typeAST*>(
                     (dynamic_cast<nonleafAST*>(this->children[2])
                          ->children)[0])
                     ->type == 6) {
        return builder.getInt32(4);
      } else if (dynamic_cast<typeAST*>(
                     (dynamic_cast<nonleafAST*>(this->children[2])
                          ->children)[0])
                     ->type == 2) {
        return builder.getInt32(1);
      } else {
        return IRError("unary_expression type error with leaf node: type_name");
      }
    }
  }
  return nullptr;
}

llvm::Value* unary_operator::CodeGen() {
#ifdef DEBUG
  cout << "unary_operator type:" << this->type << endl;
#endif
  // switch(this->type){
  //     case 4:
  //         if(cast_expression->getType() == llvm::Type::getInt32Ty(context)){
  //             return builder.CreateNeg(cast_expression, "tmpNeg");
  //         }
  //         else if(cast_expression->getType() ==
  //         llvm::Type::getFloatTy(context)){
  //             return builder.CreateFNeg(cast_expression, "tmpNegf");
  //         }
  //         else{
  //             return IRError("bool type could not associate with '-'
  //             operator");
  //         }
  //     case 5:
  //         if(cast_expression->getType() == llvm::Type::getInt1Ty(context)){
  //             return builder.CreateNot(cast_expression, "tmpNot");
  //         }
  //         else{
  //             return IRError("int/float type could not associate with '~'
  //             operator");
  //         }
  //     case 6:
  //         if(cast_expression->getType() == llvm::Type::getInt1Ty(context)){
  //             return builder.CreateNot(cast_expression, "tmpNot");
  //         }
  //         else{
  //             return IRError("int/float type could not associate with '!'
  //             operator");
  //         }
  // }
  return nullptr;
}

llvm::Instruction::CastOps getCastInst(llvm::Type* src, llvm::Type* dst) {
  if (src == llvm::Type::getFloatTy(context) &&
      dst == llvm::Type::getInt32Ty(context)) {
    return llvm::Instruction::FPToSI;
  } else if (src == llvm::Type::getInt32Ty(context) &&
             dst == llvm::Type::getFloatTy(context)) {
    return llvm::Instruction::SIToFP;
  } else if (src == llvm::Type::getInt8Ty(context) &&
             dst == llvm::Type::getFloatTy(context)) {
    return llvm::Instruction::UIToFP;
  } else if (src == llvm::Type::getInt8Ty(context) &&
             dst == llvm::Type::getInt32Ty(context)) {
    return llvm::Instruction::ZExt;
  } else if (src == llvm::Type::getInt32Ty(context) &&
             dst == llvm::Type::getInt8Ty(context)) {
    return llvm::Instruction::Trunc;
  } else {
    IRError("cast_expression error: two types are contradict");
  }
}

llvm::Value* typeCast(llvm::Value* src, llvm::Type* dst) {
  if (src->getType() == dst) {
    return src;
  } else {
    llvm::Instruction::CastOps op = getCastInst(src->getType(), dst);
    return builder.CreateCast(op, src, dst, "tmptypecast");
  }
}

llvm::Value* cast_expression::CodeGen() {
#ifdef DEBUG
  cout << "cast_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError("cast_expression error in leaf node: unary_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp1 = this->children[1]->CodeGen();
      llvm::Value* tmp2 = this->children[3]->CodeGen();
      llvm::Value* tmpvalue = nullptr;
      // llvm::Value* rs = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "cast_expression error in leaf node: type_name or cast_expression");
      } else {
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue = tmp2;
        }
      }
      if (dynamic_cast<typeAST*>(
              (dynamic_cast<nonleafAST*>(this->children[1])->children)[0])
              ->type == 2) {
        return typeCast(tmpvalue, llvm::Type::getInt8Ty(context));
      } else if (dynamic_cast<typeAST*>(
                     (dynamic_cast<nonleafAST*>(this->children[1])
                          ->children)[0])
                     ->type == 4) {
        return typeCast(tmpvalue, llvm::Type::getInt32Ty(context));
      } else if (dynamic_cast<typeAST*>(
                     (dynamic_cast<nonleafAST*>(this->children[1])
                          ->children)[0])
                     ->type == 6) {
        return typeCast(tmpvalue, llvm::Type::getFloatTy(context));
      }
    }
  }
  return nullptr;
}

llvm::Value* multiplicative_expression::CodeGen() {
#ifdef DEBUG
  cout << "multiplicative_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "multiplicative_expression error in leaf node: cast_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      // llvm::Value* rs = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "multiplicative_expression in leaf node: multiplicative_expression "
            "or cast_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "multiplicative_expression error: bool type could not associate "
            "with '*' operator");
      } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                 tmpvalue2->getType() == llvm::Type::getInt8Ty(context)) {
        return IRError(
            "multiplicative_expression error: char type could not associate "
            "with '*' operator");
      } else {
        if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
            tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
          tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
          tmpvalue2 = typeCast(tmpvalue2, llvm::Type::getFloatTy(context));
          return builder.CreateFMul(tmpvalue1, tmpvalue2, "tmpmulf");
        } else {
          return builder.CreateMul(tmpvalue1, tmpvalue2, "tmpmul");
        }
      }
    }
    case 3: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      // llvm::Value* rs = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "multiplicative_expression error in leaf node: "
            "multiplicative_expression or cast_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "multiplicative_expression error: bool type could not associate "
            "with '/' operator");
      } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                 tmpvalue2->getType() == llvm::Type::getInt8Ty(context)) {
        return IRError(
            "multiplicative_expression error: char type could not associate "
            "with '/' operator");
      } else {
        tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
        tmpvalue2 = typeCast(tmpvalue2, llvm::Type::getFloatTy(context));
        return builder.CreateFDiv(tmpvalue1, tmpvalue2, "tmpdivf");
      }
    }
    case 4: {
      // '%' operator is not finished.
    }
  }
  return nullptr;
}
llvm::Value* additive_expression::CodeGen() {
#ifdef DEBUG
  cout << "additive_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "additive_expression error in leaf node: "
            "multiplicative_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      // llvm::Value* rs = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "additive_expression error in leaf node: additive_expression or "
            "multiplicative_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "additive_expression error: bool type could not associate with '+' "
            "operator");
      } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                 tmpvalue2->getType() == llvm::Type::getInt8Ty(context)) {
        if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
            tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
          return IRError(
              "additive_expression error: char type could not connected with "
              "float type by '+' operator");
        } else {
          tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getInt32Ty(context));
          tmpvalue2 = typeCast(tmpvalue2, llvm::Type::getInt32Ty(context));
          return builder.CreateAdd(tmpvalue1, tmpvalue2, "tmpadd");
        }

      } else {
        if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
            tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
          tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
          tmpvalue2 = typeCast(tmpvalue2, llvm::Type::getFloatTy(context));
          return builder.CreateFAdd(tmpvalue1, tmpvalue2, "tmpaddf");
        } else {
          return builder.CreateAdd(tmpvalue1, tmpvalue2, "tmpadd");
        }
      }
    }
    case 3: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      // llvm::Value* rs = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "additive_expression error in leaf node: additive_expression or "
            "multiplicative_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "additive_expression error: bool type could not associate with '-' "
            "operator");
      } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                 tmpvalue2->getType() == llvm::Type::getInt8Ty(context)) {
        if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
            tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
          return IRError(
              "additive_expression error: char type could not connected with "
              "float type by '+' operator");
        } else {
          tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getInt32Ty(context));
          tmpvalue2 = typeCast(tmpvalue2, llvm::Type::getInt32Ty(context));
          return builder.CreateSub(tmpvalue1, tmpvalue2, "tmpsub");
        }

      } else {
        if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
            tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
          tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
          tmpvalue2 = typeCast(tmpvalue2, llvm::Type::getFloatTy(context));
          return builder.CreateFSub(tmpvalue1, tmpvalue2, "tmpsubf");
        } else {
          return builder.CreateSub(tmpvalue1, tmpvalue2, "tmpsub");
        }
      }
    }
  }
  return nullptr;
}

llvm::Value* shift_expression::CodeGen() {
#ifdef DEBUG
  cout << "shift_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1:
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "shift_expression error in leaf node: additive_expression");
      } else {
        return tmp;
      }
  }
  return nullptr;
}

llvm::Value* relational_expression::CodeGen() {
#ifdef DEBUG
  cout << "relational_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "relational_expression error in leaf node: shift_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "relation_expression error in leaf node: relation_expression or "
            "shift_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "relation_expression error: bool type could not associate with '<' "
            "operator");
      } else if (tmpvalue1->getType() != tmpvalue2->getType()) {
        return IRError(
            "relation_expression error: two different type connected with '<' "
            "operator");
      } else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
                 tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
        return builder.CreateFCmpOLT(tmpvalue1, tmpvalue2, "tmpcmpf");
      } else {
        return builder.CreateICmpSLT(tmpvalue1, tmpvalue2, "tmpcmp");
      }
    }
    case 3: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "relation_expression error in leaf node: relation_expression or "
            "shift_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "relation_expression error: bool type could not associate with '>' "
            "operator");
      } else if (tmpvalue1->getType() != tmpvalue2->getType()) {
        return IRError(
            "relation_expression error: two different type connected with '>' "
            "operator");
      } else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
                 tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
        return builder.CreateFCmpOGT(tmpvalue1, tmpvalue2, "tmpcmpf");
      } else {
        return builder.CreateICmpSGT(tmpvalue1, tmpvalue2, "tmpcmp");
      }
    }
    case 4: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "relation_expression error in leaf node: relation_expression or "
            "shift_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "relation_expression error: bool type could not associate with "
            "'<=' operator");
      } else if (tmpvalue1->getType() != tmpvalue2->getType()) {
        return IRError(
            "relation_expression error: two different type connected with '<=' "
            "operator");
      } else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
                 tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
        return builder.CreateFCmpOLE(tmpvalue1, tmpvalue2, "tmpcmpf");
      } else {
        return builder.CreateICmpSLE(tmpvalue1, tmpvalue2, "tmpcmp");
      }
    }
    case 5: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "relation_expression error in leaf node: relation_expression or "
            "shift_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "relation_expression error: bool type could not associate with "
            "'>=' operator");
      } else if (tmpvalue1->getType() != tmpvalue2->getType()) {
        return IRError(
            "relation_expression error: two different type connected with '>=' "
            "operator");
      } else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
                 tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
        return builder.CreateFCmpOGE(tmpvalue1, tmpvalue2, "tmpcmpf");
      } else {
        return builder.CreateICmpSGE(tmpvalue1, tmpvalue2, "tmpcmp");
      }
    }
  }
  return nullptr;
}

llvm::Value* equality_expression::CodeGen() {
#ifdef DEBUG
  cout << "equality_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "equality_expression error in leaf node: relation_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "equality_expression error in leaf node: equality_expression or "
            "relation_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "equality_expression error: bool type could not associate with "
            "'==' operator");
      }
      // else if(tmpvalue1->getType() != tmpvalue2->getType()){
      //   return IRError("equality_expression error: two different type
      //   connected with '==' operator");
      // }
      else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
               tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
        return builder.CreateFCmpOEQ(tmpvalue1, tmpvalue2, "tmpcmpf");
      } else {
        if (tmpvalue1->getType() != tmpvalue2->getType()) {
          tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getInt8Ty(context));
          tmpvalue2 = typeCast(tmpvalue2, llvm::Type::getInt8Ty(context));
        }
        return builder.CreateICmpEQ(tmpvalue1, tmpvalue2, "tmpcmp");
      }
    }
    case 3: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue2 = nullptr;
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "equality_expression error in leaf node: equality_expression or "
            "relation_expression");
      } else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp2->getType()->isPointerTy() &&
            !(tmp2->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue2 = builder.CreateLoad(
              tmp2->getType()->getPointerElementType(), tmp2, "tmpvar");
        } else {
          tmpvalue2 = tmp2;
        }
      }
      if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
          tmpvalue2->getType() == llvm::Type::getInt1Ty(context)) {
        return IRError(
            "equality_expression error: bool type could not associate with "
            "'!=' operator");
      }
      // else if(tmpvalue1->getType() != tmpvalue2->getType()){
      //   return IRError("equality_expression error: two different type
      //   connected with '!=' operator");
      // }
      else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
               tmpvalue2->getType() == llvm::Type::getFloatTy(context)) {
        return builder.CreateFCmpONE(tmpvalue1, tmpvalue2, "tmpcmpf");
      } else {
        if (tmpvalue1->getType() != tmpvalue2->getType()) {
          tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getInt8Ty(context));
          tmpvalue2 = typeCast(tmpvalue2, llvm::Type::getInt8Ty(context));
        }
        return builder.CreateICmpNE(tmpvalue1, tmpvalue2, "tmpcmp");
      }
    }
  }
  return nullptr;
}

llvm::Value* and_expression::CodeGen() {
#ifdef DEBUG
  cout << "and_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1:
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "and_expression error in leaf node: equality_expression");
      } else {
        return tmp;
      }
  }
  return nullptr;
}

llvm::Value* exclusive_or_expression::CodeGen() {
#ifdef DEBUG
  cout << "exclusive_or_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1:
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "exclusive_or_expression error in leaf node: and_expression");
      } else {
        return tmp;
      }
  }
  return nullptr;
}

llvm::Value* inclusive_or_expression::CodeGen() {
#ifdef DEBUG
  cout << "inclusive_or_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1:
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "inclusive_or_expression error in leaf node: "
            "exclusive_or_expression");
      } else {
        return tmp;
      }
  }
  return nullptr;
}

llvm::Value* logical_and_expression::CodeGen() {
#ifdef DEBUG
  cout << "logical_and_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "logical_and_expression error in leaf node: "
            "inclusive_or_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "logical_and_expression error in leaf node: logical_and_expression "
            "or inclusive_or_expression");
      } else if (tmp1->getType() == llvm::Type::getInt1Ty(context) &&
                 tmp2->getType() == llvm::Type::getInt1Ty(context)) {
        return builder.CreateAnd(tmp1, tmp2, "tmpand");
      } else {
        return IRError(
            "logical_and_expression error: type float/int/char could not "
            "connected with '&&' operator");
      }
    }
  }
  return nullptr;
}

llvm::Value* logical_or_expression::CodeGen() {
#ifdef DEBUG
  cout << "logical_or_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "logical_or_expression error in leaf node: logical_and_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      llvm::Value* tmp2 = this->children[2]->CodeGen();
      if (tmp1 == nullptr || tmp2 == nullptr) {
        return IRError(
            "logical_or_expression error in leaf node: logical_or_expression "
            "or logical_and_expression");
      } else if (tmp1->getType() == llvm::Type::getInt1Ty(context) &&
                 tmp2->getType() == llvm::Type::getInt1Ty(context)) {
        return builder.CreateOr(tmp1, tmp2, "tmpor");
      } else {
        return IRError(
            "logical_or_expression error: type float/int/char could not "
            "connected with '||' operator");
      }
    }
  }
  return nullptr;
}

llvm::Value* conditional_expression::CodeGen() {
#ifdef DEBUG
  cout << "conditional_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      if (tmp == nullptr) {
        return IRError(
            "conditional_expression error in leaf node: logical_or_expression");
      } else {
        return tmp;
      }
    }
    case 2: {
      // 1;
    }
  }
  return nullptr;
}

llvm::Value* assignment_expression::CodeGen() {
#ifdef DEBUG
  cout << "assignment_expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      llvm::Value* tmpvalue = nullptr;

      if (tmp == nullptr) {
        return IRError(
            "assignment_expression error in leaf node: conditional_expression");
      } else {
        // if(tmp->getType()->isPointerTy()){
        //   cout<<tmp->getType()->getPointerElementType()->isIntegerTy()<<endl;
        // }
        // // cout<<tmp->getType()->getPointerElementType()<<endl;
        // if (tmp->getType()->isPointerTy() &&
        // (tmp->getType()->getPointerElementType() !=
        // llvm::Type::getInt8Ty(context))) {
        //     tmpvalue =
        //     builder.CreateLoad(tmp->getType()->getPointerElementType(), tmp,
        //     "tmpvar");
        // }
        // else {
        //     tmpvalue = tmp;
        // }
        return tmp;
      }
    }
    case 2: {
      llvm::Value* tmp1 = this->children[0]->CodeGen();
      // llvm::Value* tmp2 = this->children[1]->CodeGen();
      llvm::Value* tmp3 = this->children[2]->CodeGen();
      llvm::Value* tmpvalue1 = nullptr;
      llvm::Value* tmpvalue3 = nullptr;
      if (tmp1 == nullptr || tmp3 == nullptr) {
        return IRError(
            "assignment_expression error in leaf node: assignment_expression "
            "or conditional_expression");
      }
      // else if(tmp1->getType() != tmp3->getType()){
      //     return IRError("assignment_expression error in leaf node: two
      //     different type could not be connected by assignment_operator");
      // }
      else {
        if (tmp1->getType()->isPointerTy() &&
            !(tmp1->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue1 = builder.CreateLoad(
              tmp1->getType()->getPointerElementType(), tmp1, "tmpvar");
        } else {
          tmpvalue1 = tmp1;
        }
        if (tmp3->getType()->isPointerTy() &&
            !(tmp3->getType()->getPointerElementType()->isArrayTy())) {
          tmpvalue3 = builder.CreateLoad(
              tmp3->getType()->getPointerElementType(), tmp3, "tmpvar");
        } else {
          tmpvalue3 = tmp3;
        }

        if ((dynamic_cast<operatorAST*>(this->children[1]))->op.compare("=") ==
            0) {
          if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
              tmpvalue3->getType() == llvm::Type::getInt1Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: bool type could not "
                "be connected by assignment_operator");
          } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                     tmpvalue3->getType() == llvm::Type::getInt8Ty(context)) {
            // return IRError("assignment_expression error in leaf node: char
            // type could not be connected by assignment_operator");
            tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getInt8Ty(context));
            tmpvalue3 = typeCast(tmpvalue3, llvm::Type::getInt8Ty(context));
            builder.CreateStore(tmpvalue3, tmp1);
            return tmpvalue3;
          } else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
                     tmpvalue3->getType() == llvm::Type::getFloatTy(context)) {
            tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
            tmpvalue3 = typeCast(tmpvalue3, llvm::Type::getFloatTy(context));
            builder.CreateStore(tmpvalue3, tmp1);
            return tmpvalue3;
          } else {
            builder.CreateStore(tmpvalue3, tmp1);
            return tmpvalue3;
          }
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("*=") == 0) {
          if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
              tmpvalue3->getType() == llvm::Type::getInt1Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: bool type could not "
                "be connected by '*=' operator");
          } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                     tmpvalue3->getType() == llvm::Type::getInt8Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: char type could not "
                "be connected by '*=' operator");
          } else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
                     tmpvalue3->getType() == llvm::Type::getFloatTy(context)) {
            tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
            tmpvalue3 = typeCast(tmpvalue3, llvm::Type::getFloatTy(context));
            llvm::Value* tmpexp =
                builder.CreateFMul(tmpvalue1, tmpvalue3, "tmpmulf");
            builder.CreateStore(tmpexp, tmp1);
            return tmpexp;
          } else {
            llvm::Value* tmpexp =
                builder.CreateMul(tmpvalue1, tmpvalue3, "tmpmul");
            builder.CreateStore(tmpexp, tmp1);
            return tmpexp;
          }
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("/=") == 0) {
          if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
              tmpvalue3->getType() == llvm::Type::getInt1Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: bool type could not "
                "be connected by '/=' operator");
          } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                     tmpvalue3->getType() == llvm::Type::getInt8Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: char type could not "
                "be connected by '/=' operator");
          } else {
            tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
            tmpvalue3 = typeCast(tmpvalue3, llvm::Type::getFloatTy(context));
            llvm::Value* tmpexp =
                builder.CreateFDiv(tmpvalue1, tmpvalue3, "tmpdivf");
            builder.CreateStore(tmpexp, tmp1);
            return tmpexp;
          }
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("MOD_ASSIGN") == 0) {
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("+=") == 0) {
          if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
              tmpvalue3->getType() == llvm::Type::getInt1Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: bool type could not "
                "be connected by '+=' operator");
          } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                     tmpvalue3->getType() == llvm::Type::getInt8Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: char type could not "
                "be connected by '+=' operator");
          } else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
                     tmpvalue3->getType() == llvm::Type::getFloatTy(context)) {
            tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
            tmpvalue3 = typeCast(tmpvalue3, llvm::Type::getFloatTy(context));
            llvm::Value* tmpexp =
                builder.CreateFAdd(tmpvalue1, tmpvalue3, "tmpaddf");
            builder.CreateStore(tmpexp, tmp1);
            return tmpexp;
          } else {
            llvm::Value* tmpexp =
                builder.CreateAdd(tmpvalue1, tmpvalue3, "tmpadd");
            builder.CreateStore(tmpexp, tmp1);
            return tmpexp;
          }
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("-=") == 0) {
          if (tmpvalue1->getType() == llvm::Type::getInt1Ty(context) ||
              tmpvalue3->getType() == llvm::Type::getInt1Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: bool type could not "
                "be connected by '-=' operator");
          } else if (tmpvalue1->getType() == llvm::Type::getInt8Ty(context) ||
                     tmpvalue3->getType() == llvm::Type::getInt8Ty(context)) {
            return IRError(
                "assignment_expression error in leaf node: char type could not "
                "be connected by '-=' operator");
          } else if (tmpvalue1->getType() == llvm::Type::getFloatTy(context) ||
                     tmpvalue3->getType() == llvm::Type::getFloatTy(context)) {
            tmpvalue1 = typeCast(tmpvalue1, llvm::Type::getFloatTy(context));
            tmpvalue3 = typeCast(tmpvalue3, llvm::Type::getFloatTy(context));
            llvm::Value* tmpexp =
                builder.CreateFSub(tmpvalue1, tmpvalue3, "tmpsubf");
            builder.CreateStore(tmpexp, tmp1);
            return tmpexp;
          } else {
            llvm::Value* tmpexp =
                builder.CreateSub(tmpvalue1, tmpvalue3, "tmpsub");
            builder.CreateStore(tmpexp, tmp1);
            return tmpexp;
          }
        }
        // logical operator unfinished
        else if ((dynamic_cast<operatorAST*>(this->children[1]))
                     ->op.compare("LEFT_ASSIGN") == 0) {
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("RIGHT_ASSIGN") == 0) {
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("AND_ASSIGN") == 0) {
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("XOR_ASSIGN") == 0) {
        } else if ((dynamic_cast<operatorAST*>(this->children[1]))
                       ->op.compare("OR_ASSIGN") == 0) {
        }
        return IRError(
            "assignment_expression error: unknown assignment_operator");
      }
    }
  }
  return nullptr;
}

llvm::Value* assignment_operator::CodeGen() {
#ifdef DEBUG
  cout << "assignment_expression type:" << this->type << endl;
#endif
  return nullptr;
}

// llvm::Value* type_specifier::CodeGen() {
//   switch (this->type) {
//   case 1:
//     this->type_spec = llvm::Type::getVoidTy(context);
//   case 2:
//     this->type_spec = llvm::Type::getInt8Ty(context);
//   case 3:
//     this->type_spec = llvm::Type::getInt16Ty(context);
//   case 4:
//     this->type_spec = llvm::Type::getInt32Ty(context);
//   case 5:
//     this->type_spec = llvm::Type::getInt64Ty(context);
//   case 6:
//     this->type_spec = llvm::Type::getFloatTy(context);
//   case 7:
//     this->type_spec = llvm::Type::getDoubleTy(context);
//   }
//   return nullptr;
// }

Value* expression::CodeGen() {
#ifdef DEBUG
  cout << "expression type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      llvm::Value* tmp = this->children[0]->CodeGen();
      llvm::Value* tmpvalue;
      if (tmp->getType()->isPointerTy() &&
          !(tmp->getType()->getPointerElementType()->isArrayTy())) {
        tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                      tmp, "tmpvar");
      } else {
        tmpvalue = tmp;
      }
      return tmpvalue;
    }
    case 2: {
      this->children[0]->CodeGen();

      llvm::Value* tmp = this->children[2]->CodeGen();
      llvm::Value* tmpvalue;
      if (tmp->getType()->isPointerTy() &&
          !(tmp->getType()->getPointerElementType()->isArrayTy())) {
        tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                      tmp, "tmpvar");
      } else {
        tmpvalue = tmp;
      }
      return tmpvalue;
    }
  }
  return nullptr;
}

// done
llvm::Value* parameter_declaration::CodeGen() {  // here
#ifdef DEBUG
  cout << "parameter_declaration type:" << this->type << endl;
#endif
  this->clear();
  Type* type_spec = get_type(dynamic_cast<typeAST*>(this->children[0])->type);
  this->children[1]->CodeGen();
  if (dynamic_cast<declarator*>(this->children[1])->is_array()) {
    type_spec = PointerType::getUnqual(build_array(
        type_spec, dynamic_cast<declarator*>(this->children[1])->array_size));
  }
  this->name = dynamic_cast<declarator*>(this->children[1])->name;
  this->type_spec = type_spec;
  return nullptr;
}

// done
llvm::Value* parameter_list::CodeGen() {
#ifdef DEBUG
  cout << "parameter_list type:" << this->type << endl;
#endif
  this->clear();
  switch (this->type) {
    case 1: {
      this->children[0]->CodeGen();
      parameter_declaration* decl =
          dynamic_cast<parameter_declaration*>(this->children[0]);
      this->para_name.push_back(decl->name);
      this->para_type.push_back(decl->type_spec);
      break;
    }
    case 2: {
      this->children[0]->CodeGen();
      parameter_list* decl_list =
          dynamic_cast<parameter_list*>(this->children[0]);
      this->children[2]->CodeGen();
      parameter_declaration* decl =
          dynamic_cast<parameter_declaration*>(this->children[2]);
      this->para_name = decl_list->para_name;
      this->para_type = decl_list->para_type;
      this->para_name.push_back(decl->name);
      this->para_type.push_back(decl->type_spec);
      break;
    }
  }
  return nullptr;
}

// done
llvm::Value* function_definition::CodeGen() {
#ifdef DEBUG
  cout << "function_definition type:" << this->type << endl;
#endif
  Type* type_spec = get_type(dynamic_cast<typeAST*>(this->children[0])->type);
  llvm::Type* return_type = type_spec;
  declarator* prototype = dynamic_cast<declarator*>(this->children[1]);
  prototype->CodeGen();
  FunctionType* func_type =
      FunctionType::get(return_type, prototype->para_type, false);
  Function* func = Function::Create(func_type, Function::ExternalLinkage,
                                    prototype->name, generator->module);
  int para_ptr = 0;
  for (Function::arg_iterator it = func->arg_begin(); it != func->arg_end();
       ++it, ++para_ptr) {
    if (!it->getType()->isPointerTy()) {
      it->setName((prototype->para_name[para_ptr] + "para"));
    } else {
      it->setName((prototype->para_name[para_ptr]));
    }
  }
  BasicBlock* BB = BasicBlock::Create(context, prototype->name, func);
  builder.SetInsertPoint(BB);
  para_ptr = 0;
  for (Function::arg_iterator it = func->arg_begin(); it != func->arg_end();
       ++it, ++para_ptr) {
    if (!it->getType()->isPointerTy()) {
      Value* ptr = builder.CreateAlloca(it->getType(), nullptr,
                                        prototype->para_name[para_ptr]);
      builder.CreateStore(it, ptr);
    }
    // } else {
    //   //       builder.CreateInBoundsGEP();
    //   vector<llvm::Value*> indexList;
    //   indexList.push_back(builder.getInt32(0));
    //   indexList.push_back(builder.getInt32(0));
    //   llvm::Value * varPtr = builder.CreateInBoundsGEP(it,
    //   llvm::ArrayRef<llvm::Value*>(indexList), "tmpvar"); cout << varPtr << "
    //   " << type2str(varPtr);
    //   //return varPtr;
    // }
  }
  compound_statement* body =
      dynamic_cast<compound_statement*>(this->children[2]);
  // Value* ret_val =
  body->CodeGen();
  // builder.CreateRet(ret_val);
  verifyFunction(*func);
  return func;
}

// done
llvm::Value* declarator::CodeGen() {
#ifdef DEBUG
  cout << "declarator type:" << this->type << endl;
#endif
  this->clear();
  switch (this->type) {
    case 1: {
      this->name = dynamic_cast<identifierAST*>(this->children[0])->identifier;
      break;
    }
    case 2: {
      this->children[1]->CodeGen();
      break;
    }
    case 3: {
      // int a[][3]
      this->children[0]->CodeGen();
      this->name = dynamic_cast<declarator*>(this->children[0])->name;
      this->array_size =
          dynamic_cast<declarator*>(this->children[0])->array_size;
      this->array_size.push_back(
          cast<ConstantInt>(this->children[2]->CodeGen()));
      break;
    }
    case 4: {
      // int a[]
      this->children[0]->CodeGen();
      this->name = dynamic_cast<declarator*>(this->children[0])->name;
      this->array_size =
          dynamic_cast<declarator*>(this->children[0])->array_size;
      this->array_size.push_back(0);
      break;
    }
    case 5: {
      this->children[0]->CodeGen();
      this->children[2]->CodeGen();
      parameter_list* para_list =
          dynamic_cast<parameter_list*>(this->children[2]);
      this->para_name = para_list->para_name;
      this->para_type = para_list->para_type;
      this->name = dynamic_cast<declarator*>(this->children[0])->name;
      break;
    }
    case 6: {
      this->children[0]->CodeGen();
      this->para_name = vector<string>();
      this->para_type = ArrayRef<Type*>();
      this->name = dynamic_cast<declarator*>(this->children[0])->name;
      break;
    }
  }
  return nullptr;
}

llvm::Value* init_declarator::CodeGen() {
#ifdef DEBUG
  cout << "init_declarator type:" << this->type << endl;
#endif
  this->clear();
  this->children[0]->CodeGen();
  declarator* decl = dynamic_cast<declarator*>(this->children[0]);
  // cout << decl->name << endl;
  switch (this->type) {
    case 1: {
      this->decl = decl;
      this->value = nullptr;
      break;
    }
    case 2: {
      this->decl = decl;
      llvm::Value* tmp = this->children[2]->CodeGen();
      llvm::Value* tmpvalue;
      if (tmp->getType()->isPointerTy() &&
          !(tmp->getType()->getPointerElementType()->isArrayTy())) {
        tmpvalue = builder.CreateLoad(tmp->getType()->getPointerElementType(),
                                      tmp, "tmpvar");
      } else {
        tmpvalue = tmp;
      }
      this->value = tmpvalue;
      break;
    }
  }
  return nullptr;
}

llvm::Value* init_declarator_list::CodeGen() {
#ifdef DEBUG
  cout << "init_declarator_list type:" << this->type << endl;
#endif
  this->clear();
  switch (this->type) {
    case 1: {
      this->children[0]->CodeGen();
      this->list.push_back(dynamic_cast<init_declarator*>(this->children[0]));
      break;
    }
    case 2: {
      this->children[0]->CodeGen();
      this->children[2]->CodeGen();
      this->list = dynamic_cast<init_declarator_list*>(this->children[0])->list;
      this->list.push_back(dynamic_cast<init_declarator*>(this->children[2]));
      break;
    }
  }
  return nullptr;
}

// done
llvm::Value* declaration::CodeGen() {
#ifdef DEBUG
  cout << "declaration type:" << this->type << endl;
#endif
  this->children[0]->CodeGen();
  this->children[1]->CodeGen();
  Type* type_spec = get_type(dynamic_cast<typeAST*>(this->children[0])->type);
  vector<init_declarator*> decl_list =
      dynamic_cast<init_declarator_list*>(this->children[1])->list;
  for (int i = 0; i < decl_list.size(); ++i) {
    Type* type_spec_local = type_spec;
    int is_array = decl_list[i]->decl->is_array();
    if (is_array) {
      type_spec_local =
          build_array_with_size(type_spec, decl_list[i]->decl->array_size);
    }
    AllocaInst* alloc = builder.CreateAlloca(type_spec_local, nullptr,
                                             decl_list[i]->decl->name);
    if (!is_array && decl_list[i]->value) {
      builder.CreateStore(decl_list[i]->value, alloc);
    }
  }
}

// done
llvm::Value* declaration_list::CodeGen() {
#ifdef DEBUG
  cout << "declaration_list type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      this->children[0]->CodeGen();
      break;
    }
    case 2: {
      this->children[0]->CodeGen();
      this->children[1]->CodeGen();
      break;
    }
  }
  return nullptr;
}

// done
llvm::Value* statement::CodeGen() {
#ifdef DEBUG
  cout << "statement type:" << this->type << endl;
#endif
  this->children[0]->CodeGen();
}

llvm::Value* expression_statement::CodeGen() {
#ifdef DEBUG
  cout << "expression_statement type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      break;
    }
    case 2: {
      return this->children[0]->CodeGen();
      break;
    }
  }
  return nullptr;
}

llvm::Value* selection_statement::CodeGen() {
#ifdef DEBUG
  cout << "selection_statement type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      Function* func = builder.GetInsertBlock()->getParent();
      BasicBlock* ThenBB = BasicBlock::Create(context, "then", func);
      BasicBlock* ElseBB = BasicBlock::Create(context, "else", func);
      BasicBlock* MergeBB = BasicBlock::Create(context, "merge", func);
      Value* cond = this->children[2]->CodeGen();
      builder.CreateCondBr(cond, ThenBB, ElseBB);
      builder.SetInsertPoint(ThenBB);
      this->children[4]->CodeGen();
      builder.CreateBr(MergeBB);
      builder.SetInsertPoint(ElseBB);
      builder.CreateBr(MergeBB);
      builder.SetInsertPoint(MergeBB);
      break;
    }
    case 2: {
      Function* func = builder.GetInsertBlock()->getParent();
      BasicBlock* ThenBB = BasicBlock::Create(context, "then", func);
      BasicBlock* ElseBB = BasicBlock::Create(context, "else", func);
      BasicBlock* MergeBB = BasicBlock::Create(context, "merge", func);
      Value* cond = this->children[2]->CodeGen();
      builder.CreateCondBr(cond, ThenBB, ElseBB);
      builder.SetInsertPoint(ThenBB);
      this->children[4]->CodeGen();
      builder.CreateBr(MergeBB);
      builder.SetInsertPoint(ElseBB);
      this->children[6]->CodeGen();
      builder.CreateBr(MergeBB);
      builder.SetInsertPoint(MergeBB);
      break;
    }
  }
  return nullptr;
}

stack<BasicBlock*> continue_lable;
stack<BasicBlock*> break_lable;

llvm::Value* iteration_statement::CodeGen() {
#ifdef DEBUG
  cout << "iteration_statement type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      //     BasicBlock *ThenBB = BasicBlock::Create(context, "then", func);
      Function* func = builder.GetInsertBlock()->getParent();
      BasicBlock* loop = BasicBlock::Create(context, "whileloop", func);
      BasicBlock* cont = BasicBlock::Create(context, "whilecont", func);
      Value* cond_value = this->children[2]->CodeGen();
      builder.CreateCondBr(cond_value, loop, cont);
      builder.SetInsertPoint(loop);
      this->children[4]->CodeGen();
      cond_value = this->children[2]->CodeGen();
      builder.CreateCondBr(cond_value, loop, cont);
      builder.SetInsertPoint(cont);
      break;
    }
    case 2: {
      // for loop
    }
    case 3: {
    }
    case 4: {
      Function* func = builder.GetInsertBlock()->getParent();
      // expression_statement* init =
      // dynamic_cast<expression_statement*>(this->children[2]);
      expression_statement* cond =
          dynamic_cast<expression_statement*>(this->children[3]);
      expression* incr = this->type == 2
                             ? nullptr
                             : dynamic_cast<expression*>(this->children[4]);
      statement* body = dynamic_cast<statement*>(
          this->type == 2 ? this->children[5] : this->children[6]);
      // init->CodeGen();
      this->children[2]->CodeGen();
      BasicBlock* cont = BasicBlock::Create(context, "forcont", func);
      BasicBlock* add = BasicBlock::Create(context, "foradd", func, cont);
      BasicBlock* loop = BasicBlock::Create(context, "forloop", func, add);

      continue_lable.push(add);
      break_lable.push(cont);
      Value* cond_value = cond->CodeGen();
      builder.CreateCondBr(cond_value, loop, cont);
      builder.SetInsertPoint(loop);
      body->CodeGen();
      builder.CreateBr(add);
      builder.SetInsertPoint(add);
      if (incr) {
        incr->CodeGen();
      }
      cond_value = cond->CodeGen();
      builder.CreateCondBr(cond_value, loop, cont);
      builder.SetInsertPoint(cont);
      continue_lable.pop();
      break_lable.pop();
      break;
    }
  }
}

llvm::Value* jump_statement::CodeGen() {
#ifdef DEBUG
  cout << "jump_statement type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      BasicBlock* br = continue_lable.top();
      builder.CreateBr(br);
      break;
    }
    case 2: {
      BasicBlock* br = break_lable.top();
      builder.CreateBr(br);
      break;
    }
    case 3: {
      builder.CreateRetVoid();
      break;
    }
    case 4: {
      Value* return_value = this->children[1]->CodeGen();
      builder.CreateRet(return_value);
      break;
    }
  }
  return nullptr;
}

llvm::Value* translation_unit::CodeGen() {
#ifdef DEBUG
  cout << "translation_unit type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      this->children[0]->CodeGen();
      break;
    }
    case 2: {
      this->children[0]->CodeGen();
      this->children[1]->CodeGen();
      break;
    }
  }
  return nullptr;
}

llvm::Value* external_declaration::CodeGen() {
#ifdef DEBUG
  cout << "external_declaration type:" << this->type << endl;
#endif
  switch (this->type) {
    case 1: {
      this->children[0]->CodeGen();
      break;
    }
    case 2: {
      this->children[0]->CodeGen();
      this->children[1]->CodeGen();
      vector<init_declarator*> list =
          dynamic_cast<init_declarator_list*>(this->children[1])->list;
      Type* type_spec =
          get_type(dynamic_cast<typeAST*>(this->children[0])->type);
      for (int i = 0; i < list.size(); ++i) {
        Type* type_local = type_spec;
        if (list[i]->decl->is_array()) {
          type_local = build_array(type_spec, list[i]->decl->array_size);
        }
        generator->module->getOrInsertGlobal(list[i]->decl->name, type_local);
        if (!list[i]->decl->is_array()) {
          GlobalVariable* gVar =
              generator->module->getNamedGlobal(list[i]->decl->name);
          gVar->setInitializer(cast<Constant>(list[i]->value));
        } else {
          GlobalVariable* gVar =
              generator->module->getNamedGlobal(list[i]->decl->name);
          ConstantAggregateZero* const_array_2 =
              ConstantAggregateZero::get(type_local);
          gVar->setInitializer(const_array_2);
        }
      }
    }
  }
}

llvm::Value* constant_expression::CodeGen() {
#ifdef DEBUG
  cout << "constant_expression type:" << this->type << endl;
#endif
  return this->children[0]->CodeGen();
}

llvm::Value* statement_list::CodeGen() {
  switch (this->type) {
    case 1: {
      this->children[0]->CodeGen();
      break;
    }
    case 2: {
      this->children[0]->CodeGen();
      this->children[1]->CodeGen();
      break;
    }
  }
  return nullptr;
}

llvm::Value* compound_statement::CodeGen() {
  switch (this->type) {
    case 1: {
      break;
    }
    case 2: {
      this->children[1]->CodeGen();
      break;
    }
    case 3: {
      this->children[1]->CodeGen();
      break;
    }
    case 4: {
      this->children[1]->CodeGen();
      this->children[2]->CodeGen();
      break;
    }
  }
  return nullptr;
}

llvm::Type* build_array(Type* array_type, vector<ConstantInt*> array_size) {
  // if (array_size.size() > 1) {
  //   ArrayType* array = ArrayType::get(array_type,
  //   array_size.back()->getZExtValue()); for (int i = (int)array_size.size() -
  //   2; i >= 1; --i) {
  //     array = ArrayType::get(array, array_size[i]->getZExtValue());
  //   }
  //   array = ArrayType::get(array, 0);
  //   return array;
  // } else {
  //   return ArrayType::get(array_type, 0);
  // }
  ArrayType* array =
      ArrayType::get(array_type, array_size.back()->getZExtValue());
  for (int i = (int)array_size.size() - 2; i >= 0; --i) {
    array = ArrayType::get(array, array_size[i]->getZExtValue());
  }
  return array;
}

llvm::Type* build_array_with_size(Type* array_type,
                                  vector<ConstantInt*> array_size) {
  ArrayType* array =
      ArrayType::get(array_type, array_size.back()->getZExtValue());
  for (int i = (int)array_size.size() - 2; i >= 0; --i) {
    array = ArrayType::get(array, array_size[i]->getZExtValue());
  }
  return array;
}
// codeGen * codegen = new codeGen();

// codeGen::~codeGen() {}
// */
