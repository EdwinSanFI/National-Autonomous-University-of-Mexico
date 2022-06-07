package EjemplosGuia;

public class Fecha {
    private int dia;
    private int mes;
    private int anio;

    public Fecha(){
    }
    public Fecha(int dia, int mes, int anio){
        setDia(dia);
        setMes(mes);
        setAnio(anio);
    }
    public int getDia(){
        return dia;
    }
    public void setDia(int dia){
        if (dia > 0 && dia < 32){
            this.dia = dia;
        }
        else {
            System.out.println("Dia no valido");
        }
    }

    public int getMes(){
        return mes;
    }
    public void setMes(int mes){
        if(mes > 0  && mes < 13){
            this.mes = mes;
        } else {
            System.out.println("Mes no valido");
        }
    }

    public int getAnio(){
        return anio;
    }
    public void setAnio(int anio){
        if(anio > 0){
            this.anio = anio;
        } else {
            System.out.println("El año no puede ser negativo");
        }
    }

    public String toString(){
        return dia+"/"+mes+"/"+anio;
    }
}
