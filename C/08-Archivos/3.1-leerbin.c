#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1;
    file1 = fopen("binarios.dat","r");
    if (file1 == NULL) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }

    int   leer1;
    float leer2;
    char  leer3;

    int exito1 = fread(&leer1, sizeof(leer1), 1, file1);
    int exito2 = fread(&leer2, sizeof(leer2), 1, file1);
    int exito3 = fread(&leer3, sizeof(leer3), 1, file1);
    // Los datos binarios no pueden leerse de forma normal
    // Retorna un int con la cantidad de datos escritas

    printf("Datos leidos: %i\n",exito1 + exito2 + exito3);
    printf("Dato 1 leido: %i\n",leer1);
    printf("Dato 2 leido: %f\n",leer2);
    printf("Dato 3 leido: %c\n",leer3);

    if ((exito1 == 0) || (exito2 == 0) || (exito3 == 0)) {
        printf("No se leyo ningun dato.\n");
    }

    fclose(file1);

    return 0;
}
