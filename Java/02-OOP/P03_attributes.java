// Los atributos basicamente son variables que estan asociados a una clase.
class Vehiculo {
    // Los atributos de la clase Vehiculo
    String color;
    int ruedas;
    int velMax;
    double combustible;

    // Los metodos de la clase Vehiculo
    void bocina() {
        System.out.println("Beep!");
    }
}

public class P03_attributes {
    public static void main(String[] args) {

        // Podemos crear dos objetos de la misma clase...
        Vehiculo auto = new Vehiculo();
        Vehiculo moto = new Vehiculo();

        // Donde sus caracteristicas sean diferentes.
        auto.ruedas = 4;
        moto.ruedas = 2;

        auto.color = "Blanco";
        moto.color = "Rojo";

        System.out.println(auto.color); // Blanco
        System.out.println(moto.ruedas); // 2
    }
}
