/**
 * @Author: Edwin Santiago
 */
public  class Ejercicio2 {
    public static void main(String[] args) {
        // Se declara un arreglo
        int[] arreglo = {10,9,8,7,6,5,4,3,2,1};
        // Utilizamos la funcion para sumar los elementos excepto el mayor y el menor
        devolverSuma(arreglo);
    }
    // Inciso A
    /**
     * Suma los elementos de una lista excepto el mayor y el menor de la lista.
     * @param arreglo la lista de numeros enteros
     */
    static void devolverSuma(int[] arreglo) {
        // Asignamos el primer elemento del arreglo a las variables
        int maximo = arreglo[0];
        int minimo = arreglo[0];
        // Inicializamos en 0 la suma
        int suma = 0;
        // Recorremos el arreglo
        for (int array : arreglo) {
            // Si el elemento actual es mayor al el elemento maximo guardado
            if (array > maximo) {
                // Se guarda el nuevo elemento maximo
                maximo = array;
            } else if (array < minimo) { // Si el elemento actual es menor al elemento menor guardado
                // Se guarda el nuevo elemento menor
                minimo = array;
            }
            // Se suma los elementos de la lista
            suma += array;
        }
        // Se resta de la suma el numero mayor y el menor
        suma -= maximo;
        suma -= minimo;
        // Se imprime los resultados
        System.out.print("Resultado de la suma: ");
        System.out.println(suma);
        // Se imprime los numeros que fueron sumados
        for(int i = 2; i < arreglo.length;i++){
            System.out.println("Los numeros sumados son: " + i);
        }
        // Imprime el numero mayor y el menor
        System.out.println("El numero menor: " + arreglo[9] + " y el mayor: " + arreglo[0]);
    }

}