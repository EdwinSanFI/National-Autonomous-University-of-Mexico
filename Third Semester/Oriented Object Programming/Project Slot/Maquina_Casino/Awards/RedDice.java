package Awards;

public class RedDice implements Awards {
    /** Los 3 premios */
    private int cincoDados = 100_000;
    private int cuatroDados = 30_000;
    private int tresDados = 15_000;
    /** Nombre del objeto */
    private String name = "Dado Rojo";
    /** Color para que se pueda imprimir con color */
    private String color = "";

    public String getName(){
        return " "+name;
    }
    public String getNomString(){
        return name;
    }
    public void setNomString(String name){
        this.name = name;
    }
    public int getCinco(){
        return cincoDados;
    }
    public int getCuatro(){
        return cuatroDados;
    }
    public int getTres(){
        return tresDados;
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