#Actividad 3 - Practica 11
#Santiago Díaz Edwin Jaret
#Estructura de Datos y Algoritmos I

def minMax(L):
    if len(L) == 1:
        return (L[0], L[0])
    elif len(L) == 2:
        if L[0] <= L[1]:
            return (L[0], L[1])
        else:
            return (L[1], L[0])
    else:
        mid = len(L) / 2
        (minL, maxL) = minMax(L[:int(mid)])
        (minR, maxR) = minMax(L[int(mid):])
        if minL <= minR:
            min = minL
        else: 
            min = minR
        if maxL >= maxR:
            max = maxL
        else:
            max = maxR
        return (min, max)

def principal():
    lista = [3, 10, 32, 100, 4, 76, 45, 32, 17, 12, 1]
    lista2 = [89, 219, 423, 110, 644, 776, 245, 362, 178, 112, 521]
    print("Los valores son: ", minMax(lista))
    print("Los valores son: ", minMax(lista2))

if __name__ == '__main__':
    principal()