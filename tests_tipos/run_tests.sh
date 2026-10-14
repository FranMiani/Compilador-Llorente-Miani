#!/bin/bash

# Compila el proyecto desde cero.
# Funciona tanto desde la raíz del proyecto como desde tests_tipos/.
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

# Función para correr un test de chequeos de tipos
# $1: ruta al archivo de test
# $2: modo esperado:
#     "ok"      -> sin errores ni warnings
#     "error"   -> debe reportar un error de tipo
#     "warning" -> debe reportar un warning y ningún error
run_test() {
    local archivo="$1"
    local modo="$2"

    output=$(./compilador "$archivo" 2>&1)

    case "$modo" in
        ok)
            if echo "$output" | grep -qiE "error|warning"; then
                echo "[FAIL] $archivo (no esperaba error ni warning)"
                echo "   Salida: $output"
                fails=$((fails + 1))
            else
                echo "[PASS] $archivo"
            fi
            ;;
        error)
            if echo "$output" | grep -qi "error"; then
                echo "[PASS] $archivo (detectó el error esperado)"
            else
                echo "[FAIL] $archivo (esperaba error)"
                echo "   Salida: $output"
                fails=$((fails + 1))
            fi
            ;;
        warning)
            if echo "$output" | grep -qi "warning" && ! echo "$output" | grep -qi "error"; then
                echo "[PASS] $archivo (detectó el warning esperado)"
            else
                echo "[FAIL] $archivo (esperaba un warning sin errores)"
                echo "   Salida: $output"
                fails=$((fails + 1))
            fi
            ;;
    esac
}

echo "Ejecutando tests..."
echo ""

# Tests que deben compilar sin errores ni warnings
run_test "tests_tipos/test_ok_tipos.txt" ok
run_test "tests_tipos/test_ok_bool.txt" ok
run_test "tests_tipos/test_ok_metodos.txt" ok
run_test "tests_tipos/test_ok_recursion.txt" ok
run_test "tests_tipos/test_ok_void_params.txt" ok

# Tests que deben reportar un error de tipo
run_test "tests_tipos/test_err_asignacion.txt" error
run_test "tests_tipos/test_err_aritmetica.txt" error
run_test "tests_tipos/test_err_and.txt" error
run_test "tests_tipos/test_err_not.txt" error
run_test "tests_tipos/test_err_uminus.txt" error
run_test "tests_tipos/test_err_if.txt" error
run_test "tests_tipos/test_err_if_else.txt" error
run_test "tests_tipos/test_err_while.txt" error
run_test "tests_tipos/test_err_return.txt" error
run_test "tests_tipos/test_err_return_void.txt" error
run_test "tests_tipos/test_err_comparacion.txt" error
run_test "tests_tipos/test_err_params_tipo.txt" error
run_test "tests_tipos/test_err_params_cantidad.txt" error
run_test "tests_tipos/test_err_args_faltan.txt" error
run_test "tests_tipos/test_err_args_sobran.txt" error

# Tests que deben compilar con warning (y sin errores)
run_test "tests_tipos/test_warn_asignacion.txt" warning
run_test "tests_tipos/test_warn_suma.txt" warning
run_test "tests_tipos/test_warn_return.txt" warning

echo ""
if [ "$fails" -gt 0 ]; then
    echo "$fails test(s) fallaron."
    exit 1
fi
echo "Todos los tests pasaron."
