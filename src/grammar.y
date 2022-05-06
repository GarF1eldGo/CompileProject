%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lex.yy.c"

int yylex();
void yyerror(char const *s){
    printf("Error Information\n");
    printf("%s at %s\n",s,yytext);
}
%}