import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class LeeTecladoBR {
    public static void main(String[] args) {
        try {
            String texto = "";
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Escribir el texto a guardar en el archivo: ");
            texto = br.readLine();
            System.out.println("El texto es: " + texto);
        } catch (IOException e) {
            System.out.println("Error al leer caracteres: \n"+ e);
        }
    }
}
