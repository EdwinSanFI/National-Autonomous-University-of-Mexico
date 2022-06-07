import matplotlib.pyplot as plt

def run():
    # n es parte del eje X
    n = (5000,10000,20000)
    # Ejecuta cada caso para graficar, pasandole como parametro n
    casoPromedio(n)
    mejorCaso(n)
    peorCaso(n)

def casoPromedio(n):
    # El tiempo promedio de cada algoritmo se calculo:
    # Ejecutando el programa 3 veces, sumando sus resultados
    # y diviendolos entre 3

    # Cada algoritmo guarda el tiempo promedio en cada valor de n
    #                 5000     10000     20000
    counting_sort = (0.003054,0.011452,0.012542)
    radix_sort = (0.027108,0.065871,0.087120)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, counting_sort, '-', linewidth="2", color='darkturquoise', label="Counting Sort") # Counting Sort
    plt.plot(n, radix_sort, '-', linewidth="2", color='gold', label="Radix Sort") # Radix Sort
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
    #                 5000     10000     20000
    counting_sort = (0.003908,0.007084,0.006689)
    radix_sort = (0.017178,0.024804,0.036579)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, counting_sort, '-', linewidth="2", color='darkturquoise', label="Counting Sort") # Counting Sort
    plt.plot(n, radix_sort, '-', linewidth="2", color='gold', label="Radix Sort") # Heap Sort
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
    #              5000     10000     20000
    counting_sort = (0.556294,0.625118,0.614811)
    radix_sort = (0.042842,0.080205,0.158442)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, counting_sort, '-', linewidth="2", color='darkturquoise', label="Counting Sort") # Counting Sort
    plt.plot(n, radix_sort, '-', linewidth="2", color='gold', label="Radix Sort") # Radix Sort
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