#Actividad 4 - Practica 11
#Santiago Díaz Edwin Jaret
#Estructura de Datos y Algoritmos I

def merge(left, right):
    result = []
    
    left_idx, right_idx = 0, 0
    while left_idx < len(left) and right_idx < len(right):
        if left[left_idx] <= right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1
    if left:
        result.extend(left[left_idx:]) #Agrega al final de lista
    if right:
        result.extend(right[right_idx:])
    print("Result" + str(result))
    print()
    return result

def merge_sort(m):
    if len(m) <= 1:
        return m
    middle = len(m) // 2
    left = m[:middle]
    right = m[middle:]
    print()
    print("left" + str(left))
    print("right" + str(right))
    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right))
    
if __name__ == '__main__':
    lista1 = [4, 12, 87, 1, 32, 54, 36, 78, 90, 7]
    lista2 = [89, 219, 423, 110, 644, 776, 245, 362, 178, 112, 521]
    print(merge_sort(lista1))
    print(merge_sort(lista2))