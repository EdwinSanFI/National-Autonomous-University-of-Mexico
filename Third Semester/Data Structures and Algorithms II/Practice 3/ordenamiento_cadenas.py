# Libreria para usar la funciones matematicas
import math

def radixSort(A):
    # Parte de mi prueba
    for i in range(len(A)):
        A[i] = list(A[i])
        for j in range(len(A[i])):
            A[i][j] = ord(A[i][j])
    k = 0
    for i in range(len(A)):
        if k < A[i][0]:
            k = A[i][0]
    d = math.floor(math.log10(k))+1
    for i in range(d): #Base 10 por ser numeros decimales
        A = countingSort_Radix(A,10,i)

    # Convierte de numeros a letras
    for i in range(len(A)):
        for j in range(len(A[i])):
            A[i][j] = chr(A[i][j])
    return A

def countingSort_Radix(A, b, i):
    k = b
    C = [0]*(k+1)
    B = [0]*len(A)

    for j in range(len(A)):
        numero = A[j][0]
        digitoi = math.floor(numero/math.pow(b,i))%b
        C[digitoi] += 1
        #print(C) Muestra el conteo de cada elemento de A
    for j in range(1, len(C)):
        C[j] = C[j] + C[j-1]
    # Mapeo de elementos de A
    for j in range(len(A)-1,-1,-1):
        numero = A[j][0]
        digitoi = math.floor(numero/math.pow(b,i))%b
        C[digitoi]-= 1 #  C[A[j]] = C[A[j]]-1
        B[C[digitoi]] = A[j]
    # Regresa el arreglo B ordenado
    return B

if __name__ == '__main__':
    arreglo = ["Z", "A", "Pedro", "Edwin", "Apple", "hqdwa0","0"]
    arregloOrdenado = radixSort(arreglo)
    for i in arregloOrdenado:
        print(i)