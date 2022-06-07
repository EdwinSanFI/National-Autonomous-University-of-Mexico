/**
 * @author: Edwin Jaret Santiago Díaz
 * The class Hilo2 implements the Runnable interface and defines the run() method. 
 * 
 * The run() method is the entry point for the second thread. 
 * 
 * The main() method creates and starts two threads. 
 * 
 * The first thread is created by instantiating the Thread class and passing an instance of the Hilo2
 * class as an argument to the constructor. 
 * 
 * The second thread is created by instantiating the Thread class and passing an instance of the Hilo2
 * class as an argument to the constructor. 
 * 
 * The start() method is invoked on each thread. 
 * 
 * The start() method creates a new stack for the thread and invokes the run() method on that new
 * stack. 
 * 
 * The run() method is invoked on the new stack. 
 * 
 * The run() method prints a message and then returns. 
 * 
 * The thread dies. 
 * 
 * The main() method prints a message and then returns.
 */
public class Hilo2 implements Runnable{
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("Iteracion "+i+" del hilo "+Thread.currentThread().getName());
        }
        System.out.println("Termina el hilo "+Thread.currentThread().getName());
    }
    public static void main(String[] args) {
        new Thread(new Hilo2(), "Primer Hilo").start();
        new Thread(new Hilo2(), "Segundo Hilo").start();
        System.out.println("Termina el hilo principal");
    }
}