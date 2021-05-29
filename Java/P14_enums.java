// Una enumeracion es un tipo especial de coleccion, que contiene constantes.

public class P14_enums {
    // De esta manera definimos una enumeracion 'Estado', sus constantes estan dentro de
    // parentesis angulares.
    enum Estado {CORRECTO, FALLO, ATENCION}
    // Una enumeracion es util cuando se requiere de alguna variable que unicamente puede estar
    // en un conjunto posible de estados.

    // Esto hace mas eficiente al programa, y tambien lo hace a prueba de errores sobre algun caso
    // donde el valor de la variable sea invalida.


    public static void main(String[] args) {
        // De esta manera declaramos una variable de tipo enumeracion 'Estado'
        Estado status = Estado.FALLO;
        // La variable 'status' va a tener el valor de 'FALLO' de la enumeracion 'Estado'

        System.out.println("Estado actual: " + status);

        switch (status) {
            case CORRECTO:
                System.out.println("El sistema esta funcionando.");
                break;

            case FALLO:
                System.out.println("El sistema tiene fallas.");

            case ATENCION:
                System.out.println("Se requiere atencion.");
                break;
        }
    }
}
