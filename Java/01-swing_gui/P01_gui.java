/*
- Con las interfaces graficas podemos facilitar el uso del programa para el usuario final sin
  necesidad de usar lineas de comando.

- Las interfaces graficas en Java se crean con el paquete 'javax.swing'

- 'swing' provee diferentes Objetos para poder crear interfaces graficas.

- Para importar todas las clases de un paquete, se usa el simbolo *

- La clase 'JFrame' nos pemrite crear el "contenedor" donde iran todos los elementos de la interfaz grafica
*/

import javax.swing.*;
// Como no sabemos cuales objetos vamos a terminar usando en nuestra interfaz graficas, entonces
// importamos todo por ahora.

// En vez de definir nuestra propia clase, se hace uso de la 'herencia' de clases con la palabra "extends"
// esto es posible por el paradigma de orientacion a objetos.

// Vamos a hacer nuestra clase, utilizando y heredando las propiedades de otra clase
public class P01_gui extends JFrame {
    // Creamos nuestra clase 'P01_gui' utilizando las propiedades que ya posee la clase 'JFrame', que
    // esta contenida en el paquete 'javax.swing', y que nos permitira poder contener los elementos
    // graficos para nuestra interfaz.


    // La clase 'JLabel' nos permite poder mostrar etiquetas de texto. Es nuestro equivalente a
    // 'System.out.print()'.
    private JLabel etiqueta1;
    // El modificador de acceso 'private' hace que las variables, objetos, o clases, solo sean accesibles
    // solo para los integrantes de este archivo.
    // Las etiquetas solo se van a usar en la interfaz que estamos programando actualmente.


    // CONSTRUCTOR: Esta funcion se ejecuta en el momento cuando se cree un objeto de esta clase.
    // La funcion constructor DEBE llamarse igual que la clase, y debe ser publica (en caso contrario,
    // la clase 'JFrame' no podria acceder al constructor para poder aplicar los elementos)
    public P01_gui() {
        // Aqui dentro del costructor, se deben definir el diseño de los elementos que se
        // utilizaran dentro de la interfaz


        // Con el metodo 'setLayout()' se puede indicar con coordenadas DONDE poner los elementos
        // dentro de la interfaz.
        setLayout(null);


        // Creamos el objeto etiqueta de delcaramos anteriormente.
        etiqueta1 = new JLabel("Hola mundo, estoy en una interfaz.");


        // Con el metodo 'setBounds()' se pueden definir las dimensiones de un objeto 'JLabel'.
        // Parametros = (xPos, yPos, ancho, alto)
        etiqueta1.setBounds(0, 0, 300, 100);


        // Con el metodo 'add()' se añaden todos los elementos anteriormente declarados a la
        // etiqueta dada.
        add(etiqueta1);
    }


    public static void main(String[] args) {
        /*
        Anteriormente, lo unico que hicimos fue crear la "etiqueta" que va a contener el mensaje.
        Ahora la otra cosa que nos falta es crear el "contenedor" para poder mostrarlo por pantalla.
        */

        // Creamos un objeto del mismo tipo que la clase que estamos trabajando, ya que como lo
        // definimos anteriomente, hace uso de la clase 'JFrame'. Este sera nuestro "contendor" (o ventana).
        P01_gui ventana1 = new P01_gui();

        // Con el metodo 'setBounds()', podemos dar las dimensiones a los "contenedores"
        // Parametros = (xPos, yPos, ancho, alto)
        ventana1.setBounds(0,0,500,200);


        // Con el metodo 'setVisible()', podemos controlar la visibilidad del contenedor.
        ventana1.setVisible(true);


        // Con el metodo 'setLocationRelativeTo()' podemos controlar donde ubicar el contenedor.
        ventana1.setLocationRelativeTo(null);
    }
}
