%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<vector>
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
    : external_declaration { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new translation_unit("translation_unit", 1, children);
		ROOT = $$;
	}
    | translation_unit external_declaration {
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		$$ = new translation_unit("translation_unit", 2, children);
		ROOT = $$;
	}
    ;


//全局定义
external_declaration
    : function_definition { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new external_declaration("external_declaration", 1, children);
	}
    | declaration {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new external_declaration("external_declaration", 2, children);
	}
    ;


//函数定义
function_definition
    : declaration_specifiers declarator compound_statement {
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		children.push_back($3);
		$$ = new function_definition("function_definition", 1, children);
	}
    ;


declaration_specifiers
    : type_specifier {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new declaration_specifiers("declaration_specifiers", 1, children);
	}
	| type_specifier declaration_specifiers {
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		$$ = new declaration_specifiers("declaration_specifiers", 2, children);
	}
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
    : direct_declarator { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new declarator("declarator", 1, children);
	}
	;


//TODO
direct_declarator
	: IDENTIFIER { 
		exprAST* id = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(id);
		$$ = new nonleafAST("direct_declarator", 1, children);
	}
	| '(' declarator ')' { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back($2);
		children.push_back(right);
		$$ = new nonleafAST("direct_declarator", 2, children);
	}
	| direct_declarator '[' constant_expression ']' { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(left);
		children.push_back($3);
		children.push_back(right);
		$$ = new nonleafAST("direct_declarator", 3, children);
	}
	| direct_declarator '[' ']' { 
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(left);
		children.push_back(right);
		$$ = new nonleafAST("direct_declarator", 4, children);
	}
	| direct_declarator '(' parameter_type_list ')' { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(left);
		children.push_back($3);
		children.push_back(right);
		$$ = new nonleafAST("direct_declarator", 5, children);
	}
	| direct_declarator '(' ')' { 
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(left);
		children.push_back(right);
		$$ = new nonleafAST("direct_declarator", 6, children);
	}
	;


//常量表达式
constant_expression
	: conditional_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new constant_expression("constant_expression", 1, children);
	}
	;


//条件表达式
conditional_expression
	: logical_or_expression {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new conditional_expression("conditional_expression", 1, children);
	}
	| logical_or_expression '?' expression ':' conditional_expression {
		exprAST* questionMark = new punctuationAST("?");
		exprAST* colon = new punctuationAST(":");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(questionMark);
		children.push_back($3);
		children.push_back(colon);
		children.push_back($5);
		$$ = new conditional_expression("conditional_expression", 2, children);
	}
	;


//逻辑或表达式
logical_or_expression
	: logical_and_expression {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new logical_or_expression("logical_or_expression", 1, children);
	}
	| logical_or_expression OR_OP logical_and_expression {
		exprAST* orOp = new operatorAST("||");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(orOp);
		children.push_back($3);
		$$ = new logical_or_expression("logical_or_expression", 2, children);
	}
	;


//逻辑与表达式
logical_and_expression
	: inclusive_or_expression {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new logical_and_expression("logical_and_expression", 1, children);
	}
	| logical_and_expression AND_OP inclusive_or_expression {
		exprAST* andOp = new operatorAST("&&");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(andOp);
		children.push_back($3);
		$$ = new logical_and_expression("logical_and_expression", 2, children);
	}
	;


//间或表达式
inclusive_or_expression
	: exclusive_or_expression {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new inclusive_or_expression("inclusive_or_expression", 1, children);
	}
	| inclusive_or_expression '|' exclusive_or_expression {
		exprAST* orOp = new operatorAST("|");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(orOp);
		children.push_back($3);
		$$ = new inclusive_or_expression("inclusive_or_expression", 2, children);
	}
	;


//异或表达式
exclusive_or_expression
	: and_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new exclusive_or_expression("exclusive_or_expression", 1, children);
	}
	| exclusive_or_expression '^' and_expression {
		exprAST* xorOp = new operatorAST("^");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(xorOp);
		children.push_back($3);
		$$ = new exclusive_or_expression("exclusive_or_expression", 2, children);
	}
	;


//与表达式
and_expression
	: equality_expression {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new and_expression("and_expression", 1, children);
	}
	| and_expression '&' equality_expression {
		exprAST* andOp = new operatorAST("&");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(andOp);
		children.push_back($3);
		$$ = new and_expression("and_expression", 2, children);
	}
	;


//等式表达式
equality_expression
	: relational_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new equality_expression("equality_expression", 1, children);
	}
	| equality_expression EQ_OP relational_expression {
		exprAST* eqOp = new operatorAST("==");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(eqOp);
		children.push_back($3);
		$$ = new equality_expression("equality_expression", 2, children);
	}
	| equality_expression NE_OP relational_expression {
		exprAST* neOp = new operatorAST("!=");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(neOp);
		children.push_back($3);
		$$ = new equality_expression("equality_expression", 3, children);
	}
	;


//关系表达式
relational_expression
	: shift_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new relational_expression("relational_expression", 1, children);
	}
	| relational_expression '<' shift_expression {
		exprAST* lessOp = new operatorAST("<");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(lessOp);
		children.push_back($3);
		$$ = new relational_expression("relational_expression", 2, children);
	}
	| relational_expression '>' shift_expression {
		exprAST* greaterOp = new operatorAST(">");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(greaterOp);
		children.push_back($3);
		$$ = new relational_expression("relational_expression", 3, children);
	}
	| relational_expression LE_OP shift_expression {
		exprAST* lessEqualOp = new operatorAST("<=");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(lessEqualOp);
		children.push_back($3);
		$$ = new relational_expression("relational_expression", 4, children);
	}
	| relational_expression GE_OP shift_expression {
		exprAST* greaterEqualOp = new operatorAST(">=");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(greaterEqualOp);
		children.push_back($3);
		$$ = new relational_expression("relational_expression", 5, children);
	}
	;


//移位表达式
shift_expression
	: additive_expression {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new shift_expression("shift_expression", 1, children);
	}
	| shift_expression LEFT_OP additive_expression {
		exprAST* leftOp = new operatorAST("<<");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(leftOp);
		children.push_back($3);
		$$ = new shift_expression("shift_expression", 2, children);
	}
	| shift_expression RIGHT_OP additive_expression {
		exprAST* rightOp = new operatorAST(">>");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(rightOp);
		children.push_back($3);
		$$ = new shift_expression("shift_expression", 3, children);
	}
	;


//加减表达式
additive_expression
	: multiplicative_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new additive_expression("additive_expression", 1, children);
	}
	| additive_expression '+' multiplicative_expression {
		exprAST* addOp = new operatorAST("+");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(addOp);
		children.push_back($3);
		$$ = new additive_expression("additive_expression", 2, children);
	}
	| additive_expression '-' multiplicative_expression {
		exprAST* subOp = new operatorAST("-");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(subOp);
		children.push_back($3);
		$$ = new additive_expression("additive_expression", 3, children);
	}
	;


//乘除表达式
multiplicative_expression
	: cast_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new multiplicative_expression("multiplicative_expression", 1, children);
	}
	| multiplicative_expression '*' cast_expression {
		exprAST* mulOp = new operatorAST("*");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(mulOp);
		children.push_back($3);
		$$ = new multiplicative_expression("multiplicative_expression", 2, children);
	}
	| multiplicative_expression '/' cast_expression {
		exprAST* divOp = new operatorAST("/");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(divOp);
		children.push_back($3);
		$$ = new multiplicative_expression("multiplicative_expression", 3, children);
	}
	| multiplicative_expression '%' cast_expression {
		exprAST* modOp = new operatorAST("%");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(modOp);
		children.push_back($3);
		$$ = new multiplicative_expression("multiplicative_expression", 4, children);
	}
	;


// 类型转换表达式
cast_expression
	: unary_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new cast_expression("cast_expression", 1, children);
	}
	| '(' type_name ')' cast_expression {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back($2);
		children.push_back(right);
		children.push_back($4);
		$$ = new cast_expression("cast_expression", 2, children);
	}
	;


//类型名称
type_name
	: type_specifier { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new type_name("type_name", 1, children);
	}
	;


//表达式
expression
	: assignment_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new expression("expression", 1, children);
	}
	| expression ',' assignment_expression {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(comma);
		children.push_back($3);
		$$ = new expression("expression", 2, children);
	}
	;


//赋值表达式
assignment_expression
	: conditional_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new assignment_expression("assignment_expression", 1, children);
	}
	| unary_expression assignment_operator assignment_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		children.push_back($3);
		$$ = new assignment_expression("assignment_expression", 2, children);
	}
	;


//一元运算表达式
unary_expression
	: postfix_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new unary_expression("unary_expression", 1, children);
	}
	| INC_OP unary_expression {
		exprAST* incOp = new operatorAST("++");
		vector<exprAST*> children;
		children.push_back(incOp);
		children.push_back($2);
		$$ = new unary_expression("unary_expression", 2, children);
	}
	| DEC_OP unary_expression {
		exprAST* decOp = new operatorAST("--");
		vector<exprAST*> children;
		children.push_back(decOp);
		children.push_back($2);
		$$ = new unary_expression("unary_expression", 3, children);
	}
	| unary_operator cast_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		$$ = new unary_expression("unary_expression", 4, children);
	}
	| SIZEOF unary_expression {
		exprAST* sizeOf = new keywordAST("sizeof");
		vector<exprAST*> children;
		children.push_back(sizeOf);
		children.push_back($2);
		$$ = new unary_expression("unary_expression", 5, children);
	}
	| SIZEOF '(' type_name ')' {
		exprAST* sizeOf = new keywordAST("sizeof");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(sizeOf);
		children.push_back(left);
		children.push_back($3);
		children.push_back(right);
		$$ = new unary_expression("unary_expression", 6, children);
	}
	;


// 后缀表达式
postfix_expression
	: primary_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new postfix_expression("postfix_expression", 1, children);
	}
	| postfix_expression '[' expression ']' {
		exprAST* left = new punctuationAST("[");
		exprAST* right = new punctuationAST("]");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(left);
		children.push_back($3);
		children.push_back(right);
		$$ = new postfix_expression("postfix_expression", 2, children);
	}
	| postfix_expression '(' ')' {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(left);
		children.push_back(right);
		$$ = new postfix_expression("postfix_expression", 3, children);
	}
	| postfix_expression '(' argument_expression_list ')'{
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(left);
		children.push_back($3);
		children.push_back(right);
		$$ = new postfix_expression("postfix_expression", 4, children);
	}
	| postfix_expression INC_OP {
		exprAST* incOp = new operatorAST("++");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(incOp);
		$$ = new postfix_expression("postfix_expression", 5, children);
	}
	| postfix_expression DEC_OP {
		exprAST* decOp = new operatorAST("--");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(decOp);
		$$ = new postfix_expression("postfix_expression", 6, children);
	}
	;


//基本表达式
//TODO
primary_expression
	: IDENTIFIER {
		exprAST* identifier = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(identifier);
		$$ = new primary_expression("primary_expression", 1, children);
	}
	| CONSTANT {
		exprAST* constant = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(constant);
		$$ = new primary_expression("primary_expression", 2, children);
	}
	| STRING_LITERAL {
		exprAST* str = tokenStack.top();
		tokenStack.pop();
		vector<exprAST*> children;
		children.push_back(str);
		$$ = new primary_expression("primary_expression", 3, children);
	}
	| '(' expression ')' {
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back($2);
		children.push_back(right);
		$$ = new primary_expression("primary_expression", 4, children);
	}
	;


//参数表达式列表
argument_expression_list
	: assignment_expression { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new argument_expression_list("argument_expression_list", 1, children);
	}
	| argument_expression_list ',' assignment_expression {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(comma);
		children.push_back($3);
		$$ = new argument_expression_list("argument_expression_list", 2, children);
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
	: parameter_list { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new parameter_type_list("parameter_type_list", 1, children);
	}
	| parameter_list ',' ELLIPSIS {
		exprAST* comma = new punctuationAST(",");
		exprAST* ellipsis = new keywordAST("...");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(comma);
		children.push_back(ellipsis);
		$$ = new parameter_type_list("parameter_type_list", 2, children);
	}
	;


//参数列表
parameter_list
	: parameter_declaration { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new parameter_list("parameter_list", 1, children);
	}
	| parameter_list ',' parameter_declaration {
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(comma);
		children.push_back($3);
		$$ = new parameter_list("parameter_list", 2, children);
	}
	;


// 参数定义
parameter_declaration
	: declaration_specifiers declarator{ 
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		$$ = new parameter_declaration("parameter_declaration", 1, children);
	}
	;


//复合语句
compound_statement
	: '{' '}' { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back(right);
		$$ = new compound_statement("compound_statement", 1, children);
	}
	| '{' statement_list '}' { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back($2);
		children.push_back(right);
		$$ = new compound_statement("compound_statement", 2, children);
	}
	| '{' declaration_list '}' { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back($2);
		children.push_back(right);
		$$ = new compound_statement("compound_statement", 3, children);
	}
	| '{' declaration_list statement_list '}' { 
		exprAST* left = new punctuationAST("{");
		exprAST* right = new punctuationAST("}");
		vector<exprAST*> children;
		children.push_back(left);
		children.push_back($2);
		children.push_back($3);
		children.push_back(right);
		$$ = new compound_statement("compound_statement", 4, children);
	}
	;


//基本语句的list
statement_list
	: statement { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new statement_list("statement_list", 1, children);
	}
	| statement_list statement { 
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		$$ = new statement_list("statement_list", 2, children);
	}
	;


//变量声明的list
declaration_list
	: declaration {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new declaration_list("declaration_list", 1, children);
	}
	| declaration_list declaration {
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		$$ = new declaration_list("declaration_list", 2, children);
	}
	;


//基本语句
statement
	: compound_statement { 
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new statement("statement", 1, children);
	}
	| expression_statement {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new statement("statement", 2, children);
	}
	| selection_statement {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new statement("statement", 3, children);
	}
	| iteration_statement {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new statement("statement", 4, children);
	}
	| jump_statement {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new statement("statement", 5, children);
	}
	;


//表达式语句
expression_statement
	: ';' { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(semiColon);
		$$ = new expression_statement("expression_statement", 1, children);
	}
	| expression ';' { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(semiColon);
		$$ = new expression_statement("expression_statement", 2, children);
	}
	;
    

//选择语句
selection_statement
	: IF '(' expression ')' statement { 
		exprAST* oneIF = new keywordAST("if");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneIF);
		children.push_back(left);
		children.push_back($3);
		children.push_back(right);
		children.push_back($5);
		$$ = new selection_statement("selection_statement", 1, children);
	}
	| IF '(' expression ')' statement ELSE statement { 
		exprAST* oneIF = new keywordAST("if");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		exprAST* oneELSE = new keywordAST("else");
		vector<exprAST*> children;
		children.push_back(oneIF);
		children.push_back(left);
		children.push_back($3);
		children.push_back(right);
		children.push_back($5);
		children.push_back(oneELSE);
		children.push_back($7);
		$$ = new selection_statement("selection_statement", 2, children);
	}
	;


//迭代语句
iteration_statement
	: WHILE '(' expression ')' statement { 
		exprAST* oneWHILE = new keywordAST("while");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneWHILE);
		children.push_back(left);
		children.push_back($3);
		children.push_back(right);
		children.push_back($5);
		$$ = new iteration_statement("iteration_statement", 1, children);
	}
	| DO statement WHILE '(' expression ')' ';' { 
		exprAST* oneDO = new keywordAST("do");
		exprAST* oneWHILE = new keywordAST("while");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneDO);
		children.push_back($2);
		children.push_back(oneWHILE);
		children.push_back(left);
		children.push_back($5);
		children.push_back(right);
		children.push_back(semiColon);
		$$ = new iteration_statement("iteration_statement", 2, children);
	}
	| FOR '(' expression_statement expression_statement ')' statement { 
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneFOR);
		children.push_back(left);
		children.push_back($3);
		children.push_back($4);
		children.push_back(right);
		children.push_back($6);
		$$ = new iteration_statement("iteration_statement", 3, children);
	}
	| FOR '(' expression_statement expression_statement expression ')' statement { 
		exprAST* oneFOR = new keywordAST("for");
		exprAST* left = new punctuationAST("(");
		exprAST* right = new punctuationAST(")");
		vector<exprAST*> children;
		children.push_back(oneFOR);
		children.push_back(left);
		children.push_back($3);
		children.push_back($4);
		children.push_back($5);
		children.push_back(right);
		children.push_back($7);
		$$ = new iteration_statement("iteration_statement", 4, children);
	}
	;


//跳转语句
jump_statement
	: CONTINUE ';' { 
		exprAST* oneCONTINUE = new keywordAST("continue");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneCONTINUE);
		children.push_back(semiColon);
		$$ = new jump_statement("jump_statement", 1, children);
	}
	| BREAK ';' { 
		exprAST* oneBREAK = new keywordAST("break");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneBREAK);
		children.push_back(semiColon);
		$$ = new jump_statement("jump_statement", 2, children);
	}
	| RETURN ';' { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneRETURN);
		children.push_back(semiColon);
		$$ = new jump_statement("jump_statement", 3, children);
	}
	| RETURN expression ';' { 
		exprAST* oneRETURN = new keywordAST("return");
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back(oneRETURN);
		children.push_back($2);
		children.push_back(semiColon);
		$$ = new jump_statement("jump_statement", 4, children);
	}
	;


//变量声明
declaration
    : declaration_specifiers init_declarator_list ';' { 
		exprAST* semiColon = new punctuationAST(";");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back($2);
		children.push_back(semiColon);
		$$ = new declaration("declaration", 1, children);
	}
	;


// list:除去类型符号的变量声明或定义
init_declarator_list
	: init_declarator {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new init_declarator_list("init_declarator_list", 1, children);
	}
	| init_declarator_list ',' init_declarator{
		exprAST* comma = new punctuationAST(",");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(comma);
		children.push_back($3);
		$$ = new init_declarator_list("init_declarator_list", 2, children);
	}


// 除去类型符号的变量声明或定义
init_declarator
	: declarator {
		vector<exprAST*> children;
		children.push_back($1);
		$$ = new init_declarator("init_declarator", 1, children);
	}
	| declarator '=' assignment_expression {
		exprAST* eqOp = new operatorAST("=");
		vector<exprAST*> children;
		children.push_back($1);
		children.push_back(eqOp);
		children.push_back($3);
		$$ = new init_declarator("init_declarator", 2, children);
	}


%%


void yyerror(char const *s){
    printf("Error Information\n");
    printf("%s at %s\n",s,yytext);
	return ;
}


