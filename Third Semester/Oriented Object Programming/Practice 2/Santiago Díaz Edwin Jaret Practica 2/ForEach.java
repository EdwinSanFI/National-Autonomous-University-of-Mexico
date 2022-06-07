// @Autor: Edwin Jaret Santiago Díaz
// Ejercico 4
// Se transcrriben 3 ciclos for a ciclo for-each

public class ForEach {
    public static void main(String[] args) {
        // Arreglo de numeros
        int a[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
        int var = 0;
        int var2 = 10;
        // Ciclo for-each
        for (int i : a) {
            // En el ejercicio original, la variable "var" almacena el valor de "i"
            // Pero "i" es el valor de los indices del arrelgo
            // Pero en este caso guarda los valores del arreglo (5, 10, 15..)
            // Y se debe de dividir entre 5 y restar 1 para que guarde los indices
            var += a[(i/5)-1];
        }
        // Ciclo for-each
        for (int j : a) {
            // Cada elemento del arreglo es multiplicado por 10
            // Primero, se obtiene los indices del 0 al 9
            // Y estos son utilizados para realizar la operacion
            a[(j/5)-1] = a[(j/5)-1] * 10;
        }
        // Ciclo for-each
        for (int k : a) {
            // Cada elemento se divide entre 50 para guardar el valor índice
            // Y acceder a los elementos del arreglo.
            int z = k/50 - 1;
            // El 0 no puede ser contado en la operacion siguiente ya que
            // 0 % 4 == 0 y no nos sirve en este caso
            if (z > 0) {
                // Se obtiene numeros multiplos de 4
                if (z % 4 == 0) {
                    // Imprime aquellos numeros multiplos de 4 que se encuentran en
                    // El arreglo y estos se encuentran en la posicion "z-1"
                    System.out.println(a[z-1] + " es divisible entre 4");
                }
            }
        }
    }
}