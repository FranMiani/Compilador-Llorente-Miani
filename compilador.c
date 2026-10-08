#include <stdio.h>
#include <libgen.h>
#include "parser.tab.h"
#include "symbol_table.h"
#include "ast.h"
#include "instruccion.h"

extern FILE *yyin;
void yyerror(const char *s);
extern int yylex(void);
extern SymbolTable *tabla;
extern Node *father;
extern Pila *pila;

int main(int argc, char *argv[]) {
    pila = crear_pila();
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
    print_pila(pila);


    return 0;
}
