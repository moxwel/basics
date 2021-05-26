/*
Un paquete es basicamente, una CARPETA que contiene clases de (idealmente) la misma naturaleza.

Sirve para poder modularizar el codigo, y evitar conflictos de nombre.

Para poder importar las clases de un paquete, hay que importarlo, siguiendo la estructura de
las carpetas dentro del proyecto.
*/

import mi_paquete.*;
// De esta forma, estamos importando TODAS las clases de 'mi_paquete'

public class P11_paquetes {
    public static void main(String[] args) {
        Mascota botas = new Mascota("Botas");
        Mascota blu = new Mascota("Blu");
        Persona max = new Persona("Maxwell", 20, botas);
        Persona bro = new Persona("Bromo", 35, blu);

        botas.hablar();
        max.saludar();
        bro.saludar();

        System.out.println(max.getId());
        System.out.println(bro.getId());
    }
}
