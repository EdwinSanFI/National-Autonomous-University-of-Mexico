#include "listacircdoble.h"
#include "acentos.h"

/*
    ! Actividad 3 FINALIZADA
    A) Crear lista ligada circular doble *FINALIZADO
    B) Hacer un menu con las funciones de basicas de las listas ligadas dobles.
    Agregar i-esimo, validar que la posicion
    del usuario exista, de lo contrario, no permita la insercion
 */

struct NodoDoble {
    int val;
    struct NodoDoble* next;
    struct NodoDoble* prev;
};

struct ListaDoble {
    int tamano;
    struct NodoDoble* head;
};

ListaDoble crearListaDoble(){
    ListaDoble listaCircularDoble;
    listaCircularDoble.head = NULL;
    listaCircularDoble.tamano = 0;
    return listaCircularDoble;
}

// * Actividad 1.a
// Aqui inicia la ejecución del programa
int main() {
    int opcion, op;
    // Crea una lista circular doble
    ListaDoble listaCircularDoble = crearListaDoble();
    printf("\t%cMen%c de Lista Ligada Doble%c\n",decoracion,au,decoracion);
    // Se ejecutara el menu siempre y cuando el numero de instruccion del usuario exista
    // dentro del menu.
    do
    {
        op = menuDoble();
        ColaDoble(&listaCircularDoble, op);
    } while (op >= 1 && op <= 6);
}

// Funcion que imprime el menu
int menuDoble() {
    int opcion;
    printf("\n%c1.-Agregar un elemento al principio\n", barras);
    printf("%c2.-Agregar un elemento al final\n",barras);
    printf("%c3.-Agregar un elemento en la posicion N\n",barras);
    printf("%c4.-Eliminar el primer elemento\n",barras);
    printf("%c5.-Eliminar el %cltimo elemento\n",barras,au);
    printf("%c6.-Imprimir la lista\n",barras);
    printf("%c%cCon cu%cl desea trabajar?\n",barras, ap, aa);
    fflush(stdin);
    // Guarda el numero de instruccion que el usuario ingreso
    scanf("%d", &opcion);
    // Retorna la variable
    return opcion;
}

// Conforme el usuario ingreso el numero de instruccion
// se va a ejecutar dicha la funcion 
void ColaDoble(ListaDoble *doble, int opcion){
    int posicion, val;
    switch (opcion)
    {
    case 1:
        printf("%c%cQu%c elemento desea agregar?\n",barras,ap,ae);
        fflush(stdin);
        scanf("%d", &val);
        agregarPrincipioNodoDoble(doble, val);
        break;
    case 2:
        printf("%c%cQu%c elemento desea agregar?\n",barras,ap,ae);
        fflush(stdin);
        scanf("%d", &val);
        agregarFinalNodoDoble(doble, val);
        break;
    case 3:
        printf("%c%cEn qu%c posici%cn desea agregar?\n",barras,ap,ae,ao);
        fflush(stdin);
        scanf("%d", &posicion);
        printf("%c%cQu%c elemento desea agregar?\n",barras,ap,ae);
        fflush(stdin);
        scanf("%d", &val);
        agregarIesimoNodoDoble(doble, posicion, val);
        break;
    case 4:
        eliminarInicioNodoDoble(doble);
        break;
    case 5:
        eliminarFinalNodoDoble(doble);
        break;
    case 6:
        imprimirListaDoble(*doble);
        break;
    default:
        break;
    }
}

// Esta funcion se ejecutara cuando la lista este vacia
// y el primer nodo sera el head con un valor que se le paso
// como parametro, ademas, su .next y .prev se van a direccionar
// al mismo nodo head
void siEstaVacio(ListaDoble *listaDoble, int val){
    listaDoble->head = (NodoDoble*)malloc(sizeof(NodoDoble));
    listaDoble->head->val = val;
    listaDoble->head->next = listaDoble->head;
    listaDoble->head->prev = listaDoble->head;
    listaDoble->tamano++;
}

// Agregara al principio de la lista un nodo
void agregarPrincipioNodoDoble(ListaDoble *listaDoble, int val) {
    // ? Si el tamano es cero, se ejecuta la funcion siEstaVacio()
    if (listaDoble->tamano == 0) {
        siEstaVacio(listaDoble, val);
    } else {
        // ? Si no se encuentra vacia la lista
        // Se crea un nodo para agregarlo a la lista
        NodoDoble *nuevo;
		nuevo = (NodoDoble *)malloc(sizeof(NodoDoble)); 
        // Se reserva un espacio en la memoria y se le asigna el valor ingresado 
		nuevo->val = val;
        // Apuntara como siguiente nodo al nodo head
		nuevo->next = listaDoble->head;
        // Apuntara como nodo anterior al noodo anterior del head
		nuevo->prev = listaDoble->head->prev;
        // El nodo anterior del head apuntara como nodo siguiente al nodo nuevo
		listaDoble->head->prev->next = nuevo;
        // El nodo head apuntara como nodo anterior al nodo nuevo
		listaDoble->head->prev = nuevo;
        // Se le asigna como nodo head al nodo nuevo ya que fue agregado al principio
        // de la lista
        listaDoble->head = nuevo;
        // Se incrementa el tamano de la lista
        listaDoble->tamano++;
    }
}

// Agrega al final de la lista un nodo doble
void agregarFinalNodoDoble(ListaDoble* listaDoble, int val) {
    // ? Si la lista se encuentra vacia
    if (listaDoble->tamano == 0) {
        // Se ejecuta esta funcion
        siEstaVacio(listaDoble, val);
    } else {
        // ? Si no se encuentra vacia
        // Se crean 2 nodos dobles
        NodoDoble *nuevo, *temp;
        // El nodo temp es igualado al nodo head
        temp = listaDoble->head;
		nuevo = (NodoDoble *)malloc(sizeof(NodoDoble)); 
		// EL nodo nuevo se reserva un espacio en la memoria y se le asigna su valor
        nuevo->val = val;
		// El nodo nuevo apuntara al siguiente nodo al nodo head
        nuevo->next = listaDoble->head;
        // El nodo nuevo apuntara al nodo anterior al ultimo nodo de la lista
		nuevo->prev = listaDoble->head->prev;
        // El ultimo nodo apuntara como nodo siguiente al nodo nuevo
		listaDoble->head->prev->next = nuevo;
        // El nodo temp llegara al ultimo nodo de la lista
        while (temp->next != listaDoble->head) {
            temp = temp->next;
        }
        // Para que este pueda ser igualado al nodo nuevo y asi quede
        // en la ultima posicion de la lista
		temp = nuevo;
        // El nodo head apuntara como nodo anterio al nodo nuevo 
        listaDoble->head->prev = nuevo;
        // Se aumenta el tamano de la lista
        listaDoble->tamano++;
    }
}

// Agregara un nodo en una posicion deseada por el usuario
void agregarIesimoNodoDoble(ListaDoble* listaDoble, int posicion, int val) {
    // ? Se valida por medio de la funcion validarPosicion() que la posicion
    // exista dentro de la lista
    if (validarPosicion(*listaDoble, posicion)) {   
        // ?Si la posicion es al principio de la lista
        if (posicion == 1) {
            // Es como agregar al principio de la lista, por lo tanto, se manda a ejecutar
            // la siguiente función
            agregarPrincipioNodoDoble(listaDoble, val);
        } else if (posicion == (listaDoble->tamano+1)) {
            // ?Si la posicion es al final de la lista
            // Es como agregar al final de la lista, por lo tanto, se manda a ejecutar
            // la siguiente función
            agregarFinalNodoDoble(listaDoble, val);
        } else {
            // Se crean 2 nodos
            // Temp es igualado al nodo head
            NodoDoble *temp = listaDoble->head;
            NodoDoble *nuevo;
            nuevo = (NodoDoble *)malloc(sizeof(NodoDoble)); 
            // El nuevo nodo se le reserva un espacio en la memoria y se le 
            // asigna un valor, el cual, es el ingresdao por el usuario
            nuevo->val = val;
            int i;
            // El nodo temp llegara al nodo de la posicon deseada de la lista
            for (i = 1; i < posicion; i++) {  
                temp = temp->next;
            }
            // El nodo anterior de temp apuntara como nodo siguiente
            // al nodo nuevo
            temp->prev->next = nuevo;
            // El nodo nuevo apuntara como nodo anterior al nodo anterior de temp
            nuevo->prev = temp->prev;
            // El nodo temp apuntara como nodo anterior al nodo nuevo
            temp->prev = nuevo;
            // El nodo nuevo apuntara como nodo siguiente al temp
            nuevo->next = temp;
            // Asi se agrega un nodo en una posicion
            // Se agrega el tamano de la lista
            listaDoble->tamano++;
        }
    } else {
        // ? Si la posicion no existe dentro de la lista
        printf("Ni modo :( \n");
    }
}

// Elimina el primer nodo de la lista
void eliminarInicioNodoDoble(ListaDoble* listaDoble) {
    // Se crea un nodo, se iguala al segundo ndo de la lista
    NodoDoble *temp = listaDoble->head->next;
    // El ultimo nodo de la lista se iguala al nodo creado
    listaDoble->head->prev->next = temp;
    // El nodo creado apuntara hacia atras al ultimo nodo
    temp->prev = listaDoble->head->prev;
    // Se libera el nodo head
    listaDoble->head = NULL;
    // Se iguala el nodo head al nodo temp, este era el segundo nodo y ahora
    // es el primer nodo
    listaDoble->head = temp;
    // Se reduce el tamano de la lista
    listaDoble->tamano--;
}

// Eliminar el ultimo nodo de la lista ligada circular doble
void eliminarFinalNodoDoble(ListaDoble* listaDoble) {
    // Creamos un nodo, el cual, va a ser el penultimo de la lista
    NodoDoble *temp = listaDoble->head->prev->prev;
    // Del nodo head, su .prev va a direccionar al penultimo nodo
    listaDoble->head->prev = temp;
    // El penultimo nodo, su .next va a ser el head
    temp->next = listaDoble->head;
    // Eliminamos el nodo tail, el ultimo
    listaDoble->head->prev = NULL;
    // El nodo penultimo, temp, se convierte en el ultimo y en tail
    listaDoble->head->prev = temp;
    // Se reduce el tamano
    listaDoble->tamano--;
}

// Imprime los valores de la lista circular doble
void imprimirListaDoble(ListaDoble imprimir){
    // ? Valida si se encuentra vacia la lista
    if (imprimir.tamano == 0) {
        printf("La Lista se encuentra vac%ca\n",ai);
    }
    // ? Si no se encuentra vacia
    else {
        // Se crea un nodo igualandolo a head, para iniciar el recorrido
        NodoDoble* temp = imprimir.head;
        printf("\n");
        int i;
        // A traves del ciclo for se va a recorrer la lista hasta que i llegue
        // al valor del tamano de la lista
        for (i = 1; i <= imprimir.tamano; i++) {
            // Se imprime el valor del nodo actual
            printf("%d\n",temp->val);
            // Se recorre al siguiente nodo
            temp = temp->next;
        }
        // Se imprime el tamano de la lista
        printf("Tama%co: %d\n", an, imprimir.tamano);
    }
}

// * Actividad 3.b
// Valida que la posicion a ingresar por el usuario
// exista en la lista
int validarPosicion(ListaDoble listaDoble, int posicion) {
    // ? Si el valor de la posicion es mayor al tamno de la posicion+1
    // Se utiliza tamano+1 ya que, si el usuario decide ingresar en la ultima posicion
    // de la lista, marcaria error y esto no valido.
    // EJEMPLO: posicion= 7; tamano=7
    if (posicion > (listaDoble.tamano+1))
    {
        // No existe dicha posicion
        printf("Esa posici%cn no existe en la lista\n",ao);
        // Regresa 0 indicando que no existe
        return 0;
    } else {
        // De lo contrario, regresa 1 indicando que si existe
        return 1;
    }
}
