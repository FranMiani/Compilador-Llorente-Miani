#include <stdio.h>
int print(int x){
    printf("%d", x);
    return 0;
}
int getInt(){
    int x=0;
    scanf("%d", &x);
    return x;
}