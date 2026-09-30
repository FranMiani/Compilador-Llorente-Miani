#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "symbol.h"
#include "symbol_table.h"

Node* create_node(NodeType type, Symbol *simb, Node *left, Node *third, Node *right) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->third = third;
    node->right = right;
    node->info = simb;
    return node;
}

void print_ast(Node *node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; i++) printf("  ");

    printf("Tipo: %d  ", node->type);
    if(node->info && node->info->value){
        printf("Valor: %d", node->info->value);
    }
    printf("\n");
    print_ast(node->left, indent + 1);
    print_ast(node->third, indent + 1);
    print_ast(node->right, indent + 1);



}

void free_ast(Node *node) {
    if (!node) return;
    free_ast(node->left);
    free_ast(node->right);
    free(node);
}

void push_type(Node *node){
    if(!node) return;
    if(!node->left) return;
    ExprType symbol_type = node->info->exprType;
    Symbol *simb = node->left->info;
    simb->exprType = symbol_type;
    push_type(node->left);
}
