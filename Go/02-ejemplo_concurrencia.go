package main

import (
	"fmt"
	"sync"
)

// El paquete "sync" provee primitivas para sincronización de concurrencia.

// Go es un lenguaje fuertemente tipado, se debe especificar el tipo de cada variable.

// Primero va el nombre de la variable, luego el tipo de la variable.

func decir_algo(text string, wg *sync.WaitGroup) {
	// "text" es una variable de tipo string.
	// "wg" es un puntero a un objeto de tipo "sync.WaitGroup".
	// "sync.WaitGroup" es un objeto que agrupa "goroutines" (se hace uso del paquete "sync").
	// Una "goroutine" es una función que se ejecuta en paralelo con otras funciones.

	// "defer" es una palabra reservada que ejecuta una función al final de la función actual.
	defer wg.Done()
	// El metodo "Done" de un "sync.WaitGroup" indica que la "goroutine" ha terminado, y
	// decrementa el contador de "goroutines" ejecutandose en el "sync.WaitGroup".

	fmt.Println(text)
}

// "main" es la funcion que se va a ejecutar al correr el programa.
func main() {
	// Para crear una variable es: "var nombre_variable tipo_variable"
	var wg sync.WaitGroup

	// La variable "wg" sera un objeto que agrupará "goroutines". Con esta variable seremos capaces
	// de ejecutar multiples instancias de una funcion en paralelo.

	// El metodo "Add" de un "sync.WaitGroup" incrementa el contador de "goroutines" ejecutandose en el "sync.WaitGroup".
	// Se debe llamar a "Add" antes de ejecutar una "goroutine", para decir que se añade una tarea a la cola de dicho "sync.WaitGroup"..
	wg.Add(1)

	// Para ejecutar una "goroutine" se usa la palabra reservada "go" seguida de la funcion a ejecutar.
	go decir_algo("Hola", &wg)
	// Se hace pasar la direccion de memoria de la variable "wg" a la funcion.
	// La funcion lo recibe como un puntero.

	// El metodo "Wait" de un "sync.WaitGroup" bloquea la ejecución del programa hasta que todas las "goroutines" terminen.
	// Es decir, hasta que el contador de "goroutines" llegue a 0. Para ello, cada "goroutine" debe llamar a "Done" una vez terminen.
	wg.Wait()
}
