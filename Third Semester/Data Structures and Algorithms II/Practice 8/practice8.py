class node:
    # Constructor
    def __init__(self, val):
        self.value = val
        self.left = None
        self.right = None

# Arbol B
class BTree:
    # Constructor
    def __init__(self):
        # Inicializamos el node raiz en None
        self.root = None

    def add_node(self, k, node):
        # Si el node raiz no existe
        if self.root == None:
            # Se crea un node raiz con el value k
            self.root = node(k)

        # Si el node raiz existe
        else:
            # Si el value es menor que el value del node raiz, se inserta en el subarbol leftuierdo
            if k < node.value:
                # Si el node leftuierdo es None (no tiene hijos)
                if node.left == None:
                    # Insertamos el value en el node leftuierdo
                    node.left = node(k)
                # Si el node leftuierdo tiene hijos
                else:
                    # Llamamos recursivamente a la funcion con el node leftuierdo
                    self.add_node(k, node.left)
            # Si el value es mayor que el value del node raiz, se inserta en el subarbol rightecho
            elif k > node.value:
                # Si el node rightecho es None (no tiene hijos)
                if node.right == None:
                    # Insertamos el value en el node rightecho
                    node.right = node(k)
                #Si el node rightecho tiene hijos
                else:
                    # Llamamos recursivamente a la funcion con el node rightecho
                    self.add_node(k, node.right)

            # Si el value ya existe en el arbol
            elif k == node.value:
                print("The value " + str(k) + " already exists in the tree")

    # Funcion para print_tree el arbol por el metodo in_order
    def in_order(self, node):
        # Si el node no es None
        if node != None:
            # Llamamos recursivamente a la funcion con el node leftuierdo hasta que sea None
            self.in_order(node.left)
            # Imprimimos el value del node
            print(node.value, end=" ")
            # Llamamos recursivamente a la funcion con el node rightecho
            self.in_order(node.right)

    # Funcion para print_tree el arbol por el metodo pre_order
    def pre_order(self, node):
        # Si el node no es None
        if node != None:
            print(node.value, end=" ")
            self.pre_order(node.left)
            self.pre_order(node.right)

    # Funcion para print_tree el arbol por el metodo post_order
    def post_order(self, node):
        # Si el node no es None
        if node != None:
            # Llamamos recursivamente a la funcion con el node leftuierdo
            self.post_order(node.left)
            # Llamamos recursivamente a la funcion con el node rightecho
            self.post_order(node.right)
            # Imprimimos el value del node
            print(node.value, end=" ")

    # Funcion para search un value en el arbol
    def search(self, k, node):
        # Si el node no es None
        if node != None:
            # Si el value es menor que el value del node raiz
            if k < node.value:
                # Llamamos recursivamente a la funcion con el node leftuierdo
                self.search(k, node.left)
            # Si el value es mayor que el value del node raiz
            elif k > node.value:
                # Llamamos recursivamente a la funcion con el node rightecho
                self.search(k, node.right)
            # Si el value es igual que el value del node raiz
            elif k == node.value:
                print("Existe el " + str(k),"? True")
        # No existe el node
        else:
            print("Existe el " + str(k),"? False")

    # Funcion para eliminar un node
    def delete2(self, k, node):
        # Se guarda en un arreglo los node recorridos en el arbol
        node_recorridos =[node]
        # Mientras el node sea distinto a None
        while node != None:
            # Si el value es menor que el value del node raiz
            if k < node.value:
                # El node leftuierdo es el node actual
                node = node.left
                # Se agrega al arreglo el node actual
                node_recorridos.append(node)
            # Si el value es mayor que el value del node raiz
            elif k > node.value:
                # El node rightecho es el node actual
                node = node.right
                # Se agrega al arreglo el node actual
                node_recorridos.append(node)
            # Si el value es igual que el value del node raiz
            elif k == node.value:
                # Si el node tiene hijos
                if node.left != None and node.right != None:
                    # Se obtiene el value maximum en el subarbol leftuierdo
                    value_max = self.maximum(node.left)
                    # Se elimina el value maximum en el subarbol leftuierdo
                    self.delete2(value_max,node)
                    # Se actualiza el value del node actual
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

    # Obtiene el value maximum del arbol
    def minimum(self, node):
        # Si el node no es None
        if node != None:
            # Si el node tiene hijo leftuierdo
            if node.left != None:
                # Llamamos recursivamente a la funcion con el node leftuierdo
                return self.minimum(node.left)
            # Si el node no tiene hijo leftuierdo
            else:
                # Retornamos el value del node
                return node.value
        else:
            return None

    # Obtiene el value minimum del arbol
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

    # Imprime el contenido del arbol
    def print_tree(self):
        print("\n*Tree*")
        # Si el node raiz no es None (existe)
        if self.root != None:
            # Imprime el contenido del arbol a traves del metodo pre orden
            print(" -pre_order: ", end=" ")
            self.pre_order(self.root)
            print()
            # Imprime el contenido del arbol a traves del metodo in orden
            print(" -in_order: ",end=" ")
            self.in_order(self.root)
            print()
            # Imprime el contenido del arbol a traves del metodo post orden
            print(" -post_order",end=" ")
            self.post_order(self.root)
            print()
            # Imprime el contenido del arbol a traves del metodo de breadth
            print(" -breadth",end=" ")
            self.breadth(self.root)
            # Llamamos a la funcion con el node raiz
            print()
        # Si el node raiz no existe (arbol vacio)
        else:
            print("El arbol esta vacio")

    # Funcion para recorrer el arbol por niveles
    def breadth(self, node):
        if node !=None:
            # Creamos una queue
            queue = []
            # Agregamos el node raiz a la queue
            queue.append(node)
            # Mientras la queue no este vacia
            while len(queue) > 0:
                # Sacamos el primer elemento de la queue
                node = queue.pop(0)
                # Imprimimos el value del node
                print(node.value, end=" ")
                # Si el node tiene hijo leftuierdo
                if node.left != None:
                    # Agregamos el hijo leftuierdo a la queue
                    queue.append(node.left)
                # Si el node no tiene hijo leftuierdo
                if node.right != None:
                    # Agregamos el hijo rightecho a la queue
                    queue.append(node.right)

# Funcion main
if __name__ == '__main__':
    # Creamos un arbol
    arbol = BTree()

    # Insertamos node
    arbol.print_tree()

    # Insertamos node
    arbol.add_node(8, arbol.root)
    arbol.add_node(3, arbol.root)
    arbol.add_node(10, arbol.root)
    arbol.add_node(1, arbol.root)
    arbol.add_node(6, arbol.root)
    arbol.add_node(14, arbol.root)
    arbol.add_node(4, arbol.root)
    arbol.add_node(7, arbol.root)
    arbol.add_node(13, arbol.root)

    # Imprimimos el arbol
    arbol.print_tree()

    # Inserta valuees repetidos
    print("\n")
    arbol.add_node(14, arbol.root) # value repetido
    arbol.add_node(1, arbol.root) # valuedo repetido
    print("\n")

    # Obtenemos el maximum y minimum del arbol
    print("**Metodo maximum y minimum**")
    print("\nEl value minimum es: ",arbol.minimum(arbol.root))
    print("El value maximum es: ",arbol.maximum(arbol.root))
    print()

    # Buscamos un value en el arbol
    print("\n**Metodo search**\n")
    arbol.search(4,arbol.root)
    arbol.search(8,arbol.root)
    arbol.search(13,arbol.root)
    arbol.search(2,arbol.root)
    arbol.search(15,arbol.root)

    # Eliminamos un value del arbol
    print("\n**Metodo elimniar**\n")

    print("\n  -Borrando el 7 (sin hijos)")
    arbol.delete2(7, arbol.root)
    arbol.print_tree()

    print("\n  -Borrando el 10 (con hijo rightecho)")
    arbol.delete2(10, arbol.root)
    arbol.print_tree()

    print("\n  -Borrando el 6 (con hijo leftuierdo)")
    arbol.delete2(6, arbol.root)
    arbol.print_tree()

    print("\n  -Borrando el 3 (con ambos hijos)")
    arbol.delete2(3, arbol.root)
    arbol.print_tree()

    print("\n  -Borrando el 3 (no existe)")
    arbol.delete2(3, arbol.root)
    arbol.print_tree()

    print("\n  -Borrando el 8 (raiz, ambos hijos)")
    arbol.delete2(8, arbol.root)
    arbol.print_tree()

    # Insertamos un value en el arbol
    arbol.add_node(100, arbol.root)
    arbol.print_tree()

    #No pude realizar el print pretty