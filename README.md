# Compilador-Llorente-Miani

Implementación del proyecto de la materia **Compiladores**.

---

## Compilación y ejecución

Para compilar y ejecutar con un archivo de prueba:
```bash
./ejecutar.sh
```

Para correr los tests sobre análisis sintáctico y léxico:
```bash
./tests_sintaxis/run_tests.sh
```

Para correr los tests de la tabla de símbolos y el AST (restricciones semánticas):
```bash
./test_TS_AST/run_tests.sh
```

Para correr los tests de chequeos de tipos (errores y warnings de tipos):
```bash
./tests_tipos/run_tests.sh
```

Para correr los tests de generación de código intermedio:
```bash
./tests_codigo_inter/run_tests.sh
```

Para correr los tests de generación de assembly (ensamblado, linkeo y ejecución):
```bash
./tests_asm/run_tests.sh
```

Para correr los tests end-to-end (compilación, ensamblado, linkeo, ejecución y verificación de stdout y exit code):
```bash
./tests_e2e/run_tests.sh
```

Los scripts de test compilan el proyecto y pueden ejecutarse desde cualquier directorio del repositorio.

De forma manual:
```bash
bison -d parser.y
flex lexer.l
gcc -o compilador parser.tab.c lex.yy.c compilador.c ast.c symbol_table.c \
    instruccion.c asm_gen.c optimLit.c registerManager.c -lfl
./compilador programa.txt
```

El compilador imprime por stdout la tabla de símbolos, el AST y el IR, y escribe el assembly en `prueba.s` (en el directorio actual).

### Pipeline

El `main` de `compilador.c` ejecuta las etapas en este orden:

1. **Parseo** (`yyparse`): construye la tabla de símbolos y el AST. Las validaciones semánticas de tipos se hacen en las acciones del parser.
2. **Impresión de depuración**: `print_table` y `print_ast`.
3. **Preparación del IR**: `inicializarRegs()` (llamada al arrancar) deja libres `r12`–`r15`; `initReg()` crea los símbolos globales `RET` y `TOP`.
4. **Optimización del AST**: `optimizarCalculosLiterales` (plegado de constantes) y después `optimizarCaminos` (poda de ramas con condición literal).
5. **Generación de IR**: `crear_pila()` + `armarPila(pila, father, NULL)`, con asignación de registros (`registerManager.c`) y contabilidad de memoria.
6. **Impresión del IR**: `print_pila`.
7. **Generación de assembly**: `stack_to_asm(pila, "prueba.s")`, que calcula los frames y traduce cada instrucción.

--- 

## Documentación — Etapa 1

Las tareas fueron realizadas en conjunto durante las clases.

### Decisiones de diseño

- **Regla para bloques:**  
  Agregamos la regla `Bloque -> '{' Linea '}'` para evitar repetir código encargado de la creación de niveles.

- **Literales numéricos y booleanos:**  
  En lugar de utilizar un único token `LITERAL`, utilizamos un token específico para cada tipo numérico:
  - `LIT_INT`
  - `LIT_FLOAT`

  Además, los valores booleanos `TRUE` y `FALSE` cuentan con tokens específicos.

- **Comentarios multilínea:**  
  Para el manejo de comentarios multilínea utilizamos la funcionalidad de **cambios de estado de Flex**.

  Al detectar `/*` desde el estado por defecto `INITIAL`, se cambia al estado `COMMENT`. En este estado se cuentan los saltos de línea y se ignoran los demás caracteres. Al detectar `*/`, se vuelve al estado `INITIAL`.

  La regla correspondiente a `*/` se encuentra antes que la regla encargada de ignorar caracteres, de modo que los símbolos de cierre del comentario sean reconocidos correctamente y no sean descartados por esta última.

- **Conteo de líneas:**  
  Para contar las líneas del programa, creamos una variable global y una función encargada de incrementarla. Esta función es invocada desde el analizador léxico cada vez que se reconoce un salto de línea (`\n`).

---

## Documentación — Etapa 2

Las tareas fueron principalmente realizadas en conjunto durante los horarios de clases.

### Decisiones de diseño

- **TS: una lista enlazada + pila de marcadores de nivel:**  
  La tabla de símbolos es una única lista enlazada de `Symbol`. Los niveles se representan con una pila `Levels`, donde cada entrada guarda un puntero al símbolo que limita ese nivel.

  Alternativa: un arreglo de tablas (una por nivel). Elegimos esta porque la inserción es constante y `close_level` tambien, restaura `table->head = actual->level` y desapila, sin recorrer ni copiar nada. El scope queda definido por *dónde está el marcador*, no por un contador.

- **TS: dos búsquedas con semántica distinta sobre la misma lista:**  
  - `find_symbol`: recorre **toda** la lista. Se usa para visibilidad con scope dinámico (asignaciones, llamadas a métodos): desde cualquier nivel alcanza cualquier símbolo declarado antes.
  - `find_in_level`: recorre **solo hasta el marcador del nivel actual**. Se usa para chequear redeclaración en el scope donde se está parseando: si declaro `int z;` dentro de un `while`, no choca con un `z` de un nivel externo.

- **Declaraciones en dos fases: `NOT_TYPE` + `push_type`:**  
  `Ids_decl` inserta los símbolos con tipo `NOT_TYPE`; recién en `Var_decl` se define el tipo de la declaración y `push_type` lo propaga por la cadena de IDs.


- **Métodos con parámetros: usamos `'{' Linea '}'` en vez de `Bloque`:**  
  En la regla de `Method_decl`.
  Si el body usara `Bloque` (que hace su propio `new_level`), params y locales quedarían en niveles distintos y `find_in_level` no vería los params al chequear redeclaraciones dentro del método. Con el nivel único, `int a;` en el body de `int max(int a)` detecta el conflicto correctamente, mientras que un bloque anidado `{ int a; }` sigue pudiendo "sombrear" el param.

---

## Documentación — Etapa 3

Las tareas fueron principalmente realizadas en conjunto durante los horarios de clases. 

### Decisiones de diseño

- **Chequeos en las acciones del parser, sin fase separada:**  
  No recorremos el AST después de parsear: los chequeos van en las acciones semánticas de las reglas, justo cuando se reduce cada producción, porque ahí `$1` y `$3` ya tienen los `Symbol` con su `exprType`. Cada reducción de `expr` crea su símbolo con el tipo resultante (aritmética → tipo de los operandos, con mezcla int/float → `FLOAT`; comparaciones y lógicos → `BOOL`; literales → su tipo; `ID` → el tipo declarado en la TS), de modo que los contextos superiores (asignación, condición, retorno, argumentos) solo tienen que mirar el tipo del nodo que reciben.

- **Distincion entre error y warning:**  
  Los mensajes se distinguen por el prefijo (`Error ...` / `Warning ...`), y los tests de `tests_tipos` los separan segun su salida.  Los warnings nunca bloquean: la compilación continúa y la expresión toma el tipo promovido.

- **Compatibilidad numérica con `comp()`:**  
  Dos tipos son compatibles si son iguales o si ambos son numéricos (`INT`/`FLOAT`). Un booleano nunca es compatible con un numérico. `comp()` se usa en `verify_params` para validar el pasaje de parámetros; la aritmética, las comparaciones, la asignación y el `return` tienen su chequeo escrito directamente en la acción de la regla (con la misma regla de compatibilidad int/float).

- **Coerción int↔float:**  
  Cuando se mezclan `int` y `float` en aritmética, asignación o retorno, se emite un **warning** y el resultado/promoción es `FLOAT`. En el pasaje de parámetros la mezcla de int y float se acepta **sin warning** (para no ensuciar la salida con conversiones esperadas). El caso incompatible (booleano donde va un numérico o viceversa) es error.

- **Tipos de retorno con `returnType`:**  
  Una variable global se setea al entrar a la declaración de un método (en la acción intermedia después de `(`) y se resetea a `VOID1` al cerrarlo. `return expr` se compara contra ese tipo: mezcla int con float → warning, cualquier otra discrepancia → error. `return;` exige método `void`.

- **Símbolo del método insertado antes de abrir el nivel:**  
  El símbolo de la función se inserta en el nivel externo *antes* de hacer `new_level()` (no al final de la regla). Esto permite que el método se llame a sí mismo (recursión), porque `find_symbol` lo encuentra durante su propio parseo; además detecta declaraciones duplicadas antes de parsear el body y deja el símbolo de la función como centinela para el chequeo de cantidad de parámetros (ver siguiente punto).

- **Verificación de parámetros: `init`/`end` en el `Symbol` + `verify_params` (algoritmo):**  
  Los símbolos de los parámetros ya quedan cargados en la lista enlazada de la TS durante el parseo de `Params`, porque así se insertaron al declararlos; no creamos una estructura aparte para los parámetros, **reutilizamos esa misma lista**. Al terminar de parsearlos (acción intermedia justo antes del `{`), guardamos en el `Symbol` de la función dos punteros sobre esa lista: `init` al primer parámetro y `end` al último (obtenido con `search_last_Symbol`, que recorre el árbol de `Params` por `third` hasta la hoja). En la TS, `init->next` apunta al símbolo de la propia función y funciona como centinela de cantidad exacta. En la llamada, `verify_params(end, árbol_de_args)` recorre en paralelo las dos estructuras: el árbol de argumentos (`PARAM_PASS`) recursivo por `third`, visitando primero los *últimos* argumentos, y la lista de parámetros desde `end` siguiendo `next`, que también visita primero el *último* parámetro; como ambos recorridos van de atrás hacia adelante, el i-ésimo parámetro se empareja con el i-ésimo argumento y cada par se valida con `comp()`. La cantidad se chequea implícitamente: si los argumentos consumieron exactamente los parámetros, el recorrido devuelve `init->next`; cualquier desigualdad (de más o de menos) devuelve otro puntero y se reporta «Parametros Incorrectos». Que `init`/`end` se guarden *antes* del body (y no al cerrarlo) es lo que permite la recursión; los llamados sin argumentos chequean `init` directamente para detectar métodos que esperan parámetros.

- **Condiciones y operadores:**  
  `if`, `if/else` y `while` exigen que la condición sea `BOOL1` (si no: «expresion no booleana»). `&&` y `||` exigen booleanos en ambos operandos; `!` exige booleano; el `-` unario exige numérico (`INT`/`FLOAT`). Las comparaciones `<`, `>` y `==` producen `BOOL`: en `<`/`>`, si los tipos de los operandos difieren se exige que ambos sean numéricos (error si no, warning ante mezcla int/float), mientras que `==` no valida los operandos y acepta cualquier par.

- **Llamada a método como sentencia:**  
  Agregamos `Method_call ';'` a `Sentencia` para poder invocar métodos (incluidos los `void`) como statements, no solo dentro de expresiones.

---

## Documentación — Etapa 4

Las tareas fueron principalmente realizadas en conjunto durante los horarios de clases. Mateo hizo que la generacion del codigo intermedio suceda recorriendo el arbol AST (antes lo haciamos durante el parseo).

### Decisiones de diseño

- **Fase separada que recorre el AST con `armarPila`:**  
  La generación no está mezclada con el parser: es un recorrido posterior del árbol ya construido. Desde `compilador.c` se llama a `initReg()`, luego a las optimizaciones, después a `crear_pila()` + `armarPila(pila, father, NULL)`, y finalmente a `print_pila(pila)` y `stack_to_asm(...)`. Cada nodo deja su "dirección de resultado" en el atributo sintetizado `dirRet` (vía `addDirRet`), que los nodos padre usan como operandos.

- **Instrucciones y "pila" (`instruccion.h` / `instruccion.c`):**  
  `Instruccion { operador, val1, val2, val3, next }`. `Pila` es una lista enlazada **en orden de emisión**: `top` es la primera instrucción y `bottom` la última, de modo que `add_inst` encola al final en O(1). No es una pila LIFO: `asm_gen` la recorre de principio a fin. `print_pila` muestra `MOV` como `ASSIGN`, `DEC` como `DECLARATION` y `EQ` como `EQUAL`; el resto de los opcodes conserva su nombre, incluidos `BLOCK` y `ENDBLOCK`.

- **Temporales y símbolos globales `RET` / `TOP`:**  
  `registro_siguiente()` crea un `Symbol` nuevo con nombres generados por `name()`: `A..Z, A1..Z1, ...`. Cada temporal recibe `offset = 8 * cant_memoria_necesaria` y `isFuction = 3`. `initReg()` crea los dos símbolos globales del protocolo de llamadas: `RET` (transporta el valor de retorno, se traduce a `%rax`) y `TOP` (base para acceder a los parámetros que vienen por stack). `booleano()` crea y reutiliza el símbolo `r10` para los resultados booleanos.

- **Memoria: contador de slots, offsets y bloques:**  
  `cant_memoria_necesaria` cuenta slots de 8 bytes dentro de la función actual. Se incrementa al declarar (`NODE_DECLARATION`) y al crear un temporal (`registro_siguiente`); los parámetros también consumen un slot. Los offsets se asignan así:
  - temporales: `8 * cant_memoria_necesaria` (en `registro_siguiente`);
  - locales: `8 * cant_memoria_necesaria` (en `NODE_AUX_DEC`, con el contador que ya incrementó la declaración);
  - parámetros: `8 * (++cant_memoria_necesaria)` (en `NODE_PARAM_DECLARATION_PURE`).

  `DECLARATION` es una pseudo-instrucción: no genera assembly. El slot de un temporal es su lugar de respaldo por si el register manager no le da un registro o lo derrama.

- **`BLOCK` / `ENDBLOCK`:**  
  Son pseudo-instrucciones que tampoco generan assembly; solo delimitan regiones para reutilizar slots y para el manejo de registros. En un `if`, `if/else` o `while` se guarda `auxMemo = cant_memoria_necesaria` y, al cerrar el bloque, se restaura el contador: los slots usados por una rama (o por el cuerpo del `while`) quedan libres para lo que sigue o para la otra rama. El `offset` del nodo del bloque no es una dirección de memoria: guarda **cuántos slots** usó (`cant_memoria_necesaria - auxMemo`). El tamaño real del frame se calcula después en `asm_gen.c`.

- **Asignación de registros (`registerManager.c`):**  
  Hay cuatro registros para valores del programa: `r12`, `r13`, `r14` y `r15`. La asignación es local y greedy:
  - `registrar(símbolo, pila, nodo)` usa el primer registro libre;
  - si no hay libre y no estamos dentro de un `while`, elige una víctima y emite `MOV víctima, registro` para derramarla a su slot de memoria;
  - `use(símbolo)` traduce un símbolo lógico a su registro físico si lo tiene y, si es un temporal, lo libera para que el padre pueda reutilizar ese registro como destino;
  - las variables, una vez registradas, tienden a quedarse en su registro; los temporales son efímeros;
  - si los cuatro registros están ocupados por temporales, el temporal nuevo queda directamente en memoria.

  Los contadores de "apariciones restantes" y de temporales están declarados y se consultan, pero no se recalculan durante el recorrido; en la práctica la política termina siendo "derramar la primera variable que se encuentre". Las variables que quedan en memoria no se vuelven a promover a un registro.

- **`while`, `if` y snapshots de registros:**  
  Antes de generar un `while` se llama a `blockear()`; mientras `block > 0`, `registrar` no derrama (si no hay registro libre, el valor va a memoria) y `copiarTo`, `copiarFrom`, `corregir`, `liberarTodo` y `recuperar` no hacen nada. En `if` e `if/else` se usan snapshots del mapa `regs[]`: `copiarTo(aux)` guarda una foto, `copiarFrom(aux)` la restaura para la rama `else` y `corregir(aux)` invalida los registros cuyo contenido pudo quedar inconsistente después de una rama.

- **Aritmética, comparaciones y booleanos:**  
  `ADD`/`SUB`/`MUL`/`DIV`/`MOD` visitan ambos hijos, piden un temporal nuevo con `registro_siguiente()`, lo pasan por `registrar()` y emiten la operación con `use()` sobre los operandos. Las comparaciones (`LESS`, `GREAT`, `EQ`) no crean temporal nuevo: el resultado va siempre a `r10` (`booleano()`), que es un símbolo compartido. Por eso dos comparaciones en la misma expresión se pisan si no se consumen a tiempo. La negación `!` genera `XOR op, 1 → r10`.

- **Cortocircuito de `&&` / `||`:**  
  El resultado del nodo es `r10`. Esquema para `&&`: evaluar la izquierda, `MOV r10 ← izq`, `JUMPF izq → End_And` (si es falso, se saltea la derecha), evaluar la derecha, `MOV r10 ← der`, `LBL End_And`. Para `||` se usa `JUMPT → End_OR` y la misma estructura. El salto condicional testea el operando izquierdo, no el temporal.

- **Control de flujo con etiquetas generadas:**  
  Cada estructura se envuelve en `BLOCK`/`ENDBLOCK`. Los esquemas son:
  - `if`: evaluar condición → `copiarTo(aux)` → `JUMPF r10 → End_if` → cuerpo → `corregir(aux)` → `LBL End_if`;
  - `if/else`: condición → `copiarTo(aux2)` → `JUMPF r10 → Else` → cuerpo del `then` → `copiarTo(aux3)` → restaurar el contador de memoria → `JUMP → End_if` → `LBL Else` → `copiarFrom(aux2)` → cuerpo del `else` → `corregir(aux2)` y `corregir(aux3)` → `LBL End_if`;
  - `while`: `blockear()` → `BLOCK` → `LBL While` → condición → `JUMPF r10 → End_While` → cuerpo → `JUMP While` → `LBL End_While` → `ENDBLOCK` → `desblockear()`.

  Los generadores (`endIf`, `idElse`, `idWhile`, `endWhile`, `endOr`, `endAnd`, ...) numeran las etiquetas para que sean únicas ante anidamiento (`End_if`, `End_if1`, ...).

- **Funciones: parámetros, llamadas y retorno:**  
  Al entrar a una función se reinicia `cant_memoria_necesaria = 0`. Cada parámetro recibe un slot y se copia desde su registro de argumento: los primeros seis van en `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`; del séptimo en adelante se reciben por stack con `MOV param ← TOP índice` (en assembly: `mov 16*índice(%rbp), %r11` y luego al slot del parámetro). Los parámetros **no** pasan por `registrar`: viven siempre en memoria.

  La llamada evalúa los argumentos, los pasa por registro (`MOV rdi/rsi/... ← arg`) o con `PUSH` a partir del séptimo, guarda una foto de los registros, derrama los vivos con `liberarTodo`, emite `CALL función`, copia el resultado con `MOV temporal ← RET`, hace un `POP` por cada argumento que fue por stack y recarga los registros con `recuperar`. El temporal del resultado se crea con `registro_siguiente()` pero **no** se registra, así que vive en memoria.

  `return expr` emite `MOV RET ← expr` + `RET`; `return;` emite solo `RET`.

- **Declaraciones `extern`:**  
  Un método externo se representa con `NODE_EXT_MET_DECLARATION` y en el IR emite `LBLE`, que no genera assembly: la resolución del nombre queda para el linker. La llamada se hace con `CALL` y termina siendo `call nombre`.

- **Optimizaciones del AST (`optimLit.c`):**  
  Antes de generar el IR se ejecutan dos pasadas:
  - `optimizarCalculosLiterales`: pliega operaciones con dos literales (`2+3*4 → 14`, `1 > 2 → false`, `!true → false`, etc.) y simplifica `&&`/`||` cuando un operando es el literal absorbente (`a && false → false`, `a || true → true`).
  - `optimizarCaminos`: si la condición quedó siendo `NODE_VAL_FALSE`, elimina el `if`/`while` completo (no ejecuta el cuerpo); si es `NODE_VAL_TRUE`, en un `if` conserva el cuerpo del `then` y en un `if/else` también; y en un `if/else` con condición `false` conserva la rama `else`. Solo actúa sobre condiciones que en el AST son literalmente `true` o `false`; no hay propagación de constantes entre variables.

  El orden importa: primero se pliega y después se podan los caminos, para que, por ejemplo, `if (1 > 2)` también se elimine.

- **Menos unario se convierte en resta:**  
  La regla de `-` unario no tiene instrucción propia: en la acción semántica se construye `SUB(cero, operando)` con un literal `0` del mismo tipo numérico (`-x` ==> `0 - x`), reusando el camino de `NODE_OP_SUB` en `armarPila`.

---

## Documentación — Etapa 5

Las tareas fueron principalmente realizadas en conjunto durante los horarios de clases. La etapa consistió en traducir el código intermedio de la etapa 4 a assembly nativo de GNU/Linux x86-64 (`asm_gen.c`) y en armar la suite de tests de la etapa.

### Decisiones de diseño

- **Sintaxis de GNU vía `charear`:** `asm_gen.c` recorre la lista de instrucciones y por cada operando llama a `charear`, que traduce un `Symbol` del IR a sintaxis AT&T:
  - literal (sin nombre) → `$valor`;
  - `isFuction == 1` (función) → `nombre`;
  - `isFuction == 2` (variable global) → `nombre(%rip)`;
  - `isFuction == 3` (temporal lógico) → `-offset(%rbp)`;
  - `RET` → `%rax`;
  - nombres de registros reconocidos (`rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`, `r10`, `r12`–`r15`) → `%nombre`;
  - todo lo demás (locales, parámetros, temporales ya derramados) → `-offset(%rbp)`.

  `%r11` se usa directamente en el texto generado como registro scratch (por ejemplo, para mover memoria a memoria), pero no aparece como símbolo del IR.

- **Variables globales en `.bss`:** los símbolos con `isFuction == 2` se emiten al principio del `.s` como `.globl nombre`, `nombre:` y `.space 8`. Cuando una global está en memoria, `charear` la referencia como `nombre(%rip)`. Si el register manager le dio un registro, el acceso usa el registro y solo se escribe/lee la global en los derrames.

- **Frame con `enter`/`leave` y slots de 8 bytes:** `calcular_frames` recorre el IR función por función, toma el máximo `offset` que aparece en cualquier operando entre un `LBL` de función y el siguiente, lo redondea a 16 bytes y lo guarda en el símbolo de la función. El `LBL` de una función emite `.globl`, la etiqueta y `enter $N, $0`; `RET` emite `leave; ret`. El IR asigna offsets de 8 bytes por temporal, por parámetro y por declaración local. El frame se alinea a 16, de modo que las llamadas sin argumentos por stack quedan alineadas; los `push` de argumentos no ajustan la alineación, así que con un número impar de argumentos apilados la alineación ABI no se mantiene (el código generado no usa instrucciones que la requieran).

- **Parámetros: 6 por registro, el resto por stack:** los primeros 6 argumentos van en `rdi, rsi, rdx, rcx, r8, r9`; del séptimo en adelante se pasan con `push` en orden izquierda→derecha y el callee los lee en `16(%rbp)`, `32(%rbp)`, ... (`16 × índice`), sin red zone. El call emite tantos `POP` (que en assembly son `add $8, %rsp`) como argumentos hubo por stack.

- **Aritmética:** `ADD` y `SUB` operan directamente sobre el destino cuando es posible (`emitir_op`), sin pasar siempre por `%rax`; si origen y destino son ambos memoria, usan `%r11` como puente. `MUL` mueve el primer factor a `%rax`, usa `imul` (con el segundo factor por `%r11` si es un literal) y guarda `%rax` en el destino. `DIV` mueve el dividendo a `%rax`, extiende el signo con `cqto`, usa `idiv` (divisor por `%r11` si es literal) y guarda `%rax`. `MOD` hace lo mismo pero guarda `%rdx`.

- **Comparaciones en `%r10`:** `LESS`, `GREAT` y `EQUAL` cargan los operandos en `%rax` y `%rbx`, hacen `cmp %rbx, %rax` y usan `jl`, `jg` o `je` para dejar `1` o `0` en `%r10` (no se usan `setl`/`setg`/`sete`). `JUMPF` y `JUMPT` cargan el operando en `%r10` si hace falta, hacen `cmp $1, %r10` y saltan con `jne`/`je`. La negación (`XOR` del IR) invierte con `xor $1, %r10`.

- **Resultado de `CALL` guardado en un temporal:** el call emite `call nombre` y después `mov %rax, -temp(%rbp)` (vía `MOV temporal ← RET`). A diferencia de usar directamente `RET`, esto hace que dos llamadas anidadas como `fib(n-1) + fib(n-2)` no se pisen. Alrededor del `CALL` se derraman y recargan los registros vivos, y se descartan los argumentos que fueron por stack.

- **Saltos locales del ensamblador:** los saltos cortos de las comparaciones usan labels numéricos locales (`1:` y `1f`), que no ensucian el espacio de símbolos globales. Las etiquetas del IR (`While`, `End_if`, `Else`, funciones) se emiten como labels en el orden del IR.

- **Tests de la etapa (`tests_asm/`):** por cada programa se verifican tres cosas: (1) que el `.s` se ensamble con `gcc -Wall -Werror -Wa,--fatal-warnings` (cero errores y cero warnings del ensamblador), (2) que linkee (incluye el externo con stub) y (3) que el binario ejecute y devuelva el exit code esperado (aritmética, división con signo, `if`/`while`, booleanos, llamadas de 1 y 7 argumentos, recursión). Además se chequea selección de instrucciones y detalles puntuales: `imul`, un `cqto` por cada división, `idiv %r11` cuando el divisor es literal, `xor $1` para la negación, `jne Else`/`jmp End_if` y las etiquetas de `if`/`while`, `%rdi` para el primer argumento, `push` y `add $8, %rsp` para el séptimo, `mov 16(%rbp), %r11` para el parámetro recibido por stack, `enter`, `.globl`, `.text` y `.note.GNU-stack`. Los tests de la etapa 4 se actualizaron a los opcodes actuales (`CALL`, `LBLE`, y las comparaciones como `LESS`, `GREAT` y `EQUAL`).

### Limitaciones conocidas

- **`float` solo existe en el chequeo de tipos.** El lexer convierte `LIT_FLOAT` con `atoi` y el codegen usa instrucciones enteras (`cmp`, `idiv`, etc.), así que no hay promoción ni aritmética de punto flotante real.
- **Los tests de assembly cubren como máximo un argumento por stack.** Con más de un argumento apilado, el orden de lectura en el callee no coincide con el orden de los `push` del invocador.
- **Las declaraciones múltiples comparten offset.** En una declaración como `int a, b, c;`, `NODE_DECLARATION` incrementa `cant_memoria_necesaria` una sola vez, así que todos los IDs reciben el mismo `offset = 8 * cant_memoria_necesaria`. Si se derraman a memoria, escriben y leen el mismo slot. Declarar cada variable por separado evita el problema.
