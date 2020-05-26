#include <stdio.h>

int main() {

    int ent = 543;
    int *pent = &ent;
    // El simbolo ampersand toma la ubicacion en memoria

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
