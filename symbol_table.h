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
SymbolTable* init_table();
Symbol* insert_symbol(SymbolTable *table, ExprType type, char *name, int value);
Symbol* find_symbol(SymbolTable *table, char *name);
Symbol* find_in_level(SymbolTable *table, char *name);
void free_table(SymbolTable *table);
void set_init(Symbol *func, Symbol *param);
void set_end(Symbol *func, Symbol *param);
Symbol* create_symb(ExprType exprtype, int value, char *name);
Symbol* insert_symbolo(SymbolTable *table, Symbol *s);
void print_table(SymbolTable *table);
void print_current_level(SymbolTable *table, int level_num);
#endif
