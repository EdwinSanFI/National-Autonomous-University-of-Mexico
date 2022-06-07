/**
 * @Author: Edwin Santiago
 */

package Ejercicio1;

import java.util.*;

public class Batallon {
    static int numeroBatallones;
    private int claveBatallon;
    private String nombreBatallon, especialidadBatallon;

    /** Guarda los militares por batallon */
    ArrayList<Militar> militares = new ArrayList<>();

    /** Metodo constructor vacio */
    public Batallon(){}
    /**
     * Metodo constructor con 3 parametros
     * @param nombreBatallon nombre del batallon
     * @param especialidadBatallon especialidad del batallon
     * @param claveBatallon clave del batallon
     */
    public Batallon(String nombreBatallon, String especialidadBatallon, int claveBatallon){
        setClaveBatallon(claveBatallon);
        setEspecialidadBatallon(especialidadBatallon);
        setNombreBatallon(nombreBatallon);
    }

    /**
     * Asigna el nombre del batallon
     * @param nombreBatallon nombre del batallon
     */
    public void setNombreBatallon(String nombreBatallon){
        this.nombreBatallon = nombreBatallon;
    }
    /**
     * @return el nombre del batallon
     */
    public String getNombreBatallon(){
        return nombreBatallon;
    }

    /**
     * Asigna la especialidad del batallon
     * @param especialidadBatallon especilidad del batallon
     */
    public void setEspecialidadBatallon(String especialidadBatallon){
        this.especialidadBatallon = especialidadBatallon;
    }
    /**
     * @return especialidad del batallon
     */
    public String getEspecialidadBatallon(){
        return especialidadBatallon;
    }

    /**
     * Asigna la clave del batallon
     * @param claveBatallon clave del batallon
     */
    public void setClaveBatallon(int claveBatallon){
        this.claveBatallon = claveBatallon;
    }
    /**
     * @return la clave del batallon
     */
    public int getClaveBatallon(){
        return claveBatallon;
    }

    /** Muestra la informacion del batallon */
    public void MostrarInformacion(){
        System.out.println("\n\tClave del batallon: "+getClaveBatallon());
        System.out.println("\tNombre del batallon: "+getNombreBatallon());
        System.out.println("\tEspecialidad del Batallon: "+getEspecialidadBatallon());
        int i = 1;
        for (Militar militar : militares) {
            /** Manda a imprimir la informacion de los militares */
            System.out.println("\n++Militar #"+i+"++");
            militar.MostrarInformacion();
            i += 1;
        }
    }
}