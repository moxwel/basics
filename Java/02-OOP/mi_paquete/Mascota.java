package mi_paquete;
// Con esto, estamos diciendo que la clase es parte del paquete 'mi_paquete'.
// El nombre del paquete DEBE COINCIDIR con el nombre de la carpeta quien contiene las clases.

// Que sea publico, de esta forma, podremos instanciarlo fuera del paquete
public class Mascota {
    // Atributos
    private String nombre;

    // Constructor (debe ser publico, de esta forma podremos instanciarlo fuera del paquete)
    public Mascota(String name) {
        nombre = name;
    }

    // Metodos
    public void hablar() {
        System.out.println("Soy mascota. Me llamo " + nombre + ".");
    }
    public String getNombre() {
        return nombre;
    }
}
