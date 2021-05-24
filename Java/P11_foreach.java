public class P11_foreach {
    public static void main(String[] args) {
        // Existe una manera mas sencilla de recorrer los elementos de un arreglo, utilizando lo
        // que se conoce como un 'foreach' loop.

        // Creamos un arreglo de 'String' con nombres
        String[] nombres = {"Juan", "Pepe", "Etesech", "Max"};

        // En este loop, la variable 'nmb' va a ir tomando cada elemento en el arreglo 'nombres'
        // en cada iteracion.
        for (String nmb: nombres) {
            System.out.println(nmb);
        }

        // Juan
        // Pepe
        // Etesech
        // Max
    }
}
