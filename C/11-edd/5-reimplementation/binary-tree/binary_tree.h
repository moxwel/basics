#ifndef __BINARY_TREE__
#define __BINARY_TREE__

// ====================

#include <stdio.h>
#include <stdlib.h>

/**
 * Tipo de dato: Elementos del arbol.
 *
 * Definido como: int
 **/
typedef int tABBElem;

/**
 * Tipo de dato: Nodo de arbol.
 *
 * Celdas:
 * - info : Elemento a guardar
 * - izq : Puntero al nodo hijo izquierdo
 * - der : Puntero al nodo hijo derecho
 **/
typedef struct ABBNode{
    tABBElem info;
    struct ABBNode *izq;
    struct ABBNode *der;
} tABBNode;

/**
 * Tipo de dato: EDD Arbol Binario.
 *
 * Celdas:
 * - root : Puntero al nodo raiz
 * - size : Cantidad de elementos guardados
 **/
typedef struct {
    tABBNode* root;
    int size;
} tABB;

// Operaciones de inicializacion

tABB* newABB();

void deleteABB();

// Operaciones de recorrido

void preOrden();

void inOrden();

void postOrden();

// Operaciones de elemento

void insert();

int remove();

void clearABB();

void setValue();

// Operaciones de obtencion

tABBElem getValue();

int getSize();

int find();

// ====================

#endif
