package Animales.Terrestres;
public class Tigre extends Terrestre{
    @Override
    public void comer(){
        System.out.println("Comer carne");
    }
    @Override
    public void dormir(){
        System.out.println("Dormir en el bosque");
    }
    @Override
    public void morir(){
        System.out.println("Morir por la edad");
    }
    @Override
    public void nacer(){
        System.out.println("Soy viviparo y nazco en la tierra en 100 dias");
    }
    @Override
    public void comunicarse(){
        System.out.println("Comunicarse por el rugido");
    }
}
