// TODO: Santiago Díaz Edwin Jaret
// * El programa registrará la información ingresada por medio de estructuras.
// * Estas son 2 y una estructura está enlazada a otra.

#include <stdio.h>
#define TAM_ASIG 5
#define TAM_ALU 2
char aa = 160,ao = 163, au = 164;
struct asignatura {
    char nombre[20];
};

struct estudiante {
    char nombre[20];
    char apellido[20];
    int edad;
    struct asignatura materias[TAM_ASIG];
};

// Declaramos funciones para:
void llenarAlumnos(struct estudiante *); // Solicitarle al usuario la informción y guardarla
void imprimirAlumnos(struct estudiante *); // Imprimir la información

int main () {
    int opcion;
    while (1)
    {
        struct estudiante alumnoss[TAM_ALU];
        // Primero se va a llamar a las funciones
        llenarAlumnos(alumnoss);
        imprimirAlumnos(alumnoss);
        // Y si desea el usuario modificar la información puede hacerlo
        // Si ingresa el número 1
        // Si ingresa el 0 no modificará nada y se acaba la ejecución del programa
        printf("Desea modificar la informaci%cn de los arreglos?\n",ao);
        printf("Presione 1 si desea\n");
        printf("De lo contrario presione 0\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            llenarAlumnos(alumnoss);
            imprimirAlumnos(alumnoss);
            break;
        default:
            return 0;
            break;
        }
    }   
}

void llenarAlumnos (struct estudiante alumnoss [TAM_ALU]) {
    int i, j;
    for (i = 0; i < TAM_ALU; i++)
    {
        // Se crea una nueva variable para guardar la información
        struct estudiante deUni;
        printf("\n\n*** Ingrese el nombre del Alumno %d *** \n",i+1);
        setbuf(stdin, NULL);
        scanf("%s", &deUni.nombre);
        getchar();
        printf("Ingrese el apellido de %s \n", deUni.nombre);
        setbuf(stdin, NULL);
        scanf("%s", &deUni.apellido);
        getchar();
        printf("Ingrese la edad de %s %s \n",deUni.nombre, deUni.apellido);
        setbuf(stdin, NULL);
        scanf("%d", &deUni.edad);
        for (j = 0; j < TAM_ASIG; j++)
        {
            printf("--- Alumno %s %s ---\n",deUni.nombre, deUni.apellido);
            printf("Ingrese el nombre de la materia #%d: \n",j);
            setbuf(stdin, NULL);
            scanf("%s", &deUni.materias[j].nombre);
            getchar();
        } 
        // Y la información recopilada se guardará en la variable 
        // "alumnoss" con dimensión "i"
        alumnoss[i] = deUni;
    }
}
void imprimirAlumnos (struct estudiante alumnoss [TAM_ALU]){
    int i, j;
    printf("\n--La informaci%cn de los alumnos--\n",ao);
    // Imprime la información de los alumnos con un ciclo for
    for (i = 0; i < TAM_ALU; i++)
    {
        printf("\n- Alumno: %s -\n", alumnoss[i].nombre);
        printf("- Apellido: %s -\n", alumnoss[i].apellido);
        printf("* Edad: %d *\n", alumnoss[i].edad);
        for (j = 0; j < TAM_ASIG; j++)
        {
            // Imprime las materias que tiene cada alumno
            printf("* Materia %d: %s * \n", j, alumnoss[i].materias[j].nombre);
        }
    }
}