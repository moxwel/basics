#include <stdio.h>

int main() {

    int arr[5] = {5, 32, 144, 2020, 19};

    printf("Indice:\tValor:\n");
    for (int i = 0; i < 5; i++) {
        printf("%i\t%i\n",i,arr[i]);
    }

    printf("\nDireccion arreglo: %p\n\n",arr);
    // El nombre del arreglo es una direccion
    // de memoria en si (al primer elemento).
    // Usar los corchetes es equivalente a desreferenciar.

    printf("Indice:\tDirecc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%i\t%p\n",i,&arr[i]);
    }
    // Los datos se guardan uno al lado del otro en memoria

    return 0;
}
