#include <stdio.h>

int main()
{
    char *cadena = "Hola mundo";
    printf("%s\n\n",cadena);

    char *arr[4] = {"hola","mundo","gcc","progra"};
    printf("Indice:\tValor:\n");
    for (int i = 0; i < 4; i++) {
        printf("%i\t%s\n",i,arr[i]);
    }

    return 0;
}
