#include "ast.h"


//ROOT表示AST的根节点
exprAST* ROOT = new exprAST();


//根据AST创建Json文件
void exprAST::createJsonFile(string fileName){
    // ofstream outFile;
    // outFile.open(fileName);
    // if(!outFile.is_open()){
    //     cout<<"open file \"" << fileName << "\" failed" << endl;
    //     return;
    // }
    // Json::Value root = buildJsonAST();
    // outFile << root;
    // outFile.close();
}


//为非叶子结点创建Json类型的AST
// Json::Value nonleafAST::buildJsonAST(){
//     Json::Value root;
//     root["name"] = name;

//     for(int i=0;i<children.size();i++){
//         root["children"].append(children[i]->buildJsonAST());
//     }

//     return root;
// }


//为叶子结点创建Json类型的AST
// Json::Value leafAST::buildJsonAST(){
//     Json::Value root;
//     root["name"] = name;
//     return root;
// }



//非终结符结点的构造函数
nonleafAST::nonleafAST(string name, int type, vector<exprAST*> children){
    this->name = name;
    this->type = type;
    this->children = children;
}

// //非终结符结点的构造函数
// nonleafAST::nonleafAST(string name, int type, int childNum, ...)
// {
//     this->name = name;
//     this->type = type;

//     va_list ap;
//     va_start(ap, childNum);
//     for(int i=0;i<childNum;i++){
//         children.push_back(va_arg(ap, exprAST*));
//     }
//     va_end(ap);//清理保留的内存
// }


// nonleafAST::nonleafAST(string name, int type)
// {
//     this->name = name;
//     this->type = type;
// }


/*
===========================叶子结点的相关类================================
*/


constantAST::constantAST(int type, double value)
{
    this->type = type;
    this->value = value;
    this->name = "constant";
}


stringAST::stringAST(string value)
{

  value.pop_back();
  value = value.erase(0, 1);
  value += '\n';
  cout << value << endl;
    this->value = value;
    this->name = "string";
}


operatorAST::operatorAST(string op)
{
    this->op = op;
    this->name = "operator";
}


identifierAST::identifierAST(string identifier)
{
    this->identifier = identifier;
    this->name = "identifier";
}


typeAST::typeAST(int type)
{
  this->type = type;
  this->name = "type";
}


keywordAST::keywordAST(string keyword)
{
    this->keyword = keyword;
    this->name = "keyword";
}


punctuationAST::punctuationAST(string punctuation)
{
    this->punctuation = punctuation;
    this->name = "punctuation";
}



/*
===========================非叶子结点的相关类================================
*/

// primaryExprAST::primaryExprAST(string name, int type, int childNum, ...)
// {
//     this->name = name;
//     this->type = type;

//     va_list ap;
//     va_start(ap, childNum);
//     for(int i=0;i<childNum;i++){
//         children.push_back(va_arg(ap, exprAST*));
//     }
//     va_end(ap);//清理保留的内存
// }


// nonleafAST* new_nonleafAST(string name, int type, vector<exprAST*>children)
// {   
//     if(!strcmp(name.c_str(),"primary_expression")){
//         return new primaryExprAST(name,type,children);
//     }
//     else if(!strcmp(name.c_str(),"postfix_expression")){
//     }


// }
