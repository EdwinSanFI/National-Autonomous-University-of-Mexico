class node:
    # Constructor
    def __init__(self, val):
        self.value = val
        self.left = None
        self.right = None

# tree B
class Binary_Tree:
    # Constructor
    def __init__(self):
        self.root = None

    def add_node(self, k, node):
        # If the tree is empty
        if self.root == None:
            self.root = node(k)

        else:
            # If the value is less than the node value
            if k < node.value:
                # If the node has no left child
                if node.left == None:
                    node.left = node(k)
                # If the node has a left child
                else:
                    self.add_node(k, node.left)
            # If the value is greater than the node value
            elif k > node.value:
                # If the node has no right child
                if node.right == None:
                    node.right = node(k)
                # If the node has a right child
                else:
                    self.add_node(k, node.right)
            elif k == node.value:
                print("The value " + str(k) + " already exists in the tree")

    def in_order(self, node):
        if node != None:
            self.in_order(node.left)
            print(node.value, end=" ")
            self.in_order(node.right)

    def pre_order(self, node):
        if node != None:
            print(node.value, end=" ")
            self.pre_order(node.left)
            self.pre_order(node.right)

    def post_order(self, node):
        if node != None:
            self.post_order(node.left)
            self.post_order(node.right)
            print(node.value, end=" ")

    def search(self, k, node):
        if node != None:
            if k < node.value:
                self.search(k, node.left)
            elif k > node.value:
                self.search(k, node.right)
            elif k == node.value:
                print("Existe el " + str(k),"? True")
        else:
            print("Existe el " + str(k),"? False")

    # Funcion para eliminar un node
    def delete2(self, k, node):
        # Se guarda en un arreglo los node recorridos en el tree
        node_recorridos =[node]
        while node != None:
            if k < node.value:
                node = node.left
                node_recorridos.append(node)
            elif k > node.value:
                node = node.right
                node_recorridos.append(node)
            elif k == node.value:
                if node.left != None and node.right != None:
                    value_max = self.maximum(node.left)
                    self.delete2(value_max,node)
                    node.value = value_max

                # Si el node no tiene hijos
                elif node.left == None and node.right == None:
                    # Se obtiene el penultimo node recorrido
                    nuevo_node = node_recorridos[-2]
                    # Si el penultimo node tiene hijo leftuierdo y es el node actual
                    if nuevo_node.left != None  and nuevo_node.left.value == node.value:
                        # El penultimo node deja de hacer referencia al node actual
                        nuevo_node.left = None
                    # Si el penultimo node tiene hijo rightecho y es el node actual
                    else:
                        # El penultimo node deja de hacer referencia al node actual
                        nuevo_node.right = None
                    # EL node actual es eliminado
                    node = None
                # Tiene hijo leftuierdo
                elif node.left != None:
                    # Se obtiene el penultimo node recorrido
                    nuevo_node = node_recorridos[-2]
                    # Si el penultimo node tiene hijo leftuierdo y es el node actual
                    if nuevo_node.left != None and nuevo_node.left.value == node.value:
                        # El hijo leftuierdo del penultimo node hará referencia al hijo leftuierdo del node actual
                        nuevo_node.left = node.left
                    else:
                        # El hijo rightecho del penultimo node hará referencia al hijo leftuierdo del node actual
                        nuevo_node.right = node.left
                # Tiene hijo rightecho
                elif node.right != None:
                    # Se obtiene el penultimo node recorrido
                    nuevo_node = node_recorridos[-2]
                    # Si el penultimo node tiene hijo rightecho y es el node actual
                    if nuevo_node.left != None and nuevo_node.left.value == node.value:
                        # El hijo leftuierdo del penultimo node hará referencia al hijo rightecho del node actual
                        nuevo_node.left = node.right
                    else:
                        # El hijo rightecho del penultimo node hará referencia al hijo rightecho del node actual
                        nuevo_node.right = node.right
                break
            else:
                print("\nNo se pudo eliminar el value " + str(k), " porque no existe")

    # Get the minimum value in the tree
    def minimum(self, node):
        if node != None:
            if node.left != None:
                return self.minimum(node.left)
            else:
                return node.value
        else:
            return None

    # Get the maximum value in the tree
    def maximum(self, node):
        # Si el node no es None
        if node != None:
            # Si el node tiene hijo rightecho
            if node.right != None:
                # Llamamos recursivamente a la funcion con el node rightecho
                return self.maximum(node.right)
            # Si el node no tiene hijo rightecho
            else:
                # Retornamos el value del node
                return node.value
        else:
            return None

    # Print the tree
    def print_tree(self):
        print("\n*Tree*")
        if self.root != None:
            print(" -pre_order: ", end=" ")
            self.pre_order(self.root)
            print()
            print(" -in_order: ",end=" ")
            self.in_order(self.root)
            print()
            print(" -post_order",end=" ")
            self.post_order(self.root)
            print()
            print(" -breadth",end=" ")
            self.breadth(self.root)
            print()
        else:
            print("The tree is empty")

    # Method to go through the tree in level order
    def breadth(self, node):
        if node !=None:
            queue = []
            queue.append(node)
            while len(queue) > 0:
                # Get the first node in the queue
                node = queue.pop(0)
                print(node.value, end=" ")
                # If the node has a left child
                if node.left != None:
                    queue.append(node.left)
                # If the node has a right child
                if node.right != None:
                    queue.append(node.right)

if __name__ == '__main__':
    # Create a binary tree
    tree = Binary_Tree()

    # Empty tree
    tree.print_tree()

    # Insert values
    tree.add_node(8, tree.root)
    tree.add_node(3, tree.root)
    tree.add_node(10, tree.root)
    tree.add_node(1, tree.root)
    tree.add_node(6, tree.root)
    tree.add_node(14, tree.root)
    tree.add_node(4, tree.root)
    tree.add_node(7, tree.root)
    tree.add_node(13, tree.root)

    # Tree with values
    tree.print_tree()

    # Add a repeated value
    print("\n")
    tree.add_node(14, tree.root)
    tree.add_node(1, tree.root)
    print("\n")

    # Get the maximum y minimum value of the tree
    print("**Maximum and minimum value**")
    print("\nThe minimum value is: ",tree.minimum(tree.root))
    print("The maximum value is: ",tree.maximum(tree.root))
    print()

    # Buscamos un value en el tree
    print("\n**Search method**\n")
    tree.search(4,tree.root)
    tree.search(8,tree.root)
    tree.search(13,tree.root)
    tree.search(2,tree.root)
    tree.search(15,tree.root)

    print("\n**Delete method**\n")

    print("\n  -Deleting the node 7 (no children)")
    tree.delete2(7, tree.root)
    tree.print_tree()

    print("\n  -Deleting the node 10 (with right children)")
    tree.delete2(10, tree.root)
    tree.print_tree()

    print("\n  -Deleting the node 6 (with left children)")
    tree.delete2(6, tree.root)
    tree.print_tree()

    print("\n  -Deleting the node 3 (with two children)")
    tree.delete2(3, tree.root)
    tree.print_tree()

    print("\n  -Deleting the node 3 (doesn't exist)")
    tree.delete2(3, tree.root)
    tree.print_tree()

    print("\n  -Deleting the node 8 (root)")
    tree.delete2(8, tree.root)
    tree.print_tree()

    # Insertamos un value en el tree
    tree.add_node(100, tree.root)
    tree.print_tree()