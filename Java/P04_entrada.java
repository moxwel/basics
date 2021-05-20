/*
- Un paquete es un conjunto de clases que pueden ser utilizadas en otras partes

- Se va a utilizar la clase 'Scanner' que se encuentra en el subpaquete 'util' del paquete 'java'

- 'java.util' es un paquete que contiene clases de utilidad
*/
import java.util.Scanner;



// Scanner sirve para poder obtener entrada del usuario desde la consola
public class P04_entrada {
    public static void main(String[] args) {
        String nombre;
        int x, y, suma;

        /*
        - Hay que crear un objeto de tipo Scanner

        - De igual forma, se debe mencionar el TIPO del objeto, e inicializarlo.

        - Para inicializar un objeto es necesario crearlo con 'new'

        - El parametro que recibe Scanner() es el origen de la entrada de datos,
          en este caso, es la entrada desde la consola.

        - Hay que llamar al objeto 'Scanner' que creamos anteriormente junto con
          un "metodo" para que nos pida ingresar datos. Segun el metodo que
          se utilice, se podra guaradr diferentes tipos de datos.
        */
        Scanner entrada = new Scanner(System.in);

        System.out.print("Ingrese su nombre: ");

        // 'next()' lee una unica palabra ingresada como String.
        // 'nextLine()' lee toda la linea ingresada como String.
        nombre = entrada.nextLine();
        System.out.println("Bienvenido a este programa, " + nombre + ".\n");



        System.out.print("Dame un numero: ");

        // 'nextInt()' lee un entero.
        x = entrada.nextInt();

        System.out.print("Dame otro numero: ");
        y = entrada.nextInt();

        suma = x + y;
        System.out.println("La suma entre los dos numeros " + x + " y " + y + " es " + suma);

        // Finalmente, hay que cerrar el escaner (recomendable)
        entrada.close();
    }
}
