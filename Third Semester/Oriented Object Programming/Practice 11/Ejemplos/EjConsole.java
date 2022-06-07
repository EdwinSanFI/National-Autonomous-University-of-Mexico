/**
 * The Console class is used to read passwords and other sensitive information from the console.
 */
import java.io.Console;

public class EjConsole {
    public static void main(String[] args) {
        Console console = System.console();
        System.out.println("Usuario: ");
        String usuario = console.readLine();
        System.out.println("Contraseña: ");
        char[] contrasena = console.readPassword();
        System.out.println(contrasena);
    }
}