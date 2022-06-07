#include<stdio.h>
#include<math.h>
int incisoA, incisoB;
char ao = 162, au = 163;;
void valor();
void main () {
    int valora, valorb;
    printf("Ingrese el primer valor: ");
    scanf("%d", &valora);
    printf("Ingrese el segundo valor: ");
    scanf("%d", &valorb);
    valor(&valora, &valorb);
    printf("Resultado de elevar el primero a la potencia del n%cmero del segundo: %d\n", au,valorb);
    printf("La divisi%cn entre el valor obtenido anteriormente y el primero valor ingresado  da: %d\n", ao, valora);
}
void valor(int *a, int *b) {
    *b = pow(*a, *b);
    *a = *b / *a;
}