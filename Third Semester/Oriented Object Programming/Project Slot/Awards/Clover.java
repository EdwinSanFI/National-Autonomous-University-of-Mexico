package Awards;

public class Clover implements Awards {
    private int cincoTreboles = 2_500;
    private int cuatroTreboles = 1_250;
    private int tresTreboles = 650;
    private String name = "Clover";
    private String color = "\033[37m";

    public String getName(){
        return "  "+name+"  ";
    }
    public String getNomString(){
        return name;
    }
    public void setNomString(String name){
        this.name = name;
    }
    public int getCinco(){
        return cincoTreboles;
    }
    public int getCuatro(){
        return cuatroTreboles;
    }
    public int getTres(){
        return tresTreboles;
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
        return new Clover();
    }
}
