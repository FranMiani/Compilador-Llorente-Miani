#include <stdio.h>
#include <libgen.h>
#include "parser.tab.h"
#include "symbol_table.h"
#include "ast.h"
#include "instruccion.h"
#include "asm_gen.h"
extern FILE *yyin;
void yyerror(const char *s);
extern int yylex(void);
extern SymbolTable *tabla;
extern Node *father;

int main(int argc, char *argv[]) {

    setvbuf(stdout, NULL, _IONBF, 0);

    tabla = init_table();

    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo_a_compilar>\n", basename(argv[0]));
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Error: No se pudo abrir el archivo '%s'\n", argv[1]);
        return 1;
    }

    yyparse();
    fclose(yyin);
    print_table(tabla);
    print_ast(father, 0);
    initReg();
    Pila *pila2 = crear_pila();
    armarPila(pila2, father);
    print_pila(pila2);

    stack_to_asm(pila2,"prueba.s");
    

    return 0;
}
