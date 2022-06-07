/**
 * @Author: Edwin Santiago
 */

package Animales.Acuaticos;

/** Clase Ajolote hereda de la clase abstracta Acuaticos */
public class Ajolote extends Acuaticos {
    /** Sobrescribe el metodo comer */
    @Override
    public void comer() {
        System.out.println("Comer larvas de insecto, caracoles y lombrices");
    }
    /** Sobrescribe el metodo dormir */
    @Override
    public void dormir() {
        System.out.println("Dormir estatico");
    }
    /** Sobrescribe el metodo morir */
    @Override
    public void morir() {
        System.out.println("Morir por el cambio climatico");
    }
    /** Sobrescribe el metodo nacer */
    @Override
    public void nacer() {
        System.out.println("Nacer en el agua después de 15 dias en un huevo");
    }
    /** Sobrescribe el metodo comunicarse */
    @Override
    public void comunicarse() {
        System.out.println("Comunicarse por el sonido");
    }
}
