#include "ast.h"
#include <stdio.h>
#include "symbol.h"
#include <stdlib.h>

void optimizarCalculosLiterales(Node *node){
    if(!node) return;
    switch (node->type) {
        case NODE_OP_ADD:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
                node->info->value = node->left->info->value + node->third->info->value;
                node->type = NODE_VAL_NUM;
            }
            return;
        case NODE_OP_SUB:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
                node->info->value = node->left->info->value - node->third->info->value;
                node->type = NODE_VAL_NUM;
            }
            return;
        case NODE_OP_MUL:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
                node->info->value = node->left->info->value * node->third->info->value;
                node->type = NODE_VAL_NUM;
            }
            return;
        case NODE_OP_DIV:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
                if(node->third->info->value == 0){
                    printf("Error division por 0\n");
                }
                node->info->value = node->left->info->value / node->third->info->value;
                node->type = NODE_VAL_NUM;
            }
            return;
        case NODE_OP_MOD:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
                if(node->third->info->value == 0){
                    printf("Error division por 0\n");
                }
                node->info->value = node->left->info->value % node->third->info->value;
                node->type = NODE_VAL_NUM;
            }
            return;
        case NODE_OP_LESS:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
                if(node->left->info->value < node->third->info->value){
                    node->info->value = 1;
                    node->type = NODE_VAL_TRUE;
                }else{
                    node->info->value = 0;
                    node->type = NODE_VAL_FALSE;
                }
            }
            return;
        case NODE_OP_GREAT:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
                if(node->left->info->value > node->third->info->value){
                    node->info->value = 1;
                    node->type = NODE_VAL_TRUE;
                }else{
                    node->info->value = 0;
                    node->type = NODE_VAL_FALSE;
                }
            }
            return;
        case NODE_OP_EQUAL:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
                if(node->left->info->value == node->third->info->value){
                    node->info->value = 1;
                    node->type = NODE_VAL_TRUE;
                }else{
                    node->info->value = 0;
                    node->type = NODE_VAL_FALSE;
                }
            }
            return;
        case NODE_OP_AND:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);

            if(node->left->type == NODE_VAL_FALSE || node->third->type == NODE_VAL_FALSE){


                node->type = NODE_VAL_FALSE;
                node->info->value = 0;
                node->third = NULL;
                node->left = NULL;
            }else{
                if(node->third->type == NODE_VAL_TRUE){

                    node->type = node->left->type;
                    node->info= node->left->info;
                    node->third = node->left->third;
                    node->left = node->left->left;
                }else{
                    if(node->left->type == NODE_VAL_TRUE){

                        node->type = node->third->type;
                        node->info= node->third->info;
                        node->left = node->third->left;
                        node->third = node->third->third;
                    }
                }
            }
            return;
        case NODE_OP_OR:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_TRUE || node->third->type == NODE_VAL_TRUE){
                node->type = NODE_VAL_TRUE;
                node->info->value = 1;
                node->third = NULL;
                node->left = NULL;
            }else{
                if(node->third->type == NODE_VAL_FALSE){
                    node->type = node->left->type;
                    node->info= node->left->info;
                    node->third = node->left->third;
                    node->left = node->left->left;
                }else{
                    if(node->left->type == NODE_VAL_FALSE){
                        node->type = node->third->type;
                        node->info= node->third->info;
                        node->left = node->third->left;
                        node->third = node->third->third;
                    }
                }
            }

            return;
        case NODE_OP_NOT:
            optimizarCalculosLiterales(node->left);
            if(node->left->type == NODE_VAL_TRUE || node->left->type == NODE_VAL_FALSE){
                if(node->left->type == NODE_VAL_FALSE){
                    node->info->value = 1;
                    node->type = NODE_VAL_TRUE;
                }else{
                    node->info->value = 0;
                    node->type = NODE_VAL_FALSE;
                }
            }
            return;
        default: optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            optimizarCalculosLiterales(node->right);
    }
    return;
}

void optimizarCaminos(Node *node){
    Symbol *x;
    if(!node) return;
    if(node->type == NODE_OP_NEWLINE){
        switch (node->left->type){
            case NODE_IF:
                if(node->left->left->type==NODE_VAL_TRUE){
                    node->left = node->left->third;
                }else{
                    if(node->left->left->type==NODE_VAL_FALSE){
                        node->left=NULL;
                    }
                }
                break;
            case NODE_IF_ELSE:
                if(node->left->left->type==NODE_VAL_TRUE){
                    node->left = node->left->third;
                }else{
                    if(node->left->left->type==NODE_VAL_FALSE){
                        node->left=node->left->third;
                    }
                }
                break;
            case NODE_WHILE:
                if(node->left->left->type==NODE_VAL_FALSE){
                    node->left=NULL;
                }
                break;
        }

    }
    optimizarCaminos(node->left);
    optimizarCaminos(node->third);
    optimizarCaminos(node->third);
}
