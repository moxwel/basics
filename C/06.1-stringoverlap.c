#include <stdio.h>

int main() {

    char cad[4] = {'H','o','l','a'};
    char cad2[6] = {'m','u','n','d','o','\0'};

    printf("Imprimir string 1: %s\n",cad);
    printf("Imprimir string 2: %s\n",cad2);
    // El placeholder %s va a recorrer todos los caracteres de
    // un string hasta encontrar el caracter nulo.

    return 0;
}
