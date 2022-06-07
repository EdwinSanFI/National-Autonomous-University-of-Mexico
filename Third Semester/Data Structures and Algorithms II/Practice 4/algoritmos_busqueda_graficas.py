import matplotlib.pyplot as plt

def run():
    # n es parte del eje X
    n = (200000,500000,1000000)
    # Ejecuta caso promedio, pasandole como parametro n
    caso_promedio(n)

def caso_promedio(n):
    # El tiempo promedio de cada algoritmo se calculo:
    # Ejecutando el programa 3 veces, sumando sus resultados
    # y diviendolos entre 3

    # Cada algoritmo guarda el tiempo promedio en cada valor de n
    #                            200000     500000     1000000
    busqueda_lineal_optimizada = (0.044589 ,0.0008825,0.013745)
    busqueda_lineal_centinela = (0.050424,0.09070,0.016323)
    busqueda_binaria = (0.000054,0.000019,.000039)

    # Se grafican 3 lineas, cada linea equivale a cada algoritmo
    plt.plot(n, busqueda_lineal_optimizada, '-', linewidth="2", color='red', label="Busqueda Lineal Op")
    plt.plot(n, busqueda_lineal_centinela, '-', linewidth="2", color='green', label="Busqueda Lineal Cent")
    plt.plot(n, busqueda_binaria, '-', linewidth="2", color='blue', label="Busqueda Binaria")
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