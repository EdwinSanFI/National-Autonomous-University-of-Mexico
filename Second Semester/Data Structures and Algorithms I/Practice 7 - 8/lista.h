#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo Nodo;
typedef struct Lista Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,int);  
void addFinalLista(Lista*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
int primerElemento(Lista);

// Por la actividad 1 se agregaron estas funciones 
// * Actividad 1.a
void addIesimoLista(Lista*, int, int);
// * Actividad 1.b
int busqueda(Lista, int);
// * Actividad 1.c
void borrarIesimoLista(Lista*, int);
// * Actividad 1.d
void borrarMenoresLista(Lista* ,int);