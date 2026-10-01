#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "symbol.h"
int nivelActual = 0;

SymbolTable* init_table() {
    SymbolTable *table = malloc(sizeof(SymbolTable));
    if (!table) return NULL;

    table->head = NULL;
    table->levels = malloc(sizeof(Levels));

    if (!table->levels) {
        free(table);
        return NULL;
    }

    table->levels->level = NULL;
    table->levels->back = NULL;

    return table;
}

Symbol* create_symb(ExprType exprtype, int value, char *name) {
    Symbol *s = (Symbol*)calloc(1,sizeof(Symbol));
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

Symbol* find_in_level(SymbolTable *table, char *name) {
    if (!table || !name) return NULL;

    Symbol *current = table->head;

    while (current != NULL && current != table->levels->level) {
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
    print_current_level(table, nivelActual++);
    table->levels = actual->back;
    //delete_until(temp, table->head); si los elimino despues al imprimir el arbol leo basura
    table->head = temp;
    //free(actual);
}

void print_current_level(SymbolTable *table, int nivelActual) {
    if (!table || !table->levels) return;

    printf("cerrando nivel %d \n", nivelActual);
    Symbol *current = table->head;
    Symbol *limit = table->levels->level;

    if (current == limit) {
        printf("  (Nivel vacio)\n");
    } else {
        while (current != NULL && current != limit) {
            printf("  name: %-15s | type: %d | value: %d\n",
                   current->name ? current->name : "(null)",
                   current->exprType,
                   current->value);
            current = current->next;
        }
    }
    printf("\n");
}

void delete_until(Symbol *symb, Symbol *actual){
    if(!actual || actual==symb) return;
    delete_until(symb, actual->next);
    free(actual);
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

void print_table(SymbolTable *table) {
    if (!table) return;



    Levels *level = table->levels;
    Symbol *current = table->head;


    while (level != NULL) {
        printf("\n[LEVEL %d]\n", nivelActual);

        Symbol *limit = level->level;

        while (current != NULL && current != limit) {
            printf("  name: %-15s | type: %s | value: %d\n",
                   current->name ? current->name : "(null)",
                   expr_type_name(current->exprType),
                   current->value);

            current = current->next;
        }

        level = level->back;
        nivelActual++;
    }

    printf("\n========================\n");
}
