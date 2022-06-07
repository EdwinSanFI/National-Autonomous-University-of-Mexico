import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.List;

public class MetodoToString {
    public static void main(String[] args) {

        Integer numero=10;
        System.out.println(numero.toString());

        // Entero
        System.out.println(Integer.toString(917));
        // System.out.println(Integer.toString(parametro));

        // O:
        // Se crea una lista
        List<Integer> lista1= Arrays.asList(1,2);
        System.out.println(lista1.toString());
        // System.out.println(variable.toString());

        // Long
        System.out.println(Long.toString(831931731));

        // Boolean
        System.out.println(Boolean.toString(true));
    }
}
