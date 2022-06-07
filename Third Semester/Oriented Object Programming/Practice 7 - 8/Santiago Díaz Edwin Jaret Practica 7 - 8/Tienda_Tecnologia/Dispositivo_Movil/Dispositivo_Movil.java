package Tienda_Tecnologia.Dispositivo_Movil;

public abstract class Dispositivo_Movil {
    private String nombre;
    private Double precio;

    protected Dispositivo_Movil(String nombre, Double precio) {
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

    public abstract void encender();
    public abstract void apagar();
    public abstract void reiniciar();

}
