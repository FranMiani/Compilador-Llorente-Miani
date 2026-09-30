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
