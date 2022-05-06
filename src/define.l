%{
#include<stdio.h>
#include"grammar.h"
extern int yylval;
%}

letter = [A-Za-z]
digit = [0-9]
letgit = letter | digit


INTEGER = [0-9]+ | -[0-9]+
FLOAT = [0-9]+.[0-9]+ | -[0-9]+.[0-9]+


ID = letter digit*
CHARCONST = '\'' letdit '\''
STRINGCONST = '"' letgit* '"'
WhiteSpace = ' ' | '\t' | '\n' | '\r'
Comment = '//' [^\n]* '\n'


while = "while"
for = "for"
if = "if"
else = "else"
break = "break"
continue = "continue"
return = "return"


int = "int"
float = "float"
char = "char"
double = "double"
bool = "bool"
void = "void"



%%
{INTEGER} {yylval = atoi(yytext); return INTEGER;}
{FLOAT} {yylval = atof(yytext); return FLOAT;}
{ID} {yylval = yytext; return ID;}
{CHARCONST} {yylval = yytext; return CHARCONST;}
{STRINGCONST} {yylval = yytext; return STRINGCONST;}

{WhiteSpace} {//Ignore WhiteSpace}
{Comment} {//Ignore Comment}

{while} {return while;}
{for} {return for;}
{if} {return if;}
{else} {return else;}
{break} {return break;}
{continue} {return continue;}
{return} {return return;}

{int} {return int;}
{float} {return float;}
{char} {return char;}
{double} {return double;}
{bool} {return bool;}
{void} {return void;}

. {yylval = yytext;}
%%


int yywrap(void) {
    return 1;
}