/**
 * @author Edwin Jaret Santiago Díaz
 */

import java.util.Scanner;

public class ejercicio3 {
    public static void main(String[] args) {
        int opcion;
        Scanner sc = new Scanner(System.in);
        Alumnos alumnoNuevo = new Alumnos();
        String nombreArchivo = "listaAlumnos";
        do {
            System.out.println("\nEscoge una opcion: ");
            System.out.println("1.- Crear Lista");
            System.out.println("2.- Ver Lista");
            System.out.println("3.- Salir");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    alumnoNuevo.crearAlumno(nombreArchivo);
                    break;
                case 2:
                    alumnoNuevo.verLista(nombreArchivo);
                    break;
                case 3:
                    System.out.println("\nSaliendo...");
                    break;
                default:
                    System.out.println("\nOpcion no valida...");
                    break;
            }
        } while (opcion != 3);
    }
}
