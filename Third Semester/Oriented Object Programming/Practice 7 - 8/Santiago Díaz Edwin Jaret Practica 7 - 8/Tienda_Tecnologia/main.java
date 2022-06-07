package Tienda_Tecnologia;
import java.util.*;
import Tienda_Tecnologia.Compradores.*;
import Tienda_Tecnologia.Dispositivo_Movil.*;
/**
 * main
 */
public class main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("\tPractica 7 - 8\n");
        System.out.println("Bienvenido a la tienda de tecnologia!\n");
        System.out.println("Compradores: ");
        System.out.println("1. Socio");
        System.out.println("2. Estudiante");
        System.out.println("3. ClienteVip");
        System.out.println("Que tipo de comprador eres?");
        int opcion = sc.nextInt();

        switch (opcion) {
            case 1:
                Socio comprador = new Socio();
                comprador.imprimirLista();
                comprador.procesoCompra();
                break;
            case 2:
                Estudiante estudiante = new Estudiante();
                estudiante.imprimirLista();
                estudiante.procesoCompra();
                break;
            case 3:
                ClienteVip clienteVip = new ClienteVip();
                clienteVip.imprimirLista();
                clienteVip.procesoCompra();
                break;
            default:
                System.out.println("Opcion invalida");
                break;
        }
    }
}