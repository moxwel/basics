#ifndef __LINKED_QUEUE__
#define __LINKED_QUEUE__

// ====================

#include <stdio.h>
#include <stdlib.h>

/**
 * Tipo de dato: Elementos de la cola.
 *
 * Definido como: int
 **/
typedef int tQueueElem;

/**
 * Tipo de dato: Nodo de cola.
 *
 * Celdas:
 * - info : Elemento a guardar
 * - sig : Puntero al nodo siguiente
 **/
typedef struct QueueNode{
    tQueueElem info;
    struct QueueNode *sig;
} tQueueNode;

/**
 * Tipo de dato: EDD Cola.
 *
 * Celdas:
 * - head : Puntero al primer nodo
 * - tail : Puntero al ultimo nodo
 * - len : Tamano de la cola
 **/
typedef struct {
    tQueueNode* head;
    tQueueNode* tail;
    int len;
} tQueue;

// Operaciones de inicializacion

/**
 * Crear cola nueva.
 * Debe asignarse a una variable tQueue*.
 **/
tQueue* newQueue();

/**
 * Eliminar cola.
 * Libera toda la memoria.
 **/
void deleteQueue(tQueue* Q);

// Operaciones de elemento

/**
 * Insertar elemento en cola.
 * Se va a insertar al final de la cola.
 **/
void enqueue(tQueue* Q, tQueueElem item);

/**
 * Eliminar elemento de la cola.
 * Se va a eliminar el primer elemento que se agrego.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (cola vacia)
 **/
int dequeue(tQueue* Q);

/**
 * Limpiar cola.
 * Todos los elementos se borran.
 **/
void clearQueue(tQueue* Q);

// Operaciones de obtencion

/**
 * Obtiene el valor del primer elemento que se agrego
 **/
tQueueElem frontValue(tQueue* Q);

/**
 * Obtiene el valor del tamano de la cola.
 **/
int getLength(tQueue* Q);


/**
 * Imprimir cola.
 **/
void printQueue(tQueue* Q);

// ====================

#endif
