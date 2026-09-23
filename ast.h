#ifndef AST_H
#define AST_H

#include "symbol.h"

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
    NODE_OP_RETURN,
    NODE_ID,
    NODE_OP_NEWLINE, 
    NODE_OP_FUNC,
    NODE_IF,
    NODE_IF_ELSE,
    NODE_WHILE
    
} NodeType;

typedef struct Node {
    NodeType type;
    struct Symbol *info;
    struct Node *left;
    struct Node *right;
    struct Node *third;
} Node;

Node* create_node(NodeType type, Symbol *simb, Node *left, Node *third, Node *right);
Symbol* create_simb(ExprType exprtype, int value, char *name);
void print_ast(Node *node, int indent);
void free_ast(Node *node);

#endif
