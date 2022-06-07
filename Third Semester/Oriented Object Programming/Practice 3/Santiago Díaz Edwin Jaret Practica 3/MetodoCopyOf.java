import java.util.Arrays;

public class MetodoCopyOf {
    public static void main(String[] args) {

        int[] arreglo1 = {1,2,3,4,5,6};
        // También se puede crear de esta forma
        // int[] arreglo1 = new int[] {1,2,3,4,5,6};
        System.out.println("Arreglo original:");
        for (int i : arreglo1) {
            System.out.print(i + " ");
        }
        // Copia del arreglo con 10 indices
        int[] copiaMayor = Arrays.copyOf(arreglo1, 10);
        // Copia del arreglo con 4 indices
        int[] copiaMenor = Arrays.copyOf(arreglo1, 4);
        // tipo[] nuevoArreglo = Arrays.copyOf(arregloOriginal, Tamaño);

        System.out.println("\nCopiamos el arreglo con tamaño a 10 indices:");
        for (int i : copiaMayor) {
            System.out.print(i + " ");
        }
        System.out.println("\nCopaimos el arreglo con tamaño a 4 indices:");
        for (int i : copiaMenor) {
            System.out.print(i + " ");
        }
        // Modificamos el arreglo mayor
        copiaMayor[6] = 964;
        copiaMayor[8] = 121;
        copiaMayor[9] = 532;
        copiaMayor[7] = 12;

        System.out.println("\nModifamos el arreglo de mayor tamano: ");
        for (int i : copiaMayor) {
            System.out.print(i + " ");
        }

        //  STRINGS

        String[] arreglo2 = {"Hola", "Mundo"};
        // También se puede crear de esta forma
        // String[] arreglo2 = new String[] {"Hola", "Mundo"};
        System.out.println("\n\nArreglo original:");
        for (String i : arreglo2) {
            System.out.print(i + " ");
        }
        // Copia del arreglo con 10 indices
        String[] copiaMayorS = Arrays.copyOf(arreglo2, 10);
        // Copia del arreglo con 4 indices
        String[] copiaMenorS = Arrays.copyOf(arreglo2, 4);
        // tipo[] nuevoArreglo = Arrays.copyOf(arregloOriginal, Tamaño);

        System.out.println("\nCopiamos el arreglo con tamaño a 10 indices:");
        for (String i : copiaMayorS) {
            System.out.print(i + " ");
        }
        System.out.println("\nCopaimos el arreglo con tamaño a 4 indices:");
        for (String i : copiaMenorS) {
            System.out.print(i + " ");
        }
        // Modificamos el arreglo mayor
        copiaMayorS[6] = "Estoy";
        copiaMayorS[8] = "Programando";
        copiaMayorS[9] = "Pero";
        copiaMayorS[7] = "Reprobe";

        System.out.println("\nModifamos el arreglo de mayor tamano: ");
        for (String i : copiaMayorS) {
            System.out.print(i + " ");
        }
    }
}