#ifndef _AST_H_
#define _AST_H_

#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include <json/json.h>

using namespace std;
//using namespace llvm;



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
    nonleafAST(string name, int type, int childNum, ...);
    nonleafAST(string name, int type);
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

class primaryExprAST : public nonleafAST{};
class postfixExprAST : public nonleafAST{};
class argumentExprListAST : public nonleafAST{};
class unaryExprAST : public nonleafAST{};
class unaryOpAST : public nonleafAST{};
class castExprAST : public nonleafAST{};
class multiplicativeExprAST : public nonleafAST{};
class additiveExprAST : public nonleafAST{};
class shiftExprAST : public nonleafAST{};
class relationalExprAST : public nonleafAST{};
class equalityExprAST : public nonleafAST{};
class andExpAST : public nonleafAST{};
class exclusiveOrExpAST : public nonleafAST{};
class inclusiveOrExpAST : public nonleafAST{};
class logicalAndExpAST : public nonleafAST{};
class logicalOrExpAST : public nonleafAST{};
class conditionalExpAST : public nonleafAST{};
class assignmentExprAST : public nonleafAST{};
class assignmentOpAST : public nonleafAST{};
class expressionAST : public nonleafAST{};
class constantExpAST : public nonleafAST{};
class declarationAST : public nonleafAST{};
class initDeclaratorAST : public nonleafAST{};
class initDeclaratorListAST : public nonleafAST{};
class declarationSpecifierAST : public nonleafAST{};
class typeSpecifierAST : public nonleafAST{};
class declaratorAST : public nonleafAST{};
class directDeclaratorAST : public nonleafAST{};
class parameterTypeListAST : public nonleafAST{};
class parameterListAST : public nonleafAST{};
class parameterDeclarationAST : public nonleafAST{};
class typeNameAST : public nonleafAST{};
class statementAST : public nonleafAST{};
class compoundStatementAST : public nonleafAST{};
class declarationListAST : public nonleafAST{};
class statementListAST : public nonleafAST{};
class expressionStatementAST : public nonleafAST{};
class selectionStatementAST : public nonleafAST{};
class iterationStatementAST : public nonleafAST{};
class jumpStatementAST : public nonleafAST{};
class translationUnitAST : public nonleafAST{};
class externalDeclarationAST : public nonleafAST{};
class functionDefinitionAST : public nonleafAST{};


#endif
