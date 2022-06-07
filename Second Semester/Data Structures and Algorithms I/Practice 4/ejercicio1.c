#include <stdio.h>
#include <stdlib.h>


main(){
	char au = 163;
	int cont,arreglo[]={35,40,45,50,55}; 
	int variable, i;
	int *ptr = calloc(10, sizeof(int));
	char *ptr2 = malloc(100*sizeof(char));
	int *ptr3;
	
	
	// ! Solicitando al usuario que ingrese vlaores en las localidades de memoria reservadas. Deben de ser múltiplos de 4
	for (i = 0; i < 10; i++)
	{
		printf("Ingrese valores m%cltiplos de 4 para el espacio[%d]: ", au,i);
		scanf("%d", &ptr[i]);
		if (ptr[i] % 4 == 0)
		{
			continue;
		} else {
			printf("Por favor, ingrese valores m%cltiplos de 4\n",au);
			i -= 1;
		}
	}
	printf("\n");
	//Imprimiendo direcciones de un arreglo
	for(cont=0;cont<10;cont++){
		printf("direccion arreglo[%d]=%d   valor arreglo[%d]=%d\n",cont,&arreglo[cont],cont,arreglo[cont]);
	}
	printf("\n"); 
	
	
	//Imprimiendo direcciones y contenido de un apuntador de memoria din�mica reservado con malloc
	printf("Sin realloc\n");
	for(cont=0;cont<10;cont++){
		printf("direccion=%d   *valor=%d \n",ptr+cont, *(ptr+cont));
	}
	printf("\n");

	// ! Reasigna con un realloc el "ptr"
	ptr = (int * ) realloc(ptr, 20);
	ptr3 = (int * ) realloc(ptr, 20);
	
	for (i = 0; i < 20; i++)
	{
		printf("Ingrese valores m%cltiplos de 4 para el espacio[%d]: ", au,i);
		scanf("%d", &ptr[i]);
		if (ptr[i] % 4 == 0)
		{
			continue;
		} else {
			printf("Por favor, ingrese valores m%cltiplos de 4\n",au);
			i -= 1;
		}
	}
	printf("\n");

	// * Imprime las direcciones y valores asignados por realloc
	printf("Con realloc a la variable ptr\n");
	for(cont=0;cont<20;cont++){
		printf("direccion=%d   *valor=%d \n",ptr+cont,cont ,*(ptr+cont));
	}
	printf("\n");
	printf("Con realloc a la variable ptr3\n");
	for(cont=0;cont<20;cont++){
		printf("direccion=%d   *valor=%d \n",ptr3+cont, cont, *(ptr3+cont));
	}
	printf("\n");
    /* No remover estos comentarios, (por lo menos no antes de acabar la actividad1) /*/
 	//strcpy(ptr2,"hola amigo como estas");  //esto si se puede hacer 
	// //ptr2 = "Hola amigo como estas";    //nunca haga esto compa 
  	//for(cont=0;cont<100;cont++){
 	//   printf("%c",ptr2[cont]);     //no vaya a descomentar esta linea, ni cambiar el contador del for a 1000 (
 	//}
    
	free(ptr);	
	free(ptr2);
	free(ptr3);

	system("PAUSE");
}

