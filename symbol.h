#ifndef SYMBOL
#define SYMBOL

typedef enum {
    INT1, BOOL1, FLOAT1, NOT_TYPE, VOID1
} ExprType;

typedef struct Symbol {
    ExprType exprType;
    int value; 
    char *name;
    int isFuction;
    struct Symbol *next;
} Symbol;

#endif