#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "instruccion.h"
static const char *type_name(Operador t) {
    switch (t) {
        case ADD: return "ADD";
        case SUB: return "SUB";
        case MUL: return "MUL";
        case DIV: return "DIV";
        case MOD: return "MOD";
        case JUMPL: return "JUMPL";
        case JUMPG: return "JUMPG";
        case JUMPE: return "JUMPE";
        case ANDD: return "AND";
        case ORR: return "OR";
        case MOV: return "ASSIGN";
        case DEC: return "DECLARATION";
        case JUMP: return "JUMP";
        case PUSH: return "PUSH";
        case POP: return "POP";
        case RET: return "RET";
        case CMP: return "CMP";
        case LBL: return "LBL";        
        case XOR: return "XOR";
        default: return "???";
    }
}
Instruccion* create_inst(Operador op, Symbol *p1, Symbol *p2, Symbol *p3){
    Instruccion *inst = (Instruccion*)malloc(sizeof(Instruccion));
    inst->operador = op;
    inst->val1 = p1;
    inst->val2 = p2;
    inst->val3 = p3;
    return inst;
}

void add_inst(Pila *pila, Instruccion *inst){
    if(!pila->top){
        pila->top = inst;
        pila->bottom = inst;
    } else {
        pila->bottom->next = inst;
        pila->bottom = inst; 
    }
}

static const char *expr_type_name(ExprType t) {
    switch (t) {
        case INT1: return "INT";
        case BOOL1: return "BOOL";
        case FLOAT1: return "FLOAT";
        case NOT_TYPE: return "NOT_TYPE";
        case VOID1: return "VOID";
        default: return "???";
    }
}
void printSymbol(Symbol *symbol){
    if(!symbol){
        printf("NULL  ");
        return;
    }
    printf("[  name: %-5s | type: %s | value: %d ] ",
           symbol->name ? symbol->name : "(null)",
           expr_type_name(symbol->exprType),
           symbol->value);
}

void print_pila(Pila *pila){
    Instruccion *actual = pila->top;
    while(actual){
        printf("%s ", type_name(actual->operador));
        printSymbol(actual->val1);
        printSymbol(actual->val2);
        printSymbol(actual->val3);
        printf("\n");
        actual = actual->next;
    }
}

Pila* crear_pila(){
    Pila *pila = (Pila*)malloc(sizeof(Pila));
    pila->top = NULL;
    pila->bottom = NULL;
    return pila;
}