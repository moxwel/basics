#include <stdio.h>
#include <string.h>

#include "universal_list.h"

// Retorna el tamaño de un string
int sLen(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// Retorna 1 (true) si el string dado es palindromo
int esPalindromo(char *s) {
    tList* pl = newList();

    char temp[(sLen(s)+1)];

    // Poner los caracteres dentro de la pila
    for (int i = 0; i < sLen(s); i++) {
        push(pl,s[i]);
        // printList(pl);
    }

    // Al sacarlos, el orden seria el inverso
    // Al guardarlos en otro arreglo, tendriamos el string al reves
    for (int i = 0; i < sLen(s); i++) {
        temp[i] = topValue(pl);
        pop(pl);
        // printList(pl);
    }

    deleteList(pl);

    temp[sLen(s)] = '\0';

    //printf("%s - %s, %i\n",s,temp,strcmp(s,temp)==0);

    // Si los strings son iguales, entonces strcmp() retornara 0
    // 0 == 0 retorna 1

    if (strcmp(s,temp) == 0) {
        printf("\"%s\" SI es palindromo.\n",s);
    } else {
        printf("\"%s\" NO es palindromo.\n",s);
    }

    return (strcmp(s,temp) == 0);
}

int main() {
    char *s1 = "anitalavalatina";
    char *s2 = "reconocer";
    char *s3 = "sardinas";
    char *s4 = "sus";
    char *s5 = "palindromo";

    esPalindromo(s1);
    esPalindromo(s2);
    esPalindromo(s3);
    esPalindromo(s4);
    esPalindromo(s5);

    return 0;
}
