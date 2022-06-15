package Slot.Awards;

public class Clover implements Awards {
    private int fiveClovers = 2_500;
    private int fourClovers = 1_250;
    private int threeClovers = 650;
    private String name = "Clover";
    private String color = "\033[37m";

    public String getName(){
        return "  "+name+"  ";
    }
    public String getNameString(){
        return name;
    }

    /** Return the award for 5 clovers */
    public int getFive(){
        return fiveClovers;
    }
    /** Return the award for 4 clovers */
    public int getFour(){
        return fourClovers;
    }
    /** Return the award for 3 clovers */
    public int getThree(){
        return threeClovers;
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
