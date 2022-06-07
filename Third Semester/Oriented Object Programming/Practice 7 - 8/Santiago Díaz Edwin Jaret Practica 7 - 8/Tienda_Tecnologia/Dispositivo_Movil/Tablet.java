package Tienda_Tecnologia.Dispositivo_Movil;

public class Tablet extends Dispositivo_Movil {
    public Tablet(String nombre, Double precio) {
        super(nombre, precio);
    }
    @Override
    public void encender() {
        System.out.println("Encendiendo tablet");
    }
    @Override
    public void apagar() {
        System.out.println("Apagando tablet");
    }
    @Override
    public void reiniciar() {
        System.out.println("Reiniciando tablet");
    }
}
