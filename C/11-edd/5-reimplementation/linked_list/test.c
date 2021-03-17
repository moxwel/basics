#include <stdio.h>

#include "linked_list.h"

int main() {
    tList* a = newList();printList(a);

    insert(a, 321);printList(a);
    insert(a, 1533426);printList(a);
    insert(a, 132);printList(a);
    append(a, 9999);printList(a);
    insert(a, 321);printList(a);
    insert(a, 1533426);printList(a);
    insert(a, 132);printList(a);
    append(a, 9999);printList(a);

    next(a);printList(a);
    next(a);printList(a);
    next(a);printList(a);
    next(a);printList(a);
    next(a);printList(a);

    deleteList(a);

    return 0;
}
