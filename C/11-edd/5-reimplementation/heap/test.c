#include <stdio.h>
#include <stdlib.h>

#include "max_heap.h"

int main() {

    tHeap* miHeap = newHeap();

    pushHeap(miHeap, 1);
    pushHeap(miHeap, 2);
    pushHeap(miHeap, 3);
    pushHeap(miHeap, 4);
    pushHeap(miHeap, 2);
    pushHeap(miHeap, 1);
    pushHeap(miHeap, 5);
    pushHeap(miHeap, 6);
    pushHeap(miHeap, 4);


    printHeap(miHeap);

    printf("%d\n", isHeapEmpty(miHeap));

    clearHeap(miHeap);

    printf("%d\n", isHeapEmpty(miHeap));

    deleteHeap(miHeap);

    return 0;
}
