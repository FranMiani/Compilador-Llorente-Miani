#include <stdio.h>
#include <stdlib.h>
#include "instruccion.h"



void recursiva2(Instruccion *actual, FILE *f);
void stack_to_asm(Pila *pila, char *file_name);