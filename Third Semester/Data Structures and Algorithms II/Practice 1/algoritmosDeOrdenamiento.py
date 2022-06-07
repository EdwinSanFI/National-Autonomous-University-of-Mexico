##################################
# @author: Edwin Santiago
# Se implementan los 3 algoritmos (BubbleSort, BubbleSortOptimizado y MergeSort)
# Con una lista de 10 números aleatorios del 0 al 10
##################################

# Se importa de la libreria "time" la funcion "perf_counter"
# para calcular el tiempo que tardan en ordenar cada algoritmo
from time import perf_counter

# Algoritmo BubbleSort
# Recibe como parametro el arreglo de 10 numeros
def bubbleSort(arr):
    # Se obtiene el tamaño del arreglo
    n = len(arr)
    # Se recorre el arreglo, esto es para repetir las instrucciones siguientes
    # Y ordenar el arreglo
    for i in range(n-1):
        # Se vuelve a recorrer el arreglo
        for j in range(n - i - 1):
            # Si la posicion siguiente de la actual es menor
            if arr[j] > arr[j+1]:
                # Estos cambian de posicion
                    arr[j], arr[j+1] = arr[j+1], arr[j]

# Algoritmo BubbleSortOptimizado
# Recibe como parametro el arreglo de 10 numeros
def bubbleSortOptimizado(arr):
    # Se calcula el tamaño del arreglo
    n = len(arr)
    # Se inicializan valores
    i = 0
    ordenado = False
    # La sentencia while evita que se hagan instrucciones demas
    # Como lo hae el algoritmo BubbleSort
    while (i < n and ordenado == False):
        i += 1
        ordenado = True
        # Recorrera la lista completa
        for j in range(n - i):
            # Si la posicion siguiente de la actual es menor
            if arr[j] > arr[j+1]:
                ordenado = False
                # Estos cambian de posicion
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Algoritmo MergeSort
# Recibe el arreglo, el indice incial y el indice final
def mergeSort(arr, p, r):
    # Al ser un algoritmo recursivo, se revisa que el arreglo
    # Tenga mas de 1 valor con la posicion inicial y final
    if p < r:
        # Se parte en dos el arrelgo
        q = int((p+r)/2)
        # Se llama a si misma con la mitad izquierda del arreglo
        mergeSort(arr, p, q)
        # Se llama a si misma con la mitad derecha del arreglo
        mergeSort(arr, q+1, r)
        # Una vez llegado a solo listas con 1 dato, estas se acomodan y se mezclan.
        merge(arr,p,q,r)

# Es parte del algoritmo MergeSort
# Mezcla y ordena los elementos
# Recibe los elementos, el indice incial, el de medio y el final.
def merge(arr, p, q, r):
    # Garda un valor en la variable izq
    izq = arr[p:q+1]
    # Garda un valor en la variable der
    der = arr[q+1:r+1]
    i = 0
    j = 0
    # Recorre desde el indie inicial hasta el indice final del arreglo
    for k in range(p, r+1):
        # Comprueba que valor de que variable es menor
        if (j >= r-q) or ((i<q - p+1) and (izq[i] < der[j])):
            # Si la vairable izq es menor, se asigna en el arrelgo
            arr[k] = izq[i]
            i += 1
        else:
            # Si la variable der es menor, se asigna en el arreglo
            arr[k] = der[j]
            j += 1

def run():
    #Arreglos de numeros para cada algoritmo.
    arreglo1 = [3, 5, 0, 9, 7, 4, 1, 6, 8, 2]
    arreglo2 = [3, 5, 0, 9, 7, 4, 1, 6, 8, 2]
    arreglo3 = [3, 5, 0, 9, 7, 4, 1, 6, 8, 2]

    print("La lista de numeros a ordenar es: " + str(arreglo1) + "\n")

    # Se toman los tiempos de cada algoritmo

    #! Algoritmo 1
    # Se inicializa el cronómetro
    tiempoInicial1 = perf_counter()
    # Se ejecuta el algoritmo
    bubbleSort(arreglo1)
    # Se detiene el cronómetro
    tiempoFinal1 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo1 = tiempoFinal1 - tiempoInicial1
    # Se imprimen los valores
    print('Arreglo ordenado: ', arreglo1)
    # {:.9f} es para indiciarle cuantos decimales se desea imprimir
    print("El tiempo que le tomó al algoritmo BubbleSort es de: {:.9f}\n".format(tiempo1))

    #! Algoritmo 2
    # Se inicializa el cronómetro
    tiempoInicial2 = perf_counter()
    # Se ejecuta el algoritmo
    bubbleSortOptimizado(arreglo2)
    # Se detiene el cronómetro
    tiempoFinal2 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo2 = tiempoFinal2 - tiempoInicial2
    # Se imprimen los valores
    print('Arreglo ordenado: ', arreglo2)
    #{:.9f} es para indiciarle cuantos decimales se desea imprimir
    print("El tiempo que le tomó al algoritmo BubbleSortOptimizado es de: {:.9f}\n".format(tiempo2))

    #! Algoritmo 3
    # Se inicializa el cronómetro
    tiempoInicial3 = perf_counter()
    # Se ejecuta el algoritmo
    mergeSort(arreglo3,0,9)
    # Se detiene el cronómetro
    tiempoFinal3 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo3 = tiempoFinal3 - tiempoInicial3
    # Se imprimen los valores
    print('Arreglo ordenado: ', arreglo3)
    #{:.9f} es para indiciarle cuantos decimales se desea imprimir
    print("El tiempo que le tomó al algoritmo MergeSort es de: {:.9f}\n".format(tiempo3))

if __name__ == '__main__':
    # Se imprime el numero de la practica y del ejercicio
    print('\t¡Practica 1!')
    print('\tEjercicio 2\n')
    # Se ejecuta la funcion donde ejecuta otras funciones
    run()
