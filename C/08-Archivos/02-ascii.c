#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("archivo1.txt","a");
    // Modo "w" de write para escribir
    if (fp == NULL) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }

    char nomb[] = "Maximiliano";

    fprintf(fp, "Hola mundo. Soy %s.",nomb);

    fclose(fp);

    return 0;
}
