# Se importa la libreria cProfile par poner las etiquetas en la grafica
from cProfile import label
# Se importa la libreria matplotlib.pyplot par graficar
import matplotlib.pyplot as plt

def run():
    # n es parte del eje X
    n = (500,1000,5000,10000,20000)
    # Ejecuta cada caso para graficar, pasandole como parametro n
    casoPromedio(n)
    mejorCaso(n)
    peorCaso(n)

def casoPromedio(n):
    # El tiempo promedio de cada algoritmo se calculo:
    # Corriendo el programa 3 veces, sumando sus resultados
    # y diviendolos entre 3

    # Cada algoritmo guarda el tiempo promedio en cada valor de n
    #                     500          1000        5000        10000       20000
    bubleSortPromedio = (0.02883213,  0.07592649, 1.49885477, 6.20216426, 21.19370417)
    bubleSortOpPromedio = (0.028747833, 0.07289076, 1.67958433, 5.63425826,21.50669489)
    mergeSortPromedio = (0.00249066, 0.00296786, 0.01511882, 0.02780992, 0.05525299)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, bubleSortPromedio, '-', linewidth="2", color='red', label="Bubble Sort") # Bubble Sort
    plt.plot(n, bubleSortOpPromedio, '-', linewidth="2", color='blue', label="Bubble Sort Optimizado") # Bubble Sort Optimizado
    plt.plot(n, mergeSortPromedio, '-', linewidth="2", color='green', label="Merge Sort") # Merge Sort
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
    #                     500          1000        5000        10000       20000
    bubleSortMejor = (0.02288940, 3.918755549, 0.98965599, 3.91875549, 13.78163409)
    bubleSortOpMejor = (0.00008069, 0.00089566, 0.00047469, 0.00089566, 0.00127036)
    mergeSortMejor = (0.00293526, 0.03164349, 0.01517739, 0.03164349, 0.05830529)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, bubleSortPromedio, '-', linewidth="2", color='red', label="Bubble Sort") # Bubble Sort
    plt.plot(n, bubleSortOpPromedio, '-', linewidth="2", color='blue', label="Bubble Sort Optimizado") # Bubble Sort Optimizado
    plt.plot(n, mergeSortPromedio, '-', linewidth="2", color='green', label="Merge Sort") # Merge Sort
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

def peorCaso(n):
    # El tiempo promedio de cada algoritmo se calculo:
    # Corriendo el programa 3 veces, sumando sus resultados
    # y diviendolos entre 3

    # Cada algoritmo guarda el tiempo promedio en cada valor de n
    #                     500          1000        5000        10000       20000
    bubleSortPeor = (0.05004129, 0.10301502, 2.54553669, 9.46475733, 32.50327869)
    bubleSortOpPeor = (0.02685706, 0.10332622, 2.47078116, 9.77235423, 32.25500973)
    mergeSortPeor = (0.00123183, 0.00280302, 0.01302032, 0.10538276, 0.04612959)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, bubleSortPromedio, '-', linewidth="2", color='red', label="Bubble Sort") # Bubble Sort
    plt.plot(n, bubleSortOpPromedio, '-', linewidth="2", color='blue', label="Bubble Sort Optimizado") # Bubble Sort Optimizado
    plt.plot(n, mergeSortPromedio, '-', linewidth="2", color='green', label="Merge Sort") # Merge Sort
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

if __name__ == '__main__':
    run()