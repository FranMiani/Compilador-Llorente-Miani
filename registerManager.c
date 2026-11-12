#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "instruccion.h"
#include "symbol_table.h"
#include "symbol.h"

#define LEN 4
typedef enum {
    R12,
    R13,
    R1LEN,
    R15
}registrosLibres;
int block=0;
Symbol* regs[LEN];
Symbol* contraparte[LEN];
int cantTempsToAp[LEN];
int cantAparicionesRestantes[LEN];
void blockear(){
    block+=1;
}
void desblockear(){
    block-=1;
}
char* regName2(int i){
    switch (i) {
        case R12:
            return "r12";
        case R13:
            return "r13";
        case R1LEN:
            return "r14";
        case R15:
            return "r15";
    }
}
void inicializarRegs(){
    for (int i=0; i<LEN; i++) {
        regs[i] = NULL;
        contraparte[i] = create_symb(NOT_TYPE, 0, regName2(i));
        cantTempsToAp[i]=0;
        cantAparicionesRestantes[i]=0;

    }
}




int searchReg(Symbol *symbol){
    for (int i=0; i<LEN; i++) {
        if(regs[i]==symbol){
            return i;
        }
    }
    return -1;
}
void aparicionDeTemporal(){
    for (int i=0; i<LEN; i++) {
        if(cantTempsToAp[i]!=0){
            cantTempsToAp[i]-=1;
        }
    }
}
void liberarTemp(Symbol* sym){
    if(block)return;
    int aux = searchReg(sym);
    if(aux!=-1){
        regs[aux]=NULL;
        cantAparicionesRestantes[aux]=0;
        cantTempsToAp[aux]=0;
    }
}
void useVar(Symbol* symbol){
    int aux = searchReg(symbol);
    if(aux!=-1){
        cantAparicionesRestantes[aux]-=1;
    }
    if(cantAparicionesRestantes==0){
        regs[aux]=NULL;
        cantAparicionesRestantes[aux]=0;
        cantTempsToAp[aux]=0;

    }
}
Symbol* use(Symbol* symbol){
    int aux = searchReg(symbol);
    if(symbol->isFuction==3){
        liberarTemp(symbol);
        aparicionDeTemporal();
    }else{
        useVar(symbol);
    }
    if(aux!=-1){
        return contraparte[aux];
    }
    return symbol;

}
void liberarForzoso(Pila* pila, Symbol* symbol){
    int aux = searchReg(symbol);
    add_inst(pila,create_inst(MOV,contraparte[aux],regs[aux],NULL));
}
void liberarTodo(Pila* pila){
    if(block)return;
    for (int i=0; i<LEN; i++) {
        if(regs[i]!=NULL){
            add_inst(pila,create_inst(MOV,contraparte[i],regs[i],NULL));
        }
    }
}
Symbol* buscarRegistro(Symbol *symbol){
    for (int i=0; i<LEN; i++) {
        if(regs[i]==symbol){
            return contraparte[i];
        }
    }
    return symbol;
}
int contarAp(Symbol* symbol, Node* node){
    if(!node) return 0;
    int aux = contarAp(symbol, node->left) +
    contarAp(symbol, node->right) +
    contarAp(symbol, node->third);
    if(node->info == symbol){
        aux++;
    }
    return aux;
}
void contarApAux(Node* node, int i){
    if(!node) return;
    if(node->info == regs[i]){
        cantAparicionesRestantes[i]+=1;
    }
    contarApAux(node->left, i);
    contarApAux(node->right, i);
    contarApAux(node->third, i);
}
void contarAparicionesRestantes(Node* node, Symbol* symbol){
    if(!node) return;
    int aux = searchReg(symbol);
    if(aux!=-1) return;
    cantAparicionesRestantes[aux] = contarAp(symbol, node)-1;
}
int contarTemps(Node* node, Symbol* symbol){
    if(!node) return 0;
    if(node->info == symbol) return -1;
    int aux=0;
    int left = contarTemps(node->left, symbol);
    if(left!=-1){
        int third = contarTemps(node->third, symbol);
        aux+=left;
        if(third!=-1){
            int right = contarTemps(node->right, symbol);
            aux+=third;
            if(right!=-1){
                aux+=right;
            }
        }
    }
    if(node->dirRet != NULL){
        aux++;
    }
    return aux;
}
int contarTempAux(Node* node, int i){
    if(!node) return -1;
    if(node->dirRet != NULL){
        cantTempsToAp[i]+=1;
    }
    if(node->info == regs[i]) return 0;
    if(contarTempAux(node->left, i)==-1){
        if(contarTempAux(node->right, i)==-1){
            return contarTempAux(node->third, i);
        }
    }
    return 0;
}
void contarTemporales(Node* node, Symbol* symbol){
    if(!node) return;
    int aux = searchReg(symbol);
    if(aux!=-1) return;
    cantTempsToAp[aux]=0;
    contarTempAux(node, aux);
}

void aparicionDeVar(Symbol* symbol){
    int aux = searchReg(symbol);
    if(aux!=-1){
        cantAparicionesRestantes[aux]-=1;
    }
}
void aparicion(Symbol* symbol){
    if(symbol->isFuction==0 || symbol->isFuction==2){
        aparicionDeVar(symbol);
    }
    if(symbol->isFuction==3){
        aparicionDeTemporal();
    }
}
int liberarRegistroTo(Pila* pila, Symbol* sym, Node* node){
    int type = sym->isFuction;
    Symbol* reg;
    Symbol* memo;
    int select=-1;
    int min=9999999;
    if(type==0 || type==2){
        int apariciones = contarAp(sym, node);
        if(apariciones<2)return -1;
        for (int i=0; i<LEN; i++) {
            if(regs[i]->isFuction==3){
                select = i;
                break;
            }else{
                if(cantAparicionesRestantes[i]<apariciones-1 && cantAparicionesRestantes[i]<min){
                    select=i;
                    min = cantAparicionesRestantes[i];
                }
            }
        }
    }else{
        min = -1;
        for (int i=0; i<LEN; i++) {
            if(regs[i]->isFuction!=3 && cantAparicionesRestantes[i]==0){
                select = i;
                break;
            }else{
                if(regs[i]->isFuction!=3){
                    if(cantTempsToAp[i]>min){
                        select=i;
                        min = cantAparicionesRestantes[i];
                    }
                }
            }
        }
    }
    if(select==-1)return select;
    memo = regs[select];
    reg = contraparte[select];
    add_inst(pila,create_inst(MOV,reg, memo,NULL));
    return select;
}
Symbol* registrar(Symbol* symbol, Pila* pila, Node* node){
    for (int i=0; i<LEN; i++) {
        if(regs[i]==NULL){
            regs[i]=symbol;
            return contraparte[i];
        }
    }
    if(block) return symbol;
    int aux = liberarRegistroTo(pila, symbol, node);
    if(aux==-1) return symbol;
    regs[aux]=symbol;
    return contraparte[aux];
}


void copy(Symbol* origen[LEN], Symbol* destino[LEN]){
    Symbol* copia[LEN];
    for(int i=0;i<LEN;i++){
        destino[i]=origen[i];
    }
}
void copiarFrom(Symbol* origen[LEN]){
    if(block) return;
    copy(origen, regs);
}
void copiarTo(Symbol* destino[LEN]){
    if(block) return;
    copy(regs,destino);
}
void recuperar(Symbol* origen[LEN], Pila* pila){
    if(block) return;
    for (int i=0; i<LEN; i++) {
        if(origen[i]!=NULL){
            add_inst(pila,create_inst(MOV,origen[i],contraparte[i],NULL));
        }
    }

}
void corregir(Symbol* aux[LEN]){
    if(block) return;
    for (int i=0; i<LEN; i++) {
        if(regs[i]!=aux[i]){
            regs[i]=NULL;
            cantTempsToAp[i]=0;
            cantAparicionesRestantes[i]=0;
        }
    }
}
