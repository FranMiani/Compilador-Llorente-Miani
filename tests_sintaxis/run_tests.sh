#!/bin/bash

# Compila el proyecto desde cero.
# Funciona tanto desde la raíz del proyecto como desde tests_sintaxis/.
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$PROJECT_DIR" || exit 1

echo "Compilando el proyecto..."
rm -f compilador parser.tab.c parser.tab.h lex.yy.c
bison -d parser.y
flex lexer.l
gcc -o compilador parser.tab.c lex.yy.c compilador.c ast.c symbol_table.c -lfl

if [ ! -f compilador ]; then
    echo "Error: no se pudo generar el ejecutable 'compilador'."
    exit 1
fi

echo "Build OK."
echo ""

fails=0

# Función para correr un test
# $1: ruta al archivo de test
# $2: 0 si debe compilar OK, 1 si debe fallar con error
run_test() {
    local archivo="$1"
    local debe_fallar="$2"

    output=$(./compilador "$archivo" 2>&1)

    if [ "$debe_fallar" -eq 0 ]; then
        if echo "$output" | grep -qi "error"; then
            echo "[FAIL] $archivo (no esperaba error)"
            echo "   Salida: $output"
            fails=$((fails + 1))
        else
            echo "[PASS] $archivo"
        fi
    else
        if echo "$output" | grep -qi "error"; then
            echo "[PASS] $archivo (detectó el error esperado)"
        else
            echo "[FAIL] $archivo (esperaba error)"
            echo "   Salida: $output"
            fails=$((fails + 1))
        fi
    fi
}

echo "Ejecutando tests..."
echo ""

# Tests que deben compilar OK
run_test "tests_sintaxis/test_ok.txt" 0
run_test "tests_sintaxis/test_ok2.txt" 0
run_test "tests_sintaxis/test_ok_full.txt" 0
run_test "tests_sintaxis/test_ok_if.txt" 0
run_test "tests_sintaxis/test_ok_while.txt" 0

# Tests que deben reportar error
run_test "tests_sintaxis/test_oknt.txt" 1
run_test "tests_sintaxis/test_oknt2.txt" 1
run_test "tests_sintaxis/test_oknt3.txt" 1

echo ""
if [ "$fails" -gt 0 ]; then
    echo "$fails test(s) fallaron."
    exit 1
fi
echo "Todos los tests pasaron."
