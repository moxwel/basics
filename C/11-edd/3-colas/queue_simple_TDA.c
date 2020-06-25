#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Este archivo puede incluirse de forma individual en cualquier
// programa en el que se necesiten Colas.
#define MAX_SIZE 1000000
#define INVALID_ELEMENT INT_MIN



// ====================
// CREACION DEL TDA
// ====================

// Vamos a suponer que los elementos de la Cola van a ser 'ints'
typedef int tElemCola;

// Se define la estructura "Cola", en este caso, basada en un arreglo
typedef struct {

    unsigned int maxSize; // El tamaño maximo del arreglo

    unsigned int listSize; // EL tamaño de la "porcion del arreglo" que se esta utilizando

    tElemCola* queueArray; // El arreglo en donde se van a guardar los elementos
} tCola;



// ====================
// CREACION DE INTERFAZ
// ====================

// Inicializador de Cola. Asigna memoria.
void initQueue(tCola *L) {
    L->maxSize = MAX_SIZE;
    L->listSize = 0;
    L->queueArray = (tElemCola*)malloc(L->maxSize * sizeof(tElemCola));
}

// Borrar Cola. Libera memoria.
void deleteQueue(tCola *L) {
    free(L->queueArray);
}



// Insertar elemento al final de la cola
int enqueue(tCola *L, tElemCola item) {
    // Si el tamaño de la Cola ya es el maximo posible, entonces no agrega nada
    if (L->listSize >= L->maxSize) {
        return 0;
    }

    // Al final, se inserta el elemento deseado
    L->queueArray[L->listSize] = item;
    L->listSize++;
    return 1;
}

// Elimina el elemento al frente de la cola
tElemCola dequeue(tCola *L) {
    // Asegurarse de que no se pueden eliminar elementos si no hay nada en la Cola
    if (L->listSize == 0) {
        return INVALID_ELEMENT;
    }

    // Se guarda el elemento inicial para despues retornarlo
    tElemCola item = L->queueArray[0];

    // Hay que mover todos los elementos despues del cursor una casilla mas a la izquierda
    for (int i = 0; i < (L->listSize - 1); i++) {
        L->queueArray[i] = L->queueArray[i+1];
    }

    // Al final, el tamaño de la Cola disminuye
    L->listSize--;
    return item;
}

// Limpiar Cola
void clear(tCola *L) {
    //Liberar y volver a declarar
    free(L->queueArray);
    L->listSize = 0;
    L->queueArray = (tElemCola*)malloc(L->maxSize * sizeof(tElemCola));
}

// Retorna el elemento al frente de la cola
tElemCola frontValue(tCola *L) {
    // Si la lista esta vacia, entonces retorna invalido
    if (L->listSize == 0) {
        return INVALID_ELEMENT;
    }
    return L->queueArray[0];
}

// Retorna el tamaño de la Cola
int size(tCola *L) {
    return L->listSize;
}



// Imprimir Cola
void printQueue(tCola *L) {
    printf("\n=^========::COLA::==========\n");
    printf("Pos:\tVal:\tLen:%i\tFront:%i\n",size(L),frontValue(L));

    for (int i = 0; i < size(L); i++) {
        if (i == 0) {
            printf(">%i\t%i\n",i,L->queueArray[i]);
        } else {
            printf("%i\t%i\n",i,L->queueArray[i]);
        }
    }

    printf("=^==========================\n\n");
}
