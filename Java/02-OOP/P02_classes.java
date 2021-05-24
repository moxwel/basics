// Se puede crear una nueva clase, con sus respectivos metodos y atributos.
// Generalmente, los nombres de las clases comienzan con mayusculas.
class Animal {

    // Algun objeto que se instancie de esta clase, va a poseer el metodo 'ladrar()'
    void ladrar() {
        System.out.println("wow.");
    }
}

public class P02_classes {
    public static void main(String[] args) {

        // Ahora podemos instanciar un objeto de la clase 'Animal' que definimos anteriormente.
        // De la misma forma en como delcaramos objetos como 'String' o 'Scanner'
        Animal perro = new Animal();

        perro.ladrar();
    }
}

// Al compilar este archivo, se van a generar dos archivos '.class', uno de 'Animal' y otro de 'P02_classes'
