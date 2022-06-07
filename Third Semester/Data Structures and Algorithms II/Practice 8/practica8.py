# Nodo con valor e hijos
class Nodos:
    # Constructor
    def __init__(self, val):
        self.valor = val
        self.izq = None
        self.der = None

# Arbol B
class ArbolB:
    # Constructor
    def __init__(self):
        # Inicializamos el nodo raiz en None
        self.root = None
    # Funcion para insertar un nodo
    def Insertar(self, k, nodo):
        # Si el nodo raiz no existe
        if self.root == None:
            # Se crea un nodo raiz con el valor k
            self.root = Nodos(k)

        # Si el nodo raiz existe
        else:
            # Si el valor es menor que el valor del nodo raiz, se inserta en el subarbol izquierdo
            if k < nodo.valor:
                # Si el nodo izquierdo es None (no tiene hijos)
                if nodo.izq == None:
                    # Insertamos el valor en el nodo izquierdo
                    nodo.izq = Nodos(k)
                # Si el nodo izquierdo tiene hijos
                else:
                    # Llamamos recursivamente a la funcion con el nodo izquierdo
                    self.Insertar(k, nodo.izq)
            # Si el valor es mayor que el valor del nodo raiz, se inserta en el subarbol derecho
            elif k > nodo.valor:
                # Si el nodo derecho es None (no tiene hijos)
                if nodo.der == None:
                    # Insertamos el valor en el nodo derecho
                    nodo.der = Nodos(k)
                #Si el nodo derecho tiene hijos
                else:
                    # Llamamos recursivamente a la funcion con el nodo derecho
                    self.Insertar(k, nodo.der)

            # Si el valor ya existe en el arbol
            elif k == nodo.valor:
                print(f"ERROR, El valor {k} ya se encuentra en el arbol")

    # Funcion para imprimir el arbol por el metodo InOrden
    def InOrden(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Llamamos recursivamente a la funcion con el nodo izquierdo hasta que sea None
            self.InOrden(nodo.izq)
            # Imprimimos el valor del nodo
            print(nodo.valor, end=" ")
            # Llamamos recursivamente a la funcion con el nodo derecho
            self.InOrden(nodo.der)

    # Funcion para imprimir el arbol por el metodo PreOrden
    def PreOrden(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Imprimimos el valor del nodo
            print(nodo.valor, end=" ")
            # Llamamos recursivamente a la funcion con el nodo izquierdo
            self.PreOrden(nodo.izq)
            # Llamamos recursivamente a la funcion con el nodo derecho
            self.PreOrden(nodo.der)

    # Funcion para imprimir el arbol por el metodo PostOrden
    def PostOrden(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Llamamos recursivamente a la funcion con el nodo izquierdo
            self.PostOrden(nodo.izq)
            # Llamamos recursivamente a la funcion con el nodo derecho
            self.PostOrden(nodo.der)
            # Imprimimos el valor del nodo
            print(nodo.valor, end=" ")

    # Funcion para buscar un valor en el arbol
    def Buscar(self, k, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Si el valor es menor que el valor del nodo raiz
            if k < nodo.valor:
                # Llamamos recursivamente a la funcion con el nodo izquierdo
                self.Buscar(k, nodo.izq)
            # Si el valor es mayor que el valor del nodo raiz
            elif k > nodo.valor:
                # Llamamos recursivamente a la funcion con el nodo derecho
                self.Buscar(k, nodo.der)
            # Si el valor es igual que el valor del nodo raiz
            elif k == nodo.valor:
                print("Existe el " + str(k),"? True")
        # No existe el nodo
        else:
            print("Existe el " + str(k),"? False")

    # Funcion para eliminar un nodo
    def eliminar2(self, k, nodo):
        # Se guarda en un arreglo los nodos recorridos en el arbol
        nodos_recorridos =[nodo]
        # Mientras el nodo sea distinto a None
        while nodo != None:
            # Si el valor es menor que el valor del nodo raiz
            if k < nodo.valor:
                # El nodo izquierdo es el nodo actual
                nodo = nodo.izq
                # Se agrega al arreglo el nodo actual
                nodos_recorridos.append(nodo)
            # Si el valor es mayor que el valor del nodo raiz
            elif k > nodo.valor:
                # El nodo derecho es el nodo actual
                nodo = nodo.der
                # Se agrega al arreglo el nodo actual
                nodos_recorridos.append(nodo)
            # Si el valor es igual que el valor del nodo raiz
            elif k == nodo.valor:
                # Si el nodo tiene hijos
                if nodo.izq != None and nodo.der != None:
                    # Se obtiene el valor maximo en el subarbol izquierdo
                    valor_max = self.Maximo(nodo.izq)
                    # Se elimina el valor maximo en el subarbol izquierdo
                    self.eliminar2(valor_max,nodo)
                    # Se actualiza el valor del nodo actual
                    nodo.valor = valor_max

                # Si el nodo no tiene hijos
                elif nodo.izq == None and nodo.der == None:
                    # Se obtiene el penultimo nodo recorrido
                    nuevo_nodo = nodos_recorridos[-2]
                    # Si el penultimo nodo tiene hijo izquierdo y es el nodo actual
                    if nuevo_nodo.izq != None  and nuevo_nodo.izq.valor == nodo.valor:
                        # El penultimo nodo deja de hacer referencia al nodo actual
                        nuevo_nodo.izq = None
                    # Si el penultimo nodo tiene hijo derecho y es el nodo actual
                    else:
                        # El penultimo nodo deja de hacer referencia al nodo actual
                        nuevo_nodo.der = None
                    # EL nodo actual es eliminado
                    nodo = None
                # Tiene hijo izquierdo
                elif nodo.izq != None:
                    # Se obtiene el penultimo nodo recorrido
                    nuevo_nodo = nodos_recorridos[-2]
                    # Si el penultimo nodo tiene hijo izquierdo y es el nodo actual
                    if nuevo_nodo.izq != None and nuevo_nodo.izq.valor == nodo.valor:
                        # El hijo izquierdo del penultimo nodo hará referencia al hijo izquierdo del nodo actual
                        nuevo_nodo.izq = nodo.izq
                    else:
                        # El hijo derecho del penultimo nodo hará referencia al hijo izquierdo del nodo actual
                        nuevo_nodo.der = nodo.izq
                # Tiene hijo derecho
                elif nodo.der != None:
                    # Se obtiene el penultimo nodo recorrido
                    nuevo_nodo = nodos_recorridos[-2]
                    # Si el penultimo nodo tiene hijo derecho y es el nodo actual
                    if nuevo_nodo.izq != None and nuevo_nodo.izq.valor == nodo.valor:
                        # El hijo izquierdo del penultimo nodo hará referencia al hijo derecho del nodo actual
                        nuevo_nodo.izq = nodo.der
                    else:
                        # El hijo derecho del penultimo nodo hará referencia al hijo derecho del nodo actual
                        nuevo_nodo.der = nodo.der
                break
            else:
                print("\nNo se pudo eliminar el valor " + str(k), " porque no existe")

    # Obtiene el valor maximo del arbol
    def Minimo(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Si el nodo tiene hijo izquierdo
            if nodo.izq != None:
                # Llamamos recursivamente a la funcion con el nodo izquierdo
                return self.Minimo(nodo.izq)
            # Si el nodo no tiene hijo izquierdo
            else:
                # Retornamos el valor del nodo
                return nodo.valor
        else:
            return None

    # Obtiene el valor minimo del arbol
    def Maximo(self, nodo):
        # Si el nodo no es None
        if nodo != None:
            # Si el nodo tiene hijo derecho
            if nodo.der != None:
                # Llamamos recursivamente a la funcion con el nodo derecho
                return self.Maximo(nodo.der)
            # Si el nodo no tiene hijo derecho
            else:
                # Retornamos el valor del nodo
                return nodo.valor
        else:
            return None

    # Imprime el contenido del arbol
    def Imprimir(self):
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
                # Imprimimos el valor del nodo
                print(nodo.valor, end=" ")
                # Si el nodo tiene hijo izquierdo
                if nodo.izq != None:
                    # Agregamos el hijo izquierdo a la cola
                    cola.append(nodo.izq)
                # Si el nodo no tiene hijo izquierdo
                if nodo.der != None:
                    # Agregamos el hijo derecho a la cola
                    cola.append(nodo.der)

# Funcion main
if __name__ == '__main__':
    # Creamos un arbol
    arbol = ArbolB()

    # Insertamos nodos
    arbol.Imprimir()

    # Insertamos nodos
    arbol.Insertar(8, arbol.root)
    arbol.Insertar(3, arbol.root)
    arbol.Insertar(10, arbol.root)
    arbol.Insertar(1, arbol.root)
    arbol.Insertar(6, arbol.root)
    arbol.Insertar(14, arbol.root)
    arbol.Insertar(4, arbol.root)
    arbol.Insertar(7, arbol.root)
    arbol.Insertar(13, arbol.root)

    # Imprimimos el arbol
    arbol.Imprimir()

    # Inserta valores repetidos
    print("\n")
    arbol.Insertar(14, arbol.root) # Valor repetido
    arbol.Insertar(1, arbol.root) # Valordo repetido
    print("\n")

    # Obtenemos el maximo y minimo del arbol
    print("**Metodo maximo y minimo**")
    print("\nEl valor minimo es: ",arbol.Minimo(arbol.root))
    print("El valor maximo es: ",arbol.Maximo(arbol.root))
    print()

    # Buscamos un valor en el arbol
    print("\n**Metodo buscar**\n")
    arbol.Buscar(4,arbol.root)
    arbol.Buscar(8,arbol.root)
    arbol.Buscar(13,arbol.root)
    arbol.Buscar(2,arbol.root)
    arbol.Buscar(15,arbol.root)

    # Eliminamos un valor del arbol
    print("\n**Metodo elimniar**\n")

    print("\n  -Borrando el 7 (sin hijos)")
    arbol.eliminar2(7, arbol.root)
    arbol.Imprimir()

    print("\n  -Borrando el 10 (con hijo derecho)")
    arbol.eliminar2(10, arbol.root)
    arbol.Imprimir()

    print("\n  -Borrando el 6 (con hijo izquierdo)")
    arbol.eliminar2(6, arbol.root)
    arbol.Imprimir()

    print("\n  -Borrando el 3 (con ambos hijos)")
    arbol.eliminar2(3, arbol.root)
    arbol.Imprimir()

    print("\n  -Borrando el 3 (no existe)")
    arbol.eliminar2(3, arbol.root)
    arbol.Imprimir()

    print("\n  -Borrando el 8 (raiz, ambos hijos)")
    arbol.eliminar2(8, arbol.root)
    arbol.Imprimir()

    # Insertamos un valor en el arbol
    arbol.Insertar(100, arbol.root)
    arbol.Imprimir()

    #No pude realizar el print pretty