#include <stdio.h>
#define TAM 2
#define NUM_DIR 2
char ai = 161, ae = 130, an = 164, ann = 165, aii = 214, aee = 144;
struct pelicula {
    char nombre[20];
    char genero[29];
    short anio;
    short numDirectores;
    char directores[NUM_DIR][20];
};
void llenarArreglo(struct pelicula *);
void imprimirArreglo(struct pelicula *);

int main () {
    struct pelicula arreglo[TAM];
    llenarArreglo(arreglo);
    imprimirArreglo(arreglo);
    return 0;
}
void llenarArreglo(struct pelicula arreglo [TAM]) {
    int iesimo, enesimo;
    for (iesimo = 0; iesimo < TAM; iesimo++)
    {
        struct pelicula movie;
        printf("###### Pel%ccula %d ######\n", ai, iesimo+1);
        printf("Ingrese nombre pel%ccula: ",ai);
        setbuf(stdin, NULL);
        scanf("%s", &movie.nombre);
        getchar();
        printf("Ingrese g%cnero pel%ccula: ",ae,ai);
        setbuf(stdin, NULL);
        scanf("%s", &movie.genero);
        getchar();
        printf("Ingrese a%co pel%ccula: ",an,ai);
        setbuf(stdin, NULL);
        scanf("%d", &movie.anio);
        movie.numDirectores = NUM_DIR;
        for (enesimo = 0; enesimo < NUM_DIR; enesimo++)
        {
            printf("Ingrese director %d: ", enesimo+1);
            setbuf(stdin, NULL);
            scanf("%s", &movie.directores[enesimo]);
            getchar();
        }
        arreglo[iesimo] = movie;
    }
}
void imprimirArreglo(struct pelicula arreglo [TAM]) {
    int iesimo, enesimo;
    printf("###### Contenido del arreglo ######\n");
    for (iesimo = TAM -1 ; iesimo >= 0; iesimo--)
    {
        printf("###### Pel%ccula %d ######\n", ai,iesimo+1);
        printf("PEL%cCULA: %s\n",aii, arreglo[iesimo].nombre);
        printf("G%cNERO: %s\n",aee,arreglo[iesimo].genero);
        printf("A%cO: %d\n",ann,arreglo[iesimo].anio);
        printf("DIRECTOR(ES): \n");
        for (enesimo = 0; enesimo < arreglo[iesimo].numDirectores; enesimo++)
        {
            printf("%s\n", arreglo[iesimo].directores[enesimo]);
        }
    }
}