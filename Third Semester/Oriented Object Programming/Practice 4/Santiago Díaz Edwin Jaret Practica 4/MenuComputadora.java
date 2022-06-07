/**
 * @author: Edwin Santiago
 */

import java.util.*;

public class MenuComputadora {
    public static void main(String[] args) {
        System.out.println("\t**Practica 4**");

        // Se instancia un objeto para capturar datos
        Scanner sc = new Scanner(System.in);
        int opcion = 1;
        // Se instancia un objeto computadora
        Computadora compu = new Computadora();
        do {
            System.out.println("\nEscoge una de las siguientes opciones: ");
            System.out.println("1.- Crear una computadora");
            System.out.println("2.- Modificar una computadora");
            System.out.println("3.- Ver las computadoras guardadas");
            System.out.println("4.- Eliminar una computadora");
            // Se guarda la opcion deseada
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                // Funcion estatica, crea una computadora
                    Computadora.crearComputadora();
                    break;
                case 2:
                // Modifica los datos de una computadora
                    compu.modificarComputadora();
                    break;
                case 3:
                // Imprime las computadoras guardadas
                    compu.verComputadorasActuales();
                    break;
                case 4:
                // Funcion estatica, elimina una computadora
                    Computadora.elminarComputadora();
                    break;
                default:
                    System.out.println("Esa opcion no esta disponible :(");
                    break;
            }
        } while (opcion <= 4 && opcion >0);
    }
}