#include "ejercicio2.h"
char aa = 160, au = 163, an = 164;
int main(){
    int tam, i;
// Se obtiene el tamaño de la cola y la cantidad de elementos
    printf("Cu%cntos documentos va a registrar?\n", aa);
	fflush(stdin);
    scanf("%d", &tam);
    
    Documento *doc;
    doc = calloc(tam, sizeof(Documento));
    Cola cc = crearCola(tam);

// ! Se ejecuta el ciclo for para solicitar al usuario la información de los Documentos
// ! Se ejecutará hasta llegar el tamaño escrito por el usuario
    for (i = 0; i < tam; i++)
    {
        printf("\nIngrese el nombre del Documento [%d]: \n",i+1);
		fflush(stdin);
        scanf("%20[^\n]", &doc[i].nombre);

        printf("Ingrese el Autor del Documento [%d]: \n", i+1);
		fflush(stdin);
        scanf("%20[^\n]", &doc[i].autor);

        printf("Ingrese el N%cmero de P%cginas del Documento [%d]: \n", au, aa, i+1);
		fflush(stdin);
        scanf("%d", &doc[i].numPaginas);
        
        printf("Ingrese el tama%co del Documento[%d]: \n", an, i+1);
		fflush(stdin);
        scanf("%d", &doc[i].tamano);

        encolarC(&cc, doc[i]);
    }
    // ! Se ejecuta la función para imprimir los datos registrados.
    imprimirDatos(tam, &cc);
}

void imprimirDatos(int x, Cola *cc) {
    int i, tiempo, total;
    for (i = 0; i < x; i++)
    {
        // Se desencola para ir eliminando los elementos y dejar la cola vacía
        // Esto representa un orden de impresión, como si fuera una impresora.

        Documento desencolado = desencolarC(cc);
        printf("\n\nNombre: '%s'", &desencolado.nombre);
        // Se obtiene el tamaño de las paginas de un documento
        // Por cada página representa 4 segundos, por lo tanto, se multiplicará 
        // El número de páginas por 4
        tiempo = ((desencolado.numPaginas)*4);
        printf("\nTiempo de Impresion:\n");
        // ! Llamará la función imprimir tiempo en donde se encuntra el formato de impresión
        // deseado por el profesor.
        imprimirTiempo(tiempo);
        // Se sumará el tiempo en segundos a una variable para guardar el tiempo total.
        total+=tiempo;
    }
    //! Ejecutará la función para imprimir el tiempo total en cuestión de minutos y/o horas.
    printf("\n\n\nTiempo total: ");
    imprimirTiempo(total);
}

void imprimirTiempo(int tiempo) {
    int horas, minutos;
    
    if (tiempo >= 3600)
    {
        // Una hora equivale a 3600 segundos, y aquí se guardan el tiempo en horas
        horas = tiempo / 3600;
        // Se le resta los a tiempo ya que son utilizados en la hora
        tiempo -= horas * 3600;
        // Un minuto equivale a 60 segundos, y así se guardan el tiempo en minutos
        minutos = tiempo / 60;
        // Si el tiempo son mayor o igual a 3600 segundos

        // Al tiempo, variable que guarda los segundos, se le restará el valor de segundos 
        // De la suma de los segundos totales de las horas y de los minutos
        tiempo -= (minutos * 60);
        // Imprime las horas 
        printf("\n\t Horas: %d", horas);
        // Imprime los minutos
        printf("\n\t Minutos: %d", minutos);
        // Imprime los segundos
        printf("\n\t Segundos: %d", tiempo-1);
    }
    else {
        // Un minuto equivale a 60 segundos, y así se guardan el tiempo en minutos
        minutos = tiempo / 60;
        tiempo -= (minutos * 60);
        printf("\n\t Minutos: %d", minutos);
        printf("\n\t Segundos: %d", tiempo);
    }
}