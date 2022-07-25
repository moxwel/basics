class ClasePadre {
    ClasePadre() {
        System.out.println("Constructor por defecto.");
    }

    ClasePadre(int a) {
        System.out.println("Constrcutor con 1 parametro.");
    }
}

class SubClase1 extends ClasePadre {
    SubClase1() {
        System.out.println("Construyendo SubClase1...");
    }
}

class SubClase2 extends ClasePadre {
    SubClase2() {
        super(1);
        System.out.println("Construyendo SubClase2...");
    }
}

public class P12_herencia4 {
    public static void main(String[] args) {
        ClasePadre obj1 = new SubClase1();
        ClasePadre obj2 = new SubClase2();
    }
}
