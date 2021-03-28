#include <stdio.h>
#include <stdlib.h>

#include "max_heap.h"

int main(){
    int numeros[] = {4,3,2,1,2,4,6,7,8,9};

    tHeap* h = newHeap();
    for(int i = 0; i < 10; i++) pushHeap(h, numeros[i]);

    printHeap(h);

    while(!isHeapEmpty(h)){
        printf("%d ", topHeap(h));
        popHeap(h);
        printHeap(h);
        printf("\n");
    }


    deleteHeap(h);

    return 0;
}
