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

/**
 * Eliminar arbol.
 * Libera toda la memoria.
 **/
void deleteABB(tABB* T);

// Operaciones de recorrido

/**
 * Recorrer el arbol en pre-orden.
 **/
void preOrden(tABB* T);
/**
 * [Funcion auxiliar recursiva]
 * Recorrer el arbol en pre-orden.
 *
 * Se utiliza para recorrer por nodo.
 **/
void preOrdenAux(tABBNode* node);

/**
 * Recorrer el arbol en in-orden.
 **/
void inOrden(tABB* T);
/**
 * [Funcion auxiliar recursiva]
 * Recorrer el arbol en in-orden.
 *
 * Se utiliza para recorrer por nodo.
 **/
void inOrdenAux(tABBNode* node);

/**
 * Recorrer el arbol en post-orden.
 **/
void postOrden(tABB* T);
/**
 * [Funcion auxiliar recursiva]
 * Recorrer el arbol en post-orden.
 *
 * Se utiliza para recorrer por nodo.
 **/
void postOrdenAux(tABBNode* node);

// Operaciones de elemento

/**
 * Insertar elemento en el arbol.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (ya existe el elemento)
 **/
int insertNode(tABB *T, tABBElem item);
/**
 * [Funcion auxiliar recursiva]
 * Inserta elemento en un nodo.
 *
 * Se utiliza para recorrer por nodo.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (ya existe el elemento)
 **/
int insertAux(tABBNode* node, tABBElem item);

/**
 * Borrar elemento del arbol.
 *
 * Retornos:
 * - 1 : Exito
 * - 0 : Sin exito (no existe el elemento)
 **/
int removeNode(tABB* T, tABBElem item);
/**
 * [Funcion auxiliar recursiva]
 * Borrar un nodo.
 *
 * Se utiliza para recorrer por nodo.
 *
 * Sin retornos, pues, solo se accedera cuando el elemento exista.
 **/
void removeAux(tABB* T, tABBNode* node, tABBNode* penult, tABBElem item);

/**
 * Limpiar arbol.
 * Todos los elementos se borran.
 **/
void clearABB(tABB* T);

/**
 * Crear nuevo nodo con un elemento.
 * Debe asignarse a una variable tABBNode*.
 **/
tABBNode* newNode(tABBElem item);

// Operaciones de obtencion

/**
 * Obtener el valor de un nodo.
 **/
tABBElem getValue(tABBNode* node);

/**
 * Obtener el tamano del arbol.
 **/
int getSize(tABB* T);

/**
 * Buscar un elemento en el arbol.
 *
 * Retornos:
 * - 1 : Exito (existe)
 * - 0 : Sin exito (no existe)
 **/
int findNode(tABB* T, tABBElem item);
/**
 * [Funcion auxiliar recursiva]
 * Buscar un elemento en un nodo.
 *
 * Se utiliza para recorrer por nodo.
 *
 * Retornos:
 * - 1 : Exito (existe)
 * - 0 : Sin exito (no existe)
 **/
int findAux(tABBNode* node, tABBElem item);

/**
 * Retorna el nodo sucesor desde uno dado.
 *
 * Retornos:
 * - tABBNode* : Nodo sucesor al dado
 **/
tABBNode* sucesor(tABBNode* node);

// ====================

#endif
