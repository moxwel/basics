/*
La herencia nos permite poder obtener los atributos y metodos de otra clase padre.

Con la herencia, las clases se organizan de mejor manera y de forma jerarquica.

La clase que hereda/extiende otra clase se le llama 'subclase' o clase hijo
La clase del que se heredan otras clases se le llama 'superclase' o clase padre

Para heredar/extender una clase de otra clase padre, se usa la palabra clave 'extends'
*/


// Se crea una clase 'Animal', con propiedades generales que pueden aplicar a TODOS los animales
class Animal {

    // Recordemos el acceso 'protected':
    // Las celdas con 'protected' seran accesibles para las demas clases del mismo paquete, y ademas
    // tambien para las subclases (es util si una clase extiende otra clase de otro paquete).
    protected int patas;
    protected String especie;

    public void comer() {
        System.out.println("El " + especie + " come.");
    }
}


// La clase 'Perro' va a heredar las propiedades de la clase 'Animal'.
// 'Perro' es una subclase de 'Animal'
class Perro extends Animal {

    // Como 'Perro' lo estamos extendiendo desde 'Animal', singifica que 'Perro' tambien posee los
    // atributos 'patas' y 'especie'.

    // Pero ahora, estamos definiendo atributos nuevos, especificamente para los perros.
    private String nombre;
    public String raza;

    Perro(String n, String b) {
        patas = 4;
        especie = "Canino";
        nombre = n;
        raza = b;
    }

    // Como 'Perro' lo estamos extendiendo desde 'Animal', singifica que 'Perro' tambien posee el
    // metodo 'comer'.

    // Pero ahora, estamos un metodo nuevo, especificamente para los perros.
    public void ladrar() {
        System.out.println("Wow. Soy un perro, me llamo " + nombre + " y soy un " + raza + ".");
    }
}


// De la misma manera que 'Perro', la clase 'Gato' extiende a la clase 'Animal', es decir, va a heredar
// las mismas propiedades de 'Animal'
class Gato extends Animal {

    // Y de la misma manera, podemos definir caracteristicas especificas para los gatos.

    private String nombre;

    Gato(String n) {
        patas = 4;
        especie = "Felino";
        nombre = n;
    }

    public void maullar() {
        System.out.println("Miau. Soy un gato, me llamo " + nombre + ".");
    }
}


public class P12_herencia {
    public static void main(String[] args) {
        // Ahora en nuestro main, podemos declarar perros y gatos.

        Perro mi_perro = new Perro("Pepe", "Labrador");
        Gato mi_gato = new Gato("Botas");

        mi_perro.ladrar(); // Podemos usar metodos de la clase 'Perro'
        mi_perro.comer();  // Como tambien usar metodos de la clase 'Animal'

        mi_gato.maullar(); // Podemos usar metodos de la clase 'Gato'
        mi_gato.comer();   // Como tambien usar metodos de la clase 'Animal'
    }
}
