#include <stdio.h>

int main() {

    int* pent, ent;
    // la variable "pent" sera un puntero, "ent" sera un int.
    ent = 3621;
    pent = &ent;

    printf("Valor de la variable:\t%i\n",ent);
    printf("Direccion de variable:\t%p\n\n",&ent);

    printf("Valor de puntero:\t%p\n",pent);
    printf("Direccion de puntero:\t%p\n",&pent);
    printf("Desref. de puntero:\t%i\n\n",*pent);

    *pent = 10;
    // Modificar la variale desde el puntero

    printf("Valor de la variable:\t%i\n",ent);

    return 0;
}
