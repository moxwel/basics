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

    printHeap(miHeap);

    return 0;
}
