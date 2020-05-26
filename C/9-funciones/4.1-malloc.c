#include <stdio.h>
#include <stdlib.h>
// Para usar (type*)malloc() hay que incluir stdlib

// Funcion va a retornar un puntero (una direccion de memoria)
int* num_arr(int n) {
    int *lista = (int*)malloc(sizeof(int) * n);
    // Con malloc se asigna una direccion de memoria que no
    // se eliminara al terminar la funcion.
    // Asiganr direccion de memoria que apunta a un tipo "int"

    printf("Valor de lista (num_arr): %p\n",lista);

    for (int i = 0; i < n; i++) {
        lista[i] = i*5;
    }

    return lista;
}

int main() {

    int *arr = num_arr(10);

    printf("Valor de lista (main): %p\n",arr);

    printf("Indice:\tValor:\n");
    for (int i = 0; i < 10; i++) {
        printf("%i\t%i\n",i,arr[i]);
    }

    free(arr);
    // Es importante liberar la memoria

    return 0;
}
