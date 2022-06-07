##################################
# @author: Edwin Santiago
# Se grafican los resutlados obtenidos en el programa AlgoritmosPruebasGrandes
# Para analizar la complejidad algoritmica de los algoritmos
##################################

# Se importa la libreria cProfile par poner las etiquetas en la grafica
from cProfile import label
# Se importa la libreria matplotlib.pyplot par graficar
import matplotlib.pyplot as plt

def run():
    # n es parte del eje X
    n = (1000,3000,4000,5000)
    # Ejecuta cada caso para graficar, pasandole como parametro n
    casoPromedio(n)
    mejorCaso(n)
    peorCaso(n)

def casoPromedio(n):
    # El tiempo promedio de cada algoritmo se calculo:
    # Corriendo el programa 3 veces, sumando sus resultados
    # y diviendolos entre 3

    # Cada algoritmo guarda el tiempo promedio en cada valor de n
    #              1000     3000     4000     5000
    QuickSort = (0.016471,0.118914,0.064479,0.090050)
    HeapSort = (0.065715,0.545402,1.189833,1.202189)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, QuickSort, '-', linewidth="2", color='pink', label="Quick Sort") # QuickSort
    plt.plot(n, HeapSort, '-', linewidth="2", color='purple', label="Heap Sort") # Heap Sort
    # El titulo arriba del titulo
    plt.suptitle('Caso Promedio', fontdict={'color':'black'})
    # El titulo
    plt.title('n vs t', fontdict={'color':'blue'})
    # La etiqueta en el eje y
    plt.ylabel('Tiempo [s]')
    # La etiqueta en el eje x
    plt.xlabel('Numero de Datos [n]')
    # Se cuadricula la grafica
    plt.grid(True)
    # Se muestra las leyendas
    plt.legend()
    # Se crea la grafica
    plt.show()

def mejorCaso(n):
    # El tiempo promedio de cada algoritmo se calculo:
    # Corriendo el programa 3 veces, sumando sus resultados
    # y diviendolos entre 3

    # Cada algoritmo guarda el tiempo promedio en cada valor de n
    #              1000     3000     4000     5000
    QuickSort = (0.015948,0.156481,0.246747,0.118235)
    HeapSort = (0.595536,4.561465,15.242346,16.735227)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, QuickSort, '-', linewidth="2", color='pink', label="Quick Sort") # QuickSort
    plt.plot(n, HeapSort, '-', linewidth="2", color='purple', label="Heap Sort") # Heap Sort
    # El titulo arriba del titulo
    plt.suptitle('Mejor de los casos', fontdict={'color':'black'})
    # El titulo
    plt.title('n vs t', fontdict={'color':'blue'})
    # La etiqueta en el eje y
    plt.ylabel('Tiempo [s]')
    # La etiqueta en el eje x
    plt.xlabel('Numero de Datos [n]')
    # Se cuadricula la grafica
    plt.grid(True)
    # Se muestra las leyendas
    plt.legend()
    # Se crea la grafica
    plt.show()

def peorCaso(n):
    # El tiempo promedio de cada algoritmo se calculo:
    # Corriendo el programa 3 veces, sumando sus resultados
    # y diviendolos entre 3

    # Cada algoritmo guarda el tiempo promedio en cada valor de n
    #              1000     3000     4000     5000
    QuickSort = (0.037344,0.128522,0.157660,0.129849)
    HeapSort = (0.219396,0.796351,1.874456,3.501674)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, QuickSort, '-', linewidth="2", color='pink', label="Quick Sort") # QuickSort
    plt.plot(n, HeapSort, '-', linewidth="2", color='purple', label="Heap Sort") # Heap Sort
    # El titulo arriba del titulo
    plt.suptitle('Peor de los casos', fontdict={'color':'black'})
    # El titulo
    plt.title('n vs t', fontdict={'color':'blue'})
    # La etiqueta en el eje y
    plt.ylabel('Tiempo [s]')
    # La etiqueta en el eje x
    plt.xlabel('Numero de Datos [n]')
    # Se cuadricula la grafica
    plt.grid(True)
    # Se muestra las leyendas
    plt.legend()
    # Se crea la grafica
    plt.show()

if __name__ == '__main__':
    run()