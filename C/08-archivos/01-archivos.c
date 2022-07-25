#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    // Descriptor: guarda la direccion de
    // memoria donde esta el archivo.

    fp = fopen("archivo1.txt","w");
    // Retorna una direccion de memoria que
    // apunta a un dato de tipo "FILE".
    // Retorna NULL si hay un error.

    if (fp == NULL) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }

    fclose(fp);
    // Cerrar archivo

    return 0;
}
