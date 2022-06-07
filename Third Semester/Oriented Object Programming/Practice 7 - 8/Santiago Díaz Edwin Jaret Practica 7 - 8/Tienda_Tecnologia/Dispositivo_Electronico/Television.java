package Tienda_Tecnologia.Dispositivo_Electronico;

public class Television implements Dispositivo_Electronico{
    String nombre;
    Double precio;

    public Television(String nombre, Double precio) {
        setNombre(nombre);
        setPrecio(precio);
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public String getNombre() {
        return nombre;
    }
    public void setPrecio(double precio) {
        this.precio = precio;
    }
    public double getPrecio() {
        return precio;
    }

    public void encender() {
        System.out.println("Encendiendo Television");
    }
    public void apagar() {
        System.out.println("Apagando Television");
    }
    public void reiniciar() {
        System.out.println("Reiniciando Television");
    }

    /** Metodos de una television */
    public void subirVolumen() {
        System.out.println("Subiendo volumen");
    }
    public void bajarVolumen() {
        System.out.println("Bajando volumen");
    }
    public void cambiarCanal() {
        System.out.println("Cambiando canal");
    }
}
