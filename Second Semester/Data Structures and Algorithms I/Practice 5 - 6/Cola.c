#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>

int tam;
struct Cola{
    int primero;
    int ultimo;
    int lista[100];
};

Cola crearCola(int tam){
	Cola c;
	c.primero=1;
	c.ultimo=0;
	// Se incializan todos los valores de la Cola en 0's
	int i;
	for (i = 0; i < tam; i++)
	{
		c.lista[i] = 0;
	}
	return c;
}

int isEmptyC(Cola c){
	if(c.primero==c.ultimo+1)
		return 1;
	return 0;
}

void encolarC(Cola *c,int x){
	c->lista[c->ultimo]=x;
	c->ultimo+=1;
}
	
int desencolarC(Cola *c){
	if((isEmptyC(* c))==1)
		printf("la cola est%c vac%ca \n",160, 161);
	else{
		int aux = c->lista[c->primero-1];
		// Se le asigna 0 al elemento eliminado
		c->lista[c->primero-1] = 0;
		c->primero++;
		if(c->primero==c->ultimo+1){
			*c=crearCola(tam);
		}
		return aux;
	}
}

int firstC(Cola c){
	return c.lista[c.primero-1];
}

//  Agregar los indices ultimo y primero 
void imprimirCola(Cola c, int tam){
	int i;
	for (i = 0; i < tam; i++)
	{
		printf("Posicion %d \t valor %d \n",i+1, c.lista[i]);
	}

	// printf("El tope es actual es: %d\n\n", firstC(c));
	printf("El indice del primero: %d\n\n", c.primero);
	printf("El indice del ultimo: %d\n\n", c.ultimo);
}
