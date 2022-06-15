package Slot.Awards;

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

    /** Return the award for 5 grapes */
    public int getFive(){
        return cincoUvas;
    }
    /** Return the award for 4 grapes */
    public int getFour(){
        return cuatroUvas;
    }
    /** Return the award for 3 grapes */
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