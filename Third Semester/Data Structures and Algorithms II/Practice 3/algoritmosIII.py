# Libreria para usar la funciones matematicas
import math
# Libreria para contar el tiempo
from time import perf_counter
# Libreria para escoger numeros aletorios dentro de un rango
import random

# Calcula el valor maximo del arrelglo A
def maximo(A):
    # Asigna el primer valor del arreglo (se cambiará después)
    maximo = A[0]
    # Recorremos el arreglo
    for i in range(1, len(A)):
        # Revisamos cual es el elemento maximo
        if A[i] > maximo:
            maximo = A[i]
    # Esta función es igual a:
    # k = max(A) #O(1)
    # Retornamos el valor maximo del arreglo
    return maximo

# Algoritmo Counting Sort
def countingSort(A):
    # Guarda el elemento maximo
    k = maximo(A)
    C = [0]*(k+1)  # == [0 for _ in range(k+1)]
    B = [0]*(len(A)) # == B[0 for _ in range(len(A))]

    for j in range(len(A)):
        C[A[j]] = C[A[j]]+1
        #print(C) Muestra el conteo de cada elemento de A
    for i in range(1, len(C)):
        C[i] = C[i] + C[i-1]

    for j in range(len(A)-1,-1,-1):
        # print(A[j]) Revisa los elementos
        C[A[j]]-= 1 #  C[A[j]] = C[A[j]]-1
        B[C[A[j]]] = A[j]
    # Regresa el arreglo B ordenado
    return B

# Radix sort
# B es la base
# D es el numero de digitos maximos
# Para eso se necesita K
def radixSort(A):
    k = max(A)
    d = math.floor(math.log10(k))+1
    # print('D= ', d) Para ver ek valor de D
    for i in range(d): #Base 10 por ser numeros decimales
        A = countingSort_Radix(A,10,i)
    return A

def countingSort_Radix(A, b, i):
    k = b
    C = [0]*(k+1)
    B = [0]*len(A)

    for j in range(len(A)):
        numero = A[j]
        digitoi = math.floor(numero/math.pow(b,i))%b
        C[digitoi] += 1
        #print(C) Muestra el conteo de cada elemento de A
    for j in range(1, len(C)):
        C[j] = C[j] + C[j-1]
    # Mapeo de elementos de A
    for j in range(len(A)-1,-1,-1):
        numero = A[j]
        digitoi = math.floor(numero/math.pow(b,i))%b
        C[digitoi]-= 1 #  C[A[j]] = C[A[j]]-1
        B[C[digitoi]] = A[j]
    # Regresa el arreglo B ordenado
    return B

# Caso promedio
def caso_promedio(n):
    # Caso promedio
    # La lista de numeros estan en un rango promedio
    a = []
    for _ in range (n):
        a.append(random.randint(0,100))
    # Se crea un arreglo para cada algoritmo
    arreglo = a[:]
    arreglo2 = a[:]

    print("\tCaso Promedio")

    # Counting Sort
    tiempo_inicial = perf_counter()
    countingSort(arreglo)
    tiempo_final = perf_counter()
    tiempo_total = tiempo_final - tiempo_inicial
    print("El tiempo que tarda CountingSort es de {:.8f}".format(tiempo_total))

    # Radix Sort
    tiempo_inicial = perf_counter()
    radixSort(arreglo2)
    tiempo_final = perf_counter()
    tiempo_total = tiempo_final - tiempo_inicial
    print("El tiempo que tarda RadixSort es de {:.8f}".format(tiempo_total))

def mejor_caso(n):
    # Mejor de los casos
    # La lista de numeros estan en un rango pequeño
    a = []
    for _ in range (n):
        a.append(random.randint(0,10))

    # Crea un arreglo para cada algoritmo
    arreglo = a[:]
    arreglo2 = a[:]

    print("\tMejor Caso")

    # Counting Sort
    tiempo_inicial = perf_counter()
    countingSort(arreglo)
    tiempo_final = perf_counter()
    tiempo_total = tiempo_final - tiempo_inicial
    print("El tiempo que tarda CountingSort es de {:.8f}".format(tiempo_total))

    # Radix Sort
    tiempo_inicial = perf_counter()
    radixSort(arreglo2)
    tiempo_final = perf_counter()
    tiempo_total = tiempo_final - tiempo_inicial
    print("El tiempo que tarda RadixSort es de {:.8f}".format(tiempo_total))

def peor_caso(n):
    # Peor de los casos
    # La lista de numeros estan en un rango largo
    # Se inicializa con un numero grande para tener un un espacio grande entre numeros
    a = [4000000]
    for _ in range (n):
        a.append(random.randint(0,1000))

    # Se crea un arreglo para cada algoritmo
    arreglo = a[:]
    arreglo2 = a[:]

    print("\tPeor de los casos")

    # Uno de los problemas de counting sort es:
    # Cuando el rango de los valores es muy grande
    # toma mucho tiempo en ordenarlo
    tiempo_inicial = perf_counter()
    countingSort(arreglo)
    tiempo_final = perf_counter()
    tiempo_total = tiempo_final - tiempo_inicial
    print("El tiempo que tarda CountingSort es de {:.8f}".format(tiempo_total))

    # Radix Sort
    # Radix Sort es ideal para rangos grandes de numeros y es mejor para el peor de los casos
    # De counting sort
    tiempo_inicial = perf_counter()
    radixSort(arreglo2)
    tiempo_final = perf_counter()
    tiempo_total = tiempo_final - tiempo_inicial
    print("El tiempo que tarda RadixSort es de {:.8f}".format(tiempo_total))

# Ejecutaa a los 3 casos y asigna el tamaño de las listas
def run():
    # Tamaño de la lista
    n = 20000
    print("\t n = ", n)
    # Ejecuta los promedios
    caso_promedio(n)
    mejor_caso(n)
    peor_caso(n)

# Entrada del programa
if __name__ == '__main__':
    run()