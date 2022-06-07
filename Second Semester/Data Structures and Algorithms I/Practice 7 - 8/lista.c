#include "lista.h"
#include "acentos.h"

// Se crea la estructura del nodo
struct Nodo{
	// Gurda el valor que contiene el nodo,  ".item"
    int val;
	// Guarda la direccion de memoria del nodo siguiente ".next"
    struct Nodo* next;
};

// Se crea la estructura de la lista, la cual contiene nodos
// y por empezar, contiene al nodo "head"
struct Lista{
	struct Nodo* head;
};

// Se crea la lista
Lista crearLista(){
	// Utiliza la estructura de la Lista
	Lista lista;
	// Le da a el head a valor nulo
	lista.head = NULL;
	// Regresa la lista creada 
	return lista;
}

// Imprime los valores de la lista
void print_list(Lista lista) {
	// ? Si el valor de head es nulo
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
		// ? Si no, imprime los valores
    	printf("Los elementos de la lista son: \n");
    	// Crea un nodo donde contiene la informacion de head
		Nodo *current = lista.head;
		// Mientras que current sea distinto a 0
   		while (current != 0) {
			// Se va a imprimir los valores del nodo actual
        	printf("%d \n",current->val);
			// El nodo va a ser el nodo siguiente
			current = current->next;
   	 	}
	}
}

// Agrega un nodo al principio de la lista
void addPrincipioLista(Lista *lista, int val) {
	// Se crea un nodo 
	Nodo *new_node;
	// El nodo reserva un espacio en la memoria con un tamaño de la estructura Nodo 
    new_node = (Nodo*)malloc(sizeof(Nodo));
	// El valor del nodo será asignado por la variable val, 
	// El cual, es solicitado al usuario
    new_node->val = val;
	// Apuntara al nodo head
    new_node->next = lista->head;
	// Head ahora será el nuevo nodo, ya que, este se agrego al principio
    lista->head = new_node;
}

// * Actividad 1.a Finalizado
void addIesimoLista(Lista* lista, int val, int posicion) {
	// Si head no tiene ningun nodo, encontrandose vacío
	int opcion, valor=1, maximo=1, si;
	if(lista->head==NULL){
		// Significa que no hay nodos en la lista
		printf("No haay nodos en la lista\n");
		printf("%cDesea agregar uno?\n", ap);
		printf("%c1.- Si\n", barras);
		printf("%c2.- No\n", barras);
		// Se le da la opción al usuario si desea agregar un nodo estando vacía la lista
		scanf("%d", &opcion);
		if(opcion == 1) {
			addPrincipioLista(lista, val);
		}
		else {
			printf("Okay :(");
		}
	}	
	else
	{
		// Si se desea agregar al principio de la lista
		if(posicion == 1) {
			addPrincipioLista(lista, val);
		}

		// Si se desea agregar en otro lado de la lista
		else {
			// Se crea un nuevo nodo, donde sera el mismo que el head
			Nodo *current = lista->head;
			// Se obtiene el tamano de la lista
			maximo = tamano(*lista);
			
			// Se valida que la posicion deseada exista en la lista
			
			// ?Si la posición es no existe en la lista
			if (posicion > maximo+1) {
				printf("No se puede agregar un nodo en una posicion mayor al del tama%co de la lista\n", an);
				printf("%cDesea agregarlo en la %cltima posici%cn?", ap,au,ao);
				scanf("%d", &si);
				// Ya que la posicion es mayor al de la lista, se le pregunta si desea agregarlo
				// al final de la lista
				if (si==1)
				{
					addFinalLista(lista,val);
				}
			} 

			// ? Si la posicion esta dentro de la lista
			else {
				while (valor != posicion-1) {
					// El nodo sera el nodo siguiente
					// Siendo asi, que se recorre nodo tras nodo
					// Hasta llegar a la posición deseada
					current = current->next;
					valor++;
				}
				//  Se crea un nodo, el cual
				Nodo *nuevoNodo;
				// Se le reserva al nodo nuevo un espacio en la memoria 
				// de un tamaño de la estructura nodo
				nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
				// El valor del nodo es asignado por el usuario
				nuevoNodo->val = val;
				// Apuntara al siguiente nodo de current, ya que ese nodo
				// se encuentra en una posicion antes del desado
				nuevoNodo->next = current->next;
				// Ahora, el nodo current apunta al nodo agregado
				current->next = nuevoNodo;
			}
		}
	}	
}

// Agrega un nodo al final de la lista
void addFinalLista(Lista *lista, int val) {
	// ? Si head no tiene ningun nodo, encontrandose vacío
	if(lista->head==NULL){
		// Se crea un nodo donde se le reserva un espacio en la memoria
		// de tamaño nodo
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		// Al valor del nodo se le asigna el valor ingresado por el usuario
		nodo->val = val;
		// No direccionara a otro nodo ya que esta al final de la lista
    	nodo->next = NULL;
		// El nodo head sera el nodo recien creado, pues la lista esta vacia
		// Y el nodo fue agregado al "final", siendo este el unico elemento de la lista
		// Y por lo tanto, el head
    	lista->head = nodo;
	}	
	// ? Si head no se encuentra vacio
	else
	{
		// Se crea un nuevo nodo, donde sera el mismo que el head
		Nodo *current = lista->head;
		// Mientras que el siguiente nodo de la lista sea distinto a 0
		while (current->next != 0) {
			// El nodo sera el nodo siguiente
			// Siendo asi, que se recorre nodo tras nodo
			// Para llegar al final de la lista
       		current = current->next;
 		}
		//  Se crea un nodo, el cual, es el que se agregará al final de la lista
		Nodo *nuevoNodo;
		// Se le reserva al nodo nuevo un espacio en la memoria 
		// de un tamaño de la estructura nodo
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
		// El valor del nodo es asignado por el usuario
    	nuevoNodo->val = val;
		// No se va a apuntar a otro nodo, debido a que esta al final de la lista
    	nuevoNodo->next = NULL;
		// El nodo que se encontra al final, obtenido por el ciclo while
		// Apuntará al nodo "nuevoNodo", siendo este el ultimo nodo
 		current->next = nuevoNodo;
	}	
}

// Borra el primer nodo de la lista
void borrarPrimero(Lista *lista) {
	// ? Si el nodo head no contiene nada
    if (lista->head == NULL) {
		// La lista esta vacias
        printf("La lista esta vacia");
    }
	// ? Si no se encuentra vacia 
    else{
		// Se crea un nuevo nodo vacio, este, es para suplentar al head actual de la lista
    	Nodo *nuevo_head = NULL;
		// Se crea otro nodo el cual contiene la informacion de head
    	Nodo *temp = lista->head;
		// el nodo nuevo_head apuntara al nodo siguiente de temp, el cual, es head.
		// En pocas palabras, el nodo nuevo_head apuntara al nodo 2
    	nuevo_head=temp->next;
		// Se libera el head, eliminandolo
    	free(lista->head);
		// Se iguala head al nodo nuevo_head, el cual, era el nodo 2
		// Pero al eliminar el head anterior, se convirtio en el nodo 1
    	lista->head = nuevo_head;
	}
}

// Borra el ultimo nodo de la lista
void borrarUltimo(Lista *lista) {
	// Se crea un nodo auxiliar que contiene la informacion de head
    Nodo *temp = lista->head;
	// ? Si el head es nullo, no existe
	if (lista->head == NULL) {
		// La lista esta vacia
        printf("La lista esta vacia");
    }
	// ? Si no esta vacia
    else{
		// Si el nodo siguiente del nodo creado, temp, es nullo
    	if(temp->next==NULL){
			// El head lo convertimos nullo
			// Ya que solo habia 1 nodo en la lista el cual, era head
    		lista->head = NULL;
			// Se libera head debido a que no se ocupa
			free(lista->head);	
    	}
		// Si el nodo siguiente del nodo tmp NO es nulo
		else{
			// Se crea un nodo current, el cual, es igualado al nodo head
    		Nodo *current = lista->head;
			// Mientras que el nodo siguiente del nodo current NO apunta a NULL 
    		while (current->next->next != NULL) {
				// El nodo current es el siguiente
        		current = current->next;
    		}
			// Terminar el ciclo while, llegando al nodo penultimo
			// El nodo penultimo no apuntara a otro nodo, poniendolo NULO
    		current->next = NULL;
			// Se libera el ultimo nodo
			free(current->next);
    	}
	}

}

// Retorna el valor del primer elemento, el cual, es el valor de head
int primerElemento(Lista lista){
	return lista.head->val;
}

// * Actividad 1.b - Finalizado
int busqueda(Lista lista, int elemento){
	// Se crea un nodo para recorrer la lista
	struct Nodo *temp = lista.head;
	int encontrado=0;
	// LLegará hasat que el ultimo nodo direccione a NULL
	while (temp->next != NULL) {
		if (temp->val == elemento) {
			// Si el valor que desea el usuario se encuentra
			// se suma 1 a la variable para llevar un conteo de cuantas veces
			// esta ese valor en al lista
			encontrado++;
		}
		else {
			encontrado += 0;
		}
		temp = temp->next;
	}
	// Se retorna el conteo 
	return encontrado;
}

// * Actividad 1.c - Finalizado
void borrarIesimoLista(Lista* lista,int posicion) {
	// Se crea un nodo auxiliar que contiene la informacion de head
    Nodo *temp = lista->head;
	int i, tam;
	// Se llama la siguien funcion para obtener el tamaño de la lista
	tam = tamano(*lista);
	// ? Se evalua el contenido de la lista
	if (lista->head == NULL) {
		// La lista esta vacia
        printf("La lista esta vacia");
    }

	// ? Si no esta vacia
    else{

		// ? Si el nodo siguiente del nodo creado, temp, es nullo
		// Esto es si hay solo 1 nodo
    	if(temp->next==NULL){
			printf("\nSolo hay un nodo en la lista, por lo tanto, se procede a eliminarlo\n");
			// El head lo convertimos nullo
			// Ya que solo habia un nodo en la lista el cual, era head
			lista->head = NULL;	
			// Se libera head debido a que no se ocupa
			free(lista->head);	
    	}

		// ? Si hay más de 1 nodo
		else{
			// La sentencia if es para comprobar si el usuario quiere ingresarlo en
			// El principio, final o en medio
			// ? Si quiere borrar el primero
			if (posicion == 1)
			{
				borrarPrimero(lista);
			} 
			// ? Si quiere borra el ultimo
			// O si ingreso una posicion fuera del elemento
			else if (posicion >= tam)
			{
				borrarUltimo(lista);
			}
			// ? Si quiere borrar otro elemento dentro de la lista
			else {

				// Se va a recorrer un nodo hasta una posicion antes deseada
				for (i = 1; i < posicion-1; i++) {
					temp = temp->next;
				}
				
				// Se crea un nodo, el cual contendrá la info que se va a eliminar
				Nodo *eliminar = temp->next;

				// El nodo con posicion anterior a eliminar, apuntara el nodo siguiente a eliminar
				temp->next = temp->next->next;

				// El nodo eliminar le asignamos NULL
				eliminar = NULL;
				
				// Se libera el nodo eliminado
				free(eliminar);
			}
    	}
	}
}

// * Actividad 1.d - Finalizado
void borrarMenoresLista(Lista *lista,int elemento){
    Nodo *temp = lista->head;
	// El valor de i indicara la posicion a eliminar
	int i=1, j=0;
	// Se crea una lista donde se guarda los elementos menores
	Lista menoresL = crearLista();
	while (temp != NULL) {
		// ? Si el valor del nodo es menor al elemento
		if (temp->val < elemento)
		{
			// Se va a agregar a la lista menoresL
			addFinalLista(&menoresL, temp->val);
			// Se recorre al siguiente nodo
			temp = temp->next;
			// Se va a eliminar de la "lista" la posicion i
			borrarIesimoLista(lista, i);
			j++;
		} 
		// ? Si no
		else {
			// Se recorre de posicion el nodo, y el valor de la posicion
			i++;
			temp = temp->next;
		}
	}
	// Debido a que si se elimina nodos con vlaor menor al deseado
	// Se va incrementando el valor de J
	// Si no se aumenta, es porque ningun nodo fue eliminado
	if (j == 0)
	{
		printf("No fue eliminado ning%cn nodo\n",au);
	} else {
		// Se crea un nodo para ser utilizado en la lista de los menores
		Nodo *menores = menoresL.head;
		printf("\nImprimimos la lista con valores menores: \n");
		// Se imprime los valores hasta llegar al ultimo
		while (menores != NULL)
		{
			printf("%d \t",menores->val);
			menores = menores->next;
		}
		// Se notifica cuantos elementos fueron eliminados
		// El valor se puede obtener del tamano de la lista de los menores
		printf("\nSe eliminaron #%d elementos", j);
		printf("\n");
	}
}

// ! EXTRA. Se calcula el tamaño de la lista
int tamano(Lista lista){
	int tam = 1;
	Nodo *temp;
	temp = lista.head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		tam++;
	}
	return tam;
}