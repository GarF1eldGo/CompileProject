#ifndef _AST_H_
#define _AST_H_

#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include <json/json.h>

#include <llvm/IR/Value.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/GlobalVariable.h>
#include "llvm/IR/Verifier.h"

// #define TYPENONE 0
// #define TYPEINT 1
// #define TYPEFLOAT 2
// #define TYPEBOOL 3
// #define TYPEICHAR 4

using namespace std;
// using namespace llvm;

using namespace llvm;
using namespace std;

static unique_ptr<LLVMContext> TheContext;
static unique_ptr<Module> TheModule;
static unique_ptr<IRBuilder<>> Builder;

static void InitializeModule() {
  TheContext = std::make_unique<LLVMContext>();
  TheModule = std::make_unique<Module>("first modlue", *TheContext);
  Builder = std::make_unique<IRBuilder<>>(*TheContext);
}





//基类
class exprAST{
public:
  string name;//用于AST可视化

    // int valuetype = TYPENONE;//节点数据类型
    //virtual Value *Codegen();
    void createJsonFile(string fileName);
    virtual Json::Value buildJsonAST(){};
    virtual llvm::Value *CodeGen(){};

};



//叶子结点
class leafAST : public exprAST{
public:
  //virtual ~leafAST(){}
    
  void createJsonFile(string fileName);
  Json::Value buildJsonAST();
};



//非叶子结点
class nonleafAST : public exprAST{
public:
  //string name;
  int type;
  vector<exprAST*> children;

  void createJsonFile(string fileName);
  Json::Value buildJsonAST();

  nonleafAST(string name, int type, vector<exprAST*> children);
};


/*
  ===========================叶子结点的相关类================================
*/


//常量结点
//int type : 表示该常量的类型。为1表示整数，为2表示浮点数
//double value : 表示该常量的值
class constantAST : public leafAST{
public:
  int type;
  double value;

  constantAST(int type,double value);
};



//字符串结点
//string value : 表示该字符串的值
class stringAST : public leafAST{
public:
  string value;
  stringAST(string value);
};



//操作符结点
//string op : 记录操作符的string表示
class operatorAST : public leafAST{
public:
  string op;
  operatorAST(string op);
};



//标识符结点
//string name : 记录标识符的名称
class identifierAST : public leafAST{
public:
  string identifier;
  identifierAST(string identifier);
};



//类型结点
//int type : 记录类型 
  //type = 1 : void
  //type = 2 : char
  //type = 3 : short
  //type = 4 : int
  //type = 5 : long
  //type = 6 : float
  //type = 7 : double
class typeAST : public leafAST{
public:
  int type;
  typeAST(int type);
};



//关键字结点
//string name : 记录关键字的名称
class keywordAST : public leafAST{
public:
  string keyword;
  keywordAST(string keyword);
};



//标点结点
class punctuationAST : public leafAST{
public:
  string punctuation;
  punctuationAST(string punctuation);
};



/*
  ===========================非叶子结点的相关类================================
*/

class primary_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class postfix_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class argument_expression_list : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen(); vector<llvm::Value *> *ArgGen();};

class unary_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class unary_operator : public nonleafAST{ public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class cast_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class multiplicative_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class additive_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class shift_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class relational_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class equality_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class and_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class exclusive_or_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class inclusive_or_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class logical_and_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class logical_or_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class conditional_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class assignment_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class assignment_operator : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class constant_expression : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class declaration : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class init_declarator : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class init_declarator_list : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class declaration_specifiers : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class type_specifier : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class declarator : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class direct_declarator : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class parameter_type_list : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class parameter_list : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class parameter_declaration : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class type_name : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class statement : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class compound_statement : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class declaration_list : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class statement_list : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class expression_statement : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class selection_statement : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class iteration_statement : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class jump_statement : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class translation_unit : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class external_declaration : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};

class function_definition : public nonleafAST {public: using nonleafAST::nonleafAST; llvm::Value *CodeGen();};


// nonleafAST* new_nonleafAST(string name, int type, int childNum, ...);
// nonleafAST* new_nonleafAST(string name, int type);

#endif
