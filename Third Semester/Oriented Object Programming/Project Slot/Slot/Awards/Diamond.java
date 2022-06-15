package Slot.Awards;

public class Diamond implements Awards {
    /** Los 3 premios */
    private int fiveDiamonds = 10_000;
    private int fourDiamonds = 5_000;
    private int threeDiamonds = 2_500;
    /** Nombre del objeto */
    private String name = "Diamante";
    /** Color para que se pueda imprimir con color */
    private String color = "";

    public String getName(){
        return " "+name+" ";
    }
    public String getNameString(){
        return name;
    }
    /** Return the award for 5 diamonds */
    public int getFive(){
        return fiveDiamonds;
    }
    /** Return the award for 4 diamonds */
    public int getFour(){
        return fourDiamonds;
    }
    /** Return the award for 3 diamonds */
    public int getThree(){
        return threeDiamonds;
    }

    /** Getter and setter for the color variable. */
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }

    /** Design Pattern PROTOTYPE */
    public Awards clone() {
        return new Diamond();
    }
}
