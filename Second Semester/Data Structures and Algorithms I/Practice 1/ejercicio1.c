#include<stdio.h>
void main() {
    int i, j, k;
    int arr[2][3][5] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60};
    //Para imprimir los valores del arreglo necesitamos 3 ciclos for anidados
    for (i = 0; i < 2; i++) // El primero es del elemento más "afuera", 
    {
        for (j = 0; j < 3; j++) // El segundo es para los renglones
        {
            for (k = 0; k < 5; k++) // El tercero es para las columnas
            {
                printf("Arreglo[%d][%d][%d]: %d \n", i, j, k, arr[i][j][k]); //Aquí se imprime los valores del arreglo con su respectiva posición 
            }
        }
    }
} //Había un error en el 2do y 3er ciclo for, los cuales sus valores a donde querían llegar (3 y 5) erran erroneos pues tenían otros valores (5 y 3)