package Awards;

public class Grape implements Awards {

    private int cincoUvas = 650;
    private int cuatroUvas = 325;
    private int tresUvas = 160;
    private String name = "Uva";
    private String color = "\033[37m";

    /** Obtiene y asigna el nombre */
    public String getName() {
        return "    "+name+"   ";
    }
    public String getNameString(){
        return name;
    }
    public void setNameString(String name){
        this.name = name;
    }

    /** Obtiene los 3 posibles premios */
    public int getFive(){
        return cincoUvas;
    }
    public int getFour(){
        return cuatroUvas;
    }
    public int getThree(){
        return tresUvas;
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
        return new Grape();
    }
}