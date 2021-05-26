class Vehiculo3 {

    // Estos atributos solamente pueden ser accedidos dentro de esta clase 'Vehiculo3'
    private String color;
    private int ruedas;

    void bocina() {
        System.out.println("Beep!");
    }


    // Para poder hacer que los atributos sean modificables fuera de la clase, hay que hacerlo
    // a traves de metodos hechos especificamente para esa tarea: los 'setters' y los 'getters'.

    // Un 'setter' es un metodo que se encarga de poder INGRESAR Y MODIFICAR datos. A traves de
    // este metodo, se podran modificar los atributos de un objeto instanciado de esta clase.
    // Por esta razon, estos metodos tienen un acceso publico.
    public void establecerColor(String valor) {
        color = valor;
        // Esto va a establecer el color del objeto actual a uno dado por el parametro.
    }

    public void ponerRuedas(int cant) {
        ruedas = cant;
        // Esto va a establecer el numero de ruedas del objeto actual a uno dado por el parametro.
    }


    // Un 'getter' es un metodo que se encarga de OBTENER datos. A traves de este metodo, se podra
    // obtener el valor de los atributos de un objeto instanciado de esta clase.
    // Al igual que los 'setters', tiene sentido de que tengan un acceso publico.
    public String obtenerColor() {
        return color;
    }

    public int obtenerRuedas() {
        return ruedas;
    }

    // Como nota al margen: una convencion para los nombres de los 'setters' es que comience con "set"
    // y despues el nombre del atributo a establecer. Ej: 'setColor', 'setruedas'

    // De la misma manera con los 'getters', es una convencion de que comience con "get" y despues
    // el nombre del atributo a obtener. Ej: 'getColor', 'getRuedas'
}

public class P05_set_get {
    public static void main(String[] args) {
        Vehiculo3 auto = new Vehiculo3();
        Vehiculo3 moto = new Vehiculo3();

        // Ahora, a diferencia de 'P03', no accedemos directamente a los atributos, sino que lo
        // hacemos a traves de los metodos 'setters' y 'getters'.
        auto.establecerColor("Rojo");
        auto.ponerRuedas(4);

        moto.establecerColor("Rojo");
        moto.ponerRuedas(2);

        System.out.println(auto.obtenerColor()); // Rojo
        System.out.println(moto.obtenerRuedas()); // 2
        moto.bocina(); // Beep!
    }
}
