#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Este archivo puede incluirse de forma individual en cualquier
// programa en el que se necesiten pilas.

// Como los elementos se van a guardar en un arreglo, significa que tienen un tamaño maximo
// Suponemos que el tamaño maximo de la Pila es 'MAX_SIZE'
#define MAX_SIZE 1000000
#define INVALID_ELEMENT INT_MIN



// ====================
// CREACION DEL TDA
// ====================

// Vamos a suponer que los elementos de la Pila van a ser 'ints'
typedef int tElemPila;

// Se define la estructura "Pila", en este caso, basada en un arreglo
typedef struct {

    unsigned int maxSize; // El tamaño maximo del arreglo

    unsigned int top; // EL tamaño de la "porcion del arreglo" que se esta utilizando

    tElemPila* stackArray; // El arreglo en donde se van a guardar los elementos

    // Unsigned significa "sin signo", no hay negativos. Tiene logica ya que los indices
    // de los arreglos son desde el 0 en adelante.
} tPila;



// ====================
// CREACION DE INTERFAZ
// ====================

// Inicializador de Pila. Asigna memoria.
void initStack(tPila *L) {
    L->maxSize = MAX_SIZE;
    L->top = 0;
    L->stackArray = (tElemPila*)malloc(L->maxSize * sizeof(tElemPila));
}

// Borrar Pila. Libera memoria.
void deleteStack(tPila *L) {
    free(L->stackArray);
}




// Agregar un elemento al tope de la Pila (retorna la cantidad de elementos insertados)
int push(tPila *P, tElemPila item) {
    // Si el tamaño de la Pila ya es el maximo posible, entonces no agrega nada
    if (P->top >= P->maxSize) {
        return 0;
    }

    // Agrega un elemento al tope de la pila
    P->stackArray[P->top] = item;
    P->top++;
    return 1;
}

// Elimina el elemento del tope de la pila (retorna el valor eliminado)
tElemPila pop(tPila *P) {
    // Asegurarse de que no se pueden eliminar elementos si no hay nada en la Pila
    if (P->top == 0) {
        return INVALID_ELEMENT;
    }

    // Se guarda el ultimo elemento para despues retornarlo
    tElemPila item = P->stackArray[P->top - 1];


    // Al final, el tamaño de la Pila disminuye
    P->top--;
    return item;
}

// Limpiar Pila
void clear(tPila *P) {
    //Liberar y volver a declarar
    free(P->stackArray);
    P->top = 0;
    P->stackArray = (tElemPila*)malloc(P->maxSize * sizeof(tElemPila));
}

// Retorna el valor del tope de la pila
tElemPila topValue(tPila *P) {
    // Revisar si la pila esta vacia
    if (P->top == 0) {
        return INVALID_ELEMENT;
    }

    return P->stackArray[P->top-1];
}

// Retorna el tamaño de la Pila
int size(tPila *P) {
    return P->top;
}



// Imprimir Pila
void printStack(tPila *P) {
    printf("\n==========::PILA::==========\n");
    printf("Pos:\tVal:\tSize:%i\tTop:%i\n",size(P),topValue(P));

    for (int i = 0; i < size(P); i++) {
        if (i == P->top-1){
            printf(">%i\t%i\n",i,P->stackArray[i]);
        } else {
            printf("%i\t%i\n",i,P->stackArray[i]);
        }
    }

    printf("=^==========================\n\n");
}
