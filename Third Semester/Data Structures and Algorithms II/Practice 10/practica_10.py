import os

def run():
    casos_estado = {}
    casos_totales = 0
    casos_generos = {'M': 0, 'F': 0}
    casos_edades = {}

    try:
        archivo = open("covid-19-mexico-01122020.csv", "r", encoding="utf-8")
        lineas = archivo.readlines()

        # Obtengo el total de casos y el caso por estado
        for i in range(1, len(lineas)):
            # Obtengo los datos de la linea
            linea_separada = lineas[i].split(",")
            # Obtengo el estado
            estado = linea_separada[1]
            # Sumo un caso
            casos_totales += 1
            # Obtengo el genero
            genero = linea_separada[2]
            # Sumo un caso al genero
            casos_generos[genero] += 1
            # Obtengo la edad
            edad = linea_separada[3]
            # Si la edad no esta en el diccionario, la agrego
            casos_edades[edad] = casos_edades.get(edad, 0) + 1
            casos_estado[estado] = casos_estado.get(estado, 0) + 1

        # Cierro el archivo
        archivo.close()

        # Ordeno los estados por el total de casos
        estados_ordenados = sorted(casos_estado, key=casos_estado.get, reverse=True)

        # Guardo el estado con mas casos
        estado_mas_casos = estados_ordenados[0]

        # Guardo el estado con menos casos
        estado_menos_casos = estados_ordenados[len(estados_ordenados) - 1]

        # Obtengo el total de casos por genero
        total_genero_m = casos_generos['M']
        total_genero_f = casos_generos['F']

        # Promedio de edad
        promedio_edad = 0
        for edad in casos_edades.keys():
            promedio_edad += int(edad) * casos_edades[edad]

        promedio_edad = promedio_edad / casos_totales

        # Edad minima y maxima
        edad_minima = min(casos_edades.keys())
        edad_maxima = max(casos_edades.keys())

        if not os.path.exists("PracticaResumen"):
            os.mkdir("PracticaResumen")

        # Guardo los datos en un archivo
        with open("PracticaResumen/resumenCovid.eda2", "w", encoding="utf-8") as archivo2:
            archivo2.write("\nTotal de casos: " + str(casos_totales) + "\n")
            archivo2.write("\nEstado con mas casos: " + estado_mas_casos + "\n")
            archivo2.write("\nEstado con menos casos: " + estado_menos_casos + "\n")
            archivo2.write("\nTotal de casos por genero:" + "\n")
            archivo2.write("\tMasculino: " + str(total_genero_m) + "\n")
            archivo2.write("\tFemenino: " + str(total_genero_f) + "\n")
            archivo2.write("\nPromedio de edad: " + str(promedio_edad) + "\n")
            archivo2.write("\nEdad minima: " + str(edad_minima) + "\n")
            archivo2.write("\nEdad maxima: " + str(edad_maxima) + "\n")
            archivo2.write("\nCasos por estado:" + "\n")
            for estado in estados_ordenados:
                archivo2.write("\t"+estado + ": " + str(casos_estado[estado]) + "\n")

    except FileNotFoundError:
        print("El archivo no existe")


if __name__ == '__main__':
    run()