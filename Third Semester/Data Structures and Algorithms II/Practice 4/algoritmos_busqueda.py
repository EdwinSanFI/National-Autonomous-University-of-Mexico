from random import randint
from time import perf_counter

# Busqued Lineal Optimizada
# Busca en el arreglo si se encuentra el valor KEY
# Retornara la posicion del valor buscado
def busqueda_lineal_mejorada(arreglo, key):
    # Recorre el arreglo
    for i in range(len(arreglo)):
        # Si la posicion i es igual al elemento a buscar
        if arreglo[i] == key:
            # Retorna el indice donde se encuentra el elemento
            return i
    return -1

# Busqueda Lineal con centinela
# Busca en el arreglo si se encuentra el valor KEY
# Retornara la posicion del valor buscado
def busqueda_lineal_centinela(arreglo,key):
    # Guarda el ultimo elemento del arreglo
    ultimo = arreglo[len(arreglo)-1]
    # El ultimo elemento se iguala al elemento a buscar
    arreglo[len(arreglo)-1] = key
    # Se declara para hacer uso en el ciclo while
    i = 0
    # Mientras que el elemnto de la posicion i no sea igual al valor a buscar
    while(arreglo[i]!=key):
        # Se suma 1 a la variable i
        i+=1
    # El ultimo elemento del arreglo vuelve a tener su valor inicial
    arreglo[len(arreglo)-1] = ultimo
    # Si la indice es menor al tamño del arreglo o si el ultimo valor del arreglo es igual al elemento a buscar
    if(i<len(arreglo)-1) or (ultimo == key):
        # Retorna la posicion y el tiempo que tarda el algoritmo
        return i
    # Retorna -1 y el tiempo que tarda el algoritmo
    return -1

# Busqueda Binaria Recursiva
def busqueda_binaria(arreglo, key, inicio, final):
    # Si el indice inicial es mayor que el final
    if inicio > final:
        # Ya no hay más elementos en el arreglo y retorna -1
        return -1
    # Guarda el índice de la mitad del arreglo
    mitad = (inicio+final)//2
    # Si el valor buscado es igual al del valor del indice de la mitad
    if key == arreglo[mitad]:
        # Retorna el indice de la mitad
        return mitad
    # O si el valor bsucado es menor al valor del indice de la mitad
    elif key < arreglo[mitad]:
        # Se llama a si misma pero se utilizara los elementos del arreglo desde
        # El primer elemento hasta el elemnto de la mitad de la lista.
        return busqueda_binaria(arreglo, key, inicio, mitad-1)
    # O si el valor bsucado es mayor al valor del indice de la mitad
    else:
        # Se llama a si misma pero se utilizara los elementos del arreglo desde
        # El la mitad de la lista hasta el ultimo elemento.
        return busqueda_binaria(arreglo, key, mitad+1, final)

def run():
    # Tamaño del arreglo
    n = 1000000
    # Elemento a buscar, es un elemento aleatorio desde 0 hasta n
    key = randint(0,n)
    # Arreglo
    arreglo = []
    # Se agregará valores aleatorios desde 0 hasta n/2
    for _ in range(n):
        arreglo.append(randint(0, n/2))
    # Es el mensaje de error
    no_dato = "No se encontró el dato"

    print("\tPractica 4")
    print("Tamaño del arreglo: ",n)
    print("Elemento a buscar: ",key)

    # Busqueda Lineal con centinela
    # Se guarda el tiempo que tardó el algoritmo y la posición donde se encontró
    # Inicializa el conteo de tiempo
    tiempo_inicial = perf_counter()
    indice_busqueda_lineal_centinela = busqueda_lineal_centinela(arreglo, key)
    # Finaliza el conteo de tiempo
    tiempo_final = perf_counter()
    # Obtiene el tiempo total
    tiempo_centinela = tiempo_final - tiempo_inicial
    # Si la posicion no es -1
    if indice_busqueda_lineal_centinela != -1:
        print("Busqueda Lineal con Centinela Se encontró el dato en el índice: ", indice_busqueda_lineal_centinela, "y tardó {:.6f}".format(tiempo_centinela))
    # Si la posicion es -1
    else:
        print("Busqueda Lineal Con Centinela: ",no_dato)

    # Busqueda Lineal
    # Guarda el tiempo que tarda el algoritmo y la posicion del elemento encontrado
    # Inicializa el conteo de tiempo
    tiempo_inicial = perf_counter()
    indice_busqueda_lineal = busqueda_lineal_mejorada(arreglo, key)
    # Finaliza el conteo de tiempo
    tiempo_final = perf_counter()
    # Obtiene el tiempo total
    tiempo_lineal = tiempo_final - tiempo_inicial
    # Si la posicion no es -1
    if indice_busqueda_lineal != -1:
        print("Busqueda Lineal Optimizada: Se encontró el dato en el índice: ", indice_busqueda_lineal, "y tardó {:.6f}".format(tiempo_lineal))
    # Si la posicion es -1
    else:
        print("Busqueda Lineal Optimizada: ",no_dato)

    # Busqueda binaria
    # Ordena el arreglo de menor a mayor
    arreglo.sort()
    # Inicializa el contador
    tiempo_inicial = perf_counter()
    # Ejecuta el algortimo y guarda la posicion de elemento encontrado
    indice_busqueda_binaria = busqueda_binaria(arreglo, key, 0, len(arreglo)-1)
    # Finaliza el contador
    tiempo_final = perf_counter()
    # Obtiene el tiempo total
    tiempo_binario = tiempo_final - tiempo_inicial
    # Si la posicion no es -1
    if indice_busqueda_binaria != -1:
        print("Busqueda Binaria: Se encontró el dato en el índice: ", indice_busqueda_binaria, "y tardó {:.6f}".format(tiempo_binario))
    # Si la posicion es -1
    else:
        print("Busqueda Binaria: ",no_dato)

# Funcion main
if __name__ == '__main__':
    run()