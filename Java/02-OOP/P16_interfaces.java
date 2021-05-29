/*
Una interfaz es una clase abstracta, donde lo unico que contiene son metodos abstractos.

Una interfaz contiene
- Variables estaticas y finales
- Metodos abstractos y publicos

No contiene constructor, pues, es una clase abstracta, y no se puede instanciar.

Una interfaz puede heredar de otra interfaz.

Una clase puede implementar multiples interfaces.

La diferencia de la herencia de clases, una clases solo puede tener UNA SOLA clase padre. En cambio,
una clase puede implementar multiples interfaces.
*/


// Vamos a definir una interfaz llamada 'Acciones'
interface Acciones {

    // Todas estas funciones son abstractas y publicas de por si
    void saludar();
    void despedirse();
}


// Aqui estamos creando una clase que va a implementar la interfaz de 'Acciones'
// Es decir, la clase 'Persona' tiene que definir y hacer uso de los metodos de 'Acciones'
class Persona implements Acciones {
    String nombre;
    int edad;

    Persona(String n, int a) {
        nombre = n;
        edad = a;
    }

    // Aqui definimos ambos metodos de la interfaz
    public void saludar() {
        System.out.println("Hola, me llamo " + nombre + ".");
    }

    public void despedirse() {
        System.out.println("Adios.");
    }
}


public class P16_interfaces {
    public static void main(String[] args) {
        Persona max = new Persona("Max", 20);

        max.saludar();
        max.despedirse();
    }
}
