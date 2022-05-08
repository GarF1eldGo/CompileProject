#include<queue>
#include"ast.h"
#include"grammar.hpp"

extern exprAST* ROOT;
extern int yyparse();

int main(){
	yyparse();

	ROOT->createJsonFile("visualize/ast.json");

	//打印AST
	// queue<exprAST*> nodeQueue;
	// nodeQueue.push(ROOT);

	// printf("\n\n 打印AST:\n\n");

	// //层序打印AST
	// while(!nodeQueue.empty()){
	// 	int n = nodeQueue.size();
	// 	for(int i=0;i<n;i++){
	// 		exprAST* node = nodeQueue.front();
	// 		nodeQueue.pop();
	// 		//判断是否为叶子结点
	// 		if(dynamic_cast<nonleafAST*>(node) == 0){ 
	// 			printf("leaf  ");
	// 		}
	// 		else{
	// 			nonleafAST* nonLeaf = dynamic_cast<nonleafAST*>(node);
	// 			printf("%s   ", nonLeaf->name.c_str());
	// 			vector<exprAST*> children = nonLeaf->children;
	// 			for(int j=0;j<children.size();j++){
	// 				nodeQueue.push(children[j]);
	// 			}
	// 		}
	// 	}
	// 	printf("\n\n");
		
	// }
	return 0;
}