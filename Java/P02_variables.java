/*
- El nombre de la clase puede diferir si la clase no se definio como "publico".

- Para ejecutarlo, hay que compilarlo de la misma forma, pero esto va a generar
  un archivo .class con el nombre de la clase, hay que ejecutar ese nombre:
    javac 02-variables.java
    java variables
*/

public class P02_variables {
    /*
    Tipos de datos para enteros:
    - byte (-128 a 127)
    - short (-32768 a 32767)
    - int (-2147483648 a 2147483647)
    - long (muy grande)

    Tipos de datos para decimales:
    - float (8 decimales)
    - double (15 decimales)

    Otros tipos:
    - char (un caracter)
    - boolean (puede ser true o false)

    Tipos de dato Objeto:
    (Son clases, y hay que invocarlos)
    - String (cadena de texto)
    */

    public static void main(String[] args) {

        // Para crear una variable, hay que asignarlo a un tipo.
        int num1 = 25;
        int num2 = 7;

        int result = num1 + num2;

        // El signo de suma sirve para concatenar
        System.out.println("El resultado es: " + result);

        String nombre = "Maximiliano";

        System.out.println("Mi nombre es: " + nombre);

        /*
        Prescedencia de operadores:
        ()  = Asociatividad
        * / = Multiplicacion y division
        + - = Suma y resta
        */

        result = num2 - num1 / 5;
        System.out.println("El primer resultado es: " + result);

        result = (num2 - num1) / 5;
        System.out.println("El segundo resultado es: " + result);
    }
}
