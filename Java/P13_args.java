public class P13_args {

    // El parametro 'args' que se encuentra en el 'main', es el parametro que recibe los "argumentos
    // de programa".

    // Cuando ejecutamos nuestro programa con argumentos, se guardan como 'Strings' en este arreglo.

    // Prueba a ejecutar el programa como:
    //     java P13_args hola mundo estos son mis argumentos 123 456
    public static void main(String[] args) {
        System.out.println("Argumentos de programa: " + args.length);

        for (int i = 0; i < args.length; i++) {
            System.out.printf("[%d] %s\n", i, args[i]);
        }
    }
}
