#include<stdio.h>
//Declaramos las funciones
void ingresar();
void sumarArray();
void multiplicar();
void multiplicar3(); 
void sumarentre3(); 
//Declaramos las variables globales para su fácil uso.
int i, array[8], arraypor3[8], suma, multiplicarArray=1, suma3;
char aa = 160, ae = 130, ai = 161, ao = 162, au = 163;
//Función principal
int main() {
    int opcion;
    printf("\n ** Men%c ** \n", au); 
    while (1) //Muestra el menú, este se dejará de repeti hasta que el usuario ingreseun número diferente entre 1 y 5 
    {
        printf("\n1) Ingresar o modificar elementos del arreglo \n");
        printf("2) Mostrar la Suma de los elementos \n");
        printf("3) Realizar la multiplicaci%cn de los elementos\n",ao);
        printf("4) Realizar la suma s%clo de los elementos divisibles entre 3\n", ao);
        printf("5) Multiplicar por 3 cada elemento del arreglo\n");
        scanf("%d", &opcion); //Guarda el valor ingresado para ejecutar una instrucción del menú
        switch (opcion)
        {
        case 1:
            ingresar(); // Si ingresa 1 se ejecuta esta función 
            break;
        case 2:
            sumarArray(); //Si ingresa 2 se ejecuta esta función
            break;
        case 3:
            multiplicar(); //Si ingresa 3 se ejecuta esta función
            break;
        case 4:
            sumarentre3(); // Si ingresa 4 se ejecuta esta función
            break;
        case 5:
            multiplicar3(); //Si ingresa 5 se ejecuta esta función
            break;
        default:
            printf("No se reconoce ese d%cgito",ai); //Si no ingresa un número entre el rango de 1 y 5
            return 0; //Retorna un valor de 0 para cancelar el ciclo While
            break;
        }
    }   
}

void ingresar() { //La función para ingresar o modificar los elementos del arreglo
    for (i = 0; i < 8; i++) //Inicia un ciclo for para registrar los valores de cada espacio del arreglo
    {
        printf("Ingrese el valor del elemento [%d]", i+1);
        scanf("%d", &array[i]);
    }    
    //Desoués de ingresar o modificar los valores del arreglo, se muestra al usuario los valores ingresados
    printf("\nEl array Ingresado es [");
    for (i = 0; i < 7; i++)
    {
        printf("%d, ", array[i]);
        if (i == 6)
        {
            printf("%d]", array[i+1]);
        }
    }
    printf("\n\n");
}

void sumarArray() { //Función para sumar entre si los elementos del arreglo
    for (i = 0; i < 8; i++) //Inicia un ciclo for para ocupar los elementos del arreglo
    {
        suma += array[i]; //Cada valor del elemento lo sumará a la variable suma
    }
    printf("La suma de los elementos del arreglo da: %d\n", suma); //Imprime el valor de la suma
    //Imprime los elementos del arreglo con el que está trabajando
    printf(" \nEl array original es [");
    for (i = 0; i < 7; i++)
    {
        printf("%d, ", array[i]);
        if (i == 6)
        {
            printf("%d]\n\n", array[i+1]);
        }
    }
    printf("\n\n");
}

void multiplicar() { //Función para multiplicar entre si los elementos del arreglo
    for (i = 0; i < 8; i++) //Ciclofor para ocupar todos los elementos del arreglo
    {
        multiplicarArray *= array[i]; //La variable ultiplicarArray inicia en 1, y esta va a guardar el valor de la multiplicación de su propio valor con cada 
    } //Elemento del arreglo
    printf("La multiplicaci%cn del array es: %d \n", ao, multiplicarArray); //Imprime el valor de la multiplicación 
    //Imprime los elementos del arreglo con el que está trabajando
    printf(" \nEl array original es ["); 
    for (i = 0; i < 7; i++)
    {
        printf("%d, ", array[i]);
        if (i == 6)
        {
            printf("%d]\n\n", array[i+1]);
        }
    }
    printf("\n\n");
}
void sumarentre3() { //Función de sumar los elementos divisibles entre 3
    for (i = 0; i < 8; i++) //Recorre los elemtnos del arreglo
    {
        if (array[i] % 3 == 0) //Cada elemento lo divide entre 3, y si su residuo es 0, es divisible entre 3
        {
            suma3 += array[i]; //Y ese valor divisible entre 3 será sumado a la variable suma3
        }
    }
    printf("Los suma de los elementos divisibles entre 3 da c%cmo resultado: %d \n", ao, suma3); //Imprime el valor de la suma
    //Imprime los elementos del arreglo con el que está trabajando
    printf(" \nEl array original es [");
    for (i = 0; i < 7; i++) 
    {
        printf("%d, ", array[i]);
        if (i == 6)
        {
            printf("%d]\n\n", array[i+1]);
        }
    }
    printf("\n\n");
}
void multiplicar3() { //Función para multiplicar cada elemento del arreglo por 3
    for (i = 0; i < 8; i++) //Recorre los elementos del arreglo
    {
        arraypor3[i] = 3 * array[i]; //Cada elemento se multiplica por 3 y será guardada en un nuevo arreglo
    }
    
    printf("\nEl arreglo multiplicado por 3 queda de la siguiente manera: ["); 
    for (i = 0; i < 7; i++) //Recorremos cada elemento del arreglo arraypor3[] para imprimir sus elementos
    {
        printf("%d, ", arraypor3[i]);
        if (i == 6)
        {
            printf("%d]", arraypor3[i+1]);
        }
    }
    //Imprime los elementos del arreglo con el que está trabajando
    printf(" \nEl array original es [");
    for (i = 0; i < 7; i++)
    {
        printf("%d, ", array[i]);
        if (i == 6)
        {
            printf("%d]\n\n", array[i+1]);
        }
    }
    printf("\n\n");
}
