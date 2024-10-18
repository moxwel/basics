package main

import (
	"fmt"
	"sync"
	"time"
)

func tarea(id int, duracion time.Duration, wg *sync.WaitGroup) {
	defer wg.Done()
	fmt.Printf("Tarea %d: Empezando\n", id)
	time.Sleep(duracion)
	fmt.Printf("Tarea %d: Terminada\n", id)
}

func main() {
	var wg sync.WaitGroup
	numero_tareas := 5
	tareas_paralelo := 3

	duraciones_tareas := []time.Duration{1 * time.Second, 2 * time.Second, 3 * time.Second, 2 * time.Second, 1 * time.Second}

	for i := 0; i < numero_tareas; i++ {
		wg.Add(1)
		go tarea(i+1, duraciones_tareas[i], &wg)
		fmt.Printf("i: %d - i+1: %d - i mod tareas_paralelo: %d\n", i, i+1, (i+1)%tareas_paralelo)
		if (i+1)%tareas_paralelo == 0 {
			wg.Wait()
		}
	}
	fmt.Println("Fuera de bucle for")
	wg.Wait()
	fmt.Println("Todas las tareas han terminado")

}
