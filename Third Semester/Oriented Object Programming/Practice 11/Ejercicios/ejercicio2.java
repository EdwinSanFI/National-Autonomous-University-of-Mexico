/**
 * @author Edwin Jaret Santiago Díaz
 */

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.io.ObjectOutputStream;

public class ejercicio2 {
    public static void main(String[] args) {
        int opcion;
        String nombreArchivo;
        Scanner sc = new Scanner(System.in);
        try {
            do {
                System.out.println("\n1. Convertir archivo de texto a binario");
                System.out.println("2. Convertir archivo binario a texto plano");
                System.out.println("3. Salir");
                opcion = sc.nextInt();
                switch (opcion) {
                    case 1:
                        System.out.println("Ingrese el nombre del archivo con su extension");
                        try {
                            nombreArchivo = sc.next();
                            File archivo = new File(nombreArchivo);
                            FileOutputStream fos = new FileOutputStream(archivo);
                            ObjectOutputStream oos = new ObjectOutputStream(fos);
                            System.out.println("\nCreado!\n");
                            oos.writeObject(archivo);
                            oos.close();
                            fos.close();
                        } catch (IOException e) {
                            System.out.println("Error al convertir el archivo");
                        }
                        break;
                    case 2:
                        System.out.println("Ingrese el nombre del archivo");
                        try {
                            nombreArchivo = sc.next();
                            File archivo2 = new File(nombreArchivo);
                            FileReader fr = new FileReader(archivo2);
                            PrintWriter pw = new PrintWriter(new FileWriter(archivo2));
                            int c;
                            while ((c = fr.read()) != -1) {
                                pw.print((char) c);
                            }
                            pw.close();
                            fr.close();
                            System.out.println("\nCreado!\n");
                        } catch (Exception e) {
                            System.out.println("Error al convertir el archivo");
                        }
                        break;
                    case 3:
                        System.out.println("Saliendo...");
                        break;
                    default:
                        System.out.println("Opción no válida");
                }
            } while (opcion != 3);
        } catch (InputMismatchException e) {
            System.out.println("Dato ingresado no correcto");
        }
    }
}
