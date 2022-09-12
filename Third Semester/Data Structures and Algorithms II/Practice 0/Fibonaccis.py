##################################
# @author: Edwin Santiago
# Obtiene la secuencia de fibonacci, el tiempo de ejecución y realiza
# graficas conforme a los datos arrojados
##################################

# Se importa de la libreria "time" la funcion "perf_counter"
# para calcular el tiempo que tarda en obtener el numero n de fibonacci
# en distintos algoritmos
from time import perf_counter

# Se importa la libreria matplotlib.pyplot par graficar
import matplotlib.pyplot as plt

# Se inicializa 4 lista en donde se guardará:
    # Los numeros 0 hasta el N en el algoritmo Fibonacci Recursivo
x_recursivo = []
    # El tiempo de ejecución de cada numero en el algorimto Fibonacci Recursivo
y_recursivo = []
    # Los numeros 0 hasta el N en el algoritmo Fibonacci Iteractivo
x_iteractivo = []
    # El tiempo de ejecución de cada numero en el algorimto Fibonacci Iteractivo
y_iteractivo = []

"""
> The function calls itself twice, and each time it calls itself, it calls itself twice again, and
so on

:param n: The number of times the function is called
:return: The nth number of the Fibonacci sequence
"""
def fibo_recursivo(n):
    if n == 0 or n == 1:
        return 1
    return fibo_recursivo(n-1) + fibo_recursivo(n-2) #* O(n^c)

#* 2 + n^c = O(2 + n^c) = O(n^c)
#* Complejidad exponencial O(n^c)

"""
It takes the sum of the previous two numbers in the sequence and returns the nth number in the
sequence

:param n: The number of the Fibonacci sequence to be calculated
:return: The nth number of the Fibonacci sequence
"""
def fib_iterativo(n):
    f0 = 0 #* O(1)
    f1 = 1 #* O(1)
    if n == 0 or n == 1:
        return 1
    for _ in range(2, n+1): #* O(n)
        fn = f0 + f1 #* O(1) * n
        f0 = f1 #* O(1) * n
        f1 = fn #* O(1) * n
    return fn #* O(n)

#* 4 + 3n = O(4 + 3n) = O(n)
#* Complejidad Lineal O(n)


#Se calcula el tiempo que tarda en realizar las operaciones
def calcularTiempo():
    # Es la posicion del numero a calcular
    n = 40

    #* Se calcula el fibonacci Recursivo
    print("\n**Fibonacci Recursivo**")
    for i in range (0, n+1):
        # Se inicializa el cronómetro
        tiempoInicial = perf_counter()
        # Se ejecuta el algoritmo
        fibb_rec = fibo_recursivo(i)
        # Se detiene el cronómetro
        tiempoFinal = perf_counter()
        #Se calcula el tiempo tomado a completar el algoritmo
        tiempo = tiempoFinal - tiempoInicial

        # Se agrega a la lista el numero calculado
        x_recursivo.append(i)
        # Se agrega a la lista el tiempo que tardó el programa en calcularlo
        y_recursivo.append(tiempo)

        # Se imprimen los datos
        print(f'El numero {i} de Fibo es {fibb_rec} y tardó: {tiempo}[s]')
    print("\n")

    #* Se calcula el fibonacci Iterativo
    print("**Fibonacci Iterativo**")
    for i in range (0, n+1):
        # Se inicializa el cronómetro
        tiempoInicial = perf_counter()
        # Se ejecuta el algoritmo
        fibb_ite = fib_iterativo(i)
        # Se detiene el cronómetro
        tiempoFinal = perf_counter()
        #Se calcula el tiempo tomado a completar el algoritmo
        tiempo = tiempoFinal - tiempoInicial

        # Se agrega a la lista el numero calculado
        x_iteractivo.append(i)
        # Se agrega a la lista el tiempo que tardó el programa en calcularlo
        y_iteractivo.append(tiempo)

        # Se imprimen los datos
        print(f'El numero {i} de Fibo es {fibb_ite} y tardó: {tiempo}[s]')
    print("\n")

# Se grafica los datos obtenidos
def graficar():
    #* Fibonacci Recursivo
    # Se grafica en el eje X los numeros del 0 a "n"
    # Se grafica en el eje y el tiempo de ejecucion de cada numero
    plt.scatter(x_recursivo, y_recursivo)
    # Se le asigna un titulo en el eje X
    plt.xlabel("N")
    # Se le asigna un titulo en el eje Y
    plt.ylabel("Segundos[s]")
    # Se le asigna un titulo con caracteristicas
    plt.title("Fibonacci Recursivo", fontdict={'family': 'serif', 'color': 'red', 'size': 20})
    # Se cuadricula la grafica
    plt.grid(True)
    # Se genera la grafica en forma de imagen
    plt.show()

    #*  Fibonacci Iteractivo
    # Se grafica en el eje X los numeros del 0 a "n"
    # Se grafica en el eje y el tiempo de ejecucion de cada numero
    plt.scatter(x_iteractivo, y_iteractivo)
    # Se le asigna un titulo en el eje X
    plt.xlabel("N")
    # Se le asigna un titulo en el eje Y
    plt.ylabel("Segundos[s]")
    # Se le asigna un titulo con caracteristicas
    plt.title("Fibonacci Iteractivo", fontdict={'family': 'serif', 'color': 'red', 'size': 20})
    # Se cuadricula la grafica
    plt.grid(True)
    # Se genera la grafica en forma de imagen
    plt.show()

#Aqui inicia la ejecucion del programa el programa
if __name__ == '__main__':
    # Se ejecuta la funcion para tomar el tiempo
    calcularTiempo()
    graficar()