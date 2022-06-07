#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoC NodoC;
typedef struct ListaC ListaC;
typedef struct Computadora Computadora;

typedef struct Computadora{
    int id;
    char marca[15];
    char tipo[15];
    char procesador[15];
    char memoria[15];
    char sistenmaOperativo[15];
}Computadora;

ListaC crearListaC();
void print_listC(ListaC);
void addPrincipioListaC(ListaC*,Computadora);
void addFinalListaC(ListaC*,Computadora);
void borrarPrimeroC(ListaC*);
void borrarUltimoC(ListaC*);
int primerElementoC(ListaC);

Computadora crearCompu(int);

Computadora Computadora1();
Computadora Computadora2();
Computadora Computadora3();
Computadora Computadora4();

void printComputadora(Computadora);
void BuscarCirc(ListaC, int);
int menuCircular();
void menuLista(int, ListaC*);

NodoC imprimirNodo (ListaC , char , NodoC *);
void recorrerLista(ListaC);