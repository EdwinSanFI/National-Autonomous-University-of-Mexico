#include <stdio.h>
#include <stdlib.h>

typedef struct Cola Cola;

Cola crearCola(int);
int isEmpty(Cola);
void encolarInicio(Cola*,int);
void encolarFinal(Cola*,int);
int desencolarInicio(Cola*);
int desencolarFinal(Cola*);
void mostrarValores(Cola);
void mostrarIndices(Cola);
void imprimirColaDoble(Cola*);