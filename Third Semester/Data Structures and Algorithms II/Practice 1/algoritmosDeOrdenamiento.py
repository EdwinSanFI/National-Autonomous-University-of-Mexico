##################################
# @author: Edwin Santiago
# 3 Algorithms for sorting numbers
##################################

from time import perf_counter

def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n - i - 1):
            # If the next element is smaller than the current element
            if arr[j] > arr[j+1]:
                # Swap the elements
                    arr[j], arr[j+1] = arr[j+1], arr[j]

# Bubble Sort Optimized
def bubble_sort_optimized(arr):
    n = len(arr)
    i = 0
    ordenado = False
    while (i < n and ordenado == False):
        i += 1
        ordenado = True
        for j in range(n - i):
            # If the next element is smaller than the current element
            if arr[j] > arr[j+1]:
                ordenado = False
                # Swap the elements
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Merge Sort
"""
If the array has more than one element, split it into two halves, sort each half, and then merge the
two sorted halves

:param arr: The array to be sorted
:param p: the start index of the array
:param r: the last index of the array
"""
def merge_sort(arr, p, r):
    # If the array has more than one element, split it into two halves, sort each half, and then merge the two sorted halves
    if p < r:
        q = int((p+r)/2)
        # From the initial position to the middle position
        merge_sort(arr, p, q)
        # From the middle position to the final position
        merge_sort(arr, q+1, r)
        # Merge and sort the array
        merge(arr,p,q,r)

# Merge and sort the array
# Recibe los elementos, el indice incial, el de medio y el final.
def merge(arr, p, q, r):
    izq = arr[p:q+1]
    der = arr[q+1:r+1]
    i = 0
    j = 0
    # From the initial position to the final position
    for k in range(p, r+1):
        if (j >= r-q) or ((i<q - p+1) and (izq[i] < der[j])):
            # If the left element is smaller than the right element will be placed in the array
            arr[k] = izq[i]
            i += 1
        else:
            # If the right element is smaller than the left element will be placed in the array
            arr[k] = der[j]
            j += 1

def run():
    #Arreglos de numeros para cada algoritmo.
    arreglo1 = [3, 5, 0, 9, 7, 4, 1, 6, 8, 2]
    arreglo2 = [3, 5, 0, 9, 7, 4, 1, 6, 8, 2]
    arreglo3 = [3, 5, 0, 9, 7, 4, 1, 6, 8, 2]

    print("The number list is: " + str(arreglo1) + "\n")

    # Algorithm 1
    tiempoInicial1 = perf_counter()
    bubble_sort(arreglo1)
    tiempoFinal1 = perf_counter()
    tiempo1 = tiempoFinal1 - tiempoInicial1
    print('Arreglo ordenado: ', arreglo1)
    # {:.9f} es para indiciarle cuantos decimales se desea imprimir
    print("El tiempo que le tomó al algoritmo bubble_sort es de: {:.9f}\n".format(tiempo1))

    #! Algorithm 2
    tiempoInicial2 = perf_counter()
    bubble_sort_optimized(arreglo2)
    tiempoFinal2 = perf_counter()
    tiempo2 = tiempoFinal2 - tiempoInicial2
    print('Arreglo ordenado: ', arreglo2)
    #{:.9f} es para indiciarle cuantos decimales se desea imprimir
    print("El tiempo que le tomó al algoritmo bubble_sort_optimized es de: {:.9f}\n".format(tiempo2))

    #! Algorithm 3
    tiempoInicial3 = perf_counter()
    merge_sort(arreglo3,0,9)
    tiempoFinal3 = perf_counter()
    tiempo3 = tiempoFinal3 - tiempoInicial3
    print('Arreglo ordenado: ', arreglo3)
    #{:.9f} es para indiciarle cuantos decimales se desea imprimir
    print("El tiempo que le tomó al algoritmo merge_sort es de: {:.9f}\n".format(tiempo3))

if __name__ == '__main__':
    run()