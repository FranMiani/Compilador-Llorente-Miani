%{
#include <stdio.h>
#include "parser.tab.h"
void addLine();

%}

DIGIT    [0-9]
ALPHA     [a-zA-Z]
ALPHA_NUM       {ALPHA}|{DIGIT}|"_"
ID        {ALPHA}{ALPHA_NUM}*
INT_LITERAL    {DIGIT}+
FLOAT_LITERAL       {DIGIT}+"."{DIGIT}+
ONE_LINE_COMMENT    "//"[^\n]*\n
LONG_COMMENT    "/*"([^*]|\*+[^*/])*\*+"/"

%%
{ONE_LINE_COMMENT}    ;
{LONG_COMMENT}        ;
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"int" {return INT;}
"float" {return FLOAT;}
"void" {return VOID;}
"boolean" {return BOOLEAN;}
"return" {return RETURN;}
"{" {return '{';}
"}" {return '}';}
"(" {return '(';}
")" {return ')';}
";" {return ';';}
"<" {return '<';}
">" {return '>';}
"==" {return EQUAL;}
"&&" {return AND;}
"||" {return OR;}
"!" {return '!';}
"=" {return '=';}
"+" {return '+';} 
"-" {return '-';}
"*" {return '*';} 
"/" {return '/';}
"%" {return '%';}
"," {return ',';}
"false" {yylval.num = 0; return FALSE;}
"true" {yylval.num = 1;  return TRUE;}
{FLOAT_LITERAL} {return LIT_FLOAT;}
{ID} {yylval.str = strdup(yytext); return ID;}
{INT_LITERAL} {yylval.num = atoi(yytext); return LIT_INT;}
[\n] {addLine();}
[ \t]+    ; /* Ignorar espacios y saltos de línea */
.           { printf("Error léxico: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
