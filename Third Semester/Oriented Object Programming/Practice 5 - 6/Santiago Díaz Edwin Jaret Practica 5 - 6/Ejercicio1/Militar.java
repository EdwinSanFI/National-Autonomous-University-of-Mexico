/**
 * @Author: Edwin Santiago
 */


package Ejercicio1;

public class Militar {
    static int numeroMilitares;
    protected int edadMilitar;
    protected String nombreMilitar, apellidoMilitar;

    public Militar(){
    }
    /**
     * Metodo constructor
     * @param nombreMilitar nombre del militar
     * @param apellidoMilitar apellido del militar
     * @param edadMilitar edad del militar
     */
    public Militar(String nombreMilitar, String apellidoMilitar, int edadMilitar){
        setNombreMilitar(nombreMilitar);
        setApellidoMilitar(apellidoMilitar);
        setEdadMilitar(edadMilitar);
    }

    /**
     * Asigna el nombre del militar
     * @param nombreMilitar nombre del militar
     */
    public void setNombreMilitar(String nombreMilitar){
        this.nombreMilitar = nombreMilitar;
    }
    /**
     * @return nombre del militar
     */
    public String getNombreMilitar(){
        return nombreMilitar;
    }

    /**
     * Asigna el apellido del militar
     * @param apellidoMilitar
     */
    public void setApellidoMilitar(String apellidoMilitar){
        this.apellidoMilitar = apellidoMilitar;
    }
    /**
     * @return apellido del militar
     */
    public String getApellidoMilitar(){
        return apellidoMilitar;
    }

    /**
     * Asigna la edad del militar
     * @param edadMilitar
     */
    public void setEdadMilitar(int edadMilitar){
        this.edadMilitar = edadMilitar;
    }
    /**
     * @return edad del militar
     */
    public int getEdadMilitar(){
        return edadMilitar;
    }

    /** Muestra la informacion del Militar */
    public void MostrarInformacion(){
        System.out.println("\nNombre:"+getNombreMilitar());
        System.out.println("Apellido: "+getApellidoMilitar());
        System.out.println("Edad: "+getEdadMilitar());
    }
}