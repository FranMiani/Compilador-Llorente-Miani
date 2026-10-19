#ifndef AST_H
#define AST_H

#include "symbol.h"
#include "instruccion.h"

typedef enum {
    // Operaciones Aritméticas
    NODE_OP_ADD, NODE_OP_SUB, NODE_OP_MUL, NODE_OP_DIV, NODE_OP_MOD,
    // Operadores Relacionales
    NODE_OP_LESS, NODE_OP_GREAT,
    NODE_OP_EQUAL,
    // Operadores Lógicos
    NODE_OP_AND, NODE_OP_OR, NODE_OP_NOT,
    // Otros
    NODE_VAL_NUM, NODE_VAL_TRUE, NODE_VAL_FALSE,
    NODE_VAR,
    NODE_ASSIGN,
    NODE_DECLARATION,
    NODE_MET_DECLARATION,
    NODE_EXTERN_DECLARATION,
    NODE_MET_CALL,
    NODE_OP_RETURN,
    NODE_ID,
    NODE_OP_NEWLINE,
    NODE_OP_FUNC,
    NODE_IF,
    NODE_IF_ELSE,
    NODE_WHILE,
    NODE_PARAM_DECLARATION,
    NODE_PARAM_DECLARATION_PURE,
    NODE_PARAM_PASS,
    NODE_AUX,
    NODE_AUX_DEC
} NodeType;     // REVISAR

typedef struct Node {
    NodeType type;
    struct Symbol *info;
    struct Node *left;
    struct Node *right;
    struct Node *third;
    struct Symbol *dirRet;
} Node;

void initReg();
void push_type(Node *node);
Node* create_node(NodeType type, Symbol *simb, Node *left, Node *third, Node *right);
Symbol* create_simb(ExprType exprtype, int value, char *name);
void print_ast(Node *node, int indent);
void free_ast(Node *node);
Symbol* search_last_Symbol(Node *father);
void print_from_to(Symbol *from, Symbol *to);
Symbol* verify_params(Symbol *from, Node *actual);
void addDirRet(Node *node, Symbol *dir);
void armarPila(Pila *pila, Node *node);

#endif