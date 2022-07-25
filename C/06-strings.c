#include <stdio.h>

int main() {

    char cad[5] = {'H','o','l','a','\0'};
    // Un arreglo de caracteres

    printf("String: %s\n\n",cad);

    char cad2[] = "Hola mundo";
    printf("String 2: %s\n",cad2);
    printf("Tamano del string 2: %i\n\n",sizeof(cad2));

    printf("Indice:\tValor:\tASCII:\n");
    for (int i = 0; i < sizeof(cad2); i++) {
        printf("%i\t%c\t%i\n",i,cad2[i],cad2[i]);
    }
    // Tener en cuenta el ultimo caracter, es el caracter nulo.

    return 0;
}
