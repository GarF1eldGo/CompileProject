#include <queue>
#include "ast.h"
#include "grammar.hpp"

extern exprAST* ROOT;
extern int yyparse();

int main(){
	//词法与语法分析
	yyparse();

	//AST可视化
	ROOT->createJsonFile("visualize/ast.json");

	return 0;
}
