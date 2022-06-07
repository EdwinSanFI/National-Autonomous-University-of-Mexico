#include <stdio.h>
#include <omp.h>

int main1();
int main2();
int main3();
int main4();

int main() {
    #pragma omp parallel
    {
        int i;
        printf("Hola Mundo\n");
        for(i=0;i<10;i++)
        {
            printf("Iteracion: %d\n", i);
        }
    }
    printf("Adios \n");

    printf("\n");
    main1();
    printf("\n");
    main2();
    printf("\n");
    main3();
    printf("\n");
    main4();
    printf("\n");

    return 0;
}

int main1() {

    omp_set_num_threads(4);

    #pragma omp parallel num_threads(4)
    {
        int i;
        printf("Hola Mundo\n");
        for(i=0;i<10;i++)
        {
            printf("Iteracion: %d\n", i);
        }
    }
        printf("Adios \n");
    return 0;
}

int main2() {
    int i;
    #pragma omp parallel
    {
        printf("Hola Mundo\n");
        for(i=0;i<10;i++)
        {
            printf("Iteracion: %d\n", i);
        }
    }
    printf("Adios \n");
    return 0;
}

int main3() {
    int i;
    #pragma omp parallel private(i)
    {
        printf("Hola Mundo\n");
        for(i=0;i<10;i++)
        {
            printf("Iteracion: %d\n", i);
        }
    }
    printf("Adios \n");
    return 0;
}

int main4() {
    int tid, nth;
    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        nth = omp_get_num_threads();
        printf("Hola MUndo desde el hilo %d de un toal de %d\n", tid, nth);
    }
    printf("Adios");
    return 0;
}