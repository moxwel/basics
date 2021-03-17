#ifndef __LINKED_LIST__
#define __LINKED_LIST__

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
 * - sig : Puntero al nodo siguiente
 **/
typedef struct ListNode{
    tListElem info;
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

    // Se usa unsigned para que los valores de int lleguen hasta 4294967295
} tList;

/**
 * Imprimir lista.
 **/
void printList(tList* L);

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
void clear(tList* L);

/**
 * Mover cursor hacia el siguiente elemento.
 **/
void next(tList* L);

/**
 * Mover cursor al elemento anterior.
 **/
void prev(tList* L);

// ====================

#endif
