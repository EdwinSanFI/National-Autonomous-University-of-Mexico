import java.util.Arrays;
import java.util.List;

public class MetodoEquals {
    public static void main(String[] args) {
        Integer arreglo1[] = {1,2,3,4,5};
        Integer arreglo2[] = {6,7,8,9,10};
        Integer arreglo3[]= {1,2,3,4,5};

        if (arreglo1.equals(arreglo2)) {
            System.out.println(arreglo1 + " y " + arreglo2 + " son IGUALES");
        }
        else {
            System.out.println(arreglo1 + " y " + arreglo2 + " son DIFERENTES");
        }

        // Convertimos en lista los arreglos
        List<Integer> lista1 = Arrays.asList(arreglo1);
        List<Integer> lista2 = Arrays.asList(arreglo3);
        lista1.equals(lista2);
        // objeto1.equals(obejto2);
        // Comparamos las listas
        if (lista1.equals(lista2)) {
            System.out.println(lista1 + " y " + lista2 + " son IGUALES");
        }
        else {
            System.out.println(lista1 + " y " + lista2 + " son DIFERENTES");
        }

        // Strings

        String arreglo1S = new String("Chocolate");
        String arreglo2S = new String("Vainilla");
        String arreglo3S = new String("Chocolate");

        if (arreglo1S.equals(arreglo2S)) {
            System.out.println(arreglo1S + " y " + arreglo2S + " son IGUALES");
        }
        else {
            System.out.println(arreglo1S + " y " + arreglo2S + " son DIFERENTES");
        }
        if (arreglo1S.equals(arreglo3S)) {
            System.out.println(arreglo1S + " y " + arreglo3S + " son IGUALES");
        }
        else {
            System.out.println(arreglo1S + " y " + arreglo3S + " son DIFERENTES");
        }
    }
}
