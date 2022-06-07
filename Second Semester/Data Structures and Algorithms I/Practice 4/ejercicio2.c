#include "Alumno.h"

void llenarAlumno();
void imprimirlos();
void limpiar();

char au=163, ao=162;
int main(){
	int j;
	printf("Tamano de objeto Alumno = %d \n",sizeof(Alumno));
	Alumno *din1,*din2,*din3, din4;
	din1 = malloc(5*sizeof(Alumno));
	din2 = calloc(5,sizeof(Alumno));

	// ! Imprime las direcciones de memoria
	// La dirección de memoria al usar
    // malloc()
    printf("Primer apuntador: \n");
	for(j=0;j<5;j++){
		printf("Direccion[%d]=%d \n",j,din1+j);
	}
	printf("\n");
	
    // Imprime la dirección de memoria al usar 
    // calloc()
	printf("Segundo apuntador \n");
	for(j=0;j<5;j++){
		printf("Direccion[%d]=%d \n",j,din2+j);
	}
	printf("\n");

	// Imprime la dirección de memoria al incrementar el espacio reservado
    // para la variable din2
	printf("Con realloc: \n");
	din3 = realloc(din2,10);
	for(j=0;j<10;j++){
		printf("&din3[%d]=%d \n",j,din3+j);
	}

    // ! Se le solicita al usario que ingrese los datos
	llenarAlumno(din2, j);
    imprimirlos(din2, j);

    // ! Esta fue mi manera creativa de limpiar los datos sin utilizar
    // ! La función free()
    // * limpiar(din2, j, din4);

	free(din1);
	free(din2);
	free(din3);
	system("PAUSE");
}

void imprimirlos(Alumno *arreglo, int i) {
    // Para fines prácticos, se fijó que solo se llenen 3 alumnos
    for (i = 0; i < 3; i++)
    {
        printf("\nN%cmero de cuenta del Alumno #%d: %d\n", au,i+1, arreglo[i].numCuenta);        
        printf("Nombre del Alumno #%d: %s\n", i+1, arreglo[i].nombre);
        printf("Apellido del Alumno #%d: %s\n", i+1, arreglo[i].apellido);
        printf("Promedio del Alumno #%f: %d\n", i+1, arreglo[i].promedio);
        printf("Calle del Alumno #%d: %s\n", i+1, arreglo[i].domicilio.calle);
        printf("N%cmero de casa del Alumno #%d: %d\n",au, i+1, arreglo[i].domicilio.num);
        printf("Colonia del Alumno #%d: %s\n", i+1, arreglo[i].domicilio.colonia);
        printf("C%cdigo Postal del Alumno #%d: %d\n",ao, i+1, arreglo[i].domicilio.cPostal);
    }
}
void llenarAlumno(Alumno *alumno, int j) {
    // Para fines prácticos, se fijó que solo se llenen 3 alumnos
    for (j = 0; j < 3; j++)
    {
        // ! Información del Alumno
        printf("\nIngrese el n%cmero de cuenta del alumno [%d]: ",au,j+1);
        scanf("%d",&(alumno[j].numCuenta));
        printf("Ingrese el nombre del alumno [%d]: ", j+1);
        scanf("%s",&(alumno[j].nombre));
        printf("Ingrese el apellido del alumno [%d]: ", j+1);
        scanf("%s",&(alumno[j].apellido));
        printf("Ingrese el promedio del alumno [%d]: ", j+1);
        scanf("%f",&(alumno[j].promedio));

        // ! Direccion del Alumno

        printf("Ingrese la calle del alumno [%d]: ", j+1);
        scanf("%s",&(alumno[j].domicilio.calle));
        printf("Ingrese el n%cmero de casa del alumno [%d]: ", au, j+1);
        scanf("%i",&(alumno[j].domicilio.num));
        printf("Ingrese la colonia del alumno [%d]: ",j+1);
        scanf("%s",&(alumno[j].domicilio.colonia));
        printf("Ingrese el c%cdigo postal del alumno [%d]: ",ao, j+1);
        scanf("%i",&(alumno[j].domicilio.cPostal));
    }
}

void limpiar(Alumno *limpio, int j, Alumno din4) {
    for (j = 0; j < 3; j++)
    {
        // ! Se encarga de limpiar los datos ya almacenados.
        // Igualando a una variable vacía
		limpio[j] = din4;
    }
    imprimirlos(limpio, j);
}