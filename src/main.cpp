#include <queue>
#include "ast.h"
#include "code_gen.h"
#include "grammar.hpp"

extern exprAST* ROOT;
extern codeGen* codegen;
extern int yyparse();

int main(){
	//词法与语法分析
	yyparse();
	//AST可视化
	ROOT->createJsonFile("visualize/ast.json");
	//IR生成
	// codegen->generate();

	return 0;
}
