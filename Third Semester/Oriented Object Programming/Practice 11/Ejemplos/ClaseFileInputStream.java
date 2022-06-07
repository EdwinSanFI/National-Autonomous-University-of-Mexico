/**
 * @Author: Edwin Jaret Santiago Díaz
 */

import java.io.FileInputStream;
import java.io.IOException;

public class ClaseFileInputStream {
    public static void main(String[] args) {
        /** Create a file input stream */
        FileInputStream fis = null;
        byte[] buffer = new byte[81];
        int nBytes;
        try {
            /** Save the file in a variable */
            fis = new FileInputStream("fis.txt");
            nBytes = fis.read(buffer, 0, 81);
            /** Print the file */
            String texto = new String(buffer, 0, nBytes);
            System.out.println("El texto leido es: " + texto);
        } catch (IOException e){
            /** In case the file doesnt exist */
            System.out.println("Error: " + e.toString());
        } finally {
            try{
                /** Close the file */
                if(fis != null){
                    fis.close();
                }
            } catch (IOException e) {
                System.out.println("Error al cerrar el archivo: ");
            }
        }
    }
}

