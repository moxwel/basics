/*
En Java, se puede moficiar el acceso a clases, atributos y metodos.

Para Clases:
- Acceso publico:
Con 'public' se esta diciendo que la clase puede ser accesible desde cualquier otra clase externa
y en cualquier paquete externa a este. Se puede acceder desde absolutamente cualquier lugar.

- Acceso por defecto:
Sin colocar ningun modificador, la clase solo sera accesible por clases del MISMO paquete. Las clases
que pertenezcan a la misma carpeta podran acceder a la clase.


Para Atributos y Metodos:
- Acceso publico:
Con 'public', los atributos/metodos pueden ser accedidos desde
cualquier otra clase desde cualquier otro paquete.

- Acceso privado:
Con 'private', los atributos/metodos solo podran ser accedidos desde la misma clase en la que se declaran.

- Acceso por defecto:
Sin colocar ningun modificador, los atributos/metodos seran accesibles para las otras clases del
mismo paquete.

- Acceso protegido:
con 'protected', provee el mismo acceso que el acceso por defecto, pero ademas añade la posibilidad de que las
sublcases declaradas tambien puedan acceder a los atributos/metodos de la clase padre.
*/



// Esta clase es publica, significa que cualquier otra clase de cualquier parte podra acceder a esta.
public class P04_accesos {

    // El metodo main debe ser publico, pues, de forma contraria, no podria ser accedida
    public static void main(String[] args) {
        Vehiculo2 auto = new Vehiculo2();

        auto.bocina();

        // auto.ruedas = 4;
        // No se puede hacer esto, pues, el atributo 'ruedas' es privado. No puede ser accedido
        // fuera de la clase donde se declaro.
    }
}


// Esta clase posee acceso por defecto, es decir, las clases del mismo paquete podran acceder a esta
class Vehiculo2 {

    // Los atributos de la clase 'Vehiculo2' son privados, es decir, solo se podran acceder desde
    // esta misma clase, no desde otra externa.
    private String color;
    private int ruedas;
    private int velMax;
    private double combustible;
    // Es buena practica mantener los atributos de una clase de manera privada, ya que de esta
    // forma se sigue el concepto de TDA. Para modificar estos valores, es necesario utilizar metodos
    // destinados a esa tarea, llamados 'setters' y 'getters'.

    void bocina() {
        System.out.println("Beep!");
    }
}
