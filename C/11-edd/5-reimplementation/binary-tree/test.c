// gcc -c binary_tree.c test.c && gcc binary_tree.o test.o && ./a.out

#include <stdio.h>

#include "binary_tree.h"

int main() {
    tABB* miArbol = newABB();

    printf("%d ", insert(miArbol, 4));
    printf("%d\n", getSize(miArbol));
    printf("%d ", insert(miArbol, 6));
    printf("%d\n", getSize(miArbol));
    printf("%d ", insert(miArbol, 5));
    printf("%d\n", getSize(miArbol));
    printf("%d ", insert(miArbol, 6));
    printf("%d\n", getSize(miArbol));
    printf("%d ", insert(miArbol, 4));
    printf("%d\n", getSize(miArbol));
    printf("%d ", insert(miArbol, 8));
    printf("%d\n", getSize(miArbol));
    printf("%d ", insert(miArbol, 7));
    printf("%d\n", getSize(miArbol));
    printf("%d ", insert(miArbol, 3));
    printf("%d\n", getSize(miArbol));


    return 0;
}
