##################################
# @author: Edwin Santiago
# QuickSort y HeapSort
# We are going to measure the time it takes to sort the list using QuickSort and HeapSort
##################################

# The function ranint is used to generate a random number
from random import randint
# The function "perf_counter" is use to measure the time of the algorithm
from time import perf_counter

# Algorithm: Quick Sort
# Recieves as parameter the list and the first and last index
def quickSort(a, p, r):
    # Check if the list has more than 1 element
    if p < r:
        # Divide the list and give the position of the pivot
        q = divide(a,p,r)
        # Subarray of the left part
        quickSort(a, p, q-1)
        # Subarray of the right part
        quickSort(a,q+1, r)

# The function accommodates the subarrays where both parts (left and right) are arranged according to the pivot
# Receives as parameter the list of numbers, the index of the first element and the size of the list
def divide(a, p, r):
    # Choose a random pivot
    rand = randint(p,r)
    # And exchange the value of the pivot with the last element
    # This will optimize the algorithm and can sort lists up to 20k elements
    a[rand], a[r] = a[r], a[rand]
    # The pivot is the last element of the list
    x=a[r]
    # Auxiliary variable
    i = p-1


    # Compare all the elements to know which are less and greater than the pivot
    for j in range(p,r):
        # If the element is less than the pivot, it is exchanged with the element in the left part
        if a[j] <= x:
            i+= 1
            a[i], a[j] = a[j], a[i]

    # Exchange the pivot with the element in the left part
    a[i+1], a[r] = a[r], a[i+1]
    # Return the index of the pivot
    return i+1

# Algorithm: Heap Sort
# Recieves as parameter the list
def ordenacionHeapSort(a):
    initialHeap(a)
    # The size of the heap is the size of the list
    tamañoHeap = len(a)
    # The main loop of the algorithm. It is used to swap the first element with the last element of
    # the list.
    for i in range(len(a)-1,0,-1):
        a[0], a[i] = a[i], a[0]
        tamañoHeap -=1
        maxHeapify(a,0,tamañoHeap)

# Initial heap is a MaxHeap
def initial_heap(A):
    # Creating a max heap.
    tamañoHeap = len(A)
    for i in range(len(A) // 2, -1, -1):
        maxHeapify (A, i, tamañoHeap)

def maxHeapify(A, i, tamañoHeap):
    """
    The function maxHeapify takes an array A and an index i into the array, and performs the
    "maxHeapify" operation on the subtree rooted at index i
    :param A: The array to be sorted
    :param i: The index of the node to be heapified
    :param oHeap: The array that represents the heap
    """
    
    L = 2*i +1
    R = 2*i+2

    posMax = i
    # Si A[i] es mayor o igual a la info almacenada en la raiz de sub.zq.
    # y derecho entonces el arbol con raiz en el nodo I es un HeapMaximo y la funcion termina
    # De lo contrario, la raiz de alguno subarbol es mayor a A[i] y es intercambiada con esta
    if L < tamañoHeap and A[L] > A[i]:
        posMax = L
    if R < tamañoHeap and A[R] > A[posMax]:
        posMax = R

    if posMax != i:
        # Intercambia los valores
        A[i], A[posMax] = A[posMax], A[i]
        # Permite que el heap modificado mantenga la propiedad de orden de un HeapMaximo
        #A[i] acomoda para que el arbol siga cumpliendo con que la raiz de cada subarbol es mayor o igual que sus nodos restantes
        maxHeapify(A, posMax, tamañoHeap)

def run():

    print("Practica 2")
    print("Ejercicio 2\n")

    arregloQuickSort = [7,3,1,9,2,3,5,4,6,8]
    arregloHeapSort = [7,3,1,9,2,3,5,4,6,8]

    print("Arreglo desordenado: ", arregloHeapSort)

    # Se inicializa el cronómetro
    tiempoInicial1 = perf_counter()
    # Se ejecuta el algoritmo
    ordenacionHeapSort(arregloQuickSort)
    # Se detiene el cronómetro
    tiempoFinal1 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo1 = tiempoFinal1 - tiempoInicial1

    # Se inicializa el cronómetro
    tiempoInicial2 = perf_counter()
    # Se ejecuta el algoritmo
    quickSort(arregloHeapSort,0,len(arregloHeapSort)-1)
    # Se detiene el cronómetro
    tiempoFinal2 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo2 = tiempoFinal2 - tiempoInicial2

    print("Lista ordenada por QuickSort: ", arregloQuickSort)
    print("El algoritmo tardó: {:.8f}".format(tiempo1))
    print("Lista ordenada por HeapSort: ",arregloHeapSort)
    print("El algoritmo tardó: {:.8f}".format(tiempo2))

if __name__ == '__main__':
    run()