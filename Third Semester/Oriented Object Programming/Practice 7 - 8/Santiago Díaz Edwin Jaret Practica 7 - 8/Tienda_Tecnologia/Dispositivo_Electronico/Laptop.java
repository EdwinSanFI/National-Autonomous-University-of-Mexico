package Tienda_Tecnologia.Dispositivo_Electronico;

public class Laptop extends Computadora{
    String nombre;
    Double precio;

    public Laptop(String nombre, Double precio) {
        super(nombre, precio);
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

    /** Sobreescritura */
    @Override
    public void encender() {
        System.out.println("Encendiendo laptop");
    }
    @Override
    public void apagar() {
        System.out.println("Apagando laptop");
    }
    @Override
    public void reiniciar() {
        System.out.println("Reiniciando laptop");
    }

    /** Metodos propios de la clase Laptop */
    public void guardar() {
        System.out.println("Guardando laptop");
    }
    public void cargar() {
        System.out.println("Cargando laptop");
    }
}
