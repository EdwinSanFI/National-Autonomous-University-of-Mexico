#include <stdio.h>
void main() {
    int w = 10, x = 20, y = 30, z = 40, r1, r2, r3; //Variables
    int *p1, *p2, *p3, *p4; //apuntadores, error en p3  
    p1 = &w; //10
    p2 = &x; //20 - Antes aquí había un error "*p2" 
    p3 = &y; //30 - Aquí había un error "*p3" y le faltaba "&y"
    p4 = p1; //10 - Aquí había un error "*p1"
    r1 = *p1 + *p2; //30 - Aqui había un error "p1"
    r2 = *p3 * *p4; //300 - Aquí había un error "p3" y "p4"
    r3 = *p2 + *p3; //50 -  Aquí había un error "*r3"
    printf("Los resultados son: %d, %d, y %d", r1, r2, r3);

    int w = 10, x = 20, y = 30, z = 40, r1, r2, r3; 
    int *p1, *p2, *p3, *p4; 
    p1 = &w;
    p2 = &x; 
    p3 = &y;
    p4 = p1; 
    r1 = *p1 + *p2; 
    r2 = *p3 * *p4; 
    r3 = *p2 + *p3; 
    printf("Los resultados son: %d, %d, y %d", r1, r2, r3);


    // int w = 10, x = 20, y = 30, z = 40, r1, r2, r3; 
    // int *p1, *p2, p3, *p4; 
    // p1 = &w; 
    // *p2 = &x; 
    // *p3 = &y; 
    // p4 = *p1; 
    // r1 = p1 + *p2; 
    // r2 = p3 * p4; /
    // *r3 = *p2 + *p3; 
    // printf("Los resultados son: %d, %d, y %d", r1, r2, r3);
}
