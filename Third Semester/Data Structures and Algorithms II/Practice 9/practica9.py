import random

# Clase Nodo
class Node:
    # Constructor
    def __init__(self, t):
        # Grado del arbol
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
    def Esta_Lleno(self):
        # Si el nodo tiene el numero de llaves que puede tener, esta lleno
        return self.n == 2*self.t - 1

# Clase Arbol B
class Arbol_B:
    # Constructor
    def __init__(self,t):
        # Grado del arbol
        self.t = t
        # Raiz del arbol, nodo raiz
        self.root = Node(t)

    #Inserta un nuevo valor en el arbol
    def Insertar(self, k):
        # Obtenemos la raiz
        r = self.root
        # Si el nodo raiz esta lleno
        if r.Esta_Lleno():
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
            self.Split_Child(s,0)
            # Se inserta el nuevo valor en el arbol
            self.Insert_Non_Full(s,k)
        # Si el nodo raiz no esta lleno
        else:
            # Se inserta el nuevo valor en el arbol
            self.Insert_Non_Full(r,k)

    # Parte el nodo en dos
    def Split_Child(self, x, i):
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

    # Inserta un nuevo valor en el arbol si el nodo no esta lleno
    def Insert_Non_Full(self, x, k): # Revisado
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
            # Buscar el lugar donde le corresponde
            while i>=0 and k<x.llaves[i]:
                i -= 1
            i += 1
            if x.hijos[i].Esta_Lleno():
                # Se parte el nodo
                self.Split_Child(x,i)
                if k>x.llaves[i]:
                    i += 1
            # Se llama recursivamente
            self.Insert_Non_Full(x.hijos[i],k)

    # Busca un elemento/llave/valor en el arbol
    def Buscar(self, x, k):
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
            return self.Buscar(x.hijos[i],k)

    # Imprime el contenido del arbol
    def Imprimir(self, nodo):
        print("\n**Metodo Imprimir**")
        # Si el nodo no esta vacion
        if nodo.n != 0:
            # Se imprime en In Orden
            print("\n  -In Orden: ", end="")
            self.In_Orden(nodo)
            # Se imprime en Pre Orden
            print("\n  -Pre Orden: ", end="")
            self.Pre_Orden(nodo)
        # El arbol está vacio
        else:
            print("\n -El arbol esta vacio")

    # Recorre el arbol en inorden
    def In_Orden(self, nodo):
        # Si el nodo no esta vacio
        if nodo is not None:
            # Se recorre las llaves del nodo
            for i in range(nodo.n):
                # Se llama recursivamente a la funcion con el hijo "izquierdo"
                self.In_Orden(nodo.hijos[i])
                # Se imprime la llave
                print(nodo.llaves[i], end=" ")
                # Se llama recursivamente a la funcion con el hijo "derecho"
                self.In_Orden(nodo.hijos[i+1])

    # Recorre el arbol en preorden
    def Pre_Orden(self, nodo):
        # Si el nodo no esta vacio
        if nodo is not None:
            # Se recorren las llaves del nodo
            for i in range(nodo.n):
                # Se imprime la llave
                print(nodo.llaves[i], end=" ")
                # Se llama recursivamente con el hijo "izquierdo"
                self.Pre_Orden(nodo.hijos[i])
                # Se llama recursivamente con el hijo "derecho"
                self.Pre_Orden(nodo.hijos[i+1])

    # Metodo para limpiar el arbol
    def Limpiar(self):
        # Cambiar el valor de la raiz por un nodo vacio
        self.root = Node(self.t)

# Main
if __name__ == '__main__':
    # Se instancia un objeto de la clase Arbol_B con grado 2
    arbol = Arbol_B(2)

    # Se imprime el arbol (vacio)
    arbol.Imprimir(arbol.root)

    # Se insertan los valores
    arbol.Insertar(3)
    arbol.Insertar(1)
    arbol.Insertar(4)
    arbol.Insertar(2)
    arbol.Insertar(5)
    arbol.Insertar(7)
    arbol.Insertar(6)
    arbol.Insertar(11)
    arbol.Insertar(15)
    arbol.Insertar(22)
    arbol.Insertar(35)
    arbol.Insertar(21)

    # Se imprime el arbol
    arbol.Imprimir(arbol.root)

    # Se busca un valor en el arbol
    print("\n\n**Metodo Buscar**\n")
    print(" -Existe el 3?", arbol.Buscar(arbol.root, 3))
    print(" -Existe el 6?", arbol.Buscar(arbol.root, 6))
    print(" -Existe el 15?", arbol.Buscar(arbol.root, 15))
    print(" -Existe el 0?", arbol.Buscar(arbol.root, 0))
    print(" -Existe el 13?", arbol.Buscar(arbol.root, 13))

    # Se limpia el arbol
    print("\n**Metodo Limpiar el arbol**")
    arbol.Limpiar()
    arbol.Imprimir(arbol.root)

    # Se insertan los valores en otro orden
    arbol.Insertar(15)
    arbol.Insertar(11)
    arbol.Insertar(5)
    arbol.Insertar(3)
    arbol.Insertar(4)
    arbol.Insertar(21)
    arbol.Insertar(7)
    arbol.Insertar(35)
    arbol.Insertar(6)
    arbol.Insertar(2)
    arbol.Insertar(1)
    arbol.Insertar(22)

    # Se imprime el arbol
    arbol.Imprimir(arbol.root)

    # Se limpia el arbol
    arbol.Limpiar()

    # Se insertan valores aleatorios
    arbol2 = Arbol_B(5)
    for i in range(1,1000):
        arbol2.Insertar(random.randint(1,1000))

    # Se imprime el arbol
    arbol2.Imprimir(arbol2.root)