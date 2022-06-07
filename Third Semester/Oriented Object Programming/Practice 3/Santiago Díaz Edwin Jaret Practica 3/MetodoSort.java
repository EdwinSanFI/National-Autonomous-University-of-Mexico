import java.util.Arrays;

public class MetodoSort {
    public static void main(String[] args) {
        // Creamos un arreglo de tipo cadena
        String[] paises = {"MEXICO", "COLOMBIA", "EUA", "UCRANIA", "RUSIA", "CHINA"};

        System.out.println("Arreglo original: ");

        // Imprimimos el contenido del arreglo
        for (String i : paises) {
            System.out.print(i + " ");
        }

        System.out.println("");

        //Ordena el array
        Arrays.sort(paises);
        // Arrays.sort(arreglo);

        System.out.println("Arreglo ordenado: ");

        //Mostramos el array ya ordenado
        for (String i : paises) {
            System.out.print(i + " ");
        }

        // Creamos un arreglo de tipo entero
        int[] numeros = {1,3831,931,9312,313,4244,62,13,5,3,74,231};

        System.out.println("");

        // Imprimimos el contenido del arreglo
        for (int i : numeros) {
            System.out.print(i + " ");
        }

        //Ordena el array
        Arrays.sort(numeros);

        System.out.println("");

        // Imprimimos el array ordenado
        for (int i : numeros) {
            System.out.print(i + " ");
        }
    }
}
