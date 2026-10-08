%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "symbol_table.h"
#include "ast.h"
#include "instruccion.h"
#define _GNU_SOURCE

SymbolTable *tabla;
Node *father;

int lines = 1;
ExprType returnType = VOID1;

void addLine(){
    lines++;
}

int params_cant = 0;
int param_extract = 1;
int temps = 0;
Symbol* registros[3];
Pila *pila;
struct Symbol *retFunc = NULL;
Symbol *pilaTop; 

Symbol* registro_correspondiente() {
    temps = temps % 3;
    return registros[temps++];
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

preinput:  { retFunc = create_symb(NOT_TYPE, 0, "D");
            registros[0] =
            create_symb(NOT_TYPE, NULL, "A");
            registros[1] =
            create_symb(NOT_TYPE, NULL, "B");
            registros[2] =
            create_symb(NOT_TYPE, NULL, "C");
            pilaTop = create_symb(NOT_TYPE, NULL, "TOP"); 
}input  {
    Symbol *simb = create_symb(NOT_TYPE, 0, NULL);
    $$ = create_node(NODE_OP_FUNC, simb, $2, NULL, NULL);
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
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            
            returnType = $1->info->exprType;
            Symbol *simb = create_symb($1->info->exprType, 0, $2);
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            add_inst(pila,create_inst(LBL,simb, NULL, NULL));
            new_level(tabla);
        } Params ')' '{' Linea '}' {
            close_level(tabla);
            Symbol *simb = find_symbol(tabla, $2);
            if(!$5->left){
                simb->init=$5->info;
                simb->end=$5->info;
            }else{
                simb->init=$5->left->info;
                simb->end = search_last_Symbol($5);
            }
            print_from_to(simb->end,simb->init);
            $$ = create_node(NODE_MET_DECLARATION, find_symbol(tabla, $2), $5, $8, NULL);
            returnType = VOID1;
        }
    | VOID ID '(' {
            if (find_in_level(tabla, $2)) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb(VOID1, 0, $2);
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            add_inst(pila,create_inst(LBL,simb, NULL, NULL));
            new_level(tabla);
        } Params ')' '{' Linea '}' {
            close_level(tabla);

            $$ = create_node(NODE_MET_DECLARATION, find_symbol(tabla, $2), $5, $8, NULL);
            
        }
    | Type ID '(' ')' {
            if (find_in_level(tabla, $2)) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            returnType = $1->info->exprType;
            Symbol *simb = create_symb($1->info->exprType, 0, $2);
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            add_inst(pila,create_inst(LBL,simb, NULL, NULL));
            new_level(tabla);
        } '{' Linea '}' {
            close_level(tabla);
            returnType = VOID1;
            $$ = create_node(NODE_MET_DECLARATION, find_symbol(tabla, $2), NULL, $7, NULL);
            
        }
    | VOID ID '(' ')' {
            if (find_in_level(tabla, $2)) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb(VOID1, 0, $2);
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            add_inst(pila,create_inst(LBL,simb, NULL, NULL));
            new_level(tabla);
        } '{' Linea '}' {
            close_level(tabla);

            $$ = create_node(NODE_MET_DECLARATION, find_symbol(tabla, $2), NULL, $7, NULL);
            add_inst(pila,create_inst(LBL,find_symbol(tabla, $2), NULL, NULL));
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
            add_inst(pila,create_inst(MOV,$1->info, pilaTop, create_symb(INT1, param_extract++, NULL)));
            }
    | Param {$$ = $1;
        add_inst(pila,create_inst(MOV,$1->info, pilaTop, create_symb(INT1, param_extract, NULL)));
        param_extract=0;
        }
    ;

Param: Type ID {
            if (find_in_level(tabla, $2)) {
                yyerror("Error de sintaxis: Parametro declarado mas de una vez\n");
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
    | IF '(' expr {add_inst(pila,create_inst(JUMPF,$3->dirRet,create_symb(VOID1, NULL, "endIF"),NULL));}')' Bloque {
                    if($3->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    $$ = create_node(NODE_IF, NULL, $3, $6, NULL);
                    add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "endIF"), NULL, NULL));
                    }
    | IF '(' expr {add_inst(pila,create_inst(JUMPF,$3->dirRet,create_symb(VOID1, NULL, "Else"),NULL));}')' Bloque {add_inst(pila,create_inst(JUMPF,$3->dirRet,create_symb(VOID1, NULL, "endIF"),NULL));} ELSE { add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "Else"), NULL, NULL));}
    Bloque    {
                    if($3->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    $$ = create_node(NODE_IF_ELSE, NULL, $3, $6, $10);
                    add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "endIF"), NULL, NULL));
                    }
    | WHILE {add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "While"), NULL, NULL));} '(' expr {add_inst(pila,create_inst(JUMPF,$4->dirRet,create_symb(VOID1, NULL, "endWhile"),NULL));}')' Bloque {
                    if($4->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    $$ = create_node(NODE_WHILE, NULL, $4, $7, NULL);
                    add_inst(pila,create_inst(JUMP, create_symb(VOID1, NULL, "While"), NULL, NULL));
                    add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "endWhile"), NULL, NULL));
                    }
    | RETURN expr ';' {Symbol *simb = create_symb($2->info->exprType, 0, NULL);
                    if(returnType!=simb->exprType){
                        if((returnType==INT1 ||returnType==FLOAT1) && (simb->exprType==INT1 || simb->exprType==FLOAT1)){
                            yyerror("Warning: Tipos no coinciden");
                        } else {
                            yyerror("Error de sintaxis: tipo de retorno incompatible");
                        }
                    }
                    add_inst(pila,create_inst(RET, simb, NULL, NULL));
                    $$ = create_node(NODE_OP_RETURN, simb, $2, NULL, NULL);
                    }
    | RETURN ';' {Symbol *simb = create_symb(VOID1, 0, NULL);
                    if(returnType!=VOID1){
                        yyerror("Error de sintaxis: tipo de retorno incompatible");
                    }
                    add_inst(pila,create_inst(RET, NULL, NULL, NULL));
                    $$ = create_node(NODE_OP_RETURN, simb, NULL, NULL, NULL);
                }
    | ';' {$$=NULL;}
    | Bloque {$$ = $1;}
    | Method_call ';' {$$=$1;}
    ;

Bloque: '{' {new_level(tabla);} Linea '}' {close_level(tabla);
        $$ = $3;
        }

Params_pass : expr',' Params_pass {$$ = create_node(NODE_PARAM_PASS, NULL, $1, $3, NULL);
        add_inst(pila,create_inst(PUSH,$1->dirRet, NULL, NULL));
        params_cant++;
    }
    | expr {$$ = $1;
        add_inst(pila,create_inst(PUSH,$1->dirRet, NULL, NULL));
        params_cant++;
        }
    ;

Method_call : ID '('')' {
                Symbol *simb = find_symbol(tabla, $1);
                if (!simb || !simb->isFuction) {
                    yyerror("Error de sintaxis: Metodo no declarado");
                    YYABORT;
                }
                $$ = create_node(NODE_MET_CALL, simb, NULL, NULL, NULL);
                addDirRet($$, retFunc);
                add_inst(pila,create_inst(JUMP,simb, NULL, NULL));
            }
    | ID '(' Params_pass ')' {
                Symbol *simb = find_symbol(tabla, $1);
                if (!simb || !simb->isFuction) {
                    yyerror("Error de sintaxis: Metodo no declarado");
                    YYABORT;
                }
                Symbol *aux = verify_params(simb->end, $3);
                if(!aux || aux !=simb->init->next){
                    yyerror("Error de sintaxis: Parametros Incorrectos");
                }
                $$ = create_node(NODE_MET_CALL, simb, $3, NULL, NULL);
                addDirRet($$, retFunc);
                add_inst(pila,create_inst(JUMP,simb, NULL, NULL));
                while(params_cant>0){
                    add_inst(pila,create_inst(POP,NULL, NULL, NULL));
                    params_cant--;
                }
            }
    ;

expr:
      ID    {   Symbol *sim = find_symbol(tabla, $1);
                if(!sim){
                yyerror("Error de sintaxis: Variable no declarado");
                YYABORT;
                }
                $$ = create_node(NODE_ID, sim, NULL, NULL, NULL);
                addDirRet($$, sim);
            }
    | Method_call {$$ = $1;}
    | LIT_FLOAT     {Symbol *simb = create_symb(FLOAT1, $1, NULL);
        $$ = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);
        addDirRet($$, simb);
        }
    | LIT_INT   {Symbol *simb = create_symb(INT1, $1, NULL);
        $$ = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);
        addDirRet($$, simb);
        }
    | FALSE {Symbol *simb = create_symb(BOOL1, 0, NULL);
        $$ = create_node(NODE_VAL_FALSE, simb, NULL, NULL, NULL);
        addDirRet($$, simb);
        }
    | TRUE {Symbol *simb = create_symb(BOOL1, 1, NULL);
        $$ = create_node(NODE_VAL_TRUE, simb, NULL, NULL, NULL);
        addDirRet($$, simb);
        }
    | expr '+' expr   {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType){
                if(($1->info->exprType != INT1 && $1->info->exprType != FLOAT1)||
                ($3->info->exprType != INT1 && $3->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb($3->info->exprType, 0, NULL);
            }
            $$ = create_node(NODE_OP_ADD, simb, $1, $3, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(ADD,$1->dirRet, $3->dirRet, $$->dirRet));
        }
    | expr '-' expr    {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType){
                if(($1->info->exprType != INT1 && $1->info->exprType != FLOAT1)||
                ($3->info->exprType != INT1 && $3->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb($3->info->exprType, 0, NULL);
            }
            $$ = create_node(NODE_OP_SUB, simb, $1, $3, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(SUB,$1->dirRet, $3->dirRet, $$->dirRet));
        }
    | expr '*' expr     {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType){
                if(($1->info->exprType != INT1 && $1->info->exprType != FLOAT1)||
                ($3->info->exprType != INT1 && $3->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb($3->info->exprType, 0, NULL);
            }
            $$ = create_node(NODE_OP_MUL, simb, $1, $3, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(MUL,$1->dirRet, $3->dirRet, $$->dirRet));
        }
    | expr '/' expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType){
                if(($1->info->exprType != INT1 && $1->info->exprType != FLOAT1)||
                ($3->info->exprType != INT1 && $3->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb($3->info->exprType, 0, NULL);
            }
            $$ = create_node(NODE_OP_DIV, simb, $1, $3, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(DIV,$1->dirRet, $3->dirRet, $$->dirRet));
        }
    | expr '%' expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType){
                if(($1->info->exprType != INT1 && $1->info->exprType != FLOAT1)||
                ($3->info->exprType != INT1 && $3->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb($3->info->exprType, 0, NULL);
            }
            $$ = create_node(NODE_OP_MOD, simb, $1, $3, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(MOD,$1->dirRet, $3->dirRet, $$->dirRet));
        }
    | expr '<' expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType){
                if(($1->info->exprType != INT1 && $1->info->exprType != FLOAT1)||
                ($3->info->exprType != INT1 && $3->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                }
            }
            simb = create_symb(BOOL1, 0, NULL);
            $$ = create_node(NODE_OP_LESS, simb, $1, $3, NULL);
            Symbol *aux = registro_correspondiente();
            add_inst(pila,create_inst(CMP,$1->dirRet, $3->dirRet, aux));
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(LESS, aux, NULL, $$->dirRet));
        }
    | expr '>' expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType){
                if(($1->info->exprType != INT1 && $1->info->exprType != FLOAT1)||
                ($3->info->exprType != INT1 && $3->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                }
            }
            simb = create_symb(BOOL1, 0, NULL);
            $$ = create_node(NODE_OP_GREAT, simb, $1, $3, NULL);
            Symbol *aux = registro_correspondiente();
            add_inst(pila,create_inst(CMP,$1->dirRet, $3->dirRet, aux));
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(GREAT, aux, NULL, $$->dirRet));
        }
    | expr EQUAL expr {Symbol *simb = NULL;
            simb = create_symb(BOOL1, 0, NULL);
            $$ = create_node(NODE_OP_EQUAL, simb, $1, $3, NULL);
            Symbol *aux = registro_correspondiente();
            add_inst(pila,create_inst(CMP,$1->dirRet, $3->dirRet, aux));
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(EQUAL, aux, NULL, $$->dirRet));
            
        }
    | expr AND expr {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_AND, simb, $1, $3, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(ANDD,$1->dirRet, $3->dirRet, $$->dirRet));
        }
    | expr OR expr  {Symbol *simb = NULL;
            if($3->info->exprType != $1->info->exprType || $1->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            simb = create_symb($3->info->exprType, 0, NULL);
            $$ = create_node(NODE_OP_OR, simb, $1, $3, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(ORR,$1->dirRet, $3->dirRet, $$->dirRet));
        }
    | '-' expr %prec UMINUS {
            if($2->info->exprType != INT1 && $2->info->exprType != FLOAT1){
                yyerror("Error de tipo");
                YYABORT;
            }
            Symbol *simb = create_symb($2->info->exprType, -$2->info->value, NULL);
            $$ = create_node(NODE_AUX, simb, $2, NULL, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(MUL,$2->dirRet, create_symb(INT1, NULL, -1), $$->dirRet));
            }
    | '!' expr  {
            if($2->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            Symbol *simb = create_symb($2->info->exprType, -$2->info->value, NULL);
            if($2->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            $$ = create_node(NODE_AUX, simb, $2, NULL, NULL);
            addDirRet($$, registro_correspondiente());
            add_inst(pila,create_inst(XOR,$2->dirRet, create_symb(BOOL1, NULL, 1), $$->dirRet));
            }
    | '(' expr ')' {$$ = $2;}
    ;

Ids_decl : ID',' Ids_decl    {
            if(!find_in_level(tabla, $1)){
                Symbol *simb = create_symb(NOT_TYPE, 0, $1);
                insert_symbolo(tabla, simb);
                $$ = create_node(NODE_AUX, simb, $3, NULL, NULL);
            }else {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
            add_inst(pila,create_inst(DEC,find_in_level(tabla, $1), NULL, NULL));
            }
    | ID    {
            if(!find_in_level(tabla, $1)){
                Symbol *simb = create_symb(NOT_TYPE, 0, $1);
                insert_symbolo(tabla, simb);
                $$ = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }else {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
            add_inst(pila,create_inst(DEC,find_in_level(tabla, $1), NULL, NULL));
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
                yyerror("Error de sintaxis: Variable no declarada");
                YYABORT;
            } else {
            if($3->info->exprType != simb->exprType){
                if((simb->exprType != INT1 && simb->exprType != FLOAT1)||
                ($3->info->exprType != INT1 && $3->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                        yyerror("Warning: tipos no coinciden");
                }
            }
            $$ = create_node(NODE_ASSIGN, simb, $3, NULL, NULL);
            add_inst(pila,create_inst(MOV,simb, $3->dirRet, NULL));
            
            }
        }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s en la linea %d\n", s, lines);
}
