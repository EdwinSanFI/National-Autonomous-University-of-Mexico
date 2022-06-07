#include <stdio.h>
// Agregué 2 librerías pues me daba error al ejecutar el código

#include <stdlib.h>
#include <string.h>

typedef struct {
	char calle[20];
	int num;
	char colonia[20];
	int cPostal;
}Direccion;
typedef struct {
	int numCuenta;
	char nombre[15];
	char apellido[15];
	float promedio;
	Direccion domicilio;
}Alumno;

Alumno crearAlumno(int, char*, char*, float);
void imprimirAlumno(Alumno);
// Se le agregó a la función crearAlumno, el parámetro de la estructura "Direccion"
// Para que sea más fácil llenar los datos
// Aunque en este caso no se requiere
Alumno crearAlumno(int numeroC, char *name, char *lastname, float prom){
	Alumno alumnoCreado;
	alumnoCreado.numCuenta = numeroC;
	strcpy(alumnoCreado.nombre,name);
	strcpy(alumnoCreado.apellido,lastname);
	alumnoCreado.promedio = prom;

	return alumnoCreado;
}

void imprimirAlumno(Alumno alumnoPrint){

	printf("Numero de cuenta: %d \n",alumnoPrint.numCuenta);
	printf("Name: %s \n",alumnoPrint.nombre);
	printf("LastName : %s  \n ", alumnoPrint.apellido);
	
}

