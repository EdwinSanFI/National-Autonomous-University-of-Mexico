// TODO: Santiago Díaz Edwin Jaret
// * El programa administra un ejercito por medio de estructuras Militar, Batallón
// * y Divisón. Todos los datos son ingresados por el usuario.
// * La estructura "Divisón" tiene asociada la estructura "Batallón" y esta a su vez
// * tiene asociada la estructura Militar.

#include <stdio.h>
int divisiones;
// Declaramos variables para utilizar acentos, estos contenen su respectivo
// Código ASCII
char aa = 160,ao =162,ai = 161,aoo=224,aii=214; 
// Creamos las estructuras
struct Militar {
    int matricula;
    char nombre[30];
    char gradoMil[30];
};
struct Batallon {
    int claveIdentificador;
    char categoria[30];
    char ubicacion[30];
    struct Militar equipo[3];
};
struct Division {
    char nombre[30];
    char zona[30];
    struct Batallon ejercito[3];
};
// Declaramos las funciones para: 
void crearDivision(struct Division *); // solicitarle la información al usuario y guardarla
void mostrarDivisones(struct Division *); // Imprimir la información usando ciclos for

int main() {
    // Creamos una variable de tamaño 1 y esta la pasamos a las funciones
    // previamente declaradas, para crear e imprimir las división militar
    struct Division ejercitoNacional[1];
    crearDivision( ejercitoNacional );
    mostrarDivisones( ejercitoNacional );
    return 0;
}
void crearDivision(struct Division ejercitoNacional[1]) {
    int i, j,m;
    // Creamos otra variable para registrar los datos a introducir
    struct Division ejercitoFalso;
    for (m = 0; m < 1; m++)
    {
        // Registra la información de la División [1]
        printf("\n\t** Crear Divisi%cn ** \n",ao);
        printf("Ingrese El nombre de la divisi%cn\n",ao);
        setbuf(stdin, NULL);
        scanf("%s", &ejercitoFalso.nombre);
        getchar();
        printf("Ingese la zona de la divisi%cn %s\n",ao,ejercitoFalso.nombre);
        setbuf(stdin, NULL);
        scanf("%s", &ejercitoFalso.zona);
        getchar();
        for ( i = 0; i < 3; i++)
        {
            // Registra la información de los batallones [3]
            printf("\t** Crear Batall%cn **\n",ao);
            printf("Ingrese la clave identificador\n");
            setbuf(stdin, NULL);
            scanf("%d", &ejercitoFalso.ejercito[i].claveIdentificador);
            printf("Ingrese la categor%ca\n",ai);
            setbuf(stdin, NULL);
            scanf("%s", &ejercitoFalso.ejercito[i].categoria);
            getchar();
            printf("Ingrese la ubicaci%cn\n",ao);
            setbuf(stdin, NULL);
            scanf("%s", &ejercitoFalso.ejercito[i].ubicacion);
            getchar();
            for (j = 0; j < 3; j++)
            {
                // Registra la información de los militares [3]
                printf("\n\t**Crear militar **\n");
                printf("Ingrese la matr%ccula del militar\n",ai);
                setbuf(stdin, NULL);
                scanf("%d", &ejercitoFalso.ejercito[i].equipo[j].matricula);
                printf("Ingrese el nombre del militar\n");
                setbuf(stdin, NULL);
                scanf("%s", &ejercitoFalso.ejercito[i].equipo[j].nombre);
                getchar();
                printf("Ingrese el grado del militar\n");
                setbuf(stdin, NULL);
                scanf("%s", &ejercitoFalso.ejercito[i].equipo[j].gradoMil);
                getchar();
            }
        }
        // Igualamos la variable con los datos registrados a 
        // la otra variable previamente hecha
        ejercitoNacional[m] = ejercitoFalso;
    }
}

void mostrarDivisones(struct Division ejercitoNacional [1]) {
    int i, j, m;
    for (m = 0; m < 1; m++)
    {
        // Imprime la información de la división [1]
        printf("\n\t\t DIVISI%cN %s\n",aoo,ejercitoNacional[m].nombre);
        printf("\t\t ZONA %s\n\n",ejercitoNacional[m].zona);
        for (i = 0; i < 3; i++)
        {
            // Imprime la información del los batallones [3]
            printf("\t CLAVE IDENTIFICADOR %d\n",ejercitoNacional[m].ejercito[i].claveIdentificador);
            printf("\t CATEGOR%cA %s\n",aii,ejercitoNacional[m].ejercito[i].categoria);
            printf("\t UBICACI%cN %s\n\n",aoo,ejercitoNacional[m].ejercito[i].ubicacion);
            for (j = 0; j < 3; j++)
            {
                // Imprime la información de los soldados [3]
                printf("Matr%cula %d \n",ai,ejercitoNacional[m].ejercito[i].equipo[j].matricula);
                printf("Nombre %s \n",ejercitoNacional[m].ejercito[i].equipo[j].nombre);
                printf("Grado Militar %s \n\n",ejercitoNacional[m].ejercito[i].equipo[j].gradoMil);
            }
        }
    }
}
