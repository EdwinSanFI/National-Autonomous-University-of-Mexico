/**
 * @author: Edwin Santiago
 */
// Importamos la clase a utilizar
import java.util.Hashtable;

public class Colecciones2 {
    public static void main(String[] args) {
        // Creamos una tabla Hash con claves de tipo String y valores a almacenar de tipo Integer
        Hashtable<String, Integer> miTabla = new Hashtable<String, Integer>();
        // Agregamos 3 claves con sus 3 valores
        miTabla.put("uno", 1);
        miTabla.put("dos", 2);
        miTabla.put("cinco", 5);
        // miTabla.put(clave, valor);
        // Comprobamos si la clave "cuatro" está en la tabla hash con el metodo containsKey()
        System.out.println("Contiene a cuatro? " + miTabla.containsKey("cuatro"));
        // Con un for-each se recorre las claves de la tabla
        for(String clave: miTabla.keySet()){
            System.out.println(clave);
        }
        // Con un for-each se recorre las valores de la tabla
        for(Integer valor:miTabla.values()) {
            System.out.println(valor);
        }
    }
}
