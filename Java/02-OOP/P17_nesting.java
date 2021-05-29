/*
Se pueden hacer clases anidadas. Es decir, clases dentro de clases.

A diferencia de la herencia, las clases anidadas si pueden ser privadas, y solamente pueden ser
accedidas desde la clase que las contiene.
*/

class Robot {

    // Esta clase 'Mente' unicamente tiene sentido dentro de la clase 'Robot', y todas sus caracteristicas
    // podran ser accedidas dentro de la clase 'Robot'
    private class Mente {
        private void pensar() {
            System.out.println(id + " esta pensando.");
        }
    }

    private int id = (int)(Math.random() * ((1000 - 9999) + 10)) + 9999; // nnumero aleatorio entre 1000 y 9999
    private Mente b = new Mente();

    public void decirAlgo() {
        b.pensar();
        // Solamente dentro de la clase 'Robot' se puede acceder a las caracteristicas de la clase
        // 'Mente', incluso si son privados.
    }
}

public class P17_nesting {
    public static void main(String[] args) {
        Robot robobo = new Robot();

        // robobo.pensar();
        // No se puede acceder al metodo 'pensar()' desde 'Robot', pues, esta dentro de otra clase.

        robobo.decirAlgo();
    }
}
