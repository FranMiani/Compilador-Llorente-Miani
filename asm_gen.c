#include <stdio.h>
#include <stdlib.h>
#include "instruccion.h"
#include "symbol.h"

char* charear(Symbol *actual){
    if (actual == NULL) {
           fprintf(stderr, "Error: charear recibió un Symbol NULL\n");
           exit(EXIT_FAILURE);
       }
    char* result = (char*)malloc(50 * sizeof(char));
    if (actual->name == NULL) {
        sprintf(result, "$%d", actual->value);
    } else {
        sprintf(result, "%s", actual->name);
    }
    return result;
}

void recursiva2(Instruccion *actual, FILE *f){
    if(actual==NULL) return;
    Instruccion *inst = actual;
    actual = actual->next;
    switch (inst->operador) {
        case LBL: fprintf(f, "%s:\n", charear(inst->val1));
            recursiva2(actual, f);
            break;
        case MOV: if(inst->val3 != NULL){
                fprintf(f, "  mov %s, [ebp-%d]\n", charear(inst->val1), inst->val3->value);
            }else{
                fprintf(f, "  mov %s, %s\n", charear(inst->val1), charear(inst->val2));
            }
            recursiva2(actual, f);
            break;
        case ADD: fprintf(f, "  add %s, %s\n", charear(inst->val1), charear(inst->val2));
            recursiva2(actual, f);
            break;
        case SUB: fprintf(f, "  sub %s, %s\n", charear(inst->val1), charear(inst->val2));
            recursiva2(actual, f);
            break;
        case MUL: fprintf(f, "  mul %s, %s\n", charear(inst->val1), charear(inst->val2));
            recursiva2(actual, f);
            break;
        case DIV: fprintf(f, "  mov rax, %s\n", charear(inst->val1));
            fprintf(f, "  div %s\n", charear(inst->val2));
            fprintf(f, "  mov %s, rax\n", charear(inst->val1));
            recursiva2(actual, f);
            break;
        case MOD: fprintf(f, "  mov rax, %s\n", charear(inst->val1));
            fprintf(f, "  div %s\n", charear(inst->val2));
            fprintf(f, "  mov %s, rdx\n", charear(inst->val1));
            recursiva2(actual, f);
            break;
        case GREAT: fprintf(f, "  mov rax, %s\n", charear(inst->val1)); 
            fprintf(f, "  mov rbx, %s\n", charear(inst->val2));
            fprintf(f, "  cmp rax, rbx\n");
            fprintf(f, "  mov r10, $1\n");
            fprintf(f, "  jg @F\n");
            fprintf(f, "  mov r10, $0\n");
            fprintf(f, "  @@:\n");
            recursiva2(actual, f);
            break;
        case LESS: fprintf(f, "  mov rax, %s\n", charear(inst->val1)); 
            fprintf(f, "  mov rbx, %s\n", charear(inst->val2));
            fprintf(f, "  cmp rax, rbx\n");
            fprintf(f, "  mov r10, $1\n");
            fprintf(f, "  jl @F\n");
            fprintf(f, "  mov r10, $0\n");
            fprintf(f, "  @@:\n");
            recursiva2(actual, f);
            break;
        case EQ: fprintf(f, "  mov rax, %s\n", charear(inst->val1)); 
            fprintf(f, "  mov rbx, %s\n", charear(inst->val2));
            fprintf(f, "  cmp rax, rbx\n");
            fprintf(f, "  mov r10, $1\n");
            fprintf(f, "  je @F\n");
            fprintf(f, "  mov r10, $0\n");
            fprintf(f, "  @@:\n");
            recursiva2(actual, f);
            break;
        case JUMPF: fprintf(f, "  cmp r10, $1\n");
            fprintf(f, "  jne %s\n", charear(inst->val2));
            recursiva2(actual, f);
            break;
        case JUMPT: fprintf(f, "  cmp r10, $1\n");
            fprintf(f, "  je %s\n", charear(inst->val2));
            recursiva2(actual, f);
            break;
        case JUMP:fprintf(f, "  jmp %s\n", charear(inst->val1));
            recursiva2(actual, f);
            break;
        case XOR:fprintf(f, "  xor r10, $1\n");
            recursiva2(actual, f);
            break;
        case DEC:fprintf(f, "  aqui codigo que reserva memoria\n");
            recursiva2(actual, f);
            break;
        case POP:fprintf(f, "  pop _\n");
            recursiva2(actual, f);
            break;
        case PUSH:fprintf(f, "  push %s\n", charear(inst->val1));
            recursiva2(actual, f);
            break;
        case RET:fprintf(f, "  ret \n");
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
    
    recursiva2(pila->top,archivo);
    fclose(archivo);
}