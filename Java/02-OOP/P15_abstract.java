/*
Una clase definida como abstracta, no se puede instanciar como tal, solamente se puede usar
creando subclases de este.

De la misma manera, se pueden decalrar metodos abstractas. Son como lo equivalentes
a los prototipos en C, funciones sin definicion.

Cualquier clase que tambien contenga metodos abstractos, tambien deberia declararse como abstracto.

Se utiliza la palabra clave 'abstract'
*/


// Se define una clase abstracta 'Animal', es decir, no se podran crear objetos de tipo 'Animal'
abstract class Animal {
    String especie;

    // Se declara este metodo abstracto, no tiene definicion
    abstract void accion();
    // Si se declara una subclase de 'Animal', esa clase necesariamente va a tener que definir este
    // metodo.
}


// Vamos a crear una subclase de 'Animal'
class Perro extends Animal {

    Perro() {
        especie = "Canino";
    }

    // Como en 'Animal' el metodo 'accion()' es abstracto, necesariamente debe definirse.
    void accion() {
        System.out.println("Woof.");
    }
}


public class P15_abstract {
    public static void main(String[] args) {
        // Animal a = new Animal();
        // No se puede instanciar un 'Animal' ya que es una clase abstracta

        Perro bob = new Perro();

        bob.accion();
    }
}
