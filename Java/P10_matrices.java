import java.util.Scanner;

public class P10_matrices {
    public static void main(String[] args) {

        // Se puede hacer un arreglo "bidireccional" (o matriz)
        // De la misma forma que los arreglos, pero hay que mencionar las dimensiones
        int matriz[][] = new int[2][3];
        // Acabamos de crear una matriz de 2 FILAS y 3 COLUMNAS

        // Asignar valores dentro de la matriz
        matriz[0][0] = 5;
        matriz[0][1] = 2;
        matriz[0][2] = 3;
        matriz[1][0] = 8;
        matriz[1][1] = 7;
        matriz[1][2] = 1;
        /*
        Matriz generada:

        5   2   3
        8   7   1

        */

        System.out.println(matriz[0][2]); // 3

        Scanner entrada = new Scanner(System.in);

        System.out.print("Ingrese la cantidad de filas: ");
        int filas = entrada.nextInt();
        System.out.print("Ingrese la cantidad de columnas: ");
        int columnas = entrada.nextInt();

        int numeros[][] = new int[filas][columnas];

        for (int m = 0; m < filas; m++) {
            for (int n = 0; n < columnas; n++) {
                System.out.print("Ingrese el elemento [" + m + "][" + n + "]: ");
                int num = entrada.nextInt();
                numeros[m][n] = num;
            }
        }

        for (int m = 0; m < filas; m++) {
            for (int n = 0; n < columnas; n++) {
                System.out.print(numeros[m][n] + "     ");
            }
            System.out.print("\n");
        }

        entrada.close();
    }
}
