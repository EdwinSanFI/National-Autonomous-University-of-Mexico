import java.lang.reflect.Array;
import java.util.Arrays;

public class MetodoBinarySearch {
    public static void main(String[] args) {
        // Arreglo de nombres de paises
        String[] paises = {"MEXICO", "COLOMBIA", "EUA", "UCRANIA", "RUSIA", "CHINA"};
        // Ordena el arreglo
        Arrays.sort(paises);
        // Recorre el arreglo e imprime el indice junto con su elemento
        for (int i=0; i< paises.length; i++) {
            System.out.println("Indice " + i + " y pais " + paises[i]);
        }
        // Guarda en una variable el elemento que buscamos
        String pais = "UCRANIA";
        // Usa el metodo e imprime el valor que devuelve
        System.out.println("El indice de Ucrania es: " + Arrays.binarySearch(paises, pais));
        //                                              Arrays.binarySearch(arreglo, elemento/variable);
    }
}
