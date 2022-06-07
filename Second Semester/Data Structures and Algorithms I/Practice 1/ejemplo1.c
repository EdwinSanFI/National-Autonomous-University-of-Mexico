#include <stdio.h>
/* 
    Programa que realiza la implementación de al escitala espartana.
    Para cifrar y descifrar.
*/

void crearMensaje();
void descifrarMnesaje();

int main () {
    short opcion = 0;
    while(1) {
        printf("\n\t***Escitala ESPARTANA***\n");
        printf("Que desea realizar?\n");
        printf("1) Crear mensaje cifrado.\n");
        printf("2) Descifrar mensaje.\n");
        printf("3) Salir.\n");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            crearMensaje();
            break;
        case 2:
            descifrarMnesaje();
            break;
        case 3:
            return 0;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    }
    return 0;
}
void crearMensaje() {
    int ren, col, i, j, k = 0;
    printf("Ingrese el tamano de la Iscitala:\n");
    printf("\nRenglones:");
    scanf("%i", &ren);
    printf("Columnas:");
    scanf("%i", &col);
    char escitala[ren][col];
    char texto[ren*col];

    printf("Escriba el texto a cifrar:\n");
    scanf("%s", &texto);

    for (i = 0; i < ren; i++)
    {
        for (j = 0; j < col; j++)
        {
            escitala[i][j] = texto[k++];
        }
    }
    printf("El texto en la tira queda de la siguiente manera:\n");
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < ren; j++)
        {
            printf("%c", escitala[j][i]);
        }        
    }
    printf("\n");
}

void descifrarMnesaje()
{
    int ren, col, i, j, k=0;
    printf("Ingresar el tamano de la escitala:\n");
    printf("\nRenglones:");
    scanf("%i",&ren);
    printf("\nColumnas:");
    scanf("%i",&col);
    char escitala[ren][col];
    char texto[ren*col];

    printf("Escriba el texto a descifrar:\n");
    scanf("%s", texto);

    for (i=0 ; i<col ; i++)
    {
        for (j=0 ; j<ren ; j++)
        {
            escitala[j][i] = texto[k++];
        }
    }

    printf("El texto descifrado es:\n");
        for (i=0 ; i<ren ; i++)
        {
            for (j=0 ; j<col ; j++)
            {
                printf("%c", escitala[i][j]);
            }
        }
}