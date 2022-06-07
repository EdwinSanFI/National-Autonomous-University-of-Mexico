#include <stdio.h>
#include <stdlib.h>

typedef struct Documento Documento;
typedef struct Cola Cola;

void llenarDocumento(Documento*, int, Cola*);
void ingresarDatos(Documento *, int);
void imprimirDatos(int, Cola *);
void encolarCola(Cola*, Documento*);
void imprimirTiempo(int);

int tam;
struct Documento{
    char nombre[20];
    char autor[20];
    int numPaginas;
    int tamano;
};  
struct Cola{
    int primero;
    int ultimo;
    Documento lista[100];
};

Cola crearCola(int tam){
	Cola c;
	c.primero=1;
	c.ultimo=0;
	return c;
}

int isEmptyC(Cola c){
	if(c.primero==c.ultimo+1)
		return 1;
	return 0;
}

void encolarC(Cola *c,Documento x){
	c->lista[c->ultimo]=x;
	c->ultimo+=1;
}
	
Documento desencolarC(Cola *c){
	if((isEmptyC(* c))==1)
		printf("la cola est%c vac%ca \n",160, 161);
	else{
		Documento aux = c->lista[c->primero-1];
		c->primero++;
		if(c->primero==c->ultimo+1){
			*c=crearCola(tam);
		}
		return aux;
	}
}
