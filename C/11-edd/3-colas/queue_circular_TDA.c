#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Este archivo puede incluirse de forma individual en cualquier
// programa en el que se necesiten Colas.

// ##################################
// #          ATENCION              #
// ##################################
// Para fines de demostracion, se puso el limite del arreglo
// a 5, por favor, si se va a implementar, cambiar este numero
// a 1000000 o coasas malas podrian pasar!!
#define MAX_SIZE 5
#define INVALID_ELEMENT INT_MIN



// ====================
// CREACION DEL TDA
// ====================

// Vamos a suponer que los elementos de la Cola van a ser 'ints'
typedef int tElemCola;

// Se define la estructura "Cola", en este caso, basada en un arreglo
typedef struct {

    unsigned int maxSize; // El tamaño maximo del arreglo

    unsigned int queueSize; // La cantidad de elementos que hay en la cola

    unsigned int front; // El comienzo de la cola

    unsigned int back; // El fin de la cola

    tElemCola* queueArray; // El arreglo en donde se van a guardar los elementos
} tCola;



// ====================
// CREACION DE INTERFAZ
// ====================

// Inicializador de Cola. Asigna memoria.
void initQueue(tCola *L) {
    L->maxSize = MAX_SIZE;
    L->queueSize = 0;
    L->front = 0;
    L->back = 0;
    L->queueArray = (tElemCola*)malloc(L->maxSize * sizeof(tElemCola));
}

// Borrar Cola. Libera memoria.
void deleteQueue(tCola *L) {
    free(L->queueArray);
}



// Insertar elemento al final de la cola
int enqueue(tCola *L, tElemCola item) {
    // Si el tamaño de la Cola ya es el maximo posible, entonces no agrega nada
    if (L->queueSize >= L->maxSize) {
        return 0;
    }

    // Si el final de la cola llega al limite del arreglo, entonces recircula
    if (L->back == L->maxSize) {
        L->back = 0;
    }

    // Al final, se inserta el elemento deseado
    L->queueArray[L->back] = item;
    L->queueSize++;
    L->back++;
    return 1;

}

// Elimina el elemento al frente de la cola
tElemCola dequeue(tCola *L) {
    // Asegurarse de que no se pueden eliminar elementos si no hay nada en la Cola
    if (L->queueSize == 0) {
        return INVALID_ELEMENT;
    }

    // Se guarda el elemento inicial para despues retornarlo
    tElemCola item = L->queueArray[L->front];

    // El frente aumenta un puesto
    L->front++;

    // Si el frente llega al limite del arreglo, entonces recircula
    if (L->front == L->maxSize) {
        L->front = 0;
    }

    // Al final, el tamaño de la Cola disminuye
    L->queueSize--;
    return item;
}

// Limpiar Cola
void clear(tCola *L) {
    //Liberar y volver a declarar
    free(L->queueArray);
    L->queueSize = 0;
    L->front = 0;
    L->back = 0;
    L->queueArray = (tElemCola*)malloc(L->maxSize * sizeof(tElemCola));
}

// Retorna el elemento al frente de la cola
tElemCola frontValue(tCola *L) {
    // Si la lista esta vacia, entonces retorna invalido
    if (L->queueSize == 0) {
        return INVALID_ELEMENT;
    }
    return L->queueArray[L->front];
}

// Retorna el tamaño de la Cola
int size(tCola *L) {
    return L->queueSize;
}



// Imprimir Cola
void printQueue(tCola *L) {
    printf("\n=^========::COLA::==========\n");
    printf("Front pos:%i\tBack pos:%i\n",L->front,L->back);
    printf("Pos:\tVal:\tLen:%i\tFront:%i\n",size(L),frontValue(L));

    int pos = L->front;
    for (int i = 0; i < size(L); i++) {
        if (pos == L->front) {
            printf(">%i\t%i\n",pos,L->queueArray[pos]);
        } else {
            printf("%i\t%i\n",pos,L->queueArray[pos]);
        }
        pos++;
        if (pos >= L->maxSize) {
            pos = 0;
        }
    }

    printf("=^==========================\n\n");
}
