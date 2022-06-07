/**
 * @author: Edwin Santiago
 */

import java.util.*;

// Clase computadora
public class Computadora {
    // Atributos
    private String nombre, procesador;
    int serieIndentificacion, modelo;

    // Instancias de objetos
    static ArrayList<Computadora> inventario = new ArrayList<>();
    Scanner sc = new Scanner(System.in);

    // Metodo constructor vacio
    public Computadora() {
    }
    // !Estos metodos constructores fueron parte del ejercicio de crear dos metodos distintos
    // Metodo constructor 1
    public Computadora(int serieIndentificacion, int modelo) {
        this.serieIndentificacion = serieIndentificacion;
        this.modelo = modelo;
    }
    // Metodo constructor 2
    public Computadora(String nombre, String procesador){
        this.nombre = nombre;
        this.procesador = procesador;
    }

    // !Esta sobrecarga fue parte del primer ejercicio
    // Metodo sobrecargado de 3 maneras
    public void imprimir(String mensaje, int clave, String destinatario){
        System.out.println(mensaje);
        System.out.println(clave);
        System.out.println(destinatario);
    }

    public void imprimir(String mensaje){
        System.out.println(mensaje);
    }

    public void imprimir(String mensaje, String destinatario){
        System.out.println(mensaje);
        System.out.println("Para: " + destinatario);
    }

    // Funcion main
    // ! Forma parte del ejercicio 3
    public static void main(String[] args) {
        // Creamos dos computadoras para el primer ejercicio
        Computadora compu1 = new Computadora("Lenovo Gaming", "Corei i-9");
        Computadora compu2 = new Computadora(91274101, 001212);

        // Es parte del primer ejercicio
        compu1.imprimir("Hola desde el futuro");
        compu2.imprimir("Hola desde el futuro", "EdwinSan");
    }

    // Metodos para el punto 2 del ejercicio
    public static void crearComputadora() {
        // Se instancia un objeto
        Computadora compuNueva = new Computadora();
        Scanner sc = new Scanner(System.in);

        // Se agrega el nombre de la computadora
        System.out.println("\nCual es el nombre/modelo de la comptuadora?");
        String nombreComputadora = sc.nextLine();
        compuNueva.setNombreComputadora(nombreComputadora);

        // Se agrega el procesador
        System.out.println("Que procesador tiene?");
        String procesadorComputadora = sc.nextLine();
        compuNueva.setProcesadorComputadora(procesadorComputadora);

        // Se agrega a la lista la comptudora creada
        inventario.add(compuNueva);
    }

    public  void modificarComputadora() {
        // Verifica si hay computadoras en el inventario (lista)
        Scanner sc = new Scanner(System.in);
        if (inventario.isEmpty()) {
            // Si no hay computadoras
            System.out.println("No hay computadoras guardadas D:");
        } else {
            // Si si hay computadoras
            System.out.println("\n¿Que computadora desea modificar?");
            // Imprime la lista de las comptudoras
            verComputadorasActuales();

            // Guarda el indice de la computadora a modificar
            System.out.println("Ingrese el indice");
            int indice = sc.nextInt();

            if(inventario.size() > indice && indice >= 0) {
                // Obtiene la computadora a traves del indice
                Computadora modificable = inventario.get(indice);

                // Cambia el nombre de la computadora
                System.out.println("Ingrese el nuevo nombre de la computadora");
                String nuevoNombre = sc.nextLine();

                // Cambia el procesador de la computadora
                System.out.println("Ingrese el nuevo procesador de la comptuadora");
                String nuevoProcesador = sc.nextLine();

                // Se asignan los valores nuevos a la computadora que se quiere modificar
                modificable.setProcesadorComputadora(nuevoProcesador);
                modificable.setNombreComputadora(nuevoNombre);
            } else {
                System.out.println("No se puede ese indice, lo siento");
            }
        }
    }

    public  void verComputadorasActuales() {

        if (inventario.isEmpty()) {
            System.out.println("No hay computadoras guardadas D:");
        } else {
            System.out.println("\nEstas son las computadoras guardadas:");

            // Se incializa el indice
            int i=0;

            // Imprime la lista de computadoras
            for(Computadora comp: inventario){
                System.out.println("Indice: "+i+", nombre: "+comp.getNombreComputadora()+", procesador: "+comp.getProcesadorComputadora());
                i+=1;
            }
        }
    }

    public static void elminarComputadora() {

        if (inventario.isEmpty()) {
            System.out.println("No hay computadoras guardadas D:");
        } else {
            Scanner sc = new Scanner(System.in);

            // Se incializa el indice
            int i = 0;

            // Imprime la lista de computadoras
            for(Computadora comp: inventario){
                System.out.println("Indice: "+i+", nombre: "+comp.getNombreComputadora()+", procesador: "+comp.getProcesadorComputadora());
                i+=1;
            }
            System.out.println("\n¿Que computadora desaas eliminar? Ingrese el indice: ");

            // Guarda el indice que va a borrar
            int indice = sc.nextInt();

            // Borra la computadora por el indice deseado
            inventario.remove(indice);
        }
    }

    // Asigna y/o regresa el nombre de al computadora actual
    public String getNombreComputadora(){
        return nombre;
    }

    public void setNombreComputadora(String nombre){
        this.nombre = nombre;
    }

    // Asigna y/o regresa el nombre del procesador actual
    public String getProcesadorComputadora(){
        return procesador;
    }

    public void setProcesadorComputadora(String procesador){
        this.procesador = procesador;
    }
}
