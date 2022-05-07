%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include "ast.h"
#include "define.cpp"

int yylex();
void yyerror(char const *s);

extern exprAST* ROOT;
stack<exprAST*> tokenStack;
%}


%union{
	class exprAST* exprPtr;
}

//终结符定义与其类型定义
%token <exprPtr> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token <exprPtr> INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <exprPtr> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <exprPtr> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token <exprPtr> XOR_ASSIGN OR_ASSIGN

%token <exprPtr> CHAR SHORT INT LONG FLOAT DOUBLE VOID
%token <exprPtr> ELLIPSIS

%token <exprPtr> IF ELSE WHILE DO FOR CONTINUE BREAK RETURN

//文法规则类型定义
%type <exprPtr> translation_unit external_declaration function_definition declaration_specifiers type_specifier
%type <exprPtr> declarator direct_declarator constant_expression conditional_expression logical_or_expression logical_and_expression
%type <exprPtr> inclusive_or_expression exclusive_or_expression and_expression equality_expression relational_expression
%type <exprPtr> shift_expression additive_expression multiplicative_expression cast_expression type_name expression assignment_expression
%type <exprPtr> unary_expression postfix_expression argument_expression_list unary_operator assignment_operator expression_statement 
%type <exprPtr> parameter_type_list parameter_list parameter_declaration compound_statement statement_list statement selection_statement
%type <exprPtr> iteration_statement jump_statement init_declarator init_declarator_list primary_expression declaration declaration_list


%start translation_unit


%%
translation_unit
    : external_declaration { $$ = new nonleafAST("translation_unit", 1, 1, $1); ROOT = $$;}
    | translation_unit external_declaration { $$ = new nonleafAST("translation_unit", 2, 2, $1, $2); ROOT = $$;}
    ;


//全局定义
external_declaration
    : function_definition { $$ = new nonleafAST("external_declaration", 1, 1, $1);}
    | declaration { $$ = new nonleafAST("external_declaration", 2, 1, $1);}
    ;

//函数定义
function_definition
    : declaration_specifiers declarator compound_statement { $$ = new nonleafAST("function_definition", 1, 3, $1, $2, $3);}
    ;


declaration_specifiers
    : type_specifier { $$ = new nonleafAST("declaration_specifiers", 1, 1, $1);}
	| type_specifier declaration_specifiers { $$ = new nonleafAST("declaration_specifiers", 2, 2, $1, $2);}
	;


type_specifier
	: VOID { $$ = new typeAST(1); }
	| CHAR { $$ = new typeAST(2);}
	| SHORT { $$ = new typeAST(3);}
	| INT { $$ = new typeAST(4);}
	| LONG { $$ = new typeAST(5);}
	| FLOAT { $$ = new typeAST(6);}
	| DOUBLE { $$ = new typeAST(7);}
	;


declarator
    : direct_declarator { $$ = new nonleafAST("declarator", 1, 1, $1);}
	;


//TODO
direct_declarator
	: IDENTIFIER { 
		exprAST* id = tokenStack.top();
		tokenStack.pop();
		$$ = new nonleafAST("direct_declarator", 1, 1, id);
	}
	| '(' declarator ')' { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("direct_declarator", 2, 3, left, $2, right);
	}
	| direct_declarator '[' constant_expression ']' { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		$$ = new nonleafAST("direct_declarator", 3, 4, $1, left, $3, right);
	}
	| direct_declarator '[' ']' { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		$$ = new nonleafAST("direct_declarator", 4, 3, $1, left, right);
	}
	| direct_declarator '(' parameter_type_list ')' { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("direct_declarator", 5, 4, $1, left, $3, right);
	}
	| direct_declarator '(' ')' { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("direct_declarator", 6, 3, $1, left, right);
	}
	;


//常量表达式
constant_expression
	: conditional_expression { $$ = new nonleafAST("constant_expression", 1, 1, $1);}
	;


//条件表达式
conditional_expression
	: logical_or_expression { $$ = new nonleafAST("conditional_expression", 1, 1, $1);}
	| logical_or_expression '?' expression ':' conditional_expression {
		exprAST* questionMark = new punctuationAST("?");
		exprAST* colon = new punctuationAST(":");
		$$ = new nonleafAST("conditional_expression", 2, 5, $1, questionMark, $3, colon, $5);
	}
	;


//逻辑或表达式
logical_or_expression
	: logical_and_expression { $$ = new nonleafAST("logical_or_expression", 1, 1, $1);}
	| logical_or_expression OR_OP logical_and_expression {
		exprAST* orOp = new operatorAST("||");
		$$ = new nonleafAST("logical_or_expression", 2, 3, $1, orOp, $3);
	}
	;


//逻辑与表达式
logical_and_expression
	: inclusive_or_expression { $$ = new nonleafAST("logical_and_expression", 1, 1, $1);}
	| logical_and_expression AND_OP inclusive_or_expression {
		exprAST* andOp = new operatorAST("&&");
		$$ = new nonleafAST("logical_and_expression", 2, 3, $1, andOp, $3);
	}
	;


//间或表达式
inclusive_or_expression
	: exclusive_or_expression { $$ = new nonleafAST("inclusive_or_expression", 1, 1, $1);}
	| inclusive_or_expression '|' exclusive_or_expression {
		exprAST* orOp = new operatorAST("|");
		$$ = new nonleafAST("inclusive_or_expression", 2, 3, $1, orOp, $3);
	}
	;


//异或表达式
exclusive_or_expression
	: and_expression { $$ = new nonleafAST("exclusive_or_expression", 1, 1, $1);}
	| exclusive_or_expression '^' and_expression {
		exprAST* xorOp = new operatorAST("^");
		$$ = new nonleafAST("exclusive_or_expression", 2, 3, $1, xorOp, $3);
	}
	;


//与表达式
and_expression
	: equality_expression { $$ = new nonleafAST("and_expression", 1, 1, $1);}
	| and_expression '&' equality_expression {
		exprAST* andOp = new operatorAST("&");
		$$ = new nonleafAST("and_expression", 2, 3, $1, andOp, $3);
	}
	;


//等式表达式
equality_expression
	: relational_expression { $$ = new nonleafAST("equality_expression", 1, 1, $1);}
	| equality_expression EQ_OP relational_expression {
		exprAST* eqOp = new operatorAST("==");
		$$ = new nonleafAST("equality_expression", 2, 3, $1, eqOp, $3);
	}
	| equality_expression NE_OP relational_expression {
		exprAST* neOp = new operatorAST("!=");
		$$ = new nonleafAST("equality_expression", 3, 3, $1, neOp, $3);
	}
	;


//关系表达式
relational_expression
	: shift_expression { $$ = new nonleafAST("relational_expression", 1, 1, $1);}
	| relational_expression '<' shift_expression {
		exprAST* lessOp = new operatorAST("<");
		$$ = new nonleafAST("relational_expression", 2, 3, $1, lessOp, $3);
	}
	| relational_expression '>' shift_expression {
		exprAST* greaterOp = new operatorAST(">");
		$$ = new nonleafAST("relational_expression", 3, 3, $1, greaterOp, $3);
	}
	| relational_expression LE_OP shift_expression {
		exprAST* lessEqualOp = new operatorAST("<=");
		$$ = new nonleafAST("relational_expression", 4, 3, $1, lessEqualOp, $3);
	}
	| relational_expression GE_OP shift_expression {
		exprAST* greaterEqualOp = new operatorAST(">=");
		$$ = new nonleafAST("relational_expression", 5, 3, $1, greaterEqualOp, $3);
	}
	;


//移位表达式
shift_expression
	: additive_expression { $$ = new nonleafAST("shift_expression", 1, 1, $1);}
	| shift_expression LEFT_OP additive_expression {
		exprAST* leftOp = new operatorAST("<<");
		$$ = new nonleafAST("shift_expression", 2, 3, $1, leftOp, $3);
	}
	| shift_expression RIGHT_OP additive_expression {
		exprAST* rightOp = new operatorAST(">>");
		$$ = new nonleafAST("shift_expression", 3, 3, $1, rightOp, $3);
	}
	;


//加减表达式
additive_expression
	: multiplicative_expression { $$ = new nonleafAST("additive_expression", 1, 1, $1);}
	| additive_expression '+' multiplicative_expression {
		exprAST* addOp = new operatorAST("+");
		$$ = new nonleafAST("additive_expression", 2, 3, $1, addOp, $3);
	}
	| additive_expression '-' multiplicative_expression {
		exprAST* subOp = new operatorAST("-");
		$$ = new nonleafAST("additive_expression", 3, 3, $1, subOp, $3);
	}
	;


//乘除表达式
multiplicative_expression
	: cast_expression { $$ = new nonleafAST("multiplicative_expression", 1, 1, $1);}
	| multiplicative_expression '*' cast_expression {
		exprAST* mulOp = new operatorAST("*");
		$$ = new nonleafAST("multiplicative_expression", 2, 3, $1, mulOp, $3);
	}
	| multiplicative_expression '/' cast_expression {
		exprAST* divOp = new operatorAST("/");
		$$ = new nonleafAST("multiplicative_expression", 3, 3, $1, divOp, $3);
	}
	| multiplicative_expression '%' cast_expression {
		exprAST* modOp = new operatorAST("%");
		$$ = new nonleafAST("multiplicative_expression", 4, 3, $1, modOp, $3);
	}
	;


// 类型转换表达式
cast_expression
	: unary_expression { $$ = new nonleafAST("cast_expression", 1, 1, $1);}
	| '(' type_name ')' cast_expression {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("cast_expression", 2, 4, left, $2, right, $4);
	}
	;


//类型名称
type_name
	: type_specifier { $$ = new nonleafAST("type_name", 1, 1, $1);}
	;


//表达式
expression
	: assignment_expression { $$ = new nonleafAST("expression", 1, 1, $1);}
	| expression ',' assignment_expression {
		exprAST* comma = new punctuationAST(",");
		$$ = new nonleafAST("expression", 2, 3, $1, comma, $3);
	}
	;


//赋值表达式
assignment_expression
	: conditional_expression { $$ = new nonleafAST("assignment_expression", 1, 1, $1);}
	| unary_expression assignment_operator assignment_expression { 
		$$ = new nonleafAST("assignment_expression", 2, 3, $1, $2, $3);
	}
	;


//一元运算表达式
unary_expression
	: postfix_expression { $$ = new nonleafAST("unary_expression", 1, 1, $1);}
	| INC_OP unary_expression {
		exprAST* incOp = new operatorAST("++");
		$$ = new nonleafAST("unary_expression", 2, 2, incOp, $2);
	}
	| DEC_OP unary_expression {
		exprAST* decOp = new operatorAST("--");
		$$ = new nonleafAST("unary_expression", 3, 2, decOp, $2);
	}
	| unary_operator cast_expression { 
		$$ = new nonleafAST("unary_expression", 4, 2, $1, $2);
	}
	| SIZEOF unary_expression {
		exprAST* sizeOf = new keywordAST("sizeof");
		$$ = new nonleafAST("unary_expression", 5, 2, sizeOf, $2);
	}
	| SIZEOF '(' type_name ')' {
		exprAST* sizeOf = new keywordAST("sizeof");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("unary_expression", 6, 4, sizeOf, left, $3, right);
	}
	;


// 后缀表达式
postfix_expression
	: primary_expression { $$ = new nonleafAST("postfix_expression", 1, 1, $1);}
	| postfix_expression '[' expression ']' {
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		$$ = new nonleafAST("postfix_expression", 2, 4, $1, left, $3, right);
	}
	| postfix_expression '(' ')' {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("postfix_expression", 3, 3, $1, left, right);
	}
	| postfix_expression '(' argument_expression_list ')'{
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("postfix_expression", 4, 4, $1, left, $3, right);
	}
	| postfix_expression INC_OP {
		exprAST* incOp = new operatorAST("++");
		$$ = new nonleafAST("postfix_expression", 5, 2, $1, incOp);
	}
	| postfix_expression DEC_OP {
		exprAST* decOp = new operatorAST("--");
		$$ = new nonleafAST("postfix_expression", 6, 2, $1, decOp);
	}
	;


//基本表达式
//TODO
primary_expression
	: IDENTIFIER {
		exprAST* identifier = tokenStack.top();
		tokenStack.pop();
		$$ = new nonleafAST("primary_expression", 1, 1, identifier);
	}
	| CONSTANT {
		exprAST* constant = tokenStack.top();
		tokenStack.pop();
		$$ = new nonleafAST("primary_expression", 2, 1, constant);
	}
	| STRING_LITERAL {
		exprAST* str = tokenStack.top();
		tokenStack.pop();
		$$ = new nonleafAST("primary_expression", 3, 1, str);
	}
	| '(' expression ')' {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("primary_expression", 1, 3, left, $2, right);
	}
	;


//参数表达式列表
argument_expression_list
	: assignment_expression { $$ = new nonleafAST("argument_expression_list", 1, 1, $1);}
	| argument_expression_list ',' assignment_expression {
		exprAST* comma = new punctuationAST(",");
		$$ = new nonleafAST("argument_expression_list", 2, 3, $1, comma, $3);
	}
	;


//一元运算符
unary_operator
	: '&' { $$ = new operatorAST("&"); }
	| '*' { $$ = new operatorAST("*"); }
	| '+' { $$ = new operatorAST("+"); }
	| '-' {	$$ = new operatorAST("-"); }
	| '~' { $$ = new operatorAST("~"); }
	| '!' { $$ = new operatorAST("!"); }
	;


//赋值运算符
assignment_operator
	: '=' { $$ = new operatorAST("="); }
	| MUL_ASSIGN { $$ = new operatorAST("*="); }
	| DIV_ASSIGN { $$ = new operatorAST("/="); }
	| MOD_ASSIGN { $$ = new operatorAST("%="); }
	| ADD_ASSIGN { $$ = new operatorAST("+="); }
	| SUB_ASSIGN { $$ = new operatorAST("-="); }
	| LEFT_ASSIGN { $$ = new operatorAST("<<="); }
	| RIGHT_ASSIGN { $$ = new operatorAST(">>="); }
	| AND_ASSIGN { $$ = new operatorAST("&="); }
	| XOR_ASSIGN { $$ = new operatorAST("^="); }
	| OR_ASSIGN { $$ = new operatorAST("|="); }
	;


//参数类型列表
parameter_type_list
	: parameter_list { $$ = new nonleafAST("parameter_type_list", 1, 1, $1);}
	| parameter_list ',' ELLIPSIS {
		exprAST* comma = new punctuationAST(",");
		exprAST* ellipsis = new keywordAST("...");
		$$ = new nonleafAST("parameter_type_list", 2, 3, $1, comma, ellipsis);
	}
	;


//参数列表
parameter_list
	: parameter_declaration { $$ = new nonleafAST("parameter_list", 1, 1, $1);}
	| parameter_list ',' parameter_declaration {
		exprAST* comma = new punctuationAST(",");
		$$ = new nonleafAST("parameter_list", 2, 3, $1, comma, $3);
	}
	;


// 参数定义
parameter_declaration
	: declaration_specifiers declarator{ $$ = new nonleafAST("parameter_declaration", 1, 2, $1, $2);}
	;


//复合语句
compound_statement
	: '{' '}' { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		$$ = new nonleafAST("compound_statement", 1, 2, left, right);
	}
	| '{' statement_list '}' { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		$$ = new nonleafAST("compound_statement", 2, 3, left, $2, right);
	}
	| '{' declaration_list '}' { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		$$ = new nonleafAST("compound_statement", 3, 3, left, $2, right);
	}
	| '{' declaration_list statement_list '}' { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		$$ = new nonleafAST("compound_statement", 4, 4, left, $2, $3, right);
	}
	;


//基本语句的list
statement_list
	: statement { $$ = new nonleafAST("statement_list", 1, 1, $1);}
	| statement_list statement { $$ = new nonleafAST("statement_list", 2, 2, $1, $2);}
	;


//变量声明的list
declaration_list
	: declaration { $$ = new nonleafAST("declaration_list", 1, 1, $1);}
	| declaration_list declaration { $$ = new nonleafAST("declaration_list", 2, 2, $1, $2);}
	;


//基本语句
statement
	: compound_statement { $$ = new nonleafAST("statement", 1, 1, $1);}
	| expression_statement { $$ = new nonleafAST("statement", 2, 1, $1);}
	| selection_statement { $$ = new nonleafAST("statement", 3, 1, $1);}
	| iteration_statement { $$ = new nonleafAST("statement", 4, 1, $1);}
	| jump_statement { $$ = new nonleafAST("statement", 5, 1, $1);}
	;


//表达式语句
expression_statement
	: ';' { 
		exprAST* semiColon = new punctuationAST(";");
		$$ = new nonleafAST("expression_statement", 1, 1, semiColon);
	}
	| expression ';' { 
		exprAST* semiColon = new punctuationAST(";");
		$$ = new nonleafAST("expression_statement", 2, 2, $1, semiColon);
	}
	;
    
//选择语句
selection_statement
	: IF '(' expression ')' statement { 
		exprAST* oneIF = new keywordAST("if");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("selection_statement", 1, 5, oneIF, left, $3, right, $5);
	}
	| IF '(' expression ')' statement ELSE statement { 
		exprAST* oneIF = new keywordAST("if");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		exprAST* oneELSE = new keywordAST("else");
		$$ = new nonleafAST("selection_statement", 2, 7, oneIF, left, $3, right, $5, oneELSE, $7);
	}
	;


//迭代语句
iteration_statement
	: WHILE '(' expression ')' statement { 
		exprAST* oneWHILE = new keywordAST("while");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("iteration_statement", 1, 5, oneWHILE, left, $3, right, $5);
	}
	| DO statement WHILE '(' expression ')' ';' { 
		exprAST* oneDO = new keywordAST("do");
		exprAST* oneWHILE = new keywordAST("while");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		exprAST* semiColon = new punctuationAST(";");
		$$ = new nonleafAST("iteration_statement", 2, 7, oneDO, $2, oneWHILE, left, $5, right, semiColon);
	}
	| FOR '(' expression_statement expression_statement ')' statement { 
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("iteration_statement", 3, 6, oneFOR, left, $3, $4,right, $6);
	}
	| FOR '(' expression_statement expression_statement expression ')' statement { 
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		$$ = new nonleafAST("iteration_statement", 4, 7, oneFOR, left, $3, $4, $5, right, $7);
	}
	;


//跳转语句
jump_statement
	: CONTINUE ';' { 
		exprAST* oneCONTINUE = new keywordAST("continue");
		exprAST* semiColon = new punctuationAST(";");
		$$ = new nonleafAST("jump_statement", 1, 2, oneCONTINUE, semiColon);
	}
	| BREAK ';' { 
		exprAST* oneBREAK = new keywordAST("break");
		exprAST* semiColon = new punctuationAST(";");
		$$ = new nonleafAST("jump_statement", 2, 2, oneBREAK, semiColon);
	}
	| RETURN ';' { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		$$ = new nonleafAST("jump_statement", 3, 2, oneRETURN, semiColon);
	}
	| RETURN expression ';' { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		$$ = new nonleafAST("jump_statement", 4, 3, oneRETURN, $2, semiColon);
	}
	;


//变量声明
declaration
    : declaration_specifiers init_declarator_list ';' { 
		exprAST* semiColon = new punctuationAST(";");
		$$ = new nonleafAST("declaration", 1, 3, $1, $2, semiColon);
	}
	;


// list:除去类型符号的变量声明或定义
init_declarator_list
	: init_declarator { $$ = new nonleafAST("init_declarator_list", 1, 1, $1);}
	| init_declarator_list ',' init_declarator{
		exprAST* comma = new punctuationAST(",");
		$$ = new nonleafAST("init_declarator_list", 2, 3, $1, comma, $3);
	}


// 除去类型符号的变量声明或定义
init_declarator
	: declarator { $$ = new nonleafAST("init_declarator", 1, 1, $1);}
	| declarator '=' assignment_expression {
		exprAST* eqOp = new operatorAST("=");
		$$ = new nonleafAST("init_declarator", 2, 3, $1, eqOp, $3);
	}


%%


void yyerror(char const *s){
    printf("Error Information\n");
    printf("%s at %s\n",s,yytext);
	return ;
}


