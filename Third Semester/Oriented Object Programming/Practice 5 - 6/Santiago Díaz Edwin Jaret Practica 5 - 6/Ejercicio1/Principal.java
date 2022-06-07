/**
 * @Author: Edwin Santiago
 */

package Ejercicio1;
import java.util.*;
public class Principal {
    public static void main(String[] args) {
        System.out.println("\n\t**Practica 5-6**");
        /** Objeto para capturar datos del usuario */
        Scanner sc = new Scanner(System.in);
        /** Opcion del usuario, se inicializa en 0 */
        int opcion = 1;

        do {
            /** Menu */
            System.out.println("\n1. Crear una division");
            System.out.println("2. Ver la informacion de una division");
            /** Captura la opcion ingresada por usuario */
            opcion = sc.nextInt();
            /** Evita que se salte una linea */
            sc.nextLine();
            switch (opcion) {
                case 1:
                    /** Crea una division */
                    System.out.println("\n\t**DIVISION**");
                    System.out.println("Cual es el nombre de la division?");
                    String nombreDivision = sc.nextLine();
                    System.out.println("Cual es el area de la division?");
                    String areaDivision = sc.nextLine();
                    System.out.println("Quien es el militar al mando?");
                    String militarAlMando = sc.nextLine();
                    /** Instancia un objeto de la clase Division con los parametros de la informacion guardada por el usuario */
                    Division nuevaDivision = new Division(nombreDivision, areaDivision,militarAlMando);
                    /** Guarda la division en el ArrayList */
                    Division.divisiones.add(nuevaDivision);

                    /** Crea 2 batallones */
                    for (int i = 1; i <= 2; i++) {
                        System.out.println("\n\t**BATALLON #"+i+"**");
                        System.out.println("Cual es el nombre del batallon?");
                        String nombreBatallon = sc.nextLine();
                        System.out.println("Cual es la especialidad del batallon?");
                        String especialidadBatallon = sc.nextLine();
                        System.out.println("Cual es la clave del batallon?");
                        int claveBatallon = sc.nextInt();
                        sc.nextLine();
                        /** Instancia un objeto de la clase Batallon con los parametros de la informacion guardada por el usuario*/
                        Batallon nuevoBatallon = new Batallon(nombreBatallon, especialidadBatallon, claveBatallon);
                        /** Agrega el batallon al ArrayList */
                        nuevaDivision.batallones.add(nuevoBatallon);
                        /** Incrementa el conteo de batallones */
                        Batallon.numeroBatallones += 1;

                        /** Crea 3 militares */
                        for (int j = 1; j <= 3; j++) {
                            System.out.println("\n\t**MILITAR #"+j+"**");
                            System.out.println("Cual es el nombre del militar?");
                            String nombreMilitar = sc.nextLine();
                            System.out.println("Cual es el apellido del militar?");
                            String apellidoMilitar = sc.nextLine();
                            System.out.println("Cual es la edad del militar?");
                            int edadMilitar = sc.nextInt();
                            sc.nextLine();
                            /** Instancia un objeto de la clase Militar con los parametros de la informacion guardada por el usuario */
                            Militar nuevoMilitar = new Militar(nombreMilitar, apellidoMilitar, edadMilitar);
                            /** Agregar militar al ArrayList */
                            nuevoBatallon.militares.add(nuevoMilitar);
                            /** Incrementa el conteo de militares */
                            Militar.numeroMilitares += 1;
                        }
                    }
                    break;
                case 2:
                    /** Imprime el contenido de las Divisiones */

                    System.out.println("\t\tNumero de Divisiones: "+Division.divisiones.size());
                    System.out.println("\t\tNumero de Batallones: "+Batallon.numeroBatallones);
                    System.out.println("\t\tNumero de Militares: "+Militar.numeroMilitares);
                    int i = 1;
                    /** Si hay Divisiones creadas */
                    if (Division.divisiones.size() != 0){
                        for (Division divisiones: Division.divisiones) {
                            /** Imprime la informacion de la Division */
                            System.out.println("\n\t\t++Division #"+i+"++");
                            divisiones.MostrarInformacion();
                            i += 1;
                        }
                    } else {
                        /** Si no hay Divisiones creadas */
                        System.out.println("\n\tNo hay divisiones creadas, intente crear una.");
                    }
                    break;
                default:
                    System.out.println("Intente de nuevo");
                    break;
            }
        } while (opcion < 3 && opcion >= 1);
        /** El menu se ejecuta siempre y cuando la opcion ingresada por el usuario sea menor que 3 y mayor o igual que 1 */
    }
}
