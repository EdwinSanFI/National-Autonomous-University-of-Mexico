import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class EjScanner {
    public static void main(String[] args) {
        /** Information container */
        File archivo = new File("archivo.txt");
        Scanner sc;
        try {
            sc = new Scanner(archivo);
            sc.useDelimiter("/");
            while (sc.hasNext()) {
                System.out.println(sc.next());
            }
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}