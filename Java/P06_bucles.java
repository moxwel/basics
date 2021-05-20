public class P06_bucles {
    public static void main(String[] args) {

        // Misma estructura que C
        int i = 1;
        while (i <= 10) {
            System.out.print(i + " ");
            i++;
        }
        System.out.print("\n");

        // Misma estructura que C
        do {
            System.out.println("El do-while se va a ejecutar al menos una vez");
        } while (i < 5);

        // Misma estructura que C
        for (int j = 0; j < 10; j+=2) {
            System.out.println("[For] bucle numero: " + j);
        }
    }
}
