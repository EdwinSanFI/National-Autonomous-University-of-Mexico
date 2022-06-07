/**
 * @Author: Edwin Santiago
 */

package Animales.Aereos;

/** Clase Paloma hereda de la clase abstracta Aereo */
public class Paloma extends Aereo{
    /** Sobrescribe el metodo comer */
    @Override
    public void comer(){
        System.out.println("Comer granos, trigo, girasol, maiz");
    }
    /** Sobrescribe el metodo dormir */
    @Override
    public void dormir(){
        System.out.println("No duermo en las ramas de los arboles porque me caigo");
    }
    /** Sobrescribe el metodo morir */
    @Override
    public void morir(){
        System.out.println("Morir por la edad");
    }
    /** Sobrescribe el metodo nacer */
    @Override
    public void nacer(){
        System.out.println("Soy oviparo y eclosiono en 18 dias");
    }
    /** Sobrescribe el metodo comunicarse */
    @Override
    public void comunicarse(){
        System.out.println("Comunicarse por el sonido (Gruu)");
    }
}
