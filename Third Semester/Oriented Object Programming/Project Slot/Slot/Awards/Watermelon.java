package Slot.Awards;

public class Watermelon implements Awards {
    private int fiveWatermelons = 650;
    private int fourWatermelons = 325;
    private int threeWatermelons = 160;
    private String name = "Sandia";
    private String color = "";

    public String getName(){
        return "  "+name+"  ";
    }
    public String getNameString(){
        return name;
    }

    /** Return the award for 5 watermelons */
    public int getFive(){
        return fiveWatermelons;
    }
    /** Return the award for 4 watermelons */
    public int getFour(){
        return fourWatermelons;
    }
    /** Return the award for 3 watermelons */
    public int getThree(){
        return threeWatermelons;
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
