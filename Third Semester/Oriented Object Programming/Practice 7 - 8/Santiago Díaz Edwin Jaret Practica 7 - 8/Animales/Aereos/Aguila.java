package Animales.Aereos;

/** Clase Aguila hereda de la clase abstracta Aereo */
public class Aguila extends Aereo{
    /** Sobrescribe el metodo comer */
    @Override
    public void comer(){
        System.out.println("Comer insectos, roedores y aves");
    }
    /** Sobrescribe el metodo dormir */
    @Override
    public void dormir(){
        System.out.println("Dormir 12 horas mientras estoy en tierra");
    }
    /** Sobrescribe el metodo morir */
    @Override
    public void morir(){
        System.out.println("Morir por la edad");
    }
    /** Sobrescribe el metodo nacer */
    @Override
    public void nacer(){
        System.out.println("Soy oviparo y eclosiono en 35 dias");
    }
    /** Sobrescribe el metodo comunicarse */
    @Override
    public void comunicarse(){
        System.out.println("Comunicarse por el sonido");
    }
}
