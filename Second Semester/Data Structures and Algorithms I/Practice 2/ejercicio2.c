#include <stdio.h>
int arr1[3][4][5][2], var, f, i, j, k;
int *point;

void main() {
    int i;
    point = &arr1[0][0][0][0];
    var = 1;
    for (f = 0; f < 3; f++)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 5; j++)
            {
                for (k = 0; k < 2; k++)
                {
                    arr1[f][i][j][k] = var;
                    var+=2;               
                }
            }
        }
    }
    int a = *(point+3); //7
    int b = *(point+12); //25
    int c = *(point+27);//55
    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);
    printf("Valor de c: %d\n", c);
}