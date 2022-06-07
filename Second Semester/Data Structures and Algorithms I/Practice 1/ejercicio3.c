#include<stdio.h>
#include <math.h> // se incluye la librería math.h para ocupar la función de elevar al cuadrado.
void binario();
void punto();
void representacion(); //Declaramos las funciones que ocuparemos
int  opciones, i, ceros, resultado, cuadrado,  entero, resta,  numeros[9], exponente[9], calcularbinario[8]; // Se declaran las variables a ocupar
float sumatoriaNegativa, resultadoSumatoria, sumatoria; //Las variables flotantes se utilizan en el cálculo de punto fijo.
char aa = 160, ae = 130, ai = 161, ao = 162, au = 163; // estos son las variables de tipo caractér para ocupar acentos

int main () {
    for (i = 0; i < 9; i++)
    {
        printf("** Ingrese los valores de 0 o 1 en el lugar [%d] **  ", i);
        scanf("%d", &numeros[i]); //En esta variable se guardará el arreglo de los 9 elementos siendo estos de [0] a [8]
        if (numeros[i] != 0 && numeros[i] != 1) // Comprueba que los números ingresados sean 0's o 1's
        {
            printf("Solo se admiten 0 y 1\n"); // Si es un número diferente a 0 o 1, se imprime esto
            i = -1; // Y se le asigna el valor a la i de -1, así, el ciclo for terminará esta repetición y sumará 1
        } //Lo cual empezaría desde 0 el valor de i y repetiria el proceso de ingreso de valores
    }
    //Esto es el menú a imprimir
    printf("\n1) Binario Puro \n");
    printf("2) Punto fijo (6 bit entero y 3 bit decimal) \n");
    printf("3) Representaci%cn de complemeto a 2 \n",ao);
    scanf("%d", &opciones); // La variable guardará la opción que quiera realizar el usuario
    switch (opciones)
    {
    case 1:
        binario(); //Si fuera el valor de 1, se ejecuta la función de binario
        break;
    case 2:
        punto(); //Si fuera el valor de 2, se ejecuta la función de punto
        break;
    case 3:
        representacion(); //Si fuera el valor de 3, se ejecuta la función de representación
        break;
    default:
        printf("No se reconoce ese valor");
        break;
            
    }
}

void binario() { //Esta función convierte de números binario a binario puro
    for (i = 0; i < 9; i++) //Empieza el ciclo desde 0 hasta llegar al 9
    {
        if (numeros[i] == 1) // Si la posición de "i" en el arreglo es 1 
        {
            calcularbinario[i] = 8 - i; // Obtiene el número en donde elevará a la 2
            cuadrado = pow(2, calcularbinario[i]); // Guarda el valor del 2 elevado al número de la variable calcularbinario[i]
            resultado += cuadrado; // Y lo sumará en esta variable, aquí se van registrando los valores elevados del número 2.
        }
    }
    printf("El c%cdigo Binario representado en n%cmero da: %i",ao,au,resultado); //Imprime el resultado de la función 
}

void punto() { // Esta función es para punto Fijo, está destinada 6 bits para el entero y 3 para el decimal
    for (i = 0; i < 9; i++) // El ciclo for va de 0 a 6 para qué elementos tienen 1 
    {
        if (numeros[i] == 1) // Si ese elemento tiene 1
        {
            exponente[i] = 5 - i; // La variable es el resultado de de una resta de 5 menos el valor de la i
            //Un ejemplo: 5-0 = 5, y como contamos los exponentes de izquierda a derecha empezando por el exponente más alto, así se obtiene qué elemento
            //Tiene 1 y qué valor tiene. 
            sumatoria += pow (2, exponente[i]); // Se guarda la suma de elevar el número 2 al valor del exponente (obtenido anteriormente)  
        }
    }
    printf("El n%cmero es: %.3f", au,sumatoria); //Se imprime ese valor
}

void representacion() { // Esta es la función del complemento A 2
    for (i = 0; i < 9; i++) //Primero necesitamos saber el complemento a 1 
    {
        if (numeros[i] == 0) //Si en el lugar i el bit vale 0
        {
            numeros[i] += 1; // Se le sumará 1, así, se puede "cambiar" el 0 por el 1
        }
        else if (numeros[i] == 1) { // Si en el lugar i el bit vale 1
            numeros[i] -= 1; // Se le restará 1, así se cambia el valor de 1 a 0
        }
    }
    numeros[8] += 1; // En el complemento A 2 se suma 1 al último elemento del arreglo, sin importar si vale 1 o 0
    for (i = 8; i > 0; i--)// Recorremos cada valor del arreglo
    {
        if (numeros[i] > 1) // Si un valor da más de 1 (Como en el caso que el bit final fuera 1 y se le sumara 1, esto me daría 2 y no se puede)
        {
            numeros[i] = 0; // El valor que era mayor a 1, se le asigna como 0
            numeros[i-1] += 1; // Y le pasa el valor de 1 al elemento anterior
        }
    } //Esto pasará por cada valor del elemento
    for (i = 0; i < 9; i++) //Recorremos el arreglo elemento por elemento
    {
        ceros += numeros[i]; //Sumaremos el valor de cada elemento
    }
    if (ceros == 2)
    /* Si la sumatoria me da 2 (esto es porque si el usuario ingresa a todos los elementos "0", 
    al cambiar a complejo A 1 serían todos "1", pero al sumarle 1 al ultimo elemento, se recorre ese valor hacia la izquierda y ocupará los 8 bits dando 0, 
    pero se agrega un 9no bit en donde da un 2) 
    [0 0 0 0 0 0 0 0] <-Ingresado
    [1 1 1 1 1 1 1 1] <-A 1
                  +1 
    [1 1 1 1 1 1 2 0]
  [2 0 0 0 0 0 0 0 0]  --> De aquí sale el 2, la sumatoria de todos los elementos
    */
    {
        printf("El arreglo no puede ser representado con 8 bits el complemento A 2\n"); //Se imprime esto
    } else { // Y si no es iguala 2 cumple esta parte
        printf("\nEl complemento a 2 es: "); 
        for (i = 0; i < 9; i++) 
        {
            printf("%d", numeros[i]); //Imprime los valores del Complemento A 2    
        }
    }
    printf("\n");
}