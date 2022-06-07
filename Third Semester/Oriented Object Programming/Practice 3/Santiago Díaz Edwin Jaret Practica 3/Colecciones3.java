import java.util.Enumeration;
import java.util.Hashtable;

public class Colecciones3 {
    public static void main(String[] args) {
        // Se crea una tabla hash
        Hashtable<String, Integer> miTabla = new Hashtable<String, Integer>();
        // Se agrega los valores con sus claves
        miTabla.put("uno", 1);
        miTabla.put("dos", 2);
        miTabla.put("cinco", 5);
        // Se inicializa 2 variables que imprimiran los valores y claves en el ciclo while
        String clave;
        Integer valor;
        // Se guarda las claves
        Enumeration<String> claves = miTabla.keys();
        // Se recorren las claves
        while(claves.hasMoreElements()) {
            // Se obtiene la clave actual
            clave = claves.nextElement();
            // Se obtiene el valor actual
            valor = miTabla.get(clave);
            // Se imprimen los valores
            System.out.println("Clave : " + clave + "\tValor : " + valor);
        }
    }
}
