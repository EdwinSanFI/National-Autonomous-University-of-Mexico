#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

List createList();
void print_list(List);
void insertNodeBeginning(List*,int);
void insertNodeEnd(List*,int);
void deleteNodeBeginning(List*);
void deleteNodeEnd(List*);
int primerElemento(List);

int tamano(List);

// Por la actividad 1 se agregaron estas funciones
// * Actividad 1.a
void addIesimoLista(List*, int, int);
// * Actividad 1.b
int busqueda(List, int);
// * Actividad 1.c
void borrarIesimoLista(List*, int);
// * Actividad 1.d
void borrarMenoresLista(List* ,int);