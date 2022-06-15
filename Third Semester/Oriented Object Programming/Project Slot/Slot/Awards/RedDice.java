package Slot.Awards;

public class RedDice implements Awards {
    /** Los 3 premios */
    private int fiveDices = 100_000;
    private int fourDices = 30_000;
    private int threeDices = 15_000;
    /** Nombre del objeto */
    private String name = "Dado Rojo";
    /** Color para que se pueda imprimir con color */
    private String color = "";

    public String getName(){
        return " "+name;
    }
    public String getNameString(){
        return name;
    }
    public void setNameString(String name){
        this.name = name;
    }
    public int getFive(){
        return fiveDices;
    }
    public int getFour(){
        return fourDices;
    }
    public int getThree(){
        return threeDices;
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
        return new RedDice();
    }
}