#include <stdio.h>
#include <stdlib.h>
#include "./ABB_TDA.c"


int main() {
    tABB mi_arbol;
    tABB *pa = &mi_arbol;


    initABB(pa);

    insert(pa, 10);
    insert(pa, 6);
    insert(pa, 19);
    insert(pa, 8);
    insert(pa, 11);
    insert(pa, 9);
    insert(pa, 15);
    insert(pa, 3);
    insert(pa, 21);

    removeNode(pa,19);
    removeNode(pa,15);

    preOrden(pa);



    return 0;
}
