// Compilar de forma separada:
// gcc -c max_heap.c

#include "max_heap.h"

tHeap* newHeap() {
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
    // Insertar elemento justo al final del arreglo.
    int insert = H->nElems + 1;

    // Si el lugar que se va a insertar supera el tamano maximo, aumentar tamano
    if (insert > H->size) {
        growHeap(H);
    }

    H->heap[insert] = item;

    // Se puede busacar el padre solo si no es la raiz del arbol (indice 1)
    while (insert > 1) {
        // El nodo padre en un arreglo heap esta dado por el indice del nodo dividido en 2
        int padre = insert / 2;

        // Si el elemento insertado es mayor que su padre, hay que intercambiar los nodos.
        if (H->heap[insert] > H->heap[padre]) {
            swapElems(H, insert, padre);
        } else {
            break;
        }

        insert = padre;
    }

    H->nElems++;
}

void growHeap(tHeap* H) {
    H->size = (H->size * 2) + 1;

    // Se añade 1 mas al size por el elemento vacio extra. Vease newHeap()
    H->heap = (tHeapElem*)realloc(H->heap, sizeof(tHeapElem)*(H->size + 1));
}

void swapElems(tHeap* H, int item1, int item2) {
    // No hacer nada si se intenta intercambiar el mismo elemento.
    if (item1 == item2) {
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
    // Ilusion: El heap no tiene ningun elemento.
    H->nElems = 0;

    // Cambiar el primer elemento para cambiar el topHeap()
    H->heap[1] = 0;
}

void deleteHeap(tHeap* H) {
    free(H->heap);
    free(H);
}

void popHeap(tHeap* H) {
    // Si el heap esta vacio, no hacer nada
    if (H->nElems == 0) {
        return;
    }

    int actual = 1;

    // Sustituir la raiz con la ultima hoja del heap y eliminar la hoja.
    swapElems(H, actual, H->nElems);
    H->nElems--;

    // Si el heap se vacia, entonces cambiar el primer elemento para cambiar el topHeap() y terminar
    if (H->nElems == 0) {
        H->heap[1] = 0;
        return;
    }

    // Los hijos del nodo actual se definen de esta manera
    int izq = 2 * actual;
    int der = (2 * actual) + 1;

    // Si es que el nodo actual tiene al menos un hijo...
    while (izq <= H->nElems) {
        // Si el hijo izquierdo es mayor que el hijo derecho (o no hay hijo derecho), hay que revisar el izquierdo
        if ((H->heap[izq] > H->heap[der]) || (der > H->nElems)) {
            // Si el hijo izquierdo es mayor que el nodo actual, entonces el hijo izquierdo debe subir.
            if (H->heap[izq] > H->heap[actual]) {
                swapElems(H, izq, actual);
                actual = izq;
            } else {
                // Si el hijo ya no es mayor que el actual, entonces terminar.
                return;
            }
        }
        // Si el hijo derecho es mayor que el hijo izquierdo, hay que revisar el derecho
        else {
            // Si el hijo derecho es mayor que el nodo actual, entonces el hijo derecho debe subir.
            if (H->heap[der] > H->heap[actual]) {
                swapElems(H, der, actual);
                actual = der;
            } else {
                // Si el hijo ya no es mayor que el actual, entonces terminar.
                return;
            }
        }

        // Ahora se calcula los nuevos hijos del nodo
        izq = 2 * actual;
        der = (2 * actual) + 1;
    }
}
