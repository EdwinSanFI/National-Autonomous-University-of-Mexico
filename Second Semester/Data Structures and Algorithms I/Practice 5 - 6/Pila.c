#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>
#include "acentos.h"

struct Pila{
    int tope;
    int lista[100];
};
// Agregar esto al word
Pila crearPila(int tam){
	Pila p;
	p.tope=0;
	// Se incializan todos los valores de la Pila en 0's
	int i;
	for (i = 0; i < tam; i++)
	{
		p.lista[i] = 0;
	}
	
	return p;
}

int isEmpty(Pila p){
	if(p.tope==0)
		return 1;
	return 0;
}

void push(Pila *p,int x){
	p->lista[p->tope]=x;
	p->tope++;
}


int pop(Pila *p){
	if(isEmpty(*p)==1){
		printf("La pila ya est%c vac%ca. \n",aa,ai);
		return -1;
	}
	else{
		int aux = p->lista[p->tope-1];
		// Se le asigna 0 al elemento eliminado
		p->lista[p->tope-1] = 0;
		p->tope--;
		return aux;
	}
}

int top(Pila pila){
	if(isEmpty(pila)==1){
		printf("La pila ya est%c vac%ca. \n\n",160,161);
		return -1;
	}
	else{
		return pila.lista[pila.tope-1];
	}
}

// Agregar a word el parámetro int 
void imprimirPila(Pila p, int tam){
	int i;
	for (i = 0; i < tam; i++)
	{
	    printf("Posicion %d \t valor %d \n",i+1, p.lista[i]);
	}
	printf("El tope es actual es el elemento: %d\n\n", top(p));
}
