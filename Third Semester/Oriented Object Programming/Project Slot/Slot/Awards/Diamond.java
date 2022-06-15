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
    public void setNameString(String name){
        this.name = name;
    }
    public int getFive(){
        return fiveDiamonds;
    }
    public int getFour(){
        return fourDiamonds;
    }
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
