%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "symbol_table.h"
#include "ast.h"
#define _GNU_SOURCE

SymbolTable *tabla;
Node *father;

int lines = 1;
int hay_error = 0;
char error_msg[512] = "";

void addLine(){
    lines++;
}

void set_error(const char *msg) {
    hay_error = 1;
    snprintf(error_msg, sizeof(error_msg), "%s", msg);
}

void error_tipo(void) {
    char buf[128];
    snprintf(buf, sizeof(buf), "Error de tipo. En la linea %d", lines);
    set_error(buf);
    fprintf(stderr, "%s\n", buf);
}

extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);
%}

%union {
    int num;
    float flow;
    char *str;
    struct Node *node;
}

%token IF ELSE WHILE INT RETURN BOOLEAN FLOAT
%token EQUAL AND OR
%token <str> ID
%token <num> LIT_INT TRUE FALSE LIT_FLOAT
%token VOID

%type <node> preinput input
%type <node> Method_decl Type Params Param
%type <node> Linea Sentencia Bloque
%type <node> Params_pass Method_call expr
%type <node> Ids_decl Var_decl Asign


%left AND
%left OR
%nonassoc '<' '>' EQUAL
%left '+' '-'
%left '*' '/' '%'
%right '!' UMINUS


%%

preinput: input {
    Symbol *simb = create_symb(NOT_TYPE, 0, NULL);
    $$ = create_node(NODE_OP_FUNC, simb, $1, NULL, NULL);
    father = $$;
}
    ;

input:
    Var_decl ';' input {
                        $$ = create_node(NODE_OP_NEWLINE, NULL, $1, $3, NULL);
                    }
    | Var_decl ';' {
                        $$ = create_node(NODE_OP_NEWLINE, NULL, $1, NULL, NULL);
                    }
    | Method_decl {
                        $$ = create_node(NODE_OP_NEWLINE, NULL, $1, NULL, NULL);
                    }
    | Method_decl input {
                        $$ = create_node(NODE_OP_NEWLINE, NULL, $1, $2, NULL);
                    }
    ;

Method_decl:
    Type ID '(' {
            if (find_in_level(tabla, $2)) {
                yyerror("Metodo declarado mas de una vez\n");
                YYABORT;
            }
            new_level(tabla);
        } Params ')' '{' Linea '}' {
            close_level(tabla);
            Symbol *simb = create_symb($1->info->exprType, 0, $2);
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            $$ = create_node(NODE_MET_DECLARATION, simb, $5, $8, NULL);
        }
    | VOID ID '(' {
            if (find_in_level(tabla, $2)) {
                yyerror("Metodo declarado mas de una vez\n");
                YYABORT;
            }
            new_level(tabla);
        } Params ')' '{' Linea '}' {
            close_level(tabla);
            Symbol *simb = create_symb(VOID1, 0, $2);
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            $$ = create_node(NODE_MET_DECLARATION, simb, $5, $8, NULL);
        }
    | Type ID '(' ')' {
            if (find_in_level(tabla, $2)) {
                yyerror("Metodo declarado mas de una vez\n");
                YYABORT;
            }
            new_level(tabla);
        } '{' Linea '}' {
            close_level(tabla);
            Symbol *simb = create_symb($1->info->exprType, 0, $2);
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            $$ = create_node(NODE_MET_DECLARATION, simb, NULL, $7, NULL);
        }
    | VOID ID '(' ')' {
            if (find_in_level(tabla, $2)) {
                yyerror("Metodo declarado mas de una vez\n");
                YYABORT;
            }
            new_level(tabla);
        } '{' Linea '}' {
            close_level(tabla);
            Symbol *simb = create_symb(VOID1, 0, $2);
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            $$ = create_node(NODE_MET_DECLARATION, simb, NULL, $7, NULL);
        }

Type: INT   { Symbol *simb = create_symb(INT1, 0, NULL);
            $$ = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
    | BOOLEAN   { Symbol *simb = create_symb(BOOL1, 0, NULL);
            $$ = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
    | FLOAT { Symbol *simb = create_symb(FLOAT1, 0, NULL);
            $$ = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
    ;

Params:
    Param ',' Params    {
            $$ = create_node(NODE_PARAM_DECLARATION, NULL, $1, $3, NULL);
            }
    | Param {$$ = $1;}
    ;

Param: Type ID {
            if (find_in_level(tabla, $2)) {
                yyerror("Parametro declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb($1->info->exprType, 0, $2);
            insert_symbolo(tabla, simb);
            $$ = create_node(NODE_PARAM_DECLARATION, simb, NULL, NULL, NULL);
        }
    ;

Linea:
      /* vacío */  {$$ = NULL;}
    | Sentencia Linea   {$$ = create_node(NODE_OP_NEWLINE, NULL, $1, $2, NULL);}
    ;

Sentencia:
      Var_decl ';'  {$$ = $1;}
    | Asign ';' {$$ = $1;}
    | IF '(' expr ')' Bloque {
                    $$ = create_node(NODE_IF, NULL, $3, $5, NULL);
                    }
    | IF '(' expr ')' Bloque ELSE Bloque    {
                    $$ = create_node(NODE_IF_ELSE, NULL, $3, $5, $7);
                    }
    | WHILE '(' expr ')' Bloque {
                    $$ = create_node(NODE_WHILE, NULL, $3, $5, NULL);
                    }
    | RETURN expr ';' {Symbol *simb = create_symb($2->info->exprType, 0, NULL);
                    $$ = create_node(NODE_OP_RETURN, simb, $2, NULL, NULL);
                    }
    | RETURN ';' {Symbol *simb = create_symb(VOID1, 0, NULL);
                    $$ = create_node(NODE_OP_RETURN, simb, NULL, NULL, NULL);
                    }
    | ';' {$$=NULL;}
    | Bloque {$$ = $1;}
    ;

Bloque: '{' {new_level(tabla);} Linea '}' {close_level(tabla);
        $$ = $3;
        }

Params_pass : expr',' Params_pass {$$ = create_node(NODE_PARAM_PASS, NULL, $1, $3, NULL);}
    | expr {$$ = $1;}
    ;

Method_call : ID '('')' {
                Symbol *simb = find_symbol(tabla, $1);
                if (!simb || !simb->isFuction) {
                    yyerror("Metodo no declarado");
                    YYABORT;
                }
                $$ = create_node(NODE_MET_CALL, simb, NULL, NULL, NULL);
            }
    | ID '(' Params_pass ')' {
                Symbol *simb = find_symbol(tabla, $1);
                if (!simb || !simb->isFuction) {
                    yyerror("Metodo no declarado");
                    YYABORT;
                }
                $$ = create_node(NODE_MET_CALL, simb, $3, NULL, NULL);
            }
    ;

expr:
      ID    {   Symbol *sim = find_symbol(tabla, $1);
                if(!sim){
                yyerror("Symbol no declarado");
                YYABORT;
                }
                $$ = create_node(NODE_ID, sim, NULL, NULL, NULL);
            }
    | Method_call {$$ = $1;}
    | LIT_FLOAT     {Symbol *simb = create_symb(FLOAT1, $1, NULL);
        $$ = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);}
    | LIT_INT   {Symbol *simb = create_symb(INT1, $1, NULL);
        $$ = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);}
    | FALSE {Symbol *simb = create_symb(BOOL1, 0, NULL);
        $$ = create_node(NODE_VAL_FALSE, simb, NULL, NULL, NULL);}
    | TRUE {Symbol *simb = create_symb(BOOL1, 1, NULL);
        $$ = create_node(NODE_VAL_TRUE, simb, NULL, NULL, NULL);}
    | expr '+' expr   {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != INT1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_ADD, simb, $1, $3, NULL);
        }
    | expr '-' expr    {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != INT1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_SUB, simb, $1, $3, NULL);
        }
    | expr '*' expr     {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != INT1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_MUL, simb, $1, $3, NULL);
        }
    | expr '/' expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != INT1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_DIV, simb, $1, $3, NULL);
        }
    | expr '%' expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != INT1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_MOD, simb, $1, $3, NULL);
        }
    | expr '<' expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != INT1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_LESS, simb, $1, $3, NULL);
        }
    | expr '>' expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != INT1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_GREAT, simb, $1, $3, NULL);
        }
    | expr EQUAL expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != INT1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_EQUAL, simb, $1, $3, NULL);
        }
    | expr AND expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != BOOL1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_AND, simb, $1, $3, NULL);
        }
    | expr OR expr  {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != BOOL1){
                error_tipo();
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_OR, simb, $1, $3, NULL);
        }
    | '-' expr %prec UMINUS {Symbol *simb = create_symb($2->info->exprType, -$2->info->value, NULL);
            $$ = create_node(NODE_AUX, simb, $2, NULL, NULL);
            }
    | '!' expr  {Symbol *simb = create_symb($2->info->exprType, -$2->info->value, NULL);
            if($2->info->exprType != BOOL1){
                error_tipo();
                YYABORT;
            }
            $$ = create_node(NODE_AUX, simb, $2, NULL, NULL);
            }
    | '(' expr ')' {$$ = $2;}
    ;

Ids_decl : ID',' Ids_decl    {
            if(!find_in_level(tabla, $1)){
                Symbol *simb = create_symb(NOT_TYPE, 0, $1);
                insert_symbolo(tabla, simb);
                $$ = create_node(NODE_AUX, simb, $3, NULL, NULL);
            }else {
                yyerror("Variable declarada mas de una vez\n");
                YYABORT;
            }
            }
    | ID    {
            if(!find_in_level(tabla, $1)){
                Symbol *simb = create_symb(NOT_TYPE, 0, $1);
                insert_symbolo(tabla, simb);
                $$ = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }else {
                yyerror("Variable declarada mas de una vez\n");
                YYABORT;
            }
            }
    ;

Var_decl: Type Ids_decl {
        $$ = create_node(NODE_DECLARATION, NULL, $1, $2, NULL);
        $2->info->exprType = $1->info->exprType;
        push_type($2);
        }
    ;

Asign: ID '=' expr { Symbol *simb = find_symbol(tabla, $1);
            if(!simb){
            yyerror("Variable no declarada");
            YYABORT;
            } else {
            $$ = create_node(NODE_ASSIGN, simb, $3, NULL, NULL);
            }
        }
    ;

%%

void yyerror(const char *s) {
    set_error(s);
    fprintf(stderr, "Error sintáctico en línea %d: %s\n", lines, s);
}
