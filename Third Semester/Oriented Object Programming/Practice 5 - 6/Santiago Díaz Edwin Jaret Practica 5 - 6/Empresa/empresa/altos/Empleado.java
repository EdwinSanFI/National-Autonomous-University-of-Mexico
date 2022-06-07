/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package altos;
/**
 *
 * @author Edgar
 */
public class Empleado {
    private String Nombre;
    private String Apellido;
    private double salarioBase;
    private String Puesto;

    public Empleado(String Nombre, String Apellido){
        this.Nombre=Nombre;
        this.Apellido=Apellido;
    }

    public double getsalarioBase(){            //es public porque cualquiera puede conocer su propio sueldo
        return this.salarioBase;
    }

    void setSalarioBase(double salarioBase){     //es friendly para que solo los que estan dentro del paquete(directivo) lo puedan usar
        this.salarioBase=salarioBase;
    }

    protected void setPuesto(String Puesto){
        this.Puesto=Puesto;
    }
    
    protected String getPuesto(){
        return this.Puesto;
    }

}
