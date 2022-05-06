%{
#include<stdio.h>
#include"grammar.h"
#include"ast.h"
extern int yylval;
%}


digit = [0-9]
letter = [A-Za-z]
letgit = digit | letter
identifier = letter letgit*

integer = digit+ | -digit+
float = digit+ "." digit+ | -digit+ "." -digit+
string = "\"" (letgit | "\"")* "\""

comment = "//" (letgit | "\n")* "\n"


%%
{identifier} {return IDENTIFIER;}
{float} {return CONSTANT;}
{integer} {return CONSTANT;}
{string} {return STRING_LITERAL;}

{comment} {//ignore the comment;}

"++" {return INC_OP;}
"--" {return DEC_OP;}
"<<" {return LEFT_OP;}
">>" {return RIGHT_OP;}
"<=" {return LE_OP;}
">=" {return GE_OP;}
"==" {return EQ_OP;}
"!=" {return NE_OP;}

"&&" {return AND_OP;}
"||" {return OR_OP;}

"*=" {return MUL_ASSIGN;}
"/=" {return DIV_ASSIGN;}
"%=" {return MOD_ASSIGN;}
"+=" {return ADD_ASSIGN;}
"-=" {return SUB_ASSIGN;}
"<<=" {return LEFT_ASSIGN;}
">>=" {return RIGHT_ASSIGN;}
"&=" {return AND_ASSIGN;}
"^=" {return XOR_ASSIGN;}
"|=" {return OR_ASSIGN;}

"char" {return CHAR;}
"chort" {return CHORT;}
"int" {return INT;}
"long" {return LONG;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"void" {return VOID;}

"..." {return ELLIPSIS;}

"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"do" {return DO;}
"for" {return FOR;}
"continue" {return CONTINUE;}
"break" {return BREAK;}
"return" {return RETURN;}

. {//ignore this character}

%%


int yywrap(void) {
    return 1;
}