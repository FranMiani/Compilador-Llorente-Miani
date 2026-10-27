#!/bin/bash
#
# Tests de generación de código intermedio.
# Compila el proyecto y verifica que la pila de instrucciones impresa por
# compilador.c contenga las instrucciones correctas, en el orden correcto.
#
# OJO: compilador.c imprime tabla de símbolos + AST + instrucciones todo
# mezclado en stdout. Por eso se filtra solo las líneas de instrucciones
# (las que empiezan con un opcode). NOTA: print_pila imprime MOV como
# "ASSIGN", DEC como "DECLARATION" y EQ como "EQUAL". CALL y LBLE se
# imprimen como "CALL" y "LBLE".
#
# Funciona tanto desde la raíz del proyecto como desde tests_codigo_inter/.

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

fails=0

# Regex de líneas de instrucciones (ver type_name() en instruccion.c).
IR_RE='^(ADD|SUB|MUL|DIV|MOD|CMP|AND|OR|XOR|LESS|GREAT|EQUAL|ASSIGN|DECLARATION|JUMPG|JUMPL|JUMPE|JUMP|LBL|LBLE|JUMPF|JUMPT|PUSH|POP|RET|CALL) '

# ir <archivo> : imprime solo las líneas de instrucciones.
ir() {
    ./compilador "$1" 2>&1 | grep -E "$IR_RE"
}

# ops <archivo> : solo la columna de opcodes, uno por línea.
ops() {
    ir "$1" | awk '{print $1}'
}

# check_order <nombre> <archivo> <pat1> [pat2 ...]
# Cada patrón es un grep -E contra una línea del IR y deben aparecer en orden.
check_order() {
    local name="$1"; local file="$2"; shift 2
    local lines
    lines=$(ir "$file")
    if [ -z "$lines" ]; then
        echo "[FAIL] $name (sin instrucciones para $file)"
        echo "$lines" | head -5
        fails=$((fails + 1))
        return 1
    fi
    local rest="$lines"
    local pat
    for pat in "$@"; do
        local idx
        idx=$(echo "$rest" | grep -n -m1 -E "$pat" | cut -d: -f1)
        if [ -z "$idx" ]; then
            echo "[FAIL] $name (patrón '$pat' no encontrado en orden)"
            echo "--- IR de $file ---"
            echo "$lines"
            echo "-------------------"
            fails=$((fails + 1))
            return 1
        fi
        rest=$(echo "$rest" | tail -n +"$((idx + 1))")
    done
    echo "[PASS] $name"
    return 0
}

# check_count <nombre> <archivo> <opcode> <esperado>
check_count() {
    local name="$1"; local file="$2"; local op="$3"; local exp="$4"
    local got
    got=$(ops "$file" | grep -cx "$op" || true)
    if [ "$got" -ne "$exp" ]; then
        echo "[FAIL] $name (opcode $op: esperaba $exp, obtuvo $got)"
        fails=$((fails + 1))
        return 1
    fi
    echo "[PASS] $name"
    return 0
}

# check_grep <nombre> <archivo> <patrón>
# Verifica un operando/detalle (ej. "ASSIGN.*name: x").
check_grep() {
    local name="$1"; local file="$2"; local pat="$3"
    if ir "$file" | grep -qE "$pat"; then
        echo "[PASS] $name"
        return 0
    fi
    echo "[FAIL] $name (patrón '$pat' ausente en $file)"
    fails=$((fails + 1))
    return 1
}

echo "Ejecutando tests de código intermedio..."
echo ""

T="tests_codigo_inter"

# --- Aritmética: ADD luego MUL, resultado asignado a x ---
check_order "arith: ADD antes que MUL antes que ASSIGN" "$T/test_arith.txt" "^ADD " "^MUL " "^ASSIGN "
check_grep  "arith: MUL/ASSIGN operan sobre x" "$T/test_arith.txt" "ASSIGN.*name: x"

# --- DIV y MOD ---
check_order "divmod: DIV y luego MOD" "$T/test_divmod.txt" "^DIV " "^MOD "
check_count "divmod: un DIV" "$T/test_divmod.txt" "DIV" 1
check_count "divmod: un MOD" "$T/test_divmod.txt" "MOD" 1

# --- Declaración + asignación simple ---
check_order "decl: LBL, DECLARATION, ADD, ASSIGN x" "$T/test_decl_assign.txt" "^LBL " "DECLARATION.*name: x" "^ADD " "ASSIGN.*name: x"

# --- Comparaciones: cada una genera LESS|GREAT|EQUAL (con el resultado en un
#     temp) y un JUMPF posterior; no existe un opcode CMP suelto ---
check_count "cmp: una LESS"  "$T/test_cmp.txt" "LESS" 1
check_count "cmp: una GREAT" "$T/test_cmp.txt" "GREAT" 1
check_count "cmp: una EQUAL" "$T/test_cmp.txt" "EQUAL" 1
check_count "cmp: sin CMP suelto" "$T/test_cmp.txt" "CMP" 0
check_order "cmp: LESS y su JUMPF"  "$T/test_cmp.txt" "^LESS " "^JUMPF "
check_order "cmp: GREAT y su JUMPF" "$T/test_cmp.txt" "^GREAT " "^JUMPF "
check_order "cmp: EQUAL y su JUMPF" "$T/test_cmp.txt" "^EQUAL " "^JUMPF "
check_order "cmp: LESS, GREAT, EQUAL en orden" "$T/test_cmp.txt" "^LESS " "^GREAT " "^EQUAL "

# --- IF sin else: JUMPF ... End_if, LBL End_if, sin rama Else ni JUMP ---
check_order "if: JUMPF a End_if y LBL End_if" "$T/test_if.txt" "JUMPF.*End_if" "LBL.*End_if"
check_count "if: sin JUMP incondicional" "$T/test_if.txt" "JUMP" 0

# --- IF/ELSE: JUMPF a Else, JUMP a End_if, LBL Else, LBL End_if ---
check_order "if-else: JUMPF Else, JUMP End, LBLs" "$T/test_if_else.txt" "JUMPF.*Else" "JUMP.*End_if" "LBL.*Else" "LBL.*End_if"

# --- WHILE: LBL While, JUMPF End_While, JUMP al label While (val1, no un
#     temp de la condición), LBL End_While ---
check_order "while: etiquetas y saltos" "$T/test_while.txt" "LBL.*While" "JUMPF.*End_While" "^JUMP \[  name: While" "LBL.*End_While"

# --- AND cortocircuito: MOV, JUMPF End_And, MOV, LBL End_And ---
check_order "and: MOV, JUMPF End_And, MOV, LBL" "$T/test_and.txt" "^ASSIGN " "JUMPF.*End_And" "^ASSIGN " "LBL.*End_And"

# --- OR cortocircuito: MOV, JUMPT End_OR, MOV, LBL End_OR ---
check_order "or: MOV, JUMPT End_OR, MOV, LBL" "$T/test_or.txt" "^ASSIGN " "JUMPT.*End_OR" "^ASSIGN " "LBL.*End_OR"

# --- Menos unario: SUB 0, op antes de asignar ---
check_order "uminus: SUB 0,5 antes que ASSIGN x" "$T/test_uminus.txt" "SUB.*value: 0.*value: 5" "ASSIGN.*name: x"
check_order "uminus: SUB 0,y antes que ASSIGN x" "$T/test_uminus.txt" "SUB.*value: 0.*name: y" "ASSIGN.*name: x"
check_count "uminus: dos SUB" "$T/test_uminus.txt" "SUB" 2

# --- Doble &&: etiquetas End_And únicas ---
check_order "and2: End_And y luego End_And1" "$T/test_double_and.txt" "LBL.*End_And " "LBL.*End_And1"
check_count "and2: cuatro JUMPF en total" "$T/test_double_and.txt" "JUMPF" 4

# --- Declaración de función: LBL foo, param de 1 arg desde rdi, MOV RET + RET ---
check_order "func: LBL foo y param desde rdi" "$T/test_func.txt" "LBL.*name: foo" "ASSIGN.*name: p.*name: rdi"
check_order "func: return deja RET y retorna" "$T/test_func.txt" "ASSIGN.*name: RET" "^RET "

# --- Llamada sin args: CALL a foo, sin PUSH ni POP, resultado en temp ---
check_grep  "call0: CALL a foo" "$T/test_call0.txt" "CALL.*name: foo"
check_grep  "call0: resultado de la llamada en temp" "$T/test_call0.txt" "ASSIGN \[  name: [A-Z] +\|.*name: RET"
check_count "call0: sin PUSH" "$T/test_call0.txt" "PUSH" 0
check_count "call0: sin POP" "$T/test_call0.txt" "POP" 0

# --- NOT: XOR con 1 y luego asignación ---
check_order "not: XOR antes que ASSIGN c" "$T/test_not.txt" "^XOR " "ASSIGN.*name: c"
check_count "not: un XOR" "$T/test_not.txt" "XOR" 1
check_grep  "not: XOR contra valor 1" "$T/test_not.txt" "XOR.*value: 1"

# --- Llamada con 1 arg: el arg va por registro (rdi), CALL, sin PUSH ni POP ---
check_order "call1: arg en rdi y CALL a foo" "$T/test_call1.txt" "ASSIGN.*name: rdi.*value: 1" "CALL.*name: foo"
check_count "call1: sin PUSH (args por registro)" "$T/test_call1.txt" "PUSH" 0
check_count "call1: sin POP" "$T/test_call1.txt" "POP" 0

# --- Llamada con 2 args: rdi y rsi, CALL, sin PUSH ni POP ---
check_order "call2: args en rdi y rsi y CALL a foo" "$T/test_call2.txt" "ASSIGN.*name: rdi.*value: 1" "ASSIGN.*name: rsi.*value: 2" "CALL.*name: foo"
check_count "call2: sin PUSH (args por registro)" "$T/test_call2.txt" "PUSH" 0
check_count "call2: sin POP" "$T/test_call2.txt" "POP" 0

# --- Llamada con 7 args: 6 por registro, el 7mo por PUSH y se recibe en TOP ---
check_order "call7: r9, PUSH 7, CALL, POP" "$T/test_call7.txt" "ASSIGN.*name: r9.*value: 6" "PUSH.*value: 7" "CALL.*name: foo" "^POP "
check_count "call7: un PUSH" "$T/test_call7.txt" "PUSH" 1
check_count "call7: un POP" "$T/test_call7.txt" "POP" 1
check_grep  "call7: param extra recibido en TOP" "$T/test_call7.txt" "ASSIGN.*name: g.*name: TOP"

# --- Extern: la declaración genera LBLE (sin label ni cuerpo) y el CALL ---
check_grep  "extern: LBLE por la declaración" "$T/test_extern.txt" "LBLE.*name: mm"
check_grep  "extern: CALL a mm" "$T/test_extern.txt" "CALL.*name: mm"

echo ""
if [ "$fails" -gt 0 ]; then
    echo "$fails test(s) fallaron."
    exit 1
fi
echo "Todos los tests pasaron."
