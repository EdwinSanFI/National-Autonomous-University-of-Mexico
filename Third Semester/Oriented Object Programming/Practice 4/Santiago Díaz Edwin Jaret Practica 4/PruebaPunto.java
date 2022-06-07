/**
 * @author: Edwin Santiago
 */

// La clase crea un punto con valores X y Y.
// El método imprime los puntos
class Punto{
    int x, y;
    // Constructor vacío
    public Punto() {

    }
    // Constructor con los atributos
    public Punto(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public void imprimePunto(){
        System.out.println("Punto [x="+x+", y="+y+"]");
    }
}

// La clase utiliza la clase Punto
public class PruebaPunto {
    public static void main(String[] args) {
        // Instancia una variable y guarda valores del punto X,Y.
        Punto p = new Punto();
        p.x = 5;
        p.y = 8;
        // Llama al método de la clase Punto
        p.imprimePunto();

        // Instancia una variable y guarda valores del punto X,Y.
        Punto x = new Punto();
        x.x=7;
        x.x = 2;
        // Llama al método de la clase Punto
        x.imprimePunto();
    }
}