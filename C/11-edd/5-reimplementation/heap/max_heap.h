#ifndef __MAX_HEAP__
#define __MAX_HEAP__

// ====================

#include <stdio.h>
#include <stdlib.h>

/**
 * Tipo de dato: Elementos del heap.
 *
 * Definido como: int
 **/
typedef int tHeapElem;

/**
 * Tipo de dato: Max-Heap.
 *
 * Celdas:
 * - heap : Arreglo donde se van a guardar elementos
 * - size : Tamano maximo del heap
 * - nElems : Cantidad de elementos guardados
 **/
typedef struct {
    tHeapElem* heap;

    int size;
    int nElems;
} tHeap;

// Operaciones de inicializacion

/**
 * Crear heap nuevo.
 * Debe asignarse a una variable tHeap*.
 **/
tHeap* newHeap();

void deleteHeap(tHeap* H);

// Operaciones de elemento

/**
 * Insertar elemento en el heap.
 **/
void pushHeap(tHeap* H, tHeapElem item);

void popHeap(tHeap* H);

void clearHeap(tHeap* H);

// Operaciones de obtencion

/**
 * Obtiene el primer elemento del heap.
 * En Max-Heap, seria el mayor elemento.
 **/
tHeapElem topHeap(tHeap* H);

/**
 * Obtiene el numero de elementos que contiene el heap
 **/
int getSize(tHeap* H);

// Operaciones auxiliares

/**
 * Aumentar el tamano del arreglo.
 * Se añade un nuevo nivel al pseudo arbol.
 **/
void growHeap(tHeap* H);

/**
 * Intercambiar elementos del arreglo.
 * Se intercambia el elemento item1 con item2.
 **/
void swapElems(tHeap* H, int item1, int item2);



/**
 * Imprimir heap.
 **/
void printHeap(tHeap* H);

// ====================

#endif
