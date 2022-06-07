#include "lista.c"

/* 
    ! Actividiad 1 - TERMINADA 

    A) Finalizado
        addPrincipioLista(lista, elemento);
        addFinalLista(lista, elemento);
        addIesimoLista(lista, elemento,posicion);
        borrarPrimero(lista);
        borrarUltimo(lista);
    B) Finalizado
        busqueda(*lista,elemento);
    C) Finalizado, con pruebas de inicio, en medio, final y fuera de la llista
        borrarIesimoLista(lista,posicion); 
    D) Finalizado, no he hecho pruebas suficientes
        borrarMenoresLista(lista, elemento);
*/

void listaSimple(Lista *, int);

// Se va a ejecutar primero esta funcion
int main() {
    // El programa inicia aquí

    int opcion, operacion, tam;
    // Aquí se va a ejecutar el menú
    printf("\t%c MEN%c %c\n", decoracion, auu, decoracion);
    Lista lista = crearLista();

    do {
        operacion = menu();
        listaSimple(&lista, operacion);
    } while (operacion <= 10 && operacion >= 1);
}

int menu() {
    int operacion;
    printf("\n Estas son las operaciones disponibles:\n\n");
    printf("\t %c1.- Imprimir los valores de los nodos.\n", barras);
    printf("\t %c2.- Agregar al principio de la lista un Nodo.\n", barras);
    printf("\t %c3.- Agregar al final de la lista un Nodo.\n", barras);
    // * Actividad 1.a 
    printf("\t %c4.- Agregar en la posici%cn N de la lista un Nodo.\n", barras,ao);
    printf("\t %c5.- Borrar el primer Nodo de la lista.\n", barras);
    printf("\t %c6.- Borrar el %cltimo Nodo de la lista.\n", barras, au);
    // * Actividad 1.b
    printf("\t %c7.- Buscar un elemento \n", barras, au);
    // * Activida 1.c
    printf("\t %c8.- Eliminar el nodo N-%csimo \n", barras, ae);
    // * Actividad 1.d
    printf("\t %c9.- Eliminar los elementos menores de un elemento \n", barras, au);
    printf("\t %c10.- Obtener el valor del primer nodo de la lista.\n", barras, au);
    printf("\t %c11.- Terminar el programa\n", barras, au);
    printf("%cQu%c operacion desea realizar?\n",ap, ae);
    fflush(stdin);
    scanf("%d", &operacion);
    return operacion;
}

// Trabajamos en la lista ligada simple
void listaSimple(Lista *lista, int operacion){
    int elemento, posicion, repeticion;
    switch (operacion)
    {
        case 1:
            print_list(*lista);
            break;
        case 2:
            printf("%cQu%c elemento desea agregar?\n", barras, ae);
            fflush(stdin);
            scanf("%d", &elemento);
            // Agrega al principio de la lista el elemento asignado por el usuario
            addPrincipioLista(lista, elemento);
            break;
        case 3:
            printf("%cQu%c elemento desea agregar?\n", barras, ae);
            fflush(stdin);
            scanf("%d", &elemento);
            // Agrega al final de la lista el elemento asignado por el usuario
            addFinalLista(lista, elemento);
            break;
        case 4:
            // Agrega en la posicion N un elemento/nodo de la lista
            printf("%c%cQu%c elemento desea agregar?\n", barras, ap, ae);
            fflush(stdin);
            scanf("%d", &elemento);
            printf("%c%cEn qu%c posici%cn?\n", barras, ap, ae, ao);
            fflush(stdin);
            scanf("%d", &posicion);
            addIesimoLista(lista, elemento, posicion);
            break;
        case 5:
            // Elimina el ultimo elemento/nodo de la lista.
            borrarPrimero(lista);
            break;
        case 6:
            borrarUltimo(lista);
            break;
        case 7:
            printf("%c%cCu%cl es el elemento que desea buscar? \n",barras,ap, aa);
            fflush(stdin);
            scanf("%d", &elemento);
            // Se guarda en una variable la cantidad de veces
            // Se encontró el elemento
            repeticion = busqueda(*lista, elemento);
            if (repeticion == 1)
            {
                printf("%cEl elemento %d se encuentra %d vez\n", barras, elemento, repeticion);
            } else {
                printf("%cEl elemento %d se encuentra %d veces\n", barras, elemento, repeticion);
            }
            break;
        case 8:
            // * Actividad 1.c
            printf("%cQu%c posici%cn desea eliminar?\n", barras, ae,ao);
            fflush(stdin);
            scanf("%d", &posicion);
            borrarIesimoLista(lista,posicion);
            break;
        case 9:
            // * Actividad 1.d
            printf("%c%cCu%cl es el elemento mayor?\n", barras, ap, aa);
            fflush(stdin);
            scanf("%d", &elemento);
            borrarMenoresLista(lista, elemento);
            break;
        case 10:
            printf("Primer elemento: %d\n",primerElemento(*lista));
            break;
        case 11:
            printf("Adi%cs\n", ao);
            break;
        default:
            break;
    }
}
