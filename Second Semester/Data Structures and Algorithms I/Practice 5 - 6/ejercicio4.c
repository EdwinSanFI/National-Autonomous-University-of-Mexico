// Programa Creador de Colas dobles con sus respectivas
// Operaciones de encolar y desencolar al inicio y al final.

#include "colaDoble.c"

int main() {
    // Creamos la cola doble con ayuda de la estructura COLA del archivo
    // "colaDoble.c"
    Cola doble;
    // La cola Doble tendrá un tamaño de 8 elementos/espacios
    doble = crearCola(8);
    // Utilizamos las funciones de encolar al principio y final
    // Y de desencolar al principio y al final

    
    // * Estado 1
    // Encolamos al final. Esto es en el espacio 0
    encolarFinal(&doble, 101);
    // Encolamos al final. Esto es en el espacio 1
    encolarFinal(&doble, 102);
    // Encolamos al final. Esto es en el espacio 2
    encolarFinal(&doble, 103);
    // Encolamos al final. Esto es en el espacio 3
    encolarFinal(&doble, 104);
    // Encolamos al final. Esto es en el espacio 4
    encolarFinal(&doble, 105);
    // Desencolamos el valor inicial de la Cola Doble. Este es el espacio 0 = 101
    desencolarInicio(&doble);
    printf("Estado 1: \n");
    // Muestra los valores contenidos en la cola doble.
    mostrarValores(doble);
    printf("\n");


    // * Estado 2
    // Desencolamos el valor inicial de la Cola Doble. Este es el espacio 1 = 102
    desencolarInicio(&doble);
    // Encolamos al inicio el valor de 99. Esto es en el espacio 1
    encolarInicio(&doble, 99);
    // Encolamos al inicio el valor de 98. Esto es en el espacio 0
    encolarInicio(&doble, 98);
    // Encolamos al inicio el valor de 97. Esto es en el espacio 7
    encolarInicio(&doble, 97);
    // Desencolamos el valor Final de la Cola Doble. Esto es, el espacio 4 = 105
    desencolarFinal(&doble);
    // Encolamos al final el valor de 120. Esto es en el espacio 4
    encolarFinal(&doble, 120);
    // Encolamos al final el valor de 121. Esto es en el espacio 5
    encolarFinal(&doble, 121);
    printf("Estado 2: \n");
    // Imprimimos los valores que contiene la cola Doble
    mostrarValores(doble);
    printf("\n");


    // * Estado 3
    // Encolamos al final de la Cola Doble el valor de 122. Esto es en el espacio 6
    encolarFinal(&doble, 122);
    // Desencolamos el valor Inicial de la Cola Doble. Esto es, el espacio 7 = 97
    desencolarInicio(&doble);
    // Desencolamos el valor Inicial de la Cola Doble. Esto es, el espacio 0 = 98
    desencolarInicio(&doble);
    // Desencolamos el valor Inicial de la Cola Doble. Esto es, el espacio 1 = 99
    desencolarInicio(&doble);
    printf("Estado 3: \n");
    // Imprimimos los valores de la cola Doble
    mostrarValores(doble);
    printf("\n");
}