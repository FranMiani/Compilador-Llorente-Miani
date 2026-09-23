//por ahora la tabla de simbolos solo tiene un nivel

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "symbol.h"

typedef struct Levels{
    Symbol *level;
    struct Levels *back;
} Levels;

typedef struct {
    Symbol *head;
    Levels *levels;
} SymbolTable;

void new_level(SymbolTable *table);
void close_level(SymbolTable *table);
void delete_until(Symbol *symb, Symbol *actual);
Symbol* find_in_level(SymbolTable *table, char *name);
SymbolTable* init_table();
Symbol* insert_symbol(SymbolTable *table, ExprType type, char *name, int value);
Symbol* find_symbol(SymbolTable *table, char *name);
void free_table(SymbolTable *table);
Symbol* create_symb(ExprType exprtype, int value, char *name);
Symbol* insert_symbolo(SymbolTable *table, Symbol *s);

#endif