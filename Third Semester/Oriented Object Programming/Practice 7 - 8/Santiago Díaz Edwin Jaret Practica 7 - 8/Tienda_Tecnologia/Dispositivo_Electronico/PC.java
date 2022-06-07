package Tienda_Tecnologia.Dispositivo_Electronico;

public class PC extends Computadora{
    String nombre;
    Double precio;
    public PC(String nombre, Double precio) {
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
        System.out.println("Encendiendo PC");
    }
    @Override
    public void apagar() {
        System.out.println("Apagando PC");
    }
    @Override
    public void reiniciar() {
        System.out.println("Reiniciando PC");
    }

    /** Metodos propios de la clase PC */
    public void encenderLuz() {
        System.out.println("Encendiendo luces RGB para tener mas FPS");
    }
    public void apagarLuz() {
        System.out.println("Apagando luces RGB para tener menos FPS");
    }
    public void streaming() {
        System.out.println("Streaming en vivo");
    }
}
