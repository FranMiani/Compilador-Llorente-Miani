#include <stdio.h>
#include <stdlib.h>
#include "instruccion.h"

void stack_to_asm(Pila pila, char *file_name){
    FILE *archivo;

    // 2. Abrir/crear el archivo en modo escritura ("w")
    archivo = fopen(file_name, "w");

    // 3. Verificar si el archivo se creó correctamente
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }
}