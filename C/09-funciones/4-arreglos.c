#include <stdio.h>

int total(int* arr, int n) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }

    return suma;
}

int main() {
    int lista[5] = {5,3,139,12,41};
    // Como un arreglo es un puntero basicamente
    int sumTot = total(lista, 5);

    printf("Suma total: %i\n",sumTot);

    return 0;
}
