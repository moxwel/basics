#include <stdio.h>

int main() {

    char cad[] = "Hola mundo";
    // El tamaño del arreglo es 10 + 1 (por el \0) = 11

    printf("Tamano del string: %i\n",sizeof(cad));
    printf("Indice:\tValor:\tASCII:\n");
    for (int i = 0; i < 30; i++) {
        printf("%i\t%c\t%i\n",i,cad[i],cad[i]);
    }
    // Despues del indice 10, todo es dato basura, lo que
    // haya estado antes en memoria en ese momento.

    return 0;
}
