/**
 * @Author: Edwin Santiago
 */

package Animales.Acuaticos;

/** Clase Tortuga hereda de la clase Acuaticos */
public class Tortuga extends Acuaticos{
    /** Sobrescribe el metodo comer */
    @Override
    public void comer(){
        System.out.println("Comer medusas y peces");
    }
    /** Sobrescribe el metodo dormir */
    @Override
    public void dormir(){
        System.out.println("Dormir estatico por 5 horas");
    }
    /** Sobrescribe el metodo morir */
    @Override
    public void morir(){
        System.out.println("Morir por un popote en la nariz");
    }
    /** Sobrescribe el metodo nacer */
    @Override
    public void nacer(){
        System.out.println("Soy oviparo y nazco en la arena, al eclosionar me tengo que mover rapido al oceano");
    }
    /** Sobrescribe el metodo comunicarse */
    @Override
    public void comunicarse(){
        System.out.println("Comunicarse por el sonido");
    }
}
