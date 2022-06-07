/**
 * @Author: Edwin Santiago
 */

package Animales.Acuaticos;
import Animales.Animal;

/** Clase abstracta Acuaticos hereda de la clase abstracta Animal */
public abstract class Acuaticos extends Animal {
    /** Desplazarse como un animal Acuatico */
    public void desplazarse(){
        System.out.println("Desplazarse por el agua");
    }
    /** Respirar como un animal Acuatico */
    public void respirar() {
        System.out.println("Respirar por el agua");
    }
    /** Habitad de un animal Acuatico */
    public void habitat(){
        System.out.println("Habitat: Agua");
    }
    /** Ejecuta los metodos de un animal Acuatico */
    public void ver(){
        /** Metodos de la clase abstracta Animal */
        comer();
        dormir();
        morir();
        nacer();
        comunicarse();
        /** Metodos de la clase abstracta Acuaticos */
        desplazarse();
        respirar();
        habitat();
    }
}