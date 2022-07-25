#include <stdio.h>

int main() {

    struct mi_struct{
        int dat1;
        float dat2;
        char dat3;
    };

    struct mi_struct mi_arr[2];

    mi_arr[0].dat1 = 13;
    mi_arr[0].dat2 = 3.1415;
    mi_arr[0].dat3 = 'A';

    mi_arr[1].dat1 = 321;
    mi_arr[1].dat2 = 41.45;
    mi_arr[1].dat3 = 'C';

    for (int i = 0; i < 2; i++) {
        printf("Indice: %i\n",i);
        printf("Dato 1: %i\n",mi_arr[i].dat1);
        printf("Dato 2: %f\n",mi_arr[i].dat2);
        printf("Dato 3: %c\n\n",mi_arr[i].dat3);
    }

    return 0;
}
