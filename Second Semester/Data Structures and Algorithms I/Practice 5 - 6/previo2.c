// Programa para utilizar las funciones de la cola circular doble
// del programa "colaDoble.c"
#include <stdio.h>
#include <stdlib.h>
#include "colaDoble.c"

int main() {
    Cola cc;
    printf("Se crea la cola Doble\n");
    // Se crea la cola con un tamaño de 6 posiciones
    cc = crearCola(6);
    printf("Se verifica su estado, si se encuentra vacia o no\n");
    if (isEmpty(cc) == 1)
        {
            printf("%d : Est%c vac%ca\n", isEmpty(cc),aa,ai);
        } else {
            printf("%d : No est%c vac%ca\n", isEmpty(cc),aa,ai);
        }

    // Por cada operación a realizar, se imprimen los valores de la cola para 
    // visualizar los cambios hechos en la Cola Doble

    printf("Se hace un encolar al final del elemento 6\n");
    encolarFinal(&cc, 6);
    mostrarValores(cc);

    printf("Se hace un encolar al final del elemento 7\n");
    encolarFinal(&cc, 7);
    mostrarValores(cc);

    printf("Se hace un encolar al inicio del elemento 4\n");
    encolarInicio(&cc, 4);
    mostrarValores(cc);

    printf("Se hace un encolar al inicio del elemento 1\n");
    encolarInicio(&cc, 1);
    mostrarValores(cc);

    printf("Se hace un desencolar al final\n");
    desencolarFinal(&cc);
    mostrarValores(cc);

    printf("Se hace un desencolar al inicio\n");
    desencolarInicio(&cc);
    mostrarValores(cc);

    printf("\nSe muestran los valores finales\n");
    mostrarValores(cc);

    printf("\nSe muestran los %cndices\n",ai);
    mostrarIndices(cc);

    printf("\n");

    printf("Se verifica su estado, si se encuentra vacia o no\n");
    if (isEmpty(cc) == 1)
        {
            printf("%d : Est%c vac%ca\n", isEmpty(cc),aa,ai);
        } else {
            printf("%d : No est%c vac%ca\n", isEmpty(cc),aa,ai);
        }
}   