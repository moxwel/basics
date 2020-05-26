#include <stdio.h>
#define N 5
// Cualquier cosa que coincida con la
#include "./exp.c"

int main() {

    int b = N;
    int e = 7;

    printf("%i elevando a %i: %i\n",b,e,exponente(b,e));

    return 0;
}
