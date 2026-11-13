#include <stdio.h>

/* Funciones externas disponibles para los programas de tests_e2e. */

void print(int x) {
    printf("%d", x);
}

void println(int x) {
    printf("%d\n", x);
}

int getInt(void) {
    int x = 0;
    if (scanf("%d", &x) != 1) {
        return 0;
    }
    return x;
}
