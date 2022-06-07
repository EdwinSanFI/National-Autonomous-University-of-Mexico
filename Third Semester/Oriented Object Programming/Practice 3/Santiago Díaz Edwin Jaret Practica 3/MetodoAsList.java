import java.util.Arrays;
import java.util.List;

public class MetodoAsList {
    public static void main(String[] args) {

        // asList() Convierte un arreglo a una lista, ¿Por qué haríamos eso?
        // Porque un arreglo es estático una vez definido y una lista se puede modificar

        // Creamos una arreglo y una lista de tipo entero
        Integer arreglo1[] = {10,40,50,20,90};
        // También se puede declarar de esta manera:
        // Integer arreglo1[] = new Integer[] {10,40,50,20,90};
        System.out.println("Primer elemento del arreglo: " + arreglo1[0]); // Imprime el primer elemento del arreglo
        // Creamos una lista de tipo Integer y convertimos el arreglo a una lista
        List<Integer> lista1 = Arrays.asList(arreglo1);
        // Tambien se puede crear de esta manera:
        // List<Integer> lista1 = new ArrayList <Integer>();
        // lista1 = Arrays.asList(arreglo1);
        System.out.println("Lista: " + lista1); // Nos imprime el contenido de la lista

        //  Ahora, creamos un arreglo y una lista de tipo cadena
        String arreglo2[] = {"Pedro", "Edgar", "Marco"};
        System.out.println("Primer elemento del arreglo: " + arreglo2[0]); // Imprime el primer elemento del arreglo
        // Creamos una lista de tipo String y convertimos el arreglo en la lista
        List<String> lista2 = Arrays.asList(arreglo2);
        System.out.println("Lista: "+ lista2); // Imprimos el contenido de la lista

        //  Ahora, creamos un arreglo y una lista de tipo booleano
        Boolean arreglo3[] = {true, false, true};
        System.out.println("Primer elemento del arreglo: " + arreglo3[0]); // Imprime el primer elemento del arreglo
        // Creamos una lista de tipo String y convertimos el arreglo en la lista
        List<Boolean> lista3 = Arrays.asList(arreglo3);
        System.out.println("Lista: " + lista3); // Imprimos el contenido de la lista
    
        //  Ahora, creamos un arreglo y una lista de tipo double
        Double arreglo4[] = {124.21, 21.2121, 1275.8653};
        System.out.println("Primer elemento del arreglo: " + arreglo4[0]); // Imprime el primer elemento del arreglo
        // Creamos una lista de tipo String y convertimos el arreglo en la lista
        List<Double> lista4 = Arrays.asList(arreglo4);
        System.out.println("Lista: " + lista4); // Imprimos el contenido de la lista

    }
}
