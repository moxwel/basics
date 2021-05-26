/*
Los constructores tambien pueden tener parametros. Esos parametros se introducen en el momento
en que el objeto es instanciado.

Tambien se permiten tener varios constructores con diferentes parametros (sobrecarga).
Segun como se instancie la clase, se llamaran de forma diferente.
*/

class Vehiculo5 {

    private String color;
    private int ruedas;

    // Este constructor admite un parametro de tipo 'String' que definira el color del vehiculo
    Vehiculo5(String col) {
        color = col;
        ruedas = 4;
        System.out.println("[1] Acaba de crearse un vehiculo de color " + col);
    }

    // Este constructor admite dos parametros, que definiran el color y la cantidad de ruedas
    Vehiculo5(String col, int whel) {
        color = col;
        ruedas = whel;
        System.out.println("[2] Acaba de crearse un vehiculo de color " + col + " y con " + whel + " ruedas");
    }

    // Si instanciamos un objeto sin parametros, se ejecutara este constructor. Se puede considerar
    // que esta es la manera "por defecto" en como se va a instanciar esta clase.
    Vehiculo5() {
        color = "Blanco";
        ruedas = 4;
        System.out.println("[3] Acaba de crearse un vehiculo por defecto.");
    }



    public String getColor() {
        return color;
    }

    public int getRuedas() {
        return ruedas;
    }
}

public class P07_constructors2 {
    public static void main(String[] args) {
        Vehiculo5 un_auto = new Vehiculo5("Rojo"); // Crear un auto de color rojo
        Vehiculo5 otro_auto = new Vehiculo5("Azul", 6); // Crear un auto de color rojo y con 6 ruedas
        Vehiculo5 auto_defecto = new Vehiculo5(); // Crear un auto por defecto: blanco y con 4 ruedas

        System.out.println(un_auto.getColor()); // Rojo
        System.out.println(otro_auto.getColor()); // Azul
        System.out.println(auto_defecto.getColor()); // Blanco
    }
}
