// Programa a utilzar las funciones para crear una PILA y COLA de los programas
// "pila.c" y "cola.c"
#include <stdio.h>
#include <stdlib.h>
#include "Cola.c"
#include "Pila.c"

char an = 164;

int main() {
    int op, tam;
    Pila pp;
    Cola cc;
    printf("Con que desea trabajar?\n");
    printf("1) Pila\n");
    printf("2) Cola\n\n");
    scanf("%i", &op);
    printf("De que tama%co se desea la pila?\n Se recomienda que sea de 5\n", an);
    scanf("%d", &tam);
    switch (op)
    {
        case 1:
            printf("\nSe crea la pila\n");
            pp = crearPila(tam);

            printf("Se verifica su estado, si se encuentra vac%ca o no\n",ai);
            if (isEmpty(pp) == 1)
            {
                printf("%d : Esta vacia\n\n", isEmpty(pp));
            } else {
                printf("%d : No esta vacia\n\n", isEmpty(pp));
            }
            
            printf("Se hace un push para agregar en la %cltima posici%cn\n",au,ao);
            push(&pp, 5);
            imprimirPila(pp, tam);

            printf("Se hace un push para agregar en la %cltima posici%cn\n",au,ao);
            push(&pp, 8);
            imprimirPila(pp, tam);
            
            printf("Se hace un push para agregar en la %cltima posici%cn\n",au,ao);
            push(&pp, 10);
            imprimirPila(pp, tam);
            
            printf("Se hace un pop para eliminar el %cltimo elemento\n",au);
            pop(&pp);
            imprimirPila(pp, tam);
            
            printf("Se hace un pop para eliminar el %cltimo elemento\n",au);
            pop(&pp);
            imprimirPila(pp, tam);
        
            printf("Se verifica su estado, si se encuentra vac%ca o no\n",ai);
            if (isEmpty(pp) == 1)
            {
                printf("%d : Esta vacia\n\n", isEmpty(pp));
            } else {
                printf("%d : No esta vacia\n\n", isEmpty(pp));
            }
            break;
        
        case 2:
            printf("\nSe crea la cola\n");
            cc = crearCola(tam);

            printf("Se verifica su estado, si se encuentra vac%ca o no\n",ai);
            if (isEmptyC(cc) == 1)
            {
                printf("%d : Esta vac%ca\n\n", isEmptyC(cc),ai);
            } else {
                printf("%d : No esta vac%ca\n\n", isEmptyC(cc),ai);
            }
            
            printf("Se hace un encolar para agregar en la primera posici%cn\n",ao);
            encolarC(&cc, 1);
            imprimirCola(cc, tam);

            printf("Se hace un encolar para agregar en la primera posici%cn\n",ao);
            encolarC(&cc, 7);
            imprimirCola(cc, tam);

            printf("Se hace un encolar para agregar en la primera posici%cn\n", ao);
            encolarC(&cc, 15);
            imprimirCola(cc, tam);

            printf("Se hace un desencolar para eliminar el primera elemento\n");
            desencolarC(&cc);
            imprimirCola(cc, tam);

            printf("Se hace un desencolar para eliminar el primera elemento\n");
            desencolarC(&cc);
            imprimirCola(cc, tam);

            printf("El primer elemento: %d\n\n", firstC(cc));
            printf("El contenido de la cola es: \n\n");
            imprimirCola(cc, tam);

            printf("Se verifica su estado, si se encuentra vac%ca o no\n",ai);
            if (isEmptyC(cc) == 1)
            {
                printf("%d : Esta vac%ca\n\n", isEmptyC(cc),ai);
            } else {
                printf("%d : No esta vac%ca\n\n", isEmptyC(cc),ai);
            }
            break;

        default:
            return -1;
            break;
    }   
}