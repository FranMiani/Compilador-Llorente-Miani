#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "parser.tab.h"
#include "symbol.h"
#include "instruccion.h"
#include "symbol_table.h"
int params_can = 0;
int param_extrac = 1;
int temp = 0;
struct Symbol *retFun = NULL;
Symbol *pilaTope;

struct Symbol *last = NULL;

int a = 'A';
int count = 0;

int andCount=0;
char* endAnd(){
    char* result = (char*)malloc(10 * sizeof(char));
    char* aux = "End_And";
    if (andCount == 0) {
        sprintf(result, "%s", aux);
        andCount++;
    } else {
        sprintf(result, "%s%d", aux, andCount++);
    }
    return result;
}

int orCount=0;
char* endOr(){
    char* result = (char*)malloc(10 * sizeof(char));
    char* aux = "End_OR";
    if (orCount == 0) {
        sprintf(result, "%s", aux);
        orCount++;
    } else {
        sprintf(result, "%s%d", aux, orCount++);
    }
    return result;
}

int ifCount=0;
char* endIf(){
    char* result = (char*)malloc(10 * sizeof(char));
    char* aux = "End_if";
    if (ifCount == 0) {
        sprintf(result, "%s", aux);
        ifCount++;
    } else {
        sprintf(result, "%s%d", aux, ifCount++);
    }
    return result;
}
int elseCount=0;
char* idElse(){
    char* result = (char*)malloc(10 * sizeof(char));
    char* aux = "Else";
    if (elseCount == 0) {
        sprintf(result, "%s", aux);
        elseCount++;
    } else {
        sprintf(result, "%s%d", aux, elseCount++);
    }
    return result;
}

int endWhileCount=0;
char* endWhile(){
    char* result = (char*)malloc(15 * sizeof(char));
    char* aux = "End_While";
    if (endWhileCount == 0) {
        sprintf(result, "%s", aux);
        endWhileCount++;
    } else {
        sprintf(result, "%s%d", aux, endWhileCount++);
    }
    return result;
}

int whileCount=0;
char* idWhile(){
    char* result = (char*)malloc(10 * sizeof(char));
    char* aux = "While";
    if (whileCount == 0) {
        sprintf(result, "%s", aux);
        whileCount++;
    } else {
        sprintf(result, "%s%d", aux, whileCount++);
    }
    return result;
}

char* name() {
    // 1. Reservamos memoria para el nombre (suficiente para "A", "Z1", "Z99", etc.)
    char* result = (char*)malloc(count + 2 * sizeof(char));
    if (!result) return NULL; // Por seguridad si falla malloc
    if (count == 0) {
        sprintf(result, "%c", a);
    } else {
        sprintf(result, "%c%d", a, count);
    }

    a++;
    if (a > 'Z') {
        a = 'A';
        count++;
    }

    return result;
}
Symbol* registro_siguiente() {
    if(!last){
        last = create_symb(NOT_TYPE, 0, name());
    }else{
        last = create_symb(NOT_TYPE, 0, name());
    }
    return last;
}

void initReg(){
    retFun = create_symb(NOT_TYPE, 0, "RET");
    pilaTope = create_symb(NOT_TYPE, 0, "TOP");
}
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
        case NODE_PARAM_DECLARATION_PURE: return "NODE_PARAM_DECLARATION";
        case NODE_PARAM_PASS: return "NODE_PARAM_PASS";
        case NODE_AUX: return "NODE_AUX";
        case NODE_AUX_DEC: return "NODE_AUX";
        default: return "NODE_???";
    }
}
int comp(ExprType a, ExprType b);
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

void addDirRet(Node *node, Symbol *dir){
    node->dirRet = dir;
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


Symbol* search_last_Symbol(Node *father){
    if(!father->left){
        return father->info;
    }
    return search_last_Symbol(father->third);
}

void print_from_to(Symbol *from, Symbol *to){
    printf(" name=%s", from->name);
    printf(" type=%s", expr_type_name(from->exprType));
    printf("\n");
    if(from==to)return;
    print_from_to(from->next, to);
}

Symbol* verify_params(Symbol *from, Node *actual){
    if(actual->type!=NODE_PARAM_PASS){
        if(comp(from->exprType, actual->info->exprType)){
            return from->next;
        }else{
            return NULL;
        }
    }else{
        Symbol *aux = verify_params(from, actual->third);
        if(!aux)return NULL;
        if(comp(aux->exprType,actual->left->info->exprType)) return aux->next;
        return NULL;
    }
}
int comp(ExprType a, ExprType b){
    return (a==b||((a==FLOAT1||a==INT1) && (b==FLOAT1 || b==INT1)) );
}

int cantidadP(Symbol *init, Symbol *end){
    if(init==NULL) return 0;
    if(init==end) return 1;
    return 1 + cantidadP(init, end->next);
}
void armarPila(Pila *pila, Node *node){
    if(!node) return;
    switch (node->type) {
        case NODE_OP_ADD:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(ADD,node->left->dirRet, node->third->dirRet, node->dirRet));
            return;
        case NODE_OP_SUB:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(SUB,node->left->dirRet, node->third->dirRet, node->dirRet));
            return;
        case NODE_OP_MUL:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(MUL,node->left->dirRet, node->third->dirRet, node->dirRet));
            return;
        case NODE_OP_DIV:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(DIV,node->left->dirRet, node->third->dirRet, node->dirRet));
            return;
        case NODE_OP_MOD:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(MOD,node->left->dirRet, node->third->dirRet, node->dirRet));
            return;
        case NODE_OP_LESS:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            Symbol *aux = registro_siguiente();
            add_inst(pila,create_inst(CMP,node->left->dirRet, node->third->dirRet, aux));
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(LESS, aux, NULL, node->dirRet));
            return;
        case NODE_OP_GREAT:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            Symbol *aux2 = registro_siguiente();
            add_inst(pila,create_inst(CMP,node->left->dirRet, node->third->dirRet, aux2));
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(GREAT, aux2, NULL, node->dirRet));
            return;
        case NODE_OP_EQUAL:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            Symbol *aux3 = registro_siguiente();
            add_inst(pila,create_inst(CMP,node->left->dirRet, node->third->dirRet, aux3));
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(EQ, aux3, NULL, node->dirRet));
            return;
        case NODE_OP_AND:
            addDirRet(node, registro_siguiente());
            armarPila(pila, node->left);
            add_inst(pila,create_inst(MOV,node->dirRet, node->left->dirRet,NULL));
            char* endA = endAnd();
            add_inst(pila,create_inst(JUMPF,node->left->dirRet,create_symb(VOID1, 0, endA),NULL));
            armarPila(pila, node->third);
            add_inst(pila,create_inst(MOV,node->dirRet, node->third->dirRet,NULL));
            add_inst(pila,create_inst(LBL, create_symb(VOID1, 0, endA), NULL, NULL));
            return;
        case NODE_OP_OR:
            addDirRet(node, registro_siguiente());
            armarPila(pila, node->left);
            add_inst(pila,create_inst(MOV,node->dirRet, node->left->dirRet,NULL));
            char* endO = endOr();
            add_inst(pila,create_inst(JUMPT,node->left->dirRet,create_symb(VOID1, 0, endO),NULL));
            armarPila(pila, node->third);
            add_inst(pila,create_inst(MOV,node->dirRet, node->third->dirRet,NULL));
            add_inst(pila,create_inst(LBL, create_symb(VOID1, 0, endO), NULL, NULL));
            return;
        case NODE_OP_NOT:
            armarPila(pila, node->left);
            addDirRet(node, registro_siguiente());
            add_inst(pila,create_inst(XOR,node->left->dirRet, create_symb(BOOL1, 1, NULL), node->dirRet));
            return;
        case NODE_VAL_NUM:
            addDirRet(node, node->info);
            return;
        case NODE_VAL_TRUE:
            addDirRet(node, node->info);
            return;
        case NODE_VAL_FALSE:
            addDirRet(node, node->info);
            return;
        case NODE_ASSIGN:
            armarPila(pila, node->left);
            add_inst(pila,create_inst(MOV,node->info, node->left->dirRet, NULL));
            addDirRet(node, node->info);
            return;
        case NODE_DECLARATION:
            armarPila(pila, node->third);
            return;
        case NODE_MET_DECLARATION:
            add_inst(pila,create_inst(LBL,node->info, NULL, NULL));
            armarPila(pila, node->left);
            param_extrac=1;
            armarPila(pila, node->third);
            return;
        case NODE_MET_CALL:
            int params_cant = cantidadP(node->info->init, node->info->end);
            armarPila(pila, node->left);
            if(params_cant==1){
                add_inst(pila,create_inst(PUSH,node->left->dirRet, NULL, NULL));
            }
            
            addDirRet(node, retFun);
            add_inst(pila,create_inst(JUMP,node->info, NULL, NULL));
            while(params_cant>0){
                add_inst(pila,create_inst(POP,NULL, NULL, NULL));
                params_cant--;
            }
            return;
        case NODE_OP_RETURN:
            armarPila(pila, node->left);
            if(node->left){
                add_inst(pila,create_inst(MOV,retFun, node->left->dirRet, NULL));
            }
            add_inst(pila,create_inst(RET, NULL, NULL, NULL));
            return;
        case NODE_ID:
            addDirRet(node, node->info);
            return;
        case NODE_OP_NEWLINE:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            return;
        case NODE_OP_FUNC:
            armarPila(pila, node->left);
            return;
        case NODE_IF:
            armarPila(pila, node->left);
            char* endIF = endIf();
            add_inst(pila,create_inst(JUMPF,node->left->dirRet,create_symb(VOID1, 0, endIF),NULL));
            armarPila(pila, node->third);
            add_inst(pila,create_inst(LBL, create_symb(VOID1, 0, endIF), NULL, NULL));
            return;
        case NODE_IF_ELSE:
            armarPila(pila, node->left);
            char* endIfEl = endIf();
            char* isElse = idElse();
            add_inst(pila,create_inst(JUMPF,node->left->dirRet,create_symb(VOID1, 0, isElse),NULL));
            armarPila(pila, node->third);
            add_inst(pila,create_inst(JUMP,node->left->dirRet,create_symb(VOID1, 0, endIfEl),NULL));
            add_inst(pila,create_inst(LBL, create_symb(VOID1, 0, isElse), NULL, NULL));
            armarPila(pila, node->right);
            add_inst(pila,create_inst(LBL, create_symb(VOID1, 0, endIfEl), NULL, NULL));
            return;
        case NODE_WHILE:
            char* whileId = idWhile();
            char* whileEnd = endWhile();
            add_inst(pila,create_inst(LBL, create_symb(VOID1, 0, whileId), NULL, NULL));
            armarPila(pila, node->left);
            add_inst(pila,create_inst(JUMPF,node->left->dirRet,create_symb(VOID1, 0, whileEnd),NULL));
            armarPila(pila, node->third);
            add_inst(pila,create_inst(JUMP,node->left->dirRet,create_symb(VOID1, 0, whileId),NULL));
            add_inst(pila,create_inst(LBL, create_symb(VOID1, 0, whileEnd), NULL, NULL));
            return;
        case NODE_PARAM_DECLARATION:
            armarPila(pila, node->left);
            armarPila(pila, node->third);
            return;
        case NODE_PARAM_DECLARATION_PURE:
            add_inst(pila,create_inst(MOV,node->info, pilaTope, create_symb(INT1, param_extrac++, NULL)));
            return;
        case NODE_PARAM_PASS:
            armarPila(pila, node->left);
            if(node->left){
                add_inst(pila,create_inst(PUSH,node->left->dirRet, NULL, NULL));
            }
            if(node->third && node->third->type!=NODE_PARAM_PASS){
                armarPila(pila, node->third);
                add_inst(pila,create_inst(PUSH,node->third->dirRet, NULL, NULL));
                params_can++;
            }else{
                armarPila(pila, node->third);
            }
            params_can++;
            return;
        case NODE_AUX_DEC:
            armarPila(pila, node->left);
            add_inst(pila,create_inst(DEC,node->info, NULL, NULL));
            return;
        case NODE_AUX:
            addDirRet(node, registro_siguiente());
            return;
        default:
            return;
    }
}