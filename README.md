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

Los scripts de test compilan el proyecto y pueden ejecutarse desde cualquier directorio del repositorio.

De forma manual:
```bash
bison -d parser.y
flex lexer.l
gcc lex.yy.c parser.tab.c compilador.c ast.c symbol_table.c -lfl -o compilador
./compilador programa.txt
```

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
  Dos tipos son compatibles si son iguales o si ambos son numéricos (`INT`/`FLOAT`). Un booleano nunca es compatible con un numérico. `comp()` se usa en la aritmética, las comparaciones, la asignación y el pasaje de parámetros.

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
