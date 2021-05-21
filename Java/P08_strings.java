// La clase 'String' posee metodos (funciones) bien utiles.

public class P08_strings {
    public static void main(String[] args) {
        String nombre = "Maximiliano";

        // El metodo 'equals()' permite poder comparar strings
        System.out.println(nombre == "Maximiliano");      // True MALA PRACTICA
        System.out.println(nombre.equals("Maximiliano")); // True
        System.out.println(nombre.equals("Max"));         // False
        System.out.println(nombre.equalsIgnoreCase("MAXIMILIANO")); // True IGNORA MAYUS-MINUS

        // El metodo 'length()' permite poder obtener la cantidad de caracteres
        // P a l a b r a
        // 1 2 3 4 5 6 7
        System.out.println(nombre.length()); // 11

        // El metodo 'siubstring()' permite obtener una parte del string,
        // definiendo los limites.
        //  P a l a b r a
        // 0 1 2 3 4 5 6 7
        System.out.println(nombre.substring(0, 3)); // Max
        System.out.println(nombre.substring(4));    // miliano

        // El metodo 'charAt()' obtiene el caracter que se encuentra en el
        // indice dado.
        // P a l a b r a
        // 0 1 2 3 4 5 6
        System.out.println(nombre.charAt(0));  // M
        System.out.println(nombre.charAt(10)); // o
        System.out.println(nombre.charAt(2));  // x

        // De esta forma se puede transformar el String 'num' al tipo Integer
        String num = "3621";
        System.out.println(Integer.valueOf(num)+10); // 3631

        // El metodo 'split()' separa un string segun el regex que contenga
        // y genera un arreglo de Strings
        String frase = "El zorro salta sobre el elefante";
        String[] arr = frase.split(" ");
        int size = arr.length; // ''.length' es una propiedad de cualquier arreglo

        for (int i = 0; i < size; i++) {
            System.out.println("arr[" + i + "] : " + arr[i]);
        }
    }
}
