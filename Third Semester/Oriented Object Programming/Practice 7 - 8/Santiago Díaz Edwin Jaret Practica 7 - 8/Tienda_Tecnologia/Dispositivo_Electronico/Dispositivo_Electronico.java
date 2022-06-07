package Tienda_Tecnologia.Dispositivo_Electronico;

public interface Dispositivo_Electronico {
    void setNombre(String nombre);
    String getNombre();
    void setPrecio(double precio);
    double getPrecio();
    void encender();
    void apagar();
    void reiniciar();
}
