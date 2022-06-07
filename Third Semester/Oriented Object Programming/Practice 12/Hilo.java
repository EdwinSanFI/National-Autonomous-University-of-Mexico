/**
 *
 * @auhtor: Edwin Jaret Santiago Díaz
 *
 * The class Hilo extends Thread and has a constructor that takes a String as a parameter and calls the
 * superclass constructor with the same parameter.
 *
 * The run() method is overridden to print a message five times and then print a message that the
 * thread has finished.
 *
 * The main() method creates two instances of the Hilo class and calls the start() method on each of
 * them.
 *
 * The start() method calls the run() method on each of the threads.
 *
 * The main() method then prints a message that the main thread has finished.
 *
 * The output from the program is:
 *
 * Iteration 1 of thread Primer hilo
 * Iteration 1 of thread Segundo hilo
 * Iteration 2 of thread Primer hilo
 * Iteration 2 of thread Segundo hilo
 * Iteration 3 of thread Primer hilo
 * Iteration 3 of thread Segundo hilo
 * Iter
 */
public class Hilo extends Thread {
    public Hilo (String Nombre) {
        super(Nombre);
    }
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Iteracion "+(i+1)+" del hilo "+getName());
        }
        System.out.println("Termina el "+getName());
    }

    public static void main(String[] args) {
        new Hilo("Primer hilo").start();
        new Hilo("Segundo hilo").start();
        System.out.println("Termina el hilo principal");
    }
}