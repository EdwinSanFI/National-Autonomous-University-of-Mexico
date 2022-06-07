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
public class Directivo extends Empleado{

    private double salarioAdicional;
    
    public Directivo(String Nombre, String Apellido){
        super(Nombre, Apellido);
    }
    
    void setSalarioAdicional(double salarioAdicional){
        this.salarioAdicional=salarioAdicional;
    }
    double getSalarioAdicional(){
        return this.salarioAdicional;
    }
    
    void setSalarioOtro(Empleado empleado,int SalarioBase){
        empleado.setSalarioBase(SalarioBase);
    }
    
    double getSalarioOtro(Empleado empleado){
        return empleado.getsalarioBase();
    }   
    
}
