import java.util.Arrays;

public class MetodoCopyOfRange {
    public static void main(String[] args) {
        int[] arreglo1 = {1,2,3,4,5};
        // int[] arr1 = new int[] {15, 10, 45};

        // Se imprime el arreglo original
        System.out.println("Arreglo original:");
        for (int i: arreglo1) {
            System.out.print(i+" ");
        }

        // Se copia el arreglo desde el primer indice hasta el tercer indice
        int[] arreglo2 = Arrays.copyOfRange(arreglo1, 1, 3);
        // tipoDato[] arrelgoCopia = Arrays.copyOfRange(arregloOriginal, incio, final);

        // Se imprime la copia del arreglo
        System.out.println("\nCopia del arreglo desde el indice 1 hasta el 3:");
        for (int i : arreglo2) {
            System.out.print(i + " ");
        }

        // Strings

        String[] arreglo1S = {"EDA II", "POO", "ING. DE SW", "PROBA", "VECTORIAL"};
        // String[] arr1 = new String[] {"EDA II", "POO", "ING. DE SW", "PROBA", "VECTORIAL"};

        // Se imprime el arreglo original
        System.out.println("\n\nArreglo original:");
        for (String i: arreglo1S) {
            System.out.print(i+" ");
        }

        // Se copia el arreglo desde el primer indice hasta el tercer indice
        String[] arreglo2S = Arrays.copyOfRange(arreglo1S, 1, 3);

        // Se imprime la copia del arreglo
        System.out.println("\nCopia del arreglo desde el indice 1 hasta el 3:");
        for (String i : arreglo2S) {
            System.out.print(i + " ");
        }
    }
}
