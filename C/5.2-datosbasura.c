#include <stdio.h>

int main() {

    int arr[5] = {5, 32, 144, 2020, 19};

    printf("Indice:\tValor:\n");
    for (int i = 0; i < 5; i++) {
        printf("%i\t%i\n",i,arr[i]);
    }
    printf("Nos pasamos de largo...\n");
    for (int i = 5; i < 10; i++) {
        printf("%i\t%i\n",i,arr[i]);
    }


    return 0;
}
