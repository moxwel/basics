/*
Los metodos definen el comportamiento de una clase.
Son funciones que estan asociadas a objetos, y pueden realizar acciones.
*/

public class P01_methods {

    // Se pueden definir metodos como funciones.
    static void decirHola() {
        System.out.println("Hola mundo");
    }

    // De la misma manera, se le pueden entregar parametros
    static void saludar(String nombre) {
        System.out.println("Saludos " + nombre + "!");
    }

    public static void main(String[] args) {
        decirHola();
        saludar("Maximiliano");

        int resultado = sumar(5, 3);
        System.out.printf("El resultado de sumar %d con %d es %d.\n", 5, 3, resultado);

        despedirse();
    }

    // A diferencia de C, los metodos no necesariamente deben ir antes de 'main'
    static void despedirse() {
        System.out.println("Adios!");
    }

    // Al definir un metodo, debe ir asociado el tipo de retorno
    static int sumar(int a, int b) {
        return a + b;
    }

    // Podemos darnos cuenta entonces que la funcion 'main' no retorna nada, y recibe como parametros
    // un arreglo de strings.
}
