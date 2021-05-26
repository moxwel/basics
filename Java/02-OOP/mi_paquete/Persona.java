package mi_paquete;
// Con esto, estamos diciendo que la clase es parte del paquete 'mi_paquete'.
// El nombre del paquete DEBE COINCIDIR con el nombre de la carpeta quien contiene las clases.

// Que sea publico, de esta forma, podremos instanciarlo fuera del paquete
public class Persona {
    // Atributos
    private static int cant = 1;
    private int id;
    private String nombre;
    private int edad;
    private Mascota mascota;

    // Constructor (debe ser publico, de esta forma podremos instanciarlo fuera del paquete)
    public Persona(String name, int age, Mascota pet) {
        nombre = name;
        edad = age;
        mascota = pet;
        id = cant;
        cant++;
    }

    // Metodos
    public void saludar() {
        System.out.println("Hola, soy " + nombre + "! Tengo " + edad + " annos. Mi mascota se llama " + mascota.getNombre() + ".");
    }
    public int getId() {
        return id;
    }
}
