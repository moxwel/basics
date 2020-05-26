#include <stdio.h>

int main() {

    int arr[5] = {5, 32, 144, 2020, 19};

    printf("Indice:\tValor:\n");
    for (int i = 0; i < 5; i++) {
        printf("%i\t%i\n",i,arr[i]);
    }

    arr[0] = 399010;
    arr[2] = 3621;
    // Modificar valores desde indices

    printf("\nIndice:\tValor:\n");
    for (int i = 0; i < 5; i++) {
        printf("%i\t%i\n",i,arr[i]);
    }

    return 0;
}
