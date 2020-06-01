#include <stdio.h>
#include <stdlib.h>

// Como los elementos se van a guardar en un arreglo, significa que tienen un tamaño maximo

// Suponemos que el tamaño maximo de la lista es 'MAX_SIZE'
#define MAX_SIZE 1000000

// ==========
// CREACION DEL TDA

// Vamos a suponer que los elementos de la lista van a ser 'ints'
typedef int tElemLista;

// Se define la estructura "Pila", en este caso, basada en un arreglo
typedef struct {
    unsigned int maxSize; // El tamaño maximo de la pila
    unsigned int top; // Ubicacion del cursor, es decir, el ultimo elemento
    tElemLista* stackArray; // El arreglo en donde se van a guardar los elementos

    // Unsigned significa "sin signo", no hay negativos. Tiene logica ya que los indices
    // de los arreglos son desde el 0 en adelante.
} tPila;

// ==========
// CREACION DE INTERFAZ


// ==========

int main() {
    return 0;
}
