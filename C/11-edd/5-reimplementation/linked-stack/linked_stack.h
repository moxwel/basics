#ifndef __LINKED_STACK__
#define __LINKED_STACK__

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
 * - len : tamano de la pila
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
 * Agregar elemento a la pila.
 * Se va a insertar al final de la pila.
 **/
void push(tStack* S, tStackElem item);

/**
 * Eliminar elemento de la pila.
 * Se va a eliminar el ultimo elemento que se agrego.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (pila vacia)
 **/
int pop(tStack* S);

/**
 * Limpiar pila.
 * Todos los elementos se borran.
 **/
void clearStack(tStack* S);

// Operaciones de obtencion

/**
 * Obtiene el valor del ultimo elemento que se agrego.
 **/
tStackElem topValue(tStack* S);

/**
 * Obtiene el valor del tamano de la pila.
 **/
int getLength(tStack* S);



/**
 * Imprimir pila.
 **/
void printStack(tStack* L);


// ====================

#endif
