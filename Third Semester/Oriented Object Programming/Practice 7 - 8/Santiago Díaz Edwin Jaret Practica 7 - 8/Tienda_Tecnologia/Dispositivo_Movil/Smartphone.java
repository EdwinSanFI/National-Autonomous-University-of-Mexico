package Tienda_Tecnologia.Dispositivo_Movil;

public class Smartphone extends Celular {
    public Smartphone(String nombre, Double precio) {
        super(nombre, precio);
    }
    // Funciones de un telefono inteligente
    public void usarInternet() {
        System.out.println("Usando internet...");
    }
    public void usarGPS() {
        System.out.println("Usando GPS...");
    }
    public void tomandoFotos(){
        System.out.println("Tomando fotos...");
    }
}
