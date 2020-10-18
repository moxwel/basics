#include <stdio.h>
#include <stdbool.h> // True o False

// A compare function that is used for searching an integer
// array
bool comparar (void* a, void* b) {
    return ( *(int*)a == *(int*)b );
}

// General purpose search() function that can be used
// for searching an element *x in an array arr[] of
// arr_size. Note that void pointers are used so that
// the function can be called by passing a pointer of
// any type. ele_size is size of an array element

//     arreglo,  tamaño arreglo,  tamaño elementos, elemento a buscar,   funcion de comparacion
int search(void *arr, int arr_size, int ele_size, void *x, bool (*comp_func)(void* , void*)) {
	// Considerando que char almancena solo 1 bit, podriamos usarlo
    // para poder movernos entre el arreglo, teniendo en cuenta el tamaño
    // de un elemento individual de este.
	char* ptr = (char*)arr;
    // 'ptr' va a tener la direccion del primer byte del primer elemento de 'arr'

	for (int i = 0; i < arr_size; i++) {

        // Como vamos a ir viendo byte por byte, es necesario tener que avanzar la cantidad
        // correcta de bytes segun el tipo de datos que estamos ordenando.

        // En el caso de 'int', habria que avanzar 4 bytes (ele_size).
		if (comp_func(  ptr + i*ele_size  ,  x  )) {
		    return i;
        }
    }

	// If element not found
	return -1;
}

int main()
{
	int arr[] = {2, 5, 7, 90, 70};

    // Cantidad de elementos (20/4 = 5)
	int n = sizeof(arr)/sizeof(arr[0]);

    // 7 estara en el arreglo 'arr'?
	int x = 7;

	printf ("El indice donde se encuentra es: %d \n", search(arr, n, sizeof(int), &x, comparar));

	return 0;
}
