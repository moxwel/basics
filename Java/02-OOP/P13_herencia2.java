/*
- Los constructores no se heredan, pero se ejecutan cuando una subclase se instancia.

- Una subclase puede tener variables con el mismo nombre que las variables de su clase padre.
  Se puede acceder a la variable de la clase padre con la palabra 'super'.
*/

class MiClase {
    // Notese la variable 'mi_variable' de 'MiClase' y 'MiOtraClase'
    int mi_variable = 56;

    MiClase() {
        System.out.println("Se ha creado un nuevo objeto 'MiClase'.");
    }
}

class OtraClase extends MiClase {
    // Para 'OtraClase', el valor de 'mi_variable' sera 12
    // Pero para 'MiClase' el valor sera de 56.
    int mi_variable = 12;

    // Cuando se declare un objeto de clase 'OtraClase', se va a ejecutar primero el
    // constructor de 'MiClase'
    OtraClase() {
        System.out.println("Se ha creado un nuevo objeto 'OtraClase'.");

        System.out.println("Contenido de 'mi_variable' local (OtraClase): " + mi_variable);
        // 12 (variable local de la clase)

        System.out.println("Contenido de 'mi_variable' de la clase padre (MiClase): " + super.mi_variable);
        // 56 (variable de la superclase)
    }
}

public class P13_herencia2 {
    public static void main(String[] args) {
        // Tambien podemos definir el tipo de la variable como la clase padre, y creear un objeto de
        // una subclase de esta. Esto nos permite poder usar variables de tipo 'MiClase' sin saber
        // a primera vista que contienen un objeto de una subclase.
        MiClase a = new OtraClase();
    }
}
