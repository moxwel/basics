#include <stdio.h>

int main() {

    int entero = 54;
    float flot = 3.14;
    char caract = 'a';
    int *punt = &entero;
    char cadena[] = "Hola mundo";

    printf("Podemos poner:\n");
    printf("%%i entero:\t%i\n",entero);
    printf("%%f flotante:\t%f\n",flot);
    printf("%%c caracter:\t%c\n",caract);
    printf("%%p puntero:\t%p\n",punt);
    printf("%%s string\t%s\n\n",cadena);

    printf("Podemos poner un entero %i y un flotante %f a la vez.\n",entero,flot);

    return 0;
}
