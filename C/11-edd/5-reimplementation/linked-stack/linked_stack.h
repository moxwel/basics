#ifndef __LINKED_LIST__
#define __LINKED_LIST__

// ====================

#include <stdio.h>
#include <stdlib.h>

/**
 * Tipo de dato: Elementos de la pila.
 *
 * Definido como: int
 **/
typedef int tStackElem;

/**
 * Tipo de dato: Nodo de pila.
 *
 * Celdas:
 * - info : Elemento a guardar
 * - sig : Puntero al nodo siguiente
 **/
typedef struct StackNode{
    tStackElem info;
    struct StackNode *sig;
} tStackNode;

/**
 * Tipo de dato: EDD Pila.
 *
 * Celdas:
 * - head : Puntero al primer nodo
 * - tail : Puntero al ultimo nodo
 * - curr : Puntero al nodo actual
 * - pos : Posicion del cursor
 * - len : tamano de la lista
 **/
typedef struct {
    tStackNode* head;
    tStackNode* tail;
    int len;
} tStack;

// Operaciones de inicializacion

/**
 * Crear pila nueva.
 * Debe asignarse a una variable tStack*.
 **/
tStack* newStack();

/**
 * Eliminar pila.
 * Libera toda la memoria.
 **/
void deleteStack(tStack* S);

// Operaciones de elemento

/**
 * Adjuntar elemento en la lista.
 * Se va a insertar al final de la lista.
 **/
void push(tStack* S, tStackElem item);

/**
 * Eliminar elemento de la lista.
 * Se va a eliminar el elemento despues del cursor.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (lista vacia)
 **/
int pop(tStack* S);

/**
 * Limpiar lista.
 * Todos los elementos se borran.
 **/
void clearStack(tStack* S);

// Operaciones de cursor








// Operaciones de obtencion

/**
 * Obtiene el valor del elemento siguiente al cursor.
 * Si el cursor esta al final, se obtiene el valor actual.
 **/
tStackElem topValue(tStack* S);

/**
 * Obtiene el valor del tamano de la lista.
 **/
int getLength(tStack* S);



/**
 * Imprimir lista.
 **/
void printStack(tStack* L);


// ====================

#endif
