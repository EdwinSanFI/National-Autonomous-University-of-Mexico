# Importa randint para escoger un número aleatorio entre 2 números.
from random import randint
# Importamos perf_counter para medir el tiempo
from time import perf_counter
# Importa la clase Usuario del archivo Database_12k
from Database_12k import Usuario

# Crea una Tabla Hash
# Recibe como parametro la lista de usuarios
def crear_tabla_hash(database):
    # Se crea una Tabla Hash del tamaño de la lista de usuarios
    hashTable = [[] for _ in range(len(database))]
    # Retorna la Tabla Hash
    return hashTable

# Conforme al nombre del usuario se guarda la informacion del usuario en una posicion calculada
# Recibe como parametro la Tabla Hash y el nombre del usuario
def hashing(tabla_hash, llave):
    # Inicializa una variable para guardar la sumatoria de las letras del nombre del usuario
    # conforme a su numero ASCII
    sumatoria = 0
    # Recorre el nombre del usuario
    for i in llave:
        # Suma el codigo ASCII de cada caracter del nombre del usuario
        sumatoria += ord(i)

    # Retorna el residuo de dividir la variable "sumatoria" entre la longitud de la Tabla Hash(10_000)
    return sumatoria%len(tabla_hash)

# Inserta a la Tabla Hash la informacion del alumno en forma de un arreglo
# Recibe como parametros la Tabla Hash, el nombre del usuario y la informacion del usuario
def insertar(tablaHash, fullname, usuario):
    # En la posicion que retorna la funcion hashing() se inserta en un arreglo la informacion del usuario
    tablaHash[hashing(tablaHash, fullname)].insert(hashing(tablaHash, fullname),[usuario])
    # Retorna la tabla hash con actualizada
    return tablaHash

# Busca en la Tabla Hash el nombre del alumno y retorna su información
# Recibe como parametros la Tabla Hash y el nombre del usuario
def buscar(tabla_hash, nombre_usuario):
    # Guarda el indice en donde se podria econtrar la lista de la información del usuario
    indice = hashing(tabla_hash, nombre_usuario)
    # Recorre la lista en donde se encuentra la informacion del usuario
    for i in range(len(tabla_hash[indice])):
        # Valida si se encuentra el usuario
        if tabla_hash[indice][i][0].fullname == nombre_usuario:
            # Retorna la informacion del usuario
            return tabla_hash[indice][i][0]

    # Retorna False si no se encuentra el usuario en la Tabla Hash
    return False

# Valida que el nombre de un usuario y su contraseña sean las mismas a las guardadas en el sistema
# Recibe como parametros la Tabla Hash, el nombre del usuario y su contraseña
def login(tabla_hash, username, password):
    # Guarda un valor a buscar en la tabla hash el nombre del usuario
    usuario = buscar(tabla_hash, username)

    # Si se guarda otro valor que no sea False (datos del usuario)
    if usuario != False:
        # Valida la contraseña ingresada con la contraseña guardada en la Tabla Hash
        if password == usuario.password:
            # Se le da acceso al usuario
            print("\nAcceso Autorizado: Bienvenido", username, "\n")
        else:
            # Se le niega el acceso al ususario
            print("\nAcceso Denegado: Contraseña Incorrecta\n")
    else:
        # Si se guarda el valor de Falso, no se encontró al usuario
        print("\nUsuario no encontrado\n")

# Ejecuta las demas funciones
def run():
    print("\n\t**Practica 5**")

    # Guarda los 10_000 usuarios de "Database_12k"
    database = Usuario.GetUsuariosDB(10000)
    # Crea y guarda una tabla hash con el parametro de la lista de los usuarios
    tabla_hash = crear_tabla_hash(database)

    # Imprime la longitud de la Tabla Hash
    print("\nLa longitud de la Base de datos es: ", len(tabla_hash))

    # Cada usuario de la base de datos será agregado a la tabla hash
    for i in range(len(tabla_hash)):
        tabla_hash = insertar(tabla_hash, database[i].fullname,database[i])

    # Solicita el nombre y la contraseña de un usuario
    username = input("\nCual es el nombre del usuario? ")
    password = input("Cual es la contraseña? ")
    # Metodo que para validar la información ingresada y simula el acceso a una cuenta
    login(tabla_hash, username, password)

    # Metodo Buscar de la Tabla Hash
    # Se crea una arreglo en donde se guardan el nombre de 10 usuarios distintos
    buscar_usuarios = []
    for i in range(10):
        # Escoge un numero aleatorio entre 0 y 10_000 para obtener el nombre del usuario de esa posicion
        indice_aleatorio = randint(0, 10000)
        # Agrega al arreglo el nombre de los usuarios
        buscar_usuarios.append(database[indice_aleatorio].fullname)
    print("Estos son los usuarios a buscar: ")
    # Imprime el nombre de los usuarios buscados
    for i in range(10):
        print("\t", buscar_usuarios[i])

    # Inicia el conteo de tiempo
    inicio = perf_counter()
    for i in range(10):
        # Buscara a los usuarios guardados en el arreglo buscar_usuarios
        buscar(tabla_hash,buscar_usuarios[i])
    # Finaliza el conteo de tiempo
    final = perf_counter()
    # Calcula el tiempo
    tiempo_hash = final - inicio
    print("\nTiempos de ejecución PROMEDIO (10 ejecuciones)")
    # Imprime el tiempo que le tomo al programa en ejecutar el algoritmo
    print("\tHash Table: ", tiempo_hash)

    # Busqueda lineal
    # Inicia el conteo de usuarios encontrados por la Busqueda Lineal
    usuarios_encontrados = 0
    # Inicia el conteo de tiempo
    inicio = perf_counter()
    # Desde 0 hasta 10_000
    for i in range(len(tabla_hash)):
        # Si en una posicion se guarda una lista de usuarios
        if len(tabla_hash[i])> 0:
            # Se recorre la lista de usuarios de esa posicion
            for j in range(len(tabla_hash[i])):
                # Si en la lista se encuentra uno de los nombres del arreglo buscar_usuarios
                if tabla_hash[i][j][0].fullname in buscar_usuarios:
                    # Se suma 1 al contador
                    usuarios_encontrados += 1
    # Finaliza el conteo de tiempo
    final = perf_counter()
    # Se calcula el tiempo
    tiempo_lineal = final - inicio
    # Imprime el tiempo que le tomo al programa en ejecutar el algoritmo
    print("\tLinear: ", tiempo_lineal)
    # Imprime cuantos usuarios fueron encontrados (si fueron 10, se encontraron todos los usuarios)
    print("\tEncontrados: ", usuarios_encontrados)

    # Se calcula cuantas posiciones de la Tabla Hash están ocupadas
    numero_de_llaves = 0
    for i in range(len(tabla_hash)):
        if len(tabla_hash[i])>0:
            numero_de_llaves += 1
    # Imprime el valor de Load Factor
    print("\nLoadFactor: ",numero_de_llaves/len(tabla_hash))

# Metodo main
if __name__ == '__main__':
    # Ejecuta los pasos necesarios para crear y llenar la base de datos
    run()