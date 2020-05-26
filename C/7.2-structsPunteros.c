#include <stdio.h>

int main() {

    struct mi_struct{
        int dat1;
        float dat2;
        char dat3;
    };

    struct mi_struct mi_var;

    mi_var.dat1 = 13;
    mi_var.dat2 = 3.1415;
    mi_var.dat3 = 'A';

    struct mi_struct *mi_punt = &mi_var;
    // Puntero a tipo "struct mi_struct"

    printf("Direccion de variable: %p\n",mi_punt);
    printf("Dato 1: %i\n", mi_var.dat1);

    printf("Dato 2: %f\n", (*mi_punt).dat2);
    printf("Dato 3: %c\n", mi_punt->dat3);
    // Desreferenciar variable


    return 0;
}
