import random

class Node:
    # Constructor
    def __init__(self, t):
        # Grado del tree
        self.t = t
        # Elementos/llaves/valores del nodo
        self.llaves = [None] * (2 * t - 1) # El nodo puede tener varios valores (llamados llaves)
        # Hijos del nodo
        self.hijos = [None] * (2 * t) # El nodo puede tener varios hijos (entre 0 y 2t-1)
        # Numero de llaves/valores del nodo
        self.n = 0
        # Indica si el nodo esta hoja o no (si tiene hijos o no)
        self.hoja = True

    # Revisa si el nodo esta lleno
    def is_full(self):
        # Si el nodo tiene el numero de llaves que puede tener, esta lleno
        return self.n == 2*self.t - 1

# Clase tree B
class tree_B:
    # Constructor
    def __init__(self,t):
        # Grado del tree
        self.t = t
        # Raiz del tree, nodo raiz
        self.root = Node(t)

    #Inserta un nuevo valor en el tree
    def insert(self, k):
        # Obtenemos la raiz
        r = self.root
        # Si el nodo raiz esta lleno
        if r.is_full():
            # Se crea un nuevo nodo raiz
            s = Node(self.t)
            # Se le asigna que no es hoja, porque tendra nodos hijos
            s.hoja = False
            # Se le asigna el numero de llaves existentes
            s.n = 0
            # El primer valor del nuevo nodo raiz se inserta el nodo raiz
            s.hijos[0] = r
            # Se asigna el nuevo nodo raiz
            self.root = s
            # Recibe el nodo raiz y el indice que se quiere partir
            self.split_child(s,0)
            # Se inserta el nuevo valor en el tree
            self.insert_non_full(s,k)
        # Si el nodo raiz no esta lleno
        else:
            # Se inserta el nuevo valor en el tree
            self.insert_non_full(r,k)

    # Parte el nodo en dos
    def split_child(self, x, i):
        z = Node(self.t)
        y = x.hijos[i]
        z.hoja = y.hoja
        z.n = self.t - 1

        # Recorre las llaves
        for j in range(0,self.t-1):
            z.llaves[j] = y.llaves[j+self.t]
            y.llaves[j+self.t] = None

        # Recorre los hijos
        if not y.hoja:
            for j in range(0,self.t):
                z.hijos[j] = y.hijos[j+self.t]
                y.hijos[j+self.t] = None

        y.n=self.t-1
        # Recorrer los hijos del padre
        for j in range(x.n,i-1,-1):
            x.hijos[j+1] = x.hijos[j]
        # Sube como hijo
        x.hijos[i+1] = z
        # Se reocrren las llaves para hacer espacio para la mediana
        for j in range(x.n-1,i-1,-1):
            x.llaves[j+1] = x.llaves[j]

        x.llaves[i] = y.llaves[self.t-1]
        y.llaves[self.t-1] = None
        x.n += 1

    # Inserta un nuevo valor en el tree si el nodo no esta lleno
    def insert_non_full(self, x, k): # Revisado
        # Indice de la ultima llave
        i = x.n-1
        if x.hoja:
            # Se recorren las llaves para hacer espacio
            while i>=0 and k<x.llaves[i]:
                x.llaves[i+1] = x.llaves[i]
                i -= 1
            # Se ingresa la llave K en el indice i donde se hizo espacio
            x.llaves[i+1] = k
            # Se aumenta el numero de llaves
            x.n += 1
        else:
            # search el lugar donde le corresponde
            while i>=0 and k<x.llaves[i]:
                i -= 1
            i += 1
            if x.hijos[i].is_full():
                # Se parte el nodo
                self.split_child(x,i)
                if k>x.llaves[i]:
                    i += 1
            # Se llama recursivamente
            self.insert_non_full(x.hijos[i],k)

    # Busca un elemento/llave/valor en el tree
    def search(self, x, k):
        i = 0
        # Se recorren las llaves para encontrar el valor
        while i<x.n and k>x.llaves[i]:
            i += 1
        # Si la llave es igual a la llave del nodo
        if i<x.n and k==x.llaves[i]:
            # Regresa True
            return True
        # Si el nodo es hoja
        if x.hoja:
            # Regresa False
            return False
        # Si el nodo no es hoja
        else:
            # Regresa el resultado de la busqueda
            return self.search(x.hijos[i],k)

    # Imprime el contenido del tree
    def print_tree(self, nodo):
        print("\n**Metodo print_tree**")
        # Si el nodo no esta vacion
        if nodo.n != 0:
            # Se imprime en In Orden
            print("\n  -In Orden: ", end="")
            self.in_order(nodo)
            # Se imprime en Pre Orden
            print("\n  -Pre Orden: ", end="")
            self.pre_order(nodo)
        # El tree está vacio
        else:
            print("\n -El tree esta vacio")

    # Recorre el tree en inorden
    def in_order(self, nodo):
        # Si el nodo no esta vacio
        if nodo is not None:
            # Se recorre las llaves del nodo
            for i in range(nodo.n):
                # Se llama recursivamente a la funcion con el hijo "izquierdo"
                self.in_order(nodo.hijos[i])
                # Se imprime la llave
                print(nodo.llaves[i], end=" ")
                # Se llama recursivamente a la funcion con el hijo "derecho"
                self.in_order(nodo.hijos[i+1])

    # Recorre el tree en preorden
    def pre_order(self, nodo):
        # Si el nodo no esta vacio
        if nodo is not None:
            # Se recorren las llaves del nodo
            for i in range(nodo.n):
                # Se imprime la llave
                print(nodo.llaves[i], end=" ")
                # Se llama recursivamente con el hijo "izquierdo"
                self.pre_order(nodo.hijos[i])
                # Se llama recursivamente con el hijo "derecho"
                self.pre_order(nodo.hijos[i+1])

    # Metodo para clean_tree el tree
    def clean_tree(self):
        # Cambiar el valor de la raiz por un nodo vacio
        self.root = Node(self.t)

# Main
if __name__ == '__main__':
    # Se instancia un objeto de la clase tree_B con grado 2
    tree = tree_B(2)

    # Se imprime el tree (vacio)
    tree.print_tree(tree.root)

    # Se insertan los valores
    tree.insert(3)
    tree.insert(1)
    tree.insert(4)
    tree.insert(2)
    tree.insert(5)
    tree.insert(7)
    tree.insert(6)
    tree.insert(11)
    tree.insert(15)
    tree.insert(22)
    tree.insert(35)
    tree.insert(21)

    # Se imprime el tree
    tree.print_tree(tree.root)

    # Se busca un valor en el tree
    print("\n\n**Metodo search**\n")
    print(" -Existe el 3?", tree.search(tree.root, 3))
    print(" -Existe el 6?", tree.search(tree.root, 6))
    print(" -Existe el 15?", tree.search(tree.root, 15))
    print(" -Existe el 0?", tree.search(tree.root, 0))
    print(" -Existe el 13?", tree.search(tree.root, 13))

    # Se limpia el tree
    print("\n**Metodo clean_tree el tree**")
    tree.clean_tree()
    tree.print_tree(tree.root)

    # Se insertan los valores en otro orden
    tree.insert(15)
    tree.insert(11)
    tree.insert(5)
    tree.insert(3)
    tree.insert(4)
    tree.insert(21)
    tree.insert(7)
    tree.insert(35)
    tree.insert(6)
    tree.insert(2)
    tree.insert(1)
    tree.insert(22)

    # Se imprime el tree
    tree.print_tree(tree.root)

    # Se limpia el tree
    tree.clean_tree()

    # Se insertan valores aleatorios
    tree2 = tree_B(5)
    for i in range(1,1000):
        tree2.insert(random.randint(1,1000))

    # Se imprime el tree
    tree2.print_tree(tree2.root)