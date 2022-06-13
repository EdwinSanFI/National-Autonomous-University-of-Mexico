package Awards;

public class Seven implements Awards {
    private int cincoSietes = 50_000;
    private int cuatroSietes = 25_000;
    private int tresSietes = 10_000;
    private String name = "Siete";
    private String color = "\033[37m";

    public String getName(){
        return "   "+name+"  ";
    }
    public String getNomString(){
        return name;
    }
    public void setNomString(String name){
        this.name = name;
    }

    public int getCinco(){
        return cincoSietes;
    }
    public int getCuatro(){
        return cuatroSietes;
    }
    public int getTres(){
        return tresSietes;
    }

    /** Agregar metodo que guarde y regrese color */
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }

    /** Patron de diseño Prototype */
    public Awards clone() {
        return new Seven();
    }
}
