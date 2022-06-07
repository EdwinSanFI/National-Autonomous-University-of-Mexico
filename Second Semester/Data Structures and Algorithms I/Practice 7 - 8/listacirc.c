#include "listacirc.h"
#include "acentos.h"

/*
	! Actividad 2 TERMINADA
	* 1.A - FINALIZADO
	Crear struct Computadora con funciones
	* 1.B - FINALIZADO 
	Cambio de lista de enteros a Lista de Computadoras
	* 1.C - FINALIZADO
	Recorrer Lista, para que el usuario elija si avanzar, seleccionar el elemtno actual para ver sus detalles
	o salir de la lista circular
*/

struct NodoC{
    Computadora val;
    struct NodoC* next;
};

struct ListaC{
	struct NodoC* head;
	int tamano;
};

ListaC crearListaC(){
	ListaC listaC;
	listaC.head = NULL;
	listaC.tamano = 0;
	return listaC;
}

// Va a imprimir los valores de cada nodo de la lista
void print_listC(ListaC listaC) {
	// Nos ayudara a recorrer la lista
	int i=0;
	// ? Si el tamaño de la lista es 0
    if(listaC.tamano == 0){
    	printf("\n\t%cLA LISTA ESTA VACIA \n",decoracion);
    }
	// ? Si el tamaño es mayor a 0
    else {
		// Se crea un nodo para recorrer la lista
		NodoC *temp = listaC.head;
    	printf("\t%cLos elementos de la lista son: \n",decoracion);
    	// Se va a imprimir el valor de cada nodo de la lista.
		// el valor de cada nodo es una estructura Computadora.
		while (i != listaC.tamano) {
			Computadora imprimir = temp->val;
			// Se llama a esta funcion para imprimir la informacion de la Computadora
			// del nodo actual
			printComputadora(imprimir);
			temp = temp->next;
			// Se incrementa i hasta llegar al tamano de la lista (para llegar al ultimo noodos)
			i++;
		}
	}
}

// Agregara al final de la lista un nuevo nodo con su valor
void addFinalListaC(ListaC *listaC, Computadora val) {
	// Se guarda en una variable el tamano de la lista
	int posicion=listaC->tamano;
	// ? Si el tamano de la lista es 0
	if(listaC->tamano == 0){
		// Se crea un nodo
		NodoC *nodoC = (NodoC*)malloc(sizeof(NodoC));
		// Al nodo se le asigna la estructura Computadora
		nodoC->val = val;
		// Su siguiente nodo apuntará a si mismo, ya que es el primer nodo de la lista
    	nodoC->next = nodoC;
		// Se le asigna el nodo head al nuevo nodo de la lista.
    	listaC->head = nodoC;
	}	
	// ? Si el tamano es mayor a 0
	else
	{
		// Se crea un nodo asignandole la información de head
		NodoC *current = listaC->head;
		// Se recorrera la lista hasta el ultimo nodo
		while (posicion!=1) {
       		current = current->next;
       		posicion--;
 		}
		// Se crea un nodo, el cual, sera el ultimo de la lista
		NodoC *nuevoNodoC;
		nuevoNodoC = (NodoC*)malloc(sizeof(NodoC));
		// El ultimo nodo actual apuntara al nodo creado
    	current->next = nuevoNodoC;
		// Se le asigna un valor
		nuevoNodoC->val = val;
		// El nodo creado apuntara al nodo head. Asi, fue agregado a la ultima posicion
    	nuevoNodoC->next = listaC->head;
	}	
	// Se incrementa el valor de tamano
	listaC->tamano++; 
}

// Agregará al principio de la lista un nuevo nodo con su valor.
void addPrincipioListaC(ListaC *listaC, Computadora val) {
	// Se crea 2 nodos
	NodoC *node,*temp;
    node = (NodoC*)malloc(sizeof(NodoC));
	// Se reserva su espacio en la memoria y se le asigna un valor al nodo
	// que sera agregado al principio
    node->val = val;
	// ? Si head es nulo, no existe
    if(listaC->head==NULL){
		// El nodo apuntara asi mismo
    	node->next=node;
	}
	// ? Si no es nulo head, significa que contiene mas nodos la lista
    else{
		// El nodo a agregar apuntara al nodo head
    	node->next = listaC->head;
		// Este nodo recorrera la lista hasta llegar al ultimo nodo, inicia desde el nodo head
		temp = listaC->head;
    	while(temp->next != listaC->head){
    		temp=temp->next;
		}
		// Estando en el ultimo nodo, este apuntara al nodo a agregar al principio
		temp->next=node;
	}
	// Se le asigna el nodo head al nodo agregado a la lista
	listaC->head = node;
    listaC->tamano++;
}

// Eliminará el primer nodo de la lista
void borrarPrimeroC(ListaC *listaC) {
    if (listaC->tamano == 0) {
        printf("\tLa lista esta vacia\n");
    	free(listaC->head);
    }
    else{
		NodoC *nuevo_head = NULL;
		NodoC *temp = listaC->head->next;
		// Ciclo for para llegar al ultimo elemento de la lista y hacer que este seleccione
		// Al segundo nodo de la lista, debido que el primer nodo sera el segundo nodo
		nuevo_head=temp;
		while (temp->next != listaC->head)
		{
			temp = temp->next;
		}
		temp->next = nuevo_head;
		free(listaC->head);
		listaC->head = nuevo_head;
		// Le puse esto
		listaC->tamano--;
	}
}

// Borrará el último nodo de la lista
void borrarUltimoC(ListaC *listaC) {
	if (listaC->tamano == 0) {
        printf("\tLa lista esta vacia\n");
    }
    else{
		int i = 1;
		NodoC *current = listaC->head;
		NodoC *current2 = listaC->head->next;
		while (i != (listaC->tamano-1))
		{
			
			current = current->next;
			current2 = current2->next;
			i++;
		}
		current->next = listaC->head;
		current2 = NULL;
		listaC->tamano--;
	}
}

// Imprimirá el valor del primer nodo de la lista
int primerElementoC(ListaC lista){
	NodoC *primer = lista.head;
	printComputadora(primer->val);
}

// Aquí inicia todo el programa
int main() {
	int opcion, cantidadComputadoras, i, posicion, op;
	// Crea una lista
	ListaC lista = crearListaC();
	// Crea una estructura computadora 
	Computadora agregar;
	printf("\t%cLista Circular Ligada%c\n",decoracion,decoracion);
	// Se le pregunta al usuario si desea agregar computadoras o trabajar con las creadas
	printf("%c%cDesea agregar las computadoras?\n",barras,ap);
	printf("1.- Si\n");
	printf("2.- No\n");
	fflush(stdin);
	scanf("%d", &opcion);
	switch (opcion)
	{
	case 1:
		// ? Si el usuario desea crear computadoras, se ejecuta esta parte
		// Se le pregunta la cantidad de computadoras que desea
		printf("%c%cCu%cntas computadoras desea agregar?\n",barras,ap,aa);
		fflush(stdin);
		scanf("%d", &cantidadComputadoras);
		// Atraves de un ciclo for, se mandara a llamar la funcion de crearComputadora
		// enviandole como argumento el numero de computadora con la que se esta trabajando
		for (i = 1; i <= cantidadComputadoras; i++)
		{
			agregar = crearCompu(i);
			// Se le pregunta si desea agregar la computadora al principio o al final de
			// la lista
			printf("%c%cEn que parte de la lista desea agregarla?\n", barras, ap);
			printf("1.- Al inicio\n");
			printf("2.- Al final\n");
			fflush(stdin);
			scanf("%d", &posicion);
			if (posicion == 1)
			{
				addPrincipioListaC(&lista, agregar);
			} else if(posicion == 2) {
				addFinalListaC(&lista, agregar);
			} else {
				printf("%cIngrese un n%cmero v%clido\n", barras,au,aa);
			}
		}
		// Se ejecuta este ciclo Do-While llamando a la funcion Menu, y
		// obteniendo la instruccion que desea ejecutar, siempre y cuando sea
		// una instruccion entre 1 y 8
		do
		{
			op = menuCircular();
			menuLista(op, &lista);
		} while (op >= 1 && op <= 8);
		break;

	case 2:
		// ? Si no desea crear computadoras, se ejecuta esta parte
		printf("Se han creado 4 computadoras con sus caracter%csticas\n",ai);
		// Se llaman a las funciones donde fueron creadas las computadoras
		// y se guardan en una variable de tipo Computadora
		Computadora c1 = Computadora1();
		Computadora c2 = Computadora2();
		Computadora c3 = Computadora3();
		Computadora c4 = Computadora4();
		// Se imprime cada computadora
		printComputadora(c1);		
		printComputadora(c2);		
		printComputadora(c3);		
		printComputadora(c4);
		// Y se agregan al final de la lista
		addFinalListaC(&lista, c1);
		addFinalListaC(&lista, c2);
		addFinalListaC(&lista, c3);
		addFinalListaC(&lista, c4);
		// Se ejecuta el menu siempre y cuando, el numero ingresado por el usuario sea
		// entre 1 y 8, debido a que solo hay esas operaciones
		do
		{
			op = menuCircular();
			menuLista(op, &lista);
		} while (op >= 1 && op <= 8);
		
		break;
	default:
		printf("%cIngrese un n%cmero v%alido\n", barras,au,aa);
		break;
	}
}

// Funcion encargada de crear la computadora y llenarla conforme el usuario desee
Computadora crearCompu(int i){
	// Recibe como parametro el numero de computadoras que desea crear
	// Crea una estructura Computadora en donde guardara la info
	Computadora creada;
	printf("\t%cComputadora #%d",barras,i);
	// Se le solicita al usuario la informacion
	printf("\n%cIngrese el ID: \n", barras);
	fflush(stdin);
	scanf("%d", &creada.id);

	printf("%cIngrese la marca: \n", barras);
	fflush(stdin);
	scanf("%20[^\n]", &creada.marca);

	printf("%cIngrese la cantidad de memoria: \n", barras);
	fflush(stdin);
	scanf("%20[^\n]", &creada.memoria);

	printf("%cIngrese el procesador: \n", barras);
	fflush(stdin);
	scanf("%20[^\n]", &creada.procesador);

	printf("%cIngrese el sistema operativo: \n", barras);
	fflush(stdin);
	scanf("%20[^\n]", &creada.sistenmaOperativo);

	printf("%cIngrese el tipo de computadora: \n", barras);
	fflush(stdin);
	scanf("%20[^\n]", &creada.tipo);
	// Se retorna la computadora creada
	return creada;
}

// * Para fines practicos, se crean 4 computadoras si el usuario no desea crearlas

// Computadora No.1 con su propia info
Computadora Computadora1() {
	Computadora comp1;
	comp1.id = 83121;
	strcpy(comp1.marca, "DELL");
	strcpy(comp1.memoria, "16GB RAM");
	strcpy(comp1.procesador,"Intel CoreI9");
	strcpy(comp1.sistenmaOperativo, "Windows");
	strcpy(comp1.tipo, "Laptop");
	return comp1;
}
// Computadora No.2 con su propia info
Computadora Computadora2() {
	Computadora comp2;
	comp2.id = 9120823;
	strcpy(comp2.marca, "Lenovo");
	strcpy(comp2.memoria, "64GB RAM");
	strcpy(comp2.procesador,"Intel CoreI7");
	strcpy(comp2.sistenmaOperativo, "Windows");
	strcpy(comp2.tipo, "Desktop");
	return comp2;
}
// Computadora No.3 con su propia info
Computadora Computadora3() {
	Computadora comp3;
	comp3.id = 357320;
	strcpy(comp3.marca, "Alienware");
	strcpy(comp3.memoria, "24GB RAM");
	strcpy(comp3.procesador,"Ryzen 9 3950X");
	strcpy(comp3.sistenmaOperativo, "Windows");
	strcpy(comp3.tipo, "Laptop");
	return comp3;
}
// Computadora No.4 con su propia info
Computadora Computadora4() {
	Computadora comp4;
	comp4.id = 729012;
	strcpy(comp4.marca, "Apple");
	strcpy(comp4.memoria, "32GB RAM");
	strcpy(comp4.procesador,"M1");
	strcpy(comp4.sistenmaOperativo, "MAC OS X");
	strcpy(comp4.tipo, "Desktop");
	return comp4;
}

// Imprime la informacion de la computadora del parametro
void printComputadora(Computadora imprimir) {
	// Imprime la informacion de la estructura Computadora que recibe como parametro
	printf("ID: %d\n", imprimir.id);
	printf("Marca: %s\n", imprimir.marca);
	printf("Memoria: %s\n", imprimir.memoria);
	printf("Procesador: %s\n", imprimir.procesador);
	printf("Sistema Operativo: %s\n", imprimir.sistenmaOperativo);
	printf("Tipo de Computadora: %s\n", imprimir.tipo);
	printf("\n");
}

// *  Actividad 2.B - TERMINADO
// Recibe como parametros la lista con la que se esta trabajando 
// El ID que el usuario desea buscar
void BuscarCirc(ListaC busquedaComp, int id) {
	NodoC *temp = busquedaComp.head;
	// La variable 'j' guardara '0' o '1' indicando si se encontro el ID o no.
	int i = 0, j = 0;
	// Con un ciclo while, se recorrera la lista y se ejecutara 
	// hasta que I llegue al tamano de la lista.
	while (i != busquedaComp.tamano)
	{
		// Si el id que recube como parametro es el mismo ID que del nodo actual
		if (temp->val.id == id)
		{
			// Se crea una estructura Computadora con la informacion actual del nodo
			Computadora paraImprimir = temp->val;
			// Se le envia como parametro a la funcion para se impresa
			printComputadora(paraImprimir);
			// Se le informa en que posicion se encontro
			printf("%cEn la posici%cn %d\n",barras,ao,i+1);
			// Se le da a I el valor de tamano, para que termine el ciclo WHILE
			i = busquedaComp.tamano;
			// Se le suma 1 a la variable J, para que se indique que al sistema que el ID
			// fue encontrado.
			j++;
		}
		else {
			// Si el ID que el usuario desea encontrar y la del nodo no coinciden
			// Se aumenta el ID para avanzar al siguiente nodo
			i++;
		}
		// El nodo temp va a valer lo del siguiente nodo
		temp = temp->next;
	}
	if (j == 0) {
		// Si no se encontro el ID, se le notifica al usuario
		printf("%cNo se encontr%c el ID :(\n", barras, ao);
	}
	printf("\n");
}


// * Actividad 2.C - TERMINADO
// La funcion recorre la lista pero el usuario decide si avanzar, retroceder, 
// ver la informacion del nodo actual o salir de la lista circular
// Esto se hace con teclas 'a', 'd', 'g', 'j'.
void recorrerLista(ListaC listaImprimir) {
	// Si le da 'a', retrocede 1 nodo
	// Si le da 'd', avanza 1 nodo 
	// Si le da 'j', muestra la info del nodo actual
	// Si le da 'g', sale de la ejeción de recorrido
	// El nodo inicia al principio de la lista
	NodoC *imprimir = listaImprimir.head;
	// El nodo estara recorreindo la lista
	if (listaImprimir.tamano == 0)
	{
		// Si el tamano de la lista es 0
		printf("\nNo se puede realizar la acci%cn debido a que no hay elementos en la lista\n");
	} else {
		// Si contiene nodos se ejecuta esta parte
		char UserInput = ' ';
		printf("\n%c Ingrese 'a' para moverse al nodo de la izquierda\n",barras);
		printf("%c Ingrese 'd' para moverse al nodo de la derecha\n",barras);
		printf("%c Ingrese 'g' para ver la informaci%cn del nodo\n",barras,ao);
		printf("%c Ingrese 'j' para salir de la ejecuci%cn\n",barras,ao);
		do
		{
			NodoC *actual = imprimir;
			printf("\n");
			fflush(stdin);
			scanf("%s", &UserInput);
			printf("\n");
			switch (UserInput)
			{
			// Cuando se mueve entre nodos, se muestra la informacion del ID y la MARCA
			// Ademas, se le notifica hacia donde se esta moviendo
			case 'a':
				printf("Se mueve a la izquierda\n");
				actual = imprimir->next;
				// Se utiliza un ciclo WHILE para obtener el nodo anterior al actual
				while (actual->next != imprimir) {
					actual = actual->next;
				}
				imprimir = actual;
				printf("ID: %d \n", imprimir->val.id);
				printf("MARCA: %s \n", imprimir->val.marca);
				break;
			case 'd':
				printf("Se mueve a la Derecha\n");
				// Debido que el nodo actual es el siguiente del nodo imprimir
				// Solo es cuestion de igualar al nodo imprimir al actual
				actual = imprimir->next;
				imprimir = actual;
				printf("ID: %d \n", imprimir->val.id);
				printf("MARCA: %s \n", imprimir->val.marca);
				break;
			case 'g':
				// Se va a mostrar la info llamando a la funcion printComputadora
				printf("\nSe Imprime la informaci%cn\n",ao);
				printComputadora(imprimir->val);
				break;
			case 'j':
				printf("Decidi%c salir de la operaci%cn\n",ao,ao);
				break;
			default:
				printf("%c No est%c permitido esa tecla\n",barras,aa);
				break;
			}
		} while (UserInput != 'j');
	}
}

// Se miuestran las operaciones disponibles
int menuCircular() {
	int opcion;
	printf("\n%c 1.-Imprimir la lista\n", barras);
	printf("%c 2.-Agregar un nodo al final de la lista\n", barras);
	printf("%c 3.-Agregar un nodo al principio de la lista\n", barras);
	printf("%c 4.-Borrar el primero nodo de la lista\n", barras);
	printf("%c 5.-Borrar el ultimo nodo de la lista\n", barras);
	printf("%c 6.-Imprimir el primer nodo de la lista\n", barras);
	printf("%c 7.-Buscar a trav%cs del ID\n", barras,ae);
	printf("%c 8.-Recorrer la lista\n", barras);
	printf("%c 9.- Salir del programa\n", barras);
	printf("%c%cCu%cl desea realizar?\n", barras,ap,aa);
	// Guarda el numero de instruccion a ejecutar
	scanf("%d", &opcion);
	// Se retorna dicho numero
	return opcion;
}

// Conforme el numero de instruccion que el usuario ingrese
// se ejecuta dicha funcion
void menuLista(int opcion, ListaC *listaC) {
	Computadora agregar;
	int elemento;
	switch (opcion) {
	case 1:
		print_listC(*listaC);
		printf("Tama%co: %d\n",an,listaC->tamano);
		break;
	case 2:
		agregar = crearCompu(1);
		addFinalListaC(listaC, agregar);
		break;
	case 3:
		agregar = crearCompu(1);
		addPrincipioListaC(listaC, agregar);
		break;
	case 4:
		borrarPrimeroC(listaC);
		break;
	case 5:
		borrarUltimoC(listaC);
		break;
	case 6:
		primerElementoC(*listaC);
		break;
	case 7:
		printf("%c%cCu%cl es el ID que desea buscar?: \n", barras,ap,aa);
        fflush(stdin);	
		scanf("%d", &elemento);
		printf("\n");
		BuscarCirc(*listaC, elemento);
		break;
	case 8:
		recorrerLista(*listaC);
		break;
	default:
		printf("%cNo se reconoce ese d%cgito\n",barras,ai);
		break;
	}
}
