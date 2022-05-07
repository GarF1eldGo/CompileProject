#include"ast.h"

//ROOT表示AST的根节点
exprAST* ROOT = new exprAST();


void exprAST::visualizeAST(string fileName){
    ofstream outFile;
    outFile.open(fileName);
    
}


//非终结符结点的构造函数
nonleafAST::nonleafAST(string name, int type, int childNum, ...)
{
    this->name = name;
    this->type = type;

    va_list ap;
    va_start(ap, childNum);
    for(int i=0;i<childNum;i++){
        children.push_back(va_arg(ap, exprAST*));
    }
    va_end(ap);//清理保留的内存
}


nonleafAST::nonleafAST(string name, int type)
{
    this->name = name;
    this->type = type;
}


constantAST::constantAST(int type, double value)
{
    this->type = type;
    this->value = value;
}


stringAST::stringAST(string value)
{
    this->value = value;
}


operatorAST::operatorAST(string op)
{
    this->op = op;
}


identifierAST::identifierAST(string name)
{
    this->name = name;
}


typeAST::typeAST(int type)
{
    this->type = type;
}


keywordAST::keywordAST(string name)
{
    this->name = name;
}


punctuationAST::punctuationAST(string punctuation)
{
    this->punctuation = punctuation;
}