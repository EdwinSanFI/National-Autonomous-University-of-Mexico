#include "Pila.h"
#include "Pila.c"
char an=164;
int main() {
    int i, j, tam;
    printf("De que tama%co se desea la pila?. Se recomienda que sea de 8\n", an);
    scanf("%d", &tam);
    Pila ejercicio = crearPila(tam);
    Pila vacia1 = crearPila(tam);
    Pila vacia2 = crearPila(tam);
    printf("Ingrese los valores para llenar la pila\n");
    
    for (i = 0; i < tam; i++)
    {
        printf("%d: ", i);
        scanf("%i", &ejercicio.lista[i]);
        push(&ejercicio, ejercicio.lista[i]);
    }
    printf("\n");
    imprimirPila(ejercicio, tam);

    for (i = 0; i < tam; i++)
    {
        // Si el elemento de la pila ejercicio [i] es mayor que el elemento siguiente y a la vez
        // es distinta al elemento siguiente y es mayor al elemento inicial de la pila vacia 2,
        // se hace un psuh a la pila vacia2
        if (ejercicio.lista[i] > ejercicio.lista[i+1] && ejercicio.lista[i] != ejercicio.lista[i+1] && ejercicio.lista[i] > vacia2.lista[0]) {
            // Se añade a la pila de los máximos
            push(&vacia1, vacia2.lista[0]);
            pop(&vacia2);
            push(&vacia2, ejercicio.lista[i]);
        }
        // De lo contrario, se añade a la pila auxiliar en donde se guardan los demás elementos
        else {
            // Se añade a la pila de los mínimos
            push(&vacia1, ejercicio.lista[i]);
        }
    }
    printf("La pila con los elementos menores es: \n");
    imprimirPila(vacia1, tam);
    printf("El elemento mayor es: %d\n", vacia2.lista[0]);
    imprimirPila(vacia2, tam);

}