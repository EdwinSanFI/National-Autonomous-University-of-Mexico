/**
 * @Author: Edwin Santiago
 */

package Animales.Aereos;

/** Clase Ave hereda de la clase abstracta Aereo */
public class Ave extends Aereo{
    /** Sobrescribe el metodo comer */
    @Override
    public void comer(){
        System.out.println("Comer insectos");
    }
    /** Sobrescribe el metodo dormir */
    @Override
    public void dormir(){
        System.out.println("Dormir en el aire o en mi nido");
    }
    /** Sobrescribe el metodo morir */
    @Override
    public void morir(){
        System.out.println("Morir por ser cazado");
    }
    /** Sobrescribe el metodo nacer */
    @Override
    public void nacer(){
        System.out.println("Soy oviparo y nazco en el nido");
    }
    /** Sobrescribe el metodo comunicarse */
    @Override
    public void comunicarse(){
        System.out.println("Comunicarse por el canto");
    }
}
