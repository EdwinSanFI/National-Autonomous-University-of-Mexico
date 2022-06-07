/**
 * @Author: Edwin Santiago
 */

package Animales.Terrestres;

/** Clase Cabra hereda de la clase abstracta Terrestre */
public class Cabra extends Terrestre{
    /** Sobrescribe el metodo comer */
    @Override
    public void comer(){
        System.out.println("Comer maiz,hojas,alfalfa");
    }
    /** Sobrescribe el metodo dormir */
    @Override
    public void dormir(){
        System.out.println("Dormir unas 5 horas acostado");
    }
    /** Sobrescribe el metodo morir */
    @Override
    public void morir(){
        System.out.println("Morir por la edad, a veces me hacen carna asada");
    }
    /** Sobrescribe el metodo nacer */
    @Override
    public void nacer(){
        System.out.println("Soy viviparo y tardo 149 dias");
    }
    /** Sobrescribe el metodo comunicarse */
    @Override
    public void comunicarse(){
        System.out.println("Comunicarse por el sonido (Beeep)");
    }
}
