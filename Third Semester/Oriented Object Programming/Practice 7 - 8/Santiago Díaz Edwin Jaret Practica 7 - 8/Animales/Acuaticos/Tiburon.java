/**
 * @Author: Edwin Santiago
 */

package Animales.Acuaticos;

/** Clase Tiburon hereda de la clase abstracta Acuaticos */
public class Tiburon extends Acuaticos {
    /** Sobrescribe el metodo comer */
    @Override
    public void comer() {
        System.out.println("Comer peces y calamares");
    }
    /** Sobrescribe el metodo dormir */
    @Override
    public void dormir() {
        System.out.println("No duermo porque me muero");
    }
    /** Sobrescribe el metodo morir */
    @Override
    public void morir() {
        System.out.println("Morir asesinado por una ballena");
    }
    /** Sobrescribe el metodo nacer */
    @Override
    public void nacer() {
        System.out.println("Soy viviparo y nazco en el agua");
    }
    /** Sobrescribe el metodo comunicarse */
    @Override
    public void comunicarse() {
        System.out.println("Comunicarse por el lenguaje corporal");
    }
}
