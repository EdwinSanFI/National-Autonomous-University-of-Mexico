import sys
import metro

class node:
    # Constructor
    def __init__(self, name):
        self.name = name
        self.neighbors = []
        self.color = None
        self.distance = None
        self.parent = None

    # Add a neighbor to the node
    def add_neighbors(self, node):
        # Check if the node is already in the list
        if node not in self.neighbors:
            self.neighbors.append(node)
        else:
            print("The node {} already in list".format(node.name))
            print("Therefore is not added")

class graph:
    # Constructor
    def __init__(self):
        # Vertex dictionary
        self.vertex = {}

    # Add a node to the graph
    def add_node(self, name_node):
        new_node = node(name_node)
        # Check if the node is already in the graph
        if name_node not in self.vertex:
            # Add the node to the graph
            self.vertex[name_node] = new_node
        else:
            # If the node is already in the graph, it is not added
            print('The node {} already exists'.format(name_node))
            print('Therefore is not added\n')

    # Add an edge to the graph
    def add_edge(self, name_node1, name_node2):
        # If both nodes are in the graph
        if name_node1 in self.vertex and name_node2 in self.vertex:
            # obtain the nodes
            node1 = self.vertex[name_node1]
            node2 = self.vertex[name_node2]

            # Add the neighbors
            node1.add_neighbors(node2)
            node2.add_neighbors(node1)
        else:
            # If one of the nodes is not in the graph
            print("One of the nodes {} or {} doesnt exist".format(name_node1, name_node2))
            print("Therefore the edge is not added\n")

    # Recorre los nodes del graph a partir del node inicial a traves del algoritmo de anchura
    def breadth_first_search(self, name_node_inicial):
        # Obtiene el node inicial
        node_s = self.vertex[name_node_inicial]
        # Inicializa todos los nodes como no visitados
        for unidad in self.vertex.values():
            unidad.color = 'white'
            unidad.distance = sys.maxsize
            unidad.parent = None

        # node inicial tiene distance 0 y cambia de color a gris
        node_s.color = 'Grey'
        node_s.distance = 0

        # Cola de nodes
        queue = []

        # Encola el node inicial
        self.enqueue(queue, node_s)
        # Mientras la cola no este vacia
        while(len(queue)>0):
            # Desencola el node actual y se guarda el node
            unidad = self.desqueue(queue)
            # Recorre los neighbors del node actual
            for vertice in unidad.neighbors:
                # Si el vecino no ha sido visitado
                if vertice.color == 'white':
                    # Cambia el color del vecino a gris
                    vertice.color = 'Grey'
                    # Cambia la distance del vecino a la distance del node actual + 1
                    vertice.distance += 1
                    # Cambia el parent del vecino al node actual
                    vertice.parent = unidad

                    # Encola el vecino
                    self.enqueue(queue, vertice)

            # Cambia el color del node actual a negro despues de recorrer sus neighbors
            unidad.colors = 'Black'

    # Encola un node en la cola
    def enqueue(self, queue, node_s):
        # Agrega el node al final de la cola
        queue.append(node_s)

    # Desencola un node de la cola
    def desqueue(self, queue):
        # ELimina el primer elemento de la cola y lo retorna
        return queue.pop(0)

    # Recorre los nodes del graph a partir del node inicial a traves del algoritmo de profundidad
    def depth_first_search(self, name_node_inicial):
        # Recorre todos los nodes del graph y los inicializa como no visitados
        for unidad in self.vertex.values():
            unidad.color = 'white'
            unidad.parent = None

        # Obtiene el node inicial
        node_s = self.vertex[name_node_inicial]
        # Llama a la funcion dfs_visit con el node inicial
        self.dfs_visit(node_s)

    # Recorre el graph a traves del algoritmo de profundidad
    def dfs_visit(self, node_s):
        # Aumenta la distance del node actual en 1
        node_s.distance += 1
        # Cambia el color del node a gris
        node_s.color = 'Grey'
        # Recorre los neighbors del node actual
        for unidad in node_s.neighbors:
            # Si el vecino no ha sido visitado
            if unidad.color == 'white':
                # Cambia el parent del vecino al node actual
                unidad.parent = node_s
                # Llama a la funcion dfs_visit con el vecino
                self.dfs_visit(unidad)
        # Cambia el color del node actual a negro
        node_s.color = 'Black'

    # Guarda el path mas corto entre dos vertex con el algoritmo de anchura
    def find_path_bfs(self, name_node_inicial, name_node_final):
        # Guarda el name de los vertex en el orden para desplazarse
        # Entre el node inicial y el final

        self.breadth_first_search(name_node_inicial)
        # Lista que guarda los names de los vertex en el orden en que se visitaron
        path = []
        # Obtiene el node final
        node_s = self.vertex[name_node_final]
        # Mientras el node final no sea el node inicial
        while node_s.parent is not None:
            # Agrega el name del node al final de la lista
            path.append(node_s.name)
            # Cambia el node actual al parent del node actual
            node_s = node_s.parent
        # Agrega el name del node inicial al final de la lista
        path.append(node_s.name)
        # Se invierte la lista para que el primer elemento sea el node inicial
        path.reverse()
        # Retorna la lista de names de los vertex
        return path

    # Guarda el path mas corto entre dos vertex con el metodo de profundidad
    def find_path_dfs(self, name_node_inicial, name_node_final):
        # Guarda el name de los vertex en el orden para desplazarse
        # Entre el node inicial y el final

        self.depth_first_search(name_node_inicial)
        # Lista que guarda los names de los vertex en el orden en que se visitaron
        path = []
        # Obtiene el node final
        node_s = self.vertex[name_node_final]
        # Mientras el node final no sea el node inicial
        while node_s.parent is not None:
            # Agrega el name del node al final de la lista
            path.append(node_s.name)
            # Cambia el node actual al parent del node actual
            node_s = node_s.parent
        # Agrega el name del node inicial al final de la lista
        path.append(node_s.name)
        # Se invierte la lista para que el primer elemento sea el node inicial
        path.reverse()
        # Retorna la lista de names de los vertex
        return path

    # Imprime el name de los vertex en el orden en que se visitaron
    def print_path(self, path):
        print("path:")
        path = " -> ".join(path)
        print(path)

# Crea un graph con los datos del archivo Metro.py
def run():
    # Crea un graph
    graph = graph()
    # Agrega los vertex al graph
    # Por cada linea del metro.py
    for linea in metro.lineas:
        # Por cada estacion de la linea
        for parada in linea:
            # Agrega el vertice
            graph.add_node(parada)

    # Agrega las edges al graph
    i = 0
    # Por cada linea del metro.py
    for linea in metro.lineas:
        # Por cada estacion de la linea
        for parada in linea:
            # Si la estacion no es la ultima de la linea
            if i != len(linea) - 1:
                # Agrega la edge
                i+=1
                # Enlaza cada estacion con la siguiente
                # Conectando toda la linea
                graph.add_edge(parada, linea[i])
        # Reinicia el contador al iniciar con la linea siguiente
        i = 0

    # Ejemplo de error
    graph.add_edge('San Antonio', 'Mixcoac')
    graph.add_edge('S4n Ant1ni0', 'Mixcoac')

    busqueda0(graph)
    busqueda1(graph)
    busqueda2(graph)
    busqueda3(graph)
    # print('Hola Mundo')

def busqueda0(graph):
    node1 = "San Antonio"
    node2 = "General Anaya"
    print("**{} -> {}**".format(node1, node2))

    # Imprime el path a recorrer a traves del algoritmo de bfs
    print("\n-----\nBreadth First Search\n")
    # Obtiene el path a recorrer desde la estacion inicial hasta la final
    path = graph.find_path_bfs(node1, node2)
    print("Numero de estaciones: ", len(path))
    # Imprime el path
    graph.print_path(path)

    # Imprime el path a recorrer a traves del algoritmo de dfs
    print("\n-----\nDepth First Search\n")
    # Obtiene el path a recorrer desde la estacion inicial hasta la final
    path2 = graph.find_path_dfs(node1, node2)
    print("Numero de estaciones: " + str(len(path2)))
    # Imprime el path
    graph.print_path(path2)
    print("\n")

def busqueda1(graph):
    node1 = "Aquiles Serdán"
    node2 = "Iztapalapa"
    print("**{} -> {}**".format(node1, node2))

    # Imprime el path a recorrer a traves del algoritmo de bfs
    print("\n-----\nBreadth First Search\n")
    # Obtiene el path a recorrer desde la estacion inicial hasta la final
    path = graph.find_path_bfs(node1, node2)
    print("Numero de estaciones: ", len(path))
    # Imprime el path
    graph.print_path(path)

    # Imprime el path a recorrer a traves del algoritmo de dfs
    print("\n-----\nDepth First Search\n")
    # Obtiene el path a recorrer desde la estacion inicial hasta la final
    path2 = graph.find_path_dfs(node1, node2)
    print("Numero de estaciones: " + str(len(path2)))
    # Imprime el path
    graph.print_path(path2)
    print("\n")

def busqueda2(graph):
    node1 = "San Antonio"
    node2 = "Aragón"
    print("**{} -> {}**".format(node1, node2))

    # Imprime el path a recorrer a traves del algoritmo de bfs
    print("\n-----\nBreadth First Search\n")
    # Obtiene el path a recorrer desde la estacion inicial hasta la final
    path = graph.find_path_bfs(node1, node2)
    print("Numero de estaciones: ", len(path))
    # Imprime el path
    graph.print_path(path)

    # Imprime el path a recorrer a traves del algoritmo de dfs
    print("\n-----\nDepth First Search\n")
    # Obtiene el path a recorrer desde la estacion inicial hasta la final
    path2 = graph.find_path_dfs(node1, node2)
    print("Numero de estaciones: " + str(len(path2)))
    # Imprime el path
    graph.print_path(path2)
    print("\n")

def busqueda3(graph):
    node1 = "Vallejo"
    node2 = "Insurgentes"
    print("**{} -> {}**".format(node1, node2))

    # Imprime el path a recorrer a traves del algoritmo de bfs
    print("\n-----\nBreadth First Search\n")
    # Obtiene el path a recorrer desde la estacion inicial hasta la final
    path = graph.find_path_bfs(node1, node2)
    print("Numero de estaciones: ", len(path))
    # Imprime el path
    graph.print_path(path)

    # Imprime el path a recorrer a traves del algoritmo de dfs
    print("\n-----\nDepth First Search\n")
    # Obtiene el path a recorrer desde la estacion inicial hasta la final
    path2 = graph.find_path_dfs(node1, node2)
    print("Numero de estaciones: " + str(len(path2)))
    # Imprime el path
    graph.print_path(path2)
    print("\n")

# Metodo principal
if __name__ == '__main__':
    run()