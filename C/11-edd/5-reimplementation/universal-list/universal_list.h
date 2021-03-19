#ifndef __UNIVERSAL_LIST__
#define __UNIVERSAL_LIST__

// ====================

#include <stdio.h>
#include <stdlib.h>

/**
 * Tipo de dato: Elementos de la lista.
 *
 * Definido como: int
 **/
typedef int tListElem;

/**
 * Tipo de dato: Nodo de lista.
 *
 * Celdas:
 * - info : Elemento a guardar
 * - ant : Puntero al nodo anterior
 * - sig : Puntero al nodo siguiente
 **/
typedef struct ListNode{
    tListElem info;
    struct ListNode *ant;
    struct ListNode *sig;
} tListNode;

/**
 * Tipo de dato: EDD Lista.
 *
 * Celdas:
 * - head : Puntero al primer nodo
 * - tail : Puntero al ultimo nodo
 * - curr : Puntero al nodo actual
 * - pos : Posicion del cursor
 * - len : tamano de la lista
 **/
typedef struct {
    tListNode* head;
    tListNode* tail;
    tListNode* curr;
    int pos;
    int len;
} tList;

// Operaciones de inicializacion

/**
 * Crear lista nueva.
 * Debe asignarse a una variable tList*.
 **/
tList* newList();

/**
 * Eliminar lista.
 * Libera toda la memoria.
 **/
void deleteList(tList* L);

// Operaciones de elemento

/**
 * Insertar elemento en lista.
 * Se va a insertar despues del cursor.
 **/
void insert(tList* L, tListElem item);

/**
 * Adjuntar elemento en la lista.
 * Se va a insertar al final de la lista.
 **/
void append(tList* L, tListElem item);

/**
 * Eliminar elemento de la lista.
 * Se va a eliminar el elemento despues del cursor.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (lista vacia)
 **/
int erase(tList* L);

/**
 * Limpiar lista.
 * Todos los elementos se borran.
 **/
void clearList(tList* L);

// Operaciones de cursor

/**
 * Mover cursor hacia el siguiente elemento.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (final de la lista)
 **/
int next(tList* L);

/**
 * Mover cursor al elemento anterior.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (comienzo de la lista)
 **/
int prev(tList* L);

/**
 * Mover cursor a posicion determinada.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (invalido)
 **/
int moveToPos(tList* L, int target);

/**
 * Mover cursor al inicio de la lista.
 **/
void moveToStart(tList* L);

/**
 * Mover cursor al final de la lista.
 **/
void moveToEnd(tList* L);

// Operaciones de obtencion

/**
 * Obtiene el valor del elemento siguiente al cursor.
 * Si el cursor esta al final, se obtiene el valor actual.
 **/
tListElem getValue(tList* L);

/**
 * Obtiene el valor del tamano de la lista.
 **/
int getLength(tList* L);

/**
 * Obtiene el valor de la posicion del cursor.
 **/
int getPos(tList* L);

// Operaciones de pila

/**
 * Agregar elemento a la pila.
 * Se va a insertar al final de la lista.
 **/
void push(tList* L, tListElem item);

/**
 * Eliminar elemento de la pila.
 * Se va a eliminar el ultimo elemento de la lista.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (lista vacia)
 **/
int pop(tList* L);

/**
 * Obtiene el valor del ultimo elemento de la lista.
 **/
tListElem topValue(tList* L);

// Operaciones de cola

/**
 * Insertar elemento en cola.
 * Se va a insertar al final de la lista.
 **/
void enqueue(tList* L, tListElem item);

/**
 * Eliminar elemento de la cola.
 * Se va a eliminar el primer elemento de la lista.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (lista vacia)
 **/
int dequeue(tList* L);

/**
 * Obtiene el valor del primer elemento de la lista.
 **/
tListElem frontValue(tList* L);



/**
 * Imprimir lista.
 **/
void printList(tList* L);

// ====================

#endif
