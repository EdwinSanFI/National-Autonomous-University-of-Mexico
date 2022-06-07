package Animales.Aereos;
import Animales.Animal;

/** Clase abstracta Aereo hereda de la clase abstracta Animal */
public abstract class Aereo extends Animal{
    /** Desplazarse como un animal Aereo */
    public void desplazarse(){
        System.out.println("Desplazarse por el aire");
    }
    /** Respirar como un animal Aereo */
    public void respirar() {
        System.out.println("Respirar aire");
    }
    /** Habitat de un animal Aereo */
    public void habitat(){
        System.out.println("Habitat: Arboles");
    }
    /** Ejecuta los metodos del animal Aereo */
    public void ver(){
        /** Metodos de la clase abstracta Animal */
        comer();
        dormir();
        morir();
        nacer();
        comunicarse();
        /** Metodos de la clase abstracta Aereo  */
        desplazarse();
        respirar();
        habitat();
    }
}
