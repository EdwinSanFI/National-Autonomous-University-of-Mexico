##################################
# @author: Edwin Santiago
# Se implementan 2 algoritmos (QuickSort y HeapSort)
# Con una lista de n números aleatorios del -100 al 100
# Y se mide el tiempo que tarda cada algoritmo
##################################

# Se importa la libreria para cambiar el limite de recursiones permitidas
import sys
from random import randint
# El limite es de 1,000 y se cambió a 2,000
sys.setrecursionlimit(1000000)

# Se importa de la libreria "time" la funcion "perf_counter"
# para calcular el tiempo que tardan en ordenar cada algoritmo
from time import perf_counter
# La libreria random es para esocger numeros aleatorios de un rango dado
import random

# Algoritmo: Quick Sort
# Recibe como parametro la lsita de numeros, el indice del primer elemento de la lista y el tamaño de la lista
def quickSort(a, p, r):
    # Revisa que la lsita tenga más de 1 elemento
    if p < r:
        # Divide la lista y nos da la posicion del pivote
        q = patrocinar(a,p,r)
        # Subarreglo de la parte izquierda
        quickSort(a, p, q-1)
        # Subarreglo de la parte derecha
        quickSort(a,q+1, r)

# La funcion reacomoda los subarreglos donde ambas partes (izq y der) esten acomoaddos conforme al pivote
# Recibe como parametro la lista de numeros, el indice del primer elemento y el tamaño de la lista
def patrocinar(a, p, r):
    # Para evitar que el algoritmo caiga en el peor de los casos se escoge un pivote al azar
    rand = randint(p,r)
    # Y se intercambia de valor con el ultimo elemento
    # Con esto, se optimiza el algoritmo y puede ordenar listas hasta de 20k elementos
    a[rand], a[r] = a[r], a[rand]
    # Es el elemento pivote (ultimo elemento aunque puede variar)
    x=a[r]
    # Indice auxuliar
    i = p-1

    # Compara todos los elementos para saber cuales son menores y mayores que el pivote
    for j in range(p,r):
        # Intercambia el valor para que quede del lado izquierdo del arreglo los menores o iguales al pivote
        if a[j] <= x:
            i+= 1
            a[i], a[j] = a[j], a[i]

    # El pivote cambia de posicion para marcar la division de menores y mayores a el
    a[i+1], a[r] = a[r], a[i+1]
    # Retorna la posicion final del pivote.
    return i+1

# Algoritmo: Heap Sort
# Recibe como parametro el arreglo de numeros
def ordenacionHeapSort(a):
    construirHeapMaxIni(a)
    # Guarda el numero de elementos del arreglo
    tamañoHeap = len(a)
    for i in range(len(a)-1,0,-1):
        a[0], a[i] = a[i], a[0]
        tamañoHeap -=1
        maxHeapify(a,0,tamañoHeap)

# Construye el heap inicial de forma que sea un HeapMaixmo
def construirHeapMaxIni(A):
    tamañoHeap = len(A)
    for i in range(len(A) // 2, -1, -1):
        maxHeapify (A, i, tamañoHeap)

def maxHeapify(A, i, tamañoHeap):
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

#* Caso Promedio
def casoPromedio(promedio1, promedio2):

    #! Algoritmo 1
    # Se inicializa el cronómetro
    tiempoInicial1 = perf_counter()
    # Se ejecuta el algoritmo
    ordenacionHeapSort(promedio1)
    # Se detiene el cronómetro
    tiempoFinal1 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo1 = tiempoFinal1 - tiempoInicial1

    #! Algoritmo 2
    # Se inicializa el cronómetro
    tiempoInicial2 = perf_counter()
    # Se ejecuta el algoritmo
    quickSort(promedio2,0,len(promedio2)-1)
    # Se detiene el cronómetro
    tiempoFinal2 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo2 = tiempoFinal2 - tiempoInicial2

    # Imprime los tiempos de cada algoritmo con 12 decimales
    print('\n¡Caso Promedio!')
    print('Tiempo QuickSort : {:.12f}'.format(tiempo1))
    print('Tiempo HeapSort : {:.12f}'.format(tiempo2))
    print("\n")

#* Mejor caso
def mejorCaso(mejor1, mejor2):

    #! Algoritmo 1
    # Se inicializa el cronómetro
    tiempoInicial1 = perf_counter()
    # Se ejecuta el algoritmo
    ordenacionHeapSort(mejor1)
    # Se detiene el cronómetro
    tiempoFinal1 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo1 = tiempoFinal1 - tiempoInicial1

    #! Algoritmo 2
    # Se inicializa el cronómetro
    tiempoInicial2 = perf_counter()
    # Se ejecuta el algoritmo
    quickSort(mejor2,0,len(mejor2)-1)
    # Se detiene el cronómetro
    tiempoFinal2 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo2 = tiempoFinal2 - tiempoInicial2

    # Imprime los tiempos de cada algoritmo con 12 decimales
    print('\n¡Mejor de los casos!')
    print('Tiempo QuickSort : {:.12f}'.format(tiempo1))
    print('Tiempo HeapSort : {:.12f}'.format(tiempo2))
    print("\n")

#* Peor de los casos
def peorCaso(peor1,peor2):

    #! Algoritmo 1
    # Se inicializa el cronómetro
    tiempoInicial1 = perf_counter()
    # Se ejecuta el algoritmo
    ordenacionHeapSort(peor1)
    # Se detiene el cronómetro
    tiempoFinal1 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo1 = tiempoFinal1 - tiempoInicial1

    #! Algoritmo 2
    # Se inicializa el cronómetro
    tiempoInicial2 = perf_counter()
    # Se ejecuta el algoritmo
    quickSort(peor2,0,len(peor2)-1)
    # Se detiene el cronómetro
    tiempoFinal2 = perf_counter()
    #Se calcula el tiempo tomado a completar el algoritmo
    tiempo2 = tiempoFinal2 - tiempoInicial2

    # Imprime los tiempos de cada algoritmo con 8 decimales
    print('\n¡Peor de los casos!')
    print('Tiempo QuickSort : {:.8f}'.format(tiempo1))
    print('Tiempo HeapSort : {:.8f}'.format(tiempo2))
    print("\n")

def run():
    # Genera una lista con valores del -100 al 100 del tamaño "n"
    n = 20000
    a = []
    for i in range (n):
        a.append(random.randint(0,10))
    # Copia la lista generada 3 veces para ser utilziadas en cada algoritmo.
    a1 = a[:]
    a2 = a[:]

    print("\nNumero de datos: ", n)
    # Ejecuta los casos promedio con los arreglos desordenados aleatoriamente
    casoPromedio(a1,a2)
    # Ejecuta los mejores casos con los arreglos ordenados ascendientemente
    mejorCaso(a1,a2)
    # A cada arreglo ordenado cambia de ser ascendiente a descendente
    a1.reverse()
    a2.reverse()
    # Ejecuta los peores casos con los arreglos ordenados descendientemente
    peorCaso(a1,a2)

if __name__ == '__main__':
    # Aqui inicia la ejecucion del programa
    run()
