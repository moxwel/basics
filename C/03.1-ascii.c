#include <stdio.h>

int main() {

    char c1 = 'a';
    char c2 = 'A';

    printf("Caracter: %c %c\n",c1,c2);
    printf("Caracter: %i %i\n",c1,c2);
    // El placeholder %i esta interpretando un char como un numero.
    // En este caso, toma el codigo ASCII del caracter.

    return 0;
}
