package Awards;

public class Watermelon implements Awards {
    private int cincoSandias = 650;
    private int cuatroSandias = 325;
    private int tresSandias = 160;
    private String name = "Sandia";
    private String color = "";

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
        return cincoSandias;
    }
    public int getCuatro(){
        return cuatroSandias;
    }
    public int getTres(){
        return tresSandias;
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
        return new Watermelon();
    }
}
