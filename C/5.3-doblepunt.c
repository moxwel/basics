#include <stdio.h>

int main()
{


    int my_arr[3] = {43,7,21};

    printf("Indice:\tValor:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%i\t%i\n",i,my_arr[i]);
    }

    // Matriz
    int my_arr2[3][2] = {{10,11},{20,21},{30,31}};

    printf("\nIndice:\tValor:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%i-%i\t%i\n",i,j,my_arr2[i][j]);
        }
    }

    return 0;
}
