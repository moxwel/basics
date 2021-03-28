// Compilar de forma separada:
// gcc -c max_heap_debug.c

#include "max_heap.h"

tHeap* newHeap() {
    printf("[newHeap] Creando heap nuevo. Asignando memoria...\n");

    // Asignar memoria para el TDA
    tHeap* H = (tHeap*)malloc(sizeof(tHeap));

    H->size = 1;
    H->nElems = 0;

    // Asignar memoria para el arreglo (dos celdas, el primero es vacio)
    H->heap = (tHeapElem*)malloc(sizeof(tHeapElem)*(H->size + 1));

    return H;
}

void pushHeap(tHeap* H, tHeapElem item) {
    printf("[pushHeap] Insertando elemento al final de la lista...\n");

    // Insertar elemento justo al final del arreglo.
    int insert = H->nElems + 1;

    // Si el lugar que se va a insertar supera el tamano maximo, aumentar tamano
    if (insert > H->size) {
        printf("[pushHeap] Se superó el tamano maximo. Hay que aumentar el tamano...\n");
        growHeap(H);
    }

    printf("[pushHeap] Asignando elemento en posicion %d...\n", insert);
    H->heap[insert] = item;

    // Se puede busacar el padre solo si no es la raiz del arbol (indice 1)
    while (insert > 1) {
        // El nodo padre en un arreglo heap esta dado por el indice del nodo dividido en 2
        int padre = insert / 2;

        printf("[pushHeap] Revisando el padre del nodo %d. Posicion del padre: %d.\n", insert, padre);

        // Si el elemento insertado es mayor que su padre, hay que intercambiar los nodos.
        if (H->heap[insert] > H->heap[padre]) {
            printf("[pushHeap] El insertado es mayor que el padre, hay que intercambiar.\n");
            swapElems(H, insert, padre);
        } else {
            printf("[pushHeap] El elemento no es mayor que el padre. No hacer nada.\n");
        }

        insert = padre;
    }

    H->nElems++;
}

void growHeap(tHeap* H) {
    printf("[growHeap] Aumentando tamano del heap: %d --> %d...\n", H->size, ((H->size * 2) + 1));

    H->size = (H->size * 2) + 1;

    // Se añade 1 mas al size por el elemento vacio extra. Vease newHeap()
    H->heap = (tHeapElem*)realloc(H->heap, sizeof(tHeapElem)*(H->size + 1));

    return;
}

void swapElems(tHeap* H, int item1, int item2) {
    printf("[swapElems] Intercambiando indice %d con %d...\n", item1, item2);

    tHeapElem temp = H->heap[item1];

    H->heap[item1] = H->heap[item2];

    H->heap[item2] = temp;

    return;
}

tHeapElem topHeap(tHeap* H) {
    return H->heap[1];
}

int getSize(tHeap* H) {
    return H->nElems;
}

int isHeapEmpty(tHeap* H) {
    return (H->nElems == 0);
}

void printHeap(tHeap* H) {
    printf("-----HEAP-----\nTop: %d - nElems: %d - Size: %d\n", topHeap(H), getSize(H), H->size);

    for (int i = 1; i <= H->nElems; i++) {
        printf("[%d] %d\n", i, H->heap[i]);
    }
    printf("==============\n");
}

void clearHeap(tHeap* H) {
    printf("[clearHeap] Limpiando heap...\n");

    // Ilusion: El heap no tiene ningun elemento.
    H->nElems = 0;

    // Cambiar el primer elemento para cambiar el topHeap()
    H->heap[1] = 0;

    return;
}

void deleteHeap(tHeap* H) {
    printf("[deleteHeap] Liberando memoria...\n");
    free(H->heap);
    free(H);
    return;
}
