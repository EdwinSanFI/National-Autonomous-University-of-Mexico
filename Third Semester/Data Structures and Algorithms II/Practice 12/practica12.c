#include <stdio.h>
#include <omp.h>
long long num_steps = 100000000;
double step;
double empezarS, terminarS, empezarP, terminarP, tiempoS, tiempoP, speedUp, eficiencia, overhead;
int nucleos;

int main(int argc, char* argv[])
{
    double x, pi, sum = 0.0;
    int i;
    step = 1.0/(double)num_steps;
    // Secuencial
    // Inicia contador
    empezarS = omp_get_wtime();
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4.0/(1.0 + x*x);
    }
    pi = step * sum;
    // Finaliza contador
    terminarS = omp_get_wtime();
    // Obtiene el tiempo de ejecucion
    tiempoS = terminarS-empezarS;
    printf("\nPi Secuencial = %15.12f\n", pi);
    printf("Tiempo Secuencial = %15.12f segundos \n\n", tiempoS);


    sum=0;
    // Paralelo
    // Inicia contador
    empezarP = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum) private(i,x)
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4.0/(1.0 + x*x);
    }
    pi = step * sum;
    // Finaliza contador
    terminarP = omp_get_wtime();
    // Obtiene el tiempo
    tiempoP = terminarP-empezarP;
    // Obtiene el SpeedUp
    speedUp = tiempoS/tiempoP;
    // Obtiene el numero de nucleos de la computadora
    nucleos = omp_get_num_procs();
    // Obtiene la eficiencia
    eficiencia = speedUp / nucleos;
    // Obtiene el overhead
    overhead = tiempoP - tiempoS/nucleos;
    printf("\nPi Paralelo = %15.12f\n", pi);
    printf("Tiempo Paralelo = %15.12f segundos\n", tiempoP);
    printf("\nNucleos del procesador = %d\n", omp_get_num_procs());
    printf("SpeedUp = %f\n", speedUp);
    printf("Eficiencia = %f\n", eficiencia);
    printf("Overhead = %f\n", overhead);

    printf("\n");

    return 0;
}