#Actividad 2 - Practica 11
#Santiago Díaz Edwin Jaret
#Estructura de Datos y Algoritmos

def activities(s, f, n):
    print("Selected Activities are:")
    i = 0
    print("A" + str(i+1))
    for j in range(1, n):
        if s[j] >= f[i]:
            print("A" + str(j+1)) # Si la hora de finalización es igual o mayor a la hora de inicio
            i = j # La hora de inicio ahora es la hora final de la ultima actividad

if __name__ == '__main__':
    s = [1, 2, 3, 2, 4, 5, 6, 8, 7] #Horario de inicio de actividades
    f = [4, 5, 6, 8, 6, 7, 7, 12, 9] #Horario de fin de actividades
    #Esto lo hace diferente al programa escrito en C
    n = len(s)
    activities(s, f, n)