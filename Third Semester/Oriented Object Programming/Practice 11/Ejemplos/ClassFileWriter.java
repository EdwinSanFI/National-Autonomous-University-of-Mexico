/**
 * @Author: Edwin Jaret Santiago Díaz
 * The above class writes a text file to the current directory
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;

public class ClassFileWriter {
    public static void main(String[] args) {
        String texto = "";
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Escribir el texto a guardar en el archivo: ");
            texto = br.readLine();
            FileWriter fw = new FileWriter("archivo2.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter salida = new PrintWriter(bw);
            salida.println(texto);
            salida.close();
        } catch (IOException e) {
            System.out.println("\n\nError al abrir o guardar el archivo:");
            e.printStackTrace();
        } catch (Exception e) {
            System.out.println("\n\nError al leer de teclado: ");
            e.printStackTrace();
        }
    }
}
