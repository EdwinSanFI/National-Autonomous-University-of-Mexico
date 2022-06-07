/**
 * @author: Edwin Santiago
 */
// Importamos la clase a utilizar
import java.util.ArrayList;

public class Colecciones {
    public static void main(String[] args) {
        // Crea un arreglo de la clase ArrayList
        ArrayList<Integer> arreglo = new ArrayList<Integer>(); 
        // Añadimos elementos al arreglo
        arreglo.add(1);
        arreglo.add(8);
        arreglo.add(5);
        // arreglo.add(valor);
        arreglo.add(1, 9);
        // arreglo.add(valor, posicion);
        // Imprimimos el tamaño del arreglo con el metodo size()
        System.out.println("Tamano del array list " + arreglo.size());
        // Imprimimos el elemento de la posicion 3 con el metodo get(n)
        System.out.println("Elemento en la posicion 3: " + arreglo.get(3));
        // Imprimimos los elementos del arreglo
        for (Integer elemento : arreglo) {
            System.out.println(elemento);
        }
    }
}