package Tienda_Tecnologia.Compradores;
import java.util.*;
import Tienda_Tecnologia.Dispositivo_Electronico.*;

public class ClienteVip extends Comprador{

    int total, cantidad_productos;

    /** Se crea un HashMap para guardar los dispostivos disponibles para el Cliente VIP */
    HashMap<Dispositivo_Electronico, Double> dispositivos = new HashMap<Dispositivo_Electronico, Double>();

    /** Se instancian los objetos del Cliente VIP */
    Computadora computadora1 = new Computadora("MacBook",1600.0);
    Computadora computadora2 = new Computadora("Asus", 1900.0);
    Computadora computadora3 = new Computadora("Hp", 1200.0);
    Laptop laptop1 = new Laptop("Lenovo",1800.0);
    Laptop laptop2 = new Laptop("Asus", 2000.0);
    Laptop laptop3 = new Laptop("Acer", 1500.0);
    Television television1 = new Television("LG", 1000.0);
    Television television2 = new Television("Samsung", 1200.0);
    Television television3 = new Television("Sony", 1000.0);
    PC pc1 = new PC("MacBook", 1600.0);
    PC pc2 = new PC("Asus", 1900.0);
    PC pc3 = new PC("Hp", 1200.0);

    /** Se agregan los dipositivos electronicos creados al HashMap */
    public ClienteVip(){
        dispositivos.put(computadora1, computadora1.getPrecio());
        dispositivos.put(computadora2, computadora2.getPrecio());
        dispositivos.put(computadora3, computadora3.getPrecio());
        dispositivos.put(laptop1, laptop1.getPrecio());
        dispositivos.put(laptop2, laptop2.getPrecio());
        dispositivos.put(laptop3, laptop3.getPrecio());
        dispositivos.put(television1, television1.getPrecio());
        dispositivos.put(television2, television2.getPrecio());
        dispositivos.put(television3, television3.getPrecio());
        dispositivos.put(pc1, pc1.getPrecio());
        dispositivos.put(pc2, pc2.getPrecio());
        dispositivos.put(pc3, pc3.getPrecio());
    }

    @Override
    /** Se imprimen los dispositivos electronicos */
    public void imprimirLista(){
        System.out.println("\nDispositivos electronicos disponibles para Cliente VIP:\n");
        int i = 1;
        for(Map.Entry<Dispositivo_Electronico, Double> entry : dispositivos.entrySet()){
            System.out.println("\t "+i+" "+entry.getKey().getClass().getSimpleName()+": "+entry.getKey().getNombre() + " " + entry.getValue());
            i += 1;
        }
        System.out.println("\nEliga 77 si desea salir del programa\n");
    }

    @Override
    public void procesoCompra() {
        Scanner sc = new Scanner(System.in);
        int opcion = 0;
        do {
            System.out.println("Que desea comprar?");
            opcion = sc.nextInt();

            if(opcion > 0 && opcion <= dispositivos.size()){
                System.out.println("Cuanto desea comprar?");
                int cantidad = sc.nextInt();
                if(cantidad > 0){
                    if(cantidad <= dispositivos.get(dispositivos.keySet().toArray()[opcion-1])){
                        System.out.println("\nDispositivo agregado al carrito\n");
                        cantidad_productos += cantidad;
                        total+=dispositivos.get(dispositivos.keySet().toArray()[opcion-1])*cantidad;
                    }else{
                        System.out.println("No hay suficiente stock");
                    }
                }else{
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
