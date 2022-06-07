#include "Cola.c"
#include "Cola.h"
#include "acentos.h"

int main() {
    // Se crea una cola
    Cola queue = crearCola(8);
    printf("\nSe crea la cola\n");

    printf("Se verifica su estado, si se encuentra vac%ca o no\n",ai);
    if (isEmptyC(queue) == 1)
    {
        printf("%d : Esta vac%ca\n\n", isEmptyC(queue),ai);
    } else {
        printf("%d : No esta vac%ca\n\n", isEmptyC(queue),ai);
    }
    // Se encola en la posición 1
    printf("Se encola el valor de 8\n");
    encolarC(&queue, 8);
    imprimirCola(queue, 8);
    // Se encola en la posición 2
    printf("Se encola el valor de 14\n");
    encolarC(&queue, 14);
    imprimirCola(queue, 8);
    // Se encola en la posición 3
    printf("Se encola el valor de 22\n");
    encolarC(&queue, 22);
    imprimirCola(queue, 8);
    // Se encola en la posición 4
    printf("Se encola el valor de 28\n");
    encolarC(&queue, 28);
    imprimirCola(queue, 8);
    // Se encola en la posición 5
    printf("Se encola el valor de 30\n");
    encolarC(&queue, 30);
    imprimirCola(queue, 8);
    // Se encola en la posición 6
    printf("Se encola el valor de 33\n");
    encolarC(&queue, 33);
    imprimirCola(queue, 8);
    // Se encola en la posición 7
    printf("Se encola el valor de 40\n");
    encolarC(&queue, 40);
    imprimirCola(queue, 8);
    // Se desencola la posición 1
    printf("Se desencola el primer elemento\n");
    desencolarC(&queue);
    imprimirCola(queue,8);
    // Se desencola la posición 2
    printf("Se desencola el primer elemento\n");
    desencolarC(&queue);
    imprimirCola(queue,8);
    // Se desencola la posición 3
    printf("Se desencola el primer elemento\n");
    desencolarC(&queue);
    imprimirCola(queue,8);
    // Se encola en la posición 8
    printf("Se encola el valor de 50\n");
    encolarC(&queue, 50);
    imprimirCola(queue, 8);
    // Se desencola la posición 4
    printf("Se desencola el primer elemento\n");
    desencolarC(&queue);
    imprimirCola(queue,8);

}