#include <stdio.h>
#include <stdlib.h>

typedef struct NodoDoble NodoDoble;
typedef struct ListaDoble ListaDoble;

ListaDoble crearListaDoble();
void agregarPrincipioNodoDoble(ListaDoble*, int);
void agregarFinalNodoDoble(ListaDoble*, int);
void agregarIesimoNodoDoble(ListaDoble*, int, int);
void eliminarInicioNodoDoble(ListaDoble*);
void eliminarFinalNodoDoble(ListaDoble*);
int validarPosicion(ListaDoble, int);
void imprimirListaDoble(ListaDoble);
void siEstaVacio(ListaDoble*, int );

int manuDoble();
void ColaDoble();