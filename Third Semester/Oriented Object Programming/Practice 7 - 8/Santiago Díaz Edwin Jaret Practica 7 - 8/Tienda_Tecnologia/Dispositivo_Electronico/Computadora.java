package Tienda_Tecnologia.Dispositivo_Electronico;

public class Computadora implements Dispositivo_Electronico{
    private String nombre;
    private Double precio;

    public Computadora (String nombre, Double precio){
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
        System.out.println("Encendiendo computadora");
    }
    public void apagar() {
        System.out.println("Apagando computadora");
    }
    public void reiniciar() {
        System.out.println("Reiniciando computadora");
    }

    /** Metodos de una computadora */
    public void revisarCorreo() {
        System.out.println("Revisando correo");
    }
    public void cargarMemoria() {
        System.out.println("Cargando memoria");
    }
    public void navegarInternet() {
        System.out.println("Navegando en internet");
    }
}
