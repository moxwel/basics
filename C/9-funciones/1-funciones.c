#include <stdio.h>

// Esta funcion recibe dos parametros y retorna un int
int suma(int num1, int num2) {
    int resultado = num1 + num2;
    return resultado;
}

int main() {
    int a = 5, b = 3;

    int res = suma(a,b);

    printf("Resultado: %i\n",res);

    return 0;
}
