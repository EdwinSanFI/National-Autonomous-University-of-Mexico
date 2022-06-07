#include <stdio.h>
int arr1[3][4][5][2], var, i, j;
int *point;

void main() {
    point = &arr1[0][0][0][0];

    for (var = 1; var < 122; var++) //Maximo
    { //10
        if (var < 11) // 5 - 50
        {
            *(point+var) = 5 * var;
        }
        else if (var == 11 || var < 21) // 6 - 60
        {
            *(point+var) = 6 * (var-10);
        }
        else if (var == 21 || var < 31)  //7 - 70
        {
            *(point+var) = 7 * (var - 20);
        }
        else if (var == 31 || var < 41) // 3 - 30
        {
            *(point+var) = 3 * (var - 30);
        }  
        // 20
        else if (var == 41 || var < 51) // 55 - 100
        {
            *(point+var) = 5 * (var-30);
        }
        else if (var == 51 || var < 61) // 66 - 120
        {
            *(point+var) = 6 * (var-40);
        }
        else if (var == 61 || var < 71)  //77 - 140
        {
            *(point+var) = 7 * (var - 50);
        }
        else if (var == 71 || var < 81) // 33 - 60
        {
            *(point+var) = 3 * (var - 60);
        }
        // 30
        else if (var == 81 || var < 91) // 105 - 150
        {
            *(point+var) = 5 * (var-60);
        }
        else if (var == 91 || var < 101) // 126 - 180
        {
            *(point+var) = 6 * (var-70);
        }
        else if (var == 101 || var < 111)  //147 - 210
        {
            *(point+var) = 7 * (var - 80);
        }
        else if (var == 111 || var < 121) // 63 - 90
        {
            *(point+var) = 3 * (var - 90);
        }
    }

    for (j = 0; j < 3; j++)
    {
        printf("Superplano %d \n[ \n", j);
        for (i = 0; i < 4; i++)
        {
            printf("En el plano %d queda de la siguiente manera: \n [", i);
            for (var = (((10*(i+1))+(j*40))-9); var < (((10*(i+1))+(j*40))+1); var++)
            {
                if (var == ((10*(i+1))+(j*40)))
                {
                    printf("%d",*(point+var));
                } else {
                    printf("%d, ",*(point+var));
                }        
            }   
            printf("]\n\n");
        }
        printf("]\n\n"); 
    } 
}