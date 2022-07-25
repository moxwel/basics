#include <stdio.h>

void func(int var) {
    var = 60;
    printf("Valor variable (FUNC): %i\n",var);

    // Las variables despues de terminar la funcion se destruyen
}

int main() {
    int var = 15;

    printf("Valor variable (MAIN): %i\n",var);
    func(var);
    printf("Valor variable (MAIN): %i\n",var);

    // Las variabes pasadas como parametros
    // dentro de funciones son copias, es decir,
    // no pueden modificar variables que estan
    // fuera del main.

    return 0;
}
