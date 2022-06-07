/**
 * @Author: Edwin Jaret Santiago Díaz
 * The FileOutputStream class is used to write data to a file
 */
import java.io.FileOutputStream;
import java.io.IOException;

public class ClaseFileOutputStream {
    public static void main(String[] args) {
        FileOutputStream fos = null;
        byte[] buffer = new byte[81];
        int nBytes;
        try {
            System.out.println("Escribir el texto a guardar en el archivo: ");
            /** Save the text written by the user */
            nBytes = System.in.read(buffer);
            /** Create/Save the file */
            fos = new FileOutputStream("fos.txt");
            /** Write on the file the text saved before */
            fos.write(buffer, 0, nBytes);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            try{
                if(fos != null){
                    /** Close the file */
                    fos.close();
                }
            } catch (IOException e) {
                System.out.println("Error al cerrar el archivo: " + e.getMessage());
            }
        }
    }
}
