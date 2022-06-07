/**
 * @Author: Edwin Santiago
 */

package Animales.Terrestres;
import Animales.Animal;

/** Clase abstracta Terrestre hereda de la clase abstracta Animal*/
public abstract class Terrestre extends Animal{
    /** Desplazarse como un animal terrestre */
    public void desplazarse(){
        System.out.println("Desplazarse por el terreno moviendo sus pies");
    }
    /** Respirar como un animal Terrestre */
    public void respirar() {
        System.out.println("Respira aire");
    }
    /** Habitat de un animal Terrestre */
    public void habitat(){
        System.out.println("Habitat: Tierra");
    }
    /** Ejecuta los metodos del animal Terrestre */
    public void ver(){
        /** Metodos de la clase abstracta Animal */
        comer();
        dormir();
        morir();
        nacer();
        comunicarse();
        /** Metodos de la clase abstracta Terrestre */
        desplazarse();
        respirar();
        habitat();
    }
}
