package Tienda_Tecnologia.Dispositivo_Movil;

public class Celular extends Dispositivo_Movil{
    String nombre;
    Double precio;
    public Celular(String nombre, Double precio) {
        super(nombre, precio);
        this.nombre = nombre;
        this.precio = precio;
    }
    // Funciones de un telefono movil
    /** Metodos de la clase Celular */
    public void llamar() {
        System.out.println("Llamando...");
    }
    public void enviarMensaje() {
        System.out.println("Enviando mensaje...");
    }
    /** Metodos que se sobrescriben */
    @Override
    public void encender() {
        System.out.println("Encendiendo celular");
    }
    @Override
    public void apagar() {
        System.out.println("Apagando celular");
    }
    @Override
    public void reiniciar() {
        System.out.println("Reiniciando celular");
    }
}
