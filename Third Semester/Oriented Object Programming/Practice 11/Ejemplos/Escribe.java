/**
 * @Author: Edwin Jaret Santiago Díaz
 */
import java.io.File;

public class Escribe {
    public static void main(String[] args) {
        try {
            /** Information container */
            File archivo = new File("rchivo.txt");
            /** print if the file exists */
            System.out.println(archivo.exists());
            /** Boolean method, True if the file created or False if the file exists */
            boolean seCreo = archivo.createNewFile();
            System.out.println(seCreo);
            /** print if the file exists */
            System.out.println(archivo.exists());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
