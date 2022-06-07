#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define n 10

void llenaArreglo(int *a);
void suma(int *a, int *b, int *c);
void suma_parelela(int *a, int *b, int *c);
void suma_parelela_02(int *a, int *b, int *c);

void main(){
    int max, *a, *b, *c;
    double t1, t2;

    a=(int *)malloc(n*sizeof(int));
    b=(int *)malloc(n*sizeof(int));
    c=(int *)malloc(n*sizeof(int));

    llenaArreglo(a);
    llenaArreglo(b);

    // Mide el tiempo de la suma secuencial
    t1 = omp_get_wtime();
    suma(a,b,c);
    t2 = omp_get_wtime();
    printf("\nEl tiempo tardado secuencial es: %f\n", t2-t1);

    // Mide el tiempo de la suma paralela
    t1 = omp_get_wtime();
    suma_parelela(a,b,c);
    t2 = omp_get_wtime();
    printf("\nEl tiempo tardado paralelo de 2 hilos es: %f\n", t2-t1);

    // Mide el tiempo de la suma paralela
    t1 = omp_get_wtime();
    suma_parelela_02(a,b,c);
    t2 = omp_get_wtime();
    printf("\nEl tiempo tardado paralelo de 8 hilos es: %f\n", t2-t1);

}

// Funcion que llena el arreglo con numeros aleatorios
void llenaArreglo(int *a){
    int i;
    for(i=0;i<n;i++){
        a[i] = rand()%n;
        printf("%d\t",a[i]);
    }
    printf("\n");
}

// Suma de dos arreglos de manera secuencial
void suma(int *a, int *b, int *c){
    int i;
    for(i=0;i<n;i++){
        c[i] = a[i] + b[i];
        printf("%d\t",c[i]);
    }
}

// Suma de dos arreglos paralelozada con 2 hilos
void suma_parelela(int *a, int *b, int *c){
    printf("\n");
    int i, tid, inicio, fin;
    omp_set_num_threads(2);
    #pragma omp parallel private (inicio, fin, tid, i)
        {
        tid = omp_get_thread_num();
        inicio = tid*5;
        fin = (tid+1)*5-1;
        for(i = inicio; i<=fin; i++){
            c[i] = a[i] + b[i];
            printf("Hilo %d calculo c[%d]: %d + %d =  %d\n",tid,i,a[i],b[i],c[i]);
        }
    }
}

// Suma de dos arreglos paralelizada con 8 hilos
void suma_parelela_02(int *a, int *b, int *c){
    printf("\n");
    int i;
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        #pragma omp for
        for(i = 0; i<=n; i++){
            c[i] = a[i] + b[i];
            printf("Hilo %d calculo c[%d]: %d + %d =  %d\n",omp_get_thread_num(),i,a[i],b[i],c[i]);
        }
    }
}