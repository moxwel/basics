#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1;
    file1 = fopen("binarios.dat","w");
    if (file1 == NULL) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }

    int   escr1 = 123454321;
    float escr2 = 3.1415;
    char  escr3 = 'b';

    int exito1 = fwrite(&escr1, sizeof(escr1), 1, file1);
    // Los datos binarios no pueden leerse de forma normal
    // Retorna un int con la cantidad de datos escritas
    int exito2 = fwrite(&escr2, sizeof(escr2), 1, file1);
    int exito3 = fwrite(&escr3, sizeof(escr3), 1, file1);

    printf("Datos escritos: %i\n",exito1 + exito2 + exito3);

    if ((exito1 == 0) || (exito2 == 0) || (exito3 == 0)) {
        printf("No se escribio ningun dato.\n");
    }

    fclose(file1);

    return 0;
}
