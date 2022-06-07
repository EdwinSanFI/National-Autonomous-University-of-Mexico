package Awards;

public class Cherry implements Awards {
    /** Los 3 premios */
    private int cincoCerezas = 1_500;
    private int cuatroCerezas = 1_000;
    private int tresCerezas = 600;
    /** Nombre del objeto */
    private String name = "Cereza";
    /** Color para que se pueda imprimir con color */
    private String color = "";

    public String getName(){
        return "  "+name+"  ";
    }
    public String getNomString(){
        return name;
    }
    public void setNomString(String name){
        this.name = name;
    }
    public int getCinco(){
        return cincoCerezas;
    }
    public int getCuatro(){
        return cuatroCerezas;
    }
    public int getTres(){
        return tresCerezas;
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
