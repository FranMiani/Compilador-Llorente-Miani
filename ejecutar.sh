#!/bin/bash

bison -d parser.y;
flex lexer.l;
gcc lex.yy.c parser.tab.c compilador.c -o compilador;
./compilador programa.txt;