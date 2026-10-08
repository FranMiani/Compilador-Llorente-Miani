#ifndef INSTRUCCION
#define INSTRUCCION
#include "symbol.h"

typedef enum {
    ADD, SUB, MUL, DIV, MOD,
    CMP, ANDD, ORR, XOR, LESS, GREAT,
    MOV, DEC,
    JUMPG, JUMPL, JUMPE, JUMP, LBL, JUMPF,
    PUSH, POP, RET
} Operador;

typedef struct Instruccion{
    Operador operador;
    Symbol *val1;
    Symbol *val2;
    Symbol *val3;
    struct Instruccion *next;
} Instruccion;

typedef struct Pila{
    Instruccion *top;
    Instruccion *bottom;
} Pila;

Instruccion* create_inst(Operador op, Symbol *p1, Symbol *p2, Symbol *p3);

void add_inst(Pila *pila, Instruccion *inst);

void print_pila(Pila *pila);

Pila* crear_pila();

#endif
