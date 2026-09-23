%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#define _GNU_SOURCE

SymbolTable *tabla;

int lines = 1;
void addLine(){
    lines++;
}

extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);
%}

%union {
       int num;
       char *str;
}


%token IF ELSE WHILE INT RETURN BOOLEAN FLOAT 
%token EQUAL AND OR
%token <str> ID
%token <num> LIT_INT TRUE FALSE LIT_FLOAT
%token VOID

%left AND
%left OR 
%nonassoc '<' '>' EQUAL  
%left '+' '-'
%left '*' '/' '%'
%right '!' UMINUS



%%

input:
    Var_decl ';' input
    | Var_decl ';'
    | Method_decl
    | Method_decl input
    ;

Method_decl:
    Type ID '('Params')' Bloque
    | VOID ID '('Params')' Bloque
    | Type ID '('')' Bloque
    | VOID ID '('')' Bloque
    ;
    
Type: INT
    | BOOLEAN
    | FLOAT
    ;
    
Params:
    Param ',' Params
    | Param
    ;
    
Param: Type ID
    ;
        
Linea:
      /* vacío */
    | Sentencia Linea
    ;

Sentencia:
      Var_decl ';'
    | Asign ';'
    | IF '(' expr ')' Bloque
    | IF '(' expr ')' Bloque ELSE Bloque
    | WHILE '(' expr ')' Bloque
    | RETURN expr ';'
    | RETURN ';'
    | ';'
    | Bloque
    ;

Bloque: '{' {new_level(tabla);} Linea '}' {close_level(tabla);}
    
Params_pass : expr',' Params_pass
    | expr
    ;
    
Method_call : ID '('')'
    | ID '(' Params_pass ')'
    ;
    
expr:
      ID
    | Method_call
    | LIT_FLOAT
    | LIT_INT
    | TRUE
    | FALSE
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '%' expr
    | expr '<' expr
    | expr '>' expr
    | expr EQUAL expr
    | expr AND expr
    | expr OR expr
    | '-' expr %prec UMINUS
    | '!' expr
    | '(' expr ')'
    ;
        
Ids_decl : ID',' Ids_decl {insert_symbol(tabla, NULL, $1, NULL);}
    | ID    {if(!find_in_level(tabla, $1)){
            insert_symbol(tabla, NULL, $1, NULL);}
    ;
    
Var_decl: Type Ids_decl
    ;
    
Asign: ID '=' expr
    ;
    
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico en línea %d: %s\n", lines, s);
}
