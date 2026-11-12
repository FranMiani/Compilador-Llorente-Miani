#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "instruccion.h"
#include "symbol.h"

#include "symbol_table.h"
#define LEN 4
typedef enum {
    R12,
    R13,
    R1LEN,
    R15
}registrosLibres;

char* regName2(int i);
void inicializarRegs();
void blockear();
void desblockear();
int searchReg(Symbol *symbol);
Symbol* buscarRegistro(Symbol *symbol);
Symbol* use(Symbol* symbol);
void liberarTodo(Pila* pila);
int contarAp(Symbol* symbol, Node* node);
void contarApAux(Node* node, int i);
void contarAparicionesRestantes(Node* node, Symbol* symbol);
int contarTemps(Node* node, Symbol* symbol);
int contarTempAux(Node* node, int i);
void contarTemporales(Node* node, Symbol* symbol);
void aparicionDeTemporal();
void aparicionDeVar(Symbol* symbol);
void aparicion(Symbol* symbol);
int liberarRegistroTo(Pila* pila, Symbol* sym, Node* node);
Symbol* registrar(Symbol* symbol, Pila* pila, Node* node);
void copy(Symbol* origen[LEN], Symbol* destino[LEN]);
void copiarFrom(Symbol* origen[LEN]);
void copiarTo(Symbol* destino[LEN]);
void recuperar(Symbol* origen[LEN], Pila* pila);

void corregir(Symbol* aux[LEN]);
