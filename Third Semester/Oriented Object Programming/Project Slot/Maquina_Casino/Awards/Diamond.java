package Awards;

public class Diamond implements Awards {
    /** Los 3 premios */
    private int cincoDiamantes = 10_000;
    private int cuatroDiamantes = 5_000;
    private int tresDiamantes = 2_500;
    /** Nombre del objeto */
    private String name = "Diamante";
    /** Color para que se pueda imprimir con color */
    private String color = "";

    public String getName(){
        return " "+name+" ";
    }
    public String getNomString(){
        return name;
    }
    public void setNomString(String name){
        this.name = name;
    }
    public int getCinco(){
        return cincoDiamantes;
    }
    public int getCuatro(){
        return cuatroDiamantes;
    }
    public int getTres(){
        return tresDiamantes;
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
        return new Diamond();
    }
}
