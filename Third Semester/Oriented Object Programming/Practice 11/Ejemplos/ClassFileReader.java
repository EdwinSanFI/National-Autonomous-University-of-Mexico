import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ClassFileReader {
    public static void main(String[] args) {
        String texto = "";
        try {
            BufferedReader br;
            FileReader fr = new FileReader("leer.txt");
            br = new BufferedReader(fr);
            System.out.println("El texto contenido en el archivo leer.txt es: ");
            String linea = br.readLine();
            while (linea != null) {
                System.out.println(linea);
                linea = br.readLine();
            }
            br.close();
        } catch (IOException e) {
            System.out.println("\n\nError al abrir o guardar el archivo:");
            e.printStackTrace();
        }
        catch (Exception e){
            System.out.println("\n\n Error al leer de teclado: ");
            e.printStackTrace();
        }
    }
}
