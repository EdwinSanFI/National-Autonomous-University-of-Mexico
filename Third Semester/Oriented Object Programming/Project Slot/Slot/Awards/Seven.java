package Slot.Awards;

public class Seven implements Awards {
    private int fiveSevens = 50_000;
    private int fourSevens = 25_000;
    private int threeSevens = 10_000;
    private String name = "Siete";
    private String color = "\033[37m";

    public String getName(){
        return "   "+name+"  ";
    }
    public String getNameString(){
        return name;
    }
    public void setNameString(String name){
        this.name = name;
    }

    public int getFive(){
        return fiveSevens;
    }
    public int getFour(){
        return fourSevens;
    }
    public int getThree(){
        return threeSevens;
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
