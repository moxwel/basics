#include <stdio.h>

/**
 * int buscarMaximo
 ******
 * Busca el indice del elemento mas grande de un arreglo
 ******
 * Input:
 * int *A : Arreglo de enteros
 * int n : Cantidad de elementos del arreglo 'A'
 ******
 * Returns:
 * posMax : Indice en el arreglo 'A' donde se encuentra el elemento mas grande
 **/
int buscarMaximo(int *A, int n) {
    int posMax = 0;

    for (int i = 1; i < n; i++) {
        if (A[posMax] < A[i]) {
            posMax = i;
        }
    }

    return posMax;
}


int main() {
    int arr[99] = {4,2,5,1,4,3,2,2,2,2,2,2,22,2,2,2,2,2,1,43,4,321,43,14,3,214,32,14,3215,32,15,32,15,321,5,65,47,54,7,54,5,6,43,14,15,21,4,67,54,7,568,7,9,76,9,69,86,37,54,7,47,52,5643,265,436,54,7,453,754,37,54,375,437,543,43,26,43,26,3};
    int grande = buscarMaximo(arr,99);

    printf("En el indice %i se encuentra el mas grande.\n",grande);

    return 0;
}
