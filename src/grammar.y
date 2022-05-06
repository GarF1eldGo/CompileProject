%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ast.h"
#include "lex.yy.c"

int yylex();
void yyerror(char const *s);

extern exprAST* ROOT;
%}


%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN

%token CHAR SHORT INT LONG FLOAT DOUBLE VOID
%token ELLIPSIS

%token IF ELSE WHILE DO FOR CONTINUE BREAK RETURN

%start translation_unit


%%
translation_unit
    : external_declaration { $$ = new nonleafAST("translation_unit", 1, 1, $1); ROOT = $$;}
    | translation_unit external_declaration { $$ = new nonleafAST("translation_unit", 2, 2, $1, $2); ROOT = $$;}
    ;


external_declaration
    : function_definition { $$ = new nonleafAST("external_declaration", 1, 1, $1);}
    | declaration { $$ = new nonleafAST("external_declaration", 2, 1, $1);}
    ;


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
	: IDENTIFIER { }
	| '(' declarator ')' { $$ = new nonleafAST("direct_declarator", 2, 1, $2);}
	| direct_declarator '[' constant_expression ']' { $$ = new nonleafAST("direct_declarator", 3, 2, $1, $3);}
	| direct_declarator '[' ']' { $$ = new nonleafAST("direct_declarator", 4, 1, $1);}
	| direct_declarator '(' parameter_type_list ')' { $$ = new nonleafAST("direct_declarator", 5, 2, $1, $3);}
	| direct_declarator '(' ')' { $$ = new nonleafAST("direct_declarator", 6, 1, $1);}
	;


compound_statement
	: '{' '}' { $$ = new nonleafAST("compound_statement", 1);}
	| '{' statement_list '}' { $$ = new nonleafAST("compound_statement", 2, 1, $2);}
	| '{' declaration_list '}' { $$ = new nonleafAST("compound_statement", 3, 1, $2);}
	| '{' declaration_list statement_list '}' { $$ = new nonleafAST("compound_statement", 4, 2, $2, $3);}
	;


statement_list
	: statement { $$ = new nonleafAST("statement_list", 1, 1, $1);}
	| statement_list statement { $$ = new nonleafAST("statement_list", 2, 2, $1, $2);}
	;


statement
	: compound_statement { $$ = new nonleafAST("statement", 1, 1, $1);}
	| expression_statement { $$ = new nonleafAST("statement", 2, 1, $1);}
	| selection_statement { $$ = new nonleafAST("statement", 3, 1, $1);}
	| iteration_statement { $$ = new nonleafAST("statement", 4, 1, $1);}
	| jump_statement { $$ = new nonleafAST("statement", 5, 1, $1);}
	;


compound_statement
	: '{' '}' { $$ = new nonleafAST("compound_statement", 1);}
	| '{' statement_list '}' { $$ = new nonleafAST("compound_statement", 2, 1, $2);}
	| '{' declaration_list '}' { $$ = new nonleafAST("compound_statement", 3, 1, $2);}
	| '{' declaration_list statement_list '}' { $$ = new nonleafAST("compound_statement", 4, 2, $2, $3);}
	;


expression_statement
	: ';' { $$ = new nonleafAST("expression_statement", 1);}
	| expression ';' { $$ = new nonleafAST("expression_statement", 2, 1, $1);}
	;
    

selection_statement
	: IF '(' expression ')' statement { $$ = new nonleafAST("selection_statement", 1, 2, $3, $5);}
	| IF '(' expression ')' statement ELSE statement { $$ = new nonleafAST("selection_statement", 2, 3, $3, $5, $7);}
	;


iteration_statement
	: WHILE '(' expression ')' statement { $$ = new nonleafAST("iteration_statement", 1, 2, $3, $5);}
	| DO statement WHILE '(' expression ')' ';' { $$ = new nonleafAST("iteration_statement", 2, 2, $2, $5);}
	| FOR '(' expression_statement expression_statement ')' statement { $$ = new nonleafAST("iteration_statement", 3, 3, $3, $4, $6);}
	| FOR '(' expression_statement expression_statement expression ')' statement { $$ = new nonleafAST("iteration_statement", 4, 4, $3, $4, $5, $7);}
	;


declaration
    : declaration_specifiers init_declarator_list ';' { $$ = new nonleafAST("declaration", 1, 2, $1, $2);}
	;






%%


void yyerror(char const *s){
    printf("Error Information\n");
    printf("%s at %s\n",s,yytext);
}
