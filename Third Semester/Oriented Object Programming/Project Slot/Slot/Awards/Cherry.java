package Slot.Awards;

public class Cherry implements Awards {
    /** Los 3 premios */
    private int fiveCherrys = 1_500;
    private int fourCherrys = 1_000;
    private int threeCherrys = 600;
    /** Nombre del objeto */
    private String name = "Cereza";
    /** Color para que se pueda imprimir con color */
    private String color = "";

    public String getName(){
        return "  "+name+"  ";
    }
    public String getNameString(){
        return name;
    }
    public void setNameString(String name){
        this.name = name;
    }
    public int getFive(){
        return fiveCherrys;
    }
    public int getFour(){
        return fourCherrys;
    }
    public int getThree(){
        return threeCherrys;
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
        return new Cherry();
    }
}
