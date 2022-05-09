#ifndef _AST_H_
#define _AST_H_

#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include <json/json.h>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"

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

  //virtual Value *Codegen();
  void createJsonFile(string fileName);
  virtual Json::Value buildJsonAST(){};
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

class primary_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class postfix_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class argument_expression_list : public nonleafAST {public: using nonleafAST::nonleafAST;};

class unary_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class unary_operator : public nonleafAST{ public: using nonleafAST::nonleafAST;};

class cast_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class multiplicative_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class additive_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class shift_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class relational_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class equality_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class and_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class exclusive_or_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class inclusive_or_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class logical_and_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class logical_or_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class conditional_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class assignment_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class assignment_operator : public nonleafAST {public: using nonleafAST::nonleafAST;};

class expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class constant_expression : public nonleafAST {public: using nonleafAST::nonleafAST;};

class declaration : public nonleafAST {public: using nonleafAST::nonleafAST;};

class init_declarator : public nonleafAST {public: using nonleafAST::nonleafAST;};

class init_declarator_list : public nonleafAST {public: using nonleafAST::nonleafAST;};

class declaration_specifiers : public nonleafAST {public: using nonleafAST::nonleafAST;};

class type_specifier : public nonleafAST {public: using nonleafAST::nonleafAST;};

class declarator : public nonleafAST {public: using nonleafAST::nonleafAST;};

class direct_declarator : public nonleafAST {public: using nonleafAST::nonleafAST;};

class parameter_type_list : public nonleafAST {public: using nonleafAST::nonleafAST;};

class parameter_list : public nonleafAST {public: using nonleafAST::nonleafAST;};

class parameter_declaration : public nonleafAST {public: using nonleafAST::nonleafAST;};

class type_name : public nonleafAST {public: using nonleafAST::nonleafAST;};

class statement : public nonleafAST {public: using nonleafAST::nonleafAST;};

class compound_statement : public nonleafAST {public: using nonleafAST::nonleafAST;};

class declaration_list : public nonleafAST {public: using nonleafAST::nonleafAST;};

class statement_list : public nonleafAST {public: using nonleafAST::nonleafAST;};

class expression_statement : public nonleafAST {public: using nonleafAST::nonleafAST;};

class selection_statement : public nonleafAST {public: using nonleafAST::nonleafAST;};

class iteration_statement : public nonleafAST {public: using nonleafAST::nonleafAST;};

class jump_statement : public nonleafAST {public: using nonleafAST::nonleafAST;};

class translation_unit : public nonleafAST {public: using nonleafAST::nonleafAST;};

class external_declaration : public nonleafAST {public: using nonleafAST::nonleafAST;};

class function_definition : public nonleafAST {public: using nonleafAST::nonleafAST;};


// nonleafAST* new_nonleafAST(string name, int type, int childNum, ...);
// nonleafAST* new_nonleafAST(string name, int type);

#endif
