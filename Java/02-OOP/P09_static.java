/*
Un mimebro de una clase (ya sea un metodo o un atributo) definido con 'static', significa que esa
caracteristica pertenece A LA CLASE EN SI mas que a una instancia de este (objeto).

Esto significa que solo puede existir una unica instancia de esa caracteristica, incluso si se crean
multiples objetos de esa clase, o no se crea ninguno.

Todos los miembros estaticos de una clase seran compartidos entre todos los objetos.
*/

// Definimos la clase 'Perro'
class Perro {
    // La variable 'cantidad' sera de tipo 'int', sera estatico, y ademas privado.
    public static int cantidad = 0;
    // 'cantidad' sera un atributo que estara ligado directamente a la clase; quiere decir que
    // todos los objetos de tipo 'Perro' que se vayan a crear van a compartir este atributo.

    // En cambio, estos attributos no son estaticos.
    private String nombre;
    private int edad;
    private String dueno;
    // Quiere decir que estos atributos se van a ligar a los objetos que se van a crear de esta clase,
    // y seran independientes.


    // Constructor
    Perro(String name, int age, String owner) {
        nombre = name;
        edad = age;
        dueno = owner;

        // Cada vez que se cree un perro, se va a aumentar el contador de cantidad
        cantidad += 1;
    }

    public void getInfo() {
        System.out.printf("%s\n==========\nEdad: %d - Dueno: %s\nPerros creados hasta ahora: %d\n\n", nombre, edad, dueno, cantidad);
    }
}

public class P09_static {
    public static void main(String[] args) {
        // Creamos el primer 'Perro', esto hara que el contador 'cantidad' aumente en 1.
        Perro bob = new Perro("Bob", 5, "Max");

        bob.getInfo(); // Notese la frase "Perros creados hasta ahora"

        // Al crear 2 'Perro' mas, el contador 'cantidad' aumentara a 3.
        Perro rojo = new Perro("Rojo", 9, "Nicolas");
        Perro blu = new Perro("Blu", 9, "Sergio");

        bob.getInfo();
        rojo.getInfo();
        blu.getInfo();
        // Notese que ahora, podemos ver que en la frase "Perros creados hasta ahora" dice 3.
        // Pues, en este instante en el codigo, ya se habran creado 3 perros. El contador se comparte
        // entre los 3 objetos creados.

        // Como 'cantidad' es un atributo publico, podemos acceder a esta de manera directa, pero
        // como es estatica, no esta ligado a ningun objeto, sino que esta ligado a la misma clase.
        System.out.println(Perro.cantidad); // 3
        // A diferencia de las otras caracteristicas no estaticas, hay que acceder a ellas mediante
        // un objeto. Pero con las caracteristicas estaticas, se debe acceder directamente desde la clase.
    }
}
