#include <stdio.h>

void suma(int n1, int n2, int* r) {
    printf("---\n");
    printf("Valor de parametro r: %p\n",r);
    printf("Valor de referencia r: %i\n\n",*r);

    *r = n1 + n2;
    // Cambio de valor desde puntero

    printf("Valor de referencia r: %i\n",*r);
    printf("---\n");
}

int main() {
    int numero1, numero2, resultado;

    numero1 = 5;
    numero2 = 15;
    resultado = 0;

    printf("Direccion de resultado: %p\n",&resultado);
    printf("Valor de resultado (antes de func): %i\n",resultado);

    suma(numero1, numero2, &resultado);

    printf("Valor de resultado (despues de func): %i\n",resultado);

    return 0;
}
