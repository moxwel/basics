#include <stdio.h>
#include <stdlib.h>
#include "./queue_simple_TDA.c"


int main() {
    tCola mi_cola;
    tCola *pc = &mi_cola;

    printf("1-Inicializando pila...\n");
    initQueue(pc);
    printQueue(pc);

    printf("2-Agregando elementos a la pila...\n");
    enqueue(pc,1431);
    printQueue(pc);
    enqueue(pc,5321);
    printQueue(pc);
    enqueue(pc,432);
    printQueue(pc);
    enqueue(pc,8709);
    printQueue(pc);

    printf("3-Eliminando elemento %i...\n",dequeue(pc));
    printQueue(pc);
    printf("4-Eliminando elemento %i...\n",dequeue(pc));
    printQueue(pc);
    printf("5-Eliminando elemento %i...\n",dequeue(pc));
    printQueue(pc);
    printf("5-Eliminando elemento %i...\n",dequeue(pc));
    printQueue(pc);



    return 0;
}
