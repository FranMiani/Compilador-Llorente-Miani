#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instruccion.h"
#include "symbol.h"
#include "symbol_table.h"
#include "ast.h"

extern Symbol *lastSymbol;
Symbol* boolReg;
int isRet(Symbol *actual){
    if(strcmp("RET",actual->name)==0) return 1;
    return 0;
}






int tiene_nombre(Symbol *actual){
    if(!actual->name)return 0;
    if(actual->isFuction==1) return 1;
    if(strcmp("rdi",actual->name)==0) return 1;
    if(strcmp("rsi",actual->name)==0) return 1;
    if(strcmp("rdx",actual->name)==0) return 1;
    if(strcmp("rcx",actual->name)==0) return 1;
    if(strcmp("r8",actual->name)==0) return 1;
    if(strcmp("r9",actual->name)==0) return 1;
    if(strcmp("r10",actual->name)==0) return 1;
    if(strcmp("r12",actual->name)==0) return 1;
    if(strcmp("r13",actual->name)==0) return 1;
    if(strcmp("r14",actual->name)==0) return 1;
    if(strcmp("r15",actual->name)==0) return 1;
    return 0;
}
int es_memoria(Symbol *s){
    if(!s->name) return 0;
    if(s->isFuction==1) return 0;
    if(isRet(s)) return 0;
    if(tiene_nombre(s)) return 0;
    return 1;
}
int need_aux(Symbol *s1, Symbol *s2){
    if(s1->name && s2->name){
        if(isRet(s2)==0 && isRet(s1)==0){
            if(tiene_nombre(s1)==0 && tiene_nombre(s2)==0)return 1;
        }
    }
    if(es_memoria(s1) && es_memoria(s2)) return 1;
    if(es_memoria(s2)&& !s1->name)return 1;
    if(es_memoria(s1)&& !s2->name)return 1;
    return 0;
}
char* charear(Symbol *actual){
    char* result = (char*)malloc(25 * sizeof(char));
    if (actual == NULL) {
           fprintf(stderr, "Error: charear recibió un Symbol NULL\n");
           sprintf(result, " ");
           return result;
       }
    if (actual->name == NULL) {
        sprintf(result, "$%d", actual->value);
    } else {
        if(actual->isFuction){
            if(actual->isFuction==1){
                sprintf(result, "%s", actual->name);
            }else{
                if(actual->isFuction==3){
                    sprintf(result, "-%d(%s)", actual->offset, "%rbp");
                }else{
                    sprintf(result, "%s(%%rip)", actual->name);
                }
            }

        }else if(strcmp("RET",actual->name)==0){
            sprintf(result, "%%rax");
        }else if(tiene_nombre(actual)==1){
            sprintf(result, "%%%s", actual->name);
        }else{
            sprintf(result, "-%d(%s)", actual->offset, "%rbp");
        }

    }
    return result;
}

void emitir_op(FILE *f, const char *op, Symbol *origen, Symbol *destino) {
    char *strOri = charear(origen);
    char *strDes = charear(destino);

    if (es_memoria(origen) && es_memoria(destino)) {
        fprintf(f, "  mov %s, %%r11\n", strOri);
        fprintf(f, "  %s %%r11, %s\n", op, strDes);
    } else {
        fprintf(f, "  %s %s, %s\n", op, strOri, strDes);
    }

    free(strOri);
    free(strDes);
}

void recursiva2(Instruccion *actual, FILE *f){
    if(actual==NULL) return;
    Instruccion *inst = actual;
    actual = actual->next;
    char* registroEnUso1 = (char*)malloc(10 * sizeof(char));
    char* registroEnUso2 = (char*)malloc(10 * sizeof(char));
    char* registroEnUso3 = (char*)malloc(10 * sizeof(char));
    char *v1 = charear(inst->val1);
    char *v2 = charear(inst->val2);
    char *v3 = charear(inst->val3);
    int aux=-1;
    int aux2=-1;
    switch (inst->operador) {
        case LBL:
            if(inst->val1->isFuction){
                fprintf(f, "  .globl %s\n", charear(inst->val1));
                fprintf(f, "%s:\n", charear(inst->val1));
                if(inst->val1->offset%2==0){
                    fprintf(f, "  enter $%d, $0\n", inst->val1->offset);
                }else{
                    fprintf(f, "  enter $%d, $0\n", (inst->val1->offset+1));
                }

            }else{
                fprintf(f, "%s:\n", inst->val1->name);
            }
            recursiva2(actual, f);
            break;
        case MOV: if(inst->val3 != NULL){
                fprintf(f, "  mov %d(%%rbp), %%r11\n", 16*inst->val3->value);
                fprintf(f, "  mov %%r11, %s\n", charear(inst->val1));
            }else if (inst->val1 != inst->val2) {
                emitir_op(f, "mov", inst->val2, inst->val1);
            }
            recursiva2(actual, f);
            break;
        case ADD:
            // Caso 1: Destino (val3) ya tiene a val1 (ej. c = c + b)
            if (inst->val3 == inst->val1) {
                emitir_op(f, "add", inst->val2, inst->val3);
            }
            // Caso 2: Destino ya tiene a val2 (ej. c = a + c)
            else if (inst->val3 == inst->val2) {
                emitir_op(f, "add", inst->val1, inst->val3);
            }
            // Caso 3: Destino es nuevo (ej. c = a + b)
            else {
                // Movemos primero el que NO es literal constante al destino
                if (inst->val1->name == NULL) {
                    emitir_op(f, "mov", inst->val2, inst->val3);
                    emitir_op(f, "add", inst->val1, inst->val3);
                } else {
                    emitir_op(f, "mov", inst->val1, inst->val3);
                    emitir_op(f, "add", inst->val2, inst->val3);
                }
            }
            recursiva2(actual, f);
            break;
        case SUB:
            if (inst->val3 != inst->val1) {
                emitir_op(f, "mov", inst->val1, inst->val3);
            }
            emitir_op(f, "sub", inst->val2, inst->val3);
            recursiva2(actual, f);
            break;
        case MUL:
            Symbol *op1 = inst->val1;
            Symbol *op2 = inst->val2;
            v1 = charear(op1);
            v2 = charear(op2);
            v3 = charear(inst->val3);

            // OPTIMIZACIÓN CONMUTATIVA:
            // Si op2 es una constante (y op1 no lo es) .
            if ((op2->name == NULL && op1->name != NULL)) {
                // Intercambiamos los punteros de los símbolos
                Symbol *temp_op = op1;
                op1 = op2;
                op2 = temp_op;

                // Intercambiamos los strings generados
                char *temp_v = v1;
                v1 = v2;
                v2 = temp_v;
            }

            // 1. Movemos el primer factor a %rax
            fprintf(f, "  mov %s, %%rax\n", v1);

            // 2. Multiplicamos por el segundo factor.
            if (op2->name == NULL) {
                fprintf(f, "  mov %s, %%r11\n", v2);
                fprintf(f, "  imul %%r11\n");
            } else {
                fprintf(f, "  imul %s\n", v2);
            }

            // 3. El resultado queda en %rax. Lo guardamos en su destino final.
            fprintf(f, "  mov %%rax, %s\n", v3);

            free(v1); free(v2); free(v3);
            recursiva2(actual, f);
            break;
        case DIV:
            v1 = charear(inst->val1);
            v2 = charear(inst->val2);
            v3 = charear(inst->val3);

            // 1. Dividendo siempre a %rax
            fprintf(f, "  mov %s, %%rax\n", v1);

            // 2. Extender el signo de %rax hacia %rdx (Obligatorio para idiv en x86-64)
            fprintf(f, "  cqto\n");

            // 3. idiv no acepta literales, verificamos si es constante
            if (inst->val2->name == NULL) {
                fprintf(f, "  mov %s, %%r11\n", v2);
                fprintf(f, "  idiv %%r11\n");
            } else {
                fprintf(f, "  idiv %s\n", v2); // Registro o memoria directo
            }

            if (strcmp(v3, "%rax") != 0) {
                fprintf(f, "  mov %%rax, %s\n", v3);
            }
            free(v1); free(v2); free(v3);
            recursiva2(actual, f);
            break;
        case MOD:
            v1 = charear(inst->val1);
            v2 = charear(inst->val2);
            v3 = charear(inst->val3);

            // 1. Dividendo siempre a %rax
            if (strcmp(v1, "%rax") != 0) {
                fprintf(f, "  mov %s, %%rax\n", v1);
            }

            // 2. Extender el signo de %rax hacia %rdx (Obligatorio para idiv en x86-64)
            fprintf(f, "  cqto\n");

            // 3. idiv tampoco acepta literales, verificamos si es constante
            if (inst->val2->name == NULL) {
                fprintf(f, "  mov %s, %%r11\n", v2);
                fprintf(f, "  idiv %%r11\n");
            } else {
                fprintf(f, "  idiv %s\n", v2); // Registro o memoria directo
            }
            if (strcmp(v3, "%rdx") != 0) {
                fprintf(f, "  mov %%rdx, %s\n", v3);
            }
            free(v1); free(v2); free(v3);
            recursiva2(actual, f);
            break;
        case GREAT: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1));
            fprintf(f, "  mov %s, %%rbx\n", charear(inst->val2));
            fprintf(f, "  cmp %%rbx, %%rax\n");
            fprintf(f, "  mov $1, %%r10\n");
            fprintf(f, "  jg 1f\n");
            fprintf(f, "  xor %%r10, %%r10\n");
            fprintf(f, "1:\n");

            if(inst->val3){
                if(boolReg==inst->val3){
                    recursiva2(actual, f);
                    break;
                }
                fprintf(f, "  mov %%r10, %s\n", charear(inst->val3));
            }
            recursiva2(actual, f);
            break;
        case LESS: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1));
            fprintf(f, "  mov %s, %%rbx\n", charear(inst->val2));
            fprintf(f, "  cmp %%rbx, %%rax\n");
            fprintf(f, "  mov $1, %%r10\n");
            fprintf(f, "  jl 1f\n");
            fprintf(f, "  xor %%r10, %%r10\n");
            fprintf(f, "1:\n");
            if(inst->val3){
                if(boolReg==inst->val3){
                    recursiva2(actual, f);
                    break;
                }
                fprintf(f, "  mov %%r10, %s\n", charear(inst->val3));
            }recursiva2(actual, f);
            break;
        case EQ: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1));
            fprintf(f, "  mov %s, %%rbx\n", charear(inst->val2));
            fprintf(f, "  cmp %%rbx, %%rax\n");
            fprintf(f, "  mov $1, %%r10\n");
            fprintf(f, "  je 1f\n");
            fprintf(f, "  xor %%r10, %%r10\n");
            fprintf(f, "1:\n");
            if(inst->val3){
                if(boolReg==inst->val3){
                    recursiva2(actual, f);
                    break;
                }
                fprintf(f, "  mov %%r10, %s\n", charear(inst->val3));
            }
            recursiva2(actual, f);
            break;
        case JUMPF:
            if(inst->val1!=boolReg){
                fprintf(f, "  mov %s, %%r10\n", charear(inst->val1));
            }
            fprintf(f, "  cmp $1, %%r10\n");
            fprintf(f, "  jne %s\n", inst->val2->name);
            recursiva2(actual, f);
            break;
        case JUMPT:
            if(inst->val1!=boolReg){
                fprintf(f, "  mov %s, %%r10\n", charear(inst->val1));
            }
            fprintf(f, "  cmp $1, %%r10\n");
            fprintf(f, "  je %s\n", inst->val2->name);
            recursiva2(actual, f);
            break;
        case JUMP:fprintf(f, "  jmp %s\n", inst->val1->name);
            recursiva2(actual, f);
            break;
        case XOR:
            if(inst->val1!=boolReg){
                fprintf(f, "  mov %s, %%r10\n", charear(inst->val1));
            }
            fprintf(f, "  xor %s, %%r10\n", charear(inst->val2));
            if(inst->val3 && inst->val3!=boolReg){
                fprintf(f, "  mov %%r10, %s\n", charear(inst->val3));
            }
            recursiva2(actual, f);
            break;
        case DEC:
            recursiva2(actual, f);
            break;
        case POP:fprintf(f, "  add $8, %%rsp\n");
            recursiva2(actual, f);
            break;
        case PUSH:fprintf(f, "  push %s\n", charear(inst->val1));
            recursiva2(actual, f);
            break;
        case RET:fprintf(f, "  leave\n");
            fprintf(f, "  ret\n");

            recursiva2(actual, f);
            break;
        case CALL:fprintf(f, "  call %s\n", inst->val1->name);
            recursiva2(actual, f);
            break;
        case LBLE:
            recursiva2(actual, f);
            break;
        case BLOCK:
            recursiva2(actual, f);
            break;
        case ENDBLOCK:
            recursiva2(actual, f);
            break;
        default: fputs("vofjbgjosg",f);recursiva2(actual, f); break;
    }
}


void stack_to_asm(Pila *pila, char *file_name){
    if (pila == NULL) {
        fprintf(stderr, "Error: la pila es NULL\n");
        return;
    }
    FILE *archivo;
    boolReg = booleano();

    // 2. Abrir/crear el archivo en modo escritura ("w")
    archivo = fopen(file_name, "w");

    // 3. Verificar si el archivo se creó correctamente
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return ;
    }

    fprintf(archivo, "  .bss\n");
    Symbol *aux = lastSymbol;
    while(lastSymbol) {
        if(lastSymbol->isFuction==2){
            fprintf(archivo, "  .globl %s\n", lastSymbol->name);
            lastSymbol->offset=0;
        }
        lastSymbol=lastSymbol->next;
    }
    lastSymbol = aux;
    while(lastSymbol) {
        if(lastSymbol->isFuction==2){
            fprintf(archivo, "%s:\n", lastSymbol->name);
            fprintf(archivo, "  .space 8\n");
        }
        lastSymbol=lastSymbol->next;
    }
    fprintf(archivo, "\t.text\n");


    recursiva2(pila->top, archivo);
    //leave de emergencia
    fprintf(archivo, "  leave\n");
    fprintf(archivo, "\t.section .note.GNU-stack,\"\",@progbits\n");
    fclose(archivo);
}
