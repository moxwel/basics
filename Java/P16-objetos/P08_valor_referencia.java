/*
En Java, todas las variables que sean OBJETOS son pasados por referencia.

En cambio, todas las variables que sean algun tipo PRIMITIVO son pasados por valor.
(Tipos primitivos: byte, short, int, long, float, double, boolean, char)

NOTA: Recordemos que en Java, los tipos de dato hecho por el usuario son clases, y en su nombre
siempre comienzan con mayusculas (ej: Scanner, String, Vehiculo, etc.)
*/

class Entero {
    int valor;
}

public class P08_valor_referencia {
    // Una sobrecarga de la funcion 'sumarUno', para ints y para objetos de clase 'Entero'
    static void sumarUno(int a) {
        a = a + 1;
    }
    static void sumarUno(Entero a) {
        a.valor = a.valor + 1;
    }

    public static void main(String[] args) {
        // La variable 'numero' es un tipo de dato primitivo (int)
        int numero = 5;
        System.out.println(numero); // 5

        // Al ejecutar el metodo/funcion, como el parametro es un tipo de dato primitivo, entonces
        // el parametro se pasa por VALOR. Es decir, se pasa una COPIA del valor hacia la funcion,
        // y el valor original fuera de la funcion no se ve afectada por los cambios.
        sumarUno(numero);
        System.out.println(numero + "\n"); // 5 (el valor no cambió porque era un tipo de dato primitivo)



        // En cambio, si decimos que 'numero2' es un OBJETO de clase 'Entero'
        Entero numero2 = new Entero();

        numero2.valor = 5;
        System.out.println(numero2.valor); // 5

        // Al ejecutar el metodo/funcion, como el parametro es un OBJETO de clase 'Entero', entonces
        // el parametro se pasa por REFERENCIA. Es decir, se pasa la REFERENCIA de la variable hacia
        // la funcion, y poder hacer cambios que se veran reflejadas fuera de esta.
        sumarUno(numero2);
        System.out.println(numero2.valor); // 6 (el valor cambió porque era un objeto)
    }
}
