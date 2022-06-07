/**
 * The class Cuenta extends Thread and has a static variable saldo, which is a long. 
 * 
 * The class has a constructor that takes a String as a parameter and calls the superclass constructor
 * with the same parameter. 
 * 
 * The class has a run method that calls the depositarDinero method if the name of the thread is
 * Deposito 1 or Deposito 2, or calls the extraerDinero method if the name of the thread is Acceso 1 or
 * Acceso 2. 
 * 
 * The class has a depositarDinero method that takes an int as a parameter and adds the parameter to
 * the saldo variable. 
 * 
 * The class has an extraerDinero method that takes an int as a parameter and subtracts the parameter
 * from the saldo variable. 
 * 
 * The class has a main method that creates four threads, two of which call the depositarDinero method
 * and two of which call the extra
 */
public class Cuenta extends Thread{
    private static long saldo = 0;
    /** Create a Thread with the name with the variable parametere */
    public Cuenta (String nombre){
        super(nombre);
    }
    /**
     * The run method calls the depositarDinero method if the name of the thread is Deposito 1 or
     * Deposito 2, or calls the extraerDinero method if the name of the thread is Acceso 1 or Acceso 2.
     */
    public void run(){
        if(getName().equals("Deposito 1") || getName().equals("Deposito 2")){
            this.depositarDinero(100);
        } else {
            this.extraerDinero(50);
        }
        System.out.println("Termina el "+getName());
    }

    /**
     * The depositarDinero method takes an int as a parameter and adds the parameter to the saldo
     * variable.
     */
    public synchronized void depositarDinero(int cantidad){
        saldo += cantidad;
        System.out.println("Se depositaron "+cantidad+" pesos");
        /** NotifyAll notify to all Threads */
        notifyAll();
    }

    /**
     * The extraerDinero method takes an int as a parameter and subtracts the parameter from the saldo
     * variable.
     */
    public synchronized void extraerDinero(int cantidad){
        try{
            if(saldo <= 0){
                System.out.println(getName()+" espera deposito"+"\nSaldo = "+saldo);
                sleep(5000);
            }
        }catch(InterruptedException e){
            System.out.println("Error en el hilo "+getName());
        }
        saldo -= cantidad;
        System.out.println(getName()+" extrajo "+cantidad+" pesos.\nSaldo restante = "+saldo);
        notifyAll();
    }

    /**
     * The main method creates four threads, two of which call the depositarDinero method and two of
     * which call the extraerDinero method.
     */
    public static void main(String[] args) {
        new Cuenta("Acceso 1").start();
        new Cuenta("Acceso 2").start();
        new Cuenta("Deposito 1").start();
        new Cuenta("Deposito 2").start();
        System.out.println("Termina el hilo principal");
    }
}
