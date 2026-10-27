#!/bin/bash
#
# Tests de generación de assembly (GNU / AT&T).
#
# Para cada programa:
#   1. genera el .s con ./compilador
#   2. lo ensambla con gcc -Wall -Werror -Wa,--fatal-warnings (cero warnings)
#   3. en los tests de ejecución, lo linkea (con un stub para los extern)
#      y compara el código de salida del proceso
#   4. opcionalmente verifica que el .s contenga ciertas instrucciones
#
# OJO: compilador.c siempre escribe la salida en "prueba.s" (cwd), por eso se
# copia a un directorio temporal usando el nombre del archivo de test.
#
# Los patrones son grep -E: usar comillas simples para que $ llegue escapado.
#
# Funciona tanto desde la raíz del proyecto como desde tests_asm/.

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$PROJECT_DIR" || exit 1

echo "Compilando el proyecto..."
rm -f compilador parser.tab.c parser.tab.h lex.yy.c
bison -d parser.y
flex lexer.l
gcc -o compilador parser.tab.c lex.yy.c compilador.c ast.c symbol_table.c instruccion.c asm_gen.c -lfl

if [ ! -f compilador ]; then
    echo "Error: no se pudo generar el ejecutable 'compilador'."
    exit 1
fi

echo "Build OK."
echo ""

OUT="$(mktemp -d)"
trap 'rm -rf "$OUT"' EXIT

fails=0

# base <archivo>: nombre base del test (sin ruta ni .txt).
base() { basename "$1" .txt; }

# gen <archivo> -> imprime la ruta del .s generado; vacío si falló.
gen() {
    local src="$1" b
    b=$(base "$src")
    if ! ./compilador "$src" >"$OUT/$b.log" 2>&1; then
        return 1
    fi
    cp prueba.s "$OUT/$b.s" || return 1
    echo "$OUT/$b.s"
}

# fail <nombre> <mensaje...>
fail() {
    local name="$1" msg="$2"
    echo "[FAIL] $name ($msg)"
    shift 2
    local line
    for line in "$@"; do
        echo "$line" | sed 's/^/       /' | head -10
    done
    fails=$((fails + 1))
}

# check_run <nombre> <archivo> <exit_esperado> [stub.o]
# Genera, ensambla sin warnings, linkea y ejecuta; compara el exit code.
check_run() {
    local name="$1" src="$2" want="$3" stub="$4"
    local b s obj bin rc
    b=$(base "$src")
    s=$(gen "$src")
    if [ -z "$s" ]; then
        fail "$name" "el compilador falló con $src" "$(head -5 "$OUT/$b.log")"
        return 1
    fi
    obj="$OUT/$b.o"
    if ! gcc -Wall -Werror -Wa,--fatal-warnings -c "$s" -o "$obj" 2>"$OUT/$b.asm.log"; then
        fail "$name" "no ensambla limpio" "$(head -10 "$OUT/$b.asm.log")"
        return 1
    fi
    bin="$OUT/$b.bin"
    if ! gcc "$obj" $stub -o "$bin" 2>"$OUT/$b.ld.log"; then
        fail "$name" "no linkea" "$(head -10 "$OUT/$b.ld.log")"
        return 1
    fi
    timeout 10 "$bin"
    rc=$?
    if [ "$rc" -eq 124 ]; then
        fail "$name" "el binario no terminó (timeout 10s)"
        return 1
    fi
    if [ "$rc" -eq "$want" ]; then
        echo "[PASS] $name (exit $rc)"
        return 0
    fi
    fail "$name" "exit $rc, esperado $want"
    return 1
}

# check_grep <nombre> <archivo> <patrón>: el patrón aparece en el .s.
check_grep() {
    local name="$1" src="$2" pat="$3"
    local s
    s=$(gen "$src")
    if [ -n "$s" ] && grep -qE "$pat" "$s"; then
        echo "[PASS] $name"
        return 0
    fi
    fail "$name" "patrón '$pat' ausente en el .s de $src"
    return 1
}

# check_notgrep <nombre> <archivo> <patrón>: el patrón NO aparece en el .s.
check_notgrep() {
    local name="$1" src="$2" pat="$3"
    local s
    s=$(gen "$src")
    if [ -n "$s" ] && ! grep -qE "$pat" "$s"; then
        echo "[PASS] $name"
        return 0
    fi
    fail "$name" "patrón '$pat' no debería estar en el .s de $src"
    return 1
}

# check_count <nombre> <archivo> <patrón> <esperado>: ocurrencias en el .s.
check_count() {
    local name="$1" src="$2" pat="$3" want="$4"
    local s got
    s=$(gen "$src")
    if [ -z "$s" ]; then
        fail "$name" "el compilador falló con $src"
        return 1
    fi
    got=$(grep -cE "$pat" "$s")
    if [ "$got" -eq "$want" ]; then
        echo "[PASS] $name ($got)"
        return 0
    fi
    fail "$name" "'$pat': esperaba $want ocurrencias, obtuvo $got"
    return 1
}

echo "Ejecutando tests de generación de assembly..."
echo ""

T="tests_asm"

STUB="$OUT/extern_stub.o"
gcc -c "$T/extern_stub.c" -o "$STUB" || { echo "Error: no se pudo compilar el stub de extern."; exit 1; }

# --- Encabezado del archivo .s ---
check_grep "hdr: arranca en .text" "$T/test_arith.txt" '^[[:space:]]*\.text'
check_grep "hdr: main es global y tiene label" "$T/test_arith.txt" '^main:'
check_grep "hdr: .globl main" "$T/test_arith.txt" '\.globl main'
check_grep "hdr: sección .note.GNU-stack" "$T/test_arith.txt" '\.note\.GNU-stack'

# --- Aritmética: imul para la multiplicación ---
check_run "arith: 2+3*4 = 14" "$T/test_arith.txt" 14
check_grep "arith: usa imul" "$T/test_arith.txt" 'imul'

# --- División y módulo con signo (cqto + idiv) ---
check_run "divmod: 10/2 + 10%3 = 6" "$T/test_divmod.txt" 6
check_count "divmod: un cqto por operación" "$T/test_divmod.txt" 'cqto' 2
check_count "divmod: un idiv por operación" "$T/test_divmod.txt" 'idiv' 2
check_grep "divmod: divisor cargado en %r11" "$T/test_divmod.txt" 'idiv %r11'
check_run "negdiv: -7/2 y -7%2 = 1" "$T/test_negdiv.txt" 1
check_count "negdiv: cqto en las dos operaciones" "$T/test_negdiv.txt" 'cqto' 2

# --- If / if-else ---
check_run "if: 2==1+1 toma la rama then (1)" "$T/test_if.txt" 1
check_grep "if: salto condicional a Else" "$T/test_if.txt" 'jne Else'
check_grep "if: salto incondicional a End_if" "$T/test_if.txt" 'jmp End_if'
check_grep "if: etiqueta End_if definida" "$T/test_if.txt" '^End_if[0-9]*:'

# --- While anidado: etiquetas únicas ---
check_run "while: anidado cuenta 9" "$T/test_while.txt" 9
check_grep "while: etiqueta While" "$T/test_while.txt" '^While:'
check_grep "while: salto de vuelta al inicio" "$T/test_while.txt" 'jmp While'

# --- Booleanos: && || ! ---
check_run "bool: a && !b y b || a -> 7" "$T/test_bool.txt" 7
check_grep "bool: NOT con xor inmediato" "$T/test_bool.txt" 'xor \$1, %r10'
# El if sobre una variable debe leer la variable y no un r10 viejo: acá la
# comparación x > x deja r10 en 0 y a queda en true, así que hay que entrar.
check_run "boolvar: if(a) tras una comparación -> 7" "$T/test_boolvar.txt" 7

# --- Llamadas: args por registro (<=6) y por stack (>6) ---
check_run "call1: doble(4) = 8" "$T/test_call1.txt" 8
check_grep "call1: función declarada global" "$T/test_call1.txt" '\.globl doble'
check_grep "call1: prólogo enter" "$T/test_call1.txt" 'enter \$'
check_grep "call1: primer arg en %rdi" "$T/test_call1.txt" 'mov \$4, %rdi'
check_run "call7: séptimo arg = 42" "$T/test_call7.txt" 42
check_grep "call7: arg extra por push" "$T/test_call7.txt" 'push \$42'
check_grep "call7: desapilado tras el call" "$T/test_call7.txt" 'add \$8, %rsp'
check_grep "call7: parámetro recibido de la pila" "$T/test_call7.txt" 'mov 16\(%rbp\), %r11'

# --- Recursión ---
check_run "recursion: fib(10) = 55" "$T/test_recursion.txt" 55

# --- Extern: no se define label acá; la resolución es en el link (stub) ---
check_run "extern: mm() = 7 con stub" "$T/test_extern.txt" 7 "$STUB"
check_notgrep "extern: sin label mm: (es externa)" "$T/test_extern.txt" '^mm:'
check_grep "extern: la llamada queda como call mm" "$T/test_extern.txt" 'call mm'

echo ""
if [ "$fails" -gt 0 ]; then
    echo "$fails test(s) fallaron."
    exit 1
fi
echo "Todos los tests pasaron."
