# Author: Edwin San

def run():
    #Se capturan la cantidad de tareas, examanes y prácticas a ingresar
    numTareas = int(input('¿Cuantas calificaciones de tareas va ingresar? '))
    numExamenes = int(input('¿Cuantas calificaciones de examenes va ingresar? '))
    numPracticas = int(input('¿Cuantas calificaciones de prácticas de laboratorio va ingresar? '))

    #Se crean las listas para guardar las calificaciones
    tareas = list()
    examenes = list()
    practicas = list()
    print("")
    #Se captura las calificaciones de las tareas, examenes  y prácticas con respecto
    #a la cantidad ingresada anteriormente
    for i in range(1, numTareas+1):
        calificacion = input('Ingrese la calficación de la tarea #{} '.format(i))
        tareas.append(float(calificacion))
    print("")
    for i in range(1, numExamenes+1):
        calificacion = input('Ingrese la calficación del examen #{} '.format(i))
        examenes.append(float(calificacion))
    print("")
    for i in range(1, numPracticas+1):
        calificacion = input('Ingrese la calficación de la práctica #{} '.format(i))
        practicas.append(float(calificacion))

    #Se crean las variables para guardar la sumatoria de las calificaciones para obtener el promedio
    totalTareas = 0
    totalExamenes = 0
    totalPracticas = 0

    #Se obtiene el promedio de tareas
    for i in range(0, numTareas):
        totalTareas += tareas[i]
    #La suma de las calificaciones entre el número de calificaciones ingresadas
    #Y se redondea a 2 decimales
    promedioTareas = round(totalTareas / numTareas, 2)

    #Se obtiene el promedio de examenes
    for i in range(0, numExamenes):
        totalExamenes += examenes[i]
    #La suma de las calificaciones entre el número de calificaciones ingresadas
    #Y se redondea a 2 decimales
    promedioExamenes = round(totalExamenes / numExamenes, 2)

    #Se obtiene el promedio de prácticas
    for i in range(0, numPracticas):
        totalPracticas += practicas[i]
    #La suma de las calificaciones entre el número de calificaciones ingresadas
    #Y se redondea a 2 decimales
    promedioPracticas = round(totalPracticas / numPracticas, 2)


    #Se obtiene los puntos de las calificaciones
    #Examen 65%
    #Prácticas de laboratorio 35%
    rubicaExamen = round(promedioExamenes * 0.65, 1)
    rubicaPracticas = round(promedioPracticas * 0.35, 1)
    #Se redondean a un decimal el resultado

    #Obtemeos la calificación final sumando los puntos obtenidos 
    #del examen y de las practicas
    calificacionFinal = rubicaExamen + rubicaPracticas
    calificacionFinal = round(calificacionFinal, 1)
    
    #Se imprime las calificaciones
    print("")
    print("Tu promedio de examen fue de " + str(promedioExamenes))
    print("Tu promedio de Laboratorio fue de " + str(promedioPracticas))
    print("Tu calificación inicial es de " + str(calificacionFinal))

    #Si el promedio de las tareas fue mayor de 8.5
    if promedioTareas > 8.5:
        #Se suma 0.5 puntos al puntaje del examen
        rubicaExamen += 0.5
    #Si el promedio de las tareas fue entre 7.5 y 8.5
    elif promedioTareas > 7.0 and promedioTareas < 8.5:
        #No se modifica nada
        rubicaExamen += 0
    #Si no cumple lo anterior, se entiende que está por debajo de 7.0
    else:
        #Se le resta 0.5 puntos al puntaje del examen
        rubicaExamen -= 0.5
    
    #Al haber sufrido (o no) el puntaje del examen, se calcula la nueva calificación final
    calificacionFinal = rubicaExamen + rubicaPracticas
    calificacionFinal = round(calificacionFinal, 1)
    
    print("")
    print("Tu calificación de tareas es de " + str(promedioTareas) + ", por lo tanto tu calificación final es de " + str(calificacionFinal))
    print("")

#Se entiende como modulo principal ya que se ejecuta directamente
#Aqui da inicio el programa
if __name__ == '__main__':
    run()