#include <stdio.h>

// cantArg = Cantidad de argmentos
// argums = Arreglo de strings (arreglo de caracteres) que
//          almacenan los argumentos pasados.

// si se ejecuta como: a.out 34 1.14 hola
// cantArg = 4 (incluyendo el llamado al archivo)
// argums = [0] a.out
//          [1] 34
//          [2] 1.14
//          [3] hola

int main(int cantArg, char **argums) {

    printf("Cantidad de argumentos pasados: %i\n\n",cantArg);

    printf("Indice:\tArgum:\n");
    for (int i = 0; i < cantArg; i++) {
        printf("%i\t%s\n",i,argums[i]);
    }

    return 0;
}
