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

/**
 * Crear arbol nuevo.
 * Debe asignarse a una variable tABB*.
 **/
tABB* newABB();

void deleteABB();

// Operaciones de recorrido

void preOrden();

void inOrden();

void postOrden();

// Operaciones de elemento

/**
 * Insertar elemento en el arbol.
 *
 * Retornos:
 * 1 - Exito
 * 0 - Sin exito (ya existe el elemento)
 **/
int insert(tABB *T, tABBElem item);
/**
 * [Funcion auxiliar recursiva]
 * Inserta elemento en un nodo.
 *
 * Se utiliza para recorrer por nodo.
 *
 * Retornos:
 * 1 - Exito
 * 0 - Sin exito (ya existe el elemento)
 **/
int insertAux(tABBNode* node, tABBElem item);

int remove();

void clearABB();

/**
 * Crear nuevo nodo con un elemento.
 * Debe asignarse a una variable tABBNode*.
 **/
tABBNode* newNode(tABBElem item);

void setValue();

// Operaciones de obtencion

/**
 * Obtener el valor de un nodo.
 **/
tABBElem getValue(tABBNode* node);

int getSize();

int find();

// ====================

#endif
