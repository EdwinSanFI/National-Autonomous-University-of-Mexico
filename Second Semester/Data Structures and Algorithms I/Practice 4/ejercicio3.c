#include "computadora.h"

char an=164;
void llenar();
void imprimir();

int main () {
    int tam, i;
    Computadora *dir;
    printf("Ingrese el tama%co del del arreglo: ",an);
    scanf("%d", &tam);
    dir = calloc(tam, sizeof(Computadora));
    llenar(dir, tam, i);
    imprimir(dir, tam, i);
}
void llenar(Computadora *relleno, int tam, int i){
    for (i = 0; i < tam; i++)
    {
        printf("\nIngrese la marca de la Computadora #%d\n\t", i+1);
        setbuf(stdin, NULL);
        scanf("%15[^\n]",&(relleno[i].marca));
        printf("Ingrese el Modelo de la Computadora #%d\n\t", i+1);
        setbuf(stdin, NULL);
        scanf("%15[^\n]",&(relleno[i].modelo));
        printf("Ingrese el procesador de la Computadora #%d\n\t", i+1);
        setbuf(stdin, NULL);
        scanf("%15[^\n]",&(relleno[i].procesador));
        printf("Ingrese la memoria de la Computadora #%d\n\t", i+1);
        setbuf(stdin, NULL);
        scanf("%15[^\n]",&(relleno[i].memoria));
    }   
}
void imprimir(Computadora *impresion, int tam, int i){
    for (i = 0; i < tam; i++)
    {
        printf("\nLa marca de la computadora #%d es: %s", i+1, (impresion[i].marca));
        printf("\nEl modelo de la computadora #%d es: %s", i+1, (impresion[i].modelo));
        printf("\nEl procesador de la computadora #%d es: %s", i+1, (impresion[i].procesador));
        printf("\nLa memoria de la computadora #%d es de: %s\n", i+1, (impresion[i].memoria));
    }   
}