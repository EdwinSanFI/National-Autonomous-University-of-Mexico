//
// @Autor: Edwin Jaret Santiago Díaz
// Ejercico 3
// Se rescribio el codigo extendiendo el rango del 0 al 500 y dando
// 5 oportunidades al usuario para que adivine el numero

// La libreria es para obtener datos de entrada del usuario
import java.util.Scanner;
// La libreria es para escoger numeros aleatoriamente
import java.util.Random;

public class AdivinaNumero {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random aleatorio = new Random();
        int numeroSecreto;
        // El programa guarda un numero aleatorio
        numeroSecreto = aleatorio.nextInt(0, 500)+1;
        // Se inicializa las oportunidades
        int oportunidades = 0;
        // Se descomenta la siguiente linea si se quiere saber el numero secreto
        // System.out.println(numeroSecreto);
        // Imprime la bienvenida
        System.out.println("Bienvenido al juego:  ADIVINA EL NUMERO");
        do {
            // Se le solicita el numero al usuario
            System.out.println("Escribe el numero:");
            int numero = sc.nextInt();
            // Se analiza si el numero ingresado y el de la computada son los mismos
            // Si son iguales, ganó el juego
            if(numero == numeroSecreto){
                System.out.println("Felicidades, adivinaste");
                // Las oportunidades se igualan a 5 y se acaba el juego
                oportunidades = 5;
            }
            // Si el numero de la computadora es mayor
            else if(numero > numeroSecreto ) {
                // Se le notifica al usuario que es mayor y que intente de nuevo
                System.out.println("El numero que ingresaste es mayor, intenta de nuevo");
            } else{
                // Se le notifica al usuario que es menor y que intente de nuevo
                System.out.println("El numero que ingresaste es menor, intenta de nuevo");
            }
            // Se incrementa la oportunidad
            oportunidades += 1;
            // Cuando llegue a las oportunidades sin aidivnar el numero, se le notifica 
            // Y se le dice que numero era
            if (oportunidades == 5) {
                System.out.println("No adivinaste, el numero a adivinar es: "+ numeroSecreto);
            }
            // Cuando se llega a las 5 oportunidades, se acaba el juego
        } while (oportunidades < 5);
    }
}