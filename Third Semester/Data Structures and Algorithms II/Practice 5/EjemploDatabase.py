from Database_12k import Usuario

usuarios = Usuario.GetUsuariosDB(100)  # Pedir desde 0 hasta 100

# Verificando la BD:
print('###')
print("El primer usuario es:", usuarios[0])
print("El nickname del primer usuario es:", usuarios[0].username)
print("El password del primer usuario es:", usuarios[0].password)
print("El nombre del primer usuario es:", usuarios[0].fullname)

# CAMBIANDO EL NOMBRE DEL 1er USUARIO:
print('###')
usuarios[0].username = "ful4n0"
usuarios[0].fullname = "Fulano Martinez"
usuarios[0].password = "123456"
print("El nombre del primer usuario es:", usuarios[0].username)
print("El password del primer usuario es:", usuarios[0].password)
print("El nombre del primer usuario es:", usuarios[0].fullname)

# Imprimiendo la BD
print('###')
print("La longitud de la DB:", len(usuarios))
print("La DB es:")
for i in range(len(usuarios)):
    print(i, usuarios[i])

# Obtener el codigo ascii de un caracter se usa ord( char )
for char in 'Eda 2':
    print('CHAR:', char, 'ASCII:', ord(char))