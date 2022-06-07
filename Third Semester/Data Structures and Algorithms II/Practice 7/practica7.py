import sys
import metro

class Nodo:
    # Constructor
    def __init__(self, nombre):
        self.nombre = nombre
        self.vecinos = []
        self.color = None
        self.distancia = None
        self.padre = None

    # Agrega un nodo vecino al nodo
    def agregar_vecinos(self, nodo):
        # Agrega un vecino al nodo si no existe
        if nodo not in self.vecinos:
            self.vecinos.append(nodo)
        else:
            # Si ya existe, se notifica
            print("El nodo vecino {} ya existe".format(nodo.nombre))
            print("Por lo tanto no se agrega\n")

class Grafo:
    # Constructor
    def __init__(self):
        # Diccionario de vertices
        self.vertices = {}

    # Agrega un nodo al grafo
    def agregar_nodo(self, nombre_nodo):
        # Agrega un nodo al grafo al diccionario de nodos
        nuevo_nodo = Nodo(nombre_nodo)
        # Si el nodo no existe
        if nombre_nodo not in self.vertices:
            # Se agrega al diccionario
            self.vertices[nombre_nodo] = nuevo_nodo
        else:
            # Si ya existe, se notifica
            print('El nodo {} ya existe'.format(nombre_nodo))
            print('Por lo tanto no se agrego el nodo\n')

    # Agrega una arista al grafo
    def agregar_arista(self, nombre_nodo1, nombre_nodo2):
        # Si los nodos existen
        if nombre_nodo1 in self.vertices and nombre_nodo2 in self.vertices:
            # Obtiene los nodos correspondientes a los nombres
            nodo1 = self.vertices[nombre_nodo1]
            nodo2 = self.vertices[nombre_nodo2]

            # Agrega el nodo2 como vecino del nodo1 y viceversa
            nodo1.agregar_vecinos(nodo2)
            nodo2.agregar_vecinos(nodo1)
        else:
            # Si uno de los nodos no existe, se notifica
            print("No existe uno de los nodos, {} o {}".format(nombre_nodo1, nombre_nodo2))
            print("Por lo tanto no se agrego la arista\n")

    # Recorre los nodos del grafo a partir del nodo inicial a traves del algoritmo de anchura
    def breadth_first_search(self, nombre_nodo_inicial):
        # Obtiene el nodo inicial
        nodo_s = self.vertices[nombre_nodo_inicial]
        # Inicializa todos los nodos como no visitados
        for unidad in self.vertices.values():
            unidad.color = 'white'
            unidad.distancia = sys.maxsize
            unidad.padre = None

        # Nodo inicial tiene distancia 0 y cambia de color a gris
        nodo_s.color = 'Grey'
        nodo_s.distancia = 0

        # Cola de nodos
        queue = []

        # Encola el nodo inicial
        self.encolar(queue, nodo_s)
        # Mientras la cola no este vacia
        while(len(queue)>0):
            # Desencola el nodo actual y se guarda el nodo
            unidad = self.desencolar(queue)
            # Recorre los vecinos del nodo actual
            for vertice in unidad.vecinos:
                # Si el vecino no ha sido visitado
                if vertice.color == 'white':
                    # Cambia el color del vecino a gris
                    vertice.color = 'Grey'
                    # Cambia la distancia del vecino a la distancia del nodo actual + 1
                    vertice.distancia += 1
                    # Cambia el padre del vecino al nodo actual
                    vertice.padre = unidad

                    # Encola el vecino
                    self.encolar(queue, vertice)

            # Cambia el color del nodo actual a negro despues de recorrer sus vecinos
            unidad.colors = 'Black'

    # Encola un nodo en la cola
    def encolar(self, queue, nodo_s):
        # Agrega el nodo al final de la cola
        queue.append(nodo_s)

    # Desencola un nodo de la cola
    def desencolar(self, queue):
        # ELimina el primer elemento de la cola y lo retorna
        return queue.pop(0)

    # Recorre los nodos del grafo a partir del nodo inicial a traves del algoritmo de profundidad
    def depth_first_search(self, nombre_nodo_inicial):
        # Recorre todos los nodos del grafo y los inicializa como no visitados
        for unidad in self.vertices.values():
            unidad.color = 'white'
            unidad.padre = None

        # Obtiene el nodo inicial
        nodo_s = self.vertices[nombre_nodo_inicial]
        # Llama a la funcion dfs_visitar con el nodo inicial
        self.dfs_visitar(nodo_s)

    # Recorre el grafo a traves del algoritmo de profundidad
    def dfs_visitar(self, nodo_s):
        # Aumenta la distancia del nodo actual en 1
        nodo_s.distancia += 1
        # Cambia el color del nodo a gris
        nodo_s.color = 'Grey'
        # Recorre los vecinos del nodo actual
        for unidad in nodo_s.vecinos:
            # Si el vecino no ha sido visitado
            if unidad.color == 'white':
                # Cambia el padre del vecino al nodo actual
                unidad.padre = nodo_s
                # Llama a la funcion dfs_visitar con el vecino
                self.dfs_visitar(unidad)
        # Cambia el color del nodo actual a negro
        nodo_s.color = 'Black'

    # Guarda el camino mas corto entre dos vertices con el algoritmo de anchura
    def encontrar_camino_bfs(self, nombre_nodo_inicial, nombre_nodo_final):
        # Guarda el nombre de los vertices en el orden para desplazarse
        # Entre el nodo inicial y el final

        self.breadth_first_search(nombre_nodo_inicial)
        # Lista que guarda los nombres de los vertices en el orden en que se visitaron
        camino = []
        # Obtiene el nodo final
        nodo_s = self.vertices[nombre_nodo_final]
        # Mientras el nodo final no sea el nodo inicial
        while nodo_s.padre is not None:
            # Agrega el nombre del nodo al final de la lista
            camino.append(nodo_s.nombre)
            # Cambia el nodo actual al padre del nodo actual
            nodo_s = nodo_s.padre
        # Agrega el nombre del nodo inicial al final de la lista
        camino.append(nodo_s.nombre)
        # Se invierte la lista para que el primer elemento sea el nodo inicial
        camino.reverse()
        # Retorna la lista de nombres de los vertices
        return camino

    # Guarda el camino mas corto entre dos vertices con el metodo de profundidad
    def encontrar_camino_dfs(self, nombre_nodo_inicial, nombre_nodo_final):
        # Guarda el nombre de los vertices en el orden para desplazarse
        # Entre el nodo inicial y el final

        self.depth_first_search(nombre_nodo_inicial)
        # Lista que guarda los nombres de los vertices en el orden en que se visitaron
        camino = []
        # Obtiene el nodo final
        nodo_s = self.vertices[nombre_nodo_final]
        # Mientras el nodo final no sea el nodo inicial
        while nodo_s.padre is not None:
            # Agrega el nombre del nodo al final de la lista
            camino.append(nodo_s.nombre)
            # Cambia el nodo actual al padre del nodo actual
            nodo_s = nodo_s.padre
        # Agrega el nombre del nodo inicial al final de la lista
        camino.append(nodo_s.nombre)
        # Se invierte la lista para que el primer elemento sea el nodo inicial
        camino.reverse()
        # Retorna la lista de nombres de los vertices
        return camino

    # Imprime el nombre de los vertices en el orden en que se visitaron
    def imprimir_camino(self, camino):
        print("Camino:")
        camino = " -> ".join(camino)
        print(camino)

# Crea un grafo con los datos del archivo Metro.py
def run():
    # Crea un grafo
    grafo = Grafo()
    # Agrega los vertices al grafo
    # Por cada linea del metro.py
    for linea in metro.lineas:
        # Por cada estacion de la linea
        for parada in linea:
            # Agrega el vertice
            grafo.agregar_nodo(parada)

    # Agrega las aristas al grafo
    i = 0
    # Por cada linea del metro.py
    for linea in metro.lineas:
        # Por cada estacion de la linea
        for parada in linea:
            # Si la estacion no es la ultima de la linea
            if i != len(linea) - 1:
                # Agrega la arista
                i+=1
                # Enlaza cada estacion con la siguiente
                # Conectando toda la linea
                grafo.agregar_arista(parada, linea[i])
        # Reinicia el contador al iniciar con la linea siguiente
        i = 0

    # Ejemplo de error
    grafo.agregar_arista('San Antonio', 'Mixcoac')
    grafo.agregar_arista('S4n Ant1ni0', 'Mixcoac')

    busqueda0(grafo)
    busqueda1(grafo)
    busqueda2(grafo)
    busqueda3(grafo)
    # print('Hola Mundo')

def busqueda0(grafo):
    nodo1 = "San Antonio"
    nodo2 = "General Anaya"
    print("**{} -> {}**".format(nodo1, nodo2))

    # Imprime el camino a recorrer a traves del algoritmo de bfs
    print("\n-----\nBreadth First Search\n")
    # Obtiene el camino a recorrer desde la estacion inicial hasta la final
    camino = grafo.encontrar_camino_bfs(nodo1, nodo2)
    print("Numero de estaciones: ", len(camino))
    # Imprime el camino
    grafo.imprimir_camino(camino)

    # Imprime el camino a recorrer a traves del algoritmo de dfs
    print("\n-----\nDepth First Search\n")
    # Obtiene el camino a recorrer desde la estacion inicial hasta la final
    camino2 = grafo.encontrar_camino_dfs(nodo1, nodo2)
    print("Numero de estaciones: " + str(len(camino2)))
    # Imprime el camino
    grafo.imprimir_camino(camino2)
    print("\n")

def busqueda1(grafo):
    nodo1 = "Aquiles Serdán"
    nodo2 = "Iztapalapa"
    print("**{} -> {}**".format(nodo1, nodo2))

    # Imprime el camino a recorrer a traves del algoritmo de bfs
    print("\n-----\nBreadth First Search\n")
    # Obtiene el camino a recorrer desde la estacion inicial hasta la final
    camino = grafo.encontrar_camino_bfs(nodo1, nodo2)
    print("Numero de estaciones: ", len(camino))
    # Imprime el camino
    grafo.imprimir_camino(camino)

    # Imprime el camino a recorrer a traves del algoritmo de dfs
    print("\n-----\nDepth First Search\n")
    # Obtiene el camino a recorrer desde la estacion inicial hasta la final
    camino2 = grafo.encontrar_camino_dfs(nodo1, nodo2)
    print("Numero de estaciones: " + str(len(camino2)))
    # Imprime el camino
    grafo.imprimir_camino(camino2)
    print("\n")

def busqueda2(grafo):
    nodo1 = "San Antonio"
    nodo2 = "Aragón"
    print("**{} -> {}**".format(nodo1, nodo2))

    # Imprime el camino a recorrer a traves del algoritmo de bfs
    print("\n-----\nBreadth First Search\n")
    # Obtiene el camino a recorrer desde la estacion inicial hasta la final
    camino = grafo.encontrar_camino_bfs(nodo1, nodo2)
    print("Numero de estaciones: ", len(camino))
    # Imprime el camino
    grafo.imprimir_camino(camino)

    # Imprime el camino a recorrer a traves del algoritmo de dfs
    print("\n-----\nDepth First Search\n")
    # Obtiene el camino a recorrer desde la estacion inicial hasta la final
    camino2 = grafo.encontrar_camino_dfs(nodo1, nodo2)
    print("Numero de estaciones: " + str(len(camino2)))
    # Imprime el camino
    grafo.imprimir_camino(camino2)
    print("\n")

def busqueda3(grafo):
    nodo1 = "Vallejo"
    nodo2 = "Insurgentes"
    print("**{} -> {}**".format(nodo1, nodo2))

    # Imprime el camino a recorrer a traves del algoritmo de bfs
    print("\n-----\nBreadth First Search\n")
    # Obtiene el camino a recorrer desde la estacion inicial hasta la final
    camino = grafo.encontrar_camino_bfs(nodo1, nodo2)
    print("Numero de estaciones: ", len(camino))
    # Imprime el camino
    grafo.imprimir_camino(camino)

    # Imprime el camino a recorrer a traves del algoritmo de dfs
    print("\n-----\nDepth First Search\n")
    # Obtiene el camino a recorrer desde la estacion inicial hasta la final
    camino2 = grafo.encontrar_camino_dfs(nodo1, nodo2)
    print("Numero de estaciones: " + str(len(camino2)))
    # Imprime el camino
    grafo.imprimir_camino(camino2)
    print("\n")

# Metodo principal
if __name__ == '__main__':
    run()