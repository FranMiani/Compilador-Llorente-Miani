#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "symbol.h"
#include "symbol_table.h"

static const char *node_type_name(NodeType t) {
    switch (t) {
        case NODE_OP_ADD: return "NODE_OP_ADD";
        case NODE_OP_SUB: return "NODE_OP_SUB";
        case NODE_OP_MUL: return "NODE_OP_MUL";
        case NODE_OP_DIV: return "NODE_OP_DIV";
        case NODE_OP_MOD: return "NODE_OP_MOD";
        case NODE_OP_LESS: return "NODE_OP_LESS";
        case NODE_OP_GREAT: return "NODE_OP_GREAT";
        case NODE_OP_EQUAL: return "NODE_OP_EQUAL";
        case NODE_OP_AND: return "NODE_OP_AND";
        case NODE_OP_OR: return "NODE_OP_OR";
        case NODE_OP_NOT: return "NODE_OP_NOT";
        case NODE_VAL_NUM: return "NODE_VAL_NUM";
        case NODE_VAL_TRUE: return "NODE_VAL_TRUE";
        case NODE_VAL_FALSE: return "NODE_VAL_FALSE";
        case NODE_VAR: return "NODE_VAR";
        case NODE_ASSIGN: return "NODE_ASSIGN";
        case NODE_DECLARATION: return "NODE_DECLARATION";
        case NODE_MET_DECLARATION: return "NODE_MET_DECLARATION";
        case NODE_MET_CALL: return "NODE_MET_CALL";
        case NODE_OP_RETURN: return "NODE_OP_RETURN";
        case NODE_ID: return "NODE_ID";
        case NODE_OP_NEWLINE: return "NODE_OP_NEWLINE";
        case NODE_OP_FUNC: return "NODE_OP_FUNC";
        case NODE_IF: return "NODE_IF";
        case NODE_IF_ELSE: return "NODE_IF_ELSE";
        case NODE_WHILE: return "NODE_WHILE";
        case NODE_PARAM_DECLARATION: return "NODE_PARAM_DECLARATION";
        case NODE_PARAM_PASS: return "NODE_PARAM_PASS";
        case NODE_AUX: return "NODE_AUX";
        default: return "NODE_???";
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

    printf("%s", node_type_name(node->type));
    if (node->info) {
        if (node->info->name)
            printf(" name=%s", node->info->name);
        printf(" type=%s", expr_type_name(node->info->exprType));
        printf(" value=%d", node->info->value);
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
