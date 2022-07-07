#include "list.h"
#include "acentos.h"

/**
 * A Node is a struct that contains an int and a pointer to a Node.
 * @property {int} val - The name-value of the node.
 * @property next - Pointer to the next node
 */
struct Node{
    int val;
    struct Node* next;
};

/**
 * A List is a pointer to a Node.
 * @property head - The head of the list.
 */
struct List{
	struct Node* head;
};

/**
 * It creates a list.
 * @return A list.
 */
List createLista(){
	List list;
	list.head = NULL;
	return list;
}

/**
 * It creates a new node, sets its value to the value passed in, sets its next pointer to the current
 * head of the list, and then sets the head of the list to the new node
 * @param list pointer to the list
 * @param val the value to be added to the list
 */
void insertNodeBeginning(List *list, int val) {
	Node *new_node;
    /* Creating a new node and allocating memory for it. */
	new_node = (Node*)malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = list->head;
    list->head = new_node;
}

void addIesimoLista(List* lista, int val, int posicion) {
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
			insertNodeBeginning(lista, val);
		}
		else {
			printf("Okay :(");
		}
	}
	else
	{
		// Si se desea agregar al principio de la lista
		if(posicion == 1) {
			insertNodeBeginning(lista, val);
		}

		// Si se desea agregar en otro lado de la lista
		else {
			// Se crea un nuevo nodo, donde sera el mismo que el head
			Node *current = lista->head;
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
					insertNodeEnd(lista,val);
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
				Node *nuevoNodo;
				// Se le reserva al nodo nuevo un espacio en la memoria 
				// de un tamaño de la estructura nodo
				nuevoNodo = (Node*)malloc(sizeof(Node));
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

/**
 * If the list is empty, create a new node and set it as the head of the list. Otherwise, traverse the
 * list until you reach the end, then create a new node and set it as the next node of the last node
 * @param lista is the list
 * @param val The value to be inserted
 */
void insertNodeEnd(List *lista, int val) {
	if(lista->head==NULL){
		insertNodeBeginning(lista, val);
	}
	else
	{
		Node *current = lista->head;
		while (current->next != 0) {
	   		current = current->next;
 		}
		Node *nuevoNodo;
		nuevoNodo = (Node*)malloc(sizeof(Node));
    	nuevoNodo->val = val;
    	nuevoNodo->next = NULL;
 		current->next = nuevoNodo;
	}
}

/**
 * If the list is not empty, the head of the list is set to the next node in the list
 * @param lista the list
 */
void deleteNodeBeginning(List *lista) {
	if(lista->head!=NULL){
		lista->head = lista->head->next;
	}
}

/**
 * It deletes the last node of the list
 * @param lista the list
 */
void deleteNodeEnd(List *lista) {
	if(lista->head!=NULL){
		Node *current = lista->head;
		while (current->next->next != NULL) {
	   		current = current->next;
 		}
		current->next = NULL;
	}
}

int primerElemento(List lista){
	return lista.head->val;
}

int busqueda(List lista, int elemento){
	// Se crea un nodo para recorrer la lista
	struct Node *temp = lista.head;
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

void borrarIesimoLista(List* lista,int posicion) {
	// Se crea un nodo auxiliar que contiene la informacion de head
    Node *temp = lista->head;
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
				deleteNodeBeginning(lista);
			} 
			// ? Si quiere borra el ultimo
			// O si ingreso una posicion fuera del elemento
			else if (posicion >= tam)
			{
				deleteNodeEnd(lista);
			}
			// ? Si quiere borrar otro elemento dentro de la lista
			else {

				// Se va a recorrer un nodo hasta una posicion antes deseada
				for (i = 1; i < posicion-1; i++) {
					temp = temp->next;
				}
				// Se crea un nodo, el cual contendrá la info que se va a eliminar
				Node *eliminar = temp->next;

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

void borrarMenoresLista(List *lista,int elemento){
    Node *temp = lista->head;
	// El valor de i indicara la posicion a eliminar
	int i=1, j=0;
	// Se crea una lista donde se guarda los elementos menores
	List menoresL = createLista();
	while (temp != NULL) {
		// ? Si el valor del nodo es menor al elemento
		if (temp->val < elemento)
		{
			// Se va a agregar a la lista menoresL
			insertNodeEnd(&menoresL, temp->val);
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
		Node *menores = menoresL.head;
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

int tamano(List lista){
	int tam = 1;
	Node *temp;
	temp = lista.head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		tam++;
	}
	return tam;
}

/**
 * Prints the list.
 * @param list the list to be printed
 */
void printList(List list){
	Node *temp;
	temp = list.head;
	while (temp != NULL)
	{
		printf("%d \t",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	List list;
	list = createLista();
	insertNodeBeginning(&list, 1);
	insertNodeBeginning(&list, 2);
	insertNodeBeginning(&list, 3);
	printList(list);

	deleteNodeBeginning(&list);
	printList(list);

	deleteNodeEnd(&list);
	printList(list);
}