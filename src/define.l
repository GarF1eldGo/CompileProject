%{
#include<stdio.h>
#include<iostream>
#include<string.h>
#include"grammar.hpp"
#include"ast.h"

extern stack<exprAST*> tokenStack;

%}


digit [0-9]
letter [A-Za-z]
letgit [A-Za-z0-9]
identifier {letter}{letgit}*

integer {digit}+
float {digit}+"."{digit}+
char \'(\\n|[^'\\])\'
string \"(\\.|[^"\\])*\"

comment \/\/[^\n]*

%%
"=" {return '=';}
"," {return ',';}
";" {return ';';}
":" {return ':';}
"(" {return '(';}
")" {return ')';}
"[" {return '[';}
"]" {return ']';}
"{" {return '{';}
"}" {return '}';}

"&" {return '&';}
"|" {return '|';}
"^" {return '^';}
"*" {return '*';}
"+" {return '+';}
"-" {return '-';}
"~" {return '~';}
"!" {return '!';}
"?" {return '?';}
">" {return '>';}
"<" {return '<';}


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
"chort" {return SHORT;}
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

{float} {
    exprAST* oneFloat = new constantAST(2, atof(yytext));
    tokenStack.push(oneFloat);
    return CONSTANT;
    }
{integer} {
    exprAST* oneInt = new constantAST(1, (double)atoi(yytext));
    tokenStack.push(oneInt);
    return CONSTANT;
    }
{char} {
    exprAST* oneChar = new charAST(yytext);
    tokenStack.push(oneChar);
    return CHAR_LITERAL;
}
{string} {
    exprAST* oneString = new stringAST(yytext);
    tokenStack.push(oneString);
    return STRING_LITERAL;
    }
{identifier} {
    exprAST* id = new identifierAST(yytext);
    tokenStack.push(id);
    return IDENTIFIER;
    }
{comment} {}

[ \t\n]+ {}
. {}

%%


int yywrap(void) {
    return 1;
}


// "-"{integer} {
//     exprAST* oneInt = new constantAST(1, (double)atoi(yytext));
//     tokenStack.push(oneInt);
//     return CONSTANT;
//     }

// "-"{float} {
//     exprAST* oneFloat = new constantAST(2, atof(yytext));
//     tokenStack.push(oneFloat);
//     return CONSTANT;
// }