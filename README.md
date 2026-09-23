# Compilador-Llorente-Miani

Implementación del proyecto de la materia **Compiladores**.

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

## Compilación y ejecución

Para compilar y ejecutar con un archivo de prueba:
```bash
./ejecutar.sh
```

Para correr los tests sobre analisis sintactico y lexico:
```bash
./tests_sintaxis/run_tests.sh
```

De forma manual:
```bash
bison -d parser.y
flex lexer.l
gcc lex.yy.c parser.tab.c compilador.c -o compilador
./compilador programa.txt
```