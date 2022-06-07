class nodo():
    def __init__(self, nombre):
        # Nmbre del nodo
        self.nombre = nombre
        # Lista de vecinos
        self.vecinos = []

    def AgregarVecino(self, nodo):
        # Agrega un vecino al nodo si no existe
        if nodo not in self.vecinos:
            self.vecinos.append(nodo)
        else:
            # Si ya existe, se notifica
            print("El nodo vecino {} ya existe".format(nodo.nombre))
            print("Por lo tanto no se agrega\n")

class grafo():
    def __init__(self):
        # Diccionario de nodos
        self.vertice = {}

    def AgregarNodo(self, nombreNodo):
        # Agrega un nodo al grafo al diccionario de nodos
        nuevoNodo = nodo(nombreNodo)
        # Si el nodo no existe
        if nombreNodo not in self.vertice:
            # Se agrega al diccionario
            self.vertice[nombreNodo] = nuevoNodo
        else:
            # Si ya existe, se notifica
            print('El nodo {} ya existe'.format(nombreNodo))
            print('Por lo tanto no se agrego el nodo\n')

    # Agrega una arista al grafo
    def AgregarArista(self, nombre_nodo1, nombre_nodo2):
        # Si los nodos existen
        if nombre_nodo1 in self.vertice and nombre_nodo2 in self.vertice:
            # Obtenemos los nodos
            nodo1 = self.vertice[nombre_nodo1]
            nodo2 = self.vertice[nombre_nodo2]

            # Se agrega de vecino al nodo
            nodo1.AgregarVecino(nodo2)
            nodo2.AgregarVecino(nodo1)
        else:
            # Si uno de los nodos no existe, se notifica
            print("No existe uno de los nodos, {} o {}".format(nombre_nodo1, nombre_nodo2))
            print("Por lo tanto no se agrego la arista\n")

    def imprimir(self):
        # Imprime el grafo
        # Se recorre el diccionario
        for n in self.vertice.keys():
            # Se obtiene el nodo
            nodo = self.vertice[n]
            # Se obtiene la lista de vecinos
            vecinos = nodo.vecinos
            # Se imprime el nombre del nodo
            print("Grafo: ",nodo.nombre)
            for v in vecinos:
                # Se imprime el nombre del vecino
                print(" Vecinos: ", v.nombre)
            print("")

def run():
    g = grafo()

    # Se agregan los nodos
    g.AgregarNodo(0)
    g.AgregarNodo(1)
    g.AgregarNodo(2)
    g.AgregarNodo(3)
    g.AgregarNodo(4)
    g.AgregarNodo(5)
    g.AgregarNodo(6)
    g.AgregarNodo(7)

    # Se agregan las aristas
    g.AgregarArista(0, 1)
    g.AgregarArista(0, 2)
    g.AgregarArista(0, 3)
    g.AgregarArista(1, 2)
    g.AgregarArista(2, 3)
    g.AgregarArista(3, 4)
    g.AgregarArista(4, 5)
    g.AgregarArista(4, 6)
    g.AgregarArista(5, 6)

    # Se imprime el grafo
    g.imprimir()

    # Casos de error
    print("\nCasos de error\n")
    # Agregar un nodo que ya existe
    print("Agregar un nodo que ya existe (0)")
    g.AgregarNodo(0)
    # Agregar una arista que ya existe
    print("Agregar una arista que ya existe (0 - 1)")
    g.AgregarArista(0, 1)
    # Agregar una arista que cuando un nodo no existe
    print("Agregar una arista que cuando un nodo no existe (8) \n")
    g.AgregarArista(0, 8)

if __name__ == '__main__':
    run()