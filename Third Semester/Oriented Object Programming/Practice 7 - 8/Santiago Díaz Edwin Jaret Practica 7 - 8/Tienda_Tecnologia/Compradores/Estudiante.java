package Tienda_Tecnologia.Compradores;
import java.util.*;
import Tienda_Tecnologia.Dispositivo_Movil.*;
import Tienda_Tecnologia.Dispositivo_Electronico.*;

public class Estudiante extends Comprador{

    int total, cantidad_productos;

    /** Se crea un HashMap para guardar los dispostivos moviles disponibles para el Estudiante */
    HashMap<Dispositivo_Movil, Double> dispositivos_moviles = new HashMap<Dispositivo_Movil, Double>();
    /** Se instancian los objetos del Estudiante */
    Smartphone smartphone1 = new Smartphone("Apple", 1200.0);
    Smartphone smartphone2 = new Smartphone("Xiaomi", 600.0);

    /** Se crea un HashMap para guardar los dispostivos electronicos disponibles para el Estudiante */
    HashMap<Dispositivo_Electronico, Double> dispositivos_electronicos = new HashMap<Dispositivo_Electronico, Double>();
    /** Se instancian los objetos del Estudiante */
    Computadora computadora1 = new Computadora("MacBook",1600.0);
    Computadora computadora2 = new Computadora("Asus", 1900.0);
    Computadora computadora3 = new Computadora("Hp", 1200.0);
    Laptop laptop1 = new Laptop("Lenovo",1800.0);
    Laptop laptop2 = new Laptop("Asus", 2000.0);
    Laptop laptop3 = new Laptop("Acer", 1500.0);

    /** Se agregan los dipositivos moviles creados a los HashMaps correspondientes */
    public Estudiante(){
        dispositivos_moviles.put(smartphone1, smartphone1.getPrecio());
        dispositivos_moviles.put(smartphone2, smartphone2.getPrecio());
        dispositivos_electronicos.put(computadora1, computadora1.getPrecio());
        dispositivos_electronicos.put(computadora2, computadora2.getPrecio());
        dispositivos_electronicos.put(computadora3, computadora3.getPrecio());
        dispositivos_electronicos.put(laptop1, laptop1.getPrecio());
        dispositivos_electronicos.put(laptop2, laptop2.getPrecio());
        dispositivos_electronicos.put(laptop3, laptop3.getPrecio());
    }

    @Override
    /** Se imprimen los dispositivos moviles */
    public void imprimirLista(){
        int i = 1;
        System.out.println("\nDispositivos moviles para el Estudiante:\n");
        for(Map.Entry<Dispositivo_Movil, Double> entry : dispositivos_moviles.entrySet()){
            System.out.println("\t "+i+" "+entry.getKey().getClass().getSimpleName()+": "+entry.getKey().getNombre() + " " + entry.getValue());
            i++;
        }
        /** Se imprimen los dispositivos electronicos */
        System.out.println("\nDispositivos electronicos para el Estudiante:\n");
        for(Map.Entry<Dispositivo_Electronico, Double> entry : dispositivos_electronicos.entrySet()){
            System.out.println("\t "+i+" "+entry.getKey().getClass().getSimpleName()+": "+entry.getKey().getNombre() + " " + entry.getValue());
            i++;
        }
        System.out.println("\nIngrese 77 para terminar de comprar\n");
    }

    @Override
    public void procesoCompra() {
        Scanner sc = new Scanner(System.in);
        int opcion = 0;
        do {
            System.out.println("Que desea comprar?");
            opcion = sc.nextInt();
            sc.nextLine();
            if(opcion > 0 && opcion <= dispositivos_moviles.size()){
                System.out.println("Cuanto desea comprar?");
                int cantidad = sc.nextInt();
                if(cantidad > 0){
                    if(cantidad <= dispositivos_moviles.get(dispositivos_moviles.keySet().toArray()[opcion-1]) && cantidad <= dispositivos_moviles.get(dispositivos_moviles.keySet().toArray()[opcion-1])){
                        System.out.println("\nDispositivo agregado al carrito\n");
                        cantidad_productos += cantidad;
                        total+=dispositivos_moviles.get(dispositivos_moviles.keySet().toArray()[opcion-1])*cantidad;
                    }else{
                        System.out.println("No hay suficiente stock");
                    }
                }else{
                    System.out.println("No se puede comprar una cantidad negativa");
                }
            } else if(opcion > dispositivos_moviles.size() && opcion <= dispositivos_electronicos.size()+2){
                System.out.println("Cuanto desea comprar?");
                int cantidad = sc.nextInt();
                if(cantidad > 0){
                    if(cantidad <= dispositivos_electronicos.get(dispositivos_electronicos.keySet().toArray()[opcion-3]) && cantidad <= dispositivos_electronicos.get(dispositivos_electronicos.keySet().toArray()[opcion-3])){
                        System.out.println("\nDispositivo agregado al carrito\n");
                        cantidad_productos += cantidad;
                        total+=dispositivos_electronicos.get(dispositivos_electronicos.keySet().toArray()[opcion-3])*cantidad;
                    }else{
                        System.out.println("No hay suficiente stock");
                    }
                }
                else{
                    System.out.println("No se puede comprar una cantidad negativa");
                }
            } else {
                System.out.println("\nNo existe ese producto, intente de nuevo\n");
            }
        } while (opcion != 77);
        System.out.println("\nTotal de productos: "+cantidad_productos);
        System.out.println("Total a pagar: "+total+"\n");
    }
}
