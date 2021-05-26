/*
La palabra clave 'final' hace que un atributo/metodo/clase sea constante. Es decir, se puede definir
una unica vez, y luego no puede cambiar.

En atributos hace que los valores no puedan cambiar.
En metodos hace que no pueda ser sobreescritos por herencia.
En clases hace que las clases no puedan ser subclases.
*/

public class P10_final {

    // Se define el atributo 'PI' como constante.
    public static final double PI = 3.1415;

    public static void main(String[] args) {
        System.out.println(PI);

        // PI = 5; // No se puede hacer esto, pues, el atributo 'PI' es constante (final)
    }
}
