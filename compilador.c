#include <stdio.h>
#include <libgen.h>
#include "parser.tab.h"

extern FILE *yyin;
void yyerror(const char *s);
extern int yylex(void);

int main(int argc, char *argv[]) {
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
    
    return 0;
}