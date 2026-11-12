#include "ast.h"
#include "instruccion.h"
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
                node->info->value = node->left->info->value / node->third->info->value;
                node->type = NODE_VAL_NUM;
            }
            return;
        case NODE_OP_MOD:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if(node->left->type == NODE_VAL_NUM && node->third->type == NODE_VAL_NUM){
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
            if((node->left->type == NODE_VAL_TRUE || node->left->type == NODE_VAL_FALSE)
                &&
                (node->third->type == NODE_VAL_TRUE || node->third->type == NODE_VAL_FALSE)){
                if(node->left->info->value ==0 || node->third->info->value==0){
                    node->info->value = 0;
                    node->type = NODE_VAL_FALSE;
                }else{
                    node->info->value = 1;
                    node->type = NODE_VAL_TRUE;
                }
            }
            return;
        case NODE_OP_OR:
            optimizarCalculosLiterales(node->left);
            optimizarCalculosLiterales(node->third);
            if((node->left->type == NODE_VAL_TRUE || node->left->type == NODE_VAL_FALSE)
                &&
                (node->third->type == NODE_VAL_TRUE || node->third->type == NODE_VAL_FALSE)){
                if(node->left->info->value ==1 || node->third->info->value==1){
                    node->info->value = 1;
                    node->type = NODE_VAL_TRUE;
                }else{
                    node->info->value = 0;
                    node->type = NODE_VAL_FALSE;
                }
            }
            return;
        case NODE_OP_NOT:
            optimizarCalculosLiterales(node->left);
            if(node->left->type == NODE_VAL_FALSE){
                node->info->value = 1;
                node->type = NODE_VAL_TRUE;
            }else{
                node->info->value = 0;
                node->type = NODE_VAL_FALSE;
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
                        node->left=node->left->right;
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
    optimizarCaminos(node->right);


}




//No voy a mentir, lo que se viene ahora lo hizo la ia
#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCK_DEPTH 128
// Macro de bitwise para redondear hacia arriba al múltiplo de 16 más cercano
#define ALIGN_16(x) (((x) + 15) & ~15)

void optimizar_y_alinear_memoria(Pila *pila) {
    if (!pila || !pila->top) return;

    Instruccion *actual = pila->top;

    // Control de bloques anidados
    Instruccion *stack_bloques[MAX_BLOCK_DEPTH];
    int stack_base_offset[MAX_BLOCK_DEPTH]; // Offset base al entrar al bloque
    int stack_max_offset[MAX_BLOCK_DEPTH];  // Pico máximo de memoria dentro del bloque
    int stack_vars_count[MAX_BLOCK_DEPTH];  // Para liberar variables del scope al salir
    int tope_bloque = -1;

    // Control de funciones (LBL)
    Instruccion *funcion_actual = NULL;
    int max_offset_funcion = 0;

    // Puntero dinámico de memoria para empaquetar variables (eliminar huecos)
    int offset_actual = 0;
    Symbol* variables_procesadas[1024];
    int cantidad_vars = 0;

    while (actual != NULL) {
        // 1. Manejo de LBL (Inicio de Función)
        if (actual->operador == LBL && actual->val1 != NULL && actual->val1->isFuction) {
            // Alinear y cerrar la función anterior si existía
            if (funcion_actual != NULL && funcion_actual->val1 != NULL) {
                funcion_actual->val1->offset = ALIGN_16(max_offset_funcion);
            }
            // Reiniciar contadores para la nueva función
            funcion_actual = actual;
            max_offset_funcion = 0;
            offset_actual = 0;
            cantidad_vars = 0;
        }
        // 2. Manejo de inicio de BLOCK
        else if (actual->operador == BLOCK) {
            tope_bloque++;
            if (tope_bloque < MAX_BLOCK_DEPTH) {
                stack_bloques[tope_bloque] = actual;
                stack_base_offset[tope_bloque] = offset_actual;
                stack_max_offset[tope_bloque] = offset_actual;
                stack_vars_count[tope_bloque] = cantidad_vars; // Guardamos cuántas vars existen
            }
        }
        // 3. Manejo de fin de BLOCK
        else if (actual->operador == ENDBLOCK) {
            if (tope_bloque >= 0) {
                Instruccion *bloque = stack_bloques[tope_bloque];
                int max_alcanzado = stack_max_offset[tope_bloque];

                // Guardamos el tamaño del bloque alineado en su val1->offset
                if (bloque->val1 != NULL) {
                    bloque->val1->offset = ALIGN_16(max_alcanzado);
                }

                // Propagar el pico de memoria al bloque padre si existe
                if (tope_bloque > 0 && max_alcanzado > stack_max_offset[tope_bloque - 1]) {
                    stack_max_offset[tope_bloque - 1] = max_alcanzado;
                }

                // LIBERAR MEMORIA: Restablecemos el offset y la lista de variables
                // para que los bloques paralelos (ej. if y else) reutilicen el mismo espacio.
                offset_actual = stack_base_offset[tope_bloque];
                cantidad_vars = stack_vars_count[tope_bloque];

                tope_bloque--;
            }
        }
        // 4. Reasignación de memoria compacta para variables
        else {
            Symbol* vars[] = {actual->val1, actual->val2, actual->val3};
            for (int i = 0; i < 3; i++) {
                Symbol *sym = vars[i];

                // Si el offset > 0, significa que la variable va a memoria (no es registro 0)
                if (sym != NULL && sym->offset > 0) {

                    // Verificar si ya le asignamos un nuevo offset empaquetado
                    int ya_procesado = 0;
                    for (int j = 0; j < cantidad_vars; j++) {
                        if (variables_procesadas[j] == sym) {
                            ya_procesado = 1;
                            break;
                        }
                    }

                    // Si es la primera vez que la vemos en memoria, compactamos
                    if (!ya_procesado) {
                        variables_procesadas[cantidad_vars++] = sym;

                        // Asignar bloque de memoria contiguo (ej. saltos de 8 bytes para punteros/64bits)
                        // NOTA: Cambia este 8 por una función get_size(sym->exprType) si manejas 4 bytes para int, etc.
                        offset_actual += 8;
                        sym->offset = offset_actual;

                        // Actualizar los picos máximos detectados
                        if (tope_bloque >= 0 && offset_actual > stack_max_offset[tope_bloque]) {
                            stack_max_offset[tope_bloque] = offset_actual;
                        }
                        if (offset_actual > max_offset_funcion) {
                            max_offset_funcion = offset_actual;
                        }
                    }
                }
            }
        }
        actual = actual->next;
    }

    // Alinear el frame de la última función procesada
    if (funcion_actual != NULL && funcion_actual->val1 != NULL) {
        funcion_actual->val1->offset = ALIGN_16(max_offset_funcion);
    }
}
