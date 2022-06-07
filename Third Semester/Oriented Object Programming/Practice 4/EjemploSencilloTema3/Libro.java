

public class Libro {
    static int numLibros;
    String titulo;
    int numPaginas;
    String autor;
    short añoPublicacion;
    double precio;
    
    public Libro (String titulo, String autor){
        numLibros++;
        this.titulo=titulo;
        this.autor=autor;
    }
    public void leer(){
        System.out.println("Habia una vez...");
    }
    
    public void fotocopiar(){
        numLibros++;
        System.out.println("Ahora tengo uno más");
       
    }
    public void vender(){
        System.out.println(this.titulo + " ha sido vendido");
        mostrarNumLibros();
    }
    public static void mostrarNumLibros(){
        System.out.println("Hay "+ numLibros + " en este momento");
    }

    @Override
    public String toString() {
        return "Libro{" + "titulo=" + titulo + ", autor=" + autor + '}';
    }
    
    
}









