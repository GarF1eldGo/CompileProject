#ifndef _CODE_GEN_H_
#define _CODE_GEN_H_

#include <iostream>
#include "ast.h"
using namespace std;


class codeGen {
public:

    void generate(Node *root);
    codeGen();
    ~codeGen();
};



#endif