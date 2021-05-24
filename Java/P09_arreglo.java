import java.util.Scanner;

public class P09_arreglo {
    public static void main(String[] args) {

        // Declaracion de un arreglo (o vector)
        // Es necesario definir el tipo de dato y la dimension del arreglo
        int arreglo[] = new int[5];
        // Acabamos de crear un arreglo de 'int' de tamaño 5

        // Asignar valores dentro del vector
        arreglo[0] = 3812; // El primer elemento comienza con indice 0
        arreglo[1] = 938;
        arreglo[2] = 8;
        arreglo[3] = 874;
        arreglo[4] = 9999;

        // Dara error porque se sale del arreglo
        // arreglo[5] = 243;

        System.out.println(arreglo[3]); // 874

        // Cada arreglo tiene el atributo '.length, con el que se puede obtener el largo del arreglo
        System.out.println(arreglo.length); // 5


        // Otra forma de delarar y definir arreglos
        int[] arreglo2 = {34, 21, 43, 12, 54};
        System.out.println(arreglo2[2]); // 43


        Scanner entrada = new Scanner(System.in);
        System.out.print("Ingrese el largo del arreglo: ");
        int len = entrada.nextInt();
        int numeros[] = new int[len];

        // Rellenando el arreglo
        for (int i = 0; i < numeros.length; i++) {
            System.out.print("Ingrese el elemento [" + i + "]: ");
            int num = entrada.nextInt();

            numeros[i] = num;
        }

        for (int i = 0; i < numeros.length; i++) {
            System.out.println("numero[" + i + "] = " + numeros[i]);
        }

        entrada.close();
    }
}
