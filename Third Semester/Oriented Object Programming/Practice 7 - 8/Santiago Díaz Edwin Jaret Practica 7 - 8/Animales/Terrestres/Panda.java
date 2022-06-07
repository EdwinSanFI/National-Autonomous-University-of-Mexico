/**
 * @Author: Edwin Santiago
 */

package Animales.Terrestres;

/** Clase Panda hereda de la clase abstracta Terrestre */
public class Panda extends Terrestre{
    /** Sobrescribe el metodo comer */
    @Override
    public void comer(){
        System.out.println("Comer carne, frutas, verduras, hojas");
    }
    /** Sobrescribe el metodo dormir */
    @Override
    public void dormir(){
        System.out.println("Dormir en el bosque unas 8 horas");
    }
    /** Sobrescribe el metodo morir */
    @Override
    public void morir(){
        System.out.println("Morir por la edad");
    }
    /** Sobrescribe el metodo nacer */
    @Override
    public void nacer(){
        System.out.println("Soy viviparo y tardo 3 a 5 meses");
    }
    /** Sobrescribe el metodo comunicarse */
    @Override
    public void comunicarse(){
        System.out.println("Comunicarse por el sonido");
    }
}
