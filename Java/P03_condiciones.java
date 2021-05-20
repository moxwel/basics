public class P03_condiciones {
    public static void main(String[] args) {
        // De esta forma se pueden declarar variables sin necesidad de inicializar
        boolean condicion;

        // Si la condicion es verdadera, se ejecuta el bloque de codigo.
        condicion = true;
        if (condicion) {
            System.out.println("[1] La condicion es verdadera.");
        }

        // Si la condicion es falsa, se va a ejecutar el bloque de falso.
        condicion = false;
        if (condicion) {
            System.out.println("[2] La condicion es verdadera.");
        } else {
            System.out.println("[3] La condicion es falsa.");
        }

        // Tambien se pueden asignar variables de un MISMO TIPO en una linea.
        int num1 = 40, num2 = 67, num3 = 55;
        int promedio = (num1 + num2 + num3) / 3;
        if (promedio >= 55) {
            System.out.println("[4] Aprobaste. Tu nota fue: " + promedio);
        } else if (promedio >= 50) {
            System.out.println("[5] Ir a global. Tu nota fue: " + promedio);
        } else {
            System.out.println("[6] Reprobaste. Tu nota fue: " + promedio);
        }
    }
}
