#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "symbol.h"

SymbolTable* init_table() {
    SymbolTable *table = (SymbolTable*)malloc(sizeof(SymbolTable));
    if (!table) return NULL;
    table->head = NULL;
    return table;
}

Symbol* create_symb(ExprType exprtype, int value, char *name) {
    Symbol *s = (Symbol*)malloc(sizeof(Symbol));
    if (!s) return NULL;
    s->exprType = exprtype;
    s->value = value;
    s->name = name ? strdup(name) : NULL;
    s->next = NULL;
    return s;
}

Symbol* insert_symbol(SymbolTable *table, ExprType type, char *name, int value) {
    Symbol *s = create_symb(type, value, name);
    if (!s) return NULL;
    s->next = table->head;
    table->head = s;
    return s;
}

Symbol* insert_symbolo(SymbolTable *table, Symbol *s) {
    if (!s) return NULL;
    s->next = table->head;
    table->head = s;
    return s;
}

Symbol* find_symbol(SymbolTable *table, char *name) {
    if (!name) return NULL;
    Symbol *current = table->head;
    while (current != NULL) {
        if (current->name && strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Symbol* find_in_level(SymbolTable *table, char *name){
    if(!name) return NULL;
    Symbol *current = table->head;
    while (current != table->levels->level) {
        if (current->name && strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void free_table(SymbolTable *table) {
    if (!table) return;
    Symbol *current = table->head;
    while (current != NULL) {
        Symbol *next = current->next;
        if (current->name) free(current->name);
        free(current);
        current = next;
    }
    free(table);
}

void new_level(SymbolTable *table){
    Symbol *level = table->head;
    Levels *l = table->levels;
    Levels *new = (Levels*)malloc(sizeof(Levels));
    new->level = table->head;
    new->back = l;
    table->levels = new;
}

void close_level(SymbolTable *table){
    Levels *actual = table->levels;
    Symbol *temp = actual->level;
    table->levels = actual->back;
    delete_until(temp, table->head);
    table->head = temp;
}

void delete_until(Symbol *symb, Symbol *actual){
    if(!actual || actual==symb) return;
    delete_until(symb, actual->next);
    free(actual);
}
