/**
 * @Author: Edwin Santiago
 */

package Animales;
import java.util.*;
import Animales.Acuaticos.*;
import Animales.Terrestres.*;
import Animales.Aereos.*;

/** Clase main */
public class main {
    /** Crea un ArrayList de tipo Animal */
    static ArrayList<Animal> animales = new ArrayList<Animal>();

    /** Metodo main */
    public static void main(String[] args) {

        /**Instancia un objeto para capturar datos del usuario */
        Scanner sc = new Scanner(System.in);
        /** Guarda los animales que se registran por el usuario */
        int[] opciones = {0,0,0,0,0,0,0,0,0};
        /** Opcion para registrar el animal, 9 opciones disponibles */
        int opcion = 0;
        /** Opcion del menu, 4 opciones disponibles */
        int opcion_general = 0;

        System.out.println("====================");
        System.out.println("Catalogo de animales");
        System.out.println("====================");

        /** Guarda los animales terrestres */
        String animales_terrestres = "\n1. Cabra"
        +"\n2. Panda"
        +"\n3. Tigre";

        /** Guarda los animales aereos */
        String animales_aereos = "\n4. Paloma"
        +"\n5. Aguila"
        +"\n6. Ave";

        /** Guarda los animales acuaticos */
        String animales_acuaticos = "\n7. Tiburon"
        +"\n8. Ajolote"
        +"\n9. Tortuga";

        /** Se ejecutara siempre y cuando la opcion ingresada sea distinto a 4 */
        do {
            System.out.println("\nQue desea hacer?");
            System.out.println("1. Agregar animal");
            System.out.println("2. Ver un animal");
            System.out.println("3. Ver catalogo");
            System.out.println("4. Salir\n");
            opcion_general = sc.nextInt();
            sc.nextLine();
            switch (opcion_general) {
                case 1: /** Agrega un animal */
                    System.out.println("\nQue animal desea agregar?");
                    System.out.println(animales_terrestres);
                    System.out.println(animales_aereos);
                    System.out.println(animales_acuaticos);
                    System.out.println("Solo se puede escoger el animal 1 vez");
                    /** Guarda el numero del animal a registrar */
                    opcion = sc.nextInt();
                    sc.nextLine();
                    /** Si el animal a agregar ya fue agregado previamente */
                    if (contains(opciones, opcion)) {
                        System.out.println("\nYa se ha escogido este animal, escoge otro\n");
                    }
                    /** Si el animal no ha sido agregado */
                    else {
                        switch (opcion) {
                            case 1: /** Agrega una cabra */
                                animales.add(new Cabra());
                                opciones[opcion-1] = 1;
                                System.out.println("Cabra agregada\n");
                                break;
                            case 2: /** Agrega un panda */
                                animales.add(new Panda());
                                opciones[opcion-1] = opcion;
                                System.out.println("Panda agregada\n");
                                break;
                            case 3: /** Agrega un tigre */
                                animales.add(new Tigre());
                                opciones[opcion-1] = opcion;
                                System.out.println("Tigre agregado\n");
                                break;
                            case 4: /** Agrega una paloma */
                                animales.add(new Paloma());
                                opciones[opcion-1] = opcion;
                                System.out.println("Paloma agregada\n");
                                break;
                            case 5: /** Agrega una aguila */
                                animales.add(new Aguila());
                                opciones[opcion-1] = opcion;
                                System.out.println("Aguila agregada\n");
                                break;
                            case 6: /** Agrega una Ave */
                                animales.add(new Ave());
                                opciones[opcion-1] = opcion;
                                System.out.println("Ave agregada\n");
                                break;
                            case 7: /** Agrega un Tiburon */
                                animales.add(new Tiburon());
                                opciones[opcion-1] = opcion;
                                System.out.println("Tiburon agregado\n");
                                break;
                            case 8: /** Agrega un ajolote */
                                animales.add(new Ajolote());
                                opciones[opcion-1] = opcion;
                                System.out.println("Ajolote agregado\n");
                                break;
                            case 9: /** Agrega una tortuga */
                                animales.add(new Tortuga());
                                opciones[opcion-1] = opcion;
                                System.out.println("Tortuga agregada\n");
                                break;
                            default: /** Si no ingreso un numero valido */
                                System.out.println("Opcion invalida");
                                break;
                        }
                    }
                    break;
                case 2: /** Imprime el comportamiento de un animal solo si este fue agregado por el usuario */
                    System.out.println("Que animal desea ver?");
                    System.out.println(animales_terrestres);
                    System.out.println(animales_aereos);
                    System.out.println(animales_acuaticos);
                    /** Captura el numero de animal que desea ver */
                    opcion = sc.nextInt();
                    sc.nextLine();
                    /** Valida que este animal ya fue registrado */
                    if (contains(opciones, opcion)) {
                        /** Ejecuta el metodo para ver los comportamientos de un animal */
                        ejecutar_metodos_animales(opcion);
                    }
                    /** Si un animal no ha sido registrado */
                    else {
                        System.out.println("\nEste animal no se ha agregado, intente agreaglo!\n");
                    }
                    break;

                case 3: /** Muestra los animales guardados por el usuario */
                    /** Si el ArrayList tiene elementos guardados */
                    if (!animales.isEmpty()) {
                        System.out.println("Mostrar todos los animales guardados\n");
                        /** Recorre el ArrayList e imprime el nombre de las clases */
                        for (int i = 0; i < animales.size(); i++) {
                            System.out.println(animales.get(i).getClass().getSimpleName());
                        }
                    }
                    /** Si no tiene elementos guardados */
                    else {
                        System.out.println("\nNo hay animales guardados\n");
                    }
                    break;
                case 4: /** Para salir del programa */
                    System.out.println("\nSaliendo del programa\n");
                    break;
                default: /** Si ingresa cualquier otro numero distinto de 1, 2, ,3 o 4 */
                    System.out.println("Opcion no valida");
                    break;
            }
        } while (opcion_general != 4);
    }

    /**
     * Metodo que valida si un numero esta en un arreglo
     * @param arr arreglo de enteros
     * @param key numero a buscar
     * @return true si el numero esta en el arreglo, false si no
     */
    public static boolean contains(final int[] arr, final int key) {
        return Arrays.stream(arr).anyMatch(i -> i == key);
    }

    /**
     * Metodo que ejecuta los metodos de un animal
     * @param opcion numero de animal a ejecutar
     */
    public static void ejecutar_metodos_animales(int opcion) {
        switch (opcion) {
            case 1: /** Imprime los metodos de la cabra */
                System.out.println("\n\tCabra");
                new Cabra().ver();
                break;
            case 2: /** Imprime los metodos del panda */
                System.out.println("\n\tPanda");
                new Panda().ver();
                break;
            case 3: /** Imprime los metodos del tigre */
                System.out.println("\n\tTigre");
                new Tigre().ver();
                break;
            case 4: /** Imprime los metodos de la paloma */
                System.out.println("\n\tPaloma");
                new Paloma().ver();
                break;
            case 5: /** Imprime los metodos de la aguila */
                System.out.println("\n\tAguila");
                new Aguila().ver();
                break;
            case 6: /** Imprime los metodos de la ave */
                System.out.println("\n\tAve");
                new Ave().ver();
                break;
            case 7: /** Imprime los metodos del tiburon */
                System.out.println("\n\tTiburon");
                new Tiburon().ver();
                break;
            case 8: /** Imprime los metodos del ajolote */
                System.out.println("\n\tAjolote");
                new Ajolote().ver();
                break;
            case 9: /** Imprime los metodos de la tortuga */
                System.out.println("\n\tTortuga");
                new Tortuga().ver();
                break;
            default:
                System.out.println("\nOpcion no valida");
                break;
        }
    }
}