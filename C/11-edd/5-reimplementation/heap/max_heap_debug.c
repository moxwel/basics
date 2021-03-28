// Compilar de forma separada:
// gcc -c max_heap_debug.c

#include "max_heap.h"

tHeap* newHeap() {
    printf("[newHeap] Creando heap nuevo. Asignando memoria...\n");

    // Asignar memoria para el TDA
    tHeap* H = (tHeap*)malloc(sizeof(tHeap));

    H->size = 1;
    H->nElems = 0;

    // Asignar memoria para el arreglo (dos celdas, el primero [0] es vacio, el heap comienza en [1])
    H->heap = (tHeapElem*)malloc(sizeof(tHeapElem)*(H->size + 1));
    H->heap[1] = 0;

    return H;
}

void pushHeap(tHeap* H, tHeapElem item) {
    printf("[pushHeap] Insertando elemento al final de la lista...\n");

    // Insertar elemento justo al final del arreglo.
    int insert = H->nElems + 1;

    // Si el lugar que se va a insertar supera el tamano maximo, aumentar tamano
    if (insert > H->size) {
        printf("[pushHeap] Se superó el tamano maximo. Hay que aumentar la capacidad...\n");
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
            printf("[pushHeap] El insertado es mayor que el padre, hay que subirlo.\n");
            swapElems(H, insert, padre);
        } else {
            printf("[pushHeap] El elemento no es mayor que el padre. No hacer nada.\n");
            break;
        }

        insert = padre;
    }

    printf("[pushHeap] Aumentando nElems...\n");
    H->nElems++;
}

void growHeap(tHeap* H) {
    printf("[growHeap] Aumentando tamano maximo del heap: %d --> %d...\n", H->size, ((H->size * 2) + 1));

    H->size = (H->size * 2) + 1;

    // Se añade 1 mas al size por el elemento vacio extra. Vease newHeap()
    H->heap = (tHeapElem*)realloc(H->heap, sizeof(tHeapElem)*(H->size + 1));
}

void swapElems(tHeap* H, int item1, int item2) {
    printf("[swapElems] Intercambiando indice %d con %d...\n", item1, item2);

    // No hacer nada si se intenta intercambiar el mismo elemento.
    if (item1 == item2) {
        printf("[swapElems] Se esta intentando intercambiar el mismo elemento. No hacer nada.\n");
        return;
    }

    tHeapElem temp = H->heap[item1];

    H->heap[item1] = H->heap[item2];

    H->heap[item2] = temp;
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
}

void deleteHeap(tHeap* H) {
    printf("[deleteHeap] Liberando memoria...\n");
    free(H->heap);
    free(H);
}

void popHeap(tHeap* H) {
    // Si el heap esta vacio, no hacer nada
    if (H->nElems == 0) {
        printf("[popHeap] El heap esta vacio. No hacer nada.\n");
        return;
    }

    int actual = 1;

    printf("[popHeap] Intercambiando ultima hoja con raiz.\n");

    // Sustituir la raiz con la ultima hoja del heap y eliminar la hoja.
    swapElems(H, actual, H->nElems);

    printf("[popHeap] Borrando hoja. Disminuyendo nElems...\n");
    H->nElems--;

    // Si el heap se vacia, entonces cambiar el primer elemento para cambiar el topHeap() y terminar
    if (H->nElems == 0) {
        printf("[popHeap] Ya no hay elementos. Reiniciando topValue().\n");
        H->heap[1] = 0;
        return;
    }

    // Los hijos del nodo actual se definen de esta manera
    int izq = 2 * actual;
    int der = (2 * actual) + 1;

    // Si es que el nodo actual tiene al menos un hijo...
    while (izq <= H->nElems) {
        printf("[popHeap] El nodo actual tiene al menos un hijo.\n");

        printf("[popHeap] Revisando hijos del nodo actual... Act: %d - Izq: %d - Der: %d\n", actual, izq, der);

        // Si el hijo izquierdo es mayor que el hijo derecho (o no hay hijo derecho), hay que revisar el izquierdo
        if ((H->heap[izq] > H->heap[der]) || (der > H->nElems)) {
            printf("[popHeap] El hijo izquierdo es mayor que el hijo derecho. Revisar izquierdo...\n");
            // Si el hijo izquierdo es mayor que el nodo actual, entonces el hijo izquierdo debe subir.
            if (H->heap[izq] > H->heap[actual]) {
                printf("[popHeap] El hijo izquierdo es mayor al actual, hundir actual...\n");
                swapElems(H, izq, actual);
                actual = izq;
            } else {
                printf("[popHeap] El actual ya es mayor que su hijo, terminar...\n");
                // Si el hijo ya no es mayor que el actual, entonces terminar.
                return;
            }
        }
        // Si el hijo derecho es mayor que el hijo izquierdo, hay que revisar el derecho
        else {
            printf("[popHeap] El hijo derecho es mayor que el hijo izquierdo. Revisar derecho...\n");
            // Si el hijo derecho es mayor que el nodo actual, entonces el hijo derecho debe subir.
            if (H->heap[der] > H->heap[actual]) {
                printf("[popHeap] El hijo derecho es mayor al actual, hundir actual...\n");
                swapElems(H, der, actual);
                actual = der;
            } else {
                printf("[popHeap] El actual ya es mayor que su hijo, terminar...\n");
                // Si el hijo ya no es mayor que el actual, entonces terminar.
                return;
            }
        }

        // Ahora se calcula los nuevos hijos del nodo
        izq = 2 * actual;
        der = (2 * actual) + 1;
    }

    printf("[popHeap] Ya no hay mas hijos.\n");
}
