/**
 * @author: Edwin Jaret Santiago Díaz
 * The class EjThreadGroup extends Thread and has a constructor that takes a ThreadGroup and a String
 * as parameters.
 *
 * The class also has a run() method that prints the name of the thread 10 times.
 *
 * The class also has a main() method that creates a ThreadGroup object and 5 EjThreadGroup objects.
 *
 * The main() method also sets the priority of the first thread to the maximum priority and sets the
 * maximum priority of the ThreadGroup object to the normal priority.
 *
 * The main() method also prints the priority of the ThreadGroup object and the 5 EjThreadGroup
 * objects.
 *
 * The main() method also starts the 5 EjThreadGroup objects and calls the listarHilos() method to list
 * the active threads in the ThreadGroup object.
 *
 * The listarHilos() method takes a ThreadGroup object as a parameter and prints the number of active
 * threads in the ThreadGroup object.
 */
public class EjThreadGroup extends Thread{
    public EjThreadGroup(ThreadGroup g, String n) {
        super(g,n);
    }
    public void run() {
        for(int i=0;i<10;i++) {
            System.out.println(getName());
        }
    }
    public static void listarHilos(ThreadGroup grupoActual){
        int numHilos;
        Thread [] listaDeHilos;
        numHilos = grupoActual.activeCount();
        listaDeHilos = new Thread[numHilos];
        grupoActual.enumerate(listaDeHilos);
        System.out.println("\nNumero de hilos activos = "+numHilos+"\n");
        for(int i=0;i<numHilos;i++) {
            System.out.println("\nHilo activo "+(i+1)+" = "+listaDeHilos[i].getName());
        }
    }

    public static void main(String[] args) {
        ThreadGroup grupoHilos = new ThreadGroup("Grupo con prioridad normal");
        Thread hilo1 = new EjThreadGroup(grupoHilos,"Hilo 1");
        Thread hilo2 = new EjThreadGroup(grupoHilos,"Hilo 2");
        Thread hilo3 = new EjThreadGroup(grupoHilos,"Hilo 3");
        Thread hilo4 = new EjThreadGroup(grupoHilos,"Hilo 4");
        Thread hilo5 = new EjThreadGroup(grupoHilos,"Hilo 5");
        hilo1.setPriority(Thread.MAX_PRIORITY);
        grupoHilos.setMaxPriority(Thread.NORM_PRIORITY);
        System.out.println("Prioridad del grupo = "+grupoHilos.getMaxPriority());

        System.out.println("Prioridad del Thread = "+hilo1.getPriority());
        System.out.println("Prioridad del Thread = "+hilo2.getPriority());
        System.out.println("Prioridad del Thread = "+hilo3.getPriority());
        System.out.println("Prioridad del Thread = "+hilo4.getPriority());
        System.out.println("Prioridad del Thread = "+hilo5.getPriority());

        hilo1.start();
        hilo2.start();
        hilo3.start();
        hilo4.start();
        hilo5.start();
        listarHilos(grupoHilos);
    }
}