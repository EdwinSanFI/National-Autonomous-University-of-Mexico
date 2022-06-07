package Tienda_Tecnologia.Compradores;
import Tienda_Tecnologia.Dispositivo_Movil.*;
import java.util.*;

public class Socio extends Comprador {

    int total, cantidad_productos;
    /** Se crea un HashMap para guardar los dispostivos moviles disponibles para el Socio */
    HashMap<Dispositivo_Movil, Double> dispositivos = new HashMap<Dispositivo_Movil, Double>();

    /** Se instancian los objetos del Socio */
    Celular celular1 = new Celular("Samsung", 1000.0);
    Celular celular2 = new Celular("Apple", 1200.0);
    Celular celular3 = new Celular("Huawei", 1000.0);
    Tablet tablet1 = new Tablet("iPad 8", 2000.0);
    Tablet tablet2 = new Tablet("iPad Pro", 3000.0);
    Smartphone smartphone1 = new Smartphone("Samsung S20", 1000.0);
    Smartphone smartphone2 = new Smartphone("iPhone 11", 1200.0);
    Smartphone smartphone3 = new Smartphone("Huawei P20", 1000.0);


    public Socio(){
        /** Se agregan los dipositivos moviles creados a la lista */
        dispositivos.put(celular1, celular1.getPrecio());
        dispositivos.put(celular2, celular2.getPrecio());
        dispositivos.put(celular3, celular3.getPrecio());
        dispositivos.put(tablet1, tablet1.getPrecio());
        dispositivos.put(tablet2, tablet2.getPrecio());
        dispositivos.put(smartphone1, smartphone1.getPrecio());
        dispositivos.put(smartphone2, smartphone2.getPrecio());
        dispositivos.put(smartphone3, smartphone3.getPrecio());
    }

    @Override
    public void imprimirLista(){
        System.out.println("\nDispositivos moviles para el Socio:\n");
        int i = 1;
        for(Map.Entry<Dispositivo_Movil, Double> entry : dispositivos.entrySet()){
            System.out.println("\t "+i+" "+entry.getKey().getClass().getSimpleName()+": "+entry.getKey().getNombre() + " " + entry.getValue());
            i += 1;
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