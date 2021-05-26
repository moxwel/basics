/*
Los "constructores" son metodos especiales que se ejecutan en el momento cuando se crea un objeto
de la clase. Es decir, cuando instancias una clase, el constructor se va a ejecutar.

Generalmente, los constructores son usados para poder dar valores iniciales a los
atributos de los objetos recien creados.

Para crear un constructor:
- El nombre del metodo debe ser EXACTAMENTE igual al nombre de la clase
- No se debe especificar tipo de retorno.

Todas las clases tienen un constructor, aunque este definida explicitamente o no. Por eso tiene sentido
que se deba poner el nombre de la clase como funcion al crear un objeto:

    String texto = new String();
*/

class Vehiculo4 {

    private String color;
    private int ruedas;

    // Cuando se instancie un objeto de esta clase, este metodo se va a ejecutar
    Vehiculo4() {
        color = "Blanco";
        ruedas = 4;
        System.out.println("Acaba de crearse un objeto de clase 'Vehiculo4'");
    }


    public String getColor() {
        return color;
    }

    public int getRuedas() {
        return ruedas;
    }
}

public class P06_constructors {
    public static void main(String[] args) {
        Vehiculo4 un_auto = new Vehiculo4();

        System.out.println(un_auto.getColor());
    }
}
