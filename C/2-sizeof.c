#include <stdio.h>

int main() {
    printf("Tipo:\tBytes\n");
    printf("Int\t%li\n",sizeof(int));
    printf("Float\t%li\n",sizeof(float));
    printf("Char\t%li\n",sizeof(char));
    printf("Long\t%li\n",sizeof(long));
    printf("Pointer\t%li\n",sizeof(int*));

    return 0;
}
