// Cada archivo .go debe empezar con la linea: package nombre_paquete

// Un paquete es un conjunto de archivos .go en un directorio. Es equivalente
// a un namespace en otros lenguajes de programación, o a un módulo en Python,
// o a un paquete en Java.
package main

// Para importar paquetes se usa la palabra reservada "import"

// "fmt" es un paquete que contiene funciones para formatear texto
import "fmt"

// "fmt" posee el método "Println" que imprime en consola con un salto de línea

// "main" es una función especial que se ejecuta al correr el programa
func main() {
	fmt.Println("Hola Mundo!")
}

// Para compilar y ejecutar el programa se usa el comando "go run" (mas sencillo).

// Para compilar el programa se usa el comando "go build", esto genera un archivo ejecutable.
