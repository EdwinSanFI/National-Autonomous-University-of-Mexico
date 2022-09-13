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

class graph():
    def __init__(self):
        # Nodes dictionary
        self.vertex = {}

    def add_node(self, node_name):
        if node_name not in self.vertex:
            # Is added to the dictionary
            new_node = node(node_name)
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
            print("One of the nodes {} or {} doesnt exist".format(node_name1, node_name2))
            print("Therefore is not added to the edge\n")

    def print_graph(self):
        for n in self.vertex.keys():
            node = self.vertex[n]
            neighbor = node.neighbor
            print("Graph: ",node.name)
            for v in neighbor:
                print(" neighbor: ", v.name)
            print("")

def run():
    g = graph()

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
    g.print_graph()

    # Error cases
    print("\nError cases\n")
    # Add a node that already exists
    print("Add an existant node (0)")
    g.add_node(0)
    # Add an edge with a node that exists
    print("Add an existant edge (0 - 1)")
    g.add_edge(0, 1)
    # Add an edge with a node that does not exist
    print("Add an edge when a node doesnt exist (8) \n")
    g.add_edge(0, 8)

if __name__ == '__main__':
    run()