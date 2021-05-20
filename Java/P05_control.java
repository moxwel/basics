public class P05_control {
    public static void main(String[] args) {

        // Switch, mismo funcionamiento que C.
        String nota = "B";
        switch (nota) {
            case "A":
                System.out.println("Excelente");
                break;

            case "B":
                System.out.println("Una B.");
                // No hay break, va a continuar en el caso C

            case "C":
                System.out.println("Bien");
                break;

            case "D":
                System.out.println("Puedes hacerlo mejor");
                break;

            case "F":
                System.out.println("Intentalo denuevo");
                break;

            default:
                System.out.println("Invalido");
        }
    }
}
