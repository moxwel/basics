/*
Anteriormente, vimos que al instanciar una subclase, implicitamente se va a llamar al constrcutor
de la superclase, como el constructor por defecto (sin parametros).

Si es que la superclase posee diferentes constrctores, es necesario que la subclase especifique
explicitamente cual constructor usar.
*/


// Vamos a crear una clase 'Persona' generica.
class Persona {

    protected String nombre;
    protected int edad;
    protected String titulo = "Ninguno";

    // Este sera el constuctor de 'Persona'
    public Persona(String nomb, int ed) {
        nombre = nomb;
        edad = ed;
    }

    public void saludar() {
        System.out.println("Hola, me llamo " + nombre + " y tengo " + edad + " annos.");
    }
}

// 'Estudiante' va a extender a la clase 'Persona', y como la superclase tiene un constructor con
// parametros, hay que decirle explicitamente como ingresar esos parametros al constructor.
class Estudiante extends Persona {

    private String carrera;

    // Este sera el constcutor de 'Estudiante'
    public Estudiante(String nomb, int ed, String carr) {
        // La subclase al crearse, llama implicitamente al constructor generico de la superclase
        // (en este caso, 'Persona()'). Pero en este caso, el constructor de 'Persona' necesita 2
        // parametros, y la subclase no sabe como rellenarlos.

        // Hay que especificar explicitamente como llamar al constructor de la superclase.
        super(nomb, ed);

        // Ahora que ya construimos la clase "base", ahora podemos rellenar con los atributos
        // especificos de esta clase actual.
        carrera = carr;
    }

    // Sobreescribimos el metodo 'saludar()' de la clase 'Persona'
    public void saludar() {
        System.out.println("Hola, me llamo " + nombre + " y tengo " + edad + " annos. Estoy estudiando " + carrera + ". Mi titulo actualmente es: " + titulo);
    }
}


class Profesional extends Persona {
    public Profesional(String nomb, int ed, String tit) {
        super(nomb, ed);
        titulo = tit;
    }

    public void saludar() {
        System.out.println("Hola, me llamo " + nombre + " y tengo " + edad + " annos. Mi titulo actualmente es: " + titulo);
    }
}


public class P12_herencia3 {
    public static void main(String[] args) {
        // Pepe es una persona generica.
        Persona person1 = new Persona("Pepe", 23);

        // Max es un estudiante
        Persona person2 = new Estudiante("Max", 20, "Informatica");

        // Marti es un profesional
        Persona person3 = new Profesional("Marti", 26, "Ingeniero");

        person1.saludar(); // Pepe
        person2.saludar(); // Max
        person3.saludar(); // Marti
    }
}
