from random import randint
from time import perf_counter

# Busca en el arreglo el valor KEY y retornara
# las veces que se encontró el KEY en el arreglos
# Recibe como parametro el arreglo, el valor KEY, el indice inicial
# el indice final
def busqueda_binaria(arreglo, key, inicio, final):
    # Si el indice inicial es mayor que el final
    if inicio > final:
        # Ya no hay más elementos en el arreglo y retorna -1
        return -1
    # Guarda el índice de la mitad del arreglo
    mitad = (inicio+final)//2
    # Si el valor buscado es igual al del valor del indice de la mitad
    if key == arreglo[mitad]:
        contador = 0
        for i in range(inicio, final):
            if arreglo[i] == key:
                contador += 1
        # Retorna el indice de la las veces que aparece la llave
        return contador, inicio, final-1
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
    n = 30
    # Elemento a buscar, es un elemento aleatorio desde 0 hasta n//2
    key = randint(0,n//2)
    # Arreglo
    arreglo = []
    # Se agregará valores aleatorios desde 0 hasta n/2
    for _ in range(n):
        arreglo.append(randint(0, n/2))
    # Es el mensaje de error
    no_dato = "No se encontró el valor en el arreglo"

    print("\tPractica 4")
    print("Tamaño del arreglo: ",n)
    print("Elemento a buscar: ",key)

    # Ordena el arreglo de menor a mayor
    arreglo.sort()
    print ("Lista: ",arreglo)
    # Inicializa el contador
    tiempo_inicial = perf_counter()
    # Ejecuta el algortimo y guarda la posicion de elemento encontrado
    repetidos_binario, inicio, final = busqueda_binaria(arreglo, key, 0, len(arreglo)-1)
    # Finaliza el contador
    tiempo_final = perf_counter()
    # Obtiene el tiempo total
    tiempo_binario = tiempo_final - tiempo_inicial
    # Si la posicion no es -1
    if repetidos_binario>0:
        print("Busqueda Binaria: Se encontró: ", repetidos_binario, " veces y se tardó {:.6f}".format(tiempo_binario), " segundos")
        print("Indice incial: ", inicio ,"Indice final", final)
    # Si la posicion es -1
    else:
        print("Busqueda Binaria: ",no_dato)

# Funcion main
if __name__ == '__main__':
    run()