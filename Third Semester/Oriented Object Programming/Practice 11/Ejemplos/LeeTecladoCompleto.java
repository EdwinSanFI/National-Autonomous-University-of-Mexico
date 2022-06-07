import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
public class LeeTecladoCompleto {
    public static void main(String[] args) {
        String texto = "";
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Escribir el texto a guardar en el archivo: ");
            texto = br.readLine();
            System.out.println("\n\nEl texto separado por espacios es: ");
            StringTokenizer st = new StringTokenizer(texto);
            while (st.hasMoreTokens()) {
                System.out.println(st.nextToken());
            }
        } catch (IOException e) {
            System.out.println("Error al leer caracteres: \n");
            e.printStackTrace();
        }
    }
}
