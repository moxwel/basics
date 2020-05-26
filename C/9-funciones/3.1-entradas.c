#include <stdio.h>

int main() {

    int a, b, c;

    scanf("%i %i %i",&a,&b,&c);
    // Como se sabe, es necesario utilizar una direccion de memoria
    // para modificar variables desde una funcion.

    printf("Datos introducidos:\nVar:\tVal:\na\t%i\nb\t%i\nc\t%i\n",a,b,c);

    return 0;
}
