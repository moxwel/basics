// La palabra clave 'this' nos sirve para poder referenciar a la instancia actual de la clase.
// Viene util cuando hay ocultamiento de nombres por parte de parametros en los metodos, o
// sobreescritura de metodos.


class MiClase {
    protected int dato;

    public MiClase (int dato) {
        // Aqui debemos usar 'this' ya que dentro del constructor, decir 'dato' en realidad se
        // refiere al parametro, y no al miembro 'dato' de la clase.

        // Utilizando 'this.dato', nos estamos refiriendo al miembro 'dato' de la instancia de
        // la clase actual
        this.dato = dato;
    }

    public void unMetodo() {
        System.out.println("Funcion de la clase 'MiClase'. Valor guardado: " + dato);
    }

}

class SubClase extends MiClase{
    private int wea;

    public SubClase(int dato) {
        super(dato);
    }

}


public class P18_this {
    public static void main(String[] args) {
        MiClase objeto = new SubClase(34);

        objeto.unMetodo();

    }
}
