/*
El JDK de Java viene con clases utiles que nos pueden servir para resolver distintos problemas.

Una de esas clases utiles es la clase 'Math', que viene con metodos utiles para problemas matematicos.

En este caso, no es necesario crear un objeto de clase 'Math' para usarlos (sus metodos son estaticos).
*/

public class P12_math {
    public static void main(String[] args) {

        // Valor absoluto 'abs()'
        System.out.println(Math.abs(15)); // 15
        System.out.println(Math.abs(-15)); // 15

        // Funcion techo/piso
        System.out.println(Math.ceil(4.2)); // 5.0
        System.out.println(Math.floor(4.2)); // 4.0

        // Obtener el mayor/menor entre dos numeros
        System.out.println(Math.max(4, 8)); // 8
        System.out.println(Math.min(4, 8)); // 4

        // Elevar un numero por un exponente
        System.out.println(Math.pow(2, 5)); // 32.0 (2^5)

        // Raiz cuadrada
        System.out.println(Math.sqrt(81)); // 9.0
    }
}
