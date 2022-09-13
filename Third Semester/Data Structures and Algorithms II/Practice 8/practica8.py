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
        # Inicializamos el nodo raiz en None
        self.root = None
    # Funcion para add un nodo
    def add(self, k, nodo):
        # Si el nodo raiz no existe
        if self.root == None:
            # Se crea un nodo raiz con el value k
            self.root = node(k)

        # Si el nodo raiz existe
        else:
            # Si el value es menor que el value del nodo raiz, se inserta en el subarbol leftuierdo
            if k < nodo.value:
                # Si el nodo leftuierdo es None (no tiene hijos)
                if nodo.left == None:
                    # Insertamos el value en el nodo leftuierdo
                    nodo.left = node(k)
                # Si el nodo leftuierdo tiene hijos
                else:
                    # Llamamos recursivamente a la funcion con el nodo leftuierdo
                    self.add(k, nodo.left)
            # Si el value es mayor que el value del nodo raiz, se inserta en el subarbol rightecho
            elif k > nodo.value:
                # Si el nodo rightecho es None (no tiene hijos)
                if nodo.right == None:
                    # Insertamos el value en el nodo rightecho
                    nodo.right = node(k)
                #Si el nodo rightecho tiene hijos
                else:
                    # Llamamos recursivamente a la funcion con el nodo rightecho
                    self.add(k, nodo.right)

            # Si el value ya existe en el arbol
            elif k == nodo.value:
                print(f"ERROR, El value {k} ya se encuentra en el arbol")

    # Funcion para print_tree el arbol por el metodo InOrden
    def InOrden(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Llamamos recursivamente a la funcion con el nodo leftuierdo hasta que sea None
            self.InOrden(nodo.left)
            # Imprimimos el value del nodo
            print(nodo.value, end=" ")
            # Llamamos recursivamente a la funcion con el nodo rightecho
            self.InOrden(nodo.right)

    # Funcion para print_tree el arbol por el metodo PreOrden
    def PreOrden(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Imprimimos el value del nodo
            print(nodo.value, end=" ")
            # Llamamos recursivamente a la funcion con el nodo leftuierdo
            self.PreOrden(nodo.left)
            # Llamamos recursivamente a la funcion con el nodo rightecho
            self.PreOrden(nodo.right)

    # Funcion para print_tree el arbol por el metodo PostOrden
    def PostOrden(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Llamamos recursivamente a la funcion con el nodo leftuierdo
            self.PostOrden(nodo.left)
            # Llamamos recursivamente a la funcion con el nodo rightecho
            self.PostOrden(nodo.right)
            # Imprimimos el value del nodo
            print(nodo.value, end=" ")

    # Funcion para search un value en el arbol
    def search(self, k, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Si el value es menor que el value del nodo raiz
            if k < nodo.value:
                # Llamamos recursivamente a la funcion con el nodo leftuierdo
                self.search(k, nodo.left)
            # Si el value es mayor que el value del nodo raiz
            elif k > nodo.value:
                # Llamamos recursivamente a la funcion con el nodo rightecho
                self.search(k, nodo.right)
            # Si el value es igual que el value del nodo raiz
            elif k == nodo.value:
                print("Existe el " + str(k),"? True")
        # No existe el nodo
        else:
            print("Existe el " + str(k),"? False")

    # Funcion para eliminar un nodo
    def delete2(self, k, nodo):
        # Se guarda en un arreglo los node recorridos en el arbol
        node_recorridos =[nodo]
        # Mientras el nodo sea distinto a None
        while nodo != None:
            # Si el value es menor que el value del nodo raiz
            if k < nodo.value:
                # El nodo leftuierdo es el nodo actual
                nodo = nodo.left
                # Se agrega al arreglo el nodo actual
                node_recorridos.append(nodo)
            # Si el value es mayor que el value del nodo raiz
            elif k > nodo.value:
                # El nodo rightecho es el nodo actual
                nodo = nodo.right
                # Se agrega al arreglo el nodo actual
                node_recorridos.append(nodo)
            # Si el value es igual que el value del nodo raiz
            elif k == nodo.value:
                # Si el nodo tiene hijos
                if nodo.left != None and nodo.right != None:
                    # Se obtiene el value maximum en el subarbol leftuierdo
                    value_max = self.maximum(nodo.left)
                    # Se elimina el value maximum en el subarbol leftuierdo
                    self.delete2(value_max,nodo)
                    # Se actualiza el value del nodo actual
                    nodo.value = value_max

                # Si el nodo no tiene hijos
                elif nodo.left == None and nodo.right == None:
                    # Se obtiene el penultimo nodo recorrido
                    nuevo_nodo = node_recorridos[-2]
                    # Si el penultimo nodo tiene hijo leftuierdo y es el nodo actual
                    if nuevo_nodo.left != None  and nuevo_nodo.left.value == nodo.value:
                        # El penultimo nodo deja de hacer referencia al nodo actual
                        nuevo_nodo.left = None
                    # Si el penultimo nodo tiene hijo rightecho y es el nodo actual
                    else:
                        # El penultimo nodo deja de hacer referencia al nodo actual
                        nuevo_nodo.right = None
                    # EL nodo actual es eliminado
                    nodo = None
                # Tiene hijo leftuierdo
                elif nodo.left != None:
                    # Se obtiene el penultimo nodo recorrido
                    nuevo_nodo = node_recorridos[-2]
                    # Si el penultimo nodo tiene hijo leftuierdo y es el nodo actual
                    if nuevo_nodo.left != None and nuevo_nodo.left.value == nodo.value:
                        # El hijo leftuierdo del penultimo nodo hará referencia al hijo leftuierdo del nodo actual
                        nuevo_nodo.left = nodo.left
                    else:
                        # El hijo rightecho del penultimo nodo hará referencia al hijo leftuierdo del nodo actual
                        nuevo_nodo.right = nodo.left
                # Tiene hijo rightecho
                elif nodo.right != None:
                    # Se obtiene el penultimo nodo recorrido
                    nuevo_nodo = node_recorridos[-2]
                    # Si el penultimo nodo tiene hijo rightecho y es el nodo actual
                    if nuevo_nodo.left != None and nuevo_nodo.left.value == nodo.value:
                        # El hijo leftuierdo del penultimo nodo hará referencia al hijo rightecho del nodo actual
                        nuevo_nodo.left = nodo.right
                    else:
                        # El hijo rightecho del penultimo nodo hará referencia al hijo rightecho del nodo actual
                        nuevo_nodo.right = nodo.right
                break
            else:
                print("\nNo se pudo eliminar el value " + str(k), " porque no existe")

    # Obtiene el value maximum del arbol
    def minimum(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Si el nodo tiene hijo leftuierdo
            if nodo.left != None:
                # Llamamos recursivamente a la funcion con el nodo leftuierdo
                return self.minimum(nodo.left)
            # Si el nodo no tiene hijo leftuierdo
            else:
                # Retornamos el value del nodo
                return nodo.value
        else:
            return None

    # Obtiene el value minimum del arbol
    def maximum(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Si el nodo tiene hijo rightecho
            if nodo.right != None:
                # Llamamos recursivamente a la funcion con el nodo rightecho
                return self.maximum(nodo.right)
            # Si el nodo no tiene hijo rightecho
            else:
                # Retornamos el value del nodo
                return nodo.value
        else:
            return None

    # Imprime el contenido del arbol
    def print_tree(self):
        print("\n*Imprimiendo el arbol*")
        # Si el nodo raiz no es None (existe)
        if self.root != None:
            # Imprime el contenido del arbol a traves del metodo pre orden
            print(" -PreOrden: ", end=" ")
            self.PreOrden(self.root)
            print()
            # Imprime el contenido del arbol a traves del metodo in orden
            print(" -InOrden: ",end=" ")
            self.InOrden(self.root)
            print()
            # Imprime el contenido del arbol a traves del metodo post orden
            print(" -PostOrden",end=" ")
            self.PostOrden(self.root)
            print()
            # Imprime el contenido del arbol a traves del metodo de anchura
            print(" -Anchura",end=" ")
            self.Anchura(self.root)
            # Llamamos a la funcion con el nodo raiz
            print()
        # Si el nodo raiz no existe (arbol vacio)
        else:
            print("El arbol esta vacio")

    # Funcion para recorrer el arbol por niveles
    def Anchura(self, nodo):
        if nodo !=None:
            # Creamos una cola
            cola = []
            # Agregamos el nodo raiz a la cola
            cola.append(nodo)
            # Mientras la cola no este vacia
            while len(cola) > 0:
                # Sacamos el primer elemento de la cola
                nodo = cola.pop(0)
                # Imprimimos el value del nodo
                print(nodo.value, end=" ")
                # Si el nodo tiene hijo leftuierdo
                if nodo.left != None:
                    # Agregamos el hijo leftuierdo a la cola
                    cola.append(nodo.left)
                # Si el nodo no tiene hijo leftuierdo
                if nodo.right != None:
                    # Agregamos el hijo rightecho a la cola
                    cola.append(nodo.right)

# Funcion main
if __name__ == '__main__':
    # Creamos un arbol
    arbol = BTree()

    # Insertamos node
    arbol.print_tree()

    # Insertamos node
    arbol.add(8, arbol.root)
    arbol.add(3, arbol.root)
    arbol.add(10, arbol.root)
    arbol.add(1, arbol.root)
    arbol.add(6, arbol.root)
    arbol.add(14, arbol.root)
    arbol.add(4, arbol.root)
    arbol.add(7, arbol.root)
    arbol.add(13, arbol.root)

    # Imprimimos el arbol
    arbol.print_tree()

    # Inserta valuees repetidos
    print("\n")
    arbol.add(14, arbol.root) # value repetido
    arbol.add(1, arbol.root) # valuedo repetido
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
    arbol.add(100, arbol.root)
    arbol.print_tree()

    #No pude realizar el print pretty