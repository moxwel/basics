// Las excepciones son erroes de programa que ocurren cuando se ejecutan.

// Un bloque 'try-catch' puede ayudarnos a capturar excepciones, de esta forma, poder realizar acciones
// incluso si es que alguna accion falla.

// Con esto podemos tener mas control sobre los fallos del programa.

public class P15_exceptions {
    public static void main(String[] args) {
        // Creamos un arreglo de 3 elementos
        int[] arreglo = {3,4,5};

        // Vamos a intentar...
        try {
            // Acceder al cuarto elemento del arreglo
            System.out.println("Elemento del arreglo: " + arreglo[3]);
            // Esto va a causar un error, pues, el arreglo solo posee 3 elementos.

            // La excepcion se va a ejecutar, y el bloque 'catch' va a poder capturarlo.
        } catch (Exception el_error) {
            // El parametro de 'catch' sirve para poder capturar la excepcion ocurrida, y poder
            // examinarlo, para poder hacer decisiones.

            // Como en la sentencia anterior ocurrio una excepcion, este bloque de memoria se va a ejecutar.
            System.out.println("Ocurrio un error en el programa...\nError: " + el_error);
        } finally {
            // El bloque 'finally' es opcional, y se va a ejecutar independiente si ocurre una
            // excepcion o no.
            System.out.println("Fin del programa.");
        }
    }
}
