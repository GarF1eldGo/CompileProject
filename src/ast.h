#ifndef _AST_H_
#define _AST_H_

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

//将结点分为两种：叶子结点（终结符token），非叶子结点（非终结符grammar）


//基类
class exprAST{
public:
    virtual ~exprAST(){}
};



//叶子结点
//终结符包括：constant,string_literal,operator,identifier,type,keyword
//constant包括：整数，浮点数，字符串
//operator包括：+,-,*,/,%,++,--,=,==,!=,>,<,>=,<=,&&,||,!,<<=,>>=,+=,-=,*=,/=,%=,&=,|=,^=
//identifier包括：标识符
//type包括：void,char,short,int,long,float,double
//keyword包括：if,else,while,for,break,continue,return
class leafAST : public exprAST{
public:
    virtual ~leafAST(){}
};



//非叶子结点
//string name : 表示该非终结符的名称
//int type : 表示使用该非终结符的第type个文法规则
//vector<exprAST*> children : 表示所有的孩子结点
class nonleafAST : public exprAST{
public:
    string name;
    int type;
    vector<exprAST*> children;

    nonleafAST(string name, int type, int childNum, ...);
    nonleafAST(string name, int type);
};



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
    string name;
    identifierAST(string name);
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
    string name;
    keywordAST(string name);
};

#endif