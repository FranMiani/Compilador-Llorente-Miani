#!/bin/bash

bison -d parser.y;
flex lexer.l;
gcc lex.yy.c parser.tab.c compilador.c ast.c symbol_table.c instruccion.c -lfl -o compilador;
./compilador programa.txt;