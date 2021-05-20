/*
- Para poder ejecutar programas en Java, necesitamos clases.

- Los nombres de las clases generalmente comienzan con mayusculas.

- Las clases son "plantillas" que contienen codigo.

- Se lee de arriba hacia abajo y de derecha a izquierda.

- La primera cosa que se debe escribir en un codigo de Java es el nombre de
  la clase.

- El nombre del archivo debe tener exactamente el mismo nombre que la clase
  (en el caso de una clase "publica").

- Para compilar, se entrega el archivo .java :
    javac P01_intro.java

- Para ejecutar, se entrega el NOMBRE del archivo .class :
    java P01_intro
*/

/** Este es un comentario de documentacion.
 *  'P01_intro' es una clase de tipo "publico"
 */
public class P01_intro {

    // El metodo 'main' es el punto de entrada de la clase.
    public static void main(String[] args) {

        System.out.println("Hola mundo!");
        System.out.print("Esto es un print sin salto de linea. ");
        System.out.print("Como se puede ver\n");

    }
}
