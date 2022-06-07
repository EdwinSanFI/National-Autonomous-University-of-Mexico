/**
 * @Author: Edwin Santiago
 */


package Ejercicio1;
import java.util.*;
public class Division {

    private String nombreDivision, areaDivision, militarAlMando;

    /** Guarda los batallones por division*/
    ArrayList<Batallon> batallones = new ArrayList<>();

    /** Guarda las divisiones */
    static ArrayList<Division> divisiones = new ArrayList<>();

    /** Metodo Constructor Vacio */
    public Division(){}
    /**
     * Metodo constructor que recibe 3 parametros
     * @param nombreDivision nombre de la Division
     * @param areaDivision area de la Division
     * @param militarAlMando nombre del militar al mando
     */
    public Division(String nombreDivision, String areaDivision, String militarAlMando){
        setAreaDivision(areaDivision);
        setMilitarAlMando(militarAlMando);
        setNombreDivision(nombreDivision);
        // divisiones.add(divisionNueva);
    }

    /**
     * Asigna el nombre a la division
     * @param nombreDivision nombre de la division
     */
    public void setNombreDivision(String nombreDivision){
        this.nombreDivision = nombreDivision;
    }
    /**
     * @return nombre de la division
     */
    public String getNombreDivision(){
        return nombreDivision;
    }

    /**
     * Asigna el area de la division
     * @param areaDivision area de la division
     */
    public void setAreaDivision(String areaDivision) {
        this.areaDivision = areaDivision;
    }
    /**
     * @return el area de la division
     */
    public String getAreaDivion(){
        return areaDivision;
    }

    /**
     * Asigna el nombre del militar al mando
     * @param militarAlMando militar al mando
     */
    public void setMilitarAlMando(String militarAlMando){
        this.militarAlMando = militarAlMando;
    }
    /**
     * @return el nombre del militar al mando
     */
    public String getMilitarAlMando(){
        return militarAlMando;
    }

    /** Imprime la informacion de la division */
    public void MostrarInformacion(){
        System.out.println("\n\t\tNombre de la division: "+getNombreDivision());
        System.out.println("\t\tArea de la division: "+getAreaDivion());
        System.out.println("\t\tMilitar al mando: "+getMilitarAlMando());
        int i = 1;
        for (Batallon batallon : batallones) {
            /** Mabda a imprimir la informacion de los batallones */
            System.out.println("\n\t++Batallon #"+i+"++");
            batallon.MostrarInformacion();
            i += 1;
        }
    }
}