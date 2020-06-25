#include <stdio.h>
#include <stdlib.h>
#include "./stack_array_TDA.c"


int main() {
    tPila mi_pila;
    tPila *ps = &mi_pila;

    printf("1-Inicializando pila...\n");
    initStack(ps);
    printStack(ps);

    printf("2-Agregando elementos a la pila...\n");
    push(ps,1431);
    printStack(ps);
    push(ps,5321);
    printStack(ps);
    push(ps,432);
    printStack(ps);
    push(ps,8709);
    printStack(ps);

    printf("3-Eliminando elemento %i...\n",pop(ps));
    printf("4-Eliminando elemento %i...\n",pop(ps));
    printf("5-Eliminando elemento %i...\n",pop(ps));
    printf("5-Eliminando elemento %i...\n",pop(ps));
    printStack(ps);

    return 0;
}
