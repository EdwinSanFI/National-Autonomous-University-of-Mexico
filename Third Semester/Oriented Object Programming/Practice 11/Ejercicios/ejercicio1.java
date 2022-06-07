/**
 * @author Edwin Jaret Santiago Díaz
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class ejercicio1 {
    public static void main(String[] args) {
        int opcion;
        String nombreArchivo;
        String contenido;
        String contenidoArchivo;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            do {
                System.out.println("\n1. Crear archivo");
                System.out.println("2. Abrir archivo");
                System.out.println("3. Editar archivo");
                System.out.println("4. Salir");
                Scanner sc = new Scanner(System.in);
                opcion = sc.nextInt();
                switch (opcion) {
                    case 1:
                        System.out.println("Ingrese el nombre del archivo con su extension");
                        try {
                            nombreArchivo = br.readLine();
                            File archivo = new File(nombreArchivo);
                            archivo.createNewFile();
                        } catch (IOException e) {
                            System.out.println("Error al crear el archivo");
                        }
                        break;
                    case 2:
                        System.out.println("Ingrese el nombre del archivo con su extension");
                        nombreArchivo = sc.next();
                        File archivo2 = new File(nombreArchivo);
                        try {
                            Scanner sc2 = new Scanner(archivo2);
                            while (sc2.hasNextLine()) {
                                contenidoArchivo = sc2.nextLine();
                                System.out.println(contenidoArchivo);
                            }
                        } catch (FileNotFoundException e) {
                            System.out.println("Error al abrir el archivo");
                        }
                        break;
                    case 3:
                        System.out.println("Ingrese el nombre del archivo con su extension");
                        nombreArchivo = sc.next();
                        File archivo3 = new File(nombreArchivo);
                        try {
                            Scanner sc3 = new Scanner(archivo3);
                            while (sc3.hasNextLine()) {
                                contenidoArchivo = sc3.nextLine();
                                System.out.println(contenidoArchivo);
                            }
                            System.out.println("Ingrese el contenido del archivo");
                            contenido = br.readLine();
                            PrintWriter pw = new PrintWriter(new FileWriter(archivo3, true));
                            pw.println(contenido);
                            pw.close();
                        } catch (FileNotFoundException e) {
                            System.out.println("Error al abrir el archivo");
                        } catch (IOException e) {
                            System.out.println("Error al editar el archivo");
                        }
                        break;
                    case 4:
                        System.out.println("Saliendo...");
                        break;
                    default:
                        System.out.println("Opcion no valida");
                        break;
                }
            } while (opcion != 4 || opcion > 4);
        } catch (InputMismatchException e) {
            System.out.println("Error al ingresar la opcion");
        }
    }
}