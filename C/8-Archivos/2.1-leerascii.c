#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1;
    file1 = fopen("lorem.txt","r");
    if (file1 == NULL) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }

    char buffer[15];

    char caract = fgetc(file1);
    printf("Caracter leido: %c\n", caract);
    caract = fgetc(file1);
    printf("Caracter leido: %c\n", caract);
    caract = fgetc(file1);
    printf("Caracter leido: %c\n\n", caract);

    fgets(buffer,15,file1);
    printf("String leido: %s\n",buffer);
    fgets(buffer,15,file1);
    printf("String leido: %s\n\n",buffer);

    printf("Leer string:\n");
    while ((caract = fgetc(file1)) != EOF) {
        printf("%c",caract);
    }
    printf("\n");

    fclose(file1);

    return 0;
}
