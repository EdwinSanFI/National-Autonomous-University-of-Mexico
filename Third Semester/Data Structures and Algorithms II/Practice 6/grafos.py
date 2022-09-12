class node():
    def __init__(self, name):
        self.name = name
        self.neighbor = []

    def add_neighbor(self, node):
        if node not in self.neighbor:
            self.neighbor.append(node)
        else:
            print("The neighbor node {} already exists".format(node.name))
            print("Therefore is not added\n")

class grafo():
    def __init__(self):
        # Nodes dictionary
        self.vertex = {}

    def add_node(self, node_name):
        new_node = node(node_name)
        if node_name not in self.vertex:
            # Is added to the dictionary
            self.vertex[node_name] = new_node
        else:
            # If the node already exists is not added
            print('The node {} already exists'.format(node_name))
            print("Therefore is not added\n")

    def add_edge(self, node_name1, node_name2):
        if node_name1 in self.vertex and node_name2 in self.vertex:
            node1 = self.vertex[node_name1]
            node2 = self.vertex[node_name2]

            node1.add_neighbor(node2)
            node2.add_neighbor(node1)
        else:
            print("No existe uno de los nodes, {} o {}".format(node_name1, node_name2))
            print("Por lo tanto no se agrego la arista\n")

    def imprimir(self):
        for n in self.vertex.keys():
            node = self.vertex[n]
            neighbor = node.neighbor
            print("Grafo: ",node.name)
            for v in neighbor:
                print(" neighbor: ", v.name)
            print("")

def run():
    g = grafo()

    # The nodes are added
    g.add_node(0)
    g.add_node(1)
    g.add_node(2)
    g.add_node(3)
    g.add_node(4)
    g.add_node(5)
    g.add_node(6)
    g.add_node(7)

    # The edges are added
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(0, 3)
    g.add_edge(1, 2)
    g.add_edge(2, 3)
    g.add_edge(3, 4)
    g.add_edge(4, 5)
    g.add_edge(4, 6)
    g.add_edge(5, 6)

    # The graph is printed
    g.imprimir()

    # Error cases
    print("\nCasos de error\n")
    # Add a node that already exists
    print("Agregar un node que ya existe (0)")
    g.add_node(0)
    # Add an edge with a node that exists
    print("Agregar una arista que ya existe (0 - 1)")
    g.add_edge(0, 1)
    # Add an edge with a node that does not exist
    print("Agregar una arista que cuando un node no existe (8) \n")
    g.add_edge(0, 8)

if __name__ == '__main__':
    run()