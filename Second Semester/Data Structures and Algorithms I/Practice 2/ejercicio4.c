#include <stdio.h>
int array[5][4], i, j;
char ao=162, au=163;
void change();
void main(){
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Ingrese los valores de [%d] y [%d]: \n", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    change();
}
void change() {
    for (i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
        {
            for (j = 0; j < 4; j++)
            {
                array[i][j] *= 2;
            }
            
        }
        else if (i == 1 || i % 3 == 0){
            for (j = 0; j < 4; j++)
            {
                array[i][j] *= 3;
            }
        }
    }    
    printf("\nEl arreglo multiplicado por 2 del n%cmero del rengl%cn divisibles entre 2 y\nmultiplicado por 3 del n%cmero de rengl%cn divisible entre 3 el resultado es: ",au,ao,au,ao);
    for (i = 0; i < 5; i++)
    { 
        printf("\n[");
        for (j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                printf("%d",array[i][j]);
            }
            else {
                printf("%d,",array[i][j]);
            }
        }
        printf("]\n");    
    }
    printf("\n");
}