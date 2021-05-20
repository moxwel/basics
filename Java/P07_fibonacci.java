import java.util.Scanner;

public class P07_fibonacci {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long a, b, c, input;
        a = 0;
        b = 1;
        c = 0;

        do {
            System.out.print("Numero de elementos a generar: ");
            input = scan.nextInt();
            System.out.print("\n");
        } while (input > 90);


        for (int i = 0; i < input; i++) {
            System.out.println("[" + (i+1) + "]\t" + a);
            c = a + b;
            a = b;
            b = c;
        }

        scan.close();
    }
}
