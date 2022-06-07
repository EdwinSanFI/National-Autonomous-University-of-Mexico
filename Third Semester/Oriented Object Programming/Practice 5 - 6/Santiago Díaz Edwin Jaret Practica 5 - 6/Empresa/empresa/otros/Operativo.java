/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package otros;
import altos.*;
/**
 *
 * @author Edgar
 */
public class Operativo extends Empleado{
    private String turno;
    private int jornadaLaboral;

    public Operativo(String Nombre, String Apellido){
        super(Nombre,Apellido);
    }

    public String getTurno(){
        return this.turno;
    }
    public void setTurno(String turno){
        this.turno=turno;
    }

    public int getJornadaLaboral(){
        return this.jornadaLaboral;
    }
    public void setJornadaLaboral(int jornadaLaboral){
        this.jornadaLaboral=jornadaLaboral;
    }
}
