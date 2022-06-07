##################################
# @author: Edwin Santiago
# Se implementan los 3 algoritmos (BubbleSort, BubbleSortOptimizado y MergeSort)
# Con una lista de n números aleatorios del -100 al 100
# Y se mide el tiempo que tarda cada algoritmo
##################################

# Se importa de la libreria "time" la funcion "perf_counter"
# para calcular el tiempo que tardan en ordenar cada algoritmo
from time import perf_counter
# La libreria random es para esocger numeros aleatorios de un rango dado
import random

# Algoritmo BubbleSort
# Recibe como parametro el arreglo de n numeros
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

#* Caso Promedio
def casoPromedio(promedio1, promedio2, promedio3):

    #! Algoritmo 1
    # Se inicializa el cronómetro
    tiempoInicial1 = perf_counter()
    # Se ejecuta el algoritmo
    bubbleSort(promedio1)
    # Se detiene el cronómetro
    tiempoFinal1 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo1 = tiempoFinal1 - tiempoInicial1

    #! Algoritmo 2
    # Se inicializa el cronómetro
    tiempoInicial2 = perf_counter()
    # Se ejecuta el algoritmo
    bubbleSortOptimizado(promedio2)
    # Se detiene el cronómetro
    tiempoFinal2 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo2 = tiempoFinal2 - tiempoInicial2

    #! Algoritmo 3
    # Se inicializa el cronómetro
    tiempoInicial3 = perf_counter()
    # Se ejecuta el algoritmo
    mergeSort(promedio3,0,len(promedio3)-1)
    # Se detiene el cronómetro
    tiempoFinal3 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo3 = tiempoFinal3 - tiempoInicial3

    # Imprime los tiempos de cada algoritmo con 12 decimales
    print('\n¡Caso Promedio!')
    print('Tiempo BubbleSort : {:.12f}'.format(tiempo1))
    print('Tiempo BubbleSortOptimizado : {:.12f}'.format(tiempo2))
    print('Tiempo MergeSort : {:.12f}'.format(tiempo3))
    print("\n")

#* Mejor caso
def mejorCaso(mejor1, mejor2, mejor3):

    #! Algoritmo 1
    # Se inicializa el cronómetro
    tiempoInicial1 = perf_counter()
    # Se ejecuta el algoritmo
    bubbleSort(mejor1)
    # Se detiene el cronómetro
    tiempoFinal1 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo1 = tiempoFinal1 - tiempoInicial1

    #! Algoritmo 2
    # Se inicializa el cronómetro
    tiempoInicial2 = perf_counter()
    # Se ejecuta el algoritmo
    bubbleSortOptimizado(mejor2)
    # Se detiene el cronómetro
    tiempoFinal2 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo2 = tiempoFinal2 - tiempoInicial2

    #! Algoritmo 3
    # Se inicializa el cronómetro
    tiempoInicial3 = perf_counter()
    # Se ejecuta el algoritmo
    mergeSort(mejor3,0,len(mejor3)-1)
    # Se detiene el cronómetro
    tiempoFinal3 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo3 = tiempoFinal3 - tiempoInicial3

    # Imprime los tiempos de cada algoritmo con 12 decimales
    print('\n¡Mejor de los casos!')
    print('Tiempo BubbleSort : {:.12f}'.format(tiempo1))
    print('Tiempo BubbleSortOptimizado : {:.12f}'.format(tiempo2))
    print('Tiempo MergeSort : {:.12f}'.format(tiempo3))
    print("\n")

#* Peor de los casos
def peorCaso(peor1,peor2,peor3):

    #! Algoritmo 1
    # Se inicializa el cronómetro
    tiempoInicial1 = perf_counter()
    # Se ejecuta el algoritmo
    bubbleSort(peor1)
    # Se detiene el cronómetro
    tiempoFinal1 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo1 = tiempoFinal1 - tiempoInicial1

    #! Algoritmo 2
    # Se inicializa el cronómetro
    tiempoInicial2 = perf_counter()
    # Se ejecuta el algoritmo
    bubbleSortOptimizado(peor2)
    # Se detiene el cronómetro
    tiempoFinal2 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo2 = tiempoFinal2 - tiempoInicial2

    #! Algoritmo 3
    # Se inicializa el cronómetro
    tiempoInicial3 = perf_counter()
    # Se ejecuta el algoritmo
    mergeSort(peor3,0,len(peor3)-1)
    # Se detiene el cronómetro
    tiempoFinal3 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo3 = tiempoFinal3 - tiempoInicial3

    print('\n¡Peor de los casos!')
    # Imprime los tiempos de cada algoritmo con 12 decimales
    print('Tiempo BubbleSort : {:.12f}'.format(tiempo1))
    print('Tiempo BubbleSortOptimizado : {:.12f}'.format(tiempo2))
    print('Tiempo MergeSort : {:.12f}'.format(tiempo3))
    print("\n")

def run():
    # Genera una lista con valores del -100 al 100 del tamaño "n"
    n = 2000000
    a = []
    for i in range (n):
        a.append(random.randint(-100,100))
    # Copia la lista generada 3 veces para ser utilziadas en cada algoritmo.
    a1 = a[:]
    a2 = a[:]
    a3 = a[:]

    print("\nNumero de datos: ", n)
    # Ejecuta los casos promedio con los arreglos desordenados aleatoriamente
    casoPromedio(a1,a2,a3)
    # Ejecuta los mejores casos con los arreglos ordenados ascendientemente
    mejorCaso(a1,a2,a3)
    # A cada arreglo ordenado cambia de ser ascendiente a descendente
    a1.reverse()
    a2.reverse()
    a3.reverse()
    # Ejecuta los peores casos con los arreglos ordenados descendientemente
    peorCaso(a1,a2, a3)

if __name__ == '__main__':
    # Aqui inicia la ejecucion del programa
    run()
