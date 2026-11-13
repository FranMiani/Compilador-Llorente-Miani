#!/bin/bash
#
# Tests end-to-end de semántica.
#
# Para cada programa de entrada:
#   1. lo compila con ./compilador (genera prueba.s),
#   2. ensambla el .s con -Wall -Werror -Wa,--fatal-warnings,
#   3. lo linkea con tests_e2e/test_lib.c (print, println, getInt),
#   4. ejecuta el binario y compara stdout y exit code contra los archivos
#      esperados.
#
# Cada caso test_XXX.txt puede tener:
#   test_XXX.out   -> stdout esperado (se ignoran los newlines finales)
#   test_XXX.exit  -> exit code esperado (si falta, se asume 0)
#   test_XXX.in    -> stdin del programa (si falta, se usa /dev/null)
#
# Funciona tanto desde la raíz del proyecto como desde tests_e2e/.

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$PROJECT_DIR" || exit 1

echo "Compilando el proyecto..."
rm -f compilador parser.tab.c parser.tab.h lex.yy.c
bison -d parser.y || exit 1
flex lexer.l || exit 1
gcc -o compilador parser.tab.c lex.yy.c compilador.c ast.c symbol_table.c instruccion.c asm_gen.c optimLit.c registerManager.c -lfl || exit 1

if [ ! -f compilador ]; then
    echo "Error: no se pudo generar el ejecutable 'compilador'."
    exit 1
fi

echo "Build OK."
echo ""

OUT="$(mktemp -d)"
trap 'rm -rf "$OUT"' EXIT

if ! gcc -c "$SCRIPT_DIR/test_lib.c" -o "$OUT/test_lib.o"; then
    echo "Error: no se pudo compilar tests_e2e/test_lib.c"
    exit 1
fi

fails=0
total=0

fail() {
    local name="$1"
    local msg="$2"
    echo "[FAIL] $name ($msg)"
    fails=$((fails + 1))
}

run_test() {
    local src="$1"
    local base
    base=$(basename "$src" .txt)
    total=$((total + 1))

    local dir="$OUT/$base"
    mkdir -p "$dir"

    local expected_out="$SCRIPT_DIR/$base.out"
    local expected_exit_file="$SCRIPT_DIR/$base.exit"
    local stdin_file="$SCRIPT_DIR/$base.in"
    local expected_exit=0

    if [ -f "$expected_exit_file" ]; then
        expected_exit=$(tr -d '[:space:]' < "$expected_exit_file")
    fi

    # 1. Compilar el programa fuente.
    if ! ( cd "$dir" && "$PROJECT_DIR/compilador" "$src" >compiler.log 2>&1 ); then
        fail "$base" "el compilador terminó con error"
        head -5 "$dir/compiler.log" | sed 's/^/       /'
        return
    fi
    if grep -qi "error" "$dir/compiler.log"; then
        fail "$base" "el compilador reportó un error"
        grep -i "error" "$dir/compiler.log" | head -5 | sed 's/^/       /'
        return
    fi
    if [ ! -f "$dir/prueba.s" ]; then
        fail "$base" "no se generó prueba.s"
        return
    fi

    # 2. Ensamblar.
    if ! gcc -Wall -Werror -Wa,--fatal-warnings -c "$dir/prueba.s" -o "$dir/prog.o" 2>"$dir/asm.log"; then
        fail "$base" "no ensambla limpio"
        head -5 "$dir/asm.log" | sed 's/^/       /'
        return
    fi

    # 3. Linkear con la librería de runtime de los tests.
    if ! gcc "$dir/prog.o" "$OUT/test_lib.o" -o "$dir/prog.bin" 2>"$dir/link.log"; then
        fail "$base" "no linkea"
        head -5 "$dir/link.log" | sed 's/^/       /'
        return
    fi

    # 4. Ejecutar y capturar stdout/exit code.
    local rc
    if [ -f "$stdin_file" ]; then
        timeout 10 "$dir/prog.bin" < "$stdin_file" >"$dir/stdout.txt" 2>"$dir/stderr.txt"
        rc=$?
    else
        timeout 10 "$dir/prog.bin" < /dev/null >"$dir/stdout.txt" 2>"$dir/stderr.txt"
        rc=$?
    fi

    if [ "$rc" -eq 124 ]; then
        fail "$base" "el binario no terminó (timeout 10s)"
        return
    fi

    local actual expected
    actual=$(cat "$dir/stdout.txt")
    expected=""
    if [ -f "$expected_out" ]; then
        expected=$(cat "$expected_out")
    fi

    if [ "$actual" != "$expected" ]; then
        fail "$base" "stdout esperado '$expected', obtenido '$actual'"
        return
    fi
    if [ "$rc" -ne "$expected_exit" ]; then
        fail "$base" "exit code $rc, esperado $expected_exit"
        return
    fi

    echo "[PASS] $base (stdout '$actual', exit $rc)"
}

echo "Ejecutando tests end-to-end..."
echo ""

for src in "$SCRIPT_DIR"/test_*.txt; do
    [ -e "$src" ] || continue
    run_test "$src"
done

echo ""
if [ "$total" -eq 0 ]; then
    echo "No se encontraron tests."
    exit 1
fi
if [ "$fails" -gt 0 ]; then
    echo "$fails test(s) fallaron."
    exit 1
fi
echo "Todos los tests pasaron."
