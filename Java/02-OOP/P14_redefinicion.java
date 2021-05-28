// Se puede sobreescribir un metodo de una superclase, si se declara de la misma manera en como
// estaba declarada en la superclase.

class Animal {

    // Este es el metodo original de la clase 'Animal'
    public void hacerSonido() {
        System.out.println("Grrr");
    }
}

class Perro extends Animal {

    // Esta subclase sobreescribe el metodo 'hacerSonido()' de la clase padre 'Animal'
    public void hacerSonido() {
        System.out.println("Woof");
    }
}

class Gato extends Animal {

    // Esta subclase sobreescribe el metodo 'hacerSonido()' de la clase padre 'Animal'
    public void hacerSonido() {
        System.out.println("Meow");
    }
}

public class P14_redefinicion {
    public static void main(String[] args) {
        Animal un_animal = new Animal();
        Perro mi_perro = new Perro();
        Gato mi_gato = new Gato();

        un_animal.hacerSonido(); // Grrr
        mi_perro.hacerSonido();  // Woof
        mi_gato.hacerSonido();   // Meow
    }
}
