#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instruccion.h"
#include "symbol.h"

int isRet(Symbol *actual){
    if(strcmp("RET",actual->name)==0) return 1;
    return 0;
}


int tiene_nombre(Symbol *actual){
    if(!actual->name)return 0;
    if(actual->isFuction) return 1;
    if(strcmp("rdi",actual->name)==0) return 1;
    if(strcmp("rsi",actual->name)==0) return 1;
    if(strcmp("rdx",actual->name)==0) return 1;
    if(strcmp("rcx",actual->name)==0) return 1;
    if(strcmp("r8",actual->name)==0) return 1;
    if(strcmp("r9",actual->name)==0) return 1;
    return 0;
}
int es_memoria(Symbol *s){
    if(!s->name) return 0;
    if(s->isFuction) return 0;
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
    return 0;
}
char* charear(Symbol *actual){
    if (actual == NULL) {
           fprintf(stderr, "Error: charear recibió un Symbol NULL\n");
           exit(EXIT_FAILURE);
       }
    char* result = (char*)malloc(50 * sizeof(char));
    if (actual->name == NULL) {
        sprintf(result, "$%d", actual->value);
    } else {
        if(actual->isFuction){
            sprintf(result, "%s", actual->name);
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

void recursiva2(Instruccion *actual, FILE *f){
    if(actual==NULL) return;
    Instruccion *inst = actual;
    actual = actual->next;
    switch (inst->operador) {
        case LBL: 
            if(inst->val1->isFuction){
                fprintf(f, "  .globl %s\n", charear(inst->val1));
                fprintf(f, "%s:\n", charear(inst->val1));
                if(inst->val1->offset%2==0){
                    fprintf(f, "  enter $%d, $0\n", 8*inst->val1->offset);
                }else{
                    fprintf(f, "  enter $%d, $0\n", 8*(inst->val1->offset+1));
                }
                
            }else{
                fprintf(f, "%s:\n", inst->val1->name);
            }
            recursiva2(actual, f);
            break;
        case MOV: if(inst->val3 != NULL){
                fprintf(f, "  mov %d(%%rbp), %%r11\n", 16*inst->val3->value);
                fprintf(f, "  mov %%r11, %s\n", charear(inst->val1));
            }else{
                if(need_aux(inst->val1, inst->val2)){
                    fprintf(f, "  mov %s, %%r11\n",charear(inst->val2));
                    fprintf(f, "  mov %%r11, %s\n", charear(inst->val1));
                }else if(!inst->val2->name && es_memoria(inst->val1)){
                    fprintf(f, "  movq %s, %s\n", charear(inst->val2), charear(inst->val1));
                }else{
                    fprintf(f, "  mov %s, %s\n", charear(inst->val2), charear(inst->val1));
                }
                
            }
            recursiva2(actual, f);
            break;
        case ADD: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1));
            fprintf(f, "  add %s, %%rax\n", charear(inst->val2));
            fprintf(f, "  mov %%rax, %s\n", charear(inst->val3));
            recursiva2(actual, f);
            break;
        case SUB: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1)); 
            fprintf(f, "  sub %s, %%rax\n", charear(inst->val2));
            fprintf(f, "  mov %%rax, %s\n", charear(inst->val3));
            recursiva2(actual, f);
            break;
        case MUL: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1));
            fprintf(f, "  mov %s, %%r11\n", charear(inst->val2));
            fprintf(f, "  imul %%r11\n");
            fprintf(f, "  mov %%rax, %s\n", charear(inst->val3));
            recursiva2(actual, f);
            break;
        case DIV: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1));
            fprintf(f, "  cqto\n");
            fprintf(f, "  mov %s, %%r11\n", charear(inst->val2));
            fprintf(f, "  idiv %%r11\n");
            fprintf(f, "  mov %%rax, %s\n", charear(inst->val3));
            recursiva2(actual, f);
            break;
        case MOD: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1));
            fprintf(f, "  cqto\n");
            fprintf(f, "  mov %s, %%r11\n", charear(inst->val2));
            fprintf(f, "  idiv %%r11\n");
            fprintf(f, "  mov %%rdx, %s\n", charear(inst->val3));
            recursiva2(actual, f);
            break;
        case GREAT: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1)); 
            fprintf(f, "  mov %s, %%rbx\n", charear(inst->val2));
            fprintf(f, "  cmp %%rbx, %%rax\n");
            fprintf(f, "  mov $1, %%r10\n");
            fprintf(f, "  jg 1f\n");
            fprintf(f, "  xor %%r10, %%r10\n");
            fprintf(f, "1:\n");
            if(inst->val3) fprintf(f, "  mov %%r10, %s\n", charear(inst->val3));
            recursiva2(actual, f);
            break;
        case LESS: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1)); 
            fprintf(f, "  mov %s, %%rbx\n", charear(inst->val2));
            fprintf(f, "  cmp %%rbx, %%rax\n");
            fprintf(f, "  mov $1, %%r10\n");
            fprintf(f, "  jl 1f\n");
            fprintf(f, "  mov $0, %%r10\n");
            fprintf(f, "1:\n");
            if(inst->val3) fprintf(f, "  mov %%r10, %s\n", charear(inst->val3));
            recursiva2(actual, f);
            break;
        case EQ: fprintf(f, "  mov %s, %%rax\n", charear(inst->val1)); 
            fprintf(f, "  mov %s, %%rbx\n", charear(inst->val2));
            fprintf(f, "  cmp %%rbx, %%rax\n");
            fprintf(f, "  mov $1, %%r10\n");
            fprintf(f, "  je 1f\n");
            fprintf(f, "  mov $0, %%r10\n");
            fprintf(f, "1:\n");
            if(inst->val3) fprintf(f, "  mov %%r10, %s\n", charear(inst->val3));
            recursiva2(actual, f);
            break;
        case JUMPF: fprintf(f, "  mov %s, %%r10\n", charear(inst->val1));
            fprintf(f, "  cmp $1, %%r10\n");
            fprintf(f, "  jne %s\n", inst->val2->name);
            recursiva2(actual, f);
            break;
        case JUMPT: fprintf(f, "  mov %s, %%r10\n", charear(inst->val1));
            fprintf(f, "  cmp $1, %%r10\n");
            fprintf(f, "  je %s\n", inst->val2->name);
            recursiva2(actual, f);
            break;
        case JUMP:fprintf(f, "  jmp %s\n", inst->val1->name);
            recursiva2(actual, f);
            break;
        case XOR:fprintf(f, "  mov %s, %%r10\n", charear(inst->val1));
            fprintf(f, "  xor %s, %%r10\n", charear(inst->val2));
            if(inst->val3) fprintf(f, "  mov %%r10, %s\n", charear(inst->val3));
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
        default: fputs("vofjbgjosg",f);recursiva2(actual, f); break;
    }
}


void stack_to_asm(Pila *pila, char *file_name){
    if (pila == NULL) {
        fprintf(stderr, "Error: la pila es NULL\n");
        return;
    }
    FILE *archivo;
    
    // 2. Abrir/crear el archivo en modo escritura ("w")
    archivo = fopen(file_name, "w");

    // 3. Verificar si el archivo se creó correctamente
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return ;
    }
    
    fprintf(archivo, "\t.text\n");
    recursiva2(pila->top, archivo);
    fprintf(archivo, "\t.section .note.GNU-stack,\"\",@progbits\n");
    fclose(archivo);
}